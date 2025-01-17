#ifndef NLF_h
#define NLF_h


/*----------------------------------------------------------------------
 Copyright (c) 2001, Sandia Corporation.   Under the terms of Contract 
 DE-AC04-94AL85000, there is a non-exclusive license for use of this 
 work by or on behalf of the U.S. Government.

 J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 ----------------------------------------------------------------------*/

#include "NLP2.h"
#include "Teuchos_SerialDenseMatrix.hpp"
#include "Teuchos_SerialDenseVector.hpp"
#include "Teuchos_SerialSymDenseMatrix.hpp"

extern "C" {
  double get_cpu_time();
  double get_wall_clock_time();
}

namespace OPTPP {

typedef void (*INITFCN)(int, Teuchos::SerialDenseVector<int,double>&);

typedef CompoundConstraint* (*INITCONFCN)(int);

typedef void (*USERFCN0)(int, const Teuchos::SerialDenseVector<int,double>&, real&, int&);
typedef void (*USERFCN0V)(int, const Teuchos::SerialDenseVector<int,double>&, real&, int&, void*);

typedef void (*USERFCN1)(int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
                         Teuchos::SerialDenseVector<int,double>&, int&);
typedef void (*USERFCN1V)(int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
                         Teuchos::SerialDenseVector<int,double>&, int&, void*);

typedef void (*USERFCN2)(int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
			 Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialSymDenseMatrix<int,double>&, int&);
typedef void (*USERFCN2V)(int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
			 Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialSymDenseMatrix<int,double>&, 
                         int&, void*);

typedef void (*USERFCN2A)(int, int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
			 Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialDenseMatrix<int,double>&, int&);
typedef void (*USERFCN2AV)(int, int, int, const Teuchos::SerialDenseVector<int,double>&, real&, 
			 Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialDenseMatrix<int,double>&, int&, void*);

typedef void (*USERNLNCON0)(int, const Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialDenseVector<int,double>&, int&);

typedef void (*USERNLNCON1)(int, int, const Teuchos::SerialDenseVector<int,double>&,
  Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialDenseMatrix<int,double>&, int&);

typedef void (*USERNLNCON2)(int, int, const Teuchos::SerialDenseVector<int,double>&, 
  Teuchos::SerialDenseVector<int,double>&, Teuchos::SerialDenseMatrix<int,double>&, OptppArray<Teuchos::SerialSymDenseMatrix<int,double> >&, int&);


//
//  Derived from NLP's
//

/**
 * NLF0 is a derived class of NLP0, a nonlinear problem without
 * analytic derivative information.  The NLF0 class implements 
 * function, finite-difference gradient, and finite-difference 
 * Hessian evaluators.
 *
 * @author J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 * @note Modified by P.J. Williams, Sandia National Laboratories, 
 * pwillia@sandia.gov
 * @date Last modified 03/2007
 */

class NLF0: public NLP0 {
protected:
  USERFCN0 fcn;			///< User-defined objective function
  USERFCN0V fcn_v;		///< User-defined objective function w/ void ptr
  USERNLNCON0 confcn;		///< User-defined nonlinear constraints 
  INITFCN init_fcn;		///< Initializes the objective function
  INITCONFCN init_confcn;	///< Initializes the constraints 
  bool init_flag;		///< Has the function been initialized?
  void *vptr;			///< Void pointer

