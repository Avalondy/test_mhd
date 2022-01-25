#include "TestMHDApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
TestMHDApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

TestMHDApp::TestMHDApp(InputParameters parameters) : MooseApp(parameters)
{
  TestMHDApp::registerAll(_factory, _action_factory, _syntax);
}

TestMHDApp::~TestMHDApp() {}

void
TestMHDApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"TestMHDApp"});
  Registry::registerActionsTo(af, {"TestMHDApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TestMHDApp::registerApps()
{
  registerApp(TestMHDApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TestMHDApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TestMHDApp::registerAll(f, af, s);
}
extern "C" void
TestMHDApp__registerApps()
{
  TestMHDApp::registerApps();
}
