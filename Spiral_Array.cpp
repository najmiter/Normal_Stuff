#include <iostream>

const size_t ROWS = 2;
const size_t COLS = 3;

void Handler(int _spiral[][COLS]);

int main()
{
    // int spiral_array[ROWS][COLS] = {
    //     {0,  1,  2,  3,  4,  5,  6},
    //     {10, 11, 12, 13, 14, 15, 16},
    //     {20, 21, 22, 23, 24, 25, 26},
    //     {30, 31, 32, 33, 34, 35, 36},
    //     {40, 41, 42, 43, 44, 45, 46},
    //     {50, 51, 52, 53, 54, 55, 56}
    //     };
    int spiral_array[ROWS][COLS] = {
            {0, 1, 2},
            {10, 11, 12}
            };
    // int spiral_array[ROWS][COLS] = {
    //     {11, 78, 33, 13},        
    //     {55, 43, 39, 89},        
    //     {61, 24, 90, 31},        
    //     {12, 87, 44, 59}    
    // };

    Handler(spiral_array);
}

void Handler(int _spiral[][COLS])
{
    int top, right, bottom, left;
    int elems = ROWS * COLS;

    top = 0;
    bottom = ROWS - 1;   // 5
    left = right = COLS - 1;           // 5

    while (elems > -1 and elems)
    {
        // TOP
        for (int i = top; i <= right; i++)
        {
            std::cout<< _spiral[top][i] << ' ';
            elems--;
        }
        // RIGHT
        for (int i = top+1; i <= bottom; i++)
        {
            std::cout<< _spiral[i][right] << ' ';
            elems--;
        }
        // BOTTOM
        for (int i = --right; i > top-1; i--) // 2 
        {
            std::cout<< _spiral[bottom][i] << ' ';
            elems--;
        }
        // LEFT
        for (int i = --bottom; i > top; i--)
        {
            std::cout<< _spiral[i][top] << ' ';
            elems--;
        }
        top++;
    }
    std::cout<< "\n";
}
