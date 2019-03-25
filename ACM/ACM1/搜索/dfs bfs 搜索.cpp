// 追牛问题  07 	G

#if  0                     // 输入 5 17 时候有问题 
#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 100005 ;

int pd[MAXN]  ;
int cnt[MAXN] ;   
queue <int> q ;

int bfs(int ni , int  ki)
{ 
 if( ni==ki ) return 0 ; 
 
 q.push(ni) ;
 
 //pd[ni] = 1 ;
 int fist ; 
 while(!q.empty()) 
                                                      
 {                                                                        
    fist = q.front() ;                            
   	q.pop() ;                                            
   if(  fist+1 < MAXN && !pd[fist+1]  )  
    	{                    
		       	q.push(fist+1) ;    
				cnt[fist+1] = cnt[fist] + 1 ;                    
    	        pd[fist+1] == 1 ;                    
				
		
		}
		   if(fist+1==ki) 
		        break ;		
		
		 if( fist-1 >= 0 && !pd[fist-1] ) 
    	{
    	        q.push(fist-1) ;
				cnt[fist-1] = cnt[fist] + 1 ;
				pd[fist-1] == 1 ;
				
		}
		if(fist-1==ki)
		  break;
		
		 if( fist*2 <= MAXN && !pd[fist*2] )
    	{
    	       	q.push(fist*2) ;
			    cnt[fist*2] = cnt[fist] + 1 ;
				pd[fist*2] == 1 ;
			
	
		}
			if(fist*2==ki) 
		      break;
	
 }	
 
return cnt[ki]  ;	
	
}

int main()

{
    int n , k ;
	cin >> n >> k ;
    cout << bfs(n , k) << endl;
	
	
}

#endif  
//追牛 wrong    07 	G
#if  0
#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 100001;  
  
bool pd[MAXN];											
int cnt[MAXN];												
  
queue<int> q;  
  
int bfs(int ni, int ki)  
{  
    if (ni == ki) return 0;
	
    q.push(ni);  
    pd[ni]= 1 ;
    int fist;  
    while (!q.empty())									
    {  
        fist = q.front();									
        q.pop();  
        if (fist + 1 < MAXN && !pd[fist + 1])					
        {  
            q.push(fist + 1);  
            cnt[fist + 1] = cnt[fist] + 1;  
            pd[fist + 1] = 1;  
        }  
          
        if (fist + 1 == ki) break;  
          
        if (fist - 1 >= 0 && !pd[fist - 1])						
            q.push(fist - 1);  
            cnt[fist - 1] = cnt[fist] + 1;  
            pd[fist - 1] = 1;  
          
        if (fist - 1 == ki) break;  
          
        if (fist*2 < MAXN && !pd[fist*2])							
        {  
            q.push(fist*2);  
            cnt[fist*2] = cnt[fist] + 1;  
            pd[fist*2] = 1;  
        }  
          
        if (fist*2== ki) break;  
    }  
      
    return cnt[ki] ;  
}
  
int main()  
{
	int n,k;
	cin>>n>>k;
   cout << bfs(n,k) <<endl; 
    return 0;  
}  

#endif 
// 07 	G 追牛 
 // correct  

#if 0
#include<iostream>
#include<queue>
using namespace std;
queue <int> q;
const int MAX = 100005 ;
int ret[MAX];
bool pd[MAX];
int bfs(int m,int k)
{
    if(m==k)return 0;
    q.push(m);
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur+1<MAX&&!pd[cur+1])
        {
            q.push(cur+1);
            ret[cur+1]=ret[cur]+1;
            pd[cur+1]=true;
        }
        if(cur+1==k)break;
        if(cur-1>=0&&!pd[cur-1])
        {
            q.push(cur-1);
            ret[cur-1]=ret[cur]+1;
            pd[cur-1]=true;
        }
        if(cur-1==k)break;
        if(cur*2<MAX&&!pd[cur*2])
        {
            q.push(cur*2);
            ret[cur*2]=ret[cur]+1;
            pd[cur*2]=true;
        }
        if(cur*2==k) break;
    }
    return ret[k];
}
int main()
{ 
    int M , K ;
    cin>>M>>K;
    cout<<bfs(M,K)<<endl;
    return 0;
}


#endif 

// 深度搜索 找出用1和0 组成的十位数 ，是 n  的 倍数的数字  
//  H 08 
#if  0 
#include<iostream>
#include<cstdio>
typedef unsigned long long int longl ;
bool pd ; 
using namespace std;
void fun(longl x , int n , int k)
{
	 if(pd) return  ;
	 if(x%n==0)
	 {
	 	pd=true ;
	 	printf("%I64u\n", x);
	 	return  ;
	 }
	 if(k==19) return ;
	 fun(x*10,n,k+1) ;
	 fun(x*10+1,n,k+1) ;
	
}

int main()

{
  int n ; 
 while(cin>> n && n!=0 )

  {
  	
    pd=false ;	
  	 fun (1,n,0);	
	
  }

 } 

#endif 
 
//素数环 问题1  给你一个n 让你给1-n的数字排序，使他们任意相邻的两个数字的和是素数   ，并且开口的数字总是 1 
#if 0 
#include<iostream>
#include<cmath>
using namespace std;
int N , toal;

bool pd[21] ;
int ret[21] ;
int prime(int a ,int b) 
{
  int x=a+b ,cnt=2;
  int sqrx=sqrt(x) ;
 
while(cnt<=sqrx&&x%cnt!=0) cnt++;
if(cnt>sqrx) return 1;
else return 0 ;

}
int show()
{
	for(int i=1 ; i < N ;i++)
	  cout << ret[i]<<" " ;
	  cout << ret[N]<< endl;
	
}
int dfs(int t,int n)
{
	int i  ;
	
	for(i = 1 ; i <= n ; i++)
	{
		if(prime(ret[t-1],i) && !pd[i])
		{
			ret[t]=i;
			pd[i]=1;
		if(t==n)
	{
		if(prime(ret[n],ret[1])&&ret[1]==1) show();
	}
        else    dfs(t+1,n) ;
         pd[i]=0;
		}
	}

      	
	
}

