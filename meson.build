project(
	'usc_core',
	'cpp',
	version : '0.1',
	default_options : [
		'warning_level=3',
		'cpp_std=c++20'
	])

# Headers that are meant to expose functionality that can be used by the consumers of the library
public_headers = include_directories('include')

# code
sources = [
	'src/math/Angle.cpp', 
	'src/math/Coordinates.cpp',
	'src/math/Vectors.cpp',
	'src/phys/Links.cpp',
	'src/txt/Print.cpp'
]

# main target
libusc_core = library(
	'usc_core',
	sources,
	install : true,
	include_directories : public_headers
)

# dependency object required to act as a meson subproject
libusc_core_dep = declare_dependency(
	include_directories : public_headers,
	link_with : libusc_core
)

# test executable
executable('usc_test', 
	'src/main.cpp',
	include_directories : public_headers,
	link_with : libusc_core
)
