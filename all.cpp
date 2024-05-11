#pragma warning(disable : 4996)
#pragma once
#pragma once
#include"struct.h"

#pragma once
#include"sys.h"

#pragma once
#pragma once
inline void purify();
void buitify();
void reset();
void manager_menu();
void seller_menu();
void me_2();
void menu();
void setcolor(int num);
void resetcolor();
void sell_prompt()
;
void purify();
void purchase_prompt();
void show_progress_bar();
void line(int co);
void cus_prompt();

#define FBLUE 34
#define FRED 31
#define FCYAN 36
#define  BBLUE 44
#define BCYAN 46
#define BRED 41
#define FFRED 35
#define FYELLOW 33
#define FGREEN 32
#define BYELLOW 43

/*

显示方式 : 0（默认值）、1（高亮）、22（非粗体）、4（下划线）、24（非下划线）、5（闪烁）、25（非闪烁）、7（反显）、27（非反显）

前景色 : 30（黑色）、31（红色）、32（绿色）、 33（黄色）、34（蓝色）、35（洋红）、36（青色）、37（白色）

背景色 : 40（黑色）、41（红色）、42（绿色）、 43（黄色）、44（蓝色）、45（洋红）、46（青色）、47（白色）

*/

typedef enum
{
	ID,
	NAME
}findprompt;


typedef enum info_chage
{
	priceC,
	saleC,
	typeC,
	purchase_priceC,
	purchase_channelC,
	purchase_sizeC,
	dateC,
	nameC

}info_change;

typedef enum Info
{
	BaseI,
	SellI,
	PurI,
	AccI,
	VoidI,
	MasterI,
	SellerI,
	AllI,
	CusI
}Info;




typedef enum compare
{
	less,
	greater
}Compare;



typedef struct Account
{
	char account[20];
	char password[20];
}Account
;
typedef struct Date
{
	int day;
	int month;
	int year;
}date;

typedef struct Base
{
	//	strcmp()
	char type[20];
	char producer[20];
	char desciption[20];
	double price;//biaojia
	double sale;
}Base;

typedef struct
{

	date purchase_date;
	char purchase_channel[20];
	double purchase_price;
	int purchase_size;
}Purchase;

typedef struct
{
	date sell_date;
	char customer_id[20];
	char customer_name[20];
	double sell_price;
	int sell_volume;
}Sell;
//name
//phone


typedef union Data
{
	void* void_;
	Base* base_;
	Sell* sell_;
	Purchase* pur_;
	Account* acc_;

}Data;

//struct cus
//{
//
//};
typedef struct Node
{
	char name[20];
	char id[20];
	struct Node* prev;
	struct Node* next;
	Base* base_;
	Sell* sell_;
	Purchase* pur_;
}Node;


typedef struct
{
	int vip;
	char cus_name[20];
	char phone[20];
}Customer;

typedef struct Node3
{
	Customer* cus_;
	struct Node3* prev;
	struct Node3* next;
}Node3;
#define ACC(a)  ((Account *)a)
#define BASEINFO(a)  ((Base *)a)
#define SELLINFO(a)  ((Sell *)a)
#define PURINFO(a)  ((Purchase *)a)
#define CUSINFO(a)	((Customer *)a)
#define DOUBLE(a)  ((double*)a)
#define CHAR(a) ((char*)a)
#define INT(a) ((int*)a)
#define DATE(a) ((date*)a)
//#define ARRAY(a) 
#define GOODS_DIR "_goods"
#define ACCOUNT_DIR "_account"
#define LOG_DIR "_log"
#define LOG_FILE "log.txt"
#define GOODS_FILE "goods.txt"
#define MASTER_FILE "master.txt"
#define SELLER_FILE "seller.txt"
#define ACCOUNT_FILE "account.txt"
#define BASE_FILE "Base.txt"
#define SELL_FILE "Sell.txt"
#define PUR_FILE "Purchase.txt"
#define CUS_FILE "Customer.txt"
#define BGOODS_DIR "b_goods"
#define BACCOUNT_DIR "b_account"

#pragma once
#pragma once
#define	_CRT_SECURE_NO_WARNINGS
//#include"struct.h"
//Setconsole()
//
#pragma once
#pragma once
#include"struct.h"
#include"sys.h"

