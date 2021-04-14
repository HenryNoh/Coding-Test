#include <string>
#include <vector>

using namespace std;

int DFS(int i, int j, vector<vector<int>> c, vector<int> m)
{
    if (i == j)
        return 1;
    else
    {
        DFS(i, j + 1, )
    }
}

int solution(int n, vector<vector<int>> c)
{
    int answer = 0;
    vector<int> m(200, 0);
    for (int i = 0; i < n; i++)
    {
        if (!m[i])
            DFS(i, j, c, m);
    }
    return answer;
}