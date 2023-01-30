#include <stdio.h>
#include <stdlib.h>

#define BSIZE 8
#define BACKGROUND '*'
#define debug 1

char board[BSIZE][BSIZE];

enum types{PAWN,ROOK,KNIGHT,BISHOP,QUEEN,KING};

struct piece
{
	int type;
	int x;
	int y;
	short upper;
	char symb;
	
};

int turn=0;

//Def vars of pieces
struct piece P0;
struct piece P1;
struct piece *pP1=&P1;

struct piece P2;
struct piece *pP2=&P2;

struct piece P3;
struct piece P4;
struct piece P5;
struct piece P6;
struct piece P7;


struct piece p0;
struct piece p1;
struct piece p2;
struct piece p3;
struct piece p4;
struct piece p5;
struct piece p6;
struct piece p7;

struct piece left_rook;
struct piece right_rook;
struct piece LEFT_ROOK;
struct piece RIGHT_ROOK;

struct piece left_knight;
struct piece right_knight;
struct piece LEFT_KNIGHT;
struct piece RIGHT_KNIGHT;

struct piece left_bishop;
struct piece right_bishop;
struct piece LEFT_BISHOP;
struct piece RIGHT_BISHOP;

struct piece queen;
struct piece QU33N; //Name has number in it cause name collision with enum
struct piece king;
struct piece K1NG5;

void initPawn(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'P':'p';
	p->type=PAWN;
	
	board[p->y][p->x]=p->symb;
}

void initRook(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'R':'r';
	p->type=ROOK;
	
	board[p->y][p->x]=p->symb;
}

void initKnight(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'N':'n';
	p->type=KNIGHT;
	
	board[p->y][p->x]=p->symb;
}

void initBishop(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'B':'b';
	p->type=BISHOP;
	
	board[p->y][p->x]=p->symb;
}

void initQueen(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'Q':'q';
	p->type=QUEEN;
	
	board[p->y][p->x]=p->symb;
}

void initKing(struct piece *p,int X, int Y, short up)
{
	p->x=X;
	p->y=Y;
	p->upper=up;
	p->symb= p->upper? 'K':'k';
	p->type=KING;
	
	board[p->y][p->x]=p->symb;
}

//inits board
int initBoard()
{
	//fills board[] with zeroes
	for(int i =0; i<BSIZE; i++)
	{
		for(int j=0; j<BSIZE; j++)
		{
			board[i][j]=BACKGROUND;
		}
	}
	
	//pawns
	initPawn(&p0,0,1,0);
	initPawn(&p1,1,1,0);
	initPawn(&p2,2,1,0);
	initPawn(&p3,3,1,0);
	initPawn(&p4,4,1,0);
	initPawn(&p5,5,1,0);
	initPawn(&p6,6,1,0);
	initPawn(&p7,7,1,0);
	
	initPawn(&P0,0,6,1);
	initPawn(&P1,1,6,1);
	initPawn(&P2,2,6,1);
	initPawn(&P3,3,6,1);
	initPawn(&P4,4,6,1);
	initPawn(&P5,5,6,1);
	initPawn(&P6,6,6,1);
	initPawn(&P7,7,6,1);

	//rooks
	initRook(&left_rook,0,0,0);
	initRook(&right_rook,7,0,0);
	initRook(&LEFT_ROOK,0,7,1);
	initRook(&RIGHT_ROOK,7,7,1);
	//knights
	initKnight(&left_knight,1,0,0);
	initKnight(&right_knight,6,0,0);
	initKnight(&LEFT_KNIGHT,1,7,1);
	initKnight(&RIGHT_KNIGHT,6,7,1);
	
	//bishops
	initBishop(&left_bishop,2,0,0);
	initBishop(&right_bishop,5,0,0);
	initBishop(&LEFT_BISHOP,2,7,1);
	initBishop(&RIGHT_BISHOP,5,7,1);
	
	//queens
	initQueen(&queen,3,0,0);
	initQueen(&QU33N,3,7,1);
	
	//kings
	initKing(&king,4,0,0);
	initKing(&king,4,7,1);
	
	printf("Chess!\n\nType \"HELP\" for help.\n");
}





//Prints Board
void printBoard()
{
	int y=8;
	
	printf("\nTurn %d",turn++);
	
	putchar('\n');
	printf("  a b c d e f g h \n");
	for(int i=0;i<BSIZE;i++)
	{
		printf("%d ",y--);
		for(int j=0;j<BSIZE;j++)
		{
			putchar(board[i][j]);
			putchar(' ');
		}
		if(debug)
		{
			printf("%d",7-y);
		}
		putchar('\n');
	}
	
	if(debug)
	{
		printf("  0 1 2 3 4 5 6 7 \n");
	}
}

int getYCoords(char numb)
{
	int num= atoi(numb)
	if(num>8 || num<1)
		return -1;
	else
		return 8-num;
}

int getXCoords(char letter)
{
	switch(letter)
	{
		case 'a':
			return 0;
			//No break cause return
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 4;
		case 'f':
			return 5;
		case 'g':
			return 6;
		case 'h':
			return 7;
		default:
			return -1;
	}
}

int main()
{
	int oldX;
	int newX;
	int oldY;
	int newY;
	
	initBoard();
	printBoard();
	printf("Enter Command: ");
	char input[100];
	
	scanf("%s", input);
	
	for(int i =0; i<100; i++)
	{
		putchar(input[i]);
	}
	putchar('\n');


	while(!(input[0]=='Q' && input[1]=='U' && input[2]=='I' && input[3]=='T'))
	{
		if(input[0]=='H' && input[1]=='E' && input[2]=='L' && input[3]=='P')
		{
			printf("How to play: You type in 4 characters,\nthe first two to select which piece you want to move,\n");
			printf("the last two for where you want the piece to move.\n");
			printf("So a2a3 moves the leftmost uppercase pawn 1 step forward.\n");
			printf("Type \"QUIT\" to quit.\n");
			printf("Uppercase goes first.\n");
		}
		
		oldX=getXCoords(input[0]);
		oldY=getYCoords(input[1]);
		newX=getXCoords(input[2]);
		newY=getYCoords(input[3]);
		
		printf("%d%d%d%d", oldX, oldY, newX, newY);
	    

		
		
		
		printf("Enter Command: ");
		scanf("%s", input);
		for(int i =0; i<100; i++)
		{
			putchar(input[i]);
		}
		putchar('\n');

		
	}

	return 0;
}
//p|k|q|

//K Q R P H B 
//k q r p h b 