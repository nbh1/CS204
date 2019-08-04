#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str1,str2,str3;
	str3="";
	cin>>str1>>str2;
	if(str1.size()<str2.size()){
		swap(str1,str2);
	}
	while(str1.size()!=str2.size()){
        str2.insert(0,"0",1);
	}
	int carry=0;

	for(int i=(str1.size()-1);i>=0;i--){
       int s,t;
       t=(int)(str1[i]-'0')+(int)(str2[i]-'0')+carry;
       carry= t/10;
       s=t%10;
       char v='0';
       str3.push_back((char)(s+(int)v)); 
      
	} 
	if(carry==1){
	    str3.push_back('1');
	}
	 reverse(str3.begin(),str3.end());
	cout<<str3<<endl;
	return 0;
}
