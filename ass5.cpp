// Implement all the functions of a dictionary (ADT) using hashing and handle collisions using chaining with / without replacement.

#include <iostream>
using namespace std;

class node
{
	int data;
	node* next;

public:
	node(int data)
	{
		this->data = data;
		next = nullptr;
	}

	node()
	{
		data = -1;
		next = nullptr;
	}

	friend class dictWithoutReplacement;
	friend class dictWithReplacement;
};

class dictWithoutReplacement
{
	node* root[10];

public:
	dictWithoutReplacement()
	{
		for(int i = 0; i < 10; i++)
		{
			root[i] = new node();
		}
	}

	int hashFunction(int data)
	{
		return data%10;
	}

	void insert(int data)
	{
		int index = hashFunction(data);

		if(root[index]->data == -1)
		{
			root[index]->data = data;
			cout << data << " got inserted1\n";
		}
		else
		{
			node* tmp = root[index];

			int count = 0;
			while(count < 10)
			{
				if(root[(++index)%10]->data == -1)
				{
					root[(index)%10]->data = data;
					tmp->next = root[index];
					cout << data << " got inserted2\n";
					break;
				}

				count++;
			}

			if(count > 9)
			{
				cout << "Table is full\n";
			}
		}
	}

	void display()
	{
		cout << endl;
		node* tmp = root[0];
		for(int i = 0; i < 10; i++)
		{
			cout << tmp->data << ": " << tmp->next << endl;
		}
	}

	void delete_ele(int data)
	{
		int index = hashFunction(data);

		if(root[index]->data == data)
		{
			if(root[index]->next == nullptr)
			{
				root[index]->data = -1;
				cout << data << " got deleted\n";
			}
			else
			{
				node* tmpNext = root[index]->next;
				root[index] = tmpNext;
				tmpNext->data = -1;
				tmpNext->next = nullptr;
				cout << data << " got deleted\n";
			}
		}
		else
		{
			node* tmp = root[index];

			while(tmp->next != nullptr)
			{
				if(tmp->data == data)
				{
					if(tmp->next == nullptr)
					{
						tmp->data = -1;
						cout << data << " got deleted\n";
					}
					else
					{
						node* tmpNext = tmp->next;
						tmp->data = tmpNext->data;
						tmp->next = tmpNext->next;
						tmpNext->data = -1;
						tmpNext->next = nullptr;
						cout << data << " got deleted\n";
					}

					break;
				}

				tmp = tmp->next;
			}
		}
	}

	void search(int data)
	{
		int index = hashFunction(data);

		if(root[index]->data == data)
		{
			cout << data << " found in table\n";   
		}
		else
		{
			node* tmp = root[index];
			while(tmp->next != nullptr)
			{
				if(tmp->data == data)
				{
					cout << data << " found in table\n";
					break;
				}

				tmp = tmp->next;
			}

			if(tmp->data == data)
			{
				cout << data << " found in table\n";
			}
			else
			{
				cout << data << " not found in table\n";
			}
		}
	}
};

class dictWithReplacement
{
	node* root[10];

public:
	dictWithReplacement()
	{
		for(int i = 0; i < 10; i++)
		{
			root[i] = new node();
		}
	}

	int hashFunction(int data)
	{
		return data%10;
	}	

	void insert(int data)
	{
		if(getSize() >= 10)
		{
			cout << "Table is full\n";
			return;
		}

		int index = hashFunction(data);

		if(root[index]->data == -1)
		{
			root[index]->data = data;
			cout << data << " got inserted1\n";
		}
		else
		{
			if(hashFunction(root[index]->data) == index)
			{
				node* tmp = root[index];

				int count = 0;
				while(count < 10)
				{
					if(root[(++index)%10]->data == -1)
					{
						root[(index)%10]->data = data;
						tmp->next = root[index];
						cout << data << " got inserted2\n";
						break;
					}

					count++;
				}

				if(count > 9)
				{
					cout << "Table is full\n";
				}			
			}
			else
			{
				node* origNext = root[index]->next;
				int origData = root[index]->data;
				root[index]->data = data;
				// display();

				int count = 0;
				while(count < 10)
				{
					if(root[(++index)%10]->data == -1)
					{
						root[(index)%10]->data = origData;
						root[(index)%10]->next = origNext;;

						// display();

						// inserting address of given node to previous node
						node* tmp = root[hashFunction(origData)];
						node* prev = nullptr;
 
						while(tmp->next != nullptr)
						{
							if(tmp->data == origData)
								break;
							prev = tmp;
							tmp = tmp->next;
						}

						// cout << prev << " " << tmp << endl;
						prev->next = root[(index)%10];
						break;
					}

					count++;
				}

				if(count > 10)
				{
					cout << "Table is full\n";
				}
				else
				{
					cout << data << " got inserted in hash table\n";
				}
			}
		}
	}

	void display()
	{
		cout << endl;
		for(int i = 0; i < 10; i++)
		{
			cout << i << " " << root[i]->data << " " << root[i]->next << endl;
		}
	}

	void delete_ele(int data)
	{
		int index = hashFunction(data);

		if(root[index]->data == data)
		{
			if(root[index]->next == nullptr)
			{
				root[index]->data = -1;
				cout << data << " got deleted\n";
			}
			else
			{
				node* tmpNext = root[index]->next;
				root[index] = tmpNext;
				tmpNext->data = -1;
				tmpNext->next = nullptr;
				cout << data << " got deleted\n";
			}
		}
		else
		{
			node* tmp = root[index];

			while(tmp->next != nullptr)
			{
				if(tmp->data == data)
				{
					if(tmp->next == nullptr)
					{
						tmp->data = -1;
						cout << data << " got deleted\n";
					}
					else
					{
						node* tmpNext = tmp->next;
						tmp->data = tmpNext->data;
						tmp->next = tmpNext->next;
						tmpNext->data = -1;
						tmpNext->next = nullptr;
						cout << data << " got deleted\n";
					}

					break;
				}

				tmp = tmp->next;
			}

			if(tmp->data == data)
			{
				if(tmp->next == nullptr)
				{
					tmp->data = -1;
					cout << data << " got deleted\n";
				}
				else
				{
					node* tmpNext = tmp->next;
					tmp->data = tmpNext->data;
					tmp->next = tmpNext->next;
					tmpNext->data = -1;
					tmpNext->next = nullptr;
					cout << data << " got deleted\n";
				}
			}
		}	
	}

	int getSize()
	{
		int count = 0;
		for(int i = 0; i < 10; i++)
		{
			if(root[i]->data != -1)
				count++;
		}

		return count;
	}

	void search(int data)
	{
		int index = hashFunction(data);

		if(root[index]->data == data)
		{
			cout << data << " found in hash table\n";
		}
		else
		{
			node* tmp = root[index];
			while(tmp->next != nullptr)
			{
				if(tmp->data == data)
				{
					cout << data << " found in hash table\n";
					break;
				}
				tmp = tmp->next;
			}

			if(tmp->data == data)
			{
				cout << data << " found in hash table\n";
			}
			else
			{
				cout << data << " is not present in hash table\n";
			}
		}
	}
};


int main()
{
	dictWithReplacement* d = new dictWithReplacement();
	d->insert(21);
	d->insert(45);
	d->insert(87);
	d->insert(22);
	d->insert(232);
	d->insert(89);

	d->insert(123);
	d->insert(124);
	d->insert(128);
	d->insert(129);
	d->insert(120);

	// d->display();
	d->search(232);

	d->delete_ele(232);
	// d->display();

	d->search(232);
	// d->display();
	return 0;
}