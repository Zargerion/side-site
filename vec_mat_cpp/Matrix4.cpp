#include "Matrix4.h"



// ======================================================================
float MINOR(const TMatrix4<float>* In, const size_t r0, const size_t r1, const size_t r2,
							const size_t c0, const size_t c1, const size_t c2)
{
	return	In->m[r0][c0] * (In->m[r1][c1] * In->m[r2][c2] - In->m[r2][c1] * In->m[r1][c2]) -
			In->m[r0][c1] * (In->m[r1][c0] * In->m[r2][c2] - In->m[r2][c0] * In->m[r1][c2]) +
			In->m[r0][c2] * (In->m[r1][c0] * In->m[r2][c1] - In->m[r2][c0] * In->m[r1][c1]);
}
// ======================================================================
TMatrix4<float>& TMatrix4<float>::Inverse(const TMatrix4<float> * In)
{
	float m00 = In->m[0][0], m01 = In->m[0][1], m02 = In->m[0][2], m03 = In->m[0][3];
	float m10 = In->m[1][0], m11 = In->m[1][1], m12 = In->m[1][2], m13 = In->m[1][3];
	float m20 = In->m[2][0], m21 = In->m[2][1], m22 = In->m[2][2], m23 = In->m[2][3];
	float m30 = In->m[3][0], m31 = In->m[3][1], m32 = In->m[3][2], m33 = In->m[3][3];

	float v0 = m20 * m31 - m21 * m30;
	float v1 = m20 * m32 - m22 * m30;
	float v2 = m20 * m33 - m23 * m30;
	float v3 = m21 * m32 - m22 * m31;
	float v4 = m21 * m33 - m23 * m31;
	float v5 = m22 * m33 - m23 * m32;

	float t00 = + (v5 * m11 - v4 * m12 + v3 * m13);
	float t10 = - (v5 * m10 - v2 * m12 + v1 * m13);
	float t20 = + (v4 * m10 - v2 * m11 + v0 * m13);
	float t30 = - (v3 * m10 - v1 * m11 + v0 * m12);

	float invDet = 1.0f / (t00 * m00 + t10 * m01 + t20 * m02 + t30 * m03);

	float d00 = t00 * invDet;
	float d10 = t10 * invDet;
	float d20 = t20 * invDet;
	float d30 = t30 * invDet;

	float d01 = - (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
	float d11 = + (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
	float d21 = - (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
	float d31 = + (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

	v0 = m10 * m31 - m11 * m30;
	v1 = m10 * m32 - m12 * m30;
	v2 = m10 * m33 - m13 * m30;
	v3 = m11 * m32 - m12 * m31;
	v4 = m11 * m33 - m13 * m31;
	v5 = m12 * m33 - m13 * m32;

	float d02 = + (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
	float d12 = - (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
	float d22 = + (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
	float d32 = - (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

	v0 = m21 * m10 - m20 * m11;
	v1 = m22 * m10 - m20 * m12;
	v2 = m23 * m10 - m20 * m13;
	v3 = m22 * m11 - m21 * m12;
	v4 = m23 * m11 - m21 * m13;
	v5 = m23 * m12 - m22 * m13;

	float d03 = - (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
	float d13 = + (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
	float d23 = - (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
	float d33 = + (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

	m[0][0] = d00; m[0][1] = d01; m[0][2] = d02; m[0][3] = d03;
	m[1][0] = d10; m[1][1] = d11; m[1][2] = d12; m[1][3] = d13;
	m[2][0] = d20; m[2][1] = d21; m[2][2] = d22; m[2][3] = d23;
	m[3][0] = d30; m[3][1] = d31; m[3][2] = d32; m[3][3] = d33;
	return *this;
}
// -----------------------------------------------------------------------
float TMatrix4<float>::Determinant() const
{
	return	m[0][0] * MINOR(this, 1, 2, 3, 1, 2, 3) -
			m[0][1] * MINOR(this, 1, 2, 3, 0, 2, 3) +
			m[0][2] * MINOR(this, 1, 2, 3, 0, 1, 3) -
			m[0][3] * MINOR(this, 1, 2, 3, 0, 1, 2);
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Transpose(const TMatrix4<float> * In)
{
	if(this != In)
	{
		m[0][0] = In->m[0][0]; m[0][1] = In->m[1][0]; m[0][2] = In->m[2][0]; m[0][3] = In->m[3][0];
		m[1][0] = In->m[0][1]; m[1][1] = In->m[1][1]; m[1][2] = In->m[2][1]; m[1][3] = In->m[3][1];
		m[2][0] = In->m[0][2]; m[2][1] = In->m[1][2]; m[2][2] = In->m[2][2]; m[2][3] = In->m[3][2];
		m[3][0] = In->m[0][3]; m[3][1] = In->m[1][3]; m[3][2] = In->m[2][3]; m[3][3] = In->m[3][3];
	}
	else
	{
		std::swap(m[0][1], m[1][0]); std::swap(m[0][2], m[2][0]);
		std::swap(m[1][3], m[3][1]); std::swap(m[2][3], m[3][2]);
		std::swap(m[0][3], m[3][0]); std::swap(m[1][2], m[2][1]);
	}
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Identity()
{
	m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
	m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] =
	m[2][0] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Multiply(const TMatrix4<float> *pM1, const TMatrix4<float> *pM2)
{
	TMatrix4<float> r;
	r.m[0][0] = pM1->m[0][0] * pM2->m[0][0] + pM1->m[0][1] * pM2->m[1][0] + pM1->m[0][2] * pM2->m[2][0] + pM1->m[0][3] * pM2->m[3][0];
	r.m[0][1] = pM1->m[0][0] * pM2->m[0][1] + pM1->m[0][1] * pM2->m[1][1] + pM1->m[0][2] * pM2->m[2][1] + pM1->m[0][3] * pM2->m[3][1];
	r.m[0][2] = pM1->m[0][0] * pM2->m[0][2] + pM1->m[0][1] * pM2->m[1][2] + pM1->m[0][2] * pM2->m[2][2] + pM1->m[0][3] * pM2->m[3][2];
	r.m[0][3] = pM1->m[0][0] * pM2->m[0][3] + pM1->m[0][1] * pM2->m[1][3] + pM1->m[0][2] * pM2->m[2][3] + pM1->m[0][3] * pM2->m[3][3];

	r.m[1][0] = pM1->m[1][0] * pM2->m[0][0] + pM1->m[1][1] * pM2->m[1][0] + pM1->m[1][2] * pM2->m[2][0] + pM1->m[1][3] * pM2->m[3][0];
	r.m[1][1] = pM1->m[1][0] * pM2->m[0][1] + pM1->m[1][1] * pM2->m[1][1] + pM1->m[1][2] * pM2->m[2][1] + pM1->m[1][3] * pM2->m[3][1];
	r.m[1][2] = pM1->m[1][0] * pM2->m[0][2] + pM1->m[1][1] * pM2->m[1][2] + pM1->m[1][2] * pM2->m[2][2] + pM1->m[1][3] * pM2->m[3][2];
	r.m[1][3] = pM1->m[1][0] * pM2->m[0][3] + pM1->m[1][1] * pM2->m[1][3] + pM1->m[1][2] * pM2->m[2][3] + pM1->m[1][3] * pM2->m[3][3];

	r.m[2][0] = pM1->m[2][0] * pM2->m[0][0] + pM1->m[2][1] * pM2->m[1][0] + pM1->m[2][2] * pM2->m[2][0] + pM1->m[2][3] * pM2->m[3][0];
	r.m[2][1] = pM1->m[2][0] * pM2->m[0][1] + pM1->m[2][1] * pM2->m[1][1] + pM1->m[2][2] * pM2->m[2][1] + pM1->m[2][3] * pM2->m[3][1];
	r.m[2][2] = pM1->m[2][0] * pM2->m[0][2] + pM1->m[2][1] * pM2->m[1][2] + pM1->m[2][2] * pM2->m[2][2] + pM1->m[2][3] * pM2->m[3][2];
	r.m[2][3] = pM1->m[2][0] * pM2->m[0][3] + pM1->m[2][1] * pM2->m[1][3] + pM1->m[2][2] * pM2->m[2][3] + pM1->m[2][3] * pM2->m[3][3];

	r.m[3][0] = pM1->m[3][0] * pM2->m[0][0] + pM1->m[3][1] * pM2->m[1][0] + pM1->m[3][2] * pM2->m[2][0] + pM1->m[3][3] * pM2->m[3][0];
	r.m[3][1] = pM1->m[3][0] * pM2->m[0][1] + pM1->m[3][1] * pM2->m[1][1] + pM1->m[3][2] * pM2->m[2][1] + pM1->m[3][3] * pM2->m[3][1];
	r.m[3][2] = pM1->m[3][0] * pM2->m[0][2] + pM1->m[3][1] * pM2->m[1][2] + pM1->m[3][2] * pM2->m[2][2] + pM1->m[3][3] * pM2->m[3][2];
	r.m[3][3] = pM1->m[3][0] * pM2->m[0][3] + pM1->m[3][1] * pM2->m[1][3] + pM1->m[3][2] * pM2->m[2][3] + pM1->m[3][3] * pM2->m[3][3];
	*this = r;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::MultiplyTranspose(const TMatrix4<float> *pM1, const TMatrix4<float> *pM2)
{
	TMatrix4<float> r;
	r.m[0][0] = pM1->m[0][0] * pM2->m[0][0] + pM1->m[0][1] * pM2->m[1][0] + pM1->m[0][2] * pM2->m[2][0] + pM1->m[0][3] * pM2->m[3][0];
	r.m[1][0] = pM1->m[0][0] * pM2->m[0][1] + pM1->m[0][1] * pM2->m[1][1] + pM1->m[0][2] * pM2->m[2][1] + pM1->m[0][3] * pM2->m[3][1];
	r.m[2][0] = pM1->m[0][0] * pM2->m[0][2] + pM1->m[0][1] * pM2->m[1][2] + pM1->m[0][2] * pM2->m[2][2] + pM1->m[0][3] * pM2->m[3][2];
	r.m[3][0] = pM1->m[0][0] * pM2->m[0][3] + pM1->m[0][1] * pM2->m[1][3] + pM1->m[0][2] * pM2->m[2][3] + pM1->m[0][3] * pM2->m[3][3];

	r.m[0][1] = pM1->m[1][0] * pM2->m[0][0] + pM1->m[1][1] * pM2->m[1][0] + pM1->m[1][2] * pM2->m[2][0] + pM1->m[1][3] * pM2->m[3][0];
	r.m[1][1] = pM1->m[1][0] * pM2->m[0][1] + pM1->m[1][1] * pM2->m[1][1] + pM1->m[1][2] * pM2->m[2][1] + pM1->m[1][3] * pM2->m[3][1];
	r.m[2][1] = pM1->m[1][0] * pM2->m[0][2] + pM1->m[1][1] * pM2->m[1][2] + pM1->m[1][2] * pM2->m[2][2] + pM1->m[1][3] * pM2->m[3][2];
	r.m[3][1] = pM1->m[1][0] * pM2->m[0][3] + pM1->m[1][1] * pM2->m[1][3] + pM1->m[1][2] * pM2->m[2][3] + pM1->m[1][3] * pM2->m[3][3];

	r.m[0][2] = pM1->m[2][0] * pM2->m[0][0] + pM1->m[2][1] * pM2->m[1][0] + pM1->m[2][2] * pM2->m[2][0] + pM1->m[2][3] * pM2->m[3][0];
	r.m[1][2] = pM1->m[2][0] * pM2->m[0][1] + pM1->m[2][1] * pM2->m[1][1] + pM1->m[2][2] * pM2->m[2][1] + pM1->m[2][3] * pM2->m[3][1];
	r.m[2][2] = pM1->m[2][0] * pM2->m[0][2] + pM1->m[2][1] * pM2->m[1][2] + pM1->m[2][2] * pM2->m[2][2] + pM1->m[2][3] * pM2->m[3][2];
	r.m[3][2] = pM1->m[2][0] * pM2->m[0][3] + pM1->m[2][1] * pM2->m[1][3] + pM1->m[2][2] * pM2->m[2][3] + pM1->m[2][3] * pM2->m[3][3];

	r.m[0][3] = pM1->m[3][0] * pM2->m[0][0] + pM1->m[3][1] * pM2->m[1][0] + pM1->m[3][2] * pM2->m[2][0] + pM1->m[3][3] * pM2->m[3][0];
	r.m[1][3] = pM1->m[3][0] * pM2->m[0][1] + pM1->m[3][1] * pM2->m[1][1] + pM1->m[3][2] * pM2->m[2][1] + pM1->m[3][3] * pM2->m[3][1];
	r.m[2][3] = pM1->m[3][0] * pM2->m[0][2] + pM1->m[3][1] * pM2->m[1][2] + pM1->m[3][2] * pM2->m[2][2] + pM1->m[3][3] * pM2->m[3][2];
	r.m[3][3] = pM1->m[3][0] * pM2->m[0][3] + pM1->m[3][1] * pM2->m[1][3] + pM1->m[3][2] * pM2->m[2][3] + pM1->m[3][3] * pM2->m[3][3];
	*this = r;
	return *this;
}
// ======================================================================
TMatrix4<float>& TMatrix4<float>::FromAxes(const Vector3f* xAxis, const Vector3f* yAxis, const Vector3f* zAxis)
{
	m[0][0] = xAxis->x; m[0][1] = xAxis->y; m[0][2] = xAxis->z; m[0][3] = 0.0f;
	m[1][0] = yAxis->x; m[1][1] = yAxis->y; m[1][2] = yAxis->z; m[1][3] = 0.0f;
	m[2][0] = zAxis->x; m[2][1] = zAxis->y; m[2][2] = zAxis->z; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Translation(float tx, float ty, float tz)
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] =   tx; m[3][1] =   ty; m[3][2] =   tz; m[3][3] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Translation(const Vector3f& v)
{
	return Translation(v.x, v.y, v.z);
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Scale(float sx, float sy, float sz)
{
	m[0][0] =   sx; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =   sy; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] =   sz; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::Scale(const Vector3f& v)
{
	return Scale(v.x, v.y, v.z);
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::RotationX(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = fCos; m[1][2] =-fSin; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = fSin; m[2][2] = fCos; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::RotationY(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = fCos; m[0][1] = 0.0f; m[0][2] = fSin; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] =-fSin; m[2][1] = 0.0f; m[2][2] = fCos; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::RotationZ(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = fCos; m[0][1] =-fSin; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = fSin; m[1][1] = fCos; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::RotationAxis(const Vector3f *pV, float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	float fOneMinusCos = 1.0f-fCos;
	float fX2 = pV->x*pV->x;
	float fY2 = pV->y*pV->y;
	float fZ2 = pV->z*pV->z;
	float fXYM = pV->x*pV->y*fOneMinusCos;
	float fXZM = pV->x*pV->z*fOneMinusCos;
	float fYZM = pV->y*pV->z*fOneMinusCos;
	float fXSin = pV->x*fSin;
	float fYSin = pV->y*fSin;
	float fZSin = pV->z*fSin;

	m[0][0] = fX2*fOneMinusCos+fCos;
	m[0][1] = fXYM-fZSin;
	m[0][2] = fXZM+fYSin;
	m[1][0] = fXYM+fZSin;
	m[1][1] = fY2*fOneMinusCos+fCos;
	m[1][2] = fYZM-fXSin;
	m[2][0] = fXZM-fYSin;
	m[2][1] = fYZM+fXSin;
	m[2][2] = fZ2*fOneMinusCos+fCos;
	m[3][0] = m[3][1] = m[3][2] = 0.0f; m[3][3] = 1.0f;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::RotationYawPitchRoll(float Yaw, float Pitch, float Roll)
{
	TMatrix4<float> Rot;
	RotationZ(Roll);
	Multiply(this, &Rot.RotationX(Pitch));
	Multiply(this, &Rot.RotationY(Yaw));
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::PerspectiveFovLH (float fovy, float Aspect, float zn, float zf)
{
	float yS = 1.0f/std::tan(fovy*0.5f);
	float xS = yS/Aspect;
	m[0][0] =   xS; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =   yS; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = zf/(zf-zn); m[2][3] = 1.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = -zn*zf/(zf-zn); m[3][3] = 0.0f; //! ���� 1.0f
	return *this;
}
// -----------------------------------------------------------------------
TMatrix4<float>& TMatrix4<float>::PerspectiveFovRH (float fovy, float Aspect, float zn, float zf)
{
	float yS = 1.0f/ std::tan(fovy*0.5f);
	float xS = yS/Aspect;
	m[0][0] =   xS; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =   yS; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = zf/(zn-zf); m[2][3] = -1.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = zn*zf/(zn-zf); m[3][3] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------