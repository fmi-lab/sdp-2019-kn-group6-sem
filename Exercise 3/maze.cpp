/// Homework - implement with stack (DFS) and queue (BFS)

#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>

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

bool is_way_stack(int maze[8][8], int startX, int startY, int endX, int endY){
    stack<pair<int, int> > container;
    container.push(pair<int, int>(startX, startY));

    while(!container.empty()){
        pair<int, int> current = container.top();
        container.pop();
        maze[current.first][current.second] = 2;
        if(current.first == endX && current.second == endY){
            return true;
        }

        if(walkable(maze, current.first + 1, current.second)){
            container.push(pair<int, int>(current.first + 1, current.second));
        }
        if(walkable(maze, current.first, current.second + 1)){
            container.push(pair<int, int>(current.first, current.second + 1));
        }
        if(walkable(maze, current.first - 1, current.second)){
            container.push(pair<int, int>(current.first - 1, current.second));
        }
        if(walkable(maze, current.first, current.second - 1)){
            container.push(pair<int, int>(current.first, current.second - 1));
        }
    }
    return false;
}

bool is_way_queue(int maze[8][8], int startX, int startY, int endX, int endY){
    queue<pair<int, int> > container;
    container.push(pair<int, int>(startX, startY));

    while(!container.empty()){
        pair<int, int> current = container.front();
        container.pop();

        if(maze[current.first][current.second] != 0){
            continue;
        }

        maze[current.first][current.second] = 2;
        if(current.first == endX && current.second == endY){
            return true;
        }

        if(walkable(maze, current.first + 1, current.second)){
            container.push(pair<int, int>(current.first + 1, current.second));
        }
        if(walkable(maze, current.first, current.second + 1)){
            container.push(pair<int, int>(current.first, current.second + 1));
        }
        if(walkable(maze, current.first - 1, current.second)){
            container.push(pair<int, int>(current.first - 1, current.second));
        }
        if(walkable(maze, current.first, current.second - 1)){
            container.push(pair<int, int>(current.first, current.second - 1));
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

int main(){
    cout<<is_way_queue(mazeM, 1, 3, 7, 2)<<endl;

    printMaze(mazeM);

}
