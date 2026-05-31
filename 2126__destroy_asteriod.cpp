class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long mass_ll=(long long )mass;
        sort(asteroids.begin(),asteroids.end());

        for(auto & a:asteroids){
            if(mass_ll<a){
                return false;
            }
            
            if(mass_ll+a>INT_MAX){
                mass_ll=INT_MAX;
            }else{
                mass_ll+=a;
            }
            
        }
        return true;
    }
};
