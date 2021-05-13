// BFS는 너비 우선 탐색이다.
// 주로 최단거리, 최단비용을 구할 때 사용한다.
// 기본적인 원리는 시작 노드와 연결된 주변 노드부터 탐색하는 것이다.

//너비 우선 탐색 기초 예
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> Array, vector<int> v)
{
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        v[cur] = 1;
        cout << cur << " ";
        for (int i = 0; i < Array[cur].size(); i++)
        {
            if (Array[cur][i] == 1 && !v[i])
                q.push(i);
        }
    }
}

int main()
{
    vector<vector<int>> Array = {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}};
    vector<int> v(7, 0);
    BFS(Array, v);
    return 0;
}

//최단 거리 기초 예

//최단 비용 기초 예