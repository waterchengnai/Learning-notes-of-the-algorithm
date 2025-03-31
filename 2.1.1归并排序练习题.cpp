//����������
//���������ͷ��� head ,�뽫�䰴 ���� ���в����� ���������� 

Definition for singly - linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode* node;

//1.ǰ�ú���һ,�ҵ��м�ڵ�
//������������׼���ҵ�������м�ڵ�ĺ���
//ϣ�����ܼǵ�ÿ��ϸ��

node tofindmiddle(node head)
{
    if (head == NULL)return NULL;
		
	  //���������fastָ���׽ڵ㲻��ͷ�ڵ�,�����Ӱ�쵽�����м�ڵ��Ƿ�׼ȷ
    node fast = head->next;
    node slow = head;
	  
    //��������ж�����ҲҪ�ǵ�
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//2.ǰ�ú�����,Ҳ����ǰ�ú�����,���ǽ��н�����ڵ��С�Ƚϵĺ���

node merge(node left, node right)
{
    struct ListNode newhead;
	//���ﲢ���Ƕ�̬�ڴ�����,����������
    //1.������������Ƚ���Ϊ�˵õ��µ�����,��������������ǲ���Ҫͷ�ڵ�,�������newhead�����������ͷ�ڵ�
    //����������head����ͷ�ڵ�,��ʵ���׽ڵ�
    //2.��̬�ڴ����ή�������ٶȺ�ռ���ڴ�

    node temp = &newhead;
    //����Ŀ���������ͼǰ�,����������,����д�Ļ��벻һ����ȫ���뵽
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

    //�����if��Ϊ�˽����������ʣ�Ľڵ�
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
    // �ݹ���ֹ����
    //�ڵ�����Ҫô��NULL,Ҫô��ֻ��һ���ڵ�
    if (head == NULL || head->next == NULL)return head;
    node middle = tofindmiddle(head);

    //�������ǶϿ�����Ĳ���
    node left = head;
    node right = middle->next;
    middle->next = NULL;

    return merge(mergesort(left), mergesort(right));

}

struct ListNode* sortList(struct ListNode* head) {
    return mergesort(head);
}