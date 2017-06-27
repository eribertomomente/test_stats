text_stats: iofunc.o node.o text_stats.o
	gcc iofunc.o node.o text_stats.o -o text_stats
iofunc.o: text_stats.h iofunc.c
	gcc -c iofunc.c
node.o: node.c text_stats.h
	gcc -c node.c
text_stats.o: text_stats.c text_stats.h
	gcc -c text_stats.c
