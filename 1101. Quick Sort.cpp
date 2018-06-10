#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
  int n,cnt=0,max=-1,min=INT_MAX;
  cin >> n;
  vector<int>val(n), lMaxVal(n),rMaxVal(n),ans;
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
    if (val[i] > max)
      max = val[i];
    lMaxVal[i] = max;
  }
  
  for (int i = n - 1; i >= 0; i--)
  {
    if (val[i] < min)
      min = val[i];
    rMaxVal[i] = min;
  }

  

  for (int i = 0; i < n; i++)
    if (val[i] >= lMaxVal[i] && val[i] <= rMaxVal[i])
      ans.push_back(val[i]);
  cnt = ans.size();
  cout << cnt<<endl;
  if(cnt)
    cout << ans[0];
  for (int i = 1; i < cnt; i++)cout << ' ' << ans[i];
  cout << endl;
  system("pause");
  return 0;
}