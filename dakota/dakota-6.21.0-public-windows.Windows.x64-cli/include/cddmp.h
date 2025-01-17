/*
  $Id: cddmp.h 149 2009-11-12 02:40:41Z tplante $
  $URL: https://software.sandia.gov/svn/hopspack/trunk/src/src-citizens/citizen-gss/cddlib/cddmp.h $
*/

/*@HEADER
 * ************************************************************************
 * 
 *         HOPSPACK: Hybrid Optimization Parallel Search Package
 *               Copyright (2003-2009) Sandia Corporation
 * 
 * Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
 * the U.S. Government retains certain rights in this software.
 * 
 * This file is part of HOPSPACK.
 *
 * HOPSPACK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *  
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *  
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see http://www.gnu.org/licenses/.
 * 
 * Questions? Contact Tammy Kolda (tgkolda@sandia.gov) 
 *                 or Todd Plantenga (tplante@sandia.gov)
 * 
 * ************************************************************************
 *@HEADER
 */

/*!
  \file cddmp.h
  \brief Part of <A href="http://www.ifor.math.ethz.ch/~fukuda/cdd_home/cdd.html">cdd</a> library.

  This file is from cddlib, version 0.94, and was downloaded from 
  http://www.ifor.math.ethz.ch/~fukuda/cdd_home/cdd.html
  on Sept. 14, 2005. 
  \author <A href="http://www.ifor.math.ethz.ch/~fukuda">Komei Fukuda</a>, August 4, 2005. 
  \sa \ref sectionCddlib.
*/

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* cddmp.h       (cddlib arithmetic operations using gmp)
   Copyright: Komei Fukuda 2000, fukuda@ifor.math.ethz.ch
   Version 0.94, Aug. 4, 2005
*/

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef  __CDDMP_H
#define  __CDDMP_H
#endif  /* __CDDMP_H */

/**********************************/
/*         MACROS                 */
/* dependent on mp implementation */
/**********************************/

#if defined GMPRATIONAL
 #include "gmp.h"
 #define dd_ARITHMETIC "GMP rational"
 #define dd_init(a)              mpq_init(a)     
 #define dd_clear(a)             mpq_clear(a)     
 #define dd_set(a, b)            mpq_set(a,b)     
 #define dd_set_si(a, b)         ddd_mpq_set_si(a,b)  /* defined in cddgmp.c */
 #define dd_set_si2(a, b, c)     mpq_set_si(a,b,c)    /* gmp 3.1 or higher */
 #define dd_add(a, b, c)         mpq_add(a,b,c)
 #define dd_sub(a, b, c)         mpq_sub(a,b,c)
 #define dd_mul(a, b, c)         mpq_mul(a,b,c)
 #define dd_div(a, b, c)         mpq_div(a,b,c)
 #define dd_neg(a, b)            mpq_neg(a,b)
 #define dd_inv(a, b)            mpq_inv(a,b)
 #define dd_cmp(a, b)            mpq_cmp(a,b)  
    /* returns pos if a>b, 0 if a=b, negative if a<b */
 #define dd_sgn(a)               mpq_sgn(a)
    /* returns nonzero if equal.  much faster than mpq_cmp. */
 #define dd_get_d(a)             mpq_get_d(a)     
#elif defined GMPFLOAT
 #include "gmp.h"
 #define dd_ARITHMETIC "GMP float"
 #define dd_init(a)              mpf_init(a)     
 #define dd_clear(a)             mpf_clear(a)     
 #define dd_set(a, b)            mpf_set(a,b)     
 #define dd_set_d(a, b)          mpf_set_d(a,b)     
 #define dd_set_si(a, b)         mpf_set_si(a,b)     
 #define dd_set_si2(a, b, c)     mpf_set_si(a,b,c)    /* gmp 3.1 or higher */
 #define dd_add(a, b, c)         mpf_add(a,b,c)
 #define dd_sub(a, b, c)         mpf_sub(a,b,c)
 #define dd_mul(a, b, c)         mpf_mul(a,b,c)
 #define dd_div(a, b, c)         mpf_div(a,b,c)
 #define dd_neg(a, b)            mpf_neg(a,b)
 #define dd_inv(a, b)            mpf_inv(a,b)
 #define dd_cmp(a, b)            mpf_cmp(a,b)  
    /* returns pos if a>b, 0 if a=b, negative if a<b */
 #define dd_sgn(a)               mpf_sgn(a)
 #define dd_get_d(a)             mpf_get_d(a)     
#else /* built-in C double */
 #define dd_ARITHMETIC "C double"
 #define dd_CDOUBLE
 #define dd_init(a)              ddd_init(a)     
 #define dd_clear(a)             ddd_clear(a)     
 #define dd_set(a, b)            ddd_set(a,b)     
 #define dd_set_si(a, b)         ddd_set_si(a,b)     
 #define dd_set_si2(a, b, c)     ddd_set_si2(a,b,c)  
 #define dd_set_d(a, b)          ddd_set_d(a,b)     
 #define dd_add(a, b, c)         ddd_add(a,b,c)
 #define dd_sub(a, b, c)         ddd_sub(a,b,c)
 #define dd_mul(a, b, c)         ddd_mul(a,b,c)
 #define dd_div(a, b, c)         ddd_div(a,b,c)
 #define dd_neg(a, b)            ddd_neg(a,b)
 #define dd_inv(a, b)            ddd_inv(a,b)
 #define dd_cmp(a, b)            ddd_cmp(a,b)  
    /* returns pos if a>b, 0 if a=b, negative if a<b */
 #define dd_sgn(a)               ddd_sgn(a)
 #define dd_get_d(a)             ddd_get_d(a)     
#endif


#if defined GMPRATIONAL
 typedef mpq_t mytype;
#elif defined GMPFLOAT
 typedef mpf_t mytype;
#else /* built-in C double */
 typedef double mytype[1];
#endif

void ddd_mpq_set_si(mytype,signed long);
void ddd_init(mytype);  
void ddd_clear(mytype);
void ddd_set(mytype,mytype);
void ddd_set_d(mytype,double);
void ddd_set_si(mytype,signed long);
void ddd_set_si2(mytype,signed long, unsigned long);
void ddd_add(mytype,mytype,mytype);
void ddd_sub(mytype,mytype,mytype);
void ddd_mul(mytype,mytype,mytype);
void ddd_div(mytype,mytype,mytype);
void ddd_neg(mytype,mytype);
void ddd_inv(mytype,mytype);
int ddd_cmp(mytype,mytype);
int ddd_sgn(mytype);
double ddd_get_d(mytype);
void ddd_mpq_set_si(mytype,signed long);

void dd_set_global_constants(void);

/* end of  cddmp.h  */

#endif
