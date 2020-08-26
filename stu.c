#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stu.h"

STU head;																//定义学生链表头节点

//保存学生信息
int BCStu()
{
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息保存界面*   \n");
	printf("     **************************   \n");
	PSTU ps=&head;
	FILE *pa;
	if((pa=fopen("student.txt","w+"))==NULL)
	{
		printf("打开文件失败。");
		printf("按回车键返回上个界面\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	while(ps->next)
	{
		fprintf(pa,"%d ",ps->next->num);
		fprintf(pa,"%s ",ps->next->name);
		fprintf(pa,"%s ",ps->next->code);
		fprintf(pa,"%d ",ps->next->age);
		fprintf(pa,"%d ",ps->next->class);
		fprintf(pa,"%d ",ps->next->sx);
		fprintf(pa,"%d ",ps->next->yw);
		fprintf(pa,"%d ",ps->next->cyy);
		fprintf(pa,"%d ",ps->next->mc);
		ps=ps->next;
	}
	fclose(pa);
	printf("保存完毕\n");
	printf("按回车键返回上个界面\n");
	setbuf(stdin,NULL);
	getchar();
	return 0;
}



//修改学生成绩信息
int XGStuT()
{
	PSTU ps=&head;
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
	while(ps->next)
	{   
		if(ps->next->num==i)
		{
			
			printf("数学:");
			while(1!=scanf("%d",&ps->next->sx))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}
			printf("语文:");
			while(1!=scanf("%d",&ps->next->yw))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}
			printf("C语言:");
			while(1!=scanf("%d",&ps->next->cyy))
			{
				printf("输入有误，请重新输入:");
				setbuf(stdin,NULL);
			}


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




			ps=&head;
			int k=0;
			for(i=0;i<n;i++)
			{
				ps->next->mc=++k;
				ps=ps->next;
			}
			
			BCStu();
			printf("修改信息完成\n");
			printf("按回车键返回上层界面\n");
			setbuf(stdin,NULL);
			getchar();
			return 0;
		}
		else
			ps=ps->next;
	}



	printf("没有此学生信息\n");
	printf("按回车键返回\n");
	setbuf(stdin,NULL);
	getchar();
	return 0;
}








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
	BCStu();
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
			BCStu();
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
			BCStu();
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










int DRStu()																	//载入学生信息
{

	FILE *pa;																//文件指针变量
	head.next=NULL;															//头节点初始化
	PSTU ps=&head;															//学生链表移动指针
	PSTU pstu;																//新增节点指针变量

	if((pa=fopen("student.txt","rb"))==NULL)								//打开文件，成功返回指向文件的指针，失败发返回NULL
	{
		printf("打开文件失败。");
		printf("按回车键继续\n");
		setbuf(stdin,NULL);													//清空键盘缓冲区
		getchar();															//作用是吸收一个字符，这里是用来控制上述提示信息的停留时间
		return 0;
	}

	while(1)																//循环遍历文件
	{

		pstu=(PSTU)malloc(sizeof(STU));										//在堆内存申请空间，储存学生信息
		pstu->next=NULL;													//申请新的链表节点时，一定要将指针区赋值为空

		if(!pstu)
		{
			printf("申请内存空间失败。\n");
			return 0;
		}

		if(fscanf(pa,"%d %s %s %d %d %d %d %d %d ",&pstu->num,pstu->name,pstu->code,&pstu->age,&pstu->class,&pstu->sx,&pstu->yw,&pstu->cyy,&pstu->mc)!=EOF)
		{
			ps->next=pstu;													//把新节点加入到最后那个节点的后面
			ps=pstu;														//将移动指针指向最后一个节点
		}
		else 
		{
			free(pstu);
			break;
		}
	}
	fclose(pa);
	return 1;
}

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

