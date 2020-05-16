#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

//定义学生信息头节点
STU head;
//定义教师信息头节点
TEA head1;

//教师功能区

//显示教师信息
void ShowTea(int a)
{
	system("clear");
	PTEA ptea=&head1;
	printf("*****************************\n");
	printf("序号\t姓名\t密码\t班级\n");
	printf("*****************************\n");
	while(ptea->next)
	{
		if(ptea->next->num==a)

		{
			printf("%d\t",ptea->next->num);
			printf("%s\t",ptea->next->name);
			printf("%s\t",ptea->next->code);
			printf("%d\t",ptea->next->class);
			printf("\n");
			break;
		}
		ptea=ptea->next;
	} 
	printf("*****************************\n");
	printf("按回车键返回上级界面。\n");
		setbuf(stdin,NULL);
		getchar();

}



//修改教师信息
int XGTeaT(int a)
{
	PTEA pt=&head1;
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息修改界面*   \n");
	printf("     **************************   \n");
	while(pt->next)
	{   
		if(pt->next->num==a)
		{
			printf("密码:");
			while(1!=scanf("%s",pt->next->code))
			{
			  printf("输入有误，请重新输入:");
			  setbuf(stdin,NULL);
			}
			printf("修改信息完成\n");
			printf("按回车键返回上层界面\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		pt=pt->next;
	}
}


//修改学生成绩信息
int XGStuT()
{
	PSTU p=&head;
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息修改界面*   \n");
	printf("     **************************   \n");
	printf("请输入想要修改学生的学号:");
	int i;
	while(1!=scanf("%d",&i))
	{
		printf("输入有误，请重新输入:");
		setbuf(stdin,NULL);
	}
	while(p->next)
	{   if(p->next->num==i)
		{
			printf("数学:");
			while(1!=scanf("%d",&p->next->sx))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}
			printf("语文:");
			while(1!=scanf("%d",&p->next->yw))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}
			printf("C语言:");
			while(1!=scanf("%d",&p->next->cyy))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}
			//对学生进行成绩从大到小排序
			int n=0;// 用来接受链表长度，控制循环次数
			int i,j;//循环变量
			int temp;//数据交换中间变量
			char a[20];//密码及姓名交换中间数组
			p=&head;
			while(p->next)//求链表长度
			{
				n++;
				p=p->next;
			}
			if(n!=0&&n!=1)
				for(i=0;i<n-1;i++)
				{
					p=&head;
					for(j=0;j<n-1-i;j++)
					{
						if((p->next->sx+p->next->yw+p->next->cyy)<(p->next->next->sx+p->next->next->yw+p->next->next->cyy))
						{
							temp=p->next->sx;//数学交换
							p->next->sx=p->next->next->sx;
							p->next->next->sx=temp;

							temp=p->next->yw;//语文交换
							p->next->yw=p->next->next->yw;
							p->next->next->yw=temp;

							temp=p->next->cyy;//c语言交换
							p->next->cyy=p->next->next->cyy;
							p->next->next->cyy=temp;

							temp=p->next->num;//学号交换
							p->next->num=p->next->next->num;
							p->next->next->num=temp;


							temp=p->next->age;//年龄交换
							p->next->age=p->next->next->age;
							p->next->next->age=temp;

							temp=p->next->class;//班级交换
							p->next->class=p->next->next->class;
							p->next->next->class=temp;


							strcpy(a,p->next->name);//交换姓名
							strcpy(p->next->name,p->next->next->name);
							strcpy(p->next->next->name,a);


							strcpy(a,p->next->code);//交换密码
							strcpy(p->next->code,p->next->next->code);
							strcpy(p->next->next->code,a);

						}
						p=p->next;
					}

				}




			p=&head;
			int k=0;
			for(i=0;i<n;i++)
			{
				p->next->mc=++k;
				p=p->next;
			}

			printf("修改信息完成\n");
			printf("按回车键返回上层界面\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		p=p->next;
	}



	printf("没有此学生信息\n");
	printf("按回车键返回\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}





//教师菜单
int MenuT(int a)
{

	int i,running=1;
	while(running)
	{
		PTEA pt=&head1;   
		while(pt->next)
		{   
			if(pt->next->num==a)
				break;
			pt=pt->next;
		}
		system("clear");
		printf("**********************************\n");
		printf("   欢迎%s教师来到教学管理系统   \n",pt->next->name);
		printf("     1.显示所有学生信息         \n");
		printf("     2.查找学生信息             \n");
		printf("     3.修改学生成绩信息         \n");
		printf("     4.保存学生信息             \n");
		printf("     5.显示教师个人信息         \n");
		printf("     6.修改教师个人密码         \n");
		printf("     7.保存教师信息             \n");
		printf("     8.退出                     \n");
		printf("**********************************\n");
		printf("请选择操作:");
		while(!scanf("%d",&i)||i<1||i>8)
		{
			printf("输入有误，请重新选择:");
			setbuf(stdin,NULL);
		}
		switch(i)
		{
			case 1:ShowAllStu();break;
			case 2:CXStu();break;
			case 3:XGStuT();break;
			case 4:BCStu();break;
			case 5:ShowTea(a);break;
			case 6:XGTeaT(a);break;
			case 7:BCTea();break;
			case 8:running=TC();break;
		}
	}
	return 0;
}




