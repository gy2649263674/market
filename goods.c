#define _CRT_SECURE_NO_WARNINGS
#include"all.h"

#define SCREEN true


int wa()
{
	purify();
	setcolor(FRED);
	printf("wrong command retry please\n");
	if (errno != 0)
	{
		perror(" ");
	}
	resetcolor();
	return 1;
}

int exam()
{
	int op = -1;
	scanf("%d", &op);
	if (op == -1)
	{
		wa();
		//purify();
		return op;
	}
	return op;
}
Node* record_base_info(Node* head, bool to_std)
{
	if (head == NULL)
	{
		printf("head is empty\n");
		return  0;
	}
	FILE* out;
	Node* o = head->next;
	if (to_std == true)
	{

		base_prompt();
		if (o == NULL)
		{
			setcolor(FCYAN);
			printf("暂无相应信息\n");
			resetcolor();
			return;
		}
		out = stdout;
	}
	else
	{
		showdir();
		out = open_info_file(BaseI, "w");
	}
	if (out == NULL)
	{
		printf("file open fail to record_base_info\n");
		return 0;
	}

	while (o != NULL)
	{
		Node* next_node = o->next;
		Base* temp = o->base_;
		if (temp != NULL)
		{
			fprintf(out, "%-15s", temp->type);
			fprintf(out, "%-10s\t ", temp->producer);
			fprintf(out, "%-10s\t ", temp->desciption);
			fprintf(out, "%.2lf\t\t %.2lf\t\t", temp->price, temp->sale);
			fprintf(out, "%-20s\t%08s\t\n", o->name, o->id);
		}
		o = next_node;
	}
	if (out != stdout)
	{
		fclose(out);
		printf("基础信息导入成功\n");
	}
	if (out == stdout)
	{
		line(FFRED);
	}
	//printf("\n");
	return head;
}


Node* record_sell_info(Node* head, bool to_std)
{
	if (head == NULL)
	{
		printf("head is empty\n");
		return 0;
	}
	FILE* out;
	Node* o = head->next;
	if (to_std == true)
	{
		sell_prompt();
		if (o == NULL)
		{
			setcolor(FCYAN);
			printf("暂无相应信息\n\033[0m");
			return 0;
		}

		out = stdout;
	}
	else
	{
		showdir();
		out = open_info_file(SellI, "w+");
	}
	if (out == NULL)
	{
		printf("file open fail to record_sell_info\n");
		return 0;
	}


	while (o != NULL)
	{
		Node* next_node = o->next;
		Sell* temp = o->sell_;
		if (to_std == SCREEN && temp == NULL)
		{
			printf("尚未售出\t\t\t");
			fprintf(out, "\t\t\t\t\t\t%-18s\t%08s\n", o->name, o->id);
		}
		if (temp != NULL)
		{
			fprintf(out, "%-8d%-8d%-8d ", temp->sell_date.year, temp->sell_date.month, temp->sell_date.day);
			fprintf(out, "%-8s\t\t ", temp->customer_name);
			fprintf(out, "%08s ", temp->customer_id);
			fprintf(out, "\t\t%.2lf\t\t%d\t\t\t", temp->sell_price, temp->sell_volume);
			fprintf(out, "%-15s\t\t%-08s\n", o->name, o->id);
		}
		o = next_node;
	}
	if (out != stdout)
	{
		fclose(out);
		printf("售卖信息导入成功\n");
	}
	if (out == stdout)
	{
		line(FFRED);
	}
	printf("\n");
	resetcolor();
	return head;
}


Node* record_purchase_info(Node* head, bool to_std)
{
	if (head == NULL)
	{
		printf("head is empty\n  record_purchase_info");
		return  0;
	}
	FILE* out = NULL;
	Node* o = head->next;
	if (to_std == true)
	{
		out = stdout;
		purchase_prompt();
		if (o == NULL)
		{
			setcolor(FCYAN);
			printf("暂无相应信息\n");
			resetcolor();
			return;
		}
	}
	else
	{
		showdir();
		out = open_info_file(PurI, "w+");
	}
	if (out == NULL)
	{
		printf("file open fail to record_base_info\n");
		return 0;
	}
	while (o != NULL)
	{
		Node* next_node = o->next;
		Purchase* temp = o->pur_;
		if (temp != NULL)
		{
			fprintf(out, "%-8d%-8d%-8d", temp->purchase_date.year, temp->purchase_date.month, temp->purchase_date.day);
			fprintf(out, " %s\t", temp->purchase_channel);
			fprintf(out, "%-6.2lf\t\t%-6d\t\t", temp->purchase_price, temp->purchase_size);
			fprintf(out, "%-18s\t%08s\n", o->name, o->id);
		}
		else
		{
			printf("尚未导入进货信息");
			fprintf(out, "\t\t\t\t\t\t\t\t%-18s\t%08s\n", o->name, o->id);
		}
		o = next_node;
	}
	if (out != stdout)
	{
		fclose(out);
		printf("购买信息保存成功\n");
	}
	if (out == stdout)
	{
		line(FFRED);
	}
	printf("\n");
	return head;
}

