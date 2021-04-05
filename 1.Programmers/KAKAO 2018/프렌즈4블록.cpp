#include <string>
#include <vector>
#include <set>

using namespace std;

int check(int x, int y, vector<string> board)
{
    if (!board[x][y])
        return 0;
    if (board[x][y] != board[x][y + 1])
        return 0;
    if (board[x][y] != board[x + 1][y])
        return 0;
    if (board[x][y] != board[x + 1][y + 1])
        return 0;
    return 1;
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    int flag;
    vector<string> temp;
    for (int i = 0; i < n; i++)
    {
        string tmp = "";
        for (int j = m - 1; j >= 0; j--)
        {
            tmp = tmp + board[j][i];
        }
        temp.push_back(tmp);
    }

    do
    {
        flag = 0;
        set<pair<int, int>> s;
        for (int i = 0; i < temp.size() - 1; i++)
        {
            if (temp[i].size() <= 0)
                continue;
            for (int j = 0; j < temp[i].size() - 1; j++)
            {
                if (check(i, j, temp))
                {
                    s.insert(make_pair(i, j));
                    s.insert(make_pair(i, j + 1));
                    s.insert(make_pair(i + 1, j));
                    s.insert(make_pair(i + 1, j + 1));
                    flag = 1;
                }
            }
        }
        for (auto iter = s.rbegin(); iter != s.rend(); iter++)
        {
            temp[iter->first].erase(temp[iter->first].begin() + iter->second);
            answer++;
        }
    } while (flag);
    return answer;
}