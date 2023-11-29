// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

# include  <glad/glad.h>
import OpenGlShape;

module Drawer;

void Drawer::draw(OpenGlShape& shape)
{
	glBindVertexArray(shape.get_vao());
	glDrawArrays(shape.get_drawing_mode(), 0, shape.get_number_of_vertices());
	glBindVertexArray(0);
}
void Drawer::draw(OpenGlShapeWithTexture& shape)
{
	glBindTexture(GL_TEXTURE_2D, shape.get_texture_id());
	glBindVertexArray(shape.get_vao());
	glDrawArrays(shape.get_drawing_mode(), 0, shape.get_number_of_vertices());
	glBindVertexArray(0);
}