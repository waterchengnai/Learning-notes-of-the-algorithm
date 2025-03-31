//问题描述：
//给定链表的头结点 head ,请将其按 升序 排列并返回 排序后的链表 

Definition for singly - linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode* node;

//1.前置函数一,找到中间节点
//这个函数是最标准的找到链表的中间节点的函数
//希望你能记得每个细节

node tofindmiddle(node head)
{
    if (head == NULL)return NULL;
		
	  //①这里必须fast指向首节点不是头节点,这里会影响到后面中间节点是否准确
    node fast = head->next;
    node slow = head;
	  
    //②这里的判断条件也要记得
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//2.前置函数二,也不算前置函数吧,这是进行将链表节点大小比较的函数

node merge(node left, node right)
{
    struct ListNode newhead;
	//这里并不是动态内存分配的,有以下两点
    //1.我们这个函数比较是为了得到新的链表,但是这个链表我们不需要头节点,而这里的newhead就是新链表的头节点
    //但是其他的head不是头节点,其实是首节点
    //2.动态内存分配会降低运行速度和占用内存

    node temp = &newhead;
    //这里的控制条件你就记吧,理解是能理解,但是写的话想不一定能全部想到
    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    //这里的if是为了解决两个里面剩的节点
    if (left == NULL)
    {
        temp->next = right;
    }
    else if (right == NULL)
    {
        temp->next = left;
    }
    return newhead.next;
}

node mergesort(node head)
{
    // 递归终止条件
    //节点最终要么是NULL,要么是只有一个节点
    if (head == NULL || head->next == NULL)return head;
    node middle = tofindmiddle(head);

    //在这里是断开链表的操作
    node left = head;
    node right = middle->next;
    middle->next = NULL;

    return merge(mergesort(left), mergesort(right));

}

struct ListNode* sortList(struct ListNode* head) {
    return mergesort(head);
}