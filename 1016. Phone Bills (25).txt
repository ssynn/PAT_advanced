#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<map>
using namespace std;
struct Customer
{
	string name;
	int day, hour, minute, second,month;
	bool flag;
};
struct CustomerBill
{
	string name;
	int day1, hour1, minute1,day2,hour2,minute2,time,month;
	double charge;
};
bool cmp(Customer a, Customer b)
{
	if (a.name != b.name)
		return a.name < b.name;
	else if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else if (a.minute != b.minute)
		return a.minute < b.minute;
	else return a.flag < b.flag;

}

int ToMinute(const Customer &a)
{
	return (a.day * 24 * 60 + a.hour * 60 + a.minute);
}
int main()
{
	int toll[24], n,k=0,p=1,cnt=0;
	char temp;
	string flag, position[2] = { "on-line","off-line" },lastName;
	vector<string>nameList;
	map<string, int>nameMap;
	for (int i = 0; i < 24; i++)
		cin >> toll[i];
	cin >> n;
	vector<Customer>customer(n);
	vector<CustomerBill>bill;
	for (int i = 0; i < n; i++)
	{
		cin >> customer[i].name >> customer[i].month >> temp >> customer[i].day >> temp;
		cin >> customer[i].hour >> temp >> customer[i].minute >>  flag;
		if (flag == "on-line")
			customer[i].flag = 0;
		else
			customer[i].flag = 1;
		if (nameMap[customer[i].name] == 0)
			nameList.push_back(customer[i].name);
		nameMap[customer[i].name] = 1;
	}

	sort(customer.begin(), customer.end(), cmp);
	sort(nameList.begin(), nameList.end());

	//找配对
	CustomerBill tem;
	k = 0; p = 1;
	while ((k<n)&&(p<n))
	{
		if (customer[k].flag == 0 && customer[p].flag == 1 && customer[p].name == customer[k].name)//合法记录
		{
			nameMap[customer[k].name] = 2;
			//cout << k <<' '<< p << endl;
			int day, hour,sumTime1,sumTime2;
			tem.month = customer[k].month;
			tem.name = customer[k].name;
			tem.day1 = customer[k].day;
			tem.hour1 = customer[k].hour;
			tem.minute1 = customer[k].minute;
			day=tem.day2 = customer[p].day;
			hour=tem.hour2 = customer[p].hour;
			tem.minute2 = customer[p].minute;
			sumTime2 = ToMinute(customer[p]);
			sumTime1 = ToMinute(customer[k]);

			tem.time = sumTime2 - sumTime1;
			tem.charge = 0;
			if ((sumTime2 - tem.minute2) > sumTime1)////////////////////////钱算错了！！！！！！！！！！！
			{
				sumTime2 = sumTime2 - tem.minute2;
				tem.charge += tem.minute2*toll[hour];
				hour--;
				if (hour < 0)
					hour += 24;
				while (sumTime2 - 60 > sumTime1)
				{
					tem.charge += 60 * toll[hour];
					hour--;
					sumTime2 -= 60;
					if (hour < 0)
					{
						hour += 24;
						day--;
					}
				}
			}
			if (sumTime2 > sumTime1)
			{
				tem.charge += (sumTime2 - sumTime1)*toll[hour];
			}
			tem.charge /= 100;
			bill.push_back(tem);
		}
		p++;
		k++;
	}

	//输出结果

	int i = 0;
	for (k = 0; k < nameList.size(); k++)
	{
		double sum = 0;
		if(nameMap[nameList[k]]==2)
			cout<<nameList[k]<<' ' << setfill('0') << setw(2) << bill[i].month << endl;
		while (i < bill.size() && bill[i].name == nameList[k])
		{
			if (bill[i].charge)
			{
		
			cout << setfill('0') << setw(2) << bill[i].day1 << ':' << setfill('0') << setw(2) << bill[i].hour1 << ':' << setfill('0') << setw(2) << bill[i].minute1 << ' ';
			cout << setfill('0') << setw(2) << bill[i].day2 << ':' << setfill('0') << setw(2) << bill[i].hour2 << ':' << setfill('0') << setw(2) << bill[i].minute2 << ' ';
			cout << bill[i].time << " $";
			cout << fixed << setprecision(2) << bill[i].charge << endl;
			sum += bill[i].charge;
			}
			i++;
		}
		if (nameMap[nameList[k]] == 2)
			cout << "Total amount: $" << fixed << setprecision(2) << sum << endl;
		
	}

	return 0;
}


/*

for (int i = 0; i < n; i++)
{
cout << customer[i].name << ' ' << customer[i].day << ' ' << customer[i].hour<<' ';
cout << customer[i].minute  << ' ' << position[customer[i].flag] << endl;
}

*/


