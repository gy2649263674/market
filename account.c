#define	_CRT_SECURE_NO_WARNINGS
#include"sys.h"
#include"file.h"
#include"struct.h"
#include"all.h"
int wa(void);
//const char* const goods_file = "goods.txt";
//const char* const account_dir = "_account";
//const char* const goods_dir = "_goods";
//const char* const master_account = "master.txt";
//const char* const seller_account = "seller.txt";

//format 
// date : year month days 
int SAFE;
void purify()
{
	while (getchar() != '\n');//&& SAFE != EOF);

}

void showdir()
{
	char* s = malloc(100);
	getcwd(s, 256);
	printf("\n现在的工作目录%s\n", s);
	free(s);
	return;
}


bool repetive(Info identity, char* new_id)
{
	//const char* mode = "r";
	FILE* fp = open_info_file(identity, "r");
	char id[200] = { 0 };
	if (fp != NULL)
	{
		while (fscanf(fp, "%s", id) != EOF)
		{
			if (strcmp(id, new_id) == 0)
			{
				fclose(fp);
				return true;
			}
			else
			{
				fgets(id, 256, fp);
			}
		}
		fclose(fp);
	}
	else
	{
		perror("wrong dir");
	}
	return false;
}


char* trans_to_name(Info cate, char* s)
{
	if (cate == SellerI)
	{
		//return *s = "Seller\0";
		return strcpy(s, "打工人\0");
	}
	else if (cate == MasterI)
	{
		//return *s = "Master\0";
		return 	strcpy(s, "老板\0");
	}
	else if (cate == PurI)
	{
		return strcpy(s, "进货\0");
	}
	else if (cate == BaseI)
	{
		return strcpy(s, "基本\0");
	}
	if (cate == SellI)
	{
		return strcpy(s, "售后\0");
	}
	if (cate == CusI)
	{
		return strcpy(s, "顾客\0");
	}
	return s;
}


int getpass(char* password)
{
	memset(password, 0, sizeof(password));
	char* pa = password;
	char ch = 0;
	while (ch = getch())
	{
		if (ch == '\n' || ch == '\r')
		{
			return 0;
		}
		else
		{
			if (ch == '\b')
			{
				printf("\b \b");
				*--pa = '\0';
			}
			else//**
			{
				*pa++ = ch;
				printf("*");
			}
		}
	}
	pa = password;
	return 0;
}
void  Register(Info identity)
{
	printf("\t\t\t\t注册账户\n");
	purify();
	FILE* account = NULL;
	char user[20] = { "\0" };
	trans_to_name(identity, user);
	printf("\t\t\t\t\033[44m正在注册%s用户\033[0m\n", user);
	account = open_info_file(identity, "a+");
	while (1)
	{
		printf("请输入用户名(五位字符以上)\n");
		char s[40] = { 0 };
		char pass[20] = { 0 };
		char pass2[20] = { 0 };
		while (gets(s))
		{
			if (*s != '\0' && *s != '\n' && strlen(s) >= 5)
			{
				break;
			}
			else
			{
				printf("账户不符合规格\n");
				//purify();
			}
		}
		if (repetive(identity, s))
		{
			printf("该用户名已被注册\n");
			printf("如需退出请按0\n");
			printf("如需更改用户名请按1\n");
			int op = exam();
			if (op == 0)
			{
				return;
			}
			else if (op == 1)
			{
				continue;
			}

		}

		else
			while (1)
			{
				printf("请输入密码\n");
				getpass(pass);

				printf("请输入确认密码\n");
				getpass(pass2);
				if (strcmp(pass, pass2) == 0)
				{
					fprintf(account, "%s %s\n", s, pass);
					printf("注册成功\n");
					line(FFRED);
					system("pause");
					fclose(account);
					printf("如仍需注册请按:1,退出请按:0\n");
					int op = exam();
					if (op == 0)
					{
						fclose(account);
						return;
					}
					else
					{
						fflush(stdin);
						break;;
					}
				}
				else
				{
					printf("前后密码不一致\n\
							请重新输入\n:");
					printf("0:退出\n");
					printf("1:更改密码\n");
					printf("2:需改用户名\n");
					int op1 = exam();
					if (op1 == 1)
					{
						purify();
						continue;
					}
					else if (op1 == 0)
					{
						return;
					}
					else if (op1 == 2)
					{
						break;
					}
					system("cls");
					printf("账户名 %s\n", s);
				}
			}
	}
	fclose(account);
	return;
}

