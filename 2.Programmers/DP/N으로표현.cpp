#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number)
{
    int answer = -1;
    vector<set<int>> DP;
    set<int> a;
    a.insert(N);
    DP.push_back(a);
    for (int i = 1; i < 8; i++)
    {
        set<int> tmp;
        for (int j = 0; j < i; j++)
        {
            for (auto a : DP[j])
            {
                for (auto b : DP[i - 1 - j])
                {
                    tmp.insert(a * b);
                    if (b != 0)
                        tmp.insert(a / b);
                    tmp.insert(a + b);
                    tmp.insert(a - b);
                }
            }
        }
        int temp = N;
        for (int j = 0; j < i; j++)
            temp = temp * 10 + N;
        tmp.insert(temp);
        DP.push_back(tmp);
    }
    for (int i = 0; i < 8; i++)
    {
        auto it = DP[i].find(number);
        if (it != DP[i].end())
        {
            return i + 1;
        }
    }
    return answer;
}