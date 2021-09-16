#pragma once

#include <string>
#include <utility>

//This is by: kn4ck3r (I don't remember his name correctly probably lol)

#pragma warning (push)
#pragma warning (disable : 6201)
#pragma warning (disable : 6294)

#define FORCE_INLINE __forceinline

namespace Const
{
	constexpr int Atoi(char c)
	{
		return c - '0';
	}
}

template<typename StringType, size_t nLenght>
class CBasicXorString
{
	using ValueType = typename StringType::value_type;
	static constexpr auto nRealLenght = (nLenght - 1);

public:
	constexpr FORCE_INLINE CBasicXorString(ValueType const (&str)[nLenght])
		: CBasicXorString(str, std::make_index_sequence<nRealLenght>()) { }

	inline auto c_str() const
	{
		Decrypt();
		return m_Data;
	}

	inline auto str() const
	{
		Decrypt();
		return StringType(m_Data, m_Data + nRealLenght);
	}

	inline operator StringType() const
	{
		return str();
	}

private:
	template<size_t... nIndices>
	constexpr FORCE_INLINE CBasicXorString(ValueType const (&str)[nLenght], std::index_sequence<nIndices...>)
		: m_Data{ Encrypt(str[nIndices], nIndices)..., '\0' },
		m_bEncrypted(true) { }

	static constexpr auto XORKEY = static_cast<ValueType>
		(
			Const::Atoi(__TIME__[7]) +
			Const::Atoi(__TIME__[6]) * 10 +
			Const::Atoi(__TIME__[4]) * 60 +
			Const::Atoi(__TIME__[3]) * 600 +
			Const::Atoi(__TIME__[1]) * 3600 +
			Const::Atoi(__TIME__[0]) * 36000
			);

	static FORCE_INLINE constexpr auto Encrypt(ValueType c, size_t i) {
		return static_cast<ValueType>(c ^ (XORKEY + static_cast<int>(i)));
	}

	inline void Decrypt() const
	{
		if (m_bEncrypted)
		{
			for (size_t t = 0; t < nRealLenght; t++)
				m_Data[t] = Encrypt(m_Data[t], t);

			m_bEncrypted = false;
		}
	}

	mutable ValueType m_Data[nLenght];
	mutable bool m_bEncrypted;
};
//===========================================================================
template<size_t nLenght>
using XorStrA = CBasicXorString<std::string, nLenght>;
template<size_t nLenght>
using XorStrW = CBasicXorString<std::wstring, nLenght>;
template<size_t nLenght>
using XorStrU16 = CBasicXorString<std::u16string, nLenght>;
template<size_t nLenght>
using XorStrU32 = CBasicXorString<std::u32string, nLenght>;
//===========================================================================
template<typename StringType, size_t nLenght, size_t nLenght2>
inline auto operator==(const CBasicXorString<StringType, nLenght>& lhs, const CBasicXorString<StringType, nLenght2>& rhs)
{
	static_assert(nLenght == nLenght2, "[XorString operator==] Different lenghts!");
	return nLenght == nLenght2 && lhs.str() == rhs.str();
}
//===========================================================================
template<typename StringType, size_t nLenght>
inline auto operator==(const StringType& lhs, const CBasicXorString<StringType, nLenght>& rhs)
{
	return lhs.size() == nLenght && lhs == rhs.str();
}
//===========================================================================
template<typename StreamType, typename StringType, size_t nLenght>
inline auto& operator<<(StreamType& lhs, const CBasicXorString<StringType, nLenght>& rhs)
{
	lhs << rhs.c_str();
	return lhs;
}
//===========================================================================
template<typename StringType, size_t nLenght, size_t nLenght2>
inline auto operator+(const CBasicXorString<StringType, nLenght>& lhs, const CBasicXorString<StringType, nLenght2>& rhs)
{
	return lhs.str() + rhs.str();
}
//===========================================================================
template<typename StringType, size_t nLenght>
inline auto operator+(const StringType& lhs, const CBasicXorString<StringType, nLenght>& rhs)
{
	return lhs + rhs.str();
}
//===========================================================================
template<size_t nLenght>
constexpr FORCE_INLINE auto XorStr(char const (&str)[nLenght])
{
	return XorStrA<nLenght>(str);
}
//===========================================================================
template<size_t nLenght>
constexpr FORCE_INLINE auto XorStr(wchar_t const (&str)[nLenght])
{
	return XorStrW<nLenght>(str);
}
//===========================================================================
template<size_t nLenght>
constexpr FORCE_INLINE auto XorStr(char16_t const (&str)[nLenght])
{
	return XorStrU16<nLenght>(str);
}
//===========================================================================
template<size_t nLenght>
constexpr FORCE_INLINE auto XorStr(char32_t const (&str)[nLenght])
{
	return XorStrU32<nLenght>(str);
}
//===========================================================================

#define _(str) XorStr(str).c_str()

#pragma warning (pop)