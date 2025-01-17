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

#ifndef TEUCHOS_FUNCTIONOBJECTXMLCONVERTER_HPP
#define TEUCHOS_FUNCTIONOBJECTXMLCONVERTER_HPP

/*! \file Teuchos_FunctionObjectXMLConverter.hpp
 * \brief Converts back and forth between XML
 * and FunctionObjects.
*/

#include "Teuchos_XMLObject.hpp"
#include "Teuchos_Describable.hpp"
#include "Teuchos_XMLParameterListExceptions.hpp"
#include "Teuchos_FunctionObject.hpp"
#include "Teuchos_XMLParameterListReader.hpp"
#include "Teuchos_XMLParameterListWriter.hpp"


namespace Teuchos {


/** \brief An abstract base class for converting FunctionObjects to
 * and from XML.
 */
class TEUCHOSPARAMETERLIST_LIB_DLL_EXPORT FunctionObjectXMLConverter : public Describable {

public:

  /** \name Converter Functions */
  //@{

  /** \brief Converts a given XMLObject to a FunctionObject.
   *
   * @param xmlObj The XMLObject to convert to a FunctionObject.
   * @return The converted FunctionObject.
   */
  RCP<FunctionObject> fromXMLtoFunctionObject(const XMLObject& xmlObj) const;

  /** \brief Preforms any and all special xml conversion that
   * is specific to a
   * particular FunctionObject.
   *
   * @param xmlObj The xml to be converted.
   * @return The converted FunctionObject.
   */
  virtual RCP<FunctionObject> convertXML(const XMLObject& xmlObj) const=0;

  /** \brief Converters a given FunctionObject to XML.
   *
   * @param function The FunctionObject to be converted to XML.
   * @return An XML representation of the given FunctionObject.
   */
  XMLObject fromFunctionObjecttoXML(
    const RCP<const FunctionObject> function) const;

  /** \brief Preforms any and all special FunctionObject conversion that is
   * specific to a particlar FunctionObject.
   *
   * @param function The FunctionObject to be converted.
   * @param xmlObj The XMLObject to store all serialization in.
   */
  virtual void convertFunctionObject(
    const RCP<const FunctionObject> function,
    XMLObject& xmlObj) const = 0;

  //@}

  //! \name Attribute/Query Functions
  //@{

  /** \brief . */
  static const std::string& getTypeAttributeName(){
    static const std::string typeAttributeName = "type";
    return typeAttributeName;
  }

  //@}

};


} // namespace Teuchos


#endif // TEUCHOS_FUNCTIONOBJECTXMLCONVERTER_HPP
