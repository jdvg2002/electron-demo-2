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


#ifndef ROL_SAMPLEDVECTOR_H
#define ROL_SAMPLEDVECTOR_H

namespace ROL {

template <class Real, class Key=std::vector<Real>>
class SampledVector {
private:
  // Storage
  std::map<Key, int>                  indices_;
  std::vector<bool>                   flags_;
  std::vector<ROL::Ptr<Vector<Real>>> vectors_;
  int maxIndex_;

  // Update flags
  bool updated_;

  void reset(const bool flag = true) {
    if ( flag ) {
      flags_.assign(flags_.size(),false);
//      typename std::map<Key, int>::iterator it;
//      for (it = indices_.begin(); it != indices_.end(); ++it) {
//        flags_[it->second] = false;
//      }
    }
  }

public:
  /** \brief Constructor.
  */
  SampledVector(void)
    : maxIndex_(0), updated_(false) { 
    indices_.clear();
    flags_.clear();
    vectors_.clear();
  }

  /** \brief Update for SampledVector storage.
  */
  void update(const bool flag = true) {
    updated_ = flag;
    reset(flag);
  }

  /** \brief Return vector corresponding to input parameter.
  */
  bool get(Vector<Real> &x, const Key &param) {
    int count = indices_.count(param);
    bool flag = false;
    int index = maxIndex_;
    if (count) {
      typename std::map<Key, int>::iterator it = indices_.find(param);
      index = it->second;
      flag  = flags_[index];
      if (flag) {
        x.set(*vectors_[index]);
      }
    }
    else {
      indices_.insert(std::pair<Key, int>(param, index));
      flags_.push_back(false);
      vectors_.push_back(x.clone()); 
      maxIndex_++;
    }
    return flag;
  }

  /** \brief Set vector corresponding to input parameter.
  */
  void set(const Vector<Real> &x, const Key &param) {
    int count = indices_.count(param);
    int index = maxIndex_;
    if (count) {
      typename std::map<Key, int>::iterator it = indices_.find(param);
      index = it->second;
      flags_[index] = true;
      vectors_[index]->set(x);
    }
    else {
      indices_.insert(std::pair<Key, int>(param, index));
      flags_.push_back(true);
      vectors_.push_back(x.clone()); 
      vectors_[index]->set(x);
      maxIndex_++;
    }
  }
}; // class SampledVector

} // namespace ROL

#endif
