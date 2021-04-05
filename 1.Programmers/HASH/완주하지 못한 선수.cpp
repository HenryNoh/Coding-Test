#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> p, vector<string> c) {
	string answer = "";

	sort(p.begin(), p.end());
	sort(c.begin(), c.end());
	c.push_back(" ");
	for (int i = 0; i < p.size(); i++) {
		if (p[i].compare(c[i]) != 0) {
			answer = p[i];
			break;
		}
	}

	return answer;
}