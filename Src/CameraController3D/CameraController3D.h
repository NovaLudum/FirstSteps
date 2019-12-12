#ifndef CAMERA_CONTROLLER_3D_H
#define CAMERA_CONTROLLER_3D_H

#include <Camera.hpp>
#include <Godot.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <InputEventMouseMotion.hpp>
#include <MeshInstance.hpp>
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
    Vector3 direction = Vector3();
    Vector3 movement = Vector3();
    Transform orientation = Transform();
    Vector2 motion = Vector2();

    Camera *camera;
    Spatial *character;

    float cameraXRotation = 0.0;

    bool cursorActive = false;

    //export
    float CAMERA_ROTATION_SPEED = 0.001;
    float DIRECTION_INTERPOLATE_SPEED = 1;
    float MOTION_INTERPOLATE_SPEED = 10;
    float ROTATION_INTERPOLATE_SPEED = 10;
    float CAMERA_X_ROTATION_MIN = 70;
    float CAMERA_X_ROTATION_MAX = 100;

    float MOVEMENT_SPEED = 10;
    float ACCELERATION = 3;

    //constants
    const float GRAVITY = -9.8;

    const String INPUT_MOUSE_MOTION{"InputEventMouseMotion"};
    const String INPUT_MOUSE_BUTTON{"InputEventMouseButton"};
    const String INPUT_KEY{"InputEventKey"};

    //Movement
    const String ACTION_MOVE_LEFT{"ACTION_MOVE_LEFT"};
    const String ACTION_MOVE_RIGHT{"ACTION_MOVE_RIGHT"};
    const String ACTION_MOVE_FORWARD{"ACTION_MOVE_FORWARD"};
    const String ACTION_MOVE_BACKWARD{"ACTION_MOVE_BACKWARD"};

    //Keys
    const String ACTION_INVENTORY{"ACTION_INVENTORY"};
    const String ACTION_FREECAM{"ACTION_FREECAM"};

public:
    static void _register_methods();

    CameraController3D() = default;
    ~CameraController3D() = default;

    void _init();
    void _ready();

    void _physics_process(float delta);
    void _input(const godot::Ref<godot::InputEvent> event);
};
} // namespace godot
#endif