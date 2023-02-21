#pragma once

template<typename t_T>
struct TVector2 : public jagam::Math::jaVector2<t_T>
{
	TVector2() { }
	TVector2(const t_T fX, const t_T fY):jaVector2(fX,fY) { }
	TVector2(const jagam::Math::jaVector2<t_T>& v):jaVector2(v) { }
	explicit TVector2(const t_T (&afCoordinate)[2]):jaVector2(afCoordinate) { }
	explicit TVector2(const t_T* r):jaVector2(r) { }

	void Swap(TVector2& other) { std::swap(x, other.x); std::swap(y, other.y); }
	t_T operator [] (const size_t i) const { ASSERT(i < 2); return c[i]; }
	t_T& operator [] ( const size_t i ) { ASSERT(i < 2); return c[i]; }
	t_T* ptr() { return c; }
	const t_T* ptr() const { return &x; }

	TVector2& operator = ( const TVector2& rkVector )
	{
		x = rkVector.x;
		y = rkVector.y;
		return *this;
	}

	TVector2& operator = ( const t_T fScalar)
	{
		x = fScalar;
		y = fScalar;
		return *this;
	}

	bool operator == ( const TVector2& rkVector ) const
	{
		return ( x == rkVector.x && y == rkVector.y );
	}

	bool operator != ( const TVector2& rkVector ) const
	{
		return ( x != rkVector.x || y != rkVector.y  );
	}

	TVector2 operator + ( const TVector2& rkVector ) const
	{
		return TVector2(x + rkVector.x, y + rkVector.y);
	}

	TVector2 operator - ( const TVector2& rkVector ) const
	{
		return TVector2(x - rkVector.x, y - rkVector.y);
	}

	TVector2 operator * ( const t_T fScalar ) const
	{
		return TVector2(x * fScalar, y * fScalar);
	}

	TVector2 operator * ( const TVector2& rhs) const
	{
		return TVector2(x * rhs.x, y * rhs.y);
	}

	TVector2 operator / ( const t_T fScalar ) const
	{
		ASSERT( fScalar != 0.0 );
		float fInv = 1.0f / fScalar;
		return TVector2(x * fInv,y * fInv);
	}

	TVector2 operator / ( const TVector2& rhs) const
	{
		return TVector2(x / rhs.x, y / rhs.y);
	}

	const TVector2& operator+ () const
	{
		return *this;
	}

	TVector2 operator- () const
	{
		return TVector2(-x, -y);
	}

	friend TVector2 operator * ( const t_T fScalar, const TVector2& rkVector )
	{
		return TVector2(fScalar * rkVector.x, fScalar * rkVector.y);
	}

	friend TVector2 operator / ( const t_T fScalar, const TVector2& rkVector )
	{
		return TVector2(fScalar / rkVector.x, fScalar / rkVector.y);
	}

	friend TVector2 operator + (const t_T lhs, const TVector2& rhs)
	{
		return TVector2(lhs + rhs.x, lhs + rhs.y);
	}

	friend TVector2 operator - (const t_T lhs, const TVector2& rhs)
	{
		return TVector2(lhs - rhs.x, lhs - rhs.y);
	}

	TVector2& operator += ( const TVector2& rkVector )
	{
		x += rkVector.x;
		y += rkVector.y;
		return *this;
	}

	TVector2& operator += ( const float fScaler )
	{
		x += fScaler;
		y += fScaler;
		return *this;
	}

	TVector2& operator -= ( const TVector2& rkVector )
	{
		x -= rkVector.x;
		y -= rkVector.y;
		return *this;
	}

	TVector2& operator -= ( const float fScaler )
	{
		x -= fScaler;
		y -= fScaler;
		return *this;
	}

	TVector2& operator *= ( const float fScalar )
	{
		x *= fScalar;
		y *= fScalar;
		return *this;
	}

	TVector2& operator *= ( const TVector2& rkVector )
	{
		x *= rkVector.x;
		y *= rkVector.y;
		return *this;
	}

	TVector2& operator /= ( const float fScalar )
	{
		ASSERT(fScalar != 0.0);
		float fInv = 1.0f/fScalar;
		x *= fInv;
		y *= fInv;
		return *this;
	}

	TVector2& operator /= ( const TVector2& rkVector )
	{
		x /= rkVector.x;
		y /= rkVector.y;
		return *this;
	}

	float Length () const { return jagam::Math::Sqrt(x*x+y*y); }
	float LengthSq () const { return x*x+y*y; }
	float Distance(const TVector2& rhs) const { return (*this - rhs).Length(); }
	float DistanceSq(const TVector2& rhs) const { return (*this - rhs).LengthSq(); }

	float DotProduct(const TVector2& vec) const { return x*vec.x + y*vec.y; }

	float Normalise()
	{
		float fLength = Length();
		if ( fLength > 1e-08 )
		{
			float fInvLength = 1.0f/fLength;
			x *= fInvLength;
			y *= fInvLength;
		}
		return fLength;
	}

	TVector2 MidPoint( const TVector2& vec ) const { return TVector2((x + vec.x)*0.5f, (y + vec.y)*0.5f); }

	bool operator < ( const TVector2& rhs ) const { return x < rhs.x && y < rhs.y; }
	bool operator > ( const TVector2& rhs ) const { return x > rhs.x && y > rhs.y; }

	void MakeFloor( const TVector2& cmp )
	{
		if( cmp.x < x ) x = cmp.x;
		if( cmp.y < y ) y = cmp.y;
	}

	void MakeCeil( const TVector2& cmp )
	{
		if( cmp.x > x ) x = cmp.x;
		if( cmp.y > y ) y = cmp.y;
	}

	TVector2 CrossProduct() const { return TVector2(-y, x); }

	TVector2 RandomDeviant(float angle) const
	{
		angle *= Math::UnitRandom() * (fPI*2.0f);
		float cosa = jagam::Math::Cos(angle);
		float sina = jagam::Math::Sin(angle);
		return  TVector2(cosa * x - sina * y, sina * x + cosa * y);
	}

	/** Returns true if this vector is zero length. */
	bool IsZeroLength(void) const
	{
		float sqlen = LengthSq();
		return (sqlen < (1e-06 * 1e-06));
	}

	TVector2 NormalisedCopy() const
	{
		TVector2 ret = *this;
		ret.Normalise();
		return ret;
	}

	TVector2 Reflect(const TVector2& normal) const
	{
		return TVector2((*this) - (2*DotProduct(normal)*normal));
	}

	bool IsNaN() const
	{
		return Math::IsNaN(x) || Math::IsNaN(y);
	}

	// special points
	static const TVector2 ZERO;
	static const TVector2 UNIT_X;
	static const TVector2 UNIT_Y;
	static const TVector2 NEGATIVE_UNIT_X;
	static const TVector2 NEGATIVE_UNIT_Y;
	static const TVector2 UNIT_SCALE;
};

using Vector2f = TVector2<float32_t>;
using Vector2d = TVector2<float64_t>;