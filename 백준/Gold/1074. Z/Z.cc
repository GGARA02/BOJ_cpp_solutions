#include<iostream>
using namespace std;

int get_result(int N, int r, int c)
{
	if (N == 0)
		return 0;

	int half = 1 << N - 1;
	int block = half * half;

	if (r >= half)
	{
		if (c >= half)
			return block * 3 + get_result(N - 1, r - half, c - half);
		else 
			return block * 2 + get_result(N - 1, r - half, c);
	}
	else
	{
		if (c >= half)
			return block + get_result(N - 1, r, c - half);
		else
			return get_result(N - 1, r, c);
	}
}

int main()
{
	int N, r, c;
	cin >> N >> r >> c;
	cout << get_result(N, r, c) << endl;
}