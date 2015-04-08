/*
 * material.h
 *
 *  Created on: Dec 18, 2014
 *      Author: nbingham
 */

#include "core/geometry.h"
#include "standard.h"
#include "opengl.h"

using namespace core;

#ifndef material_h
#define material_h

struct lighthdl;

struct materialhdl
{
	materialhdl();
	virtual ~materialhdl();

	string type;

	virtual void apply(const vector<lighthdl*> &lights) = 0;
	virtual materialhdl *clone() const = 0;
};

struct whitehdl : materialhdl
{
	whitehdl();
	~whitehdl();

	static GLuint vertex;
	static GLuint fragment;
	static GLuint program;

	void apply(const vector<lighthdl*> &lights);
	materialhdl *clone() const;
};

struct solidhdl : materialhdl
{
	solidhdl();
	~solidhdl();

	vec3f emission;
	vec3f ambient;
	vec3f diffuse;
	vec3f specular;
	float shininess;

	static GLuint vertex;
	static GLuint fragment;
	static GLuint program;

	void apply(const vector<lighthdl*> &lights);
	materialhdl *clone() const;
};


struct brickhdl : materialhdl
{
	brickhdl();
	~brickhdl();

	static GLuint vertex;
	static GLuint fragment;
	static GLuint program;

	void apply(const vector<lighthdl*> &lights);
	materialhdl *clone() const;
};

#endif
