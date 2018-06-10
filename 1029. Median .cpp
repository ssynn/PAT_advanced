#includestdio.h
#includeiostream
#includealgorithm
#includevector
#includestring
#includeiomanip
#includequeue
#includemap
#includelist
using namespace std;


int main()
{
	int n, k;
	long long temp;
	cin  n;
	vectorlong longans(n);

	for (int i = 0; i  n; i++)
		cin  ans[i];
	cin  k;
	for (int i = 0; i  k; i++)
	{
		cin  temp;
		ans.push_back(temp);
	}
	sort(ans.begin(), ans.end());
	n += k;
	if (n & 1)
		n = 2;
	else
		n = (n2-1);
	cout  ans[n];
	system(pause);
	return 0;
}