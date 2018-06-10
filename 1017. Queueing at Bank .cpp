
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
const int START_WORK = 28800,MAX=10000000,END_TIME=61200;
struct Time
{
	int hour, minute, second;
};
struct Customer
{
	int arriveTime, startTime, leaveTime;
	int processingTime;
	bool flag;

};
int ToSecond(int a,int b,int c)
{
	return a * 60 * 60 + b * 60 + c;
}
bool cmp(Customer a, Customer b)
{
	return a.arriveTime < b.arriveTime;
}
int main()
{
	int n,hour,minute,second,k=1,p,minLeaveTime=MAX,windows;
	double waitTime = 0;
	char temp;
	cin >> n>>windows;
	vector<Customer>customer(n);
	for (int i = 0; i < n; i++)
	{
		cin >> hour>>temp>>minute>>temp>>second;
		customer[i].arriveTime = ToSecond(hour,minute,second);
		cin >> customer[i].processingTime;
	}
	sort(customer.begin(), customer.end(), cmp);


	for (int i = 0; i < windows; i++)
	{
		if (customer[i].arriveTime < START_WORK)
		{
			customer[i].startTime = START_WORK;
			waitTime += (START_WORK - customer[i].arriveTime);
		}
		else
			customer[i].startTime = customer[i].arriveTime;
		customer[i].flag = 0;
		customer[i].leaveTime = customer[i].startTime + customer[i].processingTime*60;
		if (i == n - 1)
			break;
	}

	

	k = windows;
	for (int i = windows; i < n; i++)
	{
		if (customer[i].arriveTime > END_TIME)
			break;
		minLeaveTime = MAX;
		for (int j = 0; j < k; j++)
		{
			if (customer[j].leaveTime < minLeaveTime&&customer[j].flag == 0)
			{
				minLeaveTime = customer[j].leaveTime;
				p = j;
			}
		}
		k++;
		customer[p].flag = 1;
		if (customer[i].arriveTime < minLeaveTime)
			customer[i].startTime = minLeaveTime;
		else
			customer[i].startTime = customer[i].arriveTime;
		customer[i].leaveTime = customer[i].processingTime*60+customer[i].startTime;
		waitTime +=( customer[i].startTime - customer[i].arriveTime);
		//cout << customer[i].arriveTime << ' ' << customer[i].startTime << ' ' << customer[i].leaveTime << endl;
	}
	
	//cout << waitTime<<endl;
	waitTime /= (60*k);
	cout <<fixed<<setprecision(1)<< waitTime;
	return 0;
}
