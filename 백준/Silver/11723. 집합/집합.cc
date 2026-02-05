#include<iostream>
#include<limits>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int order_count, order_num;
	int mask = 0;
	string order;
	cin >> order_count;
	for(int i = 0; i < order_count; i++)
	{
		cin >> order;
		if (order == "all")
		{
			mask = numeric_limits<int>::max();
		}
		else if (order == "empty")
		{
			mask = 0;
		}
		else
		{
			cin >> order_num;
			if (order == "add")
			{
				mask |= (1 << order_num);
			}
			else if (order == "remove")
			{
				mask &= ~(1 << order_num);
			}
			else if (order == "toggle")
			{
				mask ^= (1 << order_num);
			}
			else if (order == "check")
			{
				cout << !!(mask & (1 << order_num)) << "\n";

			}
		}
	}
	return 0;
}