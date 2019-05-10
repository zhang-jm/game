


class Cell{


  public:
    Cell(int row, int column);
    void setupWalls();
    bool removeWall();
  private:
    int row;
    int column;
    bool [4] walls;

}