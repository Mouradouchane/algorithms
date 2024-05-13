
#include <vector>
#include <iostream>

#define value int
#define index int

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int>& arr) {
    
    int swaps = 0;
    
    std::vector<std::pair<value , index>> pairs;
    
    // store elements in pair
    for(size_t i = 0 ; i < arr.size() ; i += 1 ){
        
        pairs.push_back( 
            std::pair<value,index>{ arr[i],i } 
        );
        
    }
    
    // sort pairs by values
    std::sort(pairs.begin() , pairs.end() , 
        [&](
            std::pair<value,index> const& a ,
            std::pair<value,index> const& b
        ) -> bool {
            return a.first < b.first;
        }
    );
    
    // resort and count swaps
    for(size_t i = 0 ; i < pairs.size() ; i += 1){
        
        if( pairs[i].second == i) continue;
        else {
            std::swap(pairs[i], pairs[ pairs[i].second ]);
            swaps += 1;
            i-=1;
        }
        
    } 
    
    return swaps;   
}
