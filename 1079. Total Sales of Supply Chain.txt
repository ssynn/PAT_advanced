#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
using namespace std;
double price, increase;
struct Retailer
{
	int id;
	double total;
};
double GetTotalPrice(int self, vector<Retailer> &Tree)					//每次访问都记录已经访问的结点统计量
{
	if (Tree[self].total > 0)
	{
		return Tree[self].total;
	}
	else
	{
		Tree[self].total= GetTotalPrice(Tree[self].id, Tree)*increase;
		return Tree[self].total;
	}
}
int main()
{
	int n, ki, getProdects,total;
	double sum = 0;
	cin >> n >> price >> increase;
	increase = increase/100 + 1;

	vector<Retailer>supplyTree(n);
	vector<Retailer>retailer;
	Retailer temp;
	supplyTree[0].id = -1;
	supplyTree[0].total = price;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &ki);
		if(ki)
			for (int j = 0; j < ki; j++)
			{
				scanf_s("%d", &getProdects);
				supplyTree[getProdects].id = i;
			}
		else
		{
			scanf_s("%d", &getProdects);
			temp.id = i;
			temp.total = getProdects;
			retailer.push_back(temp);
		}
	}
	for (auto &i : retailer)
		sum += GetTotalPrice(i.id, supplyTree)*i.total;

	

	
	cout <<fixed<<setprecision(1)<< sum;
    return 0;
}

/*

for (int i = 0; i < n; i++)
cout << supplyTree[i] << ' ';
for (auto &i : retailer)
cout << i.id << ' ' << i.total << endl;

for (int i = 0; i < n; i++)
		cout << supplyTree[i].id << ' '<<supplyTree[i].total<<endl;

*/