all:
	gcc main.c -o csv_analyzer
clean:
	rm -rf csv_analyzer *.out *.o
