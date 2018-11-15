
/*

There are n cities and m roads in Berland. Each road connects a pair of cities. The roads in Berland are one-way.

What is the minimum number of new roads that need to be built to make all the cities reachable from the capital?

New roads will also be one-way.

Input
The first line of input consists of three integers n, m and s (1≤n≤5000,0≤m≤5000,1≤s≤n) — the number of cities, the number of roads and 
the index of the capital. Cities are indexed from 1 to n.

The following m lines contain roads: road i is given as a pair of cities ui, vi (1≤ui,vi≤n, ui≠vi). 
For each pair of cities (u,v), there can be at most one road from u to v. 
Roads in opposite directions between a pair of cities are allowed (i.e. from u to v and from v to u).

Output
Print one integer — the minimum number of extra roads needed to make all the cities reachable from city s. 
If all the cities are already reachable from s, print 0.

Examples
input
9 9 1
1 2
1 3
2 3
1 5
5 6
6 1
1 8
9 8
7 1
output
3

input
5 4 5
1 2
2 3
3 4
4 1
output
1

解法：Tarjan缩点，在新图中，若一个强连通分量里有一个节点入度为0，则需要从源点添加一条路径到该连通分量
      则至少添加的路径数=入度为0的节点所在的强连通分量的个数

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5050;

struct node{
    int to,next;
}adj[MAXN];
int head[MAXN],tot;
int indegree[MAXN];

int dfn[MAXN],low[MAXN],depth;
int st[MAXN],top,vis[MAXN];
int scc[MAXN],cnt;

void init(){
    tot=1;
    depth=top=cnt=0;
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(st,0,sizeof(st));
    memset(vis,0,sizeof(vis));
    memset(scc,0,sizeof(scc));
    memset(indegree,0,sizeof(indegree));
}

void addEdge(int u,int v){
    adj[tot].next=head[u];
    adj[tot].to=v;
    head[u]=tot++;
}

void tarjan(int u){  // 有向图强连通分量的Tarjan算法
    dfn[u]=low[u]=++depth;
    st[++top]=u;
    vis[u]=1;
    for(int i=head[u];~i;i=adj[i].next){
        int v=adj[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(true){
            int x=st[top--];
            scc[x]=cnt;
            vis[x]=0;
            if(x==u) break;
        }
    }
}

int main(){
    int n,m,s,u,v,i,j;
    scanf("%d%d%d",&n,&m,&s);
    init();
    for(i=0;i<m;++i){
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }
    for(i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);  // 对所有连通点和孤立点执行Tarjan算法
    }
    indegree[scc[s]]=1;  // 源点不计入结果，设置其入度为1
    for(i=1;i<=n;++i){
        for(j=head[i];~j;j=adj[j].next){
            if(scc[i]!=scc[adj[j].to]){
                indegree[scc[adj[j].to]]++;  // 统计各强连通分量的入度
            }
        }
    }
    int ans=0;
    for(i=1;i<=cnt;++i){
        if(indegree[i]==0) ans++;  // 入度为0的强连通分量需要一个从源点到其中任意一点的路径
    }
    printf("%d",ans);
}




