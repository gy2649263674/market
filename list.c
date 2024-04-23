//#define CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS
#include"all.h"
#include<stdio.h>

typedef enum Range
{
	base_priceR,
	pur_priceR,
	sell_priceR,
	pur_dateR,
	sell_dateR,
	sell_volume,

}Range;
void pin(Node* resource_, Node* des)
{
	des->base_ = resource_->base_;
	des->sell_ = resource_->sell_;
	des->pur_ = resource_->pur_;
	strcpy(des->name, resource_->name);
	strcpy(des->id, resource_->id);
}
void range_query_menu(Node* head)
{
	//title
	while (1)
	{
		setcolor(BCYAN);
		printf("\t\t\t\t\t范围查询\033[0m\n");
		//1:按类型筛选\n\
		//printf("\t\t\t\t\t统计数据ing\033[0m");
		printf("0:退出\n\
1:按价格范围筛选\n\
2:按日期范围筛选\n\
3:已售出物品件数\n\
");

		int op = exam();
		if (op == 0)
		{
			return;
		}

		//price range
		else if (op == 1)
		{
			while (1)
			{
				setcolor(BCYAN);
				printf("\t\t\t\t价格范围内查询\033[0m\n\0");
				printf("0:退出\n\
1:标价\n\
2:售价\n\
3:进价\n\
");
				int op1 = exam();
				if (op1 == 0)
				{
					break;
				}
				else if (op1 == 1)
				{
					range_query(head, base_priceR);
				}
				else if (op1 == 2)
				{
					range_query(head, sell_priceR);
				}
				else if (op1 == 3)
				{
					range_query(head, pur_priceR);
				}
				else
				{
					wa();
				}
			}
		}

		//date range
		else if (op == 2)
		{
			while (1)
			{
				printf("0:exit\n\
1:某日期范围内进货信息\n\
2:某日期范围内销售信息\n\
");
				int op1 = exam();
				if (op1 == 0)
				{
					break;
				}
				else if (op1 == 1)
				{
					range_query(head, pur_dateR);
				}
				else if (op1 == 2)
				{
					range_query(head, sell_dateR);
				}
				else
				{
					wa();
				}
			}
		}
		else if (op == 3)
		{

			range_query(head, sell_volume);
		}
		else
		{
			wa();
		}
	}
	return;
}
bool date_in_range(date* judge, date* l, date* h)
{
	if ((l->year - judge->year) * (h->year - judge->year) > 0)
	{
		return false;
	}
	else if ((l->year - judge->year) * (h->year - judge->year) < 0)
	{
		return true;
	}
	else if ((l->year - judge->year) * (h->year - judge->year) == 0)
	{
		if ((l->year - judge->month) * (h->year - judge->month) > 0)
		{
			return false;
		}
		else if (((l->year - judge->month) * (h->year - judge->month) < 0))
		{
			return true;
		}
		else
		{
			if ((l->year - judge->day) * (h->year - judge->day) > 0)
			{
				return false;
			}
			else if ((l->year - judge->day) * (h->year - judge->day) < 0)
			{
				return true;
			}
		}
	}
	return false;



}



