CC := gcc
DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.c ${DIR_SRC}/menu/*.c ${DIR_SRC}/stu/*.c ${DIR_SRC}/tea/*.c)
OBJ = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir ${SRC}))

TARGET = go
CFLAGS = -g -O2 -Wall -I${DIR_INC}

${DIR_BIN}/${TARGET}:${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@

#								  \
${DIR_OBJ}/%.o:${DIR_SRC}/menu/*.c ${DIR_SRC}/*.c  ${DIR_SRC}/stu/*.c  ${DIR_SRC}/tea/*.c						\
	${CC} ${CFLAGS} -c $?		  \
	mv *.o ${DIR_OBJ}/

#\
${DIR_OBJ}/%.o:${SRC}			\
	${CC} ${CFLAGS} -c $?		\
	mv *.o ${DIR_OBJ}/

${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	${CC} ${CFLAGS} -c $?
	mv *.o ${DIR_OBJ}/

${DIR_OBJ}/%.o:${DIR_SRC}/menu/%.c
	${CC} ${CFLAGS} -c $?
	mv *.o ${DIR_OBJ}/ 
 
${DIR_OBJ}/%.o:${DIR_SRC}/stu/%.c
	${CC} ${CFLAGS} -c $?
	mv *.o ${DIR_OBJ}/ 

${DIR_OBJ}/%.o:${DIR_SRC}/tea/%.c
	${CC} ${CFLAGS} -c $?
	mv *.o ${DIR_OBJ}/ 


.PHONY:clean run
clean:
	rm -rf ${DIR_OBJ}/*.o ${DIR_BIN}/${TARGET}
run:
	${DIR_BIN}/${TARGET}

