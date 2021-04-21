#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<pair<string, string>> g_t;
vector<bool> v;
int flg;
int length;

void dfs(string start, int depth)
{
    if (depth == length)
    {
        flg = 1;
        return;
    }
    else
    {
        for (int i = 0; i < g_t.size(); i++)
        {
            if (g_t[i].first == start && !v[i])
            {
                v[i] = true;
                answer.push_back(g_t[i].second);
                dfs(g_t[i].second, depth + 1);
                if (flg == 1)
                    return;
                v[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    length = tickets.size();
    flg = 0;
    for (int i = 0; i < tickets.size(); i++)
        v.push_back(false);
    for (int i = 0; i < tickets.size(); i++)
        g_t.push_back(make_pair(tickets[i][0], tickets[i][1]));
    sort(g_t.begin(), g_t.end());
    answer.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}