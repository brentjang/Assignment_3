#include "Board.h"
#include <iostream>
#include <fstream>

using namespace std;

Board::Board()
{
    genBoard = new char*[10];
    for (int i = 0; i < 10; i++)
    {
        genBoard[i] = new char[10];
    }
}

Board::Board(int r, int c)
{
    rows = r+2;
    cols = c+2;
    genBoard = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
        genBoard[i] = new char[cols];
    }

    //initializes whole board to empty
    for(int n = 0; n < rows; n++)
    {
        for(int m = 0; m < cols; m++)
        {
            genBoard[n][m] = '-';
        }
    }
}

Board::Board(int r, int c, char** board)
{
    rows = r;
    cols = c;
    genBoard = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        genBoard[i] = new char[cols];
    }

    //initializes whole board to empty
    for(int n = 0; n < rows; n++)
    {
        for(int m = 0; m < cols; m++)
        {
            genBoard[n][m] = '-';
        }
    }

    for(int a = 1; a <= rows-2; a++)
    {
        for(int b = 1; b <= cols-2; b++)
        {
            genBoard[a][b] = board[a][b];
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] genBoard[i];
    }
    delete[] genBoard;
}

void Board::densityFill(double density)
{
    for(int j = 1; j <= rows-2; j++)
    {
        for(int k = 1; k <= cols-2; k++)
        {
            float random = ((float) rand()/RAND_MAX);
            if(density > random)
            {
                genBoard[j][k] = 'X';
            }
            else
            {
                genBoard[j][k] = '-';
            }
        }
    }
}

void Board::fileFill(string name)
{
    ifstream file(name);
    char c;
    string line;
    int rowOn = 1;
    while(getline(file, line))
    {
        if(line[0] == '-' || line[0] == 'X')
        {
            int colOn = 1;
            for (char c : line)
            {
                if(c == 'X')
                {
                    genBoard[rowOn][colOn] = 'X';
                }
                else if(c == '-')
                {
                    genBoard[rowOn][colOn] = '-';
                }
                colOn++;
            }
            rowOn++;
        }
    }
}

int Board::getNeighbors(int x, int y)
{
    int sumN = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(genBoard[x + i][y + j] == 'X')
            {
                sumN++;
            }
        }
    }

    //accounts for the cell at X,Y
    if(genBoard[x][y] == 'X')
    {
        sumN -= 1;
    }
    return sumN;
}

void Board::printBoard()
{
    for(int i = 1; i <= rows-2; i++)
    {
        for(int j = 1; j < cols-2; j++)
        {
            cout << genBoard[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void Board::writeBoard(string filename)
{
    ofstream printFile(filename, ios_base::app);
    for(int i = 1; i < rows-2; i++)
    {
        for(int j = 1; j < cols-2; j++)
        {
            printFile << genBoard[i][j];
        }
        printFile << '\n';
    }
    printFile << '\n';
}

char** Board::getBoard()
{
    return genBoard;
}

int Board::getRows()
{
    return rows;
}

int Board::getCols()
{
    return cols;
}
