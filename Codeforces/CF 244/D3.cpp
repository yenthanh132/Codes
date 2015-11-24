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

const ll base=73471;

ll a[5555],b[5555],hashpw[5555];
ll u[5555],v[5555],c1,c2;
char s[5555];
int res,m,n;

bool found(ll val, bool not_unique){
    int l=1, r=c2, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(v[mid]==val)
            return not_unique || ((mid==1 || v[mid-1]!=v[mid]) && (mid==c2 || v[mid+1]!=v[mid]));            
        if(v[mid]<val) l=mid+1;
        else r=mid-1;
    }
    return 0;
}   

bool check_equal(int len){
    c2=0;
    FOR(i,0,n-len){
        int j=i+len;
        v[++c2]=b[j]-b[i]*hashpw[len];   
    }
    sort(v+1,v+c2+1);
    
    FOR(i,0,m-len){
        int j=i+len;
        if(found(a[j]-a[i]*hashpw[len],1)) return 1;
    }   
    return 0;
}

int get_len_max(){
    int l=1, r=min(m,n), mid, res = 0;
    while(l<=r){
        mid=(l+r)/2;
        if(check_equal(mid)){
            res=mid;
            l=mid+1;   
        }else r=mid-1;
    }
    return res;
}


bool check_unique(int len){
    c1=0;
    FOR(i,0,m-len){
        int j=i+len;
        u[++c1]=a[j]-a[i]*hashpw[len];
    }   
    sort(u+1,u+c1+1);
    c2=0;
    FOR(i,0,n-len){
        int j=i+len;
        v[++c2]=b[j]-b[i]*hashpw[len];   
    }
    sort(v+1,v+c2+1); 
    
    int i=1,j;
    bool ok=0;
    while(i<=c1){
        j=i;
        while(j<c1 && u[j+1]==u[j]) ++j;
        if(i==j) ok=1;
        i=j+1;
    }   
    if(!ok) return 0;
    i=1;
    while(i<=c2){
        j=i;
        while(j<c2 && v[j+1]==v[j]) ++j;
        if(i==j) ok=1;
        i=j+1;   
    }
    return ok;
}

int get_len_min(){
    int l=1, r=min(m,n), mid, res=oo;
    while(l<=r){
        int mid=(l+r)/2;
        if(check_unique(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }      
    return res;
}



int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    hashpw[0]=1;
    FOR(i,1,5000) hashpw[i]=hashpw[i-1]*base;
    
    scanf("%s",s+1);
    m=strlen(s+1);
    a[0]=0;
    FOR(i,1,m) a[i]=a[i-1]*base+s[i];
    
    scanf("%s",s+1);
    n=strlen(s+1);
    a[0]=0;
    FOR(i,1,n) b[i]=b[i-1]*base+s[i];
    
    int len_max = get_len_max();
    int len_min = get_len_min();
    
    res=oo;
    FOR(len,1,len_max){
        c1=0;
        FOR(i,0,m-len){
            int j=i+len;
            u[++c1]=a[j]-a[i]*hashpw[len];
        }   
        sort(u+1,u+c1+1);
        c2=0;
        FOR(i,0,n-len){
            int j=i+len;
            v[++c2]=b[j]-b[i]*hashpw[len];   
        }
        sort(v+1,v+c2+1);
        
        int i=1,j;
        while(i<=c1){
            j=i;
            while(j<c1 && u[j+1]==u[i]) ++j;
            if(i==j && found(u[i],0)){
                res=len;
                break;
            }
            i=j+1;   
        }
        if(res!=oo) break;
    }
    if(res==oo) res=-1;
    printf("%d\n",res);
    
    return 0;
}
