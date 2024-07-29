#include <stdio.h>

char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char mark;

void createBoard();
void markingBoard(int, char);
int checkWinner();
int comp_win();
int block_user();

int main()
{
    int choice, player = 1, i, mode;
    int  t_1 = 1;

    printf("Choose Game Mode:\n");
    printf("1. Player vs Computer\n");
    printf("2. Player vs Player\n\n");
    printf("Enter your choice : ");
    scanf(" %d", &mode);

    switch (mode)
    {
    case 1:
        printf("\nYou selected Player vs Computer\n");
        printf("Here player 2 is the Computer\n");
        do
        {

            createBoard();
            if (player % 2 == 0)
            {
                player = 2;
                mark = 'O';
            }
            else
            {
                player = 1;
                mark = 'X';

            }


            if (player == 1)
            {

                printf("Player, enter a number: ", player);
                scanf("%d", &choice);
                if (choice == 1 && box[1] == '1')
                    box[1] = mark;
                else if (choice == 2 && box[2] == '2')
                    box[2] = mark;
                else if (choice == 3 && box[3] == '3')
                    box[3] = mark;
                else if (choice == 4 && box[4] == '4')
                    box[4] = mark;
                else if (choice == 5 && box[5] == '5')
                    box[5] = mark;
                else if (choice == 6 && box[6] == '6')
                    box[6] = mark;
                else if (choice == 7 && box[7] == '7')
                    box[7] = mark;
                else if (choice == 8 && box[8] == '8')
                    box[8] = mark;
                else if (choice == 9 && box[9] == '9')
                    box[9] = mark;
                else
                {
                    printf("Invalid move ");
                    player--;

                }
            }
            if (player == 2)
            {
                printf("Computer, enter a number ");
                if ((choice == 1 || choice == 2 || choice == 4 || choice == 5) && t_1 == 1)
                {
                    box[9] = mark;
                    choice= 9;
                    t_1 = 0;
                }
                else if (t_1 == 1)
                {
                    box[1] = mark;
                    choice = 1;
                    t_1 = 0;
                }
                else if (comp_win())
                {
                }
                else if (block_user())
                {
                }
                else if (choice == 1 && box[6] == '6')
                {
                    box[6] = mark;
                    //choice = 6;
                }
                else if (choice == 1 && box[8] == '8')
                {
                    box[8] = mark;
                    //choice = 8;
                }
                else if (choice == 1 && box[5] == '5')
                {
                    box[5] = mark;
                    //choice = 5;
                }
                else if (choice == 6 && box[5] == '5')
                {
                    box[5] = mark;
                }
                else if (choice == 8 && box[5] == '5')
                {
                    box[5] = mark;
                }
                else if (choice == 5 && box[2] == '2')
                {
                    box[2] = mark;
                }
                else if (choice == 5 && box[4] == '4')
                {
                    box[4] = mark;
                }
                else if (choice == 2 && box[4] == '4')
                {
                    box[4] = mark;
                    //choice = 4;
                }
                else if (choice == 2 && box[2] == '2')
                {
                    box[2] = mark;
                   // choice = 3;
                }
                else if (choice == 2 && box[5] == '5')
                {
                    box[5] = mark;
                   // choice = 10;
                }
                else if (choice == 4 && box[5] == '5')
                {
                    box[5] = mark;
                }
                else if (choice == 3 && box[5] == '5')
                {
                    box[5] = mark;
                }
                else if (choice == 10 && box[6] == '6')
                {
                    box[6] = mark;
                }
                else if (choice == 5 && box[8] == '8')
                {
                    box[8] = mark;
                }
                else
                {
                    for (int l = 1; l <= 9; l++)
                    {
                        if (box[l] != 'X')
                        {
                            box[l] = mark;
                            choice = l;
                            break;
                        }
                    }
                }
                // printf("%d\n", choice);
            }
            i = checkWinner();
            player++;
        }
        while (i == -1);

        createBoard();

        if (i == 1)
            printf("Player %d You have won the game", --player);
        else
            printf("<-------Draw------->");
        break;

    case 2:
        printf("\nYou selected Player vs Player\n");
        do
        {

            createBoard();
            player = (player % 2) ? 1 : 2;

            printf("\t\tplayer %d, enter a number:", player);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'o';
            markingBoard(choice, mark);

            i = checkWinner();
            player++;
        }
        while
        (i == -1);
        createBoard();

        if (i == 1)
            printf("player %d You have won the game", --player);
        else
            printf("<-------Draw------->");
        return 0;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}

void createBoard()
{
    printf("\n\n\t\tTic-tac-toe\n\n");
    printf("\t\t\t\t\tPlayer 1 (X) -- Player 2 (0)\n\n");
    printf("\t\t\t\t\t\t    |    |   \n");
    printf("\t\t\t\t\t\t  %c | %c  |%c   \n", box[1], box[2], box[3]);
    printf("\t\t\t\t\t\t____|____|____\n");
    printf("\t\t\t\t\t\t    |    |   \n");
    printf("\t\t\t\t\t\t  %c | %c  |%c   \n", box[4], box[5], box[6]);
    printf("\t\t\t\t\t\t____|____|____\n");
    printf("\t\t\t\t\t\t    |    |   \n");
    printf("\t\t\t\t\t\t %c  | %c  |%c   \n", box[7], box[8], box[9]);
    printf("\t\t\t\t\t\t____|____|____\n");
    printf("\t\t\t\t\t\t    |    |   \n");
}

void markingBoard(int choice, char mark)
{
    if (choice == 1 && box[1] == '1')
    {
        box[1] = mark;
    }
    else if (choice == 2 && box[2] == '2')
    {
        box[2] = mark;
    }
    else if (choice == 3 && box[3] == '3')
    {
        box[3] = mark;
    }
    else if (choice == 4 && box[4] == '4')
    {
        box[4] = mark;
    }
    else if (choice == 5 && box[5] == '5')
    {
        box[5] = mark;
    }
    else if (choice == 6 && box[6] == '6')
    {
        box[6] = mark;
    }
    else if (choice == 7 && box[7] == '7')
    {
        box[7] = mark;
    }
    else if (choice == 8 && box[8] == '8')
    {
        box[8] = mark;
    }
    else if (choice == 9 && box[9] == '9')
    {
        box[9] = mark;
    }
    else
    {
        printf("Invalid");
    }
}

int checkWinner()
{
    // horizontal matching condition...
    if (box[1] == box[2] && box[2] == box[3])
        return 1;
    else if (box[4] == box[5] && box[5] == box[6])      // horizontal match...
        return 1;
    else if (box[7] == box[8] && box[8] == box[9])
        return 1;

    // vartical matching condition...
    else if (box[1] == box[4] && box[4] == box[7])
        return 1;
    else if (box[2] == box[5] && box[5] == box[8])      // vartical match...
        return 1;
    else if (box[3] == box[6] && box[6] == box[9])
        return 1;

    // transverse matching condition...
    else if (box[1] == box[5] && box[5] == box[9])      // transverse match...
        return 1;
    else if (box[3] == box[5] && box[5] == box[7])
        return 1;

    // no matching condition...
    else if (box[1]!= '1' && box[2]!= '2' && box[3]!= '3' && box[4]!= '4' && box[5]!= '5' && box[6]!= '6' && box[7]!= '7' && box[8]!= '8' && box[9]!= '9')      // no match...
        return 0;
    else
    {
        return -1;
    }
    return 0;
}

int comp_win()
{
    if (box[1] == 'O' && box[2] == 'O' && box[3] == '3')
    {
        box[3] = mark;
        return 1;
    }
    else if (box[1] == 'O' && box[3] == 'O' && box[2] == '2')
    {
        box[2] = mark;
        return 1;
    }
    else if (box[2] == 'O' && box[3] == 'O' && box[1] == '1')
    {
        box[1] = mark;
        return 1;
    }
    else if (box[4] == 'O' && box[5] == 'O' && box[6] == '6')
    {
        box[6] = mark;
        return 1;
    }
    else if (box[4] == 'O' && box[6] == 'O' && box[5] == '5')
    {
        box[5] = mark;
        return 1;
    }
    else if (box[6] == 'O' && box[5] == 'O' && box[4] == '4')
    {
        box[4] = mark;
        return 1;
    }
    else if (box[7] == 'O' && box[8] == 'O' && box[9] == '9')
    {
        box[9] = mark;
        return 1;
    }
    else if (box[7] == 'O' && box[9] == 'O' && box[8] == '8')
    {
        box[8] = mark;
        return 1;
    }
    else if (box[8] == 'O' && box[9] == 'O' && box[7] == '7')
    {
        box[7] = mark;
        return 1;
    }
    else if (box[1] == 'O' && box[4] == 'O' && box[7] == '7')
    {
        box[7] = mark;
        return 1;
    }
    else if (box[1] == 'O' && box[7] == 'O' && box[4] == '4')
    {
        box[4] = mark;
        return 1;
    }
    else if (box[4] == 'O' && box[7] == 'O' && box[1] == '1')
    {
        box[1] = mark;
        return 1;
    }
    else if (box[2] == 'O' && box[5] == 'O' && box[8] == '8')
    {
        box[8] = mark;
        return 1;
    }
    else if (box[2] == 'O' && box[8] == 'O' && box[5] == '5')
    {
        box[5] = mark;
        return 1;
    }
    else if (box[5] == 'O' && box[8] == 'O' && box[2] == '2')
    {
        box[2] = mark;
        return 1;
    }
    else if (box[3] == 'O' && box[6] == 'O' && box[9] == '9')
    {
        box[9] = mark;
        return 1;
    }
    else if (box[3] == 'O' && box[9] == 'O' && box[6] == '6')
    {
        box[6] = mark;
        return 1;
    }
    else if (box[6] == 'O' && box[9] == 'O' && box[3] == '3')
    {
        box[3] = mark;
        return 1;
    }
    else if (box[1] == 'O' && box[5] == 'O' && box[9] == '9')
    {
        box[9] = mark;
        return 1;
    }
    else if (box[1] == 'O' && box[9] == 'O' && box[5] == '5')
    {
        box[5] = mark;
        return 1;
    }
    else if (box[5] == 'O' && box[9] == 'O' && box[1] == '1')
    {
        box[1] = mark;
        return 1;
    }
    else if (box[3] == 'O' && box[5] == 'O' && box[7] == '7')
    {
        box[7] = mark;
        return 1;
    }
    else if (box[3] == 'O' && box[7] == 'O' && box[5] == '5')
    {
        box[5] = mark;
        return 1;
    }
    else if (box[5] == 'O' && box[7] == 'O' && box[3] == '3')
    {
        box[3] = mark;
        return 1;
    }
    else
    {
        return 0;
    }
}

int block_user()
{
    if(box[1]=='X' && box[2]=='X' && box[3]=='3')
    {
        box[3]=mark;
        return 1;
    }
    else if(box[1]=='X' && box[3]=='X' && box[2]=='2')
    {
        box[2]=mark;
        return 1;
    }
    else if(box[2]=='X' && box[3]=='X' && box[1]=='1')
    {
        box[1]=mark;
        return 1;
    }
    else if(box[4]=='X' && box[5]=='X' && box[6]=='6')
    {
        box[6]=mark;
        return 1;
    }
    else if(box[4]=='X' && box[6]=='X' && box[5]=='5')
    {
        box[5]=mark;
        return 1;
    }
    else if(box[6]=='X' && box[5]=='X' && box[4]=='4')
    {
        box[4]=mark;
        return 1;
    }
    else if(box[7]=='X' && box[8]=='X' && box[9]=='9')
    {
        box[9]=mark;
        return 1;
    }
    else if(box[7]=='X' && box[9]=='X' && box[8]=='8')
    {
        box[8]=mark;
        return 1;
    }
    else if(box[8]=='X' && box[9]=='X' && box[7]=='7')
    {
        box[7]=mark;
        return 1;
    }
    else if(box[1]=='X' && box[4]=='X' && box[7]=='7')
    {
        box[7]=mark;
        return 1;
    }
    else if(box[1]=='X' && box[7]=='X' && box[4]=='4')
    {
        box[4]=mark;
        return 1;
    }
    else if(box[4]=='X' && box[7]=='X' && box[1]=='1')
    {
        box[1]=mark;
        return 1;
    }
    else if(box[2]=='X' && box[5]=='X' && box[8]=='8')
    {
        box[8]=mark;
        return 1;
    }
    else if(box[2]=='X' && box[8]=='X' && box[5]=='5')
    {
        box[5]=mark;
        return 1;
    }
    else if(box[5]=='X' && box[8]=='X' && box[2]=='2')
    {
        box[2]=mark;
        return 1;
    }
    else if(box[3]=='X' && box[6]=='X' && box[9]=='9')
    {
        box[9]=mark;
        return 1;
    }
    else if(box[3]=='X' && box[9]=='X' && box[6]=='6')
    {
        box[6]=mark;
        return 1;
    }
    else if(box[6]=='X' && box[9]=='X' && box[3]=='3')
    {
        box[3]=mark;
        return 1;
    }
    else if(box[1]=='X' && box[5]=='X' && box[9]=='9')
    {
        box[9]=mark;
        return 1;
    }
    else if(box[1]=='X' && box[9]=='X' && box[5]=='5')
    {
        box[5]=mark;
        return 1;
    }
    else if(box[5]=='X' && box[9]=='X' && box[1]=='1')
    {
        box[1]=mark;
        return 1;
    }
    else if(box[3]=='X' && box[5]=='X' && box[7]=='7')
    {
        box[7]=mark;
        return 1;
    }
    else if(box[3]=='X' && box[7]=='X' && box[5]=='5')
    {
        box[5]=mark;
        return 1;
    }
    else if(box[5]=='X' && box[7]=='X' && box[3]=='3')
    {
        box[3]=mark;
        return 1;
    }
    else
    {
        return 0;
    }
}
