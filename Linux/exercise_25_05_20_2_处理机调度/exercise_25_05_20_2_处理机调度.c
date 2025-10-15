#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {          
    char task_id;
    int  call_num;        
    int  ci;             
    int  ti;  
    int  ci_left;
    int  ti_left;
    int  flag;                                  
    int  arg;                           
    pthread_t th;
} task;

void *proc(void *args);  
void *idle(void *args);
int   select_proc(int alg);

int  task_num = 0;
int  idle_num = 0;
int  alg;               
int  curr_proc = -1;
int  demo_time = 100;

task *tasks = NULL;
pthread_mutex_t proc_wait[100];
pthread_mutex_t main_wait, idle_wait;
float sum = 0.0f;
pthread_t idle_proc;

int main(void)
{
    pthread_mutex_init(&main_wait, NULL);
    pthread_mutex_lock(&main_wait);
    pthread_mutex_init(&idle_wait, NULL);
    pthread_mutex_lock(&idle_wait);

    printf("Please input number of real time tasks:\n");
    if (scanf("%d", &task_num) != 1 || task_num <= 0 || task_num > 100) {
        fprintf(stderr, "Invalid task number.\n");
        return 1;
    }

    tasks = (task *)malloc(task_num * sizeof(task));
    for (int i = 0; i < task_num; ++i) {
        pthread_mutex_init(&proc_wait[i], NULL);
        pthread_mutex_lock(&proc_wait[i]);
    }

    for (int i = 0; i < task_num; ++i) {
        printf("Please input task id, followed by Ci and Ti:\n");
        if (scanf(" %c,%d,%d,", &tasks[i].task_id, &tasks[i].ci, &tasks[i].ti) != 3) {
            fprintf(stderr, "Input format error.\n");
            return 1;
        }
        tasks[i].ci_left = tasks[i].ci;
        tasks[i].ti_left = tasks[i].ti;
        tasks[i].flag    = 1;      
        tasks[i].arg     = i;
        tasks[i].call_num = 1;
        sum += (float)tasks[i].ci / (float)tasks[i].ti;
    }

    printf("Please input algorithm, 1 for EDF, 2 for RMS:");
    scanf("%d", &alg);
    printf("Please input demo time:");
    scanf("%d", &demo_time);

    double r = 1.0;         
    if (alg == 2) {     
        r = task_num * (exp(log(2.0) / task_num) - 1);
        printf("r is %lf\n", r);
    }
    if (sum > r) {
        printf("(sum=%lf > r=%lf) ,not schedulable!\n", sum, r);
        return 2;
    }

    pthread_create(&idle_proc, NULL, idle, NULL);
    for (int i = 0; i < task_num; ++i)
        pthread_create(&tasks[i].th, NULL, proc, &tasks[i].arg);

    for (int t = 0; t < demo_time; ++t) {
        int sel = select_proc(alg);
        if (sel != -1) {
            curr_proc = sel;
            pthread_mutex_unlock(&proc_wait[sel]);
            pthread_mutex_lock(&main_wait);
        } else {            
            pthread_mutex_unlock(&idle_wait);
            pthread_mutex_lock(&main_wait);
        }

        for (int j = 0; j < task_num; ++j) {
            if (--tasks[j].ti_left == 0) {
                tasks[j].ti_left = tasks[j].ti;
                tasks[j].ci_left = tasks[j].ci;
                tasks[j].flag    = 1;
                pthread_create(&tasks[j].th, NULL, proc, &tasks[j].arg);
            }
        }
    }

    printf("\n");
    sleep(1);         
    return 0;
}

void *proc(void *args)
{
    int idx = *(int *)args;
    while (tasks[idx].ci_left > 0) {
        pthread_mutex_lock(&proc_wait[idx]);
        if (idle_num != 0) {
            printf("idle(%d)", idle_num);
            idle_num = 0;
        }
        printf("%c%d", tasks[idx].task_id, tasks[idx].call_num);
        tasks[idx].ci_left--;
        if (tasks[idx].ci_left == 0) {
            printf("(%d)", tasks[idx].ci);
            tasks[idx].flag = 0;
            tasks[idx].call_num++;
        }
        pthread_mutex_unlock(&main_wait);
    }
    return NULL; 
}

void *idle(void *args)
{
    (void)args;
    while (1) {
        pthread_mutex_lock(&idle_wait);
        printf("->");
        idle_num++;
        pthread_mutex_unlock(&main_wait);
    }
    return NULL;
}

int select_proc(int alg)
{
    int selected = -1;
    int metric   = __INT_MAX__;

    if (alg == 2 && curr_proc != -1 && tasks[curr_proc].flag)
        return curr_proc;

    for (int j = 0; j < task_num; ++j) {
        if (!tasks[j].flag) continue; 
        switch (alg) {
        case 1:    
            if (tasks[j].ti_left < metric) {
                metric   = tasks[j].ti_left; 
                selected = j;
            }
            break;      
        case 2:                     
            if (tasks[j].ti < metric) {
                metric   = tasks[j].ti;
                selected = j;
            }
            break;
        default:
            break;
        }
    }
    return selected;
}
