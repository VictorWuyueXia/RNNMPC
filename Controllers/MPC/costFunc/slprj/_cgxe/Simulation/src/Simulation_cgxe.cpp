/* Include files */

#include "Simulation_cgxe.hpp"
#include "m_ZRrpjjOELWkOuMsKQEyWoF.hpp"
#include "m_mZFHXjKJf39PvHko4ZIKxC.hpp"
#include "m_56gefFAY8sWtm2RGYfNlU.hpp"
#include "m_WFiyNWZ93pktdiGZeY69YB.hpp"
#include "m_pjFZoYX16idRmw1zvTmDE.hpp"
#include "m_RoES6REdnpdpdiUOCbCqeE.hpp"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 1121014787 &&
      ssGetChecksum1(S) == 1391846244 &&
      ssGetChecksum2(S) == 820181253 &&
      ssGetChecksum3(S) == 3455596994) {
    method_dispatcher_ZRrpjjOELWkOuMsKQEyWoF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2209566692 &&
      ssGetChecksum1(S) == 875839503 &&
      ssGetChecksum2(S) == 1047498558 &&
      ssGetChecksum3(S) == 1771902077) {
    method_dispatcher_mZFHXjKJf39PvHko4ZIKxC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2766517331 &&
      ssGetChecksum1(S) == 3970157338 &&
      ssGetChecksum2(S) == 1077290368 &&
      ssGetChecksum3(S) == 1336294495) {
    method_dispatcher_56gefFAY8sWtm2RGYfNlU(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3090108058 &&
      ssGetChecksum1(S) == 3172431932 &&
      ssGetChecksum2(S) == 2406867171 &&
      ssGetChecksum3(S) == 51515358) {
    method_dispatcher_WFiyNWZ93pktdiGZeY69YB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3955171895 &&
      ssGetChecksum1(S) == 661154611 &&
      ssGetChecksum2(S) == 140638312 &&
      ssGetChecksum3(S) == 414028511) {
    method_dispatcher_pjFZoYX16idRmw1zvTmDE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3976561189 &&
      ssGetChecksum1(S) == 3017949172 &&
      ssGetChecksum2(S) == 1188770181 &&
      ssGetChecksum3(S) == 1582093972) {
    method_dispatcher_RoES6REdnpdpdiUOCbCqeE(S, method, data);
    return 1;
  }

  return 0;
}
