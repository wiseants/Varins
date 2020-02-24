#include "stdafx.h"
#include "MilSystem.h"

using namespace HVision::Matrox;

MilSystem::MilSystem()
{
}

MilSystem::~MilSystem()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
	}
}

MilSystem^ MilSystem::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = gcnew MilSystem();
	}

	return m_pInstance;
}

bool MilSystem::Alloc()
{
	return CMilSystem::Instance()->Alloc(0);
}

void MilSystem::Release()
{
	CMilSystem::Instance()->Release();
}