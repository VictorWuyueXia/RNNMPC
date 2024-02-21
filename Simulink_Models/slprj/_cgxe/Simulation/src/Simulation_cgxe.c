/* Include files */

#include "Simulation_cgxe.h"
#include "m_MZ052aXbO4TZnBM2ZpV4mC.h"
#include "m_W2hcibOvtpwvw1S3wCpu6C.h"
#include "m_pUpcZnZhk1ZuuS3YohifKG.h"
#include "m_xGMPP5dg6NcOAWHcDYFG3E.h"
#include "m_JfY3qUib7paXLgdilcvOr.h"
#include "m_SvSMygm8xP7OgFQXmKzyxF.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 104879594 &&
      ssGetChecksum1(S) == 3833300259 &&
      ssGetChecksum2(S) == 4229585988 &&
      ssGetChecksum3(S) == 1211985281) {
    method_dispatcher_MZ052aXbO4TZnBM2ZpV4mC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 427064520 &&
      ssGetChecksum1(S) == 303696802 &&
      ssGetChecksum2(S) == 3178787481 &&
      ssGetChecksum3(S) == 2624036092) {
    method_dispatcher_W2hcibOvtpwvw1S3wCpu6C(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1261712584 &&
      ssGetChecksum1(S) == 605983007 &&
      ssGetChecksum2(S) == 520643782 &&
      ssGetChecksum3(S) == 758256508) {
    method_dispatcher_pUpcZnZhk1ZuuS3YohifKG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2337988574 &&
      ssGetChecksum1(S) == 1462109421 &&
      ssGetChecksum2(S) == 2341626354 &&
      ssGetChecksum3(S) == 1946879561) {
    method_dispatcher_xGMPP5dg6NcOAWHcDYFG3E(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2721415071 &&
      ssGetChecksum1(S) == 3258777778 &&
      ssGetChecksum2(S) == 3392792636 &&
      ssGetChecksum3(S) == 3068205031) {
    method_dispatcher_JfY3qUib7paXLgdilcvOr(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2867611393 &&
      ssGetChecksum1(S) == 2692440233 &&
      ssGetChecksum2(S) == 3079015999 &&
      ssGetChecksum3(S) == 3288895526) {
    method_dispatcher_SvSMygm8xP7OgFQXmKzyxF(S, method, data);
    return 1;
  }

  return 0;
}