bool in_range(Node* o, Range cate, void* data) //void* (data[2]))
{
	if (cate == sell_priceR)
	{
		double l = DOUBLE(data)[0];
		double h = DOUBLE(data)[1];
		if (o->sell_->sell_price <= h && o->sell_->sell_price >= l)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (cate == base_priceR)
	{
		double l = DOUBLE(data)[0];
		double h = DOUBLE(data)[1];
		if (o->base_->price <= h && o->base_->price >= l)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (cate == pur_priceR)
	{
		double l = DOUBLE(data)[0];
		double h = DOUBLE(data)[1];
		if (o->pur_->purchase_price <= h && o->pur_->purchase_price >= l)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (cate == sell_dateR)
	{
		return date_in_range(&o->sell_->sell_date, &((date*)data)[0], &DATE(data)[1]);
	}
	else if (cate == pur_dateR)
	{
		return date_in_range(&o->pur_->purchase_date, &DATE(data)[0], &DATE(data)[1]);
	}
	else if (cate == sell_volume)
	{
		int l = INT(data)[0];
		int h = INT(data)[1];
		if (o->sell_->sell_volume <= h && o->sell_->sell_volume >= l)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}
void price_range(Node* head, void* data_range, Range cate)
{
	if (head == NULL)
	{
		return;
	}
	Node* o = head->next;
	Node* temphead = init_list();
	if (cate == sell_priceR)
	{
		while (o)
		{
			if (in_range(o, sell_priceR, data_range))
			{
				push_head(temphead);
				pin(o, temphead->next);
			}
			o = o->next;
		}
		printf
		("售出价格在%.2lf--%.2lf间的商品销售信息:\n", DOUBLE(data_range)[0], DOUBLE(data_range)[1]);
		record_sell_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}
	else if (cate == base_priceR)
	{
		while (o)
		{
			if (in_range(o, base_priceR, data_range))
			{
				push_head(temphead);
				pin(o, temphead->next);

			}
			o = o->next;
		}
		printf("标价在%.2lf--%.2lf间的商品销售信息:\n", DOUBLE(data_range)[0], DOUBLE(data_range)[1]);
		record_base_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}
	else if (cate == pur_priceR)
	{
		while (o)
		{
			if (in_range(o, pur_priceR, data_range))
			{
				push_head(temphead);
				pin(o, temphead->next);

			}
			o = o->next;

		}

		printf("进货价格在%.2lf--%.2lf间的商品销售信息:\n", DOUBLE(data_range)[0], DOUBLE(data_range)[1]);
		record_purchase_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}
	else if (cate == sell_volume)
	{
		while (o)
		{
			if (in_range(o, sell_volume, data_range))
			{
				push_head(temphead);
				pin(o, temphead->next);

			}
			o = o->next;

		}

		printf("sell_volume %d----%d间的商品销售信息:\n", INT(data_range)[0], INT(data_range)[1]);
		record_purchase_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}

}

void date_range(Node* head, date* data_range, Range cate)
{
	if (head == NULL)
	{
		return;
	}
	Node* o = head->next;
	Node* temphead = init_list();
	if (cate == sell_dateR)
	{

		while (o)
		{
			if (in_range(o, sell_dateR, data_range))
			{
				push_head(temphead);
				pin(o, temphead->next);

			}
			o = o->next;
		}
		printf("售出时间在%d %d %d--%d %d %d间的商品销售信息:\n", data_range[0].year, data_range[0].month, data_range[0].day, data_range[1].year, data_range[1].month, data_range[1].day);
		record_sell_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}
	if (cate == pur_dateR)
	{

		while (o)
		{
			if (in_range(o, pur_dateR, data_range))
			{
				push_head(temphead);
				pin(o, temphead);
			}
			o = o->next;
		}
		printf("进货时间在%d %d %d--%d %d %d间的商品销售信息:\n", data_range[0].year, data_range[0].month, data_range[0].day, data_range[1].year, data_range[1].month, data_range[1].day);
		record_purchase_info(temphead, true);
		destruct_list(&temphead, VoidI);
	}
}
int range_query(Node* head, Range cate)
{
	if (head == NULL)
	{
		return 0;
	}
	if (cate == base_priceR)
	{
		double data_range[2];
		printf("请依次输入标价下上界\n");
		scanf("%lf%lf", &data_range[0], &data_range[1]);
		price_range(head, data_range, base_priceR);
	}if (cate == sell_volume)
	{
		int data_range[2];
		printf("请依次输入售出件数下上界\n");
		scanf("%d%d", &data_range[0], &data_range[1]);
		price_range(head, data_range, sell_volume);
	}
	else if (cate == sell_priceR)
	{
		double data_range[2];
		printf("请依次输入售价下上界\n");
		scanf("%lf%lf", &data_range[0], &data_range[1]);
		price_range(head, data_range, sell_priceR);
	}
	else if (cate == pur_priceR)
	{
		double data_range[2];
		printf("请依次输入进价下上界\n");
		scanf("%lf%lf", &data_range[0], &data_range[1]);
		price_range(head, data_range, pur_priceR);
	}
	else if (cate == sell_dateR)
	{
		date data_range[2];
		printf("请依次输入售货起止日期\n");
		printf("start\n");
		scanf("%d%d%d", &data_range[0].year, &data_range[0].month, &data_range[0].day);
		printf("end\n");
		scanf("%d%d%d", &data_range[1].year, &data_range[1].month, &data_range[1].day);
		date_range(head, data_range, sell_dateR);
	}
	else if (cate == pur_dateR)
	{
		date data_range[2];
		printf("请依次输入进货起止日期\n");
		printf("start\n");
		scanf("%d%d%d", &data_range[0].year, &data_range[0].month, &data_range[0].day);
		printf("end\n");
		scanf("%d%d%d", &data_range[1].year, &data_range[1].month, &data_range[1].day);
		date_range(head, data_range, pur_dateR);
	}
	return 0;
}

bool equal(void* data, Node* p, info_change cate)
{
	if (cate == typeC)
	{
		if (!strcmp(p->base_->type, CHAR(data)))
		{
			return 1;
		}
	}
	else if (cate == priceC)
	{
		return *DOUBLE(data) == p->base_->price;
	}
	else if (cate == purchase_channelC)
	{
		if (!strcmp(p->pur_->purchase_channel, CHAR(data)))
		{
			return 1;
		}
	}
	return false;
}
void type_sta(Node* head)
{
	char ty[20];
	printf("请输入类型名\n");
	scanf("%s", ty);
	Node* p = head->next;
	int num = 0;
	while (p != NULL)
	{
		if (equal(ty, p, typeC))
		{
			num++;
		}
		p = p->next;
	}
	printf("%s类的数量为：%d\n", ty, num);
}

void multi_info_staAAA(Node* head)
{
	while (1)
	{
		int op = exam();
		printf("0:return\n\
1:price&type\n\
2:price&channel\n\
3:channel&type\n");
		if (op == 0)
		{
			return;
		}
		multi_sta(head, op);
	}
}


void price_sta(Node* head)
{
	double pri;
	printf("请输入目标价格\n");
	scanf("%lf", &pri);
	Node* p = head->next;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	while (p != NULL)
	{
		if (p->sell_->sell_price > pri)
		{
			num1++;
		}
		else if (p->sell_->sell_price == pri)
			num2++;
		else
			num3++;
		p = p->next;
	}
	printf("价格大于%.2lf元的商品有%d件\n", pri, num1);
	printf("价格等于%.2lf元的商品有%d件\n", pri, num2);
	printf("价格小于%.2lf元的商品有%d件\n", pri, num3);
}

void multi_sta(Node* head, int operate)
{

	if (operate == 1)
	{
		double pri;
		char ty[20];
		printf("请输入类型名\n");
		scanf("%s", ty);
		printf("请输入目标价格\n");
		scanf("%lf", &pri);
		Node* p = head->next;
		int num1 = 0, num2 = 0, num3 = 0;
		while (p != NULL)
		{
			if (equal(ty, p, typeC) && p->sell_->sell_price == pri)
			{
				num1++;
			}
			else if (equal(ty, p, typeC) && p->sell_->sell_price > pri)
			{
				num2++;
			}
			else if (equal(ty, p, typeC) && p->sell_->sell_price < pri)
			{
				num3++;
			}
			p = p->next;
		}
		printf("%s类价格为%lf的商品有%d个\n", ty, pri, num1);
		printf("%s类价格大于%lf的商品有%d个\n", ty, pri, num2);
		printf("%s类价格小于%lf的商品有%d个\n", ty, pri, num3);
	}
	else if (operate == 2)
	{
		double pri;
		char ty[20];
		printf("请输入进货商名\n");
		scanf("%s", ty);
		printf("请输入目标价格\n");
		scanf("%lf", &pri);
		Node* p = head->next;
		int num1 = 0, num2 = 0, num3 = 0;
		while (p != NULL)
		{
			if (equal(ty, p, purchase_channelC) && p->sell_->sell_price == pri)
			{
				num1++;
			}
			else if (equal(ty, p, purchase_channelC) && p->sell_->sell_price > pri)
			{
				num2++;
			}
			else if (equal(ty, p, purchase_channelC) && p->sell_->sell_price < pri)
			{
				num3++;
			}
			p = p->next;
		}
		printf("%s进货商价格为%lf的商品有%d个\n", ty, pri, num1);
		printf("%s进货商大于%lf的商品有%d个\n", ty, pri, num2);
		printf("%s进货商小于%lf的商品有%d个\n", ty, pri, num3);
	}
	else if (operate == 3)
	{
		char channel[20];
		char ty[20];
		printf("请输入类型名\n");
		scanf("%s", ty);
		printf("请输入供应商名称\n");
		scanf("%s", channel);
		Node* p = head->next;
		int num = 0;
		while (p != NULL)
		{
			if (equal(channel, p, purchase_channelC) && equal(ty, p, typeC))
			{
				num++;
			}
			p = p->next;
		}
		printf("%s类供应商为%s的商品有%d个\n", ty, channel, num);
	}
}

















Node* combined_find(Node* head)
{
	char name[20], id[20];
	printf("输入姓名:\n");
	scanf("%s", name);
	printf("输入\n");
	scanf("%s", id);
	Node* p1 = head->next;
	while (p1 != NULL)
	{
		if (!strcmp(p1->name, name) && !strcmp(p1->id, id))
		{
			return p1;
		}
		p1 = p1->next;
	}
	setcolor(FRED);
	printf("不存在对象\n");
	resetcolor();
	return 0;
}

Node* fuzzy_find(Node* head)
{
	bool none = true;
	while (1)
	{
		char s[20];
		int operate;
		printf("选择功能:\n");
		printf("1:根据姓名模糊查询\n");
		printf("2:根据id模糊查询\n");
		scanf("%d", &operate);
		Node* p1 = head->next;
		printf("请输入关键字:\n");
		scanf("%s", s);
		if (operate == 1)
		{
			while (p1 != NULL)
			{
				if (strstr(p1->name, s))
				{
					showone(p1);
					none = false;
				}
				p1 = p1->next;
			}
			if (none)
			{
				setcolor(FRED);
				printf("无对应词条\n");
				return p1;
			}

		}
		else if (operate == 2)
		{
			while (p1 != NULL)
			{
				if (strstr(p1->id, s))
				{
					showone(p1);
					none = false;
				}
				p1 = p1->next;
			}
			if (none)
			{
				setcolor(FRED);
				printf("无对应词条\n");
				return p1;
			}
		}
		else if (operate == 0)
		{
			return 0;
		}
		else
		{
			purify();
			printf("retry please\n");
		}
	}
}
int getlength(Node* head)
{
	Node* o = head->next;
	int k = 0;
	while (o != NULL)
	{
		o = o->next;
		++k;
	}
	return k;
}
Node* init_list()
{
	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	head->prev = NULL;
	head->sell_ = NULL;
	head->base_ = NULL;
	head->pur_ = NULL;
	*head->id = '\0';
	*head->name = '\0';
	return head;
}

Node* push_head(Node* h)
{
	if (h == NULL)
	{
		return NULL;
	}
	Node* new = init_list();
	if (h->next)
	{
		h->next->prev = new;
	}
	new->prev = h;
	new->next = h->next;
	h->next = new;
	return h;
}

void swap(Node* a, Node* b)
{
	Node* ap = a->prev;
	Node* an = a->next;
	Node* bn = b->next;
	Node* bp = b->prev;
	a->next = bn;
	a->prev = b;
	b->next = a;
	b->prev = ap;
	if (bn)
	{
		bn->prev = a;
	}
	if (ap)
	{
		ap->next = b;
	}
}


//#define judge(Ind)
bool can_delete(Node* node, Info cate)
{
	if (cate == BaseI)
	{
		return !(node->base_ == NULL);
	}
	if (cate == SellI)
	{
		return !(node->sell_ == NULL);
	}
	if (cate == PurI)
	{
		return !(node->pur_ == NULL);
	}
	return false;

}

void free_info(Node* node, Info cate)
{
	if (cate == BaseI)
	{
		if (can_delete(node, BaseI))
			free(node->base_);
	}
	else if (cate == SellI)
	{
		if (can_delete(node, SellI))
			free(node->sell_);
	}
	else if (cate == PurI)
	{
		if (can_delete(node, PurI))
			free(node->pur_);
	}
	else if (cate == VoidI)
	{
		return;
	}
	else if (cate == AllI)
	{
		if (can_delete(node, SellI))
			free(node->sell_);
		if (can_delete(node, BaseI))
			free(node->base_);
		if (can_delete(node, PurI))
			free(node->pur_);
	}
}



void  free_node(Node** node, Info cate)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		free_info(*node, cate);
		//指针lay空
		free(*node);
	}
	return;

}

bool pur_vol_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return a->pur_->purchase_size < b->pur_->purchase_size;
	}
	else
		return a->pur_->purchase_size < b->pur_->purchase_size;

}
bool id_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return strcmp(a->id, b->id) < 0;
	}
	else
		return strcmp(a->id, b->id) > 0;
}

