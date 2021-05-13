#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> board;

int n;

int calCost(int dir, int i)
{
    if ((dir == 1 || dir == 2) && (i == 0 || i == 3))
        return 600;
    if ((dir == 0 || dir == 3) && (i == 1 || i == 2))
        return 600;
    return 100;
}

void dfs(int x, int y, int dir)
{
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    if (x == n - 1 && y == n - 1)
        return;
    for (int i = 0; i < 4; i++)
    {
        int curx = x + dx[i];
        int cury = y + dy[i];
        if (curx < 0 || cury < 0 || curx >= n || cury >= n || board[curx][cury])
            continue;
        int cost = calCost(dir, i);
        if (dp[curx][cury] < dp[x][y] + cost)
            continue;
        dp[curx][cury] = dp[x][y] + cost;
        dfs(curx, cury, i);
    }
}

int solution(vector<vector<int>> b)
{
    n = b.size();
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 2000000000));
    board = b;
    dp[0][0] = 0;
    dfs(0, 0, -1);
    return dp[n - 1][n - 1];
}

int main()
{
    vector<vector<int>> b = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    solution(b);
}

// #include <bits/stdc++.h>

// using namespace std;

// class Car{
//     public:
//     int x,y,cost, dir;
// };

// int solution(vector<vector<int>> board) {
//     int answer = 999999999, mx[] = {0,1,0,-1}, my[] = {1,0,-1,0}, N = board.size();
//     queue<Car> q;
//     Car c;
//     c.x = 0, c.y = 0, c.cost = 0, c.dir = 10;
//     q.push(c);
//     board[0][0] = 1;

//     while(!q.empty())
//     {
//         Car a = q.front();
//         q.pop();
//         if(a.x == N - 1 && a.y == N - 1)
//         {
//             if(answer > a.cost) answer = a.cost;
//             continue;
//         }
//         for(int i=0;i<4;i++)
//         {
//             int nx = a.x + mx[i];
//             int ny = a.y + my[i];

//             if( nx<0 || ny<0 || nx>=N || ny>=N || board[nx][ny] == 1) continue;

//             int nc = 0;

//             if(a.dir == 10 || a.dir == i)
//                 nc = a.cost + 100;
//             else if(a.dir != i)
//                 nc = a.cost + 600;

//             if(board[nx][ny] == 0 || board[nx][ny] >= nc)
//             {
//                 board[nx][ny] = nc;
//                 Car p;
//                 p.x = nx, p.y = ny, p.cost = nc, p.dir = i;
//                 q.push(p);
//             }
//         }

//     }
//     return answer;
// }
