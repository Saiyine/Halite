
//         Copyright E�in O'Callaghan 2006 - 2008.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define ID_TRACKER_BEGIN	16000
#define HAL_TRACKER_LABEL 	ID_TRACKER_BEGIN + 1
#define HAL_LOGIN_APPLY 	ID_TRACKER_BEGIN + 2
#define HAL_REANNOUNCE	 	ID_TRACKER_BEGIN + 3

#ifndef RC_INVOKED

#pragma once

#include "stdAfx.hpp"
#include "Halite.hpp"

#include "DdxEx.hpp"
#include "EditHilight.hpp"
#include "global/string_conv.hpp"

#include "TrackerListView.hpp"
#include "../HaliteTabPage.hpp"
#include "../HaliteListManager.hpp"
#include "../HaliteDialogBase.hpp"

class AdvTrackerDialog :
	public CHalTabPageImpl<AdvTrackerDialog>,
	public ATL::CAutoSizeWindow<AdvTrackerDialog, false>,
	public CHaliteDialogBase<AdvTrackerDialog>,
	public CWinDataExchangeEx<AdvTrackerDialog>
{
protected:
	typedef AdvTrackerDialog thisClass;
	typedef CHalTabPageImpl<thisClass> baseClass;
	typedef ATL::CAutoSizeWindow<thisClass, false> autosizeClass;
	typedef CHaliteDialogBase<thisClass> dialogBaseClass;

public:
	enum { IDD = HAL_ADVTRACKER };

	AdvTrackerDialog(HaliteWindow& HalWindow) :
		dialogBaseClass(HalWindow),
		m_list("listviews/tracker", "TrackerListView")
	{}

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return this->IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP_EX(thisClass)
		MSG_WM_INITDIALOG(onInitDialog)
		MSG_WM_CLOSE(onClose)

		COMMAND_ID_HANDLER_EX(HAL_LOGIN_APPLY, onLoginApply)
		COMMAND_ID_HANDLER_EX(HAL_REANNOUNCE, onReannounce)
		COMMAND_ID_HANDLER_EX(HAL_TRACKER_LOGINCHECK, onLoginCheck)
		COMMAND_ID_HANDLER_EX(HAL_TRACKER_RESET, onReset)
		COMMAND_ID_HANDLER_EX(HAL_TRACKER_APPLY, onApply)

	//	COMMAND_RANGE_CODE_HANDLER_EX(HAL_TRACKER_USER, HAL_TRACKER_PASS, EN_KILLFOCUS, OnEditKillFocus)

		if (uMsg == WM_FORWARDMSG)
			if (PreTranslateMessage((LPMSG)lParam)) return TRUE;

		CHAIN_MSG_MAP(dialogBaseClass)
		CHAIN_MSG_MAP(autosizeClass)
		CHAIN_MSG_MAP(baseClass)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	BEGIN_DDX_MAP(thisClass)
		DDX_WTLx_WSTRING(userEdit_, username_)
		DDX_WTLx_WSTRING(passEdit_, password_)
    END_DDX_MAP()
	
	static CWindowMapStruct* GetWindowMap();

	LRESULT onInitDialog(HWND, LPARAM);
	void onClose();

	void onLoginCheck(UINT, int, HWND hWnd);
	LRESULT OnEditKillFocus(UINT uCode, int nCtrlID, HWND hwndCtrl);
	void onLoginApply(UINT, int, HWND);
	void onReannounce(UINT, int, HWND);

	void onApply(UINT, int, HWND);
	void onReset(UINT, int, HWND);

	void setLoginUiState();	
	void uiUpdate(const hal::TorrentDetails& tD);
	void focusChanged(const hal::TorrentDetail_ptr pT);
	void trackerListEdited();

protected:
	string current_torrent_name_;
	TrackerListViewCtrl m_list;

	wstring username_;
	wstring password_;

	WTLx::EditHilight userEdit_;
	WTLx::EditHilight passEdit_;
};

#endif // RC_INVOKED
