/* Include files */

#include "Simulation_cgxe.h"
#include "m_i6JIq3KucPRF5QrGOFwzjB.h"
#include "m_JocDF8MFckqn84Vxx8ZZiG.h"
#include "m_SZ5YeaR6Ox52FcXntkQ9jD.h"
#include "m_lngpTpB04y9Plw6SQnFI6B.h"
#include "m_gMjjfv0nELkY1xQ5qDwKMC.h"
#include "m_9drqcfEqOaEijwL939rhKE.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 153446712 &&
      ssGetChecksum1(S) == 3579856289 &&
      ssGetChecksum2(S) == 3336506709 &&
      ssGetChecksum3(S) == 3489570508) {
    method_dispatcher_i6JIq3KucPRF5QrGOFwzjB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 444235368 &&
      ssGetChecksum1(S) == 2292809002 &&
      ssGetChecksum2(S) == 3522993967 &&
      ssGetChecksum3(S) == 2240094667) {
    method_dispatcher_JocDF8MFckqn84Vxx8ZZiG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1166200749 &&
      ssGetChecksum1(S) == 2489865969 &&
      ssGetChecksum2(S) == 161800365 &&
      ssGetChecksum3(S) == 3682709053) {
    method_dispatcher_SZ5YeaR6Ox52FcXntkQ9jD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1564209120 &&
      ssGetChecksum1(S) == 1995302686 &&
      ssGetChecksum2(S) == 3931225181 &&
      ssGetChecksum3(S) == 4275661259) {
    method_dispatcher_lngpTpB04y9Plw6SQnFI6B(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1585062389 &&
      ssGetChecksum1(S) == 1070096283 &&
      ssGetChecksum2(S) == 2478312728 &&
      ssGetChecksum3(S) == 2363510964) {
    method_dispatcher_gMjjfv0nELkY1xQ5qDwKMC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2802779187 &&
      ssGetChecksum1(S) == 33447400 &&
      ssGetChecksum2(S) == 2331305112 &&
      ssGetChecksum3(S) == 1912541166) {
    method_dispatcher_9drqcfEqOaEijwL939rhKE(S, method, data);
    return 1;
  }

  return 0;
}
