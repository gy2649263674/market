//#define _CRT_SECURE_NO_WARNINGS 
//
//#include"all.h"
//
////int (*p)(int, int);
////void(*menu_stack[1000])() = { NULL };
////void(*ptr)();
//void me_2();
//void seller_menu();
//void menu();
//void show_progress_bar()
//{
//	int total =100;
//	srand(time(0));
//	char s3[] = "=======================================================================================================================================================================================================================================================================================================================================================================================================================================================================";
//	char s4[] = "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
//	for (int i = 0; i < total; i++)
//	{
//		if (i % (rand() %  10+ 1) == 1)
//			printf("\r%.*s\033[46m>>%d%%\033[0m", i, s4, i);
//		Sleep(10);
//	}
//	//printf("\r%.*s\033[46m>>%d%%\033[0m", 100, s4, 100);
//	printf("\r%.*s\033[46m>>%d%%\033[0m", total, s4, total);
//	setcolor(BCYAN);
//
//	printf("\n加载完毕\n");
//	resetcolor();
//	return;
//}
////ptr = &menu_stack;
//
//void cus_prompt()
//{
//	setcolor(BCYAN);
//	printf("顾客信息\033[0m\n");
//	setcolor(FCYAN);
//	printf("VIP等级\t\t\t姓名\t\t联系方式\n\033[m\n");
//	resetcolor();
//	return;
//}
//
//
//void purchase_prompt()
//{
//	setcolor(BCYAN);
//	printf("进货信息\033[0m\n");
//	setcolor(FCYAN);
//	printf("年\t月\t日\t ");
//	printf("渠道价格\t数量\t货物名称\033[0m  \n");
//	return;
//}
//void sell_prompt()
//{
//	/*SetConsoleOutputCP(65001);
//	fprintf(stdout, "年    月    日\t ");
//	printf("顾客姓名\t  顾客编号      售价    购买数量\t 货物名称\tID\n");*/
//	setcolor(BCYAN);
//	printf("出售信息\033[0m\n");
//	setcolor(FCYAN);
//	printf( "年\t月\t日\t ");
//	printf("顾客姓名\t\t顾客编号\t\t售价\t\t购买数量\t\t货物名称\tID\n\033[0m\n");
//	//printf("渠道\t价格\t数量\t货物名称\033[0m\t\n");
//	return;
//}
//void base_prompt()
//{
//	//printf("type \tproducer desc\t price\t sale\t name\t id\n");
//	//printf("\033[36m类别\t生产商\t描述\t单价\t折扣\t货物名称\tID\033[36m\n");
//	setcolor(BCYAN);
//	printf("基础信息\033[0m\n");
//	setcolor(FCYAN);
//	printf("类别\t\t生产商\t\t描述\t\t单价\t\t折扣\t\t货物名称\t\tID\n\033[m\n");
//	resetcolor();
//	return;
//}
//
//void setcolor(int num)
//{
//	printf("\033[%dm", num);
//	return;
//}
//void resetcolor()
//{
//	printf("\033[0m");
//	return;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//void reset()
//{
//	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
//	WORD co = FOREGROUND_RED;
//	SetConsoleTextAttribute(hout, 1);
//	return;
//}
//
//
//
//
//
//
//void manager_menu()
//{
//	while (1)
//	{
//		printf("\t\t\t\t\t MANAGER \t\n");
//		//printf("here should be the fun of manager\nand go to some place\ncin 1\n");
//		int op = 0;
//		scanf("%d", &op);
//		if (op == 1)
//		{
//			printf("choosed 0 to return \n");
//		}
//		if (op == 0)
//		{
//			return;
//		}
//	}
//	return;
//}
//void seller_menu()
//{
//	printf("\t\t\tSELLER MENU\n");
//	while (1)
//	{
//		printf("\n");
//	}
//	return;
//}
//void menu()
//{
//	while (1)
//	{
//		int op;
//		printf("\t\t\t\t MAIN MENU HERE\n");
//		printf("choose you id\n");
//		if (scanf("%d", &op) == 0)
//		{
//			purify();
//			printf("请输入数字\n");
//		}
//		if (op == 1)
//		{
//			manager_menu();
//		}
//		else if (op == 0)
//		{
//			seller_menu();
//		}
//		else
//		{
//			printf("请重新选择\n");
//			if (op == -1)
//			{
//				return;
//			}
//		}
//
//	}
//	return;
//}