bool name_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return strcmp(a->name, b->name) < 0;
	}
	else
		return strcmp(a->name, b->name) > 0;
}

bool sell_price_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return a->sell_->sell_price < b->sell_->sell_price;
	}
	else
		return a->sell_->sell_price > b->sell_->sell_price;
}

bool base_price_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return a->base_->price < b->base_->price;
	}
	else
		return a->base_->price > b->base_->price;
}
bool pur_price_cmp(Node* a, Node* b, Compare mode)
{
	if (a == NULL)
	{
		return true;
	}
	if (mode == less)
	{
		return a->pur_->purchase_price < b->pur_->purchase_price;
	}
	else
		return a->pur_->purchase_price > b->pur_->purchase_price;

}

bool pur_sell_cmp(Node* a, Node* b, Compare mode)
{
	if (mode == less)
	{
		return a->pur_->purchase_price - a->sell_->sell_price < a->pur_->purchase_price - a->sell_->sell_price;
	}
	else
	{
		return a->pur_->purchase_price - a->sell_->sell_price > a->pur_->purchase_price - a->sell_->sell_price;
	}
}
Node* bub(Node* head, Compare mode, bool (*cmp)(Node* a, Node* b, Compare mod))
{
	if (head == NULL)
	{
		return head;
	}
	Node* o = head->next;
	Node* all = head->next;
	int count = getlength(head) + 1;
	while (count--)
	{
		for (; o->next != NULL; )
		{
			Node* temp = o->next;
			if (cmp(o, o->next, mode))
			{
				swap(o, o->next);
				continue;
			}
			o = o->next;
		}
		o = head->next;
	}
	return head;
}


