#include<iostream>
#include<algorithm>
using namespace std;

typedef struct coordinates {
	int x;
	int y;
};

bool compare_coordinates(const coordinates& a, const coordinates& b) 
{
	if (a.x == b.x) 
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	coordinates* arr = new coordinates[count];
	for (int i = 0; i < count; i++) 
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + count, compare_coordinates);

	for (int i = 0; i < count; i++) 
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

	delete[] arr;
	return 0;
}