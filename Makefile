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
	@echo "start link..................."
	${CC} ${CFLAGS} $+ -o $@
	@echo "stop link...................."

${DIR_OBJ}/%.o:${SRC}
	@echo "start huibain..............."
	${CC} ${CFLAGS} -c $?
	mv *.o ${DIR_OBJ}/
	@echo "stop huibian ..............."



.PHONY:clean run
clean:
	rm -rf ${DIR_OBJ}/*.o ${DIR_BIN}/${TARGET}
run:
	${DIR_BIN}/${TARGET}

