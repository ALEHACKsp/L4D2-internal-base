#pragma once

class RecvTable;
enum class EClientClass;

class ClientClass
{
public:
	inline const char* const GetName() const {
		return m_pNetworkName;
	}

	inline const EClientClass GetClassID() const {
		return static_cast<EClientClass>(m_ClassID);
	}

	inline RecvTable* GetRecvTable() const {
		return m_pRecvTable;
	}

	inline ClientClass* GetNext() const {
		return m_pNext;
	}

public:
	void*        m_pCreateFn      = nullptr;
	void*        m_pCreateEventFn = nullptr;
	const char*  m_pNetworkName   = nullptr;
	RecvTable*   m_pRecvTable     = nullptr;
	ClientClass* m_pNext          = nullptr;
	int			 m_ClassID        = 0;
};