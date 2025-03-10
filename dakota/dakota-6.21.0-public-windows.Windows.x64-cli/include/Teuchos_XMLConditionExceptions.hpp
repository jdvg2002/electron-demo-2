// @HEADER
// ***********************************************************************
//
//                    Teuchos: Common Tools Package
//                 Copyright (2004) Sandia Corporation
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
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ***********************************************************************
// @HEADER


#ifndef TEUCHOS_XMLCONDITIONEXCEPTIONS_HPP_
#define TEUCHOS_XMLCONDITIONEXCEPTIONS_HPP_

/*! \file Teuchos_XMLConditionExceptions.hpp
 * \brief A collection of Exceptions thrown
 * when converting Conditions to and from
 * XML.
 */
#include <stdexcept>

namespace Teuchos {

/** \brief Thrown when a StringConditon is missing it's Value tag.
 */
class MissingValuesTagException : public std::logic_error{

public:

  /**
   * \brief Constructs an MissingValuesTagException.
   *
   * @param what_arg The error message to be associated with this error.
   */
  MissingValuesTagException(const std::string& what_arg):
    std::logic_error(what_arg){}

};

/** \brief Thrown when an appropriate Condition Converter can't be found */
class CantFindConditionConverterException : public std::logic_error{

public:

  /**
   * \brief Constructs an CantFindConditionConverterException.
   *
   * @param what_arg The error message to be associated with this error.
   */
  CantFindConditionConverterException(const std::string& what_arg):
    std::logic_error(what_arg){}

};



} // namespace Teuchos
#endif //TEUCHOS_XMLCONDITIONEXCEPTIONS_HPP_

