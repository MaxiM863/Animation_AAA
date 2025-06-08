// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Tools

#include <fstream>
#include <iostream>
#include <cmath>
#include "Tools.h"

namespace VulkanCookbook {

  bool GetBinaryFileContents( std::string const          & filename,
                              std::vector<unsigned char> & contents ) {
    contents.clear();

    std::ifstream file( filename, std::ios::binary );
    if( file.fail() ) {
      std::cout << "Could not open '" << filename << "' file." << std::endl;
      return false;
    }

    std::streampos begin;
    std::streampos end;
    begin = file.tellg();
    file.seekg( 0, std::ios::end );
    end = file.tellg();

    if( (end - begin) == 0 ) {
      std::cout << "The '" << filename << "' file is empty." << std::endl;
      return false;
    }
    contents.resize( static_cast<size_t>(end - begin) );
    file.seekg( 0, std::ios::beg );
    file.read( reinterpret_cast<char*>(contents.data()), end - begin );
    file.close();

    return true;
  }

  float Deg2Rad( float value ) {
    return value * 0.01745329251994329576923690768489f;
  }

  float Dot( Vector3 const & left,
             Vector3 const & right ) {
    return left[0] * right[0] + left[1] * right[1] + left[2] * right[2];
  }

  float Length(Vector3 const &vec)
  {
      return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
  }

