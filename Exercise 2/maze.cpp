/// Homework - implement with stack (DFS) and queue (BFS)

#include<iostream>
#include<iomanip>
using namespace std;

int mazeM[8][8] =
{
    {0,1,0,0,0,1,0,0},
    {0,1,0,0,0,1,0,0},
    {0,1,0,0,1,1,1,1},
    {0,1,0,1,0,0,0,0},
    {0,1,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,0,1},
    {0,1,0,1,1,0,0,0}
};

bool walkable(int maze[8][8], int targetX, int targetY)
{
    if(targetX < 0 || targetX > 7 ||
            targetY < 0 || targetY > 7 ||
            maze[targetX][targetY] != 0)
    {
        return false;
    }
    return true;
}

bool isWay(int maze[8][8], int startX, int startY, int endX, int endY)
{
    maze[startX][startY] = 2;
    if(startX == endX && startY == endY)
    {
        return true;
    }
    bool result = false;
    if(walkable(maze, startX + 1, startY))
    {
        result = isWay(maze, startX + 1, startY, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX, startY + 1))
    {
        result = isWay(maze, startX, startY + 1, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX - 1, startY))
    {
        result = isWay(maze, startX - 1, startY, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX, startY - 1))
    {
        result = isWay(maze, startX, startY - 1, endX, endY);
        if(result)
        {
            return result;
        }
    }
    return false;
}

void printMaze(int maze[8][8]){
    for(short i = 0; i<8; i++){
        for(short j = 0; j<8; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}

bool findWay(int maze[8][8], int startX, int startY, int endX, int endY){
    maze[startX][startY] = 2;
    if(startX == endX && startY == endY)
    {
        return true;
    }

    bool result = false;

    if(walkable(maze, startX + 1, startY))
    {
        result = findWay(maze, startX + 1, startY, endX, endY);
        if(result)
        {
            maze[startX][startY] = 3;
            return result;
        }
    }
    if(walkable(maze, startX, startY + 1))
    {
        result = findWay(maze, startX, startY + 1, endX, endY);
        if(result)
        {
            maze[startX][startY] = 3;
            return result;
        }
    }
    if(walkable(maze, startX - 1, startY))
    {
        result = findWay(maze, startX - 1, startY, endX, endY);
        if(result)
        {
            maze[startX][startY] = 3;
            return result;
        }
    }
    if(walkable(maze, startX, startY - 1))
    {
        result = findWay(maze, startX, startY - 1, endX, endY);
        if(result)
        {
            maze[startX][startY] = 3;
            return result;
        }
    }
    return false;
}

void printWay(int maze[8][8], int startX, int startY){
    maze[startX][startY] = 2;
    cout<<"X = "<<startX<<", Y = "<<startY<<endl;
    if(startX + 1 < 8 && maze[startX + 1][startY] == 3){
        printWay(maze, startX + 1, startY);
    }
    if(startY + 1 < 8 && maze[startX][startY + 1] == 3){
        printWay(maze, startX, startY + 1);
    }
    if(startX - 1 >= 0 && maze[startX - 1][startY] == 3){
        printWay(maze, startX - 1, startY);
    }
    if(startY - 1 >= 0 && maze[startX][startY - 1] == 3){
        printWay(maze, startX, startY - 1);
    }
}

bool findAndPrintWay(int maze[8][8], int startX, int startY, int endX, int endY){
    bool result = false;
    result = findWay(maze, startX, startY, endX, endY);
    if(result){
        printWay(maze, startX, startY);
        cout<<"X = "<<endX<<", Y = "<<endY<<endl;
    }
    return result;
}

bool findWay2(int maze[8][8], int startX, int startY, int endX, int endY){
    bool result = false;
    if(startX == endX && startY == endY){
        return true;
    }
    if(walkable(maze, startX + 1, startY)){
        maze[startX+1][startY] = 10;
        result = findWay2(maze, startX + 1, startY, endX, endY);
        if(result) return result;
    }
    if(walkable(maze, startX, startY + 1)){
        maze[startX][startY+1] = 11;
        result = findWay2(maze, startX, startY + 1, endX, endY);
        if(result) return result;
    }
    if(walkable(maze, startX - 1, startY)){
        maze[startX-1][startY] = 12;
        result = findWay2(maze, startX - 1, startY, endX, endY);
        if(result) return result;
    }
    if(walkable(maze, startX, startY - 1)){
        maze[startX][startY-1] = 13;
        result = findWay2(maze, startX, startY - 1, endX, endY);
        if(result) return result;
    }
    return result;
}
void printMaze2(int maze[8][8]){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout<<setw(3)<<maze[i][j];
        }
        cout<<endl;
    }
}

void printWay2(int maze[8][8], int startX, int startY, int endX, int endY){
    if(startX != endX || startY != endY){
        if(maze[endX][endY] == 10){
            cout<<endX<<' '<<endY<<endl;
            printWay2(maze, startX, startY, endX - 1, endY);
        }
        if(maze[endX][endY] == 11){
            cout<<endX<<' '<<endY<<endl;
            printWay2(maze, startX, startY, endX, endY - 1);
        }
        if(maze[endX][endY] == 12){
            cout<<endX<<' '<<endY<<endl;
            printWay2(maze, startX, startY, endX + 1, endY);
        }
        if(maze[endX][endY] == 13){
            cout<<endX<<' '<<endY<<endl;
            printWay2(maze, startX, startY, endX, endY + 1);
        }
    }
}

bool findAndPrintWay2(int maze[8][8], int startX, int startY, int endX, int endY){
    bool result = findWay2(maze, startX, startY, endX, endY);
    if (result){
        printWay2(maze, startX, startY, endX, endY);
    }
    return result;
}

int main(){
    printMaze2(mazeM);
//    cout<<endl<<isWay(mazeM, 0, 0, 0, 7)<<endl<<endl;
//    printMaze(mazeM);

//    cout<<endl<<findWay(mazeM, 0, 0, 3, 4)<<endl<<endl;
//    printMaze(mazeM);
//    printWay(mazeM, 0, 0);
//    findAndPrintWay(mazeM, 0, 0, 3, 4);
    findAndPrintWay2(mazeM, 0, 0, 3, 4);
    printMaze2(mazeM);

}
