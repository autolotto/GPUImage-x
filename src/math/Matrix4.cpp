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

#include "Matrix4.hpp"

#include <cassert>
#include <cstring>

NS_GI_BEGIN

const Matrix4 Matrix4::IDENTITY = Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
                                          0.0f, 1.0f, 0.0f, 0.0f,
                                          0.0f, 0.0f, 1.0f, 0.0f,
                                          0.0f, 0.0f, 0.0f, 1.0f);

Matrix4::Matrix4() {
    *this = IDENTITY;
}

Matrix4::Matrix4(const float* mat) {
    set(mat);
}

Matrix4::Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23,float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    set(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}

Matrix4::Matrix4(const Matrix4& copy) {
    memcpy(m, copy.m, sizeof(float) * 16);
}

Matrix4::~Matrix4() {

}

void Matrix4::set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) {
    m[0]  = m11;
    m[1]  = m21;
    m[2]  = m31;
    m[3]  = m41;
    m[4]  = m12;
    m[5]  = m22;
    m[6]  = m32;
    m[7]  = m42;
    m[8]  = m13;
    m[9]  = m23;
    m[10] = m33;
    m[11] = m43;
    m[12] = m14;
    m[13] = m24;
    m[14] = m34;
    m[15] = m44;
}

void Matrix4::set(const float* mat) {
    assert(mat);
    memcpy(this->m, mat, sizeof(float) * 16);
}

void Matrix4::set(const Matrix4& mat) {
    memcpy(this->m, mat.m, sizeof(float) * 16);
}

void Matrix4::setIdentity() {
    memcpy(m, &IDENTITY, sizeof(float) * 16);
}

void Matrix4::negate()
{
    m[0] = -m[0];
    m[1] = -m[1];
    m[2] = -m[2];
    m[3] = -m[3];
    m[4] = -m[4];
    m[5] = -m[5];
    m[6] = -m[6];
    m[7] = -m[7];
    m[8] = -m[8];
    m[9] = -m[9];
    m[10] = -m[10];
    m[11] = -m[11];
    m[12] = -m[12];
    m[13] = -m[13];
    m[14] = -m[14];
    m[15] = -m[15];
}

Matrix4 Matrix4::getNegated() const
{
    Matrix4 mat(*this);
    mat.negate();
    return mat;
}

void Matrix4::transpose() {
    float tmp;
    tmp = m[1]; m[1] = m[4]; m[4] = tmp;
    tmp = m[2]; m[2] = m[8]; m[8] = tmp;
    tmp = m[6]; m[6] = m[9]; m[9] = tmp;
    tmp = m[3]; m[3] = m[12]; m[12] = tmp;
    tmp = m[7]; m[7] = m[13]; m[13] = tmp;
    tmp = m[11]; m[11] = m[14]; m[14] = tmp;
}

Matrix4 Matrix4::getTransposed() const {
    Matrix4 mat(*this);
    mat.transpose();
    return mat;
}

void Matrix4::add(float scalar)
{
    add(scalar, this);
}

void Matrix4::add(float scalar, Matrix4* dst) const
{
    assert(dst);
    dst->m[0] = this->m[0] + scalar;
    dst->m[1] = this->m[1] + scalar;
    dst->m[2] = this->m[2] + scalar;
    dst->m[3] = this->m[3] + scalar;
    dst->m[4] = this->m[4] + scalar;
    dst->m[5] = this->m[5] + scalar;
    dst->m[6] = this->m[6] + scalar;
    dst->m[7] = this->m[7] + scalar;
    dst->m[8] = this->m[8] + scalar;
    dst->m[9] = this->m[9] + scalar;
    dst->m[10] = this->m[10] + scalar;
    dst->m[11] = this->m[11] + scalar;
    dst->m[12] = this->m[12] + scalar;
    dst->m[13] = this->m[13] + scalar;
    dst->m[14] = this->m[14] + scalar;
    dst->m[15] = this->m[15] + scalar;
}

void Matrix4::add(const Matrix4& mat)
{
    add(*this, mat, this);
}

void Matrix4::add(const Matrix4& m1, const Matrix4& m2, Matrix4* dst)
{
    assert(dst);
    dst->m[0] = m1.m[0] + m2.m[0];
    dst->m[1] = m1.m[1] + m2.m[1];
    dst->m[2] = m1.m[2] + m2.m[2];
    dst->m[3] = m1.m[3] + m2.m[3];
    dst->m[4] = m1.m[4] + m2.m[4];
    dst->m[5] = m1.m[5] + m2.m[5];
    dst->m[6] = m1.m[6] + m2.m[6];
    dst->m[7] = m1.m[7] + m2.m[7];
    dst->m[8] = m1.m[8] + m2.m[8];
    dst->m[9] = m1.m[9] + m2.m[9];
    dst->m[10] = m1.m[10] + m2.m[10];
    dst->m[11] = m1.m[11] + m2.m[11];
    dst->m[12] = m1.m[12] + m2.m[12];
    dst->m[13] = m1.m[13] + m2.m[13];
    dst->m[14] = m1.m[14] + m2.m[14];
    dst->m[15] = m1.m[15] + m2.m[15];
}

void Matrix4::subtract(const Matrix4& mat)
{
    subtract(*this, mat, this);
}

