#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
        return cities.size() * 5;
    int answer = 0;
    vector<string> s;
    int size = s.size();
    for (int i = 0; i < cities.size(); i++)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    for (int i = 0; i < cities.size(); i++)
    {
        // ã�Ҵµ� ������
        if (find(s.begin(), s.end(), cities[i]) == s.end())
        {
            //������� ������ �ְ� 5���ϱ�
            if (size < cacheSize)
            {
                s.push_back(cities[i]);
                size++;
                answer += 5;
            }
            //������� ������ ���� �տ� ���ְ� ���� �ڿ� �ֱ�
            else if (size == cacheSize)
            {
                if (!s.empty())
                    s.erase(s.begin());
                s.push_back(cities[i]);
                answer += 5;
            }
        }
        // ã�Ҵµ� ������
        else if (find(s.begin(), s.end(), cities[i]) != s.end())
        {
            //ã���� ���ְ� �ڿ� �ֱ�
            s.erase(find(s.begin(), s.end(), cities[i]));
            s.push_back(cities[i]);
            answer++;
        }
    }
    return answer;
}

int main()
{
    int cacheSize = 0;
    vector<string> cities = {"Jeju", "Jeju", "Jeju", "a", "a", "b", "jeju"};
    cout << solution(cacheSize, cities);
}