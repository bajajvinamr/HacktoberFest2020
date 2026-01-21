#include <queue>
#include <iostream>
using namespace std;

struct Node {
	Node* right;
	Node* left;
	int key;
	Node(int);
};
Node::Node(int _key) {
	this->key = _key;
	right = nullptr;
	left = nullptr;
}

struct BST {
	BST();
	Node* root;
	Node* getRoot();
	void setRoot(Node* _root);
	Node* InsertNode(Node* root, int _key);
	void preOrderTraversal(Node* root);
	void inOrderTraversal(Node* root);
	void postOrderTraversal(Node* root);
};
BST::BST() {
	root = nullptr;
}
Node* BST::getRoot() {
	return this->root;
}
void BST::setRoot(Node* _root) {
	this->root = _root;
}
Node* BST::InsertNode(Node* root, int _key) {
	if (root == nullptr) {
		return new Node(_key);
	}
	if (_key < root->key) {
		root->left = InsertNode(root->left, _key);
	}
	else if (_key > root->key) {
		root->right = InsertNode(root->right, _key);
	}
	return root;
}
void BST::preOrderTraversal(Node* root) {
	if (root != nullptr) {
		cout << root->key << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}
void BST::inOrderTraversal(Node* root) {
	if (root != nullptr) {
		inOrderTraversal(root->left);
		cout << root->key << " ";
		inOrderTraversal(root->right);
	}
}
void BST::postOrderTraversal(Node* root) {
	if (root != nullptr) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->key << " ";
	}
}



int main() {
	BST Tree;
	int valuesAmount;
	cout << "How many values would you like to insert? ";
	cin >> valuesAmount;
	vector<int> treeValues;
	for (int i = 0; i < valuesAmount; i++) {
		int value;
		cout << "insert value into tree: ";
		cin >> value;
		cout << endl;
		Tree.setRoot(Tree.InsertNode(Tree.getRoot(), value));
	}
	cout << "-----Pre Order Traversal-----" << endl;
	Tree.preOrderTraversal(Tree.getRoot());
	cout << endl;
	cout << "-----In Order Traversal-----" << endl;
	Tree.inOrderTraversal(Tree.getRoot());
	cout << endl;
	cout << "-----Post Order Traversal-----" << endl;
	Tree.postOrderTraversal(Tree.getRoot());
	return 0;
}
