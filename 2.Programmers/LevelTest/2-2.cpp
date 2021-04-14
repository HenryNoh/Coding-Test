#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int answer = 0;
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] <= 'N')
            answer += name[i] - 'A';
        else
            answer += 'Z' - name[i] + 1;
    }
    int idx;
    if (name[1] == 'A')
    {
        idx = 1;
        for (int i = 1; i < name.size(); i++)
        {
            if (name[i] == 'A')
                idx = i;
            else
                break;
        }
        answer = answer + name.size() - 1 - idx;
    }
    else if (name[name.size() - 1] == 'A')
    {
        idx = name.size() - 1;
        for (int i = name.size() - 1; i >= 0; i--)
        {
            if (name[i] == 'A')
                idx = i;
            else
                break;
        }
        answer = answer + idx - 1;
    }
    else
        answer += name.size() - 1;
    cout << answer;
    return answer;
}

int main()
{
    string name = "BABAAAAAAB";
    solution(name);
}