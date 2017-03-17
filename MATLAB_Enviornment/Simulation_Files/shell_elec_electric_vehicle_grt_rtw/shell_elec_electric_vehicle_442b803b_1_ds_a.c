/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_a.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"

int32_T shell_elec_electric_vehicle_442b803b_1_ds_a(const NeDynamicSystem *ds,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mA;
  out.mX[0] = 1.2572964351350123E-6;
  out.mX[1] = 1.0;
  out.mX[2] = 1.0204081632653061;
  out.mX[3] = -1.0;
  out.mX[4] = -1.0;
  out.mX[5] = 1.1764705882352941E-8;
  out.mX[6] = -1.0;
  out.mX[7] = -1.0;
  out.mX[8] = -1.0;
  out.mX[9] = -1.0;
  out.mX[10] = -1.0;
  out.mX[11] = -1.0;
  out.mX[12] = -1.0;
  out.mX[13] = -1.0;
  out.mX[14] = 1.0;
  out.mX[15] = 0.16666666666666666;
  out.mX[16] = 0.041666666666666664;
  out.mX[17] = -1.0E-5;
  out.mX[18] = -0.041666666666666664;
  out.mX[19] = -1.0;
  out.mX[20] = 1.0;
  out.mX[21] = 0.060607284966083842;
  out.mX[22] = 1.0;
  out.mX[23] = -4.2746003248696246E-6;
  out.mX[24] = 0.0;
  out.mX[25] = 0.86880973066898093;
  out.mX[26] = -1.0204081632653061;
  out.mX[27] = 0.020408163265306121;
  out.mX[28] = 1.0;
  out.mX[29] = 1.0204081632653061;
  out.mX[30] = 1.0;
  out.mX[31] = 4.2746003248696246E-6;
  out.mX[32] = 0.03912363067293001;
  out.mX[33] = -0.0001233756363715324;
  out.mX[34] = 1.0;
  out.mX[35] = -0.0001233756363715324;
  out.mX[36] = 1.0;
  out.mX[37] = 0.99999999999999445;
  out.mX[38] = 1.0;
  out.mX[39] = 1.0;
  out.mX[40] = -1.0;
  out.mX[41] = -1.0;
  out.mX[42] = 0.001;
  out.mX[43] = -0.99999999999999445;
  out.mX[44] = 0.78539816339744839;
  out.mX[45] = 1.0;
  out.mX[46] = -0.24242913986433537;
  out.mX[47] = -1.0;
  out.mX[48] = -0.12732395447351627;
  out.mX[49] = 1.0;
  out.mX[50] = 1.0;
  out.mX[51] = 0.23916578972572047;
  out.mX[52] = 0.23916578972543764;
  out.mX[53] = 1.0;
  out.mX[54] = 0.23916578972543764;
  out.mX[55] = 1.0;
  out.mX[56] = 1.0;
  out.mX[57] = 0.23873185637891522;
  out.mX[58] = 0.239165789755621;
  out.mX[59] = 0.23916578972543764;
  out.mX[60] = 1.0;
  out.mX[61] = 1.0;
  out.mX[62] = 0.0057403831879951966;
  out.mX[63] = 0.0057403831879951966;
  out.mX[64] = 0.24242913986433537;
  out.mX[65] = -0.060607284966083842;
  out.mX[66] = 0.24242913986433537;
  out.mX[67] = -0.30303642483041915;
  out.mX[68] = 1.0;
  out.mX[69] = -1.0;
  out.mX[70] = 1.0;
  out.mX[71] = -1.0;
  out.mX[72] = 1.0;
  out.mX[73] = 1.0;
  out.mX[74] = 1.0;
  out.mX[75] = 0.23873212145434708;
  out.mX[76] = 0.23916578972573949;
  out.mX[77] = 0.23916578972543764;
  out.mX[78] = 0.23916578972573949;
  out.mX[79] = 0.23916578972543764;
  out.mX[80] = 1.0;
  out.mX[81] = 1.0;
  out.mX[82] = 1.0;
  out.mX[83] = 0.0057403831879951966;
  out.mX[84] = 1.0;
  out.mX[85] = 0.24242913986433537;
  out.mX[86] = -0.060607284966083842;
  out.mX[87] = 0.24242913986433537;
  out.mX[88] = 1.0;
  out.mX[89] = -0.99999999999999989;
  out.mX[90] = 1.0;
  out.mX[91] = 1.0;
  out.mX[92] = -1.0;
  out.mX[93] = 1.0;
  out.mX[94] = 1.0;
  out.mX[95] = 1.0;
  out.mX[96] = 0.20000000000631016;
  out.mX[97] = -0.99999999996844935;
  out.mX[98] = 0.23873212145434708;
  out.mX[99] = 0.23916578972573949;
  out.mX[100] = 0.23916578972543764;
  out.mX[101] = 1.0;
  out.mX[102] = 0.23916578972543764;
  out.mX[103] = 1.0;
  out.mX[104] = -0.30303642483041915;
  out.mX[105] = 0.99999999999999989;
  out.mX[106] = -1.0;
  out.mX[107] = -0.99999999999999989;
  out.mX[108] = 1.0;
  out.mX[109] = 1.0;
  out.mX[110] = 1.577532773568469E-10;
  out.mX[111] = 0.20000000015775329;
  out.mX[112] = -1.8864593565533387E-10;
  out.mX[113] = -0.99999999921123361;
  out.mX[114] = 0.2391657899140836;
  out.mX[115] = 0.23916578972543764;
  out.mX[116] = 1.0;
  out.mX[117] = 0.23916578972543764;
  out.mX[118] = 0.0057403831879951966;
  out.mX[119] = 0.0057403831879951966;
  out.mX[120] = 1.0;
  out.mX[121] = 1.0;
  out.mX[122] = 1.0;
  out.mX[123] = 0.23873212145434708;
  out.mX[124] = 1.0;
  out.mX[125] = 0.23916578972543764;
  out.mX[126] = 1.0;
  out.mX[127] = 0.23916578972543764;
  out.mX[128] = -1.0;
  out.mX[129] = -0.16666666666666666;
  out.mX[130] = 1.0;
  out.mX[131] = -0.041666666666666664;
  out.mX[132] = 0.001;
  out.mX[133] = 0.30303642483041915;
  out.mX[134] = 1.0;
  out.mX[135] = 1.0;
  out.mX[136] = 1.0;
  out.mX[137] = 1.0;
  out.mX[138] = 4.0E-5;
  out.mX[139] = 1.0;
  out.mX[140] = 1.0;
  out.mX[141] = 1.0;
  out.mX[142] = 9.8595798202212348E-12;
  out.mX[143] = -1.1790370969739757E-11;
  out.mX[144] = 0.23873212145434708;
  out.mX[145] = 2.0390292748104176E-7;
  out.mX[146] = 0.23916578972543764;
  out.mX[147] = 0.239165789737228;
  out.mX[148] = 0.23916578972543764;
  out.mX[149] = -1.0;
  out.mX[150] = -0.99999999999999989;
  out.mX[151] = -0.66666666666666663;
  out.mX[152] = 1.0;
  out.mX[153] = 0.99999999999999989;
  out.mX[154] = 0.0;
  out.mX[155] = 0.001;
  out.mX[156] = 1.0;
  out.mX[157] = 1.0;
  out.mX[158] = 1.0;
  out.mX[159] = 0.5;
  out.mX[160] = 1.0;
  out.mX[161] = 0.5;
  (void)ds;
  (void)t2;
  return 0;
}