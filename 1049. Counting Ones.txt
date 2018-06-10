#include<iostream>  
#include<cstdio>  
#include<fstream>  
using namespace std;
/*

如果当前位==0，则该为出现1 的情况由更高位决定，= 更高为数字*当前位数
如果当前位==1，则该为出现1 的情况受更高位以及低位影响，= （更高为数字*当前位数）+（低位数字+1）
如果当前位>1，则该为出现1 的情况由更高位决定，= (更高为数字+1)*当前位数
(参考别人的啦——嘿嘿嘿)
*/
int main() {
	int n,cnt=0;
	cin >> n;
	int high = n/10, low = 0, mid = n%10,temp=1;		//temp为当前位数
	while (temp <= n)
	{

		switch (mid)
		{
		case 0:
			cnt += high*temp;
			break;
		case 1:
			cnt += (high*temp) + low + 1;
			break;
		default:
			cnt += (high + 1)*temp;
			break;
		}
		low += mid*temp;
		temp *= 10;
		mid = high % 10;
		high /= 10;
	}
	cout << cnt;

	system("pause");
	return 0;
}