#include "ADCoupledPressure.h"

registerMooseObject("TestMHDApp", ADCoupledPressure);

InputParameters
ADCoupledPressure::validParams()
{
  InputParameters params = ADVectorKernelValue::validParams();
  params.addClassDescription("The pressure gradient term in momentum conservation equation, with "
                             "the form of ($ \\nabla p $). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("pressure", "The pressure");
  return params;
}

ADCoupledPressure::ADCoupledPressure(const InputParameters & parameters)
  : ADVectorKernelValue(parameters),
    _grad_p(adCoupledGradient("pressure"))
{
}

ADRealVectorValue
ADCoupledPressure::precomputeQpResidual()
{
  return _grad_p[_qp];
}
