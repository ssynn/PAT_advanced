#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//判断连续字符的长度是否为k的整数被

int main()
{
	int k,len,i=0;
	string val;
	bool good[125] = { 0 }, bad[125] = { 0 };
	vector<char>ans;
	cin >> k >> val;

	len = val.size();
	for (i = 0; i < len;)
	{
		int flag = 0, j=1;
		if (!good[val[i]])
			while (val[i] == val[i + j])
				j++;
		if ((j%k)!=0)
			flag = 1;
		
		if (flag)
			good[val[i]] = 1;
		else
		{
			ans.push_back(val[i]);
		}
		i += j;
	}

	for (auto &x:ans)
	{
		if (!good[x])
		{
			if(!bad[x])
				cout << x;
			bad[x] = 1;
		}
	}
	cout << endl;
	for (i = 0; i < len ; i++)
	{
		if (!good[val[i]])
			i = i + k-1;
		cout << val[i];
	}

	system("pause");
	return 0;
}