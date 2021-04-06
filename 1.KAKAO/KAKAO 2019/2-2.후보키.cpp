#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_col 8
using namespace std;

bool s[MAX_col];
vector<vector<string>> save;
vector<vector<string>> answers;
vector<string> diff = {"a", "b", "c", "d", "e", "f", "g", "h"};
void print(vector<vector<string>> relation)
{
    bool same_check = false;
    for (int i = 0; i < relation.size(); i++)
    {
        vector<string> temp;
        for (int j = 0; j < relation[0].size(); j++)
        {
            if (s[j] == true)
            {
                temp.push_back(diff[j] + relation[i][j]);
            }
        }
        if (!temp.empty())
        {
            save.push_back(temp);
        }
    }

    for (int i = 0; i < save.size(); i++)
    {
        for (int j = i + 1; j < save.size(); j++)
        {
            if (save[i] == save[j])
            {
                same_check = true;
            }
        }
    }

    if (same_check == false)
    {
        vector<string> temp;
        for (int i = 0; i < save[0].size(); i++)
        {
            temp.push_back(save[0][i]);
        }
        answers.push_back(temp);
    }
    save.clear();
}

void DFS(int idx, int cnt, int max, vector<vector<string>> relation)
{
    if (cnt == max)
    {
        print(relation);
        return;
    }
    for (int i = idx; i < relation[0].size(); i++)
    {
        if (s[i] == true)
            continue;
        s[i] = true;
        DFS(i, cnt + 1, max, relation);
        s[i] = false;
    }
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    int idx = 0, cnt = relation.size();
    for (int i = 1; i <= relation[0].size(); i++)
    {
        DFS(0, 0, i, relation);
    }

    while (answers.size() > 0)
    {
        vector<string> check1 = answers[0];
        answer++;
        for (int i = 0; i < answers.size();)
        {
            vector<string> check2 = answers[i];
            vector<string> check3(100);
            sort(check1.begin(), check1.end());
            sort(check2.begin(), check2.end());
            auto result = set_intersection(check1.begin(), check1.end(), check2.begin(), check2.end(), check3.begin());
            check3.resize(result - check3.begin());

            if (check1 == check3)
            {
                answers.erase(answers.begin() + i);
            }
            else
            {
                i++;
            }
        }
    }
    return answer;
}