#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 

	map<int, int> mp; 

	// Adding some elements in mp 
	mp[1] = 10; 
	mp[2] = 20; 
	mp[3] = 30; 

	cout << "Contents of mp before deleting"
		" the last element :\n"; 
	for (auto it = mp.begin(); it != mp.end(); it++) 
		cout << it->first << " ==> "
			<< it->second << "\n"; 

	cout << "Deleting the last element from"
		" the map.\n"; 
	mp.erase(prev(mp.end())); 

	cout << "Contents of mp after deleting the last"
			" element :\n"; 
	for (auto it = mp.begin(); it != mp.end(); it++) 
		cout << it->first << " ==> "
			<< it->second << "\n"; 
} 
