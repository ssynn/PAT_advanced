#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[128] = { 0 },n1len,n2len,sum=0,flag=1;
	string n1, n2;
	cin >> n1 >> n2;
	n1len = n1.length();
	n2len = n2.length();
	for (int i = 0; i < n1len; i++)
	{
		a[n1[i]]++;
	}
	for (int i = 0; i < n2len; i++)
	{
		a[n2[i]]--;
		if (a[n2[i]] < 0)
		{
			flag = 0;
			sum++;
		}
	}
	if (flag)
	{
		for (int i = 0; i < 128; i++)
			sum = sum + a[i];
		cout << "Yes" << " " << sum;
	}
	else
		cout << "No" << " " << sum;
	system("pause");
    return 0;
}
