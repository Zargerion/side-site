#pragma once

template<typename t_T>
struct TVector4 : public jagam::Math::jaVector4<t_T>
{
	TVector4() { }
	TVector4( const t_T fX, const t_T fY, const t_T fZ, const t_T fW):jaVector4(fX,fY,fZ,fW) { }
	TVector4(const jagam::Math::jaVector4<t_T>& v):jaVector4(v) { }
	explicit TVector4( const t_T (&afCoordinate)[4]):jaVector4(afCoordinate) { }
	explicit TVector4( const t_T* r ):jaVector4(r) { }

	void swap(TVector4& other)
	{
		std::swap(x, other.x);
		std::swap(y, other.y);
		std::swap(z, other.z);
		std::swap(w, other.w);
	}

	t_T operator [] ( const size_t i ) const
	{
		ASSERT( i < 4 );
		return c[i];
	}

	t_T& operator [] ( const size_t i )
	{
		ASSERT( i < 4 );
		return c[i];
	}

	t_T* ptr() { return c; }
	const t_T* ptr() const { return c; }

	TVector4& operator = ( const TVector4& rkVector )
	{
		x = rkVector.x;
		y = rkVector.y;
		z = rkVector.z;
		w = rkVector.w;
		return *this;
	}

	TVector4& operator = ( const t_T fScalar)
	{
		x = fScalar;
		y = fScalar;
		z = fScalar;
		w = fScalar;
		return *this;
	}

	bool operator == ( const TVector4& rkVector ) const
	{
		return ( x == rkVector.x && y == rkVector.y && z == rkVector.z && w == rkVector.w );
	}

	bool operator != ( const TVector4& rkVector ) const
	{
		return ( x != rkVector.x || y != rkVector.y || z != rkVector.z || w != rkVector.w );
	}

	TVector4& operator = (const Vector3f& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = 1.0f;
		return *this;
	}

	TVector4 operator + ( const TVector4& rkVector ) const
	{
		return TVector4(x + rkVector.x, y + rkVector.y, z + rkVector.z, w + rkVector.w);
	}

	TVector4 operator - ( const TVector4& rkVector ) const
	{
		return TVector4(x - rkVector.x, y - rkVector.y, z - rkVector.z, w - rkVector.w);
	}

	TVector4 operator * ( const t_T fScalar ) const
	{
		return TVector4( x * fScalar, y * fScalar, z * fScalar, w * fScalar);
	}

	TVector4 operator * ( const TVector4& rhs) const
	{
		return TVector4(rhs.x * x, rhs.y * y, rhs.z * z, rhs.w * w);
	}

	TVector4 operator / ( const t_T fScalar ) const
	{
		ASSERT( fScalar != 0.0f );
		t_T fInv = 1.0f / fScalar;
		return TVector4(x * fInv, y * fInv, z * fInv, w * fInv);
	}

	TVector4 operator / ( const TVector4& rhs) const
	{
		return TVector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	}

	const TVector4& operator+() const
	{
		return *this;
	}

	TVector4 operator-() const
	{
		return TVector4(-x, -y, -z, -w);
	}

	friend TVector4 operator * ( const t_T fScalar, const TVector4& rkVector )
	{
		return TVector4(fScalar * rkVector.x, fScalar * rkVector.y, fScalar * rkVector.z, fScalar * rkVector.w);
	}

	friend TVector4 operator / ( const t_T fScalar, const TVector4& rkVector )
	{
		return TVector4( fScalar / rkVector.x, fScalar / rkVector.y, fScalar / rkVector.z, fScalar / rkVector.w);
	}

	friend TVector4 operator + (const TVector4& lhs, const t_T rhs)
	{
		return TVector4(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
	}

	friend TVector4 operator + (const t_T lhs, const TVector4& rhs)
	{
		return TVector4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
	}

	friend TVector4 operator - (const TVector4& lhs, t_T rhs)
	{
		return TVector4(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
	}

	friend TVector4 operator - (const t_T lhs, const TVector4& rhs)
	{
		return TVector4( lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
	}

	TVector4& operator += ( const TVector4& rkVector )
	{
		x += rkVector.x;
		y += rkVector.y;
		z += rkVector.z;
		w += rkVector.w;
		return *this;
	}

	TVector4& operator -= ( const TVector4& rkVector )
	{
		x -= rkVector.x;
		y -= rkVector.y;
		z -= rkVector.z;
		w -= rkVector.w;
		return *this;
	}

	TVector4& operator *= ( const t_T fScalar )
	{
		x *= fScalar;
		y *= fScalar;
		z *= fScalar;
		w *= fScalar;
		return *this;
	}

	TVector4& operator += ( const t_T fScalar )
	{
		x += fScalar;
		y += fScalar;
		z += fScalar;
		w += fScalar;
		return *this;
	}

	TVector4& operator -= ( const t_T fScalar )
	{
		x -= fScalar;
		y -= fScalar;
		z -= fScalar;
		w -= fScalar;
		return *this;
	}

	TVector4& operator *= ( const TVector4& rkVector )
	{
		x *= rkVector.x;
		y *= rkVector.y;
		z *= rkVector.z;
		w *= rkVector.w;
		return *this;
	}

	TVector4& operator /= ( const t_T fScalar )
	{
		ASSERT( fScalar != 0.0f );
		t_T fInv = 1.0f / fScalar;
		x *= fInv;
		y *= fInv;
		z *= fInv;
		w *= fInv;
		return *this;
	}

	TVector4& operator /= ( const TVector4& rkVector )
	{
		x /= rkVector.x;
		y /= rkVector.y;
		z /= rkVector.z;
		w /= rkVector.w;
		return *this;
	}

	t_T DotProduct(const TVector4& vec) const
	{
		return x*vec.x+y*vec.y+z*vec.z;
	}
	bool IsNaN() const
	{
		return Math::IsNaN(x) || Math::IsNaN(y) || Math::IsNaN(z) || Math::IsNaN(w);
	}
	t_T Length () const { return jagam::Math::Sqrt(x*x+y*y+z*z+w*w); }
	t_T LengthSq () const { return x*x+y*y+z*z+w*w; }

	static const TVector4 ZERO;
};

using Vector4f = TVector4<float32_t>;
using Vector4d = TVector4<float64_t>;