string dec_to_hex(int a) //ʮ����ת16���� �ַ��� 
{

	int y=0;//ѭ���е�����
	string s="";//����Ľ��

	if(a==0)//0�Ƚ����⣬��������
	{
	cout<<0;
	return "";
	}
 
	while(a>0)//����0����
	{
		
		y=a%16;  //����
		if(y<10)   //С��10������
		s=char('0'+y)+s;  //�����ַ���ascll�����ַ���ǰ��ƴ��
		else
		s=char('A'-10+y)+s;  //����9��������ABCDE��ʾ
		a=a/16;   
	}
	return s;
}

//16����ת10����

//ʮ��ʮ�����ַ���ת����10���Ƶ����� 

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



//10����ת���� 2����
string fun1(int a)              //ת������ 
{
	string s;
	while(a > 0)
	{
		int temp = a%2;
		s += char('0'+temp);
		a /= 2;
	} 
	return s;                          //�����s�� reverse 
}  
