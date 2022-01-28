#include "ADMassConvection.h"

registerMooseObject("TestMHDApp", ADMassConvection);

InputParameters
ADMassConvection::validParams()
{
  InputParameters params = ADKernelValue::validParams();
  params.addClassDescription("The convection operator ($ a \\nabla \\cdot \\vec{u}$). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("velocity", "The velocity");
  return params;
}

ADMassConvection::ADMassConvection(const InputParameters & parameters)
  : ADKernelValue(parameters),
    _grad_velocity(adCoupledVectorGradient("velocity"))
{
}

ADReal
ADMassConvection::precomputeQpResidual()
{
  return _u[_qp] * _grad_velocity[_qp].tr();
}
