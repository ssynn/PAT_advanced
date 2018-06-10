#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	char a[82], b[82], wrong[40];
	cin >> a >> b;
	int alen, blen, wolen = 0, error = 0, already = 0;
	alen = strlen(a);
	blen = strlen(b);
	for (int i = 0; i < alen; i++)
	{
		already = 0;
		error = 0;
		if (a[i] >= 'a'&&a[i] <= 'z')
			a[i] = a[i] + 'A' - 'a';
		for (int j = 0; j < wolen; j++)//查找已有的错误
		{
			if (a[i] == wrong[j])
			{
				already++;
				break;
			}
		}
		if (already > 0)
			continue;
		for (int j = 0; j < blen; j++)//扫描b数组是否有错键
		{
			if (b[j] >= 'a'&&b[j] <= 'z')
				b[j] = b[j] + 'A' - 'a';
			if (a[i] == b[j])
			{
				error++;
				break;
			}
		}
		if (error == 0)//添加错键
		{
			wrong[wolen] = a[i];
			wolen++;
		}
	}
	for (int i = 0; i < wolen; i++)
	{
		cout << wrong[i];
	}
	system("pause");
	return 0;
}