  static void f_helper(int n, const Teuchos::SerialDenseVector<int,double>& xc, real& f, 
         int& result, void *v) {NLF0 *o = (NLF0*)v; (*o->fcn)(n,xc,f,result);}

public:
  // Constructors
  NLF0(): 
     NLP0(), init_flag(false) {;}
  NLF0(int ndim): 
     NLP0(ndim), init_flag(false) {;}
  NLF0(int ndim, USERFCN0 f): 
     NLP0(ndim), fcn(f), fcn_v(f_helper), init_flag(false), vptr(this) {;}
  NLF0(int ndim, USERFCN0 f, INITFCN i, CompoundConstraint* constraint = 0):
     NLP0(ndim, constraint), fcn(f), fcn_v(f_helper), init_fcn(i), 
     init_flag(false), vptr(this) {;}
  NLF0(int ndim, USERFCN0 f, INITFCN i, INITCONFCN c):
     NLP0(ndim), fcn(f), fcn_v(f_helper),init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(this) 
     {constraint_ = init_confcn(ndim);}
  NLF0(int ndim, int nlncons, USERNLNCON0 f, INITFCN i):
     NLP0(ndim,nlncons), confcn(f), init_fcn(i), init_flag(false), vptr(this) {;}
  /// Alternate function pointers with user-supplied void function pointer
  NLF0(int ndim, USERFCN0V f, INITFCN i, CompoundConstraint* constraint = 0, void* v = 0):
     NLP0(ndim, constraint), fcn(0), fcn_v(f), init_fcn(i), init_flag(false) 
     {if (v == 0) vptr = this; else vptr= v ;}
  NLF0(int ndim, USERFCN0V f, INITFCN i, void* v): 
     NLP0(ndim), fcn(0), fcn_v(f), init_fcn(i), init_flag(false), vptr(v) {;}
  NLF0(int ndim, USERFCN0V f, INITFCN i, INITCONFCN c, void* v):
     NLP0(ndim), fcn(0), fcn_v(f),init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(v) 
     {constraint_ = init_confcn(ndim);}

  // Destructor
  virtual ~NLF0() {;}               

  /// Reset parameter values 
  virtual void reset(); 			

  /// Initialize selected function
  virtual void initFcn(); 			

  /// Evaluate the function, gradient, and Hessian 
  virtual void eval(); 				

  /// Evaluate the function
  virtual real evalF();               		
  /// Evaluate the function at x
  virtual real evalF(const Teuchos::SerialDenseVector<int,double>& x); 	
  /// Evaluate nonlinear constraints at x 
  virtual Teuchos::SerialDenseVector<int,double> evalCF(const Teuchos::SerialDenseVector<int,double>& x); 	

// Default Gradient function for NLF0 is to do a finite-difference
  /// Evaluate a finite-difference gradient
  virtual Teuchos::SerialDenseVector<int,double> evalG();			

  /// Evaluate the Lagrangian at x 
  virtual real evalLagrangian(const Teuchos::SerialDenseVector<int,double>& x, Teuchos::SerialDenseVector<int,double>& mult,
                              const Teuchos::SerialDenseVector<int,double>& type) ;
  /// Evaluate the gradient of the Lagrangian at x
  virtual Teuchos::SerialDenseVector<int,double> evalLagrangianGradient(const Teuchos::SerialDenseVector<int,double>& x,
                                              const Teuchos::SerialDenseVector<int,double>& mult,
                                              const Teuchos::SerialDenseVector<int,double>& type) ;

private:
  /// Evaluate grad at x
  virtual Teuchos::SerialDenseVector<int,double> evalG(const Teuchos::SerialDenseVector<int,double>& x);  
  /// Evaluate the Hessian at x
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH();		
  /// Evaluate the Hessian 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH(Teuchos::SerialDenseVector<int,double> &x);
  /// Evaluate the constraint gradient at x
  virtual Teuchos::SerialDenseMatrix<int,double> evalCG(const Teuchos::SerialDenseVector<int,double>& x);  	
  /// Evaluate constraint hessian at x
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalCH(Teuchos::SerialDenseVector<int,double> &x);	
  /// Evaluate constraint hessian at x
  virtual OptppArray<Teuchos::SerialSymDenseMatrix<int,double> > evalCH(Teuchos::SerialDenseVector<int,double> &x, int darg);
  virtual void evalC(const Teuchos::SerialDenseVector<int,double>& x); 	
};

/**
 * NLF1 is a derived class of NLP1, a nonlinear problem with analytic
 * first derivatives.  The NLF1 class implements function, 
 * gradient, and Hessian evaluators.
 *
 * @author J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 * @note Modified by P.J. Williams, Sandia National Laboratories, 
 * pwillia@sandia.gov
 * @date Last modified 03/2007
 */

class NLF1: public NLP1 {
protected:
  USERFCN1 fcn;			///< User-defined objective function
  USERFCN1V fcn_v;		///< User-defined objective function w/ void ptr
  USERNLNCON1 confcn;		///< User-defined constraints
  INITFCN init_fcn;		///< Initializes the objective function
  INITCONFCN init_confcn;	///< Initializes of the constraints
  bool init_flag;		///< Has the function been initialized?
  void *vptr;			///< Void pointer

