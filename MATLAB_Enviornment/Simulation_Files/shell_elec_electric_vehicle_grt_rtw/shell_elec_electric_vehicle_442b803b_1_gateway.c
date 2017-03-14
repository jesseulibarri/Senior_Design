/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "shell_elec_electric_vehicle_442b803b_1.h"

void shell_elec_electric_vehicle_442b803b_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 0, 0.001, 0, 0.001, 0, 0, 0,
    0, (SscLoggingSetting) 1, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 1e-06, 1e-09, 0, 0,
    100, 0, 1, 0, 0, 1e-09, 1, (NeLocalSolverChoice) 0, 0.01, 1, 3, 2,
    (NeLinearAlgebraChoice) 0, 1024, 1, 0.001, };

  const NeOutputParameters* outputparameters = NULL;
  const McLinearAlgebra* linear_algebra_ptr = ((solverparams.mLinearAlgebra ==
    NE_FULL_LA) ? get_rtw_linear_algebra() : mc_get_csparse_linear_algebra());
  NeDae* dae[1];
  size_t numOutputs = 0;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0,
        "shell_elec_electric_vehicle/Solver\nConfiguration", }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  shell_elec_electric_vehicle_442b803b_1_dae(&dae[0],
    &modelparams,
    &solverparams,
    linear_algebra_ptr);
  nesl_register_simulator_group(
    "shell_elec_electric_vehicle/Solver Configuration_1",
    1,
    &dae[0],
    solverparams,
    modelparams,
    numOutputs,
    outputparameters,
    1);
}
