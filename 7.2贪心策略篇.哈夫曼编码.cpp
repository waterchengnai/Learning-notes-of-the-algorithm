////哈夫曼编码也是贪心策略的体现
////在数据结构中,我们已经学习过哈夫曼编码
////我们现在推导一下,这玩意怎么来的
////现在我们要对26个英文字母用01串编码,且要保证每个字母的编码不能重复,且编码不存在包含关系,防止编译错误
////这时候我们可以想到,用二叉树的叶子节点代表一个字母,左走代表0,右走代表1,这样保证了所有字母编码不会认错
////但是问题又来了,每个字母的使用频率是不一样的,我们怎么让使用频率大的字母分到尽量小的编码长度,也就是所在叶子节点更高呢?
////我们想到了将两个使用频率最小的元素当作兄弟节点,它们的父节点参与新的排序,再找出两个使用频率最小的,以此类推
////这样我们就搞定了
////验证贪心算法是不是最优解呢?
////我们假设有有一个一般解是将当前解的最下面的叶子节点上放了,那么我们的得到新的解带权路径长是更长的,依次类推,所有其他解都不可能小于当衔解
////下面让我们来代码实现以下
////5.5哥们放弃自己写了,等以后水平高了再战这题
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//// 哈夫曼树结点定义
//struct Node {
//    int freq;
//    Node* left;
//    Node* right;
//    Node(int f) : freq(f), left(nullptr), right(nullptr) {}
//};
//
//// 优先队列比较函数（最小堆）
//struct Compare {
//    bool operator()(Node* a, Node* b) {
//        return a->freq > b->freq;
//    }
//};
//
//// 从P数组和Q队列中获取最小结点
//Node* extractMin(vector<Node*>& P, priority_queue<Node*, vector<Node*>, Compare>& Q, int& idx) {
//    Node* minNode = nullptr;
//
//    // 当P数组和Q队列中都有剩余元素时比较
//    if (idx < P.size() && !Q.empty()) {
//        minNode = (P[idx]->freq <= Q.top()->freq) ? P[idx++] : Q.top();
//        if (minNode == Q.top()) Q.pop();
//    }
//    // 当只有P数组有剩余元素时
//    else if (idx < P.size()) {
//        minNode = P[idx++];
//    }
//    // 当只有Q队列有剩余元素时
//    else if (!Q.empty()) {
//        minNode = Q.top();
//        Q.pop();
//    }
//
//    return minNode;
//}
//
//// 哈夫曼编码树构建函数
//Node* Huffman(int F[], int n) {
//    if (n == 0) return nullptr;
//
//    sort(F, F + n);  // O(n log n) 排序
//
//    vector<Node*> P;  // 初始化结点数组P
//    for (int i = 0; i < n; ++i) {
//        P.push_back(new Node(F[i]));
//    }
//
//    priority_queue<Node*, vector<Node*>, Compare> Q;  // 辅助队列
//    int idx = 0;  // P数组的当前索引
//
//    // 合并n-1次
//    for (int i = 0; i < n - 1; ++i) {
//        Node* x = extractMin(P, Q, idx);
//        Node* y = extractMin(P, Q, idx);
//
//        Node* z = new Node(x->freq + y->freq);
//        z->left = x;
//        z->right = y;
//        Q.push(z);
//    }
//
//    return extractMin(P, Q, idx);
//}
//
//// 测试代码
//int main() {
//    int F[] = { 5, 9, 12, 13, 16, 45 };
//    int n = sizeof(F) / sizeof(int);
//
//    Node* root = Huffman(F, n);
//    cout << "Root frequency: " << root->freq << endl;  // 应输出总频率120
//
//    /* 最终树结构：
//         120
//        /   \
//      50     70
//     /  \   /  \
//    21  29 30  40
//    ......（具体结构取决于合并顺序）*/
//
//    return 0;
//}