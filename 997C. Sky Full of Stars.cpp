
/*

On one of the planets of Solar system, in Atmosphere University, many students are fans of bingo game.

It is well known that one month on this planet consists of n2 days, so calendars, represented as square matrix n by n are popular.

Weather conditions are even more unusual. Due to the unique composition of the atmosphere, 
when interacting with sunlight, every day sky takes one of three colors: blue, green or red.

To play the bingo, you need to observe the sky for one month — 
after each day, its cell is painted with the color of the sky in that day, that is, blue, green or red.

At the end of the month, students examine the calendar. 
If at least one row or column contains only cells of one color, that month is called lucky.

Let's call two colorings of calendar different, if at least one cell has different colors in them. 
It is easy to see that there are 3n⋅n different colorings. 
How much of them are lucky? Since this number can be quite large, print it modulo 998244353.

Input
The first and only line of input contains a single integer n (1≤n≤1000000) — the number of rows and columns in the calendar.

Output
Print one number — number of lucky colorings of the calendar modulo 998244353

Examples
input
1
output
3

input
2
output
63

input
3
output
9933

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1000010;
const int MOD=998244353;

int C[MAXN],inv[MAXN];

ll quickpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return ans;
}

int main(){
    int n,i,base;
    scanf("%d",&n);
    ll ans1=0;
    C[0]=inv[1]=1;
    for(i=1;i<=n;++i){
        if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
        C[i]=1ll*(n-i+1)*C[i-1]%MOD*inv[i]%MOD;
        if(i&1) ans1+=1ll*C[i]*quickpow(3,(1ll*n*(n-i)+i)%(MOD-1))%MOD;
        else ans1-=1ll*C[i]*quickpow(3,(1ll*n*(n-i)+i)%(MOD-1))%MOD;
    }
    ans1=2ll*ans1%MOD;
    ll ans2=0;
    for(i=0,base=1;i<n;++i){
        if(i&1) ans2+=1ll*C[i]*(quickpow(1+MOD-base,n)-quickpow(MOD-base,n))%MOD;
        else ans2-=1ll*C[i]*(quickpow(1+MOD-base,n)-quickpow(MOD-base,n))%MOD;
        base=3ll*base%MOD;
    }
    printf("%lld\n",((ans1+3ll*ans2)%MOD+MOD)%MOD);
}



