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
