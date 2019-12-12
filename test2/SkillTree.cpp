#include <iostream>
#include <deque>
using namespace std;
struct Node {
	int idx;
	Node* parent = NULL;
	Node* left = NULL;
	Node* right = NULL;
};
int T;
int n, k;
Node* nodes[10000];
deque<Node*> a_list;
deque<Node*> b_list;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			nodes[i] = new Node;
			nodes[i]->idx = i;
		}
		for (int i = 1; i <= n - 1; i++) {
			int parent, child;
			cin >> parent >> child;
			nodes[child]->parent = nodes[parent];
			if (nodes[parent]->left == NULL) {
				nodes[parent]->left = nodes[child];
			}
			else {
				nodes[parent]->right = nodes[child];
			}
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			a_list.clear();
			b_list.clear();
			Node* aNode = nodes[a];
			Node* bNode = nodes[b];
			while (aNode != NULL) {
				a_list.push_front(aNode);
				aNode = aNode->parent;
			}
			while (bNode != NULL) {
				b_list.push_front(bNode);
				bNode = bNode->parent;
			}
			int idx = 0;
			while (idx < a_list.size() && idx < b_list.size() &&a_list[idx] == b_list[idx]) {
				idx++;
			}
			
			cout << a_list[idx - 1]->idx << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			delete nodes[i];
		}
	}
}