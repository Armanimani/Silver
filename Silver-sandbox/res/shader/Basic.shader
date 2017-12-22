#shader = vertex
#version 420

in layout(location = 0) vec3 vertexPosition;

out vec3 color;

void main()
{
	color = vec3(1.0, 0.0, 1.0);
	gl_Position = vec4(vertexPosition, 1.0);
}

#shader = fragment
#version 420

in vec3 color;
out vec4 fragColor;

void main()
{
	fragColor = vec4(color, 1.0);
}