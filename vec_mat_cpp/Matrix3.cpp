
#include "Matrix3.h"
# if 0
// ======================================================================
inline float MINOR(const TMatrix3<float>* In, const size_t r0, const size_t r1, const size_t c0, const size_t c1)
{
	return	In->m[r0][c0] * In->m[r0][c1] - In->m[r1][c0] * In->m[r1][c1];
}
// ======================================================================
TMatrix3<float>& TMatrix3<float>::Inverse(const TMatrix3<float> * pIn)
{
	TMatrix3<float> result;
	result.m[0][0] = pIn->m[1][1]*pIn->m[2][2] - pIn->m[1][2]*pIn->m[2][1];
	result.m[0][1] = pIn->m[0][2]*pIn->m[2][1] - pIn->m[0][1]*pIn->m[2][2];
	result.m[0][2] = pIn->m[0][1]*pIn->m[1][2] - pIn->m[0][2]*pIn->m[1][1];
	result.m[1][0] = pIn->m[1][2]*pIn->m[2][0] - pIn->m[1][0]*pIn->m[2][2];
	result.m[1][1] = pIn->m[0][0]*pIn->m[2][2] - pIn->m[0][2]*pIn->m[2][0];
	result.m[1][2] = pIn->m[0][2]*pIn->m[1][0] - pIn->m[0][0]*pIn->m[1][2];
	result.m[2][0] = pIn->m[1][0]*pIn->m[2][1] - pIn->m[1][1]*pIn->m[2][0];
	result.m[2][1] = pIn->m[0][1]*pIn->m[2][0] - pIn->m[0][0]*pIn->m[2][1];
	result.m[2][2] = pIn->m[0][0]*pIn->m[1][1] - pIn->m[0][1]*pIn->m[1][0];

	float fDet = pIn->m[0][0]*result.m[0][0] + pIn->m[0][1]*result.m[1][0] + pIn->m[0][2]*result.m[2][0];
	float fInvDet = 1.0f/fDet;

	for (size_t i = 0; i < 9; ++i)
		_m[i] = result._m[i]*fInvDet;
	return *this;
}
// -----------------------------------------------------------------------
float TMatrix3<float>::Determinant() const
{
	float fCofactor00 = m[1][1]*m[2][2] - m[1][2]*m[2][1];
	float fCofactor10 = m[1][2]*m[2][0] - m[1][0]*m[2][2];
	float fCofactor20 = m[1][0]*m[2][1] - m[1][1]*m[2][0];
	return m[0][0]*fCofactor00 + m[0][1]*fCofactor10 + m[0][2]*fCofactor20;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Transpose(const TMatrix3<float> * In)
{
	if(this != In)
	{
		m[0][0] = In->m[0][0]; m[0][1] = In->m[1][0]; m[0][2] = In->m[2][0];
		m[1][0] = In->m[0][1]; m[1][1] = In->m[1][1]; m[1][2] = In->m[2][1];
		m[2][0] = In->m[0][2]; m[2][1] = In->m[1][2]; m[2][2] = In->m[2][2];
	}
	else
	{
		std::swap(m[0][1], m[1][0]);
		std::swap(m[0][2], m[2][0]);
		std::swap(m[1][2], m[2][1]);
	}
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Identity()
{
	m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1] = 0.0f;
	m[0][0] = m[1][1] = m[2][2] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Multiply (const TMatrix3<float> *pM1, const TMatrix3<float> *pM2)
{
	TMatrix3<float> r;
	r.m[0][0] = pM1->m[0][0] * pM2->m[0][0] + pM1->m[0][1] * pM2->m[1][0] + pM1->m[0][2] * pM2->m[2][0];
	r.m[0][1] = pM1->m[0][0] * pM2->m[0][1] + pM1->m[0][1] * pM2->m[1][1] + pM1->m[0][2] * pM2->m[2][1];
	r.m[0][2] = pM1->m[0][0] * pM2->m[0][2] + pM1->m[0][1] * pM2->m[1][2] + pM1->m[0][2] * pM2->m[2][2];

	r.m[1][0] = pM1->m[1][0] * pM2->m[0][0] + pM1->m[1][1] * pM2->m[1][0] + pM1->m[1][2] * pM2->m[2][0];
	r.m[1][1] = pM1->m[1][0] * pM2->m[0][1] + pM1->m[1][1] * pM2->m[1][1] + pM1->m[1][2] * pM2->m[2][1];
	r.m[1][2] = pM1->m[1][0] * pM2->m[0][2] + pM1->m[1][1] * pM2->m[1][2] + pM1->m[1][2] * pM2->m[2][2];

	r.m[2][0] = pM1->m[2][0] * pM2->m[0][0] + pM1->m[2][1] * pM2->m[1][0] + pM1->m[2][2] * pM2->m[2][0];
	r.m[2][1] = pM1->m[2][0] * pM2->m[0][1] + pM1->m[2][1] * pM2->m[1][1] + pM1->m[2][2] * pM2->m[2][1];
	r.m[2][2] = pM1->m[2][0] * pM2->m[0][2] + pM1->m[2][1] * pM2->m[1][2] + pM1->m[2][2] * pM2->m[2][2];
	*this = r;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::MultiplyTranspose (const TMatrix3<float> *pM1, const TMatrix3<float> *pM2)
{
	TMatrix3<float> r;
	r.m[0][0] = pM1->m[0][0] * pM2->m[0][0] + pM1->m[0][1] * pM2->m[1][0] + pM1->m[0][2] * pM2->m[2][0];
	r.m[1][0] = pM1->m[0][0] * pM2->m[0][1] + pM1->m[0][1] * pM2->m[1][1] + pM1->m[0][2] * pM2->m[2][1];
	r.m[2][0] = pM1->m[0][0] * pM2->m[0][2] + pM1->m[0][1] * pM2->m[1][2] + pM1->m[0][2] * pM2->m[2][2];

	r.m[0][1] = pM1->m[1][0] * pM2->m[0][0] + pM1->m[1][1] * pM2->m[1][0] + pM1->m[1][2] * pM2->m[2][0];
	r.m[1][1] = pM1->m[1][0] * pM2->m[0][1] + pM1->m[1][1] * pM2->m[1][1] + pM1->m[1][2] * pM2->m[2][1];
	r.m[2][1] = pM1->m[1][0] * pM2->m[0][2] + pM1->m[1][1] * pM2->m[1][2] + pM1->m[1][2] * pM2->m[2][2];

	r.m[0][2] = pM1->m[2][0] * pM2->m[0][0] + pM1->m[2][1] * pM2->m[1][0] + pM1->m[2][2] * pM2->m[2][0];
	r.m[1][2] = pM1->m[2][0] * pM2->m[0][1] + pM1->m[2][1] * pM2->m[1][1] + pM1->m[2][2] * pM2->m[2][1];
	r.m[2][2] = pM1->m[2][0] * pM2->m[0][2] + pM1->m[2][1] * pM2->m[1][2] + pM1->m[2][2] * pM2->m[2][2];
	*this = r;
	return *this;
}
// ======================================================================
TMatrix3<float>& TMatrix3<float>::FromAxes(const Vector3f* xAxis, const Vector3f* yAxis, const Vector3f* zAxis)
{
	m[0][0] = xAxis->x; m[0][1] = xAxis->y; m[0][2] = xAxis->z;
	m[1][0] = yAxis->x; m[1][1] = yAxis->y; m[1][2] = yAxis->z;
	m[2][0] = zAxis->x; m[2][1] = zAxis->y; m[2][2] = zAxis->z;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Translation(float tx, float ty)
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
	m[2][0] =   tx; m[2][1] =   ty; m[2][2] = 1.0f;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Translation(const Vector2f& v)
{
	return Translation(v.x, v.y);
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Scale(float sx, float sy, float sz)
{
	m[0][0] =   sx; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =   sy; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] =   sz;
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::Scale(const Vector3f& v)
{
	return Scale(v.x, v.y, v.z);
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::RotationX(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = fCos; m[1][2] =-fSin;
	m[2][0] = 0.0f; m[2][1] = fSin; m[2][2] = fCos;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::RotationY(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = fCos; m[0][1] = 0.0f; m[0][2] = fSin;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
	m[2][0] =-fSin; m[2][1] = 0.0f; m[2][2] = fCos;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::RotationZ(float Angle)
{
	float fCos = std::cos(Angle);
	float fSin = std::sin(Angle);
	m[0][0] = fCos; m[0][1] =-fSin; m[0][2] = 0.0f;
	m[1][0] = fSin; m[1][1] = fCos; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::RotationAxis(const Vector3f *pV, float Angle)
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
	Transpose(this);
	return *this;
}
// -----------------------------------------------------------------------
TMatrix3<float>& TMatrix3<float>::RotationYawPitchRoll(float Yaw, float Pitch, float Roll)
{
	TMatrix3<float> Rot;
	RotationZ(Roll);
	Multiply(this, &Rot.RotationX(Pitch));
	Multiply(this, &Rot.RotationY(Yaw));
	return *this;
}
// -----------------------------------------------------------------------
Vector3f* TMatrix3<float>::VectorTransform(Vector3f * pOut, const Vector3f* pV, const TMatrix3<float>* pMat)
{
	*pOut = Vector3f(
		pV->x*pMat->m[0][0] + pV->y*pMat->m[1][0] + pV->z*pMat->m[2][0],
		pV->x*pMat->m[0][1] + pV->y*pMat->m[1][1] + pV->z*pMat->m[2][1],
		pV->x*pMat->m[0][2] + pV->y*pMat->m[1][2] + pV->z*pMat->m[2][2]);
	return pOut;
}
// -----------------------------------------------------------------------
Vector3f* TMatrix3<float>::VectorTransformTranspose(Vector3f * pOut, const Vector3f* pV, const TMatrix3<float>* pMat)
{
	*pOut = Vector3f(
		pV->x*pMat->m[0][0] + pV->y*pMat->m[0][1] + pV->z*pMat->m[0][2],
		pV->x*pMat->m[1][0] + pV->y*pMat->m[1][1] + pV->z*pMat->m[1][2],
		pV->x*pMat->m[2][0] + pV->y*pMat->m[2][1] + pV->z*pMat->m[2][2]);
	return pOut;
}
// -----------------------------------------------------------------------

#endif