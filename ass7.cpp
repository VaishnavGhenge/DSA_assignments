// A Dictionary stores keywords and its meanings. Provide facility for adding new
// keywords, deleting keywords, updating values of any entry. Provide facility to display
// whole data sorted in ascending/ Descending order. Also find how many maximum
// comparisons may require for finding any keyword. Use Height balance tree and find the
// complexity for finding a keyword


#include <iostream>
using namespace std;

class node
{
	string key, value;
	node *left, *right;
	int height;

public:
	node()
	{
		left = right = nullptr;
		height = 1;
		key = "";
		value = "";
	}

	node(string key, string value)
	{
		this->key = key;
		this->value = value;
		height = 1;
		left = right = nullptr;
	}

	friend class dict;
};

class dict
{
	node* root;

public:
	dict()
	{
		root = nullptr;
	}

	int max(int a, int b)
	{
		return (a>b) ? a : b;
	}

	int getHeight(node* tmp)
	{
		if(tmp == nullptr)
			return 0;

		return tmp->height;
	}

	int getBalance(node* tmp)
	{
		if(tmp == nullptr)
			return 0;

		return getHeight(tmp->left) - getHeight(tmp->right);
	}

	node* rotateLeft(node* tmp)
	{
		node *tmpRight = tmp->right;
		node *tmpRightLeft = tmpRight->left;

		tmpRight->left = tmp;
		tmp->right = tmpRightLeft;

		return tmpRight;
	}

	node* rotateRight(node* tmp)
	{
		node *tmpLeft = tmp->left;
		node *tmpLeftRight = tmpLeft->right;

		tmpLeft->right = tmp;
		tmp->left = tmpLeftRight;

		return tmpLeft;
	}

	void insert(string key, string value)
	{
		root = insertmain(root, key, value);
		cout << key << " inserted in tree ";
		cout << root->key << endl;
	}

	node* insertmain(node* tmp, string key, string value)
	{
		if(tmp == nullptr)
		{
			return new node(key, value);
		}

		if(key < tmp->key)
			tmp->left = insertmain(tmp->left, key, value);
		else if(key > tmp->key)
			tmp->right = insertmain(tmp->right, key, value);
		else
		{
			cout << key << " is already exist in tree\n";
			return tmp;
		}


		tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

		int balance = getBalance(tmp);

		// LL
		if(balance > 1 && key < tmp->left->key) {
			return rotateRight(tmp);
		}

		// RR
		if(balance < -1 && key > tmp->right->key) {
			return rotateLeft(tmp);
		}

		// LR
		if(balance > 1 && key > tmp->left->key) {
			tmp->left = rotateLeft(tmp->left);
			return rotateRight(tmp);
		}

		// RL
		if(balance < -1 && key < tmp->right->key) {
			tmp->right = rotateRight(tmp->right);
			return rotateLeft(tmp);
		}

		return tmp;
	}

	void display(string type)
	{
		if(type == "ascending")
		{
			cout << "\nAscending Tree:\n";
			ascending(root);
		}
	}

	void ascending(node* tmp)
	{
		if(tmp == nullptr)
			return;

		ascending(tmp->left);
		cout << tmp->key << ": " << tmp->value << endl;
		ascending(tmp->right);
	}

	void delete_ele(string key)
	{
		root = delete_elemain(root, root, key);
		cout << key << " deleted from tree\n";
	}

	node* delete_elemain(node* tmp, node* prev, string key)
	{
		if(tmp == nullptr)
			return tmp;

		if(key < tmp->key)
		{
			tmp->left = delete_elemain(tmp->left, tmp, key);
		}
		else if(key > tmp->key)
		{ 
			tmp->right = delete_elemain(tmp->right, tmp, key);
		}
		else
		{
			if(tmp->right == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->left;
				else if(tmp->key > prev->key)
					prev->right = tmp->left;
				else
					root = tmp->left;
			}
			else if(tmp->left == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->right;
				else if(tmp->key > prev->key)
					prev->right = tmp->right;
			}
			else
			{
				node* dlt = tmp->right;
				node* prev = dlt;

				while(dlt->left != nullptr)
				{
					prev = dlt;
					dlt = dlt->left;
				}

				tmp->key = dlt->key;
				tmp->value = dlt->value;

				delete_elemain(tmp->right, prev, dlt->key);
			}
		}

		// update height;
		tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

		// balance
		int balance = getBalance(tmp);

		// LL
		if(balance > 1 && key < tmp->left->key)
			return rotateRight(tmp);

		// RR
		if(balance < -1 && key < tmp->right->key)
			return rotateLeft(tmp);

		// LR
		if(balance > 1 && key > tmp->left->key)
		{
			tmp->left = rotateLeft(tmp->left);
			return rotateRight(tmp);
		}

		// RL
		if(balance < -1 && key < tmp->right->key)
		{
			tmp->right = rotateRight(tmp->right);
			return rotateLeft(tmp);
		}

		return tmp;
	}

	void search(string key)
	{
		node* tmp = root;
		while(tmp != nullptr)
		{
			if(key < tmp->key)
			{
				tmp = tmp->left;
			}
			else if(key > tmp->key)
			{
				tmp = tmp->right;
			}
			else
			{
				cout << key << " found in tree\n";
				break;
			}
		}

		if(tmp == nullptr)
			cout << key << " not exist in tree\n";
	}
};

