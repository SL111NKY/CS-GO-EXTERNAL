#pragma once
#include "stdafx.h"
#include "Offsets.h"

namespace quickmaths {

	Vector::Vector3 ClampIt(Vector::Vector3& angles) {

		if (angles.y > 180.0f)
			angles.y = 180.0f;
		else if (angles.y < -180.0f)
			angles.y = -180.0f;

		if (angles.x > 89.0f)
			angles.x = 89.0f;
		else if (angles.x < -89.0f)
			angles.x = -89.0f;
			angles.z = 0;

			return angles;
	}

	Vector::Vector3 NormalizeIt(Vector::Vector3& angles) {

		if (angles.x > 180.f)
			angles.x -= 360;

		if (angles.x < -180.f)
			angles.x += 360.f;

		if (angles.y > 180.f)
			angles.y -= 360;

		if (angles.y < -180.f)
			angles.y += 360.f;

		if (angles.z > 180.f)
			angles.z -= 360;

		if (angles.z < -180.f)
			angles.z += 360.f;
		return angles;
	}

	bool ClampAngles(Vector::Vector3& angles) {

		Vector::Vector3 a = angles;
		NormalizeIt(a);
		ClampIt(a);

		if (isnan(a.x) || isinf(a.x) ||
			isnan(a.y) || isinf(a.y) ||
			isnan(a.z) || isinf(a.z)) {
			return false;
		}

		angles = a;
		return true;
	}

}