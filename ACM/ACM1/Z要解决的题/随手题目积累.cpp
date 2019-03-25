#if  0                  //acm程序设计中的题 草坪问题  w 23 
#include<iostream>
using namespace std;
int main() 
{ 
         int n,m; 
       while(cin>>n>>m)
   { 
        if(n==0&&m==0) break;
        int i,j;
        int a[15][15];
        int flag=0,flag1=1;
            for(i=0;i<=14;i++)
            for(j=0;j<=14;j++)
            a[i][j]=1;
           for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
           {
            cin>>a[i][j];
            if(a[i][j]==0)?flag=1;
            }
            for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
           {
                if((a[i][j]==0&&a[i-1][j]==0)||(a[i][j]==0&&a[i+1][j]==0)||(a[i][j]==0&&a[i][j-1]==0)||(a[i][j]==0&&a[i][j+1]==0))
                 flag1=0;
            }
              if(flag&&flag1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
     }
   return 0;
}

#endif



//山东第一节acm  h 题 
//水题 hello world      
#if 0 
#include<iostream>
#include<algorithm>
using namespace std;
struct E
{
    int  r,c; 
};
bool cmp(const E &a,const E &b)
{
    if(a.r<b.r)
          return 1;
      if((a.r==b.r)&&(a.c<b.c))
 return 1;
     return 0;
}

int main()
{
     int n,i,j,cas=0,r,c;
        while(cin>>n,n)
     {
  E*e=new E[n];
  E *e0=new E[n];
   for(i=0;i<n;i++)
        {
     cin>>r>>c;
            e[i].r=r;
            e[i].c=c;
            e0[i].r=r;
            e0[i].c=c; 
			}

         sort(e0,e0+n,cmp);

         //for(i=0;i<n;i++)
         //cout<<e0[i].r<<'?'<<e0[i].c<<endl;

         cout<<"Case?"<<++cas<<":"<<endl;??
          for(i=0;i<n;i++)??
    {
                r=e[i].r;
                c=e[i].c;
             for(j=0;j<n;j++)
       {
        if(e0[j].r>r&&e0[j].c>c)
              {
cout<<e0[j].r<<' '<<e0[j].c<<endl;
                 break;
                }
            }
        if(j==n)
           cout<<-1<<' '<<-1<<endl;
         }
         cout<<endl;
    }
             return 0;
}

#endif



//acm 程序设计中的题 书单问题  v  22   P170
#if    0


#endif 

 

//acm 程序设计中的题   猫食问题   p 16   P166
#if    0


#endif 

//acm 程序设计中的题   dna排序  e 05   P152
#if    0


#endif 




















