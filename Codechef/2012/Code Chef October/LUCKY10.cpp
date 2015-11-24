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

const int arr[8]={6,5,3,2,1,0,4,7};
const int arr2[5]={3,2,1,0,4};

int test,n,ca[10],cb[10],c4,c7;
char s[20007];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&test);
    REP(i_,test){
        gets(s);
        reset(ca,0); reset(cb,0);
        n=strlen(s);
        while(s[n-1]<'0' || s[n-1]>'9') n--;
        REP(i,n) ca[s[i]-'0']++;
        gets(s);
        REP(i,n) cb[s[i]-'0']++;
 
        c4=c7=0;
        REP(i,8)
            if(ca[7]<=cb[arr[i]]){
                c7+=ca[7];
                cb[arr[i]]-=ca[7];
                ca[7]=0;
                break;
            }else{
                c7+=cb[arr[i]];
                ca[7]-=cb[arr[i]];
                cb[arr[i]]=0;
            }
        REP(i,8)
            if(cb[7]<=ca[arr[i]]){
                c7+=cb[7];
                ca[arr[i]]-=cb[7];
                cb[7]=0;
                break;
            }else{
                c7+=ca[arr[i]];
                cb[7]-=ca[arr[i]];
                ca[arr[i]]=0;
            }
        
        REP(i,5)
            if(ca[4]<=cb[arr2[i]]){
                c4+=ca[4];
                cb[arr2[i]]-=ca[4];
                ca[4]=0;
                break;
            }else{
                c4+=cb[arr2[i]];
                ca[4]-=cb[arr2[i]];
                cb[arr2[i]]=0;
            }
        
        REP(i,5)
            if(cb[4]<=ca[arr2[i]]){
                c4+=cb[4];
                ca[arr2[i]]-=cb[4];
                cb[4]=0;
                break;
            }else{
                c4+=ca[arr2[i]];
                cb[4]-=ca[arr2[i]];
                ca[arr2[i]]=0;
            }
        
        REP(i,c7) putchar('7'); 
        REP(i,c4) putchar('4');
        puts("");
    }
    //getch();
    return 0;
}
        
    
