
#include<vector>

class Maze(){


  public:
    Maze(const int height, const int width);
    void init_cells();



  private:
    int height, width;
    vector<vector<Cell>> Cells;

}