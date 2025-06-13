NAME = gnltester

GNL_DIR = ../

SRCS = tester_gnl.c ${GNL_DIR}get_next_line.c ${GNL_DIR}get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}
	@echo DEFAULT BUFFER_SIZE 1 TEST
	@valgrind --leak-check=full -s ./gnltester && ./gnltester > results/buffersize10_text.txt

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -I ${GNL_DIR}. ${OBJS} -o ${NAME}

buffer10:
	@echo BUFFER_SIZE 10 TEST
	@valgrind --leak-check=full -s ./gnltester -D BUFFER_SIZE=10 && ./gnltester > results/buffersize10_text.txt

buffer42:
	@echo BUFFER_SIZE 42 TEST
	@valgrind --leak-check=full -s ./gnltester -D BUFFER_SIZE=42 && ./gnltester > results/buffersize42_text.txt

buffer100:
	@echo BUFFER_SIZE 100 TEST
	@valgrind --leak-check=full -s ./gnltester -D BUFFER_SIZE=100 && ./gnltester > results/buffersize100_text.txt

buffer1000:
	@echo BUFFER_SIZE 1000 TEST
	@valgrind  --leak-check=full -s ./gnltester -D BUFFER_SIZE=1000 && ./gnltester > results/buffersize1000_text.txt

buffer10000:
	@echo BUFFER_SIZE 10000 TEST
	@valgrind --leak-check=full -s ./gnltester -D BUFFER_SIZE=10000 && ./gnltester > results/buffersize10000_text.txt

buffer9999999:
	@echo BUFFER_SIZE 9999999 TEST
	@valgrind --leak-check=full -s ./gnltester -D BUFFER_SIZE=9999999 && ./gnltester > results/buffersize9999999_text.txt

reset_results:
	@echo "Removing results..."
	rm results/buffersize1_text.txt

clean:
	@echo "Cleaning.."
	rm ${NAME} ${OBJS}

.PHONY: all
