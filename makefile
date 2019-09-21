all : projeto1.o main.o
	gcc projeto1.o main.o -o proj -lm

projeto1.o : projeto1.c
	gcc -g -c projeto1.c -o projeto1.o -lm

main.o : main.c projeto1.o
	gcc -g -c main.c -o main.o -lm

run:
	@./proj