#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> g_places;

int dis(int a, int b, int c, int d)
{
    return abs(a - b) + abs(c - d);
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    g_places = places;
    for (int i = 0; i < 5; i++)
    {
        vector<pair<int, int>> P;
        int flg = 1;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (places[i][j][k] == 'P')
                    P.push_back(pair<int, int>(j, k));
            }
        }
        for (int j = 0; j < P.size(); j++)
        {
            for (int k = j + 1; k < P.size(); k++)
            {

                int a = P[j].first;
                int b = P[j].second;
                int c = P[k].first;
                int d = P[k].second;
                int distance = dis(a, c, b, d);
                if (distance == 1)
                {
                    flg = 0;
                    break;
                }
                else if (distance == 2)
                {
                    int a = P[j].first;
                    int b = P[j].second;
                    int c = P[k].first;
                    int d = P[k].second;
                    if (a == c && places[i][a][(a + c) / 2] == 'O')
                    {
                        flg = 0;
                        break;
                    }
                    else if (b == d && places[i][b][(b + d) / 2] == 'O')
                    {
                        flg = 0;
                        break;
                    }
                    else if (a != c && b != d && (places[i][a][d] == 'O' || places[i][b][c] == 'O'))
                    {
                        flg = 0;
                        break;
                    }
                }
            }
        }
        if (flg == 0)
            answer.push_back(0);
        else if (flg == 1)
            answer.push_back(1);
    }
    return answer;
}

int main()
{
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        // {"XXXXX", "XXXXX", "XXXXX", "XXXXX", "XXXXX"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    solution(places);
}