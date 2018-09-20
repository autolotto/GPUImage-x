/*
 * GPUImage-x
 *
 * Copyright (C) 2017 Yijin Wang, Yiqian Wang
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Matrix3_hpp
#define Matrix3_hpp

#include "../macros.h"

NS_GI_BEGIN

class Matrix3 {
public:
    float m[9];
    Matrix3();
    Matrix3(const float* mat);
    Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
    Matrix3(const Matrix3& copy);
    ~Matrix3();

    void set(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
    void set(const float* mat);
    void set(const Matrix3& mat);
    void setIdentity();

    void negate();
    Matrix3 getNegated() const;

    void transpose();
    Matrix3 getTransposed() const;

    void add(float scalar);
    void add(float scalar, Matrix3* dst) const;
    void add(const Matrix3& mat);
    static void add(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

    void subtract(const Matrix3& mat);
    static void subtract(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

    void multiply(float scalar);
    void multiply(float scalar, Matrix3* dst) const;
    static void multiply(const Matrix3& mat, float scalar, Matrix3* dst);
    void multiply(const Matrix3& mat);
    static void multiply(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

    const Matrix3 operator+(const Matrix3& mat) const;
    Matrix3& operator+=(const Matrix3& mat);
    const Matrix3 operator-(const Matrix3& mat) const;
    Matrix3& operator-=(const Matrix3& mat);
    const Matrix3 operator-() const;
    const Matrix3 operator*(const Matrix3& mat) const;
    Matrix3& operator*=(const Matrix3& mat);

    const Matrix3 operator+(float scalar) const;
    Matrix3& operator+=(float scalar);
    const Matrix3 operator-(float scalar) const;
    Matrix3& operator-=(float scalar);
    const Matrix3 operator*(float scalar) const;
    Matrix3& operator*=(float scalar);

    static const Matrix3 IDENTITY;
};

NS_GI_END

#endif /* Matrix3_hpp */
