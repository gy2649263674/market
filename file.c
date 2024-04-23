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
