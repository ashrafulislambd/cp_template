You're given a string s consisting of letters 'a', 'b' and 'c'.

The matching function ms( i ) is defined as the number of matching characters of s and its i-shift. In other words, ms( i ) is the number of characters that are matched when you align the 0-th character of s with the i-th character of its copy.

You are asked to compute the maximum of ms( i ) for all i ( 1 <= i <= |s| ). To make it a bit harder, you should also output all the optimal i's in increasing order.

Input
The first and only line of input contains the string s. 2 <= |s| <= 105.

Output
The first line of output contains the maximal ms( i ) over all i.

The second line of output contains all the i's for which ms( i ) reaches maximum.

Example
Input:
caccacaa

Output:
4
3
Explanation:
caccacaa
   caccacaa
The underlined characters indicate the ones that match when shift = 3.

Editorial:
The main idea for this problem is to compute the maximum number of pairs of identical elements which have the same "shift" value (e.g. s[4]
 and s[1]
 is an example of such a pair with shift 4−1=3
, since s[4]=s[1]
). With this in mind, the trick is:

For each distinct character c
, we will represent the set of that character's positions with a polynomial f(x)
, where term xi
 exists if and only if s[i]=c
. Then, we can imagine a second string with the same indices but negative represented by g(x)
, since the indices of the second string are effectively "cancelling" that of the first. Once we multiply these 2 polynomials together, it will effectively produce a frequency array for each shift value. For example, in the pair mentioned above, we notice that f(x)
 will contain term x4
 and g(x)
 will contain term x−1
. From this specific pair, the resulting polynomial f(x)×g(x)
 will have the coefficient of term x^4×x^−1=x3
 increased by 1
.

Hopefully from the example above you see why the resulting polynomial f(x)×g(x)
 represents the frequency array of each shift value. Once you have the frequency array for each distinct character, you can simply add them up and find the terms with a positive degree having the largest coefficient.

The final complexity of this approach will be O(3×NlogN)
 with FFT.

→ Reply