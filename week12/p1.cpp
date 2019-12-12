#include <iostream>
#include <algorithm>
using namespace std;
int cache[100001];
int board[101];
int T;
int N, M;
const int MAX = 987654321;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> board[i];
		}
		cache[0] = 0;
		for (int i = 1; i <= N; i++) {
			cache[i] = MAX;
		}
		for (int i = 1; i <= M; i++) {
			for (int j = board[i]; j <= N; j++) {
				cache[j] = min(cache[j], cache[j - board[i]] + 1);
			}
		}
		if (cache[N] == MAX) {
			cout << 0 << endl;
		}
		else {
			cout << cache[N] << endl;
		}
	}
}