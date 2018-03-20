//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CICOGNATESTAPP_H
#define CICOGNATESTAPP_H

#include "MooseApp.h"

class cicognaTestApp;

template <>
InputParameters validParams<cicognaTestApp>();

class cicognaTestApp : public MooseApp
{
public:
  cicognaTestApp(InputParameters parameters);
  virtual ~cicognaTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* CICOGNATESTAPP_H */
