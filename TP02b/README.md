# 2nd Lab Class – Part B – Divide and Conquer Algorithms

## 1. Closest pair problem

Suppose *P* is a list of points on a plane.
If *p1* = (*x1*, *y1*) and *p2* = (*x2*, *y2*), the Euclidean distance between *p1* and *p2* is given by:

![\[(x1 - x2)^2 + (y1 - y2)^2\]^(1/2)](https://render.githubusercontent.com/render/math?math={\displaystyle%20\left[%20\left%28%20x_1%20-%20x_2%20\right%29^2%20%2B%20\left%28%20y_1%20-%20y_2%20\right%29^2%20\right]^\frac{1}{2}%20}#gh-light-mode-only)
![\[(x1 - x2)^2 + (y1 - y2)^2\]^(1/2)](https://render.githubusercontent.com/render/math?math={\displaystyle\color{white}%20\left[%20\left%28%20x_1%20-%20x_2%20\right%29^2%20%2B%20\left%28%20y_1%20-%20y_2%20\right%29^2%20\right]^\frac{1}{2}%20}#gh-dark-mode-only)

Along with the **.h** and **.cpp** files, you have been given data files with a (power of 2) number of random points.
In the case where there are two points with the same coordinates, those are the closest points, with distance 0 between them.

1. Implement the *nearestPoints_BF* function following a brute force algorithm, and write down the time it takes to run.
2. Implement the *nearestPoints_DC* function using the divide and conquer algorithm described further down (except for the last part that requires a second list).
   Write down the time it takes to run and compare it to the values written down for point *1.*.
3. Implement the *nearestPoints_DC_MT* function, a multi-threaded version of the divide and conquer algorithm.
   Compare the performances obtained for different sizes of input data and different numbers of threads.
4. Indicate a loop invariant and loop variant for the main loop of the function in *1.*, and show they satisfy the properties needed to prove the algorithm correctness.
5. Prove that the time complexity of the divide and conquer algorithm in *2.* is
O(N log² N).
6. Implement the function *Result nearestPoints_BF_SortByX(vector\<Point\> &vp)* that refines the brute force algorithm with an initial sorting by *x*.
   Execute the tests and check that the execution time is very good for random points, but not for points that differ only in *y*.

### Divide and Conquer Algorithm to compute the closest pair of points

*(adapted from M.A. Weiss, “Data Structures and Algorithms Analysis in C++”, 3rd edition – chapter 10, pages 430-435)*

Suppose *P* is a list of points on a plane.
If *p1* = (*x1*, *y1*) and *p2* = (*x2*, *y2*), the Euclidean distance between *p1* and *p2* is given by:

![\[(x1 - x2)^2 + (y1 - y2)^2\]^(1/2)](https://render.githubusercontent.com/render/math?math={\displaystyle%20\left[%20\left%28%20x_1%20-%20x_2%20\right%29^2%20%2B%20\left%28%20y_1%20-%20y_2%20\right%29^2%20\right]^\frac{1}{2}%20}#gh-light-mode-only)
![\[(x1 - x2)^2 + (y1 - y2)^2\]^(1/2)](https://render.githubusercontent.com/render/math?math={\displaystyle\color{white}%20\left[%20\left%28%20x_1%20-%20x_2%20\right%29^2%20%2B%20\left%28%20y_1%20-%20y_2%20\right%29^2%20\right]^\frac{1}{2}%20}#gh-dark-mode-only)

The objective is to find the two closest points.
If there are two points with the same coordinates, those are the two closest, with distance 0.

If there are *N* points, then there are *N(N-1)/2* pairs of distances.
One could look through all of them with a very simple exhaustive search (brute force) algorithm.
However, that algorithm would have complexity O(N²).
With a divide and conquer algorithm like the one described below, one can guarantee O(N log N) complexity.

<p align="center">
    <img src="images/figure1-light.png#gh-light-mode-only" alt="A small set P of points">
    <img src="images/figure1-dark.png#gh-dark-mode-only" alt="A small set P of points">
    <br>
    Figure 1 – A small set <em>P</em> of points
</p>

Figure 1 shows a small set of *P* points.
If the points were sorted by their value in the abscissa (*x* axis), one could draw an imaginary vertical line which divides the set in two halves <em>P<sub>L</sub></em> and <em>P<sub>R</sub></em>.
Given this division, either both points of the closest pair are in <em>P<sub>L</sub></em>, both are in <em>P<sub>R</sub></em> or one is in <em>P<sub>L</sub></em> and one is in <em>P<sub>R</sub></em>.
We can call the distances between them <em>d<sub>L</sub></em>, <em>d<sub>R</sub></em> and <em>d<sub>C</sub></em>, as shown in figure 2.

<p align="center">
    <img src="images/figure2-light.png#gh-light-mode-only" alt="Set P divided into PL and PR, with the minimum distances shown.">
    <img src="images/figure2-dark.png#gh-dark-mode-only" alt="Set P divided into PL and PR, with the minimum distances shown.">
<br>
    Figure 2 – Set <em>P</em> divided into <em>P<sub>L</sub></em> and <em>P<sub>R</sub></em>, with the minimum distances shown
</p>

Computing <em>d<sub>L</sub></em> and <em>d<sub>R</sub></em> can be done recursively.
The problem is then to compute <em>d<sub>C</sub></em>.
In order to guarantee a O(N log N) complexity algorithm (needed to sort the values), it must be possible to compute <em>d<sub>C</sub></em> in O(N).

Consider *δ* = min(<em>d<sub>L</sub></em>, <em>d<sub>R</sub></em>).
One only has to compute <em>d<sub>C</sub></em> if it is smaller than *δ*.
With that in mind, it can be said that the two points which define <em>d<sub>C</sub></em> should be less than *δ* distance from the dividing line.
We will name this area the **strip**.

<p align="center">
    <img src="images/figure3-light.png#gh-light-mode-only" alt="Two bands containing all of the points considered for the strip dC">
    <img src="images/figure3-dark.png#gh-dark-mode-only" alt="Two bands containing all of the points considered for the strip dC">
<br>
    Figure 3 – Two bands containing all of the points considered for the strip <em>d<sub>C</sub></em>
</p>

There are two strategies to compute <em>d<sub>C</sub></em>.
For a very large set of uniformly distributed points, the number of points expected to be contained in the strip is very small – on average there will be O(√N) points.
In that case, the brute force algorithm can be used in this strip in time O(N).
The pseudo-code for this strategy is shown in figure 4.

<p align="center">
    <img src="images/figure4-light.png#gh-light-mode-only" alt="Brute force algorithm to compute min(δ, dC)">
    <img src="images/figure4-dark.png#gh-dark-mode-only" alt="Brute force algorithm to compute min(δ, dC)">
<br>
    Figure 4 – Brute force algorithm to compute min(<em>δ</em>, <em>d<sub>C</sub></em>)
</p>

In the worst case scenario, every point can be in the strip.
In this case, the brute force strategy does not run in linear time.
It is necessary to look closely at the problem in order to improve the algorithm: the *y* coordinates of the two points which define <em>d<sub>C</sub></em> should differ, at most, *δ*; otherwise, <em>d<sub>C</sub></em> \> *δ*.
Suppose the points in the strip are sorted by their *y* coordinate.
If the *y* coordinates of points <em>p<sub>i</sub></em> and <em>p<sub>j</sub></em> differ more than *δ*, the algorithm skips to point <em>p<sub>i+1</sub></em>.
This simple modification is implemented in the algorithm shown in figure 5.

<p align="center">
    <img src="images/figure5-light.png#gh-light-mode-only" alt="Improved computation of min(δ, d C)">
    <img src="images/figure5-dark.png#gh-dark-mode-only" alt="Improved computation of min(δ, d C)">
<br>
    Figure 5 – Improved computation of min(<em>δ</em>, <em>d<sub>C</sub></em>)
</p>

This simple additional test has a very significative effect on the algorithm’s behavior, because for each point <em>p<sub>i</sub></em>, very few points <em>p<sub>j</sub></em> are examined (if their coordinates differ by more than *δ*, the internal for loop is terminated).
Figure 6 shows, for example, that for point <em>p<sub>3</sub></em>, only points <em>p<sub>4</sub></em> and <em>p<sub>5</sub></em> are less than *δ* distance away on the vertical axis.

<p align="center">
    <img src="images/figure6-light.png#gh-light-mode-only" alt="Only points p4 e p5 are considered in the second for loop">
    <img src="images/figure6-dark.png#gh-dark-mode-only" alt="Only points p4 e p5 are considered in the second for loop">
<br>
    Figure 6 – Only points <em>p<sub>4</sub></em> e <em>p<sub>5</sub></em> are considered in the second <em>for</em> loop
</p>

In the worst case scenario, for any point <em>p<sub>i</sub></em> at most seven points <em>p<sub>j</sub></em> will be considered.
The reason for this is simple to understand: these points must be contained in a *δ*×*δ* square on the left half of the strip or a *δ*×*δ* square on the right half of the strip.
On the other hand, all points in each *δ*×*δ* square are at least *δ* distance from each other.
Worst case scenario, each square contains four points, one in each corner.
One of those points is <em>p<sub>i</sub></em>, leaving, therefore, at most seven points to be considered.
This case is illustrated in figure 7.
Even in points <em>p<sub>L2</sub></em> and <em>p<sub>R1</sub></em> have the same coordinates they can be different points.
In this analysis, the important thing to notice is that the number of points in the *λ*×*2λ* rectangle is O(1).

<p align="center">
    <img src="images/figure7-light.png#gh-light-mode-only" alt="There at most eight points in the rectangle, each sharing two coordinates with other points.">
    <img src="images/figure7-dark.png#gh-dark-mode-only" alt="There at most eight points in the rectangle, each sharing two coordinates with other points.">
<br>
    Figure 7 - There are at most eight points in the rectangle, each sharing two coordinates with other points
</p>

Given that there are at most seven points to be considered for each <em>p<sub>i</sub></em>, the time needed to compute a <em>d<sub>C</sub></em> better than *δ* is O(N).
It seems, then, that a O(N log N) solution for the closest pair problem has been found, based on the recursive call of the left and right halves plus the linear time to combine the results.

However, this solution is not effectively O(N log N).
It has been assumed that the list of points is sorted.
If this operation is done in each recursive call, then there is work of complexity O(N log N) to consider, which results in an overall complexity of O(N log² N).
This is not too bad when compared to brute force’s O(N²).
It is, however, relatively easy to reduce the complexity of each recursive call to O(N), therefore guaranteeing overall complexity O(N log N).

The idea is to maintain two lists: one contains the points sorted by the *x* axis, while the other contains the points sorted by the *y* axis.
This implies a first step where the points are sorted, with complexity O(N log N).
Let these lists be names *P* and *Q*, respectively.
<em>P<sub>L</sub></em> and <em>Q<sub>L</sub></em> are the lists passed into the left half recursive call, while <em>P<sub>R</sub></em> and <em>Q<sub>R</sub></em> are the lists passed into the right half recursive call.
List *P* is easily split in half.
Once the dividing line is known, *Q* is traversed sequentially, placing each element in <em>Q<sub>L</sub></em> or <em>Q<sub>R</sub></em> as appropriate.
It is easy to verify that both <em>Q<sub>L</sub></em> and <em>Q<sub>R</sub></em> are automatically sorted by *y* as they are filled in.
Once the recursive call returns, all points in *Q* whose *x* coordinate does not belong within the strip are removed.
That way, *Q* contains all of the points which are within the strip, already sorted by *y*.

This strategy guarantees that the overall algorithm has complexity O(N log N), because the only extra processing which is done with complexity O(N)

## 2. The maximum subarray problem

Considering the same description for the maximum subarray problem of exercise 2 of the first practical class, implement the function *maxSubsequence* below using a divide and conquer algorithm instead.

```cpp
int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j)
```

The function returns the sum of the maximum subarray, for which *i* and *j* are the indices of the first and last elements of this subsequence (respectively), starting at 0.

**For example**: **A** = [−2, 1, −3, 4, −1, 2, 1, −5, 4]\
**Solution**: [0, 0, 0, 1, 1, 1, 1, 0, 0], as subsequence [4, −1, 2, 1] (*i* = 3, *j* = 6) produces the largest sum, 6.
