/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */
/* shell_elec_electric_vehicle_442b803b_1_ds.c - body for module shell_elec_electric_vehicle_442b803b_1_ds */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_eq_tol.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_vmf.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxicr_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_assert.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxdelt_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxf.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_f.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxf_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_a_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_a.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_tdxf_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_slf.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxm.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ic.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_log.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_m.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_m_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxm_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_mode.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_obs_exp.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_tdxy_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_obs_act.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_obs_all.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_qx.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_qx_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_var_tol.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_dxy_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_mdxy_p.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_zc.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"

static int32_T ds_vmm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dum_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dum(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_b_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_b(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_c_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_c(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_duf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_tduf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_icr_im(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_id(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_y(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_dxy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_duy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dty_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dty(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cache_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_cache_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_update_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_sfo(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sfp(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_init_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_init_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_passert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_del_t(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v0(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_tmax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dp_l(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_j(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qu(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qt(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_q1(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qu_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_q1_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static void release_reference(NeDynamicSystem *ds);
static void get_reference(NeDynamicSystem *ds);
static NeDynamicSystem *diagnostics(const NeDynamicSystem *ds);
static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out);
static NeEquationData s_equation_data[130] = { { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    2U, 0U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    5U, 2U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 2U,
    7U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    2U, 9U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 11U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 13U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 15U, TRUE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 16U, TRUE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 18U, TRUE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 19U, TRUE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 21U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 22U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 5U,
    24U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 29U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 30U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Motor inertia",
    2U, 32U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 2U,
    34U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 2U,
    36U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 2U,
    38U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    2U, 40U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    2U, 42U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass", 2U,
    44U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 46U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 47U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 48U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 49U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 50U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 51U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 52U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 53U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 54U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 55U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 57U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 59U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 61U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 63U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 65U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 67U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    2U, 69U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    3U, 71U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 74U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 76U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 78U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 80U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 82U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 83U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 84U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 85U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 86U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 87U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 89U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 91U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 93U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 95U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 97U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 99U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 2U, 101U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 103U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 104U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 105U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 106U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 107U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 108U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 109U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 111U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 113U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 115U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 117U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 119U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 121U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 2U, 123U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 125U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 126U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 127U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 128U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 129U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 130U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 131U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 133U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 135U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 137U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 139U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 141U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 143U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 2U, 145U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Pump", 4U, 147U, FALSE, 1.0, "1",
  }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 151U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 153U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 155U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 157U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 159U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 161U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 163U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 165U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 167U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 168U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 169U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 170U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 171U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 172U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Product", 1U, 173U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 5U,
    174U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Product",
    1U, 179U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 180U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 182U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 184U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 186U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 188U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 190U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 192U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 194U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 196U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 197U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 198U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 199U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 200U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 201U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 202U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 3U,
    203U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 3U,
    206U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    209U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 7U,
    210U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1U, 217U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/u^2",
    1U, 218U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)",
    1U, 219U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/tanh(x)",
    1U, 220U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/PS Product",
    1U, 221U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)",
    1U, 222U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/tanh(x)",
    1U, 223U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass", 1U,
    224U, TRUE, 1.0, "1", } };

static NeVariableData s_variable_data[130] = { {
    "Battery.Thermal_Model.Battery_thermal_mass.T", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Temperature", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.v", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.Qe", 0U,
    0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Charge deficit", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.x", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Deformation", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.energy",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_NONE, "Energy of liquid volume", },
  { "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.interface_displacement",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY,
    "Interface displacement", }, { "Cooling_system.Hose_1.pipe_model.T", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, TRUE, 1U,
    1U, NE_INIT_MODE_MANDATORY, "Temperature of the liquid volume", }, {
    "Cooling_system.Hose_1.pipe_model.p", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, TRUE, 1U,
    1U, NE_INIT_MODE_MANDATORY, "Pressure of the liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.T", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, TRUE, 1U,
    1U, NE_INIT_MODE_MANDATORY, "Temperature of the liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.p", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, TRUE, 1U,
    1U, NE_INIT_MODE_MANDATORY, "Pressure of the liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.T", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Temperature of the liquid volume", },
  { "Cooling_system.Radiator.Hose_3.pipe_model.p", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Pressure of the liquid volume", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.v", 0U, 0,
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY,
    "Output voltage before ohmic drop", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY,
    "Temperature of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1.T", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1.0,
    "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.p",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY,
    "Pressure of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Motor_inertia.w", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Motor inertia",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Rotational velocity",
  }, { "Energy_based_PMSM_drive_model.Servomotor.integ1.x", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1.0,
    "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "x", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.phi", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1.0,
    "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Angle", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.phi",
    0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Angle", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.x",
    0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Position", }, {
    "Longitudinal_vehicle_dynamics.Vehicle_mass.v", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass",
    1.0, "1", 0.0, TRUE, 1U, 1U, NE_INIT_MODE_MANDATORY, "Velocity", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.Q", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1.0,
    "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Q", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.i", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.v", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.n.v", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.v", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.SOC", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "SOC", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.i", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.C", 0U, 0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "C", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Power_Sum.I1", 0U,
    0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Power Sum",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I1", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Power_Sum.I2", 0U,
    0,
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Power Sum",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I2", }, {
    "Cooling_system.Expansion_tank.A.T", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "", }, {
    "Cooling_system.Expansion_tank.A.p", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.interface_velocity",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Interface velocity", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.f", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_OPTIONAL, "Force", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.B.T", 0U, 1,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.B.p", 0U, 1,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Pressure", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.Phi_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Energy flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.T_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind temperature at port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.T_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind temperature at port B", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.mdot_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Mass flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.rho_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.rho_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Specific internal energy for thermal conduction", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port B", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.T",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_MANDATORY,
    "Temperature of the liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.T_A",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind temperature at port A", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.rho",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density of liquid volume",
  }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.rho_A",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.u",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.u_A",
    0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Hose_1.A.T", 0U, 1,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Temperature", }, { "Cooling_system.Hose_1.A.p",
    0U, 1, "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Pressure", }, {
    "Cooling_system.Hose_1.pipe_model.Nu_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Nusselt number from port A to the pipe center",
  }, { "Cooling_system.Hose_1.pipe_model.T_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port A", }, {
    "Cooling_system.Hose_1.pipe_model.Nu_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Nusselt number from port B to the pipe center",
  }, { "Cooling_system.Hose_1.pipe_model.T_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port B", }, {
    "Cooling_system.Hose_1.pipe_model.Phi_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Energy flow rate into port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.PHI",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Phi", }, {
    "Cooling_system.Hose_1.pipe_model.mdot_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Mass flow rate into port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.M",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "M", }, {
    "Cooling_system.Hose_1.pipe_model.rho", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density of liquid volume", }, {
    "Cooling_system.Hose_1.pipe_model.rho_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Cooling_system.Hose_1.pipe_model.rho_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Cooling_system.Hose_1.pipe_model.u", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Specific internal energy of the liquid volume",
  }, { "Cooling_system.Hose_1.pipe_model.u_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port A", }, {
    "Cooling_system.Hose_1.pipe_model.u_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port B", }, {
    "Cooling_system.Hose_2.A.T", 0U, 1,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Temperature", }, { "Cooling_system.Hose_2.A.p",
    0U, 1, "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Pressure", }, {
    "Cooling_system.Hose_2.B.T", 0U, 1,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Temperature", }, { "Cooling_system.Hose_2.B.p",
    0U, 1, "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Pressure", }, {
    "Cooling_system.Hose_2.pipe_model.Nu_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Nusselt number from port A to the pipe center",
  }, { "Cooling_system.Hose_2.pipe_model.T_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port A", }, {
    "Cooling_system.Hose_2.pipe_model.Nu_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Nusselt number from port B to the pipe center",
  }, { "Cooling_system.Hose_2.pipe_model.T_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port B", }, {
    "Cooling_system.Hose_2.pipe_model.Phi_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Energy flow rate into port A", }, {
    "Cooling_system.Hose_2.pipe_model.Phi_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Energy flow rate into port B", }, {
    "Cooling_system.Hose_2.pipe_model.mdot_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Mass flow rate into port A", }, {
    "Cooling_system.Hose_2.pipe_model.rho", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density of liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.rho_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Cooling_system.Hose_2.pipe_model.rho_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Cooling_system.Hose_2.pipe_model.u", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Specific internal energy of the liquid volume",
  }, { "Cooling_system.Hose_2.pipe_model.u_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port A", }, {
    "Cooling_system.Hose_2.pipe_model.u_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1.0, "1", 0.0, FALSE,
    1U, 1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port B", }, {
    "Cooling_system.OUT.T", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "", }, { "Cooling_system.OUT.p", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "", }, { "Cooling_system.Pump.Phi_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Energy flow rate into port B", }, {
    "Cooling_system.Pump.T_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Upwind temperature at port A", }, {
    "Cooling_system.Pump.T_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Upwind temperature at port B", }, {
    "Cooling_system.Pump.rho_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Density at port A", }, { "Cooling_system.Pump.rho_B",
    0U, 0, "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Cooling_system.Pump.u", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Specific internal energy for thermal conduction", },
  { "Cooling_system.Pump.u_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port A", }, {
    "Cooling_system.Pump.u_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Pump", 1.0, "1", 0.0, FALSE, 1U,
    1U, NE_INIT_MODE_NONE, "Upwind specific internal energy at port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Nu_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Nusselt number from port A to the pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.T_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Nu_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Nusselt number from port B to the pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.T_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Upwind temperature at port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density of liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u_A", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u_B", 0U, 0,
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1.0, "1", 0.0,
    FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port B", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.i2", 0U, 0,
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Output current", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.S", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "S", }, {
    "Longitudinal_vehicle_dynamics.Wheel_and_Axle.f", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Wheel and Axle",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Force", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.Q", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Q", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Nu_A",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Nusselt number from port A to the pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T_A",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind temperature at port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Nu_B",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Nusselt number from port B to the pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T_B",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind temperature at port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Product.I2", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Product",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I2", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density of liquid volume",
  }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho_A",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho_B",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Density at port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Specific internal energy of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u_A",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u_B",
    0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE,
    "Upwind specific internal energy at port B", }, {
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.T", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "T", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1.Q", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1.0,
    "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "Heat flow", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.torque", 0U, 0,
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1.0,
    "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "torque", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.F", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "F", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Product.I1", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Product.I2", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x.O", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.I2", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/PS Product",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x.O", 0U, 0,
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)",
    1.0, "1", 0.0, FALSE, 1U, 1U, NE_INIT_MODE_NONE, "O", } };

static NeVariableData *s_discrete_data = NULL;
static NeObservableData s_observable_data[524] = { { "Ambient_temperature.A.T",
    "shell_elec_electric_vehicle/Ambient temperature", 1U, 1U, "K",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Ambient_temperature.B.T", "shell_elec_electric_vehicle/Ambient temperature",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Ambient_temperature.Q", "shell_elec_electric_vehicle/Ambient temperature",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Q", }, {
    "Ambient_temperature.S", "shell_elec_electric_vehicle/Ambient temperature",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Ambient_temperature.T", "shell_elec_electric_vehicle/Ambient temperature",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Controlled_Voltage_Source.i",
    "shell_elec_electric_vehicle/Battery/Controlled Voltage Source", 1U, 1U, "A",
    NE_INIT_MODE_NONE, FALSE, FALSE, "i", }, {
    "Battery.Controlled_Voltage_Source.n.v",
    "shell_elec_electric_vehicle/Battery/Controlled Voltage Source", 1U, 1U, "V",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "Battery.Controlled_Voltage_Source.p.v",
    "shell_elec_electric_vehicle/Battery/Controlled Voltage Source", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Controlled_Voltage_Source.v",
    "shell_elec_electric_vehicle/Battery/Controlled Voltage Source", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "v", }, {
    "Battery.Controlled_Voltage_Source.vT",
    "shell_elec_electric_vehicle/Battery/Controlled Voltage Source", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "vT", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.SOC",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "SOC", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.T",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.i",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.n.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.p.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.C1.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/C1",
    1U, 1U, "V", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.C",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "hr*A", NE_INIT_MODE_NONE, FALSE, FALSE, "C", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.Qe",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "hr*A", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Charge deficit", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.SOC",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "SOC", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.T",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.i",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.n.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.p.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Ploss",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "Ploss", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Power_Sum.I1",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Power Sum",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Power_Sum.I2",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Power Sum",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Power_Sum.O",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Power Sum",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.SOC",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "SOC", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.T",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.i",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.n.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.p.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.pow",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "W", NE_INIT_MODE_NONE, FALSE, FALSE, "POW", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R0.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R0",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.SOC",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "SOC", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.T",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.i",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.n.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.p.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.pow",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "W", NE_INIT_MODE_NONE, FALSE, FALSE, "POW", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.R1.v",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Electrical_model_for_Np_parallel_connected_cells.T",
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, { "Battery.Ns.I",
    "shell_elec_electric_vehicle/Battery/Ns", 1U, 1U, "1", NE_INIT_MODE_NONE,
    FALSE, FALSE, "I", }, { "Battery.Ns.O",
    "shell_elec_electric_vehicle/Battery/Ns", 1U, 1U, "1", NE_INIT_MODE_NONE,
    FALSE, FALSE, "O", }, { "Battery.Ns_1.I",
    "shell_elec_electric_vehicle/Battery/Ns-1", 1U, 1U, "1", NE_INIT_MODE_NONE,
    FALSE, FALSE, "I", }, { "Battery.Ns_1.O",
    "shell_elec_electric_vehicle/Battery/Ns-1", 1U, 1U, "1", NE_INIT_MODE_NONE,
    FALSE, FALSE, "O", }, { "Battery.Thermal_Model.Battery_thermal_mass.M.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Battery_thermal_mass.Q",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Heat flow", }, {
    "Battery.Thermal_Model.Battery_thermal_mass.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 1U,
    1U, "K", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Temperature", }, {
    "Battery.Thermal_Model.Ideal_Heat_Flow_Source.A.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Ideal_Heat_Flow_Source.B.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Ideal_Heat_Flow_Source.Q",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Heat Flow Source",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Q", }, {
    "Battery.Thermal_Model.Ideal_Heat_Flow_Source.S",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Heat Flow Source",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Battery.Thermal_Model.Ideal_Heat_Flow_Source.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Thermal_Model.Ideal_Temperature_Sensor.A.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Ideal_Temperature_Sensor.B.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Ideal_Temperature_Sensor.Qs",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Temperature Sensor",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Qs", }, {
    "Battery.Thermal_Model.Ideal_Temperature_Sensor.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Thermal_Model.Ideal_Temperature_Sensor.Ts",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Ts", }, {
    "Battery.Thermal_Model.PlossTotal",
    "shell_elec_electric_vehicle/Battery/Thermal Model", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE, "PlossTotal", }, {
    "Battery.Thermal_Model.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Battery.Thermal_Model.Thermal_Reference1.H.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Thermal Reference1", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Battery.Thermal_Model.Thermal_Reference2.H.T",
    "shell_elec_electric_vehicle/Battery/Thermal Model/Thermal Reference2", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Battery.Voltage_Sensor.V",
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "V", }, { "Battery.Voltage_Sensor.i1",
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 1U, "A",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Current", }, { "Battery.Voltage_Sensor.n.v",
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Battery.Voltage_Sensor.p.v",
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, { "Battery.Voltage_Sensor.v1",
    "shell_elec_electric_vehicle/Battery/Voltage Sensor", 1U, 1U, "V",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Convective_Heat_Transfer.A.T",
    "shell_elec_electric_vehicle/Convective Heat Transfer", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Convective_Heat_Transfer.B.T",
    "shell_elec_electric_vehicle/Convective Heat Transfer", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Convective_Heat_Transfer.Q",
    "shell_elec_electric_vehicle/Convective Heat Transfer", 1U, 1U, "J/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Heat flow", }, {
    "Convective_Heat_Transfer.T",
    "shell_elec_electric_vehicle/Convective Heat Transfer", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature drop", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.x",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 1U, "m", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Deformation", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.C.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.R.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.f",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 1U, "N", NE_INIT_MODE_OPTIONAL, FALSE, FALSE, "Force", }, {
    "Cooling_system.Expansion_tank.Air_stiffness.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Air stiffness",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.B.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.B.p",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.Phi_B",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate into port B", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.T_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A",
  }, { "Cooling_system.Expansion_tank.Local_Restriction_TL.T_B",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B",
  }, { "Cooling_system.Expansion_tank.Local_Restriction_TL.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.mdot_B",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate into port B", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.rho_B",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy for thermal conduction", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Expansion_tank.Local_Restriction_TL.u_B",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port B", }, {
    "Cooling_system.Expansion_tank.Mechanical_Translational_Reference.V.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Mechanical Translational Reference",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Mechanical_Translational_Reference1.V.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Mechanical Translational Reference1",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Perfect_Insulator.A.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Perfect Insulator",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Perfect_Insulator.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Perfect Insulator",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.C.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.H.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.R.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.C.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.H.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.Q_H",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, TRUE, FALSE, "Heat flow rate into port H",
  }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.R.v",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.energy",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kJ", NE_INIT_MODE_NONE, FALSE, TRUE, "Energy of liquid volume", },
    {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.interface_displacement",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Interface displacement",
  }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.interface_force",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "N", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Fluid-exerted force on the interface", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.interface_velocity",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Interface velocity", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.rho",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Density of liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.volume",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Volume of liquid", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.A.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.A.p",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.T",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_MANDATORY, FALSE, FALSE,
    "Temperature of the liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.T_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A",
  }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate into port A", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.p",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure of the liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.u",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model.u_A",
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Hose_1.A.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.A.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_1.B.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.B.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_1.H.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.pipe_model.rho",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density of liquid volume", }, {
    "Cooling_system.Hose_1.pipe_model.H.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.pipe_model.Nu_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port A to the pipe center", }, {
    "Cooling_system.Hose_1.pipe_model.Nu_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port B to the pipe center", }, {
    "Cooling_system.Hose_1.pipe_model.Q_H",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Heat flow rate into port H", }, {
    "Cooling_system.Hose_1.pipe_model.pressure_loss_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port A to pipe center", }, {
    "Cooling_system.Hose_1.pipe_model.pressure_loss_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port B to pipe center", }, {
    "Cooling_system.Hose_1.pipe_model.A.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.pipe_model.A.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_1.pipe_model.B.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_1.pipe_model.B.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_1.pipe_model.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port A", }, {
    "Cooling_system.Hose_1.pipe_model.Phi_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port B", }, {
    "Cooling_system.Hose_1.pipe_model.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Temperature of the liquid volume", },
    { "Cooling_system.Hose_1.pipe_model.T_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A", }, {
    "Cooling_system.Hose_1.pipe_model.T_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B", }, {
    "Cooling_system.Hose_1.pipe_model.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Mass flow rate into port A", }, {
    "Cooling_system.Hose_1.pipe_model.mdot_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Mass flow rate into port B", }, {
    "Cooling_system.Hose_1.pipe_model.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "MPa",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Pressure of the liquid volume", }, {
    "Cooling_system.Hose_1.pipe_model.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Hose_1.pipe_model.rho_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Cooling_system.Hose_1.pipe_model.u",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Hose_1.pipe_model.u_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind specific internal energy at port A",
  }, { "Cooling_system.Hose_1.pipe_model.u_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind specific internal energy at port B",
  }, { "Cooling_system.Hose_2.A.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.A.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_2.B.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.B.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_2.H.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.pipe_model.rho",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density of liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.H.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.pipe_model.Nu_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port A to the pipe center", }, {
    "Cooling_system.Hose_2.pipe_model.Nu_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port B to the pipe center", }, {
    "Cooling_system.Hose_2.pipe_model.Q_H",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Heat flow rate into port H", }, {
    "Cooling_system.Hose_2.pipe_model.pressure_loss_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port A to pipe center", }, {
    "Cooling_system.Hose_2.pipe_model.pressure_loss_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port B to pipe center", }, {
    "Cooling_system.Hose_2.pipe_model.A.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.pipe_model.A.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_2.pipe_model.B.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Hose_2.pipe_model.B.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Hose_2.pipe_model.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port A", }, {
    "Cooling_system.Hose_2.pipe_model.Phi_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port B", }, {
    "Cooling_system.Hose_2.pipe_model.T",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Temperature of the liquid volume", },
    { "Cooling_system.Hose_2.pipe_model.T_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A", }, {
    "Cooling_system.Hose_2.pipe_model.T_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B", }, {
    "Cooling_system.Hose_2.pipe_model.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Mass flow rate into port A", }, {
    "Cooling_system.Hose_2.pipe_model.mdot_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Mass flow rate into port B", }, {
    "Cooling_system.Hose_2.pipe_model.p",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "MPa",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Pressure of the liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Hose_2.pipe_model.rho_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Cooling_system.Hose_2.pipe_model.u",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Hose_2.pipe_model.u_A",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind specific internal energy at port A",
  }, { "Cooling_system.Hose_2.pipe_model.u_B",
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind specific internal energy at port B",
  }, { "Cooling_system.Insulator_Hose.A.T",
    "shell_elec_electric_vehicle/Cooling system/Insulator Hose", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Insulator_Hose.T",
    "shell_elec_electric_vehicle/Cooling system/Insulator Hose", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Insulator_Hose1.A.T",
    "shell_elec_electric_vehicle/Cooling system/Insulator Hose1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Insulator_Hose1.T",
    "shell_elec_electric_vehicle/Cooling system/Insulator Hose1", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Pump.power",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Work done on the liquid by the source", },
  { "Cooling_system.Pump.A.T", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Pump.A.p", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Pump.B.T", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Pump.B.p", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Pump.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port A", }, {
    "Cooling_system.Pump.Phi_B",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port B", }, {
    "Cooling_system.Pump.T_A", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A",
  }, { "Cooling_system.Pump.T_B",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B", }, {
    "Cooling_system.Pump.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Mass flow rate into port A", }, {
    "Cooling_system.Pump.mdot_B",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Mass flow rate into port B", }, {
    "Cooling_system.Pump.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Pump.rho_B",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kg/m^3",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Cooling_system.Pump.u", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy for thermal conduction", }, {
    "Cooling_system.Pump.u_A", "shell_elec_electric_vehicle/Cooling system/Pump",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port A", }, { "Cooling_system.Pump.u_B",
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 1U, "kJ/kg",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind specific internal energy at port B",
  }, { "Cooling_system.Radiator.Absolute_Reference_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Absolute Reference (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Absolute_Reference_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Absolute Reference (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, TRUE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.Q",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Q", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.S",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Cooling_system.Radiator.Heat_Flow_Source.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Heat Flow Source", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Cooling_system.Radiator.Hose_3.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.A.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Hose_3.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.B.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Hose_3.H.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density of liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.H.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Nu_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port A to the pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Nu_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "1",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port B to the pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Q_H",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Heat flow rate into port H", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.pressure_loss_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port A to pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.pressure_loss_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port B to pipe center", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.A.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.B.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Phi_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.Phi_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "kW",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Energy flow rate into port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Temperature of the liquid volume", },
    { "Cooling_system.Radiator.Hose_3.pipe_model.T_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.T_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "K",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.mdot_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Mass flow rate into port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.mdot_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "kg/s",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Mass flow rate into port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U, "MPa",
    NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Pressure of the liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.rho_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy of the liquid volume", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u_A",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port A", }, {
    "Cooling_system.Radiator.Hose_3.pipe_model.u_B",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 1U,
    "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port B", }, {
    "Cooling_system.Radiator.Ideal_Temperature_Sensor.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Ideal_Temperature_Sensor.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Ideal_Temperature_Sensor.Qs",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Ideal Temperature Sensor",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Qs", }, {
    "Cooling_system.Radiator.Ideal_Temperature_Sensor.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Cooling_system.Radiator.Ideal_Temperature_Sensor.Ts",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Ts", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.B.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.M",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE, "M", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.PHI",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "W", NE_INIT_MODE_NONE, FALSE, FALSE, "Phi", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.Phi",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate from port A to port B", }, {
    "Cooling_system.Radiator.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.mdot",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate from port A to port B", }, {
    "Cooling_system.Radiator.PS_Product.I1",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Product", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Cooling_system.Radiator.PS_Product.I2",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Product", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Cooling_system.Radiator.PS_Product.O",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Product", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Cooling_system.Radiator.PS_Subtract.I1",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Subtract", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Cooling_system.Radiator.PS_Subtract.I2",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Subtract", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Cooling_system.Radiator.PS_Subtract.O",
    "shell_elec_electric_vehicle/Cooling system/Radiator/PS Subtract", 1U, 1U,
    "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.B.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.B.p",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, TRUE, FALSE, "Pressure", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.P",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "Pa", NE_INIT_MODE_NONE, FALSE, FALSE, "P", }, {
    "Cooling_system.Radiator.Pressure_Temperature_Sensor_TL.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Cooling_system.Radiator.Specific_dissipation_J_s_K_per_unit_mass_flow_rate.I",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Specific dissipation (J//s//K) per unit mass flow rate",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Cooling_system.Radiator.Specific_dissipation_J_s_K_per_unit_mass_flow_rate.O",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Specific dissipation (J//s//K) per unit mass flow rate",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Cooling_system.Radiator.Thermal_Reference1.H.T",
    "shell_elec_electric_vehicle/Cooling system/Radiator/Thermal Reference1", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Cooling_system.Thermal_Liquid_Settings_TL.A.T",
    "shell_elec_electric_vehicle/Cooling system/Thermal Liquid Settings (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Cooling_system.Thermal_Liquid_Settings_TL.A.p",
    "shell_elec_electric_vehicle/Cooling system/Thermal Liquid Settings (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.I",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Current Sensor",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.i1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Current Sensor",
    1U, 1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.n.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Current Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.p.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Current Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.v1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Current Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.V",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Voltage Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "V", }, {
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.i1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Voltage Sensor",
    1U, 1U, "A", NE_INIT_MODE_NONE, TRUE, FALSE, "Current", }, {
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.n.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Voltage Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.p.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Voltage Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.v1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Battery sensors/Voltage Sensor",
    1U, 1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.F",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "F", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.i1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Input current", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.i2",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Output current", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.n1.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.n2.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.p1.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.p2.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    "Output voltage before ohmic drop", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.v1",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Input voltage", }, {
    "DC_DC_converter_averaged.DC_DC_Converter.v2",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Output voltage", }, {
    "DC_DC_converter_averaged.No_faults.O",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/No faults", 1U, 1U,
    "1", NE_INIT_MODE_NONE, TRUE, FALSE, "O", }, {
    "DC_DC_converter_averaged.Resistor.i",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Resistor", 1U, 1U,
    "A", NE_INIT_MODE_NONE, FALSE, FALSE, "Current", }, {
    "DC_DC_converter_averaged.Resistor.n.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Resistor", 1U, 1U,
    "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Resistor.p.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Resistor", 1U, 1U,
    "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "DC_DC_converter_averaged.Resistor.v",
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/Resistor", 1U, 1U,
    "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Differential_pinion_crown_ratio.O.w",
    "shell_elec_electric_vehicle/Differential pinion-crown ratio", 1U, 1U,
    "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Differential_pinion_crown_ratio.S.w",
    "shell_elec_electric_vehicle/Differential pinion-crown ratio", 1U, 1U,
    "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Differential_pinion_crown_ratio.t_in",
    "shell_elec_electric_vehicle/Differential pinion-crown ratio", 1U, 1U, "N*m",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Input shaft incoming torque", }, {
    "Differential_pinion_crown_ratio.t_out",
    "shell_elec_electric_vehicle/Differential pinion-crown ratio", 1U, 1U, "N*m",
    NE_INIT_MODE_NONE, FALSE, FALSE, "Output shaft incoming torque", }, {
    "Electrical_Reference.V.v",
    "shell_elec_electric_vehicle/Electrical Reference", 1U, 1U, "V",
    NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Absolute_Reference_TL.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Absolute Reference (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Absolute_Reference_TL.A.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Absolute Reference (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, TRUE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.Q",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Q", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.S",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Heat_Flow_Source.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Heat Flow Source",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.Qs",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Ideal Temperature Sensor",
    1U, 1U, "J/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Qs", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.Ts",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Ideal Temperature Sensor",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Ts", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.A.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.B.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.M",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE, "M", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.PHI",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "W", NE_INIT_MODE_NONE, FALSE, FALSE, "Phi", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.Phi",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate from port A to port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Mass_Flow_Rate_Thermal_Flux_Sensor_TL.mdot",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Mass Flow Rate & Thermal Flux Sensor (TL)",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate from port A to port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Product.I1",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Product.I2",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Product.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Subtract.I1",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Subtract.I2",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.PS_Subtract.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.A.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.B.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.H.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Density of liquid volume", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.H.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Nu_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port A to the pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Nu_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Nusselt number from port B to the pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Q_H",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE, "Heat flow rate into port H",
  }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.pressure_loss_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port A to pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.pressure_loss_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Pressure loss due to viscous friction from port B to pipe center", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.A.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.B.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Phi_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate into port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.Phi_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kW", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Energy flow rate into port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    "Temperature of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port A",
  }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.T_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Upwind temperature at port B",
  }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.mdot_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Mass flow rate into port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.mdot_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kg/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Mass flow rate into port B",
  }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "MPa", NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    "Pressure of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.rho_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kg/m^3", NE_INIT_MODE_NONE, FALSE, FALSE, "Density at port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Specific internal energy of the liquid volume", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u_A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port A", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model.u_B",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 1U, "kJ/kg", NE_INIT_MODE_NONE, FALSE, FALSE,
    "Upwind specific internal energy at port B", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.A.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, FALSE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.B.p",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "MPa", NE_INIT_MODE_NONE, TRUE, FALSE, "Pressure", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.P",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "Pa", NE_INIT_MODE_NONE, FALSE, FALSE, "P", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pressure_Temperature_Sensor_TL.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pressure & Temperature Sensor (TL)",
    1U, 1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K.I",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "x", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "f", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K_per_unit_mass_flow_rate.I",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K) per unit mass flow rate",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K_per_unit_mass_flow_rate.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K) per unit mass flow rate",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Heat_exchanger.Thermal_Reference1.H.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Thermal Reference1",
    1U, 1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Mechanical_Rotational_Reference1.W.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Mechanical Rotational Reference1",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Motor_inertia.I.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Motor inertia",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    { "Energy_based_PMSM_drive_model.Motor_inertia.t",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Motor inertia",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Energy_based_PMSM_drive_model.Motor_inertia.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Motor inertia",
    1U, 1U, "rpm", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Rotational velocity", },
  { "Energy_based_PMSM_drive_model.Servomotor.C.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.H.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.Omega",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Omega", }, {
    "Energy_based_PMSM_drive_model.Servomotor.R.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.Tr",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Tr", }, {
    "Energy_based_PMSM_drive_model.Servomotor.Vm.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.Vp.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.csrc1.head.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.csrc1.i",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "i", }, {
    "Energy_based_PMSM_drive_model.Servomotor.csrc1.iT",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "iT", }, {
    "Energy_based_PMSM_drive_model.Servomotor.csrc1.tail.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.csrc1.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "v", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.losses",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "W", NE_INIT_MODE_NONE, FALSE, FALSE, "losses", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.current",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "A", NE_INIT_MODE_NONE, FALSE, FALSE, "current", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.faulted",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "faulted", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.speed",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "speed", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.torque",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "torque", }, {
    "Energy_based_PMSM_drive_model.Servomotor.current_calculation.voltage",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.damper1.C.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.damper1.R.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.damper1.t",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Energy_based_PMSM_drive_model.Servomotor.damper1.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.gain1.I",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Energy_based_PMSM_drive_model.Servomotor.gain1.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Servomotor.heat_flow_source.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.heat_flow_source.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.heat_flow_source.Q",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Q", }, {
    "Energy_based_PMSM_drive_model.Servomotor.heat_flow_source.S",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Energy_based_PMSM_drive_model.Servomotor.heat_flow_source.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Servomotor.integ1.I",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Energy_based_PMSM_drive_model.Servomotor.integ1.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Servomotor.integ1.x",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "x", }, {
    "Energy_based_PMSM_drive_model.Servomotor.ps_sub1.I1",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Energy_based_PMSM_drive_model.Servomotor.ps_sub1.I2",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Energy_based_PMSM_drive_model.Servomotor.ps_sub1.O",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Energy_based_PMSM_drive_model.Servomotor.temperature_sensor.A.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.temperature_sensor.B.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.temperature_sensor.Qs",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Qs", }, {
    "Energy_based_PMSM_drive_model.Servomotor.temperature_sensor.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Servomotor.temperature_sensor.Ts",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Ts", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1.M.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, FALSE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1.Q",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "J/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Heat flow", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_reference.H.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.thermal_reference_node.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque1.C.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque1.R.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque1.S",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque1.t",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque1.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Angular velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque_calculation.faulted",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "faulted", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque_calculation.speed",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "speed", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque_calculation.torque",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "torque", }, {
    "Energy_based_PMSM_drive_model.Servomotor.torque_calculation.torque_ref",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "torque_ref", }, {
    "Energy_based_PMSM_drive_model.Servomotor.vsens1.V",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "V", }, {
    "Energy_based_PMSM_drive_model.Servomotor.vsens1.i1",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "A", NE_INIT_MODE_NONE, TRUE, FALSE, "Current", }, {
    "Energy_based_PMSM_drive_model.Servomotor.vsens1.n.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, TRUE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.vsens1.p.v",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.vsens1.v1",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "V", NE_INIT_MODE_NONE, FALSE, FALSE, "Voltage", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.A",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad", NE_INIT_MODE_NONE, FALSE, FALSE, "A", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.C.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.R.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.W",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "W", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.phi",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "1", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Angle", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.t",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "N*m", NE_INIT_MODE_NONE, TRUE, FALSE, "Torque", }, {
    "Energy_based_PMSM_drive_model.Servomotor.wsens1.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Angular velocity", }, {
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.C.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    { "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.R.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    { "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.T",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "T", }, {
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.t",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.w",
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Torque sensor/Ideal Torque Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Angular velocity", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.F",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "F", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Product.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Product.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Product.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Subtract.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Subtract.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Subtract.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/PS Subtract",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.u2.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/u^2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.u2.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/u^2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.vV",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "vV", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.x0_5Cddensityarea.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/0.5*Cd*density*area",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.x0_5Cddensityarea.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/0.5*Cd*density*area",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x1.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x1.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x_1.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x_1.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.exp2x_1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.tanhx.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.tanhx.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.tanhx.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.x",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "x", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.x1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.x2.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.x2.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.y",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "y", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.A",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "rad", NE_INIT_MODE_NONE, FALSE, FALSE, "A", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.C.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.R.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.W",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "W", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.phi",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "1", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Angle", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.t",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, TRUE, FALSE, "Torque", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Rotational_Motion_Sensor.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Rotational Motion Sensor",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Angular velocity", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.C.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.R.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    { "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.S",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.t",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Ideal_Torque_Source.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Ideal Torque Source",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Angular velocity", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.Mechanical_Rotational_Reference.W.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/Mechanical Rotational Reference",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Rotational velocity", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/PS Product",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x1.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x1.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)+1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x_1.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x_1.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.exp2x_1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/exp(2x)-1",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.tanhx.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.tanhx.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.tanhx.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.x",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "x", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.x1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/1",
    1U, 1U, "1", NE_INIT_MODE_NONE, TRUE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.x2.I",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.x2.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/2",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.y",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)",
    1U, 1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "y", }, {
    "Longitudinal_vehicle_dynamics.Ideal_Force_Source.C.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Ideal Force Source",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Ideal_Force_Source.R.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Ideal Force Source",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Ideal_Force_Source.S",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Ideal Force Source",
    1U, 1U, "N", NE_INIT_MODE_NONE, FALSE, FALSE, "S", }, {
    "Longitudinal_vehicle_dynamics.Ideal_Force_Source.f",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Ideal Force Source",
    1U, 1U, "N", NE_INIT_MODE_NONE, FALSE, FALSE, "Force", }, {
    "Longitudinal_vehicle_dynamics.Ideal_Force_Source.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Ideal Force Source",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.C.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.P",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m", NE_INIT_MODE_NONE, FALSE, FALSE, "P", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.R.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.V",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "V", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.f",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "N", NE_INIT_MODE_NONE, TRUE, FALSE, "Force", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.x",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Ideal Translational Motion Sensor",
    1U, 1U, "m", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Position", }, {
    "Longitudinal_vehicle_dynamics.Measurement.Mechanical_Translational_Reference.V.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement/Mechanical Translational Reference",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Measurement.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Measurement", 1U,
    1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "w", }, {
    "Longitudinal_vehicle_dynamics.Mechanical_Translational_Reference.V.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Mechanical Translational Reference",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, TRUE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.PS_Subtract1.I1",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/PS Subtract1", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I1", }, {
    "Longitudinal_vehicle_dynamics.PS_Subtract1.I2",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/PS Subtract1", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "I2", }, {
    "Longitudinal_vehicle_dynamics.PS_Subtract1.O",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/PS Subtract1", 1U,
    1U, "1", NE_INIT_MODE_NONE, FALSE, FALSE, "O", }, {
    "Longitudinal_vehicle_dynamics.Vehicle_mass.M.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass", 1U,
    1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Vehicle_mass.f",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass", 1U,
    1U, "N", NE_INIT_MODE_NONE, FALSE, FALSE, "Force", }, {
    "Longitudinal_vehicle_dynamics.Vehicle_mass.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Vehicle mass", 1U,
    1U, "m/s", NE_INIT_MODE_MANDATORY, FALSE, TRUE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Wheel_and_Axle.A.w",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Wheel and Axle",
    1U, 1U, "rad/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Rotational velocity", },
    { "Longitudinal_vehicle_dynamics.Wheel_and_Axle.P.v",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Wheel and Axle",
    1U, 1U, "m/s", NE_INIT_MODE_NONE, FALSE, FALSE, "Velocity", }, {
    "Longitudinal_vehicle_dynamics.Wheel_and_Axle.f",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Wheel and Axle",
    1U, 1U, "N", NE_INIT_MODE_NONE, FALSE, FALSE, "Force", }, {
    "Longitudinal_vehicle_dynamics.Wheel_and_Axle.t",
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Wheel and Axle",
    1U, 1U, "N*m", NE_INIT_MODE_NONE, FALSE, FALSE, "Torque", }, {
    "Thermal_Reference.H.T", "shell_elec_electric_vehicle/Thermal Reference", 1U,
    1U, "K", NE_INIT_MODE_NONE, TRUE, FALSE, "Temperature", } };

static NeModeData *s_major_mode_data = NULL;
static NeZCData s_zc_data[146] = { {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 0U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    4U, 1U, "Battery.Electrical_model_for_Np_parallel_connected_cells.R1",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    16U, 5U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    9U, 21U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 12U, 30U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 42U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 12U, 47U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    9U, 59U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 68U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    9U, 73U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 82U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 87U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/R1",
    4U, 92U, "Battery.Electrical_model_for_Np_parallel_connected_cells.R1",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 96U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    3U, 97U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 100U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    3U, 102U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    3U, 105U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 108U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 110U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 112U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 114U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 119U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 124U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 129U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    2U, 131U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 133U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 138U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 143U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 148U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 2U,
    150U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_FALSE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 2U,
    152U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 154U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 159U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 164U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 169U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 174U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 179U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    5U, 184U,
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    5U, 189U,
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    3U, 194U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 197U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    3U, 199U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    3U, 202U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 205U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    2U, 207U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 209U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 211U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 216U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 221U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 226U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    2U, 228U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 230U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 235U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 240U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 245U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 2U,
    247U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 2U,
    249U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 251U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 256U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 261U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 266U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 271U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 276U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 281U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 282U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 283U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 284U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 285U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 286U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 287U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 288U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 289U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 290U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U,
    291U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U,
    292U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 293U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 294U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 295U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 296U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 297U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 298U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    16U, 299U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    9U, 315U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 12U, 324U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    5U, 336U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 12U, 341U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    9U, 353U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    5U, 362U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    9U, 367U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 5U, 376U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    5U, 381U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    3U, 386U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    3U, 389U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 392U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 394U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 395U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    2U, 397U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 399U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 400U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 402U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 403U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 1U,
    404U, "Battery.Thermal_Model.Battery_thermal_mass",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    3U, 405U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    3U, 408U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 411U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 412U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 413U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 414U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 415U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 416U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 418U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 419U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 420U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 1",
    1U, 421U, "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 2U, 422U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    2U, 424U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 426U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 427U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 428U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Hose 2",
    1U, 429U, "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    2U, 430U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U,
    432U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U,
    433U, "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 434U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 435U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 436U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 437U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 438U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 439U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 440U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 441U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    442U, "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    443U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    444U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    445U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 446U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    447U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 448U,
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 449U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    450U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    451U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    452U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    453U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_TRUE, }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    454U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    NE_ZC_TYPE_FALSE, }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    455U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    NE_ZC_TYPE_FALSE, } };

static NeRange s_range[456] = { {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    79U, 18U, 79U, 81U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    60U, 17U, 61U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    87U, 14U, 88U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    82U, 16U, 82U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    83U, 16U, 83U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    153U, 16U, 153U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    154U, 16U, 154U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    100U, 19U, 100U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    119U, 18U, 119U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    130U, 16U, 130U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    60U, 17U, 61U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    87U, 14U, 88U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    79U, 18U, 79U, 81U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    100U, 19U, 100U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    82U, 16U, 82U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    83U, 16U, 83U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    153U, 16U, 153U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    154U, 16U, 154U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    119U, 18U, 119U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    130U, 16U, 130U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    60U, 17U, 61U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    80U, 14U, 81U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    87U, 14U, 88U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    60U, 17U, 61U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    80U, 14U, 81U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    87U, 14U, 88U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    56U, 17U, 57U, 59U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    100U, 19U, 100U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    82U, 16U, 82U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    83U, 16U, 83U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    153U, 16U, 153U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    154U, 16U, 154U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    119U, 18U, 119U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    130U, 16U, 130U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    133U, 16U, 133U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    137U, 16U, 137U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    115U, 16U, 115U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    111U, 16U, 111U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    133U, 16U, 133U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    137U, 16U, 137U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    82U, 16U, 82U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    83U, 16U, 83U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    153U, 16U, 153U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    154U, 16U, 154U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    100U, 19U, 100U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    119U, 18U, 119U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    130U, 16U, 130U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    104U, 16U, 104U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    106U, 16U, 106U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    108U, 16U, 108U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    130U, 19U, 130U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 18U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 16U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    119U, 19U, 119U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 18U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 16U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    121U, 19U, 121U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 18U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 16U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    105U, 16U, 105U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    107U, 16U, 107U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    109U, 16U, 109U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    132U, 19U, 132U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 18U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 16U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    68U, 17U, 68U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    69U, 17U, 69U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    70U, 17U, 70U, 102U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 16U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 16U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    131U, 16U, 131U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    135U, 16U, 135U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    109U, 16U, 109U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    113U, 16U, 113U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    131U, 16U, 131U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    135U, 16U, 135U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    46U, 12U, 46U, 15U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    132U, 16U, 132U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    136U, 16U, 136U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    110U, 16U, 110U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    114U, 16U, 114U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    134U, 16U, 134U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    138U, 16U, 138U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    116U, 16U, 116U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    112U, 16U, 112U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    135U, 16U, 135U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    132U, 16U, 132U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    136U, 16U, 136U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    134U, 16U, 134U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    138U, 16U, 138U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 26U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    46U, 12U, 46U, 15U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    91U, 38U, 91U, 48U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    73U, 12U, 73U, 23U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    91U, 54U, 91U, 64U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeAssertData s_assert_data[365] = { {
    "shell_elec_electric_vehicle/Battery/Thermal Model/Battery thermal mass", 1U,
    0U, "Battery.Thermal_Model.Battery_thermal_mass",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    FALSE, "Temperature must be greater than absolute zero", "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 1U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 2U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 3U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 4U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 5U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 6U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 7U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 8U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 9U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 10U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 11U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 12U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 13U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE,
    "Pressure of the liquid volume is greater than the maximum valid pressure",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 14U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE,
    "Pressure of the liquid volume is less than the minimum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 15U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE,
    "Temperature of the liquid volume is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 16U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE,
    "Temperature of the liquid volume is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 17U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    FALSE, "Liquid volume fell to zero", "", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 18U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 19U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 20U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 21U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 22U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 23U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 24U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 25U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 26U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is greater than the maximum valid pressure",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 27U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is less than the minimum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 28U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 29U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 30U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 31U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 32U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 33U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 34U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 35U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 36U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 37U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 38U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is greater than the maximum valid pressure",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 39U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is less than the minimum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 40U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 41U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 42U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 43U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 44U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 45U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 46U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 47U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 48U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 49U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    50U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 51U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 52U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    53U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    54U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 55U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 56U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    57U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    58U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is greater than the maximum valid pressure",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    59U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is less than the minimum valid pressure", "",
  }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 60U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is greater than the maximum valid temperature",
    "", }, { "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U,
    61U, "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    62U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    FALSE,
    "Supply-side current exceeded the Maximum expected supply-side current", "",
  }, { "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter",
    1U, 63U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    FALSE, "Supply-side voltage must be greater than zero", "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 64U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is greater than the maximum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 65U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port A is less than the minimum valid pressure", "", },
    {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 66U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 67U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port A is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 68U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is greater than the maximum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 69U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Pressure at port B is less than the minimum valid pressure", "", },
    {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 70U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 71U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Temperature at port B is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 72U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is greater than the maximum valid pressure",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 73U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Pressure of the liquid volume is less than the minimum valid pressure", "",
  }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 74U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is greater than the maximum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 75U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE,
    "Temperature of the liquid volume is less than the minimum valid temperature",
    "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Specific dissipation (J//s//K)",
    1U, 76U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Specific_dissipation_J_s_K",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    FALSE, "Input is outside the range of Table grid vector", "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    77U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    FALSE, "Servomotor DC voltage supply must be greater than zero", "", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    78U, "Energy_based_PMSM_drive_model.Servomotor.thermal_mass1",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    FALSE, "Temperature must be greater than absolute zero", "", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 79U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 80U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 81U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 82U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 83U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 84U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 85U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 86U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 87U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 88U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 89U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 90U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 91U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 92U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 93U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 94U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 95U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 96U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 97U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 98U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 99U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 100U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 101U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 102U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 103U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 104U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 105U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 106U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 107U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 108U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 109U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 110U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 111U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 112U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 113U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 114U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 115U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 116U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 117U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 118U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 119U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 120U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 121U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 122U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 123U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 124U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 125U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 126U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 127U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 128U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 129U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 130U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 131U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 132U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 133U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 134U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 135U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 136U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 137U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 138U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 139U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 140U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 141U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 142U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 143U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 144U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 145U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 146U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 147U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 148U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 149U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 150U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 151U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 152U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 153U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 154U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 155U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 156U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 157U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 158U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 159U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 160U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 161U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 162U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 163U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 164U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 165U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 166U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 167U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 168U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 169U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 170U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 171U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 172U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 173U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 174U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 175U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 176U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 177U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 178U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 179U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 180U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 181U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 182U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 183U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 184U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 185U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 186U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 187U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 188U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 189U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 190U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 191U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 192U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 193U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 194U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 195U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 196U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 197U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 198U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 199U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 200U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 201U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 202U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 203U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 204U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 205U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 206U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 207U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 208U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 209U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 210U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 211U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 212U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 213U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 214U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 215U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 216U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 217U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 218U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 219U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 220U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 221U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 222U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 223U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 224U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 225U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 226U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 227U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 228U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 229U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 230U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 231U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 232U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 233U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 234U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 235U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 236U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 237U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 238U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 239U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 240U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 241U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 242U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    243U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    244U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    245U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    246U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    247U, "Energy_based_PMSM_drive_model.Servomotor.torque_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 248U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 249U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 250U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 251U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 252U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 253U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 254U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 255U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 256U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 257U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 258U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 259U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 260U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 261U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 262U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 263U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 264U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 265U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 266U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 267U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 268U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 269U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 270U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 271U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 272U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 273U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 274U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 275U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 276U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 277U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 278U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 279U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 280U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 281U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 282U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 283U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 284U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 285U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 286U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 287U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 288U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 289U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 290U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 291U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 292U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 293U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 294U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 295U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 296U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 297U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of log10 must be positive.",
    "physmod:common:mf:core:asserts:RequireArgumentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 298U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 299U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 300U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 301U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 302U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 303U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 304U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 305U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 306U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 307U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 308U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 309U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 310U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 311U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 312U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 313U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 314U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 315U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 316U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 317U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 318U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 319U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 320U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 321U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 322U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 323U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 324U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 325U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 326U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 327U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 328U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 329U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 330U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 331U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 332U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 333U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 334U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 335U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 336U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 337U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 338U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 339U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 340U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 341U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 342U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Battery/Electrical model for Np  parallel-connected cells/Em_table",
    1U, 343U,
    "Battery.Electrical_model_for_Np_parallel_connected_cells.Em_table",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 344U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Local Restriction (TL)",
    1U, 345U, "Cooling_system.Expansion_tank.Local_Restriction_TL",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Expansion tank/Translational Mechanical Converter (TL)",
    1U, 346U,
    "Cooling_system.Expansion_tank.Translational_Mechanical_Converter_TL.translational_mechanical_converter_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 347U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 1", 1U, 348U,
    "Cooling_system.Hose_1.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Hose 2", 1U, 349U,
    "Cooling_system.Hose_2.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Pump", 1U, 350U,
    "Cooling_system.Pump",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 351U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Cooling system/Radiator/Hose 3", 1U, 352U,
    "Cooling_system.Radiator.Hose_3.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    353U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    354U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    355U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    356U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    357U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/DC-DC converter (averaged)/DC-DC Converter", 1U,
    358U, "DC_DC_converter_averaged.DC_DC_Converter",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Heat exchanger/Pipe through stator former",
    1U, 359U,
    "Energy_based_PMSM_drive_model.Heat_exchanger.Pipe_through_stator_former.pipe_model",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Energy-based PMSM drive model/Servomotor", 1U,
    360U, "Energy_based_PMSM_drive_model.Servomotor.current_calculation",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/u^2",
    1U, 361U, "Longitudinal_vehicle_dynamics.Aerodynamic_drag.u2",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/u^2",
    1U, 362U, "Longitudinal_vehicle_dynamics.Aerodynamic_drag.u2",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", }, {
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Aerodynamic drag/y=tanh(x)/tanh(x)",
    1U, 363U, "Longitudinal_vehicle_dynamics.Aerodynamic_drag.ytanhx.tanhx",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", }, {
    "shell_elec_electric_vehicle/Longitudinal vehicle dynamics/Braking torque/y=tanh(x)/tanh(x)",
    1U, 364U, "Longitudinal_vehicle_dynamics.Braking_torque.ytanhx.tanhx",
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    FALSE, "In divide, the denominator must be nonzero.",
    "physmod:common:mf:core:asserts:RequireDenominatorNonzero", } };

static NeRange s_assert_range[365] = { {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    46U, 12U, 46U, 13U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    131U, 16U, 131U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    132U, 16U, 132U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    133U, 16U, 133U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    134U, 16U, 134U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    135U, 16U, 135U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    136U, 16U, 136U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    137U, 16U, 137U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    138U, 16U, 138U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    109U, 16U, 109U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    110U, 16U, 110U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    111U, 16U, 111U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    112U, 16U, 112U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    113U, 16U, 113U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    114U, 16U, 114U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    115U, 16U, 115U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    116U, 16U, 116U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    135U, 16U, 135U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    131U, 16U, 131U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    132U, 16U, 132U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    133U, 16U, 133U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    134U, 16U, 134U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    135U, 16U, 135U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    136U, 16U, 136U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    137U, 16U, 137U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    138U, 16U, 138U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    143U, 16U, 143U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    144U, 16U, 144U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    145U, 16U, 145U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    146U, 16U, 146U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    147U, 16U, 147U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    148U, 16U, 148U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    149U, 16U, 149U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    150U, 16U, 150U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    151U, 16U, 151U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    152U, 16U, 152U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    153U, 16U, 153U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    154U, 16U, 154U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    91U, 12U, 91U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    46U, 12U, 46U, 13U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    194U, 16U, 194U, 80U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    194U, 16U, 194U, 80U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    194U, 16U, 194U, 80U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    194U, 16U, 194U, 80U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    120U, 38U, 120U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 28U, 121U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 51U, 142U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 47U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 91U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 34U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 33U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    138U, 88U, 138U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    117U, 38U, 117U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 28U, 118U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 51U, 141U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 47U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 91U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 34U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 33U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 76U, 146U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 106U, 146U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 100U, 146U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 60U, 146U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 76U, 149U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 106U, 149U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 100U, 149U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 60U, 149U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    107U, 34U, 107U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    107U, 27U, 107U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    107U, 27U, 107U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    125U, 23U, 125U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    125U, 40U, 125U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    74U, 19U, 74U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    76U, 23U, 76U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    108U, 34U, 108U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    108U, 27U, 108U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    108U, 27U, 108U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    126U, 23U, 126U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    126U, 40U, 126U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    125U, 40U, 125U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    126U, 40U, 126U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 34U, 118U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 34U, 119U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 27U, 119U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 27U, 119U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 36U, 124U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 48U, 124U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    125U, 36U, 125U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    125U, 48U, 125U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 36U, 126U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 48U, 126U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    127U, 36U, 127U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    127U, 48U, 127U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 23U, 136U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 40U, 136U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 23U, 137U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 40U, 137U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    117U, 38U, 117U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 28U, 118U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    120U, 38U, 120U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 28U, 121U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 36U, 127U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 26U, 127U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 52U, 127U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 42U, 127U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 36U, 130U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 26U, 130U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 52U, 130U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 42U, 130U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    133U, 77U, 133U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    134U, 77U, 134U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 51U, 141U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 47U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 91U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 34U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 33U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    137U, 88U, 137U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 51U, 142U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 47U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 91U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 34U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 33U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    138U, 88U, 138U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 76U, 146U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 106U, 146U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 100U, 146U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 60U, 146U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 76U, 149U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 106U, 149U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 100U, 149U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 60U, 149U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    74U, 19U, 74U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    76U, 23U, 76U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 34U, 118U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 36U, 124U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 48U, 124U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 36U, 126U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 48U, 126U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 23U, 136U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 40U, 136U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 40U, 137U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    95U, 40U, 95U, 41U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    79U, 16U, 79U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    95U, 51U, 95U, 52U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    95U, 44U, 95U, 50U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    95U, 35U, 95U, 52U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    117U, 38U, 117U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 28U, 118U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    120U, 38U, 120U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    99U, 69U, 99U, 108U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 28U, 121U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 36U, 127U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 26U, 127U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 52U, 127U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 42U, 127U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 36U, 130U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 26U, 130U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 52U, 130U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 42U, 130U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    133U, 77U, 133U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    134U, 77U, 134U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 51U, 141U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 47U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 91U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 34U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 33U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    137U, 88U, 137U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 51U, 142U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 47U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 91U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 34U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 33U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    91U, 34U, 91U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    91U, 27U, 91U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    91U, 27U, 91U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    138U, 88U, 138U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 76U, 146U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 106U, 146U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 100U, 146U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 60U, 146U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 76U, 149U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 106U, 149U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 100U, 149U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 60U, 149U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    96U, 36U, 96U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    96U, 48U, 96U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    74U, 19U, 74U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    76U, 23U, 76U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    97U, 36U, 97U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    97U, 48U, 97U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    104U, 23U, 104U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    104U, 40U, 104U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 34U, 118U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 34U, 119U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 27U, 119U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    119U, 27U, 119U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 36U, 124U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 48U, 124U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    125U, 36U, 125U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    125U, 48U, 125U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 36U, 126U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 48U, 126U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    127U, 36U, 127U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    127U, 48U, 127U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 23U, 136U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 40U, 136U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 23U, 137U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 40U, 137U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    117U, 38U, 117U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 28U, 118U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    118U, 22U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    120U, 38U, 120U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 28U, 121U, 29U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    121U, 22U, 121U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 36U, 127U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 26U, 127U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 52U, 127U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 42U, 127U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    113U, 36U, 113U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    113U, 48U, 113U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 36U, 130U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 26U, 130U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 52U, 130U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 42U, 130U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    133U, 77U, 133U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    134U, 77U, 134U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 51U, 141U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 47U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 91U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 34U, 141U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    141U, 33U, 141U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    137U, 88U, 137U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 51U, 142U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 47U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 91U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 34U, 142U, 87U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    142U, 33U, 142U, 92U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    138U, 88U, 138U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 76U, 146U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 106U, 146U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 100U, 146U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    146U, 60U, 146U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    114U, 36U, 114U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    114U, 48U, 114U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 76U, 149U, 95U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 106U, 149U, 109U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 100U, 149U, 104U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    149U, 60U, 149U, 114U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    74U, 19U, 74U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    76U, 23U, 76U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    115U, 36U, 115U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    115U, 48U, 115U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 34U, 118U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    118U, 27U, 118U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 36U, 124U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    124U, 48U, 124U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 36U, 126U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    126U, 48U, 126U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 23U, 136U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    136U, 40U, 136U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    137U, 40U, 137U, 45U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    116U, 36U, 116U, 46U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    116U, 48U, 116U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 36U, 127U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 26U, 127U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 52U, 127U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    127U, 42U, 127U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 36U, 130U, 37U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 26U, 130U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 52U, 130U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    130U, 42U, 130U, 51U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    133U, 77U, 133U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    134U, 77U, 134U, 100U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    137U, 88U, 137U, 111U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 16U, 79U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 16U, 79U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 16U, 79U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 16U, 79U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    84U, 23U, 84U, 24U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    147U, 15U, 147U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    148U, 15U, 148U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    124U, 15U, 124U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 15U, 163U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 15U, 164U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 15U, 163U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    51U, 40U, 51U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 15U, 163U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 15U, 164U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 15U, 163U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    42U, 16U, 42U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    42U, 14U, 42U, 15U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    21U, 15U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    21U, 15U, 21U, 17U, NE_RANGE_TYPE_NORMAL, } };

static NeAssertData *s_param_assert_data = NULL;
static NeRange *s_param_assert_range = NULL;
static NeRange s_equation_range[225] = { {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    64U, 13U, 64U, 23U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/C_table.ssc",
    64U, 22U, 64U, 27U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    73U, 12U, 73U, 23U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    74U, 13U, 74U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    74U, 16U, 74U, 24U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    76U, 13U, 76U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    76U, 16U, 76U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    45U, 5U, 45U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    45U, 27U, 45U, 32U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/spring.ssc",
    26U, 5U, 26U, 11U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/spring.ssc",
    26U, 10U, 26U, 15U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    147U, 9U, 147U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    147U, 16U, 147U, 49U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    160U, 9U, 160U, 53U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    160U, 31U, 160U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 9U, 79U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 9U, 86U, 14U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 11U, 86U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 9U, 79U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 9U, 86U, 14U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 11U, 86U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 9U, 79U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 9U, 86U, 14U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 11U, 86U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    79U, 9U, 79U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 9U, 86U, 14U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    86U, 11U, 86U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+rotational/inertia.ssc",
    36U, 5U, 36U, 21U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+rotational/inertia.ssc",
    36U, 20U, 36U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+linear/integrator.ssc",
    29U, 5U, 29U, 10U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+linear/integrator.ssc",
    29U, 7U, 29U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    45U, 5U, 45U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal/+elements/mass.ssc",
    45U, 27U, 45U, 32U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/angular_velocity.ssc",
    47U, 5U, 47U, 12U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/angular_velocity.ssc",
    47U, 9U, 47U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/angular_velocity.ssc",
    47U, 5U, 47U, 12U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/angular_velocity.ssc",
    47U, 9U, 47U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/velocity.ssc",
    48U, 5U, 48U, 10U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/velocity.ssc",
    48U, 7U, 48U, 15U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/mass.ssc",
    36U, 5U, 36U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/mass.ssc",
    36U, 17U, 36U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    80U, 9U, 81U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    84U, 9U, 84U, 24U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/Em_table.ssc",
    87U, 9U, 88U, 55U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    60U, 13U, 60U, 21U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    61U, 13U, 61U, 23U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    60U, 13U, 60U, 21U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/simscapedemos/+LiBatteryElements/R_table.ssc",
    61U, 13U, 61U, 23U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc",
    32U, 5U, 32U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/spring.ssc",
    27U, 5U, 27U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    65U, 15U, 65U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 9U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    66U, 15U, 66U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 9U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    120U, 19U, 120U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    147U, 9U, 147U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    122U, 19U, 122U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    148U, 9U, 148U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    120U, 19U, 120U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    151U, 9U, 151U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    122U, 19U, 122U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    152U, 9U, 152U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    65U, 15U, 65U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 9U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    66U, 15U, 66U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 9U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    75U, 15U, 75U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    76U, 15U, 76U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/local_restriction.ssc",
    102U, 9U, 102U, 65U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    58U, 15U, 58U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    119U, 9U, 119U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    101U, 19U, 101U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    124U, 9U, 124U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    101U, 19U, 101U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    127U, 9U, 127U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    58U, 15U, 58U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/one_port_horizontal.ssc",
    130U, 9U, 130U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    144U, 9U, 144U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    150U, 9U, 150U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    153U, 9U, 153U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    154U, 9U, 154U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/translational_converter.ssc",
    164U, 9U, 164U, 83U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 9U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 9U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 9U, 163U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 9U, 164U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    167U, 9U, 167U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    168U, 9U, 168U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 9U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 9U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    156U, 9U, 162U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    165U, 9U, 171U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    175U, 9U, 181U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    184U, 9U, 190U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 9U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 9U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 9U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 9U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 9U, 163U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 9U, 164U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    167U, 9U, 167U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    168U, 9U, 168U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 9U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 9U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    156U, 9U, 162U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    165U, 9U, 171U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    175U, 9U, 181U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    184U, 9U, 190U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 9U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 9U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    65U, 15U, 65U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    141U, 9U, 141U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    66U, 15U, 66U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    142U, 9U, 142U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    120U, 19U, 120U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    147U, 9U, 147U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    122U, 19U, 122U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    148U, 9U, 148U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    120U, 19U, 120U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    151U, 9U, 151U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    122U, 19U, 122U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    152U, 9U, 152U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    65U, 15U, 65U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    155U, 9U, 155U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    66U, 15U, 66U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_steady.ssc",
    156U, 9U, 156U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    41U, 15U, 41U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    42U, 15U, 42U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    45U, 16U, 45U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+sources/mass_flow_source.ssc",
    51U, 9U, 51U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 9U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 9U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 9U, 163U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 9U, 164U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    167U, 9U, 167U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    168U, 9U, 168U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 9U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 9U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    156U, 9U, 162U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    165U, 9U, 171U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    175U, 9U, 181U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    184U, 9U, 190U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 9U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 9U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/product.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+sources/dc_dc_converter.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/product.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    157U, 9U, 157U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    158U, 9U, 158U, 105U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    163U, 9U, 163U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    164U, 9U, 164U, 77U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    131U, 19U, 131U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    167U, 9U, 167U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    133U, 19U, 133U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    168U, 9U, 168U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    69U, 15U, 69U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    171U, 9U, 171U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    70U, 15U, 70U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/two_port_dynamic.ssc",
    172U, 9U, 172U, 101U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    156U, 9U, 162U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    165U, 9U, 171U, 82U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    175U, 9U, 181U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_base.ssc",
    184U, 9U, 190U, 68U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    89U, 9U, 89U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+thermal_liquid/+elements/pipe_resistive_compressibility.ssc",
    90U, 9U, 90U, 99U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+lookup_tables/one_dimensional.ssc",
    79U, 13U, 79U, 81U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_current_thermal.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+rotational/branch.ssc",
    23U, 5U, 23U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/elec/elec/+elec/+actuators/+rotational/controlled_servomotor_torque.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/product.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    42U, 9U, 42U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    34U, 9U, 34U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/product.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/math_function.ssc",
    34U, 9U, 34U, 19U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/divide.ssc",
    21U, 5U, 21U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2016b/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+translational/mass.ssc",
    37U, 5U, 37U, 13U, NE_RANGE_TYPE_NORMAL, } };

static NeParameterData *s_logical_parameter_data = NULL;
static NeParameterData *s_integer_parameter_data = NULL;
static NeParameterData *s_index_parameter_data = NULL;
static NeParameterData s_real_parameter_data[1] = { { "T_init", "", "", 0U, 1U,
    1U, } };

static real_T s_constant_table0[11] = { 273.16, 283.16, 293.16, 303.16, 313.16,
  323.16, 333.16, 343.16, 353.16, 363.16, 373.16 };

static real_T s_constant_table1[12] = { 0.1, 0.99999999999999989, 50.0, 100.0,
  150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0 };

static real_T s_constant_table2[132] = { 0.56104, 0.58002, 0.59844000000000008,
  0.61548, 0.6306, 0.020315000000000003, 0.020999, 0.021713000000000003,
  0.022454000000000002, 0.02322, 0.024010000000000004, 0.56109000000000009,
  0.58007000000000009, 0.59848, 0.61552, 0.63064, 0.64361, 0.65439, 0.66313,
  0.67002, 0.67527, 0.025079999999999998, 0.5638, 0.58245, 0.60073, 0.61773,
  0.63287, 0.64588, 0.65673, 0.66554, 0.67251, 0.67785000000000006, 0.68177,
  0.56656, 0.58488, 0.60303, 0.62, 0.63515, 0.64821000000000006, 0.65912, 0.668,
  0.67504999999999993, 0.68048000000000008, 0.6845, 0.56932, 0.58732000000000006,
  0.60533, 0.62226, 0.63744000000000012, 0.65052999999999994, 0.6615,
  0.67046000000000006, 0.67759, 0.68311, 0.68722, 0.57208, 0.58975, 0.60764,
  0.62454, 0.63972000000000007, 0.65286, 0.66389, 0.67291, 0.68012000000000006,
  0.68573000000000006, 0.68994000000000011, 0.57482000000000011,
  0.59217999999999993, 0.60994, 0.62681, 0.64201, 0.65518, 0.66627,
  0.67536000000000007, 0.68264, 0.68834000000000006, 0.69264,
  0.57753999999999994, 0.59461, 0.61224, 0.62907, 0.64429, 0.65751, 0.66865,
  0.6778, 0.68516, 0.69094000000000011, 0.69534000000000007, 0.58024, 0.59702,
  0.61454, 0.63134, 0.64657000000000009, 0.65982000000000007, 0.67102,
  0.68024000000000007, 0.68767, 0.69353, 0.69802, 0.58292, 0.59942, 0.61682,
  0.6336, 0.64884000000000008, 0.66214, 0.67338, 0.68267, 0.69017, 0.69611,
  0.70069, 0.58557, 0.6018, 0.6191, 0.63585, 0.65111000000000008, 0.66444,
  0.67574, 0.68509000000000009, 0.69265999999999994, 0.69868, 0.70335,
  0.58817999999999993, 0.60416, 0.62136, 0.63809, 0.65336, 0.66674,
  0.67809000000000008, 0.6875, 0.69514, 0.70124, 0.706 };

static real_T s_constant_table3[21] = { 19136.0, 46257.0, 233060.0, 107360.0,
  180360.0, 122510.0, 90229.0, 124470.0, 188720.0, 407640.0, 187210.0, 336300.0,
  183600.0, 233940.0, 306090.0, 329950.0, 475350.0, 263250.0, 482740.0, 268390.0,
  306060.0 };

static real_T s_constant_table4[21] = { 0.00117, 0.0010999999999999998, 0.00114,
  0.00107, 0.00107, 0.00113, 0.00116, 0.00085000000000000006,
  0.00085000000000000006, 0.0008699999999999999, 0.00082000000000000009, 0.00083,
  0.00085000000000000006, 0.00085000000000000006, 0.0009, 0.0009, 0.00092,
  0.00088, 0.00091, 0.00089, 0.00089 };

static real_T s_constant_table5[132] = { 0.00017407, 42.062, 83.953, 125.77,
  167.57, 2443.3, 2457.8, 2472.3, 2486.7, 2501.1, 2515.5, 0.0018426, 42.06,
  83.948, 125.76, 167.56, 209.36, 251.19, 293.06, 334.99, 377.0, 2506.2,
  0.086027, 41.935, 83.651, 125.31, 166.96, 208.63, 250.33, 292.07, 333.86,
  375.73, 417.69, 0.15883, 41.804, 83.349, 124.86, 166.37, 207.9, 249.47, 291.07,
  332.73, 374.46, 416.27, 0.21897, 41.668, 83.049, 124.41, 165.79, 207.19,
  248.62, 290.1, 331.63, 373.22, 414.89, 0.26699, 41.527, 82.749, 123.97, 165.21,
  206.48, 247.79, 289.14, 330.54, 372.0, 413.54, 0.30344, 41.382, 82.451, 123.53,
  164.65, 205.79, 246.98, 288.2, 329.48, 370.81, 412.21, 0.32881, 41.233, 82.153,
  123.1, 164.09, 205.11, 246.18, 287.28, 328.44, 369.64, 410.91, 0.34362, 41.081,
  81.856, 122.68, 163.54, 204.45, 245.39, 286.38, 327.41, 368.5, 409.64, 0.34835,
  40.924, 81.56, 122.25, 163.0, 203.79, 244.62, 285.49, 326.41, 367.38, 408.4,
  0.34347, 40.763, 81.265, 121.84, 162.46, 203.14, 243.86, 284.62, 325.43,
  366.27, 407.17, 0.32943, 40.599, 80.971, 121.42, 161.94, 202.5, 243.12, 283.77,
  324.46, 365.19, 405.98 };

static real_T s_constant_table6[132] = { 0.0017913416599999999, 0.001305655926,
  0.001001354112, 0.0007970554977, 0.0006525898957999999, 1.0520965620000002e-5,
  1.08703403e-5, 1.1225771370000003e-5, 1.1587472000000002e-5, 1.195519056e-5,
  1.23272185e-5, 0.001791113376, 0.00130550823, 0.00100139424,
  0.00079705765099999989, 0.00065260628330000012, 0.0005464201112000001,
  0.00046596323670000005, 0.00040349221920000003, 0.0003540000184,
  0.000314137579, 1.2234058200000002e-5, 0.0017803854900000002, 0.0013011972,
  0.000999859784, 0.00079697879040000006, 0.00065323823250000015,
  0.0005474198576, 0.00046714021200000013, 0.0004047714237,
  0.00035532373540000006, 0.0003154631565, 0.00028287671610000004,
  0.0017699551999999998, 0.00129708216, 0.00099853879500000028,
  0.00079696000000000009, 0.00065390986200000007, 0.00054844421,
  0.00046835702100000005, 0.0004060704384, 0.0003566632329,
  0.00031681742820000003, 0.0002842184188, 0.0017600552899999997,
  0.0012931061500000003, 0.00099726276, 0.00079702961600000013, 0.000654615075,
  0.0005494921851, 0.00046957509600000007, 0.00040736865800000005,
  0.0003579941728, 0.0003181614867, 0.00028555146150000004, 0.00175061786,
  0.0012894011000000002, 0.00099612261, 0.00079710286700000006, 0.00065537388,
  0.0005505529291, 0.000470799658, 0.00040868011560000003,
  0.00035933978010000003, 0.0003195018146, 0.00028688169219999996,
  0.0017417937600000002, 0.0012859690800000002, 0.000995119335, 0.00079732917,
  0.000656157354, 0.000551632164, 0.0004720355622, 0.0004099809954,
  0.00036066700050000006, 0.00032083508740000005, 0.0002882060972,
  0.0017332732499999999, 0.0012826856000000002, 0.000994253925,
  0.00079756053600000024, 0.000656913179, 0.00055274665200000012,
  0.00047328291840000004, 0.00041128946730000003, 0.00036199541400000007,
  0.00032217103220000005, 0.0002895343326, 0.00172537423, 0.00127970484,
  0.00099341922400000013, 0.00079785668700000007, 0.00065777240000000007,
  0.000553841345, 0.00047452709979999995, 0.000412603035, 0.000363332396,
  0.0003234998487, 0.0002908469214, 0.0017177596800000004, 0.0012768774000000002,
  0.00099272486600000018, 0.00079815950500000015, 0.00065862475,
  0.00055496613900000015, 0.00047578765760000004, 0.00041391435860000004,
  0.00036467061570000003, 0.0003248280896, 0.0002921534979,
  0.0017107060500000004, 0.0012743318200000003, 0.00099215144000000012,
  0.00079861715600000008, 0.00065951574000000014, 0.00055611114700000015,
  0.00047706470400000003, 0.00041523502280000008, 0.00036600017300000007,
  0.00032614579910000011, 0.0002934667819, 0.0017041151000000002,
  0.0012718434300000002, 0.000991720163, 0.000799072616, 0.00066045574000000008,
  0.00055729666300000015, 0.00047834831099999997, 0.00041656346120000012,
  0.00036732471450000005, 0.0003274727225, 0.00029476418200000007 };

static real_T s_constant_table7[132] = { 13.473696476247682, 9.4442940545722553,
  7.0014805341247239, 5.4132899297065222, 4.32534844352312, 0.99849479278168829,
  0.99090458604028753, 0.98670771701952764, 0.98354693528101889,
  0.98092287058191219, 0.97847617731361913, 13.469182802570709, 9.44151149977244,
  7.000791171233792, 5.4125642865378865, 4.3249757396042439, 3.5498926538751112,
  2.9799601851946087, 2.5495344015048631, 2.2173476571163842, 1.9562713391840296,
  1.0129683117272728, 13.249314296546652, 9.3312225679114089, 6.9389167171541271,
  5.3757653440170934, 4.3016264540012177, 3.5344805384336411, 2.9691603443278063,
  2.5419090743669051, 2.2117979229029756, 1.9520228127514934, 1.7445108362680231,
  13.035362658006211, 9.2238136367665167, 6.8789773577906583, 5.3393749161290325,
  4.2785461772803277, 3.5190588825102975, 2.9585679278971959, 2.5342929007329338,
  2.2062345924309756, 1.9478442780983127, 1.7412270843503286, 12.832216499915686,
  9.11990787735817, 6.820688802266532, 5.3044366482512135, 4.2560660090832068,
  3.5040864843571233, 2.9482075415074833, 2.5268692761542826, 2.2007773532643631,
  1.9437328284538506, 1.7380237088009665, 12.638183054467902, 9.0206697727681231,
  6.7645321866631578, 5.2702418879544943, 4.2345438560495214, 3.4895506243540724,
  2.938163164116947, 2.5197618279009677, 2.1955485152701728, 1.9397575642639517,
  1.7349119815277849, 12.454846546271876, 8.9258649557972234, 6.71086395490622,
  5.2378907855793626, 4.2135479561623645, 3.4755065932653628, 2.9284100932016748,
  2.5127847877564853, 2.1903979413349646, 1.9358986140674088, 1.7319245760792907,
  12.279427969837586, 8.83454803356822, 6.6593771564215007, 5.20626096464686,
  4.1928697729309778, 3.4619488488406263, 2.9189731955279443, 2.5060259235796258,
  2.1854133785825214, 1.9321682392542912, 1.7290280477007505, 12.11365906896112,
  8.7480007252822354, 6.6091621331792885, 5.1758194432115809, 4.1733759941228321,
  3.4486868389363767, 2.909733249138744, 2.499431562866782, 2.1806706676324397,
  1.9285540992461037, 1.7262395213146615, 11.954949642818914, 8.6647534487337765,
  6.5612994612833573, 5.1460880585156241, 4.1543179394766048, 3.4357880412038253,
  2.9008788604392168, 2.4930538322930258, 2.1760189469801787, 1.9250955792113313,
  1.723467558506115, 11.804943912495519, 8.5855406516949166, 6.5154109101340643,
  5.1181330670755676, 4.1359135469705581, 3.4234263809736016, 2.8923644979098473,
  2.4869613416528629, 2.1715045057615576, 1.9216405172254254, 1.720912407686856,
  11.662662660308071, 8.50920009335772, 6.471653979870605, 5.0909274645031264,
  4.1183462873974532, 3.4116178115919258, 2.8840998019324866, 2.4810216793827489,
  2.1671492348410397, 1.9183987565312872, 1.7183582774184141 };

static real_T s_constant_table8[132] = { 4219.9, 4195.5, 4184.3, 4180.1,
  4179.5999999999995, 1928.0, 1914.1999999999998, 1908.5, 1905.8999999999999,
  1905.2, 1905.8, 4219.4000000000005, 4195.1, 4184.0, 4179.8, 4179.4000000000005,
  4181.3, 4185.0, 4190.1, 4196.7999999999993, 4205.2, 2076.6, 4195.7000000000007,
  4176.9, 4169.0, 4166.7, 4167.5, 4170.2000000000007, 4174.2, 4179.5,
  4186.2000000000007, 4194.4, 4204.5, 4172.6, 4159.2, 4154.3, 4153.8, 4155.8,
  4159.2, 4163.5999999999995, 4169.0, 4175.7, 4183.7, 4193.5, 4150.8, 4142.2,
  4140.1, 4141.3, 4144.4, 4148.4, 4153.2, 4158.8, 4165.5, 4173.3, 4182.8, 4130.0,
  4125.9, 4126.4000000000005, 4129.3, 4133.4, 4138.0, 4143.2, 4148.9000000000005,
  4155.5, 4163.2, 4172.4, 4110.2999999999993, 4110.2999999999993, 4113.3, 4117.7,
  4122.7, 4127.9000000000005, 4133.4, 4139.3, 4145.8, 4153.4000000000005, 4162.3,
  4091.5999999999995, 4095.3999999999996, 4100.7, 4106.4, 4112.3, 4118.1, 4123.9,
  4129.9000000000005, 4136.4, 4143.7999999999993, 4152.4, 4073.8, 4081.2, 4088.5,
  4095.6, 4102.2999999999993, 4108.6, 4114.6, 4120.7, 4127.3, 4134.5, 4142.9,
  4056.8999999999996, 4067.5999999999995, 4076.8000000000006, 4085.1, 4092.6,
  4099.3, 4105.6, 4111.7999999999993, 4118.2999999999993, 4125.5, 4133.5,
  4040.7999999999997, 4054.5, 4065.6, 4075.0, 4083.2, 4090.3, 4096.9, 4103.2,
  4109.6, 4116.6, 4124.5, 4025.4, 4042.0999999999995, 4054.8, 4065.2999999999997,
  4074.0999999999995, 4081.6, 4088.4, 4094.6999999999994, 4101.2000000000007,
  4108.0, 4115.7000000000007 };

static real_T s_constant_table9[132] = { 19649.0, 20913.000000000004,
  21786.000000000004, 22332.0, 22600.000000000004, 0.099678000000000017,
  0.099733, 0.099774000000000015, 0.099805999999999992, 0.09983199999999999,
  0.099853000000000025, 19654.0, 20918.000000000007, 21791.0, 22337.000000000004,
  22605.0, 22638.000000000004, 22472.000000000004, 22140.0, 21668.000000000004,
  21081.000000000004, 0.98392, 19929.0, 21191.0, 22067.0, 22619.000000000004,
  22895.000000000004, 22936.0, 22779.000000000004, 22455.000000000004,
  21992.000000000004, 21413.000000000004, 20739.0, 20213.0, 21471.0,
  22350.000000000004, 22908.0, 23191.0, 23240.000000000004, 23092.0, 22776.0,
  22321.0, 21750.000000000004, 21084.0, 20499.0, 21752.000000000004,
  22634.000000000004, 23197.0, 23487.0, 23544.0, 23403.0, 23096.0,
  22649.000000000004, 22086.0, 21428.000000000004, 20787.0, 22036.000000000004,
  22919.0, 23487.0, 23784.0, 23848.000000000004, 23715.0, 23415.000000000004,
  22976.0, 22421.000000000004, 21770.0, 21078.000000000007, 22322.000000000004,
  23206.000000000004, 23778.0, 24081.0, 24151.000000000004, 24025.000000000004,
  23733.0, 23301.000000000004, 22754.000000000004, 22110.000000000004, 21372.0,
  22610.0, 23494.0, 24070.0, 24378.000000000004, 24455.0, 24336.000000000004,
  24050.000000000004, 23626.0, 23085.0, 22449.000000000004, 21668.000000000004,
  22899.000000000004, 23784.0, 24363.0, 24675.000000000004, 24758.0,
  24646.000000000004, 24367.0, 23949.000000000004, 23415.000000000004, 22786.0,
  21966.0, 23191.0, 24075.000000000004, 24657.0, 24973.0, 25062.000000000004,
  24955.000000000004, 24683.0, 24272.0, 23744.0, 23121.0, 22268.000000000004,
  23485.0, 24367.0, 24951.000000000004, 25272.0, 25365.000000000004,
  25264.000000000004, 24998.0, 24593.000000000004, 24072.0, 23455.000000000004,
  22572.0, 23781.000000000004, 24661.0, 25246.0, 25571.0, 25669.0, 25573.0,
  25313.000000000004, 24914.0, 24399.0, 23788.0 };

static real_T s_constant_table10[132] = { 6.7928585717143438e-5,
  -8.7846867935097937e-5, -0.00020678047607597982, -0.000303391890398851,
  -0.00038552868963988025, -0.003153536224558065, -0.0030462052784124894,
  -0.0029492912788584608, -0.0028600013014055182, -0.0027767552372665824,
  -0.0026990541702493548, 6.7582813250120015e-5, -8.8064419325797734e-5,
  -0.00020691244239631334, -0.00030346005122281931, -0.00038555346146481088,
  -0.00045784034897725778, -0.0005233169580650738, -0.0005840185730649649,
  -0.000641420897734055, -0.00069667460892986637, -0.0028984991096413126,
  4.9031228175197051e-5, -9.9753493013972046e-5, -0.0002140843662534986,
  -0.00030737006674550513, -0.00038695630311258607, -0.0004571988365516684,
  -0.00052092721146429575, -0.00058005327019828353, -0.000635984681253016,
  -0.00068978739677322677, -0.00074233575882493778, 3.0723527070063691e-5,
  -0.00011136997212266031, -0.00022125261793158469, -0.00031133,
  -0.00038842560536271592, -0.00045664617555174844, -0.00051862841402776794,
  -0.00057620560443141084, -0.00063067908253685331, -0.00068306213780445048,
  -0.00073418628560746883, 1.3029881862404449e-5, -0.00012269792390980433,
  -0.00022830132351477761, -0.00031524645779285569, -0.00038992640064086518,
  -0.00045617087175567908, -0.00051647130153597415, -0.00057254475625368307,
  -0.00062561072837663794, -0.00067664276381444244, -0.00072640619981558018,
  -4.0641774784589477e-6, -0.0001337264618434093, -0.00023520007943600435,
  -0.00031913770785621829, -0.00039143685051958434, -0.00045578156202021015,
  -0.00051444993445598464, -0.00056905326763590641, -0.00062076104804740487,
  -0.00067048184113818819, -0.00071893573695254443, -2.0575973127840345e-5,
  -0.0001444576287946208, -0.000241959774100862, -0.00032294088425235967,
  -0.00039298035696480214, -0.00045546309370024334, -0.00051253798627462813,
  -0.00056572544337990559, -0.00061612440337468577, -0.00066457381649835093,
  -0.0007117796295532361, -3.6524396254312469e-5, -0.00015491859891465223,
  -0.00024858131487889271, -0.00032673012095974619, -0.00039457657478356053,
  -0.00045519136604376938, -0.0005107346561696658, -0.00056253849027268791,
  -0.00061167868386310551, -0.00065891647163428626, -0.00070490420036632283,
  -5.1918576064509781e-5, -0.00016507186454026382, -0.00025507103393843724,
  -0.00033045414069456807, -0.00039612711022840114, -0.00045502144210631288,
  -0.00050903424293745672, -0.00055950833711148045, -0.00060740995966679508,
  -0.00065347705926144988, -0.0006983069293715412, -6.6779827315541587e-5,
  -0.000174950884086444, -0.00026141577237373239, -0.00033414634146341463,
  -0.00039772051536174428, -0.00045488205434458042, -0.00050742581683985242,
  -0.000556606808904261, -0.00060330896109543608, -0.00064824049009830462,
  -0.00069196488028767846, -8.1117963778756742e-5, -0.00018455204861791803,
  -0.00026760660247592851, -0.00033774142688214429, -0.000399297725024728,
  -0.0004547928876527268, -0.00050590877333067175, -0.00055383411266531535,
  -0.0005993843669576625, -0.00064321475358227289, -0.00068585857553236083,
  -9.494627857003322e-5, -0.00019388633473540058, -0.00027364447494852438,
  -0.00034130605822187257, -0.00040086870681145108, -0.00045472390205214623,
  -0.00050445263472457418, -0.00055116817048379168, -0.00059559852948582359,
  -0.00063836838104889789, -0.00067997266031461043 };

static real_T s_constant_table11[21] = { 0.00109, 0.00069,
  0.00047000000000000004, 0.00033999999999999997, 0.00033, 0.00033, 0.00028,
  0.00029, 0.00023999999999999998, 0.00026, 0.00016, 0.00023,
  0.00017999999999999998, 0.00016999999999999999, 0.00013,
  0.00011999999999999999, 0.00013, 0.0001, 0.00014, 0.00011, 0.00011 };

static real_T s_constant_table12[21] = { 3.4966, 3.5519, 3.6183, 3.7066, 3.9131,
  4.0748, 4.1923, 3.5057, 3.566, 3.6337, 3.7127, 3.9259, 4.0777, 4.1928, 3.5148,
  3.5653, 3.6402, 3.7213, 3.9376, 4.0821, 4.193 };

static real_T s_constant_table13[132] = { 999.8, 999.66, 998.16, 995.61, 992.17,
  0.067261, 0.065209, 0.063283, 0.061472, 0.059764, 0.05815, 999.84, 999.7,
  998.2, 995.65, 992.21, 988.03, 983.19, 977.76, 971.78, 965.3, 0.58965, 1002.3,
  1002.0, 1000.4, 997.82, 994.35, 990.16, 985.32, 979.91, 973.97, 967.53, 960.63,
  1004.8, 1004.4, 1002.7, 1000.0, 996.51, 992.3, 987.47, 982.08, 976.17, 969.78,
  962.93, 1007.3, 1006.7, 1004.9, 1002.2, 998.65, 994.43, 989.6, 984.22, 978.34,
  971.99, 965.19, 1009.7, 1009.0, 1007.1, 1004.3, 1000.8, 996.53, 991.7, 986.34,
  980.49, 974.18, 967.43, 1012.2, 1011.3, 1009.3, 1006.5, 1002.9, 998.61, 993.78,
  988.43, 982.61, 976.34, 969.64, 1014.5, 1013.5, 1011.5, 1008.6, 1004.9, 1000.7,
  995.84, 990.51, 984.7, 978.47, 971.82, 1016.9, 1015.8, 1013.6, 1010.7, 1007.0,
  1002.7, 997.87, 992.55, 986.78, 980.57, 973.97, 1019.2, 1018.0, 1015.7, 1012.7,
  1009.0, 1004.7, 999.89, 994.58, 988.83, 982.66, 976.09, 1021.5, 1020.2, 1017.8,
  1014.8, 1011.0, 1006.7, 1001.9, 996.58, 990.85, 984.71, 978.19, 1023.8, 1022.3,
  1019.9, 1016.8, 1013.0, 1008.7, 1003.9, 998.57, 992.85, 986.75, 980.26 };

static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM_P.mNumCol = 130;
  out->mM_P.mNumRow = 130;
  out->mM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    30);
  return out;
}

static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM.mN = 30;
  out->mM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 30);
  return out;
}

static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMM.mN = 30;
  out->mVMM.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    30);
  return out;
}

static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM_P.mNumCol = 130;
  out->mDXM_P.mNumRow = 30;
  out->mDXM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mDXM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    58);
  return out;
}

static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM.mN = 58;
  out->mDXM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 58);
  return out;
}

static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM_P.mNumCol = 5;
  out->mDUM_P.mNumRow = 30;
  out->mDUM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mDUM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM.mN = 0;
  out->mDUM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM_P.mNumCol = 1;
  out->mDTM_P.mNumRow = 30;
  out->mDTM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM.mN = 0;
  out->mDTM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA_P.mNumCol = 130;
  out->mA_P.mNumRow = 130;
  out->mA_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mA_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    162);
  return out;
}

static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA.mN = 162;
  out->mA.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 162);
  return out;
}

