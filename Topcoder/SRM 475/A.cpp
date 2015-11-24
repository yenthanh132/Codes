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


class RabbitStepping {
public:
    int n,d[20],r,c[3],sum;
    string s;
    
    void update(){
        sum++;
        int a[20],b[20],save[20],savet[20];
        reset(a,0);
        reset(save,0);
        FOR(i,1,r) a[d[i]]=1;
        REP(tt,n-2){
            reset(b,0);
            reset(savet,0);
            FOR(i,1,n) if(a[i]){
                if(i==1) b[i+1]++, savet[i+1]=-1;
                else if(i>=n-tt-1) b[i-1]++, savet[i-1]=1;
                else if(s[i]=='W') b[i-1]++, savet[i-1]=1;
                else if(s[i]=='B') b[i+1]++, savet[i+1]=-1;
                else if(s[i]=='R'){
                    if(save[i]==0) b[i-1]++, savet[i-1]=1;
                    else{
                        if(save[i]==-1) b[i-1]++, save[i-1]=1;
                        else b[i+1]++, save[i+1]=-1;
                    }
                }
            }   
            FOR(i,1,n) save[i]=savet[i];
            FOR(i,1,n) if(b[i]>1) a[i]=0; else a[i]=b[i];
        }
        int res=0;
        FOR(i,1,2) res+=a[i];
        c[res]++;
        FOR(i,1,r) cout<<d[i]<<' '; cout<<" =  "<<res<<endl;
    }
    
    void duyet(int i){
        if(i>r){
            update();
            return;           
        }
        FOR(v,d[i-1]+1,n-(r-i)){
            d[i]=v;
            duyet(i+1);
        }
    }
        
	double getExpected(string field, int R) {
        s=field;
		n=sz(field);
		r=R;
	    s=' '+s;   	
	    d[0]=0;
	    sum=0;
	    reset(c,0);
		duyet(1);
		return 1.0*(c[1]+2*c[2])/sum;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
