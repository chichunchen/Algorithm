#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

template<class T>
void radixsort( T* a, int n ) {
	
}

template<>
void radixsort<char*>( char** a, int n ){
	
}

int main()
{ 
	cout << "Test 1\n";	
	unsigned short a[]={0x3579,0x3597,0x3245,0x3254,0x4235,0x4253,0x5379,0x5397,
		                0x3759,0x3795,0x3425,0x3524,0x4325,0x4523,0x5739,0x5793,
						0x3957,0x3975,0x3452,0x3542,0x4352,0x4532,0x5937,0x5973};			                
	radixsort(a,24); 
	for (int i=0;i<24;i++) cout << a[i] << ' '; cout << endl;

	cout << "\nTest 2\n";
	signed b[]={0xA345A345,0x23542354,0xA245A245,0x32543254,0xA235A235,0x42534253,0xA243A243,0x52345234,
		        0xB435B435,0x24532453,0xB425B425,0x35243524,0xB325B325,0x45234523,0xB423B423,0x53245324,
				0xC543C543,0x25342534,0xC452C452,0x35423542,0xC352C352,0x45324532,0xC432C432,0x53425342};
	radixsort(b,24); 
	for (int i=0;i<24;i++) cout << b[i] << ' '; cout << endl;

	cout << "\nTest 3\n";
	char* c[27]={"boggy","snoot","cat","dog","doggy","garage","snooper","plug","bogs",
		         "egg","cafe","dig","snoopy","cats","pluto","snooty","dogs","smell",
				 "zoo","smoke","bigger","snoop","bog","cab","garfield","small","big"};
	radixsort(c,27);
	for (int i=0;i<27;i++) cout << c[i] << ' '; cout << endl;
}


