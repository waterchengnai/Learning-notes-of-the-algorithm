//#include<iostream>;
//using namespace std;
//int arr[1009];
//int Memo[1010];
//int Rec[1010];
////使用动态规划算法可以用O(n)时间复杂度解决该问题
////我们的Memo数组这次记录的是以第i个元素为队首的最优解,从而得到所有元素的最优解,而Rec记录的是第i个元素最优解时的队尾
////记住Memo和Rec的两个递推式即可
////Memo[i]=Memo[i+1]+arr[i]||arr[i]
////Rec[i]=Rec[i+1]
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = n; i >= 1; i--)
//	{
//		if (Memo[i+1] <= 0)
//		{
//			Memo[i] = arr[i];
//			Rec[i] = i;
//		}
//		else {
//			Memo[i] = arr[i] + Memo[i + 1];
//			Rec[i] = Rec[i + 1];
//		}
//	}
//	int Maxplace = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (Memo[i] >= Memo[Maxplace])
//		{
//			Maxplace = i;
//		}
//	}
//	for (int i=Maxplace; i <= Rec[Maxplace]; i++)
//	{
//		cout << arr[i]<<' ';
//	}
//}