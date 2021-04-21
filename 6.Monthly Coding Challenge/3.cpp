#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long ans;
vector<long long> g_a;
vector<int> g_e[300001];

void dfs(int s, int m)
{
    for (int i : g_e[s])
    {
        if (i == m)
            continue;
        if (g_e[i].size() != 1)
            dfs(i, s);
        ans += abs(g_a[i]);
        g_a[s] += g_a[i];
        g_a[i] = 0;
    }
}
long long solution(vector<int> a, vector<vector<int>> ed)
{
    for (int i : a)
        g_a.push_back((long long)i);
    for (int i = 0; i < ed.size(); i++)
    {
        g_e[ed[i][0]].push_back(ed[i][1]);
        g_e[ed[i][1]].push_back(ed[i][0]);
    }
    bool allz = 1;
    long long sum = 0;
    for (long long i : a)
        sum += i, allz &= (i == 0);
    if (allz)
        return 0;
    if (sum != 0)
        return -1;
    dfs(0, -1);
    return ans;
}

int main()
{
    vector<int> a = {-5, 0, 2, 1, 2};
    vector<vector<int>> ed = {{0, 1}, {3, 4}, {2, 3}, {0, 3}};
    solution(a, ed);
}