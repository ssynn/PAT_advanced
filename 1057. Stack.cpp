#include<iostream>
#include<set>
#include<stack>
#include<stdio.h>
using namespace std;

class Stack
{
public:
	Stack() :f(), b(), data() {};
	void pop()
	{
		if (data.size() == 0)
		{
			printf("Invalid\n");
			return;
		}

		int p = data.top();
		cout << p << endl;;
		data.pop();

		if (p <= mid)
		{
			auto it = f.find(p);
			f.erase(it);
		}
		else										//这里一次吧相同的元素全删了
		{
			auto it = b.find(p);
			b.erase(it);
		}
		balance();
	}

	void push(int a)
	{
		data.push(a);
		if (a <= mid||data.size()==1)
			f.insert(a);
		else
			b.insert(a);
		balance();
	}

	void balance()
	{
		while (f.size()<b.size())
		{
			f.insert(*b.begin());
			b.erase(b.begin());
		}

		while ((f.size() - b.size())>1)
		{
			auto it = f.end();
			it--;
			b.insert(*it);
			f.erase(it);
		}
		if(data.size())
			mid = *f.rbegin();
	}

	void peakM()
	{
		if (data.size() == 0)
		{
			printf("Invalid\n");
			return;
		}
		printf("%d\n", mid);
	}

	multiset<int>f, b;
	stack<int>data;
	//int size;// fsize, bsize;
	int mid;

};

int main() 
{
	Stack val;
	int n;
	cin >> n;
	while (n--)
	{
		char s[15];
		scanf("%s", s);

		switch (s[1])
		{
		case 'o':
			val.pop();
			break;
		case 'e':
			val.peakM();
			break;
		case 'u':
			int a;
			scanf("%d", &a);
			val.push(a);
			break;
		}
	}

	system("pause");
	return 0;
}