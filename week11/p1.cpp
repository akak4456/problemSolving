#include <iostream>
using namespace std;
int T;
int x, y;
long long int num[61];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 60; i++) {
			num[i] = 0;
		}
		num[0] = 1;
		num[1] = 1;
		cin >> x >> y;
		for (int i = 2; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (i - j >= 0) {
					num[i] += num[i - j];
				}
			}
		}
		cout << num[x] << endl;
	}
}