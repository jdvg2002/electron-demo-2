// @HEADER
// ************************************************************************
//
//               Rapid Optimization Library (ROL) Package
//                 Copyright (2014) Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact lead developers:
//              Drew Kouri   (dpkouri@sandia.gov) and
//              Denis Ridzal (dridzal@sandia.gov)
//
// ************************************************************************
// @HEADER

#ifndef ROL_PH_STATUSTEST_H
#define ROL_PH_STATUSTEST_H

#include "ROL_StatusTest.hpp"

/** \class ROL::PH_StatusTest
    \brief Provides an interface to check status of the progressive hedging algorithm.
*/


namespace ROL {

template <class Real>
class PH_StatusTest : public StatusTest<Real> {
private:

  Real mu_;
  Real epsilon_;
  Ptr<const Vector<Real>> xbar_;
  Real tol_;
  Ptr<Vector<Real>> x_;

public:

  PH_StatusTest( ROL::ParameterList &parlist, const Vector<Real> &x ) {
    mu_      = parlist.sublist("SOL").sublist("Progressive Hedging").get("Fixed Tolerance", 1e-4);
    epsilon_ = parlist.sublist("SOL").sublist("Progressive Hedging").get("Dynamic Tolerance", 0.1);
    x_       = x.clone();
  }

  void setData(const int iter, const Ptr<const Vector<Real>> &xbar) {
    const Real one(1);
    tol_   = mu_*std::pow(one-epsilon_,iter+1);
    xbar_  = xbar;
  }

  bool check( AlgorithmState<Real> &state ) {
    const Real one(1);
    x_->set(*state.iterateVec); x_->axpy(-one,*xbar_);
    Real xnorm = x_->norm();
    if ( state.gnorm <= tol_*std::min(one,xnorm) ) {
      state.statusFlag = EXITSTATUS_USERDEFINED;
      return false;
    }
    return true;
  }

}; // class PH_StatusTest

} // namespace ROL

#endif
