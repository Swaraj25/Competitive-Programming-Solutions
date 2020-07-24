/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
*/


#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int targert){
    vector<int> ans ={-1,-1};
    int start = lower_bound(nums.begin(),nums.end(),targert) - nums.begin();
    int end = upper_bound(nums.begin(),nums.end(),targert) - nums.begin() - 1;
    if((start < nums.size() and end < nums.size()) and 
        (nums.at(start) == targert and nums.at(end) == targert)){
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
    return ans;
}
int main(){
    string input;
    cin>>input;
    stringstream ss(input);
    vector<int> nums;
    while(ss.good()){ // reading the array elements which are seperated by ','
        string substr;
        getline(ss,substr,',');
        nums.push_back(stoi(substr));
    }
    int n;
    // for(int k:nums) cout<<k<<" ";
    cin>>n;
    vector<int> ans;
    ans = searchRange(nums, n);
    for(int k : ans){
        cout<<k<<" ";
    }
}
