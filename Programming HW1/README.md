Programming Assignment #1
=========

Peak Finding (1D)
---------
Consider an array A containing n integers. We define a peak of A to be an x such that
``x = A[i], for some 0 ≤ i < n, with A[i - 1] ≤ A[i] and A[i] ≥ A[i + 1]``. In other words, a peak x is greater than or equal to its neighbors in A (for boundary elements, there is only one neighbor). Note that A might have multiple peaks. As an example, suppose ``A = [10; 6; 4; 3; 12; 19; 18]``. Then A has two peaks: 10 and 19. Note that the absolute maximum of A is always a peak, but it requires O(n) time to compute.
    Write quick_find_1d_peak to compute any peak of array A in O(log(n)) time using the divide & conquer algorithm described in the lecture.

Peak Finding (2D)
---------
Now consider a two dimensional matrix B of integers of size n x n. We define neighborhood of an element ``x = B[i][j] as B[i+1][j], B[i-1][j], B[i][j+1] and B[i][j-1]``. For elements at the boundary, we consider only three neighbors and for elements on the 4 corners, only two neighbors are considered. x is defined to be a peak of B if and only if it is greater than or equal to all of its neighbors. Note that the maximum element of B is a possible solution for x but that requires O(n2) time.
    For your coding help, the O(n log(n)) algorithm described in the lecture is provided as medium_find_2d_peak. Write quick_find_2d_peak to compute any peak of array B in ``O(n)`` time.
    
Reference
---------
<http://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf>