void Matrix4::subtract(const Matrix4& m1, const Matrix4& m2, Matrix4* dst)
{
    assert(dst);
    dst->m[0] = m1.m[0] - m2.m[0];
    dst->m[1] = m1.m[1] - m2.m[1];
    dst->m[2] = m1.m[2] - m2.m[2];
    dst->m[3] = m1.m[3] - m2.m[3];
    dst->m[4] = m1.m[4] - m2.m[4];
    dst->m[5] = m1.m[5] - m2.m[5];
    dst->m[6] = m1.m[6] - m2.m[6];
    dst->m[7] = m1.m[7] - m2.m[7];
    dst->m[8] = m1.m[8] - m2.m[8];
    dst->m[9] = m1.m[9] - m2.m[9];
    dst->m[10] = m1.m[10] - m2.m[10];
    dst->m[11] = m1.m[11] - m2.m[11];
    dst->m[12] = m1.m[12] - m2.m[12];
    dst->m[13] = m1.m[13] - m2.m[13];
    dst->m[14] = m1.m[14] - m2.m[14];
    dst->m[15] = m1.m[15] - m2.m[15];
}

void Matrix4::multiply(float scalar)
{
    multiply(scalar, this);
}

void Matrix4::multiply(float scalar, Matrix4* dst) const
{
    multiply(*this, scalar, dst);
}

void Matrix4::multiply(const Matrix4& mat, float scalar, Matrix4* dst)
{
    assert(dst);
    dst->m[0] = mat.m[0] * scalar;
    dst->m[1] = mat.m[1] * scalar;
    dst->m[2] = mat.m[2] * scalar;
    dst->m[3] = mat.m[3] * scalar;
    dst->m[4] = mat.m[4] * scalar;
    dst->m[5] = mat.m[5] * scalar;
    dst->m[6] = mat.m[6] * scalar;
    dst->m[7] = mat.m[7] * scalar;
    dst->m[8] = mat.m[8] * scalar;
    dst->m[9] = mat.m[9] * scalar;
    dst->m[10] = mat.m[10] * scalar;
    dst->m[11] = mat.m[11] * scalar;
    dst->m[12] = mat.m[12] * scalar;
    dst->m[13] = mat.m[13] * scalar;
    dst->m[14] = mat.m[14] * scalar;
    dst->m[15] = mat.m[15] * scalar;
}

void Matrix4::multiply(const Matrix4& mat)
{
    multiply(*this, mat, this);
}

void Matrix4::multiply(const Matrix4& m1, const Matrix4& m2, Matrix4* dst)
{
    assert(dst);
    dst->m[0] = m1.m[0] * m2.m[0];
    dst->m[1] = m1.m[1] * m2.m[1];
    dst->m[2] = m1.m[2] * m2.m[2];
    dst->m[3] = m1.m[3] * m2.m[3];
    dst->m[4] = m1.m[4] * m2.m[4];
    dst->m[5] = m1.m[5] * m2.m[5];
    dst->m[6] = m1.m[6] * m2.m[6];
    dst->m[7] = m1.m[7] * m2.m[7];
    dst->m[8] = m1.m[8] * m2.m[8];
    dst->m[9] = m1.m[9] * m2.m[9];
    dst->m[10] = m1.m[10] * m2.m[10];
    dst->m[11] = m1.m[11] * m2.m[11];
    dst->m[12] = m1.m[12] * m2.m[12];
    dst->m[13] = m1.m[13] * m2.m[13];
    dst->m[14] = m1.m[14] * m2.m[14];
    dst->m[15] = m1.m[15] * m2.m[15];
}

const Matrix4 Matrix4::operator+(const Matrix4& mat) const
{
    Matrix4 result(*this);
    result.add(mat);
    return result;
}

Matrix4& Matrix4::operator+=(const Matrix4& mat)
{
    add(mat);
    return *this;
}

const Matrix4 Matrix4::operator-(const Matrix4& mat) const
{
    Matrix4 result(*this);
    result.subtract(mat);
    return result;
}

Matrix4& Matrix4::operator-=(const Matrix4& mat)
{
    subtract(mat);
    return *this;
}

const Matrix4 Matrix4::operator-() const
{
    Matrix4 mat(*this);
    mat.negate();
    return mat;
}

const Matrix4 Matrix4::operator*(const Matrix4& mat) const
{
    Matrix4 result(*this);
    result.multiply(mat);
    return result;
}

Matrix4& Matrix4::operator*=(const Matrix4& mat)
{
    multiply(mat);
    return *this;
}

const Matrix4 Matrix4::operator+(float scalar) const
{
    Matrix4 result(*this);
    result.add(scalar);
    return result;
}

Matrix4& Matrix4::operator+=(float scalar)
{
    add(scalar);
    return *this;
}

const Matrix4 Matrix4::operator-(float scalar) const
{
    Matrix4 result(*this);
    result.add(-scalar);
    return result;
}

Matrix4& Matrix4::operator-=(float scalar)
{
    add(-scalar);
    return *this;
}

const Matrix4 Matrix4::operator*(float scalar) const
{
    Matrix4 result(*this);
    result.multiply(scalar);
    return result;
}

Matrix4& Matrix4::operator*=(float scalar)
{
    multiply(scalar);
    return *this;
}

NS_GI_END

