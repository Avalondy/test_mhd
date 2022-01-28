[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 20
  ny = 20
  nz = 20
[]

[Variables]
  [B]
    family = LAGRANGE_VEC
    order = FIRST
  []
[]

[Kernels]
  [divergence]
    type = ADCoefVectorDiffusion
    variable = B
    mu_0 = 2
    sigma = 0.5
  []
[]

[BCs]
  active = 'left'
  [left]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 1
    function_y = 2
    function_z = 3
    boundary = left
  []
  [right]
    type = ADVectorFunctionDirichletBC
    variable = B
    function_x = 4
    function_y = 5
    function_z = 6
    boundary = right
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON

  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
  exodus = true
  execute_on = 'TIMESTEP_END'
[]
