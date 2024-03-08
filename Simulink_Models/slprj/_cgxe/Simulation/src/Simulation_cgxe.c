/* Include files */

#include "Simulation_cgxe.h"
#include "m_SB9zHJYh0KMHD57S1kbsM.h"
#include "m_Tuycm3s88pcXArSxTYlM2C.h"
#include "m_GQSILvSPCTzISyZ7NYwLIF.h"
#include "m_KqMOmJaMosVk1PSEjFkU4E.h"
#include "m_pwNSslKdKNeB60Ahlj0yKH.h"
#include "m_F0jeqmD47IABR1DbZqFEwB.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 1065006368 &&
      ssGetChecksum1(S) == 1217208527 &&
      ssGetChecksum2(S) == 1096120938 &&
      ssGetChecksum3(S) == 811435461) {
    method_dispatcher_SB9zHJYh0KMHD57S1kbsM(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2738713870 &&
      ssGetChecksum1(S) == 1342834526 &&
      ssGetChecksum2(S) == 1730324275 &&
      ssGetChecksum3(S) == 3910327326) {
    method_dispatcher_Tuycm3s88pcXArSxTYlM2C(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2887874293 &&
      ssGetChecksum1(S) == 3458408461 &&
      ssGetChecksum2(S) == 4269444112 &&
      ssGetChecksum3(S) == 1373635269) {
    method_dispatcher_GQSILvSPCTzISyZ7NYwLIF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3175323601 &&
      ssGetChecksum1(S) == 749882744 &&
      ssGetChecksum2(S) == 645409672 &&
      ssGetChecksum3(S) == 850471966) {
    method_dispatcher_KqMOmJaMosVk1PSEjFkU4E(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3632150448 &&
      ssGetChecksum1(S) == 933365598 &&
      ssGetChecksum2(S) == 578439164 &&
      ssGetChecksum3(S) == 1077159606) {
    method_dispatcher_pwNSslKdKNeB60Ahlj0yKH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3894687809 &&
      ssGetChecksum1(S) == 429432161 &&
      ssGetChecksum2(S) == 675749810 &&
      ssGetChecksum3(S) == 2571590031) {
    method_dispatcher_F0jeqmD47IABR1DbZqFEwB(S, method, data);
    return 1;
  }

  return 0;
}
