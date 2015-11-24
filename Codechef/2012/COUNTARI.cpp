#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
#define PI 3.141592653589793238462

/* pnt denotes complex numbers: x=real part, y=imaginary part */
typedef struct struct_point{double x,y;}pnt;

pnt pntPlus(pnt a,pnt b){a.x+=b.x; a.y+=b.y; return a;}
pnt pntMinus(pnt a,pnt b){a.x-=b.x; a.y-=b.y; return a;}
pnt pntMultiple(pnt a,pnt b){pnt c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
pnt pntMultipleDouble(pnt a,double k){a.x*=k; a.y*=k; return a;}

pnt pntPolar(double r,double t){pnt a; a.x=r*cos(t); a.y=r*sin(t); return a;} /* r * exp(i*t), i=sqrt(-1) */
pnt pntGenerator(double x,double y){pnt res; res.x=x; res.y=y; return res;}   /* x + i*y */

/* Fast Fourier Transform */
/* n = size of a = a power of 2, theta = 2*PI/n */
/* for inverse fft, theta = -2*PI/n */
void fft(int n, double theta, pnt a[]){
  int i, j, k, m, mh;
  pnt w, x;

  for(m=n; m>=2; m/=2){
    mh = m / 2;
    rep(i,mh){
      w = pntPolar(1, i*theta);
      for(j=i; j<n; j+=m){
        k = j+mh;
        x = pntMinus(a[j], a[k]);
        a[j] = pntPlus(a[j], a[k]);
        a[k] = pntMultiple(w, x);
      }
    }
    theta *= 2;
  }

  i = 0;
  REP(j,1,n-1){
    for(k=n/2; k > (i ^= k); k/=2);
    if(j < i) w=a[i], a[i]=a[j], a[j]=w;
  }
}


#define ll long long
#define N2 65536
#define M 30000
#define BLOCK_SIZE 30

int in[120000];
int bef[M], aft[M], inside[M];
pnt p1[N2], p2[N2];

int main(){
  int N;
  int i, j, k, block;
  int st, ed, per;
  ll res;
  double invN2 = 1.0 / N2;

  assert( scanf("%d",&N)==1 );
  assert( 1<=N && N<=100000 );
  rep(i,N) assert( scanf("%d",in+i)==1 ), assert( 1 <= in[i] && in[i] <= M ), in[i]--;

  /* bef[i] = the number of i in the previous blocks */
  /* aft[i] = the number of i in the next blocks */
  res = 0;
  rep(i,M) bef[i] = aft[i] = 0;
  rep(i,N) aft[in[i]]++;

  per = (N+BLOCK_SIZE-1) / BLOCK_SIZE; /* the number of elements for each blocks */

  rep(block, BLOCK_SIZE){
    st = block * per;     /* the index of the first element in this block */
    ed = (block+1) * per; /* the index of the first element in the next block */
    if(ed > N) ed = N;

    REP(i,st,ed) aft[in[i]]--;
    rep(i,M) inside[i] = 0;

    /* BEGIN: counting arithmetic progressions whose at least 2 terms are in this block */
    REP(i,st,ed){
      /* inside[i] denotes the number of i in indexes [st, i) (in this block) */
      REP(j,i+1,ed) if(in[i] != in[j]){ /* in this loop, count only arithmetic progressions with three distinct terms */
        k = in[i] - (in[j] - in[i]);
        if(0<=k && k<M) res += bef[k] + inside[k]; /* counting: the second and third terms are indexes i and j */
        k = in[j] + (in[j] - in[i]);
        if(0<=k && k<M) res += aft[k]; /* counting: the first and second terms are indexes i and j */
      }
      inside[in[i]]++;
    }

    /* counting arithmetic progressions which have same three terms */
    rep(i,M){
      res += (ll)inside[i] * (inside[i]-1) / 2 * (bef[i] + aft[i]);
      res += (ll)inside[i] * (inside[i]-1) * (inside[i]-2) / 6;
    }
    /* END */

    /* BEGIN: counting arithmetic progressions whose only middle term is in this block */
    if(block && block+1 < BLOCK_SIZE){
      rep(i,N2) p1[i] = p2[i] = pntGenerator(0, 0);
      rep(i,M) p1[i].x = bef[i], p2[i].x = aft[i];
      
      fft(N2, 2*PI*invN2, p1);
      fft(N2, 2*PI*invN2, p2);
      rep(i,N2) p1[i] = pntMultiple(p1[i], p2[i]);
      fft(N2,-2*PI*invN2, p1);
      rep(i,N2) p1[i].x *= invN2;

      rep(i,M) res += inside[i] * (ll)( p1[2*i].x + 0.5 );
    }
    /* END */

    REP(i,st,ed) bef[in[i]]++;
  }


  printf("%lld\n",res);

  return 0;
}