void show_purchase_info(Node* node)
{
	if (node == NULL)
	{
		setcolor(FCYAN);
		printf("暂无相应信息\n");
		resetcolor();
		return;
		return;
	}
	purchase_prompt();
	FILE* out = stdout;
	Purchase* temp = node->pur_;
	if (temp != NULL)
	{
		fprintf(out, "%-8d%-8d%-8d", temp->purchase_date.year, temp->purchase_date.month, temp->purchase_date.day);
		fprintf(out, " %s\t", temp->purchase_channel);
		fprintf(out, "%.2lf\t\t%d\t\t", temp->purchase_price, temp->purchase_size);
		fprintf(out, "%-15s\t\t%-08s\n", node->name, node->id);

	}
	else
	{

		fprintf(out, "\t\t\t\t%-15s\t\t%-08s\n", node->name, node->id);
		//fprintf(out, "%-18s\t%08s\n", node->name, node->id);
		printf("暂无相应信息\n");
	}
}

Node3* load3(Node3* node, void* data, Info cate)
{
	if (node == NULL)
	{
		return 0;
	}
	if (cate == CusI)
		node->cus_ = PURINFO(data);
	return node;
}

void modify_type(Node* head)
{
	Node* last = NULL;
	while (1)
	{
		if (head == NULL)
		{
			printf("无信息,请确认已导入过信息\n");
		}
		else
		{		//wa();
			printf("\
0:返回:\n\
1:更改售价\n\
2:更改商品类型\n\
3:更改折扣\n\
4:更改商品名称\n\
5:更改进货渠道\n\
6.更改进货价格\n\
7.更改进货数量\n\
8:查看修改后商品信息\n\
9:查看所有商品信息\n\n\
");
			int op = exam();

			if (op == -1)
			{
				continue;
			}
			else if (op == 0)
			{
				return;
			}
			else if (op == 1)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改售价为:\n");
				double newprice;
				scanf("%lf", &newprice);
				last = change_data(head, goods_name, &newprice, priceC);
			}
			else if (op == 2)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改类型为:\n");
				char newname[20];
				scanf("%s", newname);
				last = change_data(head, goods_name, newname, typeC);
			}
			else if (op == 3)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改折扣为:\n");
				double newsale;
				scanf("%lf", &newsale);
				last = change_data(head, goods_name, &newsale, saleC);
			}
			else if (op == 4)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改新名称为:\n");
				char newname[20];
				scanf("%s", newname);
				last = change_data(head, goods_name, newname, nameC);
			}
			else if (op == 5)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改进货渠道为:\n");
				char newchannel[20];
				scanf("%s", newchannel);
				last = change_data(head, goods_name, newchannel, purchase_channelC);
			}
			else if (op == 6)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改进货价格为:\n");
				double newpri;
				scanf("%lf", &newpri);
				last = change_data(head, goods_name, &newpri, purchase_priceC);
			}
			else if (op == 7)
			{
				printf("请输入商品id\n");
				char goods_name[100];
				scanf("%s", goods_name);
				printf("更改进货数量为:\n");
				int newsize;
				scanf("%d", &newsize);
				last = change_data(head, goods_name, newsize, purchase_sizeC);
			}
			else if (op == 8)
			{
				showone(last);
			}
			else if (op == 9)
			{
				check_info(head);
			}

		}

	}

}

