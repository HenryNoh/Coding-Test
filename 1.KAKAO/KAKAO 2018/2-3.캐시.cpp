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
        // 찾았는데 없으면
        if (find(s.begin(), s.end(), cities[i]) == s.end())
        {
            //사이즈보다 작으면 넣고 5더하기
            if (size < cacheSize)
            {
                s.push_back(cities[i]);
                size++;
                answer += 5;
            }
            //사이즈랑 같으면 제일 앞에 없애고 제일 뒤에 넣기
            else if (size == cacheSize)
            {
                if (!s.empty())
                    s.erase(s.begin());
                s.push_back(cities[i]);
                answer += 5;
            }
        }
        // 찾았는데 있으면
        else if (find(s.begin(), s.end(), cities[i]) != s.end())
        {
            //찾은거 없애고 뒤에 넣기
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