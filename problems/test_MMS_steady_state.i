# Example taken from section 5.1 in [Int. J. Numer. Meth. Fluids 29: 535 – 554 (1999)]

[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 10
  nz = 10
[]

[Variables]
  [B]
    order = FIRST
    family = LAGRANGE_VEC
    # family = NEDELEC_ONE
  []
  # [q_dummy]
  # []
[]

[Kernels]
  # [B_time_derivative]
  #   type = ADVectorTimeDerivative
  #   variable = B
  # []
  [B_magnetic_flow]
    type = ADMagneticFlow
    variable = B
    velocity = '1 0 0'
  []
  [B_diffusion]
    type = ADCoefVectorDiffusion
    variable = B
    mu_0 = 1
    sigma = 1
  []
  # [B_coupled_dummy]
  #   type = ADCoupledDummy
  #   variable = B
  #   dummy_variable = q_dummy
  # []
  [B_body_force]
    type = VectorBodyForce
    variable = B
    function = body_force
  []

  # [Magnetic_divergence]
  #   type = ADMagneticDivergence
  #   variable = q_dummy
  #   B_field = B
  # []
  # [Magnetic_divergence_PSPG]
  #   type = ADMagneticDivergencePSPG
  #   variable = q_dummy
  #   mu_0 = 1
  #   sigma = 1
  # []
[]

[Functions]
  [body_force]
    type = ParsedVectorFunction
    value_x = '2-2*x'
    value_y = '2'
    value_z = '2*z'
  []
  [exact]
    type = ParsedVectorFunction
    value_x = 'x*x'
    value_y = 'y*y'
    value_z = '-2*(x+y)*z'
  []
[]

[BCs]
  [all]
    type = ADVectorFunctionDirichletBC
    variable = B
    function = exact
    boundary = 'bottom right left top front back'
  []
  # [dummy]
  #   type = ADDirichletBC
  #   variable = q_dummy
  #   boundary = 'bottom right left top front back'
  #   value = 0
  # []
[]

# [ICs]
#   [IC_B]
#     type = VectorConstantIC
#     x_value = 5
#     y_value = 0
#     z_value = 0
#     variable = B
#   []
#   # [IC_u]
#   #   type = VectorConstantIC
#   #   x_value = 1
#   #   y_value = 0
#   #   z_value = 0
#   #   variable = u
#   # []
# []

[Executioner]
  type = Steady
  solve_type = NEWTON
  # num_steps = 100
  # dt = 1E-2
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = ' hypre boomeramg'

  # steady_state_detection = true
  # steady_state_tolerance = 1E-5
[]

[Outputs]
  exodus = true
  # execute_on = 'TIMESTEP_END'
[]
