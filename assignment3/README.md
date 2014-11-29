Programming Assignment #3
=========
Implement two kinds of hashing algorithm to determine if one text file can be obtained from the other
by changing the word order. These two algorithm (linear hashing and double hashing)use open addressing  
to resolve collision. 

Expected time: `O(n)` 
-----------
Under the simple uniform hashing assumption, where n is the number of words in both files.

### Input 
The two files hava the same format. The first line is the number of the words. The followed lines is every single word split by new line(\n). Assume that each word is at most 32 characters long and contain only lower case letters. There will be no repeated word in a file. 

### Output

If these two files contain the same words, print true to the console.
If not, print false. 
### For example
    
#### Sample Input: 
	
Doc1:
	
	4 	
	this(\n)
    Is(\n)
    a(\n)
    book(\n)

Doc2:
    
    4 	
    a(\n)
    book(\n)
    is(\n)
    this(\n)


#### Sample output: 
    
    true
    
## Discussion

文章的第幾個字代表這個子的鍵值，在insert的時候，若將key帶入函數hash_func( key, i )中得到的值j，在j這個位置的hash table還沒放過東西，則insert成功，若是該位置j已經有東西了，則i+1，在run一次剛剛的步驟，這樣的插入方式導致hash table內很有可能是一群一群的值，而double hashing 則不會這樣，因為它的插入位置由`h(k, i) = ( h1(k) + h2(k, i) )`產生，這樣的產生方式會讓hash table內為隨機的分配擺放位置，第一次找尋插入位置時，i=0帶入上式，若沒找到則帶將i+1，然後在run一次，直到h(k, i)一次的增加幅度超過hash table的size，使用double hashing時，h1, h2兩個function的選擇非常重要，要設計成每次走到的位置都不相同。
	
	H1(k) = k % m
	H2(k) = 1 + (k % (m-1) )	//m為hash table的size

H2這個function要與hash table的size互質，這樣每次都會走到不同的地方。 

## Reference

<http://en.wikipedia.org/wiki/Hash_function>

<http://en.wikipedia.org/wiki/Open_addressing>
