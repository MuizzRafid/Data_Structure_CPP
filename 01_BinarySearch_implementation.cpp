#include<bits/stdc++.h>
using namespace std;


bool implementingBs(vector<int> &v,int low, int high ,int target){

	if(low>high){
		return false;
	}

	int mid=((high-low)/2)+low;
	if(v[mid]==target)return true;

	if(v[mid]>target){
		return implementingBs(v,low,mid-1,target);
	}

	return implementingBs(v,mid+1,high,target);

}









int main(){
vector<int> v={1,2,5,6,8,9,11};

bool result= implementingBs(v,0,v.size()-1,10);
cout<<result<<endl;

}