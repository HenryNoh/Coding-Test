#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> answer;
    int temp;
    for (int i = 0; i < array.size(); i++)
    {
        temp = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] > array[i])
            {
                temp = j;
                break;
            }
        }
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] > array[i] && temp == -1)
            {
                temp = j;
                break;
            }
        }
        answer.push_back(temp);
    }

    return answer;
}

//3 5 4 1 2
//1 -1 1 2 2
//1 2 3 4 5
//1 2 3 4 -1
//7 4 4 2 9 6
//4 0 0 2 -1 4
