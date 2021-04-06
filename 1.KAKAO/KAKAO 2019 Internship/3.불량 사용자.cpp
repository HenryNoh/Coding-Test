#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[8];

set<string> _set;

void dfs(vector<string> u_id, vector<string> b_id, int b_ind) {
	int b_size = b_id.size();
	int u_size = u_id.size();
	if (b_ind >= b_size) {// if b_ind�� �ø��鼭 ��͸� ���ٰ��ε� �̰� b_id �� ������� �������� Ż��!
		string temp = "";
		// Ż���Ҷ� check�� �ɷ��ִ°͵��� 
		for (int i = 0; i < u_id.size(); i++) {
			if (check[i]) {
				//temp�� ���� �� 
				temp += i;
			}
		}
		//set�� �־��ְ�
		_set.insert(temp);
		return;
		//return
	}
	for (int i = 0; i < u_size; i++) {
		// if ����� �ٸ��� check[i]��(�ش� id�� �ٸ� b_id�� ����������) continue
		if (b_id[b_ind].size() != u_id[i].size() || check[i]) {
			continue;
		}
		// check = true 
		bool tmp = true;

		// ����� ������
		// for u_id�� �ε�����ŭ ������
		for (int j = 0; j < u_id[i].size(); j++) {
			// if b_id�� �ε����� *�� continue
			if (b_id[b_ind][j] == '*') {
				continue;
			}
			// if u_id�� �ε����� b_id�� �ε����� �ٸ��� check = false , break;
			if (u_id[i][j] != b_id[b_ind][j]) {
				tmp = false;
				break;
			}
		}

		// if check = true��
		if (tmp) {
			// ���ݰ��� ��͸� �ؼ� ������ �ٸ� b_id�� ����ϸ� �ȵǹǷ� check[i]�� true��
			check[i] = true;
			// dfs(b_ind+1(����Ϳ� ���� �ҷ������),u_id,b_id)
			dfs(u_id, b_id, b_ind + 1);
			// ���ϰ� ������ ���� b_id�� �������� ����ؾ� �ϹǷ� check[i]�� false��
			check[i] = false;
		}
	}
}

int solution(vector<string> u_id, vector<string> b_id) {

	dfs(u_id, b_id, 0);
	int answer = _set.size();
	return answer;
}