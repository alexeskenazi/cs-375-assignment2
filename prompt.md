```
CS 375 Assignment 2 (Fall 20 25 )
(Due Sept 2 7 , 20 25 by 11:59pm)
```
**[Part B]: Divide and Conquer Programming (22%)**

1. [12%] Implement the algorithm for finding the closest pair of points in two dimension
plane using divide and conquer strategy.

A system for controlling air or sea traffic might need to know which are the two closest
vehicles in order to detect potential collisions. This part solves the problem of finding the
closest pair of points in a set of points. The set consists of points in R^2 defined by both an
x and a y coordinate. The "closest pair" refers to the pair of points in the set that has the
smallest Euclidean distance, where Euclidean distance between points p 1 =(x 1 ,y 1 ) and
p 2 =(x 2 ,y 2 ) is simply sqrt((x 1 - x 2 )^2 +(y 1 - y 2 )^2 ). If there are two identical points in the set, then
the closest pair distance in the set will obviously be zero.

Input data: n points with coordinates:

X coordinates: p[0].x, p[1].x, p[2].x,...., p[n].x

Y coordinates: p[0].y, p[1].y, p[2].y,...., p[n].y

Output: minimum distance between points p[i] and p[j] (index i and j should be
identified)

Input data for test:

n = 10000;

for(i=0; i<n; i++)

{

p[i].x= n- i;

p[i].y= n- i;

}

Other Input data for test:

n = 10000;

for(i=0; i<n; i++)

{

p[i].x= i*i;

p[i].y= i*i;


}

Or:

Input:

If X>
X=1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, ......,19995, 19997, 19999 (odd numbers)

Y=int( 99992 −( _X_ − 10000 )^2 )

Else
X=0, -2, -4, -6, -8, -10, -12, ......, -19996, -19998, -20000 (even number)

Y= int( 100002 −( _X_ + 10000 )^2 )

2. (10%) Use the brute-force approach to solve the above problem. Compare the two

implemented algorithms in terms of time complexity. Print out the time cost during the execution

of these two algorithms.

3. (Optional: Extra 10%) apply the close-pair algorithm to the three dimensional case.

Note 1:

Your report (.doc) of the programming part should follow the following format:

```
(1) Algorithm description
```
```
(2) Major codes
```
```
(3) Running results
```
```
(4) Report of any bugs
```
Note 2 :


2 .1 For Part B, your code package includes your code, makefile, executable file,
and write-up (.doc).

2. 2 Your program will read an input file and write an output file.

2. 3 Your program should be invoked like this...

prompt>submission inputFile.txt outputFile.txt

where inputFile.txt is referring to an input file,
ouputFile.txt is referring to an output file.


