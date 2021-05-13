#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;
    vector<pair<int, int>> t;
    vector<int> count;
    for (int i = 0; i < lines.size(); i++)
    {
        string tmp1 = "";
        tmp1 = tmp1 + lines[i][11] + lines[i][12];
        int h = (stoi(tmp1)) * 3600000;
        tmp1 = "";
        tmp1 = tmp1 + lines[i][14] + lines[i][15];
        int m = (stoi(tmp1)) * 60000;
        tmp1 = "";
        tmp1 = tmp1 + lines[i][17] + lines[i][18] + lines[i][20] + lines[i][21] + lines[i][22];
        int s = (stoi(tmp1));

        string tmp2 = "";
        tmp2 = tmp2 + lines[i][24];
        (!isdigit(lines[i][26])) ? tmp2 += '0' : tmp2 += lines[i][26];
        (!isdigit(lines[i][27])) ? tmp2 += '0' : tmp2 += lines[i][27];
        (!isdigit(lines[i][28])) ? tmp2 += '0' : tmp2 += lines[i][28];
        t.push_back(make_pair(h + m + s - stoi(tmp2) + 1, h + m + s));
        // sort¸¦ ÇÏ¸é ¾ÈµÊ ¹®Á¦°¡ »ý±è
        // sort(t.begin(), t.end());
    }

    for (int i = 0; i < t.size(); i++)
    {
        int s = t[i].second;
        int e = s + 1000;
        int cnt = 0;
        for (int j = i; j < t.size(); j++)
        {
            if (t[j].first < e)
                cnt++;
        }
        if (answer < cnt)
            answer = cnt;
    }

    return answer;
}

int main()
{
    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s",
                            "2016-09-15 20:59:58.233 1.181s",
                            "2016-09-15 20:59:58.299 0.8s",
                            "2016-09-15 20:59:58.688 1.041s",
                            "2016-09-15 20:59:59.591 1.412s",
                            "2016-09-15 21:00:00.464 1.466s",
                            "2016-09-15 21:00:00.741 1.581s",
                            "2016-09-15 21:00:00.748 2.31s",
                            "2016-09-15 21:00:00.966 0.381s",
                            "2016-09-15 21:00:02.066 2.62s"};
    solution(lines);
}