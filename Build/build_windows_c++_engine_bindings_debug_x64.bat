SET SOURCEPATH=%~dp0
cd %SOURCEPATH%/../godot-cpp
scons platform=windows bits=64 generate_bindings=yes use_mingw=true target=debug