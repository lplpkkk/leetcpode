use std::collections::{HashMap,BTreeSet};
use std::cmp::Ordering;

struct FoodInfo{
    cuisine:String,
    rating:i32,    
}

#[derive(Eq,PartialEq)]
struct FoodKey{
    food:String,
    rating:i32,
}

impl Ord for FoodKey{
    fn cmp(&self,other:&Self) -> std::cmp::Ordering{
        other.rating.cmp(&self.rating).then_with(|| self.food.cmp(&other.food))
    }
}

impl PartialOrd for FoodKey{
    fn partial_cmp(&self,other:&Self) ->Option<Ordering>{
        Some(self.cmp(other))
    }
}

struct FoodRatings {
    /* food -> <cuisine,rating> */
    food_map:HashMap<String,FoodInfo>,
    /* cuisine -> btree for searching the highest score */
    rating_food:HashMap<String,BTreeSet<FoodKey>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings {

    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut  food_map:HashMap<String,FoodInfo>=HashMap::new();
        let mut  rating_food:HashMap<String,BTreeSet<FoodKey>>=HashMap::new();

        for i in 0..foods.len(){
            let food_ref=&foods[i];
            let cuisine_ref=&cuisines[i];
            let rating=ratings[i];

            food_map.insert(food_ref.clone(),FoodInfo{
                cuisine:cuisine_ref.clone(),
                rating:rating,
            });

            rating_food
                .entry(cuisine_ref.clone()).or_default().insert(FoodKey{food:food_ref.clone(),rating});
        }

        FoodRatings{
            food_map,
            rating_food,
        }
    }
    
    fn change_rating(&mut self, food: String, new_rating: i32) {
        if let Some(food_info) = self.food_map.get_mut(&food){
            let old_config=food_info.rating;
            let cuisine=food_info.cuisine.clone();
            
            if let Some(set)=self.rating_food.get_mut(&cuisine){
                set.remove(&FoodKey{
                    food:food.clone(),
                    rating:old_config,
                });
            }

            food_info.rating=new_rating;
            if let Some(set)=self.rating_food.get_mut(&cuisine){
                set.insert(FoodKey{
                    food:food.clone(),
                    rating:new_rating,
                });
            }
        }
    }
    
    fn highest_rated(&self, cuisine: String) -> String {
        if let Some(set)=self.rating_food.get(&cuisine){
            if let Some(food_key)=set.iter().next(){
                return food_key.food.clone();
            }
        }
        String::new()
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * let obj = FoodRatings::new(foods, cuisines, ratings);
 * obj.change_rating(food, newRating);
 * let ret_2: String = obj.highest_rated(cuisine);
 */
