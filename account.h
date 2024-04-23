#pragma once
#pragma once
#define	_CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdbool.h>
#include"struct.h"

//void manage_goods();
//void manage_customer();
//int reset_account();
//void manage_price();
void sort_info();
void query_goods_info();
//FILE* read_info(FILE* a,FILE *rec);
bool login(Info cate);
int log_out();
void main_system();
void Register(Info identity);
Node* resetACC(Node* head);

typedef struct Manager
{
	char account[50];
	char password[50];
}Manager;

