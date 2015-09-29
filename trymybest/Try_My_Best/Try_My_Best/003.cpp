#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>


using namespace std;
//
//int **ccc;
//
//int getCom(int m, int n){
//    if (m < n || m<=0 ||n < 0) {
//        return 0;
//    }
//    if (ccc[m][n] != 0) {
//        return ccc[m][n];
//    }
//    if (n == 0) {
//        ccc[m][n] = 1;
//        return 1;
//    }
//    
//    if (n==1) {
//        ccc[m][n] = m;
//        return m;
//    }
//    
//    if (ccc[m - 1][n -1] == 0) {
//        ccc[m -1][n - 1] = getCom(m -1, n -1);
//    }
//    
//    if (ccc[m-1][n] == 0) {
//        ccc[m - 1][n] = getCom(m-1,n);
//    }
//    
//    ccc[m][n] = ccc[m - 1][n - 1] + ccc[m -1][n];
//                    
//    return ccc[m][n];
//    
//}
//
//int main(){
//
//    int n,a,b,x;
//    cin >> n >> a >> b >> x;
//    
//    double res = 1.0;
//    if (n < n*a || x > n *b) {
//        cout << 0.0000;
//        return 0;
//    }
//    
//    int end = x - n*a <=n ? x-n*a:n;
//    ccc = new int*[x];
//    for (int i = 0; i < x; ++i) {
//        ccc[i] = new int[n + 1];
//        for (int j = 0; j < n + 1; ++j) {
//            ccc[i][j] = 0;
//        }
//    }
//    
//    long sum = 0;
//    for (int i = 0; i < end; ++i) {
//        sum += getCom(x - n*a -1, i) * getCom(n,i + 1);
//    }
//    
//    res *= sum;
//    for (int i = 0; i < n; ++i) {
//        res /= (b - a + 1);
//    }
//    cout << setprecision(4) << fixed << res << endl;
//    return 0;
//    
//}


//组合概率
//Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 65536/65536 K (Java/Others)
//Problem Description:
//某生产零件的工厂为方便管理场内生产的零件种类，现将他们生产的零件从低等到高等零件排序，序号分别为1,2..n，已知该厂的任意几个低等的零件可以组合成更高等的零件，零件的序号代表了零件的等级，比如5号零件可以由1号和4号零件组合而成，也可以有2号和4号零件组合而成。
//现有一个序号为 x 的零件，它是由n个序号在[a,b]区间内的零件组合而成，求n个序号在[a,b]区间内的零件组合为 x 零件的概率
//输入
//一行输入四个整数依次为n，a，b，x，用空格分隔。数据规模和约定
//对于50%的数据，n≤5.
//对于100%的数据，n≤100,b≤100
//输出
//输出一行为组合为 x 零件的概率，小数点后保留四位小数
//
//样例输入
//2 1 3 4
//样例输出
//0.3333
//
//温馨提示
//请务必仔细阅读编程题须知：http://oj.acmcoder.com/ExamNotice.html
//请务必点击“下一题”或“上一题”或“保存”或“调试”，才能保存答案
//编程题可以使用本地编译器，此页面不记录跳出次数
//考试结束后，我们会把考生最终的代码重新运行一遍。如果作答不出来，可以把答题的思路写出来，阅卷官改卷时会审阅


//
//
//int main(){
//    
//    
//    int n;
//    cin >> n;
//    while (n--) {
//        int length;
//        cin >> length;
//        int *array = new int[length];
//        
//        for (int i = 0; i < length; ++i) {
//            int x;
//            cin >> x;
//            array[i] = x;
//        }
//        
//        int max = 1;
//        int  *ids = new int[length];
//        for (int i = 0 ; i < length; ++i) {
//            ids[i] = 1;
//        }
//        
//        
//        for (int i = 1 ; i < length; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (array[j] > array[i] && ids[j] + 1 > ids[i]) {
//                    ids[i] = ids[j] + 1;
//                    
//                    if (max < ids[i]) {
//                        max = ids[i];
//                    }
//                }
//            }
//        }
//        cout << max << endl;
//    }
//    
//
//    return 0;
//    
//}