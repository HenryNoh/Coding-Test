#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> v;
vector<int> ans;
vector<string> g_w;

bool find_word(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    if (cnt == 1)
        return true;
    else
        return false;
}

void dfs(string begin, string target, int depth)
{
    if (begin == target)
        ans.push_back(depth);
    else
    {
        for (int i = 0; i < g_w.size(); i++)
        {
            if (find_word(begin, g_w[i]) && !v[i])
            {
                v[i] = true;
                dfs(g_w[i], target, depth + 1);
                v[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    for (string a : words)
        g_w.push_back(a);
    for (int i = 0; i < words.size(); i++)
        v.push_back(false);
    dfs(begin, target, 0);
    sort(ans.begin(), ans.end());
    if (ans.empty())
        return answer;
    else
        return ans[0];
}