/*
 * li_constants.h
 *
 *  Created on: 23-Apr-2021
 *  Author: soumyadeep dhar
 */

#ifndef LI_CONSTANTS_H_
#define LI_CONSTANTS_H_

#ifdef PARI
# include <pari.h>
#endif
#include <math.h>

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{

constexpr unsigned int N_LIMIT_mVALUE = 1000000000U;
constexpr unsigned int N_LIMIT_mDIGIT = 9U;

} // namespace li
} // namespace dn
} // namespace ns

#endif // LI_CONSTANTS_H_