#pragma once

#include "ADVectorKernel.h"

/**
 *
 */
class ADDivergence : public ADVectorKernel
{
public:
  static InputParameters validParams();

  ADDivergence(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;
};
