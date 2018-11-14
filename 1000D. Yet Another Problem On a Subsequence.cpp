
/*

The sequence of integers a1,a2,…,ak is called a good array if a1=k−1 and a1>0. 
For example, the sequences [3,−1,44,0],[1,−99] are good arrays, and the sequences [3,7,8],[2,5,4,1],[0] — are not.

A sequence of integers is called good if it can be divided into a positive number of good arrays. 
Each good array should be a subsegment of sequence and each element of the sequence should belong to exactly one array. 
For example, the sequences [2,−3,0,1,4], [1,2,3,−3,−9,4] are good, and the sequences [2,−3,0,1], [1,2,3,−3−9,4,1] — are not.

For a given sequence of numbers, count the number of its subsequences that are good sequences, 
and print the number of such subsequences modulo 998244353.

Input
The first line contains the number n (1≤n≤103) — the length of the initial sequence. 
The following line contains n integers a1,a2,…,an (−109≤ai≤109) — the sequence itself.

Output
In the single line output one integer — the number of subsequences of the original sequence that are good sequences, 
taken modulo 998244353.

Examples
input
3
2 1 1
output
2

input
4
1 1 1 1
output
7

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1010;
const int MOD=998244353;
int a[MAXN],dp[MAXN],sums[MAXN];
int C[MAXN][MAXN];

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i) scanf("%d",&a[i]);
    for(i=0;i<=n;++i) C[i][0]=1,C[i][1]=i,C[i][i]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    for(i=n;i>=1;--i){
        if(a[i]>0){
            for(j=i+a[i];j<=n;++j){
                dp[i]=(dp[i]+(ll)C[j-i-1][a[i]-1]*(1+sums[j+1])%MOD)%MOD;
            }
        }
        sums[i]=(sums[i+1]+dp[i])%MOD;
    }
    printf("%d",sums[1]);
}

