#include <iostream>
using namespace std;
//��ĿҪ�����1��+2��+3��+...+50!
void func1(int* a, int n)//���n!,��ʵ���Ǹ߾��ȳ˷�
{
	a[0] = 1;//��������ʼ��,��Ȼ�ͱ�ɽ׳˵Ľ׳�,�����������
	for (int b = 1; b <= n; b++)
	{
		for (int i = 0; i < 200; i++)
		{
			a[i] = a[i] * b;
		}
		for (int i = 0; i < 199; i++)
		{
			if (a[i] >= 10)
			{
				a[i + 1] += a[i] / 10;
				a[i] = a[i] % 10;
			}
		}
	}
}
void func2(int* a, int* S)//����׳˵ĺ�,��ʵ���Ǹ߾��ȼӷ�
{
	for (int i = 0; i < 200; i++)
	{
		S[i] += a[i];
		a[i] = 0;
	}
	for (int i = 0; i < 199; i++)
	{
		if (S[i] >= 10)
		{
			S[i + 1] += S[i] / 10;
			S[i] = S[i] % 10;
		}
	}
}
void func3(int* S)//��ӡ
{
	int index = 0;
	for (int i = 199; i >= 0; i--)
	{
		if (S[i] != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i >= 0; i--)
		cout << S[i];
}
int main()
{
	int a[200] = { 0 };
	int S[200] = { 0 };
	a[0] = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		func1(a, i);
		func2(a, S);
	}
	func3(S);
}