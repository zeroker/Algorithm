#if 0
#include<bits/stdc++.h>
using namespace std;
struct go
{
int l,w;	
};
int main()
{
	vector<go> v;
	for(int i=0; i<4; i++)
    {
     go x;
	 cin>>x.l>>x.w;
	 v.push_back(x);   	
    } 
	
	vector<go>::iterator it;
	for(it=v.begin();it!=v.end();)
	{
		if(it->l==1) 
		v.erase(it);
		else it++;
	}
	
	for(int i=0; i<v.size(); i++)
	cout<<v[i].l<<" "<<v[i].w<<endl;
}

#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int head;
    int end;
    int flag;
} node[5005];

int cmp(struct Node a,struct Node b)
{
    if(a.head < b.head)
    return 1;
    else if(a.head == b.head)
    return a.end < b.end;
    return 0;
}

int main()
{
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int i,j,sum = 0,cnt = 0;
        for(i = 0; i<n; i++)
        {
            cin >> node[i].head >> node[i].end;
            node[i].flag = 0;
        }
        sort(node,node+n,cmp);
        int ans = 0;
        for(i = 0; i<n; i++)
        {
            if(!node[i].flag)
            {
                node[i].flag = 1;
                ans++;
                int end = node[i].end;
                for(int j = i+1; j < n; j++)
                {
                    if(!node[j].flag && node[j].end >= end)
                    {
                        node[j].flag = 1;
                        end = node[j].end;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

#endif


#if 0
#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
int main()
{
  int a[MAX];    
  bool b[MAX];
  int k,ans=0;
  memset(a,true,sizeof(a));
    
  for(int i=1; i<=MAX; i++)
  {
  	a[i]=i;
  }	

   for(int i=2; i<=MAX; i++)
   {
   	 int j,m=sqrt(i);
   	
   	 if(!b[i])
   	 continue;
   	 
   	 for( j=2; j<=m; j++)
   	 {
   	  if(i%j==0) break;	
	 }
	 
	 if(j==m+1) 
	 {
	 	ans++;
	 	cout<<i<<" ";
	 	for(int k=1; k<=MAX/i; k++)
	 	{
	 	 	b[i*k]=0;
		}
	 	
	 }
	  
   }
   cout<<ans<<endl;
	
}
#endif

















#if 0
#include<bits/stdc++.h>
#include <utility>
#include <queue>
#define MAX 1000000
using namespace std;

int lpf[MAX];

int main(){
    int n,cnt,i,j;
    memset(lpf,0,sizeof(lpf));
    lpf[2]=1;
    for(i=4;i<MAX;i+=2)
        lpf[i]=lpf[2];
    cnt=2;
    for(i=3;i<MAX;i+=2){
        if(lpf[i])
            continue;
        lpf[i]=cnt++;
        for(j=(i<<1);j<MAX;j+=i)
            lpf[j]=lpf[i];
    }
    while(~scanf("%d",&n))
        printf("%d\n",lpf[n]);
    return 0;
}
#endif

#if 0
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int a[1000000];
int main()
{
    int k=1;//k初始化为1,位置   
     memset(a,0,sizeof(a));
    /*筛选位置*/  
    for(int i=2;i<1000000;i++)//要到N,而不是sqrt(N)
    {
        if(!a[i])
        {
          a[i]=k;//素数i的位置   
            for(int j=i+i;j<1000000;j+=i)
                a[j]=k;    //构造出j的暂时最大素数因子的位置 
            k++;
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
#endif

#if 0
#include<stdio.h>
int main()
{
    double a,b,c,t,k,x1,x2,x3,y1,y2,y3,s1,s2;
    int te;
    scanf("%d",&te);
    while(te--)
    {
       scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
       k=(y3-y2)/(x3-x2);
       t=y3-k*x3;
       a=(y2-y1)/((x1-x2)*(x1-x2));
       b=-x1*2*a;
       c=y1-a*x1*x1-b*x1;
       s1=1.0/3*a*x2*x2*x2+1.0/2*(b-k)*x2*x2+x2*(c-t);
       s2=1.0/3*a*x3*x3*x3+1.0/2*(b-k)*x3*x3+x3*(c-t);
       printf("%.2lf\n",s2-s1);
    }
    return 0;
}
#endif 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=123564785;
	 while(a>=10000)
 {
  a=a/10; 
 } 
 cout<<a<<endl;
}
#endif



#if 0
#include<iostream>
using namespace std;

bool DFS(int n,int A[],int B[],int C[])///将n个圆盘从A杆借助B杆从而移到C杆
{
    if(B[0]==n)///如果第n个盘在B杆上的话，就多步骤了，这是不正确的
    {
        return false;
    }
    else if(A[0]==n) ///如果第n个圆盘在A杆上
    {
        return DFS(n-1,A+1,C,B);///将第n个圆盘上方（所以是A+1）的n-1个圆盘借助C移到B上
    }
    else if(C[0]==n) ///如果第n个圆盘在C杆上
    {
        return DFS(n-1,B,A,C+1);///将B上的n-1个圆盘借助A移到C杆上，且在第n个圆盘的上方（所以是C+1）
    }
    return true;
}
int main()
{
    int A[70],B[70],C[70];
    int testNum;
    int n,m,p,q;
    cin>>testNum;
    while(testNum--)
    {
        cin>>n;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>A[i];
        }
        cin>>p;
        for(int i=0;i<p;i++)
        {
            cin>>B[i];
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>C[i];
        }

        if(DFS(n,A,B,C))
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }

    }
    return 0;
}


#endif 


//高精度乘法 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string as,bs;
 cin>>as>>bs;
 int a[20],b[20],c[20];
 memset(c,0,sizeof(c));
 memset(a,0,sizeof(a));
 memset(b,0,sizeof(b));
 
 reverse(as.begin(),as.end());
 reverse(bs.begin(),bs.end());
 int lena=as.size();
 int lenb=bs.size();
 
 for(int i=0; i<lena; i++) 
 a[i+1]=as[i]-'0';
 
 for(int i=0; i<lenb; i++)
 b[i+1]=bs[i]-'0'; 
 
 
 for(int i=1; i<=lena; i++) 
 {
 	int x=0;
 	for(int j=1; j<=lenb; j++)
 	{
 	 c[i+j-1]=a[i]*b[j]+c[i+j-1]+x;      
	 x=	c[i+j-1]/10;
	 c[i+j-1]=c[i+j-1]%10;
	}
	c[i+lenb]=x;
 }
 
 int lenc=lena+lenb;
 while(c[lenc]==0 && lenc>1) 
 	lenc--;
 
 
 for(int i=lenc; i>=1; i--)
 cout<<c[i];
 	
}
#endif 

#if 0
#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

#define MAX 101
#define BASE 10000

void multiply(int a[], int len, int b) {
    for(int i=len-1, carry=0; i>=0; i--) {
        carry += b * a[i];
        a[i] = carry % BASE;
        carry /= BASE;
    }
}

void divide(int a[], int len, int b) {
    for(int i=0, div=0; i<len; i++) {
        div = div * BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}

int main()
{
    int i, j, h[101][MAX];
    memset(h[1], 0, MAX*sizeof(int));
    for(i=2, h[1][MAX-1]=1; i<=100; i++) {
        memcpy(h[i], h[i-1], MAX*sizeof(int));
        multiply(h[i], MAX, 4*i-2);
        divide(h[i], MAX, i+1);
    }

    while(cin >> i && i>=1 && i <= 100) {
        for(j=0; j<MAX && h[i][j]==0; j++);
        printf("%d", h[i][j++]);                                               
        for(; j<MAX; j++)
            printf("%04d", h[i][j]);
        cout << endl;
    }
    return 0;
}
#endif 






#if 0 
#include <stdio.h>

int main()
{
	int i, caseNum, testNum;
	int n, number, sum, startPosition, endPosition, tempPosition, max;
	scanf("%d", &testNum);
	for (caseNum = 1; caseNum <= testNum; caseNum++)
	{
		max = -1010;
		sum = 0;
		tempPosition = 1;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &number);
			sum += number;
			if (sum > max)
			{
				max = sum;
				startPosition = tempPosition;
				endPosition = i;
			}
			if (sum < 0)
			{
				sum = 0;
				tempPosition = i + 1;
			}
		}
		printf("Case %d:\n%d %d %d\n", caseNum, max, startPosition, endPosition);
		if (caseNum != testNum)
		{
			printf("\n");
		}
	}
	return 0;
}
#endif


#if 0 
#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
int a[5850];//存放丑数

int main()
 
    int n=1;
    int p2,p3,p5,p7;
    p2=p3=p5=p7=1;//2,3,5,7的计数器
    a[1]=1;
    while(a[n]<2000000000)//从2开始递推计算，一共5842个丑数
    {
        a[++n] = min4(2*a[p2],3*a[p3],5*a[p5],7*a[p7]);//取最小值，相应的计数器加1
        if(a[n]==2*a[p2]) p2++;
        if(a[n]==3*a[p3]) p3++;
        if(a[n]==5*a[p5]) p5++;
        if(a[n]==7*a[p7]) p7++;
    }
    while(scanf("%d",&n) && n)
    {
        if(n%10 == 1&&n%100!=11)
        printf("The %dst humble number is ",n);
        else if(n%10 == 2&&n%100!=12)
        printf("The %dnd humble number is ",n);
        else if(n%10 == 3&&n%100!=13)
        printf("The %drd humble number is ",n);
        else
        printf("The %dth humble number is ",n);
        printf("%d.\n",a[n]);
    }
    return 0;

}


#endif


#if 0
#include<stdio.h>
int main(){
	int n;
	int f[1001][101] = {0};
	f[0][1] = 1;
	f[1][1] = 1;
	f[2][1] = 2;
	f[3][1] = 4;
	for(int i = 4; i < 1001; ++i){
		for(int j = 1; j < 101; ++j){
			f[i][j] += f[i - 1][j] + f[i - 2][j] + f[i - 4][j];	//数组的每一位相加
			f[i][j + 1] += f[i][j] / 10000;	//超过4位的部分保存至数组下一位中
			f[i][j] %= 10000;	//每位数组只保存其中4位
		}
	}
	while(scanf("%d", &n) != EOF){
		int k = 100;
		while(!f[n][k--]);	//排除前面为空的数组
		printf("%d", f[n][k + 1]);	//输出结果的前四位
		for(; k > 0; --k){
			printf("%04d", f[n][k]);	//输出其余的所有四位数字，若数字小于四位，则前面用0填充
		}
		printf("\n");
	}
	return 0;
}

#endif 

#if 0
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int map[25][1005],dp[25][1005];

int main()
{
    int t,n,m,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i = 1; i<=n; i++)
            for(j = 1; j<=m; j++)
                scanf("%d",&map[i][j]);
        for(i = 0; i<=n; i++)
            dp[i][0] = -99999999;
        for(i = 0; i<=m; i++)
            dp[0][i] = -99999999;
        dp[1][0] = dp[0][1] = 0;
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=m; j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                for(k = 2; k<=m; k++)
                {
                    if(j/k == (double)j/k)//找倍数关系
                        dp[i][j] = max(dp[i][j],dp[i][j/k]);
                }
                dp[i][j]+=map[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }

    return 0;
}


#endif



#if 0 
#include<iostream>
using namespace std;
#define SIZE 11111
double dp[SIZE];
double Min(double x,double y)
{
    return x<y?x:y;
}
int main()
{
    int i,j;
    int n,m,a[SIZE];
    double b[SIZE];
    while(cin>>n>>m,n+m)
    {
        for(i=0;i<m;i++)
            scanf("%d %lf",&a[i],&b[i]);
        fill(dp,dp+11111,1);/*概率通通赋值为1*/  
        for(i=0;i<m;i++)
        {
            for(j=n;j>=a[i];j--)
            {
                dp[j]=Min(dp[j],dp[j-a[i]]*(1-b[i]));
            }
        }
        printf("%.1lf%%\n",(1-dp[n])*100);    
    }
    return 0;
}

#endif























#if 0
#include<bits/stdc++.h>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

typedef struct node
{
    int v,w;
} shoe;
vector<shoe>brand[15];
int main()
{
    int dp[15][10005];
    int n,m,k,a;
    shoe s;
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<=k;i++)
        brand[i].clear();
        for(int i=0; i<n; i++)
        {
            cin>>a>>s.v>>s.w;
            brand[a].push_back(s);
        }
        
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));

        for(int i=1;i<=k;i++)
        for(int p=0;p<(int)brand[i].size();p++)
        for(int j=m;j>=brand[i][p].v;j--)
        {
            if(dp[i][j-brand[i][p].v]!=-1) 
			dp[i][j]=max2(dp[i][j],dp[i][j-brand[i][p].v]+brand[i][p].w);//同一种类的鞋子能取多个
			 
            if(dp[i-1][j-brand[i][p].v]!=-1) 
			dp[i][j]=max2(dp[i][j],dp[i-1][j-brand[i][p].v]+brand[i][p].w);
        }
        
        if(dp[k][m]>=0)
        cout<<dp[k][m]<<endl;
        else
        cout<<"Impossible"<<endl;
    }
    return 0;
}

