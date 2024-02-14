/* Include files */

#include "Simulation_cgxe.h"
#include "m_7FHURCaqdj8HBx85ZVuatH.h"
#include "m_Ubuc0hQMhWDyT4IHVUnH3F.h"
#include "m_dnzcGMWurWPtQDFTDYOwHC.h"
#include "m_CbZldr20LixTpws6qXiNyC.h"
#include "m_tSgvweChskFYUuuPTg6HwH.h"
#include "m_klQ7XEZS1zy3wE2vktBM0F.h"

unsigned int cgxe_Simulation_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 196577005 &&
      ssGetChecksum1(S) == 2015493399 &&
      ssGetChecksum2(S) == 935721284 &&
      ssGetChecksum3(S) == 2726891565) {
    method_dispatcher_7FHURCaqdj8HBx85ZVuatH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 436919724 &&
      ssGetChecksum1(S) == 1785888773 &&
      ssGetChecksum2(S) == 1506053526 &&
      ssGetChecksum3(S) == 1159152402) {
    method_dispatcher_Ubuc0hQMhWDyT4IHVUnH3F(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 979849666 &&
      ssGetChecksum1(S) == 2926213305 &&
      ssGetChecksum2(S) == 327434230 &&
      ssGetChecksum3(S) == 3151806556) {
    method_dispatcher_dnzcGMWurWPtQDFTDYOwHC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2033019415 &&
      ssGetChecksum1(S) == 306828270 &&
      ssGetChecksum2(S) == 2237024133 &&
      ssGetChecksum3(S) == 4118633253) {
    method_dispatcher_CbZldr20LixTpws6qXiNyC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2632041385 &&
      ssGetChecksum1(S) == 1820346401 &&
      ssGetChecksum2(S) == 3582283875 &&
      ssGetChecksum3(S) == 1146030813) {
    method_dispatcher_tSgvweChskFYUuuPTg6HwH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3216773775 &&
      ssGetChecksum1(S) == 1886668734 &&
      ssGetChecksum2(S) == 2910500283 &&
      ssGetChecksum3(S) == 635975606) {
    method_dispatcher_klQ7XEZS1zy3wE2vktBM0F(S, method, data);
    return 1;
  }

  return 0;
}
