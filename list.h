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
