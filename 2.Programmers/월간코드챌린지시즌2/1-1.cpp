#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<bool> s)
{
    int answer = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (s[i])
            answer += a[i];
        else
            answer += -1 * a[i];
    }
    return answer;
}