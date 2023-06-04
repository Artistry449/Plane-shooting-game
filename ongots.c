#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

void printBoard(char plane[SIZE][SIZE])
{
    int i, j;
    printf("\nBoard: \n  ");

    for (i = 1; i <= 10; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 1; i <= 10; i++)
    {
        if (i < 10)
            printf(" ");
        printf("%d ", i);
        for (j = 1; j <= 10; j++)
        {
            printf("%c ", plane[i][j]);
        }
        printf("\n");
    }
}
void setPlane(char plane[SIZE][SIZE], int x, int y, int tolgoiX, int tolgoiY)
{
    plane[x][y] = 'B';
    plane[tolgoiX][tolgoiY] = 'T';
}
void duusgah()
{
    printf("Togloom duuslaa");
    exit(0);
}
int main()
{
    int Tcounter = 0, Tx, Ty, Bx, By, planeNum, i, j, n, m;
    char plane[SIZE][SIZE];

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            plane[i][j] = '.';
        }
    }

    printf("\n\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");
    printf("1. Ta uuriin ongotsnii coordinate-iig oruulna\n");
    printf("2. Ongotsnii coordinate-iig oruulj buudaj sharhduulna\n");
    printf("3. Herev togloomiig duusgahiig husvel y: 0 x: 0 gj oruulna\n\n");

    printf("T - ongotsnii tolgoi\n");
    printf("B - ongotsnii biy\n");
    printf("X - sonoson\n");
    printf("S - sharh\n\n");

    printf("Ta heden shirheg ongots oruulah ve?\n");

    printf("Ongotsnii too: ");
    scanf("%d", &planeNum);

    if (planeNum == 0)
        duusgah();
    for (int tooluur = 1; tooluur <= planeNum; tooluur++)
    {
        printf("ongots %d: \n", tooluur);

        printf("ongotsnii tolgoi hesgiin coordinate\ny:  ");
        scanf("%d", &Tx);
        printf("x:  ");
        scanf("%d", &Ty);

        if (Tx == 0 && Ty == 0)
            duusgah();
        printf("ongotsnii biynii hesgiin coordinate-uud: \n");
        for (int tooluurB = 1; tooluurB <= 7; tooluurB++)
        {
            printf("y: ");
            scanf("%d", &Bx);
            printf("x: ");
            scanf("%d", &By);

            while (Bx > SIZE || By > SIZE || Tx > SIZE || Ty > SIZE)
            {
                printf("\nTa coordinate-iig zov oruulna uu!\n");

                printf("ongotsnii tolgoi hesgiin coordinate-iig oruulna uu\ny:  ");
                scanf("%d", &Tx);
                printf("x:  ");
                scanf("%d", &Ty);

                printf("ongotsnii biynii hesgiin coordinate-uudiig oruulna uu\n");
                printf("y: ");
                scanf("%d", &Bx);
                printf("x: ");
                scanf("%d", &By);
            }
            setPlane(plane, Bx, By, Tx, Ty);
        }
        printBoard(plane);
    }
    while (100 > 0)
    {
        printf("buudah tseguud: \n");
        printf("y:");
        scanf("%d", &n);
        printf("x:");
        scanf("%d", &m);

        if (n != 0 && m != 0)
        {
            if (n < 11 & m < 11)
            {

                if (plane[n][m] == 'T')
                {
                    Tcounter += 1;
                    plane[n][m] = 'X';
                    if (Tcounter == planeNum)
                    {
                        printBoard(plane);
                        printf("\nTa hojloo!\nTogloom duuslaa!\n");
                        break;
                    }
                    printBoard(plane);
                }
                else if (plane[n][m] == 'B')
                {
                    plane[n][m] = 'S';

                    printBoard(plane);
                }
                else
                {
                    printBoard(plane);
                }
            }
            else
            {
                printf("Coordinate-iig zov oruulna uu");
            }
        }
        else
        {
            duusgah();
        }
    }
}