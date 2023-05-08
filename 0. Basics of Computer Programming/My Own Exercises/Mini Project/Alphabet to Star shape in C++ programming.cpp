#include <iostream>


using namespace std;


void printA(){           // Functions

    for (int i = 0; i<5; i++)
    {

        for (int j = 0; j<5; j++) // A
        {

            if (i == 0 || i == 2 || j == 0 || j == 4)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printC(){

    for (int i = 0; i<5; i++)    // C
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}


void printO(){
    for (int i = 0; i<5; i++)    // O
    {

        for (int j = 0; j<5; j++)
        {

            if ((i == 0 || i == 4 || j == 0 || j == 4) && i != j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printE(){
    for (int i = 0; i<5; i++)   // E
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0 || i == 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printF(){
    for (int i = 0; i<5; i++)    // F
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 2 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printG(){
    for (int i = 0; i<5; i++)  // G
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0 || i == 2 && j >= 2 || j == 4 && i >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printH(){

    for (int i = 0; i<5; i++)     // H
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 2 || j == 4 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printI(){
    for (int i = 0; i<5; i++)     // I
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printB(){
    for (int i = 0; i<5; i++)  // B
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0 || j == 4 || i == 2)
            {
                if (i != j){
                    cout << "*";
                }
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printL(){
    for (int i = 0; i<5; i++)  // L
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 4 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printD(){
    for (int i = 0; i<5; i++)   // D
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0 || j == 4)
            {
                if (!(i == j))
                    cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printT(){
    for (int i = 0; i<5; i++)   // T
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || j == 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printU(){
    for (int i = 0; i<5; i++)  // U
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 4 || i == 4 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printY(){
    for (int i = 0; i<5; i++)   // Y
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 0 && i <= 2 || i == 2 || j == 4)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}


void printJ(){
    for (int i = 0; i<5; i++)      // J
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 4 || i == 4 || j == 0 && i >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}


void printN(){
    for (int i = 0; i<5; i++)  // N
    {

        for (int j = 0; j<5; j++)
        {

            if (i == j || j == 4 || j == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printP(){
    for (int i = 0; i<5; i++)  // P
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 2 || j == 0 || j == 4 && i <= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printR(){

    for (int i = 0; i<5; i++)  // R
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 2 || j == 0 || j == 4 && i <= 2 || i == j && i >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printS(){
    for (int i = 0; i<5; i++)   // S
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 0 && i <= 2 || i == 2 || j == 4 && i >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printZ(){
    for (int i = 0; i<5; i++)  // Z
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 || i == 4 || j == 4 - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}

void printQ(){
    for (int i = 0; i<5; i++)  // Q
    {

        for (int j = 0; j<5; j++)
        {

            if (i == 0 && j != 4 || i == 3 && j != 4 || j == 0 && i != 4 || j == 3 && i != 4 || i == 4 && j == 4)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}



void printW(){
    for (int i = 0; i<5; i++)  // W
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 0 || j == 4 || j == i && j >= 2 || j == 4 - i && j <= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}
void printX(){
    for (int i = 0; i<5; i++)  // x
    {

        for (int j = 0; j<5; j++)
        {

            if (i == j || j == 4 - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}
void printV(){
    for (int i = 0; i<5; i++)  // V
    {

        for (int j = 0; j<5; j++)
        {

            if (i == j && j <= 2 || j == 4 - i && j >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}
void printM(){
    for (int i = 0; i<7; i++)  // M
    {

        for (int j = 0; j<7; j++)
        {

            if (i == j && i <= 3 || j == 6 - i && i <= 3 || j == 0 || j == 6)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }
}
void printK(){
    for (int i = 0; i<5; i++)  // K
    {

        for (int j = 0; j<5; j++)
        {

            if (j == 0 || j == 4 - i && i <= 2 || i == j && i >= 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }

        }

        cout << endl;
    }

}

int main(){     // Main Function

    char c[100]={};
    bool b = true;
    int l=1;

        while (b){

        cout << "Enter Alphabat to Print OR Exit Press 0 : ";
        cin >> c;
        l=strlen(c);
            l--;
            for (int i=0; i<=l;i++)
        switch (c[i]){
        if (l<0)
        {
            cout<<l; //<<endl;
        }
        else {
        case 'A':
            printA();
            break;

        case 'B':
            printB();
            break;

        case 'C':
            printC();
            break;

        case 'D':
            printD();
            break;

        case 'E':
            printE();
            break;

        case 'F':
            printF();
            break;

        case 'G':
            printG();
            break;

        case 'H':
            printH();
            break;

        case 'I':
            printI();
            break;

        case 'J':
            printJ();
            break;

        case 'K':
            printK();
            break;

        case 'L':
            printL();
            break;

        case 'M':
            printM();
            break;

        case 'N':
            printN();
            break;

        case 'O':
            printO();
            break;

        case 'P':
            printP();
            break;

        case 'Q':
            printQ();
            break;

        case 'R':
            printR();
            break;

        case 'S':
            printS();
            break;

        case 'T':
            printT();
            break;

        case 'U':
            printU();
            break;

        case 'V':
            printV();
            break;

        case 'W':
            printW();
            break;

        case 'X':
            printX();
            break;

        case 'Y':
            printY();
            break;

        case 'Z':
            printZ();
            break;



        default:

            b = false;

            }
        } // end switch
    }


    return 0;
}