Node* destruct_list(Node** head, Info cate)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node* p1 = (*head)->next;
	while (p1 != NULL)
	{
		Node* p2 = p1->next;
		free_node(&p1, cate);
		p1 = p2;
		if (p1 == NULL)
			break;
		p2 = p2->next;
	}
	free_node(head, VoidI);
	*head = NULL;
	head = NULL;
	return NULL;
}

void delete_menu(Node* head)
{
	while (1)
	{
		printf("0:return;\n\
1:input the id of the goods tobe deleted\n");
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			printf("which id t del\n");
			char s[50];
			scanf("%s", s);
			delete_node(head, s, AllI);
		}
	}
	return;
}
Node* delete_node(Node* head, char* id, Info cate)
{
	Node* p1 = head->next;
	while (p1 != NULL)
	{
		if (strcmp(p1->id, id) == 0)
		{
			Node* p2 = p1->next;
			if (p2 != NULL)
			{
				p2->prev = p1->prev;
			}
			p1->prev->next = p2;
			//删除当前节点再释放内部数据内存
			free_node(&p1, AllI);
			printf("删除成功\n");
			return head;
		}

		p1 = p1->next;
	}
	printf("不存在对应对象\n");
	return head;
}

Node* simple_find(Node* head)
{
	while (1)
	{
		bool non = 1;
		if (head == NULL)
		{
			return 0;
		}
		char s[100];
		Node* p1 = head->next;
		int operate;
		printf("选择操作：\n");
		printf("0:退出\n");
		printf("1.按名称查询\n");
		printf("2.按id查询\n");
		fscanf(stdin, "%d", &operate);

		if (operate == 1)
		{
			scanf("%s", s);
			while (p1 != NULL)
			{
				if (!strcmp(p1->name, s))
				{
					//show_base_info()
					non = 0;
					showone(p1);
				}
				p1 = p1->next;
			}
			if (non)
			{
				setcolor(FRED);
				printf("不存在对应商品,请重试\n");
				resetcolor();
			}
			return p1;
		}

		else if (operate == 2)
		{
			scanf("%s", s);
			while (p1 != NULL)
			{
				if (!strcmp(p1->id, s))
				{
					non = 0;
					showone(p1);
					return p1;
				}
				p1 = p1->next;
			}
			if (non)
			{
				setcolor(FRED);
				printf("不存在对应商品,请重试\n");
				resetcolor();
			}
			return 0;
		}
		else if (operate == 0)
		{
			return;
		}
		else
		{
			wa();
		}
	}
	return 0;
}



Node3* delete_list3(Node3* head)
{
	printf("请输入顾客姓名与手机号码\n");
	char s1[20], s2[20];
	scanf("%s %s", s1, s2);
	Node3* p = head->next;
	while (p != NULL)
	{
		if (!strcmp(p->cus_->cus_name, s1) && !strcmp(p->cus_->phone, s2))
		{
			if (p->next != NULL)
			{
				Node3* p2 = p->next;
				p2->prev = p->prev;
				p->prev->next = p2;
				//删除当前节点再释放内部数据内存
				free(p);
				printf("删除成功\n");
				return head;
			}
			else
			{
				p->prev->next = NULL;
				free(p);
				printf("删除成功\n");
				return head;
			}
		}
		p = p->next;
	}
	return head;
}
