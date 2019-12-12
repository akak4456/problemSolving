#include <iostream>
using namespace std;
int T;
int N;
int M;
int HAIR[1000000];
int binarySearch(int left, int right, int key) {
	if (left > right) {
		return -1;
	}
	else {
		int mid = (left + right) / 2;
		if (key == HAIR[mid]) {
			return mid;
		}
		else if (key < HAIR[mid]) {
			return binarySearch(left, mid - 1, key);
		}
		else {
			return binarySearch(mid+1, right, key);
		}
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> HAIR[i];
		}
		while (M--) {
			int t;
			cin >> t;
			cout << binarySearch(0,N-1,t) + 1 << endl;
		}
	}
}