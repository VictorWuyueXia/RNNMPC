/* Include files */

#include "Simulation_cgxe.h"
#include "m_IGTuDum22hMqh6nRrDjsgF.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 317658419 &&
      ssGetChecksum1(S) == 2636810884 &&
      ssGetChecksum2(S) == 3491679627 &&
      ssGetChecksum3(S) == 1858911522) {
    method_dispatcher_IGTuDum22hMqh6nRrDjsgF(S, method, data);
    return 1;
  }

  return 0;
}
