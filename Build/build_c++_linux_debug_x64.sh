#!/bin/bash
SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
#cd $SCRIPTPATH/../

#Build BasicTest
scons platform=linux bits=64 use_llvm=true target=debug target_path=$SCRIPTPATH/../Bin/ target_name=BasicTest source_path=$SCRIPTPATH/../Src/BasicTest