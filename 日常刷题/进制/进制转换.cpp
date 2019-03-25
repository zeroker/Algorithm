string dec_to_hex(int a) //十进制转16进制 字符串 
{

	int y=0;//循环中的余数
	string s="";//输出的结果

	if(a==0)//0比较特殊，单独处理
	{
	cout<<0;
	return "";
	}
 
	while(a>0)//大于0的数
	{
		
		y=a%16;  //求余
		if(y<10)   //小于10的余数
		s=char('0'+y)+s;  //利用字符的ascll码在字符串前面拼接
		else
		s=char('A'-10+y)+s;  //大于9的余数用ABCDE表示
		a=a/16;   
	}
	return s;
}

//16进制转10进制

//十六十进的字符串转化成10进制的整数 

string s = "abcdef";
int size = s.size(); 
for(int i=size-1; i>=0; i--)
{
	if(s[i] >= 'a' && s[i] <='f')
	{
		int temp = s[i] - 'a' + 10;
		result += temp*pow(16,size-i-1);
	}
	else
	if(s[i] >= 'A' && s[i] <='F')
	{
		int temp = s[i] - 'A' + 10;
		result += temp*pow(16,size-i-1);
	}
	else if(s[i] >= '0' && s[i] <= '9')
	{
		int temp = s[i] - '0';
		result += temp*pow(16,size-i-1);
	}
//		cout<<result<<endl;
}



//10进制转换成 2进制
string fun1(int a)              //转二进制 
{
	string s;
	while(a > 0)
	{
		int temp = a%2;
		s += char('0'+temp);
		a /= 2;
	} 
	return s;                          //结果是s的 reverse 
}  
