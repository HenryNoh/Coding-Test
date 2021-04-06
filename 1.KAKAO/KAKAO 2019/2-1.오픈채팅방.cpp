#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    vector<vector<string>> info;
    map<string, string> user;

    int l, r, k;
    for (int i = 0; i < record.size(); i++)
    {
        vector<string> temp;
        l = 0, r = 0;
        for (int j = 0; j <= record[i].size(); j++)
        {
            if (record[i][j] == ' ' || j == record[i].size())
            {
                r = j;
                temp.push_back(record[i].substr(l, r - l));
                l = j + 1;
            }
        }
        info.push_back(temp);
    }

    for (int i = 0; i < info.size(); i++)
    {
        if (info[i][0] == "Enter" || info[i][0] == "Change")
        {
            user[info[i][1]] = info[i][2];
        }
    }

    for (int i = 0; i < info.size(); i++)
    {
        string temp = "";
        if (info[i][0] == "Enter")
        {
            temp += user[info[i][1]];
            temp += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else if (info[i][0] == "Leave")
        {
            temp += user[info[i][1]];
            temp += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
        else if (info[i][0] == "Change")
        {
            continue;
        }
        answer.push_back(temp);
    }
    return answer;
}