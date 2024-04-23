#pragma warning(disable : 4996)
#define	_CRT_SECURE_NO_WARNINGS 
#include<stdbool.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "all.h"
// master
// seller
bool loginSucess1 = 0;
bool loginSucess2 = 0;
Node* head = NULL;
Node3* Cushead = NULL;
Node2* Stahead = NULL;
char SAFE = 0;
void exitSystem()
{
	printf("已退出系统\n");
	system("pause");
	exit(0);
}

void id()
{
	puts("请选择您的身份 :");
	puts("0.返回");
	puts("1.管理员");
	puts("2.售货员");
}

void showMenu()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    欢迎使用超市管理系统!  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      功能选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.退出               *****\n");
	printf("\t\t\t\t\t*****      1.登录               *****\n");
	printf("\t\t\t\t\t*****      2.注册               *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****      管理员               *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      功能选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.退出登录           *****\n");
	printf("\t\t\t\t\t*****      1.信息管理           *****\n");
	printf("\t\t\t\t\t*****      2.信息排序           *****\n");
	printf("\t\t\t\t\t*****      3.信息统计           *****\n");
	printf("\t\t\t\t\t*****      4.商品进销分析       *****\n");
	printf("\t\t\t\t\t*****      5.保存信息           *****\n");
	printf("\t\t\t\t\t*****      6.系统维护           *****\n");
	printf("\t\t\t\t\t*****      7.重置密码           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_information()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 1信息管理      *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.商品信息           *****\n");
	printf("\t\t\t\t\t*****      2.顾客信息           *****\n");
	/*printf("					*****      3.商品分类信息       *****\n");
	printf("					*****      4.顾客分类信息       *****\n");*/
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

