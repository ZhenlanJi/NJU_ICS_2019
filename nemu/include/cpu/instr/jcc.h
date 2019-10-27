#ifndef __INSTR_JCC_H__
#define __INSTR_JCC_H__

#define jcc_make_instr_func(suffix) \
	make_instr_func(concat4(j, e, _, suffix)); \
	make_instr_func(concat4(j, a, _, suffix)); \
	make_instr_func(concat4(j, b, _, suffix)); \
	make_instr_func(concat4(j, g, _, suffix)); \
	make_instr_func(concat4(j, l, _, suffix)); \
	make_instr_func(concat4(j, o, _, suffix)); \
	make_instr_func(concat4(j, p, _, suffix)); \
	make_instr_func(concat4(j, s, _, suffix)); \
	make_instr_func(concat4(j, ae, _, suffix)); \
	make_instr_func(concat4(j, ge, _, suffix)); \
	make_instr_func(concat4(j, le, _, suffix)); \
	make_instr_func(concat4(j, na, _, suffix)); \
	make_instr_func(concat4(j, ne, _, suffix)); \
	make_instr_func(concat4(j, no, _, suffix)); \
	make_instr_func(concat4(j, np, _, suffix)); \
	make_instr_func(concat4(j, ns, _, suffix)); \

jcc_make_instr_func(near)
jcc_make_instr_func(short_)
make_instr_func(jecxz_short_)

#endif
