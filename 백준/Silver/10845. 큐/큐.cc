#include<iostream>
#include<string>
using namespace std;

class Queue 
{
	struct data_node
	{
		int data;
		data_node* link;
	};
	int size;
	data_node* front, * back;
public:
	Queue()
	{
		size = 0;
		front = NULL;
		back = NULL;
	}

	~Queue()
	{
		while (front != NULL)
		{
			data_node* temp;
			temp = front;
			front = front->link;
			delete temp;
		}
	}

	int is_empty()
	{
		if (size == 0)
			return 1;
		else
			return 0;
	}

	void push(int input)
	{
		data_node* temp = new data_node;
		temp->data = input;
		temp->link = NULL;
		if (is_empty())
		{
			front = temp;
			back = temp;
		}
		else
		{
			back->link = temp;
			back = temp;
		}
		size++;
	}

	int pop()
	{
		if (is_empty())
			return -1;
		else
		{
			int temp_data = front->data;
			data_node* temp = front;
			front = front->link;
			delete temp;
			size--;
			return temp_data;
		}
	}

	int get_size()
	{
		return size;
	}

	int get_front()
	{
		if (is_empty())
			return -1;
		else
			return front->data;
	}

	int get_back()
	{
		if (is_empty())
			return -1;
		else
			return back->data;
	}
};

int main(void)
{
	int order_count;	
	cin >> order_count;

	string order;
	int input;
	Queue queue;
	for (int i = 0; i < order_count; i++)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> input;
			queue.push(input);
		}
		else if (order == "pop")
		{
			cout << queue.pop() << "\n";
		}
		else if (order == "size")
		{
			cout << queue.get_size() << "\n";
		}
		else if (order == "empty")
		{
			cout << queue.is_empty() << "\n";
		}
		else if (order == "front")
		{
			cout << queue.get_front() << "\n";
		}
		else if (order == "back")
		{
			cout << queue.get_back() << "\n";
		}
	}
}