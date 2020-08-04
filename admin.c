#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

extern STU head;												//声明学生链表头节点
extern TEA head1;												//声明教师链表头节点

PSTU GetPrevAddrA(int num)										//返回指定学号学生节点的上一个节点的指针
{

	PSTU ps=&head;												//定义学生移动指针
	
	while(ps->next)
	{
		if(ps->next->num==num)
			return ps;
		ps=ps->next;
	}
	
	return NULL;

}

//把学生信息节点加入到链表中
int AddStuA()
{  
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息添加界面*   \n");
	printf("     **************************   \n");

	PSTU pstu=(PSTU)malloc(sizeof(STU));//在堆内存申请空间，储存学生信息
	pstu->next=NULL;
	PSTU ps=&head;
	if(!pstu)
	{
		printf("申请内存空间失败。\n");
		return 0;;
	}
	printf("请输入学生学号:");
	while(1!=scanf("%d",&pstu->num))
	{
		printf("输入错误，请重新输入学生学号:");
		setbuf(stdin,NULL);
	}
	printf("请输入学生姓名:");
	scanf("%s",pstu->name);
	printf("请输入学生密码:");
	scanf("%s",pstu->code);
	printf("请输入学生年龄:");
	while(1!=scanf("%d",&pstu->age))
	{
		printf("输入错误，请重新输入学生年龄:");
		setbuf(stdin,NULL);
	}
	printf("请输入学生班级:");
	while(1!=scanf("%d",&pstu->class))
	{
		printf("输入错误，请重新输入学生班级:");
		setbuf(stdin,NULL);
	}
	printf("请输入学生数学成绩:");
	while(1!=scanf("%d",&pstu->sx))
	{
		printf("输入错误，请重新输入学生数学成绩:");
		setbuf(stdin,NULL);
	}
	printf("请输入学生语文成绩:");
	while(1!=scanf("%d",&pstu->yw))
	{
		printf("输入错误，请重新输入学生语文成绩:");
		setbuf(stdin,NULL);
	}
	printf("请输入学生C语言成绩:");
	while(1!=scanf("%d",&pstu->cyy))
	{
		printf("输入错误，请重新输入学生C语言成绩:");
		setbuf(stdin,NULL);
	}       

	//判断一下该学生信息是不是已经存在
	if(GetPrevAddrA(pstu->num))
	{
		printf("编号为%d的学生信息已经存在,按回车键进入上级界面。\n",pstu->num);
		free(pstu);//释放节点信息
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}

	while(ps->next)//找到当前链表的最后一个节点的指针
		ps=ps->next;
	//把新节点加入到最后那个节点的后面
	ps->next=pstu;
	pstu->next=NULL;

	//对学生进行成绩从大到小排序
	int n=0;// 用来接受链表长度，控制循环次数
	int i,j;//循环变量
	int temp;//数据交换中间变量
	char a[20];//密码及姓名交换中间数组
	ps=&head;
	while(ps->next)//求链表长度
	{
		n++;
		ps=ps->next;
	}
	if(n!=0&&n!=1)
		for(i=0;i<n-1;i++)
		{
			ps=&head;
			for(j=0;j<n-1-i;j++)
			{
				if((ps->next->sx+ps->next->yw+ps->next->cyy)<(ps->next->next->sx+ps->next->next->yw+ps->next->next->cyy))
				{
					temp=ps->next->sx;//数学交换
					ps->next->sx=ps->next->next->sx;
					ps->next->next->sx=temp;

					temp=ps->next->yw;//语文交换
					ps->next->yw=ps->next->next->yw;
					ps->next->next->yw=temp;

					temp=ps->next->cyy;//c语言交换
					ps->next->cyy=ps->next->next->cyy;
					ps->next->next->cyy=temp;

					temp=ps->next->num;//学号交换
					ps->next->num=ps->next->next->num;
					ps->next->next->num=temp;


					temp=ps->next->age;//年龄交换
					ps->next->age=ps->next->next->age;
					ps->next->next->age=temp;

					temp=ps->next->class;//班级交换
					ps->next->class=ps->next->next->class;
					ps->next->next->class=temp;


					strcpy(a,ps->next->name);//交换姓名
					strcpy(ps->next->name,ps->next->next->name);
					strcpy(ps->next->next->name,a);


					strcpy(a,ps->next->code);//交换密码
					strcpy(ps->next->code,ps->next->next->code);
					strcpy(ps->next->next->code,a);

				}
				ps=ps->next;
			}

		}
	//给排好序的学生名次赋值		
	ps=&head;
	int k=0;
	for(i=0;i<n;i++)
	{
		ps->next->mc=++k;
		ps=ps->next;
	}

	printf("新同学信息录入成功,按回车键进入上级界面。\n");
		setbuf(stdin,NULL);
		getchar();
	return 1;

}

