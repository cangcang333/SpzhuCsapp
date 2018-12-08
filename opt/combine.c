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
/* $end combine1 */

char combine3_descr[] = "combine3: Array reference to vector data";
