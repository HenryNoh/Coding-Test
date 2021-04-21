#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans, s;
vector<ll> a;
vector<int> adj[300001];

void go(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            cout << v << endl;
            continue;
        }
        if (adj[v].size() != 1)
            go(v, u);
        ans += abs(a[v]);
        a[u] += a[v], a[v] = 0;
    }
}

ll solution(vector<int> A, vector<vector<int>> edges)
{
    for (int i : A)
        a.push_back((ll)i);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    bool allz = 1;
    for (ll i : a)
        s += i, allz &= (i == 0);
    if (allz)
        return 0;
    if (s != 0)
        return -1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    go(0, -1);
    return ans;
}

int main()
{
    vector<int> a = {-5, 0, 2, 1, 2};
    vector<vector<int>> ed = {{0, 1}, {3, 4}, {2, 3}, {0, 3}};
    solution(a, ed);
}