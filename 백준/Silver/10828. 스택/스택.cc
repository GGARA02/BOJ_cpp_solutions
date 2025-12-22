#include<iostream>
#include<string>
using namespace std;

class Stack
{
	struct data_node
	{
		int data;
		data_node* link;
	};
	int size;
	data_node* top;
public:
	Stack()
	{
		size = 0;
		top = NULL;
	}

	~Stack()
	{
		while (top != NULL)
		{
			data_node* temp;
			temp = top;
			top = top->link;
			delete temp;
		}
	}

	int is_empty() const
	{
		if (size == 0)
			return 1;
		else
			return 0;
	}

	int get_size() const
	{
		return size;
	}

	void push(int input)
	{
		data_node* temp = new data_node;
		temp->data = input;
		temp->link = top;
		top = temp;
		size++;
	}

	int pop()
	{
		if (is_empty())
		{
			return -1;
		}
		else
		{
			data_node* temp = top;
			int output = top->data;
			top = top->link;
			delete temp;
			size--;
			return output;
		}
	}

	int get_top() const
	{
		if (is_empty())
		{
			return -1;
		}
		else
		{
			return top->data;
		}
	}
};

int main(void)
{
	Stack stack;

	int order_count;
	cin >> order_count;

	string order;
	int input;

	for (int i = 0; i < order_count; i++)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> input;
			stack.push(input);
		}
		else if (order == "pop")
		{
			cout << stack.pop() << "\n";
		}
		else if (order == "size")
		{
			cout << stack.get_size() << "\n";
		}
		else if (order == "empty")
		{
			cout << stack.is_empty() << "\n";
		}
		else if (order == "top")
		{
			cout << stack.get_top() << "\n";
		}
	}
}