#include "ADMagneticFlow.h"

registerMooseObject("TestMHDApp", ADMagneticFlow);

InputParameters
ADMagneticFlow::validParams()
{
  InputParameters params = ADVectorKernel::validParams();
  params.addClassDescription("The magnetic flow term of ($ - \\nabla \\times (\\vec{u} \\times \\vec{B})$). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("velocity", "The velocity");
  return params;
}

ADMagneticFlow::ADMagneticFlow(const InputParameters & parameters)
  : ADVectorKernel(parameters),
    _velocity(adCoupledVectorValue("velocity"))
{
}

ADReal
ADMagneticFlow::computeQpResidual()
{
  // return _grad_test[_i][_qp].cross(_velocity[_qp].cross(_u[_qp]));
  return 0.;
}
