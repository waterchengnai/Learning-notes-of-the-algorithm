////最优解本质上是归并排序的同时加上一个判断即可
//#include<iostream>
//using namespace std;
//int arcossmidcount(int* arr,int low,int high,int mid)
//{
//	int count = 0;
//	int temp = mid++;
//	int lowintil = low; //4.21 这里你没记录一开始的mid,导致后面重新赋值arr时出错了
//	int* newarr = new int[high - low + 1]; //直接用堆区开空间
//	int i = 0;
//	while(low<=temp&&mid<=high)
//	{
//		if (arr[mid] < arr[low])
//		{
//			count += temp - low + 1;
//			newarr[i] = arr[mid];
//			mid++;
//		}
//		else 
//		{
//			newarr[i] = arr[low];
//			low++;
//		}
//		i++;
//	}
//	while (low <= temp)
//	{
//		newarr[i] = arr[low];
//		low++;
//		i++;
//	}
//	while (mid <= high)
//	{
//		newarr[i] = arr[mid];
//		mid++;
//		i++;
//	}
//	i = 0;
//	for (int j = lowintil; j <= high; j++)
//	{
//		arr[j] = newarr[i];
//		i++;
//	}
//	delete []newarr;
//	return count;
//}
//int mergecount(int* arr, int low, int high)
//{
//	if (low >= high)return 0;
//	int mid = (low + high) / 2;
//	int s1 = mergecount(arr, low, mid);
//	int s2 = mergecount(arr, mid + 1, high);
//	int s3 = arcossmidcount(arr, low, high, mid);
//	return s1 + s2 + s3;
//}
//int main()
//{
//	int arr[1000];
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	cout<<mergecount(arr, 0, n-1);//4.21 这里是n-1,不是n
//}
////12
////13 8 10 6 15 18 12 20 9 14 17 19