static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB_P.mNumCol = 5;
  out->mB_P.mNumRow = 130;
  out->mB_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mB_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    3);
  return out;
}

static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB.mN = 3;
  out->mB.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 3);
  return out;
}

static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC_P.mNumCol = 1;
  out->mC_P.mNumRow = 130;
  out->mC_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mC_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC.mN = 0;
  out->mC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mF.mN = 130;
  out->mF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 130);
  return out;
}

static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMF.mN = 130;
  out->mVMF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    130);
  return out;
}

static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF.mN = 130;
  out->mSLF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    130);
  return out;
}

static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF_P.mNumCol = 130;
  out->mDXF_P.mNumRow = 130;
  out->mDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    300);
  return out;
}

static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF.mN = 300;
  out->mDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 300);
  return out;
}

static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF_P.mNumCol = 5;
  out->mDUF_P.mNumRow = 130;
  out->mDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF.mN = 4;
  out->mDUF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF_P.mNumCol = 1;
  out->mDTF_P.mNumRow = 130;
  out->mDTF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF.mN = 0;
  out->mDTF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF_P.mNumCol = 0;
  out->mDDF_P.mNumRow = 130;
  out->mDDF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF.mN = 0;
  out->mDDF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUF_P.mNumCol = 5;
  out->mTDUF_P.mNumRow = 130;
  out->mTDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mTDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    7);
  return out;
}

