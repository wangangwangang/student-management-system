#ifndef STU_H
#define STU_H

//定义学生信息结构体类型
typedef struct Student
{
	int num;
	char name[128];
	char code[32];
	int age;
	int class;
	int sx;
	int yw;
	int cyy;
	int mc;
	struct Student *next;
}STU,*PSTU;


//学生功能区
int XGStuT();//修改学生信息
PSTU GetPrevAddrA(int num);//返回指定学号学生节点的上一个节点的指针
int AddStuA();//把学生信息节点加入到链表中
int  DelStuA();//删除学生信息
int XGStuA();//修改学生信息
int DRStu();//载入学生信息
int BCStu();//保存学生信息
int CXStu();//查找学生信息
void ShowAllStu();//显示所有学生信息
void ShowStuS(int a );//显示学生个人信息
int XGStuS(int a);//修改学生基本信息
int sort_mc();
int sort_num();
int sort_sx();
int sort_yw();
int sort_cyy();
int print();


#endif 
