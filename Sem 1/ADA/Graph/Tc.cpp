#include "graphFunctions.cpp"

int main(int argc, char const *argv[])
{
    int V;
    cout << "Enter number of vertices." << endl;
    cin >> V;

    int i, j, k;

    int **graph = (int **) malloc(V * sizeof(int *));
    int **tc = (int **) malloc(V * sizeof(int *));
    for (i = 0; i < V; i++) {
        graph[i] = (int *) malloc(V * sizeof(int));
        tc[i] = (int *) malloc(V * sizeof(int));
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            for (k = 0; k < V; k++) {
                if (((i == j) || graph[i][j] == 1) || (graph[i][k] == 1 && graph[k][j] == 1)) {
                    tc [i][j] = 1; 
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cout << tc[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
