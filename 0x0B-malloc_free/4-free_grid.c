#include <stdlib.h>

/**
* free_grid - frees a 2D grid previously created by alloc_grid function
* @grid: pointer to the 2D array of integers to be freed
* @height: height of the grid
* free_grid
* Return: void
*/

void free_grid(int **grid, int height)
{
/* code */
int i;

for (i = 0; i < height; i++)
{
free(grid[i]);
}
free(grid);
}
