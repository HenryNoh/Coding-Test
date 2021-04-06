#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    vector<pair<int, int>> ans;
    string temp;
    char input[100];
    int n, a, b;
    cin >> n;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        string c = "";
        string d = "";
        for (int j = 0; j < 2; j++)
            c.push_back(temp[j]);
        a = stoi(c);
        c = "";
        for (int j = 3; j < 5; j++)
            c.push_back(temp[j]);
        a = a * 60 + stoi(c);
        for (int j = 8; j < 10; j++)
            d.push_back(temp[j]);
        b = stoi(d);
        d = "";
        for (int j = 11; j < 13; j++)
            d.push_back(temp[j]);
        b = b * 60 + stoi(d);
        ans.push_back(make_pair(a, b));
    }
    int max = 0;
    int min = 1440;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].first > max)
            max = ans[i].first;
        if (ans[i].second < min)
            min = ans[i].second;
    }
    if (max > min)
        cout << "-1";
    else
    {
        if (max / 60 < 10)
            cout << "0";
        cout << max / 60 << ":";
        if (max % 60 < 10)
            cout << "0";
        cout << max % 60 << " ~ ";
        if (min / 60 < 10)
            cout << "0";
        cout << min / 60 << ":";
        if (min % 60 < 10)
            cout << "0";
        cout << min % 60;
    }
    return 0;
}