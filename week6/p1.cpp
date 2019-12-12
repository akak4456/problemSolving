#include <iostream>
#include <vector>
using namespace std;
struct Node {
	Node* parent=NULL;
	Node* left=NULL;
	Node* right=NULL;
	int value;
	int level;
};
Node* nodes[10000];
vector<int> result;
int T;
int n, k;
void levelUpdate(Node* n) {
	if (n->parent == NULL) {
		n->level = 0;
	}
	else {
		n->level = n->parent->level + 1;
	}
	if (n->left != NULL) {
		levelUpdate(n->left);
	}
	if (n->right != NULL) {
		levelUpdate(n->right);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		result.clear();
		cin >> n >> k;
		Node* root = NULL;
		for (int i = 0; i < n; i++) {
			nodes[i] = new Node;
			nodes[i]->value = i;
		}
		for (int i = 1; i <= n - 1; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			if (nodes[t1]->left == NULL) {
				nodes[t1]->left = nodes[t2];
			}else if (nodes[t1]->right == NULL) {
				nodes[t1]->right = nodes[t2];
			}
			nodes[t2]->parent = nodes[t1];
		}
		for (int i = 0; i < n; i++) {
			if (nodes[i]->parent == NULL) {
				root = nodes[i];
				break;
			}
		}
		levelUpdate(root);
		for (int i = 0; i < k; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			Node* tmp1 = nodes[t1];
			Node* tmp2 = nodes[t2];
			while (tmp1->level > tmp2->level && tmp1->parent != NULL) {
				tmp1 = tmp1->parent;
			}
			while (tmp2->level > tmp1->level && tmp2->parent != NULL) {
				tmp2 = tmp2->parent;
			}
			while (tmp1->value != tmp2->value &&tmp1->parent != NULL && tmp2->parent != NULL) {
				tmp1 = tmp1->parent;
				tmp2 = tmp2->parent;
			}
			result.push_back(tmp1->value);
		}
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			delete nodes[i];
		}
	}
}