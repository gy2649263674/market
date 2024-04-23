#pragma once
#pragma once
#define	_CRT_SECURE_NO_WARNINGS
//#include"struct.h"
//Setconsole()
//
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



