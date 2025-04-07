#include<iostream>
#include<string>

using namespace std;

//高精度乘单精度

//int main()
//{
//	string s;
//	cin >> s;
//	int a[1000] = {0};
//	int b;
//	cin >> b;
//	for (int i = 0; i < s.size(); i++)
//	{
//		a[i] = s[s.size() - i - 1]-'0';
//	}
//	for (int i = 0; i < s.size(); i++)
//	{
//		a[i] = a[i] * b;
//	}
//	for (int i = 0; i < s.size() + 4; i++)
//	{
//		if (a[i] >= 10)
//		{
//			a[i + 1] += a[i] / 10;
//			a[i] = a[i] % 10;
//		}
//	}
//	int index = 0;
//	for (int i = s.size() + 4 - 1; i >= 0; i--)
//	{
//		if (a[i] != 0)
//		{
//			index = i;
//			break;
//		}
//	}
//	for (int i = index; i >= 0; i--)
//	{
//		cout << a[i];
//	}
//
//}

//高精度乘双精度
+
int main()
{
	string s1,s2;
	int b[1005]={0};
	int a[1005]={0};
	int c[2010]={0};
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		a[i] = s1[s1.size() - i - 1]-'0';
	}
	for (int i = 0; i < s2.size(); i++)
	{
		b[i] = s2[s2.size() - i - 1]-'0';
	}
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			c[i + j] += a[i] * b[j];
			if (c[i + j] >= 10)
			{
				c[i + j + 1] += c[i + j] / 10;
				c[i + j] = c[i + j] % 10;
			}
		}
	}
	int index = 0;
	for (int i = s1.size() + s2.size()-1; i >= 0; i--)
	{
		if (i != 0)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i >= 0; i--)
	{
		cout << c[i];
	}
}