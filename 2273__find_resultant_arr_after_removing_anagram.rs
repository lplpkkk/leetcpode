impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        let mut ans = Vec::new();
        let mut prev = String::new();

        for w in words {
            let mut chars: Vec<char> = w.chars().collect();
            chars.sort_unstable();
            let sorted: String = chars.into_iter().collect();

            if sorted != prev {
                ans.push(w.clone());
                prev = sorted;
            }
        }
        ans
    }
}
