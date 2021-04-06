#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1000;
    string temp = "";
    string slice = "";
    int cnt = 1;
    for (int i = 1; i <= s.size() / 2; i++)
    {
        temp = "";
        slice = s.substr(0, i);
        for (int j = i; j <= s.size(); j += i)
        {
            if (s.compare(j, i, slice) == 0)
            {
                cnt++;
            }
            if (s.compare(j, i, slice) != 0)
            {
                if (cnt >= 2)
                {
                    if (cnt >= 10)
                    {
                        while (cnt >= 10)
                        {
                            temp += cnt % 10 + '0';
                            cnt = cnt / 10;
                        }
                        temp += cnt + '0';
                    }
                    else
                    {
                        temp += cnt + '0';
                    }
                }
                temp += slice;
                if (j + i > s.size())
                {
                    slice = s.substr(j, s.size() - 1);
                    temp += slice;
                }
                cnt = 1;
            }
            slice = s.substr(j, i);
        }
        if (temp.size() < answer)
        {
            answer = temp.size();
        }
    }
    if (answer == 1000)
    {
        answer = 1;
    }
    return answer;
}