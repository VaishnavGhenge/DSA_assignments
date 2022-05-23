#include<iostream>
using namespace std;

// clientSeperateChaining- collision avoiding using seperate chaining method
class clientSeperateChaining {
	long long int phoneNo;
	string name;
	clientSeperateChaining* next;

public:
	clientSeperateChaining(string name, long long int phoneNo)
	{
		this->phoneNo = phoneNo;
		this->name = name;
		next = nullptr;
	}

	clientSeperateChaining()
	{
		next = nullptr;
	}

	friend class Hashtable;
};

class Hashtable {
	clientSeperateChaining *arr[10];
public:
	Hashtable()
	{
		for(int i = 0; i < 10; i++)
		{
			arr[i] = new clientSeperateChaining();
		}
	}

	void insert(string name, long long int phoneno)
	{
		int index = hashFunction(name);

		if(arr[index]->next == nullptr)
		{
			arr[index]->next = new clientSeperateChaining(name, phoneno);
			cout << "Record inerted\n";
		}
		else
		{
			clientSeperateChaining *n = arr[index]->next;

			while(n->next != nullptr)
				n = n->next;

			n->next = new clientSeperateChaining(name, phoneno);
			cout << "Record inerted\n";
		}
	}

	void lookUp(string name)
	{
		int index = hashFunction(name);

		clientSeperateChaining *n = arr[index]->next;

		if(n == nullptr)
		{
			cout << name << "- Phone number is not present for given name\n";
			return;
		}
		else
		{
			while(n != nullptr)
			{
				if(n->name == name)
				{
					cout << "Name: " << n->name << "\nPhone No: " << n->phoneNo << endl;
					break;
				}

				n = n->next;
			}

			if(n == nullptr)
				cout << name << "- Phone number is not present for given name\n";
		}
	}

	void display()
	{
		for(int i = 0; i < 10; i++)
		{
			cout << i << "- ";
			clientSeperateChaining* n = arr[i]->next;
			while(n != nullptr)
			{
				cout << n->name << " ";
				n = n->next;
			}

			cout << endl;
		}
	}

	int hashFunction(string name)
	{
		return name[0] % 10;
	}
};

int main() {
	Hashtable *tbl = new Hashtable();

	tbl->insert("Vaishnav", 8999467933);
	tbl->insert("Vaibhav", 8999467933);
	tbl->insert("Ganesh", 8999467933);
	tbl->insert("Jayesh", 8999467933);
	tbl->insert("Tejas", 8999467933);
	tbl->insert("Rohan", 8999467933);
	tbl->insert("Shreyash", 8999467933);

	tbl->display();

	tbl->lookUp("Tejas");
	tbl->lookUp("Rohon");

	// tbl->display();
	return 0;
}