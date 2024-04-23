
#define	_CRT_SECURE_NO_WARNINGS 1
#include"all.h"
Node3* init_list3()
{
	Node3* head = malloc(sizeof(Node3));
	head->next = NULL;
	head->prev = NULL;
	head->cus_ = NULL;
	return head;

}

Node3* push_head3(Node3* h)
{
	if (h == NULL)
	{
		return NULL;
	}
	Node3* new = init_list3();
	if (h->next)
	{
		h->next->prev = new;
	}
	new->prev = h;
	new->next = h->next;
	h->next = new;
	return h;
}

Node3* record_cus_info(Node3* head, bool to_std)
{
	if (head == NULL)
	{
		printf("head is empty\n");
		return 0;
	}
	FILE* out;
	Node3* o = head->next;
	if (to_std == true)
	{
		cus_prompt();
		if (o == NULL)
		{
			printf("暂无相应信息\n");
		}

		out = stdout;
	}
	else
	{
		showdir();
		out = open_info_file(CusI, "r");
	}
	if (out == NULL)
	{
		printf("file open fail to record_CusI_info\n");
		return 0;
	}


	while (o != NULL)
	{
		Node3* next_node = o->next;
		Customer* temp = o->cus_;
		if (temp != NULL)
		{
			printf("%d\t\t\t%s\t\t%s\n", temp->vip, temp->cus_name, temp->phone);
		}
		o = next_node;
	}
	if (out != stdout)
	{
		fclose(out);
		printf("顾客信息导入成功\n");


	}
	printf("\n");
	return head;
}