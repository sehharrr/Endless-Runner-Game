#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<string.h>

using namespace std;

const char Border = '|', Player = '^', Space = ' ';
const int row = 30, col = 20;

int coinplacement = 1, hurdelplacement = 1; // giving a random number for placement
int temprow = 1, temprow1 = 5;// used for coins and for hurdeles 
int points = 0, life = 3;

void Loading()
{
    system("cls");
    int x = 0;
    while (!(x == 1))
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tENDLESS RUNNER!";
        cout << "\n\t\t\t\t\t\tLOADING.";
        Sleep(700);
        cout << ".";
        Sleep(700);
        cout << ".";
        Sleep(700);
        cout << ".";
        Sleep(700);
        system("cls");
        x++;
    }
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tInstructions:";
    cout << "\n\n\t\t1.Avoid enemies(-) it will reduce your life.";
    cout << "\n\t\t2.Collect coins(+) it will increase your points.";
    cout << "\n\n\t\t\t\t\t\tCONTROLS:";
    cout << "\n\n\t\t1.Press w for moving Up.";
    cout << "\n\t\t2.Press a for moving Left.";
    cout << "\n\t\t3.Press s for moving Down.";
    cout << "\n\t\t4.Press d for moving Right.";
    cout << "\n\t\t5.Press SpaceBar for Jump.\n\n";
    cout << endl;
    system("pause");
}

void GameBoard(char array[][col], float manRow, float manCol, int life, int distance)
{
    system("CLS");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != row && j == 0)
            {
                array[i][j] = Border;
            }
            else if (j == col - 1)
            {
                array[i][j] = Border;
            }
            else if (i == manRow && j == manCol)
            {
                array[i][j] = Player;
            }
            else if (distance >= 2000 && i == manRow + 1 && j == manCol)
            {
                array[i][j] = '#';
            }
            else
            {
                array[i][j] = ' ';
            }

        }
    }
}

void CharacterMovement(float& manRow, float& manCol, int& distance)
{
    // kbhit is a function used for taking keyboard input

    if (_kbhit())
    {
        char input = _getch();
        switch (input)
        {
        case 'w': // Move up
            if (manRow > 1)
                manRow--;
            distance++;
            break;
        case 'a': // Move left
            if (manCol > 1)
                manCol--;
            distance++;
            break;
        case 's': // Move down
            if (manRow < row - 2)
                manRow++;
            break;
        case 'd': // Move right
            if (manCol < col - 2)
                manCol++;
            distance++;
            break;
        case ' ': // Jump
            if (manRow > 2)
                manRow = manRow - 2;
            distance = distance + 2;
            break;
        }
    }
}

void data(string name)
{
    ofstream data;
    data.open("playerinformation.txt");
}

void Coins(char array[][col], int row, int col, int& points, string& name, int& distance)
{
    if (temprow == row + 1)
    {
        srand(time(0));
        coinplacement = 1 + rand() % (col - 2);
        temprow = 1;
    }
    array[temprow][coinplacement] = '+';
    temprow++;

    if (array[temprow][coinplacement] == '^')
    {
        array[temprow][coinplacement] = '$';
        points += 10;
    }
    ofstream data;
    data.open("playerinformation.txt");
    data << "NAME:" << name << endl;
    data << "SCORE:" << points << endl;
    data << "DISTANCE:" << distance;
}

void Hurdeles(char array[][col], int row, int col)
{
    if (temprow1 == row + 1)
    {
        srand(time(0));
        hurdelplacement = 1 + rand() % (col - 2);
        temprow1 = 2;
    }
    array[temprow1][hurdelplacement] = '-';
    temprow1++;

    if (array[temprow1][hurdelplacement] == Player)
    {
        array[temprow1][hurdelplacement] == ' ';
        life--;
    }
}

void PrintingGame(char array[row][col], int& distance)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }

    cout << "points:" << points << endl;

    cout << "life:" << life << endl;

    cout << "Total Distance:" << distance;
    cout << endl;
}

int main()
{
    string name;
    char array[row][col];
    float manRow = row - 2, manCol = col / 2; // placing the player near the bottom center of the screen
    int distance = 0;

    system("color 6");

    Loading();

    system("color 9");

    cout << "\n\t\t\t\t\tENTER YOUR NAME:";
    cin >> name;

    data(name);

    while (life != 0)
    {
        GameBoard(array, manRow, manCol, life, distance);
        CharacterMovement(manRow, manCol, distance);
        Coins(array, row, col, points, name, distance);
        Hurdeles(array, row, col);

        system("color 5");

        PrintingGame(array, distance);

        Sleep(200);
    }

    if (life == 0)
    {
        system("color 4");

        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tGAME OVER!" << endl;
        cout << "\n\n\t\t\t\t\tYour score is:" << points << endl;
        cout << "\n\n\n\n\n";
    }
  
    return 0;
}
