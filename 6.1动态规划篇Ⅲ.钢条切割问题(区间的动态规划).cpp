////����һ�γ���ΪL�ĸ���,�����и�ɲ�ͬ�ĳ��Ȼ��в�ͬ�ļ۸�,��:��ô�и�۸����?
////1.���⹹��.��Memo[L]
////2.�ݹ��ϵ.����Ҫ��Memo[j],�����Ǿ�Ҫ֪�����е�С��i�������з�,iΪ��ȥ�ĳ���
////��Memo[j-i](1<=i<=j-1),Ȼ�����ֵ����price[i],��Memo[j-i]+price[i],��������Щֵ���ҵ����ֵ
////����Memo[j]=max{Memo[j-i]+price[i],price[j]};
////3.�Ե����ϼ���.Memo[0]=0,ʣ�µ������ƾ���
////4.���ŷ���׷��.����Ҫ֪��Memo[j]������������һ��,��i,Ȼ����Memo[j-i]��������һ��,��û�о���Ϊi=j
////��Rec[j]=i,Ȼ����Rec[j-i]
//
//#include<iostream>
//using namespace std;
//int l[1000];
//int price[1000];
//int Memo[1000];
//int Rec[1000];
//void createMemoandRec(int len)
//{
//	for (int j = 1; j <= len; j++)		//5.3 ���������ѭ���㷴��,i���Ǳ��,�����б仯��i�����֮�ҵ����Ž�
//	{
//		//����Ҫ��ʼ��,Ĭ��һ�³�ʼ���ǲ������,Ȼ����ܱȽ����˵����
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
//	cout << "�������Ϊ:" << Memo[len] << endl;	//******//��������,������ȷ����,����������maxmoney,Memo[len]���ǳ���Ϊlen��maxmoney
//	cout << "�����и��Ϊ:" << ' ';		//5.3 ����д�Ĳ�Ӧ�����и,Ӧ�����и��
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