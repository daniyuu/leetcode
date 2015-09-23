class Solution {
private:
    double power(double x, int n){
        if (n == 0) {
            return 1;
        }
        double v = power(x, n/2);
        if (n & 1) {
            return v * v * x;
        }else{
            return v * v;
        }
    }
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0/power(x, -n);
        }else {
            return power(x, n);
        }
    }
};