/*
 * lui_operator_unequal.cpp
 *
 *  Created on: 09-May-2021
 *  Author: Soumyadeep Dhar
 */

#include <sstream>
#include <cstring>
#include <iostream>

#include "largeint.h"
#include "li_constants.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{

#ifdef PARI

// Mark pari support not present until user initialized pari
bool LargeInt::_pariInitialized = false;

// Large integer base value 
long int * LargeInt::_gN_LIMIT_mVALUE = NULL;

// Initial stack position of top
unsigned long int LargeInt::_isptop = 0U;

// Initialize PARI library
void LargeInt::InitializePARI()
{
  if (!_pariInitialized)
  {
    _pariInitialized = true;

    // Initialize pari library
    pari_init(N_LIMIT_mVALUE, N_MAX_PRIME);

    // Large integer base value 
    _gN_LIMIT_mVALUE = stoi(N_LIMIT_mVALUE);

    // Initial stack position of top
    _isptop = avma;
  }
}

// Initialize PARI library
void LargeInt::ClosePARI()
{
  if (_pariInitialized)
  {
    pari_close();
    _pariInitialized = false;
  }
}

// Clear PARI stack
void LargeInt::ClearStackPARI()
{
  if (_pariInitialized)
  {
    // Clear stack
    gerepileall(_isptop, 0);
  }
}

// Get pari-gp direct support using PARI command
std::string LargeInt::EvaluatePARI(const std::string _command)
{
  if (_pariInitialized)
  {
    // Get GEN value for the command
    GEN _v = gp_read_str(_command.c_str());

    // Convert result to character buffer
    char *_resCharBuf = GENtostr(_v);

    // Create temporary string to free the allocated memory by pari
    std::string _result(_resCharBuf);

    // Free from heap
    free(_resCharBuf);

    // Return computed result
    return _result;
  }

  // Return as not initialized
  return "PARI not initialized ...";
}

/// Convert  GEN value to Large int
LargeInt LargeInt::convert(GEN _g)
{
  LargeInt _r(0);
  
  // Get result
  char *_resCharBuf = GENtostr(_g);

  // Convert back to Large int
  _r.assignment(_resCharBuf);

  // Free from heap
  free(_resCharBuf);

  return _r;
}

/// Convert  Large int to GEN(long *)
GEN LargeInt::convert(const LargeInt &_x)
{
  // Get Number of nodes in LargeInt
  long int _vSize = _x._nList.size();

  // From LargeInt to create GEN vecsmall list
  GEN _vpnList = vecsmalltrunc_init(_vSize + 1);

  for (auto _i = 0; _i < _vSize; _i++)
  {
    // Append successive values
    vecsmalltrunc_append(_vpnList, _x._nList[_i]);
  }

  // Convert LargeInt value list to GEN t_INT
  GEN _rp = fromdigitsu(_vpnList, _gN_LIMIT_mVALUE);

  // Update sign value
  if(!_x.positive) _rp = negi(_rp);

  // Return resultant pari object
  return _rp;
}

// Get facors of given Large integer number
std::vector<LargeInt> LargeInt::factor()
{
  // Get current stack top 
  pari_sp _sptop = avma;

  GEN _xp = convert(*this);
  GEN _fList = divisors(_xp);
  std::vector<LargeInt> _result;

  // Get factor count
  long int _lx = lg(_fList);

  // For all factors
  for (auto i = 1; i < _lx; i++)
  {
    // Store results
    _result.emplace_back(convert(gel(_fList, i)));
  }

  // Clear stack
  gerepileall(_sptop, 0);

  return _result;
}

// Get facors of given unsigned integer number
std::vector<unsigned long long int> LargeInt::factor(unsigned long long int _x)
{
  // Get current stack top 
  pari_sp _sptop = avma;

  GEN _xp = convert(_x);
  GEN _fList = divisors(_xp);
  std::vector<unsigned long long int> _result;

  // Get factor count
  long int _lx = lg(_fList);

  // For all factors
  for (auto i = 1; i < _lx; i++)
  {
    // Store result
    _result.emplace_back(itos(gel(_fList, i)));
  }

  // Clear stack
  gerepileall(_sptop, 0);

  return _result;
}
#endif

} // namespace li
} // namespace dn
} // namespace ns
