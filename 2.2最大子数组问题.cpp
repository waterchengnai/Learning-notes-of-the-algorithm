//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int acrossmid(int* arr, int low, int high, int mid)
//{
//	int left = arr[mid], leftcurr=arr[mid];
//	int right = arr[mid+1], rightcurr=arr[mid+1];
//	for (int i = mid-1; i >= low; i--)
//	{
//		leftcurr += arr[i];
//		left = left > leftcurr ? left : leftcurr;
//	}
//	for (int i = mid+2; i <= high; i++)
//	{
//		rightcurr += arr[i];
//		right = right > rightcurr ? right : rightcurr;
//	}
//	int Max = left + right;
//	return Max;
//}
//int func(int* arr, int low, int high)
//{
//	if (low == high)
//	{
//		return arr[low];
//	}
//	int mid = (low + high) / 2;
//	int S1 = func(arr, low, mid);
//	int S2 = func(arr, mid+1, high);
//	int S3 = acrossmid(arr, low, high, mid);
//	return max(S1, max(S2, S3));
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
//	cout<<func(arr, 0, n-1);
//}
///*12
//1 - 2 4 5 - 2 8 3 - 2 6 3 7 - 1*/