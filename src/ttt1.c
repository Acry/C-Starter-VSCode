#include <stdlib.h>

#define UNSET 0
#define P1 1
#define P2 2

void cleanBoard(int[]);
int checkBoard(int[]);
int boardIsFull(int[]);

int checkWin(int[]);
int checkH(int[]);
int checkV(int[]);
int checkD(int[]);

int main()
{
    // init game
    // clean fields
    int board[9];
    cleanBoard(board);
    int sum = checkBoard(board);
    int isFull = checkBoardIsFull(board);

    int gameRunning = 1;
    int winner = UNSET;
    int player = P1;
    // board[0] = P1;
    // board[1] = P1;
    // board[2] = P1;
    // winner = checkH(board);

    // board[2] = P2;
    // board[5] = P2;
    // board[8] = P2;
    // winner = checkV(board);

    // board[0] = P1;
    // board[4] = P1;
    // board[8] = P1;
    // winner = checkWin(board);

    // board[0] = P1;
    // board[1] = P1;
    // board[2] = P1;
    // board[3] = P1;
    // board[4] = P1;
    // board[5] = P1;
    // board[6] = P1;
    // board[7] = P1;
    // board[8] = P1;
    // isFull = checkBoardIsFull(board);

    while (gameRunning)
    {
        // draw board
        // get player input

        winner = checkWin(board);
        if (checkWin)
        {

            gameRunning = 0;
            continue;
        }

        if (boardIsFull(board))
        {
            // if winner is not set the game is a draw
            gameRunning = 0;
        }
    }

    return EXIT_SUCCESS;
}

void cleanBoard(int theArray[])
{
    for (int i = 0; i < 9; i++)
    {
        theArray[i] = UNSET;
    }
}

int checkBoard(int theArray[])
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += theArray[i];
    }
    return sum;
}

int boardIsFull(int theArray[])
{
    int isFull = 1;
    for (int i = 0; i < 9; i++)
    {
        isFull = theArray[i];
        if (!isFull)
            break;
    }
    return isFull;
}

int checkWin(int theArray[])
{
    int h = checkH(theArray);
    int v = checkV(theArray);
    int d = checkD(theArray);

    if (h)
        return h;
    if (v)
        return v;
    if (d)
        return d;
    return UNSET;
}

int checkH(int theArray[])
{
    int winner = UNSET;
    if (theArray[0] == P1 && theArray[1] == P1 && theArray[2] == P1)
    {
        winner = P1;
    }
    else if (theArray[0] == P2 && theArray[1] == P2 && theArray[2] == P2)
    {
        winner = P2;
    }

    if (theArray[3] == P1 && theArray[4] == P1 && theArray[5] == P1)
    {
        winner = P1;
    }
    else if (theArray[3] == P2 && theArray[4] == P2 && theArray[5] == P2)
    {
        winner = P2;
    }

    if (theArray[6] == P1 && theArray[7] == P1 && theArray[8] == P1)
    {
        winner = P1;
    }
    else if (theArray[6] == P2 && theArray[7] == P2 && theArray[8] == P2)
    {
        winner = P2;
    }
    return winner;
}

int checkV(int theArray[])
{
    int winner = UNSET;
    if (theArray[0] == P1 && theArray[3] == P1 && theArray[6] == P1)
    {
        winner = P1;
    }
    else if (theArray[0] == P2 && theArray[3] == P2 && theArray[6] == P2)
    {
        winner = P2;
    }

    if (theArray[1] == P1 && theArray[4] == P1 && theArray[7] == P1)
    {
        winner = P1;
    }
    else if (theArray[1] == P2 && theArray[4] == P2 && theArray[7] == P2)
    {
        winner = P2;
    }

    if (theArray[2] == P1 && theArray[5] == P1 && theArray[8] == P1)
    {
        winner = P1;
    }
    else if (theArray[2] == P2 && theArray[5] == P2 && theArray[8] == P2)
    {
        winner = P2;
    }
    return winner;
}

int checkD(int theArray[])
{
    int winner = UNSET;
    if (theArray[0] == P1 && theArray[4] == P1 && theArray[8] == P1)
    {
        winner = P1;
    }
    else if (theArray[0] == P2 && theArray[4] == P2 && theArray[8] == P2)
    {
        winner = P2;
    }

    if (theArray[2] == P1 && theArray[4] == P1 && theArray[6] == P1)
    {
        winner = P1;
    }
    else if (theArray[2] == P2 && theArray[4] == P2 && theArray[6] == P2)
    {
        winner = P2;
    }

    return winner;
}