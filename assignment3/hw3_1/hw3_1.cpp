#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Hash {
	private:

		int docSize1;
		int docSize2;
		int hashTable_Size;
		bool flag;
		vector<string> list;		//words from doc1
		vector<string> list2;
		vector<string> hashTable;	

	public:
		Hash();
		void OpenFile();
		int hashFunc( int x, int i );
		void Insert( int key, string word );
		bool Search( int key, string word );
		void print_HashTable();
		bool getFlag() {
			return flag;
		}
};

Hash::Hash() {
	OpenFile();
	hashTable_Size = list.size() * 2;

	flag = true;

	// if the number of word is different between doc1 and doc2
	// then the result must be false.
	if( docSize1 != docSize2 ) {
		flag = false;
		return;
	}

	//initialize hash table
	for( int i = 0; i < hashTable_Size; i++ ) {
		hashTable.push_back( "" );
	}

	//insert list1 to hash table
	int n = 1;
	while( list.at(n) != "" ) {
		Insert( n, list.at(n) );
		n++;
	}
	print_HashTable();
	//use list2 to serach in hash table
	
	for( int i = 1; list2.at(i) != ""; i++ ) {
		if( Search( i, list2.at(i) ) == false ) {
			cout<<"search false at "<<i<<endl;
			flag = false;
			return;
		}
	}
	
}

void Hash::OpenFile() {

    string word, word2;
    ifstream doc1( "../testdata/doc1.txt" ), doc2( "../testdata/doc2.txt" );

    while( doc1 >> word, doc2 >> word2 ) {
    	list.push_back( word );
    	list2.push_back( word2 );
    }

    list.push_back( "" );
    list2.push_back( "" );

    docSize1 = atoi( list.at(0).c_str() );
    docSize2 = atoi( list2.at(0).c_str() );
}

int Hash::hashFunc( int key, int i ) {
	return ( key + i ) % hashTable_Size;
}

// key 就是一個個word出現的順序  i am smart 分別為 key = 0, 1, 2.
void Hash::Insert( int key, string word ) {
	int i = 0;
	int j;
	do{
		j = hashFunc( key, i );
		if( hashTable.at(j) == "" )
			hashTable[ j ] = word;
		else i++;

	}while( i == hashTable_Size );
}

bool Hash::Search( int key, string word ) {
	int i = 0;
	int j;
	do{
		j = hashFunc( key, i );
		//cout<<"j: "<<j<<endl;
		if( hashTable.at(j) == word )
			return true;
		i++;
	} while( hashTable.at(j) == "" || i != hashTable_Size );
	return false;
}

void Hash::print_HashTable() {
	for( unsigned n = 0; n < list.size(); ++n ) {
    	cout << "[" << n << "]: " << hashTable.at( n )<<endl;
    }
    cout<<"-----------------------"<<endl;
}


int main() {

	Hash hash;

	if( hash.getFlag() )
		cout<<"true";
	else 
		cout<<"false";

	return 0;
}
