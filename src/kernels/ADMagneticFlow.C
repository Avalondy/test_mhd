#include "ADMagneticFlow.h"

registerMooseObject("TestMHDApp", ADMagneticFlow);

InputParameters
ADMagneticFlow::validParams()
{
  InputParameters params = ADVectorKernelValue::validParams();
  params.addClassDescription("The magnetic flow term of ($ - \\nabla \\times (\\vec{u} \\times \\vec{B})$). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("velocity", "The velocity");
  return params;
}

ADMagneticFlow::ADMagneticFlow(const InputParameters & parameters)
  : ADVectorKernelValue(parameters),
    _velocity(adCoupledVectorValue("velocity")),
    _grad_velocity(adCoupledVectorGradient("velocity"))
{
}

ADRealVectorValue
ADMagneticFlow::precomputeQpResidual()
{
  return _u[_qp] * _grad_velocity[_qp].tr() - _grad_velocity[_qp].transpose() * _u[_qp] + _grad_u[_qp].transpose() * _velocity[_qp];
}
