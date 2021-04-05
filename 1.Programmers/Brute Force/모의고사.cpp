#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<pair<int, int>> temp;
	temp.push_back(make_pair(1, 0));
	temp.push_back(make_pair(2, 0));
	temp.push_back(make_pair(3, 0));
	vector<int> supo1 = { 1,2,3,4,5 };
	vector<int> supo2 = { 2,1,2,3,2,4,2,5 };
	vector<int> supo3 = { 3,3,1,1,2,2,4,4,5,5 };

	int length = answers.size();
	int j = 0;

	for (int i = 0; i < length; i++) {
		if (answers[i] == supo1[j]) {
			temp[0].second++;
		}
		j++;
		if (j == 5) { j = 0; }
	}
	j = 0;
	for (int i = 0; i < length; i++) {
		if (answers[i] == supo2[j]) {
			temp[1].second++;
		}
		j++;
		if (j == 8) { j = 0; }
	}
	j = 0;
	for (int i = 0; i < length; i++) {
		if (answers[i] == supo3[j]) {
			temp[2].second++;
		}
		j++;
		if (j == 10) { j = 0; }
	}
	for (int i = 0; i < temp.size(); i++) {
		printf("%d %d \n", temp[i].first, temp[i].second);
	}
	sort(temp.begin(), temp.end(), cmp);

	int max = 0;
	max = temp[0].second;
	answer.push_back(temp[0].first);
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].second == max) {
			answer.push_back(temp[i].first);
		}
	}
	return answer;
}

int main() {
	vector<int> answers = { 1,3,2,4,2 };
	vector<int> answer = solution(answers);
	for (int i = 0; i < answer.size(); i++) {
		printf("%d", answer[i]);
	}
}