//编辑距离问题是指两个字符串s,t,通过三种操作(删除,插入,替换)将s变为t的最小操作次数
// 
//我么们要严格记住,操作只针对s,不会改变t
// 
//我们再按四部走来分析
//1.问题构建,首先Memo[i,j]记录的是,为了让s(末尾是s[i])到t(末尾是t[ij]),对s[i]进行操作的最小操作次数
//2.递推式构建
//①进行删除操作,那么Memo[i][j]=1+Memo[i-1][j];	先写1+,是为了说明我们脑中是先进行了删除操作
//②进行插入操作,插入是在s[i]后面插入一个新元素s[i+1]=t[j],那么Memo[i][j]=Memo[i][j-1]+1;
//为什么是这种结果呢?因为t[j]已经被s[i+1]解决了
//③进行替换操作,Memo[i][j]=Memo[i-1][j-1]+c;
//如果s[i]=t[j],则c=0,相等了当然不用再替换了,反之c=1;
//但是则还不是最终的递归式,因为这三个操作都可能进行,但是我们要找出最小操作数的情况
//即Memo[i][j]=min(①,②,③);
//3.4步操作就是代码的问题了
//3.有些操作要提,Memo[i][0]=i,即t没有元素时,只进行删除操作,反之Memo[0][j]=j,只进行插入
//Rec[i][0]=1,1代表删除,Rec[0][j]=2,2表示插入
//4.最优方案一定在Memo[i][j],因为两个字符串长度时一定的

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
			if (s1[i-1] != s2[j-1])c = 1;		//********//注意!!!,s1,s2可不是从1索引开始的,所以一开始写的s1[i]s2[j]是大错特错的
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
				Rec[i][j] = c == 0 ? 0 : 3;//0表示啥也没干,这两位是一样的
			}
		}
	}
}
void printopreate(int l1, int l2)
{
	//先设置递归出口
	if (l1 == 0 && l2 == 0)return;	//5.2 这里应该是&&,不应该写成||
	switch (Rec[l1][l2])
	{
	case 0:
		printopreate(l1 - 1, l2 - 1);
		printf("不进行操作\n");
		break;
	case 3:
		printopreate(l1 - 1, l2 - 1);
		printf("进行替换操作\n");
		Count++;
		break;
	case 1:
		printopreate(l1 - 1, l2);
		printf("进行删除操作\n");
		Count++;
		break;
	case 2:
		printopreate(l1, l2 - 1);
		printf("进行插入操作\n");
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
	cout << "最短编辑路径为" << Count;
	return 0;
}
//ABCBDAB
//BDCABA
