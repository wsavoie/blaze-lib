//=================================================================================================
/*!
//  \file src/mathtest/compressedmatrix/ClassTest.cpp
//  \brief Source file for the CompressedMatrix class test
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/DiagonalMatrix.h>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/DynamicVector.h>
#include <blaze/math/LowerMatrix.h>
#include <blaze/math/UpperMatrix.h>
#include <blaze/util/Complex.h>
#include <blaze/util/Random.h>
#include <blazetest/mathtest/compressedmatrix/ClassTest.h>
#include <blazetest/mathtest/RandomMaximum.h>
#include <blazetest/mathtest/RandomMinimum.h>


namespace blazetest {

namespace mathtest {

namespace compressedmatrix {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the CompressedMatrix class test.
//
// \exception std::runtime_error Operation error detected.
*/
ClassTest::ClassTest()
{
   testConstructors();
   testAssignment();
   testAddAssign();
   testSubAssign();
   testMultAssign();
   testScaling();
   testFunctionCall();
   testIterator();
   testNonZeros();
   testReset();
   testClear();
   testSet();
   testInsert();
   testAppend();
   testErase();
   testResize();
   testReserve();
   testTrim();
   testTranspose();
   testSwap();
   testFind();
   testLowerBound();
   testUpperBound();
   testIsDefault();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the CompressedMatrix constructors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all constructors of the CompressedMatrix class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testConstructors()
{
   //=====================================================================================
   // Row-major default constructor
   //=====================================================================================

   // Default constructor
   {
      test_ = "Row-major CompressedMatrix default constructor";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }


   //=====================================================================================
   // Row-major size constructor
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix size constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 0UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size constructor (0x4)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 4UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size constructor (3x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 0UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size constructor (3x4)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
   }


   //=====================================================================================
   // Row-major size/non-zeros constructor
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix size/non-zeros constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 0UL, 5UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size/non-zeros constructor (0x4)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 4UL, 5UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size/non-zeros constructor (3x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 0UL, 5UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size/non-zeros constructor (3x4)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL, 5UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
   }


   //=====================================================================================
   // Row-major size/vector constructor
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix size/vector constructor (0x0)";

      std::vector<size_t> nonzeros;
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 0UL, nonzeros );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size/vector constructor (0x5)";

      std::vector<size_t> nonzeros;
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 5UL, nonzeros );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix size/vector constructor (3x4)";

      std::vector<size_t> nonzeros( 3UL );
      nonzeros[0] = 2UL;
      nonzeros[1] = 1UL;
      nonzeros[2] = 3UL;
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL, nonzeros );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );

      mat.append( 0UL, 0UL, 1 );
      mat.append( 0UL, 1UL, 2 );
      mat.append( 1UL, 0UL, 3 );
      mat.append( 2UL, 0UL, 4 );
      mat.append( 2UL, 1UL, 5 );
      mat.append( 2UL, 2UL, 6 );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 6UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 3UL );
   }


   //=====================================================================================
   // Row-major copy constructor
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix copy constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 0UL, 0UL, 3UL );
      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( mat1 );

      checkRows    ( mat2, 0UL );
      checkColumns ( mat2, 0UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix copy constructor (0x3)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 0UL, 3UL, 3UL );
      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( mat1 );

      checkRows    ( mat2, 0UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix copy constructor (2x0)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 0UL, 3UL );
      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( mat1 );

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 0UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix copy constructor (2x3)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 3UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( mat1 );

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkCapacity( mat2, 3UL );
      checkNonZeros( mat2, 3UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major default constructor
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix default constructor";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }


   //=====================================================================================
   // Column-major size constructor
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix size constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 0UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size constructor (0x4)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 4UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size constructor (3x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 0UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size constructor (3x4)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
   }


   //=====================================================================================
   // Column-major size/non-zeros constructor
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix size/non-zeros constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 0UL, 5UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size/non-zeros constructor (0x4)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 4UL, 5UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size/non-zeros constructor (3x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 0UL, 5UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size/non-zeros constructor (3x4)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 4UL, 5UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
   }


   //=====================================================================================
   // Column-major size/vector constructor
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix size/vector constructor (0x0)";

      std::vector<size_t> nonzeros;
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 0UL, nonzeros );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size/vector constructor (5x0)";

      std::vector<size_t> nonzeros;
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 0UL, nonzeros );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 0UL );
      checkCapacity( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix size/vector constructor (4x3)";

      std::vector<size_t> nonzeros( 3UL );
      nonzeros[0] = 2UL;
      nonzeros[1] = 1UL;
      nonzeros[2] = 3UL;
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL, nonzeros );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );

      mat.append( 0UL, 0UL, 1 );
      mat.append( 1UL, 0UL, 2 );
      mat.append( 0UL, 1UL, 3 );
      mat.append( 0UL, 2UL, 4 );
      mat.append( 1UL, 2UL, 5 );
      mat.append( 2UL, 2UL, 6 );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 6UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 3UL );
   }


   //=====================================================================================
   // Column-major copy constructor
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix copy constructor (0x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 0UL, 0UL, 3UL );
      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( mat1 );

      checkRows    ( mat2, 0UL );
      checkColumns ( mat2, 0UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix copy constructor (0x3)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 0UL, 3UL, 3UL );
      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( mat1 );

      checkRows    ( mat2, 0UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix copy constructor (2x0)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 0UL, 3UL );
      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( mat1 );

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 0UL );
      checkNonZeros( mat2, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix copy constructor (2x3)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 3UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( mat1 );

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkCapacity( mat2, 3UL );
      checkNonZeros( mat2, 3UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 1UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all assignment operators of the CompressedMatrix class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testAssignment()
{
   //=====================================================================================
   // Row-major copy assignment
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix copy assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 3UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2;
      mat2 = mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkCapacity( mat2, 3UL );
      checkNonZeros( mat2, 3UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major CompressedMatrix copy assignment stress test";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major dense matrix assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 3UL, 2UL, 0 );
      mat1(0,1) = 1;
      mat1(1,1) = 2;
      mat1(2,0) = 3;
      mat1(2,1) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL );
      mat2 = mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 1 ||
          mat2(1,0) != 0 || mat2(1,1) != 2 ||
          mat2(2,0) != 3 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 1 )\n( 0 2 )\n( 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix assignment stress test";

      typedef blaze::DynamicMatrix<int,blaze::rowMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 3UL, 2UL, 0 );
      mat1(0,1) = 1;
      mat1(1,1) = 2;
      mat1(2,0) = 3;
      mat1(2,1) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL );
      mat2 = mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 1 ||
          mat2(1,0) != 0 || mat2(1,1) != 2 ||
          mat2(2,0) != 3 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 1 )\n( 0 2 )\n( 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix assignment stress test";

      typedef blaze::DynamicMatrix<int,blaze::columnMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL );
      mat2 = trans( mat1 );

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 ||
          mat2(2,0) != 1 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 )\n( 0 3 )\n( 1 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix assignment stress test";

      typedef blaze::CompressedMatrix<unsigned int,blaze::rowMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1;
      const unsigned int min( randmin );
      const unsigned int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 2UL );
      mat2 = mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 2UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix assignment stress test";

      typedef blaze::CompressedMatrix<unsigned int,blaze::columnMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1;
      const unsigned int min( randmin );
      const unsigned int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy assignment
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix copy assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 3UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2;
      mat2 = mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkCapacity( mat2, 3UL );
      checkNonZeros( mat2, 3UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 1UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major CompressedMatrix copy assignment stress test";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major dense matrix assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 3UL, 2UL, 0 );
      mat1(0,1) = 1;
      mat1(1,1) = 2;
      mat1(2,0) = 3;
      mat1(2,1) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL );
      mat2 = mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 1 ||
          mat2(1,0) != 0 || mat2(1,1) != 2 ||
          mat2(2,0) != 3 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 1 )\n( 0 2 )\n( 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix assignment stress test";

      typedef blaze::DynamicMatrix<int,blaze::rowMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 3UL, 2UL, 0 );
      mat1(0,1) = 1;
      mat1(1,1) = 2;
      mat1(2,0) = 3;
      mat1(2,1) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL );
      mat2 = mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 1 ||
          mat2(1,0) != 0 || mat2(1,1) != 2 ||
          mat2(2,0) != 3 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 1 )\n( 0 2 )\n( 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix assignment stress test";

      typedef blaze::DynamicMatrix<int,blaze::columnMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1;
      const int min( randmin );
      const int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,0) = 1;
      mat1(0,2) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 2UL );
      mat2 = mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 1 || mat2(0,1) != 0 || mat2(0,2) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 2 )\n( 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix assignment stress test";

      typedef blaze::CompressedMatrix<unsigned int,blaze::rowMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1;
      const unsigned int min( randmin );
      const unsigned int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Column-major/Column-major CompressedMatrix sparse matrix assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL );
      mat2 = trans( mat1 );

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 2UL );
      checkNonZeros( mat2, 4UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 ||
          mat2(1,0) != 0 || mat2(1,1) != 3 ||
          mat2(2,0) != 1 || mat2(2,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 )\n( 0 3 )\n( 1 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix assignment stress test";

      typedef blaze::CompressedMatrix<unsigned int,blaze::columnMajor>  RandomMatrixType;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1;
      const unsigned int min( randmin );
      const unsigned int max( randmax );

      for( size_t i=0UL; i<100UL; ++i )
      {
         const size_t rows   ( blaze::rand<size_t>( 0UL, 10UL ) );
         const size_t columns( blaze::rand<size_t>( 0UL, 10UL ) );
         const RandomMatrixType mat2( blaze::rand<RandomMatrixType>( rows, columns, min, max ) );

         mat1 = mat2;

         if( mat1 != mat2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment failed\n"
                << " Details:\n"
                << "   Result:\n" << mat1 << "\n"
                << "   Expected result:\n" << mat2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL );
      randomize( mat2 );

      mat2 = mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix addition assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the addition assignment operators of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testAddAssign()
{
   //=====================================================================================
   // Row-major dense matrix addition assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix addition assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix addition assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix addition assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix addition assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix addition assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix addition assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix addition assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix addition assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix addition assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 += mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 5 || mat2(0,1) !=  0 || mat2(0,2) != 7 ||
          mat2(1,0) != 2 || mat2(1,1) != 10 || mat2(1,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 5  0 7 )\n( 2 10 4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix addition assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 += mat1;

      if( mat1 != mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix subtraction assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the subtraction assignment operators of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testSubAssign()
{
   //=====================================================================================
   // Row-major dense matrix subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix subtraction assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix subtraction assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix subtraction assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix subtraction assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix subtraction assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix subtraction assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 0 );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix dense matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::DynamicMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix subtraction assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix subtraction assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 2UL, 3UL, 4UL );
      mat1(0,2) = 1;
      mat1(1,0) = 2;
      mat1(1,1) = 3;
      mat1(1,2) = 4;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 2UL, 3UL, 3UL );
      mat2(0,0) = 5;
      mat2(0,2) = 6;
      mat2(1,1) = 7;

      mat2 -= mat1;

      checkRows    ( mat2, 2UL );
      checkColumns ( mat2, 3UL );
      checkNonZeros( mat2, 5UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 1UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) !=  5 || mat2(0,1) != 0 || mat2(0,2) !=  5 ||
          mat2(1,0) != -2 || mat2(1,1) != 4 || mat2(1,2) != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n(  5 0  5 )\n( -2 4 -4 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix subtraction assignment (lower)";

      blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix subtraction assignment (upper)";

      blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major/column-major CompressedMatrix sparse matrix subtraction assignment (diagonal)";

      blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat1( 3UL );
      randomize( mat1 );

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 0 );

      mat2 -= mat1;

      if( mat1 != -mat2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n" << mat2 << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix multiplication assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the multiplication assignment operators of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testMultAssign()
{
   //=====================================================================================
   // Row-major dense matrix multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix dense matrix multiplication assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 3UL, 4UL, 0 );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix multiplication assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 3UL, 4UL, 0 );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major/row-major CompressedMatrix sparse matrix multiplication assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 3UL, 4UL, 5UL );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix multiplication assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 3UL, 4UL, 5UL );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 2UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 2UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix dense matrix multiplication assignment";

      blaze::DynamicMatrix<int,blaze::rowMajor> mat1( 3UL, 4UL, 0 );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 0UL );
      checkNonZeros( mat2, 3UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix dense matrix multiplication assignment";

      blaze::DynamicMatrix<int,blaze::columnMajor> mat1( 3UL, 4UL, 0 );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 0UL );
      checkNonZeros( mat2, 3UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major/row-major CompressedMatrix sparse matrix multiplication assignment";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 3UL, 4UL, 5UL );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 0UL );
      checkNonZeros( mat2, 3UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major/column-major CompressedMatrix sparse matrix multiplication assignment";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 3UL, 4UL, 5UL );
      mat1(0,1) = 2;
      mat1(1,0) = 1;
      mat1(1,1) = 3;
      mat1(1,3) = 4;
      mat1(2,3) = 5;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 3UL, 5UL );
      mat2(0,0) = 1;
      mat2(0,2) = 2;
      mat2(1,1) = 3;
      mat2(2,0) = 4;
      mat2(2,2) = 5;

      mat2 *= mat1;

      checkRows    ( mat2, 3UL );
      checkColumns ( mat2, 4UL );
      checkNonZeros( mat2, 7UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 3UL );
      checkNonZeros( mat2, 2UL, 0UL );
      checkNonZeros( mat2, 3UL, 3UL );

      if( mat2(0,0) != 0 || mat2(0,1) != 2 || mat2(0,2) != 0 || mat2(0,3) != 10 ||
          mat2(1,0) != 3 || mat2(1,1) != 9 || mat2(1,2) != 0 || mat2(1,3) != 12 ||
          mat2(2,0) != 0 || mat2(2,1) != 8 || mat2(2,2) != 0 || mat2(2,3) != 25 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 0 2 0 10 )\n( 3 9 0 12 )\n( 0 8 0 25 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of all CompressedMatrix (self-)scaling operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all available ways to scale an instance of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testScaling()
{
   //=====================================================================================
   // Row-major self-scaling (M*=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M*=s)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat *= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=M*s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=M*s)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat = mat * 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=s*M)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=s*M)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat = 2 * mat;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M/=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M/=s)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  2;
      mat(2,0) = -4;
      mat(2,2) =  6;

      mat /= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 1 ||
          mat(2,0) != -2 || mat(2,1) != 0 || mat(2,2) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 1 )\n( -2 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=M/s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=M/s)";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  2;
      mat(2,0) = -4;
      mat(2,2) =  6;

      mat = mat / 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 1 ||
          mat(2,0) != -2 || mat(2,1) != 0 || mat(2,2) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 1 )\n( -2 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major CompressedMatrix::scale()
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::scale() (int)";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 2UL );
      mat(0,0) = 1;
      mat(1,0) = 2;
      mat(2,1) = 3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,0) != 1 || mat(1,0) != 2 || mat(2,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 )\n( 2 0 )\n( 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Integral scaling of the matrix
      mat.scale( 2 );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,0) != 2 || mat(1,0) != 4 || mat(2,1) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 2 0 )\n( 4 0 )\n( 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Floating point scaling of the matrix
      mat.scale( 0.5 );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,0) != 1 || mat(1,0) != 2 || mat(2,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 )\n( 2 0 )\n( 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major CompressedMatrix::scale() (complex)";

      using blaze::complex;

      blaze::CompressedMatrix<complex<float>,blaze::rowMajor> mat( 2UL, 2UL );
      mat(0,0) = complex<float>( 1.0F, 0.0F );
      mat(1,1) = complex<float>( 2.0F, 0.0F );
      mat.scale( complex<float>( 3.0F, 0.0F ) );

      checkRows    ( mat, 2UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );

      if( mat(0,0) != complex<float>( 3.0F, 0.0F ) || mat(1,1) != complex<float>( 6.0F, 0.0F ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( (3,0) (0,0)\n(0,0) (6,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M*=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M*=s)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat *= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=M*s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=M*s)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat = mat * 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=s*M)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=s*M)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  1;
      mat(2,0) = -2;
      mat(2,2) =  3;

      mat = 2 * mat;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 2 ||
          mat(2,0) != -4 || mat(2,1) != 0 || mat(2,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 2 )\n( -4 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M/=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M/=s)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  2;
      mat(2,0) = -4;
      mat(2,2) =  6;

      mat /= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 1 ||
          mat(2,0) != -2 || mat(2,1) != 0 || mat(2,2) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 1 )\n( -2 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=M/s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=M/s)";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
      mat(1,2) =  2;
      mat(2,0) = -4;
      mat(2,2) =  6;

      mat = mat / 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) !=  0 || mat(0,1) != 0 || mat(0,2) != 0 ||
          mat(1,0) !=  0 || mat(1,1) != 0 || mat(1,2) != 1 ||
          mat(2,0) != -2 || mat(2,1) != 0 || mat(2,2) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 )\n(  0 0 1 )\n( -2 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major CompressedMatrix::scale()
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::scale() (int)";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL );
      mat(0,0) = 1;
      mat(1,0) = 2;
      mat(2,1) = 3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 1UL );

      if( mat(0,0) != 1 || mat(1,0) != 2 || mat(2,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 )\n( 2 0 )\n( 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Integral scaling of the matrix
      mat.scale( 2 );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 1UL );

      if( mat(0,0) != 2 || mat(1,0) != 4 || mat(2,1) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 2 0 )\n( 4 0 )\n( 0 6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Floating point scaling of the matrix
      mat.scale( 0.5 );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 1UL );

      if( mat(0,0) != 1 || mat(1,0) != 2 || mat(2,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 )\n( 2 0 )\n( 0 3 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major CompressedMatrix::scale() (complex)";

      using blaze::complex;

      blaze::CompressedMatrix<complex<float>,blaze::columnMajor> mat( 2UL, 2UL );
      mat(0,0) = complex<float>( 1.0F, 0.0F );
      mat(1,1) = complex<float>( 2.0F, 0.0F );
      mat.scale( complex<float>( 3.0F, 0.0F ) );

      checkRows    ( mat, 2UL );
      checkColumns ( mat, 2UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );

      if( mat(0,0) != complex<float>( 3.0F, 0.0F ) || mat(1,1) != complex<float>( 6.0F, 0.0F ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Scale operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( (3,0) (0,0)\n(0,0) (6,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix function call operator.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of adding and accessing elements via the function call operator
// of the CompressedMatrix class template. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
void ClassTest::testFunctionCall()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::operator()";

      // Assignment to the element (2,1)
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 3UL );
      mat(2,1) = 1;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 1UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(2,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (1,4)
      mat(1,4) = 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(1,4) != 2 || mat(2,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 2 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (0,3)
      mat(0,3) = 3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,3) != 3 || mat(1,4) != 2 || mat(2,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (2,2)
      mat(2,2) = 4;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,3) != 3 || mat(1,4) != 2 || mat(2,1) != 1 || mat(2,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 1 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element (2,1)
      mat(2,1) += mat(0,3);

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,3) != 3 || mat(1,4) != 2 || mat(2,1) != 4 || mat(2,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 4 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element (1,0)
      mat(1,0) -= mat(1,4);

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,3) != 3 || mat(1,0) != -2 || mat(1,4) != 2 || mat(2,1) != 4 || mat(2,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 3 0 )\n( -2 0 0 0 2 )\n(  0 4 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element (0,3)
      mat(0,3) *= -3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,3) != -9 || mat(1,0) != -2 || mat(1,4) != 2 || mat(2,1) != 4 || mat(2,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 -3 0 )\n( -2 0 0  0 2 )\n(  0 4 4  0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element (2,1)
      mat(2,1) /= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,3) != -9 || mat(1,0) != -2 || mat(1,4) != 2 || mat(2,1) != 2 || mat(2,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 -3 0 )\n( -2 0 0  0 2 )\n(  0 2 4  0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::operator()";

      // Assignment to the element (2,1)
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 3UL );
      mat(2,1) = 1;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 1UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );

      if( mat(2,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (1,4)
      mat(1,4) = 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(2,1) != 1 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 2 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (0,3)
      mat(0,3) = 3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(2,1) != 1 || mat(0,3) != 3 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 1 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element (2,2)
      mat(2,2) = 4;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(2,1) != 1 || mat(2,2) != 4 || mat(0,3) != 3 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 1 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element (2,1)
      mat(2,1) += mat(0,3);

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(2,1) != 4 || mat(2,2) != 4 || mat(0,3) != 3 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 3 0 )\n( 0 0 0 0 2 )\n( 0 4 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element (1,0)
      mat(1,0) -= mat(1,4);

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(1,0) != -2 || mat(2,1) != 4 || mat(2,2) != 4 || mat(0,3) != 3 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 3 0 )\n( -2 0 0 0 2 )\n(  0 4 4 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element (0,3)
      mat(0,3) *= -3;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(1,0) != -2 || mat(2,1) != 4 || mat(2,2) != 4 || mat(0,3) != -9 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 -9 0 )\n( -2 0 0  0 2 )\n(  0 4 4  0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element (2,1)
      mat(2,1) /= 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 1UL );

      if( mat(1,0) != -2 || mat(2,1) != 2 || mat(2,2) != 4 || mat(0,3) != -9 || mat(1,4) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n(  0 0 0 -9 0 )\n( -2 0 0  0 2 )\n(  0 2 4  0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the CompressedMatrix iterator implementation.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the iterator implementation of the CompressedMatrix class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIterator()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      typedef blaze::CompressedMatrix<int,blaze::rowMajor>  MatrixType;
      typedef MatrixType::Iterator                          Iterator;
      typedef MatrixType::ConstIterator                     ConstIterator;

      MatrixType mat( 3UL, 3UL, 5UL );
      mat(0,1) =  1;
      mat(1,0) = -2;
      mat(1,2) = -3;
      mat(2,1) =  4;
      mat(2,2) =  5;

      // Testing the Iterator default constructor
      {
         test_ = "Row-major Iterator default constructor";

         Iterator it = Iterator();

         if( it != Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Row-major ConstIterator default constructor";

         ConstIterator it = ConstIterator();

         if( it != ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Row-major Iterator/ConstIterator conversion";

         ConstIterator it( begin( mat, 1UL ) );

         if( it == end( mat, 1UL ) || it->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 0th row via Iterator
      {
         test_ = "Row-major Iterator subtraction";

         const size_t number( end( mat, 0UL ) - begin( mat, 0UL ) );

         if( number != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via ConstIterator
      {
         test_ = "Row-major ConstIterator subtraction";

         const size_t number( cend( mat, 1UL ) - cbegin( mat, 1UL ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Row-major read-only access via ConstIterator";

         ConstIterator it ( cbegin( mat, 2UL ) );
         ConstIterator end( cend( mat, 2UL ) );

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != cend( mat, 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Row-major assignment via Iterator";

         int value = 8;

         for( Iterator it=begin( mat, 2UL ); it!=end( mat, 2UL ); ++it ) {
            *it = value++;
         }

         if( mat(0,0) !=  0 || mat(0,1) != 1 || mat(0,2) !=  0 ||
             mat(1,0) != -2 || mat(1,1) != 0 || mat(1,2) != -3 ||
             mat(2,0) !=  0 || mat(2,1) != 8 || mat(2,2) !=  9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n(  0  1  0 )\n( -2  0 -3 )\n(  0  8  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Row-major addition assignment via Iterator";

         int value = 4;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it += value++;
         }

         if( mat(0,0) != 0 || mat(0,1) != 1 || mat(0,2) != 0 ||
             mat(1,0) != 2 || mat(1,1) != 0 || mat(1,2) != 2 ||
             mat(2,0) != 0 || mat(2,1) != 8 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 1 0 )\n( 2 0 2 )\n( 0 8 9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Row-major subtraction assignment via Iterator";

         int value = 4;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it -= value++;
         }

         if( mat(0,0) !=  0 || mat(0,1) != 1 || mat(0,2) !=  0 ||
             mat(1,0) != -2 || mat(1,1) != 0 || mat(1,2) != -3 ||
             mat(2,0) !=  0 || mat(2,1) != 8 || mat(2,2) !=  9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n(  0  1  0 )\n( -2  0 -3 )\n(  0  8  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Row-major multiplication assignment via Iterator";

         int value = 1;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it *= value++;
         }

         if( mat(0,0) !=  0 || mat(0,1) != 1 || mat(0,2) !=  0 ||
             mat(1,0) != -2 || mat(1,1) != 0 || mat(1,2) != -6 ||
             mat(2,0) !=  0 || mat(2,1) != 8 || mat(2,2) !=  9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n(  0  1  0 )\n( -2  0 -6 )\n(  0  8  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Row-major division assignment via Iterator";

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it /= 2;
         }

         if( mat(0,0) !=  0 || mat(0,1) != 1 || mat(0,2) !=  0 ||
             mat(1,0) != -1 || mat(1,1) != 0 || mat(1,2) != -3 ||
             mat(2,0) !=  0 || mat(2,1) != 8 || mat(2,2) !=  9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n(  0  1  0 )\n( -1  0 -3 )\n(  0  8  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      typedef blaze::CompressedMatrix<int,blaze::columnMajor>  MatrixType;
      typedef MatrixType::Iterator                             Iterator;
      typedef MatrixType::ConstIterator                        ConstIterator;

      MatrixType mat( 3UL, 3UL, 0 );
      mat(1,0) =  1;
      mat(0,1) = -2;
      mat(2,1) = -3;
      mat(1,2) =  4;
      mat(2,2) =  5;

      // Testing the Iterator default constructor
      {
         test_ = "Column-major Iterator default constructor";

         Iterator it = Iterator();

         if( it != Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Column-major ConstIterator default constructor";

         ConstIterator it = ConstIterator();

         if( it != ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Column-major Iterator/ConstIterator conversion";

         ConstIterator it( begin( mat, 1UL ) );

         if( it == end( mat, 1UL ) || it->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 0th column via Iterator
      {
         test_ = "Column-major Iterator subtraction";

         const size_t number( end( mat, 0UL ) - begin( mat, 0UL ) );

         if( number != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via ConstIterator
      {
         test_ = "Column-major ConstIterator subtraction";

         const size_t number( cend( mat, 1UL ) - cbegin( mat, 1UL ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Column-major read-only access via ConstIterator";

         ConstIterator it ( cbegin( mat, 2UL ) );
         ConstIterator end( cend( mat, 2UL ) );

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != cend( mat, 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Column-major assignment via Iterator";

         int value = 8;

         for( Iterator it=begin( mat, 2UL ); it!=end( mat, 2UL ); ++it ) {
            *it = value++;
         }

         if( mat(0,0) != 0 || mat(0,1) != -2 || mat(0,2) != 0 ||
             mat(1,0) != 1 || mat(1,1) !=  0 || mat(1,2) != 8 ||
             mat(2,0) != 0 || mat(2,1) != -3 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 -2  0 )\n( 1  0  8 )\n( 0 -3  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Column-major addition assignment via Iterator";

         int value = 4;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it += value++;
         }

         if( mat(0,0) != 0 || mat(0,1) != 2 || mat(0,2) != 0 ||
             mat(1,0) != 1 || mat(1,1) != 0 || mat(1,2) != 8 ||
             mat(2,0) != 0 || mat(2,1) != 2 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 2 0 )\n( 1 0 8 )\n( 0 2 9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Column-major subtraction assignment via Iterator";

         int value = 4;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it -= value++;
         }

         if( mat(0,0) != 0 || mat(0,1) != -2 || mat(0,2) != 0 ||
             mat(1,0) != 1 || mat(1,1) !=  0 || mat(1,2) != 8 ||
             mat(2,0) != 0 || mat(2,1) != -3 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 -2  0 )\n( 1  0  8 )\n( 0 -3  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Column-major multiplication assignment via Iterator";

         int value = 1;

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it *= value++;
         }

         if( mat(0,0) != 0 || mat(0,1) != -2 || mat(0,2) != 0 ||
             mat(1,0) != 1 || mat(1,1) !=  0 || mat(1,2) != 8 ||
             mat(2,0) != 0 || mat(2,1) != -6 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 -2  0 )\n( 1  0  8 )\n( 0 -6  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Column-major division assignment via Iterator";

         for( Iterator it=begin( mat, 1UL ); it!=end( mat, 1UL ); ++it ) {
            *it /= 2;
         }

         if( mat(0,0) != 0 || mat(0,1) != -1 || mat(0,2) != 0 ||
             mat(1,0) != 1 || mat(1,1) !=  0 || mat(1,2) != 8 ||
             mat(2,0) != 0 || mat(2,1) != -3 || mat(2,2) != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 -1  0 )\n( 1  0  8 )\n( 0 -3  9 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c nonZeros() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c nonZeros() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testNonZeros()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::nonZeros()";

      // Initial check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 6UL, 5UL, 2UL );

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );
      checkNonZeros( mat, 5UL, 0UL );

      // Adding two non-zero elements
      mat(2,2) = 1;
      mat(4,0) = 2;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 1UL );
      checkNonZeros( mat, 5UL, 0UL );

      // Adding a third non-zero element
      mat(1,4) = 3;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 1UL );
      checkNonZeros( mat, 5UL, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::nonZeros()";

      // Initial check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 6UL, 5UL, 2UL );

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );

      // Adding two non-zero elements
      mat(2,2) = 1;
      mat(4,0) = 2;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );

      // Adding a third non-zero element
      mat(1,4) = 3;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 1UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reset() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reset() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testReset()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::reset()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 3UL, 5UL );
      mat(0,0) = 1;
      mat(1,1) = 2;
      mat(1,2) = 3;
      mat(3,1) = 4;
      mat(3,2) = 5;

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 2UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 4 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting a single element
      reset( mat(3,1) );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 1UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 0 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting row 1
      reset( mat, 1UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 1UL );

      if( mat(0,0) != 1 || mat(1,1) != 0 || mat(1,2) != 0 || mat(3,1) != 0 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 0 0 )\n( 0 0 0 )\n( 0 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting the entire matrix
      reset( mat );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::reset()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL, 5UL );
      mat(0,0) = 1;
      mat(1,1) = 2;
      mat(1,2) = 3;
      mat(3,1) = 4;
      mat(3,2) = 5;

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 4 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting a single element
      reset( mat(3,1) );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 0 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting column 1
      reset( mat, 1UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(1,1) != 0 || mat(1,2) != 3 || mat(3,1) != 0 || mat(3,2) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 0 3 )\n( 0 0 0 )\n( 0 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting the entire matrix
      reset( mat );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c clear() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c clear() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testClear()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::clear()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 3UL, 4UL );
      mat(0,0) = 1;
      mat(1,1) = 2;
      mat(1,2) = 3;
      mat(3,1) = 4;

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 1UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing a single element
      clear( mat(1,2) );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 1UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 0 || mat(3,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Clear operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 0 )\n( 0 0 0 )\n( 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing the matrix
      clear( mat );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::clear()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL, 4UL );
      mat(0,0) = 1;
      mat(1,1) = 2;
      mat(1,2) = 3;
      mat(3,1) = 4;

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 3 || mat(3,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Clear operation failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 3 )\n( 0 0 0 )\n( 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing a single element
      clear( mat(1,2) );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );

      if( mat(0,0) != 1 || mat(1,1) != 2 || mat(1,2) != 0 || mat(3,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 2 0 )\n( 0 0 0 )\n( 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing the matrix
      clear( mat );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c set() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c set() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testSet()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::set()";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>::Iterator  Iterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 5UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );

      // Setting a non-zero element
      {
         Iterator pos = mat.set( 2UL, 3UL, 1 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 1 0 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a second non-zero element
      {
         Iterator pos = mat.set( 2UL, 4UL, 2 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 2 || pos->index() != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a third non-zero element
      {
         Iterator pos = mat.set( 2UL, 2UL, 3 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a fourth non-zero element
      {
         Iterator pos = mat.set( 0UL, 1UL, 4 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 4 || pos->index() != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 1\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 || mat(0,1) != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a fifth non-zero element
      {
         Iterator pos = mat.set( 3UL, 2UL, 5 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 5 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 || mat(0,1) != 4 || mat(3,2) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 5 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         Iterator pos = mat.set( 3UL, 2UL, 6 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 6 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 || mat(0,1) != 4 || mat(3,2) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 6 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::set()";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>::Iterator  Iterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 4UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );

      // Setting a non-zero element
      {
         Iterator pos = mat.set( 3UL, 2UL, 1 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 1 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a second non-zero element
      {
         Iterator pos = mat.set( 4UL, 2UL, 2 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 2 || pos->index() != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a third non-zero element
      {
         Iterator pos = mat.set( 2UL, 2UL, 3 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 3 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a fourth non-zero element
      {
         Iterator pos = mat.set( 1UL, 0UL, 4 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 4 || pos->index() != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 1\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 || mat(1,0) != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a fifth non-zero element
      {
         Iterator pos = mat.set( 2UL, 3UL, 5 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 5 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 || mat(1,0) != 4 || mat(2,3) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 5 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         Iterator pos = mat.set( 2UL, 3UL, 6 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 6 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 6\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 || mat(1,0) != 4 || mat(2,3) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 6 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c insert() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c insert() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testInsert()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::insert()";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>::Iterator  Iterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 5UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 5UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );

      // Inserting a non-zero element
      {
         Iterator pos = mat.insert( 2UL, 3UL, 1 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 1 0 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a second non-zero element
      {
         Iterator pos = mat.insert( 2UL, 4UL, 2 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 2 || pos->index() != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a third non-zero element
      {
         Iterator pos = mat.insert( 2UL, 2UL, 3 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a fourth non-zero element
      {
         Iterator pos = mat.insert( 0UL, 1UL, 4 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 4 || pos->index() != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 1\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 || mat(0,1) != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a fifth non-zero element
      {
         Iterator pos = mat.insert( 3UL, 2UL, 5 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 5 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(2,3) != 1 || mat(2,4) != 2 || mat(2,2) != 3 || mat(0,1) != 4 || mat(3,2) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 5 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         mat.insert( 3UL, 2UL, 6 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 4 0 0 0 )\n( 0 0 0 0 0 )\n( 0 0 3 1 2 )\n( 0 0 5 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::insert()";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>::Iterator  Iterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 4UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );

      // Inserting a non-zero element
      {
         Iterator pos = mat.insert( 3UL, 2UL, 1 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 1 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a second non-zero element
      {
         Iterator pos = mat.insert( 4UL, 2UL, 2 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 2 || pos->index() != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a third non-zero element
      {
         Iterator pos = mat.insert( 2UL, 2UL, 3 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 3 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a fourth non-zero element
      {
         Iterator pos = mat.insert( 1UL, 0UL, 4 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( pos->value() != 4 || pos->index() != 1UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 1\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 || mat(1,0) != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 0 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a fifth non-zero element
      {
         Iterator pos = mat.insert( 2UL, 3UL, 5 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 3UL );
         checkNonZeros( mat, 3UL, 1UL );

         if( pos->value() != 5 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat(3,2) != 1 || mat(4,2) != 2 || mat(2,2) != 3 || mat(1,0) != 4 || mat(2,3) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting an element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 5 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         mat.insert( 2UL, 3UL, 6 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 0 )\n( 4 0 0 0 )\n( 0 0 3 5 )\n( 0 0 1 0 )\n( 0 0 2 0 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c append() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c append() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testAppend()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::append()";

      // Appending with pre-allocation in each row
      {
         // Initialization check
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 4UL, 5UL );
         mat.reserve( 0UL, 2UL );
         mat.reserve( 2UL, 1UL );
         mat.reserve( 3UL, 2UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         // Appending one non-zero element
         mat.append( 2UL, 1UL, 1 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(2,1) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 1 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 0UL, 0UL, 2 );
         mat.append( 0UL, 3UL, 3 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(2,1) != 1 || mat(0,0) != 2 || mat(0,3) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 2 0 0 3 )\n( 0 0 0 0 )\n( 0 1 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 3UL, 1UL, 4 );
         mat.append( 3UL, 2UL, 5 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 2UL );

         if( mat(2,1) != 1 || mat(0,0) != 2 || mat(0,3) != 3 || mat(3,1) != 4 || mat(3,2) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 2 0 0 3 )\n( 0 0 0 0 )\n( 0 1 0 0 )\n( 0 4 5 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Appending with row finalization
      {
         // Initialization check
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 4UL, 4UL, 5UL );
         mat.reserve( 0UL, 2UL );
         mat.reserve( 2UL, 1UL );
         mat.reserve( 3UL, 2UL );

         // Appending one non-zero element
         mat.append( 0UL, 1UL, 1 );
         mat.finalize( 0UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(0,1) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 1UL, 1UL, 2 );
         mat.append( 1UL, 3UL, 3 );
         mat.finalize( 1UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(0,1) != 1 || mat(1,1) != 2 || mat(1,3) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n( 0 2 0 3 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 3UL, 0UL, 4 );
         mat.append( 3UL, 1UL, 5 );
         mat.finalize( 3UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 2UL );

         if( mat(0,1) != 1 || mat(1,1) != 2 || mat(1,3) != 3 || mat(3,0) != 4 || mat(3,1) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n( 0 2 0 3 )\n( 0 0 0 0 )\n( 4 5 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::append()";

      // Appending with pre-allocation in each column
      {
         // Initialization check
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 4UL, 5UL );
         mat.reserve( 0UL, 2UL );
         mat.reserve( 2UL, 1UL );
         mat.reserve( 3UL, 2UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         // Appending one non-zero element
         mat.append( 1UL, 2UL, 1 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(1,2) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 0 0 1 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 0UL, 0UL, 2 );
         mat.append( 3UL, 0UL, 3 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(1,2) != 1 || mat(0,0) != 2 || mat(3,0) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 2 0 0 0 )\n( 0 0 1 0 )\n( 0 0 0 0 )\n( 3 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 1UL, 3UL, 4 );
         mat.append( 2UL, 3UL, 5 );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 2UL );

         if( mat(1,2) != 1 || mat(0,0) != 2 || mat(3,0) != 3 || mat(1,3) != 4 || mat(2,3) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 2 0 0 0 )\n( 0 0 1 4 )\n( 0 0 0 5 )\n( 3 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Appending with column finalization
      {
         // Initialization check
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 4UL, 5UL );
         mat.reserve( 0UL, 2UL );
         mat.reserve( 2UL, 1UL );
         mat.reserve( 3UL, 2UL );

         // Appending one non-zero element
         mat.append( 1UL, 0UL, 1 );
         mat.finalize( 0UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(1,0) != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 1 0 0 0 )\n( 0 0 0 0 )\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 1UL, 1UL, 2 );
         mat.append( 3UL, 1UL, 3 );
         mat.finalize( 1UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 0UL );

         if( mat(1,0) != 1 || mat(1,1) != 2 || mat(3,1) != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n( 1 2 0 0 )\n( 0 0 0 0 )\n( 0 3 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         // Appending two more non-zero elements
         mat.append( 0UL, 3UL, 4 );
         mat.append( 1UL, 3UL, 5 );
         mat.finalize( 3UL );

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 4UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 0UL );
         checkNonZeros( mat, 3UL, 2UL );

         if( mat(1,0) != 1 || mat(1,1) != 2 || mat(3,1) != 3 || mat(0,3) != 4 || mat(1,3) != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Append operation failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 4 )\n( 1 2 0 5 )\n( 0 0 0 0 )\n( 0 3 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c erase() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c erase() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testErase()
{
   //=====================================================================================
   // Row-major index-based erase function
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::erase( size_t, size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL );
      mat(0,0) = 1;
      mat(0,2) = 2;
      mat(1,1) = 3;
      mat(1,2) = 4;
      mat(1,4) = 5;
      mat(2,1) = 6;
      mat(2,4) = 7;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
          mat(2,1) != 6 || mat(2,4) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (0,0)
      mat.erase( 0UL, size_t(0) );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 6UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
          mat(2,1) != 6 || mat(2,4) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (1,2)
      mat.erase( 1UL, 2UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,4) != 5 ||
          mat(2,1) != 6 || mat(2,4) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (2,4)
      mat.erase( 2UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,4) != 5 ||
          mat(2,1) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase a zero element
      mat.erase( 0UL, 1UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,4) != 5 ||
          mat(2,1) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::erase( size_t, Iterator )";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>  MatrixType;
      typedef MatrixType::Iterator  Iterator;

      // Initialization check
      MatrixType mat( 3UL, 5UL );
      mat(0,0) = 1;
      mat(0,2) = 2;
      mat(1,1) = 3;
      mat(1,2) = 4;
      mat(1,4) = 5;
      mat(2,1) = 6;
      mat(2,4) = 7;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
          mat(2,1) != 6 || mat(2,4) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (0,0)
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 0UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
             mat(2,1) != 6 || mat(2,4) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 2 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the element at (1,2)
      {
         Iterator pos = mat.erase( 1UL, mat.find( 1UL, 2UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 || mat(2,4) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 5 || pos->index() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the element at (2,4)
      {
         Iterator pos = mat.erase( 2UL, mat.find( 2UL, 4UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase a zero element
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 1UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 0UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::erase( size_t, Iterator, Iterator )";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>  MatrixType;
      typedef MatrixType::Iterator  Iterator;

      // Initialization check
      MatrixType mat( 3UL, 5UL );
      mat(0,0) = 1;
      mat(0,2) = 2;
      mat(1,1) = 3;
      mat(1,2) = 4;
      mat(1,4) = 5;
      mat(2,1) = 6;
      mat(2,4) = 7;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(0,2) != 2 ||
          mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
          mat(2,1) != 6 || mat(2,4) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the elements from (0,0) to (0,2)
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 0UL ), mat.find( 0UL, 2UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,2) != 4 || mat(1,4) != 5 ||
             mat(2,1) != 6 || mat(2,4) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 4 0 5 )\n( 0 6 0 0 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 2 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the elements from (1,2) to (1,4)
      {
         Iterator pos = mat.erase( 1UL, mat.find( 1UL, 2UL ), mat.find( 1UL, 4UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 || mat(2,4) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 5 || pos->index() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the elements from (2,4) to the row end
      {
         Iterator pos = mat.erase( 2UL, mat.find( 2UL, 4UL ), mat.end( 2UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 2UL ), mat.find( 0UL, 2UL ) );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(0,2) != 2 ||
             mat(1,1) != 3 || mat(1,4) != 5 ||
             mat(2,1) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 2 0 0 )\n( 0 3 0 0 5 )\n( 0 6 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.find( 0UL, 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major index-based erase function
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::erase( size_t, size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL );
      mat(0,0) = 1;
      mat(2,0) = 2;
      mat(1,1) = 3;
      mat(2,1) = 4;
      mat(4,1) = 5;
      mat(1,2) = 6;
      mat(4,2) = 7;

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
          mat(1,2) != 6 || mat(4,2) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (0,0)
      mat.erase( 0UL, size_t(0) );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 6UL );
      checkNonZeros( mat, 6UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
          mat(1,2) != 6 || mat(4,2) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (2,1)
      mat.erase( 2UL, 1UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 5UL );
      checkNonZeros( mat, 5UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(4,1) != 5 ||
          mat(1,2) != 6 || mat(4,2) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (4,2)
      mat.erase( 4UL, 2UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(4,1) != 5 ||
          mat(1,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase a zero element
      mat.erase( 0UL, 1UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(4,1) != 5 ||
          mat(1,2) != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::erase( size_t, Iterator )";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>  MatrixType;
      typedef MatrixType::Iterator  Iterator;

      // Initialization check
      MatrixType mat( 5UL, 3UL );
      mat(0,0) = 1;
      mat(2,0) = 2;
      mat(1,1) = 3;
      mat(2,1) = 4;
      mat(4,1) = 5;
      mat(1,2) = 6;
      mat(4,2) = 7;

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
          mat(1,2) != 6 || mat(4,2) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the element at (0,0)
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 0UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
             mat(1,2) != 6 || mat(4,2) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 2 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the element at (2,1)
      {
         Iterator pos = mat.erase( 1UL, mat.find( 2UL, 1UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 || mat(4,2) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 5 || pos->index() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the element at (4,2)
      {
         Iterator pos = mat.erase( 2UL, mat.find( 4UL, 2UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase a zero element
      {
         Iterator pos = mat.erase( 1UL, mat.find( 0UL, 1UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::erase( size_t, Iterator, Iterator )";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>  MatrixType;
      typedef MatrixType::Iterator  Iterator;

      // Initialization check
      MatrixType mat( 5UL, 3UL );
      mat(0,0) = 1;
      mat(2,0) = 2;
      mat(1,1) = 3;
      mat(2,1) = 4;
      mat(4,1) = 5;
      mat(1,2) = 6;
      mat(4,2) = 7;

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 7UL );
      checkNonZeros( mat, 7UL );
      checkNonZeros( mat, 0UL, 2UL );
      checkNonZeros( mat, 1UL, 3UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(0,0) != 1 || mat(2,0) != 2 ||
          mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
          mat(1,2) != 6 || mat(4,2) != 7 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 1 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the elements from (0,0) to (2,0)
      {
         Iterator pos = mat.erase( 0UL, mat.find( 0UL, 0UL ), mat.find( 2UL, 0UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(2,1) != 4 || mat(4,1) != 5 ||
             mat(1,2) != 6 || mat(4,2) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 4 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 2 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the elements from (2,1) to (4,1)
      {
         Iterator pos = mat.erase( 1UL, mat.find( 2UL, 1UL ), mat.find( 4UL, 1UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 || mat(4,2) != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos->value() != 5 || pos->index() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the elements from (4,2) to the column end
      {
         Iterator pos = mat.erase( 2UL, mat.find( 4UL, 2UL ), mat.end( 2UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a single-element range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         Iterator pos = mat.erase( 0UL, mat.find( 2UL, 0UL ), mat.find( 2UL, 0UL ) );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( mat(2,0) != 2 ||
             mat(1,1) != 3 || mat(4,1) != 5 ||
             mat(1,2) != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 0 0 0 )\n( 0 3 6 )\n( 2 0 0 )\n( 0 0 0 )\n( 0 5 0 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( pos != mat.find( 2UL, 0UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c resize() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c resize() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testResize()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::resize()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 0x3
      mat.resize( 0UL, 3UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 5x0
      mat.resize( 5UL, 0UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 3x4
      mat.resize( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );

      // Resizing to 5x3 and preserving the elements
      mat(1,0) = 1;
      mat(2,2) = 2;
      mat.resize( 5UL, 3UL, true );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 1 0 0 )\n( 0 0 2 )\n( 0 0 0 )\n( 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x4 and preserving the elements
      mat(0,1) = 3;
      mat.resize( 4UL, 4UL, true );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 0 )\n( 1 0 0 0 )\n( 0 0 2 0 )\n( 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 6x5 and preserving the elements
      mat(3,2) = 4;
      mat.resize( 6UL, 5UL, true );

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 0UL );
      checkNonZeros( mat, 5UL, 0UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 || mat(3,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 0 0 )\n( 1 0 0 0 0 )\n( 0 0 2 0 0 )\n"
                                     "( 0 0 4 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x3 and preserving the elements
      mat(0,4) = 5;
      mat(5,2) = 6;
      mat(5,4) = 7;
      mat.resize( 4UL, 3UL, true );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 || mat(3,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 )\n( 1 0 0 )\n( 0 0 2 )\n( 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 2x2
      mat.resize( 2UL, 2UL );

      checkRows   ( mat, 2UL );
      checkColumns( mat, 2UL );

      // Resizing to 0x0
      mat.resize( 0UL, 0UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::resize()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 0x3
      mat.resize( 0UL, 3UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 5x0
      mat.resize( 5UL, 0UL );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Resizing to 3x4
      mat.resize( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 0UL );
      checkNonZeros( mat, 3UL, 0UL );

      // Resizing to 5x3 and preserving the elements
      mat(1,0) = 1;
      mat(2,2) = 2;
      mat.resize( 5UL, 3UL, true );

      checkRows    ( mat, 5UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 0 0 )\n( 1 0 0 )\n( 0 0 2 )\n( 0 0 0 )\n( 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x4 and preserving the elements
      mat(0,1) = 3;
      mat.resize( 4UL, 4UL, true );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 4UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 0 )\n( 1 0 0 0 )\n( 0 0 2 0 )\n( 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 6x5 and preserving the elements
      mat(3,2) = 4;
      mat.resize( 6UL, 5UL, true );

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 5UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 || mat(3,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 0 0 )\n( 1 0 0 0 0 )\n( 0 0 2 0 0 )\n"
                                     "( 0 0 4 0 0 )\n( 0 0 0 0 0 )\n( 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x3 and preserving the elements
      mat(0,4) = 5;
      mat(5,2) = 6;
      mat(5,4) = 7;
      mat.resize( 4UL, 3UL, true );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 4UL );
      checkNonZeros( mat, 4UL );
      checkNonZeros( mat, 0UL, 1UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 2UL );

      if( mat(1,0) != 1 || mat(2,2) != 2 || mat(0,1) != 3 || mat(3,2) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n"
             << "   Expected result:\n( 0 3 0 )\n( 1 0 0 )\n( 0 0 2 )\n( 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 2x2
      mat.resize( 2UL, 2UL );

      checkRows   ( mat, 2UL );
      checkColumns( mat, 2UL );

      // Resizing to 0x0
      mat.resize( 0UL, 0UL );

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reserve() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reserve() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testReserve()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::reserve()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Increasing the capacity of the matrix
      mat.reserve( 10UL );

      checkRows    ( mat,  0UL );
      checkColumns ( mat,  0UL );
      checkCapacity( mat, 10UL );
      checkNonZeros( mat,  0UL );

      // Further increasing the capacity of the matrix
      mat.reserve( 20UL );

      checkRows    ( mat,  0UL );
      checkColumns ( mat,  0UL );
      checkCapacity( mat, 20UL );
      checkNonZeros( mat,  0UL );
   }

   {
      test_ = "Row-major CompressedMatrix::reserve( size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );

      // Increasing the capacity of the 2nd row
      mat.reserve( 2UL, 10UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 10UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 10UL );

      // Increasing the capacity of the 0th row
      mat.reserve( 0UL, 20UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 30UL );
      checkCapacity( mat,  0UL, 20UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 10UL );

      // Increasing the capacity of the 1st row
      mat.reserve( 1UL, 15UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 20UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 10UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::reserve()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat;

      checkRows    ( mat, 0UL );
      checkColumns ( mat, 0UL );
      checkNonZeros( mat, 0UL );

      // Increasing the capacity of the matrix
      mat.reserve( 10UL );

      checkRows    ( mat,  0UL );
      checkColumns ( mat,  0UL );
      checkCapacity( mat, 10UL );
      checkNonZeros( mat,  0UL );

      // Further increasing the capacity of the matrix
      mat.reserve( 20UL );

      checkRows    ( mat,  0UL );
      checkColumns ( mat,  0UL );
      checkCapacity( mat, 20UL );
      checkNonZeros( mat,  0UL );
   }

   {
      test_ = "Column-major CompressedMatrix::reserve( size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 0UL );

      // Increasing the capacity of the 2nd column
      mat.reserve( 2UL, 10UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 10UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 10UL );

      // Increasing the capacity of the 0th column
      mat.reserve( 0UL, 20UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 30UL );
      checkCapacity( mat,  0UL, 20UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 10UL );

      // Increasing the capacity of the 1st column
      mat.reserve( 1UL, 15UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 20UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 10UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c trim() member functions of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c trim() member functions of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testTrim()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::trim()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );

      // Increasing the row capacity of the matrix
      mat.reserve( 0UL, 10UL );
      mat.reserve( 1UL, 15UL );
      mat.reserve( 2UL, 20UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 10UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the matrix
      mat.trim();

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 0UL );
      checkCapacity( mat,  1UL, 0UL );
      checkCapacity( mat,  2UL, 0UL );
   }

   {
      test_ = "Row-major CompressedMatrix::trim( size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 4UL );

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 4UL );
      checkNonZeros( mat, 0UL );

      // Increasing the row capacity of the matrix
      mat.reserve( 0UL, 10UL );
      mat.reserve( 1UL, 15UL );
      mat.reserve( 2UL, 20UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 10UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the 0th row
      mat.trim( 0UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL, 25UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the 1st row
      mat.trim( 1UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 45UL );

      // Trimming the 2nd row
      mat.trim( 2UL );

      checkRows    ( mat,  3UL );
      checkColumns ( mat,  4UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 0UL );
      checkCapacity( mat,  1UL, 0UL );
      checkCapacity( mat,  2UL, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::trim()";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 0UL );

      // Increasing the column capacity of the matrix
      mat.reserve( 0UL, 10UL );
      mat.reserve( 1UL, 15UL );
      mat.reserve( 2UL, 20UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 10UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the matrix
      mat.trim();

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 0UL );
      checkCapacity( mat,  1UL, 0UL );
      checkCapacity( mat,  2UL, 0UL );
   }

   {
      test_ = "Column-major CompressedMatrix::trim( size_t )";

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 4UL, 3UL );

      checkRows    ( mat, 4UL );
      checkColumns ( mat, 3UL );
      checkNonZeros( mat, 0UL );

      // Increasing the column capacity of the matrix
      mat.reserve( 0UL, 10UL );
      mat.reserve( 1UL, 15UL );
      mat.reserve( 2UL, 20UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 10UL );
      checkCapacity( mat,  1UL, 15UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the 0th column
      mat.trim( 0UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL, 25UL );
      checkCapacity( mat,  2UL, 20UL );

      // Trimming the 1st column
      mat.trim( 1UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL,  0UL );
      checkCapacity( mat,  1UL,  0UL );
      checkCapacity( mat,  2UL, 45UL );

      // Trimming the 2nd column
      mat.trim( 2UL );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  3UL );
      checkCapacity( mat, 45UL );
      checkCapacity( mat,  0UL, 0UL );
      checkCapacity( mat,  1UL, 0UL );
      checkCapacity( mat,  2UL, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c transpose() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c transpose() member function of the CompressedMatrix
// class template. Additionally, it performs a test of self-transpose via the \c trans()
// function. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testTranspose()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major self-transpose via CompressedMatrix::transpose()";

      // Self-transpose of a 3x5 matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(0,4) = 3;
         mat(1,1) = 4;
         mat(1,3) = 5;
         mat(2,0) = 6;
         mat(2,2) = 7;
         mat(2,4) = 8;

         mat.transpose();

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 2UL );

         if( mat(0,0) != 1 || mat(2,0) != 2 || mat(4,0) != 3 || mat(1,1) != 4 ||
             mat(3,1) != 5 || mat(0,2) != 6 || mat(2,2) != 7 || mat(4,2) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 6 )\n( 0 4 0 )\n( 2 0 7 )\n( 0 5 0 )\n( 3 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Self-transpose of a 5x3 matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 5UL, 3UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 6;
         mat(1,1) = 4;
         mat(2,0) = 2;
         mat(2,2) = 7;
         mat(3,1) = 5;
         mat(4,0) = 3;
         mat(4,2) = 8;

         mat.transpose();

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( mat(0,0) != 1 || mat(0,1) != 0 || mat(0,2) != 2 || mat(0,3) != 0 || mat(0,4) != 3 ||
             mat(1,0) != 0 || mat(1,1) != 4 || mat(1,2) != 0 || mat(1,3) != 5 || mat(1,4) != 0 ||
             mat(2,0) != 6 || mat(2,1) != 0 || mat(2,2) != 7 || mat(2,3) != 0 || mat(2,4) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 2 0 3 )\n( 0 4 0 5 0 )\n( 6 0 7 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Row-major self-transpose via trans()";

      // Self-transpose of a 3x5 matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(0,4) = 3;
         mat(1,1) = 4;
         mat(1,3) = 5;
         mat(2,0) = 6;
         mat(2,2) = 7;
         mat(2,4) = 8;

         mat = trans( mat );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 2UL );

         if( mat(0,0) != 1 || mat(2,0) != 2 || mat(4,0) != 3 || mat(1,1) != 4 ||
             mat(3,1) != 5 || mat(0,2) != 6 || mat(2,2) != 7 || mat(4,2) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 6 )\n( 0 4 0 )\n( 2 0 7 )\n( 0 5 0 )\n( 3 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Self-transpose of a 5x3 matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 5UL, 3UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 6;
         mat(1,1) = 4;
         mat(2,0) = 2;
         mat(2,2) = 7;
         mat(3,1) = 5;
         mat(4,0) = 3;
         mat(4,2) = 8;

         mat = trans( mat );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( mat(0,0) != 1 || mat(0,1) != 0 || mat(0,2) != 2 || mat(0,3) != 0 || mat(0,4) != 3 ||
             mat(1,0) != 0 || mat(1,1) != 4 || mat(1,2) != 0 || mat(1,3) != 5 || mat(1,4) != 0 ||
             mat(2,0) != 6 || mat(2,1) != 0 || mat(2,2) != 7 || mat(2,3) != 0 || mat(2,4) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 2 0 3 )\n( 0 4 0 5 0 )\n( 6 0 7 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major self-transpose via CompressedMatrix::transpose()";

      // Self-transpose of a 3x5 matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(0,4) = 3;
         mat(1,1) = 4;
         mat(1,3) = 5;
         mat(2,0) = 6;
         mat(2,2) = 7;
         mat(2,4) = 8;

         mat.transpose();

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( mat(0,0) != 1 || mat(2,0) != 2 || mat(4,0) != 3 || mat(1,1) != 4 ||
             mat(3,1) != 5 || mat(0,2) != 6 || mat(2,2) != 7 || mat(4,2) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 6 )\n( 0 4 0 )\n( 2 0 7 )\n( 0 5 0 )\n( 3 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Self-transpose of a 5x3 matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 6;
         mat(1,1) = 4;
         mat(2,0) = 2;
         mat(2,2) = 7;
         mat(3,1) = 5;
         mat(4,0) = 3;
         mat(4,2) = 8;

         mat.transpose();

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 2UL );

         if( mat(0,0) != 1 || mat(0,1) != 0 || mat(0,2) != 2 || mat(0,3) != 0 || mat(0,4) != 3 ||
             mat(1,0) != 0 || mat(1,1) != 4 || mat(1,2) != 0 || mat(1,3) != 5 || mat(1,4) != 0 ||
             mat(2,0) != 6 || mat(2,1) != 0 || mat(2,2) != 7 || mat(2,3) != 0 || mat(2,4) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 2 0 3 )\n( 0 4 0 5 0 )\n( 6 0 7 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }

   {
      test_ = "Column-major self-transpose via trans()";

      // Self-transpose of a 3x5 matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(0,4) = 3;
         mat(1,1) = 4;
         mat(1,3) = 5;
         mat(2,0) = 6;
         mat(2,2) = 7;
         mat(2,4) = 8;

         mat = trans( mat );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( mat(0,0) != 1 || mat(2,0) != 2 || mat(4,0) != 3 || mat(1,1) != 4 ||
             mat(3,1) != 5 || mat(0,2) != 6 || mat(2,2) != 7 || mat(4,2) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 6 )\n( 0 4 0 )\n( 2 0 7 )\n( 0 5 0 )\n( 3 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Self-transpose of a 5x3 matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 8UL );
         mat(0,0) = 1;
         mat(0,2) = 6;
         mat(1,1) = 4;
         mat(2,0) = 2;
         mat(2,2) = 7;
         mat(3,1) = 5;
         mat(4,0) = 3;
         mat(4,2) = 8;

         mat.transpose();

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 8UL );
         checkNonZeros( mat, 8UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 2UL );

         if( mat(0,0) != 1 || mat(0,1) != 0 || mat(0,2) != 2 || mat(0,3) != 0 || mat(0,4) != 3 ||
             mat(1,0) != 0 || mat(1,1) != 4 || mat(1,2) != 0 || mat(1,3) != 5 || mat(1,4) != 0 ||
             mat(2,0) != 6 || mat(2,1) != 0 || mat(2,2) != 7 || mat(2,3) != 0 || mat(2,4) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << mat << "\n"
                << "   Expected result:\n( 1 0 2 0 3 )\n( 0 4 0 5 0 )\n( 6 0 7 0 8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c swap() functionality of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c swap() function of the CompressedMatrix class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testSwap()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix swap";

      blaze::CompressedMatrix<int,blaze::rowMajor> mat1( 5UL, 2UL );
      mat1(0,0) = 1;
      mat1(3,1) = 2;

      blaze::CompressedMatrix<int,blaze::rowMajor> mat2( 3UL, 4UL );
      mat2(0,1) = 3;
      mat2(0,2) = 4;
      mat2(2,0) = 5;

      swap( mat1, mat2 );

      checkRows    ( mat1, 3UL );
      checkColumns ( mat1, 4UL );
      checkCapacity( mat1, 3UL );
      checkNonZeros( mat1, 3UL );
      checkNonZeros( mat1, 0UL, 2UL );
      checkNonZeros( mat1, 1UL, 0UL );
      checkNonZeros( mat1, 2UL, 1UL );

      if( mat1(0,1) != 3 || mat1(0,2) != 4 || mat1(2,0) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the first matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n( 0 3 4 )\n( 0 0 0 )\n( 5 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      checkRows    ( mat2, 5UL );
      checkColumns ( mat2, 2UL );
      checkCapacity( mat2, 2UL );
      checkNonZeros( mat2, 2UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 0UL );
      checkNonZeros( mat2, 2UL, 0UL );
      checkNonZeros( mat2, 3UL, 1UL );
      checkNonZeros( mat2, 4UL, 0UL );

      if( mat2(0,0) != 1 || mat2(3,1) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the second matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 )\n( 0 0 )\n( 0 0 )\n( 0 2 )\n( 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix swap";

      blaze::CompressedMatrix<int,blaze::columnMajor> mat1( 5UL, 2UL );
      mat1(0,0) = 1;
      mat1(3,1) = 2;

      blaze::CompressedMatrix<int,blaze::columnMajor> mat2( 3UL, 4UL );
      mat2(0,1) = 3;
      mat2(0,2) = 4;
      mat2(2,0) = 5;

      swap( mat1, mat2 );

      checkRows    ( mat1, 3UL );
      checkColumns ( mat1, 4UL );
      checkCapacity( mat1, 3UL );
      checkNonZeros( mat1, 3UL );
      checkNonZeros( mat1, 0UL, 1UL );
      checkNonZeros( mat1, 1UL, 1UL );
      checkNonZeros( mat1, 2UL, 1UL );
      checkNonZeros( mat1, 3UL, 0UL );

      if( mat1(0,1) != 3 || mat1(0,2) != 4 || mat1(2,0) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the first matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat1 << "\n"
             << "   Expected result:\n( 0 3 4 0 )\n( 0 0 0 0 )\n( 5 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      checkRows    ( mat2, 5UL );
      checkColumns ( mat2, 2UL );
      checkCapacity( mat2, 2UL );
      checkNonZeros( mat2, 2UL );
      checkNonZeros( mat2, 0UL, 1UL );
      checkNonZeros( mat2, 1UL, 1UL );

      if( mat2(0,0) != 1 || mat2(3,1) != 2 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the second matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << mat2 << "\n"
             << "   Expected result:\n( 1 0 )\n( 0 0 )\n( 0 0 )\n( 0 2 )\n( 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c find() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c find() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testFind()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::find()";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 8UL, 6UL, 3UL );
      mat(1,2) = 1;
      mat(2,3) = 2;
      mat(6,5) = 3;

      checkRows    ( mat, 8UL );
      checkColumns ( mat, 6UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 1UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 0UL );
      checkNonZeros( mat, 4UL, 0UL );
      checkNonZeros( mat, 5UL, 0UL );
      checkNonZeros( mat, 6UL, 1UL );
      checkNonZeros( mat, 7UL, 0UL );

      // Searching for the first element
      {
         ConstIterator pos( mat.find( 1UL, 2UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (1,2)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         ConstIterator pos( mat.find( 2UL, 3UL ) );

         if( pos == mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (2,3)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the third element
      {
         ConstIterator pos( mat.find( 6UL, 5UL ) );

         if( pos == mat.end( 6UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (6,5)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 5 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 5\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         ConstIterator pos( mat.find( 4UL, 0UL ) );

         if( pos != mat.end( 4UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::find()";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 8UL, 6UL, 3UL );
      mat(1,2) = 1;
      mat(2,3) = 2;
      mat(6,5) = 3;

      checkRows    ( mat, 8UL );
      checkColumns ( mat, 6UL );
      checkCapacity( mat, 3UL );
      checkNonZeros( mat, 3UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 0UL );
      checkNonZeros( mat, 2UL, 1UL );
      checkNonZeros( mat, 3UL, 1UL );
      checkNonZeros( mat, 4UL, 0UL );
      checkNonZeros( mat, 5UL, 1UL );

      // Searching for the first element
      {
         ConstIterator pos( mat.find( 1UL, 2UL ) );

         if( pos == mat.end( 2UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (1,2)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         ConstIterator pos( mat.find( 2UL, 3UL ) );

         if( pos == mat.end( 3UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (2,3)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the third element
      {
         ConstIterator pos( mat.find( 6UL, 5UL ) );

         if( pos == mat.end( 5UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required position = (6,5)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 6 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 6\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         ConstIterator pos( mat.find( 4UL, 0UL ) );

         if( pos != mat.end( 0UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c lowerBound() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c lowerBound() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testLowerBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::lowerBound()";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 6UL, 3UL );
      mat(1,2) = 1;
      mat(1,4) = 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 6UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );

      // Determining the lower bound for position (1,1)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (1,2)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 2UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,2)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (1,3)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 3UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,3)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (1,4)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 4UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,4)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (1,5)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 5UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,5)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::lowerBound()";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 6L, 3UL, 3UL );
      mat(2,1) = 1;
      mat(4,1) = 2;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );

      // Determining the lower bound for position (1,1)
      {
         ConstIterator pos( mat.lowerBound( 1UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (2,1)
      {
         ConstIterator pos( mat.lowerBound( 2UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (2,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (3,1)
      {
         ConstIterator pos( mat.lowerBound( 3UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (3,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (4,1)
      {
         ConstIterator pos( mat.lowerBound( 4UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (4,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for position (5,1)
      {
         ConstIterator pos( mat.lowerBound( 5UL, 1UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (5,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c upperBound() member function of the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c upperBound() member function of the CompressedMatrix
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testUpperBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major CompressedMatrix::upperBound()";

      typedef blaze::CompressedMatrix<int,blaze::rowMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 6UL, 3UL );
      mat(1,2) = 1;
      mat(1,4) = 2;

      checkRows    ( mat, 3UL );
      checkColumns ( mat, 6UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );

      // Determining the upper bound for position (1,1)
      {
         ConstIterator pos( mat.upperBound( 1UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (1,2)
      {
         ConstIterator pos( mat.upperBound( 1UL, 2UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,2)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (1,3)
      {
         ConstIterator pos( mat.upperBound( 1UL, 3UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,3)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (1,4)
      {
         ConstIterator pos( mat.upperBound( 1UL, 4UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,4)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (1,5)
      {
         ConstIterator pos( mat.upperBound( 1UL, 5UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,5)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major CompressedMatrix::upperBound()";

      typedef blaze::CompressedMatrix<int,blaze::columnMajor>::ConstIterator  ConstIterator;

      // Initialization check
      blaze::CompressedMatrix<int,blaze::columnMajor> mat( 6UL, 3UL, 3UL );
      mat(2,1) = 1;
      mat(4,1) = 2;

      checkRows    ( mat, 6UL );
      checkColumns ( mat, 3UL );
      checkCapacity( mat, 2UL );
      checkNonZeros( mat, 2UL );
      checkNonZeros( mat, 0UL, 0UL );
      checkNonZeros( mat, 1UL, 2UL );
      checkNonZeros( mat, 2UL, 0UL );

      // Determining the upper bound for position (1,1)
      {
         ConstIterator pos( mat.upperBound( 1UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (1,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (2,1)
      {
         ConstIterator pos( mat.upperBound( 2UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (2,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (3,1)
      {
         ConstIterator pos( mat.upperBound( 3UL, 1UL ) );

         if( pos == mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (3,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 4 || pos->value() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 4\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (4,1)
      {
         ConstIterator pos( mat.upperBound( 4UL, 1UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (4,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for position (5,1)
      {
         ConstIterator pos( mat.upperBound( 5UL, 1UL ) );

         if( pos != mat.end( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required position = (5,1)\n"
                << "   Current matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDefault() function with the CompressedMatrix class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDefault() function with the CompressedMatrix class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIsDefault()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDefault() function";

      // isDefault with 0x0 matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat;

         if( isDefault( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with default matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         if( isDefault( mat(0,1) ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element: " << mat(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 2UL );
         mat(0,1) = 1;

         if( isDefault( mat(0,1) ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element: " << mat(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDefault() function";

      // isDefault with 0x0 matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat;

         if( isDefault( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with default matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         if( isDefault( mat(1,0) ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element: " << mat(1,0) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL, 1UL );
         mat(1,0) = 1;

         if( isDefault( mat(1,0) ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element: " << mat(1,0) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************

} // namespace compressedmatrix

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running CompressedMatrix class test..." << std::endl;

   try
   {
      RUN_COMPRESSEDMATRIX_CLASS_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during CompressedMatrix class test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
