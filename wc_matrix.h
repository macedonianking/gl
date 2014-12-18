#ifndef WC_MATRIX_H
#define WC_MATRIX_H

#include "wc_point.h"

#include <string>
#include <sstream>

class wcMatrix3f
{
public:
	wcMatrix3f();
	wcMatrix3f(const GLfloat *ptr);

	void SetTranslate(GLfloat tx, GLfloat ty);
	void SetScale(GLfloat sx, GLfloat sy);
	void SetScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy);
	void SetRotate(GLfloat angle);
	void SetRotate(GLfloat angle, GLfloat px, GLfloat py);

	wcMatrix3f	Transpose() const;
	void		SetIdentity();
	std::string ToString() const;

	void PrevMultiply(const wcMatrix3f &rhs);

	GLfloat		mat[3][3];
};

class wcMatrix4f
{
public:
	wcMatrix4f();
	wcMatrix4f(const GLfloat *ptr);
	wcMatrix4f(const wcMatrix3f& mat3);


	wcMatrix4f	Transpose() const;
	void		SetIdentity();
	std::string ToString() const;

	GLfloat		mat[4][4];
};

extern struct wcMatrix3f WC_MATRIX3F_IDENTITY;

class GlMatrix4f
{
public:
	GlMatrix4f();
	GlMatrix4f(const wcMatrix3f *mat);
	GlMatrix4f(const wcMatrix4f *mat);

	operator GLfloat*();
	operator const GLfloat*() const;

private:
	wcMatrix4f	mMat;
};

class Matrix3f
{
public:
	Matrix3f();
	Matrix3f(const struct wcMatrix3f *mat);

	void SetMatrix(const wcMatrix3f *mat);

	void PrevMultiply(const wcMatrix3f *mat);
	void PrevTranslate(GLfloat tx, GLfloat ty);
	void PrevScale(GLfloat sx, GLfloat sy);
	void PrevScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy);
	void PrevRotate(GLfloat angle);
	void PrevRotate(GLfloat angle, GLfloat px, GLfloat py);
	
	const GlMatrix4f GetGlMatrix() const;

	operator const struct wcMatrix3f*() const
	{
		return &mMat;
	}

	operator struct wcMatrix3f*() 
	{
		return &mMat;
	}

private:
	struct wcMatrix3f mMat;
};

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

	void SetIdentity();
	void SetTranslate(Tp tx, Tp ty, Tp tz);

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
void WcMatrix4T<Tp>::SetIdentity()
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			if (r != c)
			{
				mMat[r][c] = (Tp)0.0;
			}
			else
			{
				mMat[r][c] = (Tp)1.0;
			}
		}
	}
}

template<typename Tp>
const GlMatrixT<Tp> WcMatrix4T<Tp>::GetGlMatrix() const
{
	GlMatrixT<Tp> glMatrix;
	GetTranspose(glMatrix.mMat);
	return glMatrix;
}

template<typename Tp>
void WcMatrix4T<Tp>::SetTranslate(Tp tx, Tp ty, Tp tz)
{
	SetIdentity();
	mMat[0][3] = tx;
	mMat[1][3] = ty;
	mMat[2][3] = tz;
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
void  WcMatrix4T<Tp>::GetTranspose(Tp mat[][4]) const
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

typedef WcMatrix4T<GLfloat>		WcMatrix4F;
typedef WcMatrix4T<GLdouble>	WcMatrix4D;

void SetMatrix3fIdentity(struct wcMatrix3f *ptr);
void SetMatrix3fTranslate(struct wcMatrix3f *ptr, GLfloat tx, GLfloat ty);
void SetMatrix3fScale(struct wcMatrix3f *ptr, GLfloat sx, GLfloat sy);
void SetMatrix3fScale(struct wcMatrix3f *ptr, GLfloat px, GLfloat py,
					  GLfloat sx, GLfloat sy);
void SetMatrix3fRotate(struct wcMatrix3f *ptr, GLfloat angle);
void SetMatrix3fRotate(struct wcMatrix3f *ptr, GLfloat angle, 
					   GLfloat px, GLfloat py);
struct wcMatrix3f wcMatrix3fMulitply(struct wcMatrix3f *prev,
									 struct wcMatrix3f *next);

#endif
