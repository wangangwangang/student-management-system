go:main.o  tea.o stu.o menu.o
	gcc  main.o   tea.o stu.o  menu.o -o go
main.o:main.c menu.h stu.h tea.h
	gcc -c main.c -o main.o
menu.o:menu.c  tea.h stu.h  
	gcc -c menu.c -o menu.o
tea.o:tea.c tea.h
	gcc -c tea.c -o tea.o
stu.o:stu.c  stu.h
	gcc -c stu.c -o stu.o
clean:
	rm -f *.o go


