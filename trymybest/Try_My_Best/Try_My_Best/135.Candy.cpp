#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <list>

using namespace std;

class Solution {
private:
    int numOfCandies = 0;
    void sendCandyNum(vector<int> ratings, int pos, vector<int> &candys){
        
        int n = ratings.size();
        
        int minpos = pos;
        int maxpos = pos;
        
        if (ratings[(pos - 1 + n) % n] < ratings[(pos + 1 + n) % n]) {
            minpos = (pos - 1 + n) % n;
            maxpos = (pos + 1 + n) % n;
        }else if (ratings[(pos - 1 + n) % n] > ratings[(pos + 1 + n) % n]){
            minpos = (pos + 1 + n) % n;
            maxpos = (pos - 1 + n) % n;
        }
        
        
//        cout << "minpos = "<< minpos << " maxpos == " << maxpos << endl;
//        cout << "send candy to " << pos ;
        
        if (ratings[minpos] == ratings[maxpos]) {
            if (ratings[pos] > ratings[minpos]) {
                candys[pos] = candys[minpos] + 1;
            }
        }else{
            if (ratings[pos] > ratings[maxpos]) {
                candys[pos] = candys[maxpos] + 1;
            }else if (ratings[pos] < ratings[maxpos] && ratings[pos] > ratings[minpos]){
                candys[pos] = candys[minpos] + 1;
            }
        }
        
//        cout << " " << candys[pos] << endl;
        numOfCandies += candys[pos];
        return;
    }
    
    typedef pair<int, int> PAIR;
    
    bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second < rhs.second;
    }
    
    struct CmpByValue {
        bool operator()(const PAIR& lhs, const PAIR& rhs) {
            return lhs.second < rhs.second;
        }
    };
public:
    
    int candy(vector<int>& ratings) {
        map<int, int> m;
        for (int i = 0; i < ratings.size(); ++i) {
            m[i] = ratings[i];
        }
        
        vector<int> candys(ratings.size(), 1);
        
        vector<PAIR> index_ranting_vec(m.begin(), m.end());
        sort(index_ranting_vec.begin(), index_ranting_vec.end(), CmpByValue());
        
        // sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
        
        for (int i = 0; i < index_ranting_vec.size(); ++i) {
            int cur_pos = index_ranting_vec[i].first;
           
//            cout << index_ranting_vec[i].first << index_ranting_vec[i].second << endl;
            sendCandyNum(ratings, cur_pos, candys);
        }
        
        
        return numOfCandies;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> rating;
    while (n--) {
        int r;
        cin >> r;
        rating.push_back(r);
    }
    cout << s.candy(rating);
}




