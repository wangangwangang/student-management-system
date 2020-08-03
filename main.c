#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "admin.h"
#include "tea.h"
#include "stu.h"
#include "dr.h"
#include "common.h"

STU head;																	//定义储存学生信息的头节点
TEA head1;																	//定义储存老师信息的头节点

//主函数
void main()
{
	int i;																	//用来接受用户名（学生学号或老师序号）
	static int k=1;															//用来控制密码输错次数
	int running=1;															//控制登录界面是否运行
	char a[20];																//用来接受用户密码
	int c;																	//首界面选项
	PSTU ps=&head;															//定义一个学生结构体指针指向储存学生信息的链表的头节点
	PTEA pt=&head1;															//定义一个教师结构体指针指向储存老师信息的链表的头节点

	DRStu();																//在系统开始前将学生信息读入
	DRTea();																//在系统开始前将老师信息读入
	
	while(running)
	{

		if(k>3)															    //控制登录错误次数
		{
			printf("您已经输错三次,按回车键退出\n");
			setbuf(stdin,NULL);
			getchar();
			break;
		}

		system("clear");													//进入首界面
		printf("**************************************\n");
		printf("*        欢迎登录学生管理系统        *\n");
		printf("*             1.退出                 *\n");
		printf("*             2.登录                 *\n");
		printf("**************************************\n");
		printf("请选择操作:");
		setbuf(stdin,NULL);
		while(1!=scanf("%d",&c)||c<1||c>2)
		{
			printf("请重新输入数字(1-2):");
			setbuf(stdin,NULL);
		}
		
		switch(c)
		{
			case 1:
				{
					running=0;
					break;
				}
			case 2:
				{
					system("clear");										//进入用户登录界面
					printf("************************************\n");
					printf("*        请输入用户名及密码        *\n");
					printf("************************************\n");
					printf("            用户名:");
					setbuf(stdin,NULL);
					scanf("%d",&i);
					printf("            密码:");
					printf("\033[8m");
					setbuf(stdin,NULL);
					scanf("%s",a);
					printf("\033[0m");

					while(ps->next)											//循环遍历学生链表
					{
						if(ps->next->num==i)
						{
							if(0==strcmp(ps->next->code,a))
							{
								MenuS(i);									//进入学生操作界面
								break;
							}
							else
							{
								printf("亲爱的同学密码不对请重新输入,按任意键继续\n");
								k++;
								setbuf(stdin,NULL);							//清空键盘缓冲区
								getchar();									//吸收任意字符，目的是让上述提示信息固定，输入任意字符继续
								break;
							}
						}
						else
						{
							ps=ps->next;
						}
					}
					if(ps->next!=NULL)	
						continue;

					while(pt->next)											//循环遍历老师链表
					{
						if(pt->next->num==i)
						{
							if(0==strcmp(pt->next->code,a))
							{
								MenuT(i);									//进入老师操作界面
								break;
							}
							else
							{
								printf("尊敬的老师密码不对请重新输入，按任意键继续\n");
								k++;
								setbuf(stdin,NULL);
								getchar();
								break;
							}
						}
						else
						{
							pt=pt->next;
						}
					}
					if(pt->next!=NULL)	
						continue;

					if(i==111111)
					{
						if(0==strcmp(a,"123456"))
						{
							MenuA();										//进入管理员登录界面
							continue;
						}
						else
						{
							printf("尊敬的超级用户密码错误请重新输入，按任意键继续\n");
							k++;
							setbuf(stdin,NULL);
							getchar();
							continue;
						}
					}
					else
					{
						printf("用户不存在，请重新输入，按任意键继续\n");
						k++;
						setbuf(stdin,NULL);
						getchar();
						continue;
					}
					break;
				}
		}
	}
}
