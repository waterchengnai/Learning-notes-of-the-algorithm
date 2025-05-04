//部分背包问题的相反情况就是之前学过的01背包问题
//01代表的就是某件物品,要么全取,要么不取
//但是部分背包就可以物品只取一部分
//这时候我们就可以进行贪心策略,每一步都走局部最优解

//比如现在要调配一杯体积为 V mL鸡尾酒,现有n种饮料,分别有 vi mL,对应总价格为pi,求怎样调配鸡尾酒的价格最大
//这时候我们就可以使用性价比的思想,先装性价比大的,再装性价比小的,直至装满
//所以问题的难点只在于性价比的排序,时间复杂度为O(nlogn)
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int v[1000];
int p[1000];
int index[1000];
double p_cost[1000];
int main()
{
	int V;
	cout << "请输入鸡尾酒的体积:";
	cin >> V;
	cout << "请输入饮料的种类数:";
	int kinds;
	cin >> kinds;
	cout << "请输入各种饮料的价格和体积"<<endl;
	for (int i = 1; i <= kinds; i++)
	{
		cin >> p[i];
		index[i] = i;
	}
	for (int i = 1; i <= kinds; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= kinds; i++)
	{
		p_cost[i] = p[i] * 1.0 / v[i];
	}
	//sort(p_cost + 1, p_cost + kinds+1,greater<double>());		
	//********************//原来只对索引按性价比大小排序即可,这样性价比就没必要排序了
	sort(index + 1, index + kinds+1, [](int a, int b)
		{
			return p_cost[a] > p_cost[b];
		});
	int i = 1;
	double maxmoney = 0.0;
	while (V != 0)
	{
		if (v[index[i]] <= V)
		{
			V -= v[index[i]];
			maxmoney += p[index[i]];
		}
		else
		{
			maxmoney += p_cost[index[i]]*V;
			V = 0;
		}
		i++;
	}
	cout << "最高价为:" << maxmoney;
	return 0;
}
//60 10 36 16 45
//600 250 200 100 300