Node* same_name(Node* last, char* s)
{
	if (last == NULL)
	{
		return NULL;
	}
	Node* ne = last->next;
	while (ne)
	{
		if (strcmp(ne->name, s) == 0)
		{
			return ne;
		}
		ne = ne->next;
	}
	return NULL;
}
Node* change_data(Node* head, char* name, void* newdata, info_change op)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node* temp = accurate_find(head, name);///same_name(head, name);
	if (temp)
	{
		if (op == priceC)
		{
			temp->base_->price = *((double*)newdata);
			temp->sell_->sell_price = *DOUBLE(newdata);
		}
		else if (op == saleC)
		{
			temp->base_->sale = *DOUBLE(newdata);
		}
		else if (op == typeC)
		{
			strcpy(temp->base_->type, newdata);
			//*temp->base_->type = *CHAR(newdata);
		}
		else if (op == purchase_channelC)
		{
			strcpy(temp->pur_->purchase_channel, newdata);
			//*temp->pur_->purchase_channel = *CHAR(newdata);
		}
		else if (op == nameC)
		{
			strcpy(temp->name, newdata);
			//*temp->name = *CHAR(newdata);
		}
		else if (op == purchase_priceC)
		{
			temp->pur_->purchase_price = *DOUBLE(newdata);
		}
		else if (op == purchase_sizeC)
		{
			temp->pur_->purchase_size = INT(newdata);
		}
	}
	else {
		printf("未找到对应商品，请检查id\n");
	}
	return temp;
}


void show_sell_info(Node* node)
{
	if (node == NULL)
	{
		setcolor(FCYAN);
		printf("暂无相应信息\n");
		resetcolor();
		return;
	}
	sell_prompt();
	FILE* out = stdout;
	Sell* temp = node->sell_;
	if (temp != NULL)
	{
		fprintf(out, "%-8d%-8d%-8d ", temp->sell_date.year, temp->sell_date.month, temp->sell_date.day);
		fprintf(out, "%-8s\t\t ", temp->customer_name);
		fprintf(out, "%08s ", temp->customer_id);
		fprintf(out, "\t\t%.2lf\t\t%d\t\t\t", temp->sell_price, temp->sell_volume);
		fprintf(out, "%-15s\t\t%-08s\n", node->name, node->id);

	}
	else
	{
		fprintf(out, "%-15s\t\t%-08s\n", node->name, node->id);
		printf("暂未售出\n");
	}
}
void show_base_info(Node* node)
{
	if (node == NULL)
	{
		setcolor(FCYAN);
		printf("暂无相应信息\n");
		resetcolor();
		return;
	}
	base_prompt();
	//printf("\n\033[46m基础信息\033[0m\n");
	FILE* out = stdout;
	Base* temp = node->base_;
	if (temp == NULL)
	{
		printf("无对应信息\n");
		return;
	}
	fprintf(out, "%-15s", temp->type);
	fprintf(out, "%-10s\t ", temp->producer);
	fprintf(out, "%-10s\t ", temp->desciption);
	fprintf(out, "%.2lf\t\t %.2lf\t\t", temp->price, temp->sale);
	fprintf(out, "%-20s\t%08s\t\n", node->name, node->id);
}



void showone(Node* node)
{
	if (node == NULL)
	{
		printf("没有对应商品,请检查是否有误\n");
		return;
	}
	show_base_info(node);
	line(FBLUE);
	show_purchase_info(node);
	line(FBLUE);
	show_sell_info(node);
	line(FFRED);
	//printf("\033[34m--------------------------------------------------------------------------\033[0m\n");
	return;
}




Node* load(Node* node, void* data, Info cate)
{
	if (node == NULL)
	{
		return 0;
	}
	if (cate == BaseI)
	{
		node->base_ = BASEINFO(data);
	}
	else if (cate == SellI)
	{
		node->sell_ = SELLINFO(data);
	}
	else if (cate == PurI)
	{
		node->pur_ = PURINFO(data);
	}
	/*else if (cate == AccI)
	{
		node->acc_ = ACC(data);
	}*/
	return node;
}

FILE* getpath(Info cate)
{
	char ou[20];
	trans_to_name(cate, ou);
	FILE* in = NULL;
	while (1)
	{
		/*printf("尚未导入过BaseI 信息\n\
		请输入路径导入数据");*/
		purify();
		printf("请输入%s信息路径\n", ou);
		char s[256] = { '\0' };
		char s2[256] = { '\0' };
		//purify();
		gets(s);
		if (strcmp(s, "0") == 0)
		{
			return NULL;
		}
		stdlize(s, s2);
		in = fopen(s2, "r");
		if (in != NULL)
		{
			return in;
		}
		printf("路径有误\n");
		printf("retry please or enter 0 to return \n");
	}
	return in;
}

