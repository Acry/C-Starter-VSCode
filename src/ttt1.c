#include <stdlib.h>
#include <stdio.h>

#define UNSET 0
#define P1 1
#define P2 2

/**
 * Yet another Tic-Tac-Toe implementation.
 *
 * possible forks:
 * -> tiny TTT 2 Bytes
 * -> ncurses TTT
 * -> TTT with AI
 * -> TTT ncurses with mouse
 * -> SDL2 TTT
 * -> SDL2 Rust
 * -> SDL2 Go
 * -> SDL2 Vala
 */

void cleanBoard(int[]); // sets array to all UNSET

int boardIsFull(int[]);          // checks if the board has any UNSET values - probably a better fn name
int checkInput(int, int[], int); // code smell, bc it checks and sets the key

int checkWin(int[]); // checks if there is a winner - parent function
int checkH(int[]);   // horizontal win check - nested / child function
int checkV(int[]);   // vertical win check - nested / child function
int checkD(int[]);   // diagonal win check - nested / child function

void drawBoard(int[]);

int main()
{
    int board[9];
    cleanBoard(board);
    int gameRunning = 1;
    int winner = UNSET;
    int player = P1;

    while (gameRunning)
    {
        drawBoard(board);

        // get player input
        printf("Player %d choose a field: ", player);
        int key;
        scanf("%d", &key);

        int playerMadeMove = checkInput(key, board, player);

        winner = checkWin(board);
        if (winner)
        {
            gameRunning = 0;
            drawBoard(board);
            printf("The winner is player %d.\n", winner);
            continue;
        }

        if (boardIsFull(board))
        {
            gameRunning = 0;
            drawBoard(board);
            printf("The game is a draw.\n");
            continue;
        }

        if (playerMadeMove)
        {
            player = player == P1 ? P2 : P1;
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

void drawBoard(int theArray[])
{
    int board[9];
    for (int i = 0; i < 9; i++)
    {
        char c = i + 49;
        if (theArray[i] == P1)
        {
            c = 'X';
        }
        else if (theArray[i] == P2)
        {
            c = 'O';
        }
        board[i] = c;
    }
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

int checkInput(int key, int theArray[], int player)
{
    for (int i = 0; i < 9; i++)
    {
        char c = i + 1;
        if (theArray[i] == P1)
        {
            c = 'X';
        }
        else if (theArray[i] == P2)
        {
            c = 'O';
        }
        if (key == c)
        {
            theArray[i] = player;
            return 1;
        }
    }
    printf("No valid field\n");
    return 0;
}