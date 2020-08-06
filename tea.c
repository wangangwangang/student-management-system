#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tea.h"

TEA head1;																		//定义教师头节点

int BCTea()																		//保存老师信息
{
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到教师信息保存界面*   \n");
	printf("     **************************   \n");
	PTEA pt=&head1;
	FILE *pa;
	if((pa=fopen("teacher.txt","w+"))==NULL)
	{
		printf("打开文件失败。");
		printf("按回车键返回上个界面\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	while(pt->next)
	{
		fprintf(pa,"%d ",pt->next->num);
		fprintf(pa,"%s ",pt->next->name);
		fprintf(pa,"%s ",pt->next->code);
		fprintf(pa,"%d ",pt->next->class);
		pt=pt->next;
	}
	fclose(pa);
	printf("保存完毕,按回车键继续\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}

PTEA GetPrevAddr1A(int num)														//返回指定序号教师节点的上一个节点的指针
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
	BCTea();
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
			BCTea();
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
			BCTea();
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












int DRTea()																	//载入老师信息
{
	FILE *pa;																//定义文件指针
	head1.next=NULL;														//老师头指针初始化
	PTEA pt=&head1;															//老师链表移动指针
	PTEA ptea;																//新增老师链表节点

	if((pa=fopen("teacher.txt","rb"))==NULL)
	{
		printf("打开文件失败。");
		printf("按回车键进入主界面\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}

	while(1)
	{

		ptea=(PTEA)malloc(sizeof(TEA));										//在堆内存申请空间，储存教师信息
		ptea->next=NULL;													//申请新的链表节点时，一定要将指针区赋值为空
		
		if(!ptea)
		{
			printf("申请内存空间失败。\n");
			return 0;
		}
		
		if(fscanf(pa,"%d %s %s %d",&ptea->num,ptea->name,ptea->code,&ptea->class)!=EOF)
		{
			pt->next=ptea;													//把新节点加入到最后那个节点的后面
			pt=ptea;														//移动指针指向最后一个节点
		}
		else
		{
			free(ptea);
			break;
		}
	}
	
	fclose(pa);
	
	return 1;
}

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
			BCTea();
			printf("修改信息完成\n");
			printf("按回车键返回上层界面\n");
		setbuf(stdin,NULL);
		getchar();
			return 0;
		}
		pt=pt->next;
	}
}










