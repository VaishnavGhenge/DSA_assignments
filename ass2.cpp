// Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
// i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data value found in the tree, iv. Change a tree so that the roles of the left and right pointers
// are swapped at every node, v. Search a value


#include<iostream>
using namespace std;

class node {
	int data;
	node *left, *right;

public:
	node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

	friend class Tree;
};

class Tree {
	node* root;

public:
	Tree() {
		root = nullptr;
	}

	void insert(int data) {
		if(root == nullptr) {
			root = new node(data);
			return;
		}

		node* tmp = root;
		while(tmp != nullptr) {
			if(data < tmp->data) {
				if(tmp->left == nullptr) {
					tmp->left = new node(data);
					cout << data << " inserted\n";
					return;
				}

				tmp = tmp->left;
			} else if(data > tmp->data) {
				if(tmp->right == nullptr)
				{
					tmp->right = new node(data);
					cout << data << " inserted\n";
					return;
				}

				tmp = tmp->right;
			} else {
				cout << "Error duplicate value\n";
				return;
			}
		}
	}

	void longest_path() {
		int path = find_path(root);
		cout << "Longest path is: " << path << endl;
	}

	int find_path(node* tmp) {
		int right = 0, left = 0;

		if(tmp == nullptr)
			return 0;

		left = find_path(tmp->left);

		right = find_path(tmp->right);

		if(left > right)
			return ++left;
		else
			return ++right;
	}

	void min() {
		node* tmp = root;

		while(tmp != nullptr) {
			if(tmp->left == nullptr)
				break;
			else
				tmp = tmp->left;
		}

		cout << "Minimum value is " << tmp->data << endl;
	}

	void mirror() {
		mirror_tree(root);
	}

	void mirror_tree(node* tmp) {
		if(tmp == nullptr)
			return;

		node* temp = tmp->left;
		tmp->left = tmp->right;
		tmp->right = temp;

		mirror_tree(tmp->left);
		mirror_tree(tmp->right);
	}

	void inorder() {
		in(root);
		cout << endl << endl;
	}

	void in(node* tmp) {
		if(tmp == nullptr)
			return;

		in(tmp->left);
		cout << tmp->data << " ";
		in(tmp->right);
	}

	void search(int data) {
		node* tmp = root;

		while(tmp != nullptr) {
			if(data < tmp->data)
				tmp = tmp->left;
			else if(data > tmp->data)
				tmp = tmp->right;
			else
				break;
		}

		if(tmp == nullptr)
			cout << data << " not found\n";
		else
			cout << data << " found\n";
	}
};

int main() {
	Tree* t = new Tree();

	t->insert(6);
	t->insert(8);
	t->insert(14);
	t->insert(2);
	t->insert(5);
	// t->insert(9);
	// t->insert(50);

	t->longest_path();
	t->min();
	t->inorder();
	// t->mirror();
	// t->inorder();

	t->search(8);
	t->search(100);
	return 0;
}
