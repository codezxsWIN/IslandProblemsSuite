#include <iostream>
using namespace std;

int n, m; //n and m are created to store the rows and columns
char grid[10][10]; //the array grid is created to save land and water

//lets create dfs function to explore and find islands
void DFS(int i, int j)
{
    //ok so here the if statement is to check the boundaries and if its water.
    //if the statement is true then its water
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1')
        return;

    grid[i][j] = '0'; //else we mark the current cell as visited

    //else we recursively explore the 4 direction which are up down left right.
    DFS(i+1, j);
    DFS(i-1, j);
    DFS(i, j+1);
    DFS(i, j-1);
}

int main()
{
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "Enter grid (1 for land, 0 for water):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    int islands = 0; //islands is for number of islands.

    //COUNTING ISLANDS:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                islands++; //if a land cell is 1 then we increase islands cause its for no. of island
                DFS(i,j); //then we run dfs to mark the island
            }
        }
    }

    cout << "Number of islands: " << islands << "\n";
}
