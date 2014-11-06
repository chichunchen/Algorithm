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
		void Insert( int key, string word );
		bool Search( int key, string word );
		void print_HashTable();
		bool getFlag() {
			return flag;
		}
		
		int h1( int key ) {
			return key % hashTable_Size;
		}
		int h2( int key ){
			return 1 + ( key % ( hashTable_Size - 1 ) );
		}
};

Hash::Hash() {
	OpenFile();
	hashTable_Size = list.size() * 2;

	flag = true;

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
	//print_HashTable();
	//use list2 to serach in hash table

	for( int i = 1; list2.at(i) != ""; i++ ) {
		if( Search( i, list2.at(i) ) == false ) {
			flag = false;
			return;
		}
	}
		
}

void Hash::OpenFile() {

    string word, word2;
    ifstream doc1( "doc1.txt" ), doc2( "doc2.txt" );

    while( doc1 >> word, doc2 >> word2 ) {
    	list.push_back( word );
    	list2.push_back( word2 );
    }

    list.push_back( "" );
    list2.push_back( "" );

    docSize1 = atoi( list.at(0).c_str() );
    docSize2 = atoi( list2.at(0).c_str() );
}

// key 就是一個個word出現的順序  i am smart 分別為 key = 0, 1, 2.
void Hash::Insert( int key, string word ) {

	int hashFunc1 = h1( key );
	int hashFunc2 = h2( key );

	int hash_value = hashFunc1;

	if( hashTable.at(hash_value) == "" ) {
		hashTable[hash_value] = word;
	}
	else{
		hash_value += hashFunc2;
		hash_value %= hashTable_Size;

		while( hash_value < hashTable_Size ) {
			hash_value += hashFunc2;
			hash_value %= hashTable_Size;
		}
		if( hashTable.at(hash_value) == "" ) {
			hashTable[hash_value] = word;
		}
	}
}

bool Hash::Search( int key, string word ) {

	for( int i = 0; i < hashTable_Size; i++ ) {
		string value = hashTable.at(i);
		if( value == word )
			return true;
	}
	return false;
	/*
	int hashFunc1 = h1( key );
	int hashFunc2 = h2( key );

	int hash_value = hashFunc1;

	if( hashTable.at(hash_value) == word ) {
		return true;
	}
	else{
		hash_value += hashFunc2;
		hash_value %= hashTable_Size;

		while( hash_value < hashTable_Size ) {
			if( hashTable.at(hash_value) == word ) {
				cout<<"hash search at: "<<hash_value<<endl;
				return true;
			}
				

			hash_value += hashFunc2;
			hash_value %= hashTable_Size;
		}
		return false;
	}*/
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