Node* init_list();
void statics_menu();
void multi_sta(Node* head, int operate);
void delete_menu(Node* head);;
//Node* clear_list(Node* head);
Node* push_head(Node* head);
void swap(Node* a, Node* b);
int getlength(Node* head);
void  free_node(Node** node, Info cate);
Node* bub(Node* head, Compare mode, bool (*cmp) (Node* a, Node* b, Compare c));
Node* delete_node(Node* head, char* id, Info cate);
//Node* simple_find(Node* head, const char* s, findprompt operate);
Node* combined_find(Node* head);// , const  char* name, const char* id);
Node* simple_find(Node* head);//, char* id, findprompt operate);
Node* fuzzy_find(Node* head);//;, char* s, int operate);
Node* destruct_list(Node** head, Info cate);
Node* accurate_find(Node* head, const char* ID);
void singlesort(Node* head);
void add_cus(Node3* head);
//Node3* modify_cus(Node3* head);
Node3* get_cus_info(Node3* exist_info, bool add);
Node3* init_list3();
Node3* push_head3(Node3* head);
Node3* delete_list3(Node3* head);
void add_info(Node* head);
void range_query_menu(Node* head);
void MainTainSys(Node*head);
void resetSeller(void);

#include"sys.h"
void check_info(Node* head);
bool id_cmp(Node* a, Node* b, Compare mode);
bool name_cmp(Node* a, Node* b, Compare mode);
bool sell_price_cmp(Node* a, Node* b, Compare mode);
bool base_price_cmp(Node* a, Node* b, Compare mode);
bool pur_price_cmp(Node* a, Node* b, Compare mode);
Node* get_base_info(Node* exist_nead, bool from_std);
Node* get_purchase_info(Node* goodshead, bool from_std);
Node* get_sell_info(Node* goodshead, bool from_std);
Node* record_sell_info(Node* head, bool to_std);
Node* record_purchase_info(Node* head, bool to_std);
Node* record_base_info(Node* head, bool to_std);
void show_sell_info(Node* node);
void show_base_info(Node* node);
Node* change_data(Node* head, char* name, void* newdata, info_change op);
Node* same_name(Node* last, char* s);
void showone(Node* node);
void show_purchase_info(Node* node);
void singlesort(Node* head);
int exam();
void add_info(Node* head);
Node* load(Node* node, void* data, Info cate);
void modify_type(Node* head);
Node3* modify_cus(Node3* head);
void multi_sort(Node* head);

void add_cus(Node3* head);
void showone(Node* node);
void base_prompt();
void sell_prompt();
void purchase_prompt();
;
bool pur_vol_cmp(Node* a, Node* b, Compare mode);




//shui foods 
void copy_file(int mod);

bool opendir(const char* s);
FILE* open_info_file(Info cate, const char* mode);
FILE* openfile(const char* catename, const char* mode);
bool  goback();;
int  stdlize(char* s, char* des);
void MainTainSys(Node* head);
void showdir();


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
#pragma warning(disable : 4996)

#define _CRT_SECURE_NO_WARNINGS 
#include"all.h"
#include"sys.h"
#include"struct.h"
#include"file.h"

bool  goback()
{
	int success = chdir("..");
	if (success == -1)
	{
		system("work dir wrong ,attention\n");
		perror("failed to return workspace\n");
		return false;
	}
	showdir();
	return true;


}


FILE* open_info_file(Info cate, const char* mode)
{
	FILE* fp = NULL;

	if (cate == SellerI)
	{
		if (chdir(ACCOUNT_DIR) == -1)
		{
			_mkdir(ACCOUNT_DIR, 0777);
			chdir(ACCOUNT_DIR);
		}
		fp = fopen(SELLER_FILE, mode);
		goback();
	}
	else if (cate == MasterI)
	{
		if (chdir(ACCOUNT_DIR) == -1)
		{
			_mkdir(ACCOUNT_DIR, 0777);
			chdir(ACCOUNT_DIR);
		}
		fp = fopen(MASTER_FILE, mode);
		goback();
	}
	else if (cate == BaseI)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
		fp = fopen(BASE_FILE, mode);
		goback();
	}
	else if (cate == PurI)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
		fp = fopen(PUR_FILE, mode);
		goback();
	}
	else if (cate == SellI)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
		fp = fopen(SELL_FILE, mode);
		goback();
	}
	else if (cate == BaseI)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
		fp = fopen(BASE_FILE, mode);
		goback();
	}
	else if (cate == CusI)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
		fp = fopen(CUS_FILE, mode);
		goback();
	}

	else
	{
		printf("open_info_file error\n");
		return NULL;
	}
	return fp;
}

int  stdlize(char* s, char* des)
{
	if (strlen(s) - 2 <= 1 || strlen(s) - 2 > 256)
	{
		printf("文件路径无效请重试\n");
		return 0;
	}
	strncpy(des, s + 1, strlen(s) - 2);
	return 0;
}

