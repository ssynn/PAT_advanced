#include "stdafx.h"
#include<limits.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
using namespace std;
struct customers
{
	int num;
	int time;
	int outTime;
	int time2;
};
int main() {
	int n, m, k, q,time=0,min=100000,num=1,qCustomers,max=0;
	customers temp;
	cin >> n >> m >> k >> q;
	vector<queue<customers>>lines(n);
	queue<customers>person;
	map<int,customers>outList;
	for (int i = 0; i < k; i++)
	{
		cin >> temp.time;
		temp.num = num;
		temp.time2 = temp.time;
		num++;
		//cout << num <<' ' <<temp.time<<endl;
		if (temp.time > max)
			max = temp.time;
		person.push(temp);
	}

	for(int i=0;i<m;i++)//先将队伍填满
		for (int j = 0; j < n; j++)
		{
			if (!person.size())
				break;
			lines[j].push(person.front());
			if (lines[j].front().time < min)
				min = lines[j].front().time;
			person.pop();
		}

	int last=1;
	while (time<=(max+540)&&last )//处理业务过程保证17点前开始的人处理完
	{
		int tempMin=INT_MAX;//每处理完一轮就会更新最小值
		time += min;//处理完此轮业务的时间
		last = 0;//如果有余量则变成1
		for (int i = 0; i < n; i++)
		{
			if (lines[i].size())//队伍有人则处理业务
			{
				lines[i].front().time -= min;
				last = 1;
			}
			else
				continue;
			if (lines[i].front().time == 0 )//此人已经处理完成将其出队
			{
				lines[i].front().outTime = time;
				outList[lines[i].front().num] = lines[i].front();//将结果存入map
				//cout << lines[i].front().num << endl;
				lines[i].pop();
				if (person.size())
				{
					lines[i].push(person.front());
					person.pop();
				}
				else if (lines[i].size() == 0)
					continue;
			}	
			if (lines[i].front().time < tempMin&&lines[i].front().time)//更新最小时间
			{
				tempMin = lines[i].front().time;
			}
		}
		//cout << min << ' ' << tempMin << ' ' << min <<' '<<time<<' '<<last<<endl;
		min = tempMin;
	}
	for(int i = 0; i < q; i++)
	{
		int hour, minute;
		cin >> qCustomers;
		if ((outList[qCustomers].outTime-outList[qCustomers].time2)<540)
		{
			hour = outList[qCustomers].outTime / 60+8;
			min = outList[qCustomers].outTime % 60;
			cout << setfill('0') << setw(2) << hour << ':' << setfill('0') << setw(2) << min << endl;
			//cout << outList[qCustomers].outTime << endl;
		}
		else
			cout << "Sorry"<<endl;
	}
	system("pause");
	return 0;
}


/*
		for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (lines[j].size())
			{
				cout << lines[j].front().time << ' ';
				lines[j].pop();
			}
		}
		cout << endl;
	}


*/