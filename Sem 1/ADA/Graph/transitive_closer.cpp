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

// fix_n_row will keep track of which row is supposed to be updated
void find_tc(int *graph, int *tc, int fix_n_row, int n_row, int tot_cols) 
{
    int i;

    for (i = 0; i < tot_cols; i++) {
        if ((graph[n_row * tot_cols + i] == 1) && (i != n_row)) {
            if (tc[fix_n_row * tot_cols + i] == 0) {
                tc[fix_n_row * tot_cols + i] = 1;

                find_tc(graph, tc, fix_n_row, i, tot_cols);
            }
        }
    }
}


void tran_closer(int *graph, int *tc, int tot_rows, int tot_cols)
{
    int row, col, k;

    for (row = 0; row < tot_rows; row++) {
        tc[row*tot_rows + row] = 1;

        find_tc(graph, tc, row, row, tot_cols);
    }

}

int main(int argc, char const *argv[])
{
    int V;
    int i, j, tmp;
    
    cout << "num of vertices" << endl;
    cin >> V;
    int graph[V][V];
    int tc[V][V];

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            tc[i][j] = 0;
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }
    
    printgraph(graph[0], V, V);

    printgraph(tc[0], V, V);

    tran_closer(graph[0],tc[0], V, V);

    cout << "Transitive closer is" << endl;
    printgraph(tc[0], V, V);

    return 0;
}
