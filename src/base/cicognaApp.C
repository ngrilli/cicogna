#include "cicognaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<cicognaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

cicognaApp::cicognaApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  cicognaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  cicognaApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  cicognaApp::registerExecFlags(_factory);
}

cicognaApp::~cicognaApp() {}

void
cicognaApp::registerApps()
{
  registerApp(cicognaApp);
}

void
cicognaApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"cicognaApp"});
}

void
cicognaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"cicognaApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
cicognaApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
cicognaApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
cicognaApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cicognaApp__registerApps()
{
  cicognaApp::registerApps();
}

extern "C" void
cicognaApp__registerObjects(Factory & factory)
{
  cicognaApp::registerObjects(factory);
}

extern "C" void
cicognaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  cicognaApp::associateSyntax(syntax, action_factory);
}

extern "C" void
cicognaApp__registerExecFlags(Factory & factory)
{
  cicognaApp::registerExecFlags(factory);
}
