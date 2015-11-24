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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200007;

int n;
struct query{char c; int pos,x,y;} p[maxn];
vector<int> listx;
set<int> listy[maxn];
int IT[maxn*4];

#define ittree int i, int l, int r

void update(ittree, int pos){
    if(pos<l || r<pos) return;
    if(l==r){
        if(listy[pos].empty()) IT[i]=-1; else IT[i]=*listy[pos].rbegin();
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,pos); update(i*2+1,mid+1,r,pos);
    IT[i]=max(IT[i*2],IT[i*2+1]);
}

int query(ittree, int& pos, int& y){
    if(r<pos || IT[i]<y) return -1;
    if(l==r) return l;
    int mid=(l+r)/2,v;
    v=query(i*2,l,mid,pos,y);
    if(v==-1) v=query(i*2+1,mid+1,r,pos,y);
    return v;
}

void solve(){
    int x,y,v;
    int m=sz(listx);
    FOR(i,1,n)
        if(p[i].c=='a'){
            listy[p[i].pos].insert(p[i].y);
            update(1,1,m,p[i].pos);
        }else if(p[i].c=='r'){
            listy[p[i].pos].erase(listy[p[i].pos].find(p[i].y));
            update(1,1,m,p[i].pos);
        }else{
            p[i].pos++; p[i].y++;
            v=query(1,1,m,p[i].pos,p[i].y);
            if(v==-1) printf("-1\n");
            else{
                x=listx[v-1];
                y=*listy[v].lower_bound(p[i].y);
                printf("%d %d\n",x,y);
            }
                
        }
}

#include <conio.h>
int main(){
    //Input
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    char s[10];
    FOR(i,1,n){
        scanf("%s%d%d\n",&s,&p[i].x,&p[i].y);
        p[i].c=s[0];
        listx.pb(p[i].x);
    }
    //Compress
    sort(listx.begin(),listx.end());
    vector<int>::iterator it=unique(listx.begin(),listx.end());
    listx.resize(it-listx.begin());
    FOR(i,1,n) p[i].pos=lower_bound(listx.begin(),listx.end(),p[i].x)-listx.begin()+1;
    
    solve();
    
    //getch();
    return 0;   
}
