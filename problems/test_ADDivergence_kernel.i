[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 20
  ny = 20
  nz = 20
[]

[Variables]
  [u]
    family = LAGRANGE_VEC
    order = FIRST
  []
[]

[Kernels]
  [divergence]
    type = ADDivergence
    variable = u
  []
[]

[BCs]
  active = 'left'
  [left]
    type = ADVectorFunctionDirichletBC
    variable = u
    function_x = 1
    function_y = 0
    function_z = 0
    boundary = left
  []
  [right]
    type = ADVectorFunctionDirichletBC
    variable = u
    function_x = 1
    function_y = 0
    function_z = 0
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
