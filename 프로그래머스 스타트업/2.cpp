// //13:20
// //13:42
// //14:06
// //15:00 왜 안될까????
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
    {
        if (a[2] == b[2])
            return a[0] < b[0];
        return a[2] < b[2];
    }
    return a[1] < b[1];
}

vector<int> solution(vector<int> t, vector<int> r)
{
    vector<int> answer;
    vector<vector<int>> v;
    int size = t.size();

    for (int i = 0; i < size; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(t[i]);
        temp.push_back(r[i]);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i <= 10000; i++)
    {
        // for (int j = 0; j < v.size(); j++)
        //     cout << v[j][0] << " ";
        // cout << endl;
        // for (int j = 0; j < v.size(); j++)
        //     cout << v[j][1] << " ";
        // cout << endl;
        // for (int j = 0; j < v.size(); j++)
        //     cout << v[j][2] << " ";
        // cout << endl;
        // cout << "******************" << endl;

        if (v.empty())
            break;
        else if (v[0][1] > i)
            continue;
        else
        {
            answer.push_back(v[0][0]);
            v.erase(v.begin());
        }
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j][1] < i + 1)
                v[j][1] = i + 1;
        }
        sort(v.begin(), v.end(), compare);
    }

    if (!v.empty())
    {
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size(); i++)
            answer.push_back(v[i][0]);
    }

    // for (int i = 0; i < answer.size(); i++)
    //     cout << answer[i] << " ";

    return answer;
}
int main()
{
    vector<int> t = {9999, 10000, 10000, 10000, 9999, 9998, 9998};
    vector<int> r = {0, 1, 0, 2, 1, 4, 0};

    solution(t, r);
}

//0 1 2 3 4 5 6 7
//0 1 3 0 2 1 3 0
//3 2 1 0 3 2 1 0

//3 1 0 2 7654