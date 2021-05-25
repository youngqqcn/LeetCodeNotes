// author: yqq
// date: 2021-05-23 18:49:32
// descriptions: 

struct Solution {}

impl Solution {
    fn three_sum(nums: Vec<i32> , target: i32) -> Vec<Vec<i32>> {
        let mut ns = nums.clone();
        let mut results: Vec<Vec<i32>> = vec![];
        // ns.sort_by(|a, b| a.cmp(b));
        for i in 0..ns.len()  {
            let a = ns[i];
            // if a > 0 {
            //     break;
            // }

            if i > 0 &&  ns[i] == ns[i - 1] {
                continue;
            }
            
            let mut left = i+1;
            let mut right = ns.len()-1;

            while left < right {
                let b = ns[left];
                let c = ns[right];
                if a + b + c > target {
                    right -= 1;
                } else if a + b + c < target {
                    left += 1;
                } else if a + b + c == target{
                    results.push(vec![0/*占位*/, a, b, c]);
                    while left < right && ns[left] == b { 
                        left += 1;
                    }
                    while left < right && ns[right] == c {
                        right -= 1;
                    }
                }

            }
        }
        return results;
    }

    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {

        let mut results: Vec<Vec<i32>> = vec![];
        let mut ns = nums.clone();
        ns.sort_by(|a, b| a.cmp(b));
        if ns.len() < 4 {
            return results;
        }

        for i in 0..ns.len()-3  {
            // 去重
            if i > 0 &&  ns[i] == ns[i - 1] {
                continue;
            }

            let mut ret = Solution::three_sum(ns[i+1..].to_vec(), target - ns[i]);
            for v in ret.iter_mut() {
                v[0] = ns[i];
                results.push(v.clone());
            }
        }
        results
    }
}

fn test( nums: Vec<i32> , target: i32) {
    let results = Solution::four_sum(nums, target);
    println!("{:?}", results);
}

fn main(){
    test(vec![1, 0, -1, 0, -2, 2], 0);
	test(vec![2,2,2,2,2], 8);
    println!("hello world")
}

