#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int compare(vector<vector<int>> map, vector<vector<int>> cmp, int i, int j, int k)
{
    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < i; b++)
        {
            if (map[a + j][b + k] != cmp[a][b])
                return 0;
        }
    }
    return 1;
}

int main()
{
    vector<int> size;
    int n, cnt;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<vector<int>> cmp(i, vector<int>(i));
        cnt = 0;
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
                cmp[j][k] = 1;
        }
        for (int j = 0; j <= n - i; j++)
        {
            for (int k = 0; k <= n - i; k++)
            {
                cnt += compare(map, cmp, i, j, k);
            }
        }
        size.push_back(cnt);
    }
    int total = 0;
    for (int i = 0; i < size.size(); i++)
        total += size[i];
    cout << "total: " << total << endl;
    for (int i = 0; i < size.size(); i++)
    {
        if (size[i] != 0)
            cout << "size[" << i + 1 << "]: " << size[i] << endl;
    }
    return 0;
}