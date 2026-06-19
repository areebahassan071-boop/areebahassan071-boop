//areeba
//SU91-BIETM-F23-038
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
char number[10]={ '0','1','2','3','4','5','6','7','8','9'};
char numbers[10]={ '0','1','2','3','4','5','6','7','8','9'};
int i,c,player=1;
char a,b;
int choice;
char sign;
char f,d,hint, hints;
int j,gamer,option;
int result ();
int results ();
void board();
void display();
void board2();
void display2();
void symbol()
{ 
	cout<<"The signs are 'X' and 'O' ."<<endl;
	cout<<endl;
	cout<<"player 1 Enter your sign : ";
	cin>>a;
	cout<<"The sign of player 2 is not equal to the sign of player 1."<<endl;
	cout<<"player 2 Enter your sign : ";
	cin>>b;	
}
void marks ()
{
 	cout<<"The signs are 'X' and 'O' ."<<endl;
	cout<<endl;
	cout<<"player  Enter your sign : ";
	cin>>f;	
	if (f=='X')
	{
		d='O';
	}
	else
	{
		d='X';
	}
}
int main ()
{
	int c;
 do
{
	cout<<"        ############################\n";
	cout<<"        #     tic tac toe          #\n";
    cout<<"        ############################\n";
    cout<<"        # 1. Single player         #\n";
    cout<<"        # 2. Double Player         #\n";
    cout<<"        # 3. Exit                  #\n";
    cout<<"        ############################\n";
    cout<<"        Enter your choice: ";
    cin>>c;
    switch(c)
    {
    case 1:
marks();
do
{
board2();

if(gamer%2==1)
gamer=1;
else
gamer=2;
if(gamer==2)
{
cout << "Players  " << gamer<<endl;
cout<<"Press Enter for CPU"<<endl;
option=rand()%9;
hint=d;
int turn=1;
int placed=0;
while(placed==0)
{
if (option == 1 && numbers[1] == '1') {
numbers[1] = hint;
placed=1;
}
else if (option == 2 && numbers[2] == '2'){
numbers[2] = hint;
placed=1;
}
else if (option == 3 && numbers[3] == '3'){
numbers[3] = hint;
placed=1;
}
else if (option == 4 && numbers[4] == '4'){
numbers[4] = hint;
placed=1;
}
else if (option == 5 && numbers[5] == '5'){
numbers[5] = hint;
placed=1;
}
else if (option == 6 && numbers[6] == '6'){
numbers[6] = hint;
placed=1;
}
else if (option == 7 && numbers[7] == '7'){
numbers[7] = hint;
placed=1;
}
else if (option == 8 && numbers[8] == '8'){
numbers[8] = hint;
placed=1;
}
else if (option == 9 && numbers[9] == '9'){
numbers[9] = hint;
placed=1;
}
else
{
option=rand()%9;
}
}
j=results();
gamer++;
_getche();
board2();
}
else if(gamer==1)
{
cout << "Players  " << gamer << ": Enter a number:  ";
cin >> option;
hints=f;
if (option == 1 && numbers[1] == '1')
numbers[1] = hints;
else if (option == 2 && numbers[2] == '2')
numbers[2] = hints;
else if (option == 3 && numbers[3] == '3')
numbers[3] = hints;
else if (option == 4 && numbers[4] == '4')
numbers[4] = hints;
else if (option == 5 && numbers[5] == '5')
numbers[5] = hints;
else if (option == 6 && numbers[6] == '6')
numbers[6] = hints;
else if (option == 7 && numbers[7] == '7')
numbers[7] = hints;
else if (option == 8 && numbers[8] == '8')
numbers[8] = hints;
else if (option == 9 && numbers[9] == '9')
numbers[9] = hints;
else
{
cout<<"Invalid move ";
gamer--;
_getche();
}
j=results();
gamer++;
}
} 
while(j==-1);
board2();
if(j==1)
cout<<"Congratulation! \nPlayer "<<--gamer<<" win \n";
else
cout<<"  OOps!\nGame draw\n";
_getche();
    		break;
    		 case 2:
    		 	symbol();
    			  do
				  {
				   board();
				    player=(player%2)?1:2;
                    cout<<"Player " << player << ", enter a number:  ";
                    cin>>choice;
                    sign=(player == 1) ? a : b;
    	           display();
				   i=result();
				   player++;
				}
			  	while(i==-1);
			  	board();
				  if(i==1)
                    {
					 cout<<" congratulation\nPlayer "<<--player<<" win \n";
				    }
                   else
                  { 
					 cout<<"Game draw\n";
                  cin.ignore();
                  cin.get();
                  }
    			break;
    			case 3:
    				system("cls");
    				cout<<endl<<endl;
    				cout<<endl<<endl;;
    				cout<<"              ***************************************"<<endl;
    				cout<<"              *                                     *"<<endl;
    				cout<<"              *  Game is exit. Thank u for playing  *"<<endl;
    				cout<<"              *            Good bye!                *"<<endl;
    				cout<<"              *                                     *"<<endl;
    				cout<<"              ***************************************"<<endl;
    				break;
    				default:
    				cout<<"invalid number please choose a right number from menu\n";
    				break;
                 }
	}while(c!=3);
}
int result()
{
	if (number[1]==number[2]&&number[2]==number[3])
	{
		return 1;
	}
	else if (number[4]==number[5]&&number[5]==number[6])
	{
		return 1;
	}
	else if (number[7]==number[8]&&number[8]==number[9])
	{
		return 1;
	}
	else if(number[1]==number[4]&&number[4]==number[7])
	{
		return 1;
	}
	else if (number[1]==number[5]&&number[5]==number[9])
	{
		return 1;
	}
	else if (number[2]==number[5]&&number[5]==number[8])
	{
		return 1;
	}
	else if (number[3]==number[6]&&number[6]==number[9])
	{
		return 1;
	}
	else if (number[3]==number[5]&&number[5]==number[7])
	{
		return 1;
	}
		else if (number[1] != '1' && number[2] != '2' && number[3] != '3' && number[4] != '4' &&
    number[5] != '5' && number[6] != '6' && number[7] != '7' && number[8] != '8' && number[9] != '9')
	{
    	return 0;
    }
	else
	{
		return -1;
	}
}
void board()
{
	system ("cls");
	cout << "   player 1 =  "<<a<<"    player 2 = "<<b<<endl<<endl;
	cout<<"           |      |      \n";
	cout<<"        "<<number[1]<<"  |"<<number[2]<<"     |"<<number[3]<<"      \n";
	cout<<"     ______|______|______\n";
	cout<<"           |      |      \n";
	cout<<"        "<<number[4]<<"  |"<<number[5]<<"     |"<<number[6]<<"      \n";
	cout<<"     ______|______|______\n";
	cout<<"           |      |      \n";
	cout<<"        "<<number[7]<<"  |"<<number[8]<<"     |"<<number[9]<<"      \n";
	cout<<"           |      |      \n";
}
void board2()
{
	system ("cls");
	cout << "   player1  =  "<<f<<"    player2:(Computer) = "<<d<<endl<<endl;
	cout<<"           |      |      \n";
	cout<<"        "<<numbers[1]<<"  |"<<numbers[2]<<"     |"<<numbers[3]<<"      \n";
	cout<<"     ______|______|______\n";
	cout<<"           |      |      \n";
	cout<<"        "<<numbers[4]<<"  |"<<numbers[5]<<"     |"<<numbers[6]<<"      \n";
	cout<<"     ______|______|______\n";
	cout<<"           |      |      \n";
	cout<<"        "<<numbers[7]<<"  |"<<numbers[8]<<"     |"<<numbers[9]<<"      \n";
	cout<<"           |      |      \n";
}
void display()
{
if (choice == 1 && number[1] == '1')
number[1] = sign;
 else if (choice == 2 && number[2] == '2')
number[2] = sign;
else if (choice == 3 && number[3] == '3')
number[3] = sign;
else if (choice == 4 && number[4] == '4')
number[4] = sign;
else if (choice == 5 && number[5] == '5')
 number[5] = sign;
 else if (choice == 6 && number[6] == '6')
number[6] = sign;
else if (choice == 7 && number[7] == '7')
number[7] = sign;
else if (choice == 8 && number[8] == '8')
number[8] = sign;
  else if (choice == 9 && number[9] == '9')
number[9] = sign;
  else
    {
    cout<<"Invalid move ";
player--;
cin.ignore();
}
}
int results()
{
	if (numbers[1]==numbers[2]&&numbers[2]==numbers[3])
	{
		return 1;
	}
	else if (numbers[4]==numbers[5]&&numbers[5]==numbers[6])
	{
		return 1;
	}
	else if (numbers[7]==numbers[8]&&numbers[8]==numbers[9])
	{
		return 1;
	}
	else if(numbers[1]==numbers[4]&&numbers[4]==numbers[7])
	{
		return 1;
	}
	else if (numbers[1]==numbers[5]&&numbers[5]==numbers[9])
	{
		return 1;
	}
	else if (numbers[2]==numbers[5]&&numbers[5]==numbers[8])
	{
		return 1;
	}
	else if (numbers[3]==numbers[6]&&numbers[6]==numbers[9])
	{
		return 1;
	}
	else if (numbers[3]==numbers[5]&&numbers[5]==numbers[7])
	{
		return 1;
	}
		else if (numbers[1] != '1' && numbers[2] != '2' && numbers[3] != '3' && numbers[4] != '4' &&
    numbers[5] != '5' && numbers[6] != '6' && numbers[7] != '7' && numbers[8] != '8' && numbers[9] != '9')
	{
    	return 0;
    }
	else
	{
		return -1;
	}
}
