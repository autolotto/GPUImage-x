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

#include "Matrix3.hpp"

#include <cassert>
#include <cstring>

NS_GI_BEGIN

const Matrix3 Matrix3::IDENTITY = Matrix3(1.0f, 0.0f, 0.0f,
                                          0.0f, 1.0f, 0.0f,
                                          0.0f, 0.0f, 1.0f);

Matrix3::Matrix3() {
    *this = IDENTITY;
}

Matrix3::Matrix3(const float* mat) {
    set(mat);
}

Matrix3::Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) {
    set(m11, m12, m13, m21, m22, m23, m31, m32, m33);
}

Matrix3::Matrix3(const Matrix3& copy) {
    memcpy(m, copy.m, sizeof(float) * 9);
}

Matrix3::~Matrix3() {

}

void Matrix3::set(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) {
    m[0]  = m11;
    m[1]  = m21;
    m[2]  = m31;
    m[3]  = m12;
    m[4]  = m22;
    m[5]  = m32;
    m[6]  = m13;
    m[7]  = m23;
    m[8] = m33;
}

void Matrix3::set(const float* mat) {
    assert(mat);
    memcpy(this->m, mat, sizeof(float) * 9);
}

void Matrix3::set(const Matrix3& mat) {
    memcpy(this->m, mat.m, sizeof(float) * 9);
}

void Matrix3::setIdentity() {
    memcpy(m, &IDENTITY, sizeof(float) * 9);
}

void Matrix3::negate()
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
}

Matrix3 Matrix3::getNegated() const
{
    Matrix3 mat(*this);
    mat.negate();
    return mat;
}

void Matrix3::transpose() {
    float tmp;
    tmp = m[1]; m[1] = m[3]; m[3] = tmp;
    tmp = m[2]; m[2] = m[6]; m[6] = tmp;
    tmp = m[5]; m[5] = m[7]; m[7] = tmp;
}

Matrix3 Matrix3::getTransposed() const {
    Matrix3 mat(*this);
    mat.transpose();
    return mat;
}

void Matrix3::add(float scalar)
{
    add(scalar, this);
}

void Matrix3::add(float scalar, Matrix3* dst) const
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
}

void Matrix3::add(const Matrix3& mat)
{
    add(*this, mat, this);
}

void Matrix3::add(const Matrix3& m1, const Matrix3& m2, Matrix3* dst)
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
}

void Matrix3::subtract(const Matrix3& mat)
{
    subtract(*this, mat, this);
}

void Matrix3::subtract(const Matrix3& m1, const Matrix3& m2, Matrix3* dst)
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
}

void Matrix3::multiply(float scalar)
{
    multiply(scalar, this);
}

void Matrix3::multiply(float scalar, Matrix3* dst) const
{
    multiply(*this, scalar, dst);
}

void Matrix3::multiply(const Matrix3& mat, float scalar, Matrix3* dst)
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
}

void Matrix3::multiply(const Matrix3& mat)
{
    multiply(*this, mat, this);
}

void Matrix3::multiply(const Matrix3& m1, const Matrix3& m2, Matrix3* dst)
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
}

const Matrix3 Matrix3::operator+(const Matrix3& mat) const
{
    Matrix3 result(*this);
    result.add(mat);
    return result;
}

Matrix3& Matrix3::operator+=(const Matrix3& mat)
{
    add(mat);
    return *this;
}

const Matrix3 Matrix3::operator-(const Matrix3& mat) const
{
    Matrix3 result(*this);
    result.subtract(mat);
    return result;
}

Matrix3& Matrix3::operator-=(const Matrix3& mat)
{
    subtract(mat);
    return *this;
}

const Matrix3 Matrix3::operator-() const
{
    Matrix3 mat(*this);
    mat.negate();
    return mat;
}

const Matrix3 Matrix3::operator*(const Matrix3& mat) const
{
    Matrix3 result(*this);
    result.multiply(mat);
    return result;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat)
{
    multiply(mat);
    return *this;
}

const Matrix3 Matrix3::operator+(float scalar) const
{
    Matrix3 result(*this);
    result.add(scalar);
    return result;
}

Matrix3& Matrix3::operator+=(float scalar)
{
    add(scalar);
    return *this;
}

const Matrix3 Matrix3::operator-(float scalar) const
{
    Matrix3 result(*this);
    result.add(-scalar);
    return result;
}

Matrix3& Matrix3::operator-=(float scalar)
{
    add(-scalar);
    return *this;
}

const Matrix3 Matrix3::operator*(float scalar) const
{
    Matrix3 result(*this);
    result.multiply(scalar);
    return result;
}

Matrix3& Matrix3::operator*=(float scalar)
{
    multiply(scalar);
    return *this;
}

NS_GI_END
