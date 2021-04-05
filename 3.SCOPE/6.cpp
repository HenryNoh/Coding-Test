#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long> ans;
long long cnt;
int a;
int b;

int check1(int x, int y)
{
    if (x + 1 == a)
        return 0;
    return 1;
}
int check2(int x, int y)
{
    if (y + 1 == b)
        return 0;
    return 1;
}

int dfs(vector<vector<long long>> p, int x, int y, int n)
{
    if ((x + 1) * (y + 1) == n)
    {
        cnt += p[y][x];
        ans.push_back(cnt);
        cnt -= p[y][x];
    }
    else
    {
        cnt += p[y][x];
        if (check1(x, y))
            dfs(p, x + 1, y, n);
        if (check2(x, y))
            dfs(p, x, y + 1, n);
        cnt -= p[y][x];
    }
    return 1;
}

int main()
{
    int x, y;
    cin >> x >> y;
    vector<vector<long long>> p(y, vector<long long>(x));
    cnt = 0;
    a = x;
    b = y;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            cin >> p[i][j];
    }
    dfs(p, 0, 0, x * y);
    long long max = 0;
    for (long long i = 0; i < ans.size(); i++)
    {
        if (ans[i] > max)
            max = ans[i];
    }
    cout << max << endl;
}