static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXF_P.mNumCol = 130;
  out->mTDXF_P.mNumRow = 130;
  out->mTDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mTDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    480);
  return out;
}

static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIC.mN = 130;
  out->mIC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 130);
  return out;
}

static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR.mN = 0;
  out->mICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IM.mN = 0;
  out->mICR_IM.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_ID.mN = 0;
  out->mICR_ID.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR.mN = 0;
  out->mDXICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR_P.mNumCol = 130;
  out->mDXICR_P.mNumRow = 0;
  out->mDXICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 131);
  out->mDXICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUICR_P.mNumCol = 5;
  out->mTDUICR_P.mNumRow = 0;
  out->mTDUICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 6);
  out->mTDUICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDUY_P.mNumCol = 5;
  out->mMDUY_P.mNumRow = 6;
  out->mMDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mMDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDXY_P.mNumCol = 130;
  out->mMDXY_P.mNumRow = 6;
  out->mMDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mMDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUY_P.mNumCol = 5;
  out->mTDUY_P.mNumRow = 6;
  out->mTDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mTDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXY_P.mNumCol = 130;
  out->mTDXY_P.mNumRow = 6;
  out->mTDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mTDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mY.mN = 6;
  out->mY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY_P.mNumCol = 130;
  out->mDXY_P.mNumRow = 6;
  out->mDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY.mN = 6;
  out->mDXY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY_P.mNumCol = 5;
  out->mDUY_P.mNumRow = 6;
  out->mDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY.mN = 0;
  out->mDUY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY_P.mNumCol = 1;
  out->mDTY_P.mNumRow = 6;
  out->mDTY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY.mN = 0;
  out->mDTY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMODE.mN = 144;
  out->mMODE.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    144);
  return out;
}