Node* get_base_info(Node* exist_info, bool add)
{
	FILE* in = NULL;
	if (add)
	{
		printf("\033[46m正在导入基本信息\033[0m\n");
		printf("1-手动\\2-粘贴路径\n");
		int op = exam();
		//scanf("%d", &op);
		if (op == 2)
		{
			in = getpath(BaseI);
			if (in == NULL && add == false)
			{
				return 0;
			}
			else if (in)
			{
				printf("路径获取成功\n");
			}
		}
		else if (op == 1)
		{
			printf("手动输入ctrl+z停止录入");
			in = stdin;
		}
		else
		{
			purify();
		}

	}
	else
	{
		in = open_info_file(BaseI, "r");
	}
	Node* head = NULL;
	if (add == true || exist_info != NULL)
	{
		head = exist_info;
	}
	else
	{
		head = init_list();
	}
	Base* temp = malloc(sizeof(Base));
	if (add && in == stdin)
	{
		base_prompt();
	}
	else if (in == NULL)
	{
		return head;
	}
	while (fscanf(in, "%s", temp->type) != EOF)
	{
		fscanf(in, "%s%s", temp->producer, temp->desciption);
		fscanf(in, "%lf%lf", &(temp->price), &(temp->sale));
		load(push_head(head)->next, temp, BaseI);
		fscanf(in, "%s%08s", &head->next->name, &head->next->id);
		temp = malloc(sizeof(Base));
	}
	free(temp);
	if (in != stdin)
	{
		fclose(in);
	}
	if (add)
		printf("import base info sueesssfully\n");
	return head;

}
Node* get_purchase_info(Node* basehead, bool add)
{
	FILE* in = NULL;
	if (add)
	{
		printf("\t\t\t\t\033[46m import purchase info\033[0m\n");
		printf("1-手动\\2-粘贴路径\n");
		int op = exam();
		purify();
		if (op == 2)
		{
			in = getpath(PurI);
			if (in == NULL && add == false)
			{
				return 0;
			}
			else if (in != NULL)
			{
				printf("路径获取成功");
			}
		}
		else if (op == 1)
		{
			printf("手动输入ctrl+z停止录入");
			in = stdin;
		}
	}
	else
	{
		in = open_info_file(PurI, "r");
	}
	if (in == NULL)
	{
		return basehead;
	}
	Node* head = NULL;
	if (add == true || basehead != NULL)
	{
		head = basehead;
	}
	if (basehead == NULL)
	{
		head = init_list();
	}
	Purchase* temp = malloc(sizeof(Purchase));
	if (add == 1 && in == stdin)
	{
		purchase_prompt();
	}
	while (fscanf(in, "%d", &temp->purchase_date.year) != EOF)
	{
		fscanf(in, "%d%d", &temp->purchase_date.month, &temp->purchase_date.day);
		fscanf(in, "%s", temp->purchase_channel);
		fscanf(in, "%lf%d", &temp->purchase_price, &temp->purchase_size);
		char ID[20];
		char name[20];
		fscanf(in, "%s%08s", name, ID);
		load(accurate_find(head, ID), temp, PurI);
		temp = malloc(sizeof(Purchase));
		//ffush(stdin);
		//ffush();
		//purify();
		//purify();
	}
	free(temp);
	if (in != stdin)
	{
		fclose(in);
	}
	return basehead;
}

Node* accurate_find(Node* head, const char* ID)
{
	Node* p1 = head->next;
	while (p1 != NULL)
	{
		if (!strcmp(p1->id, ID))
		{
			return p1;
		}
		p1 = p1->next;
	}
	return NULL;
}

Node* get_sell_info(Node* head, bool add)
{
	FILE* in = NULL;

	if (add)
	{
		printf("正在导入出售信息\n");
		printf("1-手动\\2-粘贴路径\n");
		int op = exam();
		if (op == 2)
		{
			in = getpath(SellI);
			if (in == NULL && add == false)
			{
				//printf("no record");
				return 0;
			}
		}
		else if (op == 1)
		{
			printf("手动输入ctrl+z停止录入");
			in = stdin;
		}
		else
		{
			purify();
		}
	}
	else
	{

		in = open_info_file(SellI, "r");
	}
	if (in == NULL)
	{
		return head;
	}
	Sell* temp = malloc(sizeof(Sell));
	while (fscanf(in, "%d", &(temp->sell_date.year)) != EOF)
	{
		char id[20];
		char name[20];
		fscanf(in, "%d%d", &(temp->sell_date.month), &(temp->sell_date.day));
		fscanf(in, "%s%s", &temp->customer_name, &temp->customer_id);
		fscanf(in, "%lf%d", &temp->sell_price, &temp->sell_volume);
		fscanf(in, "%s%08s", name, id);
		load(accurate_find(head, id), temp, SellI);
		temp = malloc(sizeof(Sell));
		//purify();
	}
	free(temp);
	if (in != stdin)
	{
		fclose(in);
	}
	if (add)
	{
		printf("import successfully\n");
	}
	return head;
}

