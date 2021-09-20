#include <iostream> 
using namespace std; 

// START POINT -> (N-1, 0)
// END POINT ---> (0, M-1)


#define N 4
#define M 5 //Maze Matrix Dimensions
int sol[N][M]={0}; //sol Matrix
void printsol() //Print solution Matrix and Minimum Cost
{
	int cst=0; 
	for(int i=0;i<N;i++) 
	{ 
		for(int j=0;j<M;j++) 
		{ 
			
			if(sol[i][j]==1) 
			{ 
				cst++; 
			} 
			cout<<sol[i][j]<<"\t";
		}
		cout<<"\n\n\n"; 
	} 
	cout<<"Minimum Calculated Cost : "<<cst; 
}


bool pro(int m[N][M], int s[N][M], int p, int q) // To check if place is within matrix and unvisited
{
	if(p>=0 && p<N && q>=0 && q<M && m[p][q]==0 && s[p][q]==0)
	{
		return true;
	}
	return false;
  }  
 
 

bool slvmze(int maze[N][M], int p, int q) //Solve Maze Using Backtracking
{
	if((p==0) && (q==M-1)) //Returns 1 if at end point
	{
		sol[p][q] = 1;
		return true; 
	} 
	
	if(pro(maze,sol, p, q)==true) 
	{
		sol[p][q] = 1;  //Marked current location as visited (1)
		if(slvmze(maze,p-1, q)) // upward search
			return true; 
	    if(slvmze(maze,p+1, q)) //downward search
		    return true; 
	    if(slvmze(maze,p, q+1)) //right search
		    return true; 
	    if(slvmze(maze,p, q-1)) //left search
		    return true; 
		sol[p][q] = 0; //Backtracking -> Marking current location as unvisited (0)
		return false; 
	}	 
	return false; 
} 
 
int main() 
{
	int maze[N][M] = {
	{0,0,0,1,0}, 
	{0,1,0,1,0}, 
	{0,1,0,1,0}, 
	{0,1,0,0,0}}; //Main Maze
	if(slvmze(maze,N-1,0)==true) //If solution was found
		printsol(); 
	else 
		cout<<"Solution not found!";  // If solution was not found
	return 0; 
}

