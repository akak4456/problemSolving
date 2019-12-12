#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T;
int N, M, K;
struct Node {
	int num;
	int H;
	vector<Node*> next;
};
Node* nodes[1001];
int cost[1001];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		int minH = 987654321;
		int han = -1;
		for (int i = 0; i < N; i++) {
			nodes[i] = new Node;
			nodes[i]->num = i;
			cin >> nodes[i]->H;
			if (nodes[i]->H < minH) {
				minH = nodes[i]->H;
				han = i;
			}
		}
		for (int i = 0; i < M; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			nodes[t1]->next.push_back(nodes[t2]);
			nodes[t2]->next.push_back(nodes[t1]);
		}
		for (int i = 0; i < N; i++) {
			cost[i] = 987654321;//무한대를 의미
		}
		cost[han] = 0;
		vector<int> candidate;
		candidate.clear();
		int minCost = 987654321;
		int minIdx = -1;
		for (int i = 0; i < N; i++) {
			candidate.push_back(i);
		}
		while (candidate.size() > 0) {
			int eraseNum = 0;
			for (int i = 0; i < candidate.size(); i++) {
				if (cost[candidate[i]] < minCost) {
					minCost = cost[candidate[i]];
					minIdx = candidate[i];
					eraseNum = i;
				}
			}
			if (minCost == 987654321) {
				break;
			}
			//cout << minIdx << endl;
			candidate.erase(candidate.begin() + eraseNum);
			for (int i = 0; i < nodes[minIdx]->next.size(); i++) {
				int idx = nodes[minIdx]->next[i]->num;
				//cout << idx << endl;
				if (cost[idx] > cost[minIdx] + 1) {
					cost[idx] = cost[minIdx] + 1;
				}
			}
			minCost = 987654321;
		}
		for (int i = 0; i < K; i++) {
			int t1;
			cin >> t1;
			if (cost[t1] != 987654321&&t1 < N) {
				cout << cost[t1] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		for (int i = 0; i < N; i++) {
			delete nodes[i];
		}
	}
}