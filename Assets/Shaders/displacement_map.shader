shader_type spatial;

//wave height
uniform vec2 amplitude = vec2(0.2, 0.1);
uniform vec2 frequency = vec2(30, 2.5);
uniform vec2 time_factor = vec2(2.0, 3.0);

float height(vec2 pos, float time)
{
    return (amplitude.x * sin(pos.x * frequency.x + time * time_factor.x)) + (amplitude.y * sin(pos.y * frequency.y+ time * time_factor.y));
   }

void vertex() {
    VERTEX.y += height(VERTEX.xz, TIME);
    
    TANGENT =  normalize(vec3(0.0, height(VERTEX.xz + vec2(0.0, 0.2), TIME) - height(VERTEX.xz + vec2(0.0, -0.2), TIME), 0.4));
    BINORMAL = normalize(vec3(0.4, height(VERTEX.xz + vec2(0.2, 0.0), TIME) - height(VERTEX.xz + vec2(-0.2, 0.0), TIME), 0.0));
    NORMAL = cross(TANGENT, BINORMAL);
}