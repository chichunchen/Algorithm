#include <iostream>
#include <limits>
#include <string>
#include <sstream>
using namespace std;

const int MAX_NUM = numeric_limits<int>::max();

string int2str(int &i) {
	string s;
	stringstream ss(s);
	ss << i;
	
	return ss.str();
}

int str2int(string a) {
	istringstream buffer(a);
	int value;
	buffer >> value;
	return value;
}

int** Input(int s) {

    int** A = new int*[s];
    for( int i = 0; i < s; i++) {
        A[i] = new int[s];
        for(int j = 0; j < s; j++) {
            string temp;
            cin >> temp;
            if (temp != "i")
            {
                A[i][j] = str2int(temp);
            }
            else {
                A[i][j] = MAX_NUM;
            }
        }
    }
    return A;
}

int** init_predecessor(int** A, int s) {

    int** B = new int*[s];
    for( int i = 0; i < s; i++) {
        B[i] = new int[s];
        for(int j = 0; j < s; j++) {
            if( A[i][j] == 0 || A[i][j] == MAX_NUM ) {
                B[i][j] = 0;
            }
            else {
                B[i][j] = i + 1;
            }
        }
    }
    return B;
}

void print(int** A, int s){
    
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            cout<<A[i][j]<<" ";
        }    
        cout<<endl;
    }
}

void Floyd_Warshall(int** A, int** B , int size) {

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
            {
                if (A[i][j] > A[i][k] + A[k][j] && A[i][k] != MAX_NUM && A[k][j] != MAX_NUM)
                {
                    A[i][j] = A[i][k] + A[k][j];
                    B[i][j] = B[k][j];
                    //cout<<"["<<i<<","<<j<<"]= "<<A[i][j]<<endl;
                }
            }
        }
    }
}

string Path(int** B, int u, int v) {
    
    if(B[u-1][v-1] == 0) {
    	return int2str(u) + int2str(v);
    }
    
    string path = int2str(v);
    while(u != v) {
    	v = B[u-1][v-1];
        path.insert(0, "->");
    	path.insert(0, int2str(v));
    }
    return path;    
}

int main(int argc, char const *argv[])
{
	int size;

    cin >> size;
    
    int** A = Input(size);
    int** B = init_predecessor(A, size);

    Floyd_Warshall(A, B, size);
        
    //cout<<"\nAfter:"<<endl;
    print(A, size);

    //cout<<"\nPI: "<<endl;
    print(B, size);

    //cout<<"\nshortest paths for all ordered pairs of vertices:"<<endl;
    for(int i = 1; i <= size; ++i) {
    	for(int j = 1; j <= size; j++) {
        	if(i!=j) {
        		cout << i << " to " << j << ": ";
        		cout << Path(B, i, j) << endl;	
        	}
        }
    }

	return 0;
}
