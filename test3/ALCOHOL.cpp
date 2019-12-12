#include <iostream>
using namespace std;
int T;
int B, L, N;
double glass[2][100000];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 100000; j++) {
				glass[i][j] = 0;
			}
		}
		cin >> B >> L >> N;
		bool turn = false;
		glass[turn][1] = 7.0 * B;
		for (int i = 1; i < L; i++) {
			int number = 1;
			for (int j = 1; j <= i; j++) {
				for (int k = 1; k <= j; k++) {
					double dump = glass[turn][number] - 1;
					if (dump > 0) {
						glass[!turn][number] += dump / 3;
						glass[!turn][number + j] += dump / 3;
						glass[!turn][number + j + 1] += dump / 3;
					}
					glass[turn][number] = 0;
					number++;
				}
			}
			turn = !turn;
		}
		if (glass[turn][N] >= 1.0) {
			cout << 1 << endl;
		}
		else if (glass[turn][N] > 0) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}