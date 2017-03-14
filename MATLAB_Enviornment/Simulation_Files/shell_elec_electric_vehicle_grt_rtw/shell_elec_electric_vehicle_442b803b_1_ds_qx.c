/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_qx.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"

int32_T shell_elec_electric_vehicle_442b803b_1_ds_qx(const NeDynamicSystem *ds,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mQX;
  out.mX[0] = 7.7889303479999975E-7;
  out.mX[1] = -0.00050954;
  out.mX[2] = -2.5477E-5;
  out.mX[3] = -2.5477E-5;
  out.mX[4] = 1.0E+6;
  out.mX[5] = -0.00050954;
  out.mX[6] = 3.0;
  out.mX[7] = 6.0;
  out.mX[8] = -1.0;
  out.mX[9] = -1.0;
  out.mX[10] = 2.0;
  out.mX[11] = -2.5477E-5;
  out.mX[12] = 0.005000000000000001;
  out.mX[13] = 0.005000000000000001;
  out.mX[14] = -2.5477E-5;
  out.mX[15] = 0.005000000000000001;
  out.mX[16] = 0.005000000000000001;
  out.mX[17] = 1.0;
  out.mX[18] = 4.0;
  out.mX[19] = -1.0;
  out.mX[20] = 4.0;
  out.mX[21] = -1.0;
  out.mX[22] = 2.0;
  out.mX[23] = -1.0;
  out.mX[24] = 3.0;
  out.mX[25] = 2.0;
  out.mX[26] = -1.0;
  out.mX[27] = 3.0;
  out.mX[28] = 3.0;
  out.mX[29] = 2.0;
  out.mX[30] = 3.0;
  out.mX[31] = 2.0;
  out.mX[32] = 3.0;
  out.mX[33] = 2.0555555555555554;
  out.mX[34] = 0.26388888888888884;
  out.mX[35] = 0.16666666666666666;
  out.mX[36] = 0.26388888888888884;
  out.mX[37] = 2.1284722222222223;
  out.mX[38] = 0.041666666666666664;
  out.mX[39] = 1.0;
  out.mX[40] = 3.0;
  out.mX[41] = 1.0;
  out.mX[42] = 0.16666666666666666;
  out.mX[43] = 0.041666666666666664;
  out.mX[44] = 3.0;
  out.mX[45] = -1.0;
  out.mX[46] = 1.0;
  out.mX[47] = 2.0;
  out.mX[48] = -1.0;
  out.mX[49] = 2.0;
  out.mX[50] = 1.0;
  out.mX[51] = 2.0;
  (void)ds;
  (void)t2;
  return 0;
}
