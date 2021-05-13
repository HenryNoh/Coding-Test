//10:28
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare1(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}
bool compare2(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> ads)
{
    int answer = 0;
    int size = ads.size();
    int cost = 0;
    int l = 1;
    int r = 0;
    sort(ads.begin(), ads.end(), compare2);
    int first = ads[0][0];
    for (int i = 1; i < ads.size(); i++)
    {
        cost = i * 5;
        for (int j = i; j < ads.size(); j++)
        {
            if (ads[j][0] <= (i * 5) + first)
                r = j;
        }
        // cout << l << " " << r << endl;
        sort(ads.begin() + l, ads.begin() + r + 1, compare1);

        // for (int i = 0; i < size; i++)
        //     cout << ads[i][0] << " " << ads[i][1] << " ";
        // cout << endl;

        ads[i].push_back(first + cost - ads[i][0]);
        // cout << first << " " << cost << " " << ads[i][0] << endl;
        answer += ads[i][1] * ads[i][2];
        l++;
        // cout << answer << endl;
    }
    return answer;
}

int main()
{
    vector<vector<int>> ads1 = {{1, 3}, {3, 2}, {5, 4}};
    vector<vector<int>> ads2 = {{0, 3}, {5, 4}};
    vector<vector<int>> ads3 = {{0, 1}, {0, 2}, {6, 3}, {8, 4}};
    vector<vector<int>> ads4 = {{5, 2}, {2, 2}, {6, 3}, {9, 2}};
    cout << solution(ads1);
}
