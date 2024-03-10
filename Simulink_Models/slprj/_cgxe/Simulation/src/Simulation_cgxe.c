/* Include files */

#include "Simulation_cgxe.h"
#include "m_EEtzHiXfiRvve9WcRzUZ0G.h"
#include "m_Gy3UxPXLizbP5xlK4utmDC.h"
#include "m_zcZA3UboXwgydm2Nw2xQGD.h"
#include "m_A3OEzCGKN1ZkDLb8v5muLB.h"
#include "m_NvR95jDAEIBMkarGcQ1raB.h"
#include "m_UsfOBx8CwYjG2xn1VVBw3G.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 157878504 &&
      ssGetChecksum1(S) == 4001787657 &&
      ssGetChecksum2(S) == 3213701742 &&
      ssGetChecksum3(S) == 1561583486) {
    method_dispatcher_EEtzHiXfiRvve9WcRzUZ0G(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 576054828 &&
      ssGetChecksum1(S) == 384235410 &&
      ssGetChecksum2(S) == 64355062 &&
      ssGetChecksum3(S) == 3798346424) {
    method_dispatcher_Gy3UxPXLizbP5xlK4utmDC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2199502089 &&
      ssGetChecksum1(S) == 1048284618 &&
      ssGetChecksum2(S) == 198960934 &&
      ssGetChecksum3(S) == 1141218566) {
    method_dispatcher_zcZA3UboXwgydm2Nw2xQGD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3115673736 &&
      ssGetChecksum1(S) == 1974039894 &&
      ssGetChecksum2(S) == 4280443194 &&
      ssGetChecksum3(S) == 1854590770) {
    method_dispatcher_A3OEzCGKN1ZkDLb8v5muLB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3312732043 &&
      ssGetChecksum1(S) == 11562350 &&
      ssGetChecksum2(S) == 2761741414 &&
      ssGetChecksum3(S) == 2336657024) {
    method_dispatcher_NvR95jDAEIBMkarGcQ1raB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3554441861 &&
      ssGetChecksum1(S) == 15995505 &&
      ssGetChecksum2(S) == 527288328 &&
      ssGetChecksum3(S) == 869250312) {
    method_dispatcher_UsfOBx8CwYjG2xn1VVBw3G(S, method, data);
    return 1;
  }

  return 0;
}
