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

int test,res,n,m,sum4[20],sum7[20];
ll l,r;
vector<int> la, ra, arr;

vector<int> conver(ll v){
    vector<int> a;
    while(v) a.pb(v%10),v/=10;
    return a;
}

bool checkvalue(const int &pos, int num4, int num7){
    int i;
    for(i=n-1; i>=pos && i>=0; i--){
        arr[i]=la[i];
        if(i==pos){
            if(i>=num4+num7) arr[i]++;
            else if(num4>0 && 4>arr[i]) arr[i]=4;
            else if(num7>0 && 7>arr[i]) arr[i]=7;
            else return false;
        }
        if(arr[i]==7) num7--; else if(arr[i]==4) num4--;
        if(num4<0 || num7<0) return false;
    }
    for(i=0;i<pos;i++) 
        if (num7) arr[i]=7, num7--;
        else if(num4) arr[i]=4, num4--;
        else arr[i]=0;
    if(num4>0 || num7>0) return false;
    for(i=n-1;i>=0;i--) if(arr[i]<ra[i]) return true; else if(arr[i]>ra[i]) return false;
    return true;
}


bool ok(int num4, int num7){
    REP(i,sz(ra)) if(la[i]<9 && checkvalue(i,num4,num7)) return true;
    return checkvalue(-1,num4,num7);
}
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&test);
    int i,j;
    REP(index,test){
        scanf("%lld%lld",&l,&r);
        la=conver(l); ra=conver(r);
        m=sz(la); n=sz(ra);
        while(sz(la)<sz(ra)) la.pb(0);
        arr.resize(n,0);
        reset(sum4,0); reset(sum7,0);
        sum4[n-1]=(la[n-1]==4); sum7[n-1]=(la[n-1]==7);
        for(i=n-2;i>=0;i--){
            sum4[i]=sum4[i+1]+(la[i]==4);
            sum7[i]=sum7[i+1]+(la[i]==7);
        }
        res=0;
        if(n-m>=2){
            for(i=n;i>=n-1;i--) for(j=i/2;j>=1;j--)
                if (res<j*(i-j) && (ok(j,i-j) || ok(i-j,j))) res=j*(i-j);
        }else{
            for(i=n;i>=2;i--) for(j=i/2;j>=1;j--)
                if (res<j*(i-j) && (ok(j,i-j) || ok(i-j,j))) res=j*(i-j);
        }
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