bool login(Info iden, char* now_account)
{
	showdir();
	char s[20];
	trans_to_name(iden, s);
	while (1)
	{
		char exist[20];//存在的账户
		FILE* fp = NULL;
		fp = open_info_file(iden, "r");
		printf("\033[36m-------------------------欢迎!  %s---------------------------------------------\033[0m\n", s);
		if (fp == NULL)
		{
			printf("尚未注册过%s用户,请退出\n", s);
			return false;
		}
		printf("请输入用户名(五位以上)\n");
		char account[64] = { 0 };
		while (gets(account))
		{
			if (*account != '\0' && *account != '\n' && strlen(account) >= 5)
			{
				break;
			}
			else
			{
				printf("账户不符合规格\n");
			}
		}
		printf("请输入密码\n");
		char password[200] = { 0 };
		getpass(password);
		bool flag = 0;
		while (fscanf(fp, "%s", exist) != EOF)
		{
			char rightpass[20];
			fscanf(fp, "%s", rightpass);
			if (strcmp(account, exist) == 0)//找到账户
			{
				flag = 1;
				while (1)
				{
					if (strcmp(password, rightpass) == 0)
					{
						strcpy(now_account, account);
						printf("登录成功 %s用户：\n%s", s, exist);
						fclose(fp);
						return true;
					}
					else
					{
						printf("密码错误\n");
						printf("0:如需退出请按\n");
						printf("1:更改账户\n");
						printf("2:重新输入\n");
						int op1 = exam();
						if (op1 == 0)
						{
							return false;
						}
						else if (op1 == 1)
						{
							purify();
							fflush(stdin);
							break;
						}
						else if (op1 == 2)
						{
							purify();
							getpass(password);
							continue;
						}
					}
				}
			}
		}
		if (flag == 0)
		{
			printf("没有对应用户，请检查用户名是否正确~\n");
			printf("0:如需退出请按\n1:任意键重试\n");
			int op2 = exam();
			if (op2 == 0)
			{
				return false;
			}
			else if (op2 == 1)
			{
				fclose(fp);
				continue;
			}
		}
	}
	return false;

}

bool  resetsystem()
{

	printf("请输入验证码\n");
	char* s = calloc(0, 20 * sizeof(char));
	//char s[20] = {0};
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		*s = rand() % 26 + 'A';
		printf("%c", *s++);
	}
	printf("\n");
	char cin[20];
	scanf("%s", cin);
	if (strcmp(cin, s - 6) == 0)
	{
		char path[255] = { 0 };
		char command[255] = { 0 };
		getcwd(path, 255);
		sprintf(command, "rd /s  %s\\%s", path, GOODS_DIR);
		getcwd(path, 255);
		system(command);
		strcpy(command, "\0");
		sprintf(command, "rd /s  %s\\%s", path, ACCOUNT_DIR);
		system(command);
	}
	else
	{
		printf("验证码错误,请重试");
		return 0;
	}
	int total = 10;
	srand(time(NULL));
	for (int i = 0; i < total; i++)
	{
		printf("\033[%dm%d\n", rand() % 6 + 30, total - i);
		Sleep(200);
	}
	printf("即将退出系统\n");
	return 1;
}
Node* record_seller_info(Node* hist, Info cate, bool to_txt, bool to_screen);

