// author: yqq
// date: 2021-05-25 15:54:09
// descriptions: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

struct Solution {}

impl Solution {

    fn backtracking(digits: &Vec<char>, index: i32, combstr: &mut String, results: &mut Vec<String> , letter_map: &Vec<&str>) {
        if index == (digits.len() as i32) {
            results.push(combstr.clone());
            return;
        }

        let idx:usize = ((digits[index as usize]) as usize) - ('0' as usize);
        let letters = letter_map[idx];

        for ch in letters.chars(){
            combstr.push(ch);
            Solution::backtracking(digits, index + 1, combstr, results, letter_map);
            combstr.pop();
        }
    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        let letter_map = vec![
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
        ];

        if 0 == digits.len() {
            return vec![];
        }

        // 为了方便起见,我们转为chars
        let digits_chars: Vec<char> = digits.chars().collect();


        let mut results: Vec<String> = vec![] ;
        let mut combstr:String  = String::from("");
        Solution::backtracking(&digits_chars, 0, &mut combstr, &mut results, &letter_map);
        return results;
    }
}

fn test() {
    let results = Solution::letter_combinations(String::from("23"));
    for x in results.iter() { 
        print!("{:?}", x);
    }
    println!("");
}

fn main(){
    // let s = String::from("love: ❤️");
    // let v: Vec<char> = s.chars().collect();
    // println!("{:?}", v[0] );

    test();
    println!("hello world");
}

