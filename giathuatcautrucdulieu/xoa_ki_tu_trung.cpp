#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cout<<"Nhap xau: "; cin>>s;
	int danhdau[123]{};
	
	for (int i=0;i<=s.size();)
	{
		if(danhdau[s[i]]==0)
		{
			danhdau[s[i]]++;
			i++;
			
		}
		else if (danhdau[s[i]]>0)
		{ 
		
		s.erase(s.begin()+i,s.begin()+i+1);
		}
	}
	cout<<s<<" ";
	return 0;
}
