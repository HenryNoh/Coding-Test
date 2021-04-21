#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> r)
{
    int answer = 1;
    sort(r.begin(), r.end(), compare);
    int e = r[0][1];
    for (int i = 1; i < r.size(); i++)
    {
        if (e >= r[i][0] && e <= r[i][1])
            continue;
        else
        {
            answer++;
            e = r[i][1];
        }
    }
    return answer;
}