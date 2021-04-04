#include <iostream>
using namespace std;
const int RUN = 32;

bool isEven(int num)
{
	if (num & 1)
		return 0;
	else
		return 1;
}

/////TIMSORT/////

void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void merge(int arr[], int l, int m, int r)
{ 
	int len1 = m - l + 1, len2 = r - m;
	int* left = new int[len1];
	int* right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
 
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}
 
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}
 
void timSort(int arr[], int n)
{

	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min((i + 31),
			(n - 1)));

	for (int size = RUN; size < n;
		size = 2 * size)
	{
		for (int left = 0; left < n;
			left += 2 * size)
		{
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1),
				(n - 1));

			merge(arr, left, mid, right);
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);
	printf("\n");
}

/////FIFO//////

/*ARRAY*/

struct Queue
{
	int array[1024];
	int head;
	int tail;
};
class FIFO
{
public:
	FIFO()
	{
		q->head = 0;
		q->tail = -1;
	}

	~FIFO()
	{

	}

	void Enqueue(int value)
	{
		q->tail++;
		q->array[q->tail] = value;
	}

	int Dequeue()
	{
		if (isEmpty() == 1)
		{
			cout << " Queue is empty.\n";
			return 0;
		}
		else
		{
			int a = q->array[q->head];
			q->head++;
			return a;
		}
	}

	bool isEmpty()
	{
		if (q->tail < q->head)
			return 1;
		else
			return 0;
	}

	int Size()
	{
		return q->tail - q->head + 1;
	}

	void Print()
	{
		if (isEmpty() == 1)
		{
			cout << " Queue is empty.\n";
		}
		else
		{
			for (int i = q->head; i <= q->tail; i++)
			{
				cout << " " << q->array[i];
			}
		}
	}
private:
	Queue* q = new Queue();
};

/*LIST*/

struct Node
{
	int value;
	Node* next;
	Node(int _value)
	{
		value = _value;
		next = NULL;
	}
};

class FIFO1
{
public:
	FIFO1()
	{
		head = NULL;
		tail = NULL;
	}

	~FIFO1()
	{
		while (head != NULL)
			Dequeue();
	}

	void Enqueue(int _value)
	{
		Node* NewNode = new Node(_value);
		if (tail == NULL)
			head = NewNode;
		else
			tail->next = NewNode;
		tail = NewNode;
	}

	Node* Dequeue()
	{
		if (isEmpty() == 1)
		{
			cout << " Queue is empty.\n";
			return 0;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			return temp;
		}
	}

	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}

	int Size()
	{
		int cnt = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			cnt++;
			temp = temp->next;
		}
		return cnt;
	}

	void Print()
	{
		if (isEmpty() == 1)
		{
			cout << " Queue is empty.\n";
		}
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				cout << " " << temp->value;
				temp = temp->next;
			}
		}
	}

private:
	Node* head;
	Node* tail;
};


int main()
{
	/*Is Even*/
	cout << " Hello World!\n Is this number even?\n Please, enter the number:\n";
	int num = 0;
	cin >> num;
	if (isEven(num) == 1)
		cout << " The number is even.";
	else
		cout << " The number is uneven.";
	cout << "\n";

	/*FIFO array (change fifo to fifo1 for list)*/

	FIFO1* fifo1 = new FIFO1;
	FIFO* fifo = new FIFO;

	cout << "\n FIFO ARRAY.\n Please, enter the first int value:\n";
	cin >> num;
	fifo->Enqueue(num);

	cout << " Please, enter the second int value:\n";
	cin >> num;
	fifo->Enqueue(num);

	cout << " Please, enter the third int value:\n";
	cin >> num;
	fifo->Enqueue(num);

	cout << "\n Is empty? " << fifo->isEmpty();
	cout << "\n Size: " << fifo->Size();
	cout << "\n Elements: ";
	fifo->Print();
	fifo->Dequeue();

	cout << "\n Is empty? " << fifo->isEmpty();
	cout << "\n Size: " << fifo->Size();
	cout << "\n Elements: ";
	fifo->Print();
	fifo->Dequeue();

	cout << "\n Is empty? " << fifo->isEmpty();
	cout << "\n Size: " << fifo->Size();
	cout << "\n Elements: ";
	fifo->Print();
	fifo->Dequeue();

	cout << "\n Is empty? " << fifo->isEmpty();
	cout << "\n Size: " << fifo->Size();
	cout << "\n Elements: ";
	fifo->Print();

	/*Timsort*/
	
	int arr[100];
	srand(time(NULL));
	for (int i = 0; i < 100; ++i) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << endl;
	}

	int n = sizeof(arr) / sizeof(arr[0]);
	printf("\n Given Array is\n");
	printArray(arr, n);

	time_t start, end;
	time(&start);

	timSort(arr, n);

	time(&end);
	double seconds = difftime(end, start);

	printf(" After Sorting Array is\n");
	printArray(arr, n);
	cout << "\n Time: " << seconds;
	return 0;
}