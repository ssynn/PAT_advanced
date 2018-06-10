#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
bool Change(string &a,double &s)
{
	int len = a.size(), dot = 0, dec = 0,i=0;
	if (a[0] == '-') i++;
	for (; i < len; i++)
	{
		if (a[i] == '.')
		{
			dot++;
			if (dot > 1) return 0;
			continue;
		}
		if (a[i]<'0' || a[i]>'9') return 0;
		if (dot) dec++;
		if (dec > 2) return 0;
	}
	s = stod(a);
	if(s>=-1000&&s<=1000)
		return 1;
	return 0;
}
int main()
{
	int n,right=0,error=0;
	double t,sum=0;
	string num,temp;
	vector<string>errorNum;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (Change(num, t))
		{
			sum += t;
			right++;
		}
		else errorNum.push_back(num);
	}
	for (auto &i : errorNum)
		cout << "ERROR: " << i << " is not a legal number\n";

	cout << "The average of " << right ;
	if (right > 1)
	{
		sum /= right*1.0;
		cout <<" numbers is "<< fixed << setprecision(2) << sum;
	}
	else if (right == 1)													//ÕæÊµÓÐ¶¾
		cout << " number is " << fixed << setprecision(2) << sum;
	else cout << " numbers is Undefined\n";
	
	system("pause");
	return 0;
}