//删除学生信息
int  DelStuA()
{
	system("clear");
	int n;
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息删除界面*   \n");
	printf("     **************************   \n");
	printf("请输入需要删除的学生学号:");
	while(1!=scanf("%d",&n))
	{
		printf("请重新输入学号:");
		setbuf(stdin,NULL);
	}
	PSTU p=&head;
	while(p->next)
	{
		if(p->next->num==n)
		{
			p->next=p->next->next;
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
			//给排好序的学生名次赋值
			p=&head;
			int k=0;
			for(i=0;i<n;i++)
			{
				p->next->mc=++k;
				p=p->next;
			}
			printf("删除学生信息成功,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;

		}
		p=p->next;
	}

	printf("没有此学生信息,按回车键继续。\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}

//修改学生信息
int XGStuA()
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
		printf("请重新输入学号:");
		setbuf(stdin,NULL);
	}
	while(p->next)
	{   if(p->next->num==i)
		{
			printf("姓名:");
			scanf("%s",p->next->name);
			printf("密码:");
			scanf("%s",p->next->code);
			printf("年龄:");
			while(1!=scanf("%d",&p->next->age))
			{
				printf("请重新输入年龄:");
				setbuf(stdin,NULL);
			}
			printf("班级:");
			while(1!=scanf("%d",&p->next->class))
			{
				printf("请重新输入班级:");
				setbuf(stdin,NULL);
			}
			printf("数学:");
			while(1!=scanf("%d",&p->next->sx))
			{
				printf("请重新输入数学:");
				setbuf(stdin,NULL);
			}
			printf("语文:");
			while(1!=scanf("%d",&p->next->yw))
			{
				printf("请重新输入语文:");
				setbuf(stdin,NULL);
			}
			printf("C语言:");
			while(1!=scanf("%d",&p->next->cyy))
			{
				printf("请重新输入C语言:");
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
			//给排好序的学生名次赋值
			p=&head;
			int k=0;
			for(i=0;i<n;i++)
			{
				p->next->mc=++k;
				p=p->next;
			}
			printf("修改信息完成,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		p=p->next;
	}

	printf("没有此学生信息,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}

//返回指定序号教师节点的上一个节点的指针
PTEA GetPrevAddr1A(int num)
{
	PTEA ptea=&head1;
	while(ptea->next)
	{
		if(ptea->next->num==num)
			return ptea;
		ptea=ptea->next;
	}
	return NULL;
}

//把教师信息节点加入到链表中
int AddTeaA()
{
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息添加界面*   \n");
	printf("     **************************   \n");

	PTEA ptea=(PTEA)malloc(sizeof(TEA));//在堆内存申请空间，储存学生信息
	ptea->next=NULL;
	PTEA pt=&head1;
	if(!ptea)
	{
		printf("申请内存空间失败。\n");
		return 0;
	}
	printf("请输入教师序号:");
	while(1!=scanf("%d",&ptea->num))
	{
		printf("输入错误，请重新输入教师序号:");
		setbuf(stdin,NULL);
	}
	printf("请输入教师姓名:");
	scanf("%s",ptea->name);
	printf("请输入教师密码:");
	scanf("%s",ptea->code);
	printf("请输入教师班级:");
	while(1!=scanf("%d",&ptea->class))
	{
		printf("输入错误，请重新输入教师班级:");
		setbuf(stdin,NULL);
	}


	//判断一下该教师信息是不是已经存在
	if(GetPrevAddr1A(ptea->num))
	{
		printf("编号为%d的教师信息已经存在,按回车键进入上级界面。\n",ptea->num);
		free(ptea);//释放节点信息
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}

	while(pt->next)//找到当前链表的最后一个节点的指针
		pt=pt->next;
	//把新节点加入到最后那个节点的后面
	pt->next=ptea;
	ptea->next=NULL;
	printf("新教师信息录入成功,按回车键进入上级界面。\n");
		setbuf(stdin,NULL);
		getchar();
	return 1;

}

//删除教师信息
int  DelTeaA()
{
	system("clear");
	int n;
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息删除界面*   \n");
	printf("     **************************   \n");
	printf("请输入需要删除的教师序号:");
	scanf("%d",&n);
	PTEA pt=&head1;
	while(pt->next)
	{
		if(pt->next->num==n)
		{
			pt->next=pt->next->next;
			printf("删除教师信息成功,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;

		}
		pt=pt->next;
	}
	printf("没有此教师信息,按回车键继续。\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}

//显示所有教师信息
void ShowAllTeaA()
{
	system("clear");
	PTEA ptea=&head1;
	printf("*****************************\n");
	printf("序号\t姓名\t密码\t班级\n");
	printf("*****************************\n");
	while(ptea->next)
	{
		printf("%d\t",ptea->next->num);
		printf("%s\t",ptea->next->name);
		printf("%s\t",ptea->next->code);
		printf("%d\t",ptea->next->class);
		printf("\n");
		ptea=ptea->next;
	} 
	printf("*****************************\n");
	printf("按回车键返回上级界面。\n");
		setbuf(stdin,NULL);
		getchar();

}

//查找教师信息
int CXTeaA()
{
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息查询界面*   \n");
	printf("     **************************   \n");
	printf("请输入想要查询教师的序号:");
	int i;
	scanf("%d",&i);
	PTEA pt=&head1;
	while(pt->next)
	{   if(pt->next->num==i)
		{
			printf("序号\t姓名\t密码\t班级\t\n");
			printf("%d\t",pt->next->num);
			printf("%s\t",pt->next->name);
			printf("%s\t",pt->next->code);
			printf("%d\t",pt->next->class);
			printf("\n");
			printf("按回车键返回上层界面\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		pt=pt->next;
	}
	printf("没有此教师信息,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}



//修改教师信息
int XGTeaA()
{
	PTEA pt=&head1;
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息修改界面*   \n");
	printf("     **************************   \n");
	printf("请输入想要修改教师的序号:");
	int i;
	scanf("%d",&i);
	while(pt->next)
	{   if(pt->next->num==i)
		{
			printf("姓名:");
			scanf("%s",pt->next->name);
			printf("密码:");
			scanf("%s",pt->next->code);
			printf("班级:");
			scanf("%d",&pt->next->class);
			printf("修改信息完成,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		pt=pt->next;
	}
	printf("没有此教师信息,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}




//超级用户菜单
int MenuA()
{

	int i,running=1;
	while(running)
	{

		system("clear");
		printf("*******************************************************\n");
		printf("*               欢迎Admin登录教学管理系统             *\n");
		printf("*******************************************************\n");
		printf("* 1.添加学生信息   2.显示所有学生信息   3.删除学生信息*\n");
		printf("* 4.查找学生信息   5.修改学生信息       6.保存学生信息*\n");
		printf("* 7.添加教师信息   8.显示所有教师信息   9.删除教师信息*\n");
		printf("*10.查找教师信息  11.修改教师信息      12.保存教师信息*\n");
		printf("*13.退出                                              *\n");
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
			case 6:BCStu();break;
			case 7:AddTeaA();break;
			case 8:ShowAllTeaA();break;
			case 9:DelTeaA();break;
			case 10:CXTeaA();break;
			case 11:XGTeaA();break;
			case 12:BCTea();break;
			case 13:running=TC();break;
		}
	}
	return 0;
}