  Matrix4x4 Inverse(Matrix4x4 m)
  {
    double inv[16], det;
    int i;
    Matrix4x4 invI;

    inv[0] = m[5]  * m[10] * m[15] - 
             m[5]  * m[11] * m[14] - 
             m[9]  * m[6]  * m[15] + 
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] - 
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] + 
              m[4]  * m[11] * m[14] + 
              m[8]  * m[6]  * m[15] - 
              m[8]  * m[7]  * m[14] - 
              m[12] * m[6]  * m[11] + 
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] - 
             m[4]  * m[11] * m[13] - 
             m[8]  * m[5] * m[15] + 
             m[8]  * m[7] * m[13] + 
             m[12] * m[5] * m[11] - 
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] + 
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] - 
               m[8]  * m[6] * m[13] - 
               m[12] * m[5] * m[10] + 
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] + 
              m[1]  * m[11] * m[14] + 
              m[9]  * m[2] * m[15] - 
              m[9]  * m[3] * m[14] - 
              m[13] * m[2] * m[11] + 
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] - 
             m[0]  * m[11] * m[14] - 
             m[8]  * m[2] * m[15] + 
             m[8]  * m[3] * m[14] + 
             m[12] * m[2] * m[11] - 
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] + 
              m[0]  * m[11] * m[13] + 
              m[8]  * m[1] * m[15] - 
              m[8]  * m[3] * m[13] - 
              m[12] * m[1] * m[11] + 
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] - 
              m[0]  * m[10] * m[13] - 
              m[8]  * m[1] * m[14] + 
              m[8]  * m[2] * m[13] + 
              m[12] * m[1] * m[10] - 
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] - 
             m[1]  * m[7] * m[14] - 
             m[5]  * m[2] * m[15] + 
             m[5]  * m[3] * m[14] + 
             m[13] * m[2] * m[7] - 
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] + 
              m[0]  * m[7] * m[14] + 
              m[4]  * m[2] * m[15] - 
              m[4]  * m[3] * m[14] - 
              m[12] * m[2] * m[7] + 
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] - 
              m[0]  * m[7] * m[13] - 
              m[4]  * m[1] * m[15] + 
              m[4]  * m[3] * m[13] + 
              m[12] * m[1] * m[7] - 
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] + 
               m[0]  * m[6] * m[13] + 
               m[4]  * m[1] * m[14] - 
               m[4]  * m[2] * m[13] - 
               m[12] * m[1] * m[6] + 
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] + 
              m[1] * m[7] * m[10] + 
              m[5] * m[2] * m[11] - 
              m[5] * m[3] * m[10] - 
              m[9] * m[2] * m[7] + 
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] - 
             m[0] * m[7] * m[10] - 
             m[4] * m[2] * m[11] + 
             m[4] * m[3] * m[10] + 
             m[8] * m[2] * m[7] - 
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] + 
               m[0] * m[7] * m[9] + 
               m[4] * m[1] * m[11] - 
               m[4] * m[3] * m[9] - 
               m[8] * m[1] * m[7] + 
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] - 
              m[0] * m[6] * m[9] - 
              m[4] * m[1] * m[10] + 
              m[4] * m[2] * m[9] + 
              m[8] * m[1] * m[6] - 
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        invI[i] = inv[i] * det;

    return invI;    
  }

  Matrix4x4 Transpose(Matrix4x4 mat)
  {
    Matrix4x4 rep;

    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            rep[4*i+j] = mat[4*j+i];
    return rep;
  }

  Vector3 Transform(Vector3 vec, Matrix4x4 mat)
  {
    float result[4];
    Vector3 res;

    for ( int i = 0; i < 4; ++i )
        result[i] = vec[0] * mat[i] + vec[1] * mat[4+i] + vec[2] * mat[8+i] + 1.0f * mat[12+i];

    res[0] = result[0]/result[3];
    res[1] = result[1]/result[3];
    res[2] = result[2]/result[3];

    return res;
  }

  float AngleBetween(Vector3 const &left, Vector3 const &right)
  {

    return acos(Dot(left, right) / (Length(left) * Length(right)));
  }
 

  Vector3 Cross( Vector3 const & left,
                 Vector3 const & right ) {
    return {
      left[1] * right[2] - left[2] * right[1],
      left[2] * right[0] - left[0] * right[2],
      left[0] * right[1] - left[1] * right[0]
    };
  }

  Vector3 Normalize( Vector3 const & vector ) {
    float length = std::sqrt( vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2] );
    return {
      vector[0] / length,
      vector[1] / length,
      vector[2] / length
    };
  }

  Vector3 operator+ ( Vector3 const & left,
                      Vector3 const & right ) {
    return{
      left[0] + right[0],
      left[1] + right[1],
      left[2] + right[2]
    };
  }

  Vector3 operator- ( Vector3 const & left,
                      Vector3 const & right ) {
    return{
      left[0] - right[0],
      left[1] - right[1],
      left[2] - right[2]
    };
  }

  Vector3 operator+ ( float const   & left,
                      Vector3 const & right ) {
    return {
      left + right[0],
      left + right[1],
      left + right[2]
    };
  }

  Vector3 operator- ( float const   & left,
                      Vector3 const & right ) {
    return {
      left - right[0],
      left - right[1],
      left - right[2]
    };
  }

  Vector3 operator+ ( Vector3 const & left,
                      float const   & right ) {
    return{
      left[0] + right,
      left[1] + right,
      left[2] + right
    };
  }

  Vector3 operator- ( Vector3 const & left,
                      float const   & right ) {
    return {
      left[0] - right,
      left[1] - right,
      left[2] - right
    };
  }

  Vector3 operator* ( float           left,
                      Vector3 const & right ) {
    return {
      left * right[0],
      left * right[1],
      left * right[2]
    };
  }

  Vector3 operator* ( Vector3 const & left,
                      float           right ) {
    return {
      left[0] * right,
      left[1] * right,
      left[2] * right
    };
  }

  Vector3 operator* ( Vector3 const   & left,
                      Matrix4x4 const & right ) {
    return {
      left[0] * right[0] + left[1] * right[1] + left[2] * right[2],
      left[0] * right[4] + left[1] * right[5] + left[2] * right[6],
      left[0] * right[8] + left[1] * right[9] + left[2] * right[10]
    };
  }

  Vector3 operator- ( Vector3 const & vector ) {
    return {
      -vector[0],
      -vector[1],
      -vector[2]
    };
  }

  bool operator== ( Vector3 const & left,
                    Vector3 const & right ) {
    if( (std::abs( left[0] - right[0] ) > 0.00001f) ||
        (std::abs( left[1] - right[1] ) > 0.00001f) ||
        (std::abs( left[2] - right[2] ) > 0.00001f) ) {
      return false;
    } else {
      return true;
    }
  }

  Matrix4x4 operator* ( Matrix4x4 const & left,
                        Matrix4x4 const & right ) {
    return {
      left[0] * right[0] + left[4] * right[1] + left[8] * right[2] + left[12] * right[3],
      left[1] * right[0] + left[5] * right[1] + left[9] * right[2] + left[13] * right[3],
      left[2] * right[0] + left[6] * right[1] + left[10] * right[2] + left[14] * right[3],
      left[3] * right[0] + left[7] * right[1] + left[11] * right[2] + left[15] * right[3],

      left[0] * right[4] + left[4] * right[5] + left[8] * right[6] + left[12] * right[7],
      left[1] * right[4] + left[5] * right[5] + left[9] * right[6] + left[13] * right[7],
      left[2] * right[4] + left[6] * right[5] + left[10] * right[6] + left[14] * right[7],
      left[3] * right[4] + left[7] * right[5] + left[11] * right[6] + left[15] * right[7],

      left[0] * right[8] + left[4] * right[9] + left[8] * right[10] + left[12] * right[11],
      left[1] * right[8] + left[5] * right[9] + left[9] * right[10] + left[13] * right[11],
      left[2] * right[8] + left[6] * right[9] + left[10] * right[10] + left[14] * right[11],
      left[3] * right[8] + left[7] * right[9] + left[11] * right[10] + left[15] * right[11],

      left[0] * right[12] + left[4] * right[13] + left[8] * right[14] + left[12] * right[15],
      left[1] * right[12] + left[5] * right[13] + left[9] * right[14] + left[13] * right[15],
      left[2] * right[12] + left[6] * right[13] + left[10] * right[14] + left[14] * right[15],
      left[3] * right[12] + left[7] * right[13] + left[11] * right[14] + left[15] * right[15]
    };
  }

} // namespace VulkanCookbook
