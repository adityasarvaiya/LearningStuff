#include "graphFunctions.cpp"

int dfs(int *graph, int row, int V, int visited[], int par) 
{
    int col, j, flag;
    visited[row] = 1;

    for (col = 0; col < V; col++) {

        if (graph[row * V + col] == 1) {

            if (visited[col] == 0) {
                flag = dfs(graph, col, V, visited, row);     
                if (flag == 1) {
                    return 1;
                }
            } else if (col != par) {
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int V;
    cin >> V;

    int graph[V][V];
    int i,j;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    
    // haveCycle(graph[0], V);

    int visited[V];
    int row, flag = 0;
    int index = -1;
    int par = -1;

    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (row = 0; row < V; row++) {   
        
        if (visited[row] == 0) {
            flag = dfs(graph[0], row, V, visited, par);
             
            if (flag == 1) {
                break;
            }

        }
    }

    if (flag == 1) {
            cout << "Found Loop" << endl;
    } else {
        cout << "Loop Not Found" << endl;
    }

    return 0;
}
