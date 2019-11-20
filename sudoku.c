#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9] = {
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,3,0,8,5},
                    {0,0,1,0,2,0,0,0,0},
                    {0,0,0,5,0,7,0,0,0},
                    {0,0,4,0,0,0,1,0,0},
                    {0,9,0,0,0,0,0,0,0},
                    {5,0,0,0,0,0,0,7,3},
                    {0,0,2,0,1,0,0,0,0},
                    {0,0,0,0,4,0,0,0,9}
};

/*
int sudoku[9][9] = {
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}
};*/

int entraEnFila(int i, int val){
   for(int k = 0; k<9; k++)
      if(sudoku[i][k] == val)
         return 0;

   return 1;
}

int entraEnCol(int j, int val){
   for(int k = 0; k<9; k++)
      if(sudoku[k][j] == val)
         return 0;

   return 1;
}

int entraSubregion(int i, int j, int val){
   int inif = i-i%3, inic = j-j%3, fmax = inif+3, cmax= inic+3;

   for(int f=inif; f<fmax; f++){
      for(int c=inic; c<cmax; c++){
         if(sudoku[f][c] == val)
            return 0;
      }
   }

   return 1;
}

int validarSudoku(int i, int j, int val){
   return (entraEnFila(i,val) && entraEnCol(j,val)&& entraSubregion(i,j,val));
}

void printMatrix(int tablero[9][9]){
   int i,j;
   for(i=0 ; i<9 ; i++){
      for(j=0 ; j<9 ; j++){
         printf("%d ", tablero[i][j]);
      }
      printf("\n");
   }
      printf("\n");
      printf("\n");
}

int resolverSudoku(int i, int j){
   if(j>8){
      j=0;
      i++;

      if(i>8)
         return 1;
   }

   if(sudoku[i][j])
      return resolverSudoku(i,j+1);

   for(int val=1; val<=9; val++){
      if(validarSudoku(i,j,val)){
         sudoku[i][j]=val;
         if(resolverSudoku(i,j+1))
            return 1;
      }
      sudoku[i][j]=0;
   }

   return 0;
}

int main(){
   resolverSudoku(0,0);
   printMatrix(sudoku);
   return 0;
}
