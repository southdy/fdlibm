/* Store current representation for exceptions.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Schwab <schwab@issan.informatik.uni-dortmund.de>

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif
#include "fpu_ctrl.h"

int __fegetexceptflag(fexcept_t *flagp, int excepts)
{
	fexcept_t fpsr;

	/* Get the current exceptions.  */
	_FPU_GETSR(fpsr);

	*flagp = fpsr & excepts & FE_ALL_EXCEPT;

	/* Success.  */
	return 0;
}

__typeof(__fegetexceptflag) fegetexceptflag __attribute__((weak, alias("__fegetexceptflag")));