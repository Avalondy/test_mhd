[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 10
  nz = 10
[]

[Variables]
  # [u]
  #   family = LAGRANGE_VEC
  #   order = FIRST
  # []
  [B]
    family = LAGRANGE_VEC
    order = FIRST
  []
  [q_dummy]
  []
[]

[Kernels]
  [B_time_derivative]
    type = ADVectorTimeDerivative
    variable = B
  []
  [B_magnetic_flow]
    type = ADMagneticFlow
    variable = B
    velocity = '1 0 0'
  []
  [B_diffusion]
    type = ADCoefVectorDiffusion
    variable = B
    mu_0 = 1.0E-6
    sigma = 1.0E6
  []

  [B_coupled_dummy]
    type = ADCoupledDummy
    variable = B
    dummy_variable = q_dummy
  []
  [Magnetic_divergence]
    type = ADMagneticDivergence
    variable = q_dummy
    B_field = B
  []
[]

[BCs]
  active = 'left right dummy'
  [left]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 1
    function_y = 0.1
    function_z = 0.1
    boundary = left
  []
  [right]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 1
    function_y = -0.1
    function_z = -0.1
    boundary = right
  []
  [dummy]
    type = ADDirichletBC
    variable = q_dummy
    boundary = 'bottom right left top front back'
    value = 0
  []
[]

[ICs]
  [IC_B]
    type = VectorConstantIC
    x_value = 1
    y_value = 0
    z_value = 0
    variable = B
  []
  # [IC_u]
  #   type = VectorConstantIC
  #   x_value = 1
  #   y_value = 0
  #   z_value = 0
  #   variable = u
  # []
[]

[Executioner]
  type = Transient
  solve_type = NEWTON
  num_steps = 100
  dt = 1E-2
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = ' hypre boomeramg'
[]

[Outputs]
  exodus = true
  execute_on = 'TIMESTEP_END'
[]
