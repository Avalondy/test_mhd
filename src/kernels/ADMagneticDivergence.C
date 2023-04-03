#include "ADMagneticDivergence.h"

registerMooseObject("TestMHDApp", ADMagneticDivergence);

InputParameters
ADMagneticDivergence::validParams()
{
  InputParameters params = ADKernelValue::validParams();
  params.addClassDescription("The divergence operator ($\\nabla \\cdot \\vec{B}$). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("B_field", "The B field");
  return params;
}

ADMagneticDivergence::ADMagneticDivergence(const InputParameters & parameters)
  : ADKernelValue(parameters),
    _grad_B(adCoupledVectorGradient("B_field"))
{
}

ADReal
ADMagneticDivergence::precomputeQpResidual()
{
  return -_grad_B[_qp].tr();
}
