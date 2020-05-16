go:main.o dr.o admin.o tea.o stu.o common.o
	gcc  main.o dr.o admin.o tea.o stu.o common.o -o go
main.o:main.c dr.h admin.h tea.h stu.h common.h
	gcc -c main.c -o main.o
dr.o:dr.c  common.h
	gcc -c dr.c -o dr.o
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


