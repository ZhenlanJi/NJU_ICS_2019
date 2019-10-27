#ifndef __INSTR_JCC_H__
#define __INSTR_JCC_H__

#define jcc_make_instr_func(suffix) \
	make_instr_func(j, i, suffix, e) \
	make_instr_func(j, i, suffix, a) \
	make_instr_func(j, i, suffix, b) \
	make_instr_func(j, i, suffix, g) \
	make_instr_func(j, i, suffix, l) \
	make_instr_func(j, i, suffix, o) \
	make_instr_func(j, i, suffix, p) \
	make_instr_func(j, i, suffix, s) \
	make_instr_func(j, i, suffix, ae) \
	make_instr_func(j, i, suffix, ge) \
	make_instr_func(j, i, suffix, le) \
	make_instr_func(j, i, suffix, na) \
	make_instr_func(j, i, suffix, ne) \
	make_instr_func(j, i, suffix, no) \
	make_instr_func(j, i, suffix, np) \
	make_instr_func(j, i, suffix, ns) \

jcc_make_instr_func(near)
jcc_make_instr_func(short_)

#endif