#define _CRT_SECURE_NO_WARNINGS 

#include"all.h"

//int (*p)(int, int);
//void(*menu_stack[1000])() = { NULL };
//void(*ptr)();
void me_2();
void seller_menu();
void menu();
void show_progress_bar()
{
	int total = 100;
	srand(time(0));
	char s3[] = "=======================================================================================================================================================================================================================================================================================================================================================================================================================================================================";
	char s4[] = "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
	for (int i = 0; i < total; i++)
	{
		if (i % (rand() % 10 + 1) == 1)
			printf("\r%.*s\033[46m>>%d%%\033[0m", i, s4, i);
		Sleep(10);
	}
	//printf("\r%.*s\033[46m>>%d%%\033[0m", 100, s4, 100);
	printf("\r%.*s\033[46m>>%d%%\033[0m", total, s4, total);
	setcolor(BCYAN);

	printf("\n加载完毕\n");
	resetcolor();
	return;
}
//ptr = &menu_stack;
void line(int co)
{
	//setcolor(co);
	printf("\033[%dm-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\033[0m\n", co);
	return;

}
void cus_prompt(void)
{
	setcolor(BCYAN);
	printf("顾客信息\033[0m\n");
	setcolor(FCYAN);
	printf("VIP等级\t\t\t姓名\t\t联系方式\n\033[m\n");
	resetcolor();
	return;
}


void purchase_prompt()
{
	setcolor(BCYAN);
	printf("进货信息\033[0m\n");
	setcolor(FCYAN);
	printf("年\t月\t日\t ");
	printf("渠道\t\t价格\t\t数量\t\t货物名称\t\tID\033[0m  \n");
	return;
}
void sell_prompt()
{
	/*SetConsoleOutputCP(65001);
	fprintf(stdout, "年    月    日\t ");
	printf("顾客姓名\t  顾客编号      售价    购买数量\t 货物名称\tID\n");*/
	setcolor(BCYAN);
	printf("出售信息\033[0m\n");
	setcolor(FCYAN);
	printf("年\t月\t日\t ");
	printf("顾客姓名\t\t顾客编号\t\t售价\t\t购买数量\t\t货物名称\t\tID\033[0m\n");
	//printf("渠道\t价格\t数量\t货物名称\033[0m\t\n");
	return;
}
void base_prompt()
{
	//printf("type \tproducer desc\t price\t sale\t name\t id\n");
	//printf("\033[36m类别\t生产商\t描述\t单价\t折扣\t货物名称\tID\033[36m\n");
	setcolor(BCYAN);
	printf("基础信息\033[0m\n");
	setcolor(FCYAN);
	printf("类别\t\t生产商\t\t描述\t\t单价\t\t折扣\t\t货物名称\t\tID\033[m\n");
	resetcolor();
	return;
}

void setcolor(int num)
{
	printf("\033[%dm", num);
	return;
}
void resetcolor()
{
	printf("\033[0m");
	return;
}





//void reset()
//{
//	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
//	WORD co = FOREGROUND_RED;
//	SetConsoleTextAttribute(hout, 1);
//	return;
//}
//





void manager_menu()
{
	while (1)
	{
		printf("\t\t\t\t\t MANAGER \t\n");
		//printf("here should be the fun of manager\nand go to some place\ncin 1\n");
		int op = 0;
		scanf("%d", &op);
		if (op == 1)
		{
			printf("choosed 0 to return \n");
		}
		if (op == 0)
		{
			return;
		}
	}
	return;
}
void seller_menu()
{
	printf("\t\t\tSELLER MENU\n");
	while (1)
	{
		printf("\n");
	}
	return;
}
void menu()
{
	while (1)
	{
		int op;
		printf("\t\t\t\t MAIN MENU HERE\n");
		printf("choose you id\n");
		if (scanf("%d", &op) == 0)
		{
			purify();
			printf("请输入数字\n");
		}
		if (op == 1)
		{
			manager_menu();
		}
		else if (op == 0)
		{
			seller_menu();
		}
		else
		{
			printf("请重新选择\n");
			if (op == -1)
			{
				return;
			}
		}

	}
	return;
}