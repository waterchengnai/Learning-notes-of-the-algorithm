//ʲô��������?
//һ��������ɾȥ0����0������Ԫ�صõ���������
//eg:X:1 2 9 40 6 1��ɾȥ1 9 1
//�õ�2 40
//��Ȼ,Ԫ�ػ���������ĸ
//��ô��󹫹������о����������е� ���������ظ�Ԫ������ ��ͬ������
//������ΪMemo[i][j]=��max{Memo[i-1][j],Memo[i][j-1]}	;	(X[i]!=Y[j])
//��Memo[i-1][j-1]+1	;	(X[i]=Y[j])
#include<iostream>
using namespace std;
char X[1000];
char Y[1000];
int Memo[1000][1000];
int Rec[1000][1000];
int main()
{
	int N1, N2;
	cin >> N1 >> N2;
	for (int i = 1; i <= N1; i++)
	{
		cin >> X[i];
	}
	for (int i = 1; i <= N2; i++)
	{
		cin >> Y[i];
	}
	for (int i = 1; i <= N1; i++)
	{
		for (int j = 1; j <= N2; j++)
		{
			if (X[i] != Y[j])
			{
				Memo[i][j] = max(Memo[i][j - 1], Memo[i - 1][j]);
				Rec[i][j] = Memo[i][j - 1] > Memo[i - 1][j] ? 0 : 1;	//1��ʾ��ǰ�����������Ϸ�,0��ʾ������
			}
			else
			{
				Memo[i][j] = Memo[i - 1][j - 1] + 1;
				Rec[i][j] = 2;	//����ʾ���������� ��ǰԪ�� ����������� 
			}
		}

	}
	int Max_i(1), Max_j(1);
	for (int i = 1; i <= N1; i++)
	{
		for (int j = 1; j <= N2; j++)
		{
			if (Memo[i][j] > Memo[Max_i][Max_j])
			{
				Max_i = i;
				Max_j = j;
			}
		}
	}
	while (Max_i >= 1 && Max_j >= 1)
	{
		if (Rec[Max_i][Max_j] == 0)
		{
			Max_j--;
		}
		else if (Rec[Max_i][Max_j] == 1)
		{
			Max_i--;
		}
		else if (Rec[Max_i][Max_j] == 2)
		{
			cout << X[Max_i] << ' ';
			Max_i--;
			Max_j--;
		}
	}

}
//7
//6
//A B C B D A B
//B D C A B A 