#include<iostream>
#include <vector>
using namespace std;
struct Node {
	int idx;
	int count;
	vector<Node*> childList;
};
vector<Node*> nodes;
long long int GC[101];
int T;
int N;
int M;
void preOrder(int node, long long int count) {
	long long int newCount = count * nodes[node]->count;
	if (nodes[node]->childList.size() == 0) {
		GC[node] = newCount;
		return;
	}
	else {
		for (int i = 0; i < nodes[node]->childList.size(); i++) {
			preOrder(nodes[node]->childList[i]->idx, newCount);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 0; i <= 100; i++) {
			GC[i] = 0;
		}
		for (int i = 0; i < nodes.size(); i++) {
			delete nodes[i];
		}
		nodes.clear();
		cin >> N;
		cin >> M;
		for (int i = 0; i <= N; i++) {
			Node* tmp = new Node;
			tmp->idx = i;
			nodes.push_back(tmp);
		}
		for (int i = 0; i < M; i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			nodes[t1]->childList.push_back(nodes[t2]);
			nodes[t2]->count = t3;
		}
		nodes[N]->count = 1;
		preOrder(N,1);
		for (int i = 0; i <= 100; i++) {
			if (GC[i] != 0) {
				cout << i << " " << GC[i] << endl;
			}
		}
	}
}