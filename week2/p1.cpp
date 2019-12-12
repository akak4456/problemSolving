//Problem Germ: Germ
//Time used:	1.31 second
//Memory used:	262144 bytes
#include <iostream>
#include <vector>
using namespace std;
int T, N,M;
int area[100][100];//y,x
vector<pair<int, int> > germ;
int solve() {
	int count = 0;
	while (!germ.empty()) {
		int last = germ.size();
		//cout << last << endl;
		for (int i = 0; i < last; i++) {
			int x = germ[i].first;
			int y = germ[i].second;
			if (x - 1 >= 0 && area[y][x - 1] != 1) {
				//cout << "A" << endl;
				germ.push_back({ x - 1,y });
				area[y][x - 1] = 1;
			}
			if (x + 1 < N && area[y][x + 1] != 1) {
				//cout << "B" << endl;
				germ.push_back({ x + 1,y });
				area[y][x + 1] = 1;
			}
			if (y - 1 >= 0 && area[y-1][x] != 1) {
				//cout << "C" << endl;
				germ.push_back({ x,y-1 });
				area[y - 1][x] = 1;
			}
			if (y + 1 < N && area[y + 1][x] != 1) {
				//cout << "D" << endl;
				germ.push_back({ x,y + 1 });
				area[y + 1][x] = 1;
			}
		}
		//cout  << endl;
		germ.erase(germ.begin(), germ.begin() + last);
		if (!germ.empty()) {
			count++;
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (area[y][x] == 0) {
				return -1;
			}
		}
	}
	return count;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int y = N-1; y >= 0; y--) {
			for (int x = 0; x < N; x++) {
				cin >> area[y][x];
			}
		}
		germ.clear();
		while (M--) {
			int x, y;
			cin >> x >> y;
			area[y][x] = 1;
			germ.push_back({x,y});
		}
		cout << solve() << endl;
	}
}