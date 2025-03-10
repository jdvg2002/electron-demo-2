#ifndef NonLinearEquation_h 
#define NonLinearEquation_h

#include "NonLinearConstraint.h"

/**
 * NonLinearEquation is a derived class of NonLinearConstraint.
 *
 * @author P.J. Williams, Sandia National Laboratories, pwillia@sandia.gov
 * @date Last modified 02/2006
 *
 */


namespace OPTPP {
//----------------------------------------------------------------------
// NonLinear Constraint
//----------------------------------------------------------------------
class NonLinearEquation: public NonLinearConstraint{

protected:
  /// right-hand side of equation
  Teuchos::SerialDenseVector<int,double> b_;	
  /// type of constraint - NLeqn
  Teuchos::SerialDenseVector<int,double> ctype_;	

public:
/**
 * Default Constructor
 * @see NonLinearEquation(NLP* nlprob, int numconstraints = 1)
 * @see NonLinearEquation(NLP* nlprob, const Teuchos::SerialDenseVector<int,double>& rhs, 
 *                       int numconstraints = 1)
 */
  NonLinearEquation();
/**
 * Constructors
 * @param nlprob a pointer to an NLP object 
 * @param numconstraints an integer argument 
 * @note Assumes right-hand side = 0
 */
  NonLinearEquation(NLP* nlprob, int numconstraints = 1);
/**
 * Constructors
 * @param nlprob a pointer to an NLP object 
 * @param rhs ColumnVector
 * @param numconstraints an integer argument 
 * @note Nonzero right-hand side 
 */
  NonLinearEquation(NLP* nlprob, const Teuchos::SerialDenseVector<int,double>& rhs, 
                         int numconstraints = 1);

/**
 * Destructor
 */
  virtual ~NonLinearEquation(){}

/**
 * @return Type of constraint - NLeqn
 */
  Teuchos::SerialDenseVector<int,double> getConstraintType() const { return ctype_;};

/**
 * @return The right-hand side of the equation.
 */
  Teuchos::SerialDenseVector<int,double> getB() const { return b_;};

/**
 * Takes one argument and returns a ColumnVector.
 * @param xc a ColumnVector
 * @return The residual of the nonlinear equations evaluated at xc.
 */
  Teuchos::SerialDenseVector<int,double> evalResidual(const Teuchos::SerialDenseVector<int,double>& xc) const;
  void evalCFGH(const Teuchos::SerialDenseVector<int,double>& xc) const;

/**
 * Takes one argument and returns a Matrix.
 * @param xc a ColumnVector
 * @return The gradient of the nonlinear equations evaluated at xc.
 */
  Teuchos::SerialDenseMatrix<int,double> evalGradient(const Teuchos::SerialDenseVector<int,double>& xc) const ;

/**
 * Takes one argument and returns a SymmetricMatrix
 * @param xc a ColumnVector
 * @return The Hessian of the nonlinear equations evaluated at xc.
 */
  Teuchos::SerialSymDenseMatrix<int,double> evalHessian(Teuchos::SerialDenseVector<int,double>& xc) const;

/**
 * Takes two arguments and returns an array of real SymmetricMatrices.
 * @param xc a ColumnVector
 * @param darg an integer argument
 * @return An array of constraint Hessians.
 */
  OptppArray<Teuchos::SerialSymDenseMatrix<int,double> > evalHessian(Teuchos::SerialDenseVector<int,double>& xc, int darg) const;

/**
 * Takes two arguments and returns a bool.
 * @param xc a ColumnVector
 * @param epsilon a real argument.
 * @return The feasibility of the nonlinear equations at xc.
 */
  bool amIFeasible(const Teuchos::SerialDenseVector<int,double>& xc, double epsilon) const;

};

} // namespace OPTPP
#endif
