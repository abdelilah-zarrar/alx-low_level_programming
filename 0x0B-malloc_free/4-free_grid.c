#include <stdlib.h>
/*
 * @grid: pointer to the 2D array
 * @height: height of the grid
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
