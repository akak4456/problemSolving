#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int n, L, k;
vector<int> balls;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> L >> k;
		while (n--) {
			int t;
			cin >> t;
			if (t < 0) {
				balls.push_back(t*-1);
			}
			else {
				balls.push_back(L - t);
			}
		}
		sort(balls.begin(), balls.end());
		cout << balls[k - 1] << endl;
		balls.clear();
	}
}