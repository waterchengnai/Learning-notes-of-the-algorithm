//#include<iostream>
//using namespace std;
////�����������طֽ�,������ķֶ���֮���㷨
////��鲢�����˼�����෴��
//void Quicksort(int* arr, int low, int high)
//{
//	if (low < high)
//	{
//		srand(time(nullptr));
//		int i = low - 1;//4.21 ������ʼ��low-1,һ��ʼд����0,֮����д����low,������
//		int j = low; //����һ��ʼҲ��д����0
//		int rm = rand() % (high - low + 1) + low;
//		//�����������rm��Ϊ��Ԫ,�Ƿ�ֹn^2��������
//		swap(arr[rm], arr[high]); 
//		while(high>j)	//4.22 ��ʵ�������д��forѭ��,��Ϊj�������������Ҫj++
//		{
//			if (arr[high] > arr[j])
//			{
//				swap(arr[i+1], arr[j]);
//				j++;
//				i++;
//			}
//			else {
//				j++;
//			}
//		}
//		swap(arr[i + 1], arr[high]);
//		Quicksort(arr,low,i);//i����߼��ϵ��ұ߽�,��i+2���ұ߼��ϵ���߽�,���α�����
//		Quicksort(arr,i+2,high);
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[1000];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	Quicksort(arr, 0, n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i]<<' ';
//	}
//}
//
////12
////1 2 3 6 5 4 7 8 9 12 11 10