#include "wc_matrix.h"

#include <memory.h>

#include "wc_math.h"


struct wcMatrix3f WC_MATRIX3F_IDENTITY = IDENTITY_MATRIX3F;

GlMatrix3f::GlMatrix3f(const struct wcMatrix3f *ptr)
{
	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			mMat.mat[r][c] = ptr->mat[c][r];
		}
	}
}

Matrix3f::Matrix3f()
	: mMat(WC_MATRIX3F_IDENTITY)
{
}

Matrix3f::Matrix3f(const struct wcMatrix3f *mat)
	: mMat(*mat)
{
}

void Matrix3f::SetMatrix(const wcMatrix3f *mat)
{
	if (&this->mMat != mat)
	{
		this->mMat = *mat;
	}
}

void Matrix3f::PrevTranslate(GLfloat tx, GLfloat ty)
{
	struct wcMatrix3f m;

	SetMatrix3fTranslate(&m, tx, ty);
	this->mMat =  wcMatrix3fMulitply(&m, &this->mMat);
}

void Matrix3f::PrevScale(GLfloat sx, GLfloat sy)
{
	struct wcMatrix3f m;

	SetMatrix3fScale(&m, sx, sy);
	this->mMat = wcMatrix3fMulitply(&m, &this->mMat);
}

void Matrix3f::PrevScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy)
{
	struct wcMatrix3f m;

	SetMatrix3fScale(&m, px, py, sx, sy);
	this->mMat = wcMatrix3fMulitply(&m, &this->mMat);
}

void Matrix3f::PrevRotate(GLfloat angle)
{
	struct wcMatrix3f m;

	SetMatrix3fRotate(&m, angle);
	this->mMat = wcMatrix3fMulitply(&m, &this->mMat);
}

void Matrix3f::PrevRotate(GLfloat angle, GLfloat px, GLfloat py)
{
	struct wcMatrix3f m;

	SetMatrix3fRotate(&m, angle, px, py);
	this->mMat = wcMatrix3fMulitply(&m, &this->mMat);
}

void SetMatrix3fIdentity(struct wcMatrix3f *mat)
{
	*mat = WC_MATRIX3F_IDENTITY;
}

void SetMatrix3fTranslate(struct wcMatrix3f *mat,
						  GLfloat tx, GLfloat ty)
{
	*mat = WC_MATRIX3F_IDENTITY;

	mat->mat[0][2] = tx;
	mat->mat[1][2] = ty;
}

void SetMatrix3fScale(struct wcMatrix3f *mat, GLfloat sx, GLfloat sy)
{
	*mat = WC_MATRIX3F_IDENTITY;
	mat->mat[0][0] = sx;
	mat->mat[1][1] = sy;
}

void SetMatrix3fScale(struct wcMatrix3f *mat, GLfloat px, GLfloat py,
					  GLfloat sx, GLfloat sy)
{
	*mat = WC_MATRIX3F_IDENTITY;
	mat->mat[0][0] = sx;
	mat->mat[1][1] = sy;
	mat->mat[0][2] = px * (1 - sx);
	mat->mat[1][2] = py * (1 - sy);
}

void SetMatrix3fRotate(struct wcMatrix3f *mat, GLfloat angle)
{
	SetMatrix3fRotate(mat, angle, 0.0F, 0.0F);
}

void SetMatrix3fRotate(struct wcMatrix3f *mat, GLfloat angle,
					   GLfloat px, GLfloat py)
{
	double radian = ToRadian(angle);

	mat->mat[0][0] = cos(radian);
	mat->mat[0][1] = -sin(radian);
	mat->mat[0][2] = px * (1 - cos(radian)) + py * sin(radian);
	mat->mat[1][0] = sin(radian);
	mat->mat[1][1] = cos(radian);
	mat->mat[1][2] = py * (1 - cos(radian)) - px * sin(radian);
}

struct wcMatrix3f wcMatrix3fMulitply(struct wcMatrix3f *prev,
								   struct wcMatrix3f *next)
{
	struct wcMatrix3f m = WC_MATRIX3F_IDENTITY;

	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			m.mat[r][c] = prev->mat[r][0] * next->mat[0][c] +
						  prev->mat[r][1] * next->mat[1][c] +
						  prev->mat[r][2] * next->mat[2][c];
		}
	}

	return m;
}
