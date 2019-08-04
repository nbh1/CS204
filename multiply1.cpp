#include <iostream>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int y=0;y<t;++y)
  {
  string s1,s2;
  cin>>s1>>s2;
  if(s1[0]=='0'||s2[0]=='0')
  {
    cout<<"0";
    return 0;
  }
  vector<int>v1,v2;
  for(int i=0;i<s1.size();i++)
    v1.push_back(s1[i]-48);
  for(int i=0;i<s2.size();i++)
    v2.push_back(s2[i]-48);
  reverse(v1.begin(),v1.end());
  reverse(v2.begin(),v2.end());
  if(v1.size()<v2.size())
    swap(v1,v2);
    vector<int>v3(v1.size()+v2.size(),0);
    int carry =0;
    for(int i=0;i<v2.size();i++)
    {
      carry=0;
      for(int j=0;j<v1.size();j++)
      {
        int num = v3[i+j]+v1[j]*v2[i]+carry;
        v3[i+j]=num%10;
         if(num/10==0)
          carry=0;
        else 
          carry = num/10;
      }
      if(carry!=0)
      {
        v3[i+v1.size()]+=carry;
      }
    } 
    reverse(v3.begin(),v3.end());
    int i=0;
    for(i=0;i<v3.size();i++)
    {
      if(v3[i]!=0)
        break;
    }
    for(int j=i;j<v3.size();j++)
      cout<<v3[j];
    cout<<endl;
  }
}