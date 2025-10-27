#include <iostream>
using namespace std;

int n,m;
char grid[10][10];
//n and m are created to store the columsn and the rows.
//the array grid is created to save land and water.

//lets create dfs function to explore and find islands and return area.
int DFS(int i, int j)
{
    if(i<0||j<0||i>=n||j>=m||grid[i][j]!='1')
        return 0;
    grid[i][j] = '0';
    return 1+DFS(i+1,j)+DFS(i-1,j)+DFS(i,j+1)+DFS(i,j-1);
}

//ok so here the if statement is to check the boundaries and if its water.
//if the statement is true then its water
//else we recursively explore the 4 direction which are up down left right.

//NOW FOR CHECKING PERIMETER

int DFS_P(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||grid[i][j]!='0')
        return 1;
    if(grid[i][j]=='2')
        return 0;
    grid[i][j] = '2';
    int perim = 0;
    perim += DFS_P(i+1,j);
    perim += DFS_P(i-1,j);
    perim += DFS_P(i,j+1);
    perim += DFS_P(i,j-1);
    return perim;

}

//we are finding perimeter using this function
//we are using the same type of function
//but here we are checking if its out of bounds or water then it contributes to perimeter
//if we have already visited meaning 2 then give 0
//then mark current island as visited
//then we do the same and recursively explore 4 direction

int main() {
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "Enter grid (1 for land, 0 for water):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    int islands = 0;
    int maxArea = 0;
    int maxPerimeter =0;

    char gridCopy[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            gridCopy[i][j] = grid[i][j];
        }
    }
    //islands is for number of islands.
    //maxarea is for largest island area.
    //max perimenter is for largest island perimeter

    //girdcopy is to store the grid as it grid will change.

    //COUNTING ISLANDS AND AREA:

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                islands++;
                int area = DFS(i,j);
                if(area > maxArea) maxArea = area;
            }
        }
    }
    //if a land call is 1 then we increase islands cause its for no. of island
    //then we calculate area
    //then we will update area if its bigger

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gridCopy[i][j]=='1'){
                int perim = DFS_P(i,j);
                if(perim > maxPerimeter) maxPerimeter = perim;
            }
        }
    }
    //we run this for perimetr and find out max perimeter

    cout << "Number of islands: " << islands << "\n";
    cout << "Maximum island area: " << maxArea << "\n";
    cout << "Maximum island perimeter: " << maxPerimeter << "\n";
}
