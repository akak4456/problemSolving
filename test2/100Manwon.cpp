#include <iostream>
using namespace std;
int hashFuct1(int value) {
	return value % 1013;
}
int hashFuct2(int value) {
	return (37-(value % 37));
}
int hash1;
int hash2;
int curIdx;
int redCnt;
int numArray[1001];
int colorArray[1013];
/*
0:아무것도 안붙어있다.
1:뭐라도 붙어있다.
*/
int T;
int N, I;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> I;
		for (int i = 0; i < 1013; i++) {
			colorArray[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			cin >> numArray[i];
		}
		for (int i = 0; i < N; i++) {
			redCnt = 0;
			hash1 = hashFuct1(numArray[i]);
			curIdx = hash1;
			hash2 = hashFuct2(numArray[i]);
			bool redUsed = false;
			while (true) {
				if (colorArray[curIdx] == 0) {
					break;
				}
				else {
					colorArray[curIdx] = 1;
					curIdx = (curIdx + hash2) % 1013;
					if (redUsed == false) {
						redUsed = true;
					}
					else {
						redCnt++;
					}
				}
			}
			if (redUsed) {
				redCnt++;
			}
			colorArray[curIdx] = 1;
			if (curIdx == I) {
				cout << (1000000 - redCnt * 10000) << endl;
				break;
			}
			else if (i == N - 1) {
				cout << "N" << endl;
			}
		}
	}
}