#include "ADAdiabaticTimeDerivative.h"

registerMooseObject("TestMHDApp", ADAdiabaticTimeDerivative);

InputParameters
ADAdiabaticTimeDerivative::validParams()
{
  InputParameters params = ADTimeKernelValue::validParams();
  params.addClassDescription("The time derivative operator of adiabatic process with the form of "
                             "$(\\frac{\\partial p \\rho^{-\\gamma} }{\\partial t})$."
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("density", "The density");
  params.addParam<Real>("gamma", 5./3., "The exponential factor gamma");
  return params;
}

ADAdiabaticTimeDerivative::ADAdiabaticTimeDerivative(const InputParameters & parameters)
  : ADTimeKernelValue(parameters),
    _gamma(getParam<Real>("gamma")),
    _rho(adCoupledValue("density")),
    _rho_dot(adCoupledDot("density"))
{
}

ADReal
ADAdiabaticTimeDerivative::precomputeQpResidual()
{
  return _u_dot[_qp] * std::pow(_rho[_qp], -_gamma) - _gamma * _u[_qp] * std::pow(_rho[_qp], -_gamma-1) * _rho_dot[_qp];
}
