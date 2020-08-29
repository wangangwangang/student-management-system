#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/tea.h"
#include "../../include/stu.h"

extern STU head;																	//声明学生头节点
extern TEA head1;																	//声明老师头节点

int menu_stu(int a)																	//学生菜单
{

	int i;																			//菜单选项
	int running=1;																	//循环控制变量
	PSTU ps=&head;																//学生链表移动指针

	while(running)
	{

		while(ps->next)																//找到学生节点
		{
			if(ps->next->num==a)
				break;
			else
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

int menu_tea(int a)																		//教师菜单
{

	int i;																				//菜单选项
	int running=1;																		//循环控制变量
	PTEA pt=&head1;   
	
	while(running)
	{
		
		while(pt->next)																	//遍历链表，找到特定节点
		{   
			if(pt->next->num==a)
				break;
			else
				pt=pt->next;
		}
		
		system("clear");
		printf("**********************************\n");
		printf("   欢迎%s教师来到教学管理系统   \n",pt->next->name);
		printf("     1.显示所有学生信息         \n");
		printf("     2.查找学生信息             \n");
		printf("     3.修改学生成绩信息         \n");
		printf("     4.显示教师个人信息         \n");
		printf("     5.修改教师个人密码         \n");
		printf("     6.退出                     \n");
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
			case 4:ShowTea(a);break;
			case 5:XGTeaT(a);break;
			case 6:running=0;break;
		}
	}
	return 0;
}



//超级用户菜单
int menu_admin()																			//超级用户菜单
{

	int i;																					//菜单控制项
	int running=1;																			//循环控制变量
	
	while(running)
	{

		system("clear");
		printf("*******************************************************\n");
		printf("*               欢迎Admin登录教学管理系统             *\n");
		printf("*******************************************************\n");
		printf("* 1.添加学生信息   2.显示所有学生信息   3.删除学生信息*\n");
		printf("* 4.查找学生信息   5.修改学生信息    		      *\n");
		printf("* 6.添加教师信息   7.显示所有教师信息   8.删除教师信息*\n");
		printf("* 9.查找教师信息  10.修改教师信息      	              *\n");
		printf("*11.退出                                              *\n");
		printf("*******************************************************\n");
		printf("请选择操作:");
		while(!scanf("%d",&i)||i<1||i>13)
		{
			printf("输入有误，请重新选择:");
			setbuf(stdin,NULL);
		}
		
		switch(i)
		{
			case 1:AddStuA();break;
			case 2:ShowAllStu();break;
			case 3:DelStuA();break;
			case 4:CXStu();break;
			case 5:XGStuA();break;
			case 6:AddTeaA();break;
			case 7:ShowAllTeaA();break;
			case 8:DelTeaA();break;
			case 9:CXTeaA();break;
			case 10:XGTeaA();break;
			case 11:running=0;break;
		}
	}
	
	return 0;
}

void menu_login()															//登陆界面
{
	
	int c;																	//首界面选项
	int running=1;															//登录界面循环变量
	int k=1;																//用来控制密码输错次数
	int i;																	//用来接受用户名（学生学号或老师序号）
	char a[20];																//用来接受用户密码
	PSTU ps=&head;															//定义学生结构体指针,指向学生链表的头节点
	PTEA pt=&head1;															//定义教师结构体指针,指向老师链表的头节点
	
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

					ps=&head;
					while(ps->next)											//循环遍历学生链表
					{
						if(ps->next->num==i)
						{
							if(0==strcmp(ps->next->code,a))
							{
								menu_stu(i);									//进入学生操作界面
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
                   
				    pt=&head1;
					while(pt->next)											//循环遍历老师链表
					{
						if(pt->next->num==i)
						{
							if(0==strcmp(pt->next->code,a))
							{
								menu_tea(i);									//进入老师操作界面
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
							menu_admin();										//进入管理员登录界面
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
