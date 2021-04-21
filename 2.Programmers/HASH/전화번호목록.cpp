#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> p)
{
    bool answer = true;
    int len = p.size();

    sort(p.begin(), p.end());

    if (p[1].find(p[0]) == 0)
    {
        answer = false;
    }

    return answer;
}