#include<iostream>
#include<cmath>
using namespace std;

void print_prime(int m, int n)
{
	for (int i = m; i <= n; i++)
	{
		int is_prime = 1;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				is_prime = 0;
				break;
			}
		}
		if (i == 1)
			is_prime = 0;
		if (is_prime)
			cout << i << "\n";
	}
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	print_prime(m, n);
}