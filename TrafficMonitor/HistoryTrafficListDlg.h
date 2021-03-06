#pragma once
#include "ListCtrlEx.h"
#include "TabDlg.h"

// CHistoryTrafficListDlg 对话框

class CHistoryTrafficListDlg : public CTabDlg
{
	DECLARE_DYNAMIC(CHistoryTrafficListDlg)

public:
	CHistoryTrafficListDlg(deque<HistoryTraffic>& history_traffics, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHistoryTrafficListDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISTORY_TRAFFIC_LIST_DIALOG };
#endif

protected:
	CListCtrlEx m_history_list;
	CMenu m_menu;

	deque<HistoryTraffic>& m_history_traffics;

	bool m_use_log_scale{ false };		//绘制表示历史流量数值的矩形时是否使用对数比例

	void SaveConfig() const;
	void LoadConfig();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg void OnInitMenu(CMenu* pMenu);
	afx_msg void OnUseLinearScale();
	afx_msg void OnUseLogScale();

	virtual BOOL OnInitDialog();
};
