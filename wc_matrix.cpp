#include "wc_matrix.h"

#include <memory.h>

#include <sstream>

#include "wc_math.h"

wcMatrix3f::wcMatrix3f()
{
	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c !=3; ++c)
		{
			this->mat[r][c] = r != c ? 0.0F : 1.0F;
		}
	}
}

wcMatrix3f::wcMatrix3f(const GLfloat *ptr)
{
	memcpy(&this->mat[0][0], ptr, 9 * sizeof(GLfloat));
}

void wcMatrix3f::SetTranslate(GLfloat tx, GLfloat ty)
{
	this->SetIdentity();
	this->mat[0][2] = tx;
	this->mat[1][2] = ty;
}

void wcMatrix3f::SetScale(GLfloat sx, GLfloat sy)
{
	this->SetIdentity();
	this->mat[0][0] = sx;
	this->mat[1][1] = sy;
}

void wcMatrix3f::SetScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy)
{
	this->SetIdentity();

	this->mat[0][0] = sx;
	this->mat[1][1] = sy;
	this->mat[0][2] = px * (1 - sx);
	this->mat[1][2] = py * (1 - sy);
}

void wcMatrix3f::SetRotate(GLfloat angle)
{
	this->SetRotate(angle, 0.0F, 0.0F);
}

void wcMatrix3f::SetRotate(GLfloat angle, GLfloat px, GLfloat py)
{
	double radian = ToRadian(angle);

	this->mat[0][0] = cos(radian);
	this->mat[0][1] = -sin(radian);
	this->mat[0][2] = px * (1 - cos(radian)) + py * sin(radian);
	this->mat[1][0] = sin(radian);
	this->mat[1][1] = cos(radian);
	this->mat[1][2] = py * (1 - cos(radian)) - px * sin(radian);
}

void wcMatrix3f::SetIdentity()
{
	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c !=3; ++c)
		{
			this->mat[r][c] = r != c ? 0.0F : 1.0F;
		}
	}
}

wcMatrix3f wcMatrix3f::Transpose() const
{
	wcMatrix3f mat;

	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			mat.mat[c][r] = this->mat[r][c];	
		}
	}

	return mat;
}

std::string wcMatrix3f::ToString() const
{
	std::stringstream out;

	out << "[";
	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			if (r != 0 || c != 0)
			{
				out << ", ";
			}
			out << this->mat[r][c];
		}
	}	
	out << "]";
	return out.str();	
}

wcMatrix4f::wcMatrix4f()
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			this->mat[r][c] = r != c ? 0.0F : 1.0F; 
		}
	}
}

wcMatrix4f::wcMatrix4f(const GLfloat *ptr)
{
	memcpy(&this->mat[0][0], ptr, sizeof(GLfloat) * 16);	
}

wcMatrix4f::wcMatrix4f(const wcMatrix3f &mat)
{
	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			this->mat[r][c] = mat.mat[r][c];
		}
	}

	for (int c = 0; c != 3; ++c)
	{
		this->mat[3][c] = 0.0F;
	}

	for (int r = 0; r != 3; ++r)
	{
		this->mat[r][3] = 0.0F;
	}
	this->mat[3][3] = 1.0F;
}

void wcMatrix4f::SetIdentity()
{
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			this->mat[r][c] = r != c ? 0.0F : 1.0F; 
		}
	}
}

wcMatrix4f wcMatrix4f::Transpose() const
{
	wcMatrix4f mat;

	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			mat.mat[r][c] = this->mat[c][r];
		}
	}

	return mat;
}

std::string wcMatrix4f::ToString() const
{
	std::stringstream out;
	out << "[";
	for (int r = 0; r != 4; ++r)
	{
		for (int c = 0; c != 4; ++c)
		{
			if (r != 0 || c != 0)
				out << ", ";
			out << this->mat[r][c];
		}
	}
	out << "]";
	return out.str();
}

GlMatrix4f::GlMatrix4f(const struct wcMatrix3f *ptr)
	: mMat(ptr->Transpose())
{
}

GlMatrix4f::GlMatrix4f(const wcMatrix4f *ptr)
	: mMat(ptr->Transpose())
{
}

Matrix3f::Matrix3f()
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

const GlMatrix4f Matrix3f::GetGlMatrix() const
{
	return GlMatrix4f(&this->mMat);
}


void SetMatrix3fIdentity(struct wcMatrix3f *mat)
{
	mat->SetIdentity();
}

void SetMatrix3fTranslate(struct wcMatrix3f *mat,
						  GLfloat tx, GLfloat ty)
{
	mat->SetIdentity();

	mat->mat[0][2] = tx;
	mat->mat[1][2] = ty;
}

void SetMatrix3fScale(struct wcMatrix3f *mat, GLfloat sx, GLfloat sy)
{
	mat->SetIdentity();

	mat->mat[0][0] = sx;
	mat->mat[1][1] = sy;
}

void SetMatrix3fScale(struct wcMatrix3f *mat, GLfloat px, GLfloat py,
					  GLfloat sx, GLfloat sy)
{
	mat->SetIdentity();

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
	wcMatrix3f m;

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
