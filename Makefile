text_stats: iofunc.o node.o text_stats.o
	clang iofunc.o node.o text_stats.o -o text_stats
iofunc.o: iofunc.c iofunc.h node.h
	clang -c iofunc.c
node.o: node.c node.h
	clang -c node.c
text_stats.o: node.h iofunc.h text_stats.c
	clang -c text_stats.c