static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mZC.mN = 146;
  out->mZC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 146);
  return out;
}

static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_R.mN = 0;
  out->mCACHE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_I.mN = 0;
  out->mCACHE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_R.mN = 0;
  out->mUPDATE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_I.mN = 0;
  out->mUPDATE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFO.mN = 0;
  out->mSFO.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFP.mN = 0;
  out->mSFP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_R.mN = 0;
  out->mINIT_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_I.mN = 0;
  out->mINIT_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOG.mN = 524;
  out->mLOG.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 524);
  return out;
}

static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mASSERT.mN = 365;
  out->mASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    365);
  return out;
}

static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mPASSERT.mN = 0;
  out->mPASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_T.mN = 0;
  out->mDEL_T.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V.mN = 0;
  out->mDEL_V.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V0.mN = 0;
  out->mDEL_V0.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_TMAX.mN = 0;
  out->mDEL_TMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT_P.mNumCol = 130;
  out->mDXDELT_P.mNumRow = 0;
  out->mDXDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 131);
  out->mDXDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT.mN = 0;
  out->mDXDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT_P.mNumCol = 5;
  out->mDUDELT_P.mNumRow = 0;
  out->mDUDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 6);
  out->mDUDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT.mN = 0;
  out->mDUDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT_P.mNumCol = 1;
  out->mDTDELT_P.mNumRow = 0;
  out->mDTDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 2);
  out->mDTDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT.mN = 0;
  out->mDTDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_EXP.mN = 524;
  out->mOBS_EXP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    524);
  return out;
}

