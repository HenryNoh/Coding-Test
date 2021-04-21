#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> a, vector<vector<int>> ed)
{
    long long answer = 0;

    // 예외처리
    long long sum = 0;
    int size = a.size();
    for (int i = 0; i < size; i++)
        sum += a[i];
    if (sum != 0)
        return -1;
    //예외처리 끝

    //2차원 배열 생성
    vector<vector<int>> e(size, vector<int>(size, 0));
    for (int i = 0; i < ed.size(); i++)
    {
        e[ed[i][0]][ed[i][1]] = 1;
        e[ed[i][1]][ed[i][0]] = 1;
    }
    //2차원 배열 끝

    vector<pair<int, int>> c;
    //간선 개수 배열 생성 후 정렬
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        for (int j = 0; j < size; j++)
        {
            if (e[i][j] == 1)
                temp++;
        }
        c.push_back(make_pair(i, temp));
    }
    sort(c.begin(), c.end());
    //정렬 끝

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (e[c[i].first][j] == 1)
            {
                a[j] += a[c[i].first];
                answer += abs(a[c[i].first]);
                a[c[i].first] = 0;
                c[i].second--;
                c[j].second--;
                e[c[i].first][j] = 0;
                e[j][c[i].first] = 0;
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> a = {-5, 0, 2, 1, 2};
    vector<vector<int>> edges = {{0, 1}, {3, 4}, {2, 3}, {0, 3}};
    solution(a, edges);
}
