<h1 align="center">
    miniRT
</h1>

<p align="center">
    A minimalist ray tracer implementation in C.
</p>

<div align="center">
    <img src="image.png" alt="miniRT" width="500">
</div>

## Overview

MiniRT is a ray tracing engine that demonstrates fundamental computer graphics concepts through the implementation of:
- Ray-object intersections
- Light and shadow calculations
- Material properties
- Various geometric primitives

## Usage

```bash
make
./miniRT <scene_file.rt>
```

### Scene File Format

Scene files use the `.rt` format to define:
- Camera position and orientation
- Light sources and ambient lighting
- Objects with their properties (position, size, color, material)

Example:

```
# Ambient light
A 0.2 255,255,255

# Camera
C 0,0,20 0,0,-1 70

# Light
L 0,20,0 0.7 255,255,255

# Red Sphere
sp 0,0,0 10 255,0,0

# Green Plane
pl 0,10,0 0,1,0 255,0,0

# Blue Cylinder
cy 0,0,0 10 0,0,255
```


## Dependencies
- miniLibX or MLX42
- Math library
- Libft


## Features

🟥 - not implemented yet

🟨 - in development

🟩 - implemented

### Mandatory part

- 🟨 Window management (resizing?, exiting)
- 🟩 3 Simple geometric objects
    * 🟩 Plane
    * 🟩 Sphere
    * 🟩 Cylinder
- 🟩 Objects intersections
- 🟩 Inside of the object
- 🟩 Change object's (unique) properties (diameter, height)
- 🟩 Translation of an object
- 🟩 Rotation of an object
- 🟩 Light management
    * 🟩 Spot brightness
    * 🟩 Hard shadows
    * 🟩 Ambiance lightning
    * 🟩 Diffuse lightning
- 🟩 `.rt` files

### Bonus part

- 🟩 Specular reflection (Phong reflection model)
- 🟩 Color disruption
- 🟩 Colored light
- 🟩 Multi-spot light
- 🟩 2nd degree object(s) (Cone, Hyperboloid)
- 🟩 Bump mapping

### Extras

- 🟩 Skybox (lightning?)
- 🟩 Materials
- 🟩 `.obj` files
- 🟩 Complex objects
- 🟥 Soft shadows
- 🟨 Refraction
- 🟥 Global illumination
- 🟥 Caustic
- 🟩 Multi-threading
