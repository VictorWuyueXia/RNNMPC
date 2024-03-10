/* Include files */

#include "Simulation_cgxe.h"
#include "m_iRDyICeARGqVtGaVvyR5DG.h"
#include "m_hhjOAcCiMOouv2JBLmYnZH.h"
#include "m_NUBgjayZLqXOjTmGtl1zEC.h"
#include "m_zbbMdT6RMHAC8gghYamee.h"
#include "m_QpFu3jCjVJqq7A8fJE64zD.h"
#include "m_NJwZumm142EyGGbQeHQz5F.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 363952376 &&
      ssGetChecksum1(S) == 4107615566 &&
      ssGetChecksum2(S) == 3606055511 &&
      ssGetChecksum3(S) == 2374442734) {
    method_dispatcher_iRDyICeARGqVtGaVvyR5DG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 449564261 &&
      ssGetChecksum1(S) == 2043254563 &&
      ssGetChecksum2(S) == 172018135 &&
      ssGetChecksum3(S) == 1740835981) {
    method_dispatcher_hhjOAcCiMOouv2JBLmYnZH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1329887158 &&
      ssGetChecksum1(S) == 2730927159 &&
      ssGetChecksum2(S) == 4167919461 &&
      ssGetChecksum3(S) == 1755321032) {
    method_dispatcher_NUBgjayZLqXOjTmGtl1zEC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1969157303 &&
      ssGetChecksum1(S) == 2536198979 &&
      ssGetChecksum2(S) == 3080293417 &&
      ssGetChecksum3(S) == 1643249593) {
    method_dispatcher_zbbMdT6RMHAC8gghYamee(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3339446835 &&
      ssGetChecksum1(S) == 761399504 &&
      ssGetChecksum2(S) == 1250729919 &&
      ssGetChecksum3(S) == 3856429204) {
    method_dispatcher_QpFu3jCjVJqq7A8fJE64zD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3716881924 &&
      ssGetChecksum1(S) == 1387891587 &&
      ssGetChecksum2(S) == 1460350350 &&
      ssGetChecksum3(S) == 1593947996) {
    method_dispatcher_NJwZumm142EyGGbQeHQz5F(S, method, data);
    return 1;
  }

  return 0;
}
