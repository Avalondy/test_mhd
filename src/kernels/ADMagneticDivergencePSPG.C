#include "ADMagneticDivergencePSPG.h"

registerMooseObject("TestMHDApp", ADMagneticDivergencePSPG);

InputParameters
ADMagneticDivergencePSPG::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription(
      "This class adds PSPG stabilization to the magnetic divergence equation, enabling use of "
      "equal order shape functions for q (dummy) and B variables");

  params.addParam<Real>("rho", 1.0, "Density");
  params.addParam<Real>("alpha", 1., "Multiplicative factor on the stabilization parameter tau.");
  params.addParam<Real>("mu_0", 1.2566E-6, "Permeability");
  params.addParam<Real>("sigma", 1.0E6, "Electrical conductivity.");
  return params;
}

ADMagneticDivergencePSPG::ADMagneticDivergencePSPG(const InputParameters & parameters)
  : ADKernelGrad(parameters),
    _rho(getParam<Real>("rho")),
    _alpha(getParam<Real>("alpha")),
    _mu_0(getParam<Real>("mu_0")),
    _sigma(getParam<Real>("sigma"))
{
  // _hmax = _current_elem->hmax();
  _hmax = 0.1;
  auto && eta = 1 / (_mu_0 / _sigma);
  _tau = _alpha / 3. * (_hmax * _hmax / (4. * eta));
}

ADRealVectorValue
ADMagneticDivergencePSPG::precomputeQpResidual()
{
  return -_tau / _rho * _grad_u[_qp];
}
