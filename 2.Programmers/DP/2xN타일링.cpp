#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for (int i = 4; i <= n; i++)
        a.push_back(((a[i - 2] + a[i - 1]) % 1000000007));
    return a[n];
}