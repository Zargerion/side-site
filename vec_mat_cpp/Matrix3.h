#pragma once

#include "Vector3.h"
#include "Vector2.h"

// ========================================================================
template<typename t_T>
struct TMatrix3 : public jagam::Math::jaMatrix3<t_T>
{
	TMatrix3() noexcept { };
	// -----------------------------------------------------------------------
	TMatrix3 (const TMatrix3& rkMatrix) noexcept
	{
		memcpy(m,rkMatrix.m,sizeof(m));
	}
	// -----------------------------------------------------------------------
	TMatrix3(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22) noexcept
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}
	// -----------------------------------------------------------------------
	t_T (&operator[](int i))[3] { return m[i]; }
	const t_T (&operator[](int i) const)[3] { return m[i]; }
	TMatrix3<float>& Transpose(const TMatrix3<float> * In);
	float Determinant() const;
	TMatrix3<float>& Inverse(const TMatrix3<float> * In);
	TMatrix3<float>& Identity();
	TMatrix3<float>& Multiply (const TMatrix3<float> *pM1, const TMatrix3<float> *pM2);
	TMatrix3<float>& MultiplyTranspose (const TMatrix3<float> *pM1, const TMatrix3<float> *pM2);

	
	TMatrix3 operator* (const TMatrix3& rkMatrix) const
	{
		TMatrix3 result;
		result.Multiply(this, &rkMatrix);
		return result;
	}
	// -----------------------------------------------------------------------
	TMatrix3 operator+ (const TMatrix3& rkMatrix) const
	{
		TMatrix3 kSum;
		for (size_t i = 0; i < 9; ++i)
			kSum._m[i] = _m[i] + rkMatrix._m[i];
		return kSum;
	}
	// -----------------------------------------------------------------------
	TMatrix3 operator- (const TMatrix3& rkMatrix) const
	{
		TMatrix3 kDiff;
		for (size_t i = 0; i < 9; ++i)
			kDiff._m[i] = _m[i] - rkMatrix._m[i];
		return kDiff;
	}
	// -----------------------------------------------------------------------
	TMatrix3 operator- () const
	{
		TMatrix3 kNeg;
		for (size_t i = 0; i < 9; ++i)
			kNeg._m[i] = -_m[i];
		return kNeg;
	}
	// -----------------------------------------------------------------------
	TMatrix3 operator* (float fScalar) const
	{
		TMatrix3 kProd;
		for (size_t i = 0; i < 9; ++i)
			kProd._m[i] = fScalar*_m[i];
		return kProd;
	}
	// -----------------------------------------------------------------------
	TMatrix3& FromAxes(const TVector3<t_T>* xAxis, const TVector3<t_T>* yAxis, const TVector3<t_T>* zAxis);
	TMatrix3& Translation(float tx, float ty);
	TMatrix3& Translation(const TVector2<t_T>& v);
	TMatrix3& Scale(float sx, float sy, float sz);
	TMatrix3& Scale(const TVector3<t_T>& v);
	TMatrix3& RotationX (float Angle);
	TMatrix3& RotationY (float Angle);
	TMatrix3& RotationZ (float Angle);
	TMatrix3& RotationAxis (const TVector3<t_T> *pV, float Angle);
	TMatrix3& RotationYawPitchRoll (float Yaw, float Pitch, float Roll);
	static TVector3<t_T>* VectorTransform(TVector3<t_T> * pOut, const TVector3<t_T>* pV, const TMatrix3* pMat);
	static TVector3<t_T>* VectorTransformTranspose(TVector3<t_T> * pOut, const TVector3<t_T>* pV, const TMatrix3* pMat);
};
// ========================================================================

using Matrix3f = TMatrix3<float32_t>;
using Matrix3d = TMatrix3<float64_t>;
