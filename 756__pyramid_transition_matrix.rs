use std::collections::{HashMap,HashSet};

impl Sol{
	pub fn py(bottom: String, allowed: Vec<String>)-> bool{
		let mut rules=HashMap::new();
		for s in allowd{
			let b=s.as_bytes();
			rules.entry((b[0],[1])).or_insert(Vec::new()).push(b[2]);
		}

		let mut failed_memo=HashSet::new();
		Self::dfs(bottom.as_bytes().to_ver(),&rules,&mut failed_memo)
	}

	fn dfs(cur_row:Vec<u8>, 
			rules:&HashMap<(u8,u8),Vec<u8>>,
			failed_memo: &HashSet<Vec<u8>>)->bool{
		if cur_row.len()==1{
			return true;
		}

		if failed_memo.contains(&cur_row){
			return false;
		}

		let mut next_row=Vec::with_capacity(cur_row.len()-1);
		if Self::build_next_level(&cur_row,&next_row,0,rules,failed_memo){
			return true;
		}

		failed_memo.insert(cur_row);
		false
	}

	fn build_next_level(cur_row:&Vec<u8>,
						next_row:&Vec<u8>,
						col:usize,
						rules:&HashMap<(u8,u8),Vec<u8>>,
						failed_memo:&HashSet<Vec<u8>>
		)->bool{
			if col==cur_row.len()-1{
				return Self::dfs(next_row.clone(),rules,failed_memo);
			}

			let pair=(cur_row[col],cur_row[col+1]);
			if let Some(options)=rules.get(&pair){
				for &c in options{
					next_row.push(c);
					if Self::build_next_level(cur_row,next_row,col+1,rules,failed_memo){
						return true;
					}
					next_row.pop();
				}
			}
			false
	}	
}
