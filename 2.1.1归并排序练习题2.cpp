//����һ���ַ������� names ����һ���� ������ͬ ����������ɵ����� heights ����������ĳ��Ⱦ�Ϊ n ��
//
//����ÿ���±� i��names[i] �� heights[i] ��ʾ�� i ���˵����ֺ���ߡ�
//
//�밴��� ���� ˳�򷵻ض�Ӧ���������� names ��
//
//
//
//ʾ�� 1��
//
//���룺names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
//�����["Mary", "Emma", "John"]
//���ͣ�Mary ��ߣ������� Emma �� John ��
//ʾ�� 2��
//
//���룺names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
//�����["Bob", "Alice", "Bob"]
//���ͣ���һ�� Bob ��ߣ�Ȼ���� Alice �͵ڶ��� Bob ��

//***************************************************//
//��εĴ�����ϴε���Ŀ�Ĵ����кܶ��Ż���
//�������������ת���������ٽ��й鲢����,������Ϊ�Ҿ���������й鲢����ò���(�������Ҳ�֪��զд)
//�����εĴ�����ԱȽ��ſ�,���������ʼ����һ�������¿��Կ���

struct node {
    int height;
    int original_idx;
    struct node* next;
};

struct node* createList(int* heights, int heightsSize) {
    if (heightsSize == 0) return NULL;

    //��ʼ������Ķ�̬�ڴ����,�Լ�һЩ�����Ӱ˵ĸ�ֵ�������˿�����
    struct node* nodes = malloc(heightsSize * sizeof(struct node));
    for (int i = 0; i < heightsSize; i++) {
        nodes[i].height = heights[i];
        nodes[i].original_idx = i;
        //�����ر�����,����Ŀ��������ƶ�
        nodes[i].next = (i < heightsSize - 1) ? &nodes[i + 1] : NULL;
    }
    return nodes;
}

struct node* findMiddle(struct node* head) {
    if (!head) return NULL;
    struct node* slow = head, * fast = head->next;
    //���ﻹ��Ҫ�ǵ�fast��ʼ����ɶ

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
    //�����ţ��,��Ŀ������õ�̫����
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct node* mergeSort(struct node* head) {
    if (!head || !head->next) return head;

    // �ָ�����
    struct node* mid = findMiddle(head);
    struct node* left = head;
    struct node* right = mid->next;
    mid->next = NULL;  // �ж���������

    // �ݹ�������ϲ�
    return merge(mergeSort(left), mergeSort(right));
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // 1. ��������������
    struct node* head = createList(heights, heightsSize);
    head = mergeSort(head);

    // 2. ���ɽ������
    char** result = malloc(namesSize * sizeof(char*));
    struct node* curr = head;
    for (int i = 0; i < namesSize && curr; i++) {
        result[i] = names[curr->original_idx];
        curr = curr->next;
    }
    *returnSize = namesSize;
    return result;
}