#include <Eigen/Sparse>
#include <iostream>
using namespace Eigen;
using namespace std; // for convenience
void test01()
{
    // initialize
    SparseMatrix<double>                         sm1(1000, 1000);
    SparseMatrix<std::complex<double>, RowMajor> sm2;
    SparseVector<double>                         sv1(1500);

    sm1.rows();      // Number of rows
    sm1.cols();      // Number of columns
    sm1.nonZeros();  // Number of non zero values
    sm1.outerSize(); // Number of columns (resp. rows) for a column major (resp.
                     // // row major )
    sm1.innerSize(); // Number of rows (resp. columns) for a row major (resp.
                     // column major)
    sm1.norm();      // Euclidian norm of the matrix
    sm1.squaredNorm();  // Squared norm of the matrix
    sm1.blueNorm();
    sm1.isVector();     // Check if sm1 is a sparse vector or a
                        // sparse matrix
    sm1.isCompressed(); // Check if sm1 is in compressed form
}
void test02()
{
    // triplet 的一些情况
    Triplet<double> t1(185, 441, 2.6);
    cout << "row " << t1.row() << endl;
    cout << "col " << t1.col() << endl;
    cout << "val " << t1.value() << endl;
    // cout << t1 << endl; 无法输出
}
void test03()
{
    // 对稀疏矩阵赋值
    vector<Triplet<double>> triplets;
    SparseMatrix<double>    sm(100, 100);

    // 构造数据
    for (int i = 1; i < 101; i++)
        {
            triplets.push_back(Triplet<double>(i - 1, i - 1, i));
        }

    // 两种不同方式设置数据
    sm.setFromTriplets(triplets.begin(), triplets.end());
    sm.insert(5, 1) = 7.0;

    cout << sm.block(0, 0, 10, 10) << endl;
}

void test04()
{
    SparseMatrix<double> sm1(2, 2);
    sm1.insert(0, 0) = 0;
    sm1.insert(0, 1) = 0;
    sm1.insert(1, 0) = 4;
    sm1.insert(1, 1) = 1;
    cout << sm1 << endl << endl;

    SparseMatrix<double> sm2(2, 2);
    sm2.insert(0, 0) = 1;
    sm2.insert(0, 1) = 0;
    sm2.insert(1, 0) = 0;
    sm2.insert(1, 1) = 2;
    cout << sm2 << endl << endl;

    SparseMatrix<double> sm3;
    sm3 = SparseMatrix<double, ColMajor>(sm1.transpose()) + sm2;
    cout << sm3 << endl;
}
int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}
