project(Bindings.SofaRuntime)

set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SofaPython3/SofaRuntime/Module_SofaRuntime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SofaPython3/SofaRuntime/Timer/Submodule_Timer.cpp
)

set(HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SofaPython3/SofaRuntime/Timer/Submodule_Timer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SofaPython3/SofaRuntime/Timer/Submodule_Timer_doc.h
)

sofa_find_package(Sofa.Simulation.Graph REQUIRED)

SP3_add_python_package(
    SOURCE_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}/package
    TARGET_DIRECTORY
        SofaRuntime
)

message("**************** Begin SOFA Runtime ************************")

get_target_property(SP3_PLUGIN_ALL_LIBS SofaPython3::Plugin LINK_LIBRARIES)
get_target_property(SP3_PLUGIN_INTERFACE_LIBS SofaPython3::Plugin INTERFACE_LINK_LIBRARIES)
get_target_property(SP3_BINDINGS_SOFA_CORE_ALL_LIBS SofaPython3::Bindings.Sofa.Core LINK_LIBRARIES)
get_target_property(SP3_BINDINGS_SOFA_CORE_INTERFACE_LIBS SofaPython3::Bindings.Sofa.Core INTERFACE_LINK_LIBRARIES)

get_target_property(SP3_SOFA_SIMU_GRAPH_ALL_LIBS Sofa.Simulation.Graph LINK_LIBRARIES)
get_target_property(SP3_SOFA_SIMU_GRAPH_INTERFACE_LIBS Sofa.Simulation.Graph INTERFACE_LINK_LIBRARIES)

message("**************** SP3_PLUGIN_ALL_LIBS=${SP3_PLUGIN_ALL_LIBS}")
message("**************** SP3_PLUGIN_INTERFACE_LIBS=${SP3_PLUGIN_INTERFACE_LIBS}")
message("**************** SP3_BINDINGS_SOFA_CORE_ALL_LIBS=${SP3_BINDINGS_SOFA_CORE_ALL_LIBS}")
message("**************** SP3_BINDINGS_SOFA_CORE_INTERFACE_LIBS=${SP3_BINDINGS_SOFA_CORE_INTERFACE_LIBS}")
message("**************** SP3_SOFA_SIMU_GRAPH_ALL_LIBS=${SP3_BINDINGS_SOFA_CORE_ALL_LIBS}")
message("**************** SP3_SOFA_SIMU_GRAPH_INTERFACE_LIBS=${SP3_BINDINGS_SOFA_CORE_INTERFACE_LIBS}")

get_target_property(PYBIND_EMBED_ALL_LIBS pybind11::embed LINK_LIBRARIES)
get_target_property(PYBIND_EMBED_INTERFACE_LIBS pybind11::embed INTERFACE_LINK_LIBRARIES)

message("**************** PYBIND_EMBED_ALL_LIBS=${PYBIND_EMBED_ALL_LIBS}")
message("**************** PYBIND_EMBED_INTERFACE_LIBS=${PYBIND_EMBED_INTERFACE_LIBS}")

get_target_property(PYBIND_MODULE_ALL_LIBS pybind11::module LINK_LIBRARIES)
get_target_property(PYBIND_MODULE_INTERFACE_LIBS pybind11::module INTERFACE_LINK_LIBRARIES)

message("**************** PYBIND_MODULE_ALL_LIBS=${PYBIND_MODULE_ALL_LIBS}")
message("**************** PYBIND_MODULE_INTERFACE_LIBS=${PYBIND_MODULE_INTERFACE_LIBS}")

get_target_property(PYBIND_PYTHON_LIBS_ALL_LIBS pybind11::_ClassicPythonLibraries LINK_LIBRARIES)
get_target_property(PYBIND_PYTHON_INTERFACE_LIBS pybind11::_ClassicPythonLibraries INTERFACE_LINK_LIBRARIES)

message("**************** PYBIND_PYTHON_LIBS_ALL_LIBS=${PYBIND_PYTHON_LIBS_ALL_LIBS}")
message("**************** PYBIND_PYTHON_INTERFACE_LIBS=${PYBIND_PYTHON_INTERFACE_LIBS}")

message("**************** End SOFA Runtime ************************")

SP3_add_python_module(
        TARGET       ${PROJECT_NAME}
        MODULE       SofaRuntime
        DESTINATION  SofaRuntime
        TYPE         MODULE
        SOURCES      ${SOURCE_FILES}
        HEADERS      ${HEADER_FILES}
        DEPENDS      Sofa.Simulation.Graph SofaPython3::Plugin SofaPython3::Bindings.Sofa.Core
)

sofa_create_component_in_package_with_targets(
    COMPONENT_NAME ${PROJECT_NAME}
    COMPONENT_VERSION ${SofaPython3_VERSION}
    PACKAGE_NAME SofaPython3
    TARGETS ${PROJECT_NAME}
    )