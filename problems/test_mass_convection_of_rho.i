[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 10
  nz = 10
[]

[Variables]
  [u]
    family = LAGRANGE_VEC
    order = FIRST
  []
  [B]
    family = LAGRANGE_VEC
    order = FIRST
  []
  [p]
    family = LAGRANGE
    order = FIRST
  []
  [rho]
    family = LAGRANGE
    order = FIRST
  []
[]

[Kernels]
  [u_time_derivative]
    type = ADCoupledVectorTimeDerivative
    variable = u
    density = rho
  []
  [u_pressure_gradient]
    type = ADCoupledPressure
    variable = u
    pressure = p
  []
  [u_lorentz_force]
    type = ADCoupledLorentzForce
    variable = u
    B_field = B
    mu_0 = 1.0
  []

  [p_adiabatic_time_derivative]
    type = ADAdiabaticTimeDerivative
    variable = p
    density = rho
  []

  [rho_time_derivative]
    type = ADTimeDerivative
    variable = rho
  []
  [rho_mass_convection]
    type = ADMassConvection
    variable = rho
    velocity = u
  []

  [B_time_derivative]
    type = ADVectorTimeDerivative
    variable = B
  []
[]

[BCs]
  # active = 'left'
  # [u_left]
  #   type = ADVectorFunctionDirichletBC
  #   variable = u
  #   function_x = 5
  #   function_y = 0
  #   function_z = 5
  #   boundary = left
  # []
  # [p_left]
  #   type = ADDirichletBC
  #   variable = p
  #   value = 2
  #   boundary = left
  # []
[]

[Functions]
  [p_func]
    type = ParsedFunction
    value = '4-4*x'
    # value_y = '-4*x'
  []
  [B_func]
    type = ParsedVectorFunction
    value_y = '4+z'
  []
[]

[ICs]
  [IC_u]
    type = VectorConstantIC
    x_value = 2
    y_value = 0
    z_value = 0
    variable = u
  []
  [IC_p]
    type = FunctionIC
    variable = p
    function = p_func
  []
  [IC_rho]
    type = ConstantIC
    variable = rho
    value = 1
  []
  [IC_B]
    type = VectorFunctionIC
    variable = B
    function = B_func
  []
[]

[Executioner]
  type = Transient
  solve_type = NEWTON
  num_steps = 50
  dt = 1E-2
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = ' hypre boomeramg'

  steady_state_detection = true
  steady_state_tolerance = 1E-8
[]

[Outputs]
  exodus = true
  execute_on = 'TIMESTEP_END'
[]
