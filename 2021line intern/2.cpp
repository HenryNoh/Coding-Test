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
//1. 내 앞의 수가 더 클 경우
// 내 앞의 수 index - 나 vs 내가 보고 있는거 index - 나
// 전자가 작을 경우 b[i] = i-1
//2. 내 앞이 보고 있는 수가 더 클 경우
// 내 앞의 수가 보고있는거 index - 나 vs 내가 보고 있는거 index - 나
//3. 내 뒤의 수가 더 클 경우
// 내뒤의 수 index - 나 vs 내가 보고 있는거 index - 나
//4. 내 뒤가 보고 있는 수가 더 클 경우
// 내 뒤의 수가 보고있는거 index - 나 vs 내가 보고 있는거 index - 나
//5. 다 아닌 경우
// -1

//0 1 2 3 4
//3 5 4 1 2
//1 -1 1 2 2

//1 1 1 1 1
//1 3번
//1 -1 5번
//1 -1 1 1번 1-2 vs 1-2 index = 1
//1 -1 1 2 1번 2-3 vs 1-3 index = 2
//1 -1 1 2 2 2번 2-4 vs 1-4 index = 2

//0 1 2 3 4
//1 2 3 4 5
//1 2 3 4 -1

//4 4 4 4 4
//1 -> 1번 1-0 vs 4-0 index = 1
//1 2 -> 2번 2-1 vs 4-1 index = 2
//1 2 3 -> 3번 3-1 vs 4-1 index 3
//1 2 3 4

//0 1 2 3 4 5
//7 4 4 2 9 6 수
//4 0 0 2 -1 4

//4 4 4 4 4 4
//4 0 -> 1번 0-1 vs 4-1 = 0-1 승 index  = 0
//4 0 0 -> 2번 0-2 vs 4-2 = 0-2 승 index = 0
//4 0 0 2 -> 1번 2-3 vs 4-3 = 2-3 승 index = 2
//4 0 0 2 -1
//4 0 0 2 -1 4 -> 4-5 vs 4-5 index 4