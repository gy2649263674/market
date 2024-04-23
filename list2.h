#pragma once
#include "goods.h"
//#include "list.h"

typedef struct Node2
{
	int left;
	int sold;
	char name[20];
	struct Node2* next;
	struct Node2* prev;
}Node2;
void warning_op(Node2* head);
void warning(Node2* head, int yuzhi);
Node2* init_list2();
Node2* clear_list2(Node2* head);
Node2* push_head2(Node2* head, int s, int l, char* n);
void show_list2_sell(Node2* head);
void show_list2_left(Node2* head);
void warning(Node2* head, int yuszui);
Node2* creat_list2(Node* head);