int main()
{
  	while(cin>>N)
  	{
  		toal++ ;
  		cout << "Case "<<toal<<":"<<endl;
		  dfs(1,N) ;
  		cout << endl;
	}

	
 } 


#endif 

//地图搜索 p- 16

#if 0 
#include<iostream>
#include<string.h>
using namespace std;
int m , n ;
char map[101][101] ;
bool pd[101][101] ;
int dirction[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}} ;
int dfs(int a, int b)
{
	int xi, yi;
	pd[a][b] = 1 ;
	for(int i=0; i<8 ;i++)
	{
		
		  xi=a+dirction[i][0];
		  yi=b+dirction[i][1];
        if(xi>=0&&xi<m&&yi>=0&&yi<n){
		   
	    if(map[xi][yi]=='*') continue ;
        if(pd[xi][yi]) continue;
        dfs(xi,yi) ;
    }
	}
	
}

int main()
{
	
	while(cin>>m>>n&&n&&m)
	{
		int sum=0;
	   memset(pd,false,sizeof(pd)) ;
	   memset(map,0,sizeof(map)) ;
	   for(int i=0; i<m; i++)
	   {
	   	
	   
			scanf("%s",map[i]);  //   
	   }
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
		if(!pd[i][j]&&map[i][j]=='@') 	
		 {
			dfs(i,j) ;
			sum++;
		}
		}
	}
	
	cout << sum << endl;
		
	}
		
}

#endif 



//搜索 地图 内涵 数组排序 
#if 0 
#include<iostream>
#include<cstring>

using namespace std;

bool flag[10];
char mapi[10][10];
int  n , k; 
int cnt ,num; //num 已放棋子数 
void dfs(int i){
    if(k==num){
        cnt++;
        return ;
    }
    if(i>=n)
        return ;
    for(int j=0;j<n;j++)
        if(!flag[j] && mapi[i][j]=='#'){
            flag[j]=1;
            num++;
            dfs(i+1);
            flag[j]=0;
            num--;
        }
    dfs(i+1);  
}


int main()
{
 while(cin>>n>>k&&n!=-1&&k!=-1)
 {
 	cnt=num=0;
 	memset(flag,false,sizeof(flag)); 
 	for(int i=0; i<n; i++)
	 for(int j=0; j<n; j++)
	      cin>>mapi[i][j]; 
	      
	   dfs(0);   	
	 cout << cnt <<endl;
	 
    } 
 }		
  
#endif 




//经典二分查找  
//题意：有n条绳子，分成k段相等的，问能使得最长为多长 
#if 0
#include<iostream>
#include<cmath>
#include<iomanip>
#define exp 1e-8 
using namespace std;
int n,k;
double a[10001],sum;

int go(double s)        
{       
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		cnt+=(int)(a[i]/s);
	}
	if(cnt>=k) return 1;
	 else return 0;
}

int main()
{
	ios::sync_with_stdio(false) ;
double mid ,l , r;
while(cin>>n>>k )
{
	if(n==0 && k==0) break;
	
	sum=0;
 for(int i=0; i<n; i++)
  {
  cin>>a[i];
  sum+=a[i];
 }
 sum/=k;
 l=0;r=sum;
 while(fabs(l-r)>exp)
 {
 	mid=(l+r)/2;
 	if(go(mid)) 
 	l=mid;
 	else 
 	r=mid;
 }
 printf("%0.2f\n",l);	
}	
		
}

#endif

//B - 02 骑马问题
#if 0
#include<iostream>
#include<cstring>
using namespace std;
#define max 30
int ax[max],ay[max],q,p;
bool vis[max][max],flag;
int f[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int judge(int x,int y)
{
 if(x>=0 && x<q && y>=0 && y<p && vis[q][p]==0)
  return 1;
  else
  return 0;
 
}

void dfs(int a,int b,int t)
{
 	ax[t]=a;
 	ay[t]=b;
 	vis[a][b]=1;
 	
 	if(t==p*q-1) 
 	{
 	   flag=1;
       return ;
	} 
 for(int i=0; i<8; i++) 
{
	int dx=ax[t]+f[i][0];
	int dy=ay[t]+f[i][1];
	
	if(judge(dx,dy) && !vis[dx][dy])
	{
	  vis[dx][dy]=1;    
	  dfs(dx,dy,t+1);
	  if(flag)
	  return ;
	  vis[dx][dy]=0;
	}
}
 return ;
}

int main()
{
int n,ans=1;
cin>>n;

while(n--)
{
 flag=0;
 memset(vis,false,sizeof(vis));
 memset(ax,0,sizeof(ax));
 memset(ay,0,sizeof(ay));

    cin>>p>>q;
 	cout<<"Scenario #"<<ans<<":"<<endl;
    ans++;
 
  for(int i=0; i<q; i++)
  { 
  	 for(int j=0; j<p; j++)
  {
  	dfs(i,j,0);
  	if(flag) 
  	break;	
  }
  if(flag)
  break;
  }
  
  if(flag)
  {  
  for(int i=0; i<q*p; i++) 
  cout<<char(ax[i]+'A')<<ay[i]+1; 
  cout<<endl<<endl;
  }
  else 
  cout<<"impossible"<<endl<<endl;
 
 	
}	
 	
} 
#endif 



































