#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T;
int N, M;
int indegree[10001];
vector<int> nextNode[10001];
priority_queue<int, vector<int>, greater<int> > cand;
vector<int> result;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		result.clear();
		for (int i = 1; i <= N; i++) {
			indegree[i] = 0;
			nextNode[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int K;
			cin >> K;
			int parent;
			cin >> parent;
			for (int j = 2; j <= K; j++) {
				int child;
				cin >> child;
				nextNode[parent].push_back(child);
				indegree[child]++;
				parent = child;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				cand.push(i);
			}
		}
		while (!cand.empty()) {
			int topCand = cand.top();
			result.push_back(topCand);
			cand.pop();
			for (int i = 0; i < nextNode[topCand].size(); i++) {
				indegree[nextNode[topCand][i]]--;
				if (indegree[nextNode[topCand][i]] == 0) {
					cand.push(nextNode[topCand][i]);
				}
			}
		}
		if (result.size() == N) {
			for (int i = 0; i < N; i++) {
				cout << result[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}