void check_info(Node* head)
{
	while (1)
	{
		printf("0:exit\n\
1:商品基本信息\n\
2:进货信息\n\
3:出售信息\n\
4:我全都要\n");
		int op = exam();
		if (op == -1)
		{
			wa();
		}
		if (op == 0)
		{
			return;
		}
		if (op == 1 || op == 4)
		{
			record_base_info(head, SCREEN);
		}
		if (op == 2 || op == 4)
		{
			record_purchase_info(head, SCREEN);
		}
		if (op == 3 || op == 4)
		{
			record_sell_info(head, SCREEN);
		}

	}
	return;
}
bool name_id_cmp(Node* a, Node* b, Compare mod)
{
	if (a && b)
		if (mod == less)
		{
			if (strcmp(a->name, b->name) == 0)
			{
				return id_cmp(a, b, less);
			}
			else
			{
				return id_cmp(a, b, less);
			}
		}
		else
		{
			return name_id_cmp(b, a, less);
		}
}
bool base_sell_price_cmp(Node* a, Node* b, Compare mod)
{
	if (a && b)
		if (mod == less)
		{
			if (a->base_->price == b->base_->price)
			{
				return sell_price_cmp(a, b, less);
			}
			else
			{
				return base_price_cmp(a, b, less);
			}
		}
		else
		{
			return base_sell_price_cmp(b, a, less);
		}
	return false;

}
bool pur_vol_price_cmp(Node* a, Node* b, Compare mod)
{
	if (a && b)
		if (mod == less)
		{
			if (a->pur_ && b->pur_)
			{
				if (a->pur_->purchase_size == a->pur_->purchase_size)
				{
					return pur_vol_cmp(a, b, mod);
				}
				else
				{
					return pur_price_cmp(a, b, mod);
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return pur_vol_price_cmp(b, a, less);
		}
	return false;
}
//less->shengxu
void multi_sort(Node* head)
{
	Compare mod = greater;;
	while (1)
	{
		printf("当前按\033[46m%s\033[0m\n", mod == less ? "降序" : "升序");
		printf("请选择:\n\
0:退出\n\
1:更改顺序\n\
2:查看当前信息\n\
");
		printf("\
3:按id&&name\n\
4:按标价&&售价\n\
5:按进货数量&&进货价格:\n");
		int op0 = exam();
		if (op0 == 0)
		{
			return;
		}
		else if (op0 == 2)
		{
			check_info(head);
		}
		else if (op0 == 1)
		{
			mod = mod == less ? greater : less;
			printf("已改变顺序,当前是\033[46m%s\033[0m\n", mod == less ? "降序" : "升序");
			continue;
		}
		else if (op0 == 3)
		{
			bub(head, mod, name_id_cmp);
		}
		else if (op0 == 4)
		{
			bub(head, mod, base_sell_price_cmp);
		}
		else if (op0 == 5)
		{
			bub(head, mod, pur_vol_price_cmp);
		}
		printf("1:如需查看信息请按\n\
0:如需重新排序请按\n\
任意键:结束操作\n");
		int key = exam();
		if (key == 1)
		{
			check_info(head);
		}
		else if (key == 0)
		{
			continue;
		}
		else
		{
			wa();
		}
	}
}
void singlesort(Node* head)
{
	Compare mod = greater;;
	while (1)
	{
		//printf("当前按\033[46m%s\033[0m\n", mod == less ? "" : "降序");
		printf("当前是\033[46m%s\033[0m\n", mod == less ? "降序" : "升序");
		printf("请选择:\n\
0:退出\n\
1:按id\n\
2:按name\n\
3:按标价\n\
4:按进货价格\n\
5:按成交价格排序\n\
6:按进货数量:\n\
7:更改为默认排列顺序\n\
8:查看当前信息\n\
");
		int op = exam();
		//scanf("%d", &op);
		if (op == 1)
		{
			bub(head, mod, id_cmp);
		}
		else if (op == 2)
		{
			bub(head, mod, name_cmp);
		}
		else if (op == 3)
		{
			bub(head, mod, base_price_cmp);
		}
		else if (op == 4)
		{
			bub(head, mod, pur_price_cmp);
		}
		else if (op == 5)
		{
			bub(head, mod, sell_price_cmp);
		}
		else if (op == 6)
		{
			bub(head, mod, pur_vol_cmp);
		}
		else if (op == 7)
		{

			mod = mod == less ? greater : less;
			printf("已改变顺序,当前是\033[46m%s\033[0m\n", mod == less ? "降序" : "升序");
			continue;
		}
		else if (op == 8)
		{
			check_info(head);
			continue;
		}
		else if (op == 0)
		{
			return;
		}
		else
		{
			wa();
			continue;
		}
		printf("1:如需查看信息请按\n\
0:如需重新排序请按\n\
任意键:结束操作\n");
		int key = 0;
		scanf("%d", &key);
		if (key == 1)
		{
			check_info(head);
		}
		else if (key == 0)
		{
			continue;
		}
		else
		{
			purify();
			return;
		}
	}
}


void add_info(Node* head)
{
	////head = push_head(Node * head);
	while (1)
	{
		printf("\t\t\t\t\033[46mimporting info\033[0m\n");
		printf("0:return\n\
1:baseinfo\n\
2:purchase_info()\n\
3:sell_info\n");
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			get_base_info(head, true);
		}
		else if (op == 2)
		{
			get_purchase_info(head, true);
		}
		else if (op == 3)
		{
			get_sell_info(head, true);
		}
		else
		{
			continue;
		}
	}
	return;
}

Node3* modify_cus(Node3* head)
{
	int ope;
	printf("选择修改的信息\n");
	printf("1.修改顾客联系方式\n");
	printf("2.修改顾客星级\n");
	scanf("%d", &ope);
	if (ope == 1)
	{
		printf("输入姓名\n");
		printf("输入原来的联系方式\n");
		Node3* p = head->next;
		char name[20];
		char phone[20];
		scanf("%s %s", name, phone);
		while (p != NULL)
		{
			if (!strcmp(p->cus_->cus_name, name) && !strcmp(phone, p->cus_->phone))
			{
				printf("输入更改后联系方式\n");
				scanf("%s", phone);
				strcpy(p->cus_->phone, phone);
				return head;
			}
			p = p->next;
		}
	}
	else if (ope == 2)
	{
		printf("输入姓名\n");
		printf("输入联系方式\n");
		Node3* p = head->next;
		char name[20];
		char phone[20];
		scanf("%s %s", name, phone);
		while (p != NULL)
		{
			if (!strcmp(p->cus_->cus_name, name) && !strcmp(phone, p->cus_->phone))
			{
				printf("输入调整后的星级\n");
				int n;
				scanf("%d", &n);
				p->cus_->vip = n;
				return head;
			}
			p = p->next;
		}
	}
	return head;
}

Node3* get_cus_info(Node3* exist_info, bool add)
{
	FILE* in = NULL;

	if (add)
	{
		printf("正在导入顾客信息\n");
		printf("1-手动\\2-粘贴路径\n");
		int op = exam();
		if (op == 2)
		{
			in = getpath(CusI);
			if (in == NULL && add == true)
			{
				//printf("no record");
				return 0;
			}
		}
		else if (op == 1)
		{
			printf("手动输入ctrl+z停止录入");
			in = stdin;
		}
		else
		{
			purify();
		}

	}
	else
	{
		in = open_info_file(CusI, "r");
	}
	Node3* head = NULL;
	if (add == true || exist_info != NULL)
	{
		head = exist_info;
	}
	else
	{
		head = init_list3();
	}
	Customer* temp = malloc(sizeof(Customer));
	if (add && in == stdin)
	{
		cus_prompt();
	}
	else if (in == NULL)
	{
		return head;
	}
	while (fscanf(in, "%d", &temp->vip) != EOF)
	{
		/*if (safe == EOF)
		{
			return 0;
		}*/
		fscanf(in, "%s%s", temp->cus_name, temp->phone);
		load3(push_head3(head)->next, temp, CusI);
		temp = malloc(sizeof(Customer));
	}
	free(temp);
	if (in != stdin)
	{
		fclose(in);
	}
	if (add)
		printf("import customer info sueesssfully\n");
	return head;

}


void add_cus(Node3* head)
{
	printf("请导入顾客信息\n");
	get_cus_info(head, true);
	return;
}
void single_info_staAAA(Node* head)
{
	while (1)
	{
		printf("0:return\n\
1:price:\n\
2:type\n");
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			price_sta(head);
		}
		else if (op == 2)
		{
			type_sta(head);
		}
	}
	return;
}