bool opendir(const char* s)
{
	if (strcmp(s, "seller") == 0 || strcmp(s, "master") == 0)
	{
		if (chdir(ACCOUNT_DIR) == -1)
		{
			_mkdir(ACCOUNT_DIR, 0777);
			chdir(ACCOUNT_DIR);
		}
	}
	else if (strcmp("_goods", s) == 0)
	{
		if (chdir(GOODS_DIR) == -1)
		{
			_mkdir(GOODS_DIR, 0777);
			chdir(GOODS_DIR);
		}
	}
	else
	{
		printf("wrong dir\n");
		return false;
	}
	return 0;
}

//void copy_file(int mod)
//{
//
//	if (mod == 1)
//	{
//		if (chdir(BGOODS_DIR) == -1)
//		{
//			mkdir(BGOODS_DIR);
//		}
//		char old[255];
//		char old1[255] = { 0 };
//		char old2[255] = { 0 };
//		char old3[255] = { 0 };
//		getcwd(old, 255);
//		getcwd(old1, 255);
//		getcwd(old2, 255);
//		getcwd(old3, 255);
//		chdir("..");
//		char newpath[255] = { 0 };
//		getcwd(newpath, 255);
//		strcat(strcat(old1, "\\"), BASE_FILE);
//		strcat(strcat(old2, "\\"), SELL_FILE);
//		strcat(strcat(old3, "\\"), PUR_FILE);
//		char new[255] = { 0 };
//		char new1[255] = { 0 };
//		char new2[255] = { 0 };
//		char new3[255] = { 0 };
//		getcwd(new, 255);
//		getcwd(new1, 255);
//		getcwd(new2, 255);
//		getcwd(new3, 255);
//		strcat(strcat(strcat(new1, "\\"), BGOODS_DIR), "\\, BASE_FILE);
//		strcat(strcat(strcat(strcat(new1, "\\"), BGOODS_DIR), "\\"), BASE_FILE);
//		strcat(strcat(strcat(strcat(new1, "\\"), BGOODS_DIR), "\\"), BASE_FILE);
//		CopyFile(old1, new1, false);
//		CopyFile(old2, new2, false);
//		CopyFile(old3, new3, false);
//	}
//	else if (mod == 2)
//	{
//
//	}
//
//void copy_file(int mod)
//{
//
//	if (mod == 1)
//	{
//
//		char old[255];
//		char old1[255] = { 0 };
//		char old2[255] = { 0 };
//		char old3[255] = { 0 };
//		chdir(GOODS_DIR);
//		getcwd(old, 255);
//		getcwd(old1, 255);
//		getcwd(old2, 255);
//		getcwd(old3, 255);
//		char newpath[255] = { 0 };
//		getcwd(newpath, 255);
//		strcat(strcat(old1, "\\"), BASE_FILE);
//		if (fopen(old1, "r") == 0)
//		{
//			perror("");
//		}
//		strcat(strcat(old2, "\\"), SELL_FILE);
//		strcat(strcat(old3, "\\"), PUR_FILE);
//		chdir("..");
//		if (chdir(BGOODS_DIR) == -1)
//		{
//			mkdir(BGOODS_DIR);
//
//			chdir(BGOODS_DIR);
//		}
//		char new[255] = { 0 };
//		char new1[255] = { 0 };
//		char new2[255] = { 0 };
//		char new3[255] = { 0 };
//		getcwd(new, 255);
//		getcwd(new1, 255);
//		getcwd(new2, 255);
//		getcwd(new3, 255);
//		strcat(strcat(new1, "\\"), BASE_FILE);
//		strcat(strcat(new2, "\\"), SELL_FILE);
//		strcat(strcat(new3, "\\"), PUR_FILE);
//		/*FILE* f1 = fopen(new1, "w+");
//		FILE* f2 = fopen(new2, "w+");
//		FILE* f3 = fopen(new3, "w+");*/
//		if (CopyFile(old1, new1, false))
//		{
//			perror("");
//		}
//		CopyFile(old2, new2, false);
//		CopyFile(old3, new3, false);
//		/*fclose(f1);
//		fclose(f2);
//		fclose(f3);*/
//		chdir("..");
//		return;
//	}
//	else if (mod == 2)
//	{
//
//		char old[255][3] = { 0 };
//		chdir(BGOODS_DIR);
//		getcwd(old[1], 255);
//		getcwd(old[2], 255);
//		getcwd(old[3], 255);
//		char newpath[255] = { 0 };
//		for (int i = 0; i < 3; i++)
//		{
//			getcwd(old[i], 255);
//		}
//		strcat(strcat(old[1], "\\"), BASE_FILE);
//		strcat(strcat(old[2], "\\"), SELL_FILE);
//		strcat(strcat(old[3], "\\"), PUR_FILE);
//		chdir("..");
//
//		if (chdir(GOODS_DIR) == -1)
//		{
//			mkdir(GOODS_DIR);
//
//			chdir(GOODS_DIR);
//		}
//		char new[255][3] = { 0 };
//		getcwd(new, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			getcwd(new[i], 255);
//		}
//		strcat(strcat(new[1], "\\"), BASE_FILE);
//		strcat(strcat(new[2], "\\"), SELL_FILE);
//		strcat(strcat(new[3], "\\"), PUR_FILE);
//		char ch = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			FILE* in = fopen(old[i], "r");
//			FILE* out = fopen(new[1], "w+");
//			while (ch = fgetchar(in) && ch != EOF)
//			{
//				fputchar(out, ch);
//			}
//		}
//		chdir("..");
//		return;
//	}
//}
void copy_file(int mod)
{
	char fromdir[255] = { 0 };
	char afromdir[255] = { 0 };
	char atodir[255] = { 0 };
	char todir[255] = { 0 };
	if (mod == 1)
	{
		setcolor(BCYAN);
		printf("备份数据~ing\033[0m\n");
		resetcolor();
		strcpy(todir, BGOODS_DIR);
		strcpy(atodir, BACCOUNT_DIR);
		strcpy(fromdir, GOODS_DIR);
		strcpy(afromdir, ACCOUNT_DIR);
	}
	else if (mod == 2)
	{
		setcolor(BCYAN);
		printf("恢复~ing\033[0m\n");
		resetcolor();
		strcpy(todir, GOODS_DIR);
		strcpy(atodir, ACCOUNT_DIR);
		strcpy(afromdir, BACCOUNT_DIR);
		strcpy(fromdir, BGOODS_DIR);
	}
	char old[3][255] = { 0 };

	if (chdir(fromdir) == -1)
	{
		mkdir(fromdir);
		if (mod == 2)
		{
			printf("尚未进行过备份\n");
			return;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		getcwd(old[i], 255);
	}
	strcat(strcat(old[0], "\\"), BASE_FILE);
	strcat(strcat(old[1], "\\"), SELL_FILE);
	strcat(strcat(old[2], "\\"), PUR_FILE);
	chdir("..");

	if (chdir(todir) == -1)
	{
		mkdir(todir);
		chdir(todir);
	}
	char new[3][255] = { 0 };
	getcwd(new, 255);
	for (int i = 0; i < 3; i++)
	{
		getcwd(new[i], 255);
	}
	chdir("..");
	strcat(strcat(new[0], "\\"), BASE_FILE);
	strcat(strcat(new[1], "\\"), SELL_FILE);
	strcat(strcat(new[2], "\\"), PUR_FILE);
	char ch = 0;
	for (int i = 0; i < 3; i++)
	{
		FILE* in = fopen(old[i], "r");
		FILE* out = fopen(new[i], "w+");
		if (in == NULL || out == NULL)
		{
			perror("\n");
			break;
		}
		while (fscanf(in, "%c", &ch) != EOF)
		{
			fputc(ch, out);
		}
		fclose(in);
		fclose(out);
	}
	chdir(afromdir);
	for (int i = 0; i < 2; i++)
	{
		getcwd(old[i], 255);
	}
	strcat(strcat(old[0], "\\"), MASTER_FILE);
	strcat(strcat(old[1], "\\"), SELLER_FILE);
	chdir("..");
	if (chdir(atodir) == -1)
	{
		mkdir(atodir);
		chdir(atodir);
	}
	getcwd(new, 255);
	for (int i = 0; i < 2; i++)
	{
		getcwd(new[i], 255);
	}
	chdir("..");
	strcat(strcat(new[0], "\\"), MASTER_FILE);
	strcat(strcat(new[1], "\\"), SELLER_FILE);
	for (int i = 0; i < 2; i++)
	{
		FILE* in = fopen(old[i], "r");
		FILE* out = fopen(new[i], "w+");
		if (in == NULL || out == NULL)
		{
			perror("\n");
			break;
		}
		while (fscanf(in, "%c", &ch) != EOF)
		{
			fputc(ch, out);
		}
		fclose(in);
		fclose(out);
	}
	return;
}
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
}//#define CRT_SECURE_NO_WARNINGS 1 
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