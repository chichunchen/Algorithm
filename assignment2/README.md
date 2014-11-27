Programming Assignment #2
=========
Implement Quicksork with 3 different ways, and compare the running time with between Randomized-quicksort, Median of 3 partition and tukey's ninther quicksort.

Question
-----------
One way to improve the RANDOMIZED-QUICKSORT is to choose the pivot for partitioning more carefully than by picking a random element from the array. One common approach is to choose the pivot as the median of a set of 3 elements randomly selected from the array. Assume that all elements in the array are distinct. Please implement a Quicksort with Median-of-3 Partition in C or C++ and answer following questions.	
1. (review) What is the probability of getting an OK split if the pivot is chosen at random? Explain. (A split is “OK” if the smaller piece has at least n/4 elements.)2. Roughly, what is the probability of getting an OK split with the new median-of-3 method? Explain.	
3. Let I be the indicator random variable for getting an OK split using the median-of-3 partition:		I = 1 if the split is OK		I = 0 otherwiseWhat is the expectation of I?

Answer
-----------
1. The split is OK if the pivot is an element of rank n/4 to 3n/4. That is, half of the element in the array are pivots that yield an OK split. 
2. The split is not OK if and only if 
	+ The median of three randomly chosen elements has rank > n/4 or 
	+ it has rank > 3n / 4. Case( i ) happens iff( a ) exactly 2 out of 3 random elements have rank < n / 4 or ( b ) all 3 randomly chosen elements havae rank n < 4. Each random element will have rank < n / 4 with probability 1 / 4. The probability that two fixed elements will have this rank and remaining element will have rank >= n / 4 is (1/4)^2*(3/4) = 3/64. There are 3 ways to choose 2 elements out of 3. So, case(a) happens with probability 9/64. (b) (1/4)^3 = 1/64. Case(i) happens with probability 9/64 + 1/64 = 5/32. 5/32 * 2(case(ii) is the same) = 5/16. Therefore, the probability of an OK split is 1 – 5/16 = 11/16. 
3. E[I] = Pr( I = 1 ) * 1 + Pr( I = 0 ) * 0 = Pr( I = 1 ) = 11/16.

Reference
------------
<http://algs4.cs.princeton.edu/23quicksort/>