  static void f_helper(int m, int n, const Teuchos::SerialDenseVector<int,double>& xc, real& f, 
         Teuchos::SerialDenseVector<int,double>& g, int& result, void  *v) 
         {NLF1 *o = (NLF1*)v; (*o->fcn)(m,n,xc,f,g,result);}
  

public:
  // Constructors
  NLF1(): 
     NLP1(), init_flag(false) {;}
  NLF1(int ndim): 
     NLP1(ndim), init_flag(false) {;}
  NLF1(int ndim, USERFCN1 f, INITFCN i, CompoundConstraint* constraint = 0):
     NLP1(ndim, constraint), fcn(f), fcn_v(f_helper), init_fcn(i), 
     init_flag(false), vptr(this)
     {analytic_grad = 1;}
  NLF1(int ndim, USERFCN1 f, INITFCN i, INITCONFCN c):
     NLP1(ndim), fcn(f), fcn_v(f_helper), init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(this)
     {analytic_grad = 1; constraint_ = init_confcn(ndim);}
  NLF1(int ndim, int nlncons, USERNLNCON1 f, INITFCN i):
     NLP1(ndim,nlncons), confcn(f), init_fcn(i), init_flag(false), vptr(this)
     {analytic_grad = 1;}
  /// Alternate function pointers with user-supplied void function pointer
  NLF1(int ndim, USERFCN1V f, INITFCN i, CompoundConstraint* constraint = 0, void* v = 0):
     NLP1(ndim, constraint), fcn(0), fcn_v(f), init_fcn(i), init_flag(false) 
     { analytic_grad = 1; if (v == 0) vptr = this; else vptr= v ;}
  NLF1(int ndim, USERFCN1V f, INITFCN i, void* v):
     NLP1(ndim), fcn(0), fcn_v(f), init_fcn(i), init_flag(false), vptr(v)
     {analytic_grad = 1;}
  NLF1(int ndim, USERFCN1V f, INITFCN i, INITCONFCN c, void* v):
     NLP1(ndim), fcn(0), fcn_v(f), init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(v)
     {analytic_grad = 1; constraint_ = init_confcn(ndim);}

  // Destructor
  virtual ~NLF1() {;}                     

  /// Reset parameter values 
  virtual void reset(); 			

  /// Initialize selected function
  virtual void initFcn();              		

  /// Evaluate objective function, gradient, and Hessian 
  virtual void eval(); 				

  /// Evaluate the objective function 
  virtual real evalF();                		

