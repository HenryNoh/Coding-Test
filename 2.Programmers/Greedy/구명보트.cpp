#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
    return j < i;
}

int solution(vector<int> p, int limit)
{
    int answer = 0;
    int l = 0, r = p.size() - 1;
    sort(p.begin(), p.end(), compare);
    while (l <= r)
    {
        answer++;
        if (p[l] + p[r] <= limit)
        {
            l++;
            r--;
        }
        else
            l++;
    }
    return answer;
}