#include <string>
#include<iostream>
using namespace std;
#define _max(x,y) ((x > y) ? x : y)

// class Node 정의
class Node
{
public:
	int height;
	int key;
	string value;
	Node *parent, *left, *right;
	Node() {					// 생성자1
		key = height = 0;
		value = "";
		parent = left = right = NULL;
	};
	Node(int key, string value) {	// 생성자2
		this->height = 0;
		this->key = key;
		this->value = value;
		parent = left = right = NULL;
	};
};

// class AVLTree (AVL 트리) 정의
class AVLTree
{
public:
	Node *root;
	int n;
	AVLTree() {		// 생성자
		this->root = NULL;
		n = 0;
	};
	Node* find(int key, Node* v);
	void insert(int key, string value);

	int height(Node* v);
	void setHeight(Node* v);
	bool isBalanced(Node *v);
	Node* tallGrandChild(Node* v);
	Node* restructure(Node* v);
	void rebalance(Node* v);
	bool isExternal(Node* v);
	int size();
	bool empty();

	int diff(Node* v);

	Node* ll(Node* v);
	Node* lr(Node* v);
	Node* rl(Node* v);
	Node* rr(Node* v);

	void display(Node* t) {
		cout << t->key << " ";
		if (t->left != NULL) {
			cout << "(left)"<<t->left->key << " ";
		}
		if (t->right != NULL) {
			cout << "(right)"<<t->right->key << " ";
		}
		cout << endl;
		if (t->left != NULL) {
			display(t->left);
		}
		if (t->right != NULL) {
			display(t->right);
		}
	}
};

// AVL 트리의 size 반환
int AVLTree::size() {
	return n;
}

// AVL 트리의 empty 여부 반환
bool AVLTree::empty() {
	return (n == 0);
}

// 노드v가 leaf 노드인지 확인
bool AVLTree::isExternal(Node* v) {
	return (v->left == NULL && v->right == NULL);
}

// 노드 v의 높이 반환
int AVLTree::height(Node* v) {
	if (v == NULL)
		return -1;
	else
		return (isExternal(v)) ? 0 : v->height;
}

// 노드 v의 높이 계산
void AVLTree::setHeight(Node* v) {
	int hl = height(v->left);	// height of left child
	int hr = height(v->right);	// height of right child
	v->height = 1 + _max(hl, hr);
}

//  노드 v에 대해 균형 여부 확인
bool AVLTree::isBalanced(Node *v) {
	int bal = height(v->left) - height(v->right);
	return ((-1 <= bal) && (bal <= 1));
}
// 최초의 불균형 노드 z에 대해, height가 더 큰, z의 grandchld 탐색
Node* AVLTree::tallGrandChild(Node* z) {
	Node* zl = z->left;
	Node* zr = z->right;
	if (height(zl) >= height(zr)) {
		if (height(zl->left) >= height(zl->right))	// 자식과 같은 방향의 손자를 우선적으로 선택
			return zl->left;
		else
			return zl->right;
	}
	else {
		if (height(zr->right) >= height(zr->left))	// 자식과 같은 방향의 손자를 우선적으로 선택
			return zr->right;
		else
			return zr->left;
	}
}



/****************************************************************************************************************************************///학생이 구현. 
int AVLTree::diff(Node* v) {
	return (height(v->left) - height(v->right));
}
Node* AVLTree::ll(Node* v) {
	Node* ancestor = v->parent;
	Node* v2 = v->left;
	if (v2->right != NULL) {
		v2->right->parent = v;
	}
	v->left = v2->right;
	v->parent = v2;
	v2->right = v;
	v2->parent = ancestor;
	if (ancestor != NULL) {
		if (ancestor->left == v) {
			ancestor->left = v2;
		}
		else {
			ancestor->right = v2;
		}
	}
	return v2;

}
Node* AVLTree::lr(Node* v) {
	Node* ancestor = v->parent;
	Node* v2 = rr(v->left);
	return ll(v);

}
Node* AVLTree::rl(Node* v) {
	Node* ancestor = v->parent;
	Node* v2 = ll(v->right);
	return rr(v);

}
Node* AVLTree::rr(Node* v) {
	Node* ancestor = v->parent;
	Node* v2 = v->right;
	if (v2->left != NULL) {
		v2->left->parent = v;
	}
	v->right = v2->left;
	v->parent = v2;
	v2->left = v;
	v2->parent = ancestor;
	if (ancestor != NULL) {
		if (ancestor->left == v) {
			ancestor->left = v2;
		}
		else {
			ancestor->right = v2;
		}
	}
	return v2;
}
Node* AVLTree::restructure(Node* x) {
	// 직접 구현하세요.
	int t1 = diff(x);
	int t2;
	if (t1 > 0) {
		t2 = diff(x->left);
		if (t2 > 0) {
			return ll(x);
		}
		else {
			return lr(x);
		}
	}
	else {
		t2 = diff(x->right);
		if (t2 > 0) {
			return rl(x);
		}
		else {
			return rr(x);
		}

	}
}

/*****************************************************************************************************************************************///학생이 구현





																																		   // 노드 v부터 root 노드까지의 path 상에 노드의 height를 재설정하고 균형여부 확인
																																		   // 불균형 노드가 있으면, restructuring
void AVLTree::rebalance(Node* v) {
	Node *z = v;
	while (z->parent != NULL) {
		z = z->parent;
		setHeight(z);
		if (!isBalanced(z)) {
			z = restructure(z);		// -------------------> restructure() 를 직접 구현해야합니다.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			setHeight(z->left);
			setHeight(z->right);
			setHeight(z);
		}
	}
	root = z;
}



//key가 삽입될 위치 반환
Node* AVLTree::find(int key, Node* v) {
	Node* leafNode;
	leafNode = NULL;

	while (v != NULL) {
		leafNode = v;
		if (key < v->key)
			v = v->left;
		else if (key > v->key)
			v = v->right;
		else
			return v;
	}

	// leaf까지 도달한 경우, leaf노드를 반환한다. 
	return leafNode;
}


//노드 삽입
void AVLTree::insert(int key, string value) {
	Node *curLeafNode = find(key, root);
	Node *newNode = new Node(key, value);
	Node *insertNode = new Node();

	if (key < curLeafNode->key)	// 삽입하려는 key가 현재 leaf노드의 key보다 작은 경우
	{
		curLeafNode->left = newNode;
	}
	else 	// 삽입하려는 key가  현재 leaf노드의 key보다 큰 경우
	{
		curLeafNode->right = newNode;
	}
	newNode->parent = curLeafNode;
	n++;

	// restructure 및 height 갱신
	setHeight(newNode);
	rebalance(newNode);


	// 삽입된 AVL tree의 노드의 height 출력
	insertNode = find(key, root);
	cout << insertNode->value << " " << insertNode->height << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	int t, key;
	string instruct;
	AVLTree T;

	cin >> t;
	while (t--) {
		Node* tempNode;
		cin >> instruct;
		if (instruct == "find") {

			cin >> key;
			Node* ans = T.find(key, T.root);
			if (ans->key != key) {
				cout << -1 << endl;
			}
			else {
				cout << ans->value << " " << T.height(ans) << endl;
			}
		}

		else if (instruct == "insert") {
			cin >> key >> instruct;
			if (T.empty()) {
				T.root = new Node(key, instruct);
				T.n++;
				cout << T.root->value << " " << T.root->height << endl;
			}
			else
				T.insert(key, instruct);
		}
		//T.display(T.root);
	}
	return 0;
}