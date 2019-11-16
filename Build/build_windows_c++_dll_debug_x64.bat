SET SOURCEPATH=%~dp0
cd %SOURCEPATH%

rem BasicTest
scons platform=windows bits=64 use_llvm=false target=debug target_path=%SOURCEPATH%/../Bin/ target_name=BasicTest source_path=%SOURCEPATH%/../Src/BasicTest

rem CameraController3D
scons platform=windows bits=64 use_llvm=false target=debug target_path=%SOURCEPATH%/../Bin/ target_name=CameraController3D source_path=%SOURCEPATH%/../Src/CameraController3D