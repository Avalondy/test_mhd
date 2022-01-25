//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TestMHDTestApp.h"
#include "TestMHDApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
TestMHDTestApp::validParams()
{
  InputParameters params = TestMHDApp::validParams();
  return params;
}

TestMHDTestApp::TestMHDTestApp(InputParameters parameters) : MooseApp(parameters)
{
  TestMHDTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TestMHDTestApp::~TestMHDTestApp() {}

void
TestMHDTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TestMHDApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TestMHDTestApp"});
    Registry::registerActionsTo(af, {"TestMHDTestApp"});
  }
}

void
TestMHDTestApp::registerApps()
{
  registerApp(TestMHDApp);
  registerApp(TestMHDTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TestMHDTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TestMHDTestApp::registerAll(f, af, s);
}
extern "C" void
TestMHDTestApp__registerApps()
{
  TestMHDTestApp::registerApps();
}
