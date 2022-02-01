#pragma once

#include "ADVectorTimeDerivative.h"

class ADCoupledVectorTimeDerivative : public ADVectorTimeDerivative
{
public:
  static InputParameters validParams();

  ADCoupledVectorTimeDerivative(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;

  const ADVariableValue & _density;
};
