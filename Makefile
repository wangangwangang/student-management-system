go:main.o  admin.o tea.o stu.o common.o menu.o
	gcc  main.o  admin.o tea.o stu.o common.o menu.o -o go
main.o:main.c menu.h common.h
	gcc -c main.c -o main.o
menu.o:menu.c admin.h tea.h stu.h  common.h 
	gcc -c menu.c -o menu.o
admin.o:admin.c  common.h
	gcc -c admin.c -o admin.o
tea.o:tea.c common.h
	gcc -c tea.c -o tea.o
stu.o:stu.c  common.h
	gcc -c stu.c -o stu.o
common.o:common.c common.h
	gcc -c common.c -o common.o
clean:
	rm -f *.o go


