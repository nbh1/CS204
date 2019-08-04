#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3;
	s3="";
	cin>>s1>>s2;
	char v='0';
	if (s1.size()<s2.size())
	{
		swap(s1,s2);
	}

	while(s1.size()!=s2.size()){
		s2.insert(0,"0",1);
	}
	//	cout<<s1<<" "<<s2<<endl;
	for(int i=s1.size()-1;i>=0;i--){
	
		if(((int)(s1[i]-'0'))<((int)(s2[i]-'0'))){
			s1[i]=(char)(((int)(s1[i]-'0')+10)+(int)v);
			s1[i-1]=(char)(((int)(s1[i-1]-'0')-1)+(int)v);

		}
          s3.push_back((char)((int)(s1[i]-'0')-(int)(s2[i]-'0'))+(int)v);
          
	}
	reverse(s3.begin(),s3.end());
	cout<<s3<<endl;
	return 0;
}