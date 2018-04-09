etapa2: y.tab.c lex.yy.c
	gcc -o etapa2 lex.yy.c y.tab.c hash.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

y.tab.c: parser.y
	bison -d -y -t parser.y

clean:
	rm -f lex.yy.* y.tab.* *.o etapa2