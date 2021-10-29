#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include <unistd.h>
int number;
int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fx, fy, flag;
int n_players,_1st=0,_2nd=0,_3rd=0,_4th=0,position=0,seat=0,f,d1,d2;
int c;
char you,comp,ch;
char mark;
int player = 1, i, choice;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


	char you, computer, result;

char n;
int Dice()
{
	while("game")
	{
		if(d1!=6&&d2!=6)
		break;
		while(1)
		{
			scanf("%c",&n);
			if(n==10)
			{
				d2=(rand()%6)+1;
				break;
			}
		}
		printf("The dice turned to be %d\n",d2);
		d1=d1+d2;
	}
}
  

int Rolling()
{
	scanf("%c",&n);
	
	if(n==10)
	{
		srand(time(0));
		d1=(rand()%6)+1;
	}
	printf("The dice turned to be:%d\n",d1);
}
void logic()
{
    sleep(0.1);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
  
   
    if (x < 0 || x > height
        || y < 0 || y > width)
        gameover = 1;
  
    
    if (x == fx && y == fy) {
    label3:
        fx = rand() % 20;
        if (fx == 0)
            goto label3;
  
   
    label4:
        fy = rand() % 20;
        if (fy == 0)
            goto label4;
        score += 10;
    }
}
  

void input()
{
    if (kbhit()) {
        switch (getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
  

void draw()
{
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1
                || j == 0
                || j == height - 1) {
                printf("*");
            }
            else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fx
                         && j == fy)
                    printf("#");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
  
    
    printf("score = %d", score);
    printf("\n");
    //printf("press X to quit the game\n");
}
  
void setup()
{
    gameover = 0;
  
    
    x = height / 2;
    y = width / 2;
label1:
    fx = rand() % 20;
    if (fx == 0)
        goto label1;
label2:
    fy = rand() % 20;
    if (fy == 0)
        goto label2;
    score = 0;
}
  
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}

void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}


int game(char you, char computer)
{
	// If both the user and computer
	// has chose the same thing
	if (you == computer)
		return -1;

	// If user's choice is stone and
	// computer's choice is paper
	if (you == 's' && computer == 'p')
		return 0;

			// If user's choice is paper and
			// computer's choice is stone
			else if (you == 'p' && computer == 's') return 1;

	// If user's choice is stone and
	// computer's choice is scissor
	if (you == 's' && computer == 'z')
		return 1;

	// If user's choice is scissor and
	// computer's choice is stone
	else if (you == 'z' && computer == 's')
		return 0;

	// If user's choice is paper and
	// computer's choice is scissor
	if (you == 'p' && computer == 'z')
		return 0;

	// If user's choice is scissor and
	// computer's choice is paper
	else if (you == 'z' && computer == 'p')
		return 1;
}

