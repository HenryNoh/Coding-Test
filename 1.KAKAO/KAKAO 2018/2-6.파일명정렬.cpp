#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b)
{
    if (a.second.first == b.second.first)
    {
        if (a.second.second == b.second.second)
            return a.first < b.first;
        return a.second.second < b.second.second;
    }
    else
        return a.second.first < b.second.first;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<pair<int, pair<string, int>>> file;
    for (int i = 0; i < files.size(); i++)
    {
        string head = "";
        string number = "";
        int num;
        int flg = 0;
        for (int j = 0; j <= files[i].size(); j++)
        {
            if (flg == 0)
            {
                if (isdigit(files[i][j]))
                {
                    flg = 1;
                    number += files[i][j];
                }
                else
                    head += tolower(files[i][j]);
            }
            else
            {
                if (isdigit(files[i][j]))
                    number += files[i][j];
                else
                    break;
            }
        }
        num = stoi(number);
        pair<string, int> p = make_pair(head, num);
        file.push_back(make_pair(i, p));
    }
    sort(file.begin(), file.end(), cmp);
    for (int i = 0; i < file.size(); i++)
        answer.push_back(files[file[i].first]);
    return answer;
}