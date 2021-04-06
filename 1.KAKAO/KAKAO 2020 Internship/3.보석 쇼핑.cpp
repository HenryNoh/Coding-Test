#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	// 초기에 답은 최대값
	vector<int> answer = { 1,(int)gems.size() };
	// 중복값을 체크할 SET
	set<string> check;
	// 보석이름과 개수를 넣어주는 map
	map<string, int> m;
	//처음에 gems를 다 넣어줘서 개수 파악
	for (string i : gems) check.insert(i);

	int max = gems.size(); // 현재 모든게 담긴 최대길이
	int l = 0, r = 0;

	while (true) {
		//보석이 모두 담겼으면
		if (check.size() == m.size()) {
			// 담긴 보석의 길이가 이전보다 작으면 제일 작은걸로 갱신 해주고 (돌면서 더 작은값이 생길수 있으므로 ex 첫번째 1~4 두번째 3~5)
			if (max > r - l) {
				max = r - l; //작으면 갱신
				answer[0] = l + 1; // 처음값은 1개 더해주고
				answer[1] = r; // 마지막값은 그대로 대입
			}
			// 보석이 모두 담겼을 때 map 안에 l번째 보석의 개수가 1개라면 삭제 l++
			if (m[gems[l]] == 1) {
				m.erase(gems[l]);
				l++;
			}
			// 보석이 모두 담겼을 때 map 안에 해당 보석의 개수가 1보다 크다면 1개 줄여주고 l++
			else if (m[gems[l]] > 1) {
				m[gems[l]]--;
				l++;
			}
		}
		// 탐색이 끝났으면
		else if (r == gems.size()) {
			break;
		}
		// 아직 다 안담겼으면
		else {
			m[gems[r]]++;
			r++;
		}
	}
	return answer;
}