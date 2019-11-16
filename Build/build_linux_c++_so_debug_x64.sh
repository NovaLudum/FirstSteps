#!/bin/bash
SOURCEPATH="$( cd "$(dirname "$0")" ; pwd -P )"
cd $SOURCEPATH/

#Nova Ludum Common Functionality Library NL_CFL
scons platform=linux bits=64 use_llvm=true target=debug target_path=$SOURCEPATH/../Bin/ target_name=Common source_path=$SOURCEPATH/../Src/Common
#BasicTest
scons platform=linux bits=64 use_llvm=true target=debug target_path=$SOURCEPATH/../Bin/ target_name=BasicTest source_path=$SOURCEPATH/../Src/BasicTest

#CameraController3D
scons platform=linux bits=64 use_llvm=true target=debug target_path=$SOURCEPATH/../Bin/ target_name=CameraController3D source_path=$SOURCEPATH/../Src/CameraController3D