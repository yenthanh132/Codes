#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

class PointyWizardHats {
    
    int n1,n2,mx[100],my[100],dis[100];
    vector<int> a[100];

bool findpath(){
    queue<int> myqueue;
    FOR(i,1,n1)
        if(mx[i]==0){
            myqueue.push(i);
            dis[i]=0;
        }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[my[v]]==oo){
                dis[my[v]]=dis[u]+1;
                if(my[v]!=0) myqueue.push(my[v]);
            }
        }
    }
    return(dis[0]!=oo);
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[my[v]]==dis[u]+1 && dfs(my[v])){
            mx[u]=v;
            my[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}
    
public:
	int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
		n1=sz(topHeight), n2=sz(bottomHeight);
		FOR(i,1,n1) FOR(j,1,n2) 
            if(topHeight[i-1]*bottomRadius[j-1]>topRadius[i-1]*bottomHeight[j-1] && bottomRadius[j-1]>topRadius[i-1])
                a[i].pb(j);
		reset(mx,0); reset(my,0); 
		int res=0;
		while(findpath())
		  FOR(i,1,n1) if(mx[i]==0 && dfs(i)) res++;
		return res;
	}
};
