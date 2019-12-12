#include <iostream>
using namespace std;
int yellowOnBox[1013];
int redOnBox[1013];
int totalOnBox[1013];
int redUsed[1000];
int number[1000];
int T;
int N, oneMillionWon;
int Fk(int Xk) {
	return (Xk % 1013);
}
int Sk(int Xk) {
	return (37 - (Xk % 37));
}
bool game(int idx) {
	int xk = number[idx];
	int fk = Fk(xk);
	if (totalOnBox[fk] == 0) {
		yellowOnBox[fk]++;
		totalOnBox[fk]++;
		return (fk == oneMillionWon);
	}
	else {
		yellowOnBox[fk]++;
		totalOnBox[fk]++;
		int prevFk = fk;
		fk = (fk + Sk(xk)) % 1013;
		while (totalOnBox[fk] != 0) {
			redOnBox[fk]++;
			totalOnBox[fk]++;
			redUsed[idx]++;
			fk = (fk + Sk(xk)) % 1013;
			if (fk == prevFk) {
				return false;
			}
		}
		redOnBox[fk]++;
		totalOnBox[fk]++;
		redUsed[idx]++;
		return (fk == oneMillionWon);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 1013; i++) {
			yellowOnBox[i] = 0;
			redOnBox[i] = 0;
			totalOnBox[i] = 0;
		}
		for (int i = 0; i < 1000; i++) {
			redUsed[i] = 0;
		}
		cin >> N >> oneMillionWon;
		for (int i = 0; i < N; i++) {
			cin >> number[i];
		}
		bool isCan = false;
		for (int i = 0; i < N; i++) {
			isCan = game(i);
			if (isCan) {
				cout << (1000000 - 10000 * redUsed[i]) << endl;
				break;
			}
		}
		if (!isCan) {
			cout << "N" << endl;
		}
	}
}