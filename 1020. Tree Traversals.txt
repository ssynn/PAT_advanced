
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;
struct TreeNode
{
	int num;
	TreeNode *leftChild, *rightChild;
};
TreeNode* CreatTree(int *t1, int *t2, int n1)
{
	
	int root = t1[n1 - 1], inorderCenter = 0, *k1, *k2, k2n;
	if (n1 - 1 < 0)
		return NULL;
	while (t2[inorderCenter] != root)
	{
		inorderCenter++;
	}

	TreeNode *a;
	a = new TreeNode;
	a->num = root;

	k1 = new int[inorderCenter];
	k2n = n1 - inorderCenter - 1;
	k2 = new int[inorderCenter];
	for (int i = 0; i < inorderCenter; i++)
	{
		k2[i] = t2[i];
		k1[i] = t1[i];
	}
	if (inorderCenter)
		a->leftChild = CreatTree(k1, k2, inorderCenter);
	else
		a->leftChild = NULL;
	delete[]k1;
	delete[]k2;
	k1 = k2 = NULL;
	//cout << n1<<"\n*********\n";
	
		
	k1 = new int[k2n];
	k2 = new int[k2n];
	for (int i = 0; i < k2n; i++)
	{
		k2[i] = t2[inorderCenter+i+1];
		k1[i] = t1[inorderCenter+i];
	}
	if (k2n)
		a->rightChild = CreatTree(k1, k2, k2n);
	else
		a->rightChild = NULL;

	delete[]k1;
	delete[]k2;

	return a;
}
int main()
{
	int n,*t1,*t2;
	cin >> n;
	t1 = new int[n];
	t2 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> t1[i];
	for (int i = 0; i < n; i++)
		cin >> t2[i];

	TreeNode *head = CreatTree(t1,t2,n);

	queue<TreeNode*>ans;
	ans.push(head);
	cout << ans.front()->num;
	if (ans.front()->leftChild)
		ans.push(ans.front()->leftChild);
	if (ans.front()->rightChild)
		ans.push(ans.front()->rightChild);
	ans.pop();
	while (ans.size())
	{
		cout <<' '<< ans.front()->num ;
		if(ans.front()->leftChild)
			ans.push(ans.front()->leftChild);
		if(ans.front()->rightChild)
			ans.push(ans.front()->rightChild);
		ans.pop();
	}
	system("pause");
	return 0;
}