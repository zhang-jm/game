
#include "cell.h"

enum walls = { NORTH, SOUTH, EAST, WEST };

Cell::cell(int row, int column)
        : row(row),
          column(column){
    setupWalls();
}

void Cell::setupWalls(){
  for(auto j : 4){
    walls[j] = true;
  }
}

bool Cell::removeWall(){


}