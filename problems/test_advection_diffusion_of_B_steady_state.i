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
    # family = NEDELEC_ONE
    order = FIRST
  []
  [q_dummy]
  []
[]

[Kernels]
  [B_magnetic_flow]
    type = ADMagneticFlow
    variable = B
    velocity = '1 0 0'
  []
  [B_diffusion]
    type = ADCoefVectorDiffusion
    variable = B
    mu_0 = 1.0
    sigma = 1.0
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
  [force]
    type = VectorBodyForce
    variable = B
    function = force
  []
[]

[Functions]
  [force]
    type = ParsedVectorFunction
    expression_x = '2-2*x'
    expression_y = '2'
    expression_z = '2*z'
  []
[]

[BCs]
  # active = 'left right'
  [left]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = left
  []
  [right]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = right
  []
  [front]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = front
  []
  [back]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = back
  []
  [top]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = top
  []
  [bottom]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 'x*x'
    function_y = 'y*y'
    function_z = '-2*(x+y)*z'
    boundary = bottom
  []
  [dummy]
    type = ADDirichletBC
    variable = q_dummy
    boundary = 'bottom right left top front back'
    value = 0
  []
[]

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
  execute_on = 'TIMESTEP_END'
[]
