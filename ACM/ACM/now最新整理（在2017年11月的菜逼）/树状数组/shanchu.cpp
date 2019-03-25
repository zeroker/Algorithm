#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int MAXN = 100005;
const int MAXX = 1000000007;

struct node
{
    int id,v;
    bool operator<(const node ai)const
    {
    	return v<ai.v;
	}
	
}a[MAXN];

int n;
int aa[MAXN],b[MAXN]; 

int Lowbit(int x)
{
    return x & (-x);
}

void add(int x,int v)
{
    for(int i=x; i<=n; i+=Lowbit(i))
    {
        b[i] += v;
        b[i] %= MAXX;
    }
}

int sum(int x)
{
    int s = 0;
    for(int i=x; i>0; i-=Lowbit(i))
    {
        s += b[i];
        s %= MAXX;
    }
    return s;
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(aa,0,sizeof(aa));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].id = i;
        }
        
        sort(a+1,a+n+1);
        aa[a[1].id] = 1;
        for(int i=2;i<=n;i++)
        {
            if(a[i].v != a[i-1].v)
                aa[a[i].id] = i;
            else
                aa[a[i].id] = aa[a[i-1].id];
        }
        
        for(int i=1;i<=n;i++)
        {
            int x=sum(aa[i]);
            add(aa[i],x+1);
        }
        printf("%d\n",sum(n));
    }
    return 0;
}
















