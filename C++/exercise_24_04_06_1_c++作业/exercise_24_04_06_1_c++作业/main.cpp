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
    char name[50]; // ��������������50���ַ�
    int scores[5]; // ����ÿλѡ����5λ��ί���
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
        memcpy(this->scores, scores, 5 * sizeof(int)); // ����̶�5λ��ί���
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
            cout << "û��ѡ�֡�" << endl;
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
        cout << "��߷�ѡ��: " << highest->name << " ��ƽ����Ϊ�� " << highest->averageScore << endl;
    }

    static void printLowestScore() 
    {
        if (count == 0) 
        {
            cout << "û��ѡ�֡�" << endl;
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
        cout << "��ͷ�ѡ��: " << lowest->name << " ��ƽ����Ϊ�� " << lowest->averageScore << endl;
    }

    static void printContestants();
};

// ��̬��Ա��ʼ��
Singer* Singer::contestants = new Singer[10]; // ��ʼ��СΪ10���ᶯ̬��չ
int Singer::count = 0;
int Singer::size = 10;

void Singer::printContestants() 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "���: " << contestants[i].id << ", ����: " << contestants[i].name
            << ", ƽ����: " << contestants[i].averageScore << endl;
    }
}

int main() {
    int n;
    cout << "ѡ������: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int scores[5];
        char name[50];
        cout << "�������" << i + 1 << "λѡ�ֵ�����: ";
        cin >> name;
        for (int j = 0; j < 5; ++j) 
        {
            cout << "\t�������" << j + 1 << "λ��ί�����ķ���: ";
            cin >> scores[j];
        }
        Singer(i, name, scores);
    }

    Singer::printContestants();
    Singer::printHighestScore();
    Singer::printLowestScore();

    // ����
    delete[] Singer::contestants;
    return 0;
}
