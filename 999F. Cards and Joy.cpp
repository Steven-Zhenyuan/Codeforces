
/*

There are n players sitting at the card table. Each player has a favorite number. The favorite number of the j-th player is fj.

There are k⋅n cards on the table. Each card contains a single integer: the i-th card contains number ci. 
Also, you are given a sequence h1,h2,…,hk. Its meaning will be explained below.

The players have to distribute all the cards in such a way that each of them will hold exactly k cards. 
After all the cards are distributed, each player counts the number of cards he has that contains his favorite number. 
The joy level of a player equals ht if the player holds t cards containing his favorite number. 
If a player gets no cards with his favorite number (i.e., t=0), his joy level is 0.

Print the maximum possible total joy levels of the players after the cards are distributed. 
Note that the sequence h1,…,hk is the same for all the players.

Input
The first line contains two integers n and k (1≤n≤500,1≤k≤10) — the number of players and the number of cards each player will get.

The second line contains k⋅n integers c1,c2,…,ck⋅n (1≤ci≤105) — the numbers written on the cards.

The third line contains n integers f1,f2,…,fn (1≤fj≤105) — the favorite numbers of the players.

The fourth line contains k integers h1,h2,…,hk (1≤ht≤105), where ht is the joy level of a player 
if he gets exactly t cards with his favorite number written on them. 
It is guaranteed that the condition ht−1<ht holds for each t∈[2..k].

Output
Print one integer — the maximum possible total joy levels of the players among all possible card distributions.

Examples
input
4 3
1 3 2 8 5 5 8 2 2 8 5 2
1 2 2 5
2 6 7
output
21

input
3 3
9 9 9 9 9 9 9 9 9
1 2 3
1 2 3
output
0

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100010;
int c[5005],f[505],h[15];
int C[MAXN],F[MAXN];
int dp[5005][505];

int main(){
    int n,k,i,j,p;
    scanf("%d%d",&n,&k);
    for(i=0;i<n*k;++i) scanf("%d",&c[i]),C[c[i]]++;
    for(i=0;i<n;++i) scanf("%d",&f[i]),F[f[i]]++;
    for(i=1;i<=k;++i) scanf("%d",&h[i]);
    
    for(i=1;i<=n*k;++i) dp[i][1]=h[min(i,k)];
    for(i=1;i<=n*k;++i){
        for(j=2;j<=n;++j){
            for(p=1;p<=min(i,k);++p){
                dp[i][j]=max(dp[i][j],dp[i-p][j-1]+h[p]);
            }
        }
    }
    
    ll ans=0;
    for(i=0;i<MAXN;++i){
        if(F[i]) ans+=dp[C[i]][F[i]];
    }
    printf("%lld",ans);
}


