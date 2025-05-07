// ��Ȼ��������֮ǰ���ֲ����������ǵ��¼���������,�������������Ǹ���ʵ�ʵ����
// ��ÿ������ж�Ӧ����(��ȻҲ�����Ǳ�Ĵ�Ȩ���,Ҫ���Ҳ������Ȩֵ��С��),��ô��ʱ��ʹ��֮ǰ��̰���㷨���ԾͲ���ȷ��,���Ƕ������ɾٳ�����
// ������˼��һ��,֮ǰ�ķֶ���֮�Ͷ�̬�滮�ĸ���������?
// Ӧ���Ƕ�̬�滮
// �����Ƿ���һ�¶�Ӧ�Ķ�̬�滮�Ĳ���
// 1.���⹹��.�ҵ���������Ž�
// �����¼�û��˳��,��ô�������Ĳ����������,����Ҫ������
// ������Ȼ��֮ǰ���������˳���Ÿ���,Ȼ����Եõ�Memo[i],��ǰi���¼������Ž�
// ����Ҫ�õ�Memo[n]
// 2.���ƹ�ϵ����.
// Memo[i]��Memo[i-1]֮����Ȼ���й�ϵ��,�ؼ�����i��ѡ��
// �����iѡ����,��ôǰ��i-1������¼���ͻ�Ļ��Ҫ������
// ���ǿ�����p[i]��¼���һ������ʱ�����¼�i��ʼʱ��ǰ����¼�
// ����Memo[i]=Memo[p[i]]+q[i];
// �����iûѡ,��Memo[i]=Memo[i-1]
// ��Ȼ,��������ѡ�ĸ�Ҫ���ĸ����
// ��Memo[i]=max{Memo[p[i]]+q[i],Memo[i-1]}
// 3.�Ե����ϼ���
// ����˼���ɵ�,Memo[0]=0;
// Memo[1]=q[1];���ԵͶ����ȷ����,����Ϳ���������
// 4.���ŷ���׷��
// Rec[i]=��1;��0.
// 1����i��һ��ѡ��,��ô��������Memo���߼���������Ҫ��q[i]��
// 0�������ûѡ,��ôͬ�����߼��ò�i-1��
#include <iostream>
#include <algorithm>
using namespace std;
int Memo[1000];
int Rec[1000];
int start[1000];
int final[1000];
int index[1000];
int q[1000];
int p[1000]; // ��¼�������һ������ʱ�����¼�i��ʼʱ��ǰ����¼�j
int main()
{
    int n;
    cout << "����������:" << endl;
    cin >> n;
    cout << "�����������Ŀ�ʼʱ�� ����ʱ�� ��Ӧ����:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> start[i];
        cin >> final[i];
        cin >> q[i];
        index[i] = i;
    }
    sort(index + 1, index + n + 1, [&](int a, int b)
         { return final[a] < final[b]; });

    //���ź����index�����µ�start,final,q��ʡʱ��
    int sortedStart[1000 + 1], sortedFinal[1000 + 1], sortedQ[1000 + 1];
    for (int i = 1; i <= n; i++)
    {
        sortedStart[i] = start[index[i]];
        sortedFinal[i] = final[index[i]];
        sortedQ[i] = q[index[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(sortedFinal + 1, sortedFinal + n + 1, sortedStart[i]) - sortedFinal;
        //lower_bound�Ƕ��ֲ����ҵ�һ�����ڱ�׼ֵ�ĺ���,��ȥ�׵�ַ�õ�����
        //����Ҫ�õ����һ�������ڱ�׼ֵ��,����Ҫ��1
        p[i] = pos - 1; // ���һ������ʱ��ܵ�ǰ��ʼʱ��Ļ
        if (p[i] < 1) p[i] = 0; // *****//���û�������Ļ��p[i] ��Ϊ 0
    }
    for (int i = 1; i <= n; i++)
    {
        Memo[i] = Memo[p[i]] + sortedQ[i];
        Rec[i] = 1;
        if (Memo[i - 1] > Memo[p[i]] + sortedQ[i])
        {
            Memo[i] = Memo[i - 1];
            Rec[i] = 0;
        }
    }
    int i = n;
    int maxmoney = Memo[n];
    while (i >= 1)
    {
        if (Rec[i] == 1)
        {
            cout << index[i] << ' ';
            i = p[i];
        }
        else
        {
            i--;
        }
    }
    cout << endl;
    cout << "�������Ϊ" << maxmoney;
}