#include <libc.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} t_list;

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

struct ListNode *oddEvenList(struct ListNode *head)
{
	struct ListNode *odd = head;
	struct ListNode *even = odd->next;
	struct ListNode *even_head = even;
	while(even && even_head)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = even_head;
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
	struct ListNode  *current = oddEvenList(head0);
	while(current)
	{
		printf("%d\t", current->val);
		current = current->next;
	}
}