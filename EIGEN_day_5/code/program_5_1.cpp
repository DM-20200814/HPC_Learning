#include <Eigen/Sparse>
#include <iostream>
using namespace std;
using namespace Eigen;
static SparseMatrix<double> A(6, 6);
static VectorXd             b(6);
static VectorXd             x(6);

void init()
{
    A.insert(0, 0) = 2;
    A.insert(1, 1) = 1;
    A.insert(1, 2) = 2;
    A.insert(2, 2) = 1;
    A.insert(3, 3) = 1;
    A.insert(3, 5) = 1;
    A.insert(4, 2) = 1;
    A.insert(4, 3) = 1;
    A.insert(4, 4) = 1;
    A.insert(5, 5) = 1;

    b << 2, 4, 1, 5, 8, 3;
}
void SPDinit()
{
    A.insert(0, 0) = 2;
    A.insert(1, 1) = 1;
    A.insert(1, 2) = 2;
    A.insert(2, 1) = 2;
    A.insert(2, 2) = 1;
    A.insert(2, 4) = 1;
    A.insert(3, 3) = 1;
    A.insert(3, 4) = 1;
    A.insert(3, 5) = 1;
    A.insert(4, 2) = 1;
    A.insert(4, 3) = 1;
    A.insert(4, 4) = 1;
    A.insert(5, 5) = 1;

    b << 2, 4, 1, 5, 8, 3;
}

void test01()
{
    init();
    // 新建矩阵，注意要指定大小
    // 构建solver
    SparseLU<SparseMatrix<double>> solver;

    // compute步骤
    solver.compute(A);
    // solver步骤
    x = solver.solve(b);
    // 输出结果
    cout << "Here is the sparselu solution vector x:\n" << x << endl;
    SimplicialLDLT<SparseMatrix<double>> solver2;
    x = solver2.compute(A).solve(b);
    cout << "Here is the simplicialldlt solution vector x:\n" << x << endl;
    SparseQR<SparseMatrix<double>, COLAMDOrdering<int>> solver3;
    A.makeCompressed();
    solver3.compute(A);
    x = solver3.solve(b);
    cout << "Here is the sparseqr solution vector x:\n" << x << endl;
}

void test02()
{
    BiCGSTAB<SparseMatrix<double>> solver;
    // cout << A << endl;
    if (!A.isCompressed())
        A.makeCompressed();
    solver.setTolerance(1e-8);
    solver.compute(A);
    x = solver.solve(b);
    cout << x << endl << "iteration num : " << solver.iterations() << endl;
}

// test for spd matrix
void test03()
{
    SPDinit();
    SparseLU<SparseMatrix<double>> solver;

    // compute步骤
    solver.compute(A);
    // solver步骤
    x = solver.solve(b);
    // 输出结果
    cout << "Here is the sparselu solution vector x:\n" << x << endl;
    SimplicialLDLT<SparseMatrix<double>> solver2;
    x = solver2.compute(A).solve(b);
    cout << "Here is the simplicialldlt solution vector x:\n" << x << endl;
    SparseQR<SparseMatrix<double>, COLAMDOrdering<int>> solver3;
    A.makeCompressed();
    solver3.compute(A);
    x = solver3.solve(b);
    cout << "Here is the sparseqr solution vector x:\n" << x << endl;
}
int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}