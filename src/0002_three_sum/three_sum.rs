/*
date: 2021-05-22 20:25
author: yqq
descriptions: 

*/

struct Solution{}

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ns = nums.clone();
        let mut results: Vec<Vec<i32>> = vec![];
        ns.sort_by(|a, b| a.cmp(b));
        for i in 0..ns.len()  {
            let a = ns[i];
            if a > 0 {
                break;
            }

            if i > 0 &&  ns[i] == ns[i - 1] {
                continue;
            }
            
            let mut left = i+1;
            let mut right = ns.len()-1;

            while left < right {
                let b = ns[left];
                let c = ns[right];
                if a + b + c > 0 {
                    right -= 1;
                } else if a + b + c < 0 {
                    left += 1;
                } else if a + b + c == 0{
                    results.push(vec![a, b, c]);
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
}


fn test(nums: Vec<i32> ) {
    let ret = Solution::three_sum(nums);
    for it in ret.iter() {
        print!("{:?}   ", it);
    }
    println!("\n=========\n");
}

fn main(){
    test(vec![-1, 0, 1, 2, -1, -4]);
    test(vec![3, 0, -2, -1, 1, 2]);
    test(vec![1, 2, -2, -1]);
    test(vec![-1,0,1,2,-1,-4,-2,-3,3,0,4]);
    println!("hello world")
}