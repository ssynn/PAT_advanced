
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	int n,i;
	cin >> n;
	vector<int>val(n);
	for (int i = 0; i < n; i++)
		cin >> val[i];

	sort(val.begin(), val.end());

	if (val[0] > n)
	{
		cout << n;
		return 0;
	}

	for (i = n - 1; i >= 0; i--)
	{
		if (val[i] <= n - i)
		{
			cout << n - i - 1;
			break;
		}
	}

	system("pause");
    return 0;
}

