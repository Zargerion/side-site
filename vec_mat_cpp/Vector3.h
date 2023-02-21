#pragma once
#include "VecMath.h"

template<typename t_T>
struct TVector3 : public jagam::Math::jaVector3<t_T>
{
	TVector3() noexcept { }
	TVector3(const t_T fX, const t_T fY, const t_T fZ) noexcept :jaVector3(fX, fY, fZ) { }
	TVector3(const jaVector3& v) noexcept : jaVector3(v) { }
	explicit TVector3(const t_T(&afCoordinate)[3]) noexcept : jaVector3(afCoordinate) { }
	//explicit TVector3(const t_T* r):jaVector3(r) { }

	void Swap(TVector3& other)
	{
		std::swap(x, other.x);
		std::swap(y, other.y);
		std::swap(z, other.z);
	}

	t_T operator [] (const size_t i) const
	{
		ASSERT(i < 3);
		return c[i];
	}

	t_T& operator [] (const size_t i)
	{
		ASSERT(i < 3);
		return c[i];
	}

	t_T* ptr() { return c; }
	const t_T* ptr() const { return c; }

	TVector3& operator = (const TVector3& rkVector)
	{
		x = rkVector.x;
		y = rkVector.y;
		z = rkVector.z;

		return *this;
	}

	TVector3& operator = (const t_T fScaler)
	{
		x = fScaler;
		y = fScaler;
		z = fScaler;

		return *this;
	}

	bool operator == (const TVector3& rkVector) const
	{
		return (x == rkVector.x && y == rkVector.y && z == rkVector.z);
	}

	bool operator != (const TVector3& rkVector) const
	{
		return (x != rkVector.x || y != rkVector.y || z != rkVector.z);
	}

	TVector3 operator + (const TVector3& rkVector) const
	{
		return TVector3(x + rkVector.x, y + rkVector.y, z + rkVector.z);
	}

	TVector3 operator - (const TVector3& rkVector) const
	{
		return TVector3(x - rkVector.x, y - rkVector.y, z - rkVector.z);
	}

	TVector3 operator * (const t_T fScalar) const
	{
		return TVector3(x * fScalar, y * fScalar, z * fScalar);
	}

	TVector3 operator * (const TVector3& rhs) const
	{
		return TVector3(x * rhs.x, y * rhs.y, z * rhs.z);
	}

	TVector3 operator / (const t_T fScalar) const
	{
		assert(fScalar != 0.0f);
		t_T fInv = 1.0f / fScalar;
		return TVector3(x * fInv, y * fInv, z * fInv);
	}

	TVector3 operator / (const TVector3& rhs) const
	{
		return TVector3(x / rhs.x, y / rhs.y, z / rhs.z);
	}

	const TVector3& operator+() const
	{
		return *this;
	}

	TVector3 operator-() const
	{
		return TVector3(-x, -y, -z);
	}

	friend TVector3 operator * (const t_T fScalar, const TVector3& rkVector)
	{
		return TVector3(fScalar * rkVector.x, fScalar * rkVector.y, fScalar * rkVector.z);
	}

	friend TVector3 operator / (const t_T fScalar, const TVector3& rkVector)
	{
		return TVector3(fScalar / rkVector.x, fScalar / rkVector.y, fScalar / rkVector.z);
	}

	friend TVector3 operator + (const TVector3& lhs, const t_T rhs)
	{
		return TVector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
	}

	friend TVector3 operator + (const t_T lhs, const TVector3& rhs)
	{
		return TVector3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
	}

	friend TVector3 operator - (const TVector3& lhs, const t_T rhs)
	{
		return TVector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
	}

	friend TVector3 operator - (const t_T lhs, const TVector3& rhs)
	{
		return TVector3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
	}

	TVector3& operator += (const TVector3& rkVector)
	{
		x += rkVector.x;
		y += rkVector.y;
		z += rkVector.z;
		return *this;
	}

	TVector3& operator += (const t_T fScalar)
	{
		x += fScalar;
		y += fScalar;
		z += fScalar;
		return *this;
	}

	TVector3& operator -= (const TVector3& rkVector)
	{
		x -= rkVector.x;
		y -= rkVector.y;
		z -= rkVector.z;
		return *this;
	}

	TVector3& operator -= (const t_T fScalar)
	{
		x -= fScalar;
		y -= fScalar;
		z -= fScalar;
		return *this;
	}

	TVector3& operator *= (const t_T fScalar)
	{
		x *= fScalar;
		y *= fScalar;
		z *= fScalar;
		return *this;
	}

	TVector3& operator *= (const TVector3& rkVector)
	{
		x *= rkVector.x;
		y *= rkVector.y;
		z *= rkVector.z;
		return *this;
	}

	TVector3& operator /= (const t_T fScalar)
	{
		ASSERT(fScalar != 0.0);
		t_T fInv = 1.0 / fScalar;
		x *= fInv;
		y *= fInv;
		z *= fInv;
		return *this;
	}

