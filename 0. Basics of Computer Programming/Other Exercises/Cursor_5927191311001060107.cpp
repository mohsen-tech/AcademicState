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
	while(ch!=27)
	{
		gotoxy(x,y);
		cout<<"*";
		ch=getch();
		gotoxy(x,y);
		cout<<" ";
		switch(ch)
		{
			case 72: //UP y--			
					y = y>1 ? y-1 : y;
					break;				
			case 80: //DOWN	y++ 		
					y = y<20 ? y+1 : y;
					break;			
			case 75: //Left	x--			
					x = x>1 ? x-1 : x;
					break;
			case 77: //RIGHT x++			
					x = x<20 ? x+1 : x;
					break;
		}
	}
}