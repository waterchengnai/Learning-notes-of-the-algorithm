#include<iostream>
using namespace std;
//����ѡ�������ǻ��ڿ�����������ϵ�,ͨ�����ϵط�������С��Χ
//ʱ�临�Ӷ�ΪO(nlogn)
//p��������߽�,r�������ұ߽�,q����Ԫλ��
int Select(int* arr, int p, int r,int k)
{
	if (p == r) // 4.22 ���������ֻ��һ��Ԫ��ʱֱ�ӷ���,һ��ʼ����д�˵�,Ȼ��ɾ��,��AI�Ļ��Ǽ��ϰ�
		return arr[p];
	int i = p - 1;
	int rm = rand() % (r - p + 1) + p;
	swap(arr[r], arr[rm]);
	for (int j = p; j <= r; j++)
	{
		if (arr[j] < arr[r])
		{
			swap(arr[i + 1], arr[j]);
			i++;
		}		
	}
	int q = i + 1;
	swap(arr[q], arr[r]);
	int order = q - p + 1;	//���order��ֵ����Ҫ
	if (k < order)
	{
		Select(arr, p, i, k);
	}
	else if (k > order)
	{
		k = k - order;	//4.25����һ����k-order,��һ��ʼд����k-order+1;
		Select(arr, q + 1, r, k);
	}
	else {
		return arr[q];
	}
}
int main()
{
	srand(time(nullptr));	//��AI˵��,�������÷���mian�����ȽϺ�,��ֹ������ظ�
	int arr[1000];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "��" << k << "С��Ԫ��Ϊ" << Select(arr, 0, n - 1, k);	//4.25�����ǵ�kС��,���ǵ�k���
	return 0;
}
//12 9
//1 3 2 6 5 4 7 8 9 10 11 12