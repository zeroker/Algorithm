//本来打算早起打比赛的，起不来啊！！！！！ 一道水体，不想解释！！！ 发现c++的许多炉火纯青的语法都忘却了！！！补课！ 
#if 0
#include<bits/stdc++.h>
using namespace std;                                                                                                                      

string get(string s)
{
		string strf;               
		string end;
        for(int i=0; i<s.size(); i++)
        {
        	strf += 'a';
		}
//		cout<<strf<<endl;
		string mid;
		for(int i=0; i<s.size(); i++)
        {
            
            if( ('a'<= s[i] && s[i]<= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
            { 
				mid += s[i];
            }else
            {
				strf[i] = s[i];
            }
        }
       	reverse(mid.begin(),mid.end());
//       	cout<<mid<<endl;
       	
       	int j=0;
        for(int i = 0 ;i <s.size(); i++)
        {
            if(strf[i] != 'a')
            {
            	end += strf[i];                     //符号！ 
//            	cout<<end[i]<<endl;
			}
            else
            {
            	end += mid[j++]; 
			}
        }
        
        return end;
}
int main()
{
	string s = "Test1ng-Leet=code-Q!";
	string ss = get(s);
	cout<<ss<<endl;
	
}
#endif 
// 


//求环形子数组最大 和         （最大字段和的变形）
//求n点最大字段和  时间复杂度为 n^2  果然超时 
#if 1 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getmax(vector<int> &v)
{
		int n = v.size();
        int endmax = v[0];
        int curmax = v[0];
		if(curmax < 0)
			  curmax = 0;

    	for(int i=1; i<n; i++)
		{
			if(curmax + v[i] < 0)
				curmax = v[i];
			else
				curmax += v[i];
			if(curmax > endmax)
				endmax = curmax;
			if(curmax < 0)
				curmax = 0;
     	}
        
        return endmax;	
} 
int getmin(vector<int> &v)
{
		int n = v.size();
        int endmin = v[0];
        int curmin = v[0];
		if(curmin > 0)
			  curmin = 0;

    	for(int i=1; i<n; i++)
		{
			if(curmin + v[i] > 0)
				curmin = v[i];
			else
				curmin += v[i];
			if(curmin < endmin)
				endmin = curmin;
			if(curmin > 0)
				curmin = 0;
     	}
        
        return endmin;	
} 
int main() 
{
	vector<int> v;
//	v.push_back(1);
//	v.push_back(-2);
//	v.push_back(3);
//	v.push_back(-2);
//
//	v.push_back(5);
//	v.push_back(-3);
//	v.push_back(5);
	
//	v.push_back(3);
//	v.push_back(-1);
//	v.push_back(2);
//	v.push_back(-1);
//	cout<<v.size()<<endl;
//	v.push_back(3);
//	v.push_back(-2);
//	v.push_back(2);
//	v.push_back(-3);

	v.push_back(-2);
	v.push_back(-3);
	v.push_back(-1);
////	v.push_back(-1);
//	v.push_back(1);
//	v.push_back(-6);
//	v.push_back(-7);
//	v.push_back(4);
	cout<<getmax(v)<<endl;
	cout<<getmin(v)<<endl;
	
}
#endif 








 

