/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "LICENSE" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

/* $Header: /tmp_amd/presto/export/kbs/jutta/src/gsm/RCS/gsm_explode.c,v 1.2 1996/07/02 14:32:42 jutta Exp jutta $ */

#include "private.h"
#include "gsm.h"
#include "proto.h"

int gsm_explode P3((s, c, target), gsm s, gsm_byte * c, gsm_signal * target)
{
#	define	LARc	target
#	define	Nc	*((gsm_signal (*) [17])(target + 8))
#	define	bc	*((gsm_signal (*) [17])(target + 9))
#	define	Mc	*((gsm_signal (*) [17])(target + 10))
#	define	xmaxc	*((gsm_signal (*) [17])(target + 11))


#ifdef WAV49
	if (s->wav_fmt) {

		uword sr = 0;

		if (s->frame_index == 1) {

			sr = *c++;
			LARc[0] = sr & 0x3f;  sr >>= 6;
			sr |= (uword)*c++ << 2;
			LARc[1] = sr & 0x3f;  sr >>= 6;
			sr |= (uword)*c++ << 4;
			LARc[2] = sr & 0x1f;  sr >>= 5;
			LARc[3] = sr & 0x1f;  sr >>= 5;
			sr |= (uword)*c++ << 2;
			LARc[4] = sr & 0xf;  sr >>= 4;
			LARc[5] = sr & 0xf;  sr >>= 4;
			sr |= (uword)*c++ << 2;			/* 5 */
			LARc[6] = sr & 0x7;  sr >>= 3;
			LARc[7] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 4;
			Nc[0] = sr & 0x7f;  sr >>= 7;
			bc[0] = sr & 0x3;  sr >>= 2;
			Mc[0] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 1;
			xmaxc[0] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 12)
			xmc[0] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[1] = sr & 0x7;  sr >>= 3;
			xmc[2] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[3] = sr & 0x7;  sr >>= 3;
			xmc[4] = sr & 0x7;  sr >>= 3;
			xmc[5] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;			/* 10 */
			xmc[6] = sr & 0x7;  sr >>= 3;
			xmc[7] = sr & 0x7;  sr >>= 3;
			xmc[8] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[9] = sr & 0x7;  sr >>= 3;
			xmc[10] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[11] = sr & 0x7;  sr >>= 3;
			xmc[12] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 4;
			Nc[1] = sr & 0x7f;  sr >>= 7;
			bc[1] = sr & 0x3;  sr >>= 2;
			Mc[1] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 1;
			xmaxc[1] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 29 - 13)

			xmc[13] = sr & 0x7;  sr >>= 3;
			sr = *c++;				/* 15 */
			xmc[14] = sr & 0x7;  sr >>= 3;
			xmc[15] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[16] = sr & 0x7;  sr >>= 3;
			xmc[17] = sr & 0x7;  sr >>= 3;
			xmc[18] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[19] = sr & 0x7;  sr >>= 3;
			xmc[20] = sr & 0x7;  sr >>= 3;
			xmc[21] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[22] = sr & 0x7;  sr >>= 3;
			xmc[23] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[24] = sr & 0x7;  sr >>= 3;
			xmc[25] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 4;			/* 20 */
			Nc[2] = sr & 0x7f;  sr >>= 7;
			bc[2] = sr & 0x3;  sr >>= 2;
			Mc[2] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 1;
			xmaxc[2] = sr & 0x3f;  sr >>= 6;

#undef	xmc
#define	xmc	(target + 46 - 26)

			xmc[26] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[27] = sr & 0x7;  sr >>= 3;
			xmc[28] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[29] = sr & 0x7;  sr >>= 3;
			xmc[30] = sr & 0x7;  sr >>= 3;
			xmc[31] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[32] = sr & 0x7;  sr >>= 3;
			xmc[33] = sr & 0x7;  sr >>= 3;
			xmc[34] = sr & 0x7;  sr >>= 3;
			sr = *c++;				/* 25 */
			xmc[35] = sr & 0x7;  sr >>= 3;
			xmc[36] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[37] = sr & 0x7;  sr >>= 3;
			xmc[38] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 4;
			Nc[3] = sr & 0x7f;  sr >>= 7;
			bc[3] = sr & 0x3;  sr >>= 2;
			Mc[3] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 1;
			xmaxc[3] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 63 - 39)

			xmc[39] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[40] = sr & 0x7;  sr >>= 3;
			xmc[41] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;			/* 30 */
			xmc[42] = sr & 0x7;  sr >>= 3;
			xmc[43] = sr & 0x7;  sr >>= 3;
			xmc[44] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[45] = sr & 0x7;  sr >>= 3;
			xmc[46] = sr & 0x7;  sr >>= 3;
			xmc[47] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[48] = sr & 0x7;  sr >>= 3;
			xmc[49] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[50] = sr & 0x7;  sr >>= 3;
			xmc[51] = sr & 0x7;  sr >>= 3;

			s->frame_chain = sr & 0xf;
		}
		else {
			sr = s->frame_chain;
			sr |= (uword)*c++ << 4;			/* 1 */
			LARc[0] = sr & 0x3f;  sr >>= 6;
			LARc[1] = sr & 0x3f;  sr >>= 6;
			sr = *c++;
			LARc[2] = sr & 0x1f;  sr >>= 5;
			sr |= (uword)*c++ << 3;
			LARc[3] = sr & 0x1f;  sr >>= 5;
			LARc[4] = sr & 0xf;  sr >>= 4;
			sr |= (uword)*c++ << 2;
			LARc[5] = sr & 0xf;  sr >>= 4;
			LARc[6] = sr & 0x7;  sr >>= 3;
			LARc[7] = sr & 0x7;  sr >>= 3;
			sr = *c++;				/* 5 */
			Nc[0] = sr & 0x7f;  sr >>= 7;
			sr |= (uword)*c++ << 1;
			bc[0] = sr & 0x3;  sr >>= 2;
			Mc[0] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 5;
			xmaxc[0] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 12)
			xmc[0] = sr & 0x7;  sr >>= 3;
			xmc[1] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[2] = sr & 0x7;  sr >>= 3;
			xmc[3] = sr & 0x7;  sr >>= 3;
			xmc[4] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[5] = sr & 0x7;  sr >>= 3;
			xmc[6] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;			/* 10 */
			xmc[7] = sr & 0x7;  sr >>= 3;
			xmc[8] = sr & 0x7;  sr >>= 3;
			xmc[9] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[10] = sr & 0x7;  sr >>= 3;
			xmc[11] = sr & 0x7;  sr >>= 3;
			xmc[12] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			Nc[1] = sr & 0x7f;  sr >>= 7;
			sr |= (uword)*c++ << 1;
			bc[1] = sr & 0x3;  sr >>= 2;
			Mc[1] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 5;
			xmaxc[1] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 29 - 13)

			xmc[13] = sr & 0x7;  sr >>= 3;
			xmc[14] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;			/* 15 */
			xmc[15] = sr & 0x7;  sr >>= 3;
			xmc[16] = sr & 0x7;  sr >>= 3;
			xmc[17] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[18] = sr & 0x7;  sr >>= 3;
			xmc[19] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[20] = sr & 0x7;  sr >>= 3;
			xmc[21] = sr & 0x7;  sr >>= 3;
			xmc[22] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[23] = sr & 0x7;  sr >>= 3;
			xmc[24] = sr & 0x7;  sr >>= 3;
			xmc[25] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			Nc[2] = sr & 0x7f;  sr >>= 7;
			sr |= (uword)*c++ << 1;			/* 20 */
			bc[2] = sr & 0x3;  sr >>= 2;
			Mc[2] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 5;
			xmaxc[2] = sr & 0x3f;  sr >>= 6;
