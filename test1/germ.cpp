#include <iostream>
#include <queue>
using namespace std;
int T;
int N, M;
int arr[100][100];
int H;
struct Germ {
	int x;
	int y;
};
queue<Germ> germs;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		H = N*N;
		for (int y = N - 1; y >= 0; y--) {
			for (int x = 0; x < N; x++) {
				cin >> arr[y][x];
				if (arr[y][x] == 1) {
					H--;
				}
			}
		}
		while (M--) {
			Germ tmp;
			cin >> tmp.x >> tmp.y;
			H--;
			arr[tmp.y][tmp.x] = 1;
			germs.push(tmp);
		}
		int R = 0;
		while (!germs.empty()) {
			int L = germs.size();
			for (int i = 0; i < L; i++) {
				Germ a = germs.front();
				germs.pop();
				Germ tmp;
				if (a.x - 1 >= 0 && arr[a.y][a.x - 1] == 0) {
					tmp.x = a.x - 1;
					tmp.y = a.y;
					germs.push(tmp);
					arr[a.y][a.x - 1] = 1;
					H--;
				}
				if (a.x + 1 < N && arr[a.y][a.x + 1] == 0) {
					tmp.x = a.x + 1;
					tmp.y = a.y;
					germs.push(tmp);
					arr[a.y][a.x + 1] = 1;
					H--;
				}
				if (a.y - 1 >= 0 && arr[a.y-1][a.x] == 0) {
					tmp.x = a.x;
					tmp.y = a.y-1;
					germs.push(tmp);
					arr[a.y - 1][a.x] = 1;
					H--;
				}
				if (a.y + 1 < N && arr[a.y + 1][a.x] == 0) {
					tmp.x = a.x;
					tmp.y = a.y + 1;
					germs.push(tmp);
					arr[a.y + 1][a.x] = 1;
					H--;
				}
			}
			R++;
		}
		R--;
		if (H != 0) {
			R = -1;
		}
		cout << R << endl;
	}
}