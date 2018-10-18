/*
 * Programmeringsteknik med C och Matlab
 * Fall 2018
 * Assignment 2
 * File:         ou2.c
 * Description:  A simple implementation of a program that sums up the average of
 *               up to 10 judgescores. But without regarding the highest or the
 *               lowest score. Then printing out average, highest and the lowest score.
 * Author:       Mikolaj Wagner
 * CS username:  c18mwj
 * Date:         18/10
 * Input:        How many judges are scoring the competitor(s) minimum of 3
 *               judges and a max of 10. The scores given by the judges.
 * Output:       Prints the info of the program, number of judges and also the
 *               input values of every judge score. Then a final score is
 *               presented with the highest and lowest score then prints out an
 *               average of the points but not adding the largest or the lowest score.
* Limitations: No validation of input.
*/

#include <stdio.h>


int readNumbJudges (void);
void printInfo (void);
void readScoreJudges( int numbJudge, float array[]);
void printScoreJudges(int numbJudge, float array[]);
void getResult(float *max, float *min, float *average, float array[], int numbJudge);
void printResult (float *max, float *min, float *average);


int main(void)
{
    const int size = 10;
    float array[size];
    int numbJudge;
    float max;
    float min;
    float average;

    printInfo ();
    numbJudge = readNumbJudges ();
    printf("\n");
    readScoreJudges (numbJudge, array);
    printf("\n");
    printScoreJudges (numbJudge, array);
    printf("\n");
    getResult (&max, &min, &average, array, numbJudge);
    printf("\n");
    printResult (&max, &min, &average);

    return 0;

}
/*
This function prints out the information of the program.
Input: None.
Output: The information about the program.
*/
void printInfo ()
{
    printf("Program information\n"
    "The program reads in the number of judges and the score from each judge.\n"
    "Then it calculates the average score without regard to the lowest and\n"
    "highest judge score."
    " Finally it prints the results (the highest, the\nlowest and the final"
    "average score).\n\n");
}

/*
This function prints out the read "right" number of judges (between 3 and 10).
Input: Number of judges.
Output: 
*/
int readNumbJudges (void)
{
    int numbJudge;

    do {
        printf("Number of judges (min 3 and max 10 judges)? ");
        scanf("%d", &numbJudge);

    } while (numbJudge < 3 || numbJudge > 10);
    return numbJudge;
}
/*
1. Om funktionen 2. parametrar
input
@param numberofj - tyjru
ryuyuty- thytrh
output
*/
void readScoreJudges (int numbJudge,float array[])
{
    for (int i = 0; i < numbJudge; i++)
    {
        printf("Score from judge %d? ", i+1);
        scanf("%f", &array[i]);
    }
}
void printScoreJudges (int numbJudge,float array[])
{
    printf("Loaded scores:\n");
    for (int i = 0; i < numbJudge; i++)
    {
        printf("Judge %d: %.1f\n", i + 1, array[i]);
    }
}
void getResult(float *max, float *min, float *average, float array[], int numbJudge)
{
    *max = array[0];
    *min = array[0];
    for (int i = 0; i < numbJudge; i++)
    {
        if (array[i] > *max)
        {
            *max = array[i];
        }
        if (array [i] < *min)
        {
            *min = array[i];
        }
        *average += array[i];
    }
    *average -= (*max + *min)/(numbJudge - 2);
}

void printResult (float *max, float *min, float *average)
{
    printf("Final result:\n"
    "Highest judge score: %.1f\n"
    "Lowest judge score: %.1f\n"
    "Final average score: %.1f\n", *max, *min, *average);
}
