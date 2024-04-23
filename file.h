#pragma once
#pragma once
#include"struct.h"


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


//shui foods 
void copy_file(int mod);

bool opendir(const char* s);
FILE* open_info_file(Info cate, const char* mode);
FILE* openfile(const char* catename, const char* mode);
bool  goback();;
int  stdlize(char* s, char* des);
void MainTainSys(Node* head);
void showdir();

