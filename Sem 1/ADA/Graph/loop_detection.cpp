#include "graphFunctions.cpp"

int dfs(int *graph, int row, int V, int visited[], int par) 
{
    int col, j, flag;
    visited[row] = 1;

    for (col = row; col < V; col++) {

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

int haveCycle(int *graph, int V) 
{
    int visited[V];
    int row, i, flag = 0;
    int index = -1;
    int par = -1;

    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (row = 0; row < V; row++) {   
        
        if (visited[row] == 0) {
            flag = dfs(graph, row, V, visited, par);
             
            if (flag == 1) {
                break;
            }

        }
    }

    return flag;
}

int findZeroDeg(int incoming_edges[], int V)
{
    int len = V;
    int i;
    for (i = 0; i < len; i++) {
        if (incoming_edges[i] == 0) {
            incoming_edges[i] = -1;
            return i;
        }
    }

    return -1;
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
    
    if(haveCycle(graph[0], V)) {
        cout << "Had Loop" << endl;
    } else {
        cout << "Had no Loop" << endl;
    }

    int incoming_edges[V];
    
    for (i = 0; i < V; i++) {
        incoming_edges[i] = 0;
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                incoming_edges[j] += 1;            
            }
        }
    }

    cout << "Incomming edges : "; 
    for (i = 0; i < V; i++) {
        cout << incoming_edges[i] << " ";
    }
    cout << endl;

    int count = V;
    int tmp;
    while (count) {
        tmp = findZeroDeg(incoming_edges, V);

        if (tmp == -1) {
            cout << "Topological sort not possible" << endl;
            break;
        } else {
            for (i = 0; i < V; i++) {
                if (graph[tmp][i] == 1) {
                    incoming_edges[i] -= 1;
                }
            }
            cout << tmp + 1 << " ";
        }
        count--;
    }

    return 0;
}