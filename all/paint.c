// Assignment 1 21T2 DP1091: CS Paint
// paint.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2021-06-04): Assignment released.

#include <stdio.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4

// IF YOU NEED MORE #defines ADD THEM HERE


// Provided helper functions:
// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);
// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE


int main(void) {
    int canvas[N_ROWS][N_COLS];

    clearCanvas(canvas);
    
    int row ,col;
    int n; 
    int start_row, start_col, end_row, end_col;   
    while (scanf("%d", &n) == 1) {
        scanf("%d", &start_row);
        fflush(stdin);
        scanf("%d", &start_col);
        fflush(stdin);
        scanf("%d", &end_row);
        fflush(stdin);
        scanf("%d", &end_col);
        if (start_row < 0) {
            start_row = 0;
        }
        if (start_col < 0) {
            start_col = 0;
        }
        if (end_row < 0) {
            end_row = 0;
        }
        if (end_col < 0) {
            end_col = 0;
        }
        if (start_row > 20) {
            start_row = 20;
        }
        if (start_col > 36) {
            start_col = 36;
        }
        if (end_row > 20) {
             end_row = 20;
        }
        if (end_col > 36) {
            end_col = 36;
        }
        if (n == 1) {
            if (start_row == end_row) {
                if (start_col <= end_col) {
                    row = start_row;
                    col = start_col;
                    while (col <= end_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                }
                if (start_col >= end_col) {
                    row = start_row;
                    col = end_col;
                    while (col <= start_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                }
            }
           else if (start_col == end_col) {
                if (start_row <= end_row) {
                    row = start_row;
                    col = start_col;
                    while (row <= end_row) {
                        canvas[row][col] = BLACK;
                        row++;
                    }
                }
                if (start_row >= end_row) {
                    row = end_row;
                    col = start_col;
                    while (row <= start_row) {
                        canvas[row][col] = BLACK;
                        row++;
                    }
                }
            }
        }
        if (n == 2) { 
            if (start_row >= end_row && start_col >= end_col) {
                row = end_row;
                col = end_col;
                while (row <= start_row) {
                    while (col <= start_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                    row++;
                    col = end_col;
                }
            }
            else if (start_row <= end_row && start_col >= end_col) {
                row = start_row;
                col = end_col;
                while (row <= end_row) {
                    while (col <= start_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                    row++; 
                    col = end_col;
                }
            }
            else if (start_row >= end_row && start_col <= end_col) {
                row = end_row;
                col = start_col;
                while (row <= start_row) {
                    while (col <= end_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                    row++; 
                    col = start_col;                   
                }
            }
            else if (start_row <= end_row && start_col <= end_col) {
                row = start_row;
                col = start_col;
                while (row <= end_row) {
                    while (col <= end_col) {
                        canvas[row][col] = BLACK;
                        col++;
                    }
                    row++; 
                    col = start_col;
                }
            }
        }
    }
              
            

    // Hint: start by scanning in the command.
    //
    // If the command is the "Draw Line" command, scan in the rest of
    // the command (start row, start col, length, direction) and use
    // that information to draw a line on the canvas.
    //
    // Once your program can draw a line, add a loop to keep scanning
    // commands until you reach the end of input, and process each
    // command as you scan it.

    displayCanvas(canvas);

    return 0;
}



// ADD CODE FOR YOUR FUNCTIONS HERE



// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
//
// You should not need to change the displayCanvas function.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
//
// You should not need to change the clearCanvas function.
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}
