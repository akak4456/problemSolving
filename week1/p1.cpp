#include <iostream>
using namespace std;

int T;
int N, M;
int H[1000000];
int solve(int x,int min,int max) {
	int idx = (min + max) / 2;
	if (x == H[idx]) {
		return idx;
	}
	else if (x < H[idx]) {
		return solve(x, min, idx - 1);
	}
	else {
		return solve(x, idx + 1, max);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}
		while (M--) {
			int X;
			cin >> X;
			cout << solve(X,0,N-1)+1 << endl;
		}
	}
}