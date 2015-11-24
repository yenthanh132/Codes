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

const int maxn=5007;
int n,d4,d7,list[100],s4[100],s7[100],cnt,res;
char a[maxn],ch[100];

void duyet(int i){
    if(i>n){
        int c=0;
        s4[0]=0; s7[n+1]=0;
        FOR(i,1,n) s4[i]=s4[i-1]+(list[i]==4);
        FORD(i,n,1) s7[i]=s7[i+1]+(list[i]==7);
        FOR(i,1,n) if(s4[i-1]==s7[i+1]){
            c++;
            break;
        }
        res=(res+c)%oo;
    }
    if(d4){
        list[i]=4;
        d4--;
        duyet(i+1);
        d4++;
    }
    if(d7){
        list[i]=7;
        d7--;
        duyet(i+1);
        d7++;
    }
}
        
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d\n",&t);
    REP(index,t){
        gets(a);
        n=strlen(a);
        d4=0;
        REP(i,n) if(a[i]=='4') d4++;
        d7=n-d4;
        //cout<<"Test "<<index+1<<endl;
        cnt=res=0;
        duyet(1);
        cout<<res<<endl;;
    }
    getch();
    return 0;
    
}

