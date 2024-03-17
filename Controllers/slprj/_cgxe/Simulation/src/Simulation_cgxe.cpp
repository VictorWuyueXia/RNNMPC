/* Include files */

#include "Simulation_cgxe.hpp"
#include "m_CrGs8JrTwusBUauFKyg1SG.hpp"
#include "m_CIr2DVd0pXr9666zWzZpJG.hpp"
#include "m_kFZPgNUEyAHSTGzHcsG1fB.hpp"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 1353055170 &&
      ssGetChecksum1(S) == 31009053 &&
      ssGetChecksum2(S) == 357570535 &&
      ssGetChecksum3(S) == 3242618245) {
    method_dispatcher_CrGs8JrTwusBUauFKyg1SG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2466461069 &&
      ssGetChecksum1(S) == 3474179946 &&
      ssGetChecksum2(S) == 1235715190 &&
      ssGetChecksum3(S) == 1930614827) {
    method_dispatcher_CIr2DVd0pXr9666zWzZpJG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3043561812 &&
      ssGetChecksum1(S) == 2555387476 &&
      ssGetChecksum2(S) == 3702684393 &&
      ssGetChecksum3(S) == 1914704351) {
    method_dispatcher_kFZPgNUEyAHSTGzHcsG1fB(S, method, data);
    return 1;
  }

  return 0;
}
