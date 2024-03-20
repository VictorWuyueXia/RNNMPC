/* Include files */

#include "Simulation_cgxe.hpp"
#include "m_Upvy4szZAPtpcjDZjpnXHG.hpp"
#include "m_GTLVVhNzC1IjeeuqMqDtmB.hpp"
#include "m_oLcQlL2YuVA2Vz8xEYMrtE.hpp"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 347397719 &&
      ssGetChecksum1(S) == 2229074236 &&
      ssGetChecksum2(S) == 1086730579 &&
      ssGetChecksum3(S) == 1047467465) {
    method_dispatcher_Upvy4szZAPtpcjDZjpnXHG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1335342046 &&
      ssGetChecksum1(S) == 2360830674 &&
      ssGetChecksum2(S) == 495004353 &&
      ssGetChecksum3(S) == 3939002134) {
    method_dispatcher_GTLVVhNzC1IjeeuqMqDtmB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2974273141 &&
      ssGetChecksum1(S) == 2484425695 &&
      ssGetChecksum2(S) == 875821460 &&
      ssGetChecksum3(S) == 1132034650) {
    method_dispatcher_oLcQlL2YuVA2Vz8xEYMrtE(S, method, data);
    return 1;
  }

  return 0;
}
