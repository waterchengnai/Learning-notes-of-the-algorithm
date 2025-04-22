#include<iostream>
using namespace std;
//次序选择问题是基于快速排序基础上的,通过不断地分治来缩小范围
//时间复杂度为O(nlogn)
//p是数组左边界,r是数组右边界,q是主元位置
int Select(int* arr, int p, int r,int k)
{
	if (p == r) // 4.22 基本情况：只有一个元素时直接返回,一开始你是写了的,然后删了,听AI的还是加上吧
		return arr[p];
	int i = p - 1;
	int rm = rand() % (r - p + 1) + p;
	swap(arr[r], arr[rm]);
	for (int j = p; j <= r; j++)
	{
		if (arr[j] < arr[r])
		{
			swap(arr[i + 1], arr[j]);
			i++;
		}		
	}
	int q = i + 1;
	swap(arr[q], arr[r]);
	int order = q - p + 1;	//这个order的值很重要
	if (k < order)
	{
		Select(arr, p, i, k);
	}
	else if (k > order)
	{
		k = k - order;	//4.25这里一定是k-order,你一开始写成了k-order+1;
		Select(arr, q + 1, r, k);
	}
	else {
		return arr[q];
	}
}
int main()
{
	srand(time(nullptr));	//听AI说的,种子设置放在mian函数比较好,防止随机数重复
	int arr[1000];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "第" << k << "小的元素为" << Select(arr, 0, n - 1, k);	//4.25这里是第k小的,不是第k大的
	return 0;
}
//12 9
//1 3 2 6 5 4 7 8 9 10 11 12