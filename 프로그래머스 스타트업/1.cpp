//13:00
//13:20
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter);

vector<int> solution(string code, string day, vector<string> data)
{
    vector<int> answer;
    vector<vector<string>> result;

    for (int i = 0; i < data.size(); i++)
    {
        string test = data[i];
        vector<string> temp = split(test, ' ');
        result.push_back(temp);
    }
    vector<pair<string, string>> s;
    for (int i = 0; i < result.size(); i++)
    {
        if (code == result[i][1].substr(5) && day == result[i][2].substr(5, 8))
            s.push_back(make_pair(result[i][2].substr(5), result[i][0].substr(6)));
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        answer.push_back(stoi(s[i].second));

    return answer;
}
vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
        answer.push_back(temp);

    return answer;
}

int main()
{
    vector<string> data = {"price=80 code=987654 time=2019062113", "price=90 code=012345 time=2019062014", "price=120 code=987654 time=2019062010", "price=110 code=012345 time=2019062009", "price=95 code=012345 time=2019062111"};
    solution("012345", "20190620", data);
}