//查找学生信息
int CXStu()
{
	int running=1;
	while(running)
	{
		int k;//控制查询方式的变量
		system("clear");
		printf("     **************************   \n");
		printf("     *欢迎来到学生信息查询界面*   \n");
		printf("     *      1.按学号查找      *   \n");
		printf("     *      2.按姓名查找      *   \n");
		printf("     *      3.按班级查找      *   \n");
		printf("     *      4.退出            *   \n");
		printf("     **************************   \n");
		printf("请选择想要查询信息的方式:");
		while(1!=scanf("%d",&k)||k<1||k>4)
		{
			printf("请重新输入数字(1-4):");
			setbuf(stdin,NULL);
		}
		switch(k)
		{
			case 1:
				{
					int i;//用来接受学生的学号
					printf("请输入学生学号:");
					scanf("%d",&i);
					PSTU p=&head;
					while(p->next)
					{   if(p->next->num==i)
						{
							printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
							printf("%d\t",p->next->num);
							printf("%s\t",p->next->name);
							printf("%s\t",p->next->code);
							printf("%d\t",p->next->age);
							printf("%d\t",p->next->class);
							printf("%d\t",p->next->sx);
							printf("%d\t",p->next->yw);
							printf("%d\t",p->next->cyy);
							printf("%d\t",p->next->mc);
							printf("\n");
							printf("按回车键返回上层界面\n");
							setbuf(stdin,NULL);
							getchar();
							break;
						}
						p=p->next;
					}
					if(p->next==NULL)
					{
						printf("没有此学生信息\n");
						printf("按回车键返回\n");
						setbuf(stdin,NULL);
						getchar();
						break;
					}
					break;
				}
			case 2:
				{
					char a[20];//用来接受学生姓名
					int s1=0;//用来统计同一姓名学生的个数
					printf("请输入学生姓名:");
					scanf("%s",a);
					PSTU p=&head;
					while(p->next)
					{   if(0==strcmp(p->next->name,a))
						{
							printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
							printf("%d\t",p->next->num);
							printf("%s\t",p->next->name);
							printf("%s\t",p->next->code);
							printf("%d\t",p->next->age);
							printf("%d\t",p->next->class);
							printf("%d\t",p->next->sx);
							printf("%d\t",p->next->yw);
							printf("%d\t",p->next->cyy);
							printf("%d\t",p->next->mc);
							printf("\n");
							s1++;
						}
						p=p->next;
					}
					if(s1!=0)
					{
						printf("有%d个名字叫%s的学生\n",s1,a);
						printf("按回车键返回上层界面\n");
						setbuf(stdin,NULL);
						getchar();
						break;
					}
					printf("没有此学生信息\n");
					printf("按回车键返回\n");
					setbuf(stdin,NULL);
					getchar();
					break;
				}
				break;

			case 3:
				{

					int i;//用来接受班级号
					int sum=0;//用来统计一共有多少个人
					printf("请输入班级号:");
					scanf("%d",&i);
					PSTU p=&head;
					while(p->next)
					{   if(p->next->class==i)
						{
							printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
							printf("%d\t",p->next->num);
							printf("%s\t",p->next->name);
							printf("%s\t",p->next->code);
							printf("%d\t",p->next->age);
							printf("%d\t",p->next->class);
							printf("%d\t",p->next->sx);
							printf("%d\t",p->next->yw);
							printf("%d\t",p->next->cyy);
							printf("%d\t",p->next->mc);
							printf("\n");
							sum++;
						}
						p=p->next;
					}
					if(k!=0)
					{
						printf("%d班一共有%d个学生\n",i,sum);
						printf("按回车键返回上层界面\n");
						setbuf(stdin,NULL);
						getchar();
						break;
					}
					printf("没有此学生信息\n");
					printf("按回车键返回\n");
					setbuf(stdin,NULL);
					getchar();
					break;

				}
				break;
			case 4:
				{
					running=0;
				}
				break;
		}
	}
	return 0;
}





