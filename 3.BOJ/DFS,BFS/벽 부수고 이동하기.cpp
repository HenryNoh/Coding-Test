#include <iostream>
#include <vector>

using namespace std;

void dfs()
{
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << map[i][j];
        cout << endl;
    }
}