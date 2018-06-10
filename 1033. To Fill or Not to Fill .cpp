#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<list>
#include<iomanip>
using namespace std;

struct Station
{
	double price;
	int distance;
	bool operator<(Station &a)
	{
		return distance < a.distance;
	}
};

int main()
{
	int tank, sum_distance, per_l, n,max_distance,i=0;
	cin >> tank >> sum_distance >> per_l >> n;
	max_distance = per_l*tank;
	vector<Station>road(n);

	for (auto &i : road) cin >> i.price >> i.distance;
	sort(road.begin(), road.end());
	if(road[0].distance!=0)														//������û�м���վ
	{
		cout << "The maximum travel distance = " << 0 << ".00";
		return 0;
	}
	road.push_back(Station());
	road.back().distance = sum_distance;
	road.back().price = 0;

	int surplus = 0;
	double sum_value = 0;
	while (i != n)
	{
		int p = i+1,next;														//̽����
		double min_price = 10000;

		if (road[p].distance - road[i].distance > max_distance)					//�޷��ִ���һվ
		{
			cout << "The maximum travel distance = " << road[i].distance + max_distance << ".00";
			return 0;
		}

		while (p<=n&&(road[p].distance - road[i].distance) <= max_distance)		//�ҵ�·������̵ļ���վ
		{
			if (road[p].price <= road[i].price)
			{
				next = p;
				break;
			}
			if (road[p].price < min_price)
			{
				next = p;
				min_price = road[p].price;
			}
			p++;
		}
		if (road[next].price <= road[i].price)									//nextվ���ͼ�С�ڵ�ǰվ���ͼ�
		{
			int add = road[next].distance - road[i].distance-surplus;
			if (add > 0)														//��Ҫ����
			{
				sum_value += add*road[i].price;
				surplus = 0;
			}
			else
				surplus += add;													//����Ҫ����

		}
		else																	//·����û�и�С�ļ���վ
		{
			int add = max_distance - surplus;
			surplus = max_distance-road[next].distance+road[i].distance;
			sum_value += add*road[i].price;
		}
		i = next;
	}

	cout << fixed << setprecision(2) << sum_value / per_l;

	system("pause");
	return 0;
}
