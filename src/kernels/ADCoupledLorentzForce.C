#include "ADCoupledLorentzForce.h"

registerMooseObject("TestMHDApp", ADCoupledLorentzForce);

InputParameters
ADCoupledLorentzForce::validParams()
{
  InputParameters params = ADVectorKernel::validParams();
  params.addClassDescription("The Lorentz force term in momentum conservation equation, with "
                             "the form of ($ - (\\nabla \\times \\vec{B}) \\times \\vec{B} / \\mu_0 )$). "
                             "The Jacobian is computed using automatic differentiation");

  params.addRequiredCoupledVar("B_field", "The B field");
  params.addParam<Real>("mu_0", 1.0, "Permeability");
  return params;
}

ADCoupledLorentzForce::ADCoupledLorentzForce(const InputParameters & parameters)
  : ADVectorKernel(parameters),
    _B(adCoupledVectorValue("B_field")),
    _grad_B(adCoupledVectorGradient("B_field")),
    _mu_0(getParam<Real>("mu_0"))
{
}

ADReal
ADCoupledLorentzForce::computeQpResidual()
{
  return _test[_i][_qp] * ( (_grad_B[_qp] - _grad_B[_qp].transpose()) * _B[_qp] ) / _mu_0;
}
