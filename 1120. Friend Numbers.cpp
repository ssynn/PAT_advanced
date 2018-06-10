#include<iostream>
#include<string>
using namespace std;

int Sum(int n)
{
	int s = 0;
	while (n)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main()
{
	int n,temp,cnt=0;
	bool map[40] = { 0 };
	cin >> n;
	while (n--)
	{
		cin >> temp;
		map[Sum(temp)] = 1;
	}
	for (int i = 0; i < 40; i++)
	{
		if (map[i])
			cnt++;
	}
	cout << cnt << endl;
	for (int i = 0; i < 40; i++)
	{
		if (map[i])
		{
			cout << i;
			cnt--;
			if (cnt)
				cout << ' ';
		}
	}
	system("pause");
	return 0;
}