[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 10
  nz = 10
[]

[Variables]
  [rho]
    family = LAGRANGE
    order = FIRST
  []
  [u]
    family = LAGRANGE_VEC
    order = FIRST
  []
  [p]
    family = LAGRANGE
    order = FIRST
  []
[]

[Kernels]
  [rho_time_derivative]
    type = ADTimeDerivative
    variable = rho
  []
  [rho_mass_convection]
    type = ADMassConvection
    variable = rho
    velocity = u
  []

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

  [p_adiabatic_time_derivative]
    type = ADAdiabaticTimeDerivative
    variable = p
    density = rho
  []
[]

[BCs]
  # active = 'left'
  [rho_left]
    type = ADDirichletBC
    variable = rho
    value = 2
    boundary = left
  []
  # [u_left]
  #   type = ADVectorFunctionDirichletBC
  #   variable = u
  #   function_x = 5
  #   function_y = 0
  #   function_z = 5
  #   boundary = left
  # []
  [p_left]
    type = ADDirichletBC
    variable = p
    value = 2
    boundary = left
  []
[]

[ICs]
  [IC_rho]
    type = ConstantIC
    variable = rho
    value = 2
  []
  [IC_u]
    type = VectorConstantIC
    x_value = 5
    y_value = 0
    z_value = 5
    variable = u
  []
  [IC_p]
    type = ConstantIC
    variable = p
    value = 2
  []
[]

[Executioner]
  type = Transient
  solve_type = NEWTON
  num_steps = 100
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
