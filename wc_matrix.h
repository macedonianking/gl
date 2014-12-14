#ifndef WC_MATRIX_H
#define WC_MATRIX_H

#include "wc_point.h"

#include <string>

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
