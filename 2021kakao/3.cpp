#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        v[i] = i;
    stack<int> s;
    int cur = k;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'D')
        {
            string temp = "";
            for (int j = 2; j < cmd[i].size(); j++)
                temp += cmd[i][j];
            int num = stoi(temp);
            int idx = 0;
            while (idx < num)
            {
                if (v[cur + 1] == -1)
                    cur++;
                else
                {
                    cur++;
                    idx++;
                }
            }
        }
        else if (cmd[i][0] == 'U')
        {
            string temp = "";
            for (int j = 2; j < cmd[i].size(); j++)
                temp += cmd[i][j];
            int num = stoi(temp);
            int idx = 0;
            while (idx < num)
            {
                if (v[cur - 1] == -1)
                    cur--;
                else
                {
                    cur--;
                    idx++;
                }
            }
        }
        else if (cmd[i][0] == 'C')
        {
            if (cur == n - 1)
            {
                v[cur] = -1;
                s.push(cur);
                while (v[cur] == -1)
                    cur--;
            }
            else
            {
                v[cur] = -1;
                s.push(cur);
                while (v[cur] == -1)
                    cur++;
            }
        }
        else if (cmd[i][0] == 'Z')
        {
            int add = s.top();
            s.pop();
            v[add] = add;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] != i)
            answer.push_back('X');
        else
            answer.push_back('O');
    }
    return answer;
}

int main()
{
    int n = 8, k = 1;
    vector<string> cmd = {"C", "C", "U 1", "C"};
    solution(n, k, cmd);
}

//0 1 2 3 4 5 6 7
//0 1 2 3 4 5 6 7

//0  1  2 3 4 5 6 7
//0 -1 -1 3 4 5 6 7
