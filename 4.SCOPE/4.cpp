#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<string, pair<string, pair<int, double>>> a, pair<string, pair<string, pair<int, double>>> b)
{
    if (a.first == b.first)
    {
        return a.second.second.second > b.second.second.second;
    }
    else
        return a.first > b.first;
}

int main()
{
    vector<pair<string, double>> p(5);
    for (int i = 0; i < 5; i++)
    {
        p[i].first = 'A' + i;
        cin >> p[i].second;
    }
    int x, y;
    cin >> x >> y;
    vector<pair<string, pair<string, pair<int, double>>>> infos(x * y);
    for (int i = 0; i < infos.size(); i++)
    {
        if (i % y == 0)
            getchar();
        char c;
        scanf("%c", &c);
        infos[i].first = c;
    }
    for (int i = 0; i < infos.size(); i++)
    {
        if (i % y == 0)
            getchar();
        char c;
        scanf("%c", &c);
        infos[i].second.first = c;
    }
    for (int i = 0; i < infos.size(); i++)
    {
        infos[i].second.second.first = i;
        for (int k = 0; k < 5; k++)
        {
            if (infos[i].second.first == p[k].first)
                infos[i].second.second.second = p[k].second;
        }
    }
    for (int i = 0; i < infos.size();)
    {
        if (infos[i].first == "W")
            infos.erase(infos.begin() + i);
        else
            i++;
    }
    sort(infos.begin(), infos.end(), cmp);
    for (int i = 0; i < infos.size(); i++)
    {
        cout << infos[i].second.first << " ";
        printf("%.1f ", infos[i].second.second.second);
        cout << infos[i].second.second.first / y << " " << infos[i].second.second.first % y << endl;
    }
    return 0;
}
