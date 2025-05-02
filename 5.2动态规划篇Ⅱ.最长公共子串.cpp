////什么是子串？
////子串是一种特殊的子序列，他要求元素在原数组中是连续出现的
////那么解决最大公共子串的问题我们也可以沿用解决最大公共子序列的问题，甚至更加简单
////其中Memo[i][j]=①0;		X[i]!=Y[j]
////②Memo[i-1][j-1];
////其中Memo依然表示以X[i]Y[j]为结尾的最优解
////但是由于子串是连续的,所以我们实际上连Rec数组都不需要了,Memo中已经记录了最优解位置和长度
//
//#include<iostream>
//using namespace std;
//int Memo[1000][1000];
//char X[1000];
//char Y[1000];
//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	for (int i = 1; i <= n1; i++)
//	{
//		cin >> X[i];
//	}
//	for (int j = 1; j <= n2; j++)
//	{
//		cin >> Y[j];
//	}
//	for (int i = 1; i <= n1; i++)
//	{
//		for (int j = 1; j <= n2; j++)
//		{
//			if (X[i] != Y[j])
//			{
//				Memo[i][j] = 0;
//			}
//			else
//			{
//				Memo[i][j] = Memo[i - 1][j - 1] + 1;
//			}
//		}
//	}
//	int Max_i = 1;
//	int Max_j = 1;
//	for (int i = 1; i <= n1; i++)
//	{
//		for (int j = 1; j <= n2; j++)
//		{
//			if (Memo[i][j] > Memo[Max_i][Max_j])
//			{
//				Max_i = i;
//				Max_j = j;
//			}
//		}
//	}
//	while (Memo[Max_i][Max_j]!=0)
//	{
//		cout << X[Max_i--] << ' ';
//		Max_j--;
//	}
//}
////7 6
////A B C A D B B
////B C E D B B