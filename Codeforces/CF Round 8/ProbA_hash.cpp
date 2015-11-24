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

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;
const int base=73471;

string s,s1,s2;
ll val[maxn],hashpw[101];
ll key1,key2;
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    getline(cin,s);
    getline(cin,s1); getline(cin,s2);
    bool forward=0,backward=0;
    int r1,n=s.length();
    key1=0; REP(i,sz(s1)) key1=key1*base+int(s1[i]);
    key2=0; REP(i,sz(s2)) key2=key2*base+int(s2[i]);
    hashpw[0]=1; FOR(i,1,100) hashpw[i]=hashpw[i-1]*base;
    r1=oo;
    val[0]=0;    
    FOR(i,1,n){
        val[i]=val[i-1]*base+int(s[i-1]);
        if(i>=sz(s1) && key1==val[i]-val[i-sz(s1)]*hashpw[sz(s1)]) r1=min(r1,i);
        if(i>=sz(s2) && key2==val[i]-val[i-sz(s2)]*hashpw[sz(s2)] && i-sz(s2)>=r1){forward=1; break;}
    }
    val[n+1]=0;
    r1=-1;
    FORD(i,n,1){
        val[i]=val[i+1]*base+int(s[i-1]);
        if(n-i+1>=sz(s1) && key1==val[i]-val[i+sz(s1)]*hashpw[sz(s1)]) r1=max(r1,i);
        if(n-i+1>=sz(s2) && key2==val[i]-val[i+sz(s2)]*hashpw[sz(s2)] && i+sz(s2)<=r1){
            backward=1; 
            break;
        }
    }
    
    if(forward && backward) cout<<"both";
    else if(forward) cout<<"forward";
    else if(backward) cout<<"backward";
    else cout<<"fantasy";
    //getch();
    return 0;
}
    
