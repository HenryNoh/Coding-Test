#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

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

    //간선 개수 배열 생성 후 정렬
    vector<pair<int, int>> c;
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        for (int j = 0; j < ed.size(); j++)
        {
            if (i == ed[j][0])
                temp++;
            if (i == ed[j][1])
                temp++;
        }
        c.push_back(make_pair(i, temp));
    }
    int e_size = ed.size();
    for (int i = 0; i < e_size; i++)
    {
        vector<int> temp;
        temp.push_back(ed[i][1]);
        temp.push_back(ed[i][0]);
        ed.push_back(temp);
    }
    sort(c.begin(), c.end(), compare);
    int t = 0;
    int i = 0;
    while (ed.size() != 4)
    {
        cout << "i: " << i << endl;
        if (c[t].first == ed[i][0])
        {
            a[ed[i][1]] += a[ed[i][0]];
            answer += abs(a[ed[i][0]]);
            a[ed[i][0]] = 0;
            auto it = find_if(c.begin(), c.end(), ed[i][0]);
            it.second--;
            c[ed[i][1]].second--;
            if (ed[i][0] == ed[i - ed.size() / 2][1] && ed[i][1] == ed[i - ed.size() / 2][0])
            {
                int e_size = ed.size();
                ed.erase(ed.begin() + i);
                ed.erase(ed.begin() + i - e_size / 2);
            }
            else if (ed[i][0] == ed[i + ed.size() / 2][1] && ed[i][1] == ed[i + ed.size() / 2][0])
            {
                int e_size = ed.size();
                ed.erase(ed.begin() + i + e_size / 2);
                ed.erase(ed.begin());
            }
        }
        if (c[t].second == 0)
            t++;
        i++;
        if (i >= ed.size())
            i = 0;
        for (int j = 0; j < c.size(); j++)
            cout << c[j].first << " " << c[j].second << " / ";
        cout << endl;
        for (int j = 0; j < a.size(); j++)
            cout << a[j] << " ";
        cout << endl;
        for (int j = 0; j < ed.size(); j++)
            cout << ed[j][0] << " " << ed[j][1] << " / ";
        cout << endl;
        cout << answer << endl;
    }

    return answer;
}

int main()
{
    vector<int> a = {-5, 0, 2, 1, 2};
    vector<vector<int>> edges = {{0, 1}, {3, 4}, {2, 3}, {0, 3}};
    solution(a, edges);
}

// for (int j = 0; j < size; j++)
// {
//     if (e[c[i].first][j] == 1)
//     {
//         a[j] += a[c[i].first];
//         answer += abs(a[c[i].first]);
//         a[c[i].first] = 0;
//         c[i].second--;
//         c[j].second--;
//         e[c[i].first][j] = 0;
//         e[j][c[i].first] = 0;
//     }
// }

// if (e[c[i].first][j] == 1)
// {
//     a[j] += a[c[i].first];
//     answer += abs(a[c[i].first]);
//     a[c[i].first] = 0;
//     c[i].second--;
//     c[j].second--;
//     e[c[i].first][j] = 0;
//     e[j][c[i].first] = 0;
// }