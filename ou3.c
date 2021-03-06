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

/*
1. Initialisering av världen
2. Så länge användaren inte valt att avsluta
2.1. Skriv ut världen
2.2. Skriv ut menyn
2.3. Läs in användarens val
2.4. Om nytt steg
2.4.1.Uppdatera världen en generation

Programmet ska använda sig av funktioner (dvs fler än de ovan nämnda) och den
givna egendefinierade datastrukturen cell.
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
void userChoice(const int rows, const int cols, cell field[rows][cols]);
void neighbours(const int rows, const int cols, cell field[rows][cols]);

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
  userChoice(rows, cols, field);
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
  for (int r = 0; r < rows; r = r + 1){
    for (int c = 0; c < cols; c = c + 1){
      int value = rand() % 2;
      if (value == 0){
        field[r][c].current = DEAD;
      }
      else{
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


/*  Function:    printWorld
 *  Description: Prints the world on the users screen.
 *  Input:       None.
 *  Output:      The field is printed out.
 */

void printWorld(const int rows, const int cols, cell field[rows][cols]) {

  for (int r = 0 ; r < rows ; r++) {
    for (int c = 0 ; c < cols ; c++) {
      printf(" %c ", field[r][c].current);
    }
    printf("\n");
  }
}


/* Function:     printMenu
 *  Description: Prints the menu on the user screen.
 *  Input:       None.
 *  Output:      The menu is printed out.
 */

void printMenu(){

  printf("Select one of the following options:\n");
  printf("        (enter)	Step\n");
  printf("        (any)	Exit\n");
}


/* Function:    updateWorld
 * Description: Updates the world.
 * Input:       None
 * Output:      The updated world.
 */

void updateWorld(const int rows, const int cols, cell field[rows][cols]) {

  for (int r = 0 ; r < rows ; r++) {
    for (int c = 0 ; c < cols ; c++) {

      field[r][c].current = field[r][c].next;
    }
  }
}


/* Function:    userChoice
 * Description: Reads the choice of the user and prints out functions
 *              updateWorld and printMenu.
 * Input:       Choice of character.
 * Output:      The updated world of choice or end of program.
 */

void userChoice(const int rows, const int cols, cell field[rows][cols]) {

  char choice;

  do {
    printWorld(rows, cols, field);
    printMenu();
    choice = getchar();
    if (choice == '\n')
    {
      neighbours(rows, cols, field);
      updateWorld(rows, cols, field);
    }
  } while(choice == '\n');
}

/* Function:    neighbours
 * Description: Looks for how many neighbours the cell have around it self and
 *              updates.
 * Input:       Nothing
 * Output:      The new generation of the cell.
 */
void neighbours(const int rows, const int cols, cell field[rows][cols]) {
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < rows; c++)
    {
      int alive=0;

      if ((r + 1)< rows && (c - 1)>=0
      && field[r + 1][c - 1].current == ALIVE)
      {
        alive++;
      }
      if ((c - 1) >= 0 && field[r][c - 1].current == ALIVE)
      {
        alive++;
      }
      if ((r - 1) >= 0 && (c - 1) >= 0 && field[r - 1][c - 1].current == ALIVE)
      {
        alive++;
      }
      if ((r + 1 < rows) && field[r + 1][c].current == ALIVE)
      {
        alive++;
      }
      if ((r - 1) >= 0 && field[r - 1][c].current == ALIVE)
      {
        alive++;
      }
      if ((r + 1)< rows && (c + 1)< cols && field[r + 1][c + 1].current == ALIVE)
      {
        alive++;
      }
      if ((c + 1) < cols && field[r][c + 1].current == ALIVE)
      {
        alive++;
      }
      if ((r - 1) >= 0 && (c + 1) < cols && field[r - 1][c + 1].current == ALIVE)
      {
        alive++;
      }
      if (alive < 2)
      {
        field[r][c].next = DEAD;
      }
      else if (field[r][c].current == ALIVE && (alive == 2 || alive == 3))
      {
        field[r][c].next = ALIVE;
      }
      else if (alive > 3)
      {
        field[r][c].next = DEAD;
      }
      else if (field[r][c].current == DEAD && alive == 3)
      {
        field[r][c].next = ALIVE;
      }
      else{
        field[r][c].next = DEAD;
      }
    }
  }
}
