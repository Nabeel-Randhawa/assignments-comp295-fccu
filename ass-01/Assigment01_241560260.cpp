#include <iostream>
#include <ctime>
#include <windows.h>			// Library used for Cursor Hiding
#include <conio.h>	
#include <iomanip>			// For basic input & output Functions

int score=0;
using namespace std;
void HideCursor();												// Function to Hide the cursor
void InitializeTile(int board [4][4]);
void randomGeneratedValue (int board [4][4]);
void displayBoard(int board [4][4]);
void moveUP(int board [4][4]);
void mergeUp(int board [4][4]);
void moveLEFT(int board [4][4]);
void mergeLeft(int board[4][4]);
void moveDOWN(int board [4][4]);
void mergeDown(int board [4][4]);
void moveRIGHT(int board [4][4]);
void mergeRight(int board[4][4]);
void scoreOver();
bool isGameOver(int board [4][4]);
void frontPage();

int main()
{
	cout <<  "----------------------------------------------------------------------------------------" << endl;
    cout <<  "			W E L C O M E      TO      2048 " << endl;
    cout <<  "----------------------------------------------------------------------------------------" << endl;
	
	frontPage();
	HideCursor();
	
	return 0;
}


void frontPage() {
 
    cout <<"1. Start the Game "<<endl;
    cout <<"2. Instructions "<<endl;
    cout <<"3. Credits "<<endl;
    cout <<"4. Exit "<<endl;
    
    char x;
    x= getch();
    if (x=='1')						// MAIN
    { 

    	system ("cls");
    	  cout << "-----------------------------------------------------------------------------------------" << endl;
    	  cout <<"				2    0	  4 	8  "<<endl;
    	  cout << "-----------------------------------------------------------------------------------------" << endl;
    	
		  int board [4][4] = {0};
		  srand(time(0));
		  
		  InitializeTile(board);
		  displayBoard(board);
		  while (!isGameOver(board))			
		  {											//Controllers
		  	char input = getch();
		  	switch (input){
			  
		  	case 'w':
		    	moveUP(board);
				break;	
			case 'a':
				moveLEFT(board);
				break;
			case 's':
				moveDOWN(board);
				break;
			case 'd':
				moveRIGHT(board);
				break;
			default:
				continue;
		}
		  system ("cls");		
		  displayBoard(board);
		  } 
		  system ("cls") ;
		  cout << "-----------------------------------------------------------------------------------------" << endl;
		  cout << "             Y O U    W I N ! "<<endl;
		  cout << "-----------------------------------------------------------------------------------------" << endl;	
	}
	if (x=='2')
	{
			 cout << "-----------------------------------------------------------------------------------------" << endl;
			 cout <<"		   	I N S T R U C T I O N S    "<<endl;
			cout <<"Press 'W' to move UP "<<endl;
			cout <<"Press 'S' to move DOWN "<<endl;
			cout <<"Press 'A' to move LEFT "<<endl;
			cout <<"Press 'D' to move RIGHT "<<endl;
			 cout << "-----------------------------------------------------------------------------------------" << endl;
			frontPage();
	}
	if (x=='3')
	{
		 cout << "-----------------------------------------------------------------------------------------" << endl;
		 cout<<"			 C R E D I T S "<<endl;
		cout <<"Nabeel Randhawa(241560260) created this game."<<endl;
		cout <<"Student of CS , 6th Semester, FC College Lahore."<<endl;
		 cout << "-----------------------------------------------------------------------------------------" << endl;
		frontPage();
	}
	if (x=='4')
	{
		system ("cls");
		cout <<"GAME IS END!"<<endl;
		cout <<"Thank You for Playing!"<<endl;
		
	}
}

void HideCursor()	// Function to Hide the cursor
{
	
	HANDLE hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo (hCon, &cci);
}
void displayBoard(int board[4][4]){
	int i=0; 
	cout <<endl<<"	S C O R E : "<<score<<endl;
	cout <<endl;
	cout <<"				/---------------\\"<<endl;
	while (i<4){
		int j=0;
		cout <<"				|";
		while (j<4){
			if (board [i][j]==0)
			{
				cout <<"  "<<" |";
			}
			else {
				if (sizeof(board[i][j])<2)
				{
				cout<<board[i][j]<<"  |";
				}
				else
				{
				cout<<board[i][j]<<"  |";	
				}
			}
			j++;
		}
		cout <<endl;
		i++;
	}
		cout <<"				\\---------------/"<<endl;
	cout <<endl;
}

void InitializeTile(int board [4][4])		// For initializing TWO random values
{
	int row=0;
	int column=0;
	
	int count =0 ;
	while (	count < 2)		// for 2 values				
	{
		row  = rand() % 4;		// For generating random values between (0-3)
		column = rand() % 4;
		if (board [row][column]!=0)
		{
			while (board [row][column]!=0)	//	
			{
				row = rand() % 4;
				column = rand() % 4;
			}
		}
		else if (board [row][column]==0)
		{
			int value=0;
			value= (rand() % 2 + 1);		// To make the value EVEN (Either 2 or 4)
			value = value * 2;
			board[row][column] = value;
		}
		count ++;
	}
}
	//movements Functions
