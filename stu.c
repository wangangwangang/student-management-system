#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

//定义学生信息头节点
STU head;


//学生功能区

//显示学生个人信息
void ShowStuS(int a )
{
	system("clear");
	PSTU pstu=&head;
	printf("***********************************************************\n");
	printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
	printf("***********************************************************\n");
	while(pstu->next)
	{
		if(pstu->next->num==a)
		{
			printf("%d\t",pstu->next->num);
			printf("%s\t",pstu->next->name);
			printf("%s\t",pstu->next->code);
			printf("%d\t",pstu->next->age);
			printf("%d\t",pstu->next->class);
			printf("%d\t",pstu->next->sx);
			printf("%d\t",pstu->next->yw);
			printf("%d\t",pstu->next->cyy);
			printf("%d\t",pstu->next->mc);
			printf("\n");
			break;
		}
		pstu=pstu->next;
	} 
	printf("***********************************************************\n");
	printf("按回车键返回上级界面。\n");
		setbuf(stdin,NULL);
		getchar();

}


//修改学生基本信息
int XGStuS(int a)
{
	PSTU p=&head;
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息修改界面*   \n");
	printf("     **************************   \n");
	while(p->next)
	{   if(p->next->num==a)
		{
			printf("密码:");
			scanf("%s",p->next->code);
			printf("修改信息完成\n");
			printf("按回车键按返回上层界面\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		p=p->next;
	}
}




//学生菜单
int MenuS(int a)
{

	int i,running=1;
	while(running)
	{
		PSTU pstu=&head;
		while(pstu->next)
		{
			if(pstu->next->num==a)
				break;
			pstu=pstu->next;
		}
		system("clear");
		printf("**************************************\n");
		printf("      欢迎%s学生来到教学管理系统    \n",pstu->next->name);
		printf("          1.显示个人信息            \n");
		printf("          2.修改个人基本信息        \n");
		printf("          3.保存个人信息            \n");
		printf("          4.退出                    \n");
		printf("**************************************\n");
		printf("请选择操作:");
		while(!scanf("%d",&i)||i<1||i>4)
		{
			printf("输入有误，请重新选择:");
			setbuf(stdin,NULL);
		}
		switch(i)
		{
			case 1:ShowStuS(a);break;
			case 2:XGStuS(a);break;
			case 3:BCStu();break;
			case 4:running=TC();break;
		}
	}
	return 0;
}
