#pragma once

#include "ADKernelGrad.h"

/**
 *
 */
class ADMagneticDivergencePSPG : public ADKernelGrad
{
public:
  static InputParameters validParams();

  ADMagneticDivergencePSPG(const InputParameters & parameters);

protected:
  ADRealVectorValue precomputeQpResidual() override;

  // const ADVectorVariableGradient & _grad_B;
  const Real & _rho;
  ADReal _tau;
  const Real & _alpha;

  const Real & _mu_0;
  const Real & _sigma;

  ADReal _hmax;
};
