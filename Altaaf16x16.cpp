#include <iostream>

#define M 16
using namespace std;


bool iscomplete(char grid [M][M]){
    bool complete=true;
    for (int i =0; i<=M ; i++){
        for (int j=0 ; j<=M ; j++){
            if(grid[i][j]=='0'){
                complete=false;
            }
            else{
                complete=true;
            }
        }
    }

return true;
}


bool findzero(char grid[M][M], int&i, int&j){
    for (i =0; i<M;i++){
        for(j=0; j<M ; j++){
            if(grid[i][j]=='0'){
                return true;
            }
        }
    }
    return false;
}


bool checkrow(char grid[M][M],int row, char num){
    for(int col=0;col<M;col++){
        if (grid[row][col]==num){
            return true;
        }
    }
return false;

}

bool checkcolumn(char grid[M][M],int col, char num){
    for (int row=0; row <M; row++){
        if(grid[row][col]==num){
            return true;
        }
    }
return false;
}

bool checkgrid(char grid[M][M], int row1, int col1 , char num){
    for (int row = 0; row < 4; row++){
            for (int col = 0; col < 4; col++){
                if (grid[row + row1][col + col1]== num){
                    return true;
                }
            }        
        return false;
    }
}

bool isSafe(char grid[M][M],int row,int col,char c){
    return !checkrow(grid,row,c)&&!checkcolumn(grid,col,c)&&!checkgrid(grid,row-row%4,col-col%4,c)&&grid[row][col]=='0';
}


bool SolveSudoku(char grid[M][M]){
    int row,col;
    if(!findzero(grid,row,col)){
        return true;
    }
    for(int num=1;num<=M;num++){
        char c = '0'+num;
        if(isSafe(grid,row,col,c)){
            grid[row][col]=c;
            if(SolveSudoku(grid)){
                return true;
            }
            grid[row][col]='0';
        }
    }
    return false;
}






int main(){


char grid[M][M];

for (int i =0; i<M; i++){
    for(int j=0; j<M ; j++){
        cin>>grid[i][j];
        
    }
}


if(SolveSudoku(grid)==true){
    for(int i=0;i<M;i++){
        cout<<endl;
        for(int j=0;j<M;j++){
            cout<<grid[i][j]<<" ";
        }
        
    }
}
else{
    cout<<"No solution"<<endl;
}

return 0;
}
