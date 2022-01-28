#pragma once

#include "ADVectorDiffusion.h"

/**
 *
 */
class ADCoefVectorDiffusion : public ADVectorDiffusion
{
public:
  static InputParameters validParams();

  ADCoefVectorDiffusion(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;

  const Real & _mu_0;
  const Real & _sigma;
};
