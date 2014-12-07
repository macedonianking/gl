#ifndef WC_MATRIX_H
#define WC_MATRIX_H

#include "wc_point.h"

#define IDENTITY_MATRIX3F	{ 1.0, 0.0, 0.0, \
							  0.0, 1.0, 0.0, \
							  0.0, 0.0, 1.0  }

struct wcMatrix3f
{
public:
	GLfloat		mat[3][3];
};

extern struct wcMatrix3f WC_MATRIX3F_IDENTITY;

class GlMatrix3f
{
public:
	GlMatrix3f(const struct wcMatrix3f *mat);
	
	operator GLfloat*() 
	{
		return &mMat.mat[0][0];
	}

private:
	struct wcMatrix3f	mMat;
};

class Matrix3f
{
public:
	Matrix3f();
	Matrix3f(const struct wcMatrix3f *mat);

	void SetMatrix(const wcMatrix3f *mat);

	void PrevMultiply(const wcMatrix3f *mat);
	void PrevTranslate(GLfloat tx, GLfloat ty, GLfloat tz);
	void PrevScale(GLfloat sx, GLfloat sy);
	void PrevScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy);
	void PrevRotate(GLfloat angle);
	void PrevRotate(GLfloat angle, GLfloat px, GLfloat py);

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

void SetMatrix3fIdentity(struct wcMatrix3f *ptr);
void SetMatrix3fTranslate(struct wcMatrix3f *ptr, GLfloat tx, GLfloat ty);
void SetMatrix3fScale(struct wcMatrix3f *ptr, GLfloat sx, GLfloat sy);
void SetMatrix3fScale(struct wcMatrix3f *ptr, GLfloat px, GLfloat py,
					  GLfloat sx, GLfloat sy);
void SetMatrix3fRotate(struct wcMatrix3f *ptr, GLfloat angle);
void SetMatrix3fRotate(struct wcMatrix3f *ptr, GLfloat angle, 
					   GLfloat px, GLfloat py);
struct wcMatrix3f wcMatrix3fMulitply();

#endif
