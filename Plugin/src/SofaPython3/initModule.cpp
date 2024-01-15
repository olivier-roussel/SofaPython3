/******************************************************************************
*                              SofaPython3 plugin                             *
*                  (c) 2021 CNRS, University of Lille, INRIA                  *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/

#include <SofaPython3/config.h>

#include "PythonEnvironment.h"
using sofapython3::PythonEnvironment;

#include <SofaPython3/initModule.h>

#include <sofa/core/init.h>
#include <sofa/defaulttype/init.h>
#include <sofa/simulation/init.h>
#include <sofa/helper/init.h>
#include <sofa/simulation/graph/init.h>

extern "C" {

SOFAPYTHON3_API void initExternalModule();
SOFAPYTHON3_API const char* getModuleName();
SOFAPYTHON3_API const char* getModuleVersion();
SOFAPYTHON3_API const char* getModuleLicense();
SOFAPYTHON3_API const char* getModuleDescription();
SOFAPYTHON3_API const char* getModuleComponentList();
SOFAPYTHON3_API bool moduleIsInitialized();

void initExternalModule()
{
    static bool first = true;
    if (first)
    {
        sofa::helper::init();
        sofa::defaulttype::init();
        sofa::core::init();
        sofa::simulation::core::init();
        sofa::simulation::graph::init();

        PythonEnvironment::Init();
        first = false;
    }
    PythonEnvironment::addPluginManagerCallback();
}

const char* getModuleName()
{
    return "SofaPython3";
}

const char* getModuleVersion()
{
    return "1.0";
}

const char* getModuleLicense()
{
    return "LGPL";
}

const char* getModuleDescription()
{
    return "This plugin contains the interpreter for python3.";
}

const char* getModuleComponentList()
{
    return "";
}

bool moduleIsInitialized()
{
    return PythonEnvironment::isInitialized();
}

}

namespace sofapython3
{
    void init()
    {
        std::cout <<  "sofapython3::plugin::initModule::init() : Entering.... " << std::endl;
        std::string pythonVersion = Py_GetVersion();
        std::cout <<  "sofapython3::plugin::initModule::init() : Initializing with python version " << pythonVersion << std::endl;

        initExternalModule();
    }
}
