#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> numbers, int target, int sign, int depth, int temp)
{
    if (depth == numbers.size())
    {
        if (target == temp)
            answer++;
    }
    else
    {
        if (sign == 0)
            temp -= numbers[depth];
        if (sign == 1)
            temp += numbers[depth];
        dfs(numbers, target, 0, depth + 1, temp);
        dfs(numbers, target, 1, depth + 1, temp);
        if (sign == 0)
            temp += numbers[depth];
        if (sign == 1)
            temp -= numbers[depth];
    }
}

int solution(vector<int> numbers, int target)
{
    answer = 0;
    dfs(numbers, target, 0, 0, 0);
    dfs(numbers, target, 1, 0, 0);
    return answer / 2;
}