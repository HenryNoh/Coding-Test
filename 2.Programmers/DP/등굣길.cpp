//10:06
//11:06 retry
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> DP;
vector<vector<int>> V;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    DP = vector<vector<int>>(203, vector<int>(203, 0));
    V = vector<vector<int>>(203, vector<int>(203, 0));
    for (int i = 0; i < puddles.size(); i++)
        V[puddles[i][1]][puddles[i][0]] = -1;
    DP[1][1] = 1;
    //대각선으로 안돌고 그냥 2중 for문으로 돌아도 됨
    for (int i = 3; i <= m + n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int x = j, y = i - j;
            if (V[x - 1][y] == -1 && V[x][y - 1] == -1)
                DP[x][y] = 0;
            else if (V[x - 1][y] == -1)
                DP[x][y] = DP[x][y - 1];
            else if (V[x][y - 1] == -1)
                DP[x][y] = DP[x - 1][y];
            else
                DP[x][y] = (DP[x][y - 1] + DP[x - 1][y]) % 1000000007;
        }
    }
    answer = DP[n][m];
    return answer % 1000000007;
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> puddles = {};
    solution(m, n, puddles);
}