#include <string>
#include <vector>

using namespace std;

string rc(int n, int t, string dic)
{
    string tmp;
    if (t / n > 0)
        tmp = rc(n, t / n, dic) + dic[t % n];
    else
    {
        string a = "";
        a += dic[t];
        return a;
    }
    return tmp;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    string str = "";
    string dic = "0123456789ABCDEF";
    int i = 0;
    while (i <= 100000)
    {
        str += rc(n, i, dic);
        i++;
    }
    int cnt = 0;
    i = 0;
    while (i < str.size())
    {
        if (cnt == t)
            break;
        if (i % m == p - 1)
        {
            answer += str[i];
            cnt++;
        }
        i++;
    }
    return answer;
}