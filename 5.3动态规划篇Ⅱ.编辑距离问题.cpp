//�༭����������ָ�����ַ���s,t,ͨ�����ֲ���(ɾ��,����,�滻)��s��Ϊt����С��������
// 
//��ô��Ҫ�ϸ��ס,����ֻ���s,����ı�t
// 
//�����ٰ��Ĳ���������
//1.���⹹��,����Memo[i,j]��¼����,Ϊ����s(ĩβ��s[i])��t(ĩβ��t[ij]),��s[i]���в�������С��������
//2.����ʽ����
//�ٽ���ɾ������,��ôMemo[i][j]=1+Memo[i-1][j];	��д1+,��Ϊ��˵�������������Ƚ�����ɾ������
//�ڽ��в������,��������s[i]�������һ����Ԫ��s[i+1]=t[j],��ôMemo[i][j]=Memo[i][j-1]+1;
//Ϊʲô�����ֽ����?��Ϊt[j]�Ѿ���s[i+1]�����
//�۽����滻����,Memo[i][j]=Memo[i-1][j-1]+c;
//���s[i]=t[j],��c=0,����˵�Ȼ�������滻��,��֮c=1;
//�����򻹲������յĵݹ�ʽ,��Ϊ���������������ܽ���,��������Ҫ�ҳ���С�����������
//��Memo[i][j]=min(��,��,��);
//3.4���������Ǵ����������
//3.��Щ����Ҫ��,Memo[i][0]=i,��tû��Ԫ��ʱ,ֻ����ɾ������,��֮Memo[0][j]=j,ֻ���в���
//Rec[i][0]=1,1����ɾ��,Rec[0][j]=2,2��ʾ����
//4.���ŷ���һ����Memo[i][j],��Ϊ�����ַ�������ʱһ����

#include<iostream>
using namespace std;
int Memo[1000][1000];
int Rec[1000][1000];
string s1, s2;
int Count = 0;
void intil_MemoandRec(int l1,int l2)
{
	for (int i = 0; i <= l1; i++)
	{
		Memo[i][0] = i;
		Rec[i][0] = 1;
	}
	for (int j = 0; j <= l2; j++)
	{
		Memo[0][j] = j;
		Rec[0][j] = 2;
	}
}
void create_MemoandRec(int l1, int l2)
{
	for (int i = 1; i <= l1; i++)
	{
		for (int j = 1; j <= l2; j++)
		{
			int c = 0;
			if (s1[i-1] != s2[j-1])c = 1;		//********//ע��!!!,s1,s2�ɲ��Ǵ�1������ʼ��,����һ��ʼд��s1[i]s2[j]�Ǵ���ش��
			int Delete = Memo[i - 1][j] + 1;
			int insert = Memo[i][j - 1] + 1;
			int replace = Memo[i - 1][j - 1] + c;
			Memo[i][j] = min({Delete,insert,replace});
			if (Memo[i][j] == Delete)
			{
				Rec[i][j] = 1;
			}
			else if (Memo[i][j] == insert)
			{
				Rec[i][j] = 2;
			}
			else {
				Rec[i][j] = c == 0 ? 0 : 3;//0��ʾɶҲû��,����λ��һ����
			}
		}
	}
}
void printopreate(int l1, int l2)
{
	//�����õݹ����
	if (l1 == 0 && l2 == 0)return;	//5.2 ����Ӧ����&&,��Ӧ��д��||
	switch (Rec[l1][l2])
	{
	case 0:
		printopreate(l1 - 1, l2 - 1);
		printf("�����в���\n");
		break;
	case 3:
		printopreate(l1 - 1, l2 - 1);
		printf("�����滻����\n");
		Count++;
		break;
	case 1:
		printopreate(l1 - 1, l2);
		printf("����ɾ������\n");
		Count++;
		break;
	case 2:
		printopreate(l1, l2 - 1);
		printf("���в������\n");
		Count++;
		break;
	default:
		break;
	}
	
}
int main()
{
	cin >> s1 >> s2;
	int l1 = s1.size();
	int l2 = s2.size();
	intil_MemoandRec(l1,l2);
	create_MemoandRec(l1, l2);
	printopreate(l1, l2);
	cout << "��̱༭·��Ϊ" << Count;
	return 0;
}
//ABCBDAB
//BDCABA