#endif


#if 0
#include <iostream>
#include <algorithm>
using namespace std;
int qn;    //sab数组总数 
int sab[250005];
int binsearch(int q[],int n,int k)    //二分查找 
{
    int left=1,right=n,mid;
    while(left<=right){
        mid = (left+right)/2; 
        if(q[mid]==k)
            return mid;
        if(q[mid]>k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}
int main()
{
    int l,n,m;
    int count = 1;
    while(cin>>l>>n>>m){
        qn = 1;
        int A[501],B[501],C[501];
        for(int i=1;i<=l;i++){
            cin>>A[i];
        }
        for(int i=1;i<=n;i++){
            cin>>B[i];
        }
        for(int i=1;i<=m;i++){
            cin>>C[i];
        }
        for(int i=1;i<=l;i++)
            for(int j=1;j<=n;j++)
                sab[qn++] = A[i] + B[j];    //产生sab数列 
        sort(sab+1,sab+qn-1);    //对sab数列进行排序 
        int s;
        cin>>s;
        cout<<"Case "<<count++<<":"<<endl;
        while(s--){
            int t;
            cin>>t;
            int i;
            for(i=1;i<=m;i++){
                int tt = t - C[i];
                if(binsearch(sab,qn-1,tt)){    //查找有没有 x-c 
                    cout<<"YES"<<endl;
                    break;
                }
            }
            if(i>m)
                cout<<"NO"<<endl;
        }
    }
    return 0;
}


#endif




































































