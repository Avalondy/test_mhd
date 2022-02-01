#pragma once

#include "ADVectorKernel.h"

class ADCoupledLorentzForce : public ADVectorKernel
{
public:
  static InputParameters validParams();

  ADCoupledLorentzForce(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;

  const ADVectorVariableValue & _B;
  const ADVectorVariableGradient & _grad_B;
  const Real & _mu_0;
};
