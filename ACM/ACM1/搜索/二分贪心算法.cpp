 #if  0          // 2题 字典问题 
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
   map<string,string>a ;
   char s[30],s1[12],s2[12];
   int n,i;
   while(   )
   {
   	 if(strcmp(s,"")==0) break;
   	 else
   	  {
   	    n=strlen(s);       
   	    for(i=0;i<n;i++)
   	    {
   	    	if(s[i]==' ')break;
		   }
		 }
		   strncpy(s1,s,i);
		   s1[i]='\0';
		 
		 strncpy(s2,s+i+1,n-i);
	        s2[n-i]='\0';
	        a[s2]=s1;
		 
   }	
 	while(cin>>s2)
 	{
 		if(a[s2]=="")
         printf("eh\n")      // 		cout<<"eh"<<endl;
 		else           printf( %d,a[s2] )          // cout<<a[s2]<<endl;
	 }
	
	 }
	
#endif

//21 U 摞砖问题  ，问移动最少的个数 是 转一样多 

#if 0
#include<iostream>
#include<string.h>
using namespace std;

int main()

{
	int n ,i=0;
	int a[52] ;
	while(cin>> n && n!=0)
{      i++;
        int ave=0 ,sum=0 ; 
 		memset(a,0,sizeof(a)) ;
		for(int i=0; i<n; i++)
		  {
		  cin>>a[i] ;  ave+=a[i] ;
        	}
        	
		  ave/=n ;
		  
		  for(int i=0 ; i<n ;i++)
		  {
		  	if(a[i] <ave) 
		  	sum+= ave-a[i] ;
		  }
cout<<"Set #"<<i<<endl;
cout <<"The minimum number of moves is "<<sum<<"." <<endl<<endl;
}
	
	
}

#endif




// 4 ..。。 
 
#if 0 

#include <stdio.h>  
    #include <iostream>  
    #include <string.h>  
    #include <algorithm>  
    using namespace std;  
    int a[4001][4],sum1[20000002],sum2[20000002];  
    int main()  
    {  
        int n,mid;  
        cin>>n;
            for(int i=0; i<n; i++)  
            {  
                scanf("%d%d%d%d",&a[i][0],&a[i][1], &a[i][2],&a[i][3]);  
            }  
            int k=0;  
            int m=0;  
            for(int i=0; i<n; i++)  
                for(int j=0; j<n; j++)  
                {  
                    sum1[k++]=a[i][0]+a[j][1];  
                    sum2[m++]=a[i][2]+a[j][3];  
                }  
            sort(sum2,sum2+k);  
            int cnt=0;  
            for(int i=0; i<k; i++)  
            {  
                int left=0;  
                int right=k-1;  
                while(left<=right)  
                {  
                    mid=(left+right)/2;  
                    if(sum1[i]+sum2[mid]==0)  
                    {  
                        cnt++;  
                        for(int j=mid+1;j<k;j++)  
                        {  
                            if(sum1[i]+sum2[j]!=0)  
                               break;  
                            else  
                            cnt++;  
                        }  
                        for(int j=mid-1;j>=0;j--)  
                        {  
                            if(sum1[i]+sum2[j]!=0)  
                               break;  
                            else  
                               cnt++;  
                        }  
                        break;  
                    }  
                    if(sum1[i]+sum2[mid]<0)  
                        left=mid+1;  
                    else  
                        right=mid-1;  
                }  
            }  
            cout<<cnt<<endl; 
        return 0;  
    }




#endif 



//5....
#if 1
# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
int N, C, node[100001];

bool Search(int x)
{
    int last = node[1], m = 1;
    for(int i = 2; i <= N; i++)
    {
        if(node[i] - last >= x)
        {
            last = node[i];
            m++;
        }
        if(m >= C)
        return true;
    }

        return false;
}
int main()
{
    cin >> N >> C;
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &node[i]);
    }
    sort(node + 1, node + N + 1);

    int l = node[1], r = node[N];
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;

        if(Search(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;

    return 0;
}


#endif 









//T 

#if 0 

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
int key[4]={0,5,3,1};
int main()
{
    ll box[6];
    ll sum;
    while(1)
    {
        int sum=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%lld", &box[i]);
            sum += box[i];
        }
        if(sum == 0)
            break;

        ll answer = box[6] + box[5] + box[4] + (box[3] + 3)/4;

        ll num2 =box[4]*5 + key[box[3] % 4];
        if(box[2] > num2)
             answer += (box[2] - num2 + 8) / 9;

        ll num1=36*answer-36*box[6]-25*box[5]-16*box[4]-9*box[3]-4*box[2];

        if(box[1] > num1)
            answer += (box[1] - num1 + 35) / 36;

        printf("%lld\n",answer);
    }
    return 0;
}


#endif
































 
