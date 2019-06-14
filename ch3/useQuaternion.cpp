#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>

int main(){
//!!!!!!!!!!!!caution!!!!!!!!!!
//四元数赋值还是按（w x y z）来赋，但是coeffs显示的顺序是(x y z w)
	//q1 t1
	Eigen::Quaterniond q1(0.55, 0.3, 0.2, 0.2);
	Eigen::Vector3d t1(0.7, 1.1, 0.2);
	//q2 t2
	Eigen::Quaterniond q2(-0.1, 0.3, -0.7, 0.2);
	Eigen::Vector3d t2(-0.1, 0.4, 0.8);
	//p1
	Eigen::Vector3d p1(0.5, -0.1, 0.2);
	cout << "Unnormalized q1:\n" << q1.coeffs() << endl;
	cout << "Unnormalized q2:\n" << q2.coeffs() << endl;
	
	//归一化
	q1.normalize();
	q2.normalize();
	cout << "normalized q1:\n" << q1.coeffs() << endl;
	cout << "normalized q1:\n" << q2.coeffs() << endl;
	
	
	//T_wc1
	Eigen::Isometry3d T_c1w = Eigen::Isometry3d::Identity();                // 虽然称为3d，实质上是4＊4的矩阵
	T_c1w.rotate(q1);
	T_c1w.pretranslate(t1);
	Eigen::Isometry3d T_wc1 = T_c1w.inverse();
	//T_c2w
	Eigen::Isometry3d T_c2w = Eigen::Isometry3d::Identity();
	T_c2w.rotate(q2);
	T_c2w.pretranslate(t2);
	
	//T
	Eigen::Isometry3d T = T_c2w * T_wc1;
	
	//p2
	Eigen::Vector3d p2 = T * p1;
	
	cout << "p2:\n" << p2.transpose() << endl;
	
	return 0;
}