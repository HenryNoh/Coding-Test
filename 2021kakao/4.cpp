#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> v;
vector<int> g_trap;

int sum;
int answer;

void dfs(int n, int s, int e)
{
    cout << s << e << sum << endl;
    if (s == e)
    {
        if (sum < answer)
            answer = sum;
        return;
    }
    else
    {
        if (g_trap[s] == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (map[s][i] != 0)
                {
                    map[i][s] = map[s][i];
                    map[s][i] = 0;
                }
                else if (map[i][s] != 0)
                {
                    map[s][i] = map[i][s];
                    map[i][s] = 0;
                }
            }
        }

        for (int i = 1; i < map.size(); i++)
        {
            for (int j = 1; j < map.size(); j++)
                cout << map[i][j] << " ";
            cout << endl;
        }

        for (int i = 1; i < v.size(); i++)
        {
            for (int j = 1; j < v.size(); j++)
                cout << v[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < map[s].size(); i++)
        {
            if (map[s][i] != 0 && v[s][i] == 0)
            {
                v[s][i] = 1;
                sum += map[s][i];
                dfs(n, i, e);
                sum -= map[s][i];
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps)
{
    answer = 2000000000;
    sum = 0;
    map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    v = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    g_trap = vector<int>(n + 1, 0);

    for (int i = 0; i < roads.size(); i++)
        map[roads[i][0]][roads[i][1]] = roads[i][2];
    for (int i = 0; i < traps.size(); i++)
        g_trap[traps[i]] = 1;
    dfs(n, start, end);
    cout << answer;
    return answer;
}

int main()
{
    int n = 4, s = 1, e = 4;
    vector<vector<int>> roads = {{1, 2, 1},
                                 {3, 2, 1},
                                 {2, 4, 1}};
    vector<int> trap = {2, 3};

    solution(n, s, e, roads, trap);
}