//#include<iostream>
//using namespace std;
////快速排序是重分解,轻排序的分而治之的算法
////与归并排序的思想是相反的
//void Quicksort(int* arr, int low, int high)
//{
//	if (low < high)
//	{
//		srand(time(nullptr));
//		int i = low - 1;//4.21 这里起始是low-1,一开始写成了0,之后又写成了low,错两次
//		int j = low; //这里一开始也是写成了0
//		int rm = rand() % (high - low + 1) + low;
//		//这里用随机的rm作为主元,是防止n^2的最差情况
//		swap(arr[rm], arr[high]); 
//		while(high>j)	//4.22 其实这里可以写成for循环,因为j无论哪种情况都要j++
//		{
//			if (arr[high] > arr[j])
//			{
//				swap(arr[i+1], arr[j]);
//				j++;
//				i++;
//			}
//			else {
//				j++;
//			}
//		}
//		swap(arr[i + 1], arr[high]);
//		Quicksort(arr,low,i);//i是左边集合的右边界,故i+2是右边集合的左边界,传参别搞错了
//		Quicksort(arr,i+2,high);
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[1000];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	Quicksort(arr, 0, n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i]<<' ';
//	}
//}
//
////12
////1 2 3 6 5 4 7 8 9 12 11 10