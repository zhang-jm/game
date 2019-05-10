#include "maze.h"


Maze::maze(int height, int width)
          : height(height),
            width(width){

  // allocate height space
  this->Cells.resize(height);
  init_cells();
}

Maze::init_cells(){
  vector<Cell> row;

  //allocate enough for row
  row.resize(width);
  for(auto i : height){
    for(auto j : width){
      row.push_back(Cell(i,j));
    }
    Cells.push_back(row);
    row.clear();
  }
}



Maze::init_maze(){
  Maze maze(width, height);
  Set pathSet(startCell);

  // While the set of cells is not empty
  while (!pathSet.empty())
  {
    // Select randomly a cell to extend the path and remove it from the set
    // Mark the cell as visited
    auto cell = Cell::Visit(pathSet.GetRandom());

    // Get available neighbors from bottom, left, right, top and visited
    // Randomly connect to one
    auto neighbors = GetVisitedneighbors(maze, cell);
    if (!neighbors.empty())
    {
      // Randomly connect to an available cell
      auto randIdx = Random() % neighbors.size();
      Connect(cell, neighbors[randIdx]);
    }

    // Add all unvisted neighbors to the set
    pathSet.insert(Getneighbors(maze, cell));
  }
}

// printing the maze
// grabs by row
void Maze::printMaze(){
  for(auto row : Cells){
    // top
    for(auto cell : row){
      if(cell.walls[0]){
        printf("_")
      }
    }
    printf("\n");
    printf("|")
    // bars
    // check left wall
    for(auto cell : row){
      if(cell.walls[1]){
        printf("|");
      }
      printf(" ");
    }
    printf("|"); // print edge of wall
    printf("\n");
    // print bottom
    for(auto cell : row){
      if(cell.walls[2]){
        printf("-");
      }
    }
  }
  return;
}