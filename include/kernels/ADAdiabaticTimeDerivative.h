#pragma once

#include "ADTimeKernelValue.h"

class ADAdiabaticTimeDerivative : public ADTimeKernelValue
{
public:
  static InputParameters validParams();

  ADAdiabaticTimeDerivative(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;

  const Real & _gamma;
  const ADVariableValue & _rho;
  const ADVariableValue & _rho_dot;
};
