etapa1: hash.o lex.yy.o
	gcc -o etapa1 hash.o lex.yy.o
hash.o: hash.c
	gcc -c hash.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l
clean:
	rm -f *.o lex.yy.c lex.yy.h etapa1