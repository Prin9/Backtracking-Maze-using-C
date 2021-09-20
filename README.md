# Backtracking-Maze-using-C
    • The maze is of dimensions N*M. The rat starts at bottom-left corner (N-1 , 0) and its destination is the top-right corner (0 , M-1).
    • In the maze, 0 represents traversable area and 1 represents blocked off area
    • In the solution matrix, we use 1 to represent visited locations and 0 to represent unvisited locations
    • We have used backtracking as it provides a concise recursive method solve the maze. Algorithm is :
        ◦ Creating a recursive function which takes initial maze matrix, solution matrix, and position of rat (as coordinates) as input [slvmaze()]
        ◦ Check if rat position is within matrix, failing which it will return error message [pro()]
        ◦ Check if current position is the destination coordinates. If it is, print the solution matrix and exit; else recursive call for top, left, bottom, right unvisited positions. If no location is traversable from that point, unmark position as 0 in solution matrix (backtracking)
        ◦ Check for best solution and print solution matrix with cost [printsol()]
    • Time Complexity – At any time, we will run 2 for loops corresponding to the array size(n*n), which would experience exponential growth as at any point, rat can travel upto a maximum of 3 locations. Thus, time complexity = O(3n^2)
