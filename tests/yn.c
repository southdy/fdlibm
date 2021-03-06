#include "testconfig.h"
#define TEST_FUNC_IF_F __MATH_PRECNAME(yn)
#include "testdriver.h"



static test_if_f_data const yn_data[] = {
	{ __LINE__, 0, QNAN_P, QNAN_P, 0 },
	{ __LINE__, 0, QNAN_M, QNAN_P, 0 },
	{ __LINE__, 0, SNAN_P, QNAN_P, 0 },
	{ __LINE__, 0, SNAN_M, QNAN_P, 0 },
	{ __LINE__, 0, INF_P, ZERO_P, 0 },
	{ __LINE__, 0, INF_M, QNAN_P, 0 },
	{ __LINE__, 0, ZERO_P, INF_M, 0 },
	{ __LINE__, 0, ZERO_M, INF_M, 0 },
	{ __LINE__, 0, SUBNORM_P, ZERO_P, FLAG_SUBNORM },
	{ __LINE__, 0, SUBNORM_M, ZERO_M, FLAG_SUBNORM },
	{ __LINE__, 0, MIN_P, ZERO_P, 0 },
	{ __LINE__, 0, MIN_M, ZERO_M, 0 },
	{ __LINE__, 0, MAX_P, MAX_P, 0 },
	{ __LINE__, 0, MAX_M, INF_M, INVALID_EXCEPTION|ERRNO_EDOM },

	/* yn (0, x) == y0 (x)	*/
#if 0 /* TODO: could be either inf or nan */
	{ __LINE__, 0, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), QNAN_P, INVALID_EXCEPTION|ERRNO_EDOM },
#endif

	{ __LINE__, 0, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(-1.38968062514384052915582277745018693L, 0xbfff, 0xb1e10e02L, 0x70563121L), FLAG_INEXACT },
	{ __LINE__, 0, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(-0.137172769385772397522814379396581855L, 0xbffc, 0x8c7704b9L, 0xa791e343L), FLAG_INEXACT },
	{ __LINE__, 0, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.0882569642156769579829267660235151628L, 0x3ffb, 0xb4c01137L, 0x9ac6f94fL), FLAG_INEXACT },
	{ __LINE__, 0, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(0.382448923797758843955068554978089862L, 0x3ffd, 0xc3d05868L, 0x341b3e63L), FLAG_INEXACT },
	{ __LINE__, 0, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(0.510375672649745119596606592727157873L, 0x3ffe, 0x82a7fae6L, 0xb46465e1L), FLAG_INEXACT },
	{ __LINE__, 0, HEXCONSTE(8.0, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(0.223521489387566220527323400498620359L, 0x3ffc, 0xe4e2d13bL, 0x7dc16072L), FLAG_INEXACT4 },
	{ __LINE__, 0, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(0.0556711672835993914244598774101900481L, 0x3ffa, 0xe407732dL, 0x02e2c469L), FLAG_INEXACT4 },

	/* yn (1, x) == y1 (x)	*/
#if 0 /* TODO: could be either inf or nan */
	{ __LINE__, 1, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), INF_M, INVALID_EXCEPTION|ERRNO_EDOM },
#endif
	{ __LINE__, 1, ZERO_P, INF_M, 0 },
	{ __LINE__, 1, INF_P, ZERO_P, 0 },
	{ __LINE__, 1, INF_M, QNAN_P, 0 },
	{ __LINE__, 1, QNAN_P, QNAN_P, 0 },

	{ __LINE__, 1, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(-5.19993611253477499595928744876579921L, 0xc001, 0xa665e06bL, 0x140a1c74L), FLAG_INEXACT },
	{ __LINE__, 1, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(-1.03759455076928541973767132140642198L, 0xbfff, 0x84cfe5f3L, 0x07ec1815L), FLAG_INEXACT },
	{ __LINE__, 1, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(-0.781212821300288716547150000047964821L, 0xbffe, 0xc7fd903eL, 0xb35ca24fL), FLAG_INEXACT },
	{ __LINE__, 1, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(-0.412308626973911295952829820633445323L, 0xbffd, 0xd31a1dc9L, 0x6c5877f2L), FLAG_INEXACT },
	{ __LINE__, 1, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(-0.107032431540937546888370772277476637L, 0xbffb, 0xdb33d1c8L, 0xa3323ac6L), FLAG_INEXACT },
	{ __LINE__, 1, HEXCONSTE(8.0, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(-0.158060461731247494255555266187483550L, 0xbffc, 0xa1da9a07L, 0xb499b086L), FLAG_INEXACT4 },
	{ __LINE__, 1, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(0.249015424206953883923283474663222803L, 0x3ffc, 0xfefde63cL, 0xac79e011L), FLAG_INEXACT4 },

	/* yn (3, x)  */
	{ __LINE__, 3, INF_P, ZERO_P, 0 },
	{ __LINE__, 3, QNAN_P, QNAN_P, 0 },

	{ __LINE__, 3, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(-2612.69757350066712600220955744091741L, 0xc00a, 0xa34b2942L, 0xd4bebea1L), FLAG_INEXACT },
	{ __LINE__, 3, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(-12.9877176234475433186319774484809207L, 0xc002, 0xcfcdb0feL, 0xa63d9bf9L), FLAG_INEXACT },
	{ __LINE__, 3, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(-5.82151760596472884776175706442981440L, 0xc001, 0xba49df4aL, 0x569d7d9aL), FLAG_INEXACT },
	{ __LINE__, 3, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(-1.12778377684042778608158395773179238L, 0xbfff, 0x905b3803L, 0x3e97898eL), FLAG_INEXACT },
	{ __LINE__, 3, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(-0.251362657183837329779204747654240998L, 0xbffd, 0x80b29b30L, 0x149a70e4L), FLAG_INEXACT3 },

	/* yn (10, x)  */
	{ __LINE__, 10, INF_P, ZERO_P, 0 },
	{ __LINE__, 10, QNAN_P, QNAN_P, 0 },

	{ __LINE__, 10, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(-127057845771019398.252538486899753195L, 0xc037, 0xe1b33801L, 0x8dd24320L), FLAG_INEXACT },
	{ __LINE__, 10, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(-2133501638.90573424452445412893839236L, 0xc01d, 0xfe554d8dL, 0xcfbc661eL), FLAG_INEXACT },
	{ __LINE__, 10, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(-121618014.278689189288130426667971145L, 0xc019, 0xe7f7cbc8L, 0xeb059738L), FLAG_INEXACT },
	{ __LINE__, 10, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(-129184.542208039282635913145923304214L, 0xc00f, 0xfc504567L, 0x12b22c71L), FLAG_INEXACT },
	{ __LINE__, 10, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(-0.359814152183402722051986577343560609L, 0xbffd, 0xb8398f80L, 0x88076e0aL), FLAG_INEXACT3 },

	/* Check whether yn returns correct value for LDBL_MIN, DBL_MIN,
	   and FLT_MIN.  See Bug 14173.  */
#ifdef TEST_LDOUBLE
	{ __LINE__, 10, MIN_P, INF_M, UNDERFLOW_EXCEPTION /* |ERRNO_ERANGE */ },
#else
	{ __LINE__, 10, MIN_P, INF_M, OVERFLOW_EXCEPTION /* |ERRNO_ERANGE */ },
#endif
};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_if_f(yn_data, ARRAY_SIZE(yn_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
