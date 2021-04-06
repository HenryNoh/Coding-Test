#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    int a, b, cnt = 0;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = "";
        cnt = 0;
        while (arr1[i] > 0 || arr2[i] > 0)
        {
            a = arr1[i] % 2;
            b = arr2[i] % 2;
            if (a || b)
                tmp.insert(0, "#");
            else
                tmp.insert(0, " ");
            arr1[i] /= 2;
            arr2[i] /= 2;
            cnt++;
        }
        while (cnt++ < n)
            tmp.insert(0, " ");
        answer.push_back(tmp);
    }
    return answer;
}