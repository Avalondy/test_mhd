#include "ADDivergence.h"

registerMooseObject("TestMHDApp", ADDivergence);

InputParameters
ADDivergence::validParams()
{
  InputParameters params = ADVectorKernel::validParams();
  params.addClassDescription("The divergence operator ($-\\nabla \\cdot \\vec{B}$). "
                             "The Jacobian is computed using automatic differentiation");

  return params;
}

ADDivergence::ADDivergence(const InputParameters & parameters)
  : ADVectorKernel(parameters)
{
}

ADReal
ADDivergence::computeQpResidual()
{
  return _u[_qp].contract(_test[_i][_qp]);
}
