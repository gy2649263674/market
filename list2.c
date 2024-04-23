#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include "list2.h"
#include "goods.h"
#include"struct.h"
#include"sys.h"
#include"all.h"

//dir 
void warning_op(Node2* head)
{
	int lower_bound = 10;
	setcolor(BCYAN);
	printf("正在使用预警系统\n\033[0m");
	while (1)
	{
		printf("0:return\n\
1:设置阈值\n\
2:查看将售罄商品\n");
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{

			lower_bound = exam();
			if (lower_bound < 0)
			{
				printf("阈值不合法，请重新设置");
			}
			continue;
		}
		else if (op == 2)
		{
			printf("当前阈值为\033[31m%d\033[0m\n", lower_bound);
			warning(head, lower_bound);

		}
	}
	return;
}

Node2* init_list2()
{
	Node2* head = malloc(sizeof(Node));
	if (!head)
	{
		return NULL;
	}
	head->next = NULL;
	head->prev = NULL;
	return head;
}

Node2* clear_list2(Node2* head)
{
	Node2* p1 = head->next;
	Node2* p2;
	while (p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		free(p2);
	}
	return head;
}

Node2* push_head2(Node2* head, int s, int l, char* n)
{
	if (head == NULL)
		return NULL;
	Node2* new = malloc(sizeof(Node));
	strcpy(new->name, n);
	new->left = l;
	new->sold = s;
	if (head->next)
	{
		head->next->prev = new;
	}
	new->prev = head;
	new->next = head->next;
	head->next = new;
	return head;
}

void show_list2_sell(Node2* head)
{
	Node2* p = head->next;
	while (p != NULL)
	{
		printf("%s的销售数量为：%d\n", p->name, p->sold);
		p = p->next;
	}
}

void show_list2_left(Node2* head)
{
	Node2* p = head->next;
	while (p != NULL)
	{
		printf("%s的剩余数量为：%d\n", p->name, p->left);
		p = p->next;
	}
}

void warning(Node2* head, int yuzhi)
{
	int d = 0;
	if (yuzhi == 0)
	{
		printf("阈值不合法");
	}
	Node2* p = head->next;
	while (p != NULL)
	{
		if (p->left <= yuzhi)
		{
			d = 1;
			printf("%s剩余货物量为%d,需要补货\n", p->name, p->left);
		}
		p = p->next;
	}
	if (d == 0)
	{
		printf("物资充足,无需补货\n");
	}
}

Node2* cmpp(Node* p, Node2* head)
{
	Node2* p2 = head->next;
	while (p2 != NULL)
	{
		if (!strcmp(p->base_->type, p2->name))
		{
			return p2;
		}
		p2 = p2->next;
	}
	return NULL;
}


Node2* creat_list2(Node* head)
{
	Node2* head2 = init_list2();
	Node* p = head->next;
	while (p != NULL)
	{
		Node2* p2 = cmpp(p, head2);
		double s = p->sell_->sell_volume;
		double l = p->pur_->purchase_size - s;
		char n[20];
		strcpy(n, p->base_->type);
		if (p2 == NULL)
		{
			head2 = push_head2(head2, s, l, n);
		}
		else
		{
			p2->left += l;
			p2->sold += s;
		}
		p = p->next;
	}
	return head2;
}