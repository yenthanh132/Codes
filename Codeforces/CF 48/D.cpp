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

double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}


const int maxn=100007;

int n,a[maxn],b[maxn];

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int check(int x){
    int d;
    
    if(a[x-1] && x>1 && a[x]%a[x-1]==0) d=a[x]/a[x-1];
    else if(a[x] && x<n && a[x+1]%a[x]==0) d=a[x+1]/a[x];
    else if(1<x && x<n && a[x-1] && a[x+1]%a[x-1]==0) d=a[x+1]/a[x-1];
    else return 2;
    
    bool ok=1;
    int c=0;
    int i=1;
    while(i<n){
        int j=i+1;
        while(j<=n && a[i]*d!=a[j]){
            j++;
            c++;
            if(c>1) break;
        }
        if(c>1){
            ok=0;
            break;
        }
        i=j;
    }
    if(ok) return c;
    
    c=1;
    i=2;
    while(i<n){
        int j=i+1;
        if(a[i]*d!=a[j]) return 2;
        i=j;   
    }   
    return 1;    
}

int check2(int x){
    int d;
    
    if(a[x] && a[x-1] && x>1 && a[x-1]%a[x]==0) d=a[x-1]/a[x];
    else if(a[x+1] && a[x] && x<n && a[x]%a[x+1]==0) d=a[x]/a[x+1];
    else if(1<x && x<n && a[x+1] && a[x-1] && a[x-1]%a[x+1]==0) d=a[x-1]/a[x+1];
    else return 2;
    
    bool ok=1;
    int c=0;
    int i=n;
    while(i>1){
        int j=i-1;
        while(j>=1 && a[i]*d!=a[j]){
            j--;
            c++;
            if(c>1) break;
        }
        if(c>1){
            ok=0;
            break;
        }
        i=j;
    }
    if(ok) return c;
    
    c=1;
    i=n-1;
    while(i>1){
        int j=i-1;
        if(a[i]*d!=a[j]) return 2;
        i=j;   
    }   
    return 1;    
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    if(n==1){
        puts("0");
        return 0;
    }
    
    FOR(i,1,n) b[i]=abs(a[i]);
    sort(b+1,b+n+1);
    if(b[1]==b[n] && b[1]==0){
        puts("0");
        return 0;
    }    
    
    srand(time(NULL));
    int c=oo;
    c=min(c,check(1));
    c=min(c,check(n));
    REP(step,100){
        int x=randi(n)+1;
        c=min(c,check(x));
        c=min(c,check2(x));
    }
    if(n==2) c=min(c,1);
    if(b[1]==b[n-1] && b[1]==0) c=min(c,1);
    cout<<c<<endl;
    
    //getch();
    return 0;
}
    

