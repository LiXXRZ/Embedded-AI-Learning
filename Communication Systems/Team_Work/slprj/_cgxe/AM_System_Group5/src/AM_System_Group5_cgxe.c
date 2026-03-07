/* Include files */

#include "AM_System_Group5_cgxe.h"
#include "m_NxVrgrXijX0m0mdpZZqrmB.h"

unsigned int cgxe_AM_System_Group5_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 3799251684 &&
      ssGetChecksum1(S) == 2000685923 &&
      ssGetChecksum2(S) == 3635745107 &&
      ssGetChecksum3(S) == 978081198) {
    method_dispatcher_NxVrgrXijX0m0mdpZZqrmB(S, method, data);
    return 1;
  }

  return 0;
}
