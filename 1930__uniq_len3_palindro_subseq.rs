/*
impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut s_b=s.as_bytes();
        let first_char=vec![-1;26];
        let last_char=vec![-1;26];
        let mut ans=0;
        let len=s_b.len();

        for i in 0..len{
            if first_char[s_b[i]-'a']==-1{
                first_char[s_b[i]-'a']=i;
            }
            last_char[s_b[i]-'a']=i;
        }

        for i in 0..26{
            if last_char[i]>first_char[i]{
                let hs=HashSet::new();
                for j in (first_char[i]+1)..last_char[i]{
                    if !hs.contains(s_b[j]){
                        ans+=1;
                    }
                }
            }
        }
        ans
    }
}
*/
use std::collections::HashSet;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let s_b = s.as_bytes();
        let mut first_char = vec![-1; 26]; // 使用 mut 讓它可以被修改
        let mut last_char = vec![-1; 26]; // 使用 mut 讓它可以被修改
        let mut ans = 0;
        let len = s_b.len();

        for i in 0..len {
            let char_idx = (s_b[i] - b'a') as usize; // 將 char 轉換為索引
            if first_char[char_idx] == -1 {
                first_char[char_idx] = i as i32; // 存儲索引
            }
            last_char[char_idx] = i as i32; // 存儲索引
        }

        for i in 0..26 {
            if last_char[i] > first_char[i] {
                let mut hs = HashSet::new(); // HashSet 需要 mutable
                for j in (first_char[i] + 1) as usize..last_char[i] as usize { // 範圍也需要轉換為 usize
                    hs.insert(s_b[j]); // 插入 u8
                }
                ans += hs.len() as i32; // 將 HashSet 的大小加到 ans
            }
        }
        ans
    }
}
