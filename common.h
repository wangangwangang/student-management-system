#ifndef COMMON_H
#define COMMON_H


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

//定义教师信息结构体类型
typedef struct Teacher
{
	int num;
	char name[128];
	char code[32];
	int class;
	struct Teacher *next;
}TEA,*PTEA;


int TC();//退出函数
int BCStu();//保存学生信息
int BCTea();//保存老师信息
int CXStu();//查找学生信息
void ShowAllStu();//显示所有学生信息


#endif  
