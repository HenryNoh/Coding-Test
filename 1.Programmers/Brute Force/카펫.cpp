vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<pair<int, int>> temp;
	int sum = brown + yellow;
	for (int i = 3; i <= sqrt(sum); i++) {
		if (sum%i == 0) {
			temp.push_back(make_pair(i, sum / i));
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		if (((temp[i].first + temp[i].second - 2) * 2) == brown) {
			if (temp[i].first > temp[i].second) {
				answer.push_back(temp[i].first);
				answer.push_back(temp[i].second);
			}
			else {
				answer.push_back(temp[i].second);
				answer.push_back(temp[i].first);
			}
		}
	}
	return answer;
}