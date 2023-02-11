//
// Created by wh on 23-2-7.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
struct Solution {
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2 ){
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(),nums1.end());
        for(int num : nums2){
            if (nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }
//         使用迭代器 iterator 访问值
//        unordered_set<int>::iterator v = result_set.begin();
//        while( v != result_set.end()) {
//            cout << "value of v = " << *v << endl;
//            v++;
//        }

        vector<int> result(result_set.begin(), result_set.end());
        return result;

    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,2,3,4,3,6,2,1}, nums2 = {3,3,1};
    vector<int> result = solution.intersection(nums1,nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

