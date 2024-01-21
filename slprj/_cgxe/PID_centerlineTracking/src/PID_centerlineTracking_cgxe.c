/* Include files */

#include "PID_centerlineTracking_cgxe.h"
#include "m_68CfuHLavy22dwF2MWCcD.h"

unsigned int cgxe_PID_centerlineTracking_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 2324477541 &&
      ssGetChecksum1(S) == 2867015145 &&
      ssGetChecksum2(S) == 1952298486 &&
      ssGetChecksum3(S) == 3456443613) {
    method_dispatcher_68CfuHLavy22dwF2MWCcD(S, method, data);
    return 1;
  }

  return 0;
}
