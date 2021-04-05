#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int bSize = board.size();
	int mSize = moves.size();
	stack<int> baguni;
	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < bSize; j++) {
			if (board[j][moves[i] - 1] != 0) {
				int doll = board[j][moves[i] - 1];
				if (!baguni.empty()) {
					int tmp = baguni.top();
					if (doll == tmp) {
						answer += 2;
						baguni.pop();
					}
					else {
						baguni.push(board[j][moves[i] - 1]);
					}
				}
				else baguni.push(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}
	return answer;
}