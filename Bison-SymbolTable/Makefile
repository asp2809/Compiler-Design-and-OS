all: myParser

reg.tab.cpp reg.tab.hpp:	reg.ypp
	bison -d -v reg.ypp

lex.yy.c: reg.l reg.tab.hpp
	flex reg.l

myParser: lex.yy.c reg.tab.cpp reg.tab.hpp
	g++ -o myParser reg.tab.cpp lex.yy.c symTab.cpp -lfl -lm

clean:
	rm myParser reg.tab.cpp lex.yy.c reg.tab.hpp reg.output