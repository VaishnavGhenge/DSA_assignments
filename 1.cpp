#include <iostream>
using namespace std;

class node {
	string name;
	node* child[10];
	int curSize;

public:
	node(string name) {
		this->name = name;
		curSize = 0;
	}

	friend class Book;
};

class Book {
	node* root;

public:
	Book(string name) {
		root = new node(name);
	}

	void insert(string name, string type) {
		if(type == "chapter") {
			if(root->curSize < 10)
			{
				root->child[root->curSize] = new node(name);
				root->curSize++;
				cout << "chapter inserted\n";
				return;
			}
			else
			{
				cout << "Out of size/overflow\n";
			}
		}
		else if(type == "section") {
			string chapter;

			cout << "Enter chapter: ";
			cin >> chapter;

			node* chap = nullptr;
			for(int i = 0; i < root->curSize; i++) {
				if(chapter == root->child[i]->name) {
					chap = root->child[i];
					break;
				}
			}

			if(chap == nullptr) {
				cout << "Chapter is not present in Book\n";
				return;
			} else {
				if(chap->curSize < 10) {
					chap->child[chap->curSize] = new node(name);
					chap->curSize++;
					cout << "section inserted\n";
					return;
				}
			}
		}
		else if(type == "sub-section") {
			string chapter;

			cout << "Enter chapter: ";
			cin >> chapter;

			node* chap = nullptr;
			for(int i = 0; i < root->curSize; i++) {
				if(chapter == root->child[i]->name) {
					chap = root->child[i];
				}
			}

			if(chap == nullptr) {
				cout << "Chapter is not present in Book\n";
				return;
			} else {
				string section;

				cout << "Enter section: ";
				cin >> section;

				node* sec = nullptr;
				for(int i = 0; i < chap->curSize; i++) {
					if(section == chap->child[i]->name) {
						sec = chap->child[i];
						break;
					}
				}

				if(sec == nullptr) {
					cout << "Section is not present\n";
					return;
				} else {
					if(sec->curSize < 10) {
						sec->child[sec->curSize] = new node(name);
						sec->curSize++;
						cout << "sub-section inserted\n";
						return;
					}
				}
			}	
		}
	}

	void display() {
		cout << "\nBook " << root->name << endl;
		for(int i = 0; i < root->curSize; i++) {
			cout << "\tChapter " << root->child[i]->name << endl;
			node* chap = root->child[i];
			for(int sec = 0; sec < chap->curSize; sec++) {
				cout << "\t\tSection " << chap->child[sec]->name << endl;
				node* section = chap->child[sec];
				for(int subsec = 0; subsec < section->curSize; subsec++) {
					cout << "\t\t\tSub-Section " << section->child[subsec]->name << endl;
				}
			}
		}
	}
};

int main() {
	Book *b = new Book("DSA");

	b->insert("BST", "chapter");
	b->insert("OBST", "chapter");
	b->insert("Display", "section");
	b->insert("Recursive", "sub-section");
	b->insert("Iterative", "sub-section");

	b->display();
	return 0;
}