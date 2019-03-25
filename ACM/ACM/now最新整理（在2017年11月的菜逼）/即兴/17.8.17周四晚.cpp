//要么说每天要写点东西  写一个算法写是啊 ，要不手痒痒怎么办
//超时预算要有的啊  



//整理个冒泡吧 
#if 0
#include<iostream>
using namespace std;
int main()
{
	int a[100000];
	int n;
	
	while(scanf("%d",&n))
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
			
		for(int i=1; i<n; i++)
		{
			for(int j=1; j<=n-i; j++)
			{
				if(a[j]>a[j+1])
				{
					a[j]^=a[j+1];
					a[j+1]^=a[j];
					a[j]^=a[j+1];
				}
			}
		}
		
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl; 
				
	}
}
#endif	 
//还有个叫做选择排序 一直和快速排序混了
#if 0
#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[10000];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		
		for(int i=1; i<n; i++)
		{
			int maxx=i;
			for(int j=i; j<=n; j++)
			{
				if(a[maxx]>a[j])
					maxx=j;
			}
			
			if(maxx!=i)
			{
				a[i]^=a[maxx];
				a[maxx]^=a[i];
				a[i]^=a[maxx];
			}
				
		}
		
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl;	
	}
	
	
}


#endif	 
	 
	 
//哦哦
#include<stdio.h>
#include<string.h>
void makeNext(const char P[],int next[])
{
    int q,k;
    int m = strlen(P);
    next[0] = 0;
    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && P[q] != P[k])
            k = next[k-1];
        if (P[q] == P[k])
        {
            k++;
        }
        next[q] = k;
    }
}

int kmp(const char T[],const char P[],int next[])
{
    int n,m;
    int i,q;
    n = strlen(T);
    m = strlen(P);
    makeNext(P,next);
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && P[q] != T[i])
            q = next[q-1];
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m)
        {
            printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
    }    
}

int main()
{
    int i;
    int next[20]={0};
    char T[] = "ababxbababcadfdsss";
    char P[] = "abcdabd";
    printf("%s\n",T);
    printf("%s\n",P );
    // makeNext(P,next);
    kmp(T,P,next);
    for (i = 0; i < strlen(P); ++i)
    {
        printf("%d ",next[i]);
    }
    printf("\n");

    return 0;
}





































	 
	 
	 
	 
 
