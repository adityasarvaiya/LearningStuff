#include <iostream>

using namespace std;

void printgraph(int *graph, int row, int col) 
{
    int i, j;
    cout << endl;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            // *(graph + i*row + j) += 10;
            cout << graph[i*row + j] << "  ";
            // cout << *(graph + i*row + j) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}