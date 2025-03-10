#ifndef globals_h
#define globals_h

/*----------------------------------------------------------------------
 Copyright (c) 2001, Sandia Corporation.   Under the terms of Contract 
 DE-AC04-94AL85000, there is a non-exclusive license for use of this 
 work by or on behalf of the U.S. Government.

 J. C. Meza, Sandia National Laboratories, meza@ca.sandia.gov
 -----------------------------------------------------------------------*/

#ifdef HAVE_CONFIG_H
#include "OPT++_config.h"
#endif

#ifdef HAVE_STD
#include <cstring>
#else
#include <string.h>
#endif

#include "Teuchos_SerialDenseMatrix.hpp"
#include "Teuchos_SerialDenseVector.hpp"
#include "Teuchos_SerialSymDenseMatrix.hpp"
#include "Teuchos_SerialDenseSolver.hpp"
#include "Teuchos_RCP.hpp"

using Teuchos::SerialDenseVector;

#if defined(__cplusplus)
#include<algorithm>
inline double min(double a,double b) { return ((a) <= (b) ? (a) : (b)); } 
inline double max(double a,double b) { return ((a) >= (b) ? (a) : (b)); } 

inline float min(float a,float b) { return ((a) <= (b) ? (a) : (b)); }
inline float max(float a,float b) { return ((a) >= (b) ? (a) : (b)); }

inline int min(int a,int b) { return ((a) <= (b) ? (a) : (b)); }
inline int max(int a,int b) { return ((a) >= (b) ? (a) : (b)); }
#else
#define min(a,b) ((a) <= (b) ? (a) : (b)) 
#define max(a,b) ((a) >= (b) ? (a) : (b))
#endif

#if defined(_WIN32) || defined(_WIN64)
// Microsoft's starts with an underscore, which is their convention 
// for non-standard language extensions
// Leveraging boost::math copysign might be an alternative worth considering
#define copysign _copysign
#endif


#define WANT_MATH

namespace OPTPP {

#define GOOD     0
#define BAD      1

//  Some useful typdefs

typedef double real;

typedef enum {LineSearch, TrustRegion, TrustPDS } 
             SearchStrategy;

typedef enum {Cauchy_Step, Dogleg_Step, Newton_Step, Backtrack_Step} 
             Step_type;

typedef enum {Leqn, NLeqn, Lineq, NLineq, Bound} ConstraintType;

typedef enum {NLPNoOp = 0, NLPFunction = 1, NLPGradient = 2, NLPHessian = 4,
              NLPConstraint = 8, NLPCJacobian = 16} FcnMode;

typedef enum {ForwardDiff, BackwardDiff, CentralDiff, CentralDiff1, CentralDiff2} 
             DerivOption;

typedef enum {NormFmu, ArgaezTapia, VanShanno} 
             MeritFcn;

typedef enum {NoSpec, Spec1, Spec2} SpecOption;

typedef void (*UPDATEFCN)(int, int, SerialDenseVector<int, double>);

struct OPT_GLOBALS {
  static const float OPT_VERSION;
  static const int OPT_MINOR;
};

} // namespace OPTPP

#endif
