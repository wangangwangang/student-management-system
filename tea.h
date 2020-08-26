#ifndef TEA_H
#define TEA_H

typedef struct Teacher 				//定义教师信息结构体类型
{
	int num;
	char name[128];
	char code[32];
	int class;
	struct Teacher *next;
}TEA,*PTEA;

//教师功能区
int AddTeaA();//把教师信息节点加入到链表中
int  DelTeaA();//删除教师信息
void ShowAllTeaA();//显示所有教师信息
int CXTeaA();//查找教师信息
int XGTeaA();//修改教师信息
int DRTea();//载入老师信息
int BCTea();//保存老师信息
void ShowTea(int a);//显示教师信息
int XGTeaT(int a);//修改教师信息

#endif  
