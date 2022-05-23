// Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a

#include <iostream>
using namespace std;

// clientLinearProbing- collision avoiding using linear probing method
class clientLinearProbing
{
	long long int phoneNo;
	string name;

public:
	clientLinearProbing()
	{
		this->name = "";
		this->phoneNo = 0;
	}

	clientLinearProbing(string name, long long int phoneNo)
	{
		this->name = name;
		this->phoneNo = phoneNo;
	}

	friend class Hashtable;
};

class Hashtable
{
	clientLinearProbing *arr[10];

public:
	Hashtable()
	{
		for(int i = 0; i < 10; i++)
		{
			arr[i] = new clientLinearProbing();
		}
	}

	int hashFunction(string name)
	{
		return name[0] % 10;
	}

	void insert(string name, long long int phoneNo)
	{
		int index = hashFunction(name);

		if(arr[index]->name == "")
		{
			arr[index] = new clientLinearProbing(name, phoneNo);
			cout << name << "- Record inerted at " << index << endl;
		}
		else
		{
			int count = 0;
			while(count < 10)
			{
				if(arr[(++index)%10]->name == "")
				{
					arr[(index)%10] = new clientLinearProbing(name, phoneNo);
					cout << name << "- Record inerted at " << index%10 << endl;
					return;
				}

				count++;
			}

			if(count > 9)
			{
				cout << "HashTable overflow\n";
			}
		}
	}

	void lookUp(string name)
	{
		int index = hashFunction(name);

		if(arr[index]->name == name)
		{
			cout << "\nName: " << arr[index]->name << "\nPhone No: " << arr[index]->phoneNo << endl;
			return;
		}
		else
		{
			int count = 0;
			while(count < 10)
			{
				if(arr[(++index)%10]->name == name)
				{
					cout << "\nName: " << arr[index]->name << "\nPhone No: " << arr[index]->phoneNo << endl;
					break;
				}

				count++;
			}

			// cout << name << "- count: " << count << endl;

			if(count > 9)
				cout << "Number is not present for given name\n";
		}
	}
};

int main()
{
	Hashtable *tbl = new Hashtable();

	tbl->insert("Vaishnav", 8999467933);
	tbl->insert("Vaibhav", 8999467933);
	tbl->insert("Ganesh", 8999467933);
	tbl->insert("Jayesh", 8999467933);
	tbl->insert("Tejas", 8999467933);
	tbl->insert("Rohan", 8999467933);
	tbl->insert("Shreyash", 8999467933);

	// tbl->display();

	tbl->lookUp("Tejas");
	tbl->lookUp("Rohon");
	return 0;
}
