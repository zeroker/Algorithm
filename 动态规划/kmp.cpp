/*KMP�㷨 
��ѯ�ַ���a�� �Ƿ���� �ַ���b    
ababcabcacbab
abcac
*/
#if 1
#include<iostream>
#include<cstring>
using namespace std;
//���취�õ�next���� 
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
 //a �����ַ���   b��С�ַ��� 
int kmp(string a,string b,int next[])
{
	
	int n = a.size() , i = 0;           //���ַ����ĳ��ȣ����ַ������±� 
	int m = b.size() , j = 0;			//С�ַ����ĳ��ȣ��Ѿ�ƥ��ĸ��� 
	
	while(i < n) 
	{
		
		if(j==0)                       //���С�ַ����еĵ�һ��Ԫ��û���ҵ�����ַ�������ƥ��ģ��Ǿ�Ѱ��===  
		{
			if(a[i] == b[j])
			{
				j++;                                      //�Ѿ�ƥ��ĸ��� 
			}
			else
			{
				i++;									 //���ַ����� �±� 
			}
		}else{                        //�Ѿ���ƥ����� 
				if(a[i+1] != b[j])    //�������һ���ַ�����ȣ��Ǿ��ƶ�С�ַ�����������̲����������Ǹ���С�ַ������±ꡣ 
				{
					j = next[j-1];
				}	
		
				if(a[i+1] == b[j])  //�������ǾͱȽ���һ���ַ� 
				{
					i++;
					j++;
				
			    }
		}
		
		if(j == m)                    //���С�ַ���ȫ�Ƚ����ˣ��Ǿ���ȫƥ���ˣ���ɣ� ������ַ����в����� С�ַ����� 
			return i;                //���ﷵ��С�ַ����ڴ��ַ��������ƥ��ɹ����ַ����±� 
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


//��next����
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
	int k = 0;                      //k���� ���ǰ��׺���� 
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