#undef	xmc
#define	xmc	(target + 46 - 26)
			xmc[26] = sr & 0x7;  sr >>= 3;
			xmc[27] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;	
			xmc[28] = sr & 0x7;  sr >>= 3;
			xmc[29] = sr & 0x7;  sr >>= 3;
			xmc[30] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			xmc[31] = sr & 0x7;  sr >>= 3;
			xmc[32] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[33] = sr & 0x7;  sr >>= 3;
			xmc[34] = sr & 0x7;  sr >>= 3;
			xmc[35] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;			/* 25 */
			xmc[36] = sr & 0x7;  sr >>= 3;
			xmc[37] = sr & 0x7;  sr >>= 3;
			xmc[38] = sr & 0x7;  sr >>= 3;
			sr = *c++;
			Nc[3] = sr & 0x7f;  sr >>= 7;
			sr |= (uword)*c++ << 1;		
			bc[3] = sr & 0x3;  sr >>= 2;
			Mc[3] = sr & 0x3;  sr >>= 2;
			sr |= (uword)*c++ << 5;
			xmaxc[3] = sr & 0x3f;  sr >>= 6;

#undef	xmc
#define	xmc	(target + 63 - 39)

			xmc[39] = sr & 0x7;  sr >>= 3;
			xmc[40] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[41] = sr & 0x7;  sr >>= 3;
			xmc[42] = sr & 0x7;  sr >>= 3;
			xmc[43] = sr & 0x7;  sr >>= 3;
			sr = *c++;				/* 30 */
			xmc[44] = sr & 0x7;  sr >>= 3;
			xmc[45] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 2;
			xmc[46] = sr & 0x7;  sr >>= 3;
			xmc[47] = sr & 0x7;  sr >>= 3;
			xmc[48] = sr & 0x7;  sr >>= 3;
			sr |= (uword)*c++ << 1;
			xmc[49] = sr & 0x7;  sr >>= 3;
			xmc[50] = sr & 0x7;  sr >>= 3;
			xmc[51] = sr & 0x7;  sr >>= 3;
		}
	}
	else
#endif
	{
	/* GSM_MAGIC  = (*c >> 4) & 0xF; */

	if (((*c >> 4) & 0x0F) != GSM_MAGIC) return -1;

	LARc[0]  = (*c++ & 0xF) << 2;		/* 1 */
	LARc[0] |= (*c >> 6) & 0x3;
	LARc[1]  = *c++ & 0x3F;
	LARc[2]  = (*c >> 3) & 0x1F;
	LARc[3]  = (*c++ & 0x7) << 2;
	LARc[3] |= (*c >> 6) & 0x3;
	LARc[4]  = (*c >> 2) & 0xF;
	LARc[5]  = (*c++ & 0x3) << 2;
	LARc[5] |= (*c >> 6) & 0x3;
	LARc[6]  = (*c >> 3) & 0x7;
	LARc[7]  = *c++ & 0x7;

	Nc[0]  = (*c >> 1) & 0x7F;

	bc[0]  = (*c++ & 0x1) << 1;
	bc[0] |= (*c >> 7) & 0x1;

	Mc[0]  = (*c >> 5) & 0x3;

	xmaxc[0]  = (*c++ & 0x1F) << 1;
	xmaxc[0] |= (*c >> 7) & 0x1;

#undef	xmc
#define	xmc	(target + 12)

	xmc[0]  = (*c >> 4) & 0x7;
	xmc[1]  = (*c >> 1) & 0x7;
	xmc[2]  = (*c++ & 0x1) << 2;
	xmc[2] |= (*c >> 6) & 0x3;
	xmc[3]  = (*c >> 3) & 0x7;
	xmc[4]  = *c++ & 0x7;
	xmc[5]  = (*c >> 5) & 0x7;
	xmc[6]  = (*c >> 2) & 0x7;
	xmc[7]  = (*c++ & 0x3) << 1;		/* 10 */
	xmc[7] |= (*c >> 7) & 0x1;
	xmc[8]  = (*c >> 4) & 0x7;
	xmc[9]  = (*c >> 1) & 0x7;
	xmc[10]  = (*c++ & 0x1) << 2;
	xmc[10] |= (*c >> 6) & 0x3;
	xmc[11]  = (*c >> 3) & 0x7;
	xmc[12]  = *c++ & 0x7;

	Nc[1]  = (*c >> 1) & 0x7F;

	bc[1]  = (*c++ & 0x1) << 1;
	bc[1] |= (*c >> 7) & 0x1;

	Mc[1]  = (*c >> 5) & 0x3;

	xmaxc[1]  = (*c++ & 0x1F) << 1;
	xmaxc[1] |= (*c >> 7) & 0x1;

#undef	xmc
#define	xmc	(target + 29 - 13)

	xmc[13]  = (*c >> 4) & 0x7;
	xmc[14]  = (*c >> 1) & 0x7;
	xmc[15]  = (*c++ & 0x1) << 2;
	xmc[15] |= (*c >> 6) & 0x3;
	xmc[16]  = (*c >> 3) & 0x7;
	xmc[17]  = *c++ & 0x7;
	xmc[18]  = (*c >> 5) & 0x7;
	xmc[19]  = (*c >> 2) & 0x7;
	xmc[20]  = (*c++ & 0x3) << 1;
	xmc[20] |= (*c >> 7) & 0x1;
	xmc[21]  = (*c >> 4) & 0x7;
	xmc[22]  = (*c >> 1) & 0x7;
	xmc[23]  = (*c++ & 0x1) << 2;
	xmc[23] |= (*c >> 6) & 0x3;
	xmc[24]  = (*c >> 3) & 0x7;
	xmc[25]  = *c++ & 0x7;

	Nc[2]  = (*c >> 1) & 0x7F;

	bc[2]  = (*c++ & 0x1) << 1;		/* 20 */
	bc[2] |= (*c >> 7) & 0x1;

	Mc[2]  = (*c >> 5) & 0x3;

	xmaxc[2]  = (*c++ & 0x1F) << 1;
	xmaxc[2] |= (*c >> 7) & 0x1;

#undef	xmc
#define	xmc	(target + 46 - 26)

	xmc[26]  = (*c >> 4) & 0x7;
	xmc[27]  = (*c >> 1) & 0x7;
	xmc[28]  = (*c++ & 0x1) << 2;
	xmc[28] |= (*c >> 6) & 0x3;
	xmc[29]  = (*c >> 3) & 0x7;
	xmc[30]  = *c++ & 0x7;
	xmc[31]  = (*c >> 5) & 0x7;
	xmc[32]  = (*c >> 2) & 0x7;
	xmc[33]  = (*c++ & 0x3) << 1;
	xmc[33] |= (*c >> 7) & 0x1;
	xmc[34]  = (*c >> 4) & 0x7;
	xmc[35]  = (*c >> 1) & 0x7;
	xmc[36]  = (*c++ & 0x1) << 2;
	xmc[36] |= (*c >> 6) & 0x3;
	xmc[37]  = (*c >> 3) & 0x7;
	xmc[38]  = *c++ & 0x7;

	Nc[3]  = (*c >> 1) & 0x7F;

	bc[3]  = (*c++ & 0x1) << 1;
	bc[3] |= (*c >> 7) & 0x1;

	Mc[3]  = (*c >> 5) & 0x3;

	xmaxc[3]  = (*c++ & 0x1F) << 1;
	xmaxc[3] |= (*c >> 7) & 0x1;

#undef	xmc
#define	xmc	(target + 63 - 39)

	xmc[39]  = (*c >> 4) & 0x7;
	xmc[40]  = (*c >> 1) & 0x7;
	xmc[41]  = (*c++ & 0x1) << 2;
	xmc[41] |= (*c >> 6) & 0x3;
	xmc[42]  = (*c >> 3) & 0x7;
	xmc[43]  = *c++ & 0x7;			/* 30  */
	xmc[44]  = (*c >> 5) & 0x7;
	xmc[45]  = (*c >> 2) & 0x7;
	xmc[46]  = (*c++ & 0x3) << 1;
	xmc[46] |= (*c >> 7) & 0x1;
	xmc[47]  = (*c >> 4) & 0x7;
	xmc[48]  = (*c >> 1) & 0x7;
	xmc[49]  = (*c++ & 0x1) << 2;
	xmc[49] |= (*c >> 6) & 0x3;
	xmc[50]  = (*c >> 3) & 0x7;
	xmc[51]  = *c & 0x7;			/* 33 */
	}

	return 0;
}
