main: doubly-linked.o main.o
	gcc obj/doubly-linked.o obj/main.o -o main

doubly-linked.o:
	gcc -c src/doubly-linked.c -o obj/doubly-linked.o -Iinclude

main.o:
	gcc -c src/main.c -o obj/main.o -Iinclude
