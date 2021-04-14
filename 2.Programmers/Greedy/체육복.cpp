#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> st(30, -1);
    for (int i = 0; i < reserve.size(); i++)
        st[reserve[i] - 1] = 2;
    for (int i = 0; i < lost.size(); i++)
    {
        if (st[lost[i] - 1] == 2)
            st[lost[i] - 1] = 1;
        else
            st[lost[i] - 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (st[i] == -1)
            st[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            if (st[i - 1] == 2)
            {
                st[i] = 1;
                st[i - 1] = 1;
            }
            else if (st[i + 1] == 2)
            {
                st[i] = 1;
                st[i + 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 1 || st[i] == 2)
            answer++;
    }
    return answer;
}