all: tempstat

tempstat: temp.o temp_functions.o
	gcc -o tempstat temp.o temp_functions.o

temp.o: temp.c temp_functions.h
	gcc -c temp.c

temp_functions.o: temp_functions.c temp_functions.h
	gcc -c temp_functions.c

clean:
	del *.o
	del *.txt
	del tempstat.exe