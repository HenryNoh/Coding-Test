//10:00
//10:20
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string inputString)
{
    int answer = 0;
    stack<char> s;

    if (inputString[0] == ']' || inputString[0] == '}' || inputString[0] == ')' || inputString[0] == '>')
        return 0;
    for (int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] == '[' || inputString[i] == '{' || inputString[i] == '(' || inputString[i] == '<')
            s.push(inputString[i]);
        if (inputString[i] == ']')
        {
            if (!s.empty() && s.top() == '[')
                answer++;
            else
                return -1 * i;
            s.pop();
        }
        if (inputString[i] == '}')
        {
            if (!s.empty() && s.top() == '{')
                answer++;
            else
                return -1 * i;
            s.pop();
        }
        if (inputString[i] == ')')
        {
            if (!s.empty() && s.top() == '(')
                answer++;
            else
                return -1 * i;
            s.pop();
        }
        if (inputString[i] == '>')
        {
            if (!s.empty() && s.top() == '<')
                answer++;
            else
                return -1 * i;
            s.pop();
        }
    }
    if (!s.empty())
        return -1 * (inputString.size() - 1);
    return answer;
}

int main()
{
    // string inputString = "Hello,wolrd!";
    string inputString = "line [({<plus>)}]";
    cout << solution(inputString);
    // string inputString = "line [({<plus>)}]";
    // cout << solution(inputString);
    // string inputString = "line [({<plus>})";
    // cout << solution(inputString);
}