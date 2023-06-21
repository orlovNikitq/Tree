#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Node(T data) {
		this->data = data;
	}
};

template<typename T>
class Tree {
	int count = 0;
	Node<T>* root = nullptr;
public:
	void push(T data) {
		if (root == nullptr) {
			root = new Node<T>(data);
		}
		else {
			Node<T>* node = root;
			while (true) {
				if (data < node->data) {
					if (node->left == nullptr) {
						node->left = new Node<T>(data);
						break;
					}
					else {
						node = node->left;
					}
				}
				else {
					if (node->right == nullptr) {
						node->right = new Node<T>(data);
						break;
					}
					else {
						node = node->right;
					}
				}
			}
		}
		count++;
	}

	void show() {
		showw(root);
	}

	void showw(Node<T>* node) {
		if (node != nullptr) {
			showw(node->left);
			cout << node->data << " ";
			showw(node->right);
		}
	}

	void remove(T data) {
		root = removeNode(root, data);
	}

	Node<T>* removeNode(Node<T>* node, T data) {
		if (node == nullptr) {
			return 0;
		}

		if (data < node->data) {
			node->left = removeNode(node->left, data); 
		}
		else if (data > node->data) {
			node->right = removeNode(node->right, data); 
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->left == nullptr) {
				node = node->right; 
			}
			else if (node->right == nullptr) {
				node = node->left; 
			}
			else {
				Node<T>* successorParent = node;
				Node<T>* successor = node->right;

				while (successor->left != nullptr) {
					successorParent = successor;
					successor = successor->left;
				}

				if (successorParent != node) {
					successorParent->left = successor->right;
				}
				else {
					successorParent->right = successor->right;
				}

				node->data = successor->data;
				delete successor;
			}
		}

		return node;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Tree<int> tree;
	tree.push(9);
	tree.push(3);
	tree.push(8);
	tree.push(12);
	tree.remove(12);
	tree.show();
}
