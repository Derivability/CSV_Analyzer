#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_SEPARATOR 	";"
#define LINE_SEPARATOR 		";\n"
#define SIZE			1024
#define ROW			4
#define COL			4

int** getMatrix(FILE *filename)
{
	int** matrix;
	char line[SIZE];
	char* tok;
	matrix = (int **)malloc(ROW * sizeof(int *));
	
	for(int i = 0; i < ROW; i++) {
		
		fgets(line, SIZE, filename);
		matrix[i] = (int *)malloc(COL * sizeof(int));
		tok = strtok(line, ELEMENT_SEPARATOR);
		
		for(int j = 0; j < COL; j++) {
			matrix[i][j] = atoi(tok);
			tok = strtok(NULL, LINE_SEPARATOR);
		}
	}
	return matrix;
}

int main(int argc, char* argv[])
{
    if(argc > 1) {
		FILE* csv_file = fopen(argv[1], "r");
		int** data = getMatrix(csv_file);
        fclose(csv_file);
    }
    else {
		printf("No file specified\nExiting\n");
	}
	return 0;
}
