#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    int flg;
    int cnt;
    vector<int> answer;
    // info¸¦ ³ª´®
    vector<vector<string>> info_split;
    for (int i = 0; i < info.size(); i++)
    {
        string stringBuffer;
        istringstream is(info[i]);
        vector<string> tmp;
        while (getline(is, stringBuffer, ' '))
        {
            tmp.push_back(stringBuffer);
        }
        info_split.push_back(tmp);
    }
    for (int i = 0; i < query.size(); i++)
    {
        cnt = 0;
        string stringBuffer;
        vector<string> query_split;
        istringstream qs(query[i]);
        while (getline(qs, stringBuffer, ' '))
        {
            if (stringBuffer != "and")
                query_split.push_back(stringBuffer);
        }
        for (int j = 0; j < info.size(); j++)
        {
            flg = 1;
            for (int k = 0; k < 4; k++)
            {
                if (query_split[k] == "-")
                    continue;
                if (query_split[k] != info_split[j][k])
                    flg = 0;
            }
            if (flg && (stoi(query_split[4]) <= stoi(info_split[j][4])))
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}