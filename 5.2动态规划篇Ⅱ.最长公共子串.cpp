////ʲô���Ӵ���
////�Ӵ���һ������������У���Ҫ��Ԫ����ԭ���������������ֵ�
////��ô�����󹫹��Ӵ�����������Ҳ�������ý����󹫹������е����⣬�������Ӽ�
////����Memo[i][j]=��0;		X[i]!=Y[j]
////��Memo[i-1][j-1];
////����Memo��Ȼ��ʾ��X[i]Y[j]Ϊ��β�����Ž�
////���������Ӵ���������,��������ʵ������Rec���鶼����Ҫ��,Memo���Ѿ���¼�����Ž�λ�úͳ���
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