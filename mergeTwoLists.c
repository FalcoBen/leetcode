#include <libc.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
} t_list;

struct ListNode *last_node(struct ListNode *lst)
{
	struct ListNode *curr = lst;
	while(curr->next)
	{
		curr = curr->next;
	}
	return curr;
}

void ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void sort_list(struct ListNode *lst)
{
	if(!lst)
		return ;
	struct ListNode *current = lst;
	struct ListNode *node;
	while(current)
	{
		node = lst;
		while(node->next)
		{
			if(node->val > node->next->val)
				ft_swap(&node->val, &node->next->val);
			node = node->next;
		}
		current = current->next;
	}
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if(!list1 && !list2)
		return NULL;
    struct ListNode *last_in_list = last_node(list1);
	last_in_list->next = list2;
	sort_list(list1);
	return list1;
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
	struct ListNode  *head1 = lst_new(3);
	struct ListNode  *head2 = lst_new(5);
	struct ListNode  *head3 = lst_new(7);
	struct ListNode  *head4 = lst_new(9);
	head0->next = head1;
	head1->next = head2;
	head2->next = head3;
	head3->next = head4;
	struct ListNode  *tmp1 = head0;
	printf("the first list\n");
	while(tmp1)
	{
		printf("%d\t", tmp1->val);
		tmp1 = tmp1->next;
	}
	printf("\nthe second list\n");
	struct ListNode  *body0 = lst_new(2);
	struct ListNode  *body1 = lst_new(4);
	struct ListNode  *body2 = lst_new(6);
	struct ListNode  *body3 = lst_new(8);
	struct ListNode  *body4 = lst_new(10);
	body0->next = body1;
	body1->next = body2;
	body2->next = body3;
	body3->next = body4;
	struct ListNode  *tmp = body0;
	while(tmp)
	{
		printf("%d\t", tmp->val);
		tmp = tmp->next;
	}
	printf("\nafter\n");
	struct ListNode  *current = mergeTwoLists(head0, NULL);
	while(current)
	{
		printf("%d\t", current->val);
		current = current->next;
	}
}