static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ACT.mN = 524;
  out->mOBS_ACT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    524);
  return out;
}

static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ALL.mN = 565;
  out->mOBS_ALL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    565);
  return out;
}

static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_L.mN = 0;
  out->mDP_L.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_I.mN = 0;
  out->mDP_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_J.mN = 0;
  out->mDP_J.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_R.mN = 1;
  out->mDP_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX.mN = 52;
  out->mQX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 52);
  return out;
}

static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU.mN = 6;
  out->mQU.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT.mN = 0;
  out->mQT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1.mN = 26;
  out->mQ1.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 26);
  return out;
}

static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX_P.mNumCol = 130;
  out->mQX_P.mNumRow = 130;
  out->mQX_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    131);
  out->mQX_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    52);
  return out;
}

static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU_P.mNumCol = 5;
  out->mQU_P.mNumRow = 130;
  out->mQU_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  out->mQU_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT_P.mNumCol = 1;
  out->mQT_P.mNumRow = 130;
  out->mQT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1_P.mNumCol = 1;
  out->mQ1_P.mNumRow = 130;
  out->mQ1_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQ1_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    26);
  return out;
}

static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVAR_TOL.mN = 130;
  out->mVAR_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    130);
  return out;
}

static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mEQ_TOL.mN = 130;
  out->mEQ_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    130);
  return out;
}

