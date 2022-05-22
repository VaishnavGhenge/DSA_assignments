#include <iostream>
using namespace std;

class node {
	string key, value;
	node *left, *right;

public:
	node(string key, string value) {
		this->key = key;
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
	friend class Dictionary;
};

class Dictionary {
	node* root;

public:
	Dictionary() {
		root = nullptr;
	}

	void insert(string key, string value) {
		if(root == nullptr) {
			root = new node(key, value);
			return;
		}

		node* tmp = root;
		while(tmp != nullptr) {
			if(key < tmp->key) {
				if(tmp->left == nullptr)
				{
					tmp->left = new node(key, value);
					return;
				}
				else
					tmp = tmp->left;
			} else if(key > tmp->key) {
				if(tmp->right == nullptr)
				{
					tmp->right = new node(key, value);
					return;
				}
				else
					tmp = tmp->right;
			} else {
				cout << "Error duplicate key\n";
				return;
			}
		}
	}

	void display() {
		cout << "\nDictionary:\n";
		inorder(root, "a");
		cout << endl;
	}

	void inorder(node* tmp, string type) {
		if(tmp == nullptr)
			return;

		if(type == "a") {
			inorder(tmp->left, type);
			cout << tmp->key << ": " << tmp->value << endl;
			inorder(tmp->right, type);
		} else if(type == "d") {
			inorder(tmp->right, type);
			cout << tmp->key << ": " << tmp->value << endl;
			inorder(tmp->left, type);
		}
	}

	void dlt(string key) {
		dlt_main(root, key);
	}

	void dlt_main(node* tmp, string key) {
		if(root == nullptr) {
			cout << "Dictionary is empty\n";
			return;
		}

		node* prev = tmp;
		while(tmp != nullptr) {
			if(key < tmp->key) {
				prev = tmp;
				tmp = tmp->left;
			}
			else if(key > tmp->key)
			{
				prev = tmp;
				tmp = tmp->right;
			}
			else
				break;
		}

		if(tmp == nullptr)
			cout << "\"" << key << "\" not found\n";
		else {
			if(tmp->right == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->left;
				else if(tmp->key >  prev->key)
					prev->right = tmp->left;
				else
					root = tmp->left;
			} else if(tmp->left == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->right;
				else if(tmp->key > prev->key)
					prev->right = tmp->right;
				else
					root = tmp->right;
			} else
			{
				cout << "root in\n";
				node* dlt = tmp->right;

				while(dlt->left != nullptr)
					dlt = dlt->left;

				tmp->key = dlt->key;
				tmp->value = dlt->value;

				dlt_main(tmp->right, dlt->key);
			}
		}
	}

	void update(string key, string new_value) {
		if(root == nullptr) {
			cout << "Dictionary is empty\n";
			return;
		}

		node* tmp = root;
		while(tmp != nullptr) {
			if(key < tmp->key)
				tmp = tmp->left;
			else if(key > tmp->key)
				tmp = tmp->right;
			else
				break;
		}

		tmp->value = new_value;
	}

	void ascending() {
		cout << "\nAscending Dictionary: \n";
		inorder(root, "a");
		cout << endl;
	}

	void descending() {
		cout << "\nDescending Dictionary: \n";
		inorder(root, "d");
		cout << endl;

	}
};

int main() {
	Dictionary *dict = new Dictionary();
	dict->insert("Book", "Used to read");
	dict->insert("Name", "Used to mention someone");
	dict->insert("Zebra", "An animal");
	dict->insert("Table", "Used to sit");
	dict->insert("Tabla", "An indian band");

	// dict->display();
	// dict->dlt("Tabla");
	// dict->dlt("Book");
	dict->display();

	dict->update("Table", "null");
	// dict->display();
	dict->ascending();
	dict->descending();

	return 0;
}