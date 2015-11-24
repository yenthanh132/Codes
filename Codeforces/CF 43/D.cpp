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

const int maxL=100007;
const int maxn=107;

int l,b,f,n,pos[maxn],pos2[maxn],mark[maxL];

int get(int i){
    if(i<1) return 0;
    if(i>l) return 0;
    return mark[i];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>l>>b>>f;
    cin>>n;
    int x,y,c;
    FOR(step,1,n){
        cin>>x>>y;
        
        if(x==1){
            pos[step]=0;
            c=0;
            FOR(i,1-b,l+f){
                if(get(i)==0) c++; else c=0;
                if(c>=y+b+f){
                    pos[step]=i-f-y+1;
                    pos2[step]=i-f;            
                    FOR(j,pos[step],pos2[step]) mark[j]=1;
                    break;
                }
            }
            cout<<pos[step]-1<<endl;
        }else{
            FOR(j,pos[y],pos2[y]) mark[j]=0;
        }           
    }
    //getch();
    return 0;
}
