//给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。
//
//对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
//
//请按身高 降序 顺序返回对应的名字数组 names 。
//
//
//
//示例 1：
//
//输入：names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
//输出：["Mary", "Emma", "John"]
//解释：Mary 最高，接着是 Emma 和 John 。
//示例 2：
//
//输入：names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
//输出：["Bob", "Alice", "Bob"]
//解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。

//***************************************************//
//这次的代码比上次的题目的代码有很多优化点
//而且这次是数组转化成链表再进行归并排序,这是因为我觉得链表进行归并排序好操作(绝不是我不知道咋写)
//这两次的代码可以比较着看,还有链表初始化那一堆糟心事可以看看

struct node {
    int height;
    int original_idx;
    struct node* next;
};

struct node* createList(int* heights, int heightsSize) {
    if (heightsSize == 0) return NULL;

    //初始化链表的动态内存分配,以及一些杂七杂八的赋值总是让人看不懂
    struct node* nodes = malloc(heightsSize * sizeof(struct node));
    for (int i = 0; i < heightsSize; i++) {
        nodes[i].height = heights[i];
        nodes[i].original_idx = i;
        //这里特别厉害,用三目运算进行移动
        nodes[i].next = (i < heightsSize - 1) ? &nodes[i + 1] : NULL;
    }
    return nodes;
}

struct node* findMiddle(struct node* head) {
    if (!head) return NULL;
    struct node* slow = head, * fast = head->next;
    //这里还是要记得fast初始化是啥

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node* merge(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->height >= l2->height) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    //这里更牛逼,三目运算符用的太好了
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct node* mergeSort(struct node* head) {
    if (!head || !head->next) return head;

    // 分割链表
    struct node* mid = findMiddle(head);
    struct node* left = head;
    struct node* right = mid->next;
    mid->next = NULL;  // 切断链表连接

    // 递归排序与合并
    return merge(mergeSort(left), mergeSort(right));
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // 1. 创建并排序链表
    struct node* head = createList(heights, heightsSize);
    head = mergeSort(head);

    // 2. 生成结果数组
    char** result = malloc(namesSize * sizeof(char*));
    struct node* curr = head;
    for (int i = 0; i < namesSize && curr; i++) {
        result[i] = names[curr->original_idx];
        curr = curr->next;
    }
    *returnSize = namesSize;
    return result;
}