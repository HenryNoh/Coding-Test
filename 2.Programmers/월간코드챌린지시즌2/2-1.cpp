#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        stack<char> a;
        int flg = 0;
        for (int j = 0; j < size; j++)
        {
            if (s[j] == '{' || s[j] == '[' || s[j] == '(')
            {
                a.push(s[j]);
                flg = 1;
            }
            if (s[j] == '}' && a.top() == '{')
                a.pop();
            if (s[j] == ']' && a.top() == '[')
                a.pop();
            if (s[j] == ')' && a.top() == '(')
                a.pop();
        }
        if (a.empty() && flg == 1)
            answer++;
        char c = s[0];
        for (int i = 0; i < size - 1; i++)
            s[i] = s[i + 1];
        s[size - 1] = c;
    }
    return answer;
}

int main()
{
    string s = "[](){}";
    solution(s);
}