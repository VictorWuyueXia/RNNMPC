/* Include files */

#include "Simulation_cgxe.hpp"
#include "m_CHwBOLXnlwgctx4aD8MlRC.hpp"
#include "m_NBxv4KYZ78lsloO5VhEuPC.hpp"
#include "m_VDFqt2d97Bb7AD2gbxjEdF.hpp"
#include "m_zfcAZqj041NfvOO25t4bF.hpp"
#include "m_wGJK9Q8tLpU8K2MKpgoLcE.hpp"
#include "m_T4xtkbXMrvaNp4E2Jm3CG.hpp"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 604823724 &&
      ssGetChecksum1(S) == 3089889522 &&
      ssGetChecksum2(S) == 2906963106 &&
      ssGetChecksum3(S) == 4010480478) {
    method_dispatcher_CHwBOLXnlwgctx4aD8MlRC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 856368943 &&
      ssGetChecksum1(S) == 3071827884 &&
      ssGetChecksum2(S) == 591248155 &&
      ssGetChecksum3(S) == 1153183261) {
    method_dispatcher_NBxv4KYZ78lsloO5VhEuPC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2466192047 &&
      ssGetChecksum1(S) == 724621935 &&
      ssGetChecksum2(S) == 716912166 &&
      ssGetChecksum3(S) == 3276330068) {
    method_dispatcher_VDFqt2d97Bb7AD2gbxjEdF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2808590543 &&
      ssGetChecksum1(S) == 4157233288 &&
      ssGetChecksum2(S) == 4169936699 &&
      ssGetChecksum3(S) == 540532951) {
    method_dispatcher_zfcAZqj041NfvOO25t4bF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3075984405 &&
      ssGetChecksum1(S) == 1106855454 &&
      ssGetChecksum2(S) == 751293989 &&
      ssGetChecksum3(S) == 1318542748) {
    method_dispatcher_wGJK9Q8tLpU8K2MKpgoLcE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3994219229 &&
      ssGetChecksum1(S) == 1915747125 &&
      ssGetChecksum2(S) == 931433811 &&
      ssGetChecksum3(S) == 2214534302) {
    method_dispatcher_T4xtkbXMrvaNp4E2Jm3CG(S, method, data);
    return 1;
  }

  return 0;
}
