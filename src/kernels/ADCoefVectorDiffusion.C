#include "ADCoefVectorDiffusion.h"

registerMooseObject("TestMHDApp", ADCoefVectorDiffusion);

InputParameters
ADCoefVectorDiffusion::validParams()
{
  InputParameters params = ADVectorDiffusion::validParams();
  params.addClassDescription("The Laplacian operator ($-\\nabla \\cdot \\nabla \\vec{B}$), devided by two coefficients. "
                             "The Jacobian is computed using automatic differentiation");

  params.addParam<Real>("mu_0", 1.2566E-6, "Permeability");
  params.addParam<Real>("sigma", 1.0E6, "Electrical conductivity.");
  return params;
}

ADCoefVectorDiffusion::ADCoefVectorDiffusion(const InputParameters & parameters)
  : ADVectorDiffusion(parameters),
    _mu_0(getParam<Real>("mu_0")),
    _sigma(getParam<Real>("sigma"))
{
}

ADReal
ADCoefVectorDiffusion::computeQpResidual()
{
  return ADVectorDiffusion::computeQpResidual() / ( _mu_0 * _sigma );
}
