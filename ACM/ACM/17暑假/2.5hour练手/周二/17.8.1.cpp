//1.
/*
A. The Useless Toy
Walking through the streets of Marshmallow City, Slastyona have spotted some merchants selling a kind of useless toy which is very popular nowadays – caramel spinner! Wanting to join the craze, she has immediately bought the strange contraption.

Spinners in Sweetland have the form of V-shaped pieces of caramel. Each spinner can, well, spin around an invisible magic axis. At a specific point in time, a spinner can take 4 positions shown below (each one rotated 90 degrees relative to the previous, with the fourth one followed by the first one):


After the spinner was spun, it starts its rotation, which is described by a following algorithm: the spinner maintains its position for a second then majestically switches to the next position in clockwise or counter-clockwise order, depending on the direction the spinner was spun in.

Slastyona managed to have spinner rotating for exactly n seconds. Being fascinated by elegance of the process, she completely forgot the direction the spinner was spun in! Lucky for her, she managed to recall the starting position, and wants to deduct the direction given the information she knows. Help her do this.

Input
There are two characters in the first string – the starting and the ending position of a spinner. The position is encoded with one of the following characters: v (ASCII code 118, lowercase v), < (ASCII code 60), ^ (ASCII code 94) or > (ASCII code 62) (see the picture above for reference). Characters are separated by a single space.

In the second strings, a single number n is given (0?≤?n?≤?109) – the duration of the rotation.

It is guaranteed that the ending position of a spinner is a result of a n second spin in any of the directions, assuming the given starting position.

Output
Output cw, if the direction is clockwise, ccw – if counter-clockwise, and undefined otherwise.

Examples
input
^ >
1
output
cw
input
< ^
3
output
ccw
input
^ v
6
output
undefined

*/

//题意：
/*
有四个方向，给出两个方向，再给出旋转的次数，输出是顺时针旋转的，还是逆时针旋转的。 
cw顺时针，ccw逆时针 
*/ 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c,cr;
	int a,b,k;

	cin>>c>>cr>>k;
	
	if(c=='^')
		a=1;
	else 
	if(c=='>')
		a=2;
	else
	if(c=='v')
		a=3;
	else
	if(c=='<')
		a=4;			
    
    if(cr=='^')
		b=1;
	else 
	if(cr=='>')
		b=2;
	else
	if(cr=='v')
		b=3;
	else
	if(cr=='<')
		b=4;	

    if(k%2==0)
     	cout<<"undefined"<<endl;
    else	
    if((a==1&&b==2)||(a==2&&b==3)||(a==3&&b==4)||(a==4&&b==1))
	{
		if(k%4==1)
		cout<<"cw"<<endl;
		else
		if(k%4==3)
			cout<<"ccw"<<endl; 
	
    } 	
    else
    if((a==2&&b==1)||(a==3&&b==2)||(a==4&&b==3)||(a==1&&b==4))
    {
    	if(k%4==1)
    		cout<<"ccw"<<endl;
    	else
    	if(k%4==3)
			cout<<"cw"<<endl;
	
	}

}
#endif



//2. 守卫问题 


/*
It's the end of July?– the time when a festive evening is held at Jelly Castle! Guests from all over the kingdom gather here to discuss new trends in the world of confectionery. Yet some of the things discussed here are not supposed to be disclosed to the general public: the information can cause discord in the kingdom of Sweetland in case it turns out to reach the wrong hands. So it's a necessity to not let any uninvited guests in.
There are 26 entrances in Jelly Castle, enumerated with uppercase English letters from A to Z. Because of security measures, each guest is known to be assigned an entrance he should enter the castle through. The door of each entrance is opened right before the first guest's arrival and closed right after the arrival of the last guest that should enter the castle through this entrance. No two guests can enter the castle simultaneously.
For an entrance to be protected from possible intrusion, a candy guard should be assigned to it. There are k such guards in the castle, so if there are more than k opened doors, one of them is going to be left unguarded! Notice that a guard can't leave his post until the door he is assigned to is closed.
Slastyona had a suspicion that there could be uninvited guests at the evening. She knows the order in which the invited guests entered the castle, and wants you to help her check whether there was a moment when more than k doors were opened.
Input
Two integers are given in the first string: the number of guests n and the number of guards k (1?≤?n?≤?106, 1?≤?k?≤?26).
In the second string, n uppercase English letters s1s2... sn are given, where si is the entrance used by the i-th guest.
Output
Output ?YES? if at least one door was unguarded during some time, and ?NO? otherwise.
You can output each letter in arbitrary case (upper or lower).
Examples
Input
5 1
AABBB
Output
NO
Input
5 1
ABABB
Output
YES
*/


/*
题意：
可以谷歌出来题意很清晰。 
思路 ：
枚举每一个时间点求公用的交叉段的个数，然后求出最大的个数，与守卫的个数来比较 。 
*/ 
#if 0
#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	int t[30][2],n,gar,num=0,max=0;
	
	char c[1000006] ;
 	cin>>n>>gar;
	
	for(int i=0; i<n; i++)
		cin>>c[i];
	
	while(num!=n)	
	{
		int k1,k2;
		char cc; 
		
		for(int i=0; i<n; i++)
		{
		 if(c[i]!='0')
		 {
		 	cc=c[i];
		 	k1=i;
		 	t[ans++][0]=i;
			break;
		 }
		}
		
		for(int i=n-1; i>=0; i--)
		{
			if(c[i]==cc)
			{
				k2=i;
				t[ans-1][1]=i;
				break;
			}
		}
		
		for(int i=k1; i<=k2; i++)
		{
			if(c[i]==cc)
			{
				num++;
				c[i]='0';
			}
		}
		
	}
	
	
	for(int i=0; i<n; i++)
	{ 	
		int cnt=0;
		for(int j=0; j<ans; j++)
		{
			if(t[j][0]<=i && t[j][1]>=i)
			{
				cnt++;
			}
		}
		
		if(cnt>max)
			max=cnt;
	}
	
	if(max>gar)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
	
}
#endif
























































