//#include<iostream>;
//using namespace std;
//int arr[1009];
//int Memo[1010];
//int Rec[1010];
////ʹ�ö�̬�滮�㷨������O(n)ʱ�临�ӶȽ��������
////���ǵ�Memo������μ�¼�����Ե�i��Ԫ��Ϊ���׵����Ž�,�Ӷ��õ�����Ԫ�ص����Ž�,��Rec��¼���ǵ�i��Ԫ�����Ž�ʱ�Ķ�β
////��סMemo��Rec����������ʽ����
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