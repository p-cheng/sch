#include <iostream>

using namespace std;

int Find(int matrix[9][9],int rows,int cols,int number)
{
    bool found = false;
    if(matrix != NULL && rows >0 && cols > 0)
    {
        int row = 0;
        int col = cols -1;
        while(row<rows&&col>=0)
        {
            if(matrix[row][col] == number)
            {
                found = true;
                cout <<"  number" << matrix[row][col]<<endl;
                break;
            }
            else if(matrix[row][col]>number)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
    }
    return found;
}
int Findnum(int *matrix,int rows,int cols,int number)
{
    bool found = false;
    if(matrix!=NULL && rows>0 && cols>0)
    {
        int row =0;
        int col = cols-1;
        while(row < rows && col>=0)
        {
            if(matrix[row*cols + col] == number)
            {
                found = true;
                cout<<matrix[row*cols +col]<<endl;
                break;
            }
            else if(matrix[row*cols +col]>number)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
    }
    return found;
}

int main()
{
    int number = 6;
    int matrix[9][9]={0};
    for(int i =0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            matrix[i][j] = (i*9+j);
        }
    }

    for(int i =0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
           cout<< matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    Find(matrix,9,9,number);
    Findnum(*matrix,9,9,79);
    return 0;
}
