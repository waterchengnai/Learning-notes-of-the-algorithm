//���ֱ���������෴�������֮ǰѧ����01��������
//01����ľ���ĳ����Ʒ,Ҫôȫȡ,Ҫô��ȡ
//���ǲ��ֱ����Ϳ�����Ʒֻȡһ����
//��ʱ�����ǾͿ��Խ���̰�Ĳ���,ÿһ�����߾ֲ����Ž�

//��������Ҫ����һ�����Ϊ V mL��β��,����n������,�ֱ��� vi mL,��Ӧ�ܼ۸�Ϊpi,���������伦β�Ƶļ۸����
//��ʱ�����ǾͿ���ʹ���Լ۱ȵ�˼��,��װ�Լ۱ȴ��,��װ�Լ۱�С��,ֱ��װ��
//����������ѵ�ֻ�����Լ۱ȵ�����,ʱ�临�Ӷ�ΪO(nlogn)
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
	cout << "�����뼦β�Ƶ����:";
	cin >> V;
	cout << "���������ϵ�������:";
	int kinds;
	cin >> kinds;
	cout << "������������ϵļ۸�����"<<endl;
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
	//********************//ԭ��ֻ���������Լ۱ȴ�С���򼴿�,�����Լ۱Ⱦ�û��Ҫ������
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
	cout << "��߼�Ϊ:" << maxmoney;
	return 0;
}
//60 10 36 16 45
//600 250 200 100 300