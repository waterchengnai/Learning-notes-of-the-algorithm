////����������Ҳ��̰�Ĳ��Ե�����
////�����ݽṹ��,�����Ѿ�ѧϰ������������
////���������Ƶ�һ��,��������ô����
////��������Ҫ��26��Ӣ����ĸ��01������,��Ҫ��֤ÿ����ĸ�ı��벻���ظ�,�ұ��벻���ڰ�����ϵ,��ֹ�������
////��ʱ�����ǿ����뵽,�ö�������Ҷ�ӽڵ����һ����ĸ,���ߴ���0,���ߴ���1,������֤��������ĸ���벻���ϴ�
////��������������,ÿ����ĸ��ʹ��Ƶ���ǲ�һ����,������ô��ʹ��Ƶ�ʴ����ĸ�ֵ�����С�ı��볤��,Ҳ��������Ҷ�ӽڵ������?
////�����뵽�˽�����ʹ��Ƶ����С��Ԫ�ص����ֵܽڵ�,���ǵĸ��ڵ�����µ�����,���ҳ�����ʹ��Ƶ����С��,�Դ�����
////�������Ǿ͸㶨��
////��֤̰���㷨�ǲ������Ž���?
////���Ǽ�������һ��һ����ǽ���ǰ����������Ҷ�ӽڵ��Ϸ���,��ô���ǵĵõ��µĽ��Ȩ·�����Ǹ�����,��������,���������ⶼ������С�ڵ��ν�
////����������������ʵ������
////5.5���Ƿ����Լ�д��,���Ժ�ˮƽ������ս����
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//// ����������㶨��
//struct Node {
//    int freq;
//    Node* left;
//    Node* right;
//    Node(int f) : freq(f), left(nullptr), right(nullptr) {}
//};
//
//// ���ȶ��бȽϺ�������С�ѣ�
//struct Compare {
//    bool operator()(Node* a, Node* b) {
//        return a->freq > b->freq;
//    }
//};
//
//// ��P�����Q�����л�ȡ��С���
//Node* extractMin(vector<Node*>& P, priority_queue<Node*, vector<Node*>, Compare>& Q, int& idx) {
//    Node* minNode = nullptr;
//
//    // ��P�����Q�����ж���ʣ��Ԫ��ʱ�Ƚ�
//    if (idx < P.size() && !Q.empty()) {
//        minNode = (P[idx]->freq <= Q.top()->freq) ? P[idx++] : Q.top();
//        if (minNode == Q.top()) Q.pop();
//    }
//    // ��ֻ��P������ʣ��Ԫ��ʱ
//    else if (idx < P.size()) {
//        minNode = P[idx++];
//    }
//    // ��ֻ��Q������ʣ��Ԫ��ʱ
//    else if (!Q.empty()) {
//        minNode = Q.top();
//        Q.pop();
//    }
//
//    return minNode;
//}
//
//// ��������������������
//Node* Huffman(int F[], int n) {
//    if (n == 0) return nullptr;
//
//    sort(F, F + n);  // O(n log n) ����
//
//    vector<Node*> P;  // ��ʼ���������P
//    for (int i = 0; i < n; ++i) {
//        P.push_back(new Node(F[i]));
//    }
//
//    priority_queue<Node*, vector<Node*>, Compare> Q;  // ��������
//    int idx = 0;  // P����ĵ�ǰ����
//
//    // �ϲ�n-1��
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
//// ���Դ���
//int main() {
//    int F[] = { 5, 9, 12, 13, 16, 45 };
//    int n = sizeof(F) / sizeof(int);
//
//    Node* root = Huffman(F, n);
//    cout << "Root frequency: " << root->freq << endl;  // Ӧ�����Ƶ��120
//
//    /* �������ṹ��
//         120
//        /   \
//      50     70
//     /  \   /  \
//    21  29 30  40
//    ......������ṹȡ���ںϲ�˳��*/
//
//    return 0;
//}