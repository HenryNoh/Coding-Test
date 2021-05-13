#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;
    string temp = "";
    map<string, int> p;
    p.insert(pair<string, int>("zero", 0));
    p.insert(pair<string, int>("one", 1));
    p.insert(pair<string, int>("two", 2));
    p.insert(pair<string, int>("three", 3));
    p.insert(pair<string, int>("four", 4));
    p.insert(pair<string, int>("five", 5));
    p.insert(pair<string, int>("six", 6));
    p.insert(pair<string, int>("seven", 7));
    p.insert(pair<string, int>("eight", 8));
    p.insert(pair<string, int>("nine", 9));

    for (int i = 0; i < s.size(); i++)
    {
        // char c = s[i];
        if (isalpha(s[i]) != 0)
        {
            temp += s[i];
            for (auto iter = p.begin(); iter != p.end(); iter++)
            {
                if (temp == (*iter).first)
                {
                    answer = answer * 10 + (*iter).second;
                    cout << "*****" << answer << "*****" << endl;
                    temp = "";
                    break;
                }
            }
        }
        if (isdigit(s[i]) != 0)
        {
            temp = s[i];
            answer = answer * 10 + stoi(temp);
            temp = "";
        }
    }
    // cout << answer;
    return answer;
}

int main()
{
    string s = "one4seveneight";
    solution(s);
}
