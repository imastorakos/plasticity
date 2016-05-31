#ifndef PLASTICITYAPP_H
#define PLASTICITYAPP_H

#include "MooseApp.h"

class PlasticityApp;

template<>
InputParameters validParams<PlasticityApp>();

class PlasticityApp : public MooseApp
{
public:
  PlasticityApp(InputParameters parameters);
  virtual ~PlasticityApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PLASTICITYAPP_H */
