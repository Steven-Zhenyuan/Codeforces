
/*

You are given n segments on a coordinate line; each endpoint of every segment has integer coordinates. 
Some segments can degenerate to points. Segments can intersect with each other, be nested in each other or even coincide.

Your task is the following: for every k∈[1..n], calculate the number of points with integer coordinates 
such that the number of segments that cover these points equals k. 
A segment with endpoints li and ri covers point x if and only if li≤x≤ri.

Input
The first line of the input contains one integer n (1≤n≤2⋅105) — the number of segments.
The next n lines contain segments. The i-th line contains a pair of integers li,ri (0≤li≤ri≤1018) — the endpoints of the i-th segment.

Output
Print n space separated integers cnt1,cnt2,…,cntn, where cnti is equal to the number of points 
such that the number of segments that cover these points equals to i.

Examples
input
3
0 3
1 3
3 8
output
6 2 1 

input
3
1 3
2 4
5 7
output
5 2 0

解法：差分(difference)的思路，即线段左端点权值为1，右端点权值为-1，累加权值即为当前点被覆盖的次数
      由于右端点的位置仍然算覆盖，将右端点+1延长即可
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200020;
ll ans[MAXN];
map<ll,ll> mp;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        y++;
        mp[x]++;
        mp[y]--;
    }
    ll prev=0,cnt=0;
    for(auto it:mp){
        ans[cnt]+=it.first-prev;
        prev=it.first;
        cnt+=it.second;
    }
    for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
}


