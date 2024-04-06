#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Singer 
{
public:
    static Singer* contestants;
    static int count;
    static int size;
    int id;
    char name[50]; // 假设姓名不超过50个字符
    int scores[5]; // 假设每位选手由5位评委打分
    double averageScore;

    Singer() : id(0), averageScore(0) 
    {
        name[0] = '\0';
        memset(scores, 0, sizeof(scores));
    }

    Singer(int id, const char* name, int scores[]) 
    {
        this->id = id;
        strcpy(this->name, name);
        memcpy(this->scores, scores, 5 * sizeof(int)); // 假设固定5位评委打分
        this->averageScore = calculateAverage(scores);

        if (count == size) 
        {
            size *= 2;
            Singer* newContestants = new Singer[size];
            for (int i = 0; i < count; ++i)
            {
                newContestants[i] = contestants[i];
            }
            delete[] contestants;
            contestants = newContestants;
        }
        contestants[count++] = *this;
    }

    static double calculateAverage(int scores[]) 
    {
        double sum = 0;
        for (int i = 0; i < 5; ++i) 
        { 
            sum += scores[i];
        }
        return sum / 5;
    }

    static void printHighestScore()
    {
        if (count == 0) 
        {
            cout << "没有选手。" << endl;
            return;
        }
        Singer* highest = &contestants[0];
        for (int i = 1; i < count; ++i) 
        {
            if (contestants[i].averageScore > highest->averageScore) 
            {
                highest = &contestants[i];
            }
        }
        cout << "最高分选手: " << highest->name << " ，平均分为： " << highest->averageScore << endl;
    }

    static void printLowestScore() 
    {
        if (count == 0) 
        {
            cout << "没有选手。" << endl;
            return;
        }
        Singer* lowest = &contestants[0];
        for (int i = 1; i < count; ++i) 
        {
            if (contestants[i].averageScore < lowest->averageScore) 
            {
                lowest = &contestants[i];
            }
        }
        cout << "最低分选手: " << lowest->name << " ，平均分为： " << lowest->averageScore << endl;
    }

    static void printContestants();
};

// 静态成员初始化
Singer* Singer::contestants = new Singer[10]; // 初始大小为10，会动态扩展
int Singer::count = 0;
int Singer::size = 10;

void Singer::printContestants() 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "编号: " << contestants[i].id << ", 姓名: " << contestants[i].name
            << ", 平均分: " << contestants[i].averageScore << endl;
    }
}

int main() {
    int n;
    cout << "选手数量: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int scores[5];
        char name[50];
        cout << "请输入第" << i + 1 << "位选手的姓名: ";
        cin >> name;
        for (int j = 0; j < 5; ++j) 
        {
            cout << "\t请输入第" << j + 1 << "位评委给出的分数: ";
            cin >> scores[j];
        }
        Singer(i, name, scores);
    }

    Singer::printContestants();
    Singer::printHighestScore();
    Singer::printLowestScore();

    // 清理
    delete[] Singer::contestants;
    return 0;
}
