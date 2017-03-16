/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name:   CHEN,Lian         
Login:    lchenbk        
Hours to complete assignment (optional): 



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
I add two functions with the same name isCollinear. One of it is to check
whether three points is collinear or not via the formula of x1*y2-x2*y1=0
(x1 is the difference of x-coordinators of the first point and the second point,
  and y2 is the difference of y-coordinators of the first point and the third
  point,x2 is the difference of x-coordinators of the first point and the third point,
 y1 is the difference of y-coordinators of the first point and the second point,
) if three points are on the same line. Another function with the same name is its
overloading with 3 inputs to checek whether 4 points are one the same line.



/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
I use the angle to sort.
I write a function for Point data type called angleCAlculator(), which
calculate the angle of current point with a origin point I set. And I overloaded 
the operator< (return ture when the its angle is smaller than the angle of another point)
and operator ==(return true if teh absolute value of difference of two angles is smalller
than 1e-30). Then I use the overloaded operators to write a function called Comparator used in sort.
For printing a minimal representation, I firstly make sure that every time the sort() sorts 
a vector of [points, the vector only contains points which has not been used as origin to avoid repetition.
And then my program could compare the angle of points in the current lines with points which is used as 
origin before. If the angles are the same, this lines will not be considered as a segment of 
lines we has found instead of a new line. Using tis two ways, the program could print the
minimal representation of lines.



/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10        0             0
     20        0             0 
     40        0             0
     80        0             0
    100        0             0
    150       0.01          0.01
    200       0.05          0.01
    400       0.13          0.07
   1000       2.23          0.47
   2000       87.02         2.08
   4000       1366.39       9.01
  10000                     62.06


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute:60,000,000 years
Sorting: 78 days



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute: O(N^4)
Sorting:O((N^2)(logN))
For Brute, it includes nested loop where there are 4 loops nested, and 
for each loop, it operates N times operations to check whether 4 pints are 
 one the same line or not and if they are collinear, put them into a vector.
Since the constant coefficient can be ignored , so the worse-case time can be 
regarded as O(N^4)

for the fast method, there exits a sort(take up O(NlogN)) amd other for loops in
a large for loop. The running time of that large loop is O(N). Inside the large loop
every loops take up O(N) and the sort may need O(NlogN). From the theorem we learn,
inside the large loop, the worse-case running time is O(NlogN). So the total worse-case 
is O(N*(NlogN))=O((N^2)()logN)

/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
No. The only potential bug is that if I run my program and sample with
a file including hundreds of points, I can find a line consisting of 15 points
but the sample can not. And if I ran the sample with the 15 points, it can found 
a line with 15 points. So probably the probelm is not due to my program!!! 


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
I sometimes discussed with Gao tong and Huang Chiang Hong.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
In the beginning, my program can not sort points corrrectly but after debugging,
it is fine. 



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
The accuracy of the lines my program found bother me a lot. I tested several cases with
different number of points, it looks fine. But i am not sure about the accuracy of my program.

