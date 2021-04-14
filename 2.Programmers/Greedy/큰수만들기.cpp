#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int ans_size = number.size() - k;
    while (ans_size != 0)
    {
        int max = 0;
        int idx = 0;
        for (int j = 0; j <= number.size() - ans_size; j++)
        {
            if (number[j] - '0' > max)
            {
                max = number[j] - '0';
                idx = j;
            }
        }
        answer.push_back(number[idx]);
        for (int j = 0; j <= idx; j++)
            number.erase(number.begin());
        ans_size--;
    }
    return answer;
}
int main()
{
    string number = "4177252841";
    int k = 4;
    solution(number, k);
}