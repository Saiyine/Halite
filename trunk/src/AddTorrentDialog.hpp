
//         Copyright Eoin O'Callaghan 2006 - 2008.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#define ID_ADD_TORRENT_BEGIN	 	11000
#define HAL_ADJUST_DLG_HOLDER		ID_ADD_TORRENT_BEGIN + 1

#ifndef RC_INVOKED

#include <boost/function.hpp>
#include "HaliteListViewDlg.hpp"
#include "halTorrent.hpp"

class AddTorrentDialog :
	public ATL::CDialogImpl<AddTorrentDialog>,
	public ATL::CAutoSizeWindow<AddTorrentDialog, true>,
    public CWinDataExchangeEx<AddTorrentDialog>,
	private hal::IniBase<AddTorrentDialog>
{
protected:
	typedef AddTorrentDialog thisClass;
	typedef ATL::CDialogImpl<thisClass> baseClass;
	typedef ATL::CAutoSizeWindow<thisClass, true> autosizeClass;
	typedef hal::IniBase<thisClass> iniClass;

public:
	AddTorrentDialog(wstring& d, wstring& m, bool& u, bool& p, bool& c) :	  
		iniClass("AddTorrentDialog", "settings"),
		rect_(0,0,0,0),
		adjustDlg_(d, m, u),
		startPaused_(p),
		compactStorage_(c)
	{ 
		load_from_ini(); 
	}

	~AddTorrentDialog() 
	{ 
		save_to_ini(); 
	}	

	enum { IDD = HAL_ADD_TORRENT };

    BEGIN_MSG_MAP_EX(thisClass)
        MSG_WM_INITDIALOG(OnInitDialog)

		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		COMMAND_ID_HANDLER_EX(IDOK, OnOk)
		
        CHAIN_MSG_MAP(autosizeClass)
    END_MSG_MAP()
	
    BEGIN_DDX_MAP(thisClass)
        DDX_CHECK(HAL_CHECK_COMPACT, compactStorage_)
        DDX_CHECK(HAL_CHECK_PAUSED, startPaused_)
    END_DDX_MAP()	

#define ADD_BUTTONS_LAYOUT \
	WMB_HEAD(WMB_COLNOMAX(_exp), WMB_COL(_auto), WMB_COL(_auto)), \
		WMB_ROW(_auto,	0, IDOK, IDCANCEL), \
	WMB_END()

	BEGIN_WINDOW_MAP(thisClass, 6, 6, 3, 3)
		WMB_HEAD(WMB_COLNOMAX(_exp)),
			WMB_ROW(_exp,	HAL_ADJUST_DLG), 
			WMB_ROW(_gap,	_d),
			WMB_ROW(_auto,	HAL_CHECK_COMPACT), 
			WMB_ROW(_auto,	HAL_CHECK_PAUSED), 
			WMB_ROW(_auto,	HAL_ADDT_NOTE_TEXT), 
			WMB_ROW(_gap,	_d),
			WMB_ROW(_auto,	ADD_BUTTONS_LAYOUT), 
		WMB_END()
	END_WINDOW_MAP()	

	LRESULT OnInitDialog(HWND hwndFocus, LPARAM lParam)
	{
		if (rect_.left == rect_.right)
		{
			CenterWindow();
			GetWindowRect(rect_);
		}
		else 
		{
			MoveWindow(rect_.left, rect_.top, rect_.right-rect_.left, rect_.bottom-rect_.top, false);		
		}

		adjustDlg_.Create(*this);
		adjustDlg_.ShowWindow(SW_SHOW);
		adjustDlg_.SetDlgCtrlID(HAL_ADJUST_DLG);

		CtrlsInitialize();
		CtrlsArrange();
		
		BOOL retval =  DoAllDataxchange(false);
		return retval;
	}

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return this->IsDialogMessage(pMsg);
	}
	
	void OnCancel(UINT, int, HWND hWnd)
	{
		GetWindowRect(rect_);
		EndDialog(IDCANCEL);
	}
	
	void OnOk(UINT, int, HWND hWnd)
	{
		DoAllDataxchange(true);

		GetWindowRect(rect_);
		EndDialog(IDOK);
	}

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
	{
		ar & boost::serialization::make_nvp("rect", rect_);
	}

private:
	BOOL DoAllDataxchange(bool direction)
	{
		adjustDlg_.DoDataExchange(direction);
		return DoDataExchange(direction);
	}

	HaliteSaveAndMoveToDlg adjustDlg_;

	WTL::CRect rect_;
	bool& startPaused_;
	bool& compactStorage_;
};

#endif // RC_INVOKED
