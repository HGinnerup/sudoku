#include "config.h"

typedef struct vec2 Vec2;
struct vec2
{
    int x;
    int y;
};

typedef struct cell Cell;
struct cell
{
    Cell *up;
    Cell *down;
    Cell *left;
    Cell *right;
    Vec2 pos;

    int plausibleValues[NUMBER_OF_UNIQUE_VALUES];
    int value;
};

typedef struct cluster Cluster;
struct cluster
{
    Cluster *previous;
    Cluster *next;

    Cell *cells;
};

Cell *createGrid(int sizeX, int sizeY);
