#pragma once

#include "ADVectorKernel.h"

/**
 *
 */
class ADMagneticFlow : public ADVectorKernel
{
public:
  static InputParameters validParams();

  ADMagneticFlow(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;
  // virtual ADRealVectorValue computeQpJacobian() override;

  const ADVectorVariableValue & _velocity;
};
