////����������������ΪC�ı���,N����Ʒ,ÿ����Ʒ�ж�Ӧ�������ͼ�ֵ
////��,��ô���ܼ�ֵ���
//
////���ǽ�����һ������¼����Memo,����¼ǰi����Ʒ������Ϊcʱ�����Ž�
////Ȼ��ӵ������Ʋ��Memo[C][N]�����Ž�
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
//	for (int i = 1; i <= N; i++)	//��Ʒ���
//	{
//		for (int j = 1; j <= C; j++)	//�������
//		{
//			Memo[i][j] = Memo[i - 1][j]; // Ĭ�ϲ�ѡ��ǰ��Ʒ
//			if (j >= V[i])
//			{
//				int take = Memo[i - 1][j - V[i]] + worth[i];
//				if (take > Memo[i][j]) { // ���ѡ��ǰ��Ʒ����
//					Memo[i][j] = take;
//					Rec[i][j] = 1;
//				}
//			}
//		}
//	}
//	int i_index = 1;//��¼����ֵʱ�ı��
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
//	cout << "ѡ������Ʒ";
//	for (int i = i_index; i >= 1; i--)
//	{
//		if (Rec[i][j_index] == 1)
//		{
//			cout << i << ' ';
//			j_index -= V[i];	//4.28 ����ʱ���һ������,һ��ʼд��V[j_index]��,����i���Ƕ�Ӧ��Ʒ��ŵ�,ֻ��˵д�����ӷ�����
//		}
//	}
//	cout << '\n';
//	cout << "����ֵΪ" << maxprice;
//}
////13 5
////10 3 4 5 4
////24 2 9 10 9