static void release_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  if (--_ds->mRefCnt == 0) {
    _ds->mAlloc.mFreeFcn(&_ds->mAlloc, _ds);
  }
}

static void get_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  ++_ds->mRefCnt;
}

static NeDynamicSystem *diagnostics(const NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds = (_NeDynamicSystem *)ds;
  ne_ds_get_reference(&_ds->mBase);
  return &_ds->mBase;
}

static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out)
{
  (void)ds;
  memcpy(out->mX, in->mX.mX, sizeof(real_T)*out->mN);
}

NeDynamicSystem *shell_elec_electric_vehicle_442b803b_1_dae_ds(PmAllocator
  *allocator)
{
  NeDynamicSystem *ds;
  _NeDynamicSystem *_ds;
  static NeDsIoInfo input_info[5];
  static NeDsIoInfo output_info[6];

  /* allocate dynamic system data and extended data */
  _ds = (_NeDynamicSystem *)allocator->mCallocFcn( allocator, sizeof
    (_NeDynamicSystem), 1);
  _ds->mAlloc = *allocator;
  _ds->mRefCnt = 1;
  ds = &_ds->mBase;

  /* setup sizes */
  ds->mNumVariables = 130;
  ds->mNumDiscreteRealVariables = 0;
  ds->mNumDifferentialVariables = 22;
  ds->mNumEquations = 130;
  ds->mNumICResiduals = 0;
  ds->mNumModes = 144;
  ds->mNumMajorModes = 0;
  ds->mNumRealCache = 0;
  ds->mNumIntCache = 0;
  ds->mNumObservables = 524;
  ds->mNumObservableElements = 524;
  ds->mNumZcs = 146;
  ds->mNumAsserts = 365;
  ds->mNumAssertRanges = 365;
  ds->mNumParamAsserts = 0;
  ds->mNumParamAssertRanges = 0;
  ds->mNumRanges = 456;
  ds->mNumEquationRanges = 225;
  ds->mNumFundamentalSamples = 0;
  ds->mNumDelays = 0;
  ds->mNumLogicalParameters = 0;
  ds->mNumIntegerParameters = 0;
  ds->mNumIndexParameters = 0;
  ds->mNumRealParameters = 1;
  ds->mNumLogicalDerivedParameters = 0;
  ds->mNumIntegerDerivedParameters = 0;
  ds->mNumIndexDerivedParameters = 0;
  ds->mNumRealDerivedParameters = 1;
  ds->mIsOutputLinear = TRUE;
  ds->mIsOutputSwitchedLinear = TRUE;

  /* setup ios */
  ds->mNumIo[NE_INPUT_IO_TYPE] = 5;
  input_info[0].mIdentifier = "Ambient_temperature.S";
  input_info[0].mM = 1;
  input_info[0].mN = 1;
  input_info[0].mName = "Ambient_temperature.S";
  input_info[0].mUnit = "K";
  input_info[1].mIdentifier = "Energy_based_PMSM_drive_model.Servomotor.Tr";
  input_info[1].mM = 1;
  input_info[1].mN = 1;
  input_info[1].mName = "Energy_based_PMSM_drive_model.Servomotor.Tr";
  input_info[1].mUnit = "N*m";
  input_info[2].mIdentifier =
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Subtract.I2";
  input_info[2].mM = 1;
  input_info[2].mN = 1;
  input_info[2].mName =
    "Longitudinal_vehicle_dynamics.Aerodynamic_drag.PS_Subtract.I2";
  input_info[2].mUnit = "1";
  input_info[3].mIdentifier =
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.I1";
  input_info[3].mM = 1;
  input_info[3].mN = 1;
  input_info[3].mName =
    "Longitudinal_vehicle_dynamics.Braking_torque.PS_Product.I1";
  input_info[3].mUnit = "1";
  input_info[4].mIdentifier = "Longitudinal_vehicle_dynamics.PS_Subtract1.I1";
  input_info[4].mM = 1;
  input_info[4].mN = 1;
  input_info[4].mName = "Longitudinal_vehicle_dynamics.PS_Subtract1.I1";
  input_info[4].mUnit = "1";
  ds->mIo[NE_INPUT_IO_TYPE] = input_info;
  ds->mNumIo[NE_OUTPUT_IO_TYPE] = 6;
  output_info[0].mIdentifier =
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.I";
  output_info[0].mM = 1;
  output_info[0].mN = 1;
  output_info[0].mName =
    "DC_DC_converter_averaged.Battery_sensors.Current_Sensor.I";
  output_info[0].mUnit = "A";
  output_info[1].mIdentifier =
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.V";
  output_info[1].mM = 1;
  output_info[1].mN = 1;
  output_info[1].mName =
    "DC_DC_converter_averaged.Battery_sensors.Voltage_Sensor.V";
  output_info[1].mUnit = "V";
  output_info[2].mIdentifier =
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.T";
  output_info[2].mM = 1;
  output_info[2].mN = 1;
  output_info[2].mName =
    "Energy_based_PMSM_drive_model.Heat_exchanger.Ideal_Temperature_Sensor.T";
  output_info[2].mUnit = "K";
  output_info[3].mIdentifier = "Energy_based_PMSM_drive_model.Servomotor.Omega";
  output_info[3].mM = 1;
  output_info[3].mN = 1;
  output_info[3].mName = "Energy_based_PMSM_drive_model.Servomotor.Omega";
  output_info[3].mUnit = "rad/s";
  output_info[4].mIdentifier =
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.T";
  output_info[4].mM = 1;
  output_info[4].mN = 1;
  output_info[4].mName =
    "Energy_based_PMSM_drive_model.Torque_sensor.Ideal_Torque_Sensor.T";
  output_info[4].mUnit = "N*m";
  output_info[5].mIdentifier =
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.V";
  output_info[5].mM = 1;
  output_info[5].mN = 1;
  output_info[5].mName =
    "Longitudinal_vehicle_dynamics.Measurement.Ideal_Translational_Motion_Sensor.V";
  output_info[5].mUnit = "m/s";
  ds->mIo[NE_OUTPUT_IO_TYPE] = output_info;

  /* setup administration methods */
  ds->mReleaseReference = release_reference;
  ds->mGetReference = get_reference;
  ds->mDiagnosticsDsFcn = diagnostics;
  ds->mExpandFcn = expand;
  ds->mMethods[NE_DS_METHOD_M_P] = shell_elec_electric_vehicle_442b803b_1_ds_m_p;
  ds->mMakeOutput[NE_DS_METHOD_M_P] = ds_output_m_p;
  ds->mMethods[NE_DS_METHOD_M] = shell_elec_electric_vehicle_442b803b_1_ds_m;
  ds->mMakeOutput[NE_DS_METHOD_M] = ds_output_m;
  ds->mMethods[NE_DS_METHOD_VMM] = ds_vmm;
  ds->mMakeOutput[NE_DS_METHOD_VMM] = ds_output_vmm;
  ds->mMethods[NE_DS_METHOD_DXM_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_dxm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXM_P] = ds_output_dxm_p;
  ds->mMethods[NE_DS_METHOD_DXM] = shell_elec_electric_vehicle_442b803b_1_ds_dxm;
  ds->mMakeOutput[NE_DS_METHOD_DXM] = ds_output_dxm;
  ds->mMethods[NE_DS_METHOD_DUM_P] = ds_dum_p;
  ds->mMakeOutput[NE_DS_METHOD_DUM_P] = ds_output_dum_p;
  ds->mMethods[NE_DS_METHOD_DUM] = ds_dum;
  ds->mMakeOutput[NE_DS_METHOD_DUM] = ds_output_dum;
  ds->mMethods[NE_DS_METHOD_DTM_P] = ds_dtm_p;
  ds->mMakeOutput[NE_DS_METHOD_DTM_P] = ds_output_dtm_p;
  ds->mMethods[NE_DS_METHOD_DTM] = ds_dtm;
  ds->mMakeOutput[NE_DS_METHOD_DTM] = ds_output_dtm;
  ds->mMethods[NE_DS_METHOD_A_P] = shell_elec_electric_vehicle_442b803b_1_ds_a_p;
  ds->mMakeOutput[NE_DS_METHOD_A_P] = ds_output_a_p;
  ds->mMethods[NE_DS_METHOD_A] = shell_elec_electric_vehicle_442b803b_1_ds_a;
  ds->mMakeOutput[NE_DS_METHOD_A] = ds_output_a;
  ds->mMethods[NE_DS_METHOD_B_P] = ds_b_p;
  ds->mMakeOutput[NE_DS_METHOD_B_P] = ds_output_b_p;
  ds->mMethods[NE_DS_METHOD_B] = ds_b;
  ds->mMakeOutput[NE_DS_METHOD_B] = ds_output_b;
  ds->mMethods[NE_DS_METHOD_C_P] = ds_c_p;
  ds->mMakeOutput[NE_DS_METHOD_C_P] = ds_output_c_p;
  ds->mMethods[NE_DS_METHOD_C] = ds_c;
  ds->mMakeOutput[NE_DS_METHOD_C] = ds_output_c;
  ds->mMethods[NE_DS_METHOD_F] = shell_elec_electric_vehicle_442b803b_1_ds_f;
  ds->mMakeOutput[NE_DS_METHOD_F] = ds_output_f;
  ds->mMethods[NE_DS_METHOD_VMF] = shell_elec_electric_vehicle_442b803b_1_ds_vmf;
  ds->mMakeOutput[NE_DS_METHOD_VMF] = ds_output_vmf;
  ds->mMethods[NE_DS_METHOD_SLF] = shell_elec_electric_vehicle_442b803b_1_ds_slf;
  ds->mMakeOutput[NE_DS_METHOD_SLF] = ds_output_slf;
  ds->mMethods[NE_DS_METHOD_DXF_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_dxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DXF_P] = ds_output_dxf_p;
  ds->mMethods[NE_DS_METHOD_DXF] = shell_elec_electric_vehicle_442b803b_1_ds_dxf;
  ds->mMakeOutput[NE_DS_METHOD_DXF] = ds_output_dxf;
  ds->mMethods[NE_DS_METHOD_DUF_P] = ds_duf_p;
  ds->mMakeOutput[NE_DS_METHOD_DUF_P] = ds_output_duf_p;
  ds->mMethods[NE_DS_METHOD_DUF] = ds_duf;
  ds->mMakeOutput[NE_DS_METHOD_DUF] = ds_output_duf;
  ds->mMethods[NE_DS_METHOD_DTF_P] = ds_dtf_p;
  ds->mMakeOutput[NE_DS_METHOD_DTF_P] = ds_output_dtf_p;
  ds->mMethods[NE_DS_METHOD_DTF] = ds_dtf;
  ds->mMakeOutput[NE_DS_METHOD_DTF] = ds_output_dtf;
  ds->mMethods[NE_DS_METHOD_DDF_P] = ds_ddf_p;
  ds->mMakeOutput[NE_DS_METHOD_DDF_P] = ds_output_ddf_p;
  ds->mMethods[NE_DS_METHOD_DDF] = ds_ddf;
  ds->mMakeOutput[NE_DS_METHOD_DDF] = ds_output_ddf;
  ds->mMethods[NE_DS_METHOD_TDUF_P] = ds_tduf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUF_P] = ds_output_tduf_p;
  ds->mMethods[NE_DS_METHOD_TDXF_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_tdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXF_P] = ds_output_tdxf_p;
  ds->mMethods[NE_DS_METHOD_IC] = shell_elec_electric_vehicle_442b803b_1_ds_ic;
  ds->mMakeOutput[NE_DS_METHOD_IC] = ds_output_ic;
  ds->mMethods[NE_DS_METHOD_ICR] = ds_icr;
  ds->mMakeOutput[NE_DS_METHOD_ICR] = ds_output_icr;
  ds->mMethods[NE_DS_METHOD_ICR_IM] = ds_icr_im;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IM] = ds_output_icr_im;
  ds->mMethods[NE_DS_METHOD_ICR_ID] = ds_icr_id;
  ds->mMakeOutput[NE_DS_METHOD_ICR_ID] = ds_output_icr_id;
  ds->mMethods[NE_DS_METHOD_DXICR] = ds_dxicr;
  ds->mMakeOutput[NE_DS_METHOD_DXICR] = ds_output_dxicr;
  ds->mMethods[NE_DS_METHOD_DXICR_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_dxicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICR_P] = ds_output_dxicr_p;
  ds->mMethods[NE_DS_METHOD_TDUICR_P] = ds_tduicr_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUICR_P] = ds_output_tduicr_p;
  ds->mMethods[NE_DS_METHOD_MDUY_P] = ds_mduy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDUY_P] = ds_output_mduy_p;
  ds->mMethods[NE_DS_METHOD_MDXY_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_mdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDXY_P] = ds_output_mdxy_p;
  ds->mMethods[NE_DS_METHOD_TDUY_P] = ds_tduy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUY_P] = ds_output_tduy_p;
  ds->mMethods[NE_DS_METHOD_TDXY_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_tdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXY_P] = ds_output_tdxy_p;
  ds->mMethods[NE_DS_METHOD_Y] = ds_y;
  ds->mMakeOutput[NE_DS_METHOD_Y] = ds_output_y;
  ds->mMethods[NE_DS_METHOD_DXY_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_dxy_p;
  ds->mMakeOutput[NE_DS_METHOD_DXY_P] = ds_output_dxy_p;
  ds->mMethods[NE_DS_METHOD_DXY] = ds_dxy;
  ds->mMakeOutput[NE_DS_METHOD_DXY] = ds_output_dxy;
  ds->mMethods[NE_DS_METHOD_DUY_P] = ds_duy_p;
  ds->mMakeOutput[NE_DS_METHOD_DUY_P] = ds_output_duy_p;
  ds->mMethods[NE_DS_METHOD_DUY] = ds_duy;
  ds->mMakeOutput[NE_DS_METHOD_DUY] = ds_output_duy;
  ds->mMethods[NE_DS_METHOD_DTY_P] = ds_dty_p;
  ds->mMakeOutput[NE_DS_METHOD_DTY_P] = ds_output_dty_p;
  ds->mMethods[NE_DS_METHOD_DTY] = ds_dty;
  ds->mMakeOutput[NE_DS_METHOD_DTY] = ds_output_dty;
  ds->mMethods[NE_DS_METHOD_MODE] =
    shell_elec_electric_vehicle_442b803b_1_ds_mode;
  ds->mMakeOutput[NE_DS_METHOD_MODE] = ds_output_mode;
  ds->mMethods[NE_DS_METHOD_ZC] = shell_elec_electric_vehicle_442b803b_1_ds_zc;
  ds->mMakeOutput[NE_DS_METHOD_ZC] = ds_output_zc;
  ds->mMethods[NE_DS_METHOD_CACHE_R] = ds_cache_r;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_R] = ds_output_cache_r;
  ds->mMethods[NE_DS_METHOD_CACHE_I] = ds_cache_i;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_I] = ds_output_cache_i;
  ds->mMethods[NE_DS_METHOD_UPDATE_R] = ds_update_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_R] = ds_output_update_r;
  ds->mMethods[NE_DS_METHOD_UPDATE_I] = ds_update_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_I] = ds_output_update_i;
  ds->mMethods[NE_DS_METHOD_SFO] = ds_sfo;
  ds->mMakeOutput[NE_DS_METHOD_SFO] = ds_output_sfo;
  ds->mMethods[NE_DS_METHOD_SFP] = ds_sfp;
  ds->mMakeOutput[NE_DS_METHOD_SFP] = ds_output_sfp;
  ds->mMethods[NE_DS_METHOD_INIT_R] = ds_init_r;
  ds->mMakeOutput[NE_DS_METHOD_INIT_R] = ds_output_init_r;
  ds->mMethods[NE_DS_METHOD_INIT_I] = ds_init_i;
  ds->mMakeOutput[NE_DS_METHOD_INIT_I] = ds_output_init_i;
  ds->mMethods[NE_DS_METHOD_LOG] = shell_elec_electric_vehicle_442b803b_1_ds_log;
  ds->mMakeOutput[NE_DS_METHOD_LOG] = ds_output_log;
  ds->mMethods[NE_DS_METHOD_ASSERT] =
    shell_elec_electric_vehicle_442b803b_1_ds_assert;
  ds->mMakeOutput[NE_DS_METHOD_ASSERT] = ds_output_assert;
  ds->mMethods[NE_DS_METHOD_PASSERT] = ds_passert;
  ds->mMakeOutput[NE_DS_METHOD_PASSERT] = ds_output_passert;
  ds->mMethods[NE_DS_METHOD_DEL_T] = ds_del_t;
  ds->mMakeOutput[NE_DS_METHOD_DEL_T] = ds_output_del_t;
  ds->mMethods[NE_DS_METHOD_DEL_V] = ds_del_v;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V] = ds_output_del_v;
  ds->mMethods[NE_DS_METHOD_DEL_V0] = ds_del_v0;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V0] = ds_output_del_v0;
  ds->mMethods[NE_DS_METHOD_DEL_TMAX] = ds_del_tmax;
  ds->mMakeOutput[NE_DS_METHOD_DEL_TMAX] = ds_output_del_tmax;
  ds->mMethods[NE_DS_METHOD_DXDELT_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_dxdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT_P] = ds_output_dxdelt_p;
  ds->mMethods[NE_DS_METHOD_DXDELT] = ds_dxdelt;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT] = ds_output_dxdelt;
  ds->mMethods[NE_DS_METHOD_DUDELT_P] = ds_dudelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT_P] = ds_output_dudelt_p;
  ds->mMethods[NE_DS_METHOD_DUDELT] = ds_dudelt;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT] = ds_output_dudelt;
  ds->mMethods[NE_DS_METHOD_DTDELT_P] = ds_dtdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT_P] = ds_output_dtdelt_p;
  ds->mMethods[NE_DS_METHOD_DTDELT] = ds_dtdelt;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT] = ds_output_dtdelt;
  ds->mMethods[NE_DS_METHOD_OBS_EXP] =
    shell_elec_electric_vehicle_442b803b_1_ds_obs_exp;
  ds->mMakeOutput[NE_DS_METHOD_OBS_EXP] = ds_output_obs_exp;
  ds->mMethods[NE_DS_METHOD_OBS_ACT] =
    shell_elec_electric_vehicle_442b803b_1_ds_obs_act;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ACT] = ds_output_obs_act;
  ds->mMethods[NE_DS_METHOD_OBS_ALL] =
    shell_elec_electric_vehicle_442b803b_1_ds_obs_all;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ALL] = ds_output_obs_all;
  ds->mMethods[NE_DS_METHOD_DP_L] = ds_dp_l;
  ds->mMakeOutput[NE_DS_METHOD_DP_L] = ds_output_dp_l;
  ds->mMethods[NE_DS_METHOD_DP_I] = ds_dp_i;
  ds->mMakeOutput[NE_DS_METHOD_DP_I] = ds_output_dp_i;
  ds->mMethods[NE_DS_METHOD_DP_J] = ds_dp_j;
  ds->mMakeOutput[NE_DS_METHOD_DP_J] = ds_output_dp_j;
  ds->mMethods[NE_DS_METHOD_DP_R] = ds_dp_r;
  ds->mMakeOutput[NE_DS_METHOD_DP_R] = ds_output_dp_r;
  ds->mMethods[NE_DS_METHOD_QX] = shell_elec_electric_vehicle_442b803b_1_ds_qx;
  ds->mMakeOutput[NE_DS_METHOD_QX] = ds_output_qx;
  ds->mMethods[NE_DS_METHOD_QU] = ds_qu;
  ds->mMakeOutput[NE_DS_METHOD_QU] = ds_output_qu;
  ds->mMethods[NE_DS_METHOD_QT] = ds_qt;
  ds->mMakeOutput[NE_DS_METHOD_QT] = ds_output_qt;
  ds->mMethods[NE_DS_METHOD_Q1] = ds_q1;
  ds->mMakeOutput[NE_DS_METHOD_Q1] = ds_output_q1;
  ds->mMethods[NE_DS_METHOD_QX_P] =
    shell_elec_electric_vehicle_442b803b_1_ds_qx_p;
  ds->mMakeOutput[NE_DS_METHOD_QX_P] = ds_output_qx_p;
  ds->mMethods[NE_DS_METHOD_QU_P] = ds_qu_p;
  ds->mMakeOutput[NE_DS_METHOD_QU_P] = ds_output_qu_p;
  ds->mMethods[NE_DS_METHOD_QT_P] = ds_qt_p;
  ds->mMakeOutput[NE_DS_METHOD_QT_P] = ds_output_qt_p;
  ds->mMethods[NE_DS_METHOD_Q1_P] = ds_q1_p;
  ds->mMakeOutput[NE_DS_METHOD_Q1_P] = ds_output_q1_p;
  ds->mMethods[NE_DS_METHOD_VAR_TOL] =
    shell_elec_electric_vehicle_442b803b_1_ds_var_tol;
  ds->mMakeOutput[NE_DS_METHOD_VAR_TOL] = ds_output_var_tol;
  ds->mMethods[NE_DS_METHOD_EQ_TOL] =
    shell_elec_electric_vehicle_442b803b_1_ds_eq_tol;
  ds->mMakeOutput[NE_DS_METHOD_EQ_TOL] = ds_output_eq_tol;

  /* equation data */
  ds->mEquationData = s_equation_data;

  /* continuous variable data */
  ds->mVariableData = s_variable_data;

  /* discrete variable data */
  ds->mDiscreteData = s_discrete_data;

  /* observable data */
  ds->mObservableData = s_observable_data;

  /* major mode data */
  ds->mMajorModeData = s_major_mode_data;

  /* zc data */
  ds->mZCData = s_zc_data;

  /* ranges */
  ds->mRanges = s_range;

  /* assert data */
  ds->mAssertData = s_assert_data;

  /* assert ranges */
  ds->mAssertRanges = s_assert_range;

  /* param assert data */
  ds->mParamAssertData = s_param_assert_data;

  /* param assert ranges */
  ds->mParamAssertRanges = s_param_assert_range;

  /* equation ranges */
  ds->mEquationRanges = s_equation_range;

  /* parameters */
  ds->mLogicalParameters = s_logical_parameter_data;
  ds->mIntegerParameters = s_integer_parameter_data;
  ds->mIndexParameters = s_index_parameter_data;
  ds->mRealParameters = s_real_parameter_data;

  /* constant tables */
  _ds->mTable0 = s_constant_table0;
  _ds->mTable1 = s_constant_table1;
  _ds->mTable2 = s_constant_table2;
  _ds->mTable3 = s_constant_table3;
  _ds->mTable4 = s_constant_table4;
  _ds->mTable5 = s_constant_table5;
  _ds->mTable6 = s_constant_table6;
  _ds->mTable7 = s_constant_table7;
  _ds->mTable8 = s_constant_table8;
  _ds->mTable9 = s_constant_table9;
  _ds->mTable10 = s_constant_table10;
  _ds->mTable11 = s_constant_table11;
  _ds->mTable12 = s_constant_table12;
  _ds->mTable13 = s_constant_table13;
  return (NeDynamicSystem *)_ds;
}

