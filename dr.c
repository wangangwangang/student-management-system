#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
//定义储存学生信息的头节点
STU head;
//定义储存老师信息的头节点
TEA head1;



//将学生信息文件读入系统
int DRStu()
{
	system("clear");
	FILE *pa;
	head.next=NULL;
	PSTU ps=&head;
	PSTU pstu;

	if((pa=fopen("student.txt","rb"))==NULL)
	{
		printf("打开文件失败。");
		printf("按回车键继续\n");
		setbuf(stdin,NULL);				//清空键盘缓冲区
		getchar();						//作用是吸收一个字符，这里是用来控制时间
		return 0;
	}

	while(1)
	{

		pstu=(PSTU)malloc(sizeof(STU));			//在堆内存申请空间，储存学生信息
		pstu->next=NULL;						//申请新的链表节点时，一定要将指针区赋值为空

		if(!pstu)
		{
			printf("申请内存空间失败。\n");
			return 0;
		}

		if(fscanf(pa,"%d %s %s %d %d %d %d %d %d ",&pstu->num,pstu->name,pstu->code,&pstu->age,&pstu->class,&pstu->sx,&pstu->yw,&pstu->cyy,&pstu->mc)!=EOF)
		{
			while(ps->next)						//找到当前链表的最后一个节点的指针    
				ps=ps->next;
			ps->next=pstu;						//把新节点加入到最后那个节点的后面
		}
		else 
		{
			free(pstu);
			break;
		}
	}
	fclose(pa);
	ps->next->next=NULL;
	return 1;
}

//将教师信息文件读入系统
int DRTea()
{
	FILE *pa;
	head1.next=NULL;
	PTEA pt=&head1;
	PTEA ptea;

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

		ptea=(PTEA)malloc(sizeof(TEA));//在堆内存申请空间，储存教师信息
		ptea->next=NULL;//申请新的链表节点时，一定要将指针区赋值为空
		if(!ptea)
		{
			printf("申请内存空间失败。\n");
			return 0;
		}
		if(fscanf(pa,"%d %s %s %d",&ptea->num,ptea->name,ptea->code,&ptea->class)!=EOF)
		{
			while(pt->next)//找到当前链表的最后一个节点的指针
				pt=pt->next;
			pt->next=ptea;//把新节点加入到最后那个节点的后面
		}
		else
		{
			free(ptea);
			break;
		}
	}
	fclose(pa);
	pt->next->next=NULL;
	return 1;
}
