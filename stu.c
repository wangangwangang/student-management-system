#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

extern STU head;																//声明学生链表头节点

void ShowStuS(int a )															//显示学生个人信息
{
	PSTU ps=&head;

	system("clear");
	printf("***********************************************************\n");
	printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
	printf("***********************************************************\n");

	while(ps->next)																//循环遍历链表
	{
		if(ps->next->num==a)
		{
			printf("%d\t",ps->next->num);
			printf("%s\t",ps->next->name);
			printf("%s\t",ps->next->code);
			printf("%d\t",ps->next->age);
			printf("%d\t",ps->next->class);
			printf("%d\t",ps->next->sx);
			printf("%d\t",ps->next->yw);
			printf("%d\t",ps->next->cyy);
			printf("%d\t",ps->next->mc);
			printf("\n");
			break;
		}
		else
		{
			ps=ps->next;
		}
	} 

	printf("***********************************************************\n");

	printf("按任意键返回\n");
	setbuf(stdin,NULL);
	getchar();
}


int XGStuS(int a)																//修改学生基本信息
{
	PSTU ps=&head;

	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息修改界面*   \n");
	printf("     **************************   \n");
	while(ps->next)
	{   
		if(ps->next->num==a)
		{
			printf("密码:");
			scanf("%s",ps->next->code);
			BCStu();
			printf("修改信息完成\n");
			printf("按任意键按返回\n");
			setbuf(stdin,NULL);
			getchar();
			return 0;
		}
		else
		{
			ps=ps->next;
		}
	}
}

int MenuS(int a)																	//学生菜单
{

	int i;																			//菜单选项
	int running=1;																	//循环控制变量

	while(running)
	{

		PSTU ps=&head;																//学生链表移动指针

		while(ps->next)																//找到学生节点
		{
			if(ps->next->num==a)
				break;
			ps=ps->next;
		}

		system("clear");
		printf("**************************************\n");
		printf("      欢迎%s学生来到教学管理系统    \n",ps->next->name);			//个性化专人登陆界面
		printf("          1.显示个人信息            \n");
		printf("          2.修改个人基本信息        \n");
		printf("          3.退出                    \n");
		printf("**************************************\n");
		printf("请选择操作:");

		while(!scanf("%d",&i)||i<1||i>4)											//判断是否输入的是数字，数字范围是否正确
		{
			printf("输入有误，请重新选择:");
			setbuf(stdin,NULL);
		}

		switch(i)
		{
			case 1:ShowStuS(a);break;
			case 2:XGStuS(a);break;
			case 3:running=0;break;
		}
	}
	return 0;
}
