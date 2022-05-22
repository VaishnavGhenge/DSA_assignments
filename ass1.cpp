#include<iostream>
using namespace std;

class node {
	string name;
	node* n[10];
	int curSize;

public:
	node(string name) {
		this->name = name;
		this->curSize = 0;
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
			if(root->curSize < 10) {
				root->n[root->curSize++] = new node(name);
				cout << "--chapter " << name << " inserted at " << root->curSize << "--\n";
			} else {
				cout << "Book out of size\n";
			}
		} else if(type == "section") {
			string chap;
			cout << "In which chapter you want to insert this section " << name << ": ";
			cin >> chap;

			// cout << chap << endl;
			int pos = 0;

			node* chapter = nullptr;
			for(int i = 0; i < root->curSize; i++) {
				// cout << "iteration " << i << endl;
				// cout << root->n[pos++]->name << endl;
				if(root->n[i]->name == chap) {
					// cout << "--in--";
					chapter = root->n[i];
					break;
				}
			}

			if(chapter == nullptr) {
				cout << "Chapter does not exists\n";
			} else {
				if(chapter->curSize < 10) {
					chapter->n[chapter->curSize++] = new node(name);
					cout << "--section " << name << " inserted at " << chapter->curSize << "--\n";
				} else {
					cout << "Chapter out of size\n";
				}
			}
		} else if(type == "subsection") {
			string chap;
			string sec;

			cout << "In which chapter you want to insert this sub-section " << name << ": ";
			cin >> chap;

			node* chapter = nullptr;
			for(int i = 0; i < root->curSize; i++) {
				if(root->n[i]->name == chap) {
					chapter = root->n[i];
					break;
				}
			}

			if(chapter == nullptr) {
				cout << "Chapter does not exists\n";
				return;
			} else {
				if(chapter->curSize > 10) {
					cout << "Chapter out of size\n";
					return;				}
			}

			cout << "In which section you want to insert this sub-section " << name << ": ";
			cin >> sec;

			node* section = nullptr;
			for(int i = 0; i < chapter->curSize; i++) {
				if(chapter->n[i]->name == sec) {
					section = chapter->n[i];
					break;
				}
			}

			if(section == nullptr) {
				cout << "Section does not exists\n";
				return;
			} else {
				if(section->curSize < 10) {
					section->n[section->curSize++] = new node(name);
					cout << "--subsection " << name << " inserted at " << section->curSize << "--\n";
				} else {
					cout << "Section out of size\n";
				}
			}
		}
	}

	void display() {
		cout << "\nBook " << root->name << endl;
		for(int i = 0; i < root->curSize; i++) {
			cout << "\tChapter " << root->n[i]->name << endl;
			node* chap = root->n[i];
			for(int sec = 0; sec < chap->curSize; sec++) {
				cout << "\t\tSection " << chap->n[sec]->name << endl;
				node* section = chap->n[sec];
				for(int subsec = 0; subsec < section->curSize; subsec++) {
					cout << "\t\t\tSub-Section " << section->n[subsec]->name << endl;
				}
			}
		}
	}
};


int main() {
	Book* b = new Book("DSA");
	b->insert("BST", "chapter");
	b->insert("Graph", "chapter");
	// b->insert("AVL", "chapter");
	// b->insert("BST", "chapter");
	b->insert("Insert", "section");
	b->insert("Insert", "section");
	b->insert("Recursive", "subsection");
	b->insert("Iterative", "subsection");

	b->display();
	return 0;
}