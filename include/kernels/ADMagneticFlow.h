#pragma once

#include "ADKernelValue.h"

/**
 *
 */
class ADMagneticFlow : public ADVectorKernelValue
{
public:
  static InputParameters validParams();

  ADMagneticFlow(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
  // virtual ADRealVectorValue computeQpJacobian() override;

  const ADVectorVariableValue & _velocity;
  const ADVectorVariableGradient & _grad_velocity;
};
