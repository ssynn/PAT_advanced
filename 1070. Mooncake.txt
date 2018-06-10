#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
struct good
{
	double stock;
	double total;
	double price;
};
bool cmp(good &a,good &b)
{
	return a.price > b.price;
}
int main()
{
	int n, sum, k = 0, haha = 0, yu = 0, yu2 = 0, yu1 = 0;
	double profit = 0;
	good temp;
	cin >> n >> sum;
	vector<good>a(n);
	for (int i = 0; i < n; i++)//input stock
		cin >> a[i].stock;
	for (int i = 0; i < n; i++)//input total
	{
		cin >> a[i].total;
		a[i].price = a[i].total / a[i].stock;
	}
	sort(a.begin(), a.end(), cmp);
	while (sum > a[k].stock&&k<n)
	{
		sum = sum - a[k].stock;
		profit = profit + a[k].total;
		k++;
	}
	if (k<n)
		profit = profit + (sum)*a[k].price;
	cout << fixed << setprecision(2) << profit;
	system("pause");
	return 0;
}
