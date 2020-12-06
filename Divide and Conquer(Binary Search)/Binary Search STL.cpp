#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] = {20,30,40,40,40,50,100,1100};
	int n = sizeof(arr)/sizeof(int);
	int key = 40;

	//binary_search: returns true or false
	bool present = binary_search(arr,arr+n,key);
	cout << present << endl;

	//lower_bound: returns address of first number >= key
	auto lb = lower_bound(arr,arr+n,40);
	cout << (lb-arr) << endl;

	//upper_bound: return address of first number > key
	auto up = upper_bound(arr,arr+n,40);
	cout << (up-arr) << endl;

	//up-lb gives the frequency of that number in the array
	cout << up-lb << endl;
}