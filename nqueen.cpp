/*-------------------------------------------------------------
Code: Recursive Backtracking Code to Solve N-Queen Problem
Author: Sahir
-------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#define n 8
/*-------------------------------------------------------------
 * IsSafe function checks to see if the passed coordinates
 * are safe to place the queen, returns 1 if it's safe and 
 * 0 otherwise
-------------------------------------------------------------*/
int IsSafe(int x, int y, int a[][n]){ 

	int i,j;
	
	for(i=0;i<n;i++)
		if(a[(x+i)%n][y]==1||a[x][(y+i)%n]==1)
	 		return 0;
	
	for(i=x,j=y;i<=(n-1)&&j<=(n-1);i++,j++)
		if(a[i][j]==1)
			return 0;
	
	for(i=x,j=y;(i>=0)&&(j>=0);i--,j--)
		if(a[i][j]==1)
			return 0;
	
	for(i=x,j=y;(i>=0)&&(j<=n);i--,j++)
		if(a[i][j]==1)
			return 0;

    	for(i=x,j=y;(i<=n)&&(j>=0);i++,j--)
		if(a[i][j]==1)
			return 0;

	return 1;
}//close isSafe
/*-------------------------------------------------------------
 * EQueen function is the core where all the magic happens,
 * it recursively finds the positions to place each subsequent
 * queen and back track if no solutions exist in an attempt
-------------------------------------------------------------*/
int EQueen(int a[][n], int q){

	int c=0;
  	
	//Return if all queens placed
	if(q == n)
  		return 1;
  
  	else{
		//Loop until all columns exhausted
		while(c <= n-1){
	  		//Check if it's safe to put the queen
			if(IsSafe(q,c,a) == 1){ 
			 	//Place it
				a[q][c] = 1;
				//Go for the next queen
				if(EQueen(a,q+1) == 1)
			   		return 1;
			   	//Didn't work out, remove the queen (Backtracking)
			   	else
			   		a[q][c] = 0;
			}//close if
			c++;		  
	  	}//close while
	  return 0;
	}//close else
}//close EQueen
/*-------------------------------------------------------------
-------------------------------------------------------------*/
int main() {

	//Declare the chessboard
	int chess[n][n];
	
	int i=0,j=0;

	//Init the chessboard to 0's
	for (i = 0; i < n; i++)
	  for (j = 0; j < n; j++) 
	    chess[i][j] = 0;
		
	//Run the recursive algorithm starting with 0 queen placed
	if(EQueen(chess,0)==1) {
		//If found a solution, print the chessboard
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++)
				printf("%d ",chess[i][j]);
		
			printf("\n");
		}//close for
	}//close if
	return 0;
}//close main
