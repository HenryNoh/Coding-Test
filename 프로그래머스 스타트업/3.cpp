//13:42
//14:06
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> m;
int s;

int d(double a, double b, int c, int d)
{
    return abs(a - c) + abs(b - d);
}

int c(double i, double j, double p, int r)
{
    int sum = 0;
    for (int a = 0; a < s; a++)
    {
        for (int b = 0; b < s; b++)
        {
            if (d(i, j, a, b) == r && m[a][b] <= p / 2)
                sum++;
            else if (d(i, j, a, b) < r && m[a][b] <= p)
                sum++;
        }
    }
    return sum;
}

int solution(vector<vector<int>> maps, int power, int range)
{
    vector<int> answer;
    double p = (double)power;
    int r = range / 2;
    m = maps;
    s = maps.size();

    for (double i = -0.5; i <= s - 0.5; i++)
    {
        for (double j = -0.5; j <= s - 0.5; j++)
            answer.push_back(c(i, j, p, r));
    }
    sort(answer.rbegin(), answer.rend());

    return answer[0];
}
