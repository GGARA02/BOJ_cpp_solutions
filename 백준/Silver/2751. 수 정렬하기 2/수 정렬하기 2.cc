#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	int* array = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
	sort(array, array + count);
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << "\n";
	}
	delete[] array;
	return 0;
}