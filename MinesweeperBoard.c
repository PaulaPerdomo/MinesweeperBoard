//Paula Perdomo
//1005974313


#include <stdio.h>
#include "file.h"
//Includes the correct header files for random numbers.

//Function that counts the bombs, taking the current position (row and column) into account.
int countingOfBombs(int rows, int columns, char board[rows][columns], int currentRow, int currentColumn) {

  int count = 0;
  for(int i = currentRow-1; i <= currentRow+1; i++) {
    for(int j = currentColumn-1; j <= currentColumn+1; j++) {
      if(i != 0 && i != rows+1 && j != 0 && j != columns && board[i][j] == '*') {
        count++;
      }
    }
  }
  return count;
}

int main(void) {

//Declaring the varibles.
  int rows, columns;
  double probability;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &columns);
    
//Declaring a 2D array.
  char board[rows+2][columns+2];

  printf("Enter the probability p value: ");
  scanf("%lf", &probability);

  for(int i = 0; i < (columns*2)-1; i++) {
    printf("-");
  }

  printf("\n");

//Filling the array with nested for loops.
  for(int i = 0; i < rows+2; i++) {
    for(int j = 0; j < columns+2; j++) {
      if(i != 0 && i != rows+1 && j != 0 && j != columns+1 && rand() < probability) {
         board[i][j] = '*';
      }
      else {
        board[i][j] = '.';
      }
      if(i != 0 && i != rows+1 && j != 0 && j != columns+1)
        printf("%c ", board[i][j]);
    }
     if(i != 0 && i != rows+1)
        printf("\n");
  }

  for(int i = 0; i < (columns*2)-1; i++) {
    printf("-");
  }

  printf("\n");

//Using the function to count the bombs with nested for loops.
  for(int i = 0; i < rows+2; i++) {
    for(int j = 0; j < columns+2; j++) {
      if(i != 0 && i != rows+1 && j != 0 && j != columns+1 && board[i][j] != '*') {
        board[i][j] = countingOfBombs(rows+2, columns+2, board, i, j) + '0';
      }
    }
  }

//Printing the elements of the array with nested for loops.
  for(int i = 0; i < rows+2; i++){
    for(int j = 0; j < columns+2; j++){
      if(i != 0 && i != rows+1 && j != 0 && j != columns+1)
        printf("%c ", board[i][j]);
    }
    if(i != 0 && i != rows+1)
      printf("\n");
  }
  
  for(int i = 0; i < (columns*2)-1; i++) {
    printf("-");
  }
  return 0;
}




