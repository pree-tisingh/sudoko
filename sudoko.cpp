#include<iostream>
#include<conio.h>
//void showboard(int);
using namespace std;
int arr[9][9]={
    {5,1,0,0,5,0,3,0,9},
    {3,0,0,0,0,9,2,0,0},
    {0,7,0,0,8,0,0,5,0},
    {1,0,3,0,6,0,0,8,7},
    {3,9,0,7,0,8,0,2,0},
    {7,5,0,0,9,0,1,0,6},
    {0,0,6,0,3,0,0,1,0},
    {0,0,1,6,0,0,0,0,4},
    {2,0,7,0,4,0,0,9,0}};


void  showboard()
{
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    for(int r=0; r<9; r++)
    {
        for(int c=0;c<9;c++)
        {
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;

    }
    cout<<"-----------------------------------------------------------------------------------"<<endl;
}

    bool checkval(int row, int col, int val)
    {
        for( row=0;row<9;row++)
        {
            if(arr[row][col]==val)
                return false;

        }
        return true;


        for(col=0;col<9;col++)
        {
            if(arr[row][col]==val)
                return false;
        }
        return true;


        int strow = row-row%3;
        int stcol = col=col%3;
        for(int  i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                if(arr[i+strow][j+stcol]==val)
                    return false;

        }
        return true;

    }


        bool nullpos(int row,int col)
        {
            for( row=0;row<9;row++)
            {
                for( col=0;col<9;col++)
                {
                     if(arr[row][col]==0)
                        return true;
                }
                return false;

            }
        }


        void grid()
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                 {
                     if(j==3||j==6)
                        cout<<"|";

                     cout<<arr[i][j]<<" ";
                 }

                 if(i==2||i==6)
                    cout<<"---------------------------";
                 cout<<endl;
            }
        }

            bool valid(int row,int col,int val)
            {
                return !checkval(row,col,val);
            }



            bool suduko()
            {
                int row, col;
                if (!nullpos(row, col))
                   return true; //when all places are filled
                for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
                if (valid(row, col, num)){ //check validation, if yes, put the number in the grid
                    arr[row][col] = num;
                    if (suduko()) //recursively go for other rooms in the grid
                        return true;
                    arr[row][col] = 0; //turn to unassigned space when conditions are not satisfied
                 }
                }
              return false;
            }














int main()
{

    showboard();
    if(suduko()==true)
        grid();
    else
        cout<<"no solution exist";

}



