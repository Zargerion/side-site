#pragma once

namespace jagam {
namespace Math {

template<typename T>
struct jaVector2 {
	union { struct { T x, y; }; T c[2]; };
	jaVector2() noexcept { }
	jaVector2(T _x, T _y) noexcept :x(_x),y(_y) { }
	jaVector2(const jaVector2&) noexcept = default;
	jaVector2& operator=(const jaVector2&) noexcept = default;
	explicit jaVector2(const T (&coords)[2]) noexcept  :x(coords[0]),y(coords[1]) { }
	bool operator==(const jaVector2& v) const noexcept { return x == v.x && y == v.y; }
	bool operator!=(const jaVector2& v) const noexcept { return x != v.x || y != v.y; }
};
template<typename T>
struct jaVector3 {
	union { struct { T x, y, z; }; T c[3]; };
	jaVector3() noexcept { }
	jaVector3(T _x, T _y, T _z) noexcept :x(_x),y(_y),z(_z) { }
	jaVector3(const jaVector3&) noexcept = default;
	jaVector3& operator=(const jaVector3&) noexcept = default;
	explicit jaVector3(const T (&coords)[3]) noexcept  :x(coords[0]),y(coords[1]),z(coords[2]) { }
	bool operator==(const jaVector3& v) const noexcept { return x == v.x && y == v.y && z == v.z; }
	bool operator!=(const jaVector3& v) const noexcept { return x != v.x || y != v.y || z != v.z; }
};
template<typename T>
struct jaVector4 {
	union { struct { T x, y, z, w; }; T c[4]; };
	jaVector4() { }
	jaVector4(T _x, T _y, T _z, T _w):x(_x),y(_y),z(_z),w(_w) { }
	jaVector4(const jaVector4&) noexcept = default;
	jaVector4& operator=(const jaVector4&) noexcept = default;
	explicit jaVector4(const T (&coords)[4]):x(coords[0]),y(coords[1]),z(coords[2]),w(coords[3]) { }
	bool operator==(const jaVector4& v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
	bool operator!=(const jaVector4& v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }
};

template<typename T>
struct jaQuaternion {
	union { struct { T x, y, z, w; }; T c[4]; };
	jaQuaternion() noexcept { }
	jaQuaternion(T _x, T _y, T _z, T _w) noexcept :x(_x),y(_y),z(_z),w(_w) { }
	jaQuaternion(const jaQuaternion&) noexcept = default;
	jaQuaternion& operator=(const jaQuaternion&) noexcept = default;
	explicit jaQuaternion(const jaVector3<T>& _v, T _w) noexcept  :x(_v.x),y(_v.y),z(_v.z),w(_w) { }
	bool operator==(const jaQuaternion& q) const noexcept { return x == q.x && y == q.y && z == q.z && w == q.w; }
	bool operator!=(const jaQuaternion& q) const noexcept { return x != q.x || y != q.y || z != q.z || w != q.w; }
};

template<typename T>
struct jaMatrix2 { union { T _m[4], m[2][2]; struct { T _00, _01, _10, _11; }; }; };
template<typename T>
struct jaMatrix3 { union { T _m[9], m[3][3]; struct { T _00, _01, _02, _10, _11, _12, _20, _21, _22; }; }; };
template<typename T>
struct jaMatrix4 { union { T _m[16], m[4][4]; }; struct { T _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; }; };

struct jaColour {
	union { struct { float r, g, b, a; }; float c[4]; };
	jaColour() noexcept { }
	jaColour(float _r, float _g, float _b, float _a) noexcept :r(_r),g(_g),b(_b),a(_a) { }
	jaColour(float _r, float _g, float _b) noexcept  :r(_r),g(_g),b(_b),a(1.0f) { }
	jaColour(const jaColour&) noexcept = default;
	jaColour& operator=(const jaColour&) noexcept = default;
	explicit jaColour(const float (&coords)[4]) noexcept  :r(coords[0]),g(coords[1]),b(coords[2]),a(coords[3]) { }
	explicit jaColour(unsigned int argb) noexcept {
		b = (float)(argb      &0xFF)/255.0f;
		g = (float)((argb>>8) &0xFF)/255.0f;
		r = (float)((argb>>16)&0xFF)/255.0f;
		a = (float)((argb>>24)&0xFF)/255.0f;
	}
	bool operator==(const jaColour& c) const noexcept { return r == c.r && g == c.g && b == c.b && a == c.a; }
	bool operator!=(const jaColour& c) const noexcept { return r != c.r || g != c.g || b != c.b || a != c.a; }
};

template<typename T>
struct jaRect {
	T x, y, w, h;
	jaRect() noexcept { }
	jaRect(T _x, T _y, T _w, T _h) noexcept :x(_x), y(_y), w(_w), h(_h) { }
	jaRect(const jaRect&) noexcept = default;
	jaRect& operator=(const jaRect&) noexcept = default;
	bool operator==(const jaRect& c) const noexcept { return x == c.x && y == c.y && w == c.w && h == c.h; }
	bool operator!=(const jaRect& c) const noexcept { return x != c.x || y != c.y || w != c.w || h != c.h; }
};

} // namespace Math
} // namespace jagam