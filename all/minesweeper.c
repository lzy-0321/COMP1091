// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by YOUR-NAME-HERE (z5340468)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2020-03-08): Assignment released.
// Version 1.0.1 (2020-03-08): Fix punctuation in comment.
// Version 1.0.2 (2020-03-08): Fix second line of header comment to say minesweeper.c


#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0 // a square that has not been revealed.
#define HIDDEN_SAFE     1 // a hidden square that does not contain a mine.
#define HIDDEN_MINE     2 // a square that has not been revealed and contains a mine.

// The size of the starting grid.
#define SIZE 8

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7
        

// Declare functions.
void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
void mines_replace(int minefield[SIZE][SIZE]);
void row(int num, int minefield[SIZE][SIZE]);
void column(int num, int minefield[SIZE][SIZE]);
void d_square(int num, int minefield[SIZE][SIZE]);
void r_square(int t, int mode, int minefield[SIZE][SIZE]);
void change_n(int row, int column, int minefield[SIZE][SIZE]);
int c_m(int row, int column, int minefield[SIZE][SIZE]);
int d_m(int row, int column, int minefield[SIZE][SIZE]);
void c_s(int row, int column, int minefield[SIZE][SIZE]);
void c_sq(int row, int column, int minefield[SIZE][SIZE]);


int main(void) {
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    mines_replace(minefield);
    printf("Game Started\n");
    print_debug_minefield(minefield);
    int inputnum;
    int num = 0; 
    int mode = DEBUG_MODE;
    int t = 1;
    while (scanf("%d", &inputnum) == 1) {
        if (inputnum == DETECT_ROW) { 
            row(num, minefield);
            num++;       
        } else if (inputnum == DETECT_COL) {
            column(num, minefield);
            num++;
        }
        if (inputnum == DETECT_SQUARE) {
            d_square(num, minefield);
            num++;
        } else if (inputnum == REVEAL_SQUARE) {
            r_square(t, mode, minefield);
            t++;
        } 
        if (inputnum == DEBUG_MODE) {
            printf("Debug mode activated\n");
            mode = DEBUG_MODE;
        } else if (inputnum == GAMEPLAY_MODE) {
            printf("Gameplay mode activated\n");
            mode = GAMEPLAY_MODE; 
        }          
        if (mode == DEBUG_MODE || inputnum == DEBUG_MODE) {
            print_debug_minefield(minefield);
        } 
    } 
    return 0;
}
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
void mines_replace(int minefield[SIZE][SIZE]) {
    int pairNum = 0;
    scanf("%d", &pairNum);
    printf("Enter pairs:\n");
    int i = 0;
    while (i < pairNum) { 
        int row;
        int column;
        scanf("%d %d", &row, &column);
        if (row >= SIZE || column < 0) { 
        } else if (row < 0 || column >= SIZE) { 
        } else {
            minefield[row][column] = HIDDEN_MINE; 
        }
        i++;
    } 
}
void column(int num, int minefield[SIZE][SIZE]) {
    int column = 0;
    int row = 0;
    int mineNumber = 0;
    scanf("%d", &column);
    if (num < 3) {
        while (row < SIZE) {
            if (minefield[row][column] == HIDDEN_MINE) {
                mineNumber++;
            } 
            row++;
        }      
        printf("There are %d mine(s) in column %d\n", mineNumber, column);
    } else if (num >= 3) {
        printf("Help already used\n");
    }
}
void row(int num, int minefield[SIZE][SIZE]) {
    int row = 0;
    int column = 0;
    int mineNumber = 0;
    scanf("%d", &row);
    
    if (num < 3) {
        while (column < SIZE) {
            if (minefield[row][column] == HIDDEN_MINE) {
                mineNumber++;
            } 
            column++;
        }
        printf("There are %d mine(s) in row %d\n", mineNumber, row);
    } else if (num >= 3) {
        printf("Help already used\n");
    }
}
void d_square(int num, int minefield[SIZE][SIZE]) {
    int row;
    int column;
    int size; 
    scanf("%d %d %d", &row, &column, &size);

    if (num < 3) {
        printf("There are %d mine(s) in the square", 
        c_m(row, column, minefield)); 
        printf(" centered at row %d, column %d of size %d\n", row, column, size); 
    } else if (num >= 3) {
        printf("Help already used\n");
    }
}
void r_square(int t, int mode, int minefield[SIZE][SIZE]) {
    int row;
    int column;
    scanf("%d %d", &row, &column);
    if (minefield[row][column] == HIDDEN_MINE && t == 1) {
        t++;
        c_s(row, column, minefield);
    } 
    else if (minefield[row][column] == HIDDEN_MINE && mode == GAMEPLAY_MODE) {
        printf("Game over\n");
        printf("xx\n");
        printf("/\\");
        printf("\n");
        exit (EXIT_FAILURE); 
    } else if (minefield[row][column] == HIDDEN_MINE && mode == DEBUG_MODE) {
        printf("Game over\n");
        print_debug_minefield(minefield);
        exit (EXIT_FAILURE);
    } 
    else { 
        c_s(row, column, minefield);
    }
    
}
int d_m(int row, int column, int minefield[SIZE][SIZE]) {
    if (row < 0 || column < 0) {
        return 40;
    } else if (row >= SIZE || column >= SIZE) {
        return 40;
    } 
    if (c_m(row, column, minefield) > 0) {
        minefield[row][column] = VISIBLE_SAFE;
        return 2;
    } else if (c_m(row, column, minefield) == 0) {
        minefield[row][column] = VISIBLE_SAFE;
        return 0;
    }
    return 42;
}
int c_m(int row, int column, int minefield[SIZE][SIZE]) {
    int length = 3;
    int i = 0;
    int j = 0;
    int x = row - ((length - 1)/2);
    int y = column - ((length - 1)/2);
    int mineNumber = 0;
    while (i < length) {
        y = column - ((length - 1)/2); 
        j = 0; 
        while (j < length) {
            if (x < 0 || y < 0) {
            } else if (x >= SIZE || y >= SIZE) {
            } else if (minefield[x][y] == HIDDEN_MINE) {
                mineNumber++;
            }
            y++;
            j++;
        }
        x++;
        i++;
    }
    return mineNumber;
}

void c_s(int row, int column, int minefield[SIZE][SIZE]) {
    if (c_m(row, column, minefield) > 0) {
        minefield[row][column] = VISIBLE_SAFE;    
    } 
    else if (c_m(row, column, minefield) == 0) {
        c_sq(row, column, minefield);
    }
}
void c_sq(int row, int column, int minefield[SIZE][SIZE]) {
    int length = 3;
    int x = row - ((length - 1)/2);
    int y = column - ((length - 1)/2);
    int i = 0;
    int j = 0;    
    
    while (i < 3) {
        while (j < 3) {
            if (x < 0 || y < 0) {
            } else if (x >= SIZE || y >= SIZE) {
            } else if (minefield[x][y] == HIDDEN_SAFE) {
                minefield[x][y] = VISIBLE_SAFE;
            }
            y++;
            j++;
        }
        y = column - ((length -1)/2); 
        j = 0;
        x++; 
        i++;
    }
}

