//get kth bit (from 0th bit)    x = n & (1<<k);
//set bit (to 1)                n = n | (1<<k);
//reset bit (to 0)              n = n & ~(1<<k);
//invert bit (0 to 1/ 1 to 0)   n = n ^ (1<<k);
//set last 1-bit to 0           n = n & (n-1);

//determine highest 2^k such that it divides n
x = n&(-n);

//check if n is a power of 2
if((n & (n-1)) == 0) cout<<"Yes\n"
else cout<<"No\n";

//inverts all bits after the last 1-bit
n = n | (n-1);

//__builtin functions
x = 5328; //00000000000000000001010011010000
cout<<__builtin_clz(x)<<"\n"; //19 (number of 0's at the beginning)
cout<<__builtin_ctz(x)<<"\n"; //4 (number of 0's at the end)
cout<<__builtin_popcount(x)<<"\n"; //5 (number of 1's)

//some properties of bitwise operation
a|b = a^b + a&b;
(a&b) ^ (a|b) = a^b; 
a+b = a|b + a&b;
a+b = a^b + 2*(a&b);
a-b = (a ^ (a&b)) - (a ^ (a|b));
a-b = (a ^ (a&b)) - (b ^ (a&b));
a-b = ((a|b) ^ b) - (a ^ (a|b));