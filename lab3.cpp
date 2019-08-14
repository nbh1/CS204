#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
  for(int i=0;i<n;i++){
    string s1,s2;
    cin>>s1;
    int counter=0;
     int flag=0;
   for(int j=0;j<(s1.size());j++){
     
   	if(s1[j]=='(' || s1[j]=='{' || s1[j]=='[' || s1[j]=='<'){
   		s2.push_back(s1[j]);
   		counter=counter+1;
   	}
   	else if(s1[j]=='|'){
      if(flag==0){
      	s2.push_back(s1[j]);
      	counter=counter+1;
      }
      if(s2[s2.size()-1]=='|'){
      	s2.pop_back();
      	counter=counter-1;
      }
      else {
      	printf("NO" );
      	break;
      }

      
   	}
   	else  {
   		if(s1[j]==')' && s2[s2.size()-1]=='('){
   		s2.pop_back();
   		counter=counter-1;
   	   }
   	   if(s1[j]=='}' && s2[s2.size()-1]=='{'){
   		s2.pop_back();
   		counter=counter-1;
   	   }
   	   if(s1[j]==']' && s2[s2.size()-1]=='['){
   		s2.pop_back();
   		counter=counter-1;
   	   }
   	   if(s1[j]=='>' && s2[s2.size()-1]=='<'){
   		s2.pop_back();
   		counter=counter-1;
   	   }
         
   }
   }
   if(counter==0)
   		printf("YES");
   	else
   		printf("NO");
  }





	return 0;
}