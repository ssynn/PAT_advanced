#include <iostream>  
#include <algorithm>
#include<vector>
using namespace std;
int main(){     
    int n,max=0,count=0;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		if(a[i]<0)
			count++;
	}
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]>0)
			a[i]+=a[i-1];
		if(a[i]>max)
			max=a[i];
	}
	
	if(count<n)
	{
		int j=1,k=0;
		while(max!=a[j])
			j++;
		k=j;
		while(a[k]>=0)
			k--;
		cout<<max<<' '<<b[k+1]<<' '<<b[j];
	}
	else
		cout<<0<<' '<<b[1]<<' '<<b[n];
    return 0;   
} 
