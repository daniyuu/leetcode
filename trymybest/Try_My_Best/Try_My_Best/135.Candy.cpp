#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <list>

using namespace std;

//
// TL
//
//class Solution {
//private:
//    int numOfCandies = 0;
//    void sendCandyNum(vector<int> ratings, int pos, vector<int> &candys){
//        
//        int n = ratings.size();
//        
//        int minpos = pos;
//        int maxpos = pos;
//        
//        if (ratings[(pos - 1 + n) % n] < ratings[(pos + 1 + n) % n]) {
//            minpos = (pos - 1 + n) % n;
//            maxpos = (pos + 1 + n) % n;
//        }else if (ratings[(pos - 1 + n) % n] > ratings[(pos + 1 + n) % n]){
//            minpos = (pos + 1 + n) % n;
//            maxpos = (pos - 1 + n) % n;
//        }
//        
//        
////        cout << "minpos = "<< minpos << " maxpos == " << maxpos << endl;
////        cout << "send candy to " << pos ;
//        
//        if (ratings[minpos] == ratings[maxpos]) {
//            if (ratings[pos] > ratings[minpos]) {
//                candys[pos] = candys[minpos] + 1;
//            }
//        }else{
//            if (ratings[pos] > ratings[maxpos]) {
//                candys[pos] = candys[maxpos] + 1;
//            }else if (ratings[pos] < ratings[maxpos] && ratings[pos] > ratings[minpos]){
//                candys[pos] = candys[minpos] + 1;
//            }
//        }
//        
////        cout << " " << candys[pos] << endl;
//        numOfCandies += candys[pos];
//        return;
//    }
//    
//    typedef pair<int, int> PAIR;
//    
//    bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
//        return lhs.second < rhs.second;
//    }
//    
//    struct CmpByValue {
//        bool operator()(const PAIR& lhs, const PAIR& rhs) {
//            return lhs.second < rhs.second;
//        }
//    };
//public:
//    
//    int candy(vector<int>& ratings) {
//        map<int, int> m;
//        for (int i = 0; i < ratings.size(); ++i) {
//            m[i] = ratings[i];
//        }
//        
//        vector<int> candys(ratings.size(), 1);
//        
//        vector<PAIR> index_ranting_vec(m.begin(), m.end());
//        sort(index_ranting_vec.begin(), index_ranting_vec.end(), CmpByValue());
//        
//        // sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
//        
//        for (int i = 0; i < index_ranting_vec.size(); ++i) {
//            int cur_pos = index_ranting_vec[i].first;
//           
////            cout << index_ranting_vec[i].first << index_ranting_vec[i].second << endl;
//            sendCandyNum(ratings, cur_pos, candys);
//        }
//        
//        
//        return numOfCandies;
//    }
//};
//
//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    vector<int> rating;
//    while (n--) {
//        int r;
//        cin >> r;
//        rating.push_back(r);
//    }
//    cout << s.candy(rating);
//}
//
//
//


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> increment(n,1);
        
        int total = 0;
    
        for (int i = 1, inc = 1 ; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                increment[i] = increment[i -  1] + 1;
            }else{
                inc = 1;
            }
        }
        
//        cout << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << increment[i] << " ";
//        }
//        cout << endl;
        
        for (int i = n - 2, inc = 1; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                increment[i] = max(increment[i], increment[i + 1] + 1);
            }else{
                inc = 1;
            }
            
            total += increment[i];
//            cout << "total == " <<total <<  endl;
        }
        
//        cout << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << increment[i] << " ";
//        }
//        cout << endl;
        
        total += increment[n - 1];
//        cout << "total == " <<total <<  endl;
        
        return total;
    }
};

//int main(){
//    Solution s;
//        int n;
//        cin >> n;
//        vector<int> rating;
//        while (n--) {
//            int r;
//            cin >> r;
//            rating.push_back(r);
//        }
//        cout << s.candy(rating);
//
//}

