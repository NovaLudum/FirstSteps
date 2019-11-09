extends Spatial

onready var animationPlayer = get_node("AnimationPlayer");

func _ready() -> void:
    animationPlayer.play("walk");
    pass

func _process(delta: float) -> void:
        if(!animationPlayer.is_playing()):
            animationPlayer.play("walk");
