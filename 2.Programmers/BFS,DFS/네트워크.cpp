#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> networks[201];
vector<int> parent;

void dfs(int num)
{
    for (int i = 0; i < networks[num].size();)
    {
        int tmp = networks[num][i];
        parent[networks[num][i]] = parent[num];
        networks[num].erase(networks[num].begin());
        dfs(tmp);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 1;
    for (int i = 0; i < n; i++)
        parent.push_back(i);
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (computers[i][j] == 1 && i != j)
            {
                if (computers[j][i] == 0)
                {
                    networks[i].push_back(j);
                    networks[j].push_back(i);
                }
                else
                    networks[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!networks[i].empty())
            dfs(i);
    }
    sort(parent.begin(), parent.end());
    int tmp = parent[0];
    for (int i = 0; i < parent.size(); i++)
    {
        if (parent[i] != tmp)
        {
            tmp = parent[i];
            answer++;
        }
    }
    return answer;
}