static int32_T ds_passert (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_del_v (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_del_v0 (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_del_tmax (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_del_t (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dxdelt (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dudelt (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dudelt_p (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUDELT_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 0ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtdelt (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtdelt_p (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTDELT_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 0ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_cache_r (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_init_r (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_update_r (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_cache_i (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_init_i (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_update_i (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_sfp (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_sfo (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_duf (const NeDynamicSystem *t0, const NeDynamicSystemInput *t6,
  NeDsMethodOutput *t7)
{
  PmRealVector out;
  real_T X_idx_16;
  real_T U_idx_2;
  real_T X_idx_79;
  real_T X_idx_128;
  (void)t0;
  U_idx_2 = t6->mU.mX[2];
  X_idx_16 = t6->mX.mX[16];
  X_idx_79 = t6->mX.mX[79];
  X_idx_128 = t6->mX.mX[128];
  out = t7->mDUF;
  U_idx_2 = X_idx_16 * 0.041666666666666664 + -U_idx_2;
  X_idx_16 = -(-exp(U_idx_2 * 2.0) * 2.0) * 0.5;
  out.mX[0] = -(X_idx_79 * 100.0) * 0.001;
  out.mX[1] = -(-U_idx_2 * 2.0) * 0.76562500000000011;
  out.mX[2] = X_idx_16;
  out.mX[3] = -X_idx_128;
  (void)t0;
  (void)t7;
  return 0;
}

static int32_T ds_duf_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUF_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 1;
  out.mJc[3] = 3;
  out.mJc[4] = 4;
  out.mJc[5] = 4;
  out.mIr[0] = 100;
  out.mIr[1] = 123;
  out.mIr[2] = 124;
  out.mIr[3] = 126;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtf (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtf_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTF_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_b (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mB;
  out.mX[0] = -1.2572964351350123E-6;
  out.mX[1] = 1.0;
  out.mX[2] = -0.001;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_b_p (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mB_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 2;
  out.mJc[3] = 2;
  out.mJc[4] = 2;
  out.mJc[5] = 3;
  out.mIr[0] = 2;
  out.mIr[1] = 16;
  out.mIr[2] = 21;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_c (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_c_p (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mC_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_tduf_p (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUF_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 2;
  out.mJc[2] = 3;
  out.mJc[3] = 5;
  out.mJc[4] = 6;
  out.mJc[5] = 7;
  out.mIr[0] = 2;
  out.mIr[1] = 100;
  out.mIr[2] = 16;
  out.mIr[3] = 123;
  out.mIr[4] = 124;
  out.mIr[5] = 126;
  out.mIr[6] = 21;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_ddf (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_ddf_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDDF_P;
  out.mNumCol = 0ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_icr (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_icr_im (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_icr_id (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dxicr (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_tduicr_p (const NeDynamicSystem *ds, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUICR_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 0ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dum (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dum_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUM_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 30ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtm (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dtm_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTM_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 30ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_vmm (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  PmBoolVector out;
  (void)t1;
  out = t2->mVMM;
  out.mX[0] = false;
  out.mX[1] = true;
  out.mX[2] = false;
  out.mX[3] = false;
  out.mX[4] = false;
  out.mX[5] = false;
  out.mX[6] = true;
  out.mX[7] = true;
  out.mX[8] = true;
  out.mX[9] = true;
  out.mX[10] = true;
  out.mX[11] = true;
  out.mX[12] = true;
  out.mX[13] = true;
  out.mX[14] = true;
  out.mX[15] = true;
  out.mX[16] = true;
  out.mX[17] = true;
  out.mX[18] = false;
  out.mX[19] = true;
  out.mX[20] = true;
  out.mX[21] = false;
  out.mX[22] = true;
  out.mX[23] = true;
  out.mX[24] = false;
  out.mX[25] = false;
  out.mX[26] = false;
  out.mX[27] = false;
  out.mX[28] = false;
  out.mX[29] = false;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dp_l (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dp_i (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dp_j (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dp_r (const NeDynamicSystem *t0, const NeDynamicSystemInput
  *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T P_R_idx_0;
  (void)t0;
  P_R_idx_0 = t2->mP_R.mX[0];
  out = t3->mDP_R;
  out.mX[0] = P_R_idx_0;
  (void)t0;
  (void)t3;
  return 0;
}

static int32_T ds_qu (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mQU;
  out.mX[0] = -7.7889303479999975E-7;
  out.mX[1] = 0.00050954;
  out.mX[2] = 2.5477E-5;
  out.mX[3] = 2.5477E-5;
  out.mX[4] = -1.0;
  out.mX[5] = -2.0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_qt (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_q1 (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mQ1;
  out.mX[0] = 0.0;
  out.mX[1] = 0.0;
  out.mX[2] = 0.0;
  out.mX[3] = 0.0;
  out.mX[4] = 0.0;
  out.mX[5] = 0.0;
  out.mX[6] = 0.0;
  out.mX[7] = 0.0;
  out.mX[8] = 0.0;
  out.mX[9] = 0.0;
  out.mX[10] = 0.0;
  out.mX[11] = 0.0;
  out.mX[12] = 0.0;
  out.mX[13] = 0.0;
  out.mX[14] = 0.0;
  out.mX[15] = 0.0;
  out.mX[16] = 0.0;
  out.mX[17] = 0.0;
  out.mX[18] = 0.0;
  out.mX[19] = 0.0;
  out.mX[20] = 0.0;
  out.mX[21] = 0.0;
  out.mX[22] = 0.0;
  out.mX[23] = 0.0;
  out.mX[24] = 0.0;
  out.mX[25] = 0.0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_qu_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQU_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 4;
  out.mJc[2] = 4;
  out.mJc[3] = 4;
  out.mJc[4] = 4;
  out.mJc[5] = 6;
  out.mIr[0] = 0;
  out.mIr[1] = 22;
  out.mIr[2] = 30;
  out.mIr[3] = 31;
  out.mIr[4] = 108;
  out.mIr[5] = 124;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_qt_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQT_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_q1_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQ1_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 130ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 26;
  out.mIr[0] = 0;
  out.mIr[1] = 3;
  out.mIr[2] = 22;
  out.mIr[3] = 23;
  out.mIr[4] = 28;
  out.mIr[5] = 30;
  out.mIr[6] = 31;
  out.mIr[7] = 35;
  out.mIr[8] = 38;
  out.mIr[9] = 41;
  out.mIr[10] = 59;
  out.mIr[11] = 60;
  out.mIr[12] = 61;
  out.mIr[13] = 62;
  out.mIr[14] = 77;
  out.mIr[15] = 78;
  out.mIr[16] = 79;
  out.mIr[17] = 88;
  out.mIr[18] = 106;
  out.mIr[19] = 107;
  out.mIr[20] = 108;
  out.mIr[21] = 109;
  out.mIr[22] = 121;
  out.mIr[23] = 122;
  out.mIr[24] = 123;
  out.mIr[25] = 124;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_y (const NeDynamicSystem *t0, const NeDynamicSystemInput *t3,
                     NeDsMethodOutput *t4)
{
  PmRealVector out;
  real_T X_idx_23;
  real_T X_idx_25;
  real_T X_idx_14;
  real_T X_idx_16;
  real_T X_idx_121;
  (void)t0;
  X_idx_14 = t3->mX.mX[14];
  X_idx_16 = t3->mX.mX[16];
  X_idx_23 = t3->mX.mX[23];
  X_idx_25 = t3->mX.mX[25];
  X_idx_121 = t3->mX.mX[121];
  out = t4->mY;
  out.mX[0] = X_idx_23;
  out.mX[1] = -X_idx_25 / -1.0;
  out.mX[2] = X_idx_14;
  out.mX[3] = X_idx_16;
  out.mX[4] = X_idx_121;
  out.mX[5] = X_idx_16 * 0.041666666666666664;
  (void)t0;
  (void)t4;
  return 0;
}

static int32_T ds_dxy (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mDXY;
  out.mX[0] = 1.0;
  out.mX[1] = 1.0;
  out.mX[2] = 0.041666666666666664;
  out.mX[3] = 1.0;
  out.mX[4] = 1.0;
  out.mX[5] = 1.0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_duy (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_duy_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUY_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 6ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_mduy_p (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mMDUY_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 6ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_tduy_p (const NeDynamicSystem *ds, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUY_P;
  out.mNumCol = 5ULL;
  out.mNumRow = 6ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dty (const NeDynamicSystem *ds, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *t2)
{
  (void)t1;
  (void)ds;
  (void)t2;
  return 0;
}

static int32_T ds_dty_p (const NeDynamicSystem *ds, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTY_P;
  out.mNumCol = 1ULL;
  out.mNumRow = 6ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)ds;
  (void)t2;
  return 0;
}
