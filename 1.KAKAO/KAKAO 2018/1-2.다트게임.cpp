#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string dart)
{
    int ans = 0;
    int tmp[3];
    int num;
    int n;
    int i = 0;
    int j = 0;
    while (i < 3)
    {
        n = 1;
        num = dart[j] - '0';
        if (dart[j] == '1' && dart[j + 1] == '0')
        {
            num = 10;
            j++;
        }
        if (dart[j + 1] == 'D')
            n = 2;
        else if (dart[j + 1] == 'T')
            n = 3;
        tmp[i] = pow(num, n);
        if (dart[j + 2] == '*')
        {
            if (i == 0)
                tmp[i] *= 2;
            else
            {
                tmp[i] *= 2;
                tmp[i - 1] *= 2;
            }
            j++;
        }
        else if (dart[j + 2] == '#')
        {
            tmp[i] *= -1;
            j++;
        }
        j += 2;
        i++;
    }
    ans = tmp[0] + tmp[1] + tmp[2];
    return ans;
}