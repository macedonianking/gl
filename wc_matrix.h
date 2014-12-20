#ifndef WC_MATRIX_H
#define WC_MATRIX_H

#include "wc_point.h"
#include "wc_math.h"

#include <string>
#include <sstream>

#define kMatrixIndexX	0
#define kMatrixIndexY	1
#define kMatrixIndexZ	2

template<typename Tp>
class WcMatrix4T;

template<typename Tp>
class GlMatrixT;

template<typename Tp>
class GlMatrixT
{
public:
	GlMatrixT()
	{
	}

	operator Tp*()
	{
		return &mMat[0][0];
	}

	operator const Tp*() const
	{
		return &mMat[0][0];
	}

	friend class WcMatrix4T<Tp>;
private:
	Tp		mMat[4][4];
};

template<typename Tp>
class WcMatrix4T
{
public:
	WcMatrix4T();
	WcMatrix4T(const Tp* mat);

	WcMatrix4T& Transpose();
	WcMatrix4T&	SetIdentity();
	WcMatrix4T&	SetTranslate(Tp tx, Tp ty, Tp tz);
	WcMatrix4T&	SetRotateX(Tp angle);
	WcMatrix4T&	SetRotateY(Tp angle);
	WcMatrix4T& SetRotateZ(Tp angle);

	WcMatrix4T GetTranspose() const;
	const GlMatrixT<Tp> GetGlMatrix() const;

	const Tp* GetGlPointer() const {
		return &mMat[0][0];
	}

	Tp *GetGlPointer() {
		return &mMat[0][0];
	}

	std::string ToString() const;
private:
	void GetTranspose(Tp mat[][4]) const;

private:
	Tp	mMat[4][4];
};

template<typename Tp>
WcMatrix4T<Tp>::WcMatrix4T()
{
	SetIdentity();
}

template<typename Tp>
WcMatrix4T<Tp>::WcMatrix4T(const Tp *mat)
{
	memcpy(&mMat[0][0], mat, sizeof(Tp) * 16);
}

template<typename Tp>
WcMatrix4T<Tp>&	WcMatrix4T<Tp>::SetIdentity()
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			if (r != c)
			{
				mMat[r][c] = (Tp)0;
			}
			else
			{
				mMat[r][c] = (Tp)1;
			}
		}
	}
	return *this;
}

template<typename Tp>
const GlMatrixT<Tp> WcMatrix4T<Tp>::GetGlMatrix() const
{
	GlMatrixT<Tp> glMatrix;
	GetTranspose(glMatrix.mMat);
	return glMatrix;
}

template<typename Tp>
WcMatrix4T<Tp>&	WcMatrix4T<Tp>::SetTranslate(Tp tx, Tp ty, Tp tz)
{
	SetIdentity();
	mMat[0][3] = tx;
	mMat[1][3] = ty;
	mMat[2][3] = tz;
	
	return *this;
}

template<typename Tp>
std::string WcMatrix4T<Tp>::ToString() const
{
	std::stringstream out;

	out << "[";
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			if (r != 0 || c != 0)
			{
				out << ", ";
			}
			out << mMat[r][c];
		}
	}
	out << "]";

	return out.str();
}

template<typename Tp>
WcMatrix4T<Tp>& WcMatrix4T<Tp>::Transpose()
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = r + 1; c != 4; ++c)
		{
			mMat[r][c] = mMat[c][r];
		}
	}
	return *this;
}

template<typename Tp>
void WcMatrix4T<Tp>::GetTranspose(Tp mat[][4]) const
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			mat[r][c] = this->mMat[c][r];
		}
	}
}

template<typename Tp>
WcMatrix4T<Tp> WcMatrix4T<Tp>::GetTranspose() const
{
	WcMatrix4T<Tp> mat;
	GetTranspose(mat.mMat);
	return mat;
}

template<typename Tp>
WcMatrix4T<Tp>& WcMatrix4T<Tp>::SetRotateX(Tp angle)
{
	double theta;
	Tp cosTheta, sinTheta;

	theta = ToRadian(angle);
	cosTheta = (Tp)cos(theta);
	sinTheta = (Tp)sin(theta);

	SetIdentity();
	mMat[kMatrixIndexY][kMatrixIndexY] = cosTheta;
	mMat[kMatrixIndexY][kMatrixIndexZ] = -sinTheta;
	mMat[kMatrixIndexZ][kMatrixIndexY] = sinTheta;
	mMat[kMatrixIndexZ][kMatrixIndexZ] = cosTheta;

	return *this;
}

template<typename Tp>
WcMatrix4T<Tp>& WcMatrix4T<Tp>::SetRotateY(Tp angle)
{
	double theta;
	Tp cosTheta, sinTheta;

	theta = ToRadian(angle);
	cosTheta = (Tp)cos(theta);
	sinTheta = (Tp)sin(theta);

	SetIdentity();
	mMat[kMatrixIndexZ][kMatrixIndexZ] = cosTheta;
	mMat[kMatrixIndexZ][kMatrixIndexX] = -sinTheta;
	mMat[kMatrixIndexX][kMatrixIndexZ] = sinTheta;
	mMat[kMatrixIndexX][kMatrixIndexX] = cosTheta;
	
	return *this;
}

template<typename Tp>
WcMatrix4T<Tp>& WcMatrix4T<Tp>::SetRotateZ(Tp angle)
{
	double theta;
	Tp cosTheta, sinTheta;

	theta = ToRadian(angle);
	cosTheta = (Tp)cos(theta);
	sinTheta = (Tp)sin(theta);

	SetIdentity();
	mMat[kMatrixIndexX][kMatrixIndexX] = cosTheta;
	mMat[kMatrixIndexX][kMatrixIndexY] = -sinTheta;
	mMat[kMatrixIndexY][kMatrixIndexX] = sinTheta;
	mMat[kMatrixIndexY][kMatrixIndexY] = cosTheta;
	
	return *this;
}

typedef WcMatrix4T<GLfloat>		WcMatrix4F;
typedef WcMatrix4T<GLdouble>	WcMatrix4D;

#endif
