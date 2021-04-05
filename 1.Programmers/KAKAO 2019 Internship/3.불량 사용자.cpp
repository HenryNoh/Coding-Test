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
	if (b_ind >= b_size) {// if b_ind를 늘리면서 재귀를 해줄것인데 이게 b_id 의 사이즈와 같아지면 탈출!
		string temp = "";
		// 탈출할때 check가 걸려있는것들은 
		for (int i = 0; i < u_id.size(); i++) {
			if (check[i]) {
				//temp에 저장 후 
				temp += i;
			}
		}
		//set에 넣어주고
		_set.insert(temp);
		return;
		//return
	}
	for (int i = 0; i < u_size; i++) {
		// if 사이즈가 다르고 check[i]면(해당 id를 다른 b_id가 쓰고있으면) continue
		if (b_id[b_ind].size() != u_id[i].size() || check[i]) {
			continue;
		}
		// check = true 
		bool tmp = true;

		// 사이즈가 같으면
		// for u_id의 인덱스만큼 돌려줌
		for (int j = 0; j < u_id[i].size(); j++) {
			// if b_id의 인덱스가 *면 continue
			if (b_id[b_ind][j] == '*') {
				continue;
			}
			// if u_id의 인덱스와 b_id의 인덱스가 다르면 check = false , break;
			if (u_id[i][j] != b_id[b_ind][j]) {
				tmp = false;
				break;
			}
		}

		// if check = true면
		if (tmp) {
			// 지금것은 재귀를 해서 들어갔을때 다른 b_id가 사용하면 안되므로 check[i]를 true로
			check[i] = true;
			// dfs(b_ind+1(현재것에 다음 불량사용자),u_id,b_id)
			dfs(u_id, b_id, b_ind + 1);
			// 다하고 나오면 지금 b_id는 다음번에 사용해야 하므로 check[i]를 false로
			check[i] = false;
		}
	}
}

int solution(vector<string> u_id, vector<string> b_id) {

	dfs(u_id, b_id, 0);
	int answer = _set.size();
	return answer;
}