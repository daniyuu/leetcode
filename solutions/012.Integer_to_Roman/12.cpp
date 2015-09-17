class Solution {
private:
	int val[13] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    };
    string syb[13] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };
public:
    string intToRoman(int num) {
        stirng roman;
        int i = 0;
        int k;
        while(num != 0){
        	k = num / val[i];
        	while(k--){
        		roman += syb[i];
        		num -= val[i];
        	}
        	++i;
        }

        return roman;
    }
};