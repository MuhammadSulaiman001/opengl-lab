module; // optional. Defines the beginning of the global module fragment

// #include directives go here but only apply to this file.
// import statements aren't allowed here. They go in the module preamble, below.

export module Drawer;

import OpenGlShape;

export class Drawer
{
public:
    void draw(OpenGlShape&);
    void draw(OpenGlShapeWithTexture&);
};