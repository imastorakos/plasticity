#include "PlasticityApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<PlasticityApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

PlasticityApp::PlasticityApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PlasticityApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PlasticityApp::associateSyntax(_syntax, _action_factory);
}

PlasticityApp::~PlasticityApp()
{
}

// External entry point for dynamic application loading
extern "C" void PlasticityApp__registerApps() { PlasticityApp::registerApps(); }
void
PlasticityApp::registerApps()
{
  registerApp(PlasticityApp);
}

// External entry point for dynamic object registration
extern "C" void PlasticityApp__registerObjects(Factory & factory) { PlasticityApp::registerObjects(factory); }
void
PlasticityApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void PlasticityApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PlasticityApp::associateSyntax(syntax, action_factory); }
void
PlasticityApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
