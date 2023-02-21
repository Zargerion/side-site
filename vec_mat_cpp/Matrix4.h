#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"

// ========================================================================
template<typename t_T>
struct TMatrix4 : public jagam::Math::jaMatrix4<t_T>
{
	TMatrix4() { }
	TMatrix4 (const TMatrix4& rkMatrix) { memcpy(m, rkMatrix.m, sizeof(m)); }
	// -------------------------------------------------------------------------
	TMatrix4 (const TMatrix3<t_T>& rkMatrix)
	{
		for (size_t r = 0; r < 3; ++r)
			for (size_t c = 0; c < 3; ++c)
				m[r][c] = rkMatrix.m[r][c];
		m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f; m[3][3] = 1.0f;
	}
	// -------------------------------------------------------------------------
	TMatrix4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33 )
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}
	// -------------------------------------------------------------------------
	t_T (&operator[](int i))[4] { return m[i]; }
	const t_T (&operator[](int i) const)[4] { return m[i]; }
	TMatrix4& Transpose(const TMatrix4 * In);
	float Determinant() const;
	TMatrix4& Inverse(const TMatrix4 * In);
	TMatrix4& Identity();
	TMatrix4& Multiply(const TMatrix4 *pM1, const TMatrix4 *pM2);
	TMatrix4& MultiplyTranspose(const TMatrix4 *pM1, const TMatrix4 *pM2);
	// -----------------------------------------------------------------------
	TMatrix4 operator* ( const TMatrix4 &rkMatrix ) const
	{
		TMatrix4 result;
		result.Multiply(this, &rkMatrix);
		return result;
	}
	// -----------------------------------------------------------------------
	TMatrix4 operator+ (const TMatrix4& rkMatrix) const
	{
		TMatrix4 kSum;
		for (size_t i = 0; i < 16; ++i)
			kSum._m[i] = _m[i] + rkMatrix._m[i];
		return kSum;
	}
	// -----------------------------------------------------------------------
	TMatrix4 operator- (const TMatrix4& rkMatrix) const
	{
		TMatrix4 kDiff;
		for (size_t i = 0; i < 16; ++i)
			kDiff._m[i] = _m[i] - rkMatrix._m[i];
		return kDiff;
	}
	// -----------------------------------------------------------------------
	TMatrix4 operator- () const
	{
		TMatrix4 kNeg;
		for (size_t i = 0; i < 16; ++i)
			kNeg._m[i] = -_m[i];
		return kNeg;
	}
	// -----------------------------------------------------------------------
	TMatrix4 operator* (float fScalar) const
	{
		TMatrix4 kProd;
		for (size_t i = 0; i < 16; ++i)
			kProd._m[i] = fScalar*_m[i];
		return kProd;
	}
	// -------------------------------------------------------------------------
	TMatrix4& FromAxes(const TVector3<t_T>* xAxis, const TVector3<t_T>* yAxis, const TVector3<t_T>* zAxis);
	TMatrix4& Translation(float tx, float ty, float tz);
	TMatrix4& Translation(const TVector3<t_T>& v);
	TMatrix4& Scale(float sx, float sy, float sz);
	TMatrix4& Scale(const TVector3<t_T>& v);
	TMatrix4& RotationX (float Angle);
	TMatrix4& RotationY (float Angle);
	TMatrix4& RotationZ (float Angle);
	TMatrix4& RotationAxis (const TVector3<t_T> *pV, float Angle);
	TMatrix4& RotationYawPitchRoll (float Yaw, float Pitch, float Roll);
	TMatrix4& PerspectiveFovLH (float fovy, float Aspect, float zn, float zf);
	TMatrix4& PerspectiveFovRH (float fovy, float Aspect, float zn, float zf);
};
// ========================================================================

using Matrix4f = TMatrix4<float32_t>;
using Matrix4d = TMatrix4<float64_t>;
