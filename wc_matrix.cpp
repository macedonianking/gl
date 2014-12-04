#include "wc_matrix.h"

wcMatrix3f	gMatModelView = {1, 0, 0, 0, 1, 0, 0, 0, 1};

void wcMatrix3fSetIdentity(struct wcMatrix3f *mat)
{
	for (int i = 0; i != 3; ++i)
	{
		for (int j = 0; j != 3; ++j)
		{
			mat->m[i][j] = i == j ? 1.0F : 0.0F;
		}
	}
}

void wcMatrix3fPrevMultiply(struct wcMatrix3f *matPrev, struct wcMatrix3f *matPost)
{
	struct wcMatrix3f t;

	for (int r = 0; r != 3; ++r)
	{
		for (int c = 0; c != 3; ++c)
		{
			t.m[r][c] = matPrev->m[r][0] * matPost->m[0][c] +
						matPrev->m[r][1] * matPost->m[1][c] +
						matPrev->m[r][2] * matPost->m[2][c];
		}
	}

	*matPost = t;
}

