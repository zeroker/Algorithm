//4.2

//搜索
//4.21                       ........
//连连看
#if 0
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int map[1010][1010];
int cnt_map[1010][1010];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s_x,s_y;
int e_x,e_y;
int flag,n,m;
struct node
{
    int cnt;
    int x,y;
    int pre_dir;
}s_pos;
bool cheak(int x,int y)
{

    if(x>=1&&x<=n&&y>=1&&y<=m&&(map[x][y]==0||x==e_x&&y==e_y))
        return 1;
    return 0;
}

void dfs(int x,int y,int cnt,int pre_dir)
{
    if(flag||cnt>3)                     //flag==1   ||   cnt >2
        return ;
    if(x==e_x&&y==e_y)                  // 如果到了位置   flag=1
    {
        flag=1;
        return ;
    }

    for(int i=0;i<4;i++)
    {
        int n_x,n_y;
        n_x=x+dir[i][0];
        n_y=y+dir[i][1];
        if(cheak(n_x,n_y)&&cnt+1<=cnt_map[n_x][n_y])
        {
            if(pre_dir==i&&cnt<=3&&cnt<cnt_map[n_x][n_y])
            {
                cnt_map[n_x][n_y]=cnt;
                dfs(n_x,n_y,cnt,pre_dir);
            }

            if((pre_dir!=i||pre_dir==-1)&&cnt<=3)
            {
                cnt_map[n_x][n_y]=cnt+1;
                dfs(n_x,n_y,cnt+1,i);
            }
        }
    }
}
int main()
{
    int i,j,q;
    while(cin>>n>>m,n+m)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>map[i][j];
                //scanf("%d",&map[i][j]);
            }
        cin>>q;
        //scanf("%d",&q);
        while(q--)
        {
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    cnt_map[i][j]=100000;
            cin>>s_x>>s_y>>e_x>>e_y;
            //scanf("%d%d%d%d",&s_x,&s_y,&e_x,&e_y);
            if(map[s_x][s_y]!=map[e_x][e_y]||map[s_x][s_y]==0||map[e_x][e_y]==0)                                // 如果不符合条件  NO
            {
                cout<<"NO"<<endl;
            }
            else
            {
                flag=0;
                dfs(s_x,s_y,0,-1);
                if(flag)
                    cout<<"YES"<<endl;
                else
                   cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

#endif 



















//4.22 
//前两天在自己学校搜索专题上见过    所以直接tie了 

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




//4.25 
//骑士走日子 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int step[8][8];
int dir[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool pd(int x,int y) 
{
 if(x>=0 && x<=7 && y>=0 && y<=7) 
 return 1;
 else return 0;
} 
int starx,stary,endx,endy;
int bfs()
{
  memset(step,0,sizeof(step)); 
  queue <int>q;
  int x,y,x1,y1;
  q.push(starx);
  q.push(stary);
  step[x][y]=0;
  
  while(!q.empty())
  {
  	 x=q.front();
  	 q.pop();
  	 y=q.front();
  	 q.pop();
  	 
  if(x==endx && y==endy) 
  return step[x][y];
  
  else
  {
    for(int i=0; i<=7; i++)
    {
    	x1=x+dir[i][0];
    	y1=y+dir[i][1];
    	if(pd(x1,y1)) 
    	{
    		q.push(x1);
    		q.push(y1);
    		step[x1][y1]=step[x][y]+1;
		}
    	
	}
  }	
}

}

int main()
{
	char a[3],b[3];
	while(cin>>a>>b)
	{
		starx=a[0]-'a';
		stary=a[1]-'1';
		endx=b[0]-'a';
		endy=b[1]-'1';
		int ans=bfs();
		cout<<"To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves."<<endl;
	
	}
	
}
#endif 

















































