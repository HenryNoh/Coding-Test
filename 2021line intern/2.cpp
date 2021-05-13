//11:10
//12:00
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> a)
{
    int max = 0;
    int index = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    vector<int> b(a.size(), index);
    for (int i = 0; i < a.size(); i++)
    {
        if (i >= 1 && a[i - 1] > a[i])
        {
            b[i] = i - 1;
        }
        else if (i >= 1 && a[b[i - 1]] > a[i])
        {
            if (abs(b[i - 1] - i) <= abs(b[i] - i))
                b[i] = b[i - 1];
        }
        else if (i < a.size() - 1 && a[i + 1] > a[i])
        {
            if (abs(b[i] - i) > 1)
                b[i] = i + 1;
        }
        else if (i < a.size() - 1 && a[b[i + 1]] > a[i])
        {
            if (abs(b[i + 1] - i) < abs(b[i] - i))
                b[i] = b[i + 1];
        }
    }
    b[index] = -1;
    return b;
}

int main()
{
    vector<int> a = {7, 4, 4, 2, 9, 6};
    vector<int> b = solution(a);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
}
//1. �� ���� ���� �� Ŭ ���
// �� ���� �� index - �� vs ���� ���� �ִ°� index - ��
// ���ڰ� ���� ��� b[i] = i-1
//2. �� ���� ���� �ִ� ���� �� Ŭ ���
// �� ���� ���� �����ִ°� index - �� vs ���� ���� �ִ°� index - ��
//3. �� ���� ���� �� Ŭ ���
// ������ �� index - �� vs ���� ���� �ִ°� index - ��
//4. �� �ڰ� ���� �ִ� ���� �� Ŭ ���
// �� ���� ���� �����ִ°� index - �� vs ���� ���� �ִ°� index - ��
//5. �� �ƴ� ���
// -1

//0 1 2 3 4
//3 5 4 1 2
//1 -1 1 2 2

//1 1 1 1 1
//1 3��
//1 -1 5��
//1 -1 1 1�� 1-2 vs 1-2 index = 1
//1 -1 1 2 1�� 2-3 vs 1-3 index = 2
//1 -1 1 2 2 2�� 2-4 vs 1-4 index = 2

//0 1 2 3 4
//1 2 3 4 5
//1 2 3 4 -1

//4 4 4 4 4
//1 -> 1�� 1-0 vs 4-0 index = 1
//1 2 -> 2�� 2-1 vs 4-1 index = 2
//1 2 3 -> 3�� 3-1 vs 4-1 index 3
//1 2 3 4

//0 1 2 3 4 5
//7 4 4 2 9 6 ��
//4 0 0 2 -1 4

//4 4 4 4 4 4
//4 0 -> 1�� 0-1 vs 4-1 = 0-1 �� index  = 0
//4 0 0 -> 2�� 0-2 vs 4-2 = 0-2 �� index = 0
//4 0 0 2 -> 1�� 2-3 vs 4-3 = 2-3 �� index = 2
//4 0 0 2 -1
//4 0 0 2 -1 4 -> 4-5 vs 4-5 index 4