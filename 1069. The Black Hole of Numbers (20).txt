#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int Reverse(int a)
{
	int t = 0;
	while (a)
	{
		t = t * 10 + (a % 10);
		a /= 10;
	}
	if (!t)
		return 0;

	return t;
}
int Sort(int a)
{

	int temp[4] = {0,0,0,0}, i = 0;
	while (a)
	{
		temp[i] = a % 10;
		a /= 10;
		i++;
	}
	sort(temp, temp + 4);
	return temp[3] * 1000 + temp[2] * 100 + temp[1] * 10 + temp[0];
}
int main() {
	int n,maner=-1,a,b;
	cin >> n;
	while (1)
	{
		n = Sort(n);
		a = n;
		b = Reverse(a);
		n = a - b;

		if (maner == n)
			break;
		else
		{
			cout << setfill('0') << setw(4) << a<<" - ";
			cout << setfill('0') << setw(4) << b << " = ";
			cout << setfill('0') << setw(4) << n<<endl;
			maner = n;
		}
	}
	return 0;
}