////问题描述：有容量为C的背包,N个商品,每个商品有对应的容量和价值
////问,怎么拿总价值最大
//
////我们将建立一个备忘录数组Memo,将记录前i个商品在容量为c时的最优解
////然后从底向上推测出Memo[C][N]的最优解
//#include<iostream>
//using namespace std;
//int Memo[1000][1000];
//int Rec[1000][1000];
//int worth[1000];
//int V[1000];
//int main()
//{
//	int C, N;
//	cin >> C >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> V[i];
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> worth[i];
//	}
//	
//	for (int i = 1; i <= N; i++)	//物品编号
//	{
//		for (int j = 1; j <= C; j++)	//容量编号
//		{
//			Memo[i][j] = Memo[i - 1][j]; // 默认不选当前物品
//			if (j >= V[i])
//			{
//				int take = Memo[i - 1][j - V[i]] + worth[i];
//				if (take > Memo[i][j]) { // 如果选当前物品更优
//					Memo[i][j] = take;
//					Rec[i][j] = 1;
//				}
//			}
//		}
//	}
//	int i_index = 1;//记录最大价值时的编号
//	int j_index = 1;
//	int maxprice = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= C; j++)
//		{
//			if (Memo[i][j] > Memo[i_index][j_index])
//			{
//				i_index = i;
//				j_index = j;
//				maxprice = Memo[i][j];
//			}
//		}
//	}
//	cout << "选择了商品";
//	for (int i = i_index; i >= 1; i--)
//	{
//		if (Rec[i][j_index] == 1)
//		{
//			cout << i << ' ';
//			j_index -= V[i];	//4.28 这里时最后一个错误,一开始写成V[j_index]了,但是i才是对应商品编号的,只能说写到脑子发昏了
//		}
//	}
//	cout << '\n';
//	cout << "最大价值为" << maxprice;
//}
////13 5
////10 3 4 5 4
////24 2 9 10 9