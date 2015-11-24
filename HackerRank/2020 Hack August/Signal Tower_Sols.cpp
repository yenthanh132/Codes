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

const int maxn=100007;

int n,q,a[maxn],b[maxn],x[maxn],y[maxn],ql[maxn],qr[maxn];
ll res[maxn];

int arr[20][maxn],f[20][maxn],num[maxn];
ll sum[20][maxn];

void build(int i, int l, int r){
    int mid=(l+r)/2;
    int median = num[mid], cnt=0, p=l, p2=mid+1;   
    FORD(j,mid,l) if(num[j]==num[mid]) cnt++; else break;
    
    FOR(j,l,r){
        if(j==l) f[i][l]=0; else f[i][j]=f[i][j-1];
        if(arr[i][j]<median || (arr[i][j]==median && cnt)){
            f[i][j]++;
            if(arr[i][j]==median) cnt--;
            arr[i+1][p++]=arr[i][j];
        }else
            arr[i+1][p2++]=arr[i][j];       
        sum[i][j]=sum[i][j-1]+arr[i][j];
    }
    if(l==r) return;
    build(i+1,l,mid); build(i+1,mid+1,r);
}



int query(int i, int l, int r, int ql, int qr, int k, ll &left_sum){
    if(ql==qr){
        left_sum+=arr[i][ql];
        return arr[i][ql];
    }
    int shift,goleft,mid=(l+r)/2;
    
    if(ql==l){
        shift=0; goleft=f[i][qr];
    }else{
        shift=f[i][ql-1]; goleft=f[i][qr]-shift;
    }
    
    if(k<=goleft){
        return query(i+1,l,mid,l+shift,l+f[i][qr]-1,k,left_sum);   
    }else{
        left_sum+=sum[i+1][l+f[i][qr]-1] - sum[i+1][l+shift-1];
        return query(i+1,mid+1,r, mid+1+ql-(l+shift), mid+1+qr-(l+f[i][qr]), k-goleft,left_sum);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n){
        x[i]=a[i]+b[i];
        y[i]=a[i]-b[i];
    }
    FOR(i,1,q) scanf("%d%d",&ql[i],&qr[i]);
    
    //For X
    FOR(i,1,n) num[i]=arr[0][i]=x[i];
    sort(num+1,num+n+1);
    build(0,1,n);
    FOR(i,1,q){
        ll left_sum=0;
        ll mid=(ql[i]+qr[i])/2;
        ll median=query(0,1,n,ql[i],qr[i],mid-ql[i]+1,left_sum);
        res[i]=(mid-ql[i]+1)*median - left_sum + (sum[0][qr[i]]-sum[0][ql[i]-1]-left_sum) - (qr[i]-mid)*median;
    }
    
    //For Y
    FOR(i,1,n) num[i]=arr[0][i]=y[i];
    sort(num+1,num+n+1);
    build(0,1,n);
    FOR(i,1,q){
        ll left_sum=0;
        ll mid=(ql[i]+qr[i])/2;
        ll median=query(0,1,n,ql[i],qr[i],mid-ql[i]+1,left_sum);
        res[i]+=(mid-ql[i]+1)*median - left_sum + (sum[0][qr[i]]-sum[0][ql[i]-1]-left_sum) - (qr[i]-mid)*median;
    }
       
    FOR(i,1,q){
        printf("%lld",res[i]/2);
        if(res[i]&1) puts(".5"); else puts(".0");
    }
    
    //getch();
    return 0;
}
