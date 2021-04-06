#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	// �ʱ⿡ ���� �ִ밪
	vector<int> answer = { 1,(int)gems.size() };
	// �ߺ����� üũ�� SET
	set<string> check;
	// �����̸��� ������ �־��ִ� map
	map<string, int> m;
	//ó���� gems�� �� �־��༭ ���� �ľ�
	for (string i : gems) check.insert(i);

	int max = gems.size(); // ���� ���� ��� �ִ����
	int l = 0, r = 0;

	while (true) {
		//������ ��� �������
		if (check.size() == m.size()) {
			// ��� ������ ���̰� �������� ������ ���� �����ɷ� ���� ���ְ� (���鼭 �� �������� ����� �����Ƿ� ex ù��° 1~4 �ι�° 3~5)
			if (max > r - l) {
				max = r - l; //������ ����
				answer[0] = l + 1; // ó������ 1�� �����ְ�
				answer[1] = r; // ���������� �״�� ����
			}
			// ������ ��� ����� �� map �ȿ� l��° ������ ������ 1����� ���� l++
			if (m[gems[l]] == 1) {
				m.erase(gems[l]);
				l++;
			}
			// ������ ��� ����� �� map �ȿ� �ش� ������ ������ 1���� ũ�ٸ� 1�� �ٿ��ְ� l++
			else if (m[gems[l]] > 1) {
				m[gems[l]]--;
				l++;
			}
		}
		// Ž���� ��������
		else if (r == gems.size()) {
			break;
		}
		// ���� �� �ȴ������
		else {
			m[gems[r]]++;
			r++;
		}
	}
	return answer;
}