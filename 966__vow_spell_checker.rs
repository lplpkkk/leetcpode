use std::collections::HashSet;
use std::collections::HashMap;

impl Solution {
    pub fn devow(s:&str) ->String{
        s.chars()
            .map(|c| match c{
                'a'|'e'|'i'|'o'|'u' => '*',
                _ => c,
            })
            .collect()
    }

    pub fn spellchecker(wordlist: Vec<String>, queries: Vec<String>) -> Vec<String> {
        let mut exact: HashSet<String>=HashSet::new();
        let mut case_insens: HashMap<String,String>=HashMap::new();
        let mut vow_insens:HashMap<String,String>=HashMap::new();

        for w in &wordlist{
            exact.insert(w.clone());
            let lower=w.to_lowercase();
            case_insens.entry(lower.clone()).or_insert(w.clone());
            let dev=Self::devow(&lower);
            vow_insens.entry(dev).or_insert(w.clone());
        }

        queries.into_iter()
            .map(|q|{
                if exact.contains(&q){
                    q
                }else{
                    let lower=q.to_lowercase();
                    if let Some(ans)=case_insens.get(&lower){
                        ans.clone()
                    }else{
                        let dev=Self::devow(&lower);
                        if let Some(ans)=vow_insens.get(&dev){
                            ans.clone()
                        }else{
                            "".to_string()
                        }                       
                    }
                }
            }).collect()
    }
}
