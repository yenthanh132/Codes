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

int a[10][10],n,m,arr[10][10];
bool free1[10][10];
bool found;
void duyet(int i){
    if(found) return;
    if(i>5){
        found=1;
        FOR(u,1,6) FOR(v,1,6) arr[u][v]=a[u][v];
        return;
    }
    int list[8];
    FOR(j,1,7) list[j]=j;
    bool ok;
    do{
        ok=1;
        FOR(x,1,6){
            if(!free1[list[x]][list[x+1]]){
                ok=0;
                break;
            }
            FOR(y,i-1,1) if(a[y][x]==a[i][x]) ok=0;
            if(!ok) break;
        }
        if(!free1[0][list[1]]) ok=0;
        if(ok) break;
    }while (next_permutation(list+1,list+7));
    if(ok){
        free1[0][list[1]]=0;
        FOR(x,1,6) free1[list[x]][list[x+1]]=0;
        FOR(x,1,6) a[i][x]=list[x];
        duyet(i+1);
        free1[0][list[1]]=1;
        FOR(x,1,6) free1[list[x]][list[x+1]]=1;
    }
}
    

#include <conio.h>
int main(){
    FOR(u,0,7) FOR(v,0,7) if(u!=v) free1[u][v]=1;
    duyet(1);
    cout<<found<<endl;
    FOR(i,1,5){
        FOR(x,1,6) cout<<arr[i][x]<<' ';
        cout<<endl;
    }
    getch();
    return 0;
}
        
