#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

STU head;																	//定义储存学生信息的头节点
TEA head1;																	//定义储存老师信息的头节点

int DRStu()																	//将学生信息文件读入系统
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

//退出函数
int   TC()
{
	int i;
	printf("输入1继续操作,输入0返回上级界面,如有数据更改请注意保存:\n");
	scanf("%d",&i);
	return i;
}
//保存学生信息
int BCStu()
{
	system("clear");
	printf("     **************************   \n");
	printf("     *欢迎来到学生信息保存界面*   \n");
	printf("     **************************   \n");
	PSTU p=&head;
	FILE *pa;
	if((pa=fopen("student.txt","w+"))==NULL)
	{
		printf("打开文件失败。");
		printf("按回车键返回上个界面\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	while(p->next)
	{
		fprintf(pa,"%d ",p->next->num);
		fprintf(pa,"%s ",p->next->name);
		fprintf(pa,"%s ",p->next->code);
		fprintf(pa,"%d ",p->next->age);
		fprintf(pa,"%d ",p->next->class);
		fprintf(pa,"%d ",p->next->sx);
		fprintf(pa,"%d ",p->next->yw);
		fprintf(pa,"%d ",p->next->cyy);
		fprintf(pa,"%d ",p->next->mc);
		p=p->next;
	}
	fclose(pa);
	printf("保存完毕\n");
	printf("按回车键返回上个界面\n");
		setbuf(stdin,NULL);
		getchar();
	return 0;
}





//保存老师信息
int BCTea()
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
					running=TC();
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
									running=TC();
								}
								break;


						}
					}
				}
				break;
			case 4:
				{
					running=TC();
				}
				break;


		}
	}
}
