#include <iostream>
#pragma GCC optimisation("01")

using namespace std;



bool findzero(int grid[9][9], int&i, int&j){
    for (i =0; i<9;i++){
        for(j=0; j<9 ; j++){
            if(grid[i][j]== 0){
                return true;
            }
        }
    }
    return false;
}


bool checkrow(int grid[9][9],int row, int num){
    for(int col=0;col<9;col++){
        if (grid[row][col]==num){
            return true;
        }
    }
return false;

}

bool checkcolumn(int grid[9][9],int col, int num){
    for (int row=0; row <9; row++){
        if(grid[row][col]==num){
            return true;
        }
    }
return false;
}

bool checkgrid(int grid[9][9], int row1, int col1 , int num){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + row1][j + col1]== num){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[9][9],int row,int col,int num){
    return !checkrow(grid,row,num)&&!checkcolumn(grid,col,num)&&!checkgrid(grid,row-row%3,col-col%3,num)&&grid[row][col]==0;
}


bool SolveSudoku(int grid[9][9]){
    
    int row,col;
   
    if(!findzero(grid,row,col)){
        
        return true;
    }
    for(int c = 1; c <= 9;c++){
        
        if(isSafe(grid,row,col,c)){
            
            grid[row][col]=c;
            
            if(SolveSudoku(grid)){
                
                return true;
            
            }
            
            grid[row][col]= 0;
        }
    }
    return false;

}






int main(){

int grid[9][9];

for (int i = 0; i < 9; i++){
    for(int j= 0; j < 9 ; j++){
        cin >> grid[i][j];
        
    }
}


if(SolveSudoku(grid)==true){
    for(int i=0 ; i<9 ; i++){
        cout<<endl;
        for(int j=0; j<9; j++){
            if(j == 8){
                cout << grid[i][j];
            }
            else{
                cout << grid[i][j] << ' ';
            }
        }
        
    }
}
else{
    cout << "No Solution" << endl;
}

    return 0;
}