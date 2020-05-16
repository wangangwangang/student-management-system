#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "tea.h"
#include "stu.h"
#include "dr.h"
#include "common.h"
//定义储存学生信息的头节点
STU head;

//定义储存老师信息的头节点
TEA head1;

//主函数
void main()
{
	int i;//用来接受用户名（学生学号或老师序号）
	int running=1;//控制登录界面是否运行
	char a[20];//用来接受用户密码
	while(running)
	{

		static int k=1;//用来控制密码输错次数a
		if(k>3)
		{
			printf("您已经输错三次,按回车键退出\n");
			setbuf(stdin,NULL);
			getchar();
			break;
		}
		PSTU ps=&head;//定义一个学生结构体指针指向储存学生信息的链表的头节点
		PTEA pt=&head1;//定义一个教师结构体指针指向储存老师信息的链表的头节点
		system("clear");
		printf("**************************************\n");
		printf("*        欢迎登录学生管理系统        *\n");
		printf("*             1.退出                 *\n");
		printf("*             2.登录                 *\n");
		printf("**************************************\n");
		int c;
		printf("请选择操作:");
		while(1!=scanf("%d",&c)||c<1||c>2)
		{
			printf("请重新输入数字(1-2):");
			setbuf(stdin,NULL);
		}
		switch(c)
		{
			case 1:running=TC();break;
			case 2:
			       {
				       DRStu();//在系统开始前将学生信息读入
				       DRTea();//在系统开始前将老师信息读入
				       system("clear");
				       printf("************************************\n");
				       printf("*        请输入用户名及密码        *\n");
				       printf("************************************\n");
				       printf("            用户名:");
				       scanf("%d",&i);
				       printf("            密码:");
				       printf("\033[8m");
				       scanf("%s",a);
				       printf("\033[0m");

				       while(ps->next)
				       {
					       if(ps->next->num==i)
						       if(0==strcmp(ps->next->code,a))
						       {
							       MenuS(i);
							       setbuf(stdin,NULL);
							       break;
						       }
						       else
						       {
							       printf("亲爱的同学密码不对请重新输入\n");
							       k++;
			setbuf(stdin,NULL);
			getchar();
							       
							
							       break;
						       }

					       ps=ps->next;
				       }

				       if(ps->next!=NULL)	
					       continue;

				       while(pt->next)
				       {
					       if(pt->next->num==i)
						       if(0==strcmp(pt->next->code,a))
						       {
							       MenuT(i);
							       setbuf(stdin,NULL);
							       break;
						       }
						       else
						       {
							       printf("尊敬的老师密码不对请重新输入\n");
							       k++;
			setbuf(stdin,NULL);
			getchar();
							       break;
						       }
					       pt=pt->next;
				       }
				       if(pt->next!=NULL)	
					       continue;

				       if(i==111111)
					       if(0==strcmp(a,"123456"))
					       {
						       MenuA();
						       setbuf(stdin,NULL);
						       continue;
					       }
					       else
					       {
						       printf("尊敬的超级用户密码错误请重新输入\n");
						       k++;
			setbuf(stdin,NULL);
			getchar();
						       continue;
					       }
				       printf("用户不存在，请重新输入\n");
				       k++;
				       setbuf(stdin,NULL);
				       system("sleep 2");
				       continue;
			       }
			       break;
		}
	}
}
