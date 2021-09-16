#pragma once

#include "MinHook/MinHook.h"

#include <memory>

namespace Hook
{
	class CFunction
	{
	public:
		inline bool Initialize(void* pTarget, void* pDetour) {
			return (MH_CreateHook(pTarget, pDetour, &m_pOriginal) == MH_STATUS::MH_OK);
		}
		
	public:
		template<typename FN>
		inline FN Original() const {
			return reinterpret_cast<FN>(m_pOriginal);
		}

	private:
		void* m_pOriginal = nullptr;
	};

	class CTable
	{
	public:
		inline bool Initialize(void* pTable)
		{
			m_pBase = reinterpret_cast<unsigned int**>(pTable);

			while (reinterpret_cast<unsigned int*>(*m_pBase)[m_nSize])
				m_nSize += 1u;

			m_pOriginals = std::make_unique<void* []>(m_nSize);

			return (m_pBase && m_nSize);
		}

		inline bool Hook(void* pDetour, const unsigned int nIndex)
		{
			if (m_pBase && m_nSize)
				return (MH_CreateHook((*reinterpret_cast<void***>(m_pBase))[nIndex], pDetour, &m_pOriginals[nIndex]) == MH_STATUS::MH_OK);

			return false;
		}

	public:
		template<typename FN>
		inline FN Original(const unsigned int nIndex) const {
			return reinterpret_cast<FN>(m_pOriginals[nIndex]);
		}

	private:
		unsigned int**            m_pBase = 0u;
		unsigned int		      m_nSize = 0u;
		std::unique_ptr<void* []> m_pOriginals;
	};
}