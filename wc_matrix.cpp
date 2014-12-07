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
		
}
