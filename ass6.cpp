// Read the marks obtained by students of second year in an online examination of

#include <iostream>
using namespace std;

class Heap
{
	int size;
	int *minHeap, *maxHeap;

public:
	Heap(int n)
	{
		minHeap = new int[n];
		maxHeap = new int[n];
		size = n;
	}

	void insert()
	{
		cout << "Enter student subject marks: \n";
		for(int i = 0; i < size; i++)
		{
			int inp;
			cout << "Student " << (i+1) << ": ";
			cin >> inp;

			minHeap[i] = inp;
			adjust("minheap", i);

			maxHeap[i] = inp;
			adjust("maxheap", i);
		}
	}

	void adjust(string type, int index)
	{
		if(type == "minheap")
		{
			while(minHeap[(int)index/2] > minHeap[index])
			{
				int tmp = minHeap[(int)index/2];
				minHeap[(int)index/2] = minHeap[index];
				minHeap[index] = tmp;

				index = (int)index/2;
				if(index <= 0)
					break;
			}
		} else if(type == "maxheap")
		{
			while(maxHeap[(int)index/2] < maxHeap[index])
			{
				int tmp = maxHeap[(int)index/2];
				maxHeap[(int)index/2] = maxHeap[index];
				maxHeap[index] = tmp;

				index = (int)index/2;
				if(index <= 0)
					break;
			}
		}
	}

	void getMin()
	{
		cout << "Minimum marks: " << minHeap[0] << endl;
	}

	void getMax()
	{
		cout << "Maximum marks: " << maxHeap[0] << endl;
	}

	void printMinHeap()
	{
		cout << "\nComplete minHeap: \n";
		for(int i = 0; i < size; i++)
		{
			cout << minHeap[i] << " ";
		}

		cout << endl;
	}

	void printMaxHeap()
	{
		cout << "\nComplete maxHeap: \n";
		for(int i = 0; i < size; i++)
		{
			cout << maxHeap[i] << " ";
		}

		cout << endl;
	}
};

int main()
{
	int n;
	cout << "Enter number of students: ";
	cin >> n;

	Heap *h = new Heap(n); 

	h->insert();

	h->getMin();
	h->getMax();
	h->printMinHeap();
	h->printMaxHeap();
	return 0;
}