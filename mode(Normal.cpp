#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{

	int n, j;
	cin >> n;
	int first = 1, total = 0, maxi = 1, count = 1;
	vector<int>arr(n);
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i<n; i++)
	{
		j = 1;
		while (i + j<n&&arr[i] == arr[i + j]) { count++; j++; }
		maxi = max(maxi, count);
		count = 1;
	}
	vector<int>unqarr;
	unique_copy(arr.begin(), arr.end(), back_inserter(unqarr));//复制unique
	int len = unqarr.size();
	if (n==len*maxi)cout << total;//若数目相同，有最大长度*unique数值数=总数值数
	else for (int i = 0; i<n; i++)
	{
		j = 1;
		while (i + j<n&&arr[i] == arr[i + j]) { j++; count++; }
		if (count == maxi) { if (!first)cout << endl; cout << arr[i]; first = 0; }
		count = 1;
	}
	return 0;
}