//printf("\t\t\t\t\t*****      1.查看库存与销售情况           *****\n");
void showMenuMASTER_master_information_goods()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 1商品信息管理  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.显示所有商品信息   *****\n");
	printf("\t\t\t\t\t*****      2.调整商品信息       *****\n");
	printf("\t\t\t\t\t*****      3.添加商品           *****\n");
	printf("\t\t\t\t\t*****      4.删除商品           *****\n");
	printf("\t\t\t\t\t*****      5.查询商品信息       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

/*void showMenu11_2() {
	printf("*************************************\n");
	printf("*****    1管理员 1基本信息管理  *****\n");
	printf("*****                           *****\n");
	printf("*****      功能选择：           *****\n");
	printf("*****                           *****\n");
	printf("*****      0.返回               *****\n");
	printf("*****      1.增加               *****\n");
	printf("*****      2.修改               *****\n");
	printf("*****      3.删除			    *****\n");
	printf("*****                           *****\n");
	printf("*************************************\n");
}*/

void showMenu_master_information_customer()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 1顾客信息管理  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.修改顾客信息       *****\n");
	printf("\t\t\t\t\t*****      2.增加新顾客         *****\n");
	printf("\t\t\t\t\t*****      3.删除顾客           *****\n");
	printf("\t\t\t\t\t*****      4.展示顾客信息       *****\n");
	printf("\t\t\t\t\t*****      5.保存顾客信息       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

/*void showMenu14() {
	printf("*************************************\n");
	printf("*****     1管理员 4售价管理     *****\n");
	printf("*****                           *****\n");
	printf("*****      功能选择：           *****\n");
	printf("*****                           *****\n");
	printf("*****      0.返回               *****\n");
	printf("*****      1.涨价               *****\n");
	printf("*****      2.降价               *****\n");
	printf("*****      3.打折               *****\n");
	printf("*****                           *****\n");
	printf("*************************************\n");
}*/
void showMenu_master_find()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 \033[46m信息查询\033[0m       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.简单查询           *****\n");
	printf("\t\t\t\t\t*****      2.范围查询           *****\n");
	printf("\t\t\t\t\t*****      3.模糊查询           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_sort()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 2信息排序      *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.单属性排序         *****\n");
	printf("\t\t\t\t\t*****      2.多属性排序         *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_static()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 3信息统计      *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.单属性统计         *****\n");
	printf("\t\t\t\t\t*****      2.多属性统计         *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_static_single()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 3信息统计  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.根据价格统计           *****\n");
	printf("\t\t\t\t\t*****      2.根据种类统计       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_analyse()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 4商品进销分析  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.查看商品剩余库存   *****\n");
	printf("\t\t\t\t\t*****      2.查看商品销售量     *****\n");
	printf("\t\t\t\t\t*****      3:预警系统           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_protect()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 5系统维护  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回				  *****\n");
	printf("\t\t\t\t\t*****      1.重置系统			  *****\n");
	printf("\t\t\t\t\t*****      2.备份数据			  *****\n");
	printf("\t\t\t\t\t*****      3.管理账户		    *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_master_warning()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    1管理员 库存预警  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}













void showMenu_seller()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****      销售员               *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      功能选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.退出登录           *****\n");
	printf("\t\t\t\t\t*****      1.信息查询       *****\n");
	printf("\t\t\t\t\t*****      2.信息排序       *****\n");
	printf("\t\t\t\t\t*****      3.信息统计       *****\n");
	printf("\t\t\t\t\t*****      4.导入商品信息       *****\n");
	printf("\t\t\t\t\t*****      5.修改商品信息       *****\n");
	printf("\t\t\t\t\t*****      6.显示所有商品信息       *****\n");
	printf("\t\t\t\t\t*****      7.保存所有商品信息       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_seller_find()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    2销售员 1信息查询  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.简单查询           *****\n");
	printf("\t\t\t\t\t*****      2.组合查询       *****\n");
	printf("\t\t\t\t\t*****      3.模糊查询       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_seller_sort()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    2销售员 2信息排序  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.单属性排序           *****\n");
	printf("\t\t\t\t\t*****      2.多属性排序       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_seller_static()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    2销售员 3信息统计  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.单属性统计           *****\n");
	printf("\t\t\t\t\t*****      2.多属性统计       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

void showMenu_seller_static_single()
{
	printf("\t\t\t\t\t*************************************\n");
	printf("\t\t\t\t\t*****    2销售员 3信息统计  *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      对象选择：           *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*****      0.返回               *****\n");
	printf("\t\t\t\t\t*****      1.根据价格统计           *****\n");
	printf("\t\t\t\t\t*****      2.根据种类统计       *****\n");
	printf("\t\t\t\t\t*****      3.根据进货商统计       *****\n");
	printf("\t\t\t\t\t*****                           *****\n");
	printf("\t\t\t\t\t*************************************\n");
}

//void showMenu_seller_analyse()
//{
//	printf("\t\t\t\t\t*************************************\n");
//	printf("\t\t\t\t\t*****    2销售员 4商品进销分析  *****\n");
//	printf("\t\t\t\t\t*****                           *****\n");
//	printf("\t\t\t\t\t*****      对象选择：           *****\n");
//	printf("\t\t\t\t\t*****                           *****\n");
//	printf("\t\t\t\t\t*****      0.返回               *****\n");
//	printf("\t\t\t\t\t*****      1.查看商品剩余库存           *****\n");
//	printf("\t\t\t\t\t*****      2.查看商品销售量       *****\n");
//	printf("\t\t\t\t\t*****                           *****\n");
//	printf("\t\t\t\t\t*************************************\n");
//}



void find_menu()
{
	while (1)
	{
		showMenu_master_find();
		int ope = -1;
		ope = exam();
		if (ope == -1)
		{
			wa();
			continue;
		}
		if (ope == 1)
		{
			simple_find(head);
			continue;
		}
		else if (ope == 2)
		{
			//combined_find(head);
			range_query_menu(head);
		}
		else if (ope == 3)
		{
			fuzzy_find(head);
		}
		else if (ope == 0)
		{
			break;
		}
	}
}

void find_menu2()
{
	while (1)
	{
		showMenu_seller_find();
		int ope = -1;
		ope = exam();
		if (ope == -1)
		{
			wa();
			continue;
		}
		if (ope == 1)
		{
			simple_find(head);
			continue;
		}
		else if (ope == 2)
		{
			//combined_find(head);
			range_query_menu(head);
		}
		else if (ope == 3)
		{
			fuzzy_find(head);
		}
		else if (ope == 0)
		{
			break;
		}
	}
}

void goods_info_manage()
{
	//商品信息管理
	while (1)
	{
		showMenuMASTER_master_information_goods();
		int op = exam();;
		if (op == -1)
		{
			wa();
			continue;
		}
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			//print_all(head);
			record_base_info(head, 1);
			record_sell_info(head, 1);
			record_purchase_info(head, 1);
			continue;
		}
		else if (op == 2)
		{
			modify_type(head);
			continue;
		}
		else if (op == 3)
		{
			add_info(head); continue;
		}
		else if (op == 4)
		{
			delete_menu(head);
			continue;
		}
		//cha xun
		else if (op == 5)
		{
			find_menu();
		}

	}
}

void sort_info_menu()
{
	while (1)
	{
		showMenu_master_sort();
		int ope = -1;
		scanf("%d", &ope);
		if (ope == -1)
		{
			wa();
			continue;
		}
		if (ope == 1)
		{
			singlesort(head);
		}
		else if (ope == 2)
		{
			multi_sort(head);
		}
		else if (ope == 0)
		{
			break;
		}
	}
}
//greater shengxu
void sort_info_menu2()
{
	while (1)
	{
		showMenu_seller_sort();
		int ope = -1;
		scanf("%d", &ope);
		if (ope == -1)
		{
			wa();
			continue;
		}
		if (ope == 1)
		{
			singlesort(head);
		}
		else if (ope == 2)
		{
		}
		else if (ope == 0)
		{
			break;
		}
	}
}

void customer_info_manage()
{
	if (Cushead == NULL)
	{
		Cushead = get_cus_info(NULL, false);
	}
	while (1)
	{
		showMenu_master_information_customer();
		int op = exam();
		if (op == 0)
		{
			break;
		}

		else if (op == 1)
		{
			modify_cus(Cushead);
		}
		else if (op == 2)
		{
			add_cus(Cushead);
		}
		else if (op == 3)
		{
			Cushead = delete_list3(Cushead);
		}
		else if (op == 4)
		{
			record_cus_info(Cushead, false);
		}
		else if (op == 5)
		{
			printf("save cus info \n");
			record_cus_info(Cushead, true);
		}
	}
	return;
}
void goods_info_alalysis_waring_menu()
{
	Node2* Stahead = creat_list2(head);
	while (1)
	{
		showMenu_master_analyse();
		int op = exam();
		if (op == -1)
		{
			wa();
			continue;
		}
		if (op == 1)
		{
			show_list2_left(Stahead);
		}
		else if (op == 2)
		{
			show_list2_sell(Stahead);
		}
		else if (op == 3)
		{
			warning_op(Stahead);
		}
		else if (op == 0)
		{
			break;
		}
	}
	return;
}

void multi_info_staAAA(Node* head);

void statics_menu()
{
	while (1)
	{
		showMenu_master_static();
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			single_info_staAAA(head);

		}
		else if (op == 2)
		{
			multi_info_staAAA(head);
		}
	}
}
void statics_menu2()
{
	while (1)
	{
		showMenu_seller_static();
		int op = exam();
		if (op == 0)
		{
			return;
		}
		else if (op == 1)
		{
			single_info_staAAA(head);
		}
		else if (op == 2)
		{
			multi_info_staAAA(head);
		}
	}
}

void SAVE()
{
	//printf("save data\n");
	record_base_info(head, 0);
	record_sell_info(head, 0);
	record_purchase_info(head, 0);
	setcolor(FBLUE);
	printf("save successful \033[0m\n");
	destruct_list(&head, AllI);

	if (head == NULL)
	{
		head = get_base_info(head, 0);
		get_purchase_info(head, 0);
		get_sell_info(head, 0);
	}
}
void sucess1()
{

	int opt = -1;
	printf("管理员用户正在使用系统\n");
	while (1)
	{
		if (head == NULL)
		{
			head = get_base_info(head, 0);
			get_purchase_info(head, 0);
			get_sell_info(head, 0);
		}
		showMenu_master();
		opt = exam();
		if (opt == 0)
		{
			SAVE();
			printf("数据已自动保存\n");

			loginSucess1 = false;
			return;
		}
		//信息管理
		else if (opt == 1)
		{
			while (1)
			{
				showMenu_master_information();
				int opl = exam();
				if (opl == 1)
				{
					goods_info_manage();
				}
				else if (opl == 2)
				{
					customer_info_manage();
				}
				else if (opl == 0)
				{
					break;
				}
				else
				{
					wa();
				}
			}

		}
		//排序
		else if (opt == 2)
		{
			sort_info_menu();
			continue;
		}
		//统计
		else if (opt == 3)
		{
			statics_menu();
		}
		//分析
		else if (opt == 4)
		{

			goods_info_alalysis_waring_menu();
		}
		//
		else if (opt == 6)
		{
			MainTainSys(head);
		}
		else if (opt == 5)
		{
			SAVE();
		}
		else if (opt == 7)
		{
			reset_pass_word(MasterI);
		}
	}
}

void sucess2()
{
	if (head == NULL)
	{
		head = get_base_info(NULL, 0);
		get_purchase_info(head, 0);
		get_sell_info(head, 0);
	}
	printf("售货员用户正在使用系统\n");
	int opt = -1;
	while (1)
	{
		showMenu_seller();
		opt = exam();
		if (opt == 0)
		{
			SAVE();
			printf("save successfully");
			loginSucess2 = false;
			return;
		}
		else if (opt == 1)
		{
			find_menu2();
			continue;
		}
		else if (opt == 2)
		{
			sort_info_menu2();
			continue;
		}
		else if (opt == 3)
		{
			statics_menu2();
			continue;
		}
		else if (opt == 4)
		{
			add_info(head);
			continue;
		}
		else if (opt == 5)
		{
			modify_type(head);
			continue;
		}
		else if (opt == 6)
		{
			record_base_info(head, 1);
			record_sell_info(head, 1);
			record_purchase_info(head, 1);
			continue;
		}
		else if (opt == 7)
		{
			printf("save data~ing\n");
			record_base_info(head, 0);
			record_sell_info(head, 0);
			record_purchase_info(head, 0);
		}
		else if (opt == 8)
		{
			reset_pass_word(SellerI);
		}
	}
}

void loginMenu()
{
	int opt = 0;
	while (true)
	{
		setcolor(BBLUE);
		printf("\t\t\t\t\t正在登录中\033[0m\n");
		//resetcolor();
		puts("请选择您的身份 :");
		puts("0.返回");
		puts("1.管理员");
		puts("2.售货员");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
		{
			loginSucess1 = false;
			loginSucess2 = false;
			return;
		}
		case 1:
			if (login(MasterI))
			{

				loginSucess1 = true;
				return;
			}
			break;
		case 2:
			if (login(SellerI))
			{
				loginSucess2 = true;
				return;
			}
			break;
		default:
		{
			purify();
		}
		break;
		}
	}
}

void RegisterMenu()

{
	int opt = 0;
	while (true)
	{
		setcolor(BBLUE);
		puts("\t\t\t\t\t正在注册中\033[0m\n");
		puts("请选择您的身份 :");
		puts("0.返回");
		puts("1.管理员");
		puts("2.售货员");
		int opt = exam();
		if (opt == 1)
		{
			Register(MasterI);
			resetcolor();
			break;
		}
		else if (opt == 2)
		{
			Register(SellerI);
			resetcolor();
			break;
		}
		else
		{
			wa();
		}
	}
}
void testfun()
{
	head = get_base_info(head, false);
	get_purchase_info(head, false);
	get_sell_info(head, false);
	while (1)
	{
		record_base_info(head, 1);
		record_sell_info(head, 1);
		record_purchase_info(head, 1);
	}
	return;
}
int main()
{
	int opt = -1;
	while (1)
	{
		loginSucess1 = false;
		loginSucess2 = false;
		showMenu();
		opt = exam();
		if (opt == 0)
		{
			exitSystem();
		}
		else if (opt == 1)
		{
			loginMenu();
		}
		else if (opt == 2)
		{
			RegisterMenu();
		}



		if (loginSucess1 == true)
		{
			show_progress_bar();
			sucess1();
		}
		else if (loginSucess2 == true)
		{
			show_progress_bar();
			sucess2();
		}
	}
	system("pause");
	return 0;
}
