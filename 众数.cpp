#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<iterator>
using namespace std;//We need modern c++!!!
int main()
{
	vector<int>arr;
	istream_iterator<int>in_iter(cin);//有参数,则为输入流的迭代器,初始指向流首
	istream_iterator<int>eof;//无参数,默认为尾后迭代器
	while (in_iter!=eof)//dynamic
	arr.push_back(*in_iter++);
	unordered_set<int>value;
	copy(arr.begin(), arr.end(), insert_iterator<unordered_set<int>>(value, value.begin()));//获取arr中不同的值
	unordered_map<int, int>hash;//hash表储存
	int maxi = 0;
	for (auto x : arr)
	{
		hash[x]++;//会自动创建pair
		maxi = max(maxi, hash[x]);//获取最大值
	}
	if (value.size()*maxi == arr.size())
		cout << accumulate(arr.begin(),arr.end(),0);//无众数,第四个参数为默认加法
	else for (auto x : value)
		if (hash[x] == maxi)cout << x << endl;//输出众数
	return 0;
}

