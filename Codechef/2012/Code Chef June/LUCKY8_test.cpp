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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

int test,res,res2;
ll l,r;
vector<int> la, ra;

vector<int> conver(ll v){
    vector<int> a;
    while(v) a.pb(v%10),v/=10;
    return a;
}

ll getvalue(vector<int> arr, const int &pos, int num4, int num7){
    
    int i,n=sz(arr);
    for(i=n-1; i>=pos && i>=0; i--){
        if(i==pos){
            if(i>=num4+num7 && arr[i]<9) arr[i]++;
            else if(num4>0 && 4>arr[i]) arr[i]=4;
            else if(num7>0 && 7>arr[i]) arr[i]=7;
            else return oo;
        }
        if(arr[i]==7) num7--; else if(arr[i]==4) num4--;
        if(num4<0 || num7<0) return oo;
    }
    for(i=0;i<pos;i++) 
        if (num7) arr[i]=7, num7--;
        else if(num4) arr[i]=4, num4--;
        else arr[i]=0;
    if(num4>0 || num7>0) return oo;
    ll res=0;
    for(i=n-1;i>=0;i--) res=res*10+arr[i];
    return res;
}

bool ok(int num4, int num7){
    REP(i,sz(ra)) {
        if(getvalue(la,i,num4,num7)<=r) {return true;}
    }
    return (getvalue(la,-1,num4,num7)<=r);
}
        
void check(int v){
    int n4=0, n7=0, t;
    t=v;
    while(v){
        if(v%10==4) n4++;
        v/=10;
    }
    v=t;
    while(v){
        if(v%10==7) n7++;
        v/=10;
    }
    res2=max(res2,n4*n7);
}
        
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(NULL);
    int i,j;
    REP(index,100000){
        int tl,tr;
        tl=rand()%100+1; tr=rand()%(10000-tl+1)+tl;
        l=tl; r=tr;
        la=conver(l); ra=conver(r);
        while(sz(la)<sz(ra)) la.pb(0);
        res=res2=0;
        for(i=sz(ra);i>=2 && res==0;i--) 
            for(j=1;j<i;j++) if(ok(j,i-j)) res=max(res,j*(i-j));
        FOR(i,tl,tr) check(i);
        if(res!=res2) cout<<l<<" - "<<r<<" "<<res<<" "<<res2<<endl;
    }
    getch();
    return 0;
}
