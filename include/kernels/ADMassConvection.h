#pragma once

#include "ADKernelValue.h"

/**
 *
 */
class ADMassConvection : public ADKernelValue
{
public:
  static InputParameters validParams();

  ADMassConvection(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
  const ADVectorVariableGradient & _grad_velocity;
};