int main ()
{   do{

	printf("Enter 1 for Rock Paper Scissors\n");
	printf("Enter 2 for Tic Tac Toe\n");
	printf("Enter 3 for Snake & Fruit\n ");
	printf("Enter 4 for Snake & Ladder\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:     
		

	// Chooses the random number
	// every time
	srand(time(0));

	// Make the random number less
	// than 100, divided it by 100
	number = rand() % 100;

	// Using simple probability 100 is
	// roughly divided among stone,
	// paper, and scissor
	if (number < 33)

		// s is denoting Stone
		computer = 's';

	else if (number > 33 && number < 66)

		// p is denoting Paper
		computer = 'p';

	// z is denoting Scissor
	else
		computer = 'z';

	printf("\n\n\n\nEnter s	for STONE, p for PAPER 	and z for SCISSOR\n");

	// input from the user
	scanf("%c", &you);
	scanf("%c", &you);

	// Function Call to play the game
	result = game(you, computer);

	if (result == -1) {
		printf("\n\nGame Draw!\n");
	}
	else if (result == 1) {
		printf("\n\nWow! You have won the game!\n");}
		else
		 printf("\n\nOh! You have lost the game!\n");

		printf("YOu choose : %c"
			" and Computer choose : "
			"%c\n",
			you, computer);

	break;
	
	
	case 2: 

    
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();
    break;
    
    
    
    case 3:  setup();
  
    
    while (!gameover) {
  
        draw();
        input();
        logic();
    }
    
    break;
    
    
    case 4:	
	printf("\t\t\t\t\t Welcome to Snake and Ladder Game\n\n");
	printf("|100    99    98    97    96    95    94    93    92    91|         Snake 97 to 7        Ladder 13 to 80\n");
	printf("| 90    89    88    87    86    85    84    83    82    81|         Snake 84 to 44       Ladder 21 to 70\n");
	printf("| 80    79    78    77    76    75    74    73    72    71|         Snake 73 to 36       Ladder 33 to 64\n");
	printf("| 70    69    68    67    66    65    64    63    62    61|         Snake 66 to 55       Ladder 49 to 54\n");
	printf("| 60    59    58    57    56    55    54    53    52    51|         Snake 52 to 5        Ladder 51 to 89\n");
	printf("| 50    49    48    47    46    45    44    43    42    41|         Snake 43 to 16       Ladder 69 to 77\n");
	printf("| 40    39    38    37    36    35    34    33    32    31|         Snake 34 to 22       Ladder 72 to 96\n");
	printf("| 30    29    28    27    26    25    24    23    22    21|         Snake 25 to 15       Ladder 81 to 91\n");
	printf("| 20    19    18    17    16    15    14    13    12    11|         Snake 11 to 1        Ladder 90 to 99\n");
	printf("| 10    09    08    07    06    05    04    03    02    01|  <---START HERE\n");
	
	printf("\t\t\t\t\tPress Enter to Roll the Dice\n");
	printf("Max player should not exceed 4\t\tEnter the no of players you want:");
	scanf("%d",&n_players);
	//selection of players
	while("game")
	{
		f=(seat%n_players)+1;
		printf("Player %d turn\n",f);
		
		Rolling();
		Dice();
		
		if(f==1)
		position=_1st;
		if(f==2)
		position=_2nd;
		if(f==3)
		position=_3rd;
		if(f==4)
		position=_4th;
		if(position+d1>100)
		printf("The value exceeds 100 so the player will not move\n");
		else if(position+d1<=100)
		{
			position=position+d1;//increment of players position
			
		}
		//for ladder
		if (position==13)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+67;
		}
		if (position==21)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+49;
		}
		if (position==33)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+31;
		}
		if (position==49)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+5;
		}
		if (position==51)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+38;
		}
		if (position==69)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+8;
		}
		if (position==72)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+24;
		}
		if (position==81)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+10;
		}
		if (position==90)
		{
			printf("Hurray! Up the Ladder\n");
			position = position+9;
		}
		//for snakes
		if (position==97)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-90;
		}
		if (position==84)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-40;
		}
		if (position==73)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-37;
		}
		if (position==66)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-11;
		}
		if (position==52)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-47;
		}
		if (position==43)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-27;
		}
		if (position==34)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-12;
		}
		if (position==25)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-10;
		}
		if (position==11)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-10;
		}
		if (position==45)
		{
			printf("Ouch!Bitten by a snake\n");
			position = position-35;
		}
		
	
	//position of players
	if(f==1)
	{
		_1st=position;
		printf("Player 1 landed on %d\n",_1st);
	}
	if(f==2)
	{
		_2nd=position;
		printf("Player 2 landed on %d\n",_2nd);
	}
	if(f==3)
	{
		_3rd=position;
		printf("Player 3 landed on %d\n",_3rd);
	}
	if(f==4)
	{
		_4th=position;
		printf("Player 4 landed on %d\n",_4th);
	}
	//winning
	if(_1st==100)
	{
		printf("player 1 wins\n");
		break;
	
	}
	if(_2nd==100)
	{
		printf("player 2 wins\n");
		break;
	}
	if(_3rd==100)
	{
		printf("player 3 wins\n");
		break;
		
	}
	if(_4th==100)
	{
		printf("player 4 wins\n");
		break;
		
	}
	seat++;
}

printf("Game Over Congratulations\n");

	
	
	
	
	
	}
	printf("enter 1 to continue 0 to exit");

scanf("%d",&ch);
}while(ch==1);

	
return 0;	
}
