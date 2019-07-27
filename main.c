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

void printRow(int row_num, int** matrix)
{
	for(int j = 0; j < COL; j++) {
		printf("%d, ", matrix[row_num][j]);
	}
	printf("\n");
}

void printCol(int col_num, int** matrix)
{
	for(int i = 0; i < ROW; i++) {
		printf("%d; ", matrix[i][col_num]);
	}
	printf("\n");
}

void printMatrix(int** matrix)
{
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void printMainDiag(int diag_num, int** matrix)
{
	int i, j;
	if(diag_num < ROW) {
		i = ROW - diag_num - 1;
		j = 0;
		while(i < ROW) {
			printf("%d ", matrix[i][j]);
			i++;
			j++;
		}
	}
	else {
		diag_num -= ROW;
		i = 0;
		j = diag_num+1;
		while(j < COL) {
			printf("%d ", matrix[i][j]);
			i++;
			j++;
		}
	}
	printf("\n");
}

void printSideDiag(int diag_num, int** matrix)
{
	int i, j;
	if(diag_num < ROW) {
		i = diag_num;
		j = 0;
		while(i >= 0) {
			printf("%d ", matrix[i][j]);
			i--;
			j++;
		}
	}
	else {
		diag_num -= ROW;
		i = ROW-1;
		j = diag_num+1;
		while(j < COL) {
			printf("%d ", matrix[i][j]);
			i--;
			j++;
		}
	}
	printf("\n");
}

void checkHorizontal(int** matrix)
{
	int count = 0;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(matrix[i][j]) {
				count = 1;
			}
			else {
				count = 0;
				break;
			}
		}
		
		if(count) {
			printRow(i, matrix);
		}
		count = 0;
	}
}

void checkVertical(int** matrix)
{
	int count;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(matrix[j][i]) {
				count = 1;
			}
			else {
				count = 0;
				break;
			}
		}
		
		if(count) {
			printCol(i, matrix);
		}
		count = 0;
	}
}

int main(int argc, char* argv[])
{
	if(argc > 1) {
		FILE* csv_file = fopen(argv[1], "r");
		int** data = getMatrix(csv_file);
		
		printf("Given matrix\n");
		printMatrix(data);
		
		printf("\n");
		
		printf("Horizontal filled lines:\n");
		checkHorizontal(data);
		
		printf("\n");
		
		printf("Vertical filled lines:\n");
		checkVertical(data);
		
		printf("\n");
		fclose(csv_file);
	}
	else {
		printf("No file specified\nExiting\n");
	}
	return 0;
}
