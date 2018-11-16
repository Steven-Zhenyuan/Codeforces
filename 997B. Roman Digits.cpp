
/*

Let's introduce a number system which is based on a roman digits. 
There are digits I, V, X, L which correspond to the numbers 1, 5, 10 and 50 respectively. The use of other roman digits is not allowed.

Numbers in this system are written as a sequence of one or more digits. 
We define the value of the sequence simply as the sum of digits in it.

For example, the number XXXV evaluates to 35 and the number IXI — to 12.

Pay attention to the difference to the traditional roman system — in our system any sequence of digits is valid, 
moreover the order of digits doesn't matter, for example IX means 11, not 9.

One can notice that this system is ambiguous, and some numbers can be written in many different ways. 
Your goal is to determine how many distinct integers can be represented by exactly n roman digits I, V, X, L.

Input
The only line of the input file contains a single integer n (1≤n≤109) — the number of roman digits to use.

Output
Output a single integer — the number of distinct integers which can be represented using n roman digits exactly.

Examples
input
1
output
4

input
2
output
10

input
10
output
244

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int ans[]={0,4,10,20,35,56,83,116,155,198,244,292};

int main(){
    int n;
    scanf("%d",&n);
    if(n<12) printf("%d",ans[n]);
    else printf("%lld",49ll*(n-11)+ans[11]);
}


