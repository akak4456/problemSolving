#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 987654321;
int T;
int N, M;
int solution[100001];
int plate[100];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		solution[0] = 0;
		for (int i = 1; i <= N; i++)
			solution[i] = MAX;
		for (int i = 0; i < M; i++) {
			cin >> plate[i];
			solution[plate[i]] = 1;
		}
		for (int i = plate[0] + 1; i <= N; i++) {
			int ret = MAX;
			for (int j = 0; j < M; j++) {
				if (i - plate[j] >= 0) {
					ret = min(ret, solution[i - plate[j]]);
				}
			}
			solution[i] = ret + 1;
		}
		if (solution[N] < MAX) {
			cout << solution[N] << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}