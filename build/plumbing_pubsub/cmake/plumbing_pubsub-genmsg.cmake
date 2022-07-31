# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "plumbing_pubsub: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iplumbing_pubsub:/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(plumbing_pubsub_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_custom_target(_plumbing_pubsub_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "plumbing_pubsub" "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(plumbing_pubsub
  "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/plumbing_pubsub
)

### Generating Services

### Generating Module File
_generate_module_cpp(plumbing_pubsub
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/plumbing_pubsub
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(plumbing_pubsub_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(plumbing_pubsub_generate_messages plumbing_pubsub_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_dependencies(plumbing_pubsub_generate_messages_cpp _plumbing_pubsub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(plumbing_pubsub_gencpp)
add_dependencies(plumbing_pubsub_gencpp plumbing_pubsub_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS plumbing_pubsub_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(plumbing_pubsub
  "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/plumbing_pubsub
)

### Generating Services

### Generating Module File
_generate_module_eus(plumbing_pubsub
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/plumbing_pubsub
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(plumbing_pubsub_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(plumbing_pubsub_generate_messages plumbing_pubsub_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_dependencies(plumbing_pubsub_generate_messages_eus _plumbing_pubsub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(plumbing_pubsub_geneus)
add_dependencies(plumbing_pubsub_geneus plumbing_pubsub_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS plumbing_pubsub_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(plumbing_pubsub
  "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/plumbing_pubsub
)

### Generating Services

### Generating Module File
_generate_module_lisp(plumbing_pubsub
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/plumbing_pubsub
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(plumbing_pubsub_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(plumbing_pubsub_generate_messages plumbing_pubsub_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_dependencies(plumbing_pubsub_generate_messages_lisp _plumbing_pubsub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(plumbing_pubsub_genlisp)
add_dependencies(plumbing_pubsub_genlisp plumbing_pubsub_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS plumbing_pubsub_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(plumbing_pubsub
  "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/plumbing_pubsub
)

### Generating Services

### Generating Module File
_generate_module_nodejs(plumbing_pubsub
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/plumbing_pubsub
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(plumbing_pubsub_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(plumbing_pubsub_generate_messages plumbing_pubsub_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_dependencies(plumbing_pubsub_generate_messages_nodejs _plumbing_pubsub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(plumbing_pubsub_gennodejs)
add_dependencies(plumbing_pubsub_gennodejs plumbing_pubsub_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS plumbing_pubsub_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(plumbing_pubsub
  "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/plumbing_pubsub
)

### Generating Services

### Generating Module File
_generate_module_py(plumbing_pubsub
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/plumbing_pubsub
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(plumbing_pubsub_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(plumbing_pubsub_generate_messages plumbing_pubsub_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shzo/autolabor_ros_ws/src/plumbing_pubsub/msg/Person.msg" NAME_WE)
add_dependencies(plumbing_pubsub_generate_messages_py _plumbing_pubsub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(plumbing_pubsub_genpy)
add_dependencies(plumbing_pubsub_genpy plumbing_pubsub_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS plumbing_pubsub_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/plumbing_pubsub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/plumbing_pubsub
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(plumbing_pubsub_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/plumbing_pubsub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/plumbing_pubsub
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(plumbing_pubsub_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/plumbing_pubsub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/plumbing_pubsub
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(plumbing_pubsub_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/plumbing_pubsub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/plumbing_pubsub
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(plumbing_pubsub_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/plumbing_pubsub)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/plumbing_pubsub\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/plumbing_pubsub
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(plumbing_pubsub_generate_messages_py std_msgs_generate_messages_py)
endif()
