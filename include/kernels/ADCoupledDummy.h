#pragma once

#include "ADKernelValue.h"

class ADCoupledDummy : public ADVectorKernelValue
{
public:
  static InputParameters validParams();

  ADCoupledDummy(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;

  const ADVariableGradient & _grad_dummy;
};
