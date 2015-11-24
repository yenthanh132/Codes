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

int str2int(string s){
    return atoi(s.c_str());
}

int fix(int v){if(v==12) return 0; else return v;}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s1,s2;
    int n,res=0,v=oo,c=0,t;
    scanf("%d\n",&n);
    REP(i,n){
        cin>>s1>>s2;
        t=fix(str2int(s1.substr(1,2)))*60+str2int(s1.substr(4,2));
        if(s2[0]=='p') t+=12*60;
        if(t>v) v=t, c=1;
        else if(t==v){
            if(c<10) c++;
            else c=1,res++;
        }else v=t, c=1, res++;
        getline(cin,s1);
    }
    cout<<res;
    //getch();
    return 0;
}
        
