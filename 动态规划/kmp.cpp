/*KMP算法 
查询字符串a中 是否包含 字符串b    
ababcabcacbab
abcac
*/
#if 1
#include<iostream>
#include<cstring>
using namespace std;
//笨办法得到next数组 
void getNext(int next[],string s)
{
	memset(next,0,sizeof(next));
	for(int i=0; i<s.size(); i++)
	{
		int ans = 0;
		
		string str = s.substr(0,i+1);
		for(int j=0; j<str.size()-1; j++)
		{
			string str1 = str.substr(0,j+1);			
			string str2 = str.substr(str.size()-j-1,str.size());
			if(str1==str2)
			{
				ans = j+1;
			}
		
		}
		
		next[i] = ans;
	}
} 
 //a 是主字符串   b是小字符串 
int kmp(string a,string b,int next[])
{
	
	int n = a.size() , i = 0;           //主字符串的长度，主字符串的下标 
	int m = b.size() , j = 0;			//小字符串的长度，已经匹配的个数 
	
	while(i < n) 
	{
		
		if(j==0)                       //如果小字符串中的第一个元素没有找到与大字符串中有匹配的，那就寻找===  
		{
			if(a[i] == b[j])
			{
				j++;                                      //已经匹配的个数 
			}
			else
			{
				i++;									 //主字符串的 下标 
			}
		}else{                        //已经有匹配的了 
				if(a[i+1] != b[j])    //如果不下一个字符不相等，那就移动小字符串，这个过程操作起来就是更改小字符串的下标。 
				{
					j = next[j-1];
				}	
		
				if(a[i+1] == b[j])  //如果相等那就比较下一个字符 
				{
					i++;
					j++;
				
			    }
		}
		
		if(j == m)                    //如果小字符串全比较完了，那就是全匹配了，完成！ 否则大字符串中不存在 小字符串！ 
			return i;                //这里返回小字符串在大字符串中最后匹配成功的字符的下标 
	}
	return 0;	
}

int main()
{
	int next[1000];
	string a = "BBC ABCDAB ABCDABCDABDE";

	string b = "ABCDABD";
	
	getNext(next,b);
	

	cout<<"kmp:"<<kmp(a,b,next)<<endl;	
}
 
#endif 


//求next数组
/*
ababc

*/

#if 0
#include<iostream>
#include<cstring>
using namespace std;
void getnext(string s,int next[])
{
	int n = s.size();
//
//	for(int i=1; i<n; i++)
//	{
//		if(s[i] == s[next[i-1]])
//			next[i] = next[i-1] + 1;
//	}
	
	memset(next,0,sizeof(next));
	int k = 0;                      //k代表 最大前后缀长度 
	for(int i = 1,k = 0; i<n; i++)
	{
		while(k>0 && s[k] != s[i])
		{
			k = next[k-1];	
		} 
		
		if(s[i] == s[k])
		{
			k++;
		}
		next[i] = k;
	}

	
}
int main()
{
	int next[100];
	memset(next,0,sizeof(next));
//	string s = "ABCDABD";
//	string s = "ababc";
//	string s = "abcdabcefabcd";
	string s = "abadabab";
	int n = s.size();
	getnext(s,next);
	for(int i=0; i<n; i++)
	{
		cout<<next[i]<<" "; 
	}
}
#endif 







