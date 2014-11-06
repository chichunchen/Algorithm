#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

int paperNum, reviewerNum, paperAssign, paperReviewed;
int n1, n2, n3;
int* A;
int* B;
int* C;
int size;
int** map;

void Input() {
	cin >> paperNum >> reviewerNum >> paperAssign >> paperReviewed;
	
	cin >> n1;
	A = new int[n1]; 
	
	for(int i = 0; i < n1; ++i) {
		cin >> A[i];
	}
	
	cin >> n2;
	B = new int[n2]; 
	
	for(int i = 0; i < n2; ++i) {
		cin >> B[i];
	}
	
	cin >> n3;
	C = new int[n3]; 
	
	for(int i = 0; i < n3; ++i) {
		cin >> C[i];
	}
	
	size = paperNum + reviewerNum + 2; 
	map = new int*[ size ];
	for( int i = 0; i<size; ++i) {
		map[i] = new int[size];
		for( int j = 0; j<size; ++j) {
			map[i][j] = 0;
		}
	}
	for( int i = 0; i<size; ++i) {
		
		if(i==0) {
			for( int j=0; j<paperNum; ++j) {
				map[i][ j+1 ] = paperAssign;
			}
		}
		
		if(i>0 && i<=paperNum) {
			for(int j=0; j<n1; ++j) {
				map[ A[j] ][ paperNum + 1 ] = 1;
			}
			for(int j=0; j<n2; ++j) {
				map[ B[j] ][ paperNum + 2 ] = 1;
			}
			for(int j=0; j<n3; ++j) {
				map[ C[j] ][ paperNum + 3 ] = 1;
			}
		}
		
		if(i>paperNum && i<size-1) {
			map[i][size-1] = paperReviewed;
		}
	}
}

void print(int** A) {
	for( int i = 0; i<size; ++i) {
		for( int j = 0; j<size; ++j) {
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}
}

bool bfs(int** rGraph, int s, int t, int* parent) {
	
	bool visited[size];
	memset(visited, false, sizeof(visited));
	
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	
	while(!q.empty()) {
		
		int u = q.front();
		q.pop();
		
		for (int v=0; v<size; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
	}
	
	return (visited[t] == true);
}

void fordFulkerson(int** graph, int s, int t) {
	
	int u, v;
	
	int* parent = new int[size];
	
	int max_flow = 0;
	
	while (bfs(graph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
}

int main() {
	
	Input();
	
	//print(map);
	fordFulkerson(map, 0, 10);
	//print(map);
	
	int count = 0;
	for(int i=0; i<paperNum; ++i) {
		if(map[0][i+1] == 0)
			count++;
	}
	
	//cout << "Maximum paper assigned: " << count;
	cout << count;
	
	return 0;
}
