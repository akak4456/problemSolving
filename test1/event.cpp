#include <iostream>
#include <stack>
using namespace std;
int T;
int N;
int H[50001];
int E[50001];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> H[i];
			E[i] = 0;
		}
		stack<pair<int, int> > remain;
		remain.push({ H[1],1 });
		for (int i = 2; i <= N; i++) {
			bool isCan = false;
			while (!remain.empty()) {
				pair<int, int> t = remain.top();
				remain.pop();
				if (t.first >= H[i]) {
					remain.push({ t.first,t.second });
					E[i] = t.second;
					isCan = true;
					break;
				}
			}
			remain.push({ H[i],i });
		}
		for (int i = 1; i <= N; i++) {
			cout << E[i] << " ";
		}
		cout << endl;
	}
}