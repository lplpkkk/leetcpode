


use std::collections::HashMap;

struct Spreadsheet {
    cells: HashMap<String,i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Spreadsheet {

    fn new(rows: i32) -> Self {
        Spreadsheet{
            cells:HashMap::new(),
        }
    }
    
    fn set_cell(&mut self, cell: String, value: i32) {
        self.cells.insert(cell,value);
    }
    
    fn reset_cell(&mut self, cell: String) {
        self.cells.remove(&cell);
    }
    
    fn get_value(&self, formula: String) -> i32 {
        let formula_str=&formula[1..];//still string
        let parts:Vec<&str>=formula_str.split('+').collect();
        let mut sum=0;

        for part in parts{
            if part.chars().next().unwrap().is_ascii_alphabetic(){
                let val=self.cells.get(part).unwrap_or(&0);
                sum+=val;
            }else{
                let val=part.parse::<i32>().unwrap();
                sum+=val;
            }
        }
        sum
    }
}


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * let obj = Spreadsheet::new(rows);
 * obj.set_cell(cell, value);
 * obj.reset_cell(cell);
 * let ret_3: i32 = obj.get_value(formula);
 */
