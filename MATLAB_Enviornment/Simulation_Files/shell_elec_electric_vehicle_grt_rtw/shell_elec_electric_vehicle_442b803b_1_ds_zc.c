/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_zc.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"

int32_T shell_elec_electric_vehicle_442b803b_1_ds_zc(const NeDynamicSystem *t0,
  const NeDynamicSystemInput *t8, NeDsMethodOutput *t9)
{
  PmRealVector out;
  real_T intrm_sf_mf_218;
  boolean_T t1;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T X_idx_23;
  real_T X_idx_0;
  real_T X_idx_5;
  real_T X_idx_25;
  real_T X_idx_106;
  real_T X_idx_16;
  real_T X_idx_2;
  int32_T M_idx_118;
  real_T X_idx_17;
  int32_T M_idx_121;
  real_T X_idx_62;
  real_T X_idx_27;
  real_T X_idx_33;
  real_T X_idx_37;
  real_T X_idx_54;
  real_T X_idx_7;
  real_T X_idx_70;
  real_T X_idx_72;
  real_T X_idx_9;
  real_T X_idx_87;
  real_T X_idx_11;
  real_T X_idx_15;
  real_T X_idx_32;
  real_T X_idx_36;
  real_T X_idx_39;
  real_T X_idx_40;
  real_T X_idx_47;
  real_T X_idx_48;
  real_T X_idx_53;
  real_T X_idx_6;
  real_T X_idx_56;
  real_T X_idx_58;
  real_T X_idx_69;
  real_T X_idx_71;
  real_T X_idx_8;
  real_T X_idx_74;
  real_T X_idx_76;
  real_T X_idx_86;
  real_T X_idx_89;
  real_T X_idx_90;
  real_T X_idx_10;
  real_T X_idx_97;
  real_T X_idx_99;
  real_T X_idx_13;
  real_T X_idx_111;
  real_T X_idx_113;
  real_T X_idx_14;
  int32_T M_idx_119;
  (void)t0;
  M_idx_118 = t8->mM.mX[118];
  M_idx_119 = t8->mM.mX[119];
  M_idx_121 = t8->mM.mX[121];
  X_idx_0 = t8->mX.mX[0];
  X_idx_2 = t8->mX.mX[2];
  X_idx_5 = t8->mX.mX[5];
  X_idx_6 = t8->mX.mX[6];
  X_idx_7 = t8->mX.mX[7];
  X_idx_8 = t8->mX.mX[8];
  X_idx_9 = t8->mX.mX[9];
  X_idx_10 = t8->mX.mX[10];
  X_idx_11 = t8->mX.mX[11];
  X_idx_13 = t8->mX.mX[13];
  X_idx_14 = t8->mX.mX[14];
  X_idx_15 = t8->mX.mX[15];
  X_idx_16 = t8->mX.mX[16];
  X_idx_17 = t8->mX.mX[17];
  X_idx_23 = t8->mX.mX[23];
  X_idx_25 = t8->mX.mX[25];
  X_idx_27 = t8->mX.mX[27];
  X_idx_32 = t8->mX.mX[32];
  X_idx_33 = t8->mX.mX[33];
  X_idx_36 = t8->mX.mX[36];
  X_idx_37 = t8->mX.mX[37];
  X_idx_39 = t8->mX.mX[39];
  X_idx_40 = t8->mX.mX[40];
  X_idx_47 = t8->mX.mX[47];
  X_idx_48 = t8->mX.mX[48];
  X_idx_53 = t8->mX.mX[53];
  X_idx_54 = t8->mX.mX[54];
  X_idx_56 = t8->mX.mX[56];
  X_idx_58 = t8->mX.mX[58];
  X_idx_62 = t8->mX.mX[62];
  X_idx_69 = t8->mX.mX[69];
  X_idx_70 = t8->mX.mX[70];
  X_idx_71 = t8->mX.mX[71];
  X_idx_72 = t8->mX.mX[72];
  X_idx_74 = t8->mX.mX[74];
  X_idx_76 = t8->mX.mX[76];
  X_idx_86 = t8->mX.mX[86];
  X_idx_87 = t8->mX.mX[87];
  X_idx_89 = t8->mX.mX[89];
  X_idx_90 = t8->mX.mX[90];
  X_idx_97 = t8->mX.mX[97];
  X_idx_99 = t8->mX.mX[99];
  X_idx_106 = t8->mX.mX[106];
  X_idx_111 = t8->mX.mX[111];
  X_idx_113 = t8->mX.mX[113];
  out = t9->mZC;
  t5 = X_idx_16 >= 0.0 ? X_idx_16 : -X_idx_16;
  if (t5 < 227.27272727272725) {
    intrm_sf_mf_218 = 220.0;
  } else {
    intrm_sf_mf_218 = 50.0 / (t5 == 0.0 ? 1.0E-16 : t5) * 1000.0;
  }

  if (X_idx_2 < 0.0) {
    t1 = -X_idx_23 > 0.0;
  } else {
    t1 = false;
  }

  if (!(M_idx_118 != 0)) {
    X_idx_2 = -intrm_sf_mf_218 - X_idx_17;
  } else {
    X_idx_2 = 0.0;
  }

  if (!(M_idx_118 != 0) && M_idx_121 != 0) {
    t3 = 227.27272727272725 - t5;
  } else {
    t3 = 0.0;
  }

  if (M_idx_118 != 0) {
    t4 = 227.27272727272725 - t5;
  } else {
    t4 = 0.0;
  }

  t5 = (0.1 - X_idx_106 * (X_idx_106 * 0.00026666666666666668 + 400.0) * 0.001 +
        X_idx_106 * X_idx_106 * 4.9967328298324985E-5) / (X_idx_25 == 0.0 ?
    1.0E-16 : X_idx_25) * 1000.0 - 1000.0;
  out.mX[0] = -(X_idx_62 * 100.0);
  out.mX[1] = -X_idx_27;
  out.mX[2] = 0.1 - X_idx_33;
  out.mX[3] = 0.1 - X_idx_37;
  out.mX[4] = 0.1 - X_idx_54;
  out.mX[5] = 0.1 - X_idx_7;
  out.mX[6] = 0.1 - X_idx_70;
  out.mX[7] = 0.1 - X_idx_72;
  out.mX[8] = 0.1 - X_idx_9;
  out.mX[9] = 0.1 - X_idx_87;
  out.mX[10] = 0.1 - X_idx_11;
  out.mX[11] = 0.1 - X_idx_15;
  out.mX[12] = 1.0 - X_idx_27;
  out.mX[13] = 2.5 - X_idx_62 * 100.0;
  out.mX[14] = 273.16 - X_idx_32;
  out.mX[15] = 273.16 - X_idx_36;
  out.mX[16] = 273.16 - X_idx_39;
  out.mX[17] = 273.16 - X_idx_40;
  out.mX[18] = 273.16 - X_idx_47;
  out.mX[19] = 273.16 - X_idx_48;
  out.mX[20] = 273.16 - X_idx_53;
  out.mX[21] = 273.16 - X_idx_6;
  out.mX[22] = 273.16 - X_idx_56;
  out.mX[23] = 273.16 - X_idx_58;
  out.mX[24] = 273.16 - X_idx_69;
  out.mX[25] = 273.16 - X_idx_71;
  out.mX[26] = 273.16 - X_idx_8;
  out.mX[27] = 273.16 - X_idx_74;
  out.mX[28] = 273.16 - X_idx_76;
  out.mX[29] = 273.16 - X_idx_86;
  out.mX[30] = 273.16 - X_idx_89;
  out.mX[31] = 273.16 - X_idx_90;
  out.mX[32] = 273.16 - X_idx_10;
  out.mX[33] = 273.16 - X_idx_97;
  out.mX[34] = 273.16 - X_idx_99;
  out.mX[35] = 273.16 - X_idx_13;
  out.mX[36] = 273.16 - X_idx_111;
  out.mX[37] = 273.16 - X_idx_113;
  out.mX[38] = 278.15 - X_idx_0;
  out.mX[39] = 313.15 - X_idx_0;
  out.mX[40] = 373.16 - X_idx_32;
  out.mX[41] = 373.16 - X_idx_36;
  out.mX[42] = 373.16 - X_idx_39;
  out.mX[43] = 373.16 - X_idx_40;
  out.mX[44] = 373.16 - X_idx_47;
  out.mX[45] = 373.16 - X_idx_48;
  out.mX[46] = 373.16 - X_idx_53;
  out.mX[47] = 373.16 - X_idx_6;
  out.mX[48] = 373.16 - X_idx_56;
  out.mX[49] = 373.16 - X_idx_58;
  out.mX[50] = 373.16 - X_idx_69;
  out.mX[51] = 373.16 - X_idx_71;
  out.mX[52] = 373.16 - X_idx_8;
  out.mX[53] = 373.16 - X_idx_74;
  out.mX[54] = 373.16 - X_idx_76;
  out.mX[55] = 373.16 - X_idx_86;
  out.mX[56] = 373.16 - X_idx_89;
  out.mX[57] = 373.16 - X_idx_90;
  out.mX[58] = 373.16 - X_idx_10;
  out.mX[59] = 373.16 - X_idx_97;
  out.mX[60] = 373.16 - X_idx_99;
  out.mX[61] = 373.16 - X_idx_13;
  out.mX[62] = 373.16 - X_idx_111;
  out.mX[63] = 373.16 - X_idx_113;
  out.mX[64] = 373.16 - X_idx_39;
  out.mX[65] = 373.16 - X_idx_40;
  out.mX[66] = 373.16 - X_idx_47;
  out.mX[67] = 373.16 - X_idx_48;
  out.mX[68] = 373.16 - X_idx_6;
  out.mX[69] = 373.16 - X_idx_56;
  out.mX[70] = 373.16 - X_idx_58;
  out.mX[71] = 373.16 - X_idx_8;
  out.mX[72] = 373.16 - X_idx_74;
  out.mX[73] = 373.16 - X_idx_76;
  out.mX[74] = 373.16 - X_idx_89;
  out.mX[75] = 373.16 - X_idx_90;
  out.mX[76] = 373.16 - X_idx_10;
  out.mX[77] = 373.16 - X_idx_97;
  out.mX[78] = 373.16 - X_idx_99;
  out.mX[79] = 373.16 - X_idx_13;
  out.mX[80] = 373.16 - X_idx_111;
  out.mX[81] = 373.16 - X_idx_113;
  out.mX[82] = 500.0 - X_idx_33;
  out.mX[83] = 500.0 - X_idx_37;
  out.mX[84] = 500.0 - X_idx_54;
  out.mX[85] = 500.0 - X_idx_7;
  out.mX[86] = 500.0 - X_idx_70;
  out.mX[87] = 500.0 - X_idx_72;
  out.mX[88] = 500.0 - X_idx_9;
  out.mX[89] = 500.0 - X_idx_87;
  out.mX[90] = 500.0 - X_idx_11;
  out.mX[91] = 500.0 - X_idx_15;
  out.mX[92] = 500.0 - X_idx_33;
  out.mX[93] = 500.0 - X_idx_37;
  out.mX[94] = 500.0 - X_idx_54;
  out.mX[95] = 500.0 - X_idx_7;
  out.mX[96] = 500.0 - X_idx_70;
  out.mX[97] = 500.0 - X_idx_72;
  out.mX[98] = 500.0 - X_idx_9;
  out.mX[99] = 500.0 - X_idx_87;
  out.mX[100] = 500.0 - X_idx_11;
  out.mX[101] = 500.0 - X_idx_15;
  out.mX[102] = X_idx_0;
  out.mX[103] = X_idx_33 - 0.10000000000000002;
  out.mX[104] = X_idx_37 - 0.10000000000000002;
  out.mX[105] = X_idx_39 - 273.16;
  out.mX[106] = X_idx_40 - 273.16;
  out.mX[107] = X_idx_47 - 273.16;
  out.mX[108] = X_idx_48 - 273.16;
  out.mX[109] = X_idx_5 * 0.0078539816339744835 + 0.001 - 1.0000000000000001E-7;
  out.mX[110] = X_idx_54 - 0.10000000000000002;
  out.mX[111] = X_idx_6 - 273.16;
  out.mX[112] = X_idx_56 - 273.16;
  out.mX[113] = X_idx_58 - 273.16;
  out.mX[114] = X_idx_7 - 0.10000000000000002;
  out.mX[115] = X_idx_70 - 0.10000000000000002;
  out.mX[116] = X_idx_72 - 0.10000000000000002;
  out.mX[117] = X_idx_8 - 273.16;
  out.mX[118] = X_idx_74 - 273.16;
  out.mX[119] = X_idx_76 - 273.16;
  out.mX[120] = X_idx_9 - 0.10000000000000002;
  out.mX[121] = X_idx_87 - 0.10000000000000002;
  out.mX[122] = X_idx_89 - 273.16;
  out.mX[123] = X_idx_90 - 273.16;
  out.mX[124] = X_idx_10 - 273.16;
  out.mX[125] = X_idx_97 - 273.16;
  out.mX[126] = X_idx_99 - 273.16;
  out.mX[127] = X_idx_11 - 0.10000000000000002;
  out.mX[128] = X_idx_13 - 273.16;
  out.mX[129] = X_idx_111 - 273.16;
  out.mX[130] = X_idx_113 - 273.16;
  out.mX[131] = X_idx_15 - 0.10000000000000002;
  out.mX[132] = X_idx_14;
  out.mX[133] = (real_T)(0 || X_idx_23 < 1000.0);
  out.mX[134] = (real_T)(0 || X_idx_25 > 0.0);
  out.mX[135] = (real_T)(0 || X_idx_106 * 0.0022666666666666668 + 400.0 > 0.0);
  out.mX[136] = 0.0;
  out.mX[137] = X_idx_17 - intrm_sf_mf_218;
  out.mX[138] = (real_T)t1;
  out.mX[139] = 0.0;
  out.mX[140] = X_idx_2;
  out.mX[141] = !(M_idx_118 != 0) && !(M_idx_119 != 0) && M_idx_121 != 0 ?
    X_idx_16 : 0.0;
  out.mX[142] = t3;
  out.mX[143] = !(M_idx_119 != 0) && M_idx_118 != 0 ? X_idx_16 : 0.0;
  out.mX[144] = t4;
  out.mX[145] = t5;
  (void)t0;
  (void)t9;
  return 0;
}
