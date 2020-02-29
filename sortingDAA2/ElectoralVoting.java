#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	string votes[] = { "john", "johnny", "jackie", 
						"johnny", "john", "jackie", 
						"jamie", "jamie", "john", 
						"johnny", "jamie", "johnny", 
						"john" }; 
	
		// map to store count of frequency of each name 
		map<string,int>mp; 
		
		// storing the frequency of names in the map 
		for(string s:votes) 
		{ 
			mp[s]++; 
		} 
		
		int maxx = -1; 
		string answer=""; 
		
		// Iterating through the map to find the name with highest frequency 
		for(auto it=mp.begin();it!=mp.end();it++) 
		{ 
			if(it->second>maxx) 
			{ 
				maxx=it->second; 
				answer=it->first; 
			} 

		} 
		
		cout<<answer<<endl; 

	return 0; 
} 
