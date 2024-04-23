#pragma once
#include"sys.h"


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