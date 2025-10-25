## LeetCode 463 – Island Perimeter

- we have a grid, some 1s (land) and 0s (water)  
- we want total perimeter of all islands  

- idea: check every cell  
  - if its land:  
    - check 4 directions: up, down, left, right  
    - if its out of grid or water → +1 to perimeter  
    - if its land → +0  

- sum all these +1s for all land cells → total perimeter  
- basically: every edge of land that touches water or edge counts as 1