Node* acc_list()
{
	FILE* history = open_info_file(AccI, "w+");
	Node* his = init_list();
	char name[20];
	char id[20];
	while (fscanf(history, "%s%s", name, id) != EOF)
	{
		push_head(his);
		*his->next->name = *name;
		*his->next->name = *id;
	}
	fclose(history);
	return his;
}
void get_seller_info(Node* Acchead)
{
	if (Acchead == NULL)
	{
		Acchead = init_list();
	}
	FILE* in = NULL;
	char path[256] = { 0 };
	char ok[256] = { 0 };
	Node* seller = Acchead;
	printf("please copy the path of the sellers\n");
	scanf("%s", path);
	stdlize(path, ok);
	in = fopen(ok, "r");
	if (in == NULL);
		return;
	while (fscanf(in, "%s%s", path, ok) != EOF)
	{
		if (repetive(SellerI, path) == false)
		{
			push_head(seller);
			strcpy(seller->next->name, path);
			strcpy(seller->next->id, ok);
		}
		else
		{
			continue;
		}
	}
	printf("已成功导入信息\n");
	//record_seller_info(seller, SellerI, true, false);
	//destruct_list(seller, VoidI);
	return;
}
Node* record_seller_info(Node* hist, Info cate, bool to_txt, bool to_screen)
{
	FILE* out;
	if (hist == NULL || hist->next == NULL)
	{
		printf("暂无员工信息\n");
		return 0;
	}
	else
	{
		FILE* out = NULL;
		if (to_txt == true)
		{
			out = open_info_file(cate, "w+");
			if (out == NULL)
			{
				return 0;
			}
		}
		Node* temp = hist->next;
		if (to_screen == true)
		{
			printf("\033[46m账户信息\033[0m\n");
			printf("\033[36m账户\t\t   密码\033[0m\n");
		}
		while (temp)
		{
			if (to_screen == true)
			{
				fprintf(stdout, "%-20s%-20s\n", temp->name, temp->id);
			}
			if (to_txt == true)
			{
				fprintf(out, "%-20s\t%-20s\n", temp->name, temp->id);
			}
			temp = temp->next;
		}
		if (out != NULL)
		{
			fclose(out);
		}
	}
	return 0;
}

/*
bool deled = false;
FILE* in = open_info_file(SellerI, "r");
if (in == 0)
{
	perror("");
}
char get_name[20];
char get_pass[20];
while (fscanf(in, "%s%s", get_name, get_pass) != EOF)
{
	if (*get_name == '\n')
	{
		continue;
	}
	if (strcpy(get_name, name) == 0)
	{
		continue;
		deled = true;
	}
	push_head(Acchead);
	strcpy(Acchead->next->name, get_name);
	strcpy(Acchead->next->id, get_pass);
*/

Node* delete_acc(Node* head);
Node* resetACC(Node* head);
Node* creat_acc_list(Node* Acchead, Info cate);

bool  MainTainSys(Node* head)
{

	setcolor(FRED);
	printf("\a\a\apay attention \n you are manage you sys pleae operate care fullly \n");
	resetcolor();
	//Node* Acchead = init_list();
	Node* Acchead = init_list();
	Acchead = creat_acc_list(Acchead, SellerI);
	while (1)
	{
		printf("0:exit\n\
1:删除员工账户\n\
2:批量导入员工账号\n\
3:查看员工信息\n\
4:存档\n\
5:恢复数据\n\
7:重置员工密码\
\033[31m6:重置系统,(注意,这会删除所有信息)\033[0m\n");
		int op = exam();
		if (op == 0)
		{
			record_seller_info(Acchead, SellerI, true, false);
			destruct_list(&Acchead, VoidI);
			return 0;
		}
		else if (op == 7)
		{
			resetACC(Acchead);
		}

		else if (op == 1)
		{
			delete_acc(Acchead);
		}
		else if (op == 6)
		{
			if (resetsystem())
			{
				return 1;
			}
		}
		else if (op == 3)
		{
			record_seller_info(Acchead, SellerI, false, true);
		}
		else if (op == 2)
		{
			get_seller_info(Acchead);
		}
		else if (op == 4)
		{
			copy_file(1);
		}
		else if (op == 5)
		{
			copy_file(2);
			destruct_list(&head, AllI);
			if (head == NULL)
			{
				head = get_base_info(NULL, 0);
				get_purchase_info(head, 0);
				get_sell_info(head, 0);
			}
		}
	}
	free_node(&Acchead, VoidI);
	return false;
}


