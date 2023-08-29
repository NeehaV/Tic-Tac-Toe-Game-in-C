#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char player = 'X';
char computer = 'O';
char board[3][3];
bool status = true;

void resetBoard();
void printBoard();
void computerMove();
void playerMove();
char checkWinner();

int main()
{
    char winner = ' ';
    char response;
    printf("\nWelcome to Tic Tac Toe Game\n\n");
    do
    {
        resetBoard();
        printBoard();
        winner = ' ';
        response = ' ';
        while (winner == ' ')
        {
            playerMove();
            printBoard();
            winner = checkWinner();

            if (winner != ' ')
            {
                break;
            }
            printf("\n\nComputer turn....\n");
            computerMove();
            printBoard();
            winner = checkWinner();
        }

        if (winner == 'O')
        {
            printf("\nThe computer has won!");
        }
        else if (winner == 'X')
        {
            printf("\nYou have Won!!");
        }
        else if (winner == 'T')
        {
            printf("\nIt's a Tie");
        }

        printf("\nWould you like to play again (Y/N)?: ");
        fflush(stdin);
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{

    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
}

void computerMove()
{
    while (status)
    {
        int randRow, randColumn;
        srand(time(0));
        randRow = rand() % 3;
        randColumn = rand() % 3;

        if (board[randRow][randColumn] == ' ')
        {
            board[randRow][randColumn] = 'O';
            break;
        }
    }
}

void playerMove()
{
    int row, column;

    while (status)
    {
        printf("\nEnter your row (1/2/3): ");
        scanf("%d", &row);
        printf("Enter your column (1/2/3): ");
        scanf("%d", &column);
        row = row - 1;
        column = column - 1;
        if (board[row][column] == ' ')
        {
            board[row][column] = 'X';
            break;
        }
        else
        {
            printf("Error ! Enter a valid/unfilled row & column\n");
        }
    }
}

char checkWinner()
{
    char checkwinner = ' ';
    // check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
        {
            checkwinner = board[i][0];
        }
        else if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
        {
            checkwinner = board[0][i];
        }
    }
    // check diagonals
    if ((checkwinner == ' '))
    {
        if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
        {
            checkwinner = board[0][0];
        }
        else if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))
        {
            checkwinner = board[0][2];
        }
        else
        {
            // check tie condition
            int count = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] != ' ')
                    {
                        count++;
                    }
                }
            }
            if (count == 9)
            {
                checkwinner = 'T';
            }
        }
    }

    return checkwinner;
}