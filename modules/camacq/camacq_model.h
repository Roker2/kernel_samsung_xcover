  /*
 *
 * model option for each sensor table
 *
. COPYRIGHT (C)  SAMSUNG Electronics CO., LTD (Suwon, Korea). 2010   
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,

 *  but WITHOUT ANY WARRANTY; without even the implied warranty of

 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

 *  GNU General Public License for more details.

 *

 *  You should have received a copy of the GNU General Public License

 *  along with this program; if not, write to the Free Software

 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 *

 */

#if !defined(_CAMACQ_MODEL_H_)
#define _CAMACQ_MODEL_H_

/* Define Model */
#if defined(_MAKE_MODEL_JETTA_)
#define CAMACQ_MODEL_JETTA
#elif defined(_MAKE_MODEL_ALKON_)
#define CAMACQ_MODEL_ALKON
#elif defined(_MAKE_MODEL_GFORCE_)
#define CAMACQ_MODEL_GFORCE
#else
#define CAMACQ_MODEL_GFORCE
#endif

#endif /* _CAMACQ_MODEL_H_ */
