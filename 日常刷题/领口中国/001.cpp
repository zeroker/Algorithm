//dp 64 最小路径和
//   https://leetcode-cn.com/problems/minimum-path-sum/submissions/ 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	    int n,m;
	    cin>>n>>m;
	    int a[n][m];
	    for(int i=0; i<n; i++)
	    	for(int j=0; j<m; j++)
	    		cin>>a[i][j];
		for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                int x1 = 0x7f;
                int x2 = 0x7f;
                bool flag1 = 0;
                bool flag2 = 0;
                if(i+1<n)
                {
                    x1 = a[i+1][j];
                    flag1 = 1;
                }
                if(j+1<m)
                {
                    x2 = a[i][j+1];
                    flag2 = 1;
                }
                if(flag1 && flag2)
                    a[i][j] += min(x1,x2);
                else if(flag1 && !flag2)
                    a[i][j] += x1;
                else if(flag2 && !flag1)
                    a[i][j] += x2;
            }
        }
        return a[0][0];
}

#endif 
