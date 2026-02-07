#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int order_count;
	cin >> order_count;
	vector<int> stairs(order_count);
	for (int i = 0; i < order_count; i++)
	{
		cin >> stairs[i];
	}
	vector<int> scores(order_count);
	scores[0] = stairs[0];

	if (order_count >= 2)
	{
		scores[1] = stairs[0] + stairs[1];
	}

	if (order_count >= 3)
	{
		scores[2] = max(stairs[0], stairs[1]) + stairs[2];
	}

	if (order_count >= 4)
	{
		for (int i = 3; i < order_count; i++)
		{
			scores[i] = max(scores[i - 2], scores[i - 3] + stairs[i - 1]) + stairs[i];
		}
	}

	cout << scores[order_count - 1] << "\n";

	return 0;
}