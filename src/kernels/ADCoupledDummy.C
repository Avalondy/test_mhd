#include "ADCoupledDummy.h"

registerMooseObject("TestMHDApp", ADCoupledDummy);

InputParameters
ADCoupledDummy::validParams()
{
  InputParameters params = ADVectorKernelValue::validParams();
  params.addClassDescription("The dummy variable gradient term in magnetic field time derivative equation, with "
                             "the form of ($ \\nabla q $). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("dummy", "The dummy variable");
  return params;
}

ADCoupledDummy::ADCoupledDummy(const InputParameters & parameters)
  : ADVectorKernelValue(parameters),
    _grad_dummy(adCoupledGradient("dummy"))
{
}

ADRealVectorValue
ADCoupledDummy::precomputeQpResidual()
{
  return _grad_dummy[_qp];
}
