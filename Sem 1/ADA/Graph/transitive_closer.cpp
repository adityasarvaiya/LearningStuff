#include "graphFunctions.cpp"

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

int haveWay(int *graph, int V, int s, int d, int m)
{   
    if (graph[s*V + m] == 1 && graph[m*V + d] == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int V;
    int i, j, k, z, tmp;
    
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

    // tran_closer(graph[0],tc[0], V, V);
    for (z = 0; z < V; z++) {
        for (k = 0; k < V; k++) {
            for (j = 0; j < V; j++) {
                for (i = 0; i < V; i++) {
                    if ((tc[j][k] == 0 && (graph[i][k] == 1 && graph[k][j] == 1) ) || (i == j || graph[i][j] == 1)) {
                        tc[i][j] = 1;
                        tc[j][i] = 1;
                    }
                }
            }
        }
    }

    cout << "Transitive closer is" << endl;
    printgraph(tc[0], V, V);

    return 0;
}
