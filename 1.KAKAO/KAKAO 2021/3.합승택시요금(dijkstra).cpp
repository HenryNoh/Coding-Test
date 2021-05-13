//12:40
//1:10
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> money;
vector<vector<int>> d;
vector<bool> v;

int gsi(int n, int s)
{
    int min = 30000000;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[s][i] < min && !v[i])
        {
            min = d[s][i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int n, int s)
{
    for (int i = 0; i <= n; i++)
        d[s][i] = money[s][i];
    v[s] = true;
    for (int i = 0; i <= n - 2; i++)
    {
        int c = gsi(n, s);
        v[c] = true;
        for (int j = 0; j <= n; j++)
        {
            if (!v[j])
            {
                if (d[s][c] + money[c][j] < d[s][j])
                    d[s][j] = d[s][c] + money[c][j];
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    money = vector<vector<int>>(n + 2, vector<int>(n + 2, 30000000));
    d = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < fares.size(); i++)
    {
        money[fares[i][0]][fares[i][1]] = fares[i][2];
        money[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        v = vector<bool>(n + 2, false);
        dijkstra(n, i);
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; i++)
        result[i] = d[i][s] + d[i][a] + d[i][b];
    sort(result.begin(), result.end());
    return result[1];
}

int main()
{
    int n = 6, s = 4, a = 2, b = 6;
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    solution(n, s, a, b, fares);
}