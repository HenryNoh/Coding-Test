#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int nSize = numbers.size();
	int Lx = 3; int Ly = 1; int Rx = 3; int Ry = 3; int x = 0; int y = 0;
	for (int i = 0; i < nSize; i++) {
		if (numbers[i] == 0 || numbers[i] % 3 == 2) {
			if (numbers[i] == 0) {
				x = 3; y = 2;
			}
			else if (numbers[i] % 3 == 2) {
				x = numbers[i] / 3;
				y = numbers[i] % 3;
			}
			if (abs(Lx - x) + abs(Ly - y) < abs(Rx - x) + abs(Ry - y)) {
				answer += "L";
				Lx = x; Ly = y;
			}
			else if (abs(Lx - x) + abs(Ly - y) > abs(Rx - x) + abs(Ry - y)) {
				answer += "R";
				Rx = x; Ry = y;
			}
			else {
				if (hand == "right") {
					answer += "R";
					Rx = x; Ry = y;
				}
				else if (hand == "left") {
					answer += "L";
					Lx = x; Ly = y;
				}
			}
		}
		else if (numbers[i] % 3 == 1) {
			answer += "L";
			Lx = numbers[i] / 3;
			Ly = 1;
		}
		else if (numbers[i] % 3 == 0) {
			answer += "R";
			Rx = numbers[i] / 4;
			Ry = 3;
		}
	}
	return answer;
}