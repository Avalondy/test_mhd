#pragma once

#include "ADKernelValue.h"

/**
 *
 */
class ADMagneticDivergence : public ADKernelValue
{
public:
  static InputParameters validParams();

  ADMagneticDivergence(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;

  const ADVectorVariableGradient & _grad_B;
};
