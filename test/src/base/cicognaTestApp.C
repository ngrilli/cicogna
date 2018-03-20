//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "cicognaTestApp.h"
#include "cicognaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<cicognaTestApp>()
{
  InputParameters params = validParams<cicognaApp>();
  return params;
}

cicognaTestApp::cicognaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  cicognaApp::registerObjectDepends(_factory);
  cicognaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  cicognaApp::associateSyntaxDepends(_syntax, _action_factory);
  cicognaApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  cicognaApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    cicognaTestApp::registerObjects(_factory);
    cicognaTestApp::associateSyntax(_syntax, _action_factory);
    cicognaTestApp::registerExecFlags(_factory);
  }
}

cicognaTestApp::~cicognaTestApp() {}

void
cicognaTestApp::registerApps()
{
  registerApp(cicognaApp);
  registerApp(cicognaTestApp);
}

void
cicognaTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
cicognaTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
cicognaTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
cicognaTestApp__registerApps()
{
  cicognaTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
cicognaTestApp__registerObjects(Factory & factory)
{
  cicognaTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
cicognaTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  cicognaTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
cicognaTestApp__registerExecFlags(Factory & factory)
{
  cicognaTestApp::registerExecFlags(factory);
}
