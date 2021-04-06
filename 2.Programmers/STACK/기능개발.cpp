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

	//ó���� ������ �� ������ �ִ´�
	//n��° ���� ���� stack�� �ִ� ���ں��� ������ stack�� ++
	//n��° ���� ���� stack�� �ִ� ���ں��� ũ�ٸ� stack+1�� ++

	return answer;
}