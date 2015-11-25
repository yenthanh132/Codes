#include <stdio.h>
#include <algorithm>
#include <cmath>
//#include <conio.h>


using namespace std;

#define maxn 15007
#define oo 1000000007

int a[maxn],s[maxn],BIT[maxn],n,k;

int find(int v){
    int l=1,r=n+1,mid,res=0;
    while (l<=r){
        mid=(l+r)/2;
        if (s[mid]>=v){res=mid; l=mid+1;} else r=mid-1;
    }
    return res;
}

void update_min(int i,int v){
    while (i<=n+1){
        BIT[i]=min(BIT[i],v);
        i += i & (-i);
    }
}

void update_max(int i,int v){
    while (i<=n+1){
        BIT[i]=max(BIT[i],v);
        i += i & (-i);
    }
}

int get_min(int i){
    int res=oo;
    while (i>0){
        res=min(res,BIT[i]);
        i &= i-1;
    }
    return res;
}

int get_max(int i){
    int res=-1;
    while (i>0){
        res=max(res,BIT[i]);
        i &= i-1;
    }
    return res;
}


bool check(int v){
    int mink=oo,maxk=-1,sum=0;
    
    //Get mink
    fill_n(BIT,n+2,oo);
    update_min(find(0),0);
    for(int i=1;i<=n;i++){
        sum+=a[i];
        int j=get_min(find(sum-v));
        if (j!=oo) if (i<n) update_min(find(sum),j+1); else mink=j+1;
    }
    
    //Get maxk
    sum=0;
    fill_n(BIT,n+2,-1);
    update_max(find(0),0);
    for(int i=1;i<=n;i++){
        sum+=a[i];
        int j=get_max(find(sum-v));
        if (j!=-1) if (i<n) update_max(find(sum),j+1); else maxk=j+1;
    }
    
    return (mink<=k) && (k<=maxk);
}   

void solve(){
    int l=-oo,r=oo,mid,res=oo+1;
    while (l<=r){
        mid=(l+r)/2;
        if (check(mid)){res=mid;r=mid-1;} else l=mid+1;
    }
    printf("%d",res); //getch();
}

bool mycmp(int a,int b){return (a>b);}

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k); s[0]=0;
    for(int i=1;i<=n;i++) scanf("%d",a+i), s[i]=s[i-1]+a[i];
    s[n+1]=0;
    sort(s+1,s+n+2,mycmp);
    solve();
    return 0;
}
