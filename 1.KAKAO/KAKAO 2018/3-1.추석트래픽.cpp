#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;
    int temp = 0;
    int max = 0;
    vector<pair<double, double>> times;
    for (int i = 0; i < lines.size(); i++)
    {
        double after = (((lines[i][11] - '0') * 36000) +
                        ((lines[i][12] - '0') * 3600) +
                        ((lines[i][14] - '0') * 600) +
                        ((lines[i][15] - '0') * 60) +
                        ((lines[i][17] - '0') * 10) +
                        ((lines[i][18] - '0')) +
                        ((lines[i][20] - '0') * 0.1) +
                        ((lines[i][21] - '0') * 0.01) +
                        ((lines[i][22] - '0') * 0.001));
        double before = after - ((lines[i][24] - '0'));
        if (isdigit(lines[i][26]))
            before -= (lines[i][26] - '0') * 0.1;
        if (isdigit(lines[i][27]))
            before -= (lines[i][27] - '0') * 0.01;
        if (isdigit(lines[i][28]))
            before -= (lines[i][28] - '0') * 0.001;
        times.push_back(make_pair(before + 0.001, after));
    }
    sort(times.begin(), times.end());
    for (int i = 0; i < times.size(); i++)
    {
        temp = 0;
        double s = times[i].second;
        double e = s + 0.999;
        for (int j = i; j < times.size(); j++)
        {
            if (times[j].second <= s || times[j].first >= e)
                continue;
            temp++;
        }
        cout << temp << endl;
        if (max < temp)
            max = temp;
        printf("%lf %lf \n", times[i].first, times[i].second);
    }

    // cout << times[i].first << " " << times[i].second << endl;
    cout << max;
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