//删除账户
Node* delete_acc(Node* head)
{
	if (head == NULL)
	{
		return 0;
	}
	printf("请输入想要删除的员工姓名\n");
	char name[20];
	scanf("%s", name);
	Node* p = head->next;
	bool ex = false;
	while (p != NULL)
	{
		if (!strcmp(p->name, name))
		{
			Node* nex = p->next;
			Node* pre = p->prev;
			if (nex)
			{
				nex->prev = pre;
			}
			if (pre)
			{
				pre->next = nex;
			}
			free_node(&p, VoidI);
			printf("删除成功\n");
			return;
		}
		if (p)
		{
			p = p->next;
		}
		else
		{
			return 0;
		}
	}
	if (ex == false)
	{
		printf("无对应员工\n");
	}
	return head;

}

//重置密码
Node* resetACC(Node* head)
{
	if (head == NULL)
	{
		return 0;
	}
	else if (head->next == NULL)
	{
		creat_acc_list(head, SellerI);
	}
	printf("输入将要重置密码的员工姓名\n");
	char s[20];
	char id[20];
	scanf("%s", s);
	Node* p = head->next;
	while (p != NULL)
	{
		if (!strcmp(p->name, s))
		{
			printf("请输入修改后的密码\n");
			scanf("%s", id);
			strcpy(p->id, id);
			printf("修改成功\n");
		}
		p = p->next;
	}
	return head;
}

Node* creat_acc_list(Node* Acchead, Info cate)
{
	if (Acchead == NULL)
	{
		Acchead = init_list();
	}
	FILE* in = open_info_file(cate, "r");
	if (in == 0)
	{
		perror("");
		return 0;
	}
	char get_name[20];
	char get_pass[20];
	while (fscanf(in, "%s%s", get_name, get_pass) != EOF)
	{
		push_head(Acchead);
		strcpy(Acchead->next->name, get_name);
		strcpy(Acchead->next->id, get_pass);
	}
	fclose(in);
	return Acchead;
}
void reset_pass_word(Info cate, char* s)
{
	Node* sellhead = NULL;
	sellhead = creat_acc_list(sellhead, cate);
	if (sellhead == NULL)
	{
		return;
	}
	Node* p = sellhead->next;
	bool ex = false;
	char id[55];
	while (p != NULL)
	{
		if (!strcmp(p->name, s))
		{
			ex = true;
			while (1)
			{
				printf("请输入原密码\n");
				char pass[20];
				scanf("%s", pass);
				if (strcmp(pass, p->id) == 0)
				{
					printf("请输入修改后的密码\n");
					scanf("%s", id);
					strcpy(p->id, id);
					printf("修改成功\n");
					record_seller_info(sellhead, cate, true, false);
					destruct_list(&sellhead, VoidI);
					return;
				}
				else
				{
					printf("原密码输入错误，请重试\n");
					printf("0:退出\n");
					printf("1:重试\n");
					int op = exam();
					if (op == 0)
					{
						return;
					}
					else if (op == 1)
					{
						continue;
					}
					else
					{
						wa();
					}
				}
			}
		}
		p = p->next;
	}

	if (ex == false)
	{
		record_seller_info(sellhead, cate, true, false);
		destruct_list(&sellhead, VoidI);
		// printf("")
	}
	return;

}