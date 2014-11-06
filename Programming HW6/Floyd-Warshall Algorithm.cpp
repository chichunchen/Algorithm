#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int vertices = 5;
	int a[vertices][vertices];
    int b[vertices][vertices];

	// initialize diagonal
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if( i == j ) {
                a[i][j] = 0;
            }
            else
                a[i][j] = 1000;
        }
    }

    // initialize distances
    a[0][1] = 3;
    a[0][2] = 8;
    a[0][4] = -4;
    a[1][3] = 1;
    a[1][4] = 7;
    a[2][1] = 4;
    a[3][0] = 2;
    a[3][2] = -5;
    a[4][3] = 6;

    cout<<"Init: "<<endl;

    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if( a[i][j] == 0 || a[i][j] == 1000 ) {
                b[i][j] = 0;
            }
            else {
                b[i][j] = i + 1;
            }
        }
    }

    for (int i = 0; i < vertices; ++i)
    {
    	for (int j = 0; j < vertices; ++j)
    	{
    		cout<<a[i][j]<<" ";
    	}
        cout<<endl;
    }

    cout<<"PI: "<<endl;
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    // Floyd-Warshall
    // Add nodes between (first 1 then 2, 3 till n) and look if
    // distance is shorter
    for(int k = 0; k < vertices; k++) {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                if(a[i][j]>a[i][k]+a[k][j] && a[i][k] != 1000 && a[k][j] != 1000) 
                {
                    a[i][j]=a[i][k]+a[k][j];
                    
                    b[i][j] = b[k][j];  
                    
                    //cout<<"["<<i<<","<<j<<"]= "<<a[i][j]<<endl;
                }
            }
        }
        cout<<k+1<<": "<<endl;

        // Print out final distance matrix
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++) {
                if (a[i][j] == 1000)
                {
                    cout << "- ";
                }
                else {
                    cout << a[i][j] << " ";
                } 
            }
            cout << endl;
        }
            
        cout<<k+1<<" of PI: "<<endl;
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                if( b[i][j] == 0)
                    cout<<"N"<<" ";
                else 
                    cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }        
    }

	return 0;
}