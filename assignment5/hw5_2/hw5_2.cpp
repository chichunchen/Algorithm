#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct BstNode
{
	string character;
	BstNode* lchild;
	BstNode* rchild;
};

BstNode* GetNewNode() {
	BstNode* newNode = new BstNode();
	newNode->character = "";
	newNode->lchild = newNode->rchild = NULL;
	return newNode;
}

static void Insert(BstNode* root, string code, string character) {

	if(root == NULL) {
		root = GetNewNode();
	}
	
	if(code == "") {
		root->character = character;
		//cout<<root->character<<" ";
	}
	else 
	{
		if (code[0] == '0')
		{
			code.erase(0, 1);
			if(root->lchild == NULL)
				root->lchild = GetNewNode();
			//cout<<"left ";
			Insert(root->lchild, code, character);
		}
		else if (code[0] == '1')
		{
			code.erase(0, 1);
			if(root->rchild == NULL)
				root->rchild = GetNewNode();
			//cout<<"right ";
			Insert(root->rchild, code, character);
		}
	}
}

void Traversal(BstNode* root) {
	if(root == NULL) 
        return;

    Traversal(root->lchild);

    if (root != NULL)
    {
    	cout<<root->character<<" ";
    }
        
    Traversal(root->rchild);
}

void Decode(BstNode* head) {

	char ch;
	BstNode* current = head;
	
	while(cin.get(ch)) {
		if (ch == '0' && current->lchild != NULL)
		{
			current = current->lchild;		
		}
		if(ch == '1' && current->rchild != NULL) {
			current = current->rchild;
		}
		
		if (current->lchild == NULL && current->rchild == NULL)
		{
			cout<<current->character;
			current = head;
		}
	}
}

int main(int argc, char const *argv[])
{
	BstNode* root = NULL;
	root = GetNewNode();

	int n;
	vector<char> character;
	vector<string> code;
	char input1;
	string input2, content;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input1 >> input2;
		character.push_back(input1);
		code.push_back(input2);
	}

	for (int i = 0; i < n; ++i)
	{
		string ch(1, character.at(i));
		string co = code.at(i);
		Insert(root, co, ch);
	}

	//cout<<root->rchild->lchild->lchild->lchild->character;

	Decode(root);

	//Traversal(root);

	return 0;
}