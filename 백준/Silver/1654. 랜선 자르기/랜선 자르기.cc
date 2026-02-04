#include<iostream>
#include<vector>
using namespace std;

long long get_n(long long mid, int k, vector<int> wires)
{
	long long count = 0;
	for (int i = 0; i < k; i++)
	{
		count += wires[i] / mid;
	}

	return count;
}

long long get_max(vector<int> wires, int k, int n)
{
	long long start, end, mid;
	long long ans = 0;

	start = 1;
	end = -1;

	for (int i = 0; i < k; i++)
	{
		if (wires[i] > end)
			end = wires[i];
	}
	mid = (start + end) / 2;

	while (start <= end)
	{
		mid = (start + end) / 2;
		long long count = get_n(mid, k, wires);

		if (count >= n)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return ans; 
}

int main()
{
	int k, n;
	cin >> k >> n;
	vector<int> wires;
	int wire;
	for (int i = 0; i < k; i++)
	{
		cin >> wire;
		wires.push_back(wire);
	}
	
	cout << get_max(wires, k, n) << endl;

	return 0;
}