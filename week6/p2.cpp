#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	Node* parent=NULL;
	vector<Node*> leaveNodes;
	int number;
	long long int parentwantcount;
};
int T;
int N, M;
Node* nodes[101];
long long int result[101];
vector<int> leavenode;
void go(Node* n, long long int count) {
	if (n->leaveNodes.size() == 0) {
		result[n->number] = count;
		leavenode.push_back(n->number);
		return;
	}
	for (int i = 0; i < n->leaveNodes.size(); i++) {
		go(n->leaveNodes[i], count*n->leaveNodes[i]->parentwantcount);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 100; i++) {
			result[i] = 0;
		}
		leavenode.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			nodes[i] = new Node;
			nodes[i]->number = i;
		}
		Node* root = nodes[N];
		root->parentwantcount = 1;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			nodes[t1]->leaveNodes.push_back(nodes[t2]);
			nodes[t2]->parent = nodes[t1];
			nodes[t2]->parentwantcount = t3;
		}
		go(root, 1);
		sort(leavenode.begin(),leavenode.end());
		for (int i = 0; i < leavenode.size(); i++) {
			cout << leavenode[i] << " " << result[leavenode[i]] << endl;
		}
		for (int i = 1; i <= N; i++) {
			delete nodes[i];
		}
	}
}