//1:29
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<vector<int>> money(n + 1, vector<int>(n + 1, 30000000));
    for (int i = 1; i <= n; i++)
        money[i][i] = 0;
    for (int i = 0; i < fares.size(); i++)
    {
        money[fares[i][0]][fares[i][1]] = fares[i][2];
        money[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (money[j][i] + money[i][k] < money[j][k])
                    money[j][k] = money[j][i] + money[i][k];
            }
        }
    }
    int min = 30000000;
    for (int i = 1; i <= n; i++)
    {
        if (money[i][s] + money[i][a] + money[i][b] < min)
            min = money[i][s] + money[i][a] + money[i][b];
    }
    return min;
}

int main()
{
    int n = 6, s = 4, a = 2, b = 6;
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    solution(n, s, a, b, fares);
}