int main()
{
	dict *d = new dict();

	d->insert("Book", "Used to read");
	d->insert("Name", "Used to mention someone");
	d->insert("Zebra", "An animal");
	d->insert("Table", "Used to sit");
	d->insert("Tabla", "An indian band");

	d->display("ascending");
	d->delete_ele("Name");
	d->display("ascending");
	d->search("Name");
	return 0;
}

#include <iostream>
using namespace std;

class node
{
	string key, value;
	node *left, *right;
	int height;

public:
	node()
	{
		left = right = nullptr;
		height = 1;
		key = "";
		value = "";
	}

	node(string key, string value)
	{
		this->key = key;
		this->value = value;
		height = 1;
		left = right = nullptr;
	}

	friend class dict;
};

class dict
{
	node* root;

public:
	dict()
	{
		root = nullptr;
	}

	int max(int a, int b)
	{
		return (a>b) ? a : b;
	}

	int getHeight(node* tmp)
	{
		if(tmp == nullptr)
			return 0;

		return tmp->height;
	}

	int getBalance(node* tmp)
	{
		if(tmp == nullptr)
			return 0;

		return getHeight(tmp->left) - getHeight(tmp->right);
	}

	node* rotateLeft(node* tmp)
	{
		node *tmpRight = tmp->right;
		node *tmpRightLeft = tmpRight->left;

		tmpRight->left = tmp;
		tmp->right = tmpRightLeft;

		return tmpRight;
	}

	node* rotateRight(node* tmp)
	{
		node *tmpLeft = tmp->left;
		node *tmpLeftRight = tmpLeft->right;

		tmpLeft->right = tmp;
		tmp->left = tmpLeftRight;

		return tmpLeft;
	}

	void insert(string key, string value)
	{
		root = insertmain(root, key, value);
		cout << key << " inserted in tree ";
		cout << root->key << endl;
	}

	node* insertmain(node* tmp, string key, string value)
	{
		if(tmp == nullptr)
		{
			return new node(key, value);
		}

		if(key < tmp->key)
			tmp->left = insertmain(tmp->left, key, value);
		else if(key > tmp->key)
			tmp->right = insertmain(tmp->right, key, value);
		else
		{
			cout << key << " is already exist in tree\n";
			return tmp;
		}


		tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

		int balance = getBalance(tmp);

		// LL
		if(balance > 1 && key < tmp->left->key) {
			return rotateRight(tmp);
		}

		// RR
		if(balance < -1 && key > tmp->right->key) {
			return rotateLeft(tmp);
		}

		// LR
		if(balance > 1 && key > tmp->left->key) {
			tmp->left = rotateLeft(tmp->left);
			return rotateRight(tmp);
		}

		// RL
		if(balance < -1 && key < tmp->right->key) {
			tmp->right = rotateRight(tmp->right);
			return rotateLeft(tmp);
		}

		return tmp;
	}

	void display(string type)
	{
		if(type == "ascending")
		{
			cout << "\nAscending Tree:\n";
			ascending(root);
		}
	}

	void ascending(node* tmp)
	{
		if(tmp == nullptr)
			return;

		ascending(tmp->left);
		cout << tmp->key << ": " << tmp->value << endl;
		ascending(tmp->right);
	}

	void delete_ele(string key)
	{
		root = delete_elemain(root, root, key);
		cout << key << " deleted from tree\n";
	}

	node* delete_elemain(node* tmp, node* prev, string key)
	{
		if(tmp == nullptr)
			return tmp;

		if(key < tmp->key)
		{
			tmp->left = delete_elemain(tmp->left, tmp, key);
		}
		else if(key > tmp->key)
		{ 
			tmp->right = delete_elemain(tmp->right, tmp, key);
		}
		else
		{
			if(tmp->right == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->left;
				else if(tmp->key > prev->key)
					prev->right = tmp->left;
				else
					root = tmp->left;
			}
			else if(tmp->left == nullptr)
			{
				if(tmp->key < prev->key)
					prev->left = tmp->right;
				else if(tmp->key > prev->key)
					prev->right = tmp->right;
			}
			else
			{
				node* dlt = tmp->right;
				node* prev = dlt;

				while(dlt->left != nullptr)
				{
					prev = dlt;
					dlt = dlt->left;
				}

				tmp->key = dlt->key;
				tmp->value = dlt->value;

				delete_elemain(tmp->right, prev, dlt->key);
			}
		}

		// update height;
		tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

		// balance
		int balance = getBalance(tmp);

		// LL
		if(balance > 1 && key < tmp->left->key)
			return rotateRight(tmp);

		// RR
		if(balance < -1 && key < tmp->right->key)
			return rotateLeft(tmp);

		// LR
		if(balance > 1 && key > tmp->left->key)
		{
			tmp->left = rotateLeft(tmp->left);
			return rotateRight(tmp);
		}

		// RL
		if(balance < -1 && key < tmp->right->key)
		{
			tmp->right = rotateRight(tmp->right);
			return rotateLeft(tmp);
		}

		return tmp;
	}

	void search(string key)
	{
		// 
	}
};

int main()
{
	dict *d = new dict();

	d->insert("Book", "Used to read");
	d->insert("Name", "Used to mention someone");
	d->insert("Zebra", "An animal");
	d->insert("Table", "Used to sit");
	d->insert("Tabla", "An indian band");

	d->display("ascending");
	d->delete_ele("Name");
	d->display("ascending");
	return 0;
}
