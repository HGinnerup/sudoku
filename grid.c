#include <stdlib.h>
#include "grid.h"

Cell *createGrid(int sizeX, int sizeY) {
    Cell *cells = malloc(sizeX * sizeY * sizeof(Cell));

    for (int row = 0; row < sizeY; row++) {
        for (int col = 0; col < sizeX; col++) {
            Cell cell = cells[row * sizeY + col];

            cell.pos.x = col;
            cell.pos.y = row;

            // Assign pointers
            cell.up    = row == 0         ? NULL : &cells[(row - 1) * sizeY + col];
            cell.down  = row == sizeY - 1 ? NULL : &cells[(row + 1) * sizeY + col];

            cell.left  = col == 0         ? NULL : &cells[row * sizeY + col - 1];
            cell.right = col == sizeY - 1 ? NULL : &cells[row * sizeY + col + 1];
        }
    }
};
