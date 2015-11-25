#include <stdio.h>
#include <algorithm>
#define maxn 10000
#define oo 1000000007

using namespace std;

int n,a[maxn],x[maxn],sx[maxn*2+1],y[maxn],sy[maxn*2+1];

void update(int& a,int& b, int c, int d){if (a>c){a=c; b=d;} else if (a==c) b+=d;}

void count(int a[], int ss[], int& r, int& c, int& r0, int& c0){
    sort(a,a+n);
    r=oo; r0=oo;
    int i,j=0,s=0;
    for(i=0;i<n;i++) s+=a[i]+10000; ss[0]=s;
    update(r,c,s,1);
    if (a[j]!=-10000) update(r0,c0,s,1);
    for(i=-9999;i<=10000;i++){
        while (j<n && a[j]<i) j++;
        s+=j*2-n;
        ss[i+10000]=s;
        update(r,c,s,1);
        if (j==n || a[j]!=i) update(r0,c0,s,1);
    }
}

int main(){
    freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,i,j,c,cx,cy,rx,ry,cx0,cy0,rx0,ry0;
    scanf("%d",&test);
    for(i=0;i<test;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d%d",&x[j],&y[j]);
        for(j=0;j<n;j++)a[j]=x[j];
        count(a,sx,rx,cx,rx0,cx0);
        for(j=0;j<n;j++)a[j]=y[j];
        count(a,sy,ry,cy,ry0,cy0);
        c=0;
        for(j=0;j<n;j++) if (sx[x[j]+10000]+sy[y[j]+10000]==rx+ry) c++;
        if (cx*cy-c>0) printf("%d %d\n",rx+ry,cx*cy-c);
        else{
            int res1=oo,res2;
            update(res1,res2,rx0+ry0,cx0*cy0);
            update(res1,res2,rx0+ry,cx0*cy);
            update(res1,res2,rx+ry0,cx*cy0);
            printf("%d %d\n",res1,res2);
        }

    }
    return 0;
}
