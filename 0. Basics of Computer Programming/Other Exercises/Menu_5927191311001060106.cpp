#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

int main()
{
	int x=10,y=10;
	char ch=5;
	gotoxy(15,10);
	cout<<"New Game";
	gotoxy(15,12);
	cout<<"Load Game";
	gotoxy(15,14);
	cout<<"High Scores";
	gotoxy(15,16);
	cout<<"About the game";
	gotoxy(15,18);
	cout<<"Exit";
	while(ch!=27)
	{
		gotoxy(x,y);
		cout<<"--->";
		ch=getch();
		gotoxy(x,y);
		cout<<"    ";
		switch(ch)
		{
			case 72: //UP y--			
					y = y>10 ? y-2 : y;
					break;				
			case 80: //DOWN	y++ 		
					y = y<18 ? y+2 : y;
					break;			
		}
	}
	gotoxy(1,30);
}