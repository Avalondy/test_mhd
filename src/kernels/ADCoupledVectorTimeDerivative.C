#include "ADCoupledVectorTimeDerivative.h"

registerMooseObject("TestMHDApp", ADCoupledVectorTimeDerivative);

InputParameters
ADCoupledVectorTimeDerivative::validParams()
{
  InputParameters params = ADVectorTimeDerivative::validParams();
  params.addClassDescription("Time derivative kernel on vector multiplied by a coupled scalar variable. "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("density", "The density");
  return params;
}

ADCoupledVectorTimeDerivative::ADCoupledVectorTimeDerivative(const InputParameters & parameters)
  : ADVectorTimeDerivative(parameters),
    _density(adCoupledValue("density"))
{
}

ADRealVectorValue
ADCoupledVectorTimeDerivative::precomputeQpResidual()
{
  return _density[_qp] * ADVectorTimeDerivative::precomputeQpResidual();
}
