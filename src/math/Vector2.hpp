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

#ifndef Vector2_hpp
#define Vector2_hpp

#include "../macros.h"

NS_GI_BEGIN

class Vector2
{
public:

    float x;
    float y;

    Vector2();
    Vector2(float xx, float yy);
    Vector2(const float* array);
    Vector2(const Vector2& p1, const Vector2& p2);
    Vector2(const Vector2& copy);
    ~Vector2();

    bool isZero() const;
    bool isOne() const;
    static float angle(const Vector2& v1, const Vector2& v2);
    void add(const Vector2& v);
    static void add(const Vector2& v1, const Vector2& v2, Vector2* dst);
    void clamp(const Vector2& min, const Vector2& max);
    static void clamp(const Vector2& v, const Vector2& min, const Vector2& max, Vector2* dst);
    float distance(const Vector2& v) const;
    float distanceSquared(const Vector2& v) const;
    float dot(const Vector2& v) const;
    static float dot(const Vector2& v1, const Vector2& v2);
    float length() const;
    float lengthSquared() const;
    void negate();
    void normalize();
    Vector2 getNormalized() const;
    void scale(float scalar);
    void scale(const Vector2& scale);
    void rotate(const Vector2& point, float angle);
    void set(float xx, float yy);
    void set(const Vector2& v);
    void set(const Vector2& p1, const Vector2& p2);
    void setZero();
    void subtract(const Vector2& v);
    static void subtract(const Vector2& v1, const Vector2& v2, Vector2* dst);
    void smooth(const Vector2& target, float elapsedTime, float responseTime);
    const Vector2 operator+(const Vector2& v) const;
    Vector2& operator+=(const Vector2& v);
    const Vector2 operator-(const Vector2& v) const;
    Vector2& operator-=(const Vector2& v);
    const Vector2 operator-() const;
    const Vector2 operator*(float s) const;
    Vector2& operator*=(float s);
    const Vector2 operator/(float s) const;
    bool operator<(const Vector2& v) const;
    bool operator>(const Vector2& v) const;
    bool operator==(const Vector2& v) const;
    bool operator!=(const Vector2& v) const;
};

NS_GI_END

#endif /* Vector2_hpp */
