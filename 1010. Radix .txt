#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//做的我快哭了~~~~~
//如果提前吧字符串转成数字会导致大量错误，原因不明

long long int Cal(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (c - 'a' + 10);
}

long long ToInt(string &b, long long r)
{
	long long t = 1, sum = 0;
	for (auto i : b)
	{
		sum *= r;
		sum += Cal(i);
		if (sum < 0)
			return -1;
	}
	return sum;
}
int main()
{
	string a[2];
	int flag, r;
	cin >> a[0] >> a[1] >> flag >> r;

	if (flag == 2)
		swap(a[0], a[1]);

	long long ten1 = ToInt(a[0], r);

	auto m = max_element(a[1].begin(), a[1].end());
	long long minR;
	minR = Cal(*m)+1;

	long long temp = ToInt(a[1], minR);
	long long p1 = minR, p2 = ten1 + 1;
	while (temp != ten1&&p1 <= p2)
	{
		minR = (p1 + p2) / 2;
		temp = ToInt(a[1], minR);
		if (temp == -1 || temp > ten1)
			p2 = minR - 1;
		else if (temp < ten1)
			p1 = minR + 1;
		else if (temp == ten1)
			break;
	}
	if (temp == ten1)
		cout << minR;
	else
		cout << "Impossible";

	system("pause");
	return 0;
}
