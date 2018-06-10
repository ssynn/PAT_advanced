#include "stdafx.h"
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n, sum = 0, temp, k = 0;
	cin >> n;
	sum += (n * 5);
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		if (temp > k)
			sum += ((temp-k)*6);
		else
			sum += ((k-temp)*4);
		k = temp;
	}
	cout << sum;
	system("pause");
	return 0;
}
