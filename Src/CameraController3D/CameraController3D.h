#ifndef CAMERA_CONTROLLER_3D_H
#define CAMERA_CONTROLLER_3D_H

#include <Camera.hpp>
#include <Godot.hpp>
#include <InputEvent.hpp>
#include <InputEventMouseMotion.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <Spatial.hpp>

#include <algorithm>
#include <string.h>

namespace godot
{
class CameraController3D : public Node
{
    GODOT_CLASS(CameraController3D, Node);

private:
    Vector3 velocity = Vector3();
    Transform orientation = Transform();
    Vector2 motion = Vector2();

    float cameraXRotation = 0.0;

    //export
    Camera *camera;
    float CAMERA_ROTATION_SPEED = 0.001;
    float DIRECTION_INTERPOLATE_SPEED = 1;
    float MOTION_INTERPOLATE_SPEED = 10;
    float ROTATION_INTERPOLATE_SPEED = 10;
    float CAMERA_X_ROTATION_MIN = -40;
    float CAMERA_X_ROTATION_MAX = 30;
    //constants
    const Vector3 GRAVITY = Vector3(0, -9.8, 0);

    const String INPUT_MOUSE_MOTION{"InputEventMouseMotion"};
    const String INPUT_MOUSE_BUTTON{"InputEventMouseButton"};
    const String INPUT_KEY{"InputEventKey"};

public:
    static void _register_methods();

    CameraController3D() = default;
    ~CameraController3D() = default;

    void _init();
    void _ready();

    void _process(float delta);
    void _input(const godot::Ref<godot::InputEvent> event);

    void setCamera(NodePath nodePath);
    NodePath getCamera() const;
};
} // namespace godot
#endif