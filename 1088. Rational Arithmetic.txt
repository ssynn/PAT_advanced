#include<iostream>
using namespace std;
int fun(long long  a, long long  b);
int main()
{
	
	long long a, b, c, d, ans1, ans2, k = 1;
	char m, sign[4] = { '+','-','*','/' };
	cin >> a >> m >> b >> c >> m >> d;
	for (int i = 0; i < 4; i++)
	{
		fun(a, b);
		cout << ' ' << sign[i] << ' ';
		fun(c, d);
		cout << ' ' << '=' << " ";
		switch (i)
		{
		case 0:

			ans1 = a*d + b*c;
			ans2 = b*d;
			break;
		case 1:
			ans1 = a*d - b*c;
			ans2 = b*d;
			break;
		case 2:
			ans1 = a*c;
			ans2 = b*d;
			break;
		case 3:
			ans1 = a*d;
			ans2 = b*c;

		}
		fun(ans1, ans2);
		cout << endl;
	}
	
	system("pause");
	return 0;
}
int fun(long long  a,long long  b)//规范化数据并输出
{

	long long  k = 1;
	if ((a < 0 && b > 0)||(a>0&&b<0))//当数据太大时不可以用a*b<0不然会溢出
		k = -1;
	a = abs(a);
	b = abs(b);
	long long  top = 0, c = 1, t1 = a, t2 = b;
	//a,b均不为0
	if ((a!=0)&&(b!=0))
	{
		//找最大公因数
		if (t1 < t2)
		{
			c = t1;
			t1 = t2;
			t2 = c;
		}
		while (c)
		{
			c = t1%t2;
			t1 = t2;
			t2 = c;
		}
		a = a / t1;
		b = b / t1;


		//数据处理
		top = a / b;
		a = a%b;
	}

	//数据输出
	//
	if (b != 0)
	{
		if (k >= 0)
		{

			if (top)
				cout << top;
			if (top*a)
				cout << ' ';
			if (a)
				cout << a << "/" << b;
			if (a == 0 && top == 0)
				cout << 0;
		}
		else
		{
			cout << "(" << '-';
			if (top)
				cout << top;
			if (top*a)
				cout << ' ';
			if (a)
				cout << a << "/" << b;
			cout << ")";
		}

	}
	else
		cout << "Inf";
		
	return 0;
}