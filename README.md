<h1 align="center">
	 Graphic Lib
</h1>

<p align="center">
	<b><i>My graphic library developed for 42 cursus</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/rochblondiaux/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/glib?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/glib?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/glib?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/glib?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/glib?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to make graphic development easier in C using the minilibx.

## 📑 Index

`@root`

* [**📁 includes:**](includes/) contains all prototypes, structures and libraries includes.
* [**📁 mlx:**](mlx/) contains the minilibx sources.
* [**📁 srcs:**](srcs/) contains all project sources files.
  * [**📁 maths:**](srcs/maths/) contains all maths related files. 
  * [**📁 maths:**](srcs/maths/) contains all maths related files.
  * [**📁 vectors:**](srcs/graphics/) contains all vectors (2D/3D) related files.
  * [**📁 utils:**](srcs/utils/) contains all utilities files.

`@/srcs/glib.c`
* `glib_init` - Initialize window and image with minilibx.
* `glib_start` - Initialize & start rendering.
* `glib_stop` - Destroy image and window.
* `register_loop_hook` - mlx_loop_hook function wrapped.
* `rregister_key_hook` - mlx_key_hook function wrapped.

`@/graphics/draw.c`
* `draw_pixel` - Draw a pixel on image.
* `draw_line` - Draw line between to vector.

`@/maths/projections.c`
* `isometric_projection` - Project point with an isometric function.
* `parallel_projection` - Project point with a parallel function.

`@/maths/rotations.c`
* `rotate_x` - Rotate a 3D vector on x-axis.
* `rotate_y` - Rotate a 3D vector on y-axis.
* `rotate_z` - Rotate a 3D vector on z-axis.

`@/vectors/vector2f.c`
* `v2f` - Create a 2D vector from its coordinates.
* `add_v2f` - Add 2D vector's coordinates.
* `sub_v2f` - Subtract 2D vector's coordinates.
* `mul_v2f` - Multiply 2D vector's coordinates.
* `div_v2f` - Divide 2D vector's coordinates.

`@/vectors/vector3f.c`
* `v3f` - Create a 3D vector from its coordinates.
* `add_v3f` - Add 3D vector's coordinates.
* `sub_v3f` - Subtract 3D vector's coordinates.
* `mul_v3f` - Multiply 3D vector's coordinates.
* `div_v3f` - Divide 3D vector's coordinates.

`@/utils/color.c`
* `convert_rgba` - Convert rgba to hexadecimal color.
* `rgb` - Convert rgb to hexadecimal color.
* `get_light` - Get light at a certain point in space.

`@/utils/math_utils.c`
* `v2f_difference` - Get absolute difference between to 2D vector.
* `get_sign` - 
* `deg_to_rad` - Convert degrees to radian.
* `percent` - Get percentage from min, max & current.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

_Coming soon_

## 📋 Testing

_Coming soon_