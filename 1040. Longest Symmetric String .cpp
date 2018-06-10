#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
using namespace std;

int main()
{
	string a;
	int p=0, next=1,maxLength=1;
	getline(cin, a);
	while (p < a.length() - 1)
	{
		int k = 1;
		while (p+k < a.length()&&p-k>=0&&a[p+k]==a[p-k])
		{
			//cout << a[p + k] << a[p - k] << endl;
			if (k*2+1 > maxLength)
				maxLength = k*2+1;
			k++;
		}
		while (p + k < a.length() && p - k+1 >= 0 && a[p + k] == a[p - k+1])
		{
			//cout << a[p + k] << a[p - k+1] << endl;
			if (k*2 > maxLength)
				maxLength = k*2;
			k++;
		}
		p++;
		next = p + 1;
	}

	cout << maxLength;
	system("pause");
	return 0;
}