//显示所有学生信息
void ShowAllStu()
{
	int running=1;
	while(running)
	{
		int k;//控制查询方式的变量
		system("clear");
		printf("     **************************   \n");
		printf("     *欢迎来到学生信息显示界面*   \n");
		printf("     *      1.按名次显示      *   \n");
		printf("     *      2.按学号显示      *   \n");
		printf("     *      3.按某课程成绩    *   \n");
		printf("     *      4.退出            *   \n");
		printf("     **************************   \n");
		printf("请选择想要查询信息的方式:");
		while(1!=scanf("%d",&k)||k<1||k>4)
		{
			printf("请重新输入数字(1-4):");
			setbuf(stdin,NULL);
		}
		PSTU p=&head;

		switch(k)
		{
			case 1:
				{
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

									temp=p->next->mc;//名次交换
									p->next->mc=p->next->next->mc;
									p->next->next->mc=temp;


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
					printf("***********************************************************\n");
					printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
					printf("***********************************************************\n");
					while(p->next)
					{
						printf("%d\t",p->next->num);
						printf("%s\t",p->next->name);
						printf("%s\t",p->next->code);
						printf("%d\t",p->next->age);
						printf("%d\t",p->next->class);
						printf("%d\t",p->next->sx);
						printf("%d\t",p->next->yw);
						printf("%d\t",p->next->cyy);
						printf("%d\t",p->next->mc);
						printf("\n");
						p=p->next;
					} 
					printf("***********************************************************\n");
					printf("按回车键返回上级界面。\n");
					setbuf(stdin,NULL);
					getchar();
				}
				break;
			case 2:
				{

					//对学生进行学号从小到大排序
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
								if((p->next->num)>(p->next->next->num))
								{
									temp=p->next->sx;//数学交换
									p->next->sx=p->next->next->sx;
									p->next->next->sx=temp;

									temp=p->next->yw;//语文交换
									p->next->yw=p->next->next->yw;
									p->next->next->yw=temp;

									temp=p->next->mc;//名次交换
									p->next->mc=p->next->next->mc;
									p->next->next->mc=temp;


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
					printf("***********************************************************\n");
					printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
					printf("***********************************************************\n");
					while(p->next)
					{
						printf("%d\t",p->next->num);
						printf("%s\t",p->next->name);
						printf("%s\t",p->next->code);
						printf("%d\t",p->next->age);
						printf("%d\t",p->next->class);
						printf("%d\t",p->next->sx);
						printf("%d\t",p->next->yw);
						printf("%d\t",p->next->cyy);
						printf("%d\t",p->next->mc);
						printf("\n");
						p=p->next;
					} 
					printf("***********************************************************\n");
					printf("按回车键返回上级界面。\n");
					setbuf(stdin,NULL);
					getchar();
				}
				break;
			case  3:{ 
						int running=1;
						while(running)
						{
							int k;//控制查询方式的变量
							float s[3]={0};//用来计算单科总成绩，从而求出平均分
							system("clear");
							printf("     ********************************   \n");
							printf("     *欢迎来到按单科成绩排序显示界面*   \n");
							printf("     *       1.按数学显示           *   \n");
							printf("     *       2.按语文显示           *   \n");
							printf("     *       3.按c语言显示          *   \n");
							printf("     *       4.退出                 *   \n");
							printf("     ********************************   \n");
							printf("请选择想要查询信息的方式:");
							while(1!=scanf("%d",&k)||k<1||k>4)
							{
								printf("请重新输入数字(1-4):");
								setbuf(stdin,NULL);
							}
							PSTU p=&head;
							switch(k)
							{
								case 1:
									{
										//对学生进行数学成绩从大到小排序
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
													if((p->next->sx)<(p->next->next->sx))
													{
														temp=p->next->sx;//数学交换
														p->next->sx=p->next->next->sx;
														p->next->next->sx=temp;

														temp=p->next->yw;//语文交换
														p->next->yw=p->next->next->yw;
														p->next->next->yw=temp;

														temp=p->next->mc;//名次交换
														p->next->mc=p->next->next->mc;
														p->next->next->mc=temp;


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
										printf("***********************************************************\n");
										printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
										printf("***********************************************************\n");
										while(p->next)
										{
											printf("%d\t",p->next->num);
											printf("%s\t",p->next->name);
											printf("%s\t",p->next->code);
											printf("%d\t",p->next->age);
											printf("%d\t",p->next->class);
											printf("%d\t",p->next->sx);
											printf("%d\t",p->next->yw);
											printf("%d\t",p->next->cyy);
											printf("%d\t",p->next->mc);
											printf("\n");
											s[0]+=p->next->sx;
											p=p->next;
										} 

										printf("***********************************************************\n");

										printf("数学的平均分为%f\n",s[0]/n);
										printf("按回车键返回上级界面。\n");

										setbuf(stdin,NULL);
										getchar();
									}
									break;

								case 2:
									{
										//对学生进行语文成绩从大到小排序
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
													if((p->next->yw)<(p->next->next->yw))
													{
														temp=p->next->sx;//数学交换
														p->next->sx=p->next->next->sx;
														p->next->next->sx=temp;

														temp=p->next->yw;//语文交换
														p->next->yw=p->next->next->yw;
														p->next->next->yw=temp;

														temp=p->next->mc;//名次交换
														p->next->mc=p->next->next->mc;
														p->next->next->mc=temp;


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
										printf("***********************************************************\n");
										printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
										printf("***********************************************************\n");
										while(p->next)
										{
											printf("%d\t",p->next->num);
											printf("%s\t",p->next->name);
											printf("%s\t",p->next->code);
											printf("%d\t",p->next->age);
											printf("%d\t",p->next->class);
											printf("%d\t",p->next->sx);
											printf("%d\t",p->next->yw);
											printf("%d\t",p->next->cyy);
											printf("%d\t",p->next->mc);
											printf("\n");
											s[1]+=p->next->yw;
											p=p->next;
										} 
										printf("***********************************************************\n");

										printf("语文的平均分为%f\n",s[1]/n);
										printf("按回车键返回上级界面。\n");
										setbuf(stdin,NULL);
										getchar();
									}
									break;

								case 3:
									{
										//对学生进行C语言成绩从大到小排序
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
													if((p->next->cyy)<(p->next->next->cyy))
													{
														temp=p->next->sx;//数学交换
														p->next->sx=p->next->next->sx;
														p->next->next->sx=temp;

														temp=p->next->yw;//语文交换
														p->next->yw=p->next->next->yw;
														p->next->next->yw=temp;

														temp=p->next->mc;//名次交换
														p->next->mc=p->next->next->mc;
														p->next->next->mc=temp;


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
										printf("***********************************************************\n");
										printf("学号\t姓名\t密码\t年龄\t班级\t数学\t语文\tC语言\t名次\n");
										printf("***********************************************************\n");
										while(p->next)
										{
											printf("%d\t",p->next->num);
											printf("%s\t",p->next->name);
											printf("%s\t",p->next->code);
											printf("%d\t",p->next->age);
											printf("%d\t",p->next->class);
											printf("%d\t",p->next->sx);
											printf("%d\t",p->next->yw);
											printf("%d\t",p->next->cyy);
											printf("%d\t",p->next->mc);
											printf("\n");
											s[2]+=p->next->cyy;
											p=p->next;
										} 
										printf("***********************************************************\n");

										printf("c语言的平均分为%f\n",s[2]/n);
										printf("按回车键返回上级界面。\n");
										setbuf(stdin,NULL);
										getchar();
									}
									break;
								case 4:
									{
										running=0;
									}
									break;


							}
						}
					}
					break;
			case 4:
					{
						running=0;
					}
					break;


		}
	}
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

