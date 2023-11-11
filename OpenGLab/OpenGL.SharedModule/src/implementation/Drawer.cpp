// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

# include  <glad/glad.h>
import OpenGlShape;

module Drawer;

void Drawer::draw(OpenGlShape& shape)
{
	glBindVertexArray(shape.get_vao());
	glDrawArrays(shape.get_drawing_mode(), 0, shape.get_data_size());
	glBindVertexArray(0);
}