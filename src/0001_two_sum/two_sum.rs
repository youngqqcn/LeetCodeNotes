

// Author: yqq
// Date: 2021-05-20 17:01:07
// Description: 两数之和

struct Solution {}
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut maps: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            let search = target - nums[i];
            let n = i as i32;
            if  maps.contains_key(&search){
                return vec![maps[&search] , n];
            }
            maps.insert(nums[i], n);
        }
        return vec![];
    }
}


fn main() {
    // let sl = Solution{};
    let ret = Solution::two_sum(vec![1, 3, 5, 7, 8], 15);
    assert_eq!(vec![3, 4], ret);

    let ret = Solution::two_sum(vec![1, -1, 5, 7, 8], 4);
    assert_eq!(vec![1, 2], ret);

    println!("test passed");
}