#if 1
#include<bits/stdc++.h>
using namespace std;
bool isLongPressedName(string name, string typed) 
{
    char ch = name[0];
        int num = 1;
        int j = 0; 
        bool flag = 0;
        
        for(int i=1; i<name.size(); i++)
        {
            if(ch != name[i])
            {
            	cout<<"num:"<<num<<endl;
                int num1 = 0;
                while(ch == typed[j])
                {
                    num1++;
                    j++;
                }
                cout<<"num1:"<<num1<<endl;
                if(num1<num) 
                    flag = 1;              //´íÎó
                ch = name[i];
                num = 1;
            }else{
                num++;
            }
        }
        
        if(flag)
            return 0;
        return 1;    
        
}
int main()
{
	cout<<isLongPressedName("saeed","ssaaedd")<<endl;
}
#endif 
