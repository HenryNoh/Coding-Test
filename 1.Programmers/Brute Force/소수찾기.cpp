#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int prime(int number) {
	bool isPrime = true;
	if (number <= 1) {
		return 0;
	}
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime) return 1; else return 0;
}

int solution(string numbers) {
	vector<int> number;
	vector<int> num_vec;
	int answer = 0;

	for (int i = 0; i < numbers.size(); i++) {
		number.push_back(numbers[i] - '0');
	}
	sort(number.begin(), number.end());

	do {
		int temp = 0;
		for (int i = 0; i < number.size(); i++)
		{
			temp = temp * 10 + number[i];
			num_vec.push_back(temp);
		}
	} while (next_permutation(number.begin(), number.end()));

	sort(num_vec.begin(), num_vec.end());
	num_vec.erase(unique(num_vec.begin(), num_vec.end()), num_vec.end());

	for (int i = 0; i < num_vec.size(); i++) {
		answer += prime(num_vec[i]);
	}
	return answer;
}