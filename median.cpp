#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<int>num(n);
	for (int i = 0; i<n; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	if (n & 1)cout << num[(n - 1) / 2];
	else cout << ((num[n / 2] + num[n / 2 - 1]) + 1) / 2;
	return 0;
}
