#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p)
{
    stack<char> check;
    string answer = "";
    string temp = "";
    string u = "";
    string v = "";
    int cnt = 0;
    int p_cnt = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
        {
            cnt++;
            check.push(p[i]);
            p_cnt++;
        }
        else if (p[i] == ')')
        {
            cnt--;
            if (!check.empty() && check.top() == '(')
            {
                check.pop();
            }
            p_cnt++;
        }

        if (check.empty() && cnt == 0)
        {
            u = p.substr(0, p_cnt);
            v = p.substr(p_cnt);
            answer = answer + u;
            answer = answer + solution(v);
            break;
        }
        else if (!check.empty() && cnt == 0)
        {
            u = p.substr(0, p_cnt);
            v = p.substr(p_cnt);
            temp += '(';
            temp += solution(v);
            temp += ')';
            u.erase(u.begin());
            u.erase(u.end() - 1);
            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == '(')
                {
                    u[i] = ')';
                }
                else
                {
                    u[i] = '(';
                }
            }
            temp += u;
            answer = temp;
            break;
        }
    }
    return answer;
}