// 既然分析过了之前那种不带其他考虑的事件安排问题,我们现在来考虑更合实际的情况
// 即每个活动都有对应收益(当然也可以是别的带权情况,要求的也可能是权值最小的),那么此时再使用之前的贪心算法策略就不正确了,我们都能轻松举出反例
// 那我们思考一下,之前的分而治之和动态规划哪个更合适呢?
// 应该是动态规划
// 那我们分析一下对应的动态规划四部曲
// 1.问题构建.找到活动收益最优解
// 假如事件没有顺序,那么接下来的操作会出问题,所以要先排序
// 我们依然按之前的最早结束顺序排个序,然后可以得到Memo[i],即前i个事件的最优解
// 最终要得到Memo[n]
// 2.递推关系构建.
// Memo[i]与Memo[i-1]之间显然是有关系的,关键在于i的选择
// ①如果i选择了,那么前面i-1个活动中事件冲突的活动就要滚蛋了
// 我们可以用p[i]记录最后一个结束时间在事件i开始时间前面的事件
// 这样Memo[i]=Memo[p[i]]+q[i];
// ②如果i没选,那Memo[i]=Memo[i-1]
// 当然,上面两种选哪个要看哪个最大
// 即Memo[i]=max{Memo[p[i]]+q[i],Memo[i-1]}
// 3.自底向上计算
// 我们思考可得,Memo[0]=0;
// Memo[1]=q[1];所以低端情况确定了,下面就可以上推了
// 4.最优方案追踪
// Rec[i]=①1;②0.
// 1代表i这一项选了,那么根据上面Memo的逻辑接下来就要查q[i]了
// 0代表该项没选,那么同样的逻辑该差i-1了
#include <iostream>
#include <algorithm>
using namespace std;
int Memo[1000];
int Rec[1000];
int start[1000];
int final[1000];
int index[1000];
int q[1000];
int p[1000]; // 记录的是最后一个结束时间在事件i开始时间前面的事件j
int main()
{
    int n;
    cout << "请输入活动个数:" << endl;
    cin >> n;
    cout << "请输入各个活动的开始时间 结束时间 对应收益:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> start[i];
        cin >> final[i];
        cin >> q[i];
        index[i] = i;
    }
    sort(index + 1, index + n + 1, [&](int a, int b)
         { return final[a] < final[b]; });

    //用排好序的index创建新的start,final,q节省时间
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
        //lower_bound是二分查找找第一个大于标准值的函数,减去首地址得到索引
        //但是要得到最后一个不大于标准值的,所以要减1
        p[i] = pos - 1; // 最后一个结束时间≤当前开始时间的活动
        if (p[i] < 1) p[i] = 0; // *****//如果没有这样的活动，p[i] 设为 0
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
    cout << "最大收益为" << maxmoney;
}