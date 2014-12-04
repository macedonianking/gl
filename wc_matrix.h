#ifndef WC_MATRIX_H
#define WC_MATRIX_H

#include "wc_point.h"

struct wcMatrix3f
{
	GLfloat	m[3][3];
};

extern wcMatrix3f gMatModelView;

void wcMatrix3fSetIdentity(struct wcMatrix3f *mat);
void wcMatrix3fPrevMultiply(struct wcMatrix3f *matPrev, struct wcMatrix3f * matPost);
void wcMatrix3fPrevTranslate(GLfloat tx, GLfloat ty);
void wcMatrix3fPrevRotate(GLfloat px, GLfloat py, GLfloat theta);
void wcMatrix3fPrevScale(GLfloat px, GLfloat py, GLfloat sx, GLfloat sy);

void wcMatrix3fMap(const struct wcMatrix3f *mat, wcPt3f *src, GLsizei count,
		wcPt3f *dst);

#endif
