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

#ifndef TEUCHOS_FILEINPUTSTREAM_H
#define TEUCHOS_FILEINPUTSTREAM_H

/*! \file Teuchos_FileInputStream.hpp
    \brief Definition of XMLInputStream derived class for reading XML from a file
*/

#include "Teuchos_ConfigDefs.hpp"
#include "Teuchos_XMLInputStream.hpp"

namespace Teuchos
{
  using std::string;

  /** \ingroup XML
   * \brief Instantiation of XMLInputStream class for reading an entire document from a file.
   * \note This is a low-level object and should not be needed at the user level.
   * FileInputSource is the user-level object.
   */
  class FileInputStream : public XMLInputStream
    {
    public:
      /** \brief Construct with a filename */
      FileInputStream(const std::string& filename);

      /** \brief Destructor */
      virtual ~FileInputStream() { if( file_ ) { std::fclose(file_); } }

      /** \brief Read up to maxToRead bytes */
      virtual unsigned int readBytes(unsigned char* const toFill,
                                     const unsigned int maxToRead);

    private:
      std::FILE* file_;
    };
}
#endif