void moveUP(int board [4][4]){
	int j=0;
	while(j<4)
	{
		int x=0;
		int i=0;
		while(i<4)
		{
			if (board[i][j]!=0)
			{
				if (x!=i)
				{
					board[x][j]= board[i][j];
					board[i][j]=0;
				
				}
			x++;
			}
		i++;
		}
	j++;
}
mergeUp( board);  // calling mergeUp funtion
randomGeneratedValue(board);
isGameOver(board);
	int b=0;
	while(b<4)
	{
		int x=0;
		int a=0;
		while(a<4)
		{
			if (board[a][b]!= 0)
			{
				if (x!=a)
				{
					board[x][b]= board[a][b];
					board[a][b]=0;
				
				}
			x++;
			}
		a++;
		}
	b++;
	}
	
}
void moveLEFT(int board [4][4]){

	int i=0;
 	while(i<4)
	{
        int x = 0;
        int j=0;
        while(j<4)
		{
            if (board[i][j] != 0) {
            	
                if (x!=j)
					{
                    board[i][x] = board[i][j];
                    board[i][j] = 0;
                	}
            x++;
            }
        j++;
        }
    i++;
    }
    
mergeLeft(board);    // calling mergeleft funtion
randomGeneratedValue(board);  // Generating random values
isGameOver(board);     // Check the desired number
	int a=0;
 	while(a<4)
	{
        int x = 0;
        int b=0;
        while(b<4)
		{
            if (board[a][b] != 0) {
            	
                if (x != b)
					{
                    board[a][x] = board[a][b];
                    board[a][b] = 0;
                	}
            x++;
            }
        b++;
        }
    a++;
    }
}

void moveDOWN(int board[4][4]) {
    int j=0;
	while(j < 4) {
        int x = 3;
        int i = 3;
        while(i>=0) {
            if (board[i][j] != 0) {
                if (x!=i) {
                    board[x][j] = board[i][j];
                    board[i][j] = 0;
                }
            x--;
            }
        i--;
        }
    j++;
    }
mergeDown(board); // calling mergeDown funtion
randomGeneratedValue(board);  // Generating random values
isGameOver(board);     // Check the desired number
    int b=0;
	while(b<4) {
        int x = 3;
        int a = 3;
        while(a>=0) {
            if (board[a][b] != 0) {
                if (x!=a) {
                    board[x][b] = board[a][b];
                    board[a][b] = 0;
                }
            x--;
            }
        a--;
        }
    b++;
    }
}
void moveRIGHT (int board[4][4])
{
	int i=0;
    while(i<4) 
	{
        int x=3;
        int j=3;
        while(j>=0) 
			{
            if (board[i][j] != 0) 
			{
                if (x!=j)
				{
                    board[i][x] = board[i][j];
                    board[i][j] = 0;
                }
            x--;
            }
        j--;
        }
    i++;
    }
mergeRight(board); // calling mergeRight funtion
randomGeneratedValue(board);  // Generating random values
isGameOver(board);     // Check the desired number
   	int a=0;
    while(a<4) 
	{
        int x=3;
        int b=3;
        while(b>=0) 
			{
            if (board[a][b] != 0) 
			{
                if (x!=b)
				{
                    board[a][x]=board[a][b];
                    board[a][b] = 0;
                }
            x--;
            }
        b--;
        }
    a++;
    }
  	
}
void randomGeneratedValue (int board [4][4]){

	int row=0;
	int column=0;

		row  = rand() % 4;		// For generating random values between (0-3)
		column = rand() % 4;
		if (board [row][column]!=0)
		{
			while (board [row][column]!=0)	//	
			{
				row = rand() % 4;
				column = rand() % 4;
			}
		}
		else if (board [row][column]==0)
		{
			int value=0;
			value= (rand() % 2 + 1);		// To make the value EVEN (Either 2 or 4)
			value = value * 2;
			board[row][column] = value;
		}
}
bool isGameOver(int board [4][4])
{	
	int i=0;
	while(i<4)
	{
		int j=0;
		while(j<4)
		{
			if (board[i][j]==2048 || board[i][j]==32 ) // 32 check just for checking the working 
			{
				return true;
			}
		j++;
		}
	i++;
	}

	for (int i=0; i<4; i++) // check same value horizontally
	{
		int j=0;
		do
		{
			if (board[i][j]==0 || board[i][j] == board[i][j+1])
			{ 
			return false;
			}
		j++;	
		}while(i<3);
	}
	for (int j=0; j<4; i++) // check same value vertically
	{
		int i=0;
		do
		{
			if (board[i][j]==0 || board[i][j]== board[i+1][j])
			{ 
			return false;
			}
		i++;	
		}while(i<3);
		
	}
	
	system ("cls");
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "            G A M E     O V E R! "<<endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;	
	return true;
}

void mergeUp(int board[4][4])

{
	int j=0;
	while (j<4)
	{   
		int i=0;
		while(i<3)
		{
			if (board [i][j] == board[i+1][j] && board [i][j]!=0)
			{
				board [i][j]+= board[i][j];
				
				score += board[i][j];
				
				board [i+1][j]=0;
				
			}
		i++;
		}
	j++;
	}
}
void mergeDown(int board [4][4])
{
    int j=0;
    while (j<4) 
	{
		int i = 3;
        while(i > 0) {
            if (board[i][j] == board[i - 1][j] && board[i][j] != 0)
			{
                board[i][j]+=board[i][j];
                
                score += board[i][j];
                
                board[i - 1][j] = 0;
            }
        i--;
        }
    j++;
    }
}
void mergeRight(int board[4][4])

{

	int i=0;	
    while (i<4) 
	{
		int j=3;
        while(j>0) 
		{
            if (board[i][j]==board[i][j - 1] && board[i][j]!=0)
			{
                board[i][j]+=board[i][j];
                
                score += board[i][j];
                
                board[i][j - 1] = 0;
            }
        j--;
        }
    i++;
    }
}

void mergeLeft(int board[4][4])
{
int i=0;
    while(i<4) 
	{
		int j=0;
		while(j<3) 
		{
            if ( board[i][j] != 0 && board[i][j] == board[i][j + 1] )
			{
                board[i][j] += board [i][j];
                
                score += board[i][j];
                
                board[i][j + 1] = 0;
            }
        j++;
		}
	i++;
    }
}
