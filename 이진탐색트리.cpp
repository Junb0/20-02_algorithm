#include<iostream>
using namespace std;

class Node {
public:
	int key = 42;
	Node* Left = nullptr;
	Node* Right = nullptr;

	Node(int key) {
		this->key = key;
	}
};

class Tree {
public:
	Node* root;
};

Tree tree;

Node* treeInsert(Node* t, int key) {
	if (t == nullptr) {
		Node* n = new Node(key);
		return n;
	}
	if (key < t->key) {
		t->Left = treeInsert(t->Left, key);
		return t;
	}
	else {
		t->Right = treeInsert(t->Right, key);
		return t;
	}
}

void LVR(Node* t) {
	if (tree.root == nullptr) {
		cout << "트리가 비었습니다." << endl;
		return;
	}
	if (t == nullptr)
		return;
	LVR(t->Left);
	cout << t->key << ' ';
	LVR(t->Right);
}

Node* findMin(Node* t) {
	if (t == nullptr)
		return nullptr;
	else if (t->Left == nullptr)
		return t;
	else
		return findMin(t->Left);
}

Node* treeDelete(Node* t, int key) {
	Node* tmpNode;
	if (t == nullptr)
		return nullptr;
	if (key < t->key) {
		t->Left = treeDelete(t->Left, key);
	}
	else if (key > t->key) {
		t->Right = treeDelete(t->Right, key);
	}
	else if (t->Left != nullptr && t->Right != nullptr) {	// 삭제 대상 발견 및 삭제 대상이 양쪽 서브트리 지님
		tmpNode = findMin(t->Right);
		t->key = tmpNode->key;
		t->Right = treeDelete(t->Right, t->key);
	}
	else {
		if (t != tree.root) {
			tmpNode = t;
			if (t->Left == nullptr)
				t = t->Right;
			else if (t->Right == nullptr)
				t = t->Left;
			delete tmpNode;
		}
		else {
			tmpNode = t;
			if (t->Left == nullptr)
				tree.root = t->Right;
			else if (t->Right == nullptr)
				tree.root = t->Left;
			delete tmpNode;
		}
	}
	return t;
}

int main() {
	tree.root = new Node(55);
	treeInsert(tree.root, 60);
	treeInsert(tree.root, 15);
	treeInsert(tree.root, 8);
	treeInsert(tree.root, 28);
	treeInsert(tree.root, 90);
	treeInsert(tree.root, 3);
	treeInsert(tree.root, 18);
	treeInsert(tree.root, 30);
	treeInsert(tree.root, 48);
	treeInsert(tree.root, 38);
	treeInsert(tree.root, 33);
	treeInsert(tree.root, 32);
	treeInsert(tree.root, 36);

	LVR(tree.root);
	int temp;
	while (1) {
		if (tree.root != nullptr)
			cout << "root : " << tree.root->key << endl;
		cin >> temp;
		treeDelete(tree.root, temp);
		LVR(tree.root);
		cout << endl;
	}
}