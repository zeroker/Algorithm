




//1. ��������������    �α�356
//hdu   Coins

/*
Problem Description
Whuacmers use coins.They have coins of value A1,A2,A3...An Silverland dollar. One day Hibix opened purse and found there were some coins. He decided to buy a very nice watch in a nearby shop. He wanted to pay the exact price(without change) and he known the price would not more than m.But he didn't know the exact price of the watch.

You are to write a program which reads n,m,A1,A2,A3...An and C1,C2,C3...Cn corresponding to the number of Tony's coins of value A1,A2,A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins.
 

Input
The input contains several test cases. The first line of each test case contains two integers n(1 �� n �� 100),m(m �� 100000).The second line contains 2n integers, denoting A1,A2,A3...An,C1,C2,C3...Cn (1 �� Ai �� 100000,1 �� Ci �� 1000). The last test case is followed by two zeros.
 

Output
For each test case output the answer on a single line.
 

Sample Input
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
 

Sample Output
8
4
*/


//ǰ���첻֪��զ��   ������ȥ ֱ����tie   ������ �ɲ���Ķ�����һ�� Ȼ��  ���п��Լ������ ��  

#if 0 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,A[101],C[101],f[100001],num,coun;
    while(cin>>n>>m&&n&&m)
    {
        for(int i = 0; i < n ; i++)
            cin>>A[i];
        for(int i = 0; i < n ; i++)
            cin>>C[i];
        memset(f,0,sizeof(f));                                  //�����������m������ֵ��f[m]Ϊ1������Ϊ0��
        f[0] = 1;
        for(int i = 0; i < n ; i++)                             //���� i ��ֵ
            for(int j = 0;j < A[i];j++)                         //���ÿ��Ӳ��,ֻ���������ֵΪ0--A[i]-1 �� K*A[i] �ļӺ���ɡ�1<=k<=c[i]
            {
                coun = C[i];                                     //��¼ʹ�õĴ���
                for(int k = j+A[i] ; k <= m;k+=A[i])//
                    if(f[k]==1)
                        coun = C[i];                             //���������ֵ�ļ۸���A[i]����Ӳ�Ҽ�����ɣ���ô����Ӳ�ҵ��������Իָ�ԭʼ������һ��Ҳû�ù�
                    else if(coun>0&&f[k-A[i]]==1)
                    {
                        f[k] = 1;
                        coun--;
                    }
            }
        num = 0;//��¼��Ŀ���õ�������ɵĽ����Ŀ��
        for(int i = 1; i <= m; i++)
        if(f[i]==1)num++;
        printf("%d\n",num);
    }
    return 0;
}
#endif




//5.11  
#if 0     //���鼯 �������� 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int par[3000], pre[3000];
int n, m;

void init()
{
    for(int i = 1; i <= n; i++) 
    	par[i] = i;
}

int find1(int x)
{
    int r = x, j;
    while(r != par[r]) r = par[r];
    while(x != r) j = par[x], par[x] = r, x = j;

    return r;
}

void unite(int x, int y)
{
    x = find1(x);
    y = find1(y);
    par[x] = y;
}

int main()
{
    int t, a, b, x = 0;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);

        init();
        memset(pre, 0, sizeof pre);
        int f = 1;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            if(find1(a) == find1(b)) f = 0;

            if(pre[a] == 0) pre[a] = b;
            else unite(pre[a], b);

            if(pre[b] == 0) pre[b] = a;
            else unite(pre[b], a);
        }

        if(! f) printf("Scenario #%d:\nSuspicious bugs found!\n", ++x);
        else printf("Scenario #%d:\nNo suspicious bugs found!\n", ++x);
        printf("\n");
    }


    return 0;
}


#endif 



//5.12 �ж��ǲ��� һ����
//һ��������0������ȫ��1
#if 1
#include<bits/stdc++.h>
using namespace std;
#define N 100010
bool used[N];
int q[N],in[N],fa[N];

int find(int x)
{
	if(fa[x]==-1)
	return x;
	else return fa[x]=find(fa[x]);
	
}
int un(int n,int m)
{
	int a=find(n);
	int b=find(m);
	if(a!=b)
	fa[b]=a;
}


int main()
{
 int n,m;
 int ans=0;
 memset(used,0,sizeof(used));
 memset(in,0,sizeof(in));
 memset(fa,-1,sizeof(fa));
 bool ok=true;
 int number=0;
 
 while(cin>>n>>m)
 {
 	if(n==-1 && m==-1)
 	break;
 	if(n==0 && m==0)
 	{
 	int numin=0;
	 for(int i=0; i<number; i++)
	 {
	 	if(find(i) != find(0))
	 	{
	 		ok=false;
	 		break;
		}
	    if(in[q[i]]==0) 
	    numin++;
	    if(q[i]>1)
	    {
	    	ok=false;
	    	break;
		}
	 	if(numin != 1)
	 	ok=false;
	 	
	 	if(number=0)
	 	ok=true;
	 	
	 	if(ok)
	 	cout<<"Case "<<++ans<<"is a tree."<<endl;
	 	else cout<<"Case "<<++ans<<"is not a tree."<<endl;
	 	
 memset(used,0,sizeof(used));
 memset(in,0,sizeof(in));
 memset(fa,-1,sizeof(fa));
 ok=true;
 number=0;
	 	
	 }	
 		
	}
	else
	{
		if(!used[n])
		{
			used[n]=true;
			q[number++]=n;
		}
		if(!used[m])
		{
			used[m]=true;
			q[number++]=m;
		}
		
		if(find(n)==find(m))
		ok=false;
		else
		{
			in[m]++;
			un(n,m);
		}
		
	}
 	
 }
 
 
 		
}
#endif 




















