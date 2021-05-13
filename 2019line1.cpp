#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int m, int n)
{
    int num = 1;
    int cnt = 0;

    vector<int> m_place;
    m_place.push_back(m);
    queue<pair<int, int>> q;
    q.push(make_pair(n, cnt));

    while (m <= 200000)
    {
        m += num++;
        m_place.push_back(m);
    }
    while (!q.empty())
    {
        int f = q.front().first;
        int s = q.front().second;
        if (f == m_place[s])
            return s;
        q.pop();
        if (n > 200000)
            return -1;
        q.push(make_pair(f + 1, s + 1));
        if (f - 1 >= 0)
            q.push(make_pair(f - 1, s + 1));
        q.push(make_pair(f * 2, s + 1));
    }
    return 0;
}

int main()
{
    int m = 6, n = 3;
    cout << solution(m, n);
}