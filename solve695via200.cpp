#include <iostream>
using namespace std;

int n, m; //n and m are created to store the rows and columns
char grid[10][10]; //the array grid is created to save land and water

//lets create dfs function to explore and find area of islands
int DFS(int i, int j)
{
    //ok so here the if statement is to check the boundaries and if its water.
    //if the statement is true then its water
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != '1')
        return 0;

    grid[i][j] = '0'; //else we mark the current cell as visited

    //we find area = 1 for this cell + area in 4 directions
    int area = 1;

    //else we recursively explore the 4 direction which are up down left right.
    area += DFS(i+1, j);
    area += DFS(i-1, j);
    area += DFS(i, j+1);
    area += DFS(i, j-1);

    return area; //return the total area for this island
}

int main()
{
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "Enter grid (1 for land, 0 for water):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    int maxArea = 0; //maxArea is for biggest island area

    //FINDING MAX AREA:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                int currentArea = DFS(i,j); //we run dfs to find area
                if(currentArea > maxArea) //if current island area is bigger
                    maxArea = currentArea; //then we update maxArea
            }
        }
    }

    cout << "Max area of island: " << maxArea << "\n";
}
