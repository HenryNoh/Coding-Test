#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp(1);
	int len = progresses.size();
	int cnt, answer_index;
	for (int i = 0; i < len; i++) {
		cnt = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];
			cnt++;
		}
		if (i == 0) {
			temp.push_back(cnt);
			answer.push_back(1);
			answer_index = 0;
		}
		else {
			if (cnt <= temp.back()) {
				answer[answer_index]++;
			}
			else {
				temp.push_back(cnt);
				answer.push_back(1);
				answer_index++;
			}
		}
	}

	//처음에 들어오는 건 무조건 넣는다
	//n번째 들어온 값이 stack에 있는 숫자보다 작으면 stack값 ++
	//n번째 들어온 값이 stack에 있는 숫자보다 크다면 stack+1값 ++

	return answer;
}