  /// Evaluate the objective function at x 
  virtual real evalF(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the gradient of the objective function 
  virtual Teuchos::SerialDenseVector<int,double> evalG();              	

  /// Evaluate the gradient of the objective function at x
  virtual Teuchos::SerialDenseVector<int,double> evalG(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the Hessian of the objective function 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH();              

  /// Evaluate the Hessian of the objective function at x 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH(Teuchos::SerialDenseVector<int,double>& x); 

  /// Evaluate the Lagrangian at x
  virtual real evalLagrangian(const Teuchos::SerialDenseVector<int,double>& x, Teuchos::SerialDenseVector<int,double>& mult,
                              const Teuchos::SerialDenseVector<int,double>& type) ;

  /// Evaluate the gradient of the Lagrangian at x
  virtual Teuchos::SerialDenseVector<int,double> evalLagrangianGradient(const Teuchos::SerialDenseVector<int,double>& x,
                                              const Teuchos::SerialDenseVector<int,double>& mult,
                                              const Teuchos::SerialDenseVector<int,double>& type) ;

  /// Evaluate the nonlinear constraints at x
  virtual Teuchos::SerialDenseVector<int,double> evalCF(const Teuchos::SerialDenseVector<int,double>& x);  	
  /// Evaluate the gradient of the nonlinear constraints at x
  virtual Teuchos::SerialDenseMatrix<int,double> evalCG(const Teuchos::SerialDenseVector<int,double>& x);  	
  /// Evaluate the Hessian of the nonlinear constraints at x
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalCH(Teuchos::SerialDenseVector<int,double> &x);	
  // Evaluate constraint hessian at x
  virtual OptppArray<Teuchos::SerialSymDenseMatrix<int,double> > evalCH(Teuchos::SerialDenseVector<int,double> &x, int darg);
  virtual void evalC(const Teuchos::SerialDenseVector<int,double>& x); 	
};

/**
 * NLF2 is a derived class of NLP2, a nonlinear problem with
 * analytic first and second derivatives.  The NLF2 class 
 * implements function, gradient, and Hessian evaluators.
 *
 * @author J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 * @note Modified by P.J. Williams, Sandia National Laboratories, 
 * pwillia@sandia.gov
 * @date Last modified 03/2007
 */
class NLF2: public NLP2 {
protected:
  USERFCN2 fcn;			///< User-defined objective function
  USERFCN2V fcn_v;	        ///< User-defined objective function
  USERNLNCON1 confcn1;		///< User-defined nonlinear constraints 
  USERNLNCON2 confcn2;		///< User-defined nonlinear constraints 
  INITFCN init_fcn;		///< Initializes the objective function
  INITCONFCN init_confcn;	///< Initializes the constraints
  bool init_flag;		///< Has the function been initialized?
  void *vptr;			///< Void pointer

  static void f_helper(int m, int n, const Teuchos::SerialDenseVector<int,double>& xc, real& f, 
	Teuchos::SerialDenseVector<int,double>& g, Teuchos::SerialSymDenseMatrix<int,double>& H, int& result, void  *v)
  {NLF2 *o = (NLF2*)v; (*o->fcn)(m,n,xc,f,g,H,result);}

public:
  // Constructors
  NLF2(): 
     NLP2(), init_flag(false) {;}
  NLF2(int ndim): 
     NLP2(ndim), init_flag(false) {;}
  NLF2(int ndim, USERFCN2 f, INITFCN i, CompoundConstraint* constraint = 0):
     NLP2(ndim, constraint), fcn(f), fcn_v(f_helper), init_fcn(i), 
     init_flag(false), vptr(this) {;}
  NLF2(int ndim, USERFCN2 f, INITFCN i, INITCONFCN c):
     NLP2(ndim), fcn(f), fcn_v(f_helper), init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(this)
     {constraint_ = init_confcn(ndim);}
  NLF2(int ndim, int nlncons, USERNLNCON1 f, INITFCN i):
     NLP2(ndim, nlncons), confcn1(f), confcn2(NULL), init_fcn(i), 
     init_flag(false), vptr(this) {;}
  NLF2(int ndim, int nlncons, USERNLNCON2 f, INITFCN i):
     NLP2(ndim, nlncons), confcn1(NULL), confcn2(f), init_fcn(i), 
     init_flag(false), vptr(this) {;}
  /// Alternate function pointers with user-supplied void function pointer
  NLF2(int ndim, USERFCN2V f, INITFCN i, CompoundConstraint* constraint = 0, void* v = 0):
     NLP2(ndim, constraint), fcn(0), fcn_v(f), init_fcn(i), init_flag(false) 
     { if (v == 0) vptr = this; else vptr= v ;}
  NLF2(int ndim, USERFCN2V f, INITFCN i, void* v):
     NLP2(ndim), fcn(0), fcn_v(f), init_fcn(i), 
     init_flag(false), vptr(v) {;}
  NLF2(int ndim, USERFCN2V f, INITFCN i, INITCONFCN c, void* v):
     NLP2(ndim), fcn(0), fcn_v(f), init_fcn(i), init_confcn(c), 
     init_flag(false), vptr(v)
     {constraint_ = init_confcn(ndim);}

  // Destructor
  virtual ~NLF2() {;}                     


  /// Reset parameter values 
  virtual void reset(); 			

  /// Initialize function
  virtual void initFcn();                       	

  /// Evaluate the objective function, gradient, and Hessian 
  virtual void eval(); 				 	

  /// Evaluate the objective function 
  virtual real evalF();                       		

  /// Evaluate the objective function at x 
  virtual real evalF(const Teuchos::SerialDenseVector<int,double>& x);    	

  /// Evaluate the analytic gradient of the objective function 
  virtual Teuchos::SerialDenseVector<int,double> evalG();              		

  /// Evaluate the analytic gradient of the objective function at x 
  virtual Teuchos::SerialDenseVector<int,double> evalG(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the analytic Hessian of the objective function 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH();              	
private:
  /// Evaluate the analytic Hessian of the objective function at x 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH(Teuchos::SerialDenseVector<int,double>& x); 

  /// Evaluate the Lagrangian at x
  virtual real evalLagrangian(const Teuchos::SerialDenseVector<int,double>& x, Teuchos::SerialDenseVector<int,double>& mult,
                              const Teuchos::SerialDenseVector<int,double>& type) ;

  /// Evaluate the gradient of the Lagrangian at x
  virtual Teuchos::SerialDenseVector<int,double> evalLagrangianGradient(const Teuchos::SerialDenseVector<int,double>& x,
                                              const Teuchos::SerialDenseVector<int,double>& mult,
                                              const Teuchos::SerialDenseVector<int,double>& type) ;
  /// Evaluate the Hessian of the Lagrangian at x
  Teuchos::SerialSymDenseMatrix<int,double> evalLagrangianHessian(Teuchos::SerialDenseVector<int,double>& x,
                                        const Teuchos::SerialDenseVector<int,double>& mult,
                                        const Teuchos::SerialDenseVector<int,double>& type);
  /// Evaluate the nonlinear constraints at x
  virtual Teuchos::SerialDenseVector<int,double> evalCF(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the gradient of the nonlinear constraints at x
  virtual Teuchos::SerialDenseMatrix<int,double> evalCG(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the Hessian of the nonlinear constraints at x
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalCH(Teuchos::SerialDenseVector<int,double> &x);	

  /// Evaluate constraint hessian at x
  OptppArray<Teuchos::SerialSymDenseMatrix<int,double> > evalCH(Teuchos::SerialDenseVector<int,double> &x, int darg);
  virtual void evalC(const Teuchos::SerialDenseVector<int,double>& x); 	

};

/**
 * FDNLF1 is a  derived class of NLP1.
 * The FDNLF1 class implements function, gradient, and Hessian evaluators.
 *
 * @author J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 * @note Modified by P.J. Williams, Sandia National Laboratories, 
 * pwillia@sandia.gov
 * @date Last modified 03/2007
 */
class FDNLF1: public NLP1 {
protected:
  USERFCN0 fcn;			///< User-defined objective function
  USERFCN0V fcn_v;		///< User-defined objective function w/ void ptr
  USERNLNCON0 confcn;		///< User-defined nonlinear constraints
  INITFCN init_fcn;		///< Initializes the objective function
  INITCONFCN init_confcn;	///< Initializes the constraints
  bool init_flag;		///< Has the function been initialized?
  void *vptr;			///< Void pointer

  static void f_helper(int n, const Teuchos::SerialDenseVector<int,double>& xc, real& f, 
         int& result, void *v) {FDNLF1 *o = (FDNLF1*)v; (*o->fcn)(n,xc,f,result);}

public:
  // Constructor
  FDNLF1(): 
     NLP1(), init_flag(false) {;}
  FDNLF1(int ndim): 
     NLP1(ndim), init_flag(false) {;}
  FDNLF1(int ndim, USERFCN0 f, INITFCN i, CompoundConstraint* constraint = 0): 
    NLP1(ndim, constraint), fcn(f), fcn_v(f_helper), init_fcn(i), 
    init_flag(false), vptr(this)
    { analytic_grad = 0;}
  FDNLF1(int ndim, USERFCN0 f, INITFCN i, INITCONFCN c): 
    NLP1(ndim), fcn(f), fcn_v(f_helper), init_fcn(i), init_confcn(c), 
    init_flag(false), vptr(this)
    { analytic_grad = 0; constraint_ = init_confcn(ndim);}
  FDNLF1(int ndim, int nlncons, USERNLNCON0 f, INITFCN i):
    NLP1(ndim, nlncons), confcn(f), init_fcn(i), init_flag(false), vptr(this)
    { analytic_grad = 0;}
  /// Alternate function pointers with user-supplied void function pointer
  FDNLF1(int ndim, USERFCN0V f, INITFCN i, CompoundConstraint* constraint = 0, void* v = 0):
     NLP1(ndim, constraint), fcn(0), fcn_v(f), init_fcn(i), init_flag(false) 
     { analytic_grad = 1; if (v == 0) vptr = this; else vptr= v ;}
  FDNLF1(int ndim, USERFCN0V f, INITFCN i, void* v): 
    NLP1(ndim), fcn(0), fcn_v(f), init_fcn(i), init_flag(false), vptr(v)
    { analytic_grad = 0;}
  FDNLF1(int ndim, USERFCN0V f, INITFCN i, INITCONFCN c, void* v): 
    NLP1(ndim), fcn(0), fcn_v(f), init_fcn(i), init_confcn(c), 
    init_flag(false), vptr(v)
    { analytic_grad = 0; constraint_ = init_confcn(ndim);}

  // Destructor
  virtual ~FDNLF1() {;}                     

  /// Reset parameter values 
  virtual void reset(); 			

  /// Initialize function
  virtual void initFcn();                       	

  /// Evaluate the objective function, gradient, and Hessian 
  virtual void eval();                       		

  /// Evaluate the objective function 
  virtual real evalF();                         	

  /// Evaluate the objective function at 
  virtual real evalF(const Teuchos::SerialDenseVector<int,double>& x);    	

  /// Evaluate the gradient of the objective function 
  virtual Teuchos::SerialDenseVector<int,double> evalG();              		

  /// Evaluate the gradient of the objective function at x 
  virtual Teuchos::SerialDenseVector<int,double> evalG(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the Hessian of the objective function 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH();              	

  /// Evaluate the finite difference approximation to 
  /// Hessian of the objective function 
  Teuchos::SerialSymDenseMatrix<int,double> FDHessian(Teuchos::SerialDenseVector<int,double>& x);     

  /// Print out current state: 
  /// x, gradient, and function value to the screen 
  virtual void printState(const char *);    

  /// Print out current state: 
  /// x, gradient, and function value to a file
  virtual void fPrintState(std::ostream *, const char *);    


  /// Evaluate the Lagrangian at x
  virtual real evalLagrangian(const Teuchos::SerialDenseVector<int,double>& x, Teuchos::SerialDenseVector<int,double>& mult,
                              const Teuchos::SerialDenseVector<int,double>& type) ;

  /// Evaluate the gradient of the Lagrangian at x
  virtual Teuchos::SerialDenseVector<int,double> evalLagrangianGradient(const Teuchos::SerialDenseVector<int,double>& x,
                                              const Teuchos::SerialDenseVector<int,double>& mult,
                                              const Teuchos::SerialDenseVector<int,double>& type) ;
  /// Evaluate the nonlinear constraints at x
  virtual Teuchos::SerialDenseVector<int,double> evalCF(const Teuchos::SerialDenseVector<int,double>& x);  	

  /// Evaluate the gradient of the nonlinear constraints at x
  virtual Teuchos::SerialDenseMatrix<int,double> evalCG(const Teuchos::SerialDenseVector<int,double>& x);  	
private:
  /// Evaluate hessian at x 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalH(Teuchos::SerialDenseVector<int,double>& x); 	
  /// Evaluate constraint hessian at x 
  virtual Teuchos::SerialSymDenseMatrix<int,double> evalCH(Teuchos::SerialDenseVector<int,double> &x);	
  /// Evaluate constraint hessian at x
  virtual OptppArray<Teuchos::SerialSymDenseMatrix<int,double> > evalCH(Teuchos::SerialDenseVector<int,double> &x, int darg);
  virtual void evalC(const Teuchos::SerialDenseVector<int,double>& x); 	
};

} // namespace OPTPP

#endif
