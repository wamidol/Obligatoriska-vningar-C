/*
* Programmeringsteknik med C och Matlab
* Fall 18
* Assignment 3
* File:         ou3.c
* Description:  A simple implementation of Conway's Game of Life.
* Author:       Mikolaj Wagner
* CS username:  c18mwj
* Date:         25/10
* Input:        Choice of initial configuration and then instruction to step
*               or exit.
* Output:       Prints the game field in each step.
* Limitations:  No validation of input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants, representation of states */
#define ALIVE 'X'
#define DEAD '.'
/* Declaration of data structure */
typedef struct{
    char current;
    char next;
} cell;

/* Declaration of functions */
void initField(const int rows, const int cols, cell field[rows][cols]);
void loadGlider(const int rows, const int cols, cell field[rows][cols]);
void loadSemaphore(const int rows, const int cols, cell field[rows][cols]);
void loadRandom(const int rows, const int cols, cell field[rows][cols]);
void loadCustom(const int rows, const int cols, cell field[rows][cols]);
void printWorld(const int rows, const int cols, cell field[rows][cols]);
void printMenu(void);
void updateWorld(const int rows, const int cols, cell field[rows][cols]);
char userChoice(const int rows, const int cols, cell field[rows][cols]);


/* Function:    main
* Description: Start and run games, interact with the user.
* Input:       About what initial structure and whether to step or exit.
* Output:      Information to the user, and the game field in each step.
*/

int main(void) {
    
    const int rows = 20;
    const int cols = 20;
    cell field[rows][cols];
    initField(rows, cols, field);
    printWorld(rows, cols, field);
    printMenu();
    userChoice(rows, cols, field);
    countNeighbours()
    return 0;
}


/* Function:    initField
* Description: Initialize all the cells to dead, then asks the user about
*              which structure to load, and finally load the structure.
* Input:       The field array and its size.
* Output:      The field array is updated.
*/

void initField(const int rows, const int cols, cell field[rows][cols]) {
    
    for (int r = 0 ; r < rows ; r++) {
        for (int c = 0 ; c < cols ; c++) {
            field[r][c].current = DEAD;
        }
    }
    
    printf("Select field spec to load ([G]lider, [S]emaphore, [R]andom ");
    printf("or [C]ustom): ");
    
    int ch = getchar();
    
    /* Ignore following newline */
    if (ch != '\n') {
        getchar();
    }
    
    switch (ch) {
        case 'g':
        case 'G':
        loadGlider(rows, cols, field);
        break;
        case 's':
        case 'S':
        loadSemaphore(rows, cols, field);
        break;
        case 'r':
        case 'R':
        loadRandom(rows, cols, field);
        break;
        case 'c':
        case 'C':
        default:
        loadCustom(rows, cols, field);
        break;
    }
}


/* Function:    loadGlider
* Description: Inserts a glider into the field.
* Input:       The field array and its size.
* Output:      The field array is updated.
*/

void loadGlider(const int rows, const int cols, cell field[rows][cols]) {
    
    field[0][1].current = ALIVE;
    field[1][2].current = ALIVE;
    field[2][0].current = ALIVE;
    field[2][1].current = ALIVE;
    field[2][2].current = ALIVE;
}


/* Function:    loadSemaphore
* Description: Inserts a semaphore into the field.
* Input:       The field array and its size.
* Output:      The field array is updated.
*/

void loadSemaphore(const int rows, const int cols, cell field[rows][cols]) {
    
    field[8][1].current = ALIVE;
    field[8][2].current = ALIVE;
    field[8][3].current = ALIVE;
}


/* Function:    loadRandom
* Description: Inserts a random structure into the field.
* Input:       The field array and its size.
* Output:      The field array is updated. There is a 50 % chance that a cell
*              is alive.
*/

void loadRandom(const int rows, const int cols, cell field[rows][cols]) {
    
    srand(time(NULL));
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            int value = rand( ) % 1;
            if (value == 0){
                field[r][c].current = DEAD;
            }
            else {
                field[r][c].current = ALIVE;
            }
        }
        
    }
    
}


/* Function:    loadCustom
* Description: Lets the user specify a structure that then is inserted into
*              the field.
* Input:       The field array and its size.
* Output:      The field array is updated.
*/

void loadCustom(const int rows, const int cols, cell field[rows][cols]) {
    
    printf("Give custom format string: ");
    do {
        int r, c;
        scanf("%d,%d", &r, &c);
        field[r][c].current = ALIVE;
    } while (getchar() != '\n');
}

/* Function:    printWorld
* Description: Prints the world on the users screen.
* Input:       None.
* Output:      The field is printed out.
*/

void printWorld (const int rows, const int cols, cell field[rows][cols]) {
    
    for (int r = 0 ; r < rows ; r++) {
        for (int c = 0 ; c < cols ; c++) {
            printf(" %c ", field[r][c].next);
        }
        printf("\n");
    }
}

/* Function:    printMenu
* Description: Prints the menu on the user screen.
* Input:       None.
* Output:      The menu is printed out.
*/

void printMenu (){
    
    printf("Select one of the following options:\n");
    printf("        (enter)	Step\n");
    printf("        (any)	Exit\n");
}

/* Function:    updateWorld
* Description: Updates the world.
* Input:       None
* Output:      The updated world.
*/

void updateWorld (const int rows, const int cols, cell field[rows][cols]) {
    
    for (int r = 0 ; r < rows ; r++) {
        for (int c = 0 ; c < cols ; c++) {
            
            field[r][c].current = field[r][c].next;
        }
        printf("\n");
    }
}

/* Function:    userChoice
* Description: Reads the choice of the user and prints out functions
*              updateWorld and printMenu.
* Input:       Choice of character.
* Output:      The updated world of choice or end of program.
*/

char userChoice (const int rows, const int cols, cell field[rows][cols]) {
    
    char choice;
    choice = getchar();
    
    do {
        updateWorld(rows, cols, field);
        printMenu();
        scanf("%c", &choice);
    } while(choice == '\n');
    
    return 0;
}

void checkField (const int rows, const int cols, cell field[rows][cols]) {
    
    for (int r = 0 ; r < rows ; r++) {
        for (int c = 0 ; c < cols ; c++) {
            printf(" %c ", field[r][c].next);
        }
    }
}
void countNeighbours (const int rows, const int cols, cell field[rows][cols]) {
    
    for (int r = rows - 1; r <= rows + 1 ; r++) {
        for (int c = cols - 1; c <= cols + 1 ; c++) {
            field[rows][cols].current
        }
    }
    
}


/*     row - 1, column - 1
row - 1, column
row - 1, column + 1
row, column + 1
row + 1, column + 1
row + 1, column
row + 1, column - 1
row, column - 1






/* Function:
* Description:
* Input:
* Output:
*/
