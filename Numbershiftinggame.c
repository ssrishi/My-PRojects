#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<time.h>
void create_array(int [][4]);
void game_rules();
void swap(int *,int *);
int show_matrix(int [][4]);
int win_arr(int [][4]);
int Move_up(int [][4]);
int Move_down(int [][4]);
int Move_left(int [][4]);
int Move_right(int [][4]);
void game_rules()
{
    system("cls");
    printf("            RULES OF THIS GAME\n");
    printf("\n1. You can move only 1 step at a time by arrow key\n");
    printf("Move Up : by Up arrow key\nMove down : by Down arrow key\nMove Left : by Left arrow key\nMove Right : by Right arrow key\n");
    printf("2. You can move number at empty position only\n");
    printf("\nFor each valid move : your toral number of move will be decreased by 1\n");
    printf("\nWinning situation : number in a 4*4 matrix should be in order from 1 to 15\n");
    printf("        Winning Situation:\n");
    printf("---------------------\n| 1  | 2  | 3  | 4  |\n| 5  | 6  | 7  | 8  |\n| 9  | 10 | 11 | 12 |\n| 13 | 14 | 15 |    |");
    printf("\n---------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e'\nSo try to win in minimum no. of move\n");
    printf("\n        Happy gaming , Good Luck");
}
int show_matrix(int arr[][4])
{
    int i,j;
    printf("--------------------\n");
    for(i=0;i<=3;i++)
    {
         printf("|");
        for(j=0;j<=3;j++)
        {
            if(arr[i][j]!=0)
                printf(" %2d |",arr[i][j]);
            else
                printf("    |");
            }
            printf("\n");
    }
    printf("--------------------\n");
    return 0;
}
void swap(int *p,int *q)
{
    *p=*p+*q;
    *q=*p-*q;
    *p=*p-*q;
    printf("");
}
int Move_up(int arr[][4])
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(arr[i][j]==0)
            break;
    }
    if(i==3)
        return 0;
    swap(&arr[i][j],&arr[i+1][j]);
    return 1;
}
int Move_down(int arr[][4])
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(arr[i][j]==0)
            break;
    }
    if(i< 0)
        return 0;
    swap(&arr[i][j],&arr[i-1][j]);
    return 1;

}
int Move_left(int arr[][4])
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(arr[i][j]==0)
            break;
    }
    if(j==3)
        return 0;
    swap(&arr[i][j],&arr[i][j+1]);
    return 1;
}
int Move_right(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}
int win_arr(int arr[][4])
{
    int winn_arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=winn_arr[i][j])
                return 0;
        }
    }
    return 1;
}
void create_array(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for (i=0; i<n; i++)
        num[i]=i+1;
    srand(time(NULL)); // for random number generation

    int lastIndex = n - 1, index;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(lastIndex>=0)
            {
                index=rand()%(lastIndex + 1);
                printf("\n%d\n",index); // idea : performing % operation by (lastIndex+1)
                arr[i][j]=num[index];           // will give index , so put that num[index] number in matrix
                num[index]=num[lastIndex--];    // and replace last number with this indexed positioned number
            }                                     // and finally lastIndex--
        }
    arr[i - 1][j - 1]=0; // last number is zero
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    getch();
}
int main()
{
    int arr[4][4];
    int key,i,j,max_move=10;
    char name[30];
    printf("\n\n\nEnter Your name: ");
    fgets(name,30,stdin);

    while(1)
    {
        create_array(arr);
        game_rules();
        printf("\n press Enter to start: ");
        getch();
        while (!win_arr(arr))
        {
            system("cls");
            if(!max_move)
                break;
            printf("\nPlayer Name: %s,   Move Remaining: %d\n\n\n",name,max_move);
            show_matrix(arr);
            key = getch();
            switch (key)
            {
            case 69:
            case 101:
                printf("\n    Thanks For Playing.\n    Press Enter to exit-");
                getch();
                return 0;
            case 80:
                if(Move_down(arr))
                    max_move--;
                break;
            case 75:
                if(Move_left(arr))
                    max_move--;
                break;
            case 77:
                if(Move_right(arr))
                    max_move--;
                break;
            case 72:
                if(Move_up(arr))
                    max_move--;
                break;
            }
        }
        if(max_move==0)
            printf("\n  You Lose");
        else
            printf("Congratulation %s on winning the game.",name);
        printf("\n\n Do you want to play again, Enter 'y' to play and 'n' to exit: ");
        key = getch();
        if(key=='n'|| key=='N')
            return 0;
        else
            max_move=10;
    }
}
