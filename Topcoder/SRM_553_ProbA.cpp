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
typedef pair<ll, int> pii;

stack<int> mystack;
stack<pii> mystack2;

int pop(){
    if(mystack.empty()) return 0;
    int v=mystack.top(); mystack.pop();
    return v;
}

pii pop2(){
    if(mystack.empty()) return pii(0,0);
    pii v=mystack2.top(); mystack2.pop();
    return v;
}

void push(int v){
    mystack.push(v);
}

void push2(pii v){
    mystack2.push(v);
}

class Suminator {
public:
	int findMissing(vector <int> a, int wres){
		int n=sz(a);
        REP(i,n) if(a[i]>0) push(a[i]); else{
            int v1=pop(), v2=pop();
            push(v1+v2);
        }
        int v=pop(); if(v==wres) return 0;
        
        REP(i,n) 
            if(a[i]==-1) push2(pii(0,-1));
            else if(a[i]>0) push2(pii(a[i],0));
            else{
                pii v1=pop2(), v2=pop2();
                if(v1.se>v2.se) swap(v1,v2);
                if(v1.se==-1) push2(pii(v1.fi+v2.fi,-1)); else push2(pii(v1.fi+v2.fi,0));
            }
        pii v2=pop2(); 
        if(v2.se==0){
            if(v2.fi==wres) return 0; else return -1;
        }else{
            if(wres>v2.fi) return wres-v2.fi; else return -1;
        }
	}
};


<%:testing-code%>

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
