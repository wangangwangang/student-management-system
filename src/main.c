#include <stdio.h>
#include "menu.h"
#include "../include/stu.h"
#include "../include/tea.h"


//主函数
int main()
{
	
	if(DRStu()==0)					//载入学生信息
		return 0;
	if(DRTea()==0)					//载入老师信息
		return 0;
	
	menu_login();										

	return 1;

}
