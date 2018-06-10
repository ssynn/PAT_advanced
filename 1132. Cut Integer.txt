#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		int val;
		cin >> val;

		int a = val,cnt=0;
		while (a)
		{
			a /= 10;
			cnt++;
		}
		int s = pow(10, cnt / 2);
		int t1 = val / s,t2=val%s;
		t1 *= t2;
		if (t1&&(val%t1==0))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	system("pause");
	return 0;
}