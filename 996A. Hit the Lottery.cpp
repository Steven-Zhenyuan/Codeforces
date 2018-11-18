
/*

Allen has a LOT of money. He has n dollars in the bank. For security reasons, 
he wants to withdraw it in cash (we will not disclose the reasons here). 
The denominations for dollar bills are 1, 5, 10, 20, 100. 
What is the minimum number of bills Allen could receive after withdrawing his entire balance?

Input
The first and only line of input contains a single integer n (1≤n≤109).

Output
Output the minimum number of bills that Allen could receive.

Examples
input
125
output
3

input
43
output
5

input
1000000000
output
10000000

解法：从大到小开始减并累加次数

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n>=100) n-=100,ans++;
    while(n>=20) n-=20,ans++;
    while(n>=10) n-=10,ans++;
    while(n>=5) n-=5,ans++;
    printf("%d",ans+n);
}




