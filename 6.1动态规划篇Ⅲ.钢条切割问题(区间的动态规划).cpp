////现有一段长度为L的钢条,把它切割成不同的长度会有不同的价格,问:怎么切割价格最大?
////1.问题构建.求Memo[L]
////2.递归关系.假如要求Memo[j],那我们就要知道所有的小于i的最优切法,i为切去的长度
////即Memo[j-i](1<=i<=j-1),然后这个值加上price[i],即Memo[j-i]+price[i],在所有这些值中找到最大值
////所以Memo[j]=max{Memo[j-i]+price[i],price[j]};
////3.自底向上计算.Memo[0]=0,剩下的往上推就行
////4.最优方案追踪.我们要知道Memo[j]是在哪里切了一刀,即i,然后还有Memo[j-i]在哪切了一刀,若没切就认为i=j
////即Rec[j]=i,然后找Rec[j-i]
//
//#include<iostream>
//using namespace std;
//int l[1000];
//int price[1000];
//int Memo[1000];
//int Rec[1000];
//void createMemoandRec(int len)
//{
//	for (int j = 1; j <= len; j++)		//5.3 这里内外层循环搞反了,i才是变的,在所有变化的i的情况之找到最优解
//	{
//		//这里要初始化,默认一下初始就是不切情况,然后才能比较切了的情况
//		Rec[j] = j;
//		Memo[j] = price[j];
//		for (int i = 1; i <= j-1; i++)
//		{
//			if (Memo[j] < Memo[j - i] + price[i])
//			{
//				Memo[j] = Memo[j - i] + price[i];
//				Rec[j] = i;
//			}
//		}
//	}
//	
//}
//int main()
//{
//	int len;
//	cin >> len;
//	for (int i = 1; i <= len; i++)
//		cin >> l[i];
//	for (int i = 1; i <= len; i++)
//		cin >> price[i];
//	createMemoandRec(len);
//	cout << "最大收益为:" << Memo[len] << endl;	//******//犯若智了,长度是确定的,根本不用找maxmoney,Memo[len]就是长度为len的maxmoney
//	cout << "钢条切割方案为:" << ' ';		//5.3 这里写的不应该是切割处,应该是切割方案
//	int remain = len;
//	while (remain > 0) {
//		cout << Rec[remain] << ' ';
//		remain -= Rec[remain];
//	}
//	return 0;
//}
////
////10
////1 2 3 4 5 6 7 8 9 10
////1 5 8 9 10 17 17 20 24 24