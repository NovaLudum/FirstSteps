#!/bin/bash
SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
cd $SCRIPTPATH/../godot-cpp
scons platform=linux bits=64 generate_bindings=yes use_llvm=true target=debug