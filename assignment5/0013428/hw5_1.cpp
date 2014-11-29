#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

struct node {
    unsigned key;
    char character;
    node* lchild;
    node* rchild;
    string code;
    bool valid;
};

deque<node*> forest;

vector<string> asciiArrayCode;

node* ptr;

bool compare(node* a, node* b) {
    return a->key > b->key;
}

void OutputFrequency(vector<int> index, vector<char> content) {
    
    for (int i = 0; i < index.size(); i++) {
    	cout<<"["<<content.at(i)<<","<<index.at(i)<<"]"<<endl;
    }
}

void Huffman(vector<int> index, vector<char> content) {

    // initialize the beginning forest
    for (int i = 0; i < index.size(); i++) {

        ptr = new node;
        ptr->key = index.at(i);
        ptr->character = content.at(i);
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        ptr->valid = true;
        forest.push_back(ptr);
    }
    // from forest to a Huffman tree
    for (int i = 0; i < index.size()-1; ++i) {

        stable_sort(forest.begin(), forest.end(), compare);

        ptr = new node;
        ptr->key = forest[forest.size()-1]->key + forest[forest.size()-2]->key;

        ptr->lchild = forest[forest.size()-2];
        ptr->rchild = forest[forest.size()-1];
        ptr->valid = false;
        forest.pop_back();
        forest.pop_back();
        forest.push_back(ptr);
    }
    
}

void MarkHuffmanTree(node* head, string code) {

    if(head == NULL) 
        return;

    if(head->lchild) {
        head->lchild->code = code + "0";
        MarkHuffmanTree(head->lchild, head->lchild->code);
    }

    if(head->rchild) {
        head->rchild->code = code + "1";
        MarkHuffmanTree(head->rchild, head->rchild->code);
    }
}

void Traversal(node* head) {

    if(head == NULL) 
        return;

    Traversal(head->lchild);

    if(head->key != 0 && head->valid) {
        //cout<<head->character<<" : "<<head->code<<endl;
        asciiArrayCode.at( static_cast<int>( head->character ) ) = head->code;
    }
    
    Traversal(head->rchild);
}

void PrintCode( string input, vector<string> asciiArrayCode) {

    for (int i = 0; i < input.size(); ++i)
    {
    	if( static_cast<int>( input[i] ) < asciiArrayCode.size() )
        	cout<<asciiArrayCode.at( static_cast<int>( input[i] ) );
        else 
        	cout<<"error"<<endl;
    }
    
}

void OutputCharacterLength() {
	
	for (int i = 0; i < asciiArrayCode.size(); i++) {
		char a = static_cast<int>(i);
		if( asciiArrayCode.at(i) != "" ) 
    		cout<<"["<<a<<","<<asciiArrayCode.at(i).size()<<"]"<<endl;
    }
}

int main() {

    string input;
    char ascii;
    int asciiArray[128] = {0};
    vector<int> Array;
    vector<char> ArrayCharacter;
  
    cin>>noskipws;
    getline(cin, input);

    // put all input character turn into ascii code order frequency
    for (int i = 0; i < input.size(); ++i)
    {
        asciiArray[ static_cast<int>( input[i] ) ]++;
    }

    // no 0 frequency ascii code
    for (int i = 0; i < 128; ++i) 
	{
        if(asciiArray[i]>0) {
            Array.push_back(asciiArray[i]);
            ArrayCharacter.push_back(static_cast<int>(i));
        }
    }

    //OutputFrequency( Array, ArrayCharacter );
    Huffman( Array, ArrayCharacter );
    MarkHuffmanTree(forest.front(), "");
    
    for (int i = 0; i < 128; ++i)
    {
        asciiArrayCode.push_back("");
    }
    Traversal(forest.front());
    OutputCharacterLength();
    PrintCode(input, asciiArrayCode);

    return 0;
}
