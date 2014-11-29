# Programming Assignment #6

## Floyd-Warshall Algorithm

Modify the code for Floyd-Warshall so that it prints both a matrix of all shortest path lengths, and predecessors, for all ordered pairs of vertices. In addition to the final matrix, you would print these paths.

### Input
The input consists of a number of cases. You will be given a directed graph represented by a matrix. The first line is the size of the matrix, and the followed contains every row of the matrix. The letter i denotes an infinitely large number. 
### Output
You need to print both a matrix of all shortest path lengths, and predecessors, and shortest paths for all ordered pairs of vertices.  
#### Sample Input 
    5
    0 3 8 i -4
    i 0 i 1 7
    i 4 0 i i
    2 i -5 0 i
    i i i 6 0

#### Sample output 
    0 1 -3 2 -4
    3 0 -4 1 -1
    7 4 0 5 3
    2 -1 -5 0 -2
    8 5 1 6 0
    0 3 4 5 1
    4 0 4 2 1
    4 3 0 2 1
    4 3 4 0 1
    4 3 4 5 0
    1 to 2: 1->5->4->3->2
    1 to 3: 1->5->4->3
    1 to 4: 1->5->4
    1 to 5: 1->5
    2 to 1: 2->4->1
    2 to 3: 2->4->3
    2 to 4: 2->4
    2 to 5: 2->4->1->5
    3 to 1: 3->2->4->1
    3 to 2: 3->2
    3 to 4: 3->2->4
    3 to 5: 3->2->4->1->5
    4 to 1: 4->1
    4 to 2: 4->3->2
    4 to 3: 4->3
    4 to 5: 4->1->5
    5 to 1: 5->4->1
    5 to 2: 5->4->3->2
    5 to 3: 5->4->3
    5 to 4: 5->4


## Maximum Flow

You are the program chair of a conference! Part of your job is to assign papers to reviewers. For example, if you have 6 papers P1, P2, P3, P4, P5, P6 and 3 reviewers R1, R2, R3. Initially, each reviewer constructs a list of papers he is willing to review as followings: R1 = {P1, P3, P5, P6}, R2 = {P1, P2, P4}, R3 = {P1, P2, P3, P4, P5, P6}. An assignment of papers to reviewers is valid if each paper is assigned to at least 2 distinct reviewers that are willing to review that paper. The maximum number of papers assigned to any one reviewers is should not be greater than 4. You would like to maximize the total number of papers which are validly assigned. In this example, maximum number of papers that can be validly assigned is 5. Please implement a program to find maximum number of papers that can be validly assigned. (hint: model this problem using a s-t flow network G = (V, E) (a flow network with capacity labeling).

### Input
The input consists of a number of cases. The first line consists of #paper, #reviewer, minimum number of assignments of each paper, maximum number of papers a reviewer can review. The followed lines consist of numbers of papers a reviewer want to review, paper ids. 

### Output
You have to find maximum number of papers that can be validly assigned. (hint: model this problem using a s-t flow network G = (V, E) (a flow network with capacity labeling). 

#### Sample Input 
    6 3 2 4
    4 1 3 5 6
    3 1 2 4
    6 1 2 3 4 5 6

#### Sample output 
    5


