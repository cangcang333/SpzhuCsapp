#include <stdlib.h>
#include "combine.h"

/* Combining functions */

char combine1_descr[] = "combine1: Maximum use of data abstraction";
/* $begin combine1 */
void combine1(vec_ptr v, data_t *data)
{
	long i;

	*dest = IDENT;
	for (i = 0; i < vec_length(v); i++)
	{
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}
/* $end combine1 */

char combine2_descr[] = "combine2: Take vec_length() out of loop";
/* $begin combine2 */
void combine2(vec_ptr v, data_t *data)
{
	long i;
	long length = vec_length(v);

	*dest = IDENT;
	for (i = 0; i < length; i++)
	{
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}
/* $end combine2 */

char combine3_descr[] = "combine3: Array reference to vector data";
/* $begin combine3 */
/* Direct access to vector data */
void combine3(vec_ptr v, data_t *data)
{
	long i;
	long length = vec_length(v);
	data_t *data = get_vec_start(v);

	*dest = IDENT;
	for (i = 0; i < length; i++)
	{
		*dest = *dest OP data[i];
	}
}
/* $end combine3 */

char combine3w_descr[] = "combine3w: Update *dest within loop only with write"
/* $begin combine3w */
/* Make sure dest updated on each iteration */
void combine3w(vec_ptr v, data_t *data)
{
	long i;
	long length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* Initialize in event length <= 0 */
	*dest = acc;
	for (i = 0; i < length; i++)
	{
		acc = acc OP data[i];
		*dest = acc;
	}
}
/* $end combine3w */

char combine4_descr[] = "combine4: Array reference, accumulate in temporary";
/* $begin combine4 */
/* Accumulate result in local variable */
void combine4(vec_ptr v, data_t *data)
{
	long i;
	long length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	*dest = acc;
	for (i = 0; i < length; i++)
	{
		acc = acc OP data[i];
	}
	*dest = acc;
}
/* $end combine4 */

char combine4b_descr[] = "combine4b: Include bonds check in loop";
/* $begin combine4b */
/* Include bounds check in loop */
void combine4b(vec_ptr v, data_t *data)
{
	long i;
	long length = vec_length(v);
	data_t acc = IDENT;

	for (i = 0; i < length; i++)
	{
		if (i >= 0 && i < v->len)
		{
			acc = acc OP data[i];
		}
	}
	*dest = acc;
}
/* $end combine4b */


char combine4p_descr[] = "combine4p: Pointer reference, accumulate in temporary";
/* $begin combine4p */
/* Accumulate in local variable, pointer version */
void combine4p(vec_ptr v, data_t *dest)
{
	long length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t *dend = data + length;
	data_t acc = IDENT;

	for (; data < dend; data++)
	{
		acc = acc OP *data;
	}
	*dest = acc;
}
/* $end combine4p */


char combine5_descr[] = "combine5: Array code, unrolled by 2";
/* $begin combine5 */
/* 2 * 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest)
{
	long i;
	long length = vec_length(v);
	long limit = length - 1;
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* Combine 2 elements at a time */
	for (i = 0; i < limit; i += 2)
	{
		acc = (acc OP data[i]) OP data[i+1];
	}

	/* Finish any remaining elements */
	{
		acc = acc OP data[i];
	}
	*dest = acc;
}
/* $end combine5 */













