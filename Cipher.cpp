#include <iostream>
#include <string>
#include <cctype>

using namespace std;
void find(char a, char arr[][7])
{
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (arr[i][j] == a) cout << i << j;
}
int main()
{
	char alp[7][7];
	char ch;
	cin.get(ch);
	ch = tolower(ch);
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
		{
			alp[i][j] = ch;
			if (ch == 'z')ch = '0';
			else if (ch == '9')ch = 'a';
			else ch++;
		}

	string arr;
	getline(cin, arr);
	for (int i = 0; i<arr.size(); i++)
		find(tolower(arr[i]), alp);
	return 0;
}
