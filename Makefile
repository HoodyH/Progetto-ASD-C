
output: parse_in main
	gcc main.o core/inout/parse_in.o -o output
.PHONY: output


main: main.c
	gcc -c main.c


parse_in: core/inout/parse_in.c
	gcc -c core/inout/parse_in.c -o core/inout/parse_in.o 


.PHONY: clean
clean:
	rm *.o output


run:
	{ \
	make ;\
	./output ;\
	}
