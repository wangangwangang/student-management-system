#ifndef ADMIN_H
#define ADMIN_H
#include "common.h"

//超级用户功能区
PSTU GetPrevAddrA(int num);//返回指定学号学生节点的上一个节点的指针
int AddStuA();//把学生信息节点加入到链表中
int  DelStuA();//删除学生信息
int XGStuA();//修改学生信息
PTEA GetPrevAddr1A(int num);//返回指定序号教师节点的上一个节点的指针
int AddTeaA();//把教师信息节点加入到链表中
int  DelTeaA();//删除教师信息
void ShowAllTeaA();//显示所有教师信息
int CXTeaA();//查找教师信息
int XGTeaA();//修改教师信息
int MenuA();//超级用户菜单


#endif 
