//######################
//2019-6-14
//use Eigen to slove Function
//copyright @suzhilong
//######################
#include <iostream>
using namespace std;
#include <ctime>
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

int main(){
    
	Eigen::Matrix<double, 100, 100> matrix100;
	matrix100 = Eigen::MatrixXd::Random(100, 100);
	Eigen::Matrix<double, 100, 1> matrix100_1;
	matrix100_1 = Eigen::MatrixXd::Random(100, 1);
	
	// 直接求逆
	clock_t time_stt = clock(); // 计时
    Eigen::Matrix<double,100,1> x = matrix100.inverse()*matrix100_1;
	cout << x << endl;
	cout <<"time use in normal inverse is " << 1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms"<< endl;

	//QR分解
	time_stt = clock();
    x = matrix100.colPivHouseholderQr().solve(matrix100_1);
	cout << x << endl;
    cout <<"time use in Qr decomposition is " <<1000*  (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms" << endl;

	//Cholesky分解
	//要求矩阵为正定，求出来的是不对的
	time_stt = clock();
	x = matrix100.llt().solve(matrix100_1);
	cout << x << endl;
	cout <<"time use in Cholesky decomposition is " <<1000*  (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms" << endl;
	
    return 0;
}
