/*
ID:2012171708
PW:ehsi3v
*/
#include <iostream>
#include <queue>
using namespace std;
int T;
int L, B, V;
bool isVisited[50][50];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> L >> B >> V;
		for (int y = 0; y < B; y++) {
			for (int x = 0; x < L; x++) {
				isVisited[y][x] = true;
			}
		}
		int x, y;
		for (int i = 0; i < V; i++) {
			cin >> x >> y;
			isVisited[y][x] = false;
		}
		int count = 0;
		for (int y = 0; y < B; y++) {
			for (int x = 0; x < L; x++) {
				if (isVisited[y][x] == false) {
					//bfs
					queue<pair<int, int> > points;
					points.push({ y,x });
					while (!points.empty()) {
						pair<int, int> PF = points.front();
						points.pop();
						isVisited[PF.first][PF.second] = true;
						if (PF.first - 1 >= 0 && isVisited[PF.first - 1][PF.second] == false) {
							points.push({ PF.first - 1,PF.second });
							isVisited[PF.first - 1][PF.second] = true;//이게 없으면 메모리초과가 됨
						}
						if (PF.first + 1 < B && isVisited[PF.first + 1][PF.second] == false) {
							points.push({ PF.first + 1,PF.second });
							isVisited[PF.first + 1][PF.second] = true;//이게 없으면 메모리초과가 됨
						}
						if (PF.second - 1 >= 0 && isVisited[PF.first][PF.second - 1] == false) {
							points.push({ PF.first,PF.second - 1 });
							isVisited[PF.first][PF.second - 1] = true;//이게 없으면 메모리초과가 됨
						}
						if (PF.second + 1 < L && isVisited[PF.first][PF.second + 1] == false) {
							points.push({ PF.first,PF.second + 1 });
							isVisited[PF.first][PF.second + 1] = true;//이게 없으면 메모리초과가 됨
						}
					}
					//bfs
					count++;
				}
			}
		}
		cout << count << endl;
	}
}