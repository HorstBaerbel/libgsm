/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "LICENSE" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

/* $Header: /tmp_amd/presto/export/kbs/jutta/src/gsm/RCS/gsm_implode.c,v 1.2 1996/07/02 14:32:43 jutta Exp jutta $ */

#include "private.h"

#include "gsm.h"
#include "proto.h"

void gsm_implode P3((s, source, c), gsm s, gsm_signal * source, gsm_byte * c)
{
	/*	variable	size	index

		GSM_MAGIC	4	-

		LARc[0]		6	0
		LARc[1]		6	1
		LARc[2]		5	2
		LARc[3]		5	3
		LARc[4]		4	4
		LARc[5]		4	5
		LARc[6]		3	6
		LARc[7]		3	7

		Nc[0]		7	8
		bc[0]		2	9
		Mc[0]		2	10
		xmaxc[0]	6	11
		xmc[0]		3	12
		xmc[1]		3	13
		xmc[2]		3	14
		xmc[3]		3	15
		xmc[4]		3	16
		xmc[5]		3	17
		xmc[6]		3	18
		xmc[7]		3	19
		xmc[8]		3	20
		xmc[9]		3	21
		xmc[10]		3	22
		xmc[11]		3	23
		xmc[12]		3	24

		Nc[1]		7	25
		bc[1]		2	26
		Mc[1]		2	27
		xmaxc[1]	6	28
		xmc[13]		3	29
		xmc[14]		3	30
		xmc[15]		3	31
		xmc[16]		3	32
		xmc[17]		3	33
		xmc[18]		3	34
		xmc[19]		3	35
		xmc[20]		3	36
		xmc[21]		3	37
		xmc[22]		3	38
		xmc[23]		3	39
		xmc[24]		3	40
		xmc[25]		3	41

		Nc[2]		7	42
		bc[2]		2	43
		Mc[2]		2	44
		xmaxc[2]	6	45
		xmc[26]		3	46
		xmc[27]		3	47
		xmc[28]		3	48
		xmc[29]		3	49
		xmc[30]		3	50
		xmc[31]		3	51
		xmc[32]		3	52
		xmc[33]		3	53
		xmc[34]		3	54
		xmc[35]		3	55
		xmc[36]		3	56
		xmc[37]		3	57
		xmc[38]		3	58

		Nc[3]		7	59
		bc[3]		2	60
		Mc[3]		2	61
		xmaxc[3]	6	62
		xmc[39]		3	63
		xmc[40]		3	64
		xmc[41]		3	65
		xmc[42]		3	66
		xmc[43]		3	67
		xmc[44]		3	68
		xmc[45]		3	69
		xmc[46]		3	70
		xmc[47]		3	71
		xmc[48]		3	72
		xmc[49]		3	73
		xmc[50]		3	74
		xmc[51]		3	75
	*/

	/*	There are 76 parameters per frame.  The first eight are
	 * 	unique.  The remaining 68 are four identical subframes of
	 * 	17 parameters each.  gsm_implode converts from a representation
	 * 	of these parameters as values in one array of signed words
	 * 	to the "packed" version of a GSM frame.
	 */

#	define	LARc	source
#	define	Nc	*((gsm_signal (*) [17])(source + 8))
#	define	bc	*((gsm_signal (*) [17])(source + 9))
#	define	Mc	*((gsm_signal (*) [17])(source + 10))
#	define	xmaxc	*((gsm_signal (*) [17])(source + 11))

#ifdef WAV49
	if (s->wav_fmt) {

		uword sr = 0;
		if (s->frame_index) {
			sr = sr >> 6 | LARc[0] << 10;
			sr = sr >> 6 | LARc[1] << 10;
			*c++ = sr >> 4;
			sr = sr >> 5 | LARc[2] << 11;
			*c++ = sr >> 7;
			sr = sr >> 5 | LARc[3] << 11;
			sr = sr >> 4 | LARc[4] << 12;
			*c++ = sr >> 6;
			sr = sr >> 4 | LARc[5] << 12;
			sr = sr >> 3 | LARc[6] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | LARc[7] << 13;
			sr = sr >> 7 | Nc[0] << 9;
			*c++ = sr >> 5;
			sr = sr >> 2 | bc[0] << 14;
			sr = sr >> 2 | Mc[0] << 14;
			sr = sr >> 6 | xmaxc[0] << 10;
			*c++ = sr >> 3;
#undef xmc
#define	xmc	(source + 12)

			sr = sr >> 3 | xmc[0] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[1] << 13;
			sr = sr >> 3 | xmc[2] << 13;
			sr = sr >> 3 | xmc[3] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[4] << 13;
			sr = sr >> 3 | xmc[5] << 13;
			sr = sr >> 3 | xmc[6] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[7] << 13;
			sr = sr >> 3 | xmc[8] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[9] << 13;
			sr = sr >> 3 | xmc[10] << 13;
			sr = sr >> 3 | xmc[11] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[12] << 13;
			sr = sr >> 7 | Nc[1] << 9;
			*c++ = sr >> 5;
			sr = sr >> 2 | bc[1] << 14;
			sr = sr >> 2 | Mc[1] << 14;
			sr = sr >> 6 | xmaxc[1] << 10;
			*c++ = sr >> 3;
#undef	xmc
#define	xmc	(source + 29 - 13)

			sr = sr >> 3 | xmc[13] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[14] << 13;
			sr = sr >> 3 | xmc[15] << 13;
			sr = sr >> 3 | xmc[16] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[17] << 13;
			sr = sr >> 3 | xmc[18] << 13;
			sr = sr >> 3 | xmc[19] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[20] << 13;
			sr = sr >> 3 | xmc[21] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[22] << 13;
			sr = sr >> 3 | xmc[23] << 13;
			sr = sr >> 3 | xmc[24] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[25] << 13;
			sr = sr >> 7 | Nc[2] << 9;
			*c++ = sr >> 5;
			sr = sr >> 2 | bc[2] << 14;
			sr = sr >> 2 | Mc[2] << 14;
			sr = sr >> 6 | xmaxc[2] << 10;
			*c++ = sr >> 3;
#undef	xmc
#define	xmc	(source + 46 - 26)

			sr = sr >> 3 | xmc[26] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[27] << 13;
			sr = sr >> 3 | xmc[28] << 13;
			sr = sr >> 3 | xmc[29] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[30] << 13;
			sr = sr >> 3 | xmc[31] << 13;
			sr = sr >> 3 | xmc[32] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[33] << 13;
			sr = sr >> 3 | xmc[34] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[35] << 13;
			sr = sr >> 3 | xmc[36] << 13;
			sr = sr >> 3 | xmc[37] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[38] << 13;
			sr = sr >> 7 | Nc[3] << 9;
			*c++ = sr >> 5;
			sr = sr >> 2 | bc[3] << 14;
			sr = sr >> 2 | Mc[3] << 14;
			sr = sr >> 6 | xmaxc[3] << 10;
			*c++ = sr >> 3;
#undef	xmc
#define	xmc	(source + 63 - 39)

			sr = sr >> 3 | xmc[39] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[40] << 13;
			sr = sr >> 3 | xmc[41] << 13;
			sr = sr >> 3 | xmc[42] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[43] << 13;
			sr = sr >> 3 | xmc[44] << 13;
			sr = sr >> 3 | xmc[45] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[46] << 13;
			sr = sr >> 3 | xmc[47] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[48] << 13;
			sr = sr >> 3 | xmc[49] << 13;
			sr = sr >> 3 | xmc[50] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[51] << 13;
			sr = sr >> 4;
			*c = sr >> 8;
			s->frame_chain = *c;
		}
		else {
			sr = sr >> 4 | s->frame_chain << 12;
			sr = sr >> 6 | LARc[0] << 10;
			*c++ = sr >> 6;
			sr = sr >> 6 | LARc[1] << 10;
			*c++ = sr >> 8;
			sr = sr >> 5 | LARc[2] << 11;
			sr = sr >> 5 | LARc[3] << 11;
			*c++ = sr >> 6;
			sr = sr >> 4 | LARc[4] << 12;
			sr = sr >> 4 | LARc[5] << 12;
			*c++ = sr >> 6;
			sr = sr >> 3 | LARc[6] << 13;
			sr = sr >> 3 | LARc[7] << 13;
			*c++ = sr >> 8;
			sr = sr >> 7 | Nc[0] << 9;
			sr = sr >> 2 | bc[0] << 14;
			*c++ = sr >> 7;
			sr = sr >> 2 | Mc[0] << 14;
			sr = sr >> 6 | xmaxc[0] << 10;
			*c++ = sr >> 7;
#undef xmc
#define	xmc	(source + 12)

			sr = sr >> 3 | xmc[0] << 13;
			sr = sr >> 3 | xmc[1] << 13;
			sr = sr >> 3 | xmc[2] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[3] << 13;
			sr = sr >> 3 | xmc[4] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[5] << 13;
			sr = sr >> 3 | xmc[6] << 13;
			sr = sr >> 3 | xmc[7] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[8] << 13;
			sr = sr >> 3 | xmc[9] << 13;
			sr = sr >> 3 | xmc[10] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[11] << 13;
			sr = sr >> 3 | xmc[12] << 13;
			*c++ = sr >> 8;
			sr = sr >> 7 | Nc[1] << 9;
			sr = sr >> 2 | bc[1] << 14;
			*c++ = sr >> 7;
			sr = sr >> 2 | Mc[1] << 14;
			sr = sr >> 6 | xmaxc[1] << 10;
			*c++ = sr >> 7;
#undef	xmc
#define	xmc	(source + 29 - 13)

			sr = sr >> 3 | xmc[13] << 13;
			sr = sr >> 3 | xmc[14] << 13;
			sr = sr >> 3 | xmc[15] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[16] << 13;
			sr = sr >> 3 | xmc[17] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[18] << 13;
			sr = sr >> 3 | xmc[19] << 13;
			sr = sr >> 3 | xmc[20] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[21] << 13;
			sr = sr >> 3 | xmc[22] << 13;
			sr = sr >> 3 | xmc[23] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[24] << 13;
			sr = sr >> 3 | xmc[25] << 13;
			*c++ = sr >> 8;
			sr = sr >> 7 | Nc[2] << 9;
			sr = sr >> 2 | bc[2] << 14;
			*c++ = sr >> 7;
			sr = sr >> 2 | Mc[2] << 14;
			sr = sr >> 6 | xmaxc[2] << 10;
			*c++ = sr >> 7;
#undef	xmc
#define	xmc	(source + 46 - 26)

			sr = sr >> 3 | xmc[26] << 13;
			sr = sr >> 3 | xmc[27] << 13;
			sr = sr >> 3 | xmc[28] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[29] << 13;
			sr = sr >> 3 | xmc[30] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[31] << 13;
			sr = sr >> 3 | xmc[32] << 13;
			sr = sr >> 3 | xmc[33] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[34] << 13;
			sr = sr >> 3 | xmc[35] << 13;
			sr = sr >> 3 | xmc[36] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[37] << 13;
			sr = sr >> 3 | xmc[38] << 13;
			*c++ = sr >> 8;
			sr = sr >> 7 | Nc[3] << 9;
			sr = sr >> 2 | bc[3] << 14;
			*c++ = sr >> 7;
			sr = sr >> 2 | Mc[3] << 14;
			sr = sr >> 6 | xmaxc[3] << 10;
			*c++ = sr >> 7;
#undef	xmc
#define	xmc	(source + 63 - 39)

			sr = sr >> 3 | xmc[39] << 13;
			sr = sr >> 3 | xmc[40] << 13;
			sr = sr >> 3 | xmc[41] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[42] << 13;
			sr = sr >> 3 | xmc[43] << 13;
			*c++ = sr >> 8;
			sr = sr >> 3 | xmc[44] << 13;
			sr = sr >> 3 | xmc[45] << 13;
			sr = sr >> 3 | xmc[46] << 13;
			*c++ = sr >> 7;
			sr = sr >> 3 | xmc[47] << 13;
			sr = sr >> 3 | xmc[48] << 13;
			sr = sr >> 3 | xmc[49] << 13;
			*c++ = sr >> 6;
			sr = sr >> 3 | xmc[50] << 13;
			sr = sr >> 3 | xmc[51] << 13;
			*c++ = sr >> 8;
		}
	}
	else
#endif
	{

		*c++ =   ((GSM_MAGIC & 0xF) << 4)		/* 1 */
		       | ((LARc[0] >> 2) & 0xF);
		*c++ =   ((LARc[0] & 0x3) << 6)
		       | (LARc[1] & 0x3F);
		*c++ =   ((LARc[2] & 0x1F) << 3)
		       | ((LARc[3] >> 2) & 0x7);
		*c++ =   ((LARc[3] & 0x3) << 6)
		       | ((LARc[4] & 0xF) << 2)
		       | ((LARc[5] >> 2) & 0x3);
		*c++ =   ((LARc[5] & 0x3) << 6)
		       | ((LARc[6] & 0x7) << 3)
		       | (LARc[7] & 0x7);


		*c++ =   ((Nc[0] & 0x7F) << 1)


		       | ((bc[0] >> 1) & 0x1);
		*c++ =   ((bc[0] & 0x1) << 7)


		       | ((Mc[0] & 0x3) << 5)

		       | ((xmaxc[0] >> 1) & 0x1F);
		*c++ =   ((xmaxc[0] & 0x1) << 7)

#undef xmc
#define	xmc	(source + 12)

		       | ((xmc[0] & 0x7) << 4)
		       | ((xmc[1] & 0x7) << 1)
		       | ((xmc[2] >> 2) & 0x1);
		*c++ =   ((xmc[2] & 0x3) << 6)
		       | ((xmc[3] & 0x7) << 3)
		       | (xmc[4] & 0x7);
		*c++ =   ((xmc[5] & 0x7) << 5)			/* 10 */
		       | ((xmc[6] & 0x7) << 2)
		       | ((xmc[7] >> 1) & 0x3);
		*c++ =   ((xmc[7] & 0x1) << 7)
		       | ((xmc[8] & 0x7) << 4)
		       | ((xmc[9] & 0x7) << 1)
		       | ((xmc[10] >> 2) & 0x1);
		*c++ =   ((xmc[10] & 0x3) << 6)
		       | ((xmc[11] & 0x7) << 3)
		       | (xmc[12] & 0x7);


		*c++ =   ((Nc[1] & 0x7F) << 1)


		       | ((bc[1] >> 1) & 0x1);
		*c++ =   ((bc[1] & 0x1) << 7)


		       | ((Mc[1] & 0x3) << 5)


		       | ((xmaxc[1] >> 1) & 0x1F);
		*c++ =   ((xmaxc[1] & 0x1) << 7)

#undef	xmc
#define	xmc	(source + 29 - 13)

		       | ((xmc[13] & 0x7) << 4)
		       | ((xmc[14] & 0x7) << 1)
		       | ((xmc[15] >> 2) & 0x1);
		*c++ =   ((xmc[15] & 0x3) << 6)
		       | ((xmc[16] & 0x7) << 3)
		       | (xmc[17] & 0x7);
		*c++ =   ((xmc[18] & 0x7) << 5)
		       | ((xmc[19] & 0x7) << 2)
		       | ((xmc[20] >> 1) & 0x3);
		*c++ =   ((xmc[20] & 0x1) << 7)
		       | ((xmc[21] & 0x7) << 4)
		       | ((xmc[22] & 0x7) << 1)
		       | ((xmc[23] >> 2) & 0x1);
		*c++ =   ((xmc[23] & 0x3) << 6)
		       | ((xmc[24] & 0x7) << 3)
		       | (xmc[25] & 0x7);


		*c++ =   ((Nc[2] & 0x7F) << 1)			/* 20 */


		       | ((bc[2] >> 1) & 0x1);
		*c++ =   ((bc[2] & 0x1) << 7)


		       | ((Mc[2] & 0x3) << 5)


		       | ((xmaxc[2] >> 1) & 0x1F);
		*c++ =   ((xmaxc[2] & 0x1) << 7)

#undef	xmc
#define	xmc	(source + 46 - 26)

		       | ((xmc[26] & 0x7) << 4)
		       | ((xmc[27] & 0x7) << 1)
		       | ((xmc[28] >> 2) & 0x1);
		*c++ =   ((xmc[28] & 0x3) << 6)
		       | ((xmc[29] & 0x7) << 3)
		       | (xmc[30] & 0x7);
		*c++ =   ((xmc[31] & 0x7) << 5)
		       | ((xmc[32] & 0x7) << 2)
		       | ((xmc[33] >> 1) & 0x3);
		*c++ =   ((xmc[33] & 0x1) << 7)
		       | ((xmc[34] & 0x7) << 4)
		       | ((xmc[35] & 0x7) << 1)
		       | ((xmc[36] >> 2) & 0x1);
		*c++ =   ((xmc[36] & 0x3) << 6)
		       | ((xmc[37] & 0x7) << 3)
		       | (xmc[38] & 0x7);


		*c++ =   ((Nc[3] & 0x7F) << 1)


		       | ((bc[3] >> 1) & 0x1);
		*c++ =   ((bc[3] & 0x1) << 7)


		       | ((Mc[3] & 0x3) << 5)


		       | ((xmaxc[3] >> 1) & 0x1F);
		*c++ =   ((xmaxc[3] & 0x1) << 7)

#undef	xmc
#define	xmc	(source + 63 - 39)

		       | ((xmc[39] & 0x7) << 4)
		       | ((xmc[40] & 0x7) << 1)
		       | ((xmc[41] >> 2) & 0x1);
		*c++ =   ((xmc[41] & 0x3) << 6)			/* 30 */
		       | ((xmc[42] & 0x7) << 3)
		       | (xmc[43] & 0x7);
		*c++ =   ((xmc[44] & 0x7) << 5)
		       | ((xmc[45] & 0x7) << 2)
		       | ((xmc[46] >> 1) & 0x3);
		*c++ =   ((xmc[46] & 0x1) << 7)
		       | ((xmc[47] & 0x7) << 4)
		       | ((xmc[48] & 0x7) << 1)
		       | ((xmc[49] >> 2) & 0x1);
		*c++ =   ((xmc[49] & 0x3) << 6)
		       | ((xmc[50] & 0x7) << 3)
		       | (xmc[51] & 0x7);
	}
}
