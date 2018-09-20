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

#include "Vector2.hpp"

NS_GI_BEGIN

Vector2::Vector2()
: x(0.0f), y(0.0f)
{
}

Vector2::Vector2(float xx, float yy)
: x(xx), y(yy)
{
}

Vector2::Vector2(const float* array)
{
    set(array);
}

Vector2::Vector2(const Vector2& p1, const Vector2& p2)
{
    set(p1, p2);
}

Vector2::Vector2(const Vector2& copy)
{
    set(copy);
}

Vector2::~Vector2()
{
}

bool Vector2::isZero() const
{
    return x == 0.0f && y == 0.0f;
}

bool Vector2::isOne() const
{
    return x == 1.0f && y == 1.0f;
}

void Vector2::add(const Vector2& v)
{
    x += v.x;
    y += v.y;
}

float Vector2::distanceSquared(const Vector2& v) const
{
    float dx = v.x - x;
    float dy = v.y - y;
    return (dx * dx + dy * dy);
}

float Vector2::dot(const Vector2& v) const
{
    return (x * v.x + y * v.y);
}

float Vector2::lengthSquared() const
{
    return (x * x + y * y);
}

void Vector2::negate()
{
    x = -x;
    y = -y;
}

void Vector2::scale(float scalar)
{
    x *= scalar;
    y *= scalar;
}

void Vector2::scale(const Vector2& scale)
{
    x *= scale.x;
    y *= scale.y;
}

void Vector2::set(float xx, float yy)
{
    this->x = xx;
    this->y = yy;
}

void Vector2::set(const Vector2& v)
{
    this->x = v.x;
    this->y = v.y;
}

void Vector2::set(const Vector2& p1, const Vector2& p2)
{
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}

void Vector2::setZero()
{
    x = y = 0.0f;
}

void Vector2::subtract(const Vector2& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2::smooth(const Vector2& target, float elapsedTime, float responseTime)
{
    if (elapsedTime > 0)
    {
        *this += (target - *this) * (elapsedTime / (elapsedTime + responseTime));
    }
}

const Vector2 Vector2::operator+(const Vector2& v) const
{
    Vector2 result(*this);
    result.add(v);
    return result;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
    add(v);
    return *this;
}

const Vector2 Vector2::operator-(const Vector2& v) const
{
    Vector2 result(*this);
    result.subtract(v);
    return result;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
    subtract(v);
    return *this;
}

const Vector2 Vector2::operator-() const
{
    Vector2 result(*this);
    result.negate();
    return result;
}

const Vector2 Vector2::operator*(float s) const
{
    Vector2 result(*this);
    result.scale(s);
    return result;
}

Vector2& Vector2::operator*=(float s)
{
    scale(s);
    return *this;
}

const Vector2 Vector2::operator/(const float s) const
{
    return Vector2(this->x / s, this->y / s);
}

bool Vector2::operator<(const Vector2& v) const
{
    if (x == v.x)
    {
        return y < v.y;
    }
    return x < v.x;
}

bool Vector2::operator>(const Vector2& v) const
{
    if (x == v.x)
    {
        return y > v.y;
    }
    return x > v.x;
}

bool Vector2::operator==(const Vector2& v) const
{
    return x==v.x && y==v.y;
}

bool Vector2::operator!=(const Vector2& v) const
{
    return x!=v.x || y!=v.y;
}

const Vector2 operator*(float x, const Vector2& v)
{
    Vector2 result(v);
    result.scale(x);
    return result;
}

NS_GI_END
