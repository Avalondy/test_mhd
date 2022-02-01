#pragma once

#include "ADKernelValue.h"

class ADCoupledPressure : public ADVectorKernelValue
{
public:
  static InputParameters validParams();

  ADCoupledPressure(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;

  const ADVariableGradient & _grad_p;
};
