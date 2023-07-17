#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

// map operation 1
void test01()
{
    double data[8];
    for (int i = 0; i < 8; ++i)
        {
            data[i] = i;
        }
    Map<MatrixXd>        m1(data, 2, 4);
    Matrix<double, 2, 4> m = m1.matrix();

    Map<Matrix2d>                       m2(data);
    Map<Matrix<double, 4, 2>>           m3(data);
    Map<Matrix<double, 4, 2, RowMajor>> m4(data);
    cout << m1 << endl << endl;
    cout << m2 << endl << endl;
    cout << m3 << endl << endl;
    cout << m4 << endl << endl;

    MatrixXd m5 = MatrixXd::Random(3, 3);
    auto     m6{m5};

    cout << m << endl;
}
// reshape operation
void test02()
{
    auto m1 = Matrix4i::Random();
    std::cout << "Here is original matrix(4,4): \n" << m1 << std::endl;
    std::cout << "Here is reshaped matrix(2,8): \n"
              << m1.reshaped(2, 8) << std::endl;
    std::cout << "Here is reshaped matrix(8,2): \n" << m1.size() << std::endl;
}
void test03()
{
    MatrixXf M1(3, 3); // Column-major storage
    M1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << "M1:" << endl << M1 << endl;
    Map<RowVectorXf> v1(M1.data(), M1.size());
    cout << "v1:" << endl << v1 << endl;
}

void test04()
{
    RowVectorXf v = RowVectorXf::LinSpaced(20, 0, 19);
    cout << "Input:" << endl << v << endl;
    Map<RowVectorXf, 0, InnerStride<2>> v2(v.data(), v.size() / 2);
    cout << "Even:" << v2 << endl;
}

int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    // Eigen::MatrixXi m = (Eigen::MatrixXf::Random(3, 3) * 10).cast<int>();
    // std::cout << "Here is the matrix m:" << std::endl << m << std::endl;
    // cout << 100 * Matrix2i::Random() << endl;
    return 0;
}