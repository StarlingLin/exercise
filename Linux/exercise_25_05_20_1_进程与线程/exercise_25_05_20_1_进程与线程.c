// #include <stdio.h>

// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>
// #include <sys/wait.h> 

// char r_buf[4];
// char w_buf[4];
// int  pipe_fd[2];
// pid_t pid1, pid2, pid3, pid4;

// int producer(int id);
// int consumer(int id);

// int main(int argc, char **argv)
// {
//     if (pipe(pipe_fd) < 0)
//     {
//         perror("pipe create error");
//         exit(EXIT_FAILURE);
//     }

//     printf("pipe is created successfully!\n");

//     if ((pid1 = fork()) == 0) { producer(1); }
//     if ((pid2 = fork()) == 0) { producer(2); }
//     if ((pid3 = fork()) == 0) { consumer(1); }
//     if ((pid4 = fork()) == 0) { consumer(2); }

//     close(pipe_fd[0]);
//     close(pipe_fd[1]);

//     int status;
//     for (int i = 0; i < 4; ++i)
//     {
//         if (waitpid(-1, &status, 0) == -1)
//         {
//             perror("waitpid");
//         }
//     }
//     return 0;    
// }

// int producer(int id)
// {
//     printf("producer %d is running!\n", id);
//     close(pipe_fd[0]);   

//     for (int i = 1; i < 10; ++i)
//     {
//         sleep(3);
//         strcpy(w_buf, id == 1 ? "aaa" : "bbb");
//         if (write(pipe_fd[1], w_buf, 4) != 4)
//         {
//             perror("write to pipe");
//             exit(EXIT_FAILURE);
//         }
//     }

//     close(pipe_fd[1]);
//     printf("producer %d is over!\n", id);
//     exit(id);
// }

// int consumer(int id)
// {
//     close(pipe_fd[1]); 
//     printf("consumer %d is running!\n", id);

//     strcpy(w_buf, id == 1 ? "ccc" : "ddd"); 

//     while (1)
//     {
//         sleep(1);
//         if (read(pipe_fd[0], r_buf, 4) == 0) { break; } 
//         printf("consumer %d get %s, while the w_buf is %s\n",
//                id, r_buf, w_buf);
//     }

//     close(pipe_fd[0]);
//     printf("consumer %d is over!\n", id);
//     exit(id);
// }

#define _GNU_SOURCE
#include <sched.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>              
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

int  producer(void *args);
int  consumer(void *args);
pthread_mutex_t mutex;
sem_t product, warehouse;
char buffer[8][4];
int  bp = 0;

#define STACK_SIZE 4096
#define THREADS    2             

int main(int argc, char **argv)
{
    pthread_mutex_init(&mutex, NULL);
    sem_init(&product,   0, 0);
    sem_init(&warehouse, 0, 8);

    int clone_flag = CLONE_VM | CLONE_SIGHAND | CLONE_FS | CLONE_FILES;  
    pid_t tids[THREADS * 2];

    static int id_arr[THREADS * 2];

    for (int i = 0; i < THREADS; ++i)
    {
        char *stack;

        id_arr[i] = i;
        stack = (char *)malloc(STACK_SIZE);
        tids[i] = clone(producer, stack + STACK_SIZE,
                        clone_flag | SIGCHLD, &id_arr[i]);

        id_arr[i + THREADS] = i;
        stack = (char *)malloc(STACK_SIZE);
        tids[i + THREADS] = clone(consumer, stack + STACK_SIZE,
                                  clone_flag | SIGCHLD, &id_arr[i + THREADS]);
    }

    for (int i = 0; i < THREADS * 2; ++i)
    {
        waitpid(tids[i], NULL, 0);
    }

    sem_destroy(&product);
    sem_destroy(&warehouse);
    pthread_mutex_destroy(&mutex);
    return 0;
}

int producer(void *args)
{
    int id = *((int *)args);

    for (int i = 0; i < 10; ++i)
    {
        sleep(i + 1);
        sem_wait(&warehouse);
        pthread_mutex_lock(&mutex);

        strcpy(buffer[bp], id == 0 ? "aaa" : "bbb");
        printf("producer%d produce %s in %d\n", id, buffer[bp], bp);
        bp++;

        pthread_mutex_unlock(&mutex);
        sem_post(&product);
    }
    printf("producer%d is over!\n", id);
    return 0;            
}

int consumer(void *args)
{
    int id = *((int *)args);

    for (int i = 0; i < 10; ++i)
    {
        sleep(10 - i);
        sem_wait(&product);
        pthread_mutex_lock(&mutex);

        bp--;
        printf("consumer%d get %s in %d\n", id, buffer[bp], bp);
        strcpy(buffer[bp], "zzz");

        pthread_mutex_unlock(&mutex);
        sem_post(&warehouse);
    }
    printf("consumer%d is over!\n", id);
    return 0;           
}