	TVector3& operator /= (const TVector3& rkVector)
	{
		x /= rkVector.x;
		y /= rkVector.y;
		z /= rkVector.z;
		return *this;
	}

	t_T Length() const { return std::sqrtf(x*x + y * y + z * z); }
	t_T LengthSq() const { return x * x + y * y + z * z; }
	t_T Distance(const TVector3& rhs) const { return (*this - rhs).Length(); }
	t_T DistanceSq(const TVector3& rhs) const { return (*this - rhs).LengthSq(); }

	t_T DotProduct(const TVector3& vec) const { return x * vec.x + y * vec.y + z * vec.z; }

	t_T Normalise()
	{
		t_T fLength = Length();
		if (fLength > 1e-08)
		{
			t_T fInvLength = 1.0f / fLength;
			x *= fInvLength;
			y *= fInvLength;
			z *= fInvLength;
		}
		return fLength;
	}

	TVector3 CrossProduct(const TVector3& rkVector) const
	{
		return TVector3(y*rkVector.z - z * rkVector.y, z*rkVector.x - x * rkVector.z, x*rkVector.y - y * rkVector.x);
	}

	TVector3 midPoint(const TVector3& vec) const
	{
		return TVector3((x + vec.x)*0.5f, (y + vec.y)*0.5f, (z + vec.z) * 0.5f);
	}

	bool operator < (const TVector3& rhs) const
	{
		if (x < rhs.x && y < rhs.y && z < rhs.z)
			return true;
		return false;
	}

	bool operator > (const TVector3& rhs) const
	{
		if (x > rhs.x && y > rhs.y && z > rhs.z)
			return true;
		return false;
	}

	void MakeFloor(const TVector3& cmp)
	{
		if (cmp.x < x) x = cmp.x;
		if (cmp.y < y) y = cmp.y;
		if (cmp.z < z) z = cmp.z;
	}

	void MakeCeil(const TVector3& cmp)
	{
		if (cmp.x > x) x = cmp.x;
		if (cmp.y > y) y = cmp.y;
		if (cmp.z > z) z = cmp.z;
	}

	TVector3 Perpendicular() const
	{
		TVector3 perp = CrossProduct(TVector3::UNIT_X);
		if (perp.LengthSq() < (1e-06f * 1e-06f))
			perp = CrossProduct(TVector3::UNIT_Y);
		perp.Normalise();
		return perp;
	}

	/*TVector3 RandomDeviant(const t_T angle, const TVector3& up = TVector3::ZERO ) const
	{
		TVector3 newUp;
		if (up == TVector3::ZERO)
			newUp = Perpendicular();
		else
			newUp = up;

		// Rotate up vector by random amount around this
		Quaternion q;
		q.FromAngleAxis( t_T(Math::UnitRandom() * (PI*2.0f)), *this );
		newUp = q * newUp;

		// Finally rotate this by given angle around randomised up
		q.FromAngleAxis( angle, newUp );
		return q * (*this);
	}*/

	t_T AngleBetween(const TVector3& dest)
	{
		t_T lenProduct = jagam::Math::Sqrt(LengthSq()*dest.LengthSq());
		if (lenProduct < 1e-6f)
			lenProduct = 1e-6f;
		t_T f = DotProduct(dest) / lenProduct;
		f = Math::Clamp(f, -1.0f, 1.0f);
		return jagam::Math::ACos(f);
	}

	bool IsZeroLength() const
	{
		t_T sqlen = LengthSq();
		return (sqlen < (1e-06 * 1e-06));
	}
	TVector3 NormalisedCopy() const
	{
		TVector3 ret = *this;
		ret.Normalise();
		return ret;
	}
	TVector3 reflect(const TVector3& normal) const
	{
		return TVector3((*this) - (2 * DotProduct(normal)*normal));
	}

	bool PositionEquals(const TVector3& rhs, t_T tolerance = 1e-03) const
	{
		return Math::t_TEqual(x, rhs.x, tolerance) &&
			Math::t_TEqual(y, rhs.y, tolerance) &&
			Math::t_TEqual(z, rhs.z, tolerance);
	}

	bool DirectionEquals(const TVector3& rhs, const t_T& tolerance) const
	{
		t_T dot = DotProduct(rhs);
		t_T angle = jagam::Math::ACos(dot);
		return jagam::Math::Abs(angle) <= tolerance;
	}

	bool IsNaN() const
	{
		return Math::IsNaN(x) || Math::IsNaN(y) || Math::IsNaN(z);
	}

	//ToString() {  }

	// special points
	static const TVector3 ZERO;
	static const TVector3 UNIT_X;
	static const TVector3 UNIT_Y;
	static const TVector3 UNIT_Z;
	static const TVector3 NEGATIVE_UNIT_X;
	static const TVector3 NEGATIVE_UNIT_Y;
	static const TVector3 NEGATIVE_UNIT_Z;
	static const TVector3 UNIT_SCALE;
};


//using jagam::Math::TVector3;
using Vector3f = TVector3<float32_t>;
using Vector3d = TVector3<float64_t>;