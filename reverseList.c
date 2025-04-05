#include <libc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode  *last_node(struct ListNode  *node)
{
	while(node->next)
	{
		node = node->next;
	}
	return node;
}
int lst_size(struct ListNode  *node)
{
	int counter = 0;
	while(node)
	{
		counter++;
		node = node->next;
	}
	return counter;
}

void ft_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode  *last = last_node(head);
	int size = lst_size(head);
	struct ListNode  *nodes[size];
	struct ListNode  *current = head;
	int i = 0;
	while(i < size)
	{
		nodes[i++] = current;
		current = current->next;
	}
    int start = 0;
	int end = lst_size(head) - 1;
	while(start < end)
	{
		ft_swap(&nodes[start]->val, &nodes[end]->val);
		start++;
		end--;
	}
	return head;
}

struct ListNode  *lst_new(int data)
{
	struct ListNode  *node = malloc(sizeof(struct ListNode ));
	node->val = data;
	node->next = NULL;
	return node;
}

int main()
{
	struct ListNode  *head0 = lst_new(1);
	struct ListNode  *head1 = lst_new(2);
	struct ListNode  *head2 = lst_new(3);
	struct ListNode  *head3 = lst_new(4);
	struct ListNode  *head4 = lst_new(5);
	head0->next = head1;
	head1->next = head2;
	head2->next = head3;
	head3->next = head4;
	struct ListNode  *tmp = head0;
	while(tmp)
	{
		printf("%d\t", tmp->val);
		tmp = tmp->next;
	}
	printf("\nafter\n");
	struct ListNode  *current = reverseList(head0);
	while(current)
	{
		printf("%d\t", current->val);
		current = current->next;
	}
}