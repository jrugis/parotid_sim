/*
 * cVCLSolver.hpp
 *
 *  Created on: 23/01/2018
 *      Author: jrugis
 */

#ifndef CVCLSOLVER_H_
#define CVCLSOLVER_H_

typedef double tCalcs;

#include <string>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <viennacl/compressed_matrix.hpp>
#include <viennacl/linalg/ilu.hpp>

typedef Eigen::Matrix<tCalcs, Eigen::Dynamic, Eigen::Dynamic> MatrixXXC;
typedef Eigen::Matrix<tCalcs, Eigen::Dynamic, 1> MatrixX1C;
typedef viennacl::compressed_matrix<tCalcs> vcl_sparse_t;
typedef viennacl::linalg::ilut_precond<vcl_sparse_t> vcl_precond_t;
typedef Eigen::SparseMatrix<tCalcs> SparseMatrixTCalcs;

class cVCLSolver {
public:
	cVCLSolver(SparseMatrixTCalcs &sparseA);
	virtual ~cVCLSolver();
	void step(MatrixX1C &solvec, MatrixX1C &rhsvec);

private:
    // sparse matrix for passing to ViennaCL
    vcl_sparse_t vcl_sparseA;
    // number of columns
    int size;
    // preconditioner for passing to gmres
    vcl_precond_t  *vcl_precond;
};

#endif /* CVCLSOLVER_H_ */
