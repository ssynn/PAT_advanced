#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
using namespace std;
struct Card
{
	char a;
	int num;
};
Card* Shuffling(Card *orign,int *per)
{
	Card *res = new Card[55];
	for (int i = 1; i < 55; i++)
		res[per[i]] = orign[i];
	delete[]orign;
	return res;
}
int main()
{
	int n, permutation[55];
	char chart[5] = {'S','H','C','D','J'};
	Card *res = new Card[55];
	for (int i = 1; i < 55; i++)
	{
		res[i].num = ((i-1) % 13) + 1;
		res[i].a = chart[(i-1) / 13];
	}

	cin >> n;
	for (int i = 1; i <= 54; i++)
		cin >> permutation[i];
	for (int i = 0; i < n; i++)
		res = Shuffling(res,permutation);
	for (int i = 1; i < 54; i++)
		cout << res[i].a << res[i].num << ' ';
	cout << res[54].a << res[54].num;
	system("pause");
	return 0;
}


