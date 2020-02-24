#include "stdafx.h"
#include "MilApplication.h"

using namespace HVision::Matrox;

MilApplication::MilApplication()
{
}

MilApplication::~MilApplication()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
	}
}

MilApplication^ MilApplication::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = gcnew MilApplication();
	}

	return m_pInstance;
}

bool MilApplication::Alloc()
{
	return CMilApplication::Instance()->Alloc();
}

void MilApplication::Release()
{
	CMilApplication::Instance()->Release();
}

void MilApplication::RunErrorHandler()
{
	CMilApplication::Instance()->RunErrorHandler();
}

bool MilApplication::IsValid()
{
	return CMilApplication::Instance()->IsValid();
}

void MilApplication::SetMilSysErrMsg(BOOL fDisplay)
{
	CMilApplication::Instance()->SetMilSysErrMsg(fDisplay);
}
