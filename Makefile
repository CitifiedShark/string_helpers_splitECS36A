split.out: main.o string_helpers.o
	gcc -g -Wall -Werror -o split.out main.o string_helpers.o 

string_helpers.o: string_helpers.c string_helpers.h
	gcc -g -Wall -Werror -c string_helpers.c

main.o: main.c string_helpers.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -f *.o *.out 