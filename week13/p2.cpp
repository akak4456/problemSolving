#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node {
	int num;
	bool visited;
	vector<Node*> pre;
	vector<Node*> next;
};
int T;
int N, M;
int lastIdx;
Node* nodes[10001];
priority_queue<int, vector<int>, greater<int> > candidate;
vector<int> output;
bool sortByNum(Node* a, Node* b) {
	return a->num < b->num;
}
void dfs(Node* n) {
	//cout << n->num << endl;
	if (n->visited == false) {
		output.push_back(n->num);
	}
	n->visited = true;
	sort(n->next.begin(), n->next.end(), sortByNum);
	for (int i = 0; i < n->next.size(); i++) {
		Node* nextNode = n->next[i];
		//cout << nextNode->num << endl;
		bool isCan = true;
		for (int j = 0; j < nextNode->pre.size(); j++) {
			if (nextNode->pre[j]->visited == false) {
				isCan = false;
				break;
			}
		}
		if (isCan) {
			candidate.push(nextNode->num);
		}
	}
	if (!candidate.empty()) {
		int tmp = candidate.top();
		candidate.pop();
		dfs(nodes[tmp]);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		output.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			nodes[i] = new Node;
			nodes[i]->num = i;
			nodes[i]->visited = false;
		}
		for (int i = 1; i <= M; i++) {
			int K;
			cin >> K;
			vector<int> sequence;
			sequence.clear();
			for (int j = 1; j <= K; j++) {
				int t;
				cin >> t;
				sequence.push_back(t);
			}
			for (int j = 1; j < sequence.size(); j++) {
				nodes[sequence[j - 1]]->next.push_back(nodes[sequence[j]]);
				nodes[sequence[j]]->pre.push_back(nodes[sequence[j - 1]]);
			}
		}
		for (int i = 1; i <= N; i++) {
			if (nodes[i]->pre.size() == 0 && nodes[i]->visited == false) {
				candidate.push(nodes[i]->num);
			}
		}
		//cout << candidate.size() << endl;
		while (!candidate.empty()) {
			int startNum = candidate.top();
			candidate.pop();
			dfs(nodes[startNum]);
		}
		if (output.size() == N) {
			for (int i = 0; i < N; i++) {
				cout << output[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
		for (int i = 1; i <= N; i++) {
			delete nodes[i];
		}
	}
}