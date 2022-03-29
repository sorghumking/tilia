object TilSpreadSheetForm: TTilSpreadSheetForm
  Left = 891
  Top = 309
  Caption = 'Tilia'
  ClientHeight = 448
  ClientWidth = 912
  Color = clBtnFace
  ParentFont = True
  FormStyle = fsMDIChild
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  ShowHint = True
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 912
    Height = 448
    ActivePage = TabSheet2
    Align = alClient
    HotTrack = True
    TabOrder = 0
    TabWidth = 70
    OnChange = PageControl1Change
    OnChanging = PageControl1Changing
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object cxPageControl1: TcxPageControl
        Left = 0
        Top = 0
        Width = 904
        Height = 420
        Align = alClient
        TabOrder = 1
        Properties.ActivePage = cxTabSheet1
        Properties.CustomButtons.Buttons = <>
        Properties.Style = 9
        Properties.TabPosition = tpBottom
        Properties.TabSlants.Positions = [spLeft, spRight]
        TabSlants.Positions = [spLeft, spRight]
        OnChange = cxPageControl1Change
        ClientRectBottom = 400
        ClientRectRight = 904
        ClientRectTop = 0
        object cxTabSheet1: TcxTabSheet
          Caption = 'Data'
          ImageIndex = 0
          DesignSize = (
            904
            400)
          object ProfGrid1: TProfGrid
            Left = 0
            Top = 0
            Width = 904
            Height = 400
            About = 'v3.4.4.11 for C++Builder XE'
            ColCount = 256
            RowCount = 1024
            FixedCols = 8
            FixedRows = 3
            DefaultColWidth = 64
            DefaultRowHeight = 18
            EditControlOptions = [ecoAutoIncreaseRowHeight, ecoAutoIncreaseColumnWidth, ecoUseEditFontColor, ecoUseCellFont, ecoMakeFlat]
            EditorOptions = [eoAutoIncreaseRowHeight, eoShowOnChar, eoClearOnChar, eoCursorAtEnd, eoAllowPaste, eoPreserveInnerBorders]
            FixedGridLineColor = clGray
            GridLineWidth = 1
            Options = [pgoFixedVertLine, pgoFixedHorzLine, pgoVertLine, pgoHorzLine, pgoRangeSelect, pgoRowSizing, pgoColSizing, pgoEditing, pgoTabs, pgoAutoIncreaseRowHeights, pgoDrawFocusRectangle, pgoMultiLineCells, pgoSelectFixedCols, pgoSelectFixedRows, pgoClearCellOnDel, pgoCut, pgoCopy, pgoPaste, pgoAddColsOnPaste, pgoAddRowsOnPaste]
            PrintFooter.Font.Charset = DEFAULT_CHARSET
            PrintFooter.Font.Color = clWindowText
            PrintFooter.Font.Height = -13
            PrintFooter.Font.Name = 'Arial'
            PrintFooter.Font.Style = []
            PrintHeader.Font.Charset = DEFAULT_CHARSET
            PrintHeader.Font.Color = clWindowText
            PrintHeader.Font.Height = -13
            PrintHeader.Font.Name = 'Arial'
            PrintHeader.Font.Style = []
            SortColumn = 1
            SpreadsheetEnabled = True
            SpreadsheetHeaders = True
            SpreadsheetOptions = [soExcelStyleHeadings, soExcelStyleHeadingHighlight, soExcelStyleSelection, soExcelStyleNavigation, soExcelStyleComments, soColRowHeadingClickSelect, soMouseBuildUpFormula]
            WordWrap = False
            SpreadsheetStyle = ssExcelXP
            SelectionColor = 15387318
            Align = alClient
            Ctl3D = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentCtl3D = False
            ParentFont = False
            ParentShowHint = False
            PopupMenu = PopupMenu1
            ShowHint = True
            TabOrder = 0
            UsedColumns = <>
            UsedRows = <>
            UsedCells = <>
            OnClick = ProfGrid1Click
            OnKeyDown = ProfGrid1KeyDown
            OnMouseDown = ProfGrid1MouseDown
            OnCellChanged = ProfGrid1CellChanged
            OnCellCleared = ProfGridCellCleared
            OnCellExit = ProfGrid1CellExit
            OnCheckBoxChanged = ProfGrid1CheckBoxChanged
            OnClearCell = ProfGridClearCell
            OnCutCell = ProfGridCutCell
            OnGetEditControl = ProfGrid1GetEditControl
            OnPaste = ProfGridPaste
            OnPastePlainText = ProfGrid1PastePlainText
            OnEndPaste = ProfGrid1EndPaste
            OnBeforePaste = ProfGrid1BeforePaste
            ColWidths = (
              35
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64)
            RowHeights = (
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              17
              17
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18
              18)
          end
          object cxComboBox3: TcxComboBox
            Left = 56
            Top = 80
            TabStop = False
            BeepOnEnter = False
            Properties.Alignment.Vert = taBottomJustify
            Properties.BeepOnError = True
            Properties.DropDownSizeable = True
            Properties.ReadOnly = False
            Properties.Sorted = True
            Properties.OnCloseUp = cxComboBox3PropertiesCloseUp
            Style.BorderStyle = ebsNone
            Style.Edges = [bLeft, bTop, bRight, bBottom]
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.Shadow = False
            Style.TransparentBorder = True
            Style.ButtonStyle = btsHotFlat
            Style.ButtonTransparency = ebtNone
            Style.PopupBorderStyle = epbsDefault
            StyleDisabled.BorderStyle = ebsSingle
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.BorderStyle = ebsSingle
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.BorderStyle = ebsSingle
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 1
            Visible = False
            OnClick = cxComboBox3Click
            OnExit = cxComboBox3Exit
            Width = 64
          end
          object cxComboBox4: TcxComboBox
            Left = 57
            Top = 100
            TabStop = False
            BeepOnEnter = False
            Properties.Alignment.Vert = taBottomJustify
            Properties.BeepOnError = True
            Properties.DropDownSizeable = True
            Properties.ReadOnly = False
            Properties.Sorted = True
            Style.BorderStyle = ebsNone
            Style.Edges = [bLeft, bTop, bRight, bBottom]
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.Shadow = False
            Style.TransparentBorder = True
            Style.ButtonStyle = btsHotFlat
            Style.ButtonTransparency = ebtNone
            Style.PopupBorderStyle = epbsDefault
            StyleDisabled.BorderStyle = ebsSingle
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.BorderStyle = ebsSingle
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.BorderStyle = ebsSingle
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 2
            Visible = False
            OnExit = cxComboBox4Exit
            Width = 63
          end
          object cxComboBox5: TcxComboBox
            Left = 57
            Top = 120
            TabStop = False
            BeepOnEnter = False
            Properties.Alignment.Vert = taBottomJustify
            Properties.BeepOnError = True
            Properties.DropDownSizeable = True
            Properties.ReadOnly = False
            Properties.Sorted = True
            Style.BorderStyle = ebsNone
            Style.Edges = [bLeft, bTop, bRight, bBottom]
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.Shadow = False
            Style.TransparentBorder = True
            Style.ButtonStyle = btsHotFlat
            Style.ButtonTransparency = ebtNone
            Style.PopupBorderStyle = epbsDefault
            StyleDisabled.BorderStyle = ebsSingle
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.BorderStyle = ebsSingle
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.BorderStyle = ebsSingle
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 3
            Visible = False
            OnExit = cxComboBox5Exit
            Width = 63
          end
          object cxDateEdit2: TcxDateEdit
            Left = 127
            Top = 40
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            TabOrder = 4
            Visible = False
            OnExit = cxDateEdit2Exit
            Width = 65
          end
          object cxCheckComboBox4: TcxCheckComboBox
            Left = 56
            Top = 140
            Properties.ShowEmptyText = False
            Properties.DropDownSizeable = True
            Properties.Items = <>
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            TabOrder = 5
            Visible = False
            OnExit = cxCheckComboBox4Exit
            Width = 64
          end
          object cxComboBox6: TcxComboBox
            Left = 126
            Top = 60
            Properties.DropDownRows = 12
            Properties.DropDownSizeable = True
            Properties.ReadOnly = False
            Properties.Sorted = True
            Style.BorderStyle = ebsNone
            Style.Edges = [bLeft, bTop, bRight, bBottom]
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.Shadow = False
            Style.TransparentBorder = False
            Style.ButtonStyle = btsHotFlat
            Style.ButtonTransparency = ebtNone
            Style.PopupBorderStyle = epbsDefault
            StyleDisabled.BorderStyle = ebsSingle
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.BorderStyle = ebsSingle
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.BorderStyle = ebsSingle
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 6
            Visible = False
            OnExit = cxComboBox6Exit
            Width = 65
          end
          object Panel2: TPanel
            Left = 679
            Top = 167
            Width = 185
            Height = 137
            BevelOuter = bvNone
            TabOrder = 7
            Visible = False
            object Label23: TLabel
              Left = 8
              Top = 8
              Width = 28
              Height = 13
              Caption = 'Style:'
            end
            object LabeledEdit16: TLabeledEdit
              Left = 8
              Top = 68
              Width = 132
              Height = 21
              EditLabel.Width = 23
              EditLabel.Height = 13
              EditLabel.Caption = 'Deg:'
              TabOrder = 0
              OnExit = LabeledEdit16Exit
            end
            object LabeledEdit13: TLabeledEdit
              Left = 8
              Top = 68
              Width = 44
              Height = 21
              EditLabel.Width = 23
              EditLabel.Height = 13
              EditLabel.Caption = 'Deg:'
              TabOrder = 1
              OnExit = LabeledEdit13Exit
            end
            object LabeledEdit15: TLabeledEdit
              Left = 51
              Top = 68
              Width = 88
              Height = 21
              EditLabel.Width = 20
              EditLabel.Height = 13
              EditLabel.Caption = 'Min:'
              TabOrder = 2
              OnExit = LabeledEdit15Exit
            end
            object LabeledEdit3: TLabeledEdit
              Left = 8
              Top = 68
              Width = 44
              Height = 21
              EditLabel.Width = 23
              EditLabel.Height = 13
              EditLabel.Caption = 'Deg:'
              TabOrder = 3
              OnExit = LabeledEdit3Exit
            end
            object LabeledEdit9: TLabeledEdit
              Left = 51
              Top = 68
              Width = 44
              Height = 21
              EditLabel.Width = 20
              EditLabel.Height = 13
              EditLabel.Caption = 'Min:'
              TabOrder = 4
              OnExit = LabeledEdit9Exit
            end
            object LabeledEdit12: TLabeledEdit
              Left = 94
              Top = 68
              Width = 44
              Height = 21
              EditLabel.Width = 21
              EditLabel.Height = 13
              EditLabel.Caption = 'Sec:'
              TabOrder = 5
              OnExit = LabeledEdit12Exit
            end
            object ToolBar3: TToolBar
              Left = 4
              Top = 25
              Width = 221
              Height = 29
              Align = alCustom
              AutoSize = True
              ButtonHeight = 21
              ButtonWidth = 58
              Caption = 'ToolBar1'
              Images = ImageList1
              TabOrder = 6
              object ToolButton5: TToolButton
                Left = 0
                Top = 0
                Caption = 'ToolButton1'
                Down = True
                Grouped = True
                ImageIndex = 0
                Marked = True
                OnClick = ToolButton5Click
              end
              object ToolButton7: TToolButton
                Left = 58
                Top = 0
                Caption = 'ToolButton2'
                Down = True
                Grouped = True
                ImageIndex = 1
                Marked = True
                OnClick = ToolButton7Click
              end
              object ToolButton8: TToolButton
                Left = 116
                Top = 0
                Caption = 'ToolButton3'
                Grouped = True
                ImageIndex = 2
                OnClick = ToolButton8Click
              end
            end
            object cxButton1: TcxButton
              Left = 33
              Top = 108
              Width = 57
              Height = 25
              Caption = 'Ok'
              LookAndFeel.Kind = lfOffice11
              ModalResult = 1
              TabOrder = 7
              OnClick = cxButton1Click
            end
            object cxButton2: TcxButton
              Left = 94
              Top = 108
              Width = 57
              Height = 25
              Caption = 'Cancel'
              LookAndFeel.Kind = lfOffice11
              ModalResult = 2
              TabOrder = 8
            end
            object ComboBox2: TComboBox
              Left = 137
              Top = 68
              Width = 42
              Height = 21
              TabOrder = 9
            end
          end
          object cxPopupEdit3: TcxPopupEdit
            Left = 126
            Top = 80
            Properties.ImmediateDropDownWhenKeyPressed = False
            Properties.PopupControl = Panel2
            Properties.OnCloseUp = cxPopupEdit3PropertiesCloseUp
            Properties.OnPopup = cxPopupEdit3PropertiesPopup
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            Style.PopupBorderStyle = epbsSingle
            StyleDisabled.BorderStyle = ebsNone
            TabOrder = 8
            Visible = False
            OnExit = cxPopupEdit3Exit
            Width = 65
          end
          object cxComboBox11: TcxComboBox
            Left = 126
            Top = 100
            Properties.DropDownListStyle = lsEditFixedList
            Properties.DropDownRows = 12
            Properties.DropDownSizeable = True
            Properties.ReadOnly = False
            Properties.Sorted = True
            Style.BorderStyle = ebsNone
            Style.Edges = [bLeft, bTop, bRight, bBottom]
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.Shadow = False
            Style.TransparentBorder = False
            Style.ButtonStyle = btsHotFlat
            Style.ButtonTransparency = ebtNone
            Style.PopupBorderStyle = epbsDefault
            StyleDisabled.BorderStyle = ebsSingle
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.BorderStyle = ebsSingle
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.BorderStyle = ebsSingle
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 9
            Visible = False
            OnExit = cxComboBox6Exit
            Width = 65
          end
          object cxBlobEdit2: TcxBlobEdit
            Left = 126
            Top = 120
            Properties.BlobEditKind = bekMemo
            Properties.MemoScrollBars = ssVertical
            Style.BorderStyle = ebsNone
            Style.LookAndFeel.Kind = lfUltraFlat
            Style.TransparentBorder = False
            Style.ButtonStyle = btsHotFlat
            StyleDisabled.LookAndFeel.Kind = lfUltraFlat
            StyleFocused.LookAndFeel.Kind = lfUltraFlat
            StyleHot.LookAndFeel.Kind = lfUltraFlat
            TabOrder = 10
            Visible = False
            OnExit = cxBlobEdit2Exit
            Width = 65
          end
          object cxCheckComboBox5: TcxCheckComboBox
            Left = 126
            Top = 140
            BeepOnEnter = False
            Properties.ShowEmptyText = False
            Properties.Items = <>
            Properties.OnCloseUp = cxCheckComboBox5PropertiesCloseUp
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            TabOrder = 11
            Visible = False
            Width = 65
          end
          object cxPopupEdit15: TcxPopupEdit
            Left = 126
            Top = 160
            Properties.PopupClientEdge = True
            Properties.PopupSysPanelStyle = True
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            TabOrder = 12
            Visible = False
            Width = 65
          end
          object Panel6: TPanel
            Left = 316
            Top = 182
            Width = 159
            Height = 189
            Anchors = [akLeft, akTop, akRight, akBottom]
            BevelOuter = bvNone
            Color = 15984090
            ParentBackground = False
            TabOrder = 13
            object Panel23: TPanel
              Left = 0
              Top = 0
              Width = 159
              Height = 40
              Align = alTop
              BevelOuter = bvNone
              Color = 15984090
              ParentBackground = False
              TabOrder = 1
              object Label37: TLabel
                Left = 0
                Top = 0
                Width = 159
                Height = 13
                Align = alTop
                Caption = 'Taphonomic System:'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clNavy
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ExplicitWidth = 99
              end
              object cxComboBox12: TcxComboBox
                Left = 0
                Top = 13
                Align = alTop
                Properties.AutoSelect = False
                Style.BorderStyle = ebsFlat
                Style.ButtonStyle = btsFlat
                TabOrder = 0
                OnClick = cxComboBox12Click
                Width = 159
              end
            end
            object cxCheckListBox1: TcxCheckListBox
              Left = 0
              Top = 40
              Width = 159
              Height = 149
              Align = alClient
              EditValueFormat = cvfStatesString
              Items = <>
              Style.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 0
              OnClickCheck = cxCheckListBox1ClickCheck
              OnDblClick = cxCheckListBox1DblClick
            end
          end
          object AdvControlDropDown3: TAdvControlDropDown
            Left = 129
            Top = 180
            Width = 65
            Height = 19
            BevelInner = bvNone
            BevelOuter = bvNone
            BorderStyle = bsNone
            Ctl3D = False
            EmptyTextFocused = False
            EmptyTextStyle = []
            ParentCtl3D = False
            Visible = False
            DropDownColor = 15984090
            DropDownColorTo = 15785680
            DropDownBorderColor = clNone
            LabelMargin = 0
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
            Version = '1.4.5.7'
            ButtonAppearance.BorderColorHot = 10079963
            ButtonAppearance.BorderColorDown = 4370174
            ButtonAppearance.Color = 16773091
            ButtonAppearance.ColorTo = 16768452
            ButtonAppearance.ColorDisabledTo = 11974326
            ButtonAppearance.ColorDown = 11196927
            ButtonAppearance.ColorDownTo = 7257087
            ButtonAppearance.ColorHot = 15465983
            ButtonAppearance.ColorHotTo = 11332863
            ButtonAppearance.Font.Charset = DEFAULT_CHARSET
            ButtonAppearance.Font.Color = clWindowText
            ButtonAppearance.Font.Height = -11
            ButtonAppearance.Font.Name = 'Tahoma'
            ButtonAppearance.Font.Style = []
            DropDownHeader.Color = 16773091
            DropDownHeader.ColorTo = 16765615
            DropDownHeader.Font.Charset = DEFAULT_CHARSET
            DropDownHeader.Font.Color = 7485192
            DropDownHeader.Font.Height = -11
            DropDownHeader.Font.Name = 'Tahoma'
            DropDownHeader.Font.Style = []
            DropDownHeader.Visible = False
            DropDownHeader.BorderColor = 16765615
            DropDownHeader.Buttons = <>
            DropDownFooter.Color = 16773091
            DropDownFooter.ColorTo = 16765615
            DropDownFooter.Font.Charset = DEFAULT_CHARSET
            DropDownFooter.Font.Color = clNavy
            DropDownFooter.Font.Height = -11
            DropDownFooter.Font.Name = 'Tahoma'
            DropDownFooter.Font.Style = []
            DropDownFooter.Visible = True
            DropDownFooter.BorderColor = 16765615
            DropDownFooter.Buttons = <
              item
                Caption = 'Ok'
              end
              item
                Caption = 'Cancel'
              end>
            DropDownFooter.ButtonAlignment = baLeft
            TabOrder = 14
            OnExit = AdvControlDropDown3Exit
            OnBeforeDropDown = AdvControlDropDown3BeforeDropDown
            OnDropUp = AdvControlDropDown3DropUp
            OnDropDownFooterButtonClick = AdvControlDropDown3DropDownFooterButtonClick
            Control = Panel6
            SelectionColorStyle = 1
            TMSStyle = 4
          end
          object AdvControlDropDown4: TAdvControlDropDown
            Left = 58
            Top = 167
            Width = 65
            Height = 19
            BevelInner = bvNone
            BevelOuter = bvNone
            BorderStyle = bsNone
            Ctl3D = False
            EmptyTextFocused = False
            EmptyTextStyle = []
            ParentCtl3D = False
            Visible = False
            DropDownColor = 15984090
            DropDownColorTo = 15785680
            DropDownBorderColor = clNone
            LabelMargin = 0
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
            Version = '1.4.5.7'
            ButtonAppearance.BorderColor = clSilver
            ButtonAppearance.BorderColorHot = 10079963
            ButtonAppearance.BorderColorDown = 4370174
            ButtonAppearance.Color = 16773091
            ButtonAppearance.ColorTo = 16768452
            ButtonAppearance.ColorDisabledTo = 11974326
            ButtonAppearance.ColorDown = 11196927
            ButtonAppearance.ColorDownTo = 7257087
            ButtonAppearance.ColorHot = 15465983
            ButtonAppearance.ColorHotTo = 11332863
            ButtonAppearance.Font.Charset = DEFAULT_CHARSET
            ButtonAppearance.Font.Color = clNavy
            ButtonAppearance.Font.Height = -11
            ButtonAppearance.Font.Name = 'Tahoma'
            ButtonAppearance.Font.Style = []
            DropDownHeader.Color = 16773091
            DropDownHeader.ColorTo = 16765615
            DropDownHeader.Font.Charset = DEFAULT_CHARSET
            DropDownHeader.Font.Color = clNavy
            DropDownHeader.Font.Height = -11
            DropDownHeader.Font.Name = 'Tahoma'
            DropDownHeader.Font.Style = []
            DropDownHeader.Visible = True
            DropDownHeader.BorderColor = 16765615
            DropDownHeader.Buttons = <
              item
                Caption = 'Select Taxa Groups'
              end>
            DropDownHeader.ButtonAlignment = baLeft
            DropDownFooter.Color = 16773091
            DropDownFooter.ColorTo = 16765615
            DropDownFooter.Font.Charset = DEFAULT_CHARSET
            DropDownFooter.Font.Color = clNavy
            DropDownFooter.Font.Height = -11
            DropDownFooter.Font.Name = 'Tahoma'
            DropDownFooter.Font.Style = []
            DropDownFooter.Visible = True
            DropDownFooter.BorderColor = 16765615
            DropDownFooter.Buttons = <
              item
                Caption = 'Ok'
                ModalResult = 1
              end
              item
                Caption = 'Cancel'
                ModalResult = 2
              end>
            DropDownFooter.ButtonAlignment = baLeft
            TabOrder = 15
            OnExit = AdvControlDropDown4Exit
            OnBeforeDropDown = AdvControlDropDown4BeforeDropDown
            OnDropDownHeaderButtonClick = AdvControlDropDown4DropDownHeaderButtonClick
            OnDropDownFooterButtonClick = AdvControlDropDown4DropDownFooterButtonClick
            Control = Panel7
            SelectionColorStyle = 1
            TMSStyle = 4
          end
          object Panel7: TPanel
            Left = 120
            Top = 205
            Width = 190
            Height = 172
            BevelOuter = bvNone
            Color = 15984090
            ParentBackground = False
            TabOrder = 16
            DesignSize = (
              190
              172)
            object cxCheckComboBox8: TcxCheckComboBox
              Left = 4
              Top = 0
              Properties.ShowEmptyText = False
              Properties.DropDownSizeable = True
              Properties.EditValueFormat = cvfStatesString
              Properties.Items = <>
              Properties.OnCloseUp = cxCheckComboBox8PropertiesCloseUp
              Style.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 0
              Visible = False
              Width = 182
            end
            object AdvColumnGrid1: TAdvColumnGrid
              Left = 4
              Top = 19
              Width = 182
              Height = 147
              Cursor = crDefault
              Anchors = [akLeft, akTop, akRight, akBottom]
              ColCount = 2
              DefaultRowHeight = 16
              DrawingStyle = gdsClassic
              FixedCols = 0
              RowCount = 3
              FixedRows = 0
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 1
              OnDblClick = AdvColumnGrid1DblClick
              HoverRow = True
              HoverRowCells = [hcNormal, hcSelected]
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Clear')
              FixedColWidth = 40
              FixedRowHeight = 16
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              MouseActions.AllRowSize = True
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              SortSettings.DefaultFormat = ssAutomatic
              SortSettings.Column = 0
              SortSettings.IgnoreCase = True
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  HeaderAlignment = taLeftJustify
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 40
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  HeaderAlignment = taLeftJustify
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 138
                end>
              ColWidths = (
                40
                138)
            end
          end
          object AdvControlDropDown5: TAdvControlDropDown
            Left = 819
            Top = 74
            Width = 65
            Height = 19
            BevelInner = bvNone
            BevelOuter = bvNone
            BorderStyle = bsNone
            Ctl3D = False
            EmptyTextFocused = False
            EmptyTextStyle = []
            ParentCtl3D = False
            Visible = False
            DropDownColor = 15984090
            DropDownColorTo = 15785680
            DropDownBorderColor = clNone
            Images = ImageList4
            LabelMargin = 0
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
            Version = '1.4.5.7'
            ButtonAppearance.BorderColor = clSilver
            ButtonAppearance.BorderColorHot = 10079963
            ButtonAppearance.BorderColorDown = 4370174
            ButtonAppearance.Color = 16773091
            ButtonAppearance.ColorTo = 16768452
            ButtonAppearance.ColorDisabledTo = 11974326
            ButtonAppearance.ColorDown = 11196927
            ButtonAppearance.ColorDownTo = 7257087
            ButtonAppearance.ColorHot = 15465983
            ButtonAppearance.ColorHotTo = 11332863
            ButtonAppearance.Font.Charset = DEFAULT_CHARSET
            ButtonAppearance.Font.Color = clNavy
            ButtonAppearance.Font.Height = -11
            ButtonAppearance.Font.Name = 'Tahoma'
            ButtonAppearance.Font.Style = []
            DropDownHeader.Color = 16773091
            DropDownHeader.ColorTo = 16765615
            DropDownHeader.Font.Charset = DEFAULT_CHARSET
            DropDownHeader.Font.Color = clNavy
            DropDownHeader.Font.Height = -11
            DropDownHeader.Font.Name = 'Tahoma'
            DropDownHeader.Font.Style = []
            DropDownHeader.Visible = True
            DropDownHeader.BorderColor = 16765615
            DropDownHeader.Buttons = <
              item
                Caption = 'Original ID'
                ImageIndex = 0
                Width = 80
              end
              item
                Caption = 'Notes'
                ImageIndex = 0
                Width = 60
              end>
            DropDownHeader.ButtonAlignment = baLeft
            DropDownFooter.Color = 16773091
            DropDownFooter.ColorTo = 16765615
            DropDownFooter.Font.Charset = DEFAULT_CHARSET
            DropDownFooter.Font.Color = clNavy
            DropDownFooter.Font.Height = -11
            DropDownFooter.Font.Name = 'Tahoma'
            DropDownFooter.Font.Style = []
            DropDownFooter.Visible = True
            DropDownFooter.BorderColor = 16765615
            DropDownFooter.Buttons = <
              item
                Caption = 'Ok'
              end
              item
                Caption = 'Cancel'
              end>
            DropDownFooter.ButtonAlignment = baLeft
            TabOrder = 17
            SelectionColorStyle = 1
            TMSStyle = 4
          end
          object AdvStringGridXLS: TAdvStringGrid
            Left = 472
            Top = 184
            Width = 201
            Height = 114
            Cursor = crDefault
            ColCount = 7
            DefaultColWidth = 36
            DefaultRowHeight = 18
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 2
            FixedRows = 0
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ScrollBars = ssBoth
            TabOrder = 18
            Visible = False
            HoverRowCells = [hcNormal, hcSelected]
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ControlLook.FixedGradientHoverFrom = clGray
            ControlLook.FixedGradientHoverTo = clWhite
            ControlLook.FixedGradientDownFrom = clGray
            ControlLook.FixedGradientDownTo = clSilver
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Clear')
            FixedColWidth = 36
            FixedRowHeight = 18
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssAutomatic
            Version = '8.3.5.4'
          end
          object cxComboBox15: TcxComboBox
            Left = 56
            Top = 250
            Properties.DropDownRows = 16
            Properties.DropDownSizeable = True
            Properties.DropDownWidth = 180
            Properties.Sorted = True
            Style.BorderStyle = ebsNone
            Style.ButtonStyle = btsHotFlat
            TabOrder = 19
            Visible = False
            OnExit = cxComboBox15Exit
            Width = 121
          end
        end
      end
      object cxComboBox2: TcxComboBox
        Left = 56
        Top = 40
        TabStop = False
        BeepOnEnter = False
        ParentFont = False
        Properties.BeepOnError = True
        Properties.DropDownListStyle = lsEditFixedList
        Properties.DropDownRows = 12
        Properties.PostPopupValueOnTab = True
        Properties.ReadOnly = False
        Properties.Sorted = True
        Properties.OnValidate = cxComboBox2PropertiesValidate
        Style.BorderStyle = ebsNone
        Style.Color = clGradientInactiveCaption
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.ButtonStyle = btsHotFlat
        Style.ButtonTransparency = ebtNone
        Style.IsFontAssigned = True
        TabOrder = 0
        Visible = False
        OnExit = cxComboBox2Exit
        Width = 65
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Metadata'
      ImageIndex = 1
      object PageControl2: TPageControl
        Left = 0
        Top = 0
        Width = 904
        Height = 420
        Margins.Bottom = 0
        ActivePage = TabSheetSite
        Align = alClient
        HotTrack = True
        MultiLine = True
        TabOrder = 0
        OnChange = PageControl2Change
        object TabSheetSite: TTabSheet
          Caption = 'Site'
          OnShow = TabSheetSiteShow
          object ScrollBox1: TScrollBox
            Left = 0
            Top = 21
            Width = 896
            Height = 371
            Align = alClient
            Color = 10841658
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 1
            ExplicitLeft = 20
            ExplicitTop = 18
            object Label1: TLabel
              Left = 284
              Top = 264
              Width = 53
              Height = 13
              Caption = 'Site Notes:'
            end
            object Label5: TLabel
              Left = 16
              Top = 264
              Width = 78
              Height = 13
              Caption = 'Site Description:'
            end
            object Label6: TLabel
              Left = 368
              Top = 16
              Width = 121
              Height = 13
              Caption = 'First Geopolitical Division:'
            end
            object Label7: TLabel
              Left = 368
              Top = 58
              Width = 135
              Height = 13
              Caption = 'Second Geopolitical Division:'
            end
            object Label3: TLabel
              Left = 368
              Top = 100
              Width = 124
              Height = 13
              Caption = 'Third Geopolitical Division:'
            end
            object Label28: TLabel
              Left = 368
              Top = 226
              Width = 84
              Height = 13
              Caption = 'Lake Parameters:'
            end
            object Label29: TLabel
              Left = 368
              Top = 142
              Width = 94
              Height = 13
              Caption = 'Administrative Unit:'
            end
            object cxGroupBox1: TcxGroupBox
              Left = 17
              Top = 68
              Caption = 'Latitude/Longitude'
              ParentShowHint = False
              ShowHint = False
              Style.BorderColor = clWhite
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.TextColor = clWhite
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 13
              Height = 183
              Width = 313
              object Label8: TLabel
                Left = 21
                Top = 76
                Width = 120
                Height = 13
                Alignment = taRightJustify
                Caption = 'North Bounding Latitude:'
              end
              object Label9: TLabel
                Left = 20
                Top = 100
                Width = 121
                Height = 13
                Alignment = taRightJustify
                Caption = 'South Bounding Latitude:'
                Visible = False
              end
              object Label10: TLabel
                Left = 15
                Top = 128
                Width = 126
                Height = 13
                Alignment = taRightJustify
                Caption = 'West Bounding Longitude:'
              end
              object Label11: TLabel
                Left = 19
                Top = 152
                Width = 122
                Height = 13
                Alignment = taRightJustify
                Caption = 'East Bounding Longitude:'
                Visible = False
              end
              object cxPopupEdit4: TcxPopupEdit
                Left = 144
                Top = 72
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit4PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit4PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                StyleDisabled.Color = clSkyBlue
                TabOrder = 0
                OnExit = cxPopupEdit4Exit
                OnKeyDown = cxPopupEdit4KeyDown
                Width = 153
              end
              object cxPopupEdit5: TcxPopupEdit
                Left = 144
                Top = 96
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit5PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit5PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                StyleDisabled.Color = clSkyBlue
                TabOrder = 1
                Visible = False
                OnExit = cxPopupEdit5Exit
                OnKeyDown = cxPopupEdit5KeyDown
                Width = 153
              end
              object cxPopupEdit6: TcxPopupEdit
                Left = 144
                Top = 124
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit6PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit6PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                StyleDisabled.Color = clSkyBlue
                TabOrder = 2
                OnExit = cxPopupEdit6Exit
                OnKeyDown = cxPopupEdit6KeyDown
                Width = 153
              end
              object cxPopupEdit7: TcxPopupEdit
                Left = 144
                Top = 148
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit7PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit7PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                StyleDisabled.Color = clSkyBlue
                TabOrder = 3
                Visible = False
                OnExit = cxPopupEdit7Exit
                Width = 153
              end
              object cxGroupBox2: TcxGroupBox
                Left = 144
                Top = 19
                PanelStyle.Active = True
                Style.BorderColor = clWhite
                Style.BorderStyle = ebsFlat
                Style.LookAndFeel.Kind = lfFlat
                Style.LookAndFeel.NativeStyle = False
                Style.TextColor = clWhite
                StyleDisabled.LookAndFeel.Kind = lfFlat
                StyleDisabled.LookAndFeel.NativeStyle = False
                StyleFocused.LookAndFeel.Kind = lfFlat
                StyleFocused.LookAndFeel.NativeStyle = False
                StyleHot.LookAndFeel.Kind = lfFlat
                StyleHot.LookAndFeel.NativeStyle = False
                TabOrder = 5
                Height = 33
                Width = 153
                object cxRadioButton1: TcxRadioButton
                  Left = 8
                  Top = 8
                  Width = 54
                  Height = 17
                  Caption = 'Point'
                  Checked = True
                  TabOrder = 0
                  TabStop = True
                  OnClick = cxRadioButton1Click
                  LookAndFeel.NativeStyle = True
                end
                object cxRadioButton2: TcxRadioButton
                  Left = 79
                  Top = 8
                  Width = 54
                  Height = 17
                  Caption = 'Box'
                  TabOrder = 1
                  OnClick = cxRadioButton2Click
                  LookAndFeel.NativeStyle = True
                end
              end
              object FlowPanel5: TFlowPanel
                Left = 8
                Top = 22
                Width = 133
                Height = 28
                AutoSize = True
                AutoWrap = False
                BevelOuter = bvNone
                Color = 10841658
                Ctl3D = False
                ParentBackground = False
                ParentCtl3D = False
                TabOrder = 4
                object cxButton27: TcxButton
                  Left = 0
                  Top = 0
                  Width = 28
                  Height = 28
                  Enabled = False
                  LookAndFeel.Kind = lfOffice11
                  LookAndFeel.NativeStyle = True
                  OptionsImage.Glyph.Data = {
                    36090000424D3609000000000000360000002800000018000000180000000100
                    2000000000000009000000000000000000000000000000000000000000000000
                    000000000000000000000000000000000000000000000302020C0201010C0000
                    0000000000000000000000000000000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    00000000000004070714261D184F6242348C9E6A52CACD8A68FA7E513AF44930
                    23A4191717470101010300000000000000000000000000000000000000000000
                    00000000000000000000060403142718104F5E3A268C0B070521020B09262F6A
                    69975AB4BAD46FE3ECFD89D7D6FED29B7EFEDA9574FFD79371FE905E44FE8E5D
                    44FFB1B0B2FE98989BE6402D238D0E09073000000000000000000B07051E3220
                    185B6C463298A46849D5CB7F57FDD18156FFCA835BFE130F0C3A08271F5723AC
                    8CFF60D9D5FF7AEDF5FF77EDF5FF85E0E2FFCEA58AFFD99978FF96634AFFA388
                    7BFFB9BABDFFB9BABDFF93664FFF8E5C41FF7B513BD5B47C5EE1D28C67FFD38B
                    65FFD28961FFD2875FFFD1875FFFA5AC97FF69E0E3FF0A18193A2733305748B7
                    9BFE29AD8CFE5ED4CDFF7FECF4FE7DECF4FE85E7EBFFC6AC96FEAC9185FEBFBD
                    C0FFBDBCC0FEB8B2B1FF94634AFE936247FEA16C51FEDA9877FFD69370FED48E
                    6AFED48C66FFB3A68CFE77D9D9FE63ECF3FF62E9F1FE0918193932373657F5FA
                    F9FEA6DCCEFE6AC5AEFF74D8D0FE88EEF5FE91F0F6FFDCF8FAFEC6C3C6FEC4C3
                    C5FFC2C1C3FEA78473FF98684EFE98664CFEA67257FEDB9E7EFFD99979FEC4A5
                    8BFE89D4D0FF6BEBF2FE6AEBF2FE69ECF2FF68E9F0FE0B171939102A235766C3
                    ABFF97D6C6FFB8E3D8FFCEECE4FFEEF8F6FFFEFEFEFFFEFEFEFFCCC9CCFFC8C4
                    C6FFAE8D7EFF9F6E55FF9F6D53FF9E6C52FFAC785DFFD4AD93FFA2D2CBFF7CEE
                    F5FF78EEF4FF73EDF4FF70ECF2FF84DCEEFFA2C6EAFF11141839112A235748B7
                    99FE46B698FE43B697FF4DB99DFEECF7F4FEFFFEFEFFFDFDFDFEC4CACDFE7AB6
                    BAFF987F6DFEA5735BFFA37259FE947D6AFE84A39CFE90F0F4FF88F0F5FE84F0
                    F5FE82EFF5FF8EE0EEFEA8CAE8FEB0C2E7FFADBFE6FE11141839132B245751BA
                    9DFE4FB99CFE4DB99CFF88D0BDFEFDFDFDFEFEFEFEFFE0F2EEFE6BBAC0FE61B9
                    C0FF68B2B6FE87988FFF6CACAEFE5EB7BEFE6BC5CBFE96F3F8FF92F3F7FE9CE5
                    F0FEB2D2EAFFB7C8E6FEB5C6E6FEB4C6E6FFB0C2E4FE12141839152B25575ABE
                    A3FF58BDA2FF5DBFA5FF89D1BDFFFEFEFEFFFFFEFEFFA1DBCBFF389E8FFF69BF
                    C6FF67BEC5FF67BEC5FF66BEC4FF65BDC3FF74CBD0FFABEBF3FFBDD9EBFFC1D0
                    E6FF94A1CCFFB9C9E2FFBACBE6FFB8C9E6FFB5C7E5FF121418391A2D2857ADDE
                    D1FEEAF5F2FEFEFEFEFFFDFDFDFEFBFCFCFEFEFEFEFFE2F2EEFE2B9277FE4FAD
                    A5FF70C2C9FE6EC3C9FF70C0C6FE7EB1BDFE9AB2C3FECBD7E8FFC8D5E7FEC2D0
                    E3FE333A9CFF909BADFEBACBE1FEBCCEE6FFB9CAE5FE1215183936383857FEFE
                    FEFFFEFEFEFFD7EFE8FF7FCDB7FF66C3A9FF85D0BBFFE5F4F0FFC5D0CDFF3E9B
                    82FF64BCBAFF76C8CDFF76C7CCFF91ABBAFFA7B3C4FFD0DBE9FFCDD9E8FFC2CE
                    E1FF0D15AAFF535870FF99A5B3FFBCCCE1FFBDCEE5FF1315183939393957FDFD
                    FDFEE4F3EFFE74C9B1FF6FC6ADFE6EC5ACFE6DC7ADFF81CEB8FEE4DEDFFECDD5
                    D2FF3D9E85FE75C7C9FF7CCCD0FE80C5CBFEA9B7C5FED3DDE8FFD1DDE8FE929D
                    D5FE0812B5FF30356EFE71787FFE9EA9B7FFB1C0D3FE13151739393A3957FDFD
                    FDFEA1D9C9FE78CAB2FF77C9B1FE77C9B0FE76CAB1FF74C8AFFECED7D5FEE9E2
                    E4FF88BBACFE43A790FF81CFD3FE83D1D4FE9FCFD5FED7E1E9FFD4DFE7FE424F
                    C9FE0C19BDFF172199FE53585BFE89929AFFA1ADBBFE121416393A3A3A57F8FA
                    FAFE82CDB7FE80CDB6FF7FCCB5FE7ECCB5FE7ECDB5FF7DCCB4FED5DCDAFEEBE5
                    E6FFBBD1CAFE349D7DFF59B5A4FE8AD6D8FE9CE1E2FED1F0F3FF959FDEFE1420
                    C9FE131FC7FF101EC2FE333A73FE6D7478FF9DA8B2FE121415393A3A3A57E8F5
                    F1FF88D0BAFF87D0BAFF87D0BAFF86D0BAFF86D1BAFF8CD3BDFFEFE9EAFFF0E9
                    EAFFC5D8D1FF3BA182FF3AA281FF72C7BCFFA5E6E7FFC0EEFAFF2B38D7FF1C28
                    D3FF1A27D1FF1724CEFF1724BFFF666D7CFF9EA8B1FF121415393A3A3A57E8F4
                    F0FE8ED3BDFE8FD4BEFF8DD2BCFE8CD2BDFE8DD4BEFFB4E2D4FEF1EBEDFEF2EC
                    EEFFA8CEC2FE41A687FF40A484FE43A788FE9BDDD7FE839FEEFF242FDBFE1F2A
                    C8FE171C80FF1A27C7FE1927D2FE6874C7FFC4D1D9FE141618393A3A3A57FAFB
                    FBFE9BD7C5FE96D6C2FF94D5C0FE93D5C0FE96D6C2FFEBF6F3FEF4EDEFFEF2ED
                    EFFF68B69DFE48AA8BFF47A989FE46AA88FE6BBFA3FE6880E4FF2B35E0FE1F27
                    94FE222439FF1C239BFE1E2BD8FE5C69D6FFD2DFE5FE151718392F363457F7FA
                    F9FFDFF2ECFFA1DBC8FF9BD8C5FFA0DAC8FFDCF1EAFFFEFEFEFFF7F1F3FFA1CE
                    C0FF58B296FF4EAE90FF4EAF8FFF4DAF8EFF6BC0A3FF759BD5FF303AE3FF2E38
                    DBFF252DB3FF2431D9FF212FDCFF808DDDFFD5E1E6FF1517183926322E57AADD
                    CCFED5EDE5FEEFF8F5FFEAF5F1FEF8FBFAFEFEFEFEFFFDFDFDFEF8F2F4FEF9F3
                    F4FFF5F1F1FEA1D0C0FF55B193FE53B191FE71C1A5FEA6DCCDFF4E5FDFFE323B
                    E2FE2C37E0FF2733DDFE4151DFFED1DCE7FFD6E2E5FE1517183927332F57A9DD
                    CBFEA8DCCBFEA9DECDFFB0E0D0FEB8E3D5FEBBE5D8FFBAE4D6FE80C4AEFE7FC4
                    ADFF7FC4ADFE7EC4ADFF63B89CFE58B495FE77C5A9FEADE2CEFFA7DBCEFE799C
                    D6FE6781DFFF8BA4EEFECEF1FAFED8F7F7FFD7E2E5FE1517183928332F57B0E0
                    D0FFAFE0D0FFAEE0CFFFAEE0CFFFAEE0D0FFAEE0D0FFAEDFCFFF66BCA0FF62B9
                    9DFF62B99DFF61B99CFF60B99BFF5EB89AFF7CC8AEFFAFE3D0FFAEE3CFFFADE3
                    CEFFAAE2CDFFC7F2E9FFDAFDFCFFD8FDFCFFD6F5F6FF1618193A1E24223C8BAA
                    9FBE98BBAFD1A5CDBFE5B1DDCEF8B3E1D2FEB4E2D3FFB3E1D2FE6DBEA2FE6ABB
                    A0F95B9E88D24B7E6DA635564B791B2D264C0C121024181C1A322A33304D404F
                    49685B716984718F839F96B1ACBAB8D3D3D6CBECECF114181835000000000000
                    00000000000000000000000000010506060E0E111021191E1C350F16142D0102
                    0206000000000000000000000000000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000}
                  TabOrder = 0
                  OnClick = cxButton27Click
                end
                object cxButton28: TcxButton
                  Left = 28
                  Top = 0
                  Width = 28
                  Height = 28
                  Hint = 'Update coordinates in Neotoma'
                  LookAndFeel.Kind = lfOffice11
                  LookAndFeel.NativeStyle = True
                  OptionsImage.Glyph.Data = {
                    6E070000424D6E07000000000000360000002800000016000000150000000100
                    20000000000038070000000000000000000000000000000000001C1C1C1C1C1C
                    1C1C12121212000000000000000000000000000000000505050559595959F8F8
                    F8FFDFDFDFFFFFFFFFFF464646460000000018181818E9E9E9F3D9D9D9FFE5E5
                    E5FF7B7B7B891C1C1C1C0000000000000000C5C6C6FFCFD0D2FF898A8A9A0000
                    000000000000000000000000000014141414B6B6B6B7E6E6E6FF9C9C9CFFBCBC
                    BCFF7D7C7C7E0000000013131313D9D9D9FF848484FF6E6E6EFF8D8D8DFFDEDE
                    DEFF7171717100000000BEC0C2FF4F5A62FF8F9396C627272727000000000000
                    0000000000000000000074747478EAEAEAFF989797FF545453FFB2B2B3FF7171
                    727D00000000939393A7A6A6A6FF575757FF4E4F4FFF7E7E7EFFE3E2E2FF7373
                    73737D7E7F8E80898FFF818B8FFF9EA1A2CB7F7F7F7F131313135252525B6666
                    6691969898FFA4A7A8FF8D9092FF414545FF3E474EFFA5ADB7FF79797A7C0000
                    00007878789E808080FF4D4D4CFF4A4A4AFF757576FFFDFDFDFF000000007576
                    77899BA2A5FF707B7FFFCACDCEFF979695BEA8A8A8F7858585FF404446FF5A60
                    62FF596165FF6C777BFF5B6871FF414B56FFC3C2C3FF6A6969712A2A2A2ACDCC
                    CDFF535455FF343A3CFF33393CFFAFB0B0FF000000000101010178787985979D
                    A0FF697072FF8B8E92FF74797DFF6A6E6DFF6C6F71FF373A3BFF2A3338FF5868
                    6FFF757F83FF6C6E6EFF888787FFBDBDBDFDB7B7B7CEFDFCFDFFB4B6B6FF404A
                    4DFF2D373DFF606365FF000000000000000052525252C6C9CAFF586269FF4A59
                    68FF505E6FFF66707BFF777B7EFF474C4DFF303C42FF39484FFF7C8386FFBBBB
                    BBFFB5B4B4FFC1C1C1FFD1D0D0FFE0DBDDFFFFFBFDFFAEACB0FF485258FF393F
                    41FF00000000000000005C5C5C5CBDC1C1FF3F4E58FF3C536DFF435A7BFF4156
                    76FF525F68FF414E51FF39474DFF344146FF545A5DFF5D636AFF909396FFF2F1
                    F1FFDBDEDDFF9AA8A1FFA7B5AAFFB9C7BFFF677375FF39464CFF000000000000
                    00004949484FA5ADAEFF3C4C55FF43586FFF395272FF2E425CFF314148FF3243
                    49FF35454CFF3D4A50FF797E80FF878C91FC6A6D70B2ABABABAC96B0A4CE139A
                    60FF00A35FFF1F9F67FF6E8A82FF414D59FF00000000171717177274749A5F70
                    76FF35464EFF3F474CFF36434FFF32424DFF35484EFF2E424AFF273E51FF495A
                    6BFFB0B2B3FFDCDBD9FB5A5A5A683B3B3B3B0014013C00B771FF00F7B8FF00A9
                    65FF97B5A6FF505863FF0000000049494949EAEDEFFF374C55FF2D424AFF3F45
                    46FF2F383DFF24343DFF30444AFF32464EFF2C4560FF415672FF616B70FF595F
                    65FF9399A1FFC3BEC2C8000F003405B271FF07EDB3FF00A563FFA0BEADFF5960
                    69FF00000000171717176A6D6E98435760FF253B45FF3A474CFF1C282EFF0E1D
                    23FF25373EFF39464BFF39485AFF44576EFF4A585FFF3F4B54FF45515EFFABA6
                    AEE76F8F7BB806AA6DFF10EAB7FF00A564FF65897AFF7A7F88FF000000000000
                    00002C2C2D525B666BFF192D36FF27363EFF101E25FF07191FFF1D2E36FF3B45
                    49FF3A3F42FF3B454BFF5B686EFF707B80FF555F67FF74747DFF789F8AFF0DAB
                    6FFF18E7BAFF00A464FF375F53FFC4C2CAFF00000000000000004D4D4D51A8A8
                    A8EF39474DFF192E38FF162A31FF061B23FF13242CFF28353CFF374044FF424D
                    51FF5E6B71FF707B7FFF6A757AFF5B5E68FF35604DFF19AF76FF21E4BEFF00A2
                    63FF76998AFF3B353A3F0000000000000000141414147B797997647075FF1630
                    3AFF1E343DFF092029FF12242CFF1F2F36FF2E4047FF495A60FF5B6A70FF606E
                    74FF717B80FF6D707BFF396756FF20AE78FF29E2C0FF00A061FF9AB6A4DD0B0B
                    0B0B000000000000000061616161B8B9BBFF26373FFF142F3AFF142C37FF0F25
                    2FFF142932FF24353CFF263942FF37494FFF516066FF59696FFF677277FF6B67
                    77FF3C6454FF2CAE78FF38E3C8FF00A363FF0115063D00000000000000000000
                    00003A3A3A3A9E9EA0D8727F85FF455B63FF263B43FF192E37FF182D36FF1E31
                    39FF22353EFF253841FF384951FF556269FF57686CFF356053FF0E653EFF1EB3
                    82FF25D7BAFF00AA73FF00401A9F0024125D0000000000000000000000002D2D
                    2D326667697D44494B7DA4AAADF55B6A6FFF182C34FF192D35FF25373FFF2135
                    3DFF233840FF3F4C55FF3D5856FF17975BFF30BE92FF00BB95FF00C09CFF00BC
                    97FF35C196FF0D9354FF00000000000000000000000000000000000000000000
                    000050505050D1D3D3FA6C777AFF213239FF142931FF162A33FF172A32FF3441
                    48FF6D7474E9105031844BC199FF3DCFB9FF00B695FF3FD1BAFF4CBF97FF0A41
                    2475000000000000000000000000000000000000000000000000000000003838
                    383854535469A3A8AAFF4D5B61FF1D3039FF253238FF747779FFB9B6B6E00000
                    0000083816724DBC93FF83DFD4FF49B88FFF0838187000000000000000000000
                    0000000000000000000000000000000000000000000000000000000000001B1B
                    1B1B6E6F6F7FD1D5D7FFA0A4A4FFCCCDCDFA3333333400000000000000000442
                    24761EAB67FF033C1F6E0000000000000000}
                  ParentShowHint = False
                  ShowHint = True
                  TabOrder = 1
                  Visible = False
                  OnClick = cxButton28Click
                end
                object cxButton3: TcxButton
                  Left = 56
                  Top = 0
                  Width = 77
                  Height = 28
                  Caption = 'Fuzzy'
                  LookAndFeel.Kind = lfOffice11
                  OptionsImage.Glyph.Data = {
                    E6040000424DE604000000000000360000002800000014000000140000000100
                    180000000000B0040000C40E0000C40E0000000000000000000057391C56381B
                    5A3D1F7E67509A89779A8977A08E7D9C89767F654B967C62988068A18D79A08F
                    7C98816B785F46785F46593C1E62401E55371A573A1C62412060401F5134167F
                    654BC2B4A5C2B4A5CBC2B8BCB0A3B3A392B09983B2A08EC1B09EC1B2A3C0B1A2
                    AA9886AA9886856B50816345775C41614426603F1D5A3A197D654EC2B4A7E6E0
                    DAE6E0DAE0D9D1E5DDD6E3DBD4D5CBC0CEBFB1CBB9A6D5C8BBE0D7CEDACFC4DA
                    CFC4B8A5929D8874A48F7B907860664C3270563CAFA193E0DBD5EDE9E5EDE9E5
                    F1EEEBEDE8E5EAE6E2EBE7E3E7E1DCDFD6CCD9CBBDE9E2D9E4DBD1E4DBD1CBBD
                    ADB2A191A191809A8A78907D6A988776B5A89AD4CCC3E9E5E0E9E5E0F2EEEAED
                    E8E5EDE8E4EEE9E5EDE7E3ECE7E3EDE6E1EDE7E2E1D7CEE1D7CED5C8BBC4B6A9
                    A8998A9F8E7C9C8C7BAA9B8BC5BBB2D6CEC7E6E1DBE6E1DBF1EEEBF3F1EFF3F0
                    EEEFE9E5F2EEECF1EEEBEFEAE6EFEBE7EFEAE5EFEAE5EBE5DFCEC6BDB8ACA09E
                    8E7DADA092C4BAAFD2CAC3E0DAD4E9E5E1E9E5E1F3F1EFF6F7F8FAFAFAF8F8F7
                    F4F2F0F1EDEAF0EBE7F2EEEBEEE8E3EEE8E3EFE9E4E5DED8C1B2A3AA9C8EBDB3
                    A8D4CDC5E1DCD8E9E6E2F2F0EFF2F0EFF8F7F7F9F9F9F8F8F8F8F9F9F9F9F9F9
                    FAFBF8F8F8F3F0EDEEE9E5EEE9E5EFEAE6E9E3DECBC2B7A69787BCB1A5DBD6D1
                    E4DFDBEBE8E4F2F0F0F2F0F0F8F7F7F9F9F9F9F9F9F7F7F7F7F7F7F9F8F7FAF9
                    F8F7F5F5F1EFEEF1EFEEF0EDEAE8E4E1D4CDC5ADA092B4A89CDEDAD4E7E4E0EF
                    ECEBF5F4F4F5F4F4F8F8F8F8F8F9F9F9F9F8F8F8F8F7F7F8F8F8FAF9F9F7F5F4
                    F0EDEAF0EDEAEDEAE6E2DCD7D5CDC4C9C1B8AEA093D5CDC6E3DFDBEDEAE8F6F5
                    F5F6F5F5F8F8F8F9F9F9F9F9F9F7F7F7F9F9F9F9F9F9F9F9F9F4F2F0ECE7E3EC
                    E7E3E6E1DDDFD6CED2C9C1C6BDB3A59686B6ABA0D9D3CDE5E2DFF5F3F3F5F3F3
                    F8F8F8F7F7F7F9F9F9F9F9F9F7F7F7F8F8F8F8F9F9F9F8F8EBE6E2EBE6E2DFD8
                    D0D7CEC5CCC3B9BAAFA3AA9B8BA99A8BB7AB9ED8D2CBF0EEECF0EEECF7F6F6F9
                    F9F9F9F9F9FAF9F9F9F9F9F9F9F9F9F9F9F8F8F7EAE6E2EAE6E2E1DAD3D3CAC1
                    C8BEB4B5A99C948270A59687AFA294C1B6ABDDD7D1DDD7D1F5F3F2F6F5F4F7F5
                    F4F6F5F4F8F6F5F8F6F6F5F3F2F0EEEDE7E3DEE7E3DED6CFC8C0B6ACB4A79AA1
                    9180785F479F8C79AC9F91BEB3A7C9C0B6C9C0B6D6D0CAE4DFDAEFECEBF3F1EF
                    F3F1F0F2F0EFEEEBE9EEEBE8E6E2DEE6E2DED0C7BE9F8E7D98857288735E725A
                    428E7C69A49484C5BBB2D5CFC9D5CFC9D9D2CCCEC5BBD5CEC6E5E1DCE9E5E1E3
                    DFDBE3DFDBE3DFDCDDD8D3DDD8D3CFC7BFB1A4968D7A677E6851593D1F78614A
                    958371D4CDC6D4CCC3D4CCC3DCD5CDCFC7C0AA9C8DD4CCC4D0C8C0CEC5BCCDC5
                    BCCEC6BDBDB1A6BDB1A6B7AA9DA797878E7A6779624A593D1F60432793816FC7
                    BFB7C6BDB2C6BDB2BEB1A5C3BAB0A19181998876A29281AD9E8DAB9C8D9F8C79
                    9685749685749A8977836D5787715C7D664E57391C583B1D6C53399584729481
                    6F94816F846F5A8A766179624A7E67508C77638E7B68907D6A7E67518A75608A
                    7560856F5A71583F5C4023593C1E57391C57391C553618583A1D553819553819
                    5B3E21664B2F765B406A51376B4F336D5337654A2F684B2E61462A61462A5A3D
                    1F583B1D56381B57391C}
                  TabOrder = 2
                  OnClick = cxButton3Click
                end
              end
            end
            object cxComboBox7: TcxComboBox
              Left = 368
              Top = 32
              Hint = 'First geopolitical division'
              BeepOnEnter = False
              ParentFont = False
              ParentShowHint = False
              Properties.ClearKey = 46
              Properties.DropDownListStyle = lsEditFixedList
              Properties.DropDownSizeable = True
              Properties.ImmediatePost = True
              Properties.OnValidate = cxComboBox7PropertiesValidate
              ShowHint = True
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.PopupBorderStyle = epbsFrame3D
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              TabOrder = 0
              OnEnter = cxComboBox7Enter
              OnExit = cxComboBox7Exit
              Width = 169
            end
            object cxComboBox8: TcxComboBox
              Left = 368
              Top = 74
              Hint = 'Second geopolitical division'
              BeepOnEnter = False
              ParentFont = False
              ParentShowHint = False
              Properties.ClearKey = 46
              Properties.DropDownListStyle = lsEditFixedList
              Properties.DropDownSizeable = True
              Properties.ImmediatePost = True
              Properties.OnValidate = cxComboBox8PropertiesValidate
              ShowHint = True
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.LookAndFeel.Kind = lfUltraFlat
              Style.PopupBorderStyle = epbsFrame3D
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              StyleDisabled.LookAndFeel.Kind = lfUltraFlat
              StyleFocused.LookAndFeel.Kind = lfUltraFlat
              StyleHot.LookAndFeel.Kind = lfUltraFlat
              TabOrder = 1
              OnEnter = cxComboBox8Enter
              OnExit = cxComboBox8Exit
              Width = 169
            end
            object cxComboBox9: TcxComboBox
              Left = 368
              Top = 116
              Hint = 'Third geopolitical division'
              BeepOnEnter = False
              ParentFont = False
              ParentShowHint = False
              Properties.ClearKey = 46
              Properties.DropDownListStyle = lsEditFixedList
              Properties.DropDownSizeable = True
              Properties.ImmediatePost = True
              Properties.OnValidate = cxComboBox9PropertiesValidate
              ShowHint = True
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.PopupBorderStyle = epbsFrame3D
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              TabOrder = 2
              OnExit = cxComboBox9Exit
              Width = 169
            end
            object cxComboBox10: TcxComboBox
              Left = 368
              Top = 158
              Hint = 'Administrative unit'
              BeepOnEnter = False
              ParentFont = False
              ParentShowHint = False
              Properties.ClearKey = 46
              Properties.DropDownSizeable = True
              Properties.ImmediatePost = True
              Properties.OnValidate = cxComboBox10PropertiesValidate
              ShowHint = True
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.PopupBorderStyle = epbsFrame3D
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              TabOrder = 3
              OnExit = cxComboBox10Exit
              Width = 169
            end
            object cxTextEdit1: TcxTextEdit
              Left = 368
              Top = 200
              BeepOnEnter = False
              ParentFont = False
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              TabOrder = 4
              OnExit = cxTextEdit1Exit
              Width = 81
            end
            object cxLabel3: TcxLabel
              Left = 368
              Top = 182
              AutoSize = False
              Caption = 'Altitude (m):'
              FocusControl = cxTextEdit1
              Properties.Alignment.Horz = taLeftJustify
              Height = 17
              Width = 81
            end
            object cxTextEdit2: TcxTextEdit
              Left = 456
              Top = 200
              BeepOnEnter = False
              ParentFont = False
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.IsFontAssigned = True
              StyleDisabled.Color = clSkyBlue
              TabOrder = 5
              OnExit = cxTextEdit2Exit
              Width = 81
            end
            object cxLabel4: TcxLabel
              Left = 456
              Top = 182
              AutoSize = False
              Caption = 'Area of Site (ha):'
              FocusControl = cxTextEdit1
              Properties.Alignment.Horz = taLeftJustify
              Height = 17
              Width = 89
            end
            object cxMemo1: TcxMemo
              Left = 16
              Top = 280
              ParentFont = False
              Properties.ScrollBars = ssVertical
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.IsFontAssigned = True
              StyleDisabled.BorderStyle = ebs3D
              StyleDisabled.Color = clSkyBlue
              TabOrder = 6
              OnExit = cxMemo1Exit
              Height = 69
              Width = 253
            end
            object cxMemo2: TcxMemo
              Left = 284
              Top = 280
              ParentFont = False
              Properties.ScrollBars = ssVertical
              Style.BorderStyle = ebs3D
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.IsFontAssigned = True
              StyleDisabled.BorderStyle = ebs3D
              StyleDisabled.Color = clSkyBlue
              TabOrder = 7
              OnExit = cxMemo2Exit
              Height = 69
              Width = 253
            end
            object AdvControlDropDown2: TAdvControlDropDown
              Left = 368
              Top = 242
              Width = 170
              Height = 21
              EmptyTextFocused = False
              EmptyTextStyle = []
              ParentFont = False
              DropDownColor = 15984090
              DropDownColorTo = 15785680
              DropDownBorderColor = clNone
              DropDownWidth = 370
              DropDownHeight = 200
              EditorEnabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Images = ImageList2
              LabelMargin = 0
              LabelFont.Charset = DEFAULT_CHARSET
              LabelFont.Color = clWindowText
              LabelFont.Height = -11
              LabelFont.Name = 'Tahoma'
              LabelFont.Style = []
              Version = '1.4.5.7'
              ButtonAppearance.BorderColorHot = 10079963
              ButtonAppearance.BorderColorDown = 4370174
              ButtonAppearance.Color = 16773091
              ButtonAppearance.ColorTo = 16768452
              ButtonAppearance.ColorDisabledTo = 11974326
              ButtonAppearance.ColorDown = 11196927
              ButtonAppearance.ColorDownTo = 7257087
              ButtonAppearance.ColorHot = 15465983
              ButtonAppearance.ColorHotTo = 11332863
              ButtonAppearance.Font.Charset = DEFAULT_CHARSET
              ButtonAppearance.Font.Color = clWindowText
              ButtonAppearance.Font.Height = -11
              ButtonAppearance.Font.Name = 'Tahoma'
              ButtonAppearance.Font.Style = []
              DropDownHeader.Color = 16773091
              DropDownHeader.ColorTo = 16765615
              DropDownHeader.Font.Charset = DEFAULT_CHARSET
              DropDownHeader.Font.Color = 7485192
              DropDownHeader.Font.Height = -11
              DropDownHeader.Font.Name = 'Tahoma'
              DropDownHeader.Font.Style = []
              DropDownHeader.Visible = False
              DropDownHeader.BorderColor = 16765615
              DropDownHeader.Buttons = <>
              DropDownFooter.Color = 16773091
              DropDownFooter.ColorTo = 16765615
              DropDownFooter.Font.Charset = DEFAULT_CHARSET
              DropDownFooter.Font.Color = 7485192
              DropDownFooter.Font.Height = -11
              DropDownFooter.Font.Name = 'Tahoma'
              DropDownFooter.Font.Style = []
              DropDownFooter.Visible = True
              DropDownFooter.BorderColor = 16765615
              DropDownFooter.Buttons = <
                item
                  Caption = 'Post'
                  ImageIndex = 0
                  Width = 44
                end
                item
                  Caption = 'Cancel'
                  ImageIndex = 1
                  ModalResult = 2
                  Width = 54
                end>
              TabOrder = 8
              OnBeforeDropDown = AdvControlDropDown2BeforeDropDown
              OnBeforeDropUp = AdvControlDropDown2BeforeDropUp
              OnDropDownFooterButtonClick = AdvControlDropDown2DropDownFooterButtonClick
              Control = AdvStringGridLake
              SelectionColorStyle = 1
              TMSStyle = 4
            end
            object AdvStringGridLake: TAdvStringGrid
              Left = 592
              Top = 228
              Width = 169
              Height = 90
              Cursor = crIBeam
              ColCount = 2
              Ctl3D = True
              DefaultRowHeight = 20
              DrawingStyle = gdsClassic
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goTabs]
              ParentCtl3D = False
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 9
              HoverRow = True
              HoverRowCells = [hcNormal, hcSelected]
              OnEditChange = AdvStringGridLakeEditChange
              ActiveCellShow = True
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = []
              ActiveCellColor = 15387318
              AutoColor.PositiveNumber.TextColor = clWindowText
              AutoNumAlign = True
              ColumnHeaders.Strings = (
                'Parameter'
                'Value')
              ColumnSize.Stretch = True
              ControlLook.FixedGradientFrom = clWhite
              ControlLook.FixedGradientTo = clBtnFace
              ControlLook.FixedGradientHoverFrom = 13619409
              ControlLook.FixedGradientHoverTo = 12502728
              ControlLook.FixedGradientHoverMirrorFrom = 12502728
              ControlLook.FixedGradientHoverMirrorTo = 11254975
              ControlLook.FixedGradientHoverBorder = 12033927
              ControlLook.FixedGradientDownFrom = 8816520
              ControlLook.FixedGradientDownTo = 7568510
              ControlLook.FixedGradientDownMirrorFrom = 7568510
              ControlLook.FixedGradientDownMirrorTo = 6452086
              ControlLook.FixedGradientDownBorder = 14991773
              ControlLook.CheckSize = 16
              ControlLook.ControlStyle = csTMS
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              DefaultEditor = edFloat
              EnableHTML = False
              EnhRowColMove = False
              ExcelStyleDecimalSeparator = True
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Clear')
              FixedColWidth = 80
              FixedRowHeight = 20
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = []
              FloatFormat = '%.2f'
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              InvalidEntryIcon = ieError
              MouseActions.CaretPositioning = True
              MouseActions.SizeFixedCol = True
              Navigation.AlwaysEdit = True
              Navigation.AdvanceOnEnter = True
              Navigation.AdvanceOnEnterLoop = False
              Navigation.AdvanceDirection = adTopBottom
              Navigation.AllowCtrlEnter = False
              Navigation.AllowClipboardRowGrow = False
              Navigation.AllowClipboardColGrow = False
              Navigation.CursorAdvance = caLoop
              Navigation.CursorWalkEditor = True
              Navigation.TabAdvanceDirection = adTopBottom
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.ColorTo = 15790320
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              ShowDesignHelper = False
              SortSettings.DefaultFormat = ssAutomatic
              SortSettings.Column = 0
              SortSettings.FixedCols = True
              Version = '8.3.5.4'
              WordWrap = False
              ColWidths = (
                80
                68)
            end
            object FlowPanel6: TFlowPanel
              Left = 18
              Top = 8
              Width = 312
              Height = 45
              AutoSize = True
              AutoWrap = False
              BevelOuter = bvNone
              Color = 10841658
              ParentBackground = False
              TabOrder = 10
              object Panel18: TPanel
                Left = 0
                Top = 0
                Width = 41
                Height = 45
                Align = alLeft
                BevelOuter = bvNone
                Color = 10841658
                ParentBackground = False
                TabOrder = 0
                Visible = False
                object cxButton29: TcxButton
                  Left = 0
                  Top = 8
                  Width = 37
                  Height = 37
                  Hint = 'Update site metadata in Neotoma'
                  LookAndFeel.Kind = lfOffice11
                  OptionsImage.Glyph.Data = {
                    96090000424D9609000000000000360000002800000019000000180000000100
                    2000000000006009000000000000000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    0000F9F9F9FFE9E9E9FFE6E6E6FFFBFBFBFF000000000000000000000000FDFD
                    FDFFE4E4E4FFD8D8D8FFEAEAEAFF00000000000000000000000000000000DDDD
                    DDFFD7D6D7FFECECEDFF00000000000000000000000000000000000000000000
                    0000FEFEFEFFF0F0F0FFB1B1B1FF9C9C9CFFDEDEDEFF00000000000000000000
                    0000E2E2E2FF858585FF7A7A7AFF818181FFC2C2C2FFF4F4F4FF000000000000
                    0000AAACACFF414850FFB3B7BAFF000000000000000000000000000000000000
                    00000000000000000000F0F0F0FFBABABAFF737373FF8E8E8EFFF8F7F7FF0000
                    000000000000EEEEEEFF929292FF6C6C6CFF505151FF646464FFADADADFFFDFD
                    FDFF00000000E8E8E9FF48545DFF616D73FFF5F4F3FF00000000000000000000
                    00000000000000000000D7D8D8FFCACACBFFC0C0C1FF5D5D5DFF272828FF6C71
                    77FFDDDEE1FF0000000000000000C7C7C7FF737373FF565757FF515252FF6767
                    67FFB6B6B6FFFEFEFEFF00000000D0D3D3FF5D686DFF788284FFCACCCEFFFFFE
                    FEFF00000000D9D9D9FFA2A2A2FF434545FF696E70FF888E91FF62696CFF5D65
                    67FF3E4D5BFF6A7482FFFEFDFCFF0000000000000000C1C1C1FF595959FF5151
                    51FF3F4142FF525354FFE3E3E3FF0000000000000000E1E1E2FF6B767AFF606A
                    6EFFA5A7A7FFB8B8B8FF8C8D8DFF636464FF4A4D50FF606668FF404547FF5A67
                    6DFF748084FF657078FF33393FFF9A9898FFE9E9E9FF00000000F9F8F8FF8F8F
                    90FF404445FF374145FF30373AFFA6A7A8FF000000000000000000000000D4D5
                    D6FF6F777AFF72787BFF6C7178FF6B7278FF6F7373FF7D8182FF444748FF161A
                    1CFF45535AFF57666CFF7D8486FF7B7B7AFF838282FFAEAEAEFFD6D6D6FFF4F4
                    F4FFFDFDFDFF919595FF2C373CFF3B454AFF55585AFF00000000000000000000
                    0000E7E7E8FF747C7FFF55626CFF4A5A6CFF505F6FFF606B77FF7A7E81FF5C60
                    61FF333E43FF3D4B51FF3E4C52FFA4A6A7FFCDCDCDFFC4C3C3FFC3C3C3FFC4C4
                    C4FFC7C7C7FFE9E9E9FFFAFAF9FF858A8CFF424F54FF3D4142FF000000000000
                    000000000000E6E7E6FF626B6EFF384B5AFF425874FF485D7AFF3D5476FF5965
                    72FF495457FF344147FF3E4C52FF343F43FF66696CFF555D66FF77797BFFE0E0
                    DFFFD8D8D8FFB6B6B6FFB0B0B0FFCCCCCBFFC3C2C2FF4D5A5EFF404C52FF0000
                    00000000000000000000DFE0E0FF546064FF405260FF435B79FF375175FF2D43
                    62FF334149FF324349FF39474DFF39484EFF3E484BFF6D7376FF5A616AFF989B
                    9FFFFFFFFEFFFBFBFBFF409E73FF008A4AFF008A4AFF42A076FF6E777AFF3649
                    52FF000000000000000000000000989FA1FF42555CFF414D54FF465460FF3646
                    58FF2F3E4BFF34444BFF2E4047FF2F414BFF2D4354FF6C757BFFD3D2D1FFF1F1
                    F0FF000000000000000000000000008949FF00E7A7FF00E7A7FF008949FFB4B8
                    BAFF31444CFF0000000000000000FAF9F9FF58646AFF304A55FF333F43FF383A
                    3AFF2F3940FF2E3F4AFF384B53FF33474DFF293F4FFF2F486AFF5D6A76FF9397
                    97FF9A9B9DFFA4A7AAFFF6F7F7FF00000000008847FF08E2A6FF00E0A2FF0088
                    47FFDFE1E2FF3A4950FF0000000000000000FEFDFDFF69767BFF28424CFF394A
                    51FF464F53FF253138FF17252CFF25383FFF36484DFF344553FF334C70FF4757
                    68FF445155FF2B3540FF434E5CFFDADCDDFF00000000008747FF16E0ACFF00DC
                    A2FF008847FFBABFC0FF46565CFF000000000000000000000000646E73FF1E37
                    42FF2C3E46FF313D41FF0E1B22FF0E1B21FF1F3037FF3C4A4EFF333B40FF4556
                    6AFF475664FF59676CFF5C6770FF434F5CFF8C9297FFEEEEEEFF008746FF23E0
                    B2FF00D9A2FF008847FF6C797EFF889296FF0000000000000000000000008B8D
                    8EFF19282FFF283B45FF213038FF0F1E25FF081A20FF16262EFF374449FF3C43
                    44FF323537FF404C51FF677479FF737C80FF5A646AFF545D62FF7C8183FF0088
                    46FF30DFB7FF00D5A2FF008847FF47575EFFE1E3E5FF00000000000000000000
                    0000E8E6E6FF696D6EFF253942FF1B2F38FF192C33FF031821FF13242AFF1D2C
                    33FF364146FF394246FF4F5D63FF616F75FF6F7A7EFF6A767BFF59656AFF535C
                    60FF008845FF3EDFBDFF00D2A1FF008847FF9BA3A6FF00000000000000000000
                    00000000000000000000696D6EFF273A42FF1C3640FF20343DFF071D27FF1124
                    2CFF1C2C33FF26373FFF3B4D54FF536369FF5C6B71FF616F74FF757D81FF6874
                    7AFF566268FF008845FF4BDFC1FF00CEA0FF008847FFF8F7F7FF000000000000
                    00000000000000000000E7E6E5FF92999BFF293E47FF1F3943FF1F353EFF0B21
                    2BFF122731FF24353CFF263941FF2E4048FF48575DFF55656BFF57676DFF6A75
                    7AFF667277FF636F76FF008744FF58E0C7FF00CAA1FF008946FF000000000000
                    0000000000000000000000000000E7E5E5FF878C8EFF5C696FFF0F2832FF142B
                    35FF1B2F38FF122933FF1E3138FF23363EFF23363FFF304249FF4B5A61FF5867
                    6EFF5D6C71FF505C62FF404C51FF008642FF6AE1CBFF00C9A1FF008744FF0000
                    00330000002600000000000000000000000000000000CECFCFFF8E969AFF7A85
                    8AFF5C696FFF2B3E45FF20343DFF1A2F37FF20333BFF273A42FF1F343DFF2D41
                    49FF4F5D63FF4E5E64FF0F7B4BFF008846FF00AE7FFF00C39EFF00C39EFF00AE
                    80FF008946FF006A39CD00000000000000000000000000000000000000000000
                    000000000000F1F1F2FF838C90FF27383EFF192D36FF24363EFF22353DFF1F33
                    3BFF253941FF364850FF4E585DFF008C4AFF82DCCAFF00C1A0FF00BE9BFF00BE
                    9BFF00C1A0FF83DCCAFF008C4AFF000000000000000000000000000000000000
                    0000000000000000000000000000FBFBFAFF989D9EFF3A474CFF192C34FF1026
                    2FFF1A2E36FF16272FFF3F484BFFA8A9A9FF00000000008844FF8EDBCBFF00B9
                    9DFF00B99DFF8EDBCBFF008844FF000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000D9DADAFF848B
                    8EFF3E4D55FF1A2C33FF3E464AFF8B8C8CFFDEDEDDFF00000000000000000087
                    42FF9AE0D3FF9AE0D3FF008742FF000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    000000000000EAEAEAFFBEC2C3FFA7A9A9FFE5E5E5FF00000000000000000000
                    000000000000008A47FF008A47FF000000000000000000000000}
                  OptionsImage.ImageIndex = 0
                  OptionsImage.Images = cxImageList3
                  TabOrder = 0
                  OnClick = cxButton29Click
                end
              end
              object Panel16: TPanel
                Left = 41
                Top = 0
                Width = 271
                Height = 45
                BevelOuter = bvNone
                Color = 10841658
                ParentBackground = False
                TabOrder = 1
                object Edit1: TEdit
                  Left = 0
                  Top = 24
                  Width = 238
                  Height = 21
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  OnExit = Edit1Exit
                end
                object cxLabel6: TcxLabel
                  Left = 0
                  Top = 6
                  AutoSize = False
                  Caption = 'Site Name:'
                  FocusControl = cxTextEdit1
                  Properties.Alignment.Horz = taLeftJustify
                  Height = 17
                  Width = 89
                end
                object cxButton38: TcxButton
                  Left = 240
                  Top = 18
                  Width = 28
                  Height = 28
                  Hint = 'Check site in Neotoma'
                  OptionsImage.Glyph.Data = {
                    36090000424D3609000000000000360000002800000018000000180000000100
                    2000000000000009000000000000000000000000000000000000000000000000
                    000000000000000000000000000000000000000000000000000000000000F9F9
                    F9FFE9E9E9FFE6E6E6FFFBFBFBFF000000000000000000000000FDFDFDFFE4E4
                    E4FFD8D8D8FFEAEAEAFF00000000000000000000000000000000D7D6D7FFECEC
                    EDFF000000000000000000000000000000000000000000000000FEFEFEFFF0F0
                    F0FFB1B1B1FF9C9C9CFFDEDEDEFF000000000000000000000000E2E2E2FF8585
                    85FF7A7A7AFF818181FFC2C2C2FFF4F4F4FF0000000000000000414850FFB3B7
                    BAFF00000000000000000000000000000000000000000000000000000000F0F0
                    F0FFBABABAFF737373FF8E8E8EFFF8F7F7FF0000000000000000EEEEEEFF9292
                    92FF6C6C6CFF505151FF646464FFADADADFFFDFDFDFF0000000048545DFF616D
                    73FFF5F4F3FF0000000000000000000000000000000000000000D7D8D8FFCACA
                    CBFFC0C0C1FF5D5D5DFF272828FF6C7177FFDDDEE1FF0000000000000000C7C7
                    C7FF737373FF565757FF515252FF676767FFB6B6B6FFFEFEFEFFD0D3D3FF5D68
                    6DFF788284FFCACCCEFFFFFEFEFF00000000D9D9D9FFA2A2A2FF3F4C44FF277E
                    3CFF7C8D87FF62696CFF5D6567FF3E4D5BFF6A7482FFFEFDFCFF000000000000
                    0000C1C1C1FF595959FF515151FF3F4142FF525354FFE3E3E3FF00000000E1E1
                    E2FF6B767AFF606A6EFFA5A7A7FFB8B8B8FF8C8D8DFF57685EFF267E3CFF67DF
                    C7FF267F3CFF536A68FF748084FF657078FF33393FFF9A9898FFE9E9E9FF0000
                    0000F9F8F8FF8F8F90FF404445FF374145FF30373AFFA6A7A8FF000000000000
                    0000D4D5D6FF6F777AFF72787BFF6C7178FF607470FF257E3BFF4FD6B9FF05B6
                    8EFF4ED6B9FF267F3CFF506967FF7D8486FF7B7B7AFF838282FFAEAEAEFFD6D6
                    D6FFF4F4F4FFFDFDFDFF919595FF2C373CFF3B454AFF55585AFF000000000000
                    0000E7E7E8FF747C7FFF55626CFF416163FF257E3BFF32C9A7FF03B992FF00BD
                    98FF01BB94FF4ED6B9FF267F3CFF91A098FFCDCDCDFFC4C3C3FFC3C3C3FFC4C4
                    C4FFC7C7C7FFE9E9E9FFFAFAF9FF858A8CFF424F54FF3D4142FF000000000000
                    0000E6E7E6FF626B6EFF384B5AFF257E3BFF1AC19AFF02BB96FF00BD98FF02B9
                    91FF03BB93FF02BB95FF42D1B2FF267E3BFF4D6261FF77797BFFE0E0DFFFD8D8
                    D8FFD3D3D3FFDDDDDDFFFFFFFEFFE1E0E0FF4D5A5EFF404C52FF000000000000
                    0000DFE0E0FF546064FF267B3BFF04B98DFF00BC98FF01BD98FF01BA95FF257D
                    3BFF0ABF98FF08BD97FF04BA93FF21C5A1FF267E3BFF8A9894FFFFFFFEFFFBFB
                    FBFFF1F1F1FFFCFCFCFFFEFEFFFFFCFBFBFF6E777AFF364952FF000000000000
                    0000989FA1FF42555CFF207436FF99DFD2FF20C4A7FF01BC98FF257D3BFF2F41
                    48FF257D3BFF08BF9BFF07BB95FF03BA93FF21C6A2FF26803CFF040F081D0000
                    000000000000000000000000000000000000B4B8BAFF31444CFF00000000FAF9
                    F9FF58646AFF304A55FF287E31FF99DFD1FF99DFD2FF257D3BFF384B54FF3347
                    4DFF294050FF257D3BFF02BB95FF04B993FF02B992FF1EC4A1FF26803CFF0615
                    0C2B00000000000000000000000000000000DFE1E2FF3A4950FF00000000FEFD
                    FDFF69767BFF28424CFF2C7C43FF27783FFF257D3AFF16252CFF25383FFF3648
                    4EFF344553FF334D71FF257D3BFF03BC97FF01B890FF03B78DFF0EBD94FF267F
                    3BFF040F081D000000000000000000000000BABFC0FF46565CFF000000000000
                    0000646E73FF1E3742FF2C3E46FF313D42FF0E1B22FF0D1B21FF1F3037FF3C4A
                    4FFF343C41FF46576BFF475664FF257D3BFF04BA91FF01B991FF03B88FFF0EBD
                    94FF26803CFF05120A2400000000000000006C797EFF889296FF000000000000
                    00008B8D8EFF19282FFF283B45FF213038FF0F1E25FF071920FF15262EFF3744
                    49FF3D4445FF323537FF404C51FF677479FF257D3BFF01BB96FF01B991FF03B8
                    8EFF06BA8FFF267F3CFF00000000C5C9CAFF47575EFFE1E3E5FF000000000000
                    0000E8E6E6FF696D6EFF253942FF1B2F38FF192C33FF031821FF13242BFF1D2C
                    33FF364247FF394246FF4F5D63FF616F75FF6F7A7EFF257D3BFF02B891FF01B9
                    91FF02BA93FF9AE0D3FF257E3BFF515F64FF9BA3A6FF00000000000000000000
                    000000000000B8B8B9FF273A42FF1C3640FF20343DFF071D27FF11242CFF1C2C
                    33FF26373FFF3B4D54FF536369FF5C6B71FF616F74FF757D81FF257D3BFF02B8
                    91FF01B993FF9ADFD3FF257D3BFF6E797EFFF8F7F7FF00000000000000000000
                    0000E7E6E5FF565D61FF293E47FF1F3943FF1F353EFF0B212BFF122731FF2435
                    3CFF263941FF2E4048FF48575DFF55656BFF57676DFF6A757AFF667277FF257D
                    3BFF01BB96FF99DFD2FF257E3BFFF1F2F2FF0000000000000000000000000000
                    0000E7E5E5FF4E5559FF2C434CFF0F2832FF142B35FF1B2F38FF122933FF1E31
                    38FF23363EFF23363FFF304249FF4B5A61FF58676EFF5D6C71FF5F6D74FF515F
                    66FF257D3BFF9ADFD2FF257E3BFF000000000000000000000000000000000000
                    000000000000CECFCFFF8E969AFF7A858AFF5C696FFF2B3E45FF20343DFF1A2F
                    37FF20333BFF273A42FF1F343DFF2D4149FF4F5D63FF4E5E64FF4C5A5FFF8087
                    89FFECECECFF257E3BFF257E3BFF000000000000000000000000000000000000
                    000000000000000000000000000000000000F1F1F2FF838C90FF27383EFF192D
                    36FF24363EFF22353DFF1F333BFF253941FF364850FF4E585DFFA0A3A4FFF5F4
                    F4FF0000000000000000257E3BFF000000000000000000000000000000000000
                    00000000000000000000000000000000000000000000FBFBFAFF989D9EFF3A47
                    4CFF192C34FF10262FFF1A2E36FF16272FFF3F484BFFA8A9A9FF000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    000000000000000000000000000000000000000000000000000000000000D9DA
                    DAFF848B8EFF3E4D55FF1A2C33FF3E464AFF8B8C8CFFDEDEDDFF000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    000000000000EAEAEAFFBEC2C3FFA7A9A9FFE5E5E5FF00000000000000000000
                    0000000000000000000000000000000000000000000000000000}
                  TabOrder = 2
                  OnClick = cxButton38Click
                end
                object FlowPanel2: TFlowPanel
                  Left = 155
                  Top = 2
                  Width = 84
                  Height = 21
                  AutoSize = True
                  AutoWrap = False
                  BevelOuter = bvNone
                  TabOrder = 3
                  object cxButton34: TcxButton
                    Left = 0
                    Top = 0
                    Width = 21
                    Height = 21
                    LookAndFeel.NativeStyle = True
                    OptionsImage.ImageIndex = 54
                    OptionsImage.Images = cxImageList1
                    TabOrder = 0
                    OnClick = cxButton34Click
                  end
                  object cxButton35: TcxButton
                    Left = 21
                    Top = 0
                    Width = 21
                    Height = 21
                    OptionsImage.ImageIndex = 57
                    OptionsImage.Images = cxImageList1
                    TabOrder = 1
                    OnClick = cxButton35Click
                  end
                  object cxButton36: TcxButton
                    Left = 42
                    Top = 0
                    Width = 21
                    Height = 21
                    OptionsImage.ImageIndex = 56
                    OptionsImage.Images = cxImageList1
                    TabOrder = 2
                    OnClick = cxButton36Click
                  end
                  object cxButton37: TcxButton
                    Left = 63
                    Top = 0
                    Width = 21
                    Height = 21
                    OptionsImage.ImageIndex = 55
                    OptionsImage.Images = cxImageList1
                    TabOrder = 3
                    OnClick = cxButton37Click
                  end
                end
              end
            end
            object cxButton33: TcxButton
              Left = 539
              Top = 26
              Width = 28
              Height = 28
              Hint = 'Get political units from Google gecoding'
              Enabled = False
              LookAndFeel.Kind = lfOffice11
              LookAndFeel.NativeStyle = True
              OptionsImage.Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C006000000000000000000000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FDFBF3FBFCEBF9FEE0F8FEE0F8FEE2F8
                FEEBFAFEFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F8F2B8DAAF9ACF9CC1E5E57DDFF8
                40D5F746D6F744D5F75DDBF89AE9FADAF5FBFBFEFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD2EBD380BA6057A01B75
                B456D2E8E280E1F93FD5F746D6F746D6F741D6F747D6F6B0E6F3DBE6E4EBEBE3
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1E1BB63A8
                325CA0165B9D1874AE65C7DCE37BDDF93FD7F746D6F746D6F744D6F74DD8F6BD
                ECF8DED3C2DF9B5FECDCCAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                C5E2C15FA72F5FA118629F2E769D799BAEC0B7BFE87CBEEF43CEF546D8F746D6
                F744D6F74DD8F6BCECF9DFD5C5F38B3EE49552EDE2D4FEFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFE0F1E46FB14B5EA1165F9D2B87A398B2B6EE7D84EA8389E3AAB2E7
                76BCEE44CFF645D7F744D6F74DD8F6BCECF9DFD5C5F18F46F78532E5A671F0F3
                F0FFFFFFFFFFFFFFFFFFFCFEFD9FCD8F579D125DA0166B9961AEB4E55660E333
                42DB3241DB696FE0A8B6E957C0F042D6F744D6F74DD8F6BCECF9DFD5C5F18F45
                F68A3AED893CE7CAACFDFEFEFFFFFFFFFFFFECF7F07EBF7A78B65B75B36086A8
                A1979DE73A48DD3947DC3847DC3C49DC9AA0E56FBFEE41D4F744D6F74DD8F6BB
                ECF9E0D5C5F18F45F58B3CF78938E29E64F6F2EDFFFFFFFFFFFFDFF4F7CFE6E0
                D0E7E3CDE4E2B2C1E3ABAFE74552DD3341DB3141DB515ADEA3ACE861BFF041D5
                F843D6F753DAF6C4F0F9DFD7C1F69140F98B39F68C3EF0883BF5E1D0FEFFFFFF
                FFFF9BE7F97FE0F97FE0F97FE1F975CCF3A3BDEA9A9BE65D67DF616BE09D9FE5
                92BEED48CAF544D9F841D9F85AD3F6ACCBF29EA4C8BE7868DB7F4DF0883FFB8A
                33DCC4A5FDFFFFFFFFFF6BDFF93FD5F73FD5F73FD5F73FD6F752C3F290BCECA5
                B3E8B1B6E891BDEB51C7F245DBF744D2F743A3ED5686E6828FE5959CE59190D6
                897ABB8969A0C9765AD9B58BFDFFFDFFFFFF6BDFF947D6F747D6F747D6F747D7
                F744D7F741C9F48CCAEEC5D4ED5ED0F341DAF841CBF5488AE98690E4CFCCEBD7
                D8ECD4D7EDD1D5F0D6DCF4B2BAEE7D74C79C8CAEFEFDFCFFFFFF69DEF93FD5F7
                3FD5F73FD5F73FD5F73FD5F739D6F88EE3F4DCEEF05EDEF73DD2F7498EE8999A
                E4E9E8EEBBBEEA7D84E36670E06A73E08990E4CDD0ECD9DCF1747EE0BFC3F3FF
                FFFF8BE5F95ED9F65ED9F55ED9F55ED9F55DD9F55AD8F5A0E4F3DFEEF078E0F5
                4DA6ED848FE4E9E7ED9DA3E64550DD3642DB3945DB3945DB3541DA4F5BDEBBC0
                EAD3D6EB7C85E6E2E4FAE1F6FBDFF1F7E0F4FBE0F3FBE0F3FBE0F3FBDFF4FBE8
                F1F5F1F0EFE4EAEF8490E5C4C7EBC2C4EA4853DD3A46DB404CDC3F4BDC3F4BDC
                3F4BDC3844DB5A65DFE2E3EE9AA0E6ACB2F1F8FAF9E2C3A6FAB180F7B484F7B4
                84F7B484F7B281E9D0BDDEF2F69CCDEF8090E5D9D9EC8890E43643DB3F4BDC3F
                4BDC3F4BDC3F4BDC3F4BDC404BDC3542DBB2B6E9BABFE9A4AAEEFCFFFFE6C7A8
                EE8433F58636F48737F48735F48431E8BE9AD0F4FC5ABAEF859CE7D4D3EC6D76
                E13845DB3F4BDC3F4BDC3F4BDC3F4BDC3F4BDC3F4BDC3946DC8F96E5CDD0EBB0
                B5EFFFFFFFF4F3EEE2A570F48737F48C3FF48C3EF4893AF7C4A1D1F4FD4ABCF1
                7A95E6D5D4EC757EE23743DB3F4BDC3F4BDC3F4BDC3F4BDC3F4BDC3F4BDC3845
                DB979DE5CBCEEBAFB4EFFFFFFFFFFFFFF0E9DEE29A5DF48838F58C3EF4893AF7
                C4A1D2F4FD44CAF45382E5DCD7EC9FA6E73945DB3E4ADC3F4BDC3F4BDC3F4BDC
                3F4BDC3E4ADC3B46DBCBCEEBB3B8E8A4ABF0FFFFFFFFFFFFFFFFFFF0E7DDE59C
                61F38634F68838F7C5A1D2F3FD45D7F7458EE9AAAAE6DFDFED616BE03542DB3E
                4BDC3F4BDC3F4BDC3D49DC3542DB8088E3E8E8EF8991E6C3C8F5FFFFFFFFFFFF
                FFFFFFFEFFFFF2EADEE7B385EC883AF8C29CD1F2FD46D8F741C1F35E82E5D2D0
                EBCECFEB6C75E13A46DB3844DB3743DB3F4BDC858CE4E2E3EDAFB3E98A93EAF5
                F5FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBF9F4DECBE6DBCCCCEFF856D9F8
                4DDBF84EAEF06A7AE2C1C3EAE6E6EEC7C9EAA2A8E7A9AEE8D1D3ECE6E7EEADB2
                E8757EE5E5E7FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD
                FFFFFDFFFEEEFBFEDAF7FDDFF9FFC4D0F68088E78E96E4B5BAE8C7CAEAC9CDEA
                ADB2E8848DE58991E9E4E7FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEEEFFCB8BCF2A9
                AFF0ADB3EFACB1EEA7ADF0C9CDF6F8F8FEFFFFFFFFFFFFFFFFFF}
              TabOrder = 14
              OnClick = cxButton33Click
            end
          end
          object AdvPanel7: TAdvPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 21
            Align = alTop
            BevelInner = bvLowered
            BevelOuter = bvNone
            TabOrder = 0
            UseDockManager = True
            Visible = False
            Version = '2.5.7.4'
            BorderColor = clBtnFace
            BorderWidth = 1
            Caption.Color = clHighlight
            Caption.ColorTo = clNone
            Caption.Font.Charset = DEFAULT_CHARSET
            Caption.Font.Color = clWindowText
            Caption.Font.Height = -11
            Caption.Font.Name = 'Tahoma'
            Caption.Font.Style = []
            Caption.Indent = 0
            DoubleBuffered = True
            StatusBar.Font.Charset = DEFAULT_CHARSET
            StatusBar.Font.Color = clWindowText
            StatusBar.Font.Height = -11
            StatusBar.Font.Name = 'Tahoma'
            StatusBar.Font.Style = []
            FullHeight = 200
            object Label4: TLabel
              Left = 20
              Top = 4
              Width = 82
              Height = 13
              Caption = 'Neotoma SiteID: '
            end
          end
        end
        object TabSheetCollectionUnit: TTabSheet
          Caption = 'Collection Unit'
          ImageIndex = 1
          object ScrollBox2: TScrollBox
            Left = 0
            Top = 21
            Width = 896
            Height = 371
            Align = alClient
            Color = 10841658
            ParentColor = False
            TabOrder = 0
            object Label12: TLabel
              Left = 152
              Top = 8
              Width = 99
              Height = 13
              Caption = 'Collection Unit Type:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label13: TLabel
              Left = 336
              Top = 152
              Width = 125
              Height = 13
              Caption = 'Depositional Environment:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label17: TLabel
              Left = 336
              Top = 56
              Width = 51
              Height = 13
              Caption = 'Collectors:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label18: TLabel
              Left = 16
              Top = 276
              Width = 103
              Height = 13
              Caption = 'Collection Unit Notes:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label26: TLabel
              Left = 336
              Top = 104
              Width = 74
              Height = 13
              Caption = 'Date Collected:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label30: TLabel
              Left = 336
              Top = 200
              Width = 51
              Height = 13
              Caption = 'Substrate:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label32: TLabel
              Left = 336
              Top = 248
              Width = 76
              Height = 13
              Caption = 'Slope Angle ('#176'):'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label33: TLabel
              Left = 456
              Top = 248
              Width = 82
              Height = 13
              Caption = 'Slope Aspect ('#176'):'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object LabeledEdit4: TLabeledEdit
              Left = 57
              Top = 24
              Width = 89
              Height = 21
              EditLabel.Width = 37
              EditLabel.Height = 13
              EditLabel.Caption = 'Handle:'
              EditLabel.Font.Charset = DEFAULT_CHARSET
              EditLabel.Font.Color = clWhite
              EditLabel.Font.Height = -11
              EditLabel.Font.Name = 'Tahoma'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              TabOrder = 0
              OnExit = LabeledEdit4Exit
            end
            object LabeledEdit5: TLabeledEdit
              Left = 336
              Top = 24
              Width = 217
              Height = 21
              EditLabel.Width = 102
              EditLabel.Height = 13
              EditLabel.Caption = 'Collection Unit Name:'
              EditLabel.Font.Charset = DEFAULT_CHARSET
              EditLabel.Font.Color = clWhite
              EditLabel.Font.Height = -11
              EditLabel.Font.Name = 'Tahoma'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              TabOrder = 2
              OnExit = LabeledEdit5Exit
            end
            object LabeledEdit6: TLabeledEdit
              Left = 16
              Top = 120
              Width = 281
              Height = 21
              EditLabel.Width = 76
              EditLabel.Height = 13
              EditLabel.Caption = 'Location in Site:'
              EditLabel.Color = 10841658
              EditLabel.Font.Charset = DEFAULT_CHARSET
              EditLabel.Font.Color = clWhite
              EditLabel.Font.Height = -11
              EditLabel.Font.Name = 'Tahoma'
              EditLabel.Font.Style = []
              EditLabel.ParentColor = False
              EditLabel.ParentFont = False
              TabOrder = 5
              OnExit = LabeledEdit6Exit
            end
            object LabeledEdit10: TLabeledEdit
              Left = 16
              Top = 72
              Width = 281
              Height = 21
              EditLabel.Width = 85
              EditLabel.Height = 13
              EditLabel.Caption = 'Collection Device:'
              EditLabel.Font.Charset = DEFAULT_CHARSET
              EditLabel.Font.Color = clWhite
              EditLabel.Font.Height = -11
              EditLabel.Font.Name = 'Tahoma'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              TabOrder = 3
              OnExit = LabeledEdit10Exit
            end
            object cxCheckComboBox1: TcxCheckComboBox
              Left = 336
              Top = 72
              BeepOnEnter = False
              Properties.ShowEmptyText = False
              Properties.EditValueFormat = cvfStatesString
              Properties.Items = <>
              Properties.OnCloseUp = cxCheckComboBox1PropertiesCloseUp
              Properties.OnInitPopup = cxCheckComboBox1PropertiesInitPopup
              Properties.OnPopup = cxCheckComboBox1PropertiesPopup
              Style.BorderStyle = ebsFlat
              Style.Color = clWhite
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsFrame3D
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 4
              Width = 217
            end
            object Memo4: TMemo
              Left = 16
              Top = 295
              Width = 281
              Height = 60
              TabOrder = 7
              OnExit = Memo4Exit
            end
            object Button4: TButton
              Left = 472
              Top = 52
              Width = 81
              Height = 17
              Caption = 'New Contact'
              TabOrder = 11
              TabStop = False
              Visible = False
              OnClick = Button4Click
            end
            object cxGroupBox3: TcxGroupBox
              Left = 16
              Top = 157
              Caption = 'GPS Coordinates'
              Style.BorderColor = clWhite
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.TextColor = clWhite
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 16
              Height = 113
              Width = 281
              object Label19: TLabel
                Left = 4
                Top = 32
                Width = 61
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Latitude:'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
              end
              object Label20: TLabel
                Left = 4
                Top = 60
                Width = 61
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Longitude:'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
              end
              object LabeledEdit14: TLabeledEdit
                Left = 228
                Top = 28
                Width = 41
                Height = 21
                Hint = 'Potential error in GPD coordinates if known (in m)'
                EditLabel.Width = 47
                EditLabel.Height = 13
                EditLabel.Caption = 'Error (m):'
                EditLabel.Font.Charset = DEFAULT_CHARSET
                EditLabel.Font.Color = clWhite
                EditLabel.Font.Height = -11
                EditLabel.Font.Name = 'Tahoma'
                EditLabel.Font.Style = []
                EditLabel.ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnExit = LabeledEdit14Exit
              end
              object cxPopupEdit8: TcxPopupEdit
                Left = 68
                Top = 28
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit8PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit8PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                TabOrder = 0
                OnExit = cxPopupEdit8Exit
                OnKeyDown = cxPopupEdit8KeyDown
                Width = 150
              end
              object cxPopupEdit9: TcxPopupEdit
                Left = 68
                Top = 56
                BeepOnEnter = False
                ParentFont = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupClientEdge = True
                Properties.PopupControl = Panel2
                Properties.OnCloseUp = cxPopupEdit9PropertiesCloseUp
                Properties.OnPopup = cxPopupEdit9PropertiesPopup
                Style.BorderStyle = ebs3D
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWindowText
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.TextColor = clWindowText
                Style.PopupBorderStyle = epbsFlat
                Style.IsFontAssigned = True
                TabOrder = 1
                OnExit = cxPopupEdit9Exit
                Width = 150
              end
              object LabeledEdit1: TLabeledEdit
                Left = 68
                Top = 83
                Width = 81
                Height = 21
                EditLabel.Width = 60
                EditLabel.Height = 13
                EditLabel.Caption = 'Altitude (m):'
                EditLabel.Font.Charset = DEFAULT_CHARSET
                EditLabel.Font.Color = clWhite
                EditLabel.Font.Height = -11
                EditLabel.Font.Name = 'Tahoma'
                EditLabel.Font.Style = []
                EditLabel.ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                LabelPosition = lpLeft
                ParentFont = False
                TabOrder = 3
                OnExit = LabeledEdit1Exit
              end
            end
            object cxDateEdit1: TcxDateEdit
              Left = 336
              Top = 120
              BeepOnEnter = False
              Properties.DateButtons = [btnClear, btnToday]
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsDefault
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 6
              OnExit = cxDateEdit1Exit
              Width = 137
            end
            object LabeledEdit2: TLabeledEdit
              Left = 336
              Top = 312
              Width = 97
              Height = 21
              EditLabel.Width = 85
              EditLabel.Height = 13
              EditLabel.Caption = 'Water Depth (m):'
              EditLabel.Font.Charset = DEFAULT_CHARSET
              EditLabel.Font.Color = clWhite
              EditLabel.Font.Height = -11
              EditLabel.Font.Name = 'Tahoma'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              TabOrder = 10
              OnExit = LabeledEdit2Exit
            end
            object Panel12: TPanel
              Left = 592
              Top = 168
              Width = 113
              Height = 100
              BevelOuter = bvNone
              TabOrder = 12
              Visible = False
              object cxButton7: TcxButton
                Left = 8
                Top = 12
                Width = 49
                Height = 21
                Caption = 'Degrees'
                LookAndFeel.Kind = lfFlat
                SpeedButtonOptions.GroupIndex = 1
                SpeedButtonOptions.Down = True
                TabOrder = 3
                OnClick = cxButton7Click
              end
              object cxButton8: TcxButton
                Left = 56
                Top = 12
                Width = 49
                Height = 21
                Caption = 'Percent'
                LookAndFeel.Kind = lfFlat
                SpeedButtonOptions.GroupIndex = 1
                TabOrder = 4
                OnClick = cxButton8Click
              end
              object cxSpinEdit1: TcxSpinEdit
                Left = 8
                Top = 40
                BeepOnEnter = False
                Properties.AssignedValues.MinValue = True
                Properties.MaxValue = 90.000000000000000000
                Properties.OnChange = cxSpinEdit1PropertiesChange
                Properties.OnValidate = cxSpinEdit1PropertiesValidate
                Style.BorderStyle = ebs3D
                TabOrder = 0
                Width = 97
              end
              object cxButton9: TcxButton
                Left = 8
                Top = 72
                Width = 45
                Height = 21
                Caption = 'Ok'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 1
                OnClick = cxButton9Click
              end
              object cxButton10: TcxButton
                Left = 60
                Top = 72
                Width = 45
                Height = 21
                Caption = 'Cancel'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 2
                TabOrder = 2
              end
            end
            object cxPopupEdit13: TcxPopupEdit
              Left = 336
              Top = 264
              BeepOnEnter = False
              Properties.ImmediateDropDownWhenKeyPressed = False
              Properties.PopupClientEdge = True
              Properties.PopupControl = Panel12
              Properties.OnInitPopup = cxPopupEdit13PropertiesInitPopup
              Properties.OnValidate = cxPopupEdit13PropertiesValidate
              Style.BorderStyle = ebs3D
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 8
              OnExit = cxPopupEdit13Exit
              Width = 97
            end
            object Panel13: TPanel
              Left = 720
              Top = 136
              Width = 155
              Height = 155
              BevelOuter = bvNone
              Color = clWhite
              TabOrder = 13
              Visible = False
              object Image1: TImage
                Left = 17
                Top = 17
                Width = 119
                Height = 119
                Picture.Data = {
                  07544269746D6170F6A80000424DF6A800000000000036000000280000007800
                  0000780000000100180000000000C0A80000C30E0000C30E0000000000000000
                  0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E9E9A3A3A3FFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDF7474
                  74FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFCACACA4D4D4DFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFADADAD343434CBCBCBFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCC9C9C9C9C9C9323232414141E3E3E3FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDEDED979797E4E4E43434
                  340A0A0AA5A5A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  F2F2F2AFAFAF313131989898FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFB3B3B3383838E1E1E1FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB6B6B63B3B3BE0E0E0FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB6B6B63838
                  38DEDEDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFB6B6B6363636D4D4D4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFEFEFEB8B8B8333333C1C1C1FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBB8B8B8303030A8A8A8FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFEFEFEFCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6B8B8B83030
                  30929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF4F4F49A9A9AFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  F5F5F5B8B8B8303030888888FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDEDEDEA8
                  A8A8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE818181D2D2D2FFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFF4F4F4BABABA2F2F2F828282FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFF8A8A8AC4C4C4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1
                  787878FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBEBC1C1C12F2F2F707070FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFE4E4E4616161F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFF5F5F5565656D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1CBCBCB2F2F
                  2F565656FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF888888919191FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFE9E9E9C5C5C5F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8E8E8E7C7C7CFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  D8D8D8D4D4D43030303E3E3EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7E7E74B4B4BD8D8D8FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDEDE
                  DECACACAFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1575757202020797979E0E0E0FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4D4D44C4C4CDCDC
                  DCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFD0D0D0DBDBDB3131312E2E2EFDFDFDFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9090
                  906E6E6EFCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  B9B9B94C4C4C2A2A2A9E9E9EFCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6E0E0E05E5E
                  5E000000242424D7D7D7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  F7F7F7767676828282FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCFDBDBDB323232282828FCFCFCFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFE6E6E6535353B3B3B3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFF8F8F8F0101010E0E0EB8B8B8E7E7E7FEFEFEFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FDFDFDE2E2E2FAFAFA6161610000006D6D6DFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFB5B5B5555555DBDBDBFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCDDFDFDF3232
                  32212121F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFF9292926D6D6DDFDFDFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFEBEBEB131313121212BFBFBFF7F7F7E9E9E9FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFEEEEEEE5E5E5F7F7F75A5A5A484848FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDADADA797979868686FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  C7C7C7E7E7E7323232131313E6E6E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6595959A5A5A5F4F4F4FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD3D3D31F1F1FBDBDBDFBFBFBDBDB
                  DBFBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E9E9E1E1E1D9D9D95B
                  5B5B969696FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0ADAD
                  AD5B5B5BDCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFC1C1C1EFEFEF333333050505D4D4D4FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF959595737373C5C5
                  C5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAEAEA6666669E9E9E
                  E7E7E7DFDFDFF6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFDFDFDFBFBFBDADADA535353858585FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFEFEFEC4C4C47E7E7E8B8B8BFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBBBBBBF7F7F7333333000000C4C4C4FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E4
                  5E5E5EA9A9A9DADADAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E157
                  5757979797F3F3F3FAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D9525252727272FBFBFBFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFD6D6D6B1B1B1606060DBDBDBFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBABABAF9F9F93333
                  33000000BEBEBEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFF9A9A9A737373C3C3C3F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFD5D5D5494949999999F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEDADADA
                  5353535D5D5DF4F4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBEBC7C7C77B7B7B93
                  9393FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE
                  BBBBBBF9F9F9343434000000B7B7B7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFE2E2E2676767ABABABCACACAFDFDFDFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFC5C5C53A3A3A9E9E9EEEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFCFCFCDADADA535353494949EEEEEEFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                  FBCACACAB1B1B16A6A6ADADADAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFF7F7F7C0C0C0FAFAFA343434000000A4A4A4FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEA0A0A0717171D0D0D0D4D4D4FFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFB7B7B72C2C2CA4A4A4EBEBEBFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8DBDBDB5555553A3A3AE5E5E5FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFD0D0D0D5D5D57878789A9A9AFDFDFDFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFC6C6C6FCFCFC3434340000008A8A8AFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDF757575A2A2A2
                  D1D1D1EAEAEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9A9A9232323A9A9A9E8E8E8FEFEFEFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6DDDD
                  DD5757572B2B2BD9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7E7E7D4D4D4A7A7A7797979D8D8D8
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6CCCCCCFDFDFD3434
                  340000006F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDA4
                  A4A4777777D4D4D4C7C7C7FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9696961C1C1CAEAEAEE5E5
                  E5FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFF2F2F2E0E0E05858581E1E1EC9C9C9FFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCC7C7C7D7
                  D7D77D7D7DA0A0A0FBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1
                  CFCFCFFEFEFE3434340000005F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFDDDDDD848484969696E4E4E4D0D0D0FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF828282151515
                  B2B2B2E4E4E4FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFE3E3E35C5C5C121212BCBCBC
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFCDCDCDE9E9E99B9B9B878787D6D6D6FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFE1E1E1CFCFCFFEFEFE343434000000595959FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFDFDFDA8A8A8838383C7C7C7D6D6D6E8E8E8FFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFD70
                  7070121212B6B6B6E4E4E4F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBEBE6
                  E6E65D5D5D0A0A0AADADADFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFE4E4E4D9D9D9C9C9C9898989A6A6A6FBFBFBFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFDCDCDCD5D5D5FEFEFE3434340000004F4F4FFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDBDBDB919191929292EDEDEDC6C6C6
                  FAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFF6F6F66060600E0E0EBABABAE4E4E4F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFE7E7E7EAEAEA5F5F5F0303039A9A9AFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F9C6C6C6EFEFEF969696
                  939393D6D6D6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD2D2D2DFDFDFFCFCFC3434
                  340000003A3A3AFBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBACACAC929292B5
                  B5B5F1F1F1CBCBCBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFEDEDED4F4F4F0F0F0FBDBDBDE5E5E5F3F3F3FFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5EDEDED6060600000008585
                  85FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC9
                  C9C9F3F3F3B8B8B8969696AAAAAAF9F9F9FFFFFFFFFFFFFFFFFFFFFFFFC9C9C9
                  E9E9E9FBFBFB343434000000262626F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFD8D8
                  D89B9B9B979797E3E3E3D7D7D7E4E4E4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFE3E3E33D3D3D0E0E0EBEBEBEE7E7E7EFEFEFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEE3E3E3
                  F1F1F1616161000000737373FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFE1E1E1DADADAE4E4E49B9B9B9D9D9DD4D4D4FFFFFFFFFFFFFF
                  FFFFFFFFFFC0C0C0F2F2F2FAFAFA343434000000171717E7E7E7FFFFFFFFFFFF
                  FFFFFFFAFAFAAFAFAF9E9E9EABABABFDFDFDC4C4C4FAFAFAFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D92C2C2C101010BFBFBFEBEBEBEB
                  EBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFBFBFBE1E1E1F4F4F4616161000000646464F5F5F5FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8C5C5C5FEFEFEACACACA1A1A1AEAE
                  AEF8F8F8FFFFFFFFFFFFFFFFFFBEBEBEF5F5F5FAFAFA343434000000101010E3
                  E3E3FFFFFFFFFFFFFFFFFFD6D6D6A4A4A4A0A0A0D0D0D0F4F4F4CACACAFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCCC2222220F0F0FC1C1
                  C1EEEEEEE7E7E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFAE0E0E0F7F7F761616100000052
                  5252ECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC8C8C8F6F6F6
                  D2D2D2A3A3A3A6A6A6D3D3D3FFFFFFFFFFFFFFFFFFBEBEBEF6F6F6FAFAFA3434
                  340000000D0D0DDEDEDEFFFFFFFFFFFFF9F9F9B2B2B2A8A8A8A8A8A8F5F5F5D9
                  D9D9E0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBBBBBB181818
                  111111C0C0C0F1F1F1E3E3E3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8E0E0
                  E0F7F7F7616161000000404040E2E2E2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFDEDEDEDBDBDBF7F7F7A9A9A9AAAAAAB2B2B2F7F7F7FFFFFFFEFEFEBEBEBE
                  FAFAFAFAFAFA343434000000070707CCCCCCFFFFFFFFFFFFD4D4D4ABABABA9A9
                  A9C2C2C2FFFFFFC4C4C4F7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9
                  A9A90D0D0D111111C0C0C0F3F3F3E0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFF5F5F5E1E1E1F9F9F96161610000002F2F2FD9D9D9FFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF6F6F6C5C5C5FFFFFFC2C2C2ACACACADADADD1D1D1FF
                  FFFFFAFAFABEBEBEFEFEFEFAFAFA343434000000000000B4B4B4FFFFFFF7F7F7
                  B5B5B5B0B0B0ABABABE6E6E6F7F7F7C7C7C7FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFF989898050505131313BFBFBFF8F8F8DEDEDEFEFEFEFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFEFEFEF3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F1E2E2E2F9F9F9626262000000
                  252525CBCBCBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC6C6C6F8F8F8E7E7E7ACAC
                  ACB2B2B2B5B5B5F5F5F5F7F7F7BEBEBEFFFFFFF9F9F93434340000000000009D
                  9D9DFFFFFFD2D2D2B2B2B2B2B2B2B8B8B8FEFEFEDADADADEDEDEFFFFFFFFFFFF
                  FFFFFFFFFFFFFEFEFE888888000000141414C0C0C0FBFBFBDCDCDCFCFCFCFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFB
                  F6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFA9A9A9A7D7D7DB5B5B5EEEEEE
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDEDEDE5
                  E5E5FBFBFB6161610000001A1A1AB9B9B9FFFFFFFFFFFFFFFFFFFFFFFFDCDCDC
                  DCDCDCFEFEFEBABABAB4B4B4B3B3B3D2D2D2F7F7F7BDBDBDFFFFFFF9F9F93434
                  34000000000000919191FCFCFCB8B8B8B6B6B6B1B1B1D6D6D6FFFFFFC6C6C6F5
                  F5F5FFFFFFFFFFFFFFFFFFFAFAFA747474000000141414BFBFBFFEFEFEDADADA
                  FAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDE
                  DEDE999999767676CBCBCBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD6
                  D6D6828282545454797979C0C0C0F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFEAEAEAE7E7E7F9F9F96262620000000F0F0FA7A7A7FFFFFFFF
                  FFFFFFFFFFF4F4F4C7C7C7FFFFFFD7D7D7B2B2B2B7B7B7BABABAE7E7E7C0C0C0
                  FFFFFFF9F9F93434340000000000008F8F8FDBDBDBB8B8B8B8B8B8B6B6B6F6F6
                  F6F6F6F6C6C6C6FFFFFFFFFFFFFFFFFFF4F4F4606060000000151515BFBFBFFE
                  FEFED9D9D9F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDEDE
                  DEA3A3A36363635A5A5AA3A3A3EEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1929292575757585858838383BFBFBFF0
                  F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7E7E7EAEAEAFBFBFB6161610000
                  00070707979797FFFFFFFFFFFFFFFFFFC5C5C5F7F7F7F6F6F6B6B6B6BABABABB
                  BBBBBCBCBCC7C7C7FFFFFFF9F9F93434340000000000006F6F6FC4C4C4BBBBBB
                  B8B8B8CACACAFFFFFFDEDEDEDADADAFFFFFFFFFFFFEDEDED4F4F4F0000001515
                  15BEBEBEFFFFFFDADADAF5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDDFDFDF
                  A5A5A56C6C6C535353676767B2B2B2F7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8AEAE
                  AE7E7E7E616161606060888888C4C4C4EDEDEDFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E4
                  EEEEEEFAFAFA626262000000030303868686FEFEFEFFFFFFD8D8D8DFDFDFFFFF
                  FFCACACAB9B9B9BDBDBDA9A9A9C5C5C5FFFFFFF9F9F934343400000000000046
                  4646C5C5C5BDBDBDB8B8B8E9E9E9FFFFFFC7C7C7F3F3F3FFFFFFE3E3E3404040
                  000000151515BEBEBEFFFFFFDCDCDCF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBDBDBDBA9
                  A9A97373735B5B5B6C6C6C909090C4C4C4F6F6F6FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFE5E5E5C0C0C0A6A6A6858585616161696969939393C3C3
                  C3EBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFEFEFEE0E0E0F1F1F1FBFBFB616161000000000000737373FAFAFA
                  F6F6F6C7C7C7FFFFFFEAEAEAB8B8B8C1C1C1A2A2A2D6D6D6FFFFFFF9F9F93434
                  340000000000003A3A3ABEBEBEC0C0C0C1C1C1FEFEFEF8F8F8C4C4C4FFFFFFD6
                  D6D6323232000000161616BEBEBEFFFFFFDFDFDFEDEDEDFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5DADADAAEAE
                  AE7D7D7D6161616F6F6F979797B1B1B1CCCCCCF2F2F2FFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEE2E2E2C7C7C7C3C3C3
                  AAAAAA7C7C7C6B6B6B7A7A7A9C9C9CC5C5C5E6E6E6FCFCFCFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDDEDEDEF4F4F4FAFAFA62626200
                  00000000005F5F5FF5F5F5C9C9C9F8F8F8FFFFFFC2C2C2C3C3C39F9F9FDEDEDE
                  FFFFFFF9F9F9343434000000000000282828C3C3C3BEBEBEDCDCDCFFFFFFE1E1
                  E1E1E1E1CACACA232323000000161616BEBEBEFFFFFFE1E1E1EAEAEAFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5D6D6D6B0B0B0
                  8D8D8D7272726F6F6F919191BCBCBCC5C5C5CDCDCDECECECFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFBFBFBDCDCDCC8C8C8D1D1D1C6C6C69A9A9A7D7D7D7C7C7C8C8C8CA3A3A3
                  C4C4C4E5E5E5FBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCDCDC
                  DCF7F7F7FAFAFA616161000000000000505050C7C7C7E6E6E6FFFFFFDDDDDDC0
                  C0C0A5A5A5E2E2E2FFFFFFF9F9F93434340000000000002A2A2AC0C0C0BFBFBF
                  F7F7F7FFFFFFD3D3D3ABABAB191919000000161616BEBEBEFFFFFFE4E4E4E6E6
                  E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFD3D3D3B3B3B397
                  97978888887E7E7E868686AFAFAFD4D4D4D0D0D0CACACAE8E8E8FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBDADADAC7C7C7DEDEDEDEDEDEB5
                  B5B59292928B8B8B9292929A9A9AA9A9A9C4C4C4E0E0E0F9F9F9FFFFFFFFFFFF
                  FFFFFFFFFFFFF9F9F9DCDCDCF9F9F9F9F9F9626262000000000000313131B7B7
                  B7FFFFFFF9F9F9C3C3C3989898E3E3E3FFFFFFF9F9F934343400000000000018
                  1818BCBCBCD0D0D0FFFFFFFFFFFF7B7B7B0F0F0F000000161616BFBFBFFFFFFF
                  E8E8E8E3E3E3FFFFFFFFFFFFFFFFFFFFFFFFFDFDFDEDEDEDD2D2D2B5B5B5A2A2
                  A29898989393938F8F8F9D9D9DC8C8C8E5E5E5D4D4D4C7C7C7E5E5E5FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9
                  F9D7D7D7C7C7C7E3E3E3EFEFEFCBCBCBA4A4A49999999E9E9EA1A1A1A5A5A5AF
                  AFAFC4C4C4DFDFDFF4F4F4FFFFFFFFFFFFF8F8F8DCDCDCFCFCFCFAFAFA616161
                  000000000000272727D5D5D5FFFFFFD0D0D0A9A9A9EBEBEBFFFFFFF9F9F93434
                  340000000000001D1D1DB1B1B1F0F0F0FFFFFF939393050505000000161616BE
                  BEBEFFFFFFECECECE0E0E0FFFFFFFFFFFFFCFCFCEAEAEACECECEB8B8B8A9A9A9
                  A5A5A5A4A4A49E9E9E9D9D9DB1B1B1DBDBDBF1F1F1D8D8D8C5C5C5E2E2E2FFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFF8F8F8D4D4D4C6C6C6E7E7E7F9F9F9DDDDDDB5B5
                  B5A3A3A3A7A7A7ABABABADADADADADADB4B4B4C3C3C3DCDCDCF5F5F5F4F4F4E1
                  E1E1FFFFFFF9F9F9626262000000000000222222C6C6C6F8F8F8979797F5F5F5
                  FFFFFFF9F9F93434340000000000000A0A0AA9A9A9FFFFFF8181810404040000
                  00161616BFBFBFFFFFFFF3F3F3E0E0E0F7F7F7E4E4E4CECECEBBBBBBB1B1B1B0
                  B0B0B0B0B0ADADADA7A7A7A8A8A8C3C3C3EBEBEBFAFAFAD9D9D9C3C3C3E1E1E1
                  FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6D3D3D3
                  C5C5C5E7E7E7FFFFFFECECECC5C5C5ADADADACACACB3B3B3B5B5B5B6B6B6B6B6
                  B6B8B8B8C7C7C7CDCDCDD2D2D2FFFFFFFAFAFA616161000000000000161616B9
                  B9B9B3B3B3FBFBFBFFFFFFF9F9F9343434000000000000010101BCBCBC787878
                  000000000000161616BEBEBEFFFFFFF1F1F1BFBFBFCBCBCBBEBEBEB8B8B8B7B7
                  B7B8B8B8B8B8B8B3B3B3ADADADB5B5B5D3D3D3F7F7F7FDFDFDDADADAC3C3C3DD
                  DDDDFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFF5F5F5D0D0D0C5C5C5E8E8E8FFFFFFF7F7F7D4D4D4B8B8B8
                  B1B1B1B7B7B7BBBBBBBDBDBDBBBBBBBDBDBDB5B5B5DADADAFFFFFFF9F9F96262
                  620000000000000E0E0E818181FFFFFFFFFFFFF9F9F934343400000000000005
                  0505333333000000000000161616BFBFBFFFFFFFF9F9F9C2C2C2BABABAC0C0C0
                  BEBEBEBEBEBEBDBDBDB7B7B7B4B4B4C2C2C2E2E2E2FFFFFFFFFFFFDCDCDCC2C2
                  C2DBDBDBFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4F4F4D0D0D0C6C6C6E9
                  E9E9FFFFFFFEFEFEE2E2E2C3C3C3B6B6B6BBBBBBC0C0C0C1C1C1C3C3C3B4B4B4
                  D9D9D9FFFFFFFAFAFA6262620000000000005D5D5DFFFFFFFFFFFFF9F9F93434
                  34000000000000000000000000000000161616BEBEBEFFFFFFFAFAFABCBCBCBC
                  BCBCC5C5C5C2C2C2C1C1C1BABABABABABACFCFCFF0F0F0FFFFFFFFFFFFDCDCDC
                  C2C2C2D8D8D8FBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFF2F2F2CDCDCDC7C7C7E9E9E9FFFFFFFFFFFFEEEEEECFCFCFBBBBBBBE
                  BEBEC3C3C3C6C6C6C0C0C0E5E5E5FFFFFFF9F9F9636363000000707070FFFFFF
                  FFFFFFF9F9F9343434000000000000000000000000171717BFBFBFFFFFFFFCFC
                  FCCCCCCCC4C4C4C8C8C8C4C4C4BDBDBDC1C1C1DCDCDCF9F9F9FFFFFFFFFFFFE0
                  E0E0C2C2C2D6D6D6FAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3CDCDCDC9C9C9EEEEEEFFFF
                  FFFFFFFFFFFFFFE3E3E3CACACAC6C6C6CCCCCCCDCDCDF6F6F6FFFFFFFDFDFD56
                  56568C8C8CFFFFFFFFFFFFF9F9F9343434000000000000000000161616BCBCBC
                  FFFFFFFFFFFFE2E2E2C9C9C9CFCFCFC8C8C8D3D3D3F1F1F1FFFFFFFFFFFFFFFF
                  FFE2E2E2C4C4C4D5D5D5F9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  EBEBEBBEBEBEB7B7B7CACACAC3C3C3C0C0C0B3B3B38989895E5E5E5E5E5E4F4F
                  4F5757574D4D4D2F2F2F515151F5F5F5FFFFFFF9F9F93434340000000000002E
                  2E2E3535354242425252525353535353535E5E5E6969699E9E9EBCBCBCC0C0C0
                  C8C8C8CBCBCBB3B3B3CACACAF3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4F4F4FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6
                  F6EBEBEBE4E4E4E2E2E2D7D7D7C2C2C2AAAAAA9595958D8D8D86868672727258
                  58584040403232322F2F2F2828280D0D0D060606010101000000000000000000
                  000000000000000000000000000000000000000000585858F6F6F6FDFDFD3434
                  340000003030303F3F3F01010100000000000000000000000000000000000000
                  00000000000000000404040606061616162D2D2D303030363636494949626262
                  7B7B7B8A8A8A8F8F8F9C9C9CB3B3B3CBCBCBDDDDDDE3E3E3E7E7E7F0F0F0FAFA
                  FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFF4F4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5
                  B55C5C5CF9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFCFCFCFA
                  FAFAEEEEEEDEDEDECCCCCCC0C0C0BCBCBCB0B0B09999997D7D7D6666665C5C5C
                  5656564646463030301E1E1E1212120F0F0F0B0B0B0303030000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  5A5A5AF2F2F23333332A2A2A3F3F3F0000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  00000000000000000000000000000000000000000000000606060C0C0C101010
                  1616162525253939394D4D4D5959595F5F5F6E6E6E888888A3A3A3B7B7B7BDBD
                  BDC4C4C4D3D3D3E5E5E5F4F4F4FCFCFCFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFC6C6C6545454EFEFEFFFFFFFFFFFFFFFFFFFE7E7E7DADADA
                  C3C3C37171710808080000004242428A8A8A8D8D8D8989897E7E7E6666664B4B
                  4B3434342929292424241A1A1A0A0A0A00000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  00000000000000000000004D4D4D5C5C5C343434000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000000000000000000000000000000000000000000
                  0000000000000000000000000202021010101F1F1F2727272C2C2C3C3C3C5555
                  557171718484848B8B8B8D8D8D7A7A7A1616160000002B2B2B9C9C9CD2D2D2E0
                  E0E0A4A4A47575755151515959598989899292926D6D6D525252565656555555
                  5959596464646E6E6E7A7A7A7D7D7D7E7E7E8383838989898F8F8F9393939393
                  939393939393939393939393939393939393939292929191919090908F8F8F8F
                  8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F
                  8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F
                  8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F9393935353533232326868687B7B7B78
                  7878787878787878787878787878787878787878787878787878787878787878
                  7878787878787878787878787878787878787878787878787878787878787878
                  787878787878787878787878787878787878787979797A7A7A7B7B7B7C7C7C7C
                  7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7A7A7A7575756F6F6F6A6A6A676767
                  6666665E5E5E5353534848483F3F3F3F3F3F3D3D3D3F3F3F6A6A6A7C7C7C5F5F
                  5F3F3F3F5A5A5A868686FFFFFFFFFFFFFDFDFDDADADABFBFBFC5C5C5C7C7C7E8
                  E8E8EAEAEAEAEAEAE6E6E6DDDDDDD4D4D4CBCBCBC7C7C7C8C8C8C8C8C8C8C8C8
                  C8C8C8C7C7C7C7C7C7CCCCCCD6D6D6DFDFDFE7E7E7EAEAEAEBEBEBF2F2F2FAFA
                  FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCCCADADAD1E1E
                  1E4E4E4EF8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7
                  F7EFEFEFEAEAEAEAEAEAE4E4E4DBDBDBD2D2D2C9C9C9C7C7C7C8C8C8C8C8C8C8
                  C8C8C8C8C8C7C7C7C8C8C8CECECED8D8D8E1E1E1E9E9E9EAEAEAE9E9E9DFDFDF
                  BBBBBBC9C9C9C2C2C2ECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5
                  E5AFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFBFBFBF7F7F7F3F3F3F3F3F3EEEEEEE4E4E4DADADAD1D1D1CDCDCD
                  CDCDCDC8C8C8C2C2C2BCBCBCB8B8B8B8B8B8BCBCBCC1C1C1C7C7C7CCCCCCCDCD
                  CDD0D0D0D9D9D9E3E3E3EDEDEDF3F3F3F3F3F3F7F7F7FDFDFDFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0
                  B7B7B7F3F3F3252525000000484848EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCF5F5F5F3F3F3F2
                  F2F2E9E9E9DFDFDFD5D5D5CECECECDCDCDCBCBCBC5C5C5BFBFBFB9B9B9B7B7B7
                  B9B9B9BFBFBFC4C4C4CACACACECECECECECED4D4D4DEDEDEE8E8E8F2F2F2F3F3
                  F3F4F4F4F8F8F8FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFEBEBEBACACACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFAF2F2F2
                  EAEAEAE3E3E3E0E0E0DFDFDFD6D6D6CDCDCDC4C4C4BEBEBEC1C1C1B5B5B5A1A1
                  A1AEAEAEADADADB7B7B7AFAFAFC8C8C8CDCDCDD7D7D7E7E7E7E5E5E5ECECECF4
                  F4F4BFBFBFB3B3B3FFFFFFF0F0F0242424000000000000484848E4E4E4F3F3F3
                  E8E8E8E5E5E5E4E4E4CFCFCFCECECEBEBEBEAEAEAEB8B8B8ABABABABABABA1A1
                  A1BBBBBBC0C0C0BFBFBFC7C7C7D1D1D1DADADAE1E1E1E0E0E0E5E5E5EDEDEDF5
                  F5F5FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFC
                  DADADABEBEBEBBBBBBB4B4B4B7B7B7B7B7B7B3B3B3ADADADABABABC4C4C44242
                  421313131D1D1D3737379C9C9CFFFFFFFFFFFFEFEFEF24242400000000000000
                  00004545452D2D2D181818131313818181C6C6C6A4A4A4B4B4B4B4B4B4BBBBBB
                  B6B6B6B9B9B9BCBCBCC3C3C3E3E3E3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9
                  F9F9D8D8D8BABABAB6B6B6BABABABBBBBBBEBEBEBCBCBCBEBEBED0D0D0EFEFEF
                  FFFFFF7575750000000000000909099F9F9FC6C6C6FFFFFFFFFFFFEFEFEF2424
                  24000000000000000000969696797979000000000000171717C4C4C4FFFFFFE0
                  E0E0C6C6C6BEBEBEBFBFBFBFBFBFBCBCBCBBBBBBB6B6B6BFBFBFE0E0E0FEFEFE
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFBFBFBD9D9D9B7B7B7B0B0B0B4B4B4B7B7B7B7B7B7B6B6B6C0C0C0DBDBDBF8
                  F8F8FFFFFFFFFFFF8282820000000000000C0C0CB0B0B0FFFFFFBABABAFFFFFF
                  FFFFFFEFEFEF242424000000000000000000B5B5B5FFFFFF7575750000000000
                  001A1A1ACDCDCDFFFFFFFFFFFFECECECCECECEBBBBBBB8B8B8B8B8B8B8B8B8B5
                  B5B5B1B1B1BEBEBEE4E4E4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFCFCFCDBDBDBB5B5B5A9A9A9AEAEAEB0B0B0AFAFAFB4B4B4C9C9C9E9E9
                  E9FFFFFFFFFFFFFFFFFFFAFAFA9292920303030000000D0D0DB0B0B0FFFFFFFE
                  FEFEB0B0B0FFFFFFFFFFFFEFEFEF242424000000000000000000B5B5B5FFFFFF
                  FEFEFE757575000000000000272727D5D5D5FFFFFFFFFFFFFFFFFFF8F8F8DBDB
                  DBBFBFBFB2B2B2B1B1B1B2B2B2AEAEAEABABABBDBDBDE6E6E6FFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFEFEFEDDDDDDB1B1B1A2A2A2A6A6A6A7A7A7A9A9A9B7B7B7D6D6D6
                  F6F6F6FFFFFFFFFFFFF4F4F4DADADACECECE7979790303030000000C0C0CB0B0
                  B0FFFFFFFCFCFCDEDEDEAAAAAAFEFEFEFFFFFFEFEFEF24242400000000000001
                  0101A3A3A3EDEDEDFFFFFFFDFDFD757575000000000000242424AFAFAFD7D7D7
                  EBEBEBFDFDFDFFFFFFFFFFFFE9E9E9C7C7C7B1B1B1AAAAAAAAAAAAA7A7A7A5A5
                  A5BDBDBDE9E9E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFDEDEDEAFAFAF9999999B9B9B9D9D9DA6A6A6C0C0C0E5
                  E5E5FFFFFFFFFFFFF1F1F1D8D8D8C5C5C5C6C6C6E2E2E2B0B0B0121212000000
                  0D0D0DB0B0B0FFFFFFFAFAFADDDDDDF0F0F0A3A3A3F8F8F8FFFFFFEFEFEF2424
                  24000000000000010101AFAFAFBBBBBBE5E5E5FFFFFFFEFEFE74747400000000
                  0000414141D9D9D9CECECEC2C2C2CDCDCDE8E8E8FFFFFFFFFFFFF7F7F7D6D6D6
                  B4B4B4A3A3A39F9F9F9C9C9C9E9E9EBCBCBCEBEBEBFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFE1E1E1ACACAC8F8F8F8E8E8E959595A9A9A9D0D0
                  D0F4F4F4FFFFFFF2F2F2D6D6D6C3C3C3C7C7C7DDDDDDF7F7F7FFFFFFCBCBCB18
                  18180000000C0C0CB0B0B0FFFFFFF8F8F8DCDCDCF7F7F7E5E5E59A9A9AF3F3F3
                  FFFFFFEFEFEF242424000000000000141414A5A5A5CDCDCDBDBDBDD6D6D6FFFF
                  FFFDFDFD757575000000000000565656FAFAFAFCFCFCE9E9E9D0D0D0C2C2C2CC
                  CCCCE5E5E5FDFDFDFFFFFFE7E7E7BFBFBFA1A1A1959595909090969696BBBBBB
                  EEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFE2E2E2A8A8A8838383818181919191B4B4B4
                  E1E1E1FBFBFBEFEFEFD3D3D3C3C3C3CACACAE2E2E2F8F8F8FFFFFFFFFFFFFFFF
                  FFD6D6D62222220000000D0D0DB0B0B0FFFFFFF1F1F1C8C8C8F7F7F7FFFFFFC8
                  C8C8AAAAAAE7E7E7FFFFFFEFEFEF242424000000000000282828C9C9C9C6C6C6
                  C7C7C7B8B8B8D1D1D1FFFFFFFEFEFE747474000000000000676767FCFCFCFFFF
                  FFFFFFFFFFFFFFEBEBEBD2D2D2C3C3C3CACACAE5E5E5FBFBFBF5F5F5D1D1D1A5
                  A5A58B8B8B8181818C8C8CBABABAF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5A4A4A4757575747474949494C5
                  C5C5E9E9E9EBEBEBD4D4D4C3C3C3CCCCCCE3E3E3F9F9F9FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFE3E3E33131310000000C0C0CB0B0B0FFFFFFF3F3F3BFBFBFD4D4
                  D4FFFFFFEFEFEFC3C3C3979797E3E3E3FFFFFFEFEFEF2424240000000000002E
                  2E2EF1F1F1C0C0C0C5C5C5C5C5C5B2B2B2DADADAFDFDFDFDFDFD757575000000
                  0000007B7B7BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF0F0F0D6D6D6C3C3
                  C3C8C8C8E0E0E0F4F4F4E1E1E1B2B2B2878787727272818181BABABAF3F3F3FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E59E9E9E6767676F6F6F9F9F
                  9FD0D0D0E0E0E0D1D1D1C4C4C4CDCDCDE7E7E7FCFCFCFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFEDEDED4040400000000D0D0DB0B0B0FFFFFFEEEEEE
                  E2E2E2C7C7C7F2F2F2FFFFFFD1D1D1C3C3C3ABABABE1E1E1FFFFFFEFEFEF2424
                  24000000000000313131FFFFFFCDCDCDC2C2C2C1C1C1BEBEBEDCDCDCDFDFDFFA
                  FAFAFFFFFF7474740000000000008E8E8EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFF0F0F0D9D9D9C6C6C6C9C9C9DEDEDEE1E1E1C1C1C18C8C
                  8C666666757575B9B9B9F7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E69898985F5F5F717171
                  A6A6A6CACACACDCDCDC6C6C6D2D2D2EAEAEAFCFCFCFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4F4F44E4E4E0000000C0C0CB0B0B0FF
                  FFFFEAEAEAE2E2E2F9F9F9C5C5C5FEFEFEF9F9F9BDBDBDC5C5C59C9C9CDCDCDC
                  FFFFFFEFEFEF2424240000000000003E3E3EFFFFFFECECECBBBBBBC1C1C1BDBD
                  BDD3D3D3F7F7F7DBDBDBF7F7F7FEFEFE7575750000000404049E9E9EFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5DBDBDB
                  C8C8C8C8C8C8D3D3D3C6C6C69494946363636C6C6CB6B6B6F8F8F8FFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7E7E79494945A5A5A71
                  7171A7A7A7C1C1C1C8C8C8D5D5D5EBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFA6060600000000D0D
                  0DAFAFAFFFFFFFE6E6E6E4E4E4FFFFFFE3E3E3D5D5D5FFFFFFDDDDDDBABABAC1
                  C1C1A9A9A9CFCFCFFFFFFFEFEFEF242424000000000000434343FFFFFFFFFFFF
                  C1C1C1BFBFBFBCBCBCC0C0C0FDFDFDF8F8F8DBDBDBF4F4F4FFFFFF7474740000
                  000A0A0AB0B0B0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFF6F6F6E1E1E1CDCDCDC7C7C7BDBDBD949494616161
                  666666B6B6B6F9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E69292925353
                  536A6A6AA4A4A4C6C6C6DCDCDCF1F1F1FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE747474
                  0000000C0C0CB0B0B0FFFFFFE3E3E3E8E8E8FFFFFFFFFFFFCCCCCCEEEEEEFEFE
                  FEC1C1C1BCBCBCBFBFBFAAAAAAC4C4C4FFFFFFEFEFEF2424240000000000004E
                  4E4EE4E4E4FFFFFFDEDEDEB7B7B7BCBCBCB6B6B6EDEDEDFFFFFFFAFAFADCDCDC
                  F1F1F1FEFEFE757575000000131313C2C2C2FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8E5
                  E5E5D2D2D2BBBBBB9090905B5B5B606060B4B4B4FBFBFBFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E4898989
                  4C4C4C6D6D6DB4B4B4DFDFDFF4F4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFF8888880000000C0C0CB0B0B0FFFFFFE1E1E1EBEBEBFFFFFFFFFFFFFCFCFC
                  C3C3C3FFFFFFECECECB4B4B4BBBBBBBABABAC8C8C8C4C4C4FFFFFFEFEFEF2424
                  24000000000000808080CCCCCCFBFBFBFAFAFAB9B9B9BBBBBBB4B4B4D4D4D4FF
                  FFFFFFFFFFFDFDFDDEDEDEEEEEEEFFFFFF7474740000001D1D1DD2D2D2FFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDEDEDEDCFCFCF9A9A9A565656585858AF
                  AFAFF8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEDBDBDB89
                  8989616161909090D7D7D7FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFF9898980202020B0B0BB0B0B0FFFFFFDFDFDFEFEFEFFFFFFFFF
                  FFFFFFFFFFE6E6E6D2D2D2FFFFFFCBCBCBB5B5B5B8B8B8BDBDBDEDEDEDBEBEBE
                  FFFFFFEFEFEF242424000000000000919191E6E6E6D9D9D9FFFFFFD0D0D0B4B4
                  B4B6B6B6BDBDBDFFFFFFFFFFFFFFFFFFFEFEFEE0E0E0EAEAEAFEFEFE75757500
                  0000282828DCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFF1F1F1BFBFBF757575656565ABABABF3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFF9F9F9A8A8A8C4C4C4F9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFAAAAAA0606060B0B0BB0B0B0FFFFFFDDDDDDF2F2
                  F2FFFFFFFFFFFFFFFFFFFFFFFFCDCDCDEDEDEDF8F8F8B4B4B4B5B5B5B3B3B3DB
                  DBDBF8F8F8BEBEBEFFFFFFEFEFEF242424000000000000949494FFFFFFC2C2C2
                  FAFAFAF1F1F1B1B1B1B4B4B4B0B0B0EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFE4E4
                  E4E6E6E6FFFFFF747474000000353535E7E7E7FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8A7A7A7CBCBCBFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBCBCBC0E0E0E0A0A0AB1B1B1FDFDFD
                  DDDDDDF6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFBFBFBC3C3C3FEFEFED8D8D8ADAD
                  ADB2B2B2BABABAFBFBFBF8F8F8BEBEBEFFFFFFF0F0F0242424000000000000A6
                  A6A6FFFFFFDEDEDED7D7D7FFFFFFC2C2C2B0B0B0ACACACD7D7D7FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFE7E7E7E4E4E4FDFDFD757575000000464646F1F1F1FFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD1818180A0A0AB0
                  B0B0FBFBFBDDDDDDF8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAEAEACFCFCF
                  FFFFFFB7B7B7AEAEAEADADADDCDCDCFFFFFFFCFCFCBEBEBEFEFEFEF0F0F02424
                  24000000020202BEBEBEFFFFFFFDFDFDC2C2C2FAFAFAE5E5E5AAAAAAACACACBD
                  BDBDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAEAEAE1E1E1FDFDFD747474
                  000000595959F9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D92323
                  23080808B1B1B1F9F9F9DEDEDEFAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFD1D1D1EBEBEBE9E9E9A7A7A7ABABABB8B8B8FCFCFCFFFFFFFFFFFFBEBEBE
                  F9F9F9F0F0F02424240000000A0A0AD4D4D4FFFFFFFFFFFFE1E1E1D5D5D5FFFF
                  FFB4B4B4A8A8A8A9A9A9F4F4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEE
                  EEEEDFDFDFFBFBFB757575000000696969FCFCFCFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  E4E4E42D2D2D080808B1B1B1F5F5F5E0E0E0FDFDFDFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFEFEFEC2C2C2FFFFFFC1C1C1A5A5A5A7A7A7DEDEDEFFFFFFFF
                  FFFFFFFFFFBEBEBEF6F6F6F0F0F02424240000000E0E0EE1E1E1FFFFFFFFFFFF
                  FDFDFDC3C3C3FAFAFAD6D6D6A3A3A3A1A1A1D9D9D9FFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF2F2F2DEDEDEFBFBFB7474740000007A7A7AFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFEDEDED3D3D3D070707B1B1B1F2F2F2E2E2E2FEFEFEFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECECECCFCFCFF7F7F7A5A5A5A3A3A3B6B6
                  B6FDFDFDFFFFFFFFFFFFFFFFFFBEBEBEF6F6F6F0F0F0242424000000121212E4
                  E4E4FFFFFFFFFFFFFFFFFFE3E3E3D4D4D4FAFAFAA7A7A79E9E9EBBBBBBFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6DDDDDDF7F7F77474
                  740000008D8D8DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF6F6F6505050050505B0B0B0F1F1F1E5E5E5FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD3D3D3E9E9E9D3D3D3
                  9B9B9B9F9F9FE1E1E1FFFFFFFFFFFFFFFFFFFFFFFFC3C3C3F0F0F0F1F1F12424
                  240000001C1C1CEAEAEAFFFFFFFFFFFFFFFFFFFFFFFFC4C4C4F9F9F9C5C5C599
                  9999A2A2A2F6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  F8F8F8DEDEDEF6F6F6727272010101A2A2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFB616161070707AFAFAFEDEDEDE8E8
                  E8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDC4
                  C4C4F8F8F8A9A9A9979797B4B4B4FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFCCCCCC
                  E6E6E6F2F2F22424240000002D2D2DF5F5F5FFFFFFFFFFFFFFFFFFFFFFFFE6E6
                  E6D2D2D2EFEFEF999999939393DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFAFAFADFDFDFF2F2F2737373060606B3B3B3FFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF707070060606AEAEAE
                  EBEBEBECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFF0F0F0CDCDCDE4E4E4929292979797E3E3E3FFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFD6D6D6DDDDDDF3F3F3242424000000434343FEFEFEFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFC5C5C5F6F6F6B1B1B18C8C8CB8B8B8FFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDE1E1E1EFEFEF71
                  71710D0D0DC1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF83838309
                  0909ABABABE8E8E8EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFD6D6D6E5E5E5B6B6B6898989B2B2B2FFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFD3D3D3F4F4F4242424000000545454FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8D2D2D2DFDFDF898989999999
                  F9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFEFEFEE3E3E3EBEBEB6F6F6F151515CFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FF9898980B0B0BA8A8A8E8E8E8F3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC6C6C6E9E9E98E8E8E8C8C8C
                  E6E6E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1D0D0D0F4F4F42424
                  240000005C5C5CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7C7C7EF
                  EFEF9B9B9B838383DEDEDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6E7E7E76D6D6D242424DEDEDEFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFABABAB131313A4A4A4E7E7E7F6F6F6FFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2CECECEC6
                  C6C67B7B7BB0B0B0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2E2E2
                  CFCFCFF4F4F4242424000000646464FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFEAEAEAD1D1D1CACACA767676B9B9B9FFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAEAEAE4E4E4
                  6B6B6B343434E9E9E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFB9B9B9191919A0A0A0E8E8E8F9F9F9FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFDBDBDBDADADA949494808080E8E8E8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFEAEAEACACACAF3F3F3242424000000797979FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCACACAE3E3E38282828F8F8FFAFAFAFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFEEEEEEE1E1E1696969424242F0F0F0FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC8C8C82222229C9C9CE8E8E8FBFBFBFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFCACACACDCDCD6F6F6FAEAEAEFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2C5C5C5F1F1F1242424000000959595FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECECECCFCFCFAFAFAF
                  6D6D6DE4E4E4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2DEDEDE676767535353F6F6F6FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD6D6D6303030969696EAEA
                  EAFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5CACACA9D9D9D737373ECECECFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFABFBFBFF0F0F02424
                  24000000ADADADFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFCDCDCDD0D0D06A6A6AB7B7B7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5DDDD
                  DD656565686868FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E33F3F3F
                  919191EDEDEDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFC5C5C56B6B6BAB
                  ABABFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  BBBBBBEFEFEF232323000000BBBBBBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF0F0F0CACACA8C8C8C828282FEFEFEFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFF9F9F9DCDCDC6565657D7D7DFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEB
                  EBEB4D4D4D8C8C8CF0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCECE
                  CEA1A1A1686868EDEDEDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFBBBBBBEFEFEF232323000000BFBFBFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD0D0D0B4B4B4606060E6E6
                  E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBDBDBDB6464648F8F8FFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFEAEAEAD2D2D25C5C5C898989F3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFF9F9F9BEBEBE6B6B6BA8A8A8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBFEAEAEA232323020202CACACAFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2
                  C0C0C0696969B4B4B4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEDB
                  DBDB676767979797DBDBDBF9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFF9090901B1B1B181818909090F5F5F5FFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFE7E7E79C9C9C616161F0F0F0FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4C4C4E2E2E22323
                  230C0C0CDCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFD4D4D48D8D8D797979FEFEFEFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFDBDBDB6969690E0E0E393939D1D1D1FFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFBBBBBB000000070707AEAEAEE9E9E9FBFBFBFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCCC676767A5A5A5FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  CBCBCBDADADA2222221B1B1BECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6ACACAC5A5A5AE8E8E8FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECECECF0F0F07272720000003434
                  34F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4B4B4B080808AFAFAFFFFFFFE0
                  E0E0FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFD9F9F9F5C5C
                  5CF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFD0D0D0D3D3D3222222272727F9F9F9FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4D4D46363
                  63B1B1B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6E2E2E2
                  FFFFFF737373000000ACACACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDF1E1E1EA8A8
                  A8F3F3F3DCDCDCF6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  EBEBEB606060A4A4A4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D1D1D1D12222222C2C2CFCFCFCFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFF9F9F98A8A8A757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFE7E7E7E2E2E2F3F3F36A6A6A5D5D5DFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  C7C7C7919191E7E7E7E9E9E9FBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFBCBCBC525252F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4D4D4CFCFCF2121
                  21343434FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD4F4F4FEAEAEAFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5E5E5E5DADADA8C8C8CF8F8F8FF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFDFDFDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF717171A0A0A0FFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  DDDDDDC6C6C6202020494949FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFD686868AFAFAFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFD
                  FDFCFCFCFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6565656F2F2F2FFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFE6E6E6BDBDBD1F1F1F636363FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFBEBEBE6C6C6CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA3A3A3
                  9B9B9BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0B4B4B41F1F1F7A7A7AFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFBFBFB6A6A6AE4E4E4FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFF9F9F9777777ECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6AFAFAF2020
                  20878787FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB2B2B2A3A3A3FFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFF6F6F6CACACAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  F6F6F6AFAFAF2020208C8C8CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5CC
                  CCCCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFF9F9F9AFAFAF2020209B9B9BFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDAEAEAE212121B4B4B4FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAEAEAE2424
                  24CBCBCBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFACACAC262626DCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFACACAC292929E0E0E0FFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFABABAB2B2B2BE3E3E3FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA5A5A52525
                  25D7D7D7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFC
                  D1D1D1B5B5B5222222595959E9E9E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFEDEDED959595E0E0E0242424050505A1A1A1FFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEEEEEEA9A9A91F1F1F808080FFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB0B0B03131
                  31EAEAEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFD4D4D4595959FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFE2E2E2858585FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                  FFFF}
                Stretch = True
              end
              object cxAspectButtonN: TcxButton
                Left = 69
                Top = 0
                Width = 17
                Height = 17
                Caption = 'N'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 0
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonNClick
              end
              object cxAspectButtonS: TcxButton
                Left = 69
                Top = 137
                Width = 17
                Height = 17
                Caption = 'S'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 1
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonSClick
              end
              object cxAspectButtonW: TcxButton
                Left = 1
                Top = 68
                Width = 17
                Height = 17
                Caption = 'W'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 2
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonWClick
              end
              object cxAspectButtonE: TcxButton
                Left = 137
                Top = 68
                Width = 17
                Height = 17
                Caption = 'E'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 3
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonEClick
              end
              object cxAspectButtonNE: TcxButton
                Left = 123
                Top = 20
                Width = 25
                Height = 17
                Caption = 'NE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 4
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonNEClick
              end
              object cxAspectButtonNW: TcxButton
                Left = 11
                Top = 18
                Width = 25
                Height = 17
                Caption = 'NW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 5
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonNWClick
              end
              object cxAspectButtonSE: TcxButton
                Left = 121
                Top = 119
                Width = 25
                Height = 17
                Caption = 'SE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 6
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonSEClick
              end
              object cxAspectButtonSW: TcxButton
                Left = 11
                Top = 119
                Width = 25
                Height = 17
                Caption = 'SW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 7
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonSWClick
              end
              object cxAspectButtonNNE: TcxButton
                Left = 90
                Top = 10
                Width = 29
                Height = 17
                Caption = 'NNE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 8
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonNNEClick
              end
              object cxAspectButtonNNW: TcxButton
                Left = 38
                Top = 10
                Width = 29
                Height = 17
                Caption = 'NNW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 9
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonNNWClick
              end
              object cxAspectButtonENE: TcxButton
                Left = 122
                Top = 43
                Width = 31
                Height = 17
                Caption = 'ENE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonENEClick
              end
              object cxAspectButtonESE: TcxButton
                Left = 123
                Top = 93
                Width = 31
                Height = 17
                Caption = 'ESE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 11
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonESEClick
              end
              object cxAspectButtonWNW: TcxButton
                Left = 1
                Top = 43
                Width = 33
                Height = 17
                Caption = 'WNW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 12
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonWNWClick
              end
              object cxAspectButtonWSW: TcxButton
                Left = 1
                Top = 93
                Width = 33
                Height = 17
                Caption = 'WSW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 13
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonWSWClick
              end
              object cxAspectButtonSSE: TcxButton
                Left = 90
                Top = 128
                Width = 29
                Height = 17
                Caption = 'SSE'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 14
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonSSEClick
              end
              object cxAspectButtonSSW: TcxButton
                Left = 38
                Top = 128
                Width = 29
                Height = 17
                Caption = 'SSW'
                LookAndFeel.Kind = lfOffice11
                ModalResult = 1
                TabOrder = 15
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = cxAspectButtonSSWClick
              end
            end
            object cxPopupEdit14: TcxPopupEdit
              Left = 456
              Top = 267
              BeepOnEnter = False
              Properties.ImmediateDropDownWhenKeyPressed = False
              Properties.PopupClientEdge = True
              Properties.PopupControl = Panel13
              Properties.PopupSysPanelStyle = True
              Properties.OnInitPopup = cxPopupEdit14PropertiesInitPopup
              Properties.OnValidate = cxPopupEdit14PropertiesValidate
              Style.BorderStyle = ebs3D
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 9
              OnExit = cxPopupEdit14Exit
              Width = 97
            end
            object dxTreeViewEdit1: TdxTreeViewEdit
              Left = 336
              Top = 166
              Width = 186
              Height = 21
              CanSelectParents = True
              Ctl3D = True
              DropDownRows = 12
              ParentColor = False
              ParentCtl3D = False
              TabOrder = 1
              TabStop = True
              TreeViewColor = clWindow
              TreeViewCursor = crDefault
              TreeViewFont.Charset = DEFAULT_CHARSET
              TreeViewFont.Color = clWindowText
              TreeViewFont.Height = -11
              TreeViewFont.Name = 'Tahoma'
              TreeViewFont.Style = []
              TreeViewIndent = 19
              TreeViewReadOnly = True
              TreeViewShowButtons = True
              TreeViewShowHint = False
              TreeViewShowLines = True
              TreeViewShowRoot = True
              TreeViewSortType = stText
              OnClick = dxTreeViewEdit1Click
              OnExit = dxTreeViewEdit1Exit
              DividedChar = '.'
              TextStyle = tvtsShort
              Alignment = taLeftJustify
            end
            object Panel17: TPanel
              Left = 520
              Top = 166
              Width = 33
              Height = 21
              BevelInner = bvLowered
              BevelOuter = bvLowered
              Color = clWindow
              ParentBackground = False
              TabOrder = 14
              object cxButton12: TcxButton
                Left = 2
                Top = 2
                Width = 29
                Height = 17
                Align = alClient
                Caption = 'Edit'
                LookAndFeel.Kind = lfStandard
                TabOrder = 0
                OnClick = cxButton12Click
              end
            end
            object dxTreeViewEdit2: TdxTreeViewEdit
              Left = 335
              Top = 216
              Width = 217
              Height = 21
              CanSelectParents = True
              DropDownRows = 12
              ParentColor = False
              TabOrder = 15
              TabStop = True
              TreeViewColor = clWindow
              TreeViewCursor = crDefault
              TreeViewFont.Charset = DEFAULT_CHARSET
              TreeViewFont.Color = clWindowText
              TreeViewFont.Height = -11
              TreeViewFont.Name = 'Tahoma'
              TreeViewFont.Style = []
              TreeViewIndent = 19
              TreeViewPopupMenu = PopupMenuSubstrates
              TreeViewReadOnly = True
              TreeViewShowButtons = True
              TreeViewShowHint = False
              TreeViewShowLines = True
              TreeViewShowRoot = True
              TreeViewSortType = stNone
              OnExit = dxTreeViewEdit2Exit
              DividedChar = '.'
              TextStyle = tvtsShort
              Alignment = taLeftJustify
            end
            object cxComboBox1: TcxComboBox
              Left = 152
              Top = 24
              Style.LookAndFeel.Kind = lfStandard
              StyleDisabled.LookAndFeel.Kind = lfStandard
              StyleFocused.LookAndFeel.Kind = lfStandard
              StyleHot.LookAndFeel.Kind = lfStandard
              TabOrder = 17
              OnExit = cxComboBox1Exit
              Width = 145
            end
            object cxButton30: TcxButton
              Left = 16
              Top = 9
              Width = 37
              Height = 37
              Hint = 'Update site metadata in Neotoma'
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                96090000424D9609000000000000360000002800000019000000180000000100
                2000000000006009000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000F9F9F9FFE9E9E9FFE6E6E6FFFBFBFBFF000000000000000000000000FDFD
                FDFFE4E4E4FFD8D8D8FFEAEAEAFF00000000000000000000000000000000DDDD
                DDFFD7D6D7FFECECEDFF00000000000000000000000000000000000000000000
                0000FEFEFEFFF0F0F0FFB1B1B1FF9C9C9CFFDEDEDEFF00000000000000000000
                0000E2E2E2FF858585FF7A7A7AFF818181FFC2C2C2FFF4F4F4FF000000000000
                0000AAACACFF414850FFB3B7BAFF000000000000000000000000000000000000
                00000000000000000000F0F0F0FFBABABAFF737373FF8E8E8EFFF8F7F7FF0000
                000000000000EEEEEEFF929292FF6C6C6CFF505151FF646464FFADADADFFFDFD
                FDFF00000000E8E8E9FF48545DFF616D73FFF5F4F3FF00000000000000000000
                00000000000000000000D7D8D8FFCACACBFFC0C0C1FF5D5D5DFF272828FF6C71
                77FFDDDEE1FF0000000000000000C7C7C7FF737373FF565757FF515252FF6767
                67FFB6B6B6FFFEFEFEFF00000000D0D3D3FF5D686DFF788284FFCACCCEFFFFFE
                FEFF00000000D9D9D9FFA2A2A2FF434545FF696E70FF888E91FF62696CFF5D65
                67FF3E4D5BFF6A7482FFFEFDFCFF0000000000000000C1C1C1FF595959FF5151
                51FF3F4142FF525354FFE3E3E3FF0000000000000000E1E1E2FF6B767AFF606A
                6EFFA5A7A7FFB8B8B8FF8C8D8DFF636464FF4A4D50FF606668FF404547FF5A67
                6DFF748084FF657078FF33393FFF9A9898FFE9E9E9FF00000000F9F8F8FF8F8F
                90FF404445FF374145FF30373AFFA6A7A8FF000000000000000000000000D4D5
                D6FF6F777AFF72787BFF6C7178FF6B7278FF6F7373FF7D8182FF444748FF161A
                1CFF45535AFF57666CFF7D8486FF7B7B7AFF838282FFAEAEAEFFD6D6D6FFF4F4
                F4FFFDFDFDFF919595FF2C373CFF3B454AFF55585AFF00000000000000000000
                0000E7E7E8FF747C7FFF55626CFF4A5A6CFF505F6FFF606B77FF7A7E81FF5C60
                61FF333E43FF3D4B51FF3E4C52FFA4A6A7FFCDCDCDFFC4C3C3FFC3C3C3FFC4C4
                C4FFC7C7C7FFE9E9E9FFFAFAF9FF858A8CFF424F54FF3D4142FF000000000000
                000000000000E6E7E6FF626B6EFF384B5AFF425874FF485D7AFF3D5476FF5965
                72FF495457FF344147FF3E4C52FF343F43FF66696CFF555D66FF77797BFFE0E0
                DFFFD8D8D8FFB6B6B6FFB0B0B0FFCCCCCBFFC3C2C2FF4D5A5EFF404C52FF0000
                00000000000000000000DFE0E0FF546064FF405260FF435B79FF375175FF2D43
                62FF334149FF324349FF39474DFF39484EFF3E484BFF6D7376FF5A616AFF989B
                9FFFFFFFFEFFFBFBFBFF409E73FF008A4AFF008A4AFF42A076FF6E777AFF3649
                52FF000000000000000000000000989FA1FF42555CFF414D54FF465460FF3646
                58FF2F3E4BFF34444BFF2E4047FF2F414BFF2D4354FF6C757BFFD3D2D1FFF1F1
                F0FF000000000000000000000000008949FF00E7A7FF00E7A7FF008949FFB4B8
                BAFF31444CFF0000000000000000FAF9F9FF58646AFF304A55FF333F43FF383A
                3AFF2F3940FF2E3F4AFF384B53FF33474DFF293F4FFF2F486AFF5D6A76FF9397
                97FF9A9B9DFFA4A7AAFFF6F7F7FF00000000008847FF08E2A6FF00E0A2FF0088
                47FFDFE1E2FF3A4950FF0000000000000000FEFDFDFF69767BFF28424CFF394A
                51FF464F53FF253138FF17252CFF25383FFF36484DFF344553FF334C70FF4757
                68FF445155FF2B3540FF434E5CFFDADCDDFF00000000008747FF16E0ACFF00DC
                A2FF008847FFBABFC0FF46565CFF000000000000000000000000646E73FF1E37
                42FF2C3E46FF313D41FF0E1B22FF0E1B21FF1F3037FF3C4A4EFF333B40FF4556
                6AFF475664FF59676CFF5C6770FF434F5CFF8C9297FFEEEEEEFF008746FF23E0
                B2FF00D9A2FF008847FF6C797EFF889296FF0000000000000000000000008B8D
                8EFF19282FFF283B45FF213038FF0F1E25FF081A20FF16262EFF374449FF3C43
                44FF323537FF404C51FF677479FF737C80FF5A646AFF545D62FF7C8183FF0088
                46FF30DFB7FF00D5A2FF008847FF47575EFFE1E3E5FF00000000000000000000
                0000E8E6E6FF696D6EFF253942FF1B2F38FF192C33FF031821FF13242AFF1D2C
                33FF364146FF394246FF4F5D63FF616F75FF6F7A7EFF6A767BFF59656AFF535C
                60FF008845FF3EDFBDFF00D2A1FF008847FF9BA3A6FF00000000000000000000
                00000000000000000000696D6EFF273A42FF1C3640FF20343DFF071D27FF1124
                2CFF1C2C33FF26373FFF3B4D54FF536369FF5C6B71FF616F74FF757D81FF6874
                7AFF566268FF008845FF4BDFC1FF00CEA0FF008847FFF8F7F7FF000000000000
                00000000000000000000E7E6E5FF92999BFF293E47FF1F3943FF1F353EFF0B21
                2BFF122731FF24353CFF263941FF2E4048FF48575DFF55656BFF57676DFF6A75
                7AFF667277FF636F76FF008744FF58E0C7FF00CAA1FF008946FF000000000000
                0000000000000000000000000000E7E5E5FF878C8EFF5C696FFF0F2832FF142B
                35FF1B2F38FF122933FF1E3138FF23363EFF23363FFF304249FF4B5A61FF5867
                6EFF5D6C71FF505C62FF404C51FF008642FF6AE1CBFF00C9A1FF008744FF0000
                00330000002600000000000000000000000000000000CECFCFFF8E969AFF7A85
                8AFF5C696FFF2B3E45FF20343DFF1A2F37FF20333BFF273A42FF1F343DFF2D41
                49FF4F5D63FF4E5E64FF0F7B4BFF008846FF00AE7FFF00C39EFF00C39EFF00AE
                80FF008946FF006A39CD00000000000000000000000000000000000000000000
                000000000000F1F1F2FF838C90FF27383EFF192D36FF24363EFF22353DFF1F33
                3BFF253941FF364850FF4E585DFF008C4AFF82DCCAFF00C1A0FF00BE9BFF00BE
                9BFF00C1A0FF83DCCAFF008C4AFF000000000000000000000000000000000000
                0000000000000000000000000000FBFBFAFF989D9EFF3A474CFF192C34FF1026
                2FFF1A2E36FF16272FFF3F484BFFA8A9A9FF00000000008844FF8EDBCBFF00B9
                9DFF00B99DFF8EDBCBFF008844FF000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000D9DADAFF848B
                8EFF3E4D55FF1A2C33FF3E464AFF8B8C8CFFDEDEDDFF00000000000000000087
                42FF9AE0D3FF9AE0D3FF008742FF000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000EAEAEAFFBEC2C3FFA7A9A9FFE5E5E5FF00000000000000000000
                000000000000008A47FF008A47FF000000000000000000000000}
              TabOrder = 18
              Visible = False
              OnClick = cxButton30Click
            end
          end
          object AdvPanel8: TAdvPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 21
            Align = alTop
            BevelInner = bvLowered
            BevelOuter = bvNone
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            UseDockManager = True
            Visible = False
            Version = '2.5.7.4'
            BorderColor = clBtnFace
            BorderWidth = 1
            Caption.Color = clHighlight
            Caption.ColorTo = clNone
            Caption.Font.Charset = DEFAULT_CHARSET
            Caption.Font.Color = clWindowText
            Caption.Font.Height = -11
            Caption.Font.Name = 'Tahoma'
            Caption.Font.Style = []
            Caption.Indent = 0
            DoubleBuffered = True
            StatusBar.Font.Charset = DEFAULT_CHARSET
            StatusBar.Font.Color = clWindowText
            StatusBar.Font.Height = -11
            StatusBar.Font.Name = 'Tahoma'
            StatusBar.Font.Style = []
            FullHeight = 200
            object Label15: TLabel
              Left = 22
              Top = 4
              Width = 129
              Height = 13
              Caption = 'Neotoma CollectionUnitID: '
            end
          end
        end
        object TabSheetDataset: TTabSheet
          Caption = 'Dataset'
          ImageIndex = 4
          object ScrollBox3: TScrollBox
            Left = 0
            Top = 21
            Width = 896
            Height = 371
            Align = alClient
            Color = 10841658
            ParentColor = False
            TabOrder = 0
            object Label2: TLabel
              Left = 16
              Top = 256
              Width = 73
              Height = 13
              Caption = 'Dataset Notes:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label21: TLabel
              Left = 57
              Top = 18
              Width = 69
              Height = 13
              Caption = 'Dataset Type:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label22: TLabel
              Left = 16
              Top = 64
              Width = 72
              Height = 13
              Caption = 'Dataset Name:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label24: TLabel
              Left = 16
              Top = 112
              Width = 68
              Height = 13
              Caption = 'Investigators:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label25: TLabel
              Left = 16
              Top = 160
              Width = 60
              Height = 13
              Caption = 'Publications:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label31: TLabel
              Left = 16
              Top = 208
              Width = 56
              Height = 13
              Caption = 'Repository:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label34: TLabel
              Left = 327
              Top = 160
              Width = 82
              Height = 13
              Caption = 'Data Processors:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Memo2: TMemo
              Left = 16
              Top = 272
              Width = 280
              Height = 65
              TabOrder = 2
              OnExit = Memo2Exit
            end
            object Edit15: TEdit
              Left = 16
              Top = 80
              Width = 280
              Height = 21
              TabOrder = 13
              OnExit = Edit15Exit
            end
            object cxCheckComboBox2: TcxCheckComboBox
              Left = 16
              Top = 128
              BeepOnEnter = False
              Properties.ShowEmptyText = False
              Properties.EditValueFormat = cvfStatesString
              Properties.Items = <>
              Properties.ReadOnly = False
              Properties.OnCloseUp = cxCheckComboBox2PropertiesCloseUp
              Properties.OnInitPopup = cxCheckComboBox2PropertiesInitPopup
              Properties.OnPopup = cxCheckComboBox2PropertiesPopup
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsFrame3D
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 1
              Width = 280
            end
            object cxPopupEdit12: TcxPopupEdit
              Left = 16
              Top = 224
              BeepOnEnter = False
              Properties.ClearKey = 46
              Properties.PopupClientEdge = True
              Properties.PopupControl = AdvColumnGrid2
              Properties.PopupHeight = 400
              Properties.PopupSysPanelStyle = True
              Properties.ReadOnly = True
              Properties.OnInitPopup = cxPopupEdit12PropertiesInitPopup
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.PopupBorderStyle = epbsFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 3
              OnKeyUp = cxPopupEdit12KeyUp
              Width = 280
            end
            object cxCheckBox1: TcxCheckBox
              Left = 323
              Top = 19
              Caption = 'Top sample is a modern surface sample'
              ParentColor = False
              ParentFont = False
              Style.BorderColor = clWindowFrame
              Style.BorderStyle = ebsFlat
              Style.Color = 10841658
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWhite
              Style.Font.Height = -11
              Style.Font.Name = 'Tahoma'
              Style.Font.Style = []
              Style.HotTrack = True
              Style.LookAndFeel.Kind = lfFlat
              Style.Shadow = False
              Style.TransparentBorder = True
              Style.IsFontAssigned = True
              StyleDisabled.BorderStyle = ebs3D
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 0
              Transparent = True
              OnClick = cxCheckBox1Click
            end
            object cxGroupBox4: TcxGroupBox
              Left = 319
              Top = 42
              Ctl3D = True
              ParentCtl3D = False
              Style.BorderColor = clWhite
              Style.BorderStyle = ebsNone
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = True
              Style.TextColor = clWhite
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = True
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = True
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = True
              TabOrder = 7
              Height = 85
              Width = 234
              object Label35: TLabel
                Left = 8
                Top = 36
                Width = 66
                Height = 13
                Caption = 'Default Order'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                Visible = False
              end
              object cxCheckBox4: TcxCheckBox
                Left = 4
                Top = 8
                Caption = 'Aggregate Dataset'
                ParentColor = False
                ParentFont = False
                Style.BorderColor = clWindowFrame
                Style.BorderStyle = ebsFlat
                Style.Color = 10841658
                Style.Font.Charset = DEFAULT_CHARSET
                Style.Font.Color = clWhite
                Style.Font.Height = -11
                Style.Font.Name = 'Tahoma'
                Style.Font.Style = []
                Style.HotTrack = True
                Style.LookAndFeel.Kind = lfFlat
                Style.Shadow = False
                Style.TransparentBorder = True
                Style.IsFontAssigned = True
                StyleDisabled.BorderStyle = ebs3D
                StyleDisabled.LookAndFeel.Kind = lfFlat
                StyleFocused.LookAndFeel.Kind = lfFlat
                StyleHot.LookAndFeel.Kind = lfFlat
                TabOrder = 1
                Transparent = True
                OnClick = cxCheckBox4Click
              end
              object cxComboBox14: TcxComboBox
                Left = 8
                Top = 52
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                Style.BorderStyle = ebsFlat
                Style.Color = clWindow
                Style.LookAndFeel.Kind = lfFlat
                Style.TextColor = clWindowText
                StyleDisabled.Color = clWindow
                StyleDisabled.LookAndFeel.Kind = lfFlat
                StyleFocused.LookAndFeel.Kind = lfFlat
                StyleHot.LookAndFeel.Kind = lfFlat
                TabOrder = 0
                Visible = False
                OnClick = cxComboBox14Click
                Width = 217
              end
            end
            object cxCheckComboBox9: TcxCheckComboBox
              Left = 327
              Top = 176
              Properties.ShowEmptyText = False
              Properties.EditValueFormat = cvfStatesString
              Properties.Items = <>
              Properties.OnCloseUp = cxCheckComboBox9PropertiesCloseUp
              Properties.OnInitPopup = cxCheckComboBox9PropertiesInitPopup
              Properties.OnPopup = cxCheckComboBox9PropertiesPopup
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 4
              Width = 217
            end
            object cxButton21: TcxButton
              Left = 208
              Top = 108
              Width = 90
              Height = 19
              Caption = 'New Contact'
              LookAndFeel.Kind = lfOffice11
              TabOrder = 5
              Visible = False
              OnClick = cxButton21Click
            end
            object cxButton22: TcxButton
              Left = 469
              Top = 204
              Width = 90
              Height = 19
              Caption = 'New Contact'
              LookAndFeel.Kind = lfOffice11
              TabOrder = 6
              Visible = False
              OnClick = cxButton22Click
            end
            object cxComboBox13: TcxComboBox
              Left = 16
              Top = 35
              Properties.DropDownListStyle = lsEditFixedList
              Properties.OnCloseUp = cxComboBox13PropertiesCloseUp
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 8
              Width = 169
            end
            object AdvColumnGrid2: TAdvColumnGrid
              Left = 380
              Top = 187
              Width = 501
              Height = 109
              Cursor = crDefault
              ColCount = 4
              DrawingStyle = gdsClassic
              FixedCols = 0
              RowCount = 4
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 9
              Visible = False
              ActiveRowShow = True
              ActiveRowColor = 15387318
              HoverRowCells = [hcNormal, hcSelected]
              OnHoverButtonsShow = AdvColumnGrid2HoverButtonsShow
              OnCheckBoxChange = AdvColumnGrid2CheckBoxChange
              OnHoverButtonClick = AdvColumnGrid2HoverButtonClick
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'Include'
                'Acronym'
                'Repository'
                'Specimen Notes')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 2
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDown.TextChecked = 'Checked'
              FilterDropDown.TextUnChecked = 'Unchecked'
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Clear')
              FixedColWidth = 52
              FixedRowHeight = 22
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              GridImages = cxImageList1
              HideFocusRect = True
              HoverButtons.Enabled = True
              HoverButtons.Buttons = <
                item
                  Hint = 'Show Repository Notes'
                  ImageIndex = 72
                end
                item
                  Hint = 'Edit Repository Notes'
                  ImageIndex = 73
                end
                item
                  Hint = 'Add Repository'
                  ImageIndex = 74
                end>
              HoverButtons.Column = 2
              HoverButtons.Position = hbLeftFromColumnRight
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              SortSettings.DefaultFormat = ssAutomatic
              SortSettings.Column = 2
              SortSettings.Show = True
              SortSettings.IgnoreCase = True
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taCenter
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edCheckBox
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Include'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 52
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpNormalCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Acronym'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAlphaNumericNoCase
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpNormalCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Repository'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAlphaNumericNoCase
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 271
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpNormalCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Specimen Notes'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 110
                end>
              ColWidths = (
                52
                64
                271
                110)
            end
            object AdvColumnGrid6: TAdvColumnGrid
              Left = 444
              Top = 229
              Width = 274
              Height = 100
              Cursor = crDefault
              ColCount = 3
              DefaultRowHeight = 20
              DrawingStyle = gdsClassic
              FixedCols = 0
              RowCount = 3
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 10
              Visible = False
              HoverRowCells = [hcNormal, hcSelected]
              OnCanEditCell = AdvColumnGrid6CanEditCell
              OnCheckBoxChange = AdvColumnGrid6CheckBoxChange
              OnHoverButtonClick = AdvColumnGrid6HoverButtonClick
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'Include'
                'Primary'
                'Publication')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 2
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              ControlLook.NoDisabledCheckRadioLook = True
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDown.TextChecked = 'Checked'
              FilterDropDown.TextUnChecked = 'Unchecked'
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Larger than'
                'Smaller than'
                'Clear')
              FixedColWidth = 48
              FixedRowHeight = 20
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              GridImages = cxImageList1
              HideFocusRect = True
              HoverButtons.Enabled = True
              HoverButtons.Buttons = <
                item
                  Hint = 'Show publication'
                  ImageIndex = 71
                end>
              HoverButtons.Column = 2
              HoverButtons.Position = hbLeftFromColumnRight
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              SortSettings.DefaultFormat = ssAutomatic
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taCenter
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Include'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 48
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taCenter
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Primary'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 48
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Publication'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorderCustom = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 174
                end>
              ColWidths = (
                48
                48
                174)
            end
            object cxPopupEdit1: TcxPopupEdit
              Left = 16
              Top = 176
              BeepOnEnter = False
              Properties.ClearKey = 46
              Properties.PopupClientEdge = True
              Properties.PopupControl = AdvColumnGrid6
              Properties.PopupHeight = 400
              Properties.PopupSysPanelStyle = True
              Properties.ReadOnly = True
              Properties.OnCloseUp = cxPopupEdit1PropertiesCloseUp
              Properties.OnInitPopup = cxPopupEdit1PropertiesInitPopup
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.PopupBorderStyle = epbsFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 11
              Width = 280
            end
            object cxButton23: TcxButton
              Left = 16
              Top = 20
              Width = 37
              Height = 37
              Hint = 'Update site metadata in Neotoma'
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                96090000424D9609000000000000360000002800000019000000180000000100
                2000000000006009000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000F9F9F9FFE9E9E9FFE6E6E6FFFBFBFBFF000000000000000000000000FDFD
                FDFFE4E4E4FFD8D8D8FFEAEAEAFF00000000000000000000000000000000DDDD
                DDFFD7D6D7FFECECEDFF00000000000000000000000000000000000000000000
                0000FEFEFEFFF0F0F0FFB1B1B1FF9C9C9CFFDEDEDEFF00000000000000000000
                0000E2E2E2FF858585FF7A7A7AFF818181FFC2C2C2FFF4F4F4FF000000000000
                0000AAACACFF414850FFB3B7BAFF000000000000000000000000000000000000
                00000000000000000000F0F0F0FFBABABAFF737373FF8E8E8EFFF8F7F7FF0000
                000000000000EEEEEEFF929292FF6C6C6CFF505151FF646464FFADADADFFFDFD
                FDFF00000000E8E8E9FF48545DFF616D73FFF5F4F3FF00000000000000000000
                00000000000000000000D7D8D8FFCACACBFFC0C0C1FF5D5D5DFF272828FF6C71
                77FFDDDEE1FF0000000000000000C7C7C7FF737373FF565757FF515252FF6767
                67FFB6B6B6FFFEFEFEFF00000000D0D3D3FF5D686DFF788284FFCACCCEFFFFFE
                FEFF00000000D9D9D9FFA2A2A2FF434545FF696E70FF888E91FF62696CFF5D65
                67FF3E4D5BFF6A7482FFFEFDFCFF0000000000000000C1C1C1FF595959FF5151
                51FF3F4142FF525354FFE3E3E3FF0000000000000000E1E1E2FF6B767AFF606A
                6EFFA5A7A7FFB8B8B8FF8C8D8DFF636464FF4A4D50FF606668FF404547FF5A67
                6DFF748084FF657078FF33393FFF9A9898FFE9E9E9FF00000000F9F8F8FF8F8F
                90FF404445FF374145FF30373AFFA6A7A8FF000000000000000000000000D4D5
                D6FF6F777AFF72787BFF6C7178FF6B7278FF6F7373FF7D8182FF444748FF161A
                1CFF45535AFF57666CFF7D8486FF7B7B7AFF838282FFAEAEAEFFD6D6D6FFF4F4
                F4FFFDFDFDFF919595FF2C373CFF3B454AFF55585AFF00000000000000000000
                0000E7E7E8FF747C7FFF55626CFF4A5A6CFF505F6FFF606B77FF7A7E81FF5C60
                61FF333E43FF3D4B51FF3E4C52FFA4A6A7FFCDCDCDFFC4C3C3FFC3C3C3FFC4C4
                C4FFC7C7C7FFE9E9E9FFFAFAF9FF858A8CFF424F54FF3D4142FF000000000000
                000000000000E6E7E6FF626B6EFF384B5AFF425874FF485D7AFF3D5476FF5965
                72FF495457FF344147FF3E4C52FF343F43FF66696CFF555D66FF77797BFFE0E0
                DFFFD8D8D8FFB6B6B6FFB0B0B0FFCCCCCBFFC3C2C2FF4D5A5EFF404C52FF0000
                00000000000000000000DFE0E0FF546064FF405260FF435B79FF375175FF2D43
                62FF334149FF324349FF39474DFF39484EFF3E484BFF6D7376FF5A616AFF989B
                9FFFFFFFFEFFFBFBFBFF409E73FF008A4AFF008A4AFF42A076FF6E777AFF3649
                52FF000000000000000000000000989FA1FF42555CFF414D54FF465460FF3646
                58FF2F3E4BFF34444BFF2E4047FF2F414BFF2D4354FF6C757BFFD3D2D1FFF1F1
                F0FF000000000000000000000000008949FF00E7A7FF00E7A7FF008949FFB4B8
                BAFF31444CFF0000000000000000FAF9F9FF58646AFF304A55FF333F43FF383A
                3AFF2F3940FF2E3F4AFF384B53FF33474DFF293F4FFF2F486AFF5D6A76FF9397
                97FF9A9B9DFFA4A7AAFFF6F7F7FF00000000008847FF08E2A6FF00E0A2FF0088
                47FFDFE1E2FF3A4950FF0000000000000000FEFDFDFF69767BFF28424CFF394A
                51FF464F53FF253138FF17252CFF25383FFF36484DFF344553FF334C70FF4757
                68FF445155FF2B3540FF434E5CFFDADCDDFF00000000008747FF16E0ACFF00DC
                A2FF008847FFBABFC0FF46565CFF000000000000000000000000646E73FF1E37
                42FF2C3E46FF313D41FF0E1B22FF0E1B21FF1F3037FF3C4A4EFF333B40FF4556
                6AFF475664FF59676CFF5C6770FF434F5CFF8C9297FFEEEEEEFF008746FF23E0
                B2FF00D9A2FF008847FF6C797EFF889296FF0000000000000000000000008B8D
                8EFF19282FFF283B45FF213038FF0F1E25FF081A20FF16262EFF374449FF3C43
                44FF323537FF404C51FF677479FF737C80FF5A646AFF545D62FF7C8183FF0088
                46FF30DFB7FF00D5A2FF008847FF47575EFFE1E3E5FF00000000000000000000
                0000E8E6E6FF696D6EFF253942FF1B2F38FF192C33FF031821FF13242AFF1D2C
                33FF364146FF394246FF4F5D63FF616F75FF6F7A7EFF6A767BFF59656AFF535C
                60FF008845FF3EDFBDFF00D2A1FF008847FF9BA3A6FF00000000000000000000
                00000000000000000000696D6EFF273A42FF1C3640FF20343DFF071D27FF1124
                2CFF1C2C33FF26373FFF3B4D54FF536369FF5C6B71FF616F74FF757D81FF6874
                7AFF566268FF008845FF4BDFC1FF00CEA0FF008847FFF8F7F7FF000000000000
                00000000000000000000E7E6E5FF92999BFF293E47FF1F3943FF1F353EFF0B21
                2BFF122731FF24353CFF263941FF2E4048FF48575DFF55656BFF57676DFF6A75
                7AFF667277FF636F76FF008744FF58E0C7FF00CAA1FF008946FF000000000000
                0000000000000000000000000000E7E5E5FF878C8EFF5C696FFF0F2832FF142B
                35FF1B2F38FF122933FF1E3138FF23363EFF23363FFF304249FF4B5A61FF5867
                6EFF5D6C71FF505C62FF404C51FF008642FF6AE1CBFF00C9A1FF008744FF0000
                00330000002600000000000000000000000000000000CECFCFFF8E969AFF7A85
                8AFF5C696FFF2B3E45FF20343DFF1A2F37FF20333BFF273A42FF1F343DFF2D41
                49FF4F5D63FF4E5E64FF0F7B4BFF008846FF00AE7FFF00C39EFF00C39EFF00AE
                80FF008946FF006A39CD00000000000000000000000000000000000000000000
                000000000000F1F1F2FF838C90FF27383EFF192D36FF24363EFF22353DFF1F33
                3BFF253941FF364850FF4E585DFF008C4AFF82DCCAFF00C1A0FF00BE9BFF00BE
                9BFF00C1A0FF83DCCAFF008C4AFF000000000000000000000000000000000000
                0000000000000000000000000000FBFBFAFF989D9EFF3A474CFF192C34FF1026
                2FFF1A2E36FF16272FFF3F484BFFA8A9A9FF00000000008844FF8EDBCBFF00B9
                9DFF00B99DFF8EDBCBFF008844FF000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000D9DADAFF848B
                8EFF3E4D55FF1A2C33FF3E464AFF8B8C8CFFDEDEDDFF00000000000000000087
                42FF9AE0D3FF9AE0D3FF008742FF000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000EAEAEAFFBEC2C3FFA7A9A9FFE5E5E5FF00000000000000000000
                000000000000008A47FF008A47FF000000000000000000000000}
              TabOrder = 12
              Visible = False
              OnClick = cxButton23Click
            end
          end
          object AdvPanel9: TAdvPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 21
            Align = alTop
            BevelInner = bvLowered
            BevelOuter = bvNone
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            UseDockManager = True
            Visible = False
            Version = '2.5.7.4'
            BorderColor = clBtnFace
            BorderWidth = 1
            Caption.Color = clHighlight
            Caption.ColorTo = clNone
            Caption.Font.Charset = DEFAULT_CHARSET
            Caption.Font.Color = clWindowText
            Caption.Font.Height = -11
            Caption.Font.Name = 'Tahoma'
            Caption.Font.Style = []
            Caption.Indent = 0
            DoubleBuffered = True
            StatusBar.Font.Charset = DEFAULT_CHARSET
            StatusBar.Font.Color = clWindowText
            StatusBar.Font.Height = -11
            StatusBar.Font.Name = 'Tahoma'
            StatusBar.Font.Style = []
            FullHeight = 200
            object Label36: TLabel
              Left = 22
              Top = 4
              Width = 102
              Height = 13
              Caption = 'Neotoma DatasetID: '
            end
          end
        end
        object TabSheetGeochron: TTabSheet
          Caption = 'Geochronology'
          ImageIndex = 5
          OnShow = TabSheetGeochronShow
          object cxGrid2: TcxGrid
            Left = 0
            Top = 54
            Width = 896
            Height = 338
            Align = alClient
            TabOrder = 0
            LookAndFeel.Kind = lfUltraFlat
            LookAndFeel.NativeStyle = False
            LookAndFeel.SkinName = 'Lilian'
            object cxGrid2TableView1: TcxGridTableView
              Navigator.Buttons.CustomButtons = <>
              Navigator.Buttons.First.Visible = True
              Navigator.Buttons.Prior.Visible = True
              Navigator.Buttons.Append.Visible = False
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Post.Visible = True
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              OnCellClick = cxGrid2TableView1CellClick
              OnEditKeyDown = cxGrid2TableView1EditKeyDown
              OnEditKeyUp = cxGrid2TableView1EditKeyUp
              OnInitEdit = cxGrid2TableView1InitEdit
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              DataController.OnAfterPost = cxGrid2TableView1DataControllerAfterPost
              DataController.OnBeforePost = cxGrid2TableView1DataControllerBeforePost
              DataController.OnDetailExpanding = cxGrid2TableView1DataControllerDetailExpanding
              NewItemRow.Visible = True
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsBehavior.FocusCellOnCycle = True
              OptionsCustomize.ColumnFiltering = False
              OptionsCustomize.ColumnGrouping = False
              OptionsCustomize.ColumnHiding = True
              OptionsCustomize.ColumnMoving = False
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsSelection.InvertSelect = False
              OptionsSelection.MultiSelect = True
              OptionsSelection.CellMultiSelect = True
              OptionsView.CellEndEllipsis = True
              OptionsView.GroupByBox = False
              OptionsView.Indicator = True
              Styles.Background = cxStyle7
              Styles.Content = cxStyle17
              Styles.ContentEven = cxStyle17
              Styles.ContentOdd = cxStyle17
              Styles.Selection = cxStyle14
              Styles.Header = cxStyle3
              Styles.NewItemRowInfoText = cxStyle2
              Styles.StyleSheet = GridTableViewStyleSheetDevExpress
              object geMethod: TcxGridColumn
                Caption = 'Method'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                Properties.OnEditValueChanged = geMethodPropertiesEditValueChanged
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 80
              end
              object geAgeUnits: TcxGridColumn
                Caption = 'Age Units'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsFixedList
                Properties.DropDownSizeable = True
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object geDepth: TcxGridColumn
                Caption = 'Depth (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geDepthPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                SortIndex = 0
                SortOrder = soAscending
                Width = 80
              end
              object geThickness: TcxGridColumn
                Caption = 'Thickness (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geThicknessPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object geAnalUnit: TcxGridColumn
                Caption = 'Analysis Unit'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                Visible = False
                HeaderAlignmentHorz = taCenter
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object geAnalUnitID: TcxGridColumn
                Caption = 'AnalysisUnitID'
                DataBinding.ValueType = 'Integer'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.PopupControl = Panel19
                Properties.OnCloseUp = geAnalUnitIDPropertiesCloseUp
                Properties.OnPopup = geAnalUnitIDPropertiesPopup
                Visible = False
                HeaderAlignmentHorz = taCenter
                Width = 76
              end
              object geLabNumber: TcxGridColumn
                Caption = 'Lab Number'
                PropertiesClassName = 'TcxTextEditProperties'
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object geAge: TcxGridColumn
                Caption = 'Age'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geAgePropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 60
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 60
              end
              object geErrorOlder: TcxGridColumn
                Caption = 'Error Older'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geErrorOlderPropertiesValidate
                Visible = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 60
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 60
              end
              object geErrorYounger: TcxGridColumn
                Caption = 'Error Younger'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geErrorYoungerPropertiesValidate
                Visible = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 60
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 60
              end
              object geSigma: TcxGridColumn
                Caption = 'Sigma'
                DataBinding.ValueType = 'Integer'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.Alignment.Horz = taCenter
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownSizeable = True
                Properties.Items.Strings = (
                  '1'
                  '2')
                Properties.UseLeftAlignmentOnEditing = False
                Visible = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 40
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 40
              end
              object geSD: TcxGridColumn
                Caption = 'SD'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = geSDPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 40
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 40
              end
              object geInfinite: TcxGridColumn
                Caption = '>'
                DataBinding.ValueType = 'Boolean'
                PropertiesClassName = 'TcxCheckBoxProperties'
                Properties.Alignment = taCenter
                Properties.ImmediatePost = True
                HeaderAlignmentHorz = taCenter
                MinWidth = 40
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 40
              end
              object geParams: TcxGridColumn
                Caption = 'Params'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.ImmediateDropDownWhenActivated = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.PopupControl = Panel8
                Properties.PopupMinHeight = 20
                Properties.OnInitPopup = geParamsPropertiesInitPopup
                HeaderAlignmentHorz = taCenter
                MinWidth = 60
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 60
              end
              object geMaterialDated: TcxGridColumn
                Caption = 'Material Dated'
                PropertiesClassName = 'TcxTextEditProperties'
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object gePublication: TcxGridColumn
                Caption = 'Publication'
                PropertiesClassName = 'TcxCheckComboBoxProperties'
                Properties.ShowEmptyText = False
                Properties.DropDownSizeable = True
                Properties.Items = <>
                Properties.OnEditValueToStates = gePublicationPropertiesEditValueToStates
                Properties.OnStatesToEditValue = gePublicationPropertiesStatesToEditValue
                OnGetDisplayText = gePublicationGetDisplayText
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object geNotes: TcxGridColumn
                Caption = 'Notes'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                HeaderAlignmentHorz = taCenter
                MinWidth = 100
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 100
              end
            end
            object cxGrid2TableView2: TcxGridTableView
              Navigator.Buttons.CustomButtons = <>
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              OnFocusedItemChanged = cxGrid2TableView2FocusedItemChanged
              OnInitEdit = cxGrid2TableView2InitEdit
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              DataController.OnAfterPost = cxGrid2TableView2DataControllerAfterPost
              NewItemRow.Visible = True
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsBehavior.FocusCellOnCycle = True
              OptionsCustomize.ColumnFiltering = False
              OptionsCustomize.ColumnGrouping = False
              OptionsCustomize.ColumnMoving = False
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsSelection.InvertSelect = False
              OptionsSelection.MultiSelect = True
              OptionsSelection.CellMultiSelect = True
              OptionsView.CellEndEllipsis = True
              OptionsView.GroupByBox = False
              OptionsView.Indicator = True
              Styles.Background = cxStyle8
              Styles.Content = cxStyle15
              Styles.ContentEven = cxStyle15
              Styles.ContentOdd = cxStyle15
              Styles.FilterBox = cxStyle17
              Styles.Inactive = cxStyle22
              Styles.IncSearch = cxStyle23
              Styles.Selection = cxStyle14
              Styles.Footer = cxStyle18
              Styles.Group = cxStyle19
              Styles.GroupByBox = cxStyle20
              Styles.Header = cxStyle3
              Styles.Indicator = cxStyle24
              Styles.NewItemRowInfoText = cxStyle2
              Styles.Preview = cxStyle25
              Styles.StyleSheet = GridTableViewStyleSheetDevExpress
              object txUserSpecimenID: TcxGridColumn
                Caption = 'Spec ID'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsFixedList
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                Properties.OnValidate = txUserSpecimenIDPropertiesValidate
                OnGetCellHint = txUserSpecimenIDGetCellHint
                HeaderAlignmentHorz = taCenter
              end
              object txTaxon: TcxGridColumn
                Caption = 'Taxon'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownSizeable = True
                Properties.PostPopupValueOnTab = True
                Properties.Sorted = True
                Properties.OnInitPopup = txTaxonPropertiesInitPopup
                OnGetPropertiesForEdit = txTaxonGetPropertiesForEdit
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 160
              end
              object txElement: TcxGridColumn
                Caption = 'Element'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownSizeable = True
                Properties.PostPopupValueOnTab = True
                Properties.Sorted = True
                OnGetPropertiesForEdit = txElementGetPropertiesForEdit
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object txFraction: TcxGridColumn
                Caption = 'Fraction'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownSizeable = True
                Properties.PostPopupValueOnTab = True
                Properties.Sorted = True
                Properties.OnInitPopup = txFractionPropertiesInitPopup
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 100
              end
              object txCalAgeMedian: TcxGridColumn
                Caption = 'Cal Age Median'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                HeaderAlignmentHorz = taCenter
                Width = 90
              end
              object txCalAgeOlder: TcxGridColumn
                Caption = 'Cal Age Older'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                HeaderAlignmentHorz = taCenter
                Width = 90
              end
              object txCalAgeYounger: TcxGridColumn
                Caption = 'Cal Age Younger'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                HeaderAlignmentHorz = taCenter
                Width = 90
              end
              object txCalibCurve: TcxGridColumn
                Caption = 'Cal Curve'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.Sorted = True
                HeaderAlignmentHorz = taCenter
              end
              object txCalibProgram: TcxGridColumn
                Caption = 'Cal Program'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.ClearKey = 46
                Properties.ImmediateDropDownWhenActivated = False
                Properties.PopupAutoSize = False
                Properties.PopupControl = Panel10
                Properties.PopupHeight = 132
                Properties.PopupWidth = 145
                Properties.OnCloseUp = txCalibProgramPropertiesCloseUp
                Properties.OnEditValueChanged = txCalibProgramPropertiesEditValueChanged
                Properties.OnInitPopup = txCalibProgramPropertiesInitPopup
                Properties.OnPopup = txCalibProgramPropertiesPopup
                OnGetDisplayText = CalibProgramGetDisplayText
                HeaderAlignmentHorz = taCenter
              end
              object txNotes: TcxGridColumn
                Caption = 'Notes'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 120
              end
            end
            object cxGrid2Level1: TcxGridLevel
              GridView = cxGrid2TableView1
              object cxGrid2Level2: TcxGridLevel
                GridView = cxGrid2TableView2
              end
            end
          end
          object Panel8: TPanel
            Left = 297
            Top = 152
            Width = 259
            Height = 203
            BevelOuter = bvNone
            TabOrder = 1
            Visible = False
            DesignSize = (
              259
              203)
            object AdvColumnGrid3: TAdvColumnGrid
              Left = 0
              Top = 0
              Width = 259
              Height = 180
              Cursor = crDefault
              Align = alTop
              BevelOuter = bvNone
              BorderStyle = bsNone
              ColCount = 2
              Ctl3D = False
              DefaultRowHeight = 20
              DrawingStyle = gdsClassic
              FixedCols = 0
              RowCount = 9
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
              ParentCtl3D = False
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 0
              HoverRowCells = [hcNormal, hcSelected]
              OnCellValidate = AdvColumnGrid3CellValidate
              OnGetEditorType = AdvColumnGrid3GetEditorType
              OnGetEditorProp = AdvColumnGrid3GetEditorProp
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'Param'
                'Value')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ColumnSize.SynchWithGrid = True
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Clear')
              FixedColWidth = 77
              FixedRowHeight = 20
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clNavy
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = []
              Flat = True
              FloatFormat = '%.2f'
              FloatingFooter.FooterStyle = fsCustomPreview
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              Navigation.AlwaysEdit = True
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              ShowDesignHelper = False
              SortSettings.DefaultFormat = ssAutomatic
              Version = '3.1.6.0'
              WordWrap = False
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clBtnFace
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNone
                  FilterCaseSensitive = False
                  Fixed = True
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Param'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = [fsBold]
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 77
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Value'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = [fsBold]
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 182
                end>
              ColWidths = (
                77
                182)
            end
            object FlowPanel3: TFlowPanel
              Left = 146
              Top = 183
              Width = 108
              Height = 17
              Anchors = [akRight, akBottom]
              AutoSize = True
              AutoWrap = False
              BevelOuter = bvNone
              TabOrder = 1
              DesignSize = (
                108
                17)
              object cxButton24: TcxButton
                Left = 0
                Top = 0
                Width = 54
                Height = 17
                Anchors = [akRight, akBottom]
                Caption = 'Post'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.ImageIndex = 0
                OptionsImage.Images = ImageList2
                TabOrder = 0
                OnClick = cxButton24Click
              end
              object cxButton25: TcxButton
                Left = 54
                Top = 0
                Width = 54
                Height = 17
                Anchors = [akRight, akBottom]
                Caption = 'Cancel'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.ImageIndex = 1
                OptionsImage.Images = ImageList2
                TabOrder = 1
                OnClick = cxButton25Click
              end
            end
          end
          object FlowPanel7: TFlowPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 27
            Align = alTop
            AutoWrap = False
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 2
            object cxLabel2: TcxLabel
              Left = 2
              Top = 2
              Caption = 'Investigators: '
              Transparent = True
            end
            object cxCheckComboBox10: TcxCheckComboBox
              Left = 77
              Top = 2
              BeepOnEnter = False
              Properties.ShowEmptyText = False
              Properties.EditValueFormat = cvfStatesString
              Properties.Items = <>
              Properties.ReadOnly = False
              Properties.OnCloseUp = cxCheckComboBox10PropertiesCloseUp
              Properties.OnInitPopup = cxCheckComboBox10PropertiesInitPopup
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.Kind = lfFlat
              Style.LookAndFeel.NativeStyle = False
              Style.PopupBorderStyle = epbsFrame3D
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 1
              Width = 180
            end
            object cxLabel1: TcxLabel
              AlignWithMargins = True
              Left = 260
              Top = 3
              Margins.Top = 1
              Margins.Right = 1
              Caption = 'Notes:'
            end
            object cxBlobEdit1: TcxBlobEdit
              Left = 297
              Top = 2
              BeepOnEnter = False
              Properties.BlobEditKind = bekMemo
              Properties.BlobPaintStyle = bpsText
              Properties.MemoScrollBars = ssVertical
              Properties.OnCloseUp = cxBlobEdit1PropertiesCloseUp
              Style.BorderStyle = ebsFlat
              Style.LookAndFeel.NativeStyle = False
              Style.Shadow = False
              Style.ButtonStyle = btsDefault
              Style.ButtonTransparency = ebtNone
              Style.PopupBorderStyle = epbsDefault
              StyleDisabled.LookAndFeel.NativeStyle = False
              StyleFocused.LookAndFeel.NativeStyle = False
              StyleHot.LookAndFeel.NativeStyle = False
              TabOrder = 0
              Width = 152
            end
            object cxLabel7: TcxLabel
              Left = 449
              Top = 2
              Caption = '   Neotoma DatasetID: '
              Style.BorderStyle = ebsNone
              Style.LookAndFeel.Kind = lfUltraFlat
              Style.LookAndFeel.NativeStyle = True
              StyleDisabled.LookAndFeel.Kind = lfUltraFlat
              StyleDisabled.LookAndFeel.NativeStyle = True
              StyleFocused.LookAndFeel.Kind = lfUltraFlat
              StyleFocused.LookAndFeel.NativeStyle = True
              StyleHot.LookAndFeel.Kind = lfUltraFlat
              StyleHot.LookAndFeel.NativeStyle = True
              Visible = False
            end
          end
          object FlowPanel8: TFlowPanel
            Left = 0
            Top = 27
            Width = 896
            Height = 27
            Align = alTop
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 3
            object cxCheckBox2: TcxCheckBox
              Left = 2
              Top = 2
              Caption = 'Depth'
              TabOrder = 6
              OnClick = cxCheckBox2Click
            end
            object cxCheckBox3: TcxCheckBox
              Left = 55
              Top = 2
              Caption = 'Analysis Unit'
              TabOrder = 7
              OnClick = cxCheckBox3Click
            end
            object Bevel1: TBevel
              Left = 140
              Top = 2
              Width = 2
              Height = 21
            end
            object Panel4: TPanel
              Left = 142
              Top = 2
              Width = 8
              Height = 21
              BevelEdges = [beLeft]
              BevelOuter = bvNone
              TabOrder = 3
            end
            object cxRadioButton7: TcxRadioButton
              Left = 150
              Top = 2
              Width = 70
              Height = 21
              Caption = #177'1 Sigma'
              Checked = True
              TabOrder = 4
              TabStop = True
              OnClick = cxRadioButton7Click
              GroupIndex = 2
              LookAndFeel.Kind = lfStandard
              LookAndFeel.NativeStyle = True
            end
            object cxRadioButton8: TcxRadioButton
              Left = 220
              Top = 2
              Width = 96
              Height = 21
              Caption = 'Older/Younger'
              TabOrder = 5
              OnClick = cxRadioButton8Click
              GroupIndex = 2
              LookAndFeel.Kind = lfStandard
              LookAndFeel.NativeStyle = True
            end
            object cxButton4: TcxButton
              Left = 316
              Top = 2
              Width = 90
              Height = 21
              Caption = 'Taxa Lookup'
              LookAndFeel.Kind = lfFlat
              OptionsImage.ImageIndex = 31
              OptionsImage.Images = cxImageList1
              TabOrder = 0
              Visible = False
              OnClick = cxButton4Click
            end
            object cxButton17: TcxButton
              Left = 406
              Top = 2
              Width = 90
              Height = 21
              Caption = 'Calibrate'
              LookAndFeel.Kind = lfFlat
              OptionsImage.ImageIndex = 35
              OptionsImage.Images = cxImageList1
              TabOrder = 1
              Visible = False
              OnClick = cxButton17Click
            end
            object cxButton18: TcxButton
              Left = 496
              Top = 2
              Width = 90
              Height = 21
              Caption = 'New Fraction'
              LookAndFeel.Kind = lfFlat
              OptionsImage.ImageIndex = 48
              OptionsImage.Images = cxImageList1
              TabOrder = 2
              Visible = False
              OnClick = cxButton18Click
            end
          end
          object Panel19: TPanel
            Left = 544
            Top = 164
            Width = 300
            Height = 133
            TabOrder = 4
            Visible = False
            object AdvColumnGrid8: TAdvColumnGrid
              Left = 1
              Top = 1
              Width = 298
              Height = 114
              Cursor = crDefault
              Align = alClient
              ColCount = 4
              Ctl3D = True
              DefaultRowHeight = 18
              DrawingStyle = gdsClassic
              FixedCols = 0
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
              ParentCtl3D = False
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 0
              OnDblClick = AdvColumnGrid8DblClick
              HoverRowCells = [hcNormal, hcSelected]
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'ID'
                'Name'
                'Depth'
                'Thickness')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              EnhTextSize = True
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDown.TextChecked = 'Checked'
              FilterDropDown.TextUnChecked = 'Unchecked'
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Larger than'
                'Smaller than'
                'Clear')
              FixedRowHeight = 18
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              ScrollProportional = True
              ScrollType = ssFlat
              ScrollWidth = 13
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              ShowFocusedSelectionColor = False
              SortSettings.DefaultFormat = ssAutomatic
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'ID'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Name'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 85
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Depth'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Thickness'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end>
              ExplicitLeft = 0
              ExplicitTop = -6
              ExplicitWidth = 300
              ExplicitHeight = 116
              ColWidths = (
                64
                85
                64
                64)
            end
            object FlowPanel11: TFlowPanel
              Left = 1
              Top = 115
              Width = 298
              Height = 17
              Align = alBottom
              BevelOuter = bvNone
              TabOrder = 1
              object cxButton42: TcxButton
                Left = 0
                Top = 0
                Width = 60
                Height = 17
                Caption = 'Ok'
                LookAndFeel.NativeStyle = True
                LookAndFeel.SkinName = ''
                OptionsImage.ImageIndex = 2
                OptionsImage.Images = cxImageList2
                SpeedButtonOptions.AllowAllUp = True
                TabOrder = 0
                OnClick = cxButton42Click
              end
              object cxButton43: TcxButton
                Left = 60
                Top = 0
                Width = 60
                Height = 17
                Caption = 'Cancel'
                OptionsImage.ImageIndex = 0
                OptionsImage.Images = cxImageList2
                SpeedButtonOptions.AllowAllUp = True
                TabOrder = 1
                OnClick = cxButton43Click
              end
            end
          end
        end
        object TabSheetAgeModels: TTabSheet
          Caption = 'Chronologies'
          ImageIndex = 6
          OnShow = TabSheetAgeModelsShow
          object cxGrid3: TcxGrid
            Left = 0
            Top = 27
            Width = 896
            Height = 365
            Align = alClient
            TabOrder = 0
            LookAndFeel.Kind = lfUltraFlat
            LookAndFeel.NativeStyle = False
            LookAndFeel.SkinName = 'Lilian'
            object cxGrid3TableView1: TcxGridTableView
              Navigator.Buttons.OnButtonClick = cxGrid3TableView1NavigatorButtonsButtonClick
              Navigator.Buttons.CustomButtons = <
                item
                  ImageIndex = 53
                  Visible = False
                end>
              Navigator.Buttons.Images = cxImageList1
              Navigator.Buttons.Insert.Visible = True
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              OnEditKeyDown = cxGrid3TableView1EditKeyDown
              OnEditKeyUp = cxGrid3TableView1EditKeyUp
              OnFocusedRecordChanged = cxGrid3TableView1FocusedRecordChanged
              OnInitEdit = cxGrid3TableView1InitEdit
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoSortByDisplayText]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              DataController.OnAfterPost = cxGrid3TableView1DataControllerAfterPost
              DataController.OnBeforePost = cxGrid3TableView1DataControllerBeforePost
              NewItemRow.Visible = True
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsBehavior.FocusCellOnCycle = True
              OptionsCustomize.ColumnFiltering = False
              OptionsCustomize.ColumnGrouping = False
              OptionsCustomize.ColumnMoving = False
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsSelection.InvertSelect = False
              OptionsSelection.MultiSelect = True
              OptionsSelection.CellMultiSelect = True
              OptionsView.CellEndEllipsis = True
              OptionsView.GroupByBox = False
              OptionsView.Indicator = True
              Styles.Background = cxStyle7
              Styles.Content = cxStyle17
              Styles.ContentEven = cxStyle17
              Styles.ContentOdd = cxStyle17
              Styles.Selection = cxStyle14
              Styles.Header = cxStyle3
              Styles.Indicator = cxStyle24
              Styles.NewItemRowInfoText = cxStyle2
              Styles.StyleSheet = GridTableViewStyleSheetDevExpress
              object amChronNo: TcxGridColumn
                Caption = 'Chron No.'
                DataBinding.ValueType = 'Integer'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taCenter
                Properties.UseLeftAlignmentOnEditing = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 60
                Options.Editing = False
                Options.Focusing = False
                Options.Moving = False
                SortIndex = 0
                SortOrder = soAscending
                Width = 60
              end
              object amName: TcxGridColumn
                Caption = 'Name'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.ValidateOnEnter = True
                Properties.OnEditValueChanged = amNamePropertiesEditValueChanged
                HeaderAlignmentHorz = taCenter
                MinWidth = 100
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 100
              end
              object amAgeUnits: TcxGridColumn
                Caption = 'Age Units'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownSizeable = True
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object amDefault: TcxGridColumn
                Caption = 'Default'
                DataBinding.ValueType = 'Boolean'
                PropertiesClassName = 'TcxCheckBoxProperties'
                Properties.ImmediatePost = True
                HeaderAlignmentHorz = taCenter
                MinWidth = 45
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 45
              end
              object amAgeModel: TcxGridColumn
                Caption = 'Age Model'
                PropertiesClassName = 'TcxTextEditProperties'
                HeaderAlignmentHorz = taCenter
                MinWidth = 100
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 100
              end
              object amOlderBound: TcxGridColumn
                Caption = 'Older Bound'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = amOlderBoundPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object amYoungerBound: TcxGridColumn
                Caption = 'Younger Bound'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = amYoungerBoundPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object amPreparer: TcxGridColumn
                Caption = 'Preparers'
                PropertiesClassName = 'TcxCheckComboBoxProperties'
                Properties.ShowEmptyText = False
                Properties.DropDownSizeable = True
                Properties.Items = <>
                Properties.OnEditValueToStates = amPreparerPropertiesEditValueToStates
                Properties.OnStatesToEditValue = amPreparerPropertiesStatesToEditValue
                OnGetDisplayText = amPreparerGetDisplayText
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object amDatePrepared: TcxGridColumn
                Caption = 'Date Prepared'
                DataBinding.ValueType = 'DateTime'
                PropertiesClassName = 'TcxDateEditProperties'
                Properties.UseLeftAlignmentOnEditing = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 90
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 90
              end
              object amNotes: TcxGridColumn
                Caption = 'Notes'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                HeaderAlignmentHorz = taCenter
                MinWidth = 100
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 100
              end
            end
            object cxGrid3TableView2: TcxGridTableView
              Navigator.Buttons.CustomButtons = <>
              Navigator.Buttons.Insert.Visible = True
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              OnEditKeyDown = cxGrid3TableView2EditKeyDown
              OnEditKeyUp = cxGrid3TableView2EditKeyUp
              OnFocusedItemChanged = cxGrid3TableView2FocusedItemChanged
              OnFocusedRecordChanged = cxGrid3TableView2FocusedRecordChanged
              OnInitEdit = cxGrid3TableView2InitEdit
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoSortByDisplayText]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              DataController.OnAfterPost = cxGrid3TableView2DataControllerAfterPost
              DataController.OnBeforeDelete = cxGrid3TableView2DataControllerBeforeDelete
              NewItemRow.Visible = True
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsBehavior.FocusCellOnCycle = True
              OptionsCustomize.ColumnFiltering = False
              OptionsCustomize.ColumnGrouping = False
              OptionsCustomize.ColumnMoving = False
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsSelection.InvertSelect = False
              OptionsSelection.MultiSelect = True
              OptionsSelection.CellMultiSelect = True
              OptionsView.CellEndEllipsis = True
              OptionsView.GroupByBox = False
              OptionsView.Indicator = True
              Styles.Background = cxStyle8
              Styles.Content = cxStyle15
              Styles.ContentEven = cxStyle15
              Styles.ContentOdd = cxStyle15
              Styles.Selection = cxStyle14
              Styles.Header = cxStyle3
              Styles.NewItemRowInfoText = cxStyle2
              Styles.StyleSheet = GridTableViewStyleSheetDevExpress
              object chDepth: TcxGridColumn
                Caption = 'Depth (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = chDepthPropertiesValidate
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                SortIndex = 0
                SortOrder = soAscending
                Width = 80
              end
              object chThickness: TcxGridColumn
                Caption = 'Thickness (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = chThicknessPropertiesValidate
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object chAnalUnit: TcxGridColumn
                Caption = 'Analysis Unit'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                Visible = False
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object chAnalUnitID: TcxGridColumn
                Caption = 'AnalysisUnitID'
                DataBinding.ValueType = 'Integer'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.ClearKey = 46
                Properties.ImmediateDropDownWhenActivated = False
                Properties.PopupControl = Panel15
                Properties.OnCloseUp = chAnalUnitIDPropertiesCloseUp
                Properties.OnPopup = chAnalUnitIDPropertiesPopup
                Visible = False
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                Options.Sorting = False
                Width = 76
              end
              object chAgeUnits: TcxGridColumn
                Caption = 'Age Units'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsEditFixedList
                Properties.DropDownRows = 2
                Properties.Items.Strings = (
                  'Calendar'
                  'Radiocarbon')
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object chAge: TcxGridColumn
                Caption = 'Age'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = chAgePropertiesValidate
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                SortIndex = 1
                SortOrder = soAscending
                Width = 80
              end
              object chOlderLimit: TcxGridColumn
                Caption = 'Older Limit'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = chOlderLimitPropertiesValidate
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object chYoungerLimit: TcxGridColumn
                Caption = 'Younger Limit'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = chYoungerLimitPropertiesValidate
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 80
              end
              object chAgeBasis: TcxGridColumn
                Caption = 'Age Basis'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.ClearKey = 46
                Properties.ImmediateDropDownWhenActivated = False
                Properties.ImmediateDropDownWhenKeyPressed = False
                Properties.LookupItemsSorted = True
                Properties.PopupAutoSize = False
                Properties.PopupControl = Panel24
                Properties.PopupMinWidth = 160
                Properties.ReadOnly = False
                Properties.OnCloseUp = chAgeBasisPropertiesCloseUp
                Properties.OnEditValueChanged = chAgeBasisPropertiesEditValueChanged
                Properties.OnPopup = chAgeBasisPropertiesPopup
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 160
              end
              object chCalibCurve: TcxGridColumn
                Caption = 'Cal Curve'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.ClearKey = 46
                Properties.DropDownSizeable = True
                Properties.Sorted = True
                HeaderAlignmentHorz = taCenter
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 80
              end
              object chCalibProgram: TcxGridColumn
                Caption = 'Cal Program'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.ClearKey = 46
                Properties.ImmediateDropDownWhenActivated = False
                Properties.PopupAutoSize = False
                Properties.PopupControl = Panel10
                Properties.PopupHeight = 132
                Properties.PopupWidth = 145
                Properties.OnCloseUp = chCalibProgramPropertiesCloseUp
                Properties.OnEditValueChanged = chCalibProgramPropertiesEditValueChanged
                Properties.OnInitPopup = chCalibProgramPropertiesInitPopup
                Properties.OnPopup = chCalibProgramPropertiesPopup
                OnGetDisplayText = CalibProgramGetDisplayText
                HeaderAlignmentHorz = taCenter
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 80
              end
              object chGeochron: TcxGridColumn
                Caption = 'Geochronology Links'
                PropertiesClassName = 'TcxPopupEditProperties'
                Properties.Alignment.Horz = taLeftJustify
                Properties.ImmediateDropDownWhenActivated = False
                Properties.PopupAutoSize = False
                Properties.PopupControl = ProfGridGeochron
                Properties.PopupSysPanelStyle = True
                Properties.PopupWidth = 332
                Properties.OnCloseUp = chGeochronPropertiesCloseUp
                Properties.OnPopup = chGeochronPropertiesPopup
                OnGetDisplayText = chGeochronGetDisplayText
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 120
              end
              object chNotes: TcxGridColumn
                Caption = 'Notes'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                HeaderAlignmentHorz = taCenter
                HeaderGlyphAlignmentHorz = taCenter
                HeaderGlyphAlignmentVert = vaTop
              end
            end
            object cxGrid3Level1: TcxGridLevel
              GridView = cxGrid3TableView1
              object cxGrid3Level2: TcxGridLevel
                GridView = cxGrid3TableView2
              end
            end
          end
          object Panel24: TPanel
            Left = 72
            Top = 133
            Width = 132
            Height = 79
            BevelOuter = bvNone
            TabOrder = 1
            Visible = False
            DesignSize = (
              132
              79)
            object cxTreeView1: TcxTreeView
              Left = 0
              Top = 0
              Width = 132
              Height = 59
              Align = alTop
              Anchors = [akLeft, akTop, akRight, akBottom]
              PopupMenu = PopupMenu8
              Style.BorderColor = clWindowFrame
              Style.BorderStyle = cbsSingle
              Style.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 1
              OnClick = cxTreeView1Click
              OnDragDrop = cxTreeView1DragDrop
              OnDragOver = cxTreeView1DragOver
              OnKeyDown = cxTreeView1KeyDown
              OnMouseDown = cxTreeView1MouseDown
              HideSelection = False
              HotTrack = True
              MultiSelectStyle = [msControlSelect, msShiftSelect, msVisibleOnly, msSiblingOnly]
              ReadOnly = True
              RightClickSelect = True
              OnCollapsed = cxTreeView1Collapsed
              OnExpanded = cxTreeView1Expanded
            end
            object cxButton26: TcxButton
              Left = 74
              Top = 60
              Width = 56
              Height = 17
              Anchors = [akRight, akBottom]
              Caption = 'Cancel'
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                32010000424D3201000000000000360000002800000009000000090000000100
                180000000000FC000000C40E0000C40E00000000000000000000F0F0F00908B7
                F0F0F0F0F0F0F0F0F0F0F0F0F0F0F00707B1F0F0F0001313BC0F10BB0C0CB9F0
                F0F0F0F0F0F0F0F00707B40708B30707B200F0F0F01717BF1414BD1010BBF0F0
                F00909B70808B60808B5F0F0F000F0F0F0F0F0F01D1DC21918C01515BE1111BC
                0E0EBAF0F0F0F0F0F000F0F0F0F0F0F0F0F0F02222C41E1EC21919C0F0F0F0F0
                F0F0F0F0F000F0F0F0F0F0F03232CB2D2DC92928C72424C51F1FC2F0F0F0F0F0
                F000F0F0F04444D13F3FCF3939CDF0F0F02E2EC92A2AC72525C5F0F0F0005858
                D75151D54C4CD3F0F0F0F0F0F0F0F0F03535CB3030C92B2BC700F0F0F05E5ED9
                F0F0F0F0F0F0F0F0F0F0F0F0F0F0F03C3CCEF0F0F000}
              OptionsImage.ImageIndex = 0
              TabOrder = 0
              OnClick = cxButton26Click
            end
          end
          object ProfGridGeochron: TProfGrid
            Left = 47
            Top = 246
            Width = 312
            Height = 88
            About = 'v3.4.4.11 for C++Builder XE'
            ColCount = 5
            RowCount = 5
            FixedCols = 0
            FixedRows = 1
            Color = 13828095
            DefaultColWidth = 64
            DefaultRowHeight = 14
            GridLineWidth = 1
            Options = [pgoFixedVertLine, pgoFixedHorzLine, pgoVertLine, pgoHorzLine, pgoDrawFocusSelected, pgoRowSizing, pgoColSizing, pgoTabs, pgoRowSelect, pgoAutoIncreaseRowHeights, pgoAutoDecreaseRowHeights, pgoMultiLineCells, pgoClearCellOnDel]
            PrintFooter.Font.Charset = DEFAULT_CHARSET
            PrintFooter.Font.Color = clWindowText
            PrintFooter.Font.Height = -13
            PrintFooter.Font.Name = 'Arial'
            PrintFooter.Font.Style = []
            PrintHeader.Font.Charset = DEFAULT_CHARSET
            PrintHeader.Font.Color = clWindowText
            PrintHeader.Font.Height = -13
            PrintHeader.Font.Name = 'Arial'
            PrintHeader.Font.Style = []
            SelectionFontColor = clHighlightText
            SortColumn = 2
            SortIndicator = True
            SortOnClick = True
            SortOnDblClick = True
            SpreadsheetOptions = [soExcelStyleHeadings, soExcelStyleHeadingHighlight, soExcelStyleNavigation, soExcelStyleComments, soMouseBuildUpFormula]
            SpreadsheetStyle = ssExcelXP
            SelectionColor = clHighlight
            BorderStyle = bsNone
            Ctl3D = False
            ParentCtl3D = False
            ParentFont = True
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
            Visible = False
            UsedColumns = <
              item
                AbsoluteNumber = 0
                Movable = False
                Sortable = False
                CheckBox = True
              end
              item
                AbsoluteNumber = 1
                HorizontalAlignment = haRight
                ParentHorizontalAlignment = False
                WordWrap = False
                ParentWordWrap = False
                Movable = False
                ReadOnly = True
              end
              item
                AbsoluteNumber = 2
                HorizontalAlignment = haRight
                ParentHorizontalAlignment = False
                WordWrap = False
                ParentWordWrap = False
                Movable = False
                ReadOnly = True
              end
              item
                AbsoluteNumber = 3
                HorizontalAlignment = haRight
                ParentHorizontalAlignment = False
                WordWrap = False
                ParentWordWrap = False
                Movable = False
                ReadOnly = True
              end
              item
                AbsoluteNumber = 4
                HorizontalAlignment = haRight
                ParentHorizontalAlignment = False
                WordWrap = False
                ParentWordWrap = False
                Movable = False
                Sortable = False
                ReadOnly = True
              end>
            UsedRows = <>
            UsedCells = <
              item
                AbsoluteCol = 0
                AbsoluteRow = 0
                Value = 'Include'
                HorizontalAlignment = haCenter
                ParentHorizontalAlignment = False
              end
              item
                AbsoluteCol = 1
                AbsoluteRow = 0
                Value = 'Lab Nr'
                HorizontalAlignment = haCenter
                ParentHorizontalAlignment = False
              end
              item
                AbsoluteCol = 2
                AbsoluteRow = 0
                Value = 'Depth'
                HorizontalAlignment = haCenter
                ParentHorizontalAlignment = False
              end
              item
                AbsoluteCol = 3
                AbsoluteRow = 0
                Value = 'Age'
                HorizontalAlignment = haCenter
                ParentHorizontalAlignment = False
                GraphicAlignment = taCenter
              end
              item
                AbsoluteCol = 4
                AbsoluteRow = 0
                Value = 'SD'
                HorizontalAlignment = haCenter
                ParentHorizontalAlignment = False
                GraphicAlignment = taCenter
              end>
            OnMouseDown = ProfGridGeochronMouseDown
            OnMouseMove = ProfGridGeochronMouseMove
            ColWidths = (
              48
              88
              64
              64
              48)
          end
          object Panel9: TPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 27
            Align = alTop
            BevelInner = bvLowered
            TabOrder = 4
            object Panel14: TPanel
              Left = 2
              Top = 2
              Width = 8
              Height = 23
              Align = alLeft
              BevelOuter = bvNone
              TabOrder = 1
            end
            object FlowPanel9: TFlowPanel
              Left = 10
              Top = 2
              Width = 661
              Height = 23
              Align = alLeft
              AutoSize = True
              AutoWrap = False
              BevelOuter = bvNone
              TabOrder = 0
              object CheckBox1: TCheckBox
                Left = 0
                Top = 0
                Width = 53
                Height = 21
                Caption = 'Depth'
                TabOrder = 6
                OnClick = CheckBox1Click
              end
              object CheckBox3: TCheckBox
                Left = 53
                Top = 0
                Width = 88
                Height = 21
                Caption = 'Analysis Unit'
                TabOrder = 1
                OnClick = CheckBox3Click
              end
              object CheckBox2: TCheckBox
                Left = 141
                Top = 0
                Width = 128
                Height = 21
                Align = alRight
                Caption = 'Auto Chron Numbers'
                Checked = True
                State = cbChecked
                TabOrder = 0
                OnClick = CheckBox2Click
              end
              object cxButton11: TcxButton
                Left = 269
                Top = 0
                Width = 64
                Height = 23
                Align = alLeft
                Caption = 'Link'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.ImageIndex = 49
                OptionsImage.Images = cxImageList1
                TabOrder = 2
                Visible = False
                OnClick = cxButton11Click
              end
              object cxButton19: TcxButton
                Left = 333
                Top = 0
                Width = 64
                Height = 23
                Align = alLeft
                Caption = 'Import'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.ImageIndex = 50
                OptionsImage.Images = cxImageList1
                TabOrder = 3
                Visible = False
                OnClick = cxButton19Click
              end
              object cxButton20: TcxButton
                Left = 397
                Top = 0
                Width = 64
                Height = 23
                Align = alLeft
                Caption = 'Export'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.ImageIndex = 51
                OptionsImage.Images = cxImageList1
                TabOrder = 4
                Visible = False
                OnClick = cxButton20Click
              end
              object cxButton39: TcxButton
                Left = 461
                Top = 0
                Width = 200
                Height = 25
                Caption = 'Create Collection Date Age Model'
                OptionsImage.ImageIndex = 78
                OptionsImage.Images = cxImageList1
                TabOrder = 5
                Visible = False
                OnClick = cxButton39Click
              end
            end
          end
          object Panel10: TPanel
            Left = 392
            Top = 208
            Width = 128
            Height = 132
            BevelOuter = bvNone
            TabOrder = 3
            Visible = False
            object FlowPanel12: TFlowPanel
              Left = 0
              Top = 113
              Width = 128
              Height = 19
              Align = alBottom
              AutoWrap = False
              TabOrder = 0
              object cxButton5: TcxButton
                Left = 1
                Top = 1
                Width = 60
                Height = 17
                Caption = 'Cancel'
                LookAndFeel.Kind = lfUltraFlat
                OptionsImage.Glyph.Data = {
                  7A010000424D7A01000000000000360000002800000009000000090000000100
                  2000000000004401000000000000000000000000000000000000000000000908
                  B7FF00000000000000000000000000000000000000000707B1FF000000001313
                  BCFF0F10BBFF0C0CB9FF0000000000000000000000000707B4FF0708B3FF0707
                  B2FF000000001717BFFF1414BDFF1010BBFF000000000909B7FF0808B6FF0808
                  B5FF0000000000000000000000001D1DC2FF1918C0FF1515BEFF1111BCFF0E0E
                  BAFF00000000000000000000000000000000000000002222C4FF1E1EC2FF1919
                  C0FF00000000000000000000000000000000000000003232CBFF2D2DC9FF2928
                  C7FF2424C5FF1F1FC2FF0000000000000000000000004444D1FF3F3FCFFF3939
                  CDFF000000002E2EC9FF2A2AC7FF2525C5FF000000005858D7FF5151D5FF4C4C
                  D3FF0000000000000000000000003535CBFF3030C9FF2B2BC7FF000000005E5E
                  D9FF00000000000000000000000000000000000000003C3CCEFF00000000}
                TabOrder = 0
                OnClick = cxButton5Click
              end
              object cxButton6: TcxButton
                Left = 61
                Top = 1
                Width = 60
                Height = 17
                Caption = 'New'
                LookAndFeel.Kind = lfOffice11
                OptionsImage.Glyph.Data = {
                  7A010000424D7A01000000000000360000002800000009000000090000000100
                  2000000000004401000000000000000000000000000000000000000000000000
                  00000000000009560DCA1D7B2DFF09550FC70000000000000000000000000000
                  000000000000000000000C6A15F14EBB7AFF0C6A15F100000000000000000000
                  00000000000000000000000000000D6D16F151C47FFF0D6D16F1000000000000
                  0000000000001F772AFF1C852FFF268F3EFF157E22FF52C883FF137B1FFF268F
                  3EFF268F3EFF126720D6258D3BFF66D195FF66D195FF66D195FF50BB83FF64CF
                  93FF66D195FF64CF93FF218A38FF219455FF16802AFF147C26FF0E7515FF7ADC
                  A6FF117719FF1E8029FF177922FF0B5B13C40000000000000000000000001C7F
                  28FF84E3AEFF1C7F28FF00000000000000000000000000000000000000000000
                  000020832CFF8CE8B5FF20832CFF000000000000000000000000000000000000
                  0000000000003C9348FF2CB353FF449F54FF000000000000000000000000}
                TabOrder = 1
                OnClick = cxButton6Click
              end
            end
            object AdvColumnGrid9: TAdvColumnGrid
              Left = 0
              Top = 0
              Width = 128
              Height = 113
              Cursor = crDefault
              Align = alClient
              ColCount = 2
              DefaultRowHeight = 18
              DrawingStyle = gdsClassic
              FixedCols = 0
              RowCount = 3
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 1
              HoverRow = True
              HoverRowCells = [hcNormal, hcSelected]
              OnClickCell = AdvColumnGrid9ClickCell
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'Program'
                'Version')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              EnhTextSize = True
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDown.TextChecked = 'Checked'
              FilterDropDown.TextUnChecked = 'Unchecked'
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Larger than'
                'Smaller than'
                'Clear')
              FixedColWidth = 60
              FixedRowHeight = 18
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              ShowDesignHelper = False
              SortSettings.DefaultFormat = ssAutomatic
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Program'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 60
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Version'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end>
              ExplicitHeight = 91
              ColWidths = (
                60
                64)
            end
          end
          object Panel15: TPanel
            Left = 544
            Top = 164
            Width = 300
            Height = 133
            TabOrder = 5
            Visible = False
            object AdvColumnGrid7: TAdvColumnGrid
              Left = 1
              Top = 1
              Width = 298
              Height = 114
              Cursor = crDefault
              Align = alClient
              ColCount = 4
              Ctl3D = True
              DefaultRowHeight = 18
              DrawingStyle = gdsClassic
              FixedCols = 0
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
              ParentCtl3D = False
              ParentFont = False
              ScrollBars = ssBoth
              TabOrder = 0
              OnDblClick = AdvColumnGrid7DblClick
              HoverRowCells = [hcNormal, hcSelected]
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                'ID'
                'Name'
                'Depth'
                'Thickness')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              EnhTextSize = True
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDown.TextChecked = 'Checked'
              FilterDropDown.TextUnChecked = 'Unchecked'
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Larger than'
                'Smaller than'
                'Clear')
              FixedRowHeight = 18
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              HoverButtons.Buttons = <>
              HoverButtons.Position = hbLeftFromColumnLeft
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              ScrollProportional = True
              ScrollType = ssFlat
              ScrollWidth = 13
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              ShowFocusedSelectionColor = False
              SortSettings.DefaultFormat = ssAutomatic
              Version = '3.1.6.0'
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'ID'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Name'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 85
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Depth'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taRightJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Thickness'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 36
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = False
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 64
                end>
              ExplicitLeft = 0
              ExplicitTop = -6
              ExplicitWidth = 300
              ExplicitHeight = 116
              ColWidths = (
                64
                85
                64
                64)
            end
            object FlowPanel10: TFlowPanel
              Left = 1
              Top = 115
              Width = 298
              Height = 17
              Align = alBottom
              BevelOuter = bvNone
              TabOrder = 1
              object cxButton40: TcxButton
                Left = 0
                Top = 0
                Width = 60
                Height = 17
                Caption = 'Ok'
                LookAndFeel.NativeStyle = True
                LookAndFeel.SkinName = ''
                OptionsImage.ImageIndex = 2
                OptionsImage.Images = cxImageList2
                SpeedButtonOptions.AllowAllUp = True
                TabOrder = 0
                OnClick = cxButton40Click
              end
              object cxButton41: TcxButton
                Left = 60
                Top = 0
                Width = 60
                Height = 17
                Caption = 'Cancel'
                OptionsImage.ImageIndex = 0
                OptionsImage.Images = cxImageList2
                SpeedButtonOptions.AllowAllUp = True
                TabOrder = 1
                OnClick = cxButton41Click
              end
            end
          end
        end
        object TabSheetLithology: TTabSheet
          Caption = 'Lithology'
          ImageIndex = 7
          object cxGrid1: TcxGrid
            Left = 0
            Top = 0
            Width = 896
            Height = 392
            Align = alClient
            TabOrder = 0
            LookAndFeel.Kind = lfUltraFlat
            LookAndFeel.NativeStyle = False
            LookAndFeel.SkinName = 'Lilian'
            object cxGrid1TableView1: TcxGridTableView
              Navigator.Buttons.CustomButtons = <>
              Navigator.Buttons.Prior.Visible = True
              Navigator.Buttons.Insert.Visible = True
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Post.Visible = True
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              OnEditKeyDown = cxGrid1TableView1EditKeyDown
              OnEditKeyUp = cxGrid1TableView1EditKeyUp
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              NewItemRow.Visible = True
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsBehavior.FocusCellOnCycle = True
              OptionsCustomize.ColumnFiltering = False
              OptionsCustomize.ColumnGrouping = False
              OptionsCustomize.ColumnMoving = False
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsSelection.InvertSelect = False
              OptionsSelection.MultiSelect = True
              OptionsSelection.CellMultiSelect = True
              OptionsView.CellEndEllipsis = True
              OptionsView.ColumnAutoWidth = True
              OptionsView.GroupByBox = False
              OptionsView.Indicator = True
              Styles.Background = cxStyle7
              Styles.Content = cxStyle17
              Styles.ContentEven = cxStyle17
              Styles.ContentOdd = cxStyle17
              Styles.Inactive = cxStyle22
              Styles.IncSearch = cxStyle20
              Styles.Selection = cxStyle14
              Styles.Footer = cxStyle18
              Styles.Group = cxStyle19
              Styles.GroupByBox = cxStyle20
              Styles.Header = cxStyle3
              Styles.Indicator = cxStyle24
              Styles.Preview = cxStyle25
              Styles.StyleSheet = GridTableViewStyleSheetDevExpress
              object liTop: TcxGridColumn
                Caption = 'Top (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = liTopPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.ShowEditButtons = isebAlways
                Options.Grouping = False
                Options.Moving = False
                SortIndex = 0
                SortOrder = soAscending
              end
              object liBottom: TcxGridColumn
                Caption = 'Bottom (cm)'
                DataBinding.ValueType = 'Float'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.Alignment.Horz = taRightJustify
                Properties.BeepOnError = True
                Properties.UseLeftAlignmentOnEditing = False
                Properties.ValidateOnEnter = True
                Properties.OnValidate = liBottomPropertiesValidate
                HeaderAlignmentHorz = taCenter
                MinWidth = 64
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
              end
              object liDescription: TcxGridColumn
                Caption = 'Description'
                PropertiesClassName = 'TcxTextEditProperties'
                HeaderAlignmentHorz = taCenter
                MinWidth = 120
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Width = 282
              end
              object liLowerBound: TcxGridColumn
                Caption = 'Lower Boundary'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.UseLeftAlignmentOnEditing = False
                HeaderAlignmentHorz = taCenter
                MinWidth = 80
                Options.Filtering = False
                Options.Grouping = False
                Options.Moving = False
                Options.Sorting = False
                Width = 188
              end
            end
            object cxGrid1Level1: TcxGridLevel
              GridView = cxGrid1TableView1
            end
          end
        end
        object TabSheetLOI: TTabSheet
          Caption = 'LOI'
          ImageIndex = 8
          OnShow = TabSheetLOIShow
          object PageControl3: TPageControl
            Left = 0
            Top = 0
            Width = 896
            Height = 392
            ActivePage = TabSheetLOIData
            Align = alClient
            TabHeight = 18
            TabOrder = 0
            TabPosition = tpBottom
            object TabSheetLOIData: TTabSheet
              Caption = 'Data'
              object ScrollBox4: TScrollBox
                Left = 0
                Top = 0
                Width = 888
                Height = 366
                VertScrollBar.Visible = False
                Align = alClient
                BorderStyle = bsNone
                Color = 10841658
                Ctl3D = False
                ParentColor = False
                ParentCtl3D = False
                TabOrder = 0
                object Panel26: TPanel
                  Left = 0
                  Top = 0
                  Width = 888
                  Height = 75
                  Align = alTop
                  BevelOuter = bvNone
                  Color = 10841658
                  ParentBackground = False
                  TabOrder = 0
                  DesignSize = (
                    888
                    75)
                  object FlowPanel1: TFlowPanel
                    Left = 0
                    Top = 8
                    Width = 723
                    Height = 54
                    Anchors = [akLeft, akTop, akRight]
                    AutoWrap = False
                    BevelOuter = bvNone
                    Color = 10841658
                    ParentBackground = False
                    TabOrder = 0
                    object Panel3: TPanel
                      Left = 0
                      Top = 0
                      Width = 174
                      Height = 54
                      BevelOuter = bvNone
                      TabOrder = 0
                      DesignSize = (
                        174
                        54)
                      object Label14: TLabel
                        Left = 2
                        Top = 15
                        Width = 68
                        Height = 13
                        Caption = 'Investigators:'
                        Color = 10841658
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWhite
                        Font.Height = -11
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentColor = False
                        ParentFont = False
                      end
                      object Button14: TButton
                        Left = 102
                        Top = 11
                        Width = 71
                        Height = 17
                        Anchors = [akTop, akRight]
                        Caption = 'New Contact'
                        TabOrder = 1
                        TabStop = False
                        Visible = False
                        OnClick = Button14Click
                      end
                      object cxCheckComboBox3: TcxCheckComboBox
                        Left = 2
                        Top = 31
                        Anchors = [akLeft, akRight, akBottom]
                        BeepOnEnter = False
                        Properties.EditValueFormat = cvfStatesString
                        Properties.Items = <>
                        Properties.OnCloseUp = cxCheckComboBox3PropertiesCloseUp
                        Properties.OnInitPopup = cxCheckComboBox3PropertiesInitPopup
                        Properties.OnPopup = cxCheckComboBox3PropertiesPopup
                        Style.BorderStyle = ebs3D
                        Style.LookAndFeel.NativeStyle = False
                        StyleDisabled.LookAndFeel.NativeStyle = False
                        StyleFocused.LookAndFeel.NativeStyle = False
                        StyleHot.LookAndFeel.NativeStyle = False
                        TabOrder = 0
                        Width = 170
                      end
                    end
                    object Panel5: TPanel
                      Left = 174
                      Top = 0
                      Width = 174
                      Height = 54
                      BevelOuter = bvNone
                      Color = 10841658
                      ParentBackground = False
                      TabOrder = 3
                      DesignSize = (
                        174
                        54)
                      object Button15: TButton
                        Left = 88
                        Top = 11
                        Width = 85
                        Height = 17
                        Anchors = [akTop, akRight]
                        Caption = 'New Publication'
                        TabOrder = 0
                        TabStop = False
                        Visible = False
                        OnClick = Button15Click
                      end
                      object cxLabel5: TcxLabel
                        Left = 2
                        Top = 15
                        Caption = 'Publications:'
                        ParentFont = False
                        Style.Font.Charset = DEFAULT_CHARSET
                        Style.Font.Color = clWhite
                        Style.Font.Height = -11
                        Style.Font.Name = 'Tahoma'
                        Style.Font.Style = []
                        Style.IsFontAssigned = True
                      end
                      object cxCheckComboBox7: TcxCheckComboBox
                        Left = 2
                        Top = 31
                        Anchors = [akLeft, akRight, akBottom]
                        BeepOnEnter = False
                        Properties.Items = <>
                        Properties.OnCloseUp = cxCheckComboBox7PropertiesCloseUp
                        Properties.OnInitPopup = cxCheckComboBox7PropertiesInitPopup
                        Properties.OnPopup = cxCheckComboBox7PropertiesPopup
                        Style.BorderStyle = ebs3D
                        Style.LookAndFeel.NativeStyle = False
                        StyleDisabled.LookAndFeel.NativeStyle = False
                        StyleFocused.LookAndFeel.NativeStyle = False
                        StyleHot.LookAndFeel.NativeStyle = False
                        TabOrder = 1
                        Width = 170
                      end
                    end
                    object Panel20: TPanel
                      Left = 348
                      Top = 0
                      Width = 91
                      Height = 54
                      BevelOuter = bvNone
                      Color = 10841658
                      ParentBackground = False
                      TabOrder = 1
                      DesignSize = (
                        91
                        54)
                      object Label16: TLabel
                        Left = 2
                        Top = 2
                        Width = 87
                        Height = 26
                        Anchors = [akLeft, akTop, akRight]
                        AutoSize = False
                        Caption = 'Organic LOI Temperature ('#176'C)'
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWhite
                        Font.Height = -11
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                        WordWrap = True
                        ExplicitWidth = 85
                      end
                      object ComboBox7: TComboBox
                        Left = 2
                        Top = 31
                        Width = 87
                        Height = 21
                        AutoComplete = False
                        ItemIndex = 0
                        TabOrder = 0
                        Text = 'Unknown'
                        OnChange = ComboBox7Change
                        OnClick = ComboBox7Click
                        OnExit = ComboBox7Exit
                        Items.Strings = (
                          'Unknown'
                          'Variable'
                          '450'
                          '500'
                          '550'
                          '600')
                      end
                    end
                    object Panel21: TPanel
                      Left = 439
                      Top = 0
                      Width = 91
                      Height = 54
                      BevelOuter = bvNone
                      Color = 10841658
                      ParentBackground = False
                      TabOrder = 2
                      DesignSize = (
                        91
                        54)
                      object Label27: TLabel
                        Left = 2
                        Top = 2
                        Width = 85
                        Height = 26
                        Anchors = [akLeft, akTop, akRight]
                        Caption = 'Carbonate LOI Temperature ('#176'C)'
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWhite
                        Font.Height = -11
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                        WordWrap = True
                      end
                      object ComboBox8: TComboBox
                        Left = 2
                        Top = 31
                        Width = 87
                        Height = 21
                        AutoComplete = False
                        ItemIndex = 0
                        TabOrder = 0
                        Text = 'Unknown'
                        OnChange = ComboBox8Change
                        OnClick = ComboBox8Click
                        OnExit = ComboBox8Exit
                        Items.Strings = (
                          'Unknown'
                          'Variable'
                          '800'
                          '850'
                          '900'
                          '950'
                          '1000')
                      end
                    end
                    object Panel25: TPanel
                      Left = 530
                      Top = 0
                      Width = 150
                      Height = 54
                      BevelOuter = bvNone
                      TabOrder = 4
                      object cxButton31: TcxButton
                        Left = 0
                        Top = 29
                        Width = 150
                        Height = 25
                        Caption = 'Export to Spreadsheet'
                        LookAndFeel.Kind = lfOffice11
                        LookAndFeel.NativeStyle = False
                        OptionsImage.ImageIndex = 51
                        OptionsImage.Images = cxImageList1
                        TabOrder = 0
                        OnClick = cxButton31Click
                      end
                    end
                  end
                end
                object AdvColumnGrid5: TAdvColumnGrid
                  Left = 0
                  Top = 75
                  Width = 888
                  Height = 269
                  Cursor = crDefault
                  Align = alClient
                  ColCount = 10
                  Ctl3D = True
                  DefaultRowHeight = 20
                  DrawingStyle = gdsClassic
                  RowCount = 1000
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goTabs]
                  ParentCtl3D = False
                  ParentFont = False
                  ScrollBars = ssBoth
                  TabOrder = 1
                  OnKeyDown = AdvColumnGrid5KeyDown
                  HoverRowCells = [hcNormal, hcSelected]
                  OnAutoAddRow = AdvColumnGrid5AutoAddRow
                  OnClipboardBeforePasteCell = AdvColumnGrid5ClipboardBeforePasteCell
                  OnCellValidate = AdvColumnGrid5CellValidate
                  ActiveCellShow = True
                  ActiveCellFont.Charset = DEFAULT_CHARSET
                  ActiveCellFont.Color = clWindowText
                  ActiveCellFont.Height = -11
                  ActiveCellFont.Name = 'Tahoma'
                  ActiveCellFont.Style = [fsBold]
                  ActiveCellColor = 15387318
                  ColumnHeaders.Strings = (
                    ''
                    'Depth (cm)'
                    'Thickness (cm)'
                    'Temp Org ('#176'C)'
                    'LOI Org (%)'
                    'Temp Carb ('#176'C)'
                    'LOI Carb (%)'
                    'Bulk Dens (g/ml)'
                    'Date Analyzed'
                    'Analyst')
                  ControlLook.FixedGradientFrom = clWhite
                  ControlLook.FixedGradientTo = clBtnFace
                  ControlLook.FixedGradientHoverFrom = 13619409
                  ControlLook.FixedGradientHoverTo = 12502728
                  ControlLook.FixedGradientHoverMirrorFrom = 12502728
                  ControlLook.FixedGradientHoverMirrorTo = 11254975
                  ControlLook.FixedGradientHoverBorder = 12033927
                  ControlLook.FixedGradientDownFrom = 8816520
                  ControlLook.FixedGradientDownTo = 7568510
                  ControlLook.FixedGradientDownMirrorFrom = 7568510
                  ControlLook.FixedGradientDownMirrorTo = 6452086
                  ControlLook.FixedGradientDownBorder = 14991773
                  ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
                  ControlLook.DropDownHeader.Font.Color = clWindowText
                  ControlLook.DropDownHeader.Font.Height = -11
                  ControlLook.DropDownHeader.Font.Name = 'Tahoma'
                  ControlLook.DropDownHeader.Font.Style = []
                  ControlLook.DropDownHeader.Visible = True
                  ControlLook.DropDownHeader.Buttons = <>
                  ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
                  ControlLook.DropDownFooter.Font.Color = clWindowText
                  ControlLook.DropDownFooter.Font.Height = -11
                  ControlLook.DropDownFooter.Font.Name = 'Tahoma'
                  ControlLook.DropDownFooter.Font.Style = []
                  ControlLook.DropDownFooter.Visible = True
                  ControlLook.DropDownFooter.Buttons = <>
                  EnhTextSize = True
                  ExcelStyleDecimalSeparator = True
                  Filter = <>
                  FilterDropDown.Font.Charset = DEFAULT_CHARSET
                  FilterDropDown.Font.Color = clWindowText
                  FilterDropDown.Font.Height = -11
                  FilterDropDown.Font.Name = 'Tahoma'
                  FilterDropDown.Font.Style = []
                  FilterDropDown.TextChecked = 'Checked'
                  FilterDropDown.TextUnChecked = 'Unchecked'
                  FilterDropDownClear = '(All)'
                  FilterEdit.TypeNames.Strings = (
                    'Starts with'
                    'Ends with'
                    'Contains'
                    'Not contains'
                    'Equal'
                    'Not equal'
                    'Clear')
                  FixedColWidth = 36
                  FixedRowHeight = 20
                  FixedRowAlways = True
                  FixedColAlways = True
                  FixedFont.Charset = DEFAULT_CHARSET
                  FixedFont.Color = clWindowText
                  FixedFont.Height = -11
                  FixedFont.Name = 'Tahoma'
                  FixedFont.Style = []
                  FloatFormat = '%.2f'
                  HoverButtons.Buttons = <>
                  HoverButtons.Position = hbLeftFromColumnLeft
                  HTMLSettings.ImageFolder = 'images'
                  HTMLSettings.ImageBaseName = 'img'
                  MouseActions.AllSelect = True
                  MouseActions.ColSelect = True
                  MouseActions.RangeSelectAndEdit = True
                  MouseActions.RowSelect = True
                  Navigation.AdvanceOnEnter = True
                  Navigation.AdvanceInsert = True
                  Navigation.AutoComboDropSize = True
                  Navigation.AllowClipboardShortCuts = True
                  Navigation.AllowCtrlEnter = False
                  Navigation.AllowSmartClipboard = True
                  Navigation.AllowClipboardAlways = True
                  Navigation.AllowClipboardColGrow = False
                  Navigation.AppendOnArrowDown = True
                  Navigation.MoveRowOnSort = True
                  Navigation.TabToNextAtEnd = True
                  PrintSettings.DateFormat = 'dd/mm/yyyy'
                  PrintSettings.Font.Charset = DEFAULT_CHARSET
                  PrintSettings.Font.Color = clWindowText
                  PrintSettings.Font.Height = -11
                  PrintSettings.Font.Name = 'Tahoma'
                  PrintSettings.Font.Style = []
                  PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
                  PrintSettings.FixedFont.Color = clWindowText
                  PrintSettings.FixedFont.Height = -11
                  PrintSettings.FixedFont.Name = 'Tahoma'
                  PrintSettings.FixedFont.Style = []
                  PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
                  PrintSettings.HeaderFont.Color = clWindowText
                  PrintSettings.HeaderFont.Height = -11
                  PrintSettings.HeaderFont.Name = 'Tahoma'
                  PrintSettings.HeaderFont.Style = []
                  PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
                  PrintSettings.FooterFont.Color = clWindowText
                  PrintSettings.FooterFont.Height = -11
                  PrintSettings.FooterFont.Name = 'Tahoma'
                  PrintSettings.FooterFont.Style = []
                  PrintSettings.PageNumSep = '/'
                  SearchFooter.ColorTo = 15790320
                  SearchFooter.FindNextCaption = 'Find &next'
                  SearchFooter.FindPrevCaption = 'Find &previous'
                  SearchFooter.Font.Charset = DEFAULT_CHARSET
                  SearchFooter.Font.Color = clWindowText
                  SearchFooter.Font.Height = -11
                  SearchFooter.Font.Name = 'Tahoma'
                  SearchFooter.Font.Style = []
                  SearchFooter.HighLightCaption = 'Highlight'
                  SearchFooter.HintClose = 'Close'
                  SearchFooter.HintFindNext = 'Find next occurrence'
                  SearchFooter.HintFindPrev = 'Find previous occurrence'
                  SearchFooter.HintHighlight = 'Highlight occurrences'
                  SearchFooter.MatchCaseCaption = 'Match case'
                  SearchFooter.ResultFormat = '(%d of %d)'
                  SortSettings.DefaultFormat = ssAutomatic
                  SortSettings.Column = 1
                  SortSettings.Show = True
                  SortSettings.BlankPos = blLast
                  Version = '3.1.6.0'
                  Columns = <
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taCenter
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edNone
                      FilterCaseSensitive = False
                      Fixed = True
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = True
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 36
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edFloat
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Depth (cm)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 92
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edFloat
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Thickness (cm)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 79
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edNormal
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Temp Org ('#176'C)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = True
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 71
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edFloat
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'LOI Org (%)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 86
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edNormal
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Temp Carb ('#176'C)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = True
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 74
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edFloat
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'LOI Carb (%)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 88
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpFixedCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edFloat
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Bulk Dens (g/ml)'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 88
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taRightJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpAllCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edDateEdit
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Date Analyzed'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 83
                    end
                    item
                      AutoMinSize = 0
                      AutoMaxSize = 0
                      Alignment = taLeftJustify
                      Borders = []
                      BorderPen.Color = clSilver
                      ButtonHeight = 18
                      CheckFalse = 'N'
                      CheckTrue = 'Y'
                      Color = clWindow
                      ColumnPopupType = cpAllCellsRClick
                      DropDownCount = 8
                      EditLength = 0
                      Editor = edComboList
                      FilterCaseSensitive = False
                      Fixed = False
                      Font.Charset = DEFAULT_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -11
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      Header = 'Analyst'
                      HeaderAlignment = taCenter
                      HeaderFont.Charset = DEFAULT_CHARSET
                      HeaderFont.Color = clWindowText
                      HeaderFont.Height = -11
                      HeaderFont.Name = 'Tahoma'
                      HeaderFont.Style = []
                      MinSize = 0
                      MaxSize = 0
                      Password = False
                      PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                      PrintColor = clWhite
                      PrintFont.Charset = DEFAULT_CHARSET
                      PrintFont.Color = clWindowText
                      PrintFont.Height = -11
                      PrintFont.Name = 'Tahoma'
                      PrintFont.Style = []
                      ReadOnly = False
                      ShowBands = False
                      SortStyle = ssAutomatic
                      SpinMax = 0
                      SpinMin = 0
                      SpinStep = 1
                      Tag = 0
                      Width = 72
                    end>
                  ColWidths = (
                    36
                    92
                    79
                    71
                    86
                    74
                    88
                    88
                    83
                    72)
                end
                object ToolBar1: TToolBar
                  Left = 0
                  Top = 344
                  Width = 888
                  Height = 22
                  Align = alBottom
                  AutoSize = True
                  Caption = 'ToolBar1'
                  Color = clBtnFace
                  Images = cxImageList1
                  ParentColor = False
                  TabOrder = 2
                  Transparent = False
                  object ToolButton1: TToolButton
                    Left = 0
                    Top = 0
                    Hint = 'Top'
                    Caption = 'ToolButton1'
                    ImageIndex = 54
                    OnClick = ToolButton1Click
                  end
                  object ToolButton2: TToolButton
                    Left = 23
                    Top = 0
                    Hint = 'Previous'
                    Caption = 'ToolButton2'
                    ImageIndex = 57
                    OnClick = ToolButton2Click
                  end
                  object ToolButton3: TToolButton
                    Left = 46
                    Top = 0
                    Hint = 'Next'
                    Caption = 'ToolButton3'
                    ImageIndex = 56
                    OnClick = ToolButton3Click
                  end
                  object ToolButton4: TToolButton
                    Left = 69
                    Top = 0
                    Hint = 'Bottom'
                    Caption = 'ToolButton4'
                    ImageIndex = 55
                    OnClick = ToolButton4Click
                  end
                  object ToolButton6: TToolButton
                    Left = 92
                    Top = 0
                    Hint = 'Insert row'
                    Caption = 'ToolButton6'
                    ImageIndex = 58
                    OnClick = ToolButton6Click
                  end
                  object ToolButton9: TToolButton
                    Left = 115
                    Top = 0
                    Hint = 'Delete row'
                    Caption = 'ToolButton9'
                    ImageIndex = 59
                    OnClick = ToolButton9Click
                  end
                end
              end
            end
            object TabSheetLOIWorksheet: TTabSheet
              Caption = 'Worksheet'
              ImageIndex = 1
            end
          end
        end
        object TabSheetIsotopes: TTabSheet
          Caption = 'Isotopes'
          ImageIndex = 9
          object ToolBar4: TToolBar
            Left = 0
            Top = 0
            Width = 896
            Height = 29
            Caption = 'ToolBar4'
            Images = cxImageList1
            TabOrder = 3
            object cxButton32: TcxButton
              Left = 0
              Top = 0
              Width = 160
              Height = 22
              Caption = 'Import From Spreadsheet'
              DropDownMenu = PopupMenu2
              Kind = cxbkDropDown
              LookAndFeel.Kind = lfOffice11
              LookAndFeel.NativeStyle = False
              OptionsImage.Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000003000000033000000330000003300000033000000330000
                0033000000330000003300000033000000330000003300000030000000000000
                000000000000AD7B18F1B67E0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A
                08FFB47A08FFB47B08FFB47A08FFB47B09FFB67E0EFFAE7B18F2000000000000
                000000000033B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000000000
                0000B88317FFB37904FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7BFA4FFFFFF
                FFFFFFFFFFFFD7BFA4FFFFFFFFFFFFFFFFFFFFFFFFFFB47B09FF000000330000
                0033B57E0EFFFFFFFFFFAC6D00FFDAC4ACFFD8C0A4FFD8BFA2FFD9C1A3FFD8BF
                A1FFD8BFA1FFD9C1A3FFD7BE9FFFD5BC9CFFFFFFFFFFB47B08FFB47C0BFFB37A
                09FFAF7400FFFFFFFFFFFFFFFFFFAC6D00FFFFFFFFFFFFFFFFFFD7BC9EFFFFFF
                FCFFFFFFFCFFD7BC9DFFFFFFFBFFFFFFF7FFFFFFFFFFB47B08FFFFFAE5FFFFFA
                E4FFFFF7DEFFFFFAEBFFFFFAEBFFFFFFFFFFAD6E00FFFFFFFEFFD7BC9AFFFFFF
                F4FFFFFFF4FFD7BB98FFFFFFF3FFFFFDEFFFFFFFFFFFB47B08FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFF5E0FFFFF6E0FFFFFFFFFFAD6F00FFD9BD9DFFD9BC99FFD7B9
                95FFD7B995FFD8BB97FFD6B893FFD4B58FFFFFFFFFFFB47B08FFB47A08FFB37A
                06FFAF7300FFFFF8E1FFFFFFFFFFAA6B00FFFFFFF0FFFFFEECFFD7B991FFFFFC
                E8FFFFFCE8FFD7B890FFFFFBE6FFFFF8E2FFFFFFFFFFB47B08FF000000000000
                0000B57D0DFFFFFFFFFFAC6D00FFFFFCE7FFFFF9E2FFFFF9E1FFD7B58CFFFFF9
                E1FFFFF9E1FFD7B58CFFFFF8DFFFFFF5DAFFFFFFFFFFB47B08FF000000000000
                0000B88317FFB37803FFFFFFFFFFDEB482FFE0B581FFE0B683FFDEB787FFDFB6
                84FFDFB684FFDEB787FFDFB582FFDDB27DFFFFFFFFFFB57B09FF000000000000
                000000000000B57B08FFFFFFFFFF44C4FFFF49C5FFFF47C6FFFFE3B57EFF46C7
                FFFF46C7FFFFE3B57EFF46C6FFFF44C4FFFFFFFFFFFFB57C09FF000000000000
                000000000000B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000000000
                000000000000805B11B0B67E0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B
                08FFB67B08FFB57B08FFB67B08FFB67C09FFB67E0EFFAD7C17EF000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000}
              PopupMenu = PopupMenu2
              TabOrder = 2
            end
            object ToolButton16: TToolButton
              Left = 160
              Top = 0
              Width = 8
              Caption = 'ToolButton16'
              Style = tbsSeparator
            end
            object HTMLCheckBox1: THTMLCheckBox
              Left = 168
              Top = 0
              Width = 43
              Height = 22
              Color = clBtnFace
              Alignment = taLeftJustify
              ButtonVertAlign = tlCenter
              Caption = 
                '<FONT  size="8"  face="Tahoma"  >'#948'</FONT><FONT  size="6"  face="' +
                'Tahoma"  ><SUP>13</SUP></FONT><FONT  size="8"  face="Tahoma"  >C' +
                '</FONT><FONT face="Tahoma"></FONT>'
              DisabledShadow = False
              ParentColor = False
              ReturnIsTab = False
              TabOrder = 0
              OnClick = HTMLCheckBox1Click
              Version = '1.6.4.0'
            end
            object ToolButton17: TToolButton
              Left = 211
              Top = 0
              AllowAllUp = True
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton17Click
            end
            object ToolButton18: TToolButton
              Left = 234
              Top = 0
              Width = 8
              Caption = 'ToolButton18'
              ImageIndex = 0
              Style = tbsSeparator
            end
            object HTMLCheckBox2: THTMLCheckBox
              Left = 242
              Top = 0
              Width = 43
              Height = 22
              Alignment = taLeftJustify
              ButtonType = btWinXP
              ButtonVertAlign = tlCenter
              Caption = 
                '<FONT  size="8"  face="Tahoma"  >'#948'</FONT><FONT  size="6"  face="' +
                'Tahoma"  ><SUP>15</SUP></FONT><FONT face="Tahoma"  size="8"    >' +
                'N</FONT>'
              CheckColor = 10066176
              ReturnIsTab = False
              TabOrder = 1
              OnClick = HTMLCheckBox2Click
              Version = '1.6.4.0'
            end
            object ToolButton19: TToolButton
              Left = 285
              Top = 0
              AllowAllUp = True
              Caption = 'ToolButton19'
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton19Click
            end
            object ToolButton20: TToolButton
              Left = 308
              Top = 0
              Width = 8
              Caption = 'ToolButton20'
              ImageIndex = 1
              Style = tbsSeparator
            end
            object HTMLCheckBox3: THTMLCheckBox
              Left = 316
              Top = 0
              Width = 43
              Height = 22
              Alignment = taLeftJustify
              ButtonType = btWinXP
              ButtonVertAlign = tlCenter
              Caption = 
                '<FONT  size="8"  face="Tahoma"  >'#948'</FONT><FONT  size="6"  face="' +
                'Tahoma"  ><SUP>18</SUP></FONT><FONT face="Tahoma"  size="8"    >' +
                'O</FONT>'
              CheckColor = 2697727
              ReturnIsTab = False
              TabOrder = 3
              OnClick = HTMLCheckBox3Click
              Version = '1.6.4.0'
            end
            object ToolButton21: TToolButton
              Left = 359
              Top = 0
              AllowAllUp = True
              Caption = 'ToolButton21'
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton21Click
            end
            object ToolButton24: TToolButton
              Left = 382
              Top = 0
              Width = 8
              Caption = 'ToolButton24'
              ImageIndex = 69
              Style = tbsSeparator
            end
            object HTMLCheckBox5: THTMLCheckBox
              Left = 390
              Top = 0
              Width = 32
              Height = 22
              Alignment = taLeftJustify
              ButtonType = btWinXP
              ButtonVertAlign = tlCenter
              Caption = '<FONT face="Tahoma"  size="8">'#948'D<SUP> </SUP></FONT>'
              CheckColor = 6740479
              ReturnIsTab = False
              TabOrder = 5
              OnClick = HTMLCheckBox5Click
              Version = '1.6.4.0'
            end
            object ToolButton25: TToolButton
              Left = 422
              Top = 0
              AllowAllUp = True
              Caption = 'ToolButton25'
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton25Click
            end
            object ToolButton22: TToolButton
              Left = 445
              Top = 0
              Width = 8
              Caption = 'ToolButton22'
              ImageIndex = 69
              Style = tbsSeparator
            end
            object HTMLCheckBox4: THTMLCheckBox
              Left = 453
              Top = 0
              Width = 43
              Height = 22
              Alignment = taLeftJustify
              ButtonType = btWinXP
              ButtonVertAlign = tlCenter
              Caption = 
                '<FONT  size="8"  face="Tahoma"  >'#948'</FONT><FONT  size="6"  face="' +
                'Tahoma"  ><SUP>34</SUP></FONT><FONT face="Tahoma"   size="8"    ' +
                '>S</FONT>'
              CheckColor = 6740479
              ReturnIsTab = False
              TabOrder = 4
              OnClick = HTMLCheckBox4Click
              Version = '1.6.4.0'
            end
            object ToolButton23: TToolButton
              Left = 496
              Top = 0
              AllowAllUp = True
              Caption = 'ToolButton23'
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton23Click
            end
            object ToolButton26: TToolButton
              Left = 519
              Top = 0
              Width = 8
              Caption = 'ToolButton26'
              ImageIndex = 69
              Style = tbsSeparator
            end
            object HTMLCheckBox6: THTMLCheckBox
              Left = 527
              Top = 0
              Width = 60
              Height = 22
              Alignment = taLeftJustify
              ButtonType = btWinXP
              ButtonVertAlign = tlCenter
              Caption = 
                '<FONT size="6" face="Tahoma"><SUP>87</SUP></FONT><FONT face="Tah' +
                'oma" size="8" >Sr/</FONT><FONT size="6" face="Tahoma"><SUP>86</S' +
                'UP></FONT><FONT face="Tahoma" size="8" >Sr</FONT>'
              CheckColor = 6740479
              ReturnIsTab = False
              TabOrder = 6
              OnClick = HTMLCheckBox6Click
              Version = '1.6.4.0'
            end
            object ToolButton27: TToolButton
              Left = 587
              Top = 0
              AllowAllUp = True
              Caption = 'ToolButton27'
              Enabled = False
              ImageIndex = 68
              OnClick = ToolButton27Click
            end
          end
          object AdvControlDropDownPretreatment: TAdvControlDropDown
            Left = 560
            Top = 240
            Width = 200
            Height = 21
            BevelInner = bvNone
            BevelOuter = bvNone
            BorderStyle = bsNone
            EmptyTextFocused = False
            EmptyTextStyle = []
            Visible = False
            DropDownColor = 15984090
            DropDownColorTo = 15785680
            DropDownBorderColor = clNone
            EditorEnabled = False
            Images = cxImageList2
            LabelMargin = 0
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
            Version = '1.4.5.7'
            ButtonAppearance.BorderColorHot = 10079963
            ButtonAppearance.BorderColorDown = 4370174
            ButtonAppearance.Color = 16773091
            ButtonAppearance.ColorTo = 16768452
            ButtonAppearance.ColorDisabledTo = 11974326
            ButtonAppearance.ColorDown = 11196927
            ButtonAppearance.ColorDownTo = 7257087
            ButtonAppearance.ColorHot = 15465983
            ButtonAppearance.ColorHotTo = 11332863
            ButtonAppearance.Font.Charset = DEFAULT_CHARSET
            ButtonAppearance.Font.Color = clWindowText
            ButtonAppearance.Font.Height = -11
            ButtonAppearance.Font.Name = 'Tahoma'
            ButtonAppearance.Font.Style = []
            DropDownHeader.Color = 16773091
            DropDownHeader.ColorTo = 16765615
            DropDownHeader.Font.Charset = DEFAULT_CHARSET
            DropDownHeader.Font.Color = 7485192
            DropDownHeader.Font.Height = -11
            DropDownHeader.Font.Name = 'Tahoma'
            DropDownHeader.Font.Style = []
            DropDownHeader.Visible = True
            DropDownHeader.BorderColor = 16765615
            DropDownHeader.Buttons = <>
            DropDownFooter.Color = 16773091
            DropDownFooter.ColorTo = 16765615
            DropDownFooter.Font.Charset = DEFAULT_CHARSET
            DropDownFooter.Font.Color = 7485192
            DropDownFooter.Font.Height = -11
            DropDownFooter.Font.Name = 'Tahoma'
            DropDownFooter.Font.Style = []
            DropDownFooter.Visible = True
            DropDownFooter.BorderColor = 16765615
            DropDownFooter.Buttons = <
              item
                Caption = 'Ok'
                ImageIndex = 2
                Width = 34
              end
              item
                Caption = 'Cancel'
                ImageIndex = 0
                ModalResult = 2
                Width = 52
              end
              item
                Caption = 'Clear'
                ImageIndex = 1
                Width = 44
              end>
            TabOrder = 1
            OnBeforeDropDown = AdvControlDropDownPretreatmentBeforeDropDown
            OnBeforeDropUp = AdvControlDropDownPretreatmentBeforeDropUp
            OnDropDownFooterButtonClick = AdvControlDropDownPretreatmentDropDownFooterButtonClick
            Control = AdvColumnGridPretreat
            SelectionColorStyle = 1
            TMSStyle = 4
          end
          object ToolBar2: TToolBar
            Left = 0
            Top = 370
            Width = 896
            Height = 22
            Align = alBottom
            Caption = 'ToolBar2'
            Images = cxImageList1
            TabOrder = 2
            object ToolButton10: TToolButton
              Left = 0
              Top = 0
              Caption = 'ToolButton10'
              ImageIndex = 63
              OnClick = ToolButton10Click
            end
            object ToolButton11: TToolButton
              Left = 23
              Top = 0
              Caption = 'ToolButton11'
              ImageIndex = 65
              OnClick = ToolButton11Click
            end
            object ToolButton12: TToolButton
              Left = 46
              Top = 0
              Caption = 'ToolButton12'
              ImageIndex = 66
              OnClick = ToolButton12Click
            end
            object ToolButton13: TToolButton
              Left = 69
              Top = 0
              Caption = 'ToolButton13'
              ImageIndex = 64
              OnClick = ToolButton13Click
            end
            object ToolButton14: TToolButton
              Left = 92
              Top = 0
              Caption = 'ToolButton14'
              ImageIndex = 58
              OnClick = ToolButton14Click
            end
            object ToolButton15: TToolButton
              Left = 115
              Top = 0
              Caption = 'ToolButton15'
              ImageIndex = 59
              OnClick = ToolButton15Click
            end
          end
          object AdvIsotopeStringGrid: TAdvStringGrid
            Left = 0
            Top = 29
            Width = 896
            Height = 341
            Cursor = crDefault
            Align = alClient
            ColCount = 91
            DefaultRowHeight = 20
            DrawingStyle = gdsClassic
            FixedCols = 6
            RowCount = 3
            FixedRows = 2
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goTabs, goFixedHotTrack]
            ParentFont = False
            ScrollBars = ssBoth
            TabOrder = 4
            OnFixedCellClick = AdvIsotopeStringGridFixedCellClick
            OnKeyUp = AdvIsotopeStringGridKeyUp
            OnMouseDown = AdvIsotopeStringGridMouseDown
            OnMouseUp = AdvIsotopeStringGridMouseUp
            OnTopLeftChanged = AdvIsotopeStringGridTopLeftChanged
            HoverRowCells = [hcNormal, hcSelected]
            OnGetDisplText = AdvIsotopeStringGridGetDisplText
            OnGetCellColor = AdvIsotopeStringGridGetCellColor
            OnGetCellGradient = AdvIsotopeStringGridGetCellGradient
            OnGetAlignment = AdvIsotopeStringGridGetAlignment
            OnCellChanging = AdvIsotopeStringGridCellChanging
            OnCanEditCell = AdvIsotopeStringGridCanEditCell
            OnClipboardAfterPasteCell = AdvIsotopeStringGridClipboardAfterPasteCell
            OnCellValidate = AdvIsotopeStringGridCellValidate
            OnGetEditorType = AdvIsotopeStringGridGetEditorType
            OnGetEditorProp = AdvIsotopeStringGridGetEditorProp
            OnComboChange = AdvIsotopeStringGridComboChange
            OnResize = AdvIsotopeStringGridResize
            OnSelectionChanged = AdvIsotopeStringGridSelectionChanged
            OnColumnSizing = AdvIsotopeStringGridColumnSizing
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            AutoNumAlign = True
            ControlLook.FixedGradientHoverFrom = clGray
            ControlLook.FixedGradientHoverTo = clWhite
            ControlLook.FixedGradientDownFrom = clGray
            ControlLook.FixedGradientDownTo = clSilver
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDown.TextChecked = 'Checked'
            FilterDropDown.TextUnChecked = 'Unchecked'
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Larger than'
              'Smaller than'
              'Clear')
            FixedColWidth = 36
            FixedRowHeight = 20
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = []
            FloatFormat = '%.2f'
            GridImages = cxImageList1
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            MouseActions.DirectEdit = True
            MouseActions.RangeSelectAndEdit = True
            MouseActions.SizeFixedCol = True
            Navigation.AutoComboDropSize = True
            Navigation.AllowClipboardShortCuts = True
            Navigation.AllowSmartClipboard = True
            Navigation.AllowClipboardAlways = True
            Navigation.KeepHorizScroll = True
            Navigation.SkipFixedCells = False
            Navigation.SkipDisabledRows = False
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssAutomatic
            Version = '8.3.5.4'
            ColWidths = (
              36
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64
              64)
            RowHeights = (
              20
              20
              20)
            object AdvPanel1: TAdvPanel
              Left = 44
              Top = 97
              Width = 120
              Height = 20
              Color = 2500134
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Carbon<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
            object AdvPanel2: TAdvPanel
              Left = 44
              Top = 115
              Width = 120
              Height = 20
              Color = 10066176
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 5
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Nitrogen<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
            object AdvPanel3: TAdvPanel
              Left = 44
              Top = 134
              Width = 120
              Height = 20
              Color = 2697727
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 6
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Oxygen<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
            object AdvPanel4: TAdvPanel
              Left = 44
              Top = 153
              Width = 120
              Height = 20
              Color = 13431551
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 7
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Hydrogen<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
            object AdvPanel5: TAdvPanel
              Left = 44
              Top = 173
              Width = 120
              Height = 20
              Color = 6740479
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 8
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Sulfur<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
            object AdvPanel6: TAdvPanel
              Left = 44
              Top = 193
              Width = 120
              Height = 20
              Color = clLime
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 9
              UseDockManager = True
              Visible = False
              Version = '2.5.7.4'
              Buffered = False
              Caption.Color = clHighlight
              Caption.ColorTo = clNone
              Caption.Font.Charset = DEFAULT_CHARSET
              Caption.Font.Color = clWindowText
              Caption.Font.Height = -11
              Caption.Font.Name = 'Tahoma'
              Caption.Font.Style = []
              Caption.Indent = 0
              DoubleBuffered = True
              StatusBar.Font.Charset = DEFAULT_CHARSET
              StatusBar.Font.Color = clWindowText
              StatusBar.Font.Height = -11
              StatusBar.Font.Name = 'Tahoma'
              StatusBar.Font.Style = []
              Text = '<P align="center">Strontium<FONT face="Tahoma"></FONT>'
              TextVAlign = tvaCenter
              FullHeight = 20
            end
          end
          object AdvColumnGridPretreat: TAdvColumnGrid
            Left = 378
            Top = 168
            Width = 382
            Height = 106
            Cursor = crDefault
            ColCount = 4
            DefaultRowHeight = 20
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 5
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goTabs]
            ParentFont = False
            ScrollBars = ssBoth
            TabOrder = 0
            HoverRowCells = [hcNormal, hcSelected]
            OnGetCellColor = AdvColumnGridPretreatGetCellColor
            OnCanEditCell = AdvColumnGridPretreatCanEditCell
            OnGetEditorType = AdvColumnGridPretreatGetEditorType
            OnGetEditorProp = AdvColumnGridPretreatGetEditorProp
            OnComboChange = AdvColumnGridPretreatComboChange
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ActiveCellColor = 15387318
            ColumnHeaders.Strings = (
              'Order'
              'Pretreatment'
              'Qualifier'
              'Value')
            ColumnSize.StretchColumn = 1
            ControlLook.FixedGradientFrom = clWhite
            ControlLook.FixedGradientTo = clBtnFace
            ControlLook.FixedGradientHoverFrom = 13619409
            ControlLook.FixedGradientHoverTo = 12502728
            ControlLook.FixedGradientHoverMirrorFrom = 12502728
            ControlLook.FixedGradientHoverMirrorTo = 11254975
            ControlLook.FixedGradientHoverBorder = 12033927
            ControlLook.FixedGradientDownFrom = 8816520
            ControlLook.FixedGradientDownTo = 7568510
            ControlLook.FixedGradientDownMirrorFrom = 7568510
            ControlLook.FixedGradientDownMirrorTo = 6452086
            ControlLook.FixedGradientDownBorder = 14991773
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            EnhTextSize = True
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDown.TextChecked = 'Checked'
            FilterDropDown.TextUnChecked = 'Unchecked'
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Larger than'
              'Smaller than'
              'Clear')
            FixedColWidth = 48
            FixedRowHeight = 20
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clBlack
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = []
            FloatFormat = '%.2f'
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            MouseActions.SizeFixedCol = True
            Navigation.AlwaysEdit = True
            Navigation.AdvanceOnEnter = True
            Navigation.AutoComboDropSize = True
            Navigation.AppendOnArrowDown = True
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.ColorTo = 15790320
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssNatural
            SortSettings.Column = 0
            SortSettings.Show = True
            SortSettings.IgnoreBlanks = True
            SortSettings.BlankPos = blLast
            SortSettings.IgnoreCase = True
            Version = '3.1.6.0'
            Columns = <
              item
                AutoMinSize = 0
                AutoMaxSize = 0
                Alignment = taRightJustify
                Borders = []
                BorderPen.Color = clSilver
                ButtonHeight = 18
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                ColumnPopupType = cpFixedCellsRClick
                DropDownCount = 8
                EditLength = 0
                Editor = edNone
                FilterCaseSensitive = False
                Fixed = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Order'
                HeaderAlignment = taCenter
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clNavy
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                MinSize = 0
                MaxSize = 0
                Password = False
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintColor = clWhite
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                ReadOnly = False
                ShowBands = False
                SortStyle = ssAutomatic
                SpinMax = 0
                SpinMin = 0
                SpinStep = 1
                Tag = 0
                Width = 48
              end
              item
                AutoMinSize = 0
                AutoMaxSize = 0
                Alignment = taLeftJustify
                Borders = []
                BorderPen.Color = clSilver
                ButtonHeight = 18
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                ColumnPopupType = cpFixedCellsRClick
                DropDownCount = 8
                EditLength = 0
                Editor = edComboList
                FilterCaseSensitive = False
                Fixed = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Pretreatment'
                HeaderAlignment = taCenter
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clNavy
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                MinSize = 0
                MaxSize = 0
                Password = False
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintColor = clWhite
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                ReadOnly = False
                ShowBands = False
                SortStyle = ssAutomatic
                SpinMax = 0
                SpinMin = 0
                SpinStep = 1
                Tag = 0
                Width = 140
              end
              item
                AutoMinSize = 0
                AutoMaxSize = 0
                Alignment = taLeftJustify
                Borders = []
                BorderPen.Color = clSilver
                ButtonHeight = 18
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clBtnFace
                ColumnPopupType = cpFixedCellsRClick
                DropDownCount = 8
                EditLength = 0
                Editor = edNormal
                FilterCaseSensitive = False
                Fixed = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clNavy
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Qualifier'
                HeaderAlignment = taCenter
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clNavy
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                MinSize = 0
                MaxSize = 0
                Password = False
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintColor = clWhite
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                ReadOnly = False
                ShowBands = False
                SortStyle = ssAutomatic
                SpinMax = 0
                SpinMin = 0
                SpinStep = 1
                Tag = 0
                Width = 140
              end
              item
                AutoMinSize = 0
                AutoMaxSize = 0
                Alignment = taRightJustify
                Borders = []
                BorderPen.Color = clSilver
                ButtonHeight = 18
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clBtnFace
                ColumnPopupType = cpFixedCellsRClick
                DropDownCount = 8
                EditLength = 0
                Editor = edNormal
                FilterCaseSensitive = False
                Fixed = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Value'
                HeaderAlignment = taCenter
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clNavy
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                MinSize = 0
                MaxSize = 0
                Password = False
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintColor = clWhite
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                ReadOnly = False
                ShowBands = False
                SortStyle = ssAutomatic
                SpinMax = 0
                SpinMin = 0
                SpinStep = 1
                Tag = 0
                Width = 48
              end>
            ColWidths = (
              48
              140
              140
              48)
          end
        end
        object TabSheetContacts: TTabSheet
          Caption = 'Contacts'
          ImageIndex = 2
          OnShow = TabSheetContactsShow
          object ContactsGrid: TcxGrid
            Left = 0
            Top = 0
            Width = 896
            Height = 392
            Align = alClient
            TabOrder = 0
            LookAndFeel.NativeStyle = False
            LookAndFeel.SkinName = 'Lilian'
            object ContactsGridCardView1: TcxGridCardView
              Navigator.Buttons.OnButtonClick = ContactsGridCardView1NavigatorButtonsButtonClick
              Navigator.Buttons.CustomButtons = <>
              Navigator.Buttons.Delete.Visible = True
              Navigator.Buttons.Edit.Visible = False
              Navigator.Buttons.Post.Visible = True
              Navigator.Buttons.Refresh.Visible = False
              Navigator.Buttons.SaveBookmark.Visible = False
              Navigator.Buttons.GotoBookmark.Visible = False
              Navigator.Buttons.Filter.Visible = False
              Navigator.InfoPanel.Visible = True
              Navigator.Visible = True
              DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoSaveExpanding, dcoFocusTopRowAfterSorting]
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              DataController.OnCompare = ContactsGridCardView1DataControllerCompare
              DataController.Data = {
                360100000F00000044617461436F6E74726F6C6C6572310C0000001200000054
                6378537472696E6756616C75655479706512000000546378537472696E675661
                6C75655479706512000000546378537472696E6756616C756554797065120000
                00546378537472696E6756616C75655479706512000000546378537472696E67
                56616C75655479706512000000546378537472696E6756616C75655479706512
                000000546378537472696E6756616C7565547970651200000054637853747269
                6E6756616C75655479706512000000546378537472696E6756616C7565547970
                6512000000546378537472696E6756616C756554797065120000005463785374
                72696E6756616C75655479706512000000546378537472696E6756616C756554
                79706501000000445855464D5400010101010101010101010101}
              LayoutDirection = ldVertical
              OptionsBehavior.AlwaysShowEditor = True
              OptionsBehavior.CopyCaptionsToClipboard = False
              OptionsBehavior.FocusCellOnTab = True
              OptionsBehavior.FocusFirstCellOnNewRecord = True
              OptionsBehavior.GoToNextCellOnEnter = True
              OptionsBehavior.NavigatorHints = True
              OptionsData.Appending = True
              OptionsData.DeletingConfirmation = False
              OptionsView.ShowEditButtons = gsebForFocusedRecord
              OptionsView.CardIndent = 7
              OptionsView.CardWidth = 191
              Styles.Background = cxStyle7
              Styles.Content = cxStyle17
              Styles.Selection = cxStyle9
              Styles.CardBorder = cxStyle12
              Styles.RowCaption = cxStyle3
              object co_family_name: TcxGridCardViewRow
                Caption = 'Family name'
                PropertiesClassName = 'TcxButtonEditProperties'
                Properties.Buttons = <
                  item
                    Default = True
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E9E9EBEBEBFFFFFFFFFFFFF7F7F7D5D5
                      D5E4E4E4FFFFFFFFFFFFC2C3C4BBBEC0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1
                      D1D1B1B1B1F7F6F6FFFFFFE2E2E2969696909090D1D1D1FFFFFFC8CACC727D83
                      DFE0E1FFFFFFFFFFFFFDFDFDDADADAC7C8C8696A6A8B8F93F2F3F4FAFAFAAAAA
                      AA6A6A6A7E7D7DD8D8D8FFFFFFCDD1D28A9497C8CBCCE6E5E5AAAAAA696C6D82
                      87897B858865717B9BA0A6F9F9F9EFEFEF858585525758838587FFFFFFFFFFFF
                      C8CBCD888F928A8F9485898C8184853F444667757A8B9396939493CACACAEEEE
                      EED7D8D8646D71596265FFFFFFFFFFFFE3E4E47582896274876E7E917F888E55
                      6064546268828789ACAEB0CFCECED8D8D8EFEEEECCCECF5E696DFFFFFFFFFFFF
                      D7DADA64737B5B718C4C648350616B5162685361667B82858E9299ECECECF3F3
                      F3F9F9F9F9F9F9778287FFFFFFFEFEFEA1AAAE53646B515B654858664D606846
                      5C68576C7DB4B7B7DCDCDCF8F8F9FFFFFFFFFFFFFFFFFFA7AFB2FFFFFFFFFEFE
                      8A969B475E66545D6133444C4459604B5F6D586F8A687379606973D0D3D7FFFF
                      FFFFFFFFFFFFFFA9B1B4FFFFFFFFFFFF949B9F3A50593B4D54182E37384C5453
                      5D62535F6B727F856F7A828D9499DDDDDEFEFEFEEFF0F08E9A9EFFFFFFFFFFFF
                      D5D5D557666B2F485118343F253D4648565C555F637A878C879195717B80989D
                      9FF8F8F8A4ACAFB9C0C3FFFFFFFFFFFFF2F1F06C797E324F5A203F4A233D473C
                      5059596B72748288818C92818C918B94989EA3A69CA5A8FBFCFCFFFFFFFFFFFF
                      DDDDDC5D6B70324D582B465129454F394F5843586060717875848A7684897F88
                      8BB3B8BAF7F8F8FFFFFFFFFFFFFFFFFFFBFBFBD8DBDCB8BFC27C898F364D5634
                      4B54395159425861627177848D91DADBDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFF4F4F48D979A43565E28414B31454E798083EBEBEBFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFCCA
                      CECF859297788084D3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
                    Kind = bkGlyph
                  end>
                Properties.OnButtonClick = co_family_namePropertiesButtonClick
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                SortIndex = 0
                SortOrder = soAscending
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_given_names: TcxGridCardViewRow
                Caption = 'Given names'
                PropertiesClassName = 'TcxTextEditProperties'
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_leading_initials: TcxGridCardViewRow
                Caption = 'Leading initials'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.OnValidate = co_leading_initialsPropertiesValidate
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                SortIndex = 1
                SortOrder = soAscending
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_suffix: TcxGridCardViewRow
                Caption = 'Suffix'
                PropertiesClassName = 'TcxTextEditProperties'
                Properties.OnValidate = co_suffixPropertiesValidate
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_title: TcxGridCardViewRow
                Caption = 'Title'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.DropDownListStyle = lsFixedList
                Properties.Items.Strings = (
                  'Dr.'
                  'Dra.'
                  'Prof.'
                  'Prof. Dr.'
                  'Mr.'
                  'Mrs.'
                  'Miss'
                  'Ms.')
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_status: TcxGridCardViewRow
                Caption = 'Status'
                PropertiesClassName = 'TcxComboBoxProperties'
                Properties.Items.Strings = (
                  'active'
                  'deceased'
                  'defunct'
                  'ended'
                  'extant'
                  'inactive'
                  'retired'
                  'unknown')
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_telephone: TcxGridCardViewRow
                Caption = 'Telephone'
                PropertiesClassName = 'TcxTextEditProperties'
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_fax: TcxGridCardViewRow
                Caption = 'Fax'
                PropertiesClassName = 'TcxTextEditProperties'
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_email: TcxGridCardViewRow
                Caption = 'Email'
                PropertiesClassName = 'TcxTextEditProperties'
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_url: TcxGridCardViewRow
                Caption = 'URL'
                PropertiesClassName = 'TcxTextEditProperties'
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_address: TcxGridCardViewRow
                Caption = 'Address'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
              object co_notes: TcxGridCardViewRow
                Caption = 'Notes'
                PropertiesClassName = 'TcxBlobEditProperties'
                Properties.BlobEditKind = bekMemo
                Properties.BlobPaintStyle = bpsText
                Options.Filtering = False
                Options.FilteringMRUItemsList = False
                Options.Moving = False
                Position.BeginsLayer = True
                Styles.Content = cxStyle17
                Styles.Caption = cxStyle3
              end
            end
            object ContactsGridLevel1: TcxGridLevel
              GridView = ContactsGridCardView1
            end
          end
        end
        object TabSheetPubs: TTabSheet
          Caption = 'Publications'
          ImageIndex = 3
          OnShow = TabSheetPubsShow
          object Panel1: TPanel
            Left = 0
            Top = 0
            Width = 896
            Height = 392
            Align = alClient
            Color = 10841658
            ParentBackground = False
            TabOrder = 0
            OnResize = Panel1Resize
            object FlowPanel4: TFlowPanel
              Left = 24
              Top = 20
              Width = 300
              Height = 25
              AutoSize = True
              AutoWrap = False
              BevelOuter = bvNone
              Ctl3D = True
              ParentCtl3D = False
              TabOrder = 0
              object cxButton13: TcxButton
                Left = 0
                Top = 0
                Width = 75
                Height = 25
                Caption = 'New'
                LookAndFeel.Kind = lfOffice11
                TabOrder = 0
                OnClick = cxButton13Click
              end
              object cxButton14: TcxButton
                Left = 75
                Top = 0
                Width = 75
                Height = 25
                Caption = 'Delete'
                LookAndFeel.Kind = lfOffice11
                TabOrder = 1
                OnClick = cxButton14Click
              end
              object cxButton15: TcxButton
                Left = 150
                Top = 0
                Width = 75
                Height = 25
                Caption = 'Show Links'
                LookAndFeel.Kind = lfOffice11
                TabOrder = 3
                OnClick = cxButton15Click
              end
              object cxButton16: TcxButton
                Left = 225
                Top = 0
                Width = 75
                Height = 25
                Caption = 'Edit'
                LookAndFeel.Kind = lfOffice11
                TabOrder = 2
                OnClick = cxButton16Click
              end
            end
            object AdvColumnGrid4: TAdvColumnGrid
              Left = 24
              Top = 76
              Width = 552
              Height = 232
              Cursor = crDefault
              ColCount = 2
              Ctl3D = True
              DrawingStyle = gdsClassic
              RowCount = 2
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
              ParentCtl3D = False
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 1
              ActiveRowShow = True
              HoverRowCells = [hcNormal, hcSelected]
              OnRowChanging = AdvColumnGrid4RowChanging
              OnDblClickCell = AdvColumnGrid4DblClickCell
              OnHoverButtonClick = AdvColumnGrid4HoverButtonClick
              ActiveCellFont.Charset = DEFAULT_CHARSET
              ActiveCellFont.Color = clWindowText
              ActiveCellFont.Height = -11
              ActiveCellFont.Name = 'Tahoma'
              ActiveCellFont.Style = [fsBold]
              ColumnHeaders.Strings = (
                ''
                'Publication')
              ColumnSize.Stretch = True
              ColumnSize.StretchColumn = 1
              ControlLook.FixedGradientHoverFrom = clGray
              ControlLook.FixedGradientHoverTo = clWhite
              ControlLook.FixedGradientDownFrom = clGray
              ControlLook.FixedGradientDownTo = clSilver
              ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownHeader.Font.Color = clWindowText
              ControlLook.DropDownHeader.Font.Height = -11
              ControlLook.DropDownHeader.Font.Name = 'Tahoma'
              ControlLook.DropDownHeader.Font.Style = []
              ControlLook.DropDownHeader.Visible = True
              ControlLook.DropDownHeader.Buttons = <>
              ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
              ControlLook.DropDownFooter.Font.Color = clWindowText
              ControlLook.DropDownFooter.Font.Height = -11
              ControlLook.DropDownFooter.Font.Name = 'Tahoma'
              ControlLook.DropDownFooter.Font.Style = []
              ControlLook.DropDownFooter.Visible = True
              ControlLook.DropDownFooter.Buttons = <>
              Filter = <>
              FilterDropDown.Font.Charset = DEFAULT_CHARSET
              FilterDropDown.Font.Color = clWindowText
              FilterDropDown.Font.Height = -11
              FilterDropDown.Font.Name = 'Tahoma'
              FilterDropDown.Font.Style = []
              FilterDropDownClear = '(All)'
              FilterEdit.TypeNames.Strings = (
                'Starts with'
                'Ends with'
                'Contains'
                'Not contains'
                'Equal'
                'Not equal'
                'Clear')
              FixedColWidth = 16
              FixedRowHeight = 22
              FixedFont.Charset = DEFAULT_CHARSET
              FixedFont.Color = clWindowText
              FixedFont.Height = -11
              FixedFont.Name = 'Tahoma'
              FixedFont.Style = [fsBold]
              FloatFormat = '%.2f'
              GridImages = cxImageList1
              HoverButtons.Enabled = True
              HoverButtons.Buttons = <
                item
                  ImageIndex = 71
                end>
              HoverButtons.Column = 1
              HoverButtons.MoveActiveRow = False
              HoverButtons.Position = hbLeftFromColumnRight
              HTMLSettings.ImageFolder = 'images'
              HTMLSettings.ImageBaseName = 'img'
              MouseActions.RowSelect = True
              PrintSettings.DateFormat = 'dd/mm/yyyy'
              PrintSettings.Font.Charset = DEFAULT_CHARSET
              PrintSettings.Font.Color = clWindowText
              PrintSettings.Font.Height = -11
              PrintSettings.Font.Name = 'Tahoma'
              PrintSettings.Font.Style = []
              PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
              PrintSettings.FixedFont.Color = clWindowText
              PrintSettings.FixedFont.Height = -11
              PrintSettings.FixedFont.Name = 'Tahoma'
              PrintSettings.FixedFont.Style = []
              PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
              PrintSettings.HeaderFont.Color = clWindowText
              PrintSettings.HeaderFont.Height = -11
              PrintSettings.HeaderFont.Name = 'Tahoma'
              PrintSettings.HeaderFont.Style = []
              PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
              PrintSettings.FooterFont.Color = clWindowText
              PrintSettings.FooterFont.Height = -11
              PrintSettings.FooterFont.Name = 'Tahoma'
              PrintSettings.FooterFont.Style = []
              PrintSettings.PageNumSep = '/'
              RowIndicator.Data = {
                26050000424D260500000000000036040000280000000E0000000F0000000100
                080000000000F0000000C30E0000C30E000000010000000000001D1E1F003132
                330080000000CC000000FF000000C56A3100FF666600FF999900EFD3C200FFCC
                CC00FFECCC00F7E7DC00FFFFFF00000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000000C0C0C0C0C0C
                0C0C0C0C0C0C0C0C00000C0C0C0C0C0C0C0C0C0C0C0C0C0C00000C0C0C0C020C
                0C0C0C0C0C0C0C0C00000C0C0C0C03020C0C0C0C0C0C0C0C00000C0C0C0C0307
                020C0C0C0C0C0C0C00000C0C0C0C030707020C0C0C0C0C0C00000C0C0C0C0407
                0707020C0C0C0C0C00000C0C0C0C0409070707020C0C0C0C00000C0C0C0C0409
                0A07030C0C0C0C0C00000C0C0C0C040A0A030C0C0C0C0C0C00000C0C0C0C060A
                030C0C0C0C0C0C0C00000C0C0C0C06030C0C0C0C0C0C0C0C00000C0C0C0C040C
                0C0C0C0C0C0C0C0C00000C0C0C0C0C0C0C0C0C0C0C0C0C0C00000C0C0C0C0C0C
                0C0C0C0C0C0C0C0C0000}
              ScrollProportional = True
              SearchFooter.FindNextCaption = 'Find &next'
              SearchFooter.FindPrevCaption = 'Find &previous'
              SearchFooter.Font.Charset = DEFAULT_CHARSET
              SearchFooter.Font.Color = clWindowText
              SearchFooter.Font.Height = -11
              SearchFooter.Font.Name = 'Tahoma'
              SearchFooter.Font.Style = []
              SearchFooter.HighLightCaption = 'Highlight'
              SearchFooter.HintClose = 'Close'
              SearchFooter.HintFindNext = 'Find next occurrence'
              SearchFooter.HintFindPrev = 'Find previous occurrence'
              SearchFooter.HintHighlight = 'Highlight occurrences'
              SearchFooter.MatchCaseCaption = 'Match case'
              SearchFooter.ResultFormat = '(%d of %d)'
              SortSettings.DefaultFormat = ssAutomatic
              SortSettings.Column = 2
              SortSettings.IgnoreCase = True
              Version = '3.1.6.0'
              WordWrap = False
              Columns = <
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clWindowText
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 16
                end
                item
                  AutoMinSize = 0
                  AutoMaxSize = 0
                  Alignment = taLeftJustify
                  Borders = []
                  BorderPen.Color = clSilver
                  ButtonHeight = 18
                  CheckFalse = 'N'
                  CheckTrue = 'Y'
                  Color = clWindow
                  ColumnPopupType = cpFixedCellsRClick
                  DropDownCount = 8
                  EditLength = 0
                  Editor = edNormal
                  FilterCaseSensitive = False
                  Fixed = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Publication'
                  HeaderAlignment = taCenter
                  HeaderFont.Charset = DEFAULT_CHARSET
                  HeaderFont.Color = clNavy
                  HeaderFont.Height = -11
                  HeaderFont.Name = 'Tahoma'
                  HeaderFont.Style = []
                  MinSize = 0
                  MaxSize = 0
                  Password = False
                  PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                  PrintColor = clWhite
                  PrintFont.Charset = DEFAULT_CHARSET
                  PrintFont.Color = clWindowText
                  PrintFont.Height = -11
                  PrintFont.Name = 'Tahoma'
                  PrintFont.Style = []
                  ReadOnly = True
                  ShowBands = False
                  SortStyle = ssAutomatic
                  SpinMax = 0
                  SpinMin = 0
                  SpinStep = 1
                  Tag = 0
                  Width = 532
                end>
              ColWidths = (
                16
                532)
            end
          end
        end
      end
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'tlx'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    OnTypeChange = SaveDialog1TypeChange
    Left = 640
    Top = 120
  end
  object ipwXMLp1: TipwXMLp
    Left = 400
    Top = 64
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 144
    Top = 88
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clSilver
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = 13160660
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10841658
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6956042
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = 6956042
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6956042
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle2: TcxStyle
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16247513
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle15: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13828095
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle16: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle17: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle18: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle19: TcxStyle
      AssignedValues = [svColor]
      Color = 14872561
    end
    object cxStyle20: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4707838
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle21: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12937777
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle22: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle23: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle24: TcxStyle
      AssignedValues = [svColor]
      Color = 13160660
    end
    object cxStyle25: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle26: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 12937777
      TextColor = clWhite
    end
    object cxStyle27: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle28: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 10542814
      TextColor = clBlack
    end
    object cxStyle29: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 13692654
      TextColor = clBlack
    end
    object cxStyle30: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle31: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4308156
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle32: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 1916928
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle33: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle34: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clOlive
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle35: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle36: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clOlive
    end
    object cxStyle37: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clOlive
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object GridTableViewStyleSheetWindowsStandard: TcxGridTableViewStyleSheet
      Caption = 'Windows Standard'
      Styles.ContentEven = cxStyle3
      Styles.ContentOdd = cxStyle4
      Styles.Inactive = cxStyle9
      Styles.Selection = cxStyle12
      Styles.Footer = cxStyle5
      Styles.Group = cxStyle6
      Styles.GroupByBox = cxStyle7
      Styles.Header = cxStyle8
      Styles.Indicator = cxStyle10
      Styles.Preview = cxStyle11
      BuiltIn = True
    end
    object GridTableViewStyleSheetDevExpress: TcxGridTableViewStyleSheet
      Caption = 'DevExpress'
      Styles.Background = cxStyle13
      Styles.Content = cxStyle14
      Styles.ContentEven = cxStyle15
      Styles.ContentOdd = cxStyle16
      Styles.FilterBox = cxStyle17
      Styles.Inactive = cxStyle22
      Styles.IncSearch = cxStyle23
      Styles.Selection = cxStyle26
      Styles.Footer = cxStyle18
      Styles.Group = cxStyle19
      Styles.GroupByBox = cxStyle20
      Styles.Header = cxStyle21
      Styles.Indicator = cxStyle24
      Styles.Preview = cxStyle25
      BuiltIn = True
    end
    object GridTableViewStyleSheetWheat: TcxGridTableViewStyleSheet
      Caption = 'Wheat'
      Styles.Content = cxStyle27
      Styles.ContentEven = cxStyle28
      Styles.ContentOdd = cxStyle29
      Styles.Inactive = cxStyle34
      Styles.Selection = cxStyle37
      Styles.Footer = cxStyle30
      Styles.Group = cxStyle31
      Styles.GroupByBox = cxStyle32
      Styles.Header = cxStyle33
      Styles.Indicator = cxStyle35
      Styles.Preview = cxStyle36
      BuiltIn = True
    end
  end
  object ipwXMLp2: TipwXMLp
    OnCharacters = ipwXMLp2Characters
    OnEndElement = ipwXMLp2EndElement
    OnStartElement = ipwXMLp2StartElement
    Left = 488
    Top = 72
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'xml'
    Filter = 'Variables files (*.xml)|*.xml'
    Left = 632
    Top = 40
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 704
    object Copy1: TMenuItem
      Action = SSCopyAction1
    end
    object Cut1: TMenuItem
      Action = SSCutAction1
    end
    object Paste1: TMenuItem
      Action = SSPasteAction1
    end
    object Specimens1: TMenuItem
      Caption = 'Specimens'
      OnClick = Specimens1Click
    end
    object RareType1: TMenuItem
      Action = ToggleRareAction1
    end
    object ShowNeotomaIDs1: TMenuItem
      Caption = 'Neotoma IDs'
      Visible = False
      OnClick = ShowNeotomaIDs1Click
    end
    object WhitmoreTasks1: TMenuItem
      Caption = 'Whitmore Tasks'
      Visible = False
      object AssignWhitmore1: TMenuItem
        Caption = 'Assign Neotoma SampleID'
        OnClick = AssignWhitmore1Click
      end
      object RemoveWhitmoreSample1: TMenuItem
        Caption = 'Remove Whitmore Sample'
        OnClick = RemoveWhitmoreSample1Click
      end
    end
    object Format1: TMenuItem
      Caption = 'Format'
      object Text1: TMenuItem
        Action = FormatTextAction1
      end
      object Number1: TMenuItem
        Action = FormatNumberAction1
      end
      object Date1: TMenuItem
        Action = FormatDateAction1
      end
    end
    object DataType1: TMenuItem
      Caption = 'Row Data Type'
      OnClick = DataType1Click
      object SSAnalysisUnit1: TMenuItem
        Caption = 'Analysis Unit Name'
        OnClick = SSAnalysisUnit1Click
      end
      object SSCollectionUnitName1: TMenuItem
        Caption = 'Collection Unit Name'
        OnClick = SSCollectionUnitName1Click
      end
      object SSCollectionUnitHandle1: TMenuItem
        Caption = 'Collection Unit Handle'
        OnClick = SSCollectionUnitHandle1Click
      end
      object SSSiteName1: TMenuItem
        Caption = 'Site Name'
        OnClick = SSSiteName1Click
      end
    end
  end
  object PopupMenu3: TPopupMenu
    OnPopup = PopupMenu3Popup
    Left = 512
    Top = 120
    object BuildElement3: TMenuItem
      Action = BuildElementAction1
    end
    object EditElements1: TMenuItem
      Action = EditElementsAction1
    end
    object Copy2: TMenuItem
      Action = SSCopyAction1
    end
    object Cut2: TMenuItem
      Action = SSCutAction1
    end
    object Paste2: TMenuItem
      Action = SSPasteAction1
    end
  end
  object PopupMenu4: TPopupMenu
    Left = 288
    Top = 160
    object EditUnits1: TMenuItem
      Action = EditUnitsAction1
    end
    object Copy3: TMenuItem
      Action = SSCopyAction1
    end
    object Cut3: TMenuItem
      Action = SSCutAction1
    end
    object Paste3: TMenuItem
      Action = SSPasteAction1
    end
  end
  object PopupMenu5: TPopupMenu
    Left = 400
    Top = 152
    object EditContexts1: TMenuItem
      Action = EditContextsAction1
    end
    object Copy4: TMenuItem
      Action = SSCopyAction1
    end
    object Cut4: TMenuItem
      Action = SSCutAction1
    end
    object Paste4: TMenuItem
      Action = SSPasteAction1
    end
  end
  object PopupMenu6: TPopupMenu
    Left = 480
    Top = 176
    object EditTaphonomy1: TMenuItem
      Action = EditTaphonomyAction1
    end
    object Copy5: TMenuItem
      Action = SSCopyAction1
    end
    object Cut5: TMenuItem
      Action = SSCutAction1
    end
    object Paste5: TMenuItem
      Action = SSPasteAction1
    end
  end
  object PopupMenu7: TPopupMenu
    OnPopup = PopupMenu7Popup
    Left = 528
    Top = 136
    object EditGroups1: TMenuItem
      Action = EditGroupsAction1
    end
    object Copy6: TMenuItem
      Action = SSCopyAction1
    end
    object Cut6: TMenuItem
      Action = SSCutAction1
    end
    object Paste6: TMenuItem
      Action = SSPasteAction1
    end
  end
  object ipwXMLp5: TipwXMLp
    BuildDOM = False
    OnCharacters = ipwXMLp5Characters
    OnEndElement = ipwXMLp5EndElement
    OnStartElement = ipwXMLp5StartElement
    Left = 504
    Top = 80
  end
  object PopupMenu8: TPopupMenu
    OnPopup = PopupMenu8Popup
    Left = 592
    Top = 112
    object EditControl1: TMenuItem
      Caption = 'Edit Node'
      OnClick = EditControl1Click
    end
    object AddChildControl1: TMenuItem
      Caption = 'Add Child Node'
      OnClick = AddChildControl1Click
    end
    object AddSiblingControl1: TMenuItem
      Caption = 'Add Sibling Node'
      OnClick = AddSiblingControl1Click
    end
    object DeleteControl1: TMenuItem
      Caption = 'Delete Node'
      OnClick = DeleteControl1Click
    end
  end
  object PopupMenu9: TPopupMenu
    Images = cxImageList1
    OnPopup = PopupMenu9Popup
    Left = 352
    Top = 144
    object Synonyms1: TMenuItem
      Caption = 'Synonyms'
      OnClick = Synonyms1Click
    end
    object TaxonNotes1: TMenuItem
      Caption = 'Notes'
      ImageIndex = 36
      OnClick = TaxonNotes1Click
    end
    object EditTaxa1: TMenuItem
      Action = EditTaxaAction1
    end
    object Copy7: TMenuItem
      Action = SSCopyAction1
    end
    object Cut7: TMenuItem
      Action = SSCutAction1
    end
    object Paste7: TMenuItem
      Action = SSPasteAction1
    end
    object NeotomaVar1: TMenuItem
      Caption = 'Neotoma'
      ImageIndex = 6
      Visible = False
      object UpdateVariable1: TMenuItem
        Caption = 'Update Variable'
        OnClick = UpdateVariable1Click
      end
      object DeleteVariable1: TMenuItem
        Caption = 'Delete Variable'
        OnClick = DeleteVariable1Click
      end
    end
  end
  object MainMenu1: TMainMenu
    Images = cxImageList1
    Left = 272
    Top = 112
    object File1: TMenuItem
      Caption = '&File'
      ShortCut = 16474
      object SS_Open: TMenuItem
        Action = ParentForm.FileOpenAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000007F0000008B
          000000950000009E000000A1000000A2000000A3000000A4000000A7000029AD
          D6007BA3AF007DA5B20043A7C50044A7C70048ABCA004BE7FE0052E8FE0059E9
          FE005BE9FE005DEAFE0060E9FD0060EAFE0061EAFE0065EAFD0064EAFE0068EB
          FE006BEBFE0071ECFE0072ECFE0075EDFE0076EDFE007BEDFE007CEEFE007FED
          FD00A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800AAAAAA00ADADAD00AEAE
          AE00AFAFAF00B3B3B300B5B5B500B6B6B600B8B8B800BABABA00BBBBBB00BCBC
          BC0081EEFE0083EEFD0083EEFE0085EEFD0085EEFE0086EEFD0086EFFE0087EF
          FE008EF0FE0092F0FE0094F1FE0095F1FE009AF1FE009CF2FE00B6DEEB00A4F2
          FD00A5F2FE00A6F2FD00A7F3FE00D9D9D900DBDBDB00DEDEDE00DFDFDF00D8E9
          EC00D0F8FE00F0F0F000F1F1F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6
          F600F7F7F700F8F8F800F9F9F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFE
          FE00FFFFFF000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000494949494949
          4949494949494949494949272522222222222222243047494949090909090909
          090909090D0B314949490909153A3D3E3F3E3D3A340C23464949090915383A3B
          3C3B3A3820090A2F49490919091532383938321F1C190C234549091209151B1D
          1E1D1B1A1812090B3049090F1009151516151311100F0F0E2949091417090909
          0909090909090909404909213233353637363533092A49494949094142434444
          0909090909494949494949094A4A4A09494949494949492B2824494909090949
          4949492F494905060322494949494949494900492E2D2C080526494949494949
          4949490102040749044949494949494949494949494949494949}
      end
      object SS_New: TMenuItem
        Action = ParentForm.FileNewAction1
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000C30E0000C30E00001000000000000000F0A25700F1A8
          6200F1AD6B00F1B17200AFAFAF00B8B8B800F3BA8300F5C59600F7E0CE00EBEB
          EB00E8E8E800EDEDED00F0F0F000F5F5F500FAFAFA00FFFFFF00FDCAAAAA9AAA
          ACDFFC544444444445CFF1222222222214AFF1999999999914AFF1BBBBBBBBBB
          14AFF0999999999904AFF0999999999904AFF0999999999904AFF0BBBBBB9BB9
          04AFF1CCCCCCCCCB14AFF1CCCCCCCCCB14AFF2CCCCCCCCCC25BFF3DDDDDDD333
          39DFF6DDDDDDD6869DEFF6EEEEEEE669DEFFF777777777BDEFFF}
      end
      object SS_Close: TMenuItem
        Action = FileCloseAction1
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000C30E0000C30E000010000000000000003737E0007878
          CD0029ADD6005CE9FE006FECFE00A2A2A200B4B4B4009393E80081EEFE0099F1
          FE00D4D4D400D0F8FE00E8E8E800EFEFEF00FAFAFA00FFFFFF00FFFFFFFFFFFF
          FFFFFDDDDDDDDDDDDDFFD6555555555556DF22222222222226CF248999999984
          26CF24889999988426CF24488888884426CF23344444443326CF233333334333
          26CF23344444443326CF28888888888826DF2999992222222DDFE2BBB2CC666D
          DDDFFE222DD0001DDA6FFFFEEEE017AA10DFFFFFFFF0E70071EF}
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object NeotomaData1: TMenuItem
        Action = ParentForm.NeotomaAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E9E9EBEBEBFFFFFFFFFFFFF7F7F7D5D5
          D5E4E4E4FFFFFFFFFFFFC2C3C4BBBEC0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1
          D1D1B1B1B1F7F6F6FFFFFFE2E2E2969696909090D1D1D1FFFFFFC8CACC727D83
          DFE0E1FFFFFFFFFFFFFDFDFDDADADAC7C8C8696A6A8B8F93F2F3F4FAFAFAAAAA
          AA6A6A6A7E7D7DD8D8D8FFFFFFCDD1D28A9497C8CBCCE6E5E5AAAAAA696C6D82
          87897B858865717B9BA0A6F9F9F9EFEFEF858585525758838587FFFFFFFFFFFF
          C8CBCD888F928A8F9485898C8184853F444667757A8B9396939493CACACAEEEE
          EED7D8D8646D71596265FFFFFFFFFFFFE3E4E47582896274876E7E917F888E55
          6064546268828789ACAEB0CFCECED8D8D8EFEEEECCCECF5E696DFFFFFFFFFFFF
          D7DADA64737B5B718C4C648350616B5162685361667B82858E9299ECECECF3F3
          F3F9F9F9F9F9F9778287FFFFFFFEFEFEA1AAAE53646B515B654858664D606846
          5C68576C7DB4B7B7DCDCDCF8F8F9FFFFFFFFFFFFFFFFFFA7AFB2FFFFFFFFFEFE
          8A969B475E66545D6133444C4459604B5F6D586F8A687379606973D0D3D7FFFF
          FFFFFFFFFFFFFFA9B1B4FFFFFFFFFFFF949B9F3A50593B4D54182E37384C5453
          5D62535F6B727F856F7A828D9499DDDDDEFEFEFEEFF0F08E9A9EFFFFFFFFFFFF
          D5D5D557666B2F485118343F253D4648565C555F637A878C879195717B80989D
          9FF8F8F8A4ACAFB9C0C3FFFFFFFFFFFFF2F1F06C797E324F5A203F4A233D473C
          5059596B72748288818C92818C918B94989EA3A69CA5A8FBFCFCFFFFFFFFFFFF
          DDDDDC5D6B70324D582B465129454F394F5843586060717875848A7684897F88
          8BB3B8BAF7F8F8FFFFFFFFFFFFFFFFFFFBFBFBD8DBDCB8BFC27C898F364D5634
          4B54395159425861627177848D91DADBDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFF4F4F48D979A43565E28414B31454E798083EBEBEBFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFCCA
          CECF859297788084D3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      object Whitmore1: TMenuItem
        Action = WhitmoreAction1
        Visible = False
      end
      object N20: TMenuItem
        Caption = '-'
      end
      object SS_Save: TMenuItem
        Action = FileSaveAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E000000010000000000002B2B2B00C35B
          1300EC8B2D00ED8D3000ED8E3200ED8F3400ED8F3500ED903500ED903600ED91
          3700ED913800ED923900EE933C00EE943D00EE943E00EE953F00EE964100EE97
          4400EF9F5100F0A65E00808080009E9E9E00A0A0A000A7A7A700ABABAB00F4C0
          8D00F6C99E00D4D4D400E8E8E800EBEBEB00F1F1F100F9F9F900FEFEFE00FFFF
          FF00000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000212121212121
          2121212121212121212121211716151515151515151516172121210101010101
          01010101010101151721010E100118141821212101100E011621010C0F011800
          18212121010F0C011521010B0D01181418212121010D0B01152101080B010101
          01010101010B0801152101040604050708090905040604011521010203040507
          08090905040302011521010A1B1B1B1B1B1B1B1B1B1B0A011521011120202020
          2020202020201101152101121B1B1B1B1B1B1B1B1B1B12011521011320202020
          2020202020201301162101191B1B1B1B1B1B1B1B1B1B19011721011A20202020
          2020202020201A01212121010101010101010101010101212121}
      end
      object SS_SaveAs: TMenuItem
        Action = FileSaveAsAction1
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000C30E0000C30E000010000000000000001CAADE001AE3
          FD004986B600E7673300D07A5800CD867200FA944200F7AD6F007AEAF600D7A9
          9E00FBD1A000D5CDD000FAF8F700F0E7E40094B1C600AE686300DCCCCCCCDCCC
          CCCC45599999995449CC477BBBBBB97665CC477939DBB96665CC477B4EBDD966
          65CC477DEEEEC93665CC47779B00E63665CC4AA77E800F7765CC5ACCCE8800EA
          65CC4ACCCCE8810965CC4ACCCCCE881045CC4ACCCCCDE8810FCC4ACCCCCCDE88
          12BC3ADDDDDDDBE8812C5FFFFFFFF4F2802CCDDDDDDDDDDB22BC}
      end
      object SS_Export: TMenuItem
        Action = FileExportAction1
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000C30E0000C30E00001000000000000000656565000C0C
          95002D2DB0001111A3007373CD00BBBBBC006E6EA300C3C3C300CBCBC900D5D5
          D300DFDFDC00E4E4E300F2F2F200FFFFFF00EBEBEB00ADADDF00B99888887889
          9ACD977555555778ECDD97777888965ADDDDA77786666314DDDDA88893111111
          2CDDB999A233333333EDE999A23333332ADDEAAAA4444234DDDDEAAAABBBC4FC
          DDDDCBBBBBBBBEBCDDDDCBBBBBBBBBBCDDDDDEEEEEEEEEECDDDDDEEEEEEEECCD
          DDDDDEEEEEEEC608DDDDDEEEEEEED05DDDDDDCCCCCCCD5DDDDDD}
        Visible = False
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object SS_Exit: TMenuItem
        Action = ParentForm.ExitAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000008080008080
          0080800080800080800080800080800080800080800080800080800080800080
          800080800080800080800080801C43DB1231AB1432A91230A91332AC1332AD10
          31AE0D30B10A2EB2082DB4062AB10328B10127B4008080008080143CDD254BE0
          2547CF2647CF2446CF2347D02146D11E45D21B45D51642D51340D60E3DD50939
          D60435D50130D10080801840DE2E51E1B5C1F5FFFFFF4365E64165E63D64E638
          62E73260E82A5CE92459EAFFFFFFA1B8F70536D70227B00080801E45DF3658E2
          FFFFFFFFFFFFFFFFFF4568E64167E73B64E73562E82D5EEAFFFFFFFFFFFFFFFF
          FF0B3BD7062BB1008080254BE03D5EE3506DE6FFFFFFFFFFFFFFFFFF4268E73C
          65E73662E8FFFFFFFFFFFFFFFFFF1950E9103FD80A2DB10080802B4FE14463E4
          536FE7516EE6FFFFFFFFFFFFFFFFFF3D65E7FFFFFFFFFFFFF1F5FE2154E81B50
          E81642D70F31B20080803254E24B69E55570E8526FE74D6CE6FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF2655E72152E71C4EE61C46D61233B00080803759E3516DE7
          5771E7526EE64D6AE64767E5FFFFFFFFFFFFFFFFFF2C57E52653E52250E51E4D
          E52149D61635AF0080803C5DE35974E85972E7536FE64E6BE5FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF2751E4234FE4204CE3254AD51937AF0080804665E5607AE8
          5B74E8546EE7FFFFFFFFFFFFFFFFFF3A5CE3FFFFFFFFFFFFFFFFFF244DE2224B
          E2294CD41B39AE0080804665E56881E95E77E8FFFFFFFFFFFFFFFFFF4361E43D
          5DE43658E3FFFFFFFFFFFFFFFFFF274EE22A4DD31C39AD0080804D6AE66E87EB
          FFFFFFFFFFFFFFFFFF4D68E54764E4405FE43A5BE33456E2FFFFFFFFFFFFFFFF
          FF2C4DD31D3AAD008080526FE77991ECC2CCF7FFFFFF5972E7536DE74D68E546
          64E4415FE43A5BE33859E3FFFFFFADBBF32C4ED31D3AAD00808094A6F0859AEE
          758DEB6E87EA6881EA667FE9627CE95F79E85E79E85975E85672E7506EE64968
          E53F60E43255E00080800080805571E74D6AE64866E54261E44463E43E5FE43E
          5FE43B5CE33B5CE33356E23356E23053E2284DE0008080008080}
      end
    end
    object SEdit: TMenuItem
      Caption = '&Edit'
      object Undo1: TMenuItem
        Action = UndoAction1
        Enabled = False
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object SS_Cut: TMenuItem
        Action = SSCutAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E000000010000000000007F7F7F00DD76
          1400C4905F00C7936200C8946300CB986700D4A17000D7A37200D7A47300D8A5
          7400D9A67500DEAB7A00E0AC7B00E0AD7C009A9A9A009B9B9B00A0A0A000A3A3
          A300A7A7A700A9A9A900ACACAC00ADADAD00B2B2B200B3B3B300B5B5B500B8B8
          B800B9B9B900BABABA00BBBBBB00BCBCBC00BFBFBF00E8B48300E8B58400E9B6
          8500EAB78600C4C4C400C7C7C700CBCBCB00CCCCCC00CECECE00CFCFCF00D2D2
          D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D8E9EC00E3E3
          E300E5E5E500E7E7E700EAEAEA00EEEEEE00EFEFEF00F0F0F000F1F1F100F2F2
          F200F3F3F300F5F5F500F6F6F600F7F7F700F8F8F800F9F9F900FAFAFA00FBFB
          FB00FCFCFC00FDFDFD00FEFEFE00FFFFFF000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000303030303030
          303030303030303030303030303028142630302614283030303030303009010D
          182706010D192D30303030301F0129010C04013001072C3030303030200A1D30
          010130300D052F303030303022012E1B0B03173001093030303030303021012C
          010124010830303030303030303021010B02010B303030303030303030303030
          0000152830303030303030303030301800001119303030303030303030303000
          0E16001A2B30303030303030303018002A3000121B303030303030303030000F
          30301B001C2C3030303030303019002D30303000131E30303030303030001030
          3030301C00233030303030303000303030303030003030303030}
      end
      object SS_Copy: TMenuItem
        Action = SSCopyAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E000000010000000000007C7C7C007D7D
          7D00E6742600E6772A00E67B2E00E67C3000E77D3100E77E3400E7813600E782
          3800E9853B00E9853C00E7894100E9894200E9914C00EA914D00EC995800EC9A
          5800EEA46700818181008484840085858500898989008E8E8E0094949400CBB7
          A400CEB8A600E1CBB700F1CCB100C5C5C500D4D4D400D6D6D600D7D7D700D9D9
          D900DCDCDC00DEDEDE00DFDFDF00E1E1E100E2E2E200E4E4E400E6E6E600E7E7
          E700E9E9E900EAEAEA00ECECEC00EEEEEE00EFEFEF00F1F1F100F3F3F300F4F4
          F400F6F6F600F8F8F800F9F9F900FBFBFB00FFFFFF0000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000363636363626
          201E1E1E1E1E20252B363636363629171300000000001316253636363636070A
          0B0B0B0A09080713203636363621062626262626262406001E36363618150426
          12121212122504001E3636070A0B032526262625242303001E36360626260225
          12121212122202001E3636042612032828282827262403011F36360325260529
          12121228272505142336360225120C2C2C2C2C0D0D0C0C1D2A36360328280E2E
          12122E0F1C0E1929363636052912103232323211111929363636360C2C2C1212
          12121212192936363636360E2E12122E0F1C0E19293636363636361032323232
          11111A29363636363636361212121212121B2A36363636363636}
      end
      object SS_CopyAll: TMenuItem
        Action = SSCopyAllAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object SS_Paste: TMenuItem
        Action = SSPasteAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E000000010000000000000085AC0000C6
          FF0033D1FF0066DCFF00DD761400F0A15400F0A35900F0A65E00F0A76000F1A8
          6100F1A96400F1AB6700F1AC6900F2AE6C00F2AE6D00F1B17200F2B17300F2B7
          7D00F3B77E00AEAEAE00B0B0B000B2B2B200B3B3B300BABABA00BCBCBC00BDBD
          BD00BEBEBE00BFBFBF0099E8FF00F4BD8900F4BE8900F5C59600C0C0C000C1C1
          C100C5C5C500F7E0CE00E5E5E500E9E9E900EAEAEA00EBEBEB00ECECEC00EDED
          ED00EEEEEE00EFEFEF00F0F0F000F1F1F100F3F3F300F4F4F400F6F6F600F7F7
          F700F8F8F800F9F9F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFF
          FF00000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000393939393939
          1614131313131315393939393921170A0D0E0E0E0D0C0B0A1739393900000009
          2A2A2A2A2A2A280917393900010101072A1F1F1F1F1F29071739390001010106
          292A2A2A292827061739390001010105291F1F1F1F1F26051739390001010106
          2C2C2C2C2B2A280618393900010101082D1F1F1F2C2B29081B3939000101010F
          2F2F2F2F10100F0F3939390001010111301F1F3012231119393939000101011D
          343434341E1E001A393939000202021F1F1F1F1F1F0200203939390003030303
          0303030303030022393939001C1C0404040404041C1C00393939393900000420
          2020200400003939393939393939390404040439393939393939}
      end
      object SS_ClearAll: TMenuItem
        Action = ClearAllAction1
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object SS_FormatCells1: TMenuItem
        Action = FormatCellsAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFEBEAFFFFFFFFFFFFFFEBEAFFFFFFFF4A141166
          FFF600FFFF4A141166FFFFBD13FAF50ECEFFFFFDBB13FAF50ECEFF6A4DFFFF3C
          89FFFFFF6A4EFFFF3C89FF4E62FFFF4F63FFFFFF4E63FFFF4F64FF5D5AFFFF48
          6BFFFFFF5D5AFFFF486BFF8438FFFF2B90FFFFFF8438FFFF2B91FFE810AC9A0B
          F5FFFFFFE810AC9A0BF5FFFFB6303AC6FFFFFFFFFFB6303CC6FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      object FormulaToValue1: TMenuItem
        Action = FormulaToValueAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object NulltoZero1: TMenuItem
        Action = NullToZeroAction1
        Caption = 'Null to Zero'
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object SS_Sort: TMenuItem
        Action = SortAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
          FFFFFF106880FFFFFFFFFFFFFFFFFFFFFFFF0E0EF40000FE0000FE0E0EF40E0E
          F40E0EF49494C3F7F3F1FFFFFFFFFFFF30688008B0C0306880FFFFFFFFFFFFFF
          FFFFFFFFFF3A3ADC3F3FD8FFFFFFFFFFFFFDFDFEF2F2F8FFFFFFFFFFFFA8B0C0
          10688000F8F8106880A8B0C0FFFFFFFFFFFFFFFFFFECECF42C2CE30000FEFFFF
          FFFFFFFFFFFFFFFFFFFFFEFEFE10688000F8F800F8F800F8F8106880FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFF0000FE0000FEFFFFFFFFFFFFFFFFFFC3CBD3156B83
          00F8F800F8F800F8F8106880C4CCD4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
          FE0000FEDDDDECFFFFFF1068800F6E860F718800F5F5106880106880106880FF
          FFFFEFEFF6FBFBFCFFFFFFF2F2F8FFFFFF0000FE9C9CC7FFFFFFF9FDFEFFFFFF
          10688000F0F8106880FFFFFFFAFEFEFFFFFF8989C32222E80E0EF41919EC0E0E
          F40000FE0000FEFFFFFFFFFFFFFFFFFF10688000E8F8106880FFFFFFFFFFFFFF
          FFFFF1F1F7ECECF4E7E7F1E8E8F2EAEAF2E9E9F2E9E9F2FEFCFCFFFFFFFFFFFF
          10688020D8F8106880FFFFFFFFFFFFFFFFFFFDFBFBFAF6F4FCFAF8FFFEFEFFFF
          FFF9F4F3F8F3F2F7F2F0FFFFFFFFFFFF10688058E0F8106880FFFFFFFFFFFFFF
          FFFF6F2C0575350F6F2C05FFFFFFF6F2EF6F2C057636116F2C05FFFFFFFFFFFF
          10688058E0F8106880FFFFFFFFFFFFFFFFFFDBCCC474330DDBCAC3F1EAE6F2EA
          E6D8C7BE702D06DDCEC6FFFFFFFFFFFF10688070E0F8106880FFFFFFFFFFFFFF
          FFFFFAF8F6A87D65773611864D2B6F2B047D401DA87D65F7F4F2FFFFFFFFFFFF
          10688090E8F8106880FFFFFFFFFFFFFFFFFFFFFFFFFAF7F56F2C05E6DAD3FFFF
          FF7B3E1BF1EAE6FFFFFFFFFFFFFFFFFF106880BCF0FC106880FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF6F2C05D0B9ABE4D8D06F2C05FAF8F5FFFFFFFFFFFFFFFFFF
          106880FFFFFF106880FFFFFFFFFFFFFFFFFFFFFFFFF8F4F26F2C05712E066D28
          006F2C05FFFFFFF8F4F2FFFFFFFFFFFF106880106880106880FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFEFDFC722F096E2A03FFFFFFFFFFFFFFFFFF}
      end
      object SS_ToggleRare: TMenuItem
        Action = ToggleRareAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFC3DEE08BC3C2DAF4F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDCF5F571C9C83FB8B168B6B4CD
          E2E4EDFFFFF1FFFFE1F5F987D2C82FAF946CC6BAE9F5F6FFFFFFFFFFFFFFFFFF
          FFFFFFB0E0DE3DACA335BBAB42C8BD4AB5B3A0D6D5C2E8E660C3B83DBDA644D6
          C633BBA5C8EAE4FFFFFFFFFFFFFFFFFFF9FAFC8CC8C8209B8F1A9D833DC4AB4E
          D9CB51B0AC4EA39733B4A336BEAF3FD4C245C4B6D0EAE9FFFFFFFFFFFFFFFFFF
          FDFFFFA4D9D82DA397128C7B25958529A6A730AAAC238875258D8645C7B94FD9
          CB71C8C2DEF1F0FFFFFFFFFFFFFFFFFFFFFFFFE6F8F875C0C01F878319877B1A
          9D9934C7C8349F9E24A9AE59E5D94BBFB669B6B3B5E0DEF8FCFCFFFFFFF9FCFD
          C4E4E4DAE9E9B6E2DE258C8F10868F3FB4B546A6A53D989D45BFC644C6C448CB
          C642BFAC37B1997CCBC4F0FDFDA3D9D451BBAC3FB49E39958A1D858523989823
          857C196759246F6535959A1F99A13BC2BE4FDACD57E1D63FBAA4AADEDC51BFAE
          3CC2A734B194168B7C0C8A8E239F9A1D7572156F6021746A3F9DA131AFB443C8
          C054DDD058E0D63FB9A479C6C43AB5A53EB69E3BB39B1C8E82178E8836AAA72D
          83822788802F8F882EA1A525A7B448D2D05EE6DE3EBBA6B6E2DE95D2D240B4A6
          2EA9913BBBA128AA941C8C821D95973099A339989F399F9E32B1AA40A6AA51BB
          AC32B097A9E0DAFFFFFFDEF6F5A6DEDA7BC6BE5EBAAB4AB09F55ABA431989E11
          8C93118E9917B0B840C3BA87C4C2FCFCFDF2FDFDF9FDFDFFFFFFFFFFFFFFFFFF
          FFFFFFF2FCFCE2F6F8D6E9EA58B3AB189386128A822EC8C24DCFBF85C9C0FAFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFFFFF1FAFC76CCC227
          A18E2B9E8A55D5C44FD0BEA5D4CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFAFFFFC8EAE94EAEA3279F8640CFB355BDABE0F1F2FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA5
          DAD543AB9963BFB1D1EAEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ShortCut = 16466
      end
    end
    object SInsert: TMenuItem
      Caption = '&Insert'
      object SS_InsertRow: TMenuItem
        Action = InsertRowAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000120B0000120B00000000000000000000ECEBEBECEBEB
          ECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEB3A873E1D7B2D3D89
          42ECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBEC
          EBEBECEBEBECEBEB1977224EBB7A197722ECEBEBECEBEBECEBEBECEBEBECEBEB
          ECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEBECEBEB1A7A2351C47F1A7A
          23ECEBEBECEBEBECEBEB6666666666666666666666666666666666666666661F
          772A1C852F268F3E157E2252C883137B1F268F3E268F3E388D46666666F4F4F4
          F4F4F4F4F4F4F4F4F4BABABAF4F4F4258D3B66D19566D19566D19550BB8364CF
          9366D19564CF93218A38666666F4F4F4F4F4F4F4F4F4F4F4F4BABABAF4F4F448
          98521E80291B7D260E75157ADCA61177191E802917792241914A6666660F9EC1
          1BA1C126A5C132A9C13A889648B1C153B5C14EB3C13F8A96157E2884E3AE157D
          281AA1C1666666ECEBEB66666600CCFF10D1FF20D7FF31DCFF3DADC151E7FF61
          EDFF59EAFF44AFC116822D8CE8B515812D0FD1FF666666ECEBEB66666600CCFF
          10D1FF20D7FF31DCFF3DADC151E7FF61EDFF59EAFF44AFC1188F4A2CB3531799
          560FD1FF666666ECEBEB6666660F9EC11BA1C126A5C132A9C13A889648B1C153
          B5C14EB3C13F8A9639ACC12FA8C124A5C11AA1C1666666ECEBEB666666F4F4F4
          F4F4F4F4F4F4F4F4F4BABABAF4F4F4F4F4F4F4F4F4BABABAF4F4F4F4F4F4F4F4
          F4F4F4F4666666ECEBEB666666F4F4F4F4F4F4F4F4F4F4F4F4BABABAF4F4F4F4
          F4F4F4F4F4BABABAF4F4F4F4F4F4F4F4F4F4F4F4666666ECEBEB666666666666
          6666666666666666665757576666666666666666665757576666666666666666
          66666666666666ECEBEB5252525A5A5A62626269696971717178787880808088
          88888989898181817979797171716969696262625A5A5AECEBEB5252525A5A5A
          6262626969697171717878788080808888888989898181817979797171716969
          696262625A5A5AECEBEB9595958383838989898F8F8F9595959A9A9AA0A0A0A6
          A6A6A7A7A7A1A1A19B9B9B9595958F8F8F898989969696ECEBEB}
      end
      object SS_InsertColumn: TMenuItem
        Action = InsertColumnAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000120B0000120B00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          FFFFFFFF622162FFFFFFFFFFFFFFFFFFFFFFFFFF217421FFFFFFFFFFFFFFFFFF
          FFFFFFFF217421FFFFFF9B9B9B9B9B9B9B2121622174216262629BF6F6F6F62E
          7F62BDBDBD74B5BDB5629BF6F6F6F62E7F6B212121BD2121216A9B0707070725
          6E76766521BD21079BFF9BF6F6F6F62E7F7F7F6E61BE61F69BFF9BF6F6F6F62E
          7F7F7F6E6A736BF69BFF9B07070707256E767665070707079BFF9BF6F6F6F62E
          7F7F7F6EF6F6F6F69BFF9BF6F6F6F62E7F7F7F6EF6F6F6F69BFF9B9B9B9B9B5B
          9B9B9B5B9B9B9B9B9BFF5B5B9B9BA4A4A4A4A4A4A4A49B9B5BFF5B5B9B9BA4A4
          A4A4A4A4A4A49B9B5BFFF7A4A4A4F7F7F7F7F7F7F7F7A4A4F7FF}
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object SS_InsertWorksheet: TMenuItem
        Caption = 'Worksheet'
        ImageIndex = 20
        object SS_InsertCONISSWorksheet: TMenuItem
          Action = InsertCONISSSheetAction1
        end
        object Concentrations2: TMenuItem
          Action = InsertConcSheetAction1
        end
        object Influx1: TMenuItem
          Action = InsertInfluxSheetAction1
          Enabled = False
        end
      end
    end
    object Delete1: TMenuItem
      Caption = '&Delete'
      object DeleteRow1: TMenuItem
        Action = DeleteRowAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000120B0000120B00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          A79F56AFFFFFFF5F5F9FFFFFFFFFFFFFFFA75F56EFFF9F57A708FFFFFFFFFFFF
          FFFFA75F56AF56A7EFFF9B9B9B9B9B9B9B9B9B5F57565F5D9BFF9BF6F6F6F607
          F6F6F6EE5F57A7F69BFF9BF6F6F6F607F6F6F6A65FA75FF69BFF9B2E2E6E6E65
          7676765F5F5F5F5E9BFF9B373F7F7F6E7FBF6F5F6F7F675F9BFF9B373F7F7F6E
          7FBF5FA77F7F6FA75EFF9B2E2E6E6E65766FAF666E6E6EA7AFFF9BF6F6F6F607
          F6F6F607F6F6F6F69BFF9BF6F6F6F607F6F6F607F6F6F6F69BFF9B9B9B9B9B5B
          9B9B9B5B9B9B9B9B9BFF5B5B9B9BA4A4A4A4A4A4A4A49B9B5BFF5B5B9B9BA4A4
          A4A4A4A4A4A49B9B5BFFF7A4A4A4F7F7F7F7F7F7F7F7A4A4F7FF}
      end
      object DeleteColumn1: TMenuItem
        Action = DeleteColumnAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000120B0000120B00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          A79F56AFFFFFFF5F5F9FFFFFFFFFFFFFFFA75F56EFFF9F57A7FFFFFFFFFFFFFF
          FFFFA75F56AF56A7EFFF9B9B9B9B9B9B9B9B9B5F57565F5D9BFF9BF6F6F6F62E
          7F7F7F6E5F57A7F69BFF9BF6F6F6F62E7F7F7F665FA75FF69BFF9B0707070725
          6E76765F5F9F5F9E9BFF9BF6F6F6F62E7F7F6F5FAFF6A75F9BFF9BF6F6F6F62E
          7F7F5FA7F6F6EFA75EFF9B07070707256E6FAF66070707A7AFFF9BF6F6F6F62E
          7F7F7F6EF6F6F6F69BFF9BF6F6F6F62E7F7F7F6EF6F6F6F69BFF9B9B9B9B9B5B
          9B9B9B5B9B9B9B9B9BFF5B5B9B9BA4A4A4A4A4A4A4A49B9B5BFF5B5B9B9BA4A4
          A4A4A4A4A4A49B9B5BFFF7A4A4A4F7F7F7F7F7F7F7F7A4A4F7FF}
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object DeleteWorksheet1: TMenuItem
        Action = DeleteWorksheetAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object DeleteEmptyRows1: TMenuItem
        Action = DeleteEmptyRowsAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object DeleteEmptyColumns1: TMenuItem
        Action = DeleteEmptyColumnsAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
    end
    object SCalc: TMenuItem
      Caption = '&Calc'
      object SS_CalcSums: TMenuItem
        Action = SumsAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FFFFFFFFFFFF
          B16849B16849B16849B16849B16849B16849B16849B16849B16849B16849B168
          49B16849FFFFFFFFFFFFFFFFFFFFFFFFB16849D8A549D29D45D7A650D8A853E6
          C26CECCF77EED37DFBED99F8E998FAE98BB16849FFFFFFFFFFFFFFFFFFFFFFFF
          B16849C28119C17E1ACD9639D6A84DDCB562E1C174EAD186F1DC91EBCF83EED2
          76B16849FFFFFFFFFFFFFFFFFFFFFFFFB16849D19C38D09B41DBB059E2BE6BEE
          D684FAE494F7E79AEFD38AE7C474EECF72B16849FFFFFFFFFFFFFFFFFFFFFFFF
          B16849DCB153D6A853F4E087B16849B16849B16849B16849B16849B16849B168
          49B16849FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB16849EACE74EAD084FFFEA6B1
          6849FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFB16849FAEC9CEFD88BFFF598B16849FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB16849EFD37CDF
          B359F5E57FB16849FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFB16849F2D77DD59B3BDCA334B16849FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB16849F3DB86D79F3ED7
          9C2CB16849FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFB16849F1D47BD69A32D79A27B16849FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB16849FEF4B1DFB266D59830B16849FF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          B16849EDD38EDEB474DEB56FB16849B16849B16849B16849B16849B16849B168
          49B16849FFFFFFFFFFFFFFFFFFFFFFFFB16849E3B96DD49B4FD59F51DDB160E2
          BA6CE4BF74E6C376E8CA7AE8CC80F8ED9CB16849FFFFFFFFFFFFFFFFFFFFFFFF
          B16849F5E4A2EACE90ECD494ECD396ECD79CEFDCA4F0E0ABF1E3AFEFE0AEFAF6
          C0B16849FFFFFFFFFFFFFFFFFFFFFFFFB16849B16849B16849B16849B16849B1
          6849B16849B16849B16849B16849B16849B16849FFFFFFFFFFFF}
      end
      object SS_CalcPercents: TMenuItem
        Action = PercentsAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000120B0000120B00000000000000000000FFFFFFFFFFFF
          1B5DCA1B5DCA1B5DCA1B5DCAFFFFFFFFFFFFFFFFFFFFFFFFD6E5F84884D91D5F
          CB4582D7D7E7F8FFFFFFFFFFFFFFFFFFFFFFFF1B5DCA2675E7206DE11B5DCAFF
          FFFFFFFFFFE2EDFA1A5CCB206EE5287EEB2E84E41A5CCBE4EDFAFFFFFFFFFFFF
          FFFFFF1B5DCA1E6CE2247FF01B5DCAFFFFFFFFFFFF5E95DF1C68E2216CD9185A
          D049B3E83E9BE15F96DFFFFFFFFFFFFFFFFFFFFFFFFF1B5DCA3290EB3695E81B
          5DCAFFFFFF2465CD2475EB185AD0FFFFFF185AD040A6EF2365CDFFFFFFFFFFFF
          FFFFFFFFFFFF1B5DCA3590E54CBBF01B5DCAFFFFFF2465CD3894EB185AD0FFFF
          FF185AD02488ED2365CDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1B5DCA5DD1F25F
          D4ED1B5DCA5E95DF46A9E72D7AD6185AD01C7FE42385E25F96DFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF1B5DCA4FB7E771EDF01B5DCAE2EDFA1A5CCB2D85E42288
          E7218DE41B5DCAE4EDFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1B5DCA64
          DDF23EA2E71B5DCAD6E5F84884D91D5FCB4582D7D7E7F8FFFFFFFFFFFFD6E5F8
          4884D91D5FCB4582D7D7E7F81B5DCA3290E52E8EEF1B5DCAFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFE2EDFA1A5CCB1F6BE22171E72879E41B5DCAE4EDFA1B
          5DCA1C71EA1A6DE41B5DCAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5E95DF2D73E2
          2B74E51B5DCA2772D449ADE55F96DF1B5DCA1B74E51A82ED1B5DCAFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF2465CD3F88F01B5DCAFFFFFF1B5DCA57AFEF2365CDFF
          FFFF1B5DCA2895ED2991E71B5DCAFFFFFFFFFFFFFFFFFFFFFFFF2465CD54A5F0
          1B5DCAFFFFFF1B5DCA4295EF2365CDFFFFFF1B5DCA3C9BE845B9F01B5DCAFFFF
          FFFFFFFFFFFFFFFFFFFF5E95DF4596E168C4ED1B5DCA2B78DA3895E85F96DFFF
          FFFFFFFFFF1B5DCA4CD1F33FB0E81B5DCAFFFFFFFFFFFFFFFFFFE2EDFA1B5DCA
          4697E44396EB3C97E71C5ECBE4EDFAFFFFFFFFFFFF1B5DCA39A8E54CD3F01B5D
          CAFFFFFFFFFFFFFFFFFFFFFFFFD6E5F84884D91D5FCB4582D7D7E7F8FFFFFFFF
          FFFFFFFFFFFFFFFF1B5DCA1B5DCA1B5DCA1B5DCAFFFFFFFFFFFF}
      end
      object SS_CalcConc: TMenuItem
        Action = ConcAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          0800000000000001000000000000000000000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FF0A0A0A0A0A
          0A0A0A0A0A0A0A0A0A0AFF0A0C776F777E7F6F7E6F6F7E77770AFF0A7F6F6F7E
          0D7E7F0B7E777E0C7E0AFF0A6F0A777777777F6F7E777F6F770AFF0A6F777777
          77777F6F0C6F7F6F770AFF0A0B77770B6F770C776F7E7F0B770AFF0A776F6F77
          6F7777776F7777777F0AFF0A776F0A7777776F77770B6F6F770AFF0A6F6F7F7F
          0B777F6F7F77776F6F0AFF0A0C6F6F6F6F0B770D6F7F0C7E6F0AFF0A6F77770C
          777F777F6F7F776F7E0AFF0A6F6F7777770D776F0A7E7777770AFF0A0C6F7777
          7777776F7F7F7777770AFF0A776F7715777F7F777F7F770C770AFF0A0A0A0A0A
          0A0A0A0A0A0A0A0A0A0AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      object SS_CalcInflux: TMenuItem
        Action = InfluxAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          0800000000000001000000000000000000000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00272727272727
          272727272727272727271D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D6F6F6F6F6F6F
          6F6F6F6F6F6F6F6F6F6F15151515151515151515151515151515656565656565
          65656565656565656565FFFFFFFFFFFFF6FFFFFFFFFFFFFFFFFF0DFFFFFFFFFF
          0DFFFF0DFFFFFFFF0DFFFFFFFFFF0AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          15FFFFFFFFFFFFFFFFFFFFFF0DFFFFFFFF15FF0DFFFF0DFFFFFFFFFFFFFFFF0D
          FFFFFFFFF6FFFFFFFFFFFFFFFFF6F6FFFF0DF6FF0AFFF6FF15FFFFFF0DFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF15FFFFFFFFFFFFFF0DFFFFFF0DFF15FFFF
          FFFFFF0DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0DFF}
        Enabled = False
      end
    end
    object STools: TMenuItem
      Caption = '&Tools'
      SubMenuImages = cxImageList1
      object SS_VariableLookup: TMenuItem
        Action = VariableLookupAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000002222
          22002A25230026406900463F3A0047403A004F474100415571006A6159006B64
          5D0074696000756A610075706D003B74A600177ED300187CD200187FD5005769
          8900546E96005274A300557FB0001881D8003F95CA007C8BA3007B8EAB007B95
          B4005789C2005FA7CC005EADD30055AFE20062ADCF0073D7FE0073D8FE0072DA
          FE0083686500856C6700836E6F008C6C6900837D7800837D7900857F7B00927C
          72009B7F7500A5785900A47B580085807B0086807C0087817D0087827E008B80
          79008D867F0097806F0099847100BA845900A6836200B0826100CB916200D199
          6900D2A47C00D7A97C00F2B56900F2B76B00F0C47900FDC87400F9CC7A00FDCC
          7800FBD07C00958C85009A99A300A6938F00A9948D00A4999C00AC969000AC9C
          9B00AE9E9800B4988A00BEA69100B3B0AE00BFB3B300BAB8B600BDBBB90098B7
          D800A9B5C800CDAC8F00C9AD9000CAAF9F00CABDAF00C1B5B400C2C0BF00CEC1
          BE00D0C0B700DCD3BB00E1D39900F1CA8200F6D68800F9D18100FBD28200FBD6
          8600FED78300F8D68B00F8DC8E00FCDE8E00F0DD9600FBE19400FBE39500FBE6
          9700FCE39400F9E39D00FBE69900FBE69B00FEE99500FBEB9D00FBEB9E00FEEC
          9D00FBE9A500FBEEA200FBEDA700FCEEAA00FCF1A700FDF7AD00FEFBAA00FDF8
          AF00FCF6B100FEFEB100FDFDB500FCFBB800FDFBBD00FDFEBB00FDFDBD00C4C3
          C300C7C4C200C6C6C600CFC6C500C8C8C800CECECE00CFCFCF00D4CDCC00D5CD
          CD00D7CECD00D0D0D000D1D1D100D5D5D500D7D7D700D9D0D000DAD3D300DCD3
          D200D9D9D900DAD9D900DADADA00DBDBDB00DCDCDC00DDDCDC00DDDDDD00DEDE
          DD00DFDFDF00E2DBDA00FDFBC100FDFEC100FDFEC300FEFEC200FDFDC800FDFE
          C900FDFDCC00FDFDCE00FDFED000FDFED100FEFED200FDFDD600FEFED700FCF8
          D800FCFBDB00FDFDDB00E1E1E100E2E2E200E3E2E200E3E3E200E3E3E300E4E4
          E300E5E5E500E7E7E700E8E8E800EBEBEB00ECECEC00EFEFEF00EBF0F600F0ED
          E300FDFDE100FDFDE800F0F0F000F2F2F200F3F3F300F4F4F400FBF7F400FEFE
          F200FCF9F800FCFBFA00FEFEFE00FFFFFF000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000C50906050404
          04040402000000110724C5328185878D96B0B3B19399171E1D03C54D83838C95
          B2BCBFB3AF181B211012C54F83838B95B2B7BDAC191C200E1301C55083838692
          B0B6BE52161F15140C00C5828846333429498A470D0F1A972700C54E36667B9F
          A85B23254451B8B42E00892C6E71779EA7C1B9228FB0ADB530002A3E6167799D
          A7BBC4565792B0AC2F002B62636D7AA1A3ABBAAA459A928E2E003560646B749C
          A2A0A3A648948E872D00374170A4A9757E7C7F7D4A928D8C2E004B3C6A80A572
          766F785C8498928D280091383F69736C5E65684CAEAC988E2600C559393D405F
          425D5490AF9A955808C5C5C59B553A3B535AC543310B0A0AC5C5}
      end
      object SS_EditVariableLookup: TMenuItem
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000002222
          22002A25230018435A0026406900234A6B00463F3A0047403A004F4741005C55
          4E00415571006A61590074696000756A610075706D001A7ABE002E6785002B61
          8900266BAE003B74A600177ED300187CD200187FD50057698900546E96005274
          A300557FB0001881D8002B95D1003F95CA004389AA004C8ABE007C8BA3007B8E
          AB007B95B4004185C900488CC700488EC7004F8EC4004998C500469DD0004998
          DC004B9ADD005789C2005C99CF00519DDD00549AD8005FA7CC0058A5D8005EAD
          D30051A2E20055AFE200669FD30062ADCF006FA8CB0063A3D70076BAD7007AB6
          D50077BEE70055C9E4005BDFF5005EDCF5005FDCF5005AE1F7005BE2F7005DE2
          F8006DCAED0063DFF7006CDDF60077CBE70078D0ED0079D3EE007DD4EE0073D7
          FE0073D8FE0072DAFE0079D3F0007BD4F1007AD6F200836E6F00837D79009B7F
          7500A5785900A47B580086807C0087817D0087827E008B8079008D867F00BA84
          5900A6836200B0826100CB916200D1996900D2A47C00D7A97C00F2B56900F2B7
          6B00F0C47900FDC87400F9CC7A00FDCC7800FBD07C00958C8500A9948D00B498
          8A00BEA69100B3B0AE00BFB3B300BAB8B600BDBBB90085B1DB0090B7D10098B7
          D800A9B5C8008BC0E70081D6EE0094C7F90091C9F900A5C3D700ACD5E400AFD4
          E500ACD2EF00A8D9E800AED3F600B2D5E500B4D2F000AFE4F300B2E3F900BAE3
          F000BDE5F200CDAC8F00C9AD9000CAAF9F00C2C0BF00CEC1BE00D0C0B700E1D3
          9900F1CA8200F6D68800F9D18100FBD28200FBD68600FED78300F8D68B00F8DC
          8E00FCDE8E00F0DD9600FBE19400FBE39500FBE69700FCE39400F9E39D00FBE6
          9900FBE69B00FEE99500FBEB9D00FBEB9E00FEEC9D00FBE9A500FBEEA200FBED
          A700FCEEAA00FCF1A700FDF7AD00FEFBAA00FDF8AF00FCF6B100FDFDB500FDFB
          BD00FDFEBB00FDFDBD00C4C3C300C7C4C200C6C6C600C8C8C800CFCFCF00D4CD
          CC00D5CDCD00D1D1D100D5D5D500DAD3D300DCD3D200DAD9D900DBDBDB00DCDC
          DC00DDDCDC00DEDEDD00DFDFDF00C4E0FC00C2F6FD00C4F6FD00C7F7FD00E2DB
          DA00FDFBC100FDFEC100FDFDC800FDFEC900FDFDCC00FDFDCE00FDFED000FDFE
          D100FCF8D800E1E1E100E2E2E200E3E2E200E3E3E200E3E3E300E4E4E300E5E5
          E500E7E7E700E8E8E800EBEBEB00E0F2FF00E5F3FF00EBF0F600F0ECEC00F0F0
          F000F2F2F200F4F4F400FBF7F400FCF9F800FCFBFA00FDFDFD00FEFEFE00FFFF
          FF00000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000E10908070606
          06060602000000170A4FE158ACAFB0B4B9CFD2D0B7BB20353304E16BAEAEB3B8
          D1D9DBD2CE212F4B1618E16DAEAE03111F36DACB22314A141901E16EAEAE1075
          762312721D491B1A0E00E1ADB1681ED52E0F272513152BBA5000E16C5A937739
          703B3C462D71D7D35400B2539B9EA47D38BE43414C29CCD4560051628E94A6C3
          7945C03D3F4D2ACB5500528F909AA7C5C78247C03E404E320500598D9198A1C2
          C6C48148BF4442372C265B659DC8CAA2A9A8AA7B7480737CBD34696097ABC99F
          A39CA5897F3A7ED67A24B65C6396A0998B92956ACD78306F281CE1875D61648C
          668A84B5CEBCB8860BE1E1E1C1855E5F8388E167570D0C0CE1E1}
        Caption = 'Edit Variable Lookup'
        ImageIndex = 32
        object SS_EditTaxa: TMenuItem
          Action = EditTaxaAction1
        end
        object SS_EditGroups: TMenuItem
          Action = EditGroupsAction1
        end
        object SS_EditElements: TMenuItem
          Action = EditElementsAction1
        end
        object SS_EditUnits: TMenuItem
          Action = EditUnitsAction1
        end
        object SS_EditContexts: TMenuItem
          Action = EditContextsAction1
        end
        object SS_EditTaphonomy: TMenuItem
          Action = EditTaphonomyAction1
        end
      end
      object SS_NewVariableLookup: TMenuItem
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
        Caption = 'New Variable Lookup'
        object SS_NewTaxa: TMenuItem
          Action = NewTaxaAction1
        end
        object SS_NewGroups: TMenuItem
          Action = NewGroupsAction1
        end
        object SS_NewElements: TMenuItem
          Action = NewElementsAction1
        end
        object SS_NewUnits: TMenuItem
          Action = NewUnitsAction1
        end
        object SS_NewContexts: TMenuItem
          Action = NewContextsAction1
        end
        object SS_NewTaphonomy: TMenuItem
          Action = NewTaphonomyAction1
        end
      end
      object SS_CheckVariables: TMenuItem
        Action = CheckVariablesAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000120B0000120B00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          FFFFA3A3F6FFFFFFFFFFFFFFFFFFFFFFFFEDA3A3E4F6FFFFFFFFFFFFFFFFFFFF
          FFE3ECECE307F6FFFFFF9B9B9B9B9B9BE3ECECECECE39B9B9BFF9BF6F6F6F6EC
          ECEC090709ECECF69BFF9BF6F6F6F6E309ECF607F609ECF59BFF9B070707EC09
          F4F507F707F509EB9BFF9BF6F6F60909F6F6F607F6F60909E3FF9BF6F6F6F607
          F6F6F607F6F6F609ECF59B07070707F7070707F70707070709EC9BF6F6F6F607
          F6F6F607F6F6F6F69BFF9BF6F6F6F607F6F6F607F6F6F6F69BFF9B9B9B9B9B5B
          9B9B9B5B9B9B9B9B9BFF5B5B9B9BA4A4A4A4A4A4A4A49B9B5BFF5B5B9B9BA4A4
          A4A4A4A4A4A49B9B5BFFF7A4A4A4F7F7F7F7F7F7F7F7A4A4F7FF}
        Caption = 'Validate Taxa Names'
      end
      object EditMetadataLookup1: TMenuItem
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
        Caption = 'Edit Metadata Lookup'
        object EditFacies1: TMenuItem
          Action = EditFaciesAction1
        end
        object EditDepositionalAgents1: TMenuItem
          Action = EditDepAgentAction1
        end
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object Specimens2: TMenuItem
        Caption = 'Specimens'
        ImageIndex = 70
        OnClick = Specimens2Click
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object SS_Chronology: TMenuItem
        Action = ChronologyAction1
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000120B0000120B00000000000000000000C0C0C0000000
          C0C0C0C0C0C0000000C0C0C0C0C0C0000000C0C0C0C0C0C0000000C0C0C0C0C0
          C0000000C0C0C0C0C0C000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000C0C0C0000000
          912222972E2EE8D1D1F4E8E8FAF4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0000000EEDCDCEEDCDC9C3A3A9C3A3AEEDCDCFA
          F4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000
          FFFFFFFAF4F4EEDCDC972E2E9C3A3AF4E8E8FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0000000FFFFFFFFFFFFFAF4F4E8D1D1972E2EE8
          D1D1FAF4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0000000
          FFFFFFFFFFFFFFFFFFF4E8E89C3A3A9C3A3AF4E8E8FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFAF4F4E8D1D197
          2E2EE8D1D1FAF4F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0000000
          FFFFFFFFFFFFFFFFFFFFFFFFF4E8E89C3A3A972E2EE8D1D1F4E8E8FAF4F4FFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0000000FFFFFFFFFFFFFFFFFFFFFFFFFAF4F4EE
          DCDC9C3A3A972E2E9C3A3AE8D1D1F4E8E8FAF4F4FFFFFFFFFFFF000000000000
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAF4F4F4E8E8E8D1D19C3A3A9C3A3AA246
          46F4E8E8FAF4F4FFFFFFC0C0C0000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFAF4F4F4E8E8EEDCDCE8D1D19C3A3AEEDCDCFAF4F4C0C0C0000000
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4E8
          E89C3A3A9C3A3AF4E8E8000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFAF4F4E8D1D1972E2EE2C5C5C0C0C0000000
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFF4E8E89C3A3A912222C0C0C0000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAF4F4E8D1D18B1717}
      end
      object ImportChronology1: TMenuItem
        Caption = 'Import Chronology'
        ImageIndex = 83
        object BaconClam1: TMenuItem
          Action = ImportClamAction1
          ImageIndex = 80
        end
        object Bacon: TMenuItem
          Action = ImportBaconAction1
          Caption = '&Bacon'
        end
        object Bchron: TMenuItem
          Action = ImportBchronAction1
          Caption = 'Bc&hron'
        end
        object OxCal1: TMenuItem
          Action = ImportOxCalAction1
        end
        object ChronologiesTabsheet1: TMenuItem
          Action = ImportChronologiesTabsheet1
          ImageIndex = 81
        end
      end
      object Calibrate1: TMenuItem
        Action = CalibrateAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object N22: TMenuItem
        Caption = '-'
      end
      object Counter1: TMenuItem
        Action = CounterAction1
      end
      object SS_ClusterAnalysis: TMenuItem
        Action = ClusterAnalysisAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
          000000000000FFFFFFFF0000000000FFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFF00000000FF0000000000000000FFFFFF00FFFF00FFFFFFFFFFFFFF
          FF0000000000FFFF00FF0000000000000000FFFFFFFFFFFF00FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF00000000000000FFFFFFFFFFFFFFFFFF00FFFFFFFFFF0000
          00FFFFFFFFFFFFFF00FF0000000000FF00FFFFFFFFFFFFFF00FFFFFFFFFFFFFF
          000000000000000000FF0000FFFFFFFF00FFFFFFFFFFFFFFFFFFFF0000000000
          00FFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      object SS_Diagram: TMenuItem
        Action = DiagramAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000120B0000120B00000001000000000000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF006DFF0B6D6D0C
          6D6D0EFF0A6D6D0B6D6D0AFF0B0A0A1575FFFFFF0A18FFFFFFFF6DFF0B0A0A0A
          0B9CFFFF0A0A40FFFFFF6DFF0B0A0A0A0B9DFFFF0A0A0C90FFFF0AFF0B0A0A0B
          A6FFFFFF0A1818FFFFFF6DFF0B0A0C99FFFFFFFF0A0A0A40FFFF6DFF0C62AAFF
          FFFFFFFF0A0A0A0CA3FF0BFF0BA0FFFFFFFFFFFF0A0A0A18FFFF6DFF0BA0FFFF
          FFFFFFFF0A0A0A0A40FF6DFF0BA0FFFFFFFFFFFF0A0A0A0A0BAE0EFF0BA0FFFF
          FFFFFFFF0A0A0A0A0AB16DFF0BA0FFFFFFFFFFFF0A0A0A0A18FF6DFF0BA0FFFF
          FFFFFFFF0A0A0A0A0CAEFFFF0B81FFFFFFFFFFFF0B15799A9EFFFFFF400B40FF
          FFFFFFFF400B40FFFFFFFFFFFF400B75FFFFFFFFFF400B8BFFFF}
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object SS_Options: TMenuItem
        Action = OptionsAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object Test1: TMenuItem
        Caption = 'Test'
        Visible = False
        OnClick = Test1Click
      end
    end
    object Neotoma1: TMenuItem
      Caption = '&Neotoma'
      object Login1: TMenuItem
        Caption = '&Login'
        ImageIndex = 38
        OnClick = Login1Click
      end
      object Lookup1: TMenuItem
        Caption = 'L&ookup'
        ImageIndex = 39
        object NewLookupFile1: TMenuItem
          Action = NeotomaLookupAction1
        end
        object NewGeoPoliticalLookupFile1: TMenuItem
          Action = NeotomaGeoPoliticalLookupAction1
        end
        object NewTaxaLookupFile2: TMenuItem
          Action = NeotomaTaxaLookupAction1
        end
        object NewVariableModifiersLookupFile1: TMenuItem
          Action = NeotomaModifiersAction1
        end
      end
      object Variables1: TMenuItem
        Caption = '&Variables'
        ImageIndex = 37
        object ValidateSpreadsheetTaxa1: TMenuItem
          Caption = '&Validate Spreadsheet Taxa'
          Hint = 'Validate spreadsheet taxa against Neotoma Taxa table'
          OnClick = NeotomaValidateTaxaAction1Execute
        end
        object HierarachyCheck1: TMenuItem
          Action = NeotomaHierarchyCheckAction1
        end
      end
      object Steward1: TMenuItem
        Caption = '&Steward'
        ImageIndex = 40
        object Upload1: TMenuItem
          Action = NeotomaUploadAction1
        end
        object EditPublicationsTable1: TMenuItem
          Action = NeotomaEditPublicationsTableAction1
        end
        object EditTaxaTable1: TMenuItem
          Action = NeotomaEditTaxaTableAction1
        end
      end
      object WebServices1: TMenuItem
        Caption = 'Web Services'
        ImageIndex = 76
        Visible = False
        OnClick = WebServices1Click
      end
    end
    object SHelp: TMenuItem
      Caption = '&Help'
      object HelpTopics1: TMenuItem
        Action = ParentForm.HelpTopicsAction1
        Bitmap.Data = {
          E6040000424DE604000000000000E60300002800000010000000100000000100
          08000000000000010000C30E0000C30E0000EC00000000000000000000003300
          00006600000099000000CC000000FF0000000033000033330000663300009933
          0000CC330000FF33000000660000336600006666000099660000CC660000FF66
          000000990000339900006699000099990000CC990000FF99000000CC000033CC
          000066CC000099CC0000CCCC0000FFCC000000FF000033FF000066FF000099FF
          0000CCFF0000FFFF000000003300330033006600330099003300CC003300FF00
          330000333300333333006633330099333300CC333300FF333300006633003366
          33006666330099663300CC663300FF6633000099330033993300669933009999
          3300CC993300FF99330000CC330033CC330066CC330099CC3300CCCC3300FFCC
          330000FF330033FF330066FF330099FF3300CCFF3300FFFF3300000066003300
          66006600660099006600CC006600FF0066000033660033336600663366009933
          6600CC336600FF33660000666600336666006666660099666600CC666600FF66
          660000996600339966006699660099996600CC996600FF99660000CC660033CC
          660066CC660099CC6600CCCC6600FFCC660000FF660033FF660066FF660099FF
          6600CCFF6600FFFF660000009900330099006600990099009900CC009900FF00
          990000339900333399006633990099339900CC339900FF339900006699003366
          99006666990099669900CC669900FF6699000099990033999900669999009999
          9900CC999900FF99990000CC990033CC990066CC990099CC9900CCCC9900FFCC
          990000FF990033FF990066FF990099FF9900CCFF9900FFFF99000000CC003300
          CC006600CC009900CC00CC00CC00FF00CC000033CC003333CC006633CC009933
          CC00CC33CC00FF33CC000066CC003366CC006666CC009966CC00CC66CC00FF66
          CC000099CC003399CC006699CC009999CC00CC99CC00FF99CC0000CCCC0033CC
          CC0066CCCC0099CCCC00CCCCCC00FFCCCC0000FFCC0033FFCC0066FFCC0099FF
          CC00CCFFCC00FFFFCC000000FF003300FF006600FF009900FF00CC00FF00FF00
          FF000033FF003333FF006633FF009933FF00CC33FF00FF33FF000066FF003366
          FF006666FF009966FF00CC66FF00FF66FF000099FF003399FF006699FF009999
          FF00CC99FF00FF99FF0000CCFF0033CCFF0066CCFF0099CCFF00CCCCFF00FFCC
          FF0000FFFF0033FFFF0066FFFF0099FFFF00CCFFFF00FFFFFF00000000000D0D
          0D001A1A1A00282828003535350043434300505050005D5D5D006B6B6B007878
          78008686860093939300A1A1A100AEAEAE00BBBBBB00C9C9C900D6D6D600E4E4
          E400F1F1F100FFFFFF00E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6
          E6000000E6E6E6E6E6E6E6E6E6E6E600006F6FE200E6E6E6E6E6E6E6E600006F
          6FD7D7E6E200E6E6E6E6E600006F6FD7D70000E6E6E200E6E6E6E26F6FD7D700
          006F6F00E6E6E200E6E6E26FD700006F6F6F6F6F00E6E6E200E6E200006F6F6F
          7ED26F6F6F00E6E6E200E26F6F6F6F6F6F7E6F6F6F6F00E600E6E66FD76F6F6F
          6F6FD2D26F6F6F0000E6E6E66FD76F6F6F6F6F7ED2D26F6F00E6E6E6E66FD76F
          6F6F7E6FD2D26F6F6F00E6E6E6E66FD76F6FD2D2D26F6F6F0000E6E6E6E6E66F
          D76F6F6F6F6F0000E6E6E6E6E6E6E6E66FD76F6F0000E6E6E6E6E6E6E6E6E6E6
          E66F6F00E6E6E6E6E6E6}
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object About1: TMenuItem
        Action = ParentForm.AboutAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
      object Registration1: TMenuItem
        Action = ParentForm.RegistrationAction1
        Bitmap.Data = {
          36050000424D3605000000000000360400002800000010000000100000000100
          08000000000000010000C30E0000C30E00000001000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A6000020400000206000002080000020A0000020C0000020E000004000000040
          20000040400000406000004080000040A0000040C0000040E000006000000060
          20000060400000606000006080000060A0000060C0000060E000008000000080
          20000080400000806000008080000080A0000080C0000080E00000A0000000A0
          200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
          200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
          200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
          20004000400040006000400080004000A0004000C0004000E000402000004020
          20004020400040206000402080004020A0004020C0004020E000404000004040
          20004040400040406000404080004040A0004040C0004040E000406000004060
          20004060400040606000406080004060A0004060C0004060E000408000004080
          20004080400040806000408080004080A0004080C0004080E00040A0000040A0
          200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
          200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
          200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
          20008000400080006000800080008000A0008000C0008000E000802000008020
          20008020400080206000802080008020A0008020C0008020E000804000008040
          20008040400080406000804080008040A0008040C0008040E000806000008060
          20008060400080606000806080008060A0008060C0008060E000808000008080
          20008080400080806000808080008080A0008080C0008080E00080A0000080A0
          200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
          200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
          200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
          2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
          2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
          2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
          2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
          2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
          2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
          2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          0707070707070707070707070707070707070707070707070707}
      end
    end
  end
  object ipwXMLp6: TipwXMLp
    OnCharacters = ipwXMLp6Characters
    OnEndElement = ipwXMLp6EndElement
    OnStartElement = ipwXMLp6StartElement
    Left = 608
    Top = 104
  end
  object ActionList1: TActionList
    Images = cxImageList1
    Left = 240
    Top = 152
    object FileCloseAction1: TAction
      Category = 'File'
      Caption = '&Close'
      ImageIndex = 1
      OnExecute = FileCloseAction1Execute
    end
    object FileSaveAction1: TAction
      Category = 'File'
      Caption = '&Save'
      ImageIndex = 2
      OnExecute = FileSaveAction1Execute
    end
    object FileSaveAsAction1: TAction
      Category = 'File'
      Caption = 'Save &As'
      ImageIndex = 9
      OnExecute = FileSaveAsAction1Execute
    end
    object FileExportAction1: TAction
      Category = 'File'
      Caption = '&Export'
      ImageIndex = 10
      OnExecute = FileExportAction1Execute
    end
    object SSCutAction1: TAction
      Category = 'Edit'
      Caption = 'Cut'
      ImageIndex = 12
      OnExecute = SSCutAction1Execute
    end
    object SSCopyAction1: TAction
      Category = 'Edit'
      Caption = 'Copy'
      ImageIndex = 13
      OnExecute = SSCopyAction1Execute
    end
    object SSCopyAllAction1: TAction
      Category = 'Edit'
      Caption = 'Copy All'
      ImageIndex = 14
      OnExecute = SSCopyAllAction1Execute
    end
    object SSPasteAction1: TAction
      Category = 'Edit'
      Caption = 'Paste'
      ImageIndex = 15
      OnExecute = SSPasteAction1Execute
    end
    object ClearAllAction1: TAction
      Category = 'Edit'
      Caption = 'Clear All'
      ImageIndex = 16
      OnExecute = ClearAllAction1Execute
    end
    object ImportOxCalAction1: TAction
      Category = 'Tools'
      Caption = '&OxCal'
      ImageIndex = 35
      OnExecute = ImportOxCalAction1Execute
    end
    object SortAction1: TAction
      Category = 'Edit'
      Caption = 'Sort'
      ImageIndex = 18
      OnExecute = SortAction1Execute
    end
    object ToggleRareAction1: TAction
      Category = 'Edit'
      Caption = 'Toggle Rare'
      ImageIndex = 19
      OnExecute = ToggleRareAction1Execute
    end
    object InsertRowAction1: TAction
      Category = 'Insert'
      Caption = 'Row'
      ImageIndex = 24
      OnExecute = InsertRowAction1Execute
    end
    object DeleteRowAction1: TAction
      Category = 'Insert'
      Caption = 'Row'
      ImageIndex = 26
      OnExecute = DeleteRowAction1Execute
    end
    object InsertColumnAction1: TAction
      Category = 'Insert'
      Caption = 'Column'
      ImageIndex = 25
      OnExecute = InsertColumnAction1Execute
    end
    object DeleteColumnAction1: TAction
      Category = 'Insert'
      Caption = 'Column'
      ImageIndex = 27
      OnExecute = DeleteColumnAction1Execute
    end
    object DeleteWorksheetAction1: TAction
      Category = 'Insert'
      Caption = 'Worksheet'
      ImageIndex = 28
      OnExecute = DeleteWorksheetAction1Execute
    end
    object InsertCONISSSheetAction1: TAction
      Category = 'Insert'
      Caption = 'CONISS'
      ImageIndex = 21
      OnExecute = InsertCONISSSheetAction1Execute
    end
    object SumsAction1: TAction
      Category = 'Calc'
      Caption = '&Sums'
      ImageIndex = 29
      OnExecute = SumsAction1Execute
    end
    object PercentsAction1: TAction
      Category = 'Calc'
      Caption = 'Percents'
      ImageIndex = 30
      OnExecute = PercentsAction1Execute
    end
    object VariableLookupAction1: TAction
      Category = 'Tools'
      Caption = 'Variable Lookup'
      ImageIndex = 31
      OnExecute = VariableLookupAction1Execute
    end
    object EditTaxaAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Taxa'
      OnExecute = EditTaxaAction1Execute
    end
    object EditGroupsAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Groups'
      OnExecute = EditGroupsAction1Execute
    end
    object EditElementsAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Elements'
      OnExecute = EditElementsAction1Execute
    end
    object EditUnitsAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Units'
      OnExecute = EditUnitsAction1Execute
    end
    object EditContextsAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Contexts'
      OnExecute = EditContextsAction1Execute
    end
    object EditTaphonomyAction1: TAction
      Category = 'Tools'
      Caption = 'Edit T&aphonomy'
      OnExecute = EditTaphonomyAction1Execute
    end
    object NewTaxaAction1: TAction
      Category = 'Tools'
      Caption = 'New &Taxa'
      OnExecute = NewTaxaAction1Execute
    end
    object NewGroupsAction1: TAction
      Category = 'Tools'
      Caption = 'New &Groups'
      OnExecute = NewGroupsAction1Execute
    end
    object NewElementsAction1: TAction
      Category = 'Tools'
      Caption = 'New &Elements'
      OnExecute = NewElementsAction1Execute
    end
    object NewUnitsAction1: TAction
      Category = 'Tools'
      Caption = 'New &Units'
      OnExecute = NewUnitsAction1Execute
    end
    object NewContextsAction1: TAction
      Category = 'Tools'
      Caption = 'New &Contexts'
      OnExecute = NewContextsAction1Execute
    end
    object NewTaphonomyAction1: TAction
      Category = 'Tools'
      Caption = 'New T&aphonomy'
      OnExecute = NewTaphonomyAction1Execute
    end
    object CheckVariablesAction1: TAction
      Category = 'Tools'
      Caption = 'Check Variables'
      ImageIndex = 37
      OnExecute = CheckVariablesAction1Execute
    end
    object ChronologyAction1: TAction
      Category = 'Tools'
      Caption = 'Chronology'
      ImageIndex = 33
      OnExecute = ChronologyAction1Execute
    end
    object ClusterAnalysisAction1: TAction
      Category = 'Tools'
      Caption = 'Cluster Analysis'
      ImageIndex = 21
      OnExecute = ClusterAnalysisAction1Execute
    end
    object DiagramAction1: TAction
      Category = 'Tools'
      Caption = 'Diagram'
      ImageIndex = 36
      OnExecute = DiagramAction1Execute
    end
    object OptionsAction1: TAction
      Category = 'Tools'
      Caption = 'Options'
      ImageIndex = 47
      OnExecute = OptionsAction1Execute
    end
    object BuildElementAction1: TAction
      Caption = 'Build Element'
      OnExecute = BuildElementAction1Execute
    end
    object FormatTextAction1: TAction
      Category = 'Format'
      Caption = 'Text'
      OnExecute = FormatTextAction1Execute
    end
    object FormatNumberAction1: TAction
      Category = 'Format'
      Caption = 'Number'
      OnExecute = FormatNumberAction1Execute
    end
    object FormatDateAction1: TAction
      Category = 'Format'
      Caption = 'Date'
      OnExecute = FormatDateAction1Execute
    end
    object FormulaToValueAction1: TAction
      Category = 'Edit'
      Caption = 'Formula to Value'
      ImageIndex = 52
      OnExecute = FormulaToValueAction1Execute
    end
    object FormatCellsAction1: TAction
      Category = 'Edit'
      Caption = 'Format Cells'
      ImageIndex = 17
      OnExecute = FormatCellsAction1Execute
    end
    object UndoAction1: TAction
      Category = 'Edit'
      Caption = 'UnDo'
      ImageIndex = 11
      OnExecute = UndoAction1Execute
    end
    object ConcAction1: TAction
      Category = 'Calc'
      Caption = 'Concentrations'
      ImageIndex = 22
      OnExecute = ConcAction1Execute
    end
    object InsertConcSheetAction1: TAction
      Category = 'Insert'
      Caption = 'Concentrations'
      ImageIndex = 22
      OnExecute = InsertConcSheetAction1Execute
    end
    object InsertInfluxSheetAction1: TAction
      Category = 'Insert'
      Caption = 'Influx'
      ImageIndex = 23
      OnExecute = InsertInfluxSheetAction1Execute
    end
    object InfluxAction1: TAction
      Category = 'Calc'
      Caption = 'Influx'
      ImageIndex = 23
      OnExecute = InfluxAction1Execute
    end
    object DeleteEmptyRowsAction1: TAction
      Category = 'Insert'
      Caption = 'Empty Rows'
      OnExecute = DeleteEmptyRowsAction1Execute
    end
    object DeleteEmptyColumnsAction1: TAction
      Category = 'Insert'
      Caption = 'Empty Columns'
      OnExecute = DeleteEmptyColumnsAction1Execute
    end
    object NeotomaValidateTaxaAction1: TAction
      Category = 'Neotoma'
      Caption = '&Taxa'
      OnExecute = NeotomaValidateTaxaAction1Execute
    end
    object NeotomaTaxaLookupAction1: TAction
      Category = 'Neotoma'
      Caption = 'New &Taxa Lookup File'
      Hint = 'Write a new taxa lookup file based on Neotoma Taxa table'
      OnExecute = NeotomaTaxaLookupAction1Execute
    end
    object NeotomaHierarchyCheckAction1: TAction
      Category = 'Neotoma'
      Caption = '&Hierarchy Check'
      OnExecute = NeotomaHierarchyCheckAction1Execute
    end
    object NeotomaModifiersAction1: TAction
      Category = 'Neotoma'
      Caption = 'New &Variable Modifiers Lookup File'
      OnExecute = NeotomaModifiersAction1Execute
    end
    object NeotomaLookupAction1: TAction
      Category = 'Neotoma'
      Caption = 'New Tilia &Lookup File'
      ImageIndex = 39
      OnExecute = NeotomaLookupAction1Execute
    end
    object NeotomaGeoPoliticalLookupAction1: TAction
      Category = 'Neotoma'
      Caption = 'New &GeoPolitical Lookup File'
      ImageIndex = 46
      OnExecute = NeotomaGeoPoliticalLookupAction1Execute
    end
    object NeotomaEditTaxaTableAction1: TAction
      Category = 'Neotoma'
      Caption = 'Edit &Taxa Table'
      ImageIndex = 43
      OnExecute = NeotomaEditTaxaTableAction1Execute
    end
    object NeotomaEditPublicationsTableAction1: TAction
      Category = 'Neotoma'
      Caption = 'Edit &Publications Table'
      ImageIndex = 43
      OnExecute = NeotomaEditPublicationsTableAction1Execute
    end
    object NeotomaGetDataAction1: TAction
      Category = 'Neotoma'
      Caption = 'Neo&toma'
    end
    object EditFaciesAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Facies'
      OnExecute = EditFaciesAction1Execute
    end
    object EditDepAgentAction1: TAction
      Category = 'Tools'
      Caption = 'Edit &Depositional Agent'
      OnExecute = EditDepAgentAction1Execute
    end
    object CalibrateAction1: TAction
      Category = 'Tools'
      Caption = 'Calibrate'
      ImageIndex = 35
      OnExecute = CalibrateAction1Execute
    end
    object ImportClamAction1: TAction
      Category = 'Tools'
      Caption = '&Clam'
      ImageIndex = 83
      OnExecute = ImportClamAction1Execute
    end
    object ImportBaconAction1: TAction
      Category = 'Tools'
      Caption = 'ImportBaconAction1'
      ImageIndex = 34
      OnExecute = ImportBaconAction1Execute
    end
    object ImportBchronAction1: TAction
      Category = 'Tools'
      Caption = 'ImportBchronAction1'
      ImageIndex = 82
      OnExecute = ImportBchronAction1Execute
    end
    object ImportChronologiesTabsheet1: TAction
      Category = 'Tools'
      Caption = '&Chronologies Tabsheet'
      OnExecute = ImportChronologiesTabsheet1Execute
    end
    object NeotomaUploadAction1: TAction
      Category = 'Neotoma'
      Caption = '&Validate and Upload'
      ImageIndex = 41
      OnExecute = NeotomaUploadAction1Execute
    end
    object NullToZeroAction1: TAction
      Category = 'Edit'
      Caption = 'NullToZeroAction1'
      ImageIndex = 62
      OnExecute = NullToZero1Execute
    end
    object DefaultDiagramAction1: TAction
      Category = 'Tools'
      Caption = 'Default Diagram'
      OnExecute = DefaultDiagramAction1Execute
    end
    object WhitmoreAction1: TAction
      Category = 'File'
      Caption = '&Whitmore'
      ImageIndex = 77
      OnExecute = WhitmoreAction1Execute
    end
    object CounterAction1: TAction
      Category = 'Tools'
      Caption = 'Counter'
      ImageIndex = 79
      OnExecute = CounterAction1Execute
    end
  end
  object ImageList1: TImageList
    Height = 9
    Width = 48
    Left = 768
    Bitmap = {
      494C010103000400F80A30000900FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000C0000000090000000100200000000000001B
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      28000000C0000000090000000100010000000000D80000000000000000000000
      000000000000000000000000FFFFFF00EE371C7DEF7FFB8FE38D831FF71FC71F
      BC7F000000000000EDDEEBBDEF7FFB77DD77BEEFF6EFBAEFBBBF000000000000
      07DEEBA0EF7FC1F7FD77DFEF83EFFAEFBFBF0000000000006FDEEBADEFBFDBF7
      FD77EFEFB7EFFAEFBFBF000000000000ADDE1BB5EFBFEB77F30FF6EFD6EFE61F
      BBBF000000000000AC3EFBB5EFDFEB0FFD7FFA1FD61FFAFFB87F000000000000
      CDFEFBB9EFDDF37EFD7FFAFBE6FDFAFBBBED000000000000CDFEEBB98FEAF37D
      5D77BAFBE6FABAEA3BED000000000000EC1F1C7DEE0DFB06E38FC60BF60DC71B
      B82D00000000000000000000000000000000000000000000000000000000}
  end
  object PopupMenuCodes: TPopupMenu
    Left = 192
    Top = 88
    object Metadata1: TMenuItem
      Caption = 'Metadata'
      Hint = 'Metadata|Metadata'
      OnClick = Metadata1Click
      object mdChronology1: TMenuItem
        Caption = 'Chronology'
        Hint = 'Chronology metadata'
        object mdChron: TMenuItem
          Caption = 'Chron'
          Hint = 'Sample age'
          object mdChron1: TMenuItem
            Caption = '1'
            OnClick = mdChron1Click
          end
          object mdChron2: TMenuItem
            Caption = '2'
            OnClick = mdChron1Click
          end
          object mdChron3: TMenuItem
            Caption = '3'
            OnClick = mdChron1Click
          end
          object mdChron4: TMenuItem
            Caption = '4'
            OnClick = mdChron1Click
          end
          object mdChron5: TMenuItem
            Caption = '5'
            OnClick = mdChron1Click
          end
          object mdChron6: TMenuItem
            Caption = '6'
            OnClick = mdChron1Click
          end
          object mdChron7: TMenuItem
            Caption = '7'
            OnClick = mdChron1Click
          end
          object mdChron8: TMenuItem
            Caption = '8'
            OnClick = mdChron1Click
          end
          object mdChron9: TMenuItem
            Caption = '9'
            OnClick = mdChron1Click
          end
        end
        object mdChronOld: TMenuItem
          Caption = 'Chron.Old'
          Hint = 'Older limit of sample age'
          object mdChronOld1: TMenuItem
            Caption = '1'
            OnClick = mdChron1Click
          end
          object mdChronOld2: TMenuItem
            Caption = '2'
            OnClick = mdChron1Click
          end
          object mdChronOld3: TMenuItem
            Caption = '3'
            OnClick = mdChron1Click
          end
          object mdChronOld4: TMenuItem
            Caption = '4'
            OnClick = mdChron1Click
          end
          object mdChronOld5: TMenuItem
            Caption = '5'
            OnClick = mdChron1Click
          end
          object mdChronOld6: TMenuItem
            Caption = '6'
            OnClick = mdChron1Click
          end
          object mdChronOld7: TMenuItem
            Caption = '7'
            OnClick = mdChron1Click
          end
          object mdChronOld8: TMenuItem
            Caption = '8'
            OnClick = mdChron1Click
          end
          object mdChronOld9: TMenuItem
            Caption = '9'
            OnClick = mdChron1Click
          end
        end
        object ChronYoung1: TMenuItem
          Caption = 'Chron.Young'
          Hint = 'Younger limit of sample age'
          object mdChronYoung1: TMenuItem
            Caption = '1'
            OnClick = mdChron1Click
          end
          object mdChronYoung2: TMenuItem
            Caption = '2'
            OnClick = mdChron1Click
          end
          object mdChronYoung3: TMenuItem
            Caption = '3'
            OnClick = mdChron1Click
          end
          object mdChronYoung4: TMenuItem
            Caption = '4'
            OnClick = mdChron1Click
          end
          object mdChronYoung5: TMenuItem
            Caption = '5'
            OnClick = mdChron1Click
          end
          object mdChronYoung6: TMenuItem
            Caption = '6'
            OnClick = mdChron1Click
          end
          object mdChronYoung7: TMenuItem
            Caption = '7'
            OnClick = mdChron1Click
          end
          object mdChronYoung8: TMenuItem
            Caption = '8'
            OnClick = mdChron1Click
          end
          object mdChronYoung9: TMenuItem
            Caption = '9'
            OnClick = mdChron1Click
          end
        end
      end
      object mdSite1: TMenuItem
        Caption = 'Site'
        Hint = 'Site metadata'
        OnClick = mdSite1Click
        object mdAllSiteItems1: TMenuItem
          Caption = 'All Metadata Items'
          Hint = 'All site metadata'
          OnClick = mdAllSiteItems1Click
        end
        object N13: TMenuItem
          Caption = '-'
        end
        object mdSiteName1: TMenuItem
          Caption = 'Site Name'
          Hint = 'Site name'
          OnClick = mdSiteName1Click
        end
        object N21: TMenuItem
          Caption = '-'
        end
        object mdGeoPol1: TMenuItem
          Caption = 'First Geopolitical Division'
          Enabled = False
          Hint = 'First geopolitical division'
          OnClick = mdGeoPol1Click
        end
        object mdGeoPol2: TMenuItem
          Caption = 'Second Geopolitical Division'
          Enabled = False
          Hint = 'Second geopoltical division'
          OnClick = mdGeoPol2Click
        end
        object mdGeoPol3: TMenuItem
          Caption = 'Third Geopolitical Division'
          Enabled = False
          Hint = 'Third geopolitical division'
          OnClick = mdGeoPol3Click
        end
        object mdAdmin1: TMenuItem
          Caption = 'Administrative Unit'
          Enabled = False
          Hint = 'Administrative unit'
          OnClick = mdAdmin1Click
        end
        object N16: TMenuItem
          Caption = '-'
        end
        object mdLatNorth1: TMenuItem
          Caption = 'Latitude North'
          Enabled = False
          Hint = 'North latitude of site'
          OnClick = mdLatNorth1Click
        end
        object mdLatSouth1: TMenuItem
          Caption = 'Latitude South'
          Enabled = False
          Hint = 'South latitude of site'
          OnClick = mdLatSouth1Click
        end
        object mdLongWest1: TMenuItem
          Caption = 'Longitude West'
          Enabled = False
          Hint = 'West longitude of site'
          OnClick = mdLongWest1Click
        end
        object mdLongEast1: TMenuItem
          Caption = 'Longitude East'
          Enabled = False
          Hint = 'East longitude of site'
          OnClick = mdLongEast1Click
        end
        object mdAltitude1: TMenuItem
          Break = mbBarBreak
          Caption = 'Altitude'
          Enabled = False
          Hint = 'Altitude in m'
          OnClick = mdAltitude1Click
        end
        object mdArea1: TMenuItem
          Caption = 'Area'
          Enabled = False
          Hint = 'Area in ha'
          OnClick = mdArea1Click
        end
        object mdSiteDesc1: TMenuItem
          Caption = 'Site Description'
          Enabled = False
          Hint = 'Site description'
          OnClick = mdSiteDesc1Click
        end
        object mdSiteNotes1: TMenuItem
          Caption = 'Site Notes'
          Enabled = False
          Hint = 'Site notes'
          OnClick = mdSiteNotes1Click
        end
        object N17: TMenuItem
          Caption = '-'
        end
        object mdLakeCharacteristics1: TMenuItem
          Caption = 'Lake Characteristics'
          Enabled = False
          Hint = 'Lake characteristics'
          OnClick = mdLakeCharacteristics1Click
        end
      end
      object mdCollectionUnit1: TMenuItem
        Caption = 'Collection Unit'
        Hint = 'Collection unit metadata'
        OnClick = mdCollectionUnit1Click
        object mdAlllCollectionUnitItems1: TMenuItem
          Caption = 'All Metadata Items'
          Hint = 'All collection unit metadata'
          OnClick = mdAllCollectionUnitItems1Click
        end
        object N12: TMenuItem
          Caption = '-'
        end
        object mdCollName1: TMenuItem
          Caption = 'Collection Unit Name'
          Hint = 'Collection unit name'
          OnClick = mdCollName1Click
        end
        object mdHandle1: TMenuItem
          Caption = 'Handle'
          Hint = 'Handle'
          OnClick = mdHandle1Click
        end
        object mdCollType1: TMenuItem
          Caption = 'Collection Unit Type'
          Hint = 'Collection unit type'
          OnClick = mdCollType1Click
        end
        object mdCollDevice1: TMenuItem
          Caption = 'Collection Device'
          Hint = 'Collection unit device'
          OnClick = mdCollDevice1Click
        end
        object mdCollectors1: TMenuItem
          Caption = 'Collectors'
          Hint = 'Collectors'
          OnClick = mdCollectors1Click
        end
        object mdDateColl1: TMenuItem
          Caption = 'Date Collected'
          Hint = 'Date collected'
          OnClick = mdDateColl1Click
        end
        object mdCollLoc1: TMenuItem
          Caption = 'Location in Site'
          Hint = 'Location in site'
          OnClick = mdCollLoc1Click
        end
        object N14: TMenuItem
          Caption = '-'
        end
        object mdLatGPS1: TMenuItem
          Caption = 'GPS Latitude'
          Hint = 'GPS or precise latitude'
          OnClick = mdLatGPS1Click
        end
        object mdLongGPS1: TMenuItem
          Caption = 'GPS Longitude'
          Hint = 'GPS or precise longitude'
          OnClick = mdLongGPS1Click
        end
        object mdGPSErr1: TMenuItem
          Caption = 'GPS Error'
          Hint = 'GPS error'
          OnClick = mdGPSErr1Click
        end
        object mdGPSAlt1: TMenuItem
          Caption = 'GPS Altitude'
          Hint = 'GPS or precise altitude'
          OnClick = mdGPSAlt1Click
        end
        object mdDepEnv1: TMenuItem
          Break = mbBarBreak
          Caption = 'Depositional Environment'
          Hint = 'Depositional environment'
          OnClick = mdDepEnv1Click
        end
        object mdSubstrate1: TMenuItem
          Caption = 'Substrate'
          Hint = 'Substrate'
          OnClick = mdSubstrate1Click
        end
        object mdSlopeAngle1: TMenuItem
          Caption = 'Slope Angle'
          OnClick = mdSlopeAngle1Click
        end
        object mdSlopeAspect1: TMenuItem
          Caption = 'Slope Aspect'
          OnClick = mdSlopeAspect1Click
        end
        object mdWaterDep1: TMenuItem
          Caption = 'Water Depth'
          Hint = 'Water depth'
          OnClick = mdWaterDep1Click
        end
        object N15: TMenuItem
          Caption = '-'
        end
        object mdCollNotes1: TMenuItem
          Caption = 'Collection Unit Notes'
          Hint = 'Collection unit notes'
          OnClick = mdCollNotes1Click
        end
      end
      object mdAnalysisUnit1: TMenuItem
        Caption = 'Analysis Unit'
        Hint = 'Analysis unit metadata'
        OnClick = mdAnalysisUnit1Click
        object mdAnalUnit1: TMenuItem
          Caption = 'Analysis Unit Name'
          Hint = 'Analysis unit name'
          OnClick = mdAnalUnit1Click
        end
        object mdBottom1: TMenuItem
          Caption = 'Bottom'
          Visible = False
          OnClick = mdBottom1Click
        end
        object mdDepth1: TMenuItem
          Caption = 'Depth'
          Hint = 'Analysis unit depth'
          object mdAltDepth1: TMenuItem
            Caption = '1'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth2: TMenuItem
            Caption = '2'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth3: TMenuItem
            Caption = '3'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth4: TMenuItem
            Caption = '4'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth5: TMenuItem
            Caption = '5'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth6: TMenuItem
            Caption = '6'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth7: TMenuItem
            Caption = '7'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth8: TMenuItem
            Caption = '8'
            OnClick = mdAltDepth1Click
          end
          object mdAltDepth9: TMenuItem
            Caption = '9'
            OnClick = mdAltDepth1Click
          end
        end
        object mdThick1: TMenuItem
          Caption = 'Thickness'
          Hint = 'Analysis unit thickness'
          OnClick = mdThick1Click
        end
        object mdFacies1: TMenuItem
          Caption = 'Facies'
          Hint = 'Analysis unit facies'
          OnClick = mdFacies1Click
        end
        object mdDepAgent1: TMenuItem
          Caption = 'Depositional Agent'
          OnClick = mdDepAgent1Click
        end
        object mdMixed1: TMenuItem
          Caption = 'Mixed'
          OnClick = mdMixed1Click
        end
        object mdIGSN1: TMenuItem
          Caption = 'IGSN'
          OnClick = mdIGSN1Click
        end
        object mdAnalUnitNotes1: TMenuItem
          Caption = 'Notes'
          OnClick = mdAnalUnitNotes1Click
        end
      end
      object mdSample1: TMenuItem
        Caption = 'Sample'
        Hint = 'Sample metadata'
        OnClick = mdSample1Click
        object AllSampleItems1: TMenuItem
          Caption = 'All Metadata Items'
          Hint = 'All sample metadata'
          OnClick = AllSampleItems1Click
        end
        object N18: TMenuItem
          Caption = '-'
        end
        object mdSampleName1: TMenuItem
          Caption = 'Sample Name'
          OnClick = mdSampleName1Click
        end
        object mdKeywords1: TMenuItem
          Caption = 'Keywords'
          Hint = 'Sample keywords'
          OnClick = mdKeywords1Click
        end
        object mdDateSampled1: TMenuItem
          Caption = 'Date Sampled'
          Hint = 'Date sampled'
          OnClick = mdDateSampled1Click
        end
        object mdAnalyst1: TMenuItem
          Caption = 'Analyst'
          Hint = 'Analyst'
          OnClick = mdAnalyst1Click
        end
        object mdDateAnal1: TMenuItem
          Caption = 'Date Analyzed'
          Hint = 'Date analyzed'
          OnClick = mdDateAnal1Click
        end
        object mdTaxonSampled1: TMenuItem
          Caption = 'Taxon Sampled'
          OnClick = mdTaxonSampled1Click
        end
        object mdLabNumber1: TMenuItem
          Caption = 'Lab Number'
          OnClick = mdLabNumber1Click
        end
        object mdPrepMethod1: TMenuItem
          Caption = 'Preparation Method'
          OnClick = mdPrepMethod1Click
        end
        object mdSampleNotes1: TMenuItem
          Caption = 'Sample Notes'
          OnClick = mdSampleNotes1Click
        end
      end
      object mdDataset1: TMenuItem
        Caption = 'Dataset Type'
        Hint = 'New Dataset Type'
        OnClick = mdDataset1Click
      end
    end
    object Copy8: TMenuItem
      Action = SSCopyAction1
    end
    object Cut8: TMenuItem
      Action = SSCutAction1
    end
    object Paste8: TMenuItem
      Action = SSPasteAction1
    end
  end
  object PopupMenuSubstrates: TPopupMenu
    Left = 592
    Top = 168
    object ShowDescription1: TMenuItem
      Caption = 'Show Description'
      OnClick = ShowDescription1Click
    end
  end
  object ImageList2: TImageList
    Height = 9
    Width = 9
    Left = 736
    Top = 88
    Bitmap = {
      494C010102000800AC0809000900FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000240000000900000001002000000000001005
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000908B7000000
      0000000000000000000000000000000000000707B10000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000049031000000000000000000000000000000
      0000000000001313BC000F10BB000C0CB9000000000000000000000000000707
      B4000708B3000707B20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000069C30000596
      31000591310000000000000000000000000000000000000000001717BF001414
      BD001010BB00000000000909B7000808B6000808B50000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000007A7310006A23000069D30000598300005933100000000000000
      00000000000000000000000000001D1DC2001918C0001515BE001111BC000E0E
      BA00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000007AD320007AA310007A831000000
      0000069F3000059B310005953000000000000000000000000000000000000000
      00002222C4001E1EC2001919C000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000007AD320000000000000000000000000006A13100059C30000597
      31000000000000000000000000003232CB002D2DC9002928C7002424C5001F1F
      C200000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000007A23100069E2F0005993000000000004444D1003F3F
      CF003939CD00000000002E2EC9002A2AC7002525C50000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000006A4
      3000000000005858D7005151D5004C4CD3000000000000000000000000003535
      CB003030C9002B2BC70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000005E5ED9000000
      0000000000000000000000000000000000003C3CCE0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000424D3E000000000000003E00000028000000240000000900000001000100
      00000000480000000000000000000000000000000000000000000000FFFFFF00
      FFDF400000000000EF8E000000000000C7C440000000000083E0C00000000000
      11F1C00000000000B8E0C00000000000FC44400000000000FE8E000000000000
      FFDF40000000000000000000000000000000000000000000000000000000}
  end
  object ImageList4: TImageList
    Left = 776
    Top = 80
    Bitmap = {
      494C010102000800AC0710001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000C6C6C6007E7E
      7E007E7E7E007E7E7E007E7E7E007777770072727200737373006F6F6F006A6A
      6A00747474007E7E7E007E7E7E00000000000000000000000000B7A293006947
      3100694731006947310069473100694731006947310069473100694731006947
      3100694731006947310069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600F1F1
      F100C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
      C600C6C6C600A6A6A6007E7E7E00000000000000000000000000B7A29300EEE6
      E100B7A29300B7A29300B7A29300B7A29300B7A29300B7A29300B7A29300B7A2
      9300B7A29300B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600F3F3
      F300F1F1F100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C60074747400000000000000000000000000B7A29300F1EA
      E600EEE6E100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FDFDFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600F5F5
      F500F3F3F300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C6006A6A6A00000000000000000000000000ACABAB00FEFE
      FD00FBFBFC005454D400E3E3F700FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600F8F8
      F800F5F5F500FFFFFF00FFFFFF00FBFBFB00F8F8F800FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C6006F6F6F00000000000000000000000000ACABAB00FEFE
      FD00B3B3EB000000C0002424C900FBFBFC00FEFEFD00FEFEFD00FEFEFD00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FAFA
      FA00F8F8F800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C60073737300000000000000000000000000ACABAB00FEFE
      FD004040CF000C0CC3000000C0009B9BE500FEFEFD00FEFEFD00FEFEFD00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FCFC
      FC00FAFAFA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C60072727200000000000000000000000000ACABAB008B8B
      E1000000C0007070DB006464D8001818C600EFEFF900FEFEFD00FEFEFD00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FCFCFC00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C60078787800000000000000000000000000ACABAB008787
      E1001C1CC700E3E3F700EFEFF9002020C8006060D700FEFEFD00FEFEFD00FEFE
      FD00FEFEFD00B7A293005E3F3100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C6007E7E7E00000000000000000000000000ACABAB00FEFE
      FD00FEFEFD00FEFEFD00FEFEFD00CBCBF1000C0CC300AFAFEA00FEFEFD00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E500C6C6C6007E7E7E00000000000000000000000000ACABAB00FEFE
      FD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00ABABE9001414C500DFDFF600FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FBFBFB00F9F9F900F6F6F600F4F4
      F400C6C6C600C6C6C6007E7E7E00000000000000000000000000ACABAB00FEFE
      FD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00ABABE9003434CC00FEFE
      FD00FEFEFD00B7A2930069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FBFBFB00F9F9F900C6C6
      C6007E7E7E007E7E7E007E7E7E00000000000000000000000000ACABAB00FEFE
      FD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00ABABE9002B2C
      B600694731006947310069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FBFBFB00C6C6
      C600F4F4F400E0E0E0007E7E7E00000000000000000000000000ACABAB00FEFE
      FD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00FEFEFD00ABAB
      E9001414C500DBC9BF0069473100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00C6C6
      C600E0E0E0007E7E7E0000000000000000000000000000000000B7A29300FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDFDFD00B7A2
      9300DBC9BF006947310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C6C6
      C6007E7E7E000000000000000000000000000000000000000000B7A29300FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00B7A2
      9300694731000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
      C600000000000000000000000000000000000000000000000000B7A29300B7A2
      9300B7A29300B7A29300B7A29300B7A29300B7A29300B7A29300B7A29300B7A2
      9300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00C001C00100000000C001C00100000000
      C001C00100000000C001C00100000000C001C00100000000C001C00100000000
      C001C00100000000C001C00100000000C001C00100000000C001C00100000000
      C001C00100000000C001C00100000000C001C00100000000C003C00300000000
      C007C00700000000C00FC00F0000000000000000000000000000000000000000
      000000000000}
  end
  object ipwHTTP1: TipwHTTP
    TransferredDataLimit = 65536
    Left = 48
    Top = 352
  end
  object TcpClient1: TTcpClient
    Left = 96
    Top = 352
  end
  object cxImageList1: TcxImageList
    DrawingStyle = dsTransparent
    FormatVersion = 1
    DesignInfo = 4719392
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000708890FF5672
          82FF4E6777FF465C6CFF3F5161FF374656FF2F3C4CFF273141FF202636FF181B
          2BFF101020FF0909118B00000000000000000000000000000000728A92FF90A0
          B0FF70B0D0FF2098D0FF2098D0FF2098D0FF2094CAFF208AB9FF207FA8FF2075
          97FF207090FF204860FF0404083F000000000000000000000000778F97FF80C8
          E0FF90A0B0FFA1E8FFFF8EE3FFFF7CDDFDFF6DD1F7FF5FC5F2FF51BAECFF42AF
          E7FF1090D0FF206880FF0909118B0000000000000000000000007C949CFF82E1
          FFFF90A0B0FFA5C4CDFFA1E8FFFF8EE3FFFF7CDDFDFF6DD1F7FF5FC5F2FF51BA
          ECFF42AFE7FF1088D0FF204860FF0101031500000000000000008098A0FF95E5
          FFFF80C8E0FF90A0B0FFB4EDFFFFA1E8FFFF8EE3FFFF7CDDFDFF6DD1F7FF5FC5
          F2FF51BAECFF42AFE7FF206880FF0909118B0000000000000000859DA5FFA6EA
          FFFF95E5FFFF90A0B0FFA5C4CDFFB4EDFFFFA1E8FFFF8EE3FFFF7CDDFDFF6DD1
          F7FF5FC5F2FF51BAECFF30A0E0FF204860FF01010315000000008AA2AAFFB8EE
          FFFFA6EAFFFF80C8E0FF90A0B0FFC0F0FFFF80E0FFFF80E0FFFF80E0FFFF80E0
          FFFF80E0FFFF80E0FFFF80E0FFFF50A8D0FF567282FF000000008FA7AFFFC0F0
          FFFFB8EEFFFFA6EAFFFF90B0C0FF90B0C0FF90B0C0FF90B0C0FF8DACBBFF88A6
          B3FF829FACFF7D98A4FF78929CFF738B94FF718993FF0000000090A8B0FFC0F0
          FFFFC0F0FFFFB8EEFFFFA6EAFFFF95E5FFFF82E1FFFF74D6FAFF66CBF4FF59C1
          EFFF4BB6EAFF3EABE5FF708890FF00000000000000000000000090A8B0FFC0F0
          FFFFC0F0FFFFC0F0FFFFB8EEFFFFA6EAFFFF708890FF708890FF708890FF7088
          90FF708890FF708890FF708890FF00000000000000000000000090A8B0FF8DB6
          C6FFC0F0FFFFC0F0FFFFC0F0FFFF708890FF2B30325300000000000000000000
          0000000000001A08002C722300B19D3203F7A23E10FF993202FF4B575B8490A8
          B0FF88A0A8FF7A929AFF708890FF2B3032530000000000000000000000000000
          0000000000000000000022140A2D95411CC9D47F54FFA03B0CFF000000000000
          000000000000000000000000000000000000000000000000000000000000270D
          014022140A2D01010101321E1043A05326D09C421FD99D3303F8000000000000
          0000000000000000000000000000000000000000000000000000000000007D2C
          05C78D4A23AE3B1F0E5589471FB2803514BB22140A2D792500C4000000000000
          0000000000000000000000000000000000000000000000000000000000002214
          0A2D803514BB993203E9883005CC2E0F024A0200000400000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000007088
          90FF708890FF708890FF708890FF708890FF708890FF647982FF576973FF4A58
          63FF3D4854FF2F3745FF222736FF151726FF101020FF0000000000000000738B
          93FF8AE2FFFF2098D0FF2098D0FF2098D0FF2098D0FF2096CEFF208FC2FF2088
          B6FF2080AAFF20799EFF207192FF207090FF1C1F2EFF00000000000000007890
          98FF9AE7FFFF8AE2FFFF7ADBFDFF6DD1F7FF60C7F2FF54BCEDFF47B2E9FF3BA8
          E4FF2F9FDFFF249ADAFF1A95D5FF20769AFF2F3745FF00000000000000007D95
          9DFFABEBFFFF9AE7FFFF8AE2FFFF7ADBFDFF6DD1F7FF60C7F2FF54BCEDFF47B2
          E9FF3BA8E4FF2F9FDFFF249ADAFF2083AEFF43505CFF0000000000000000829A
          A2FFBCEFFFFFABEBFFFF9AE7FFFF8AE2FFFF7ADBFDFF6DD1F7FF60C7F2FF54BC
          EDFF47B2E9FF3BA8E4FF2F9FDFFF208FC2FF576973FF000000000000000088A0
          A8FFC0F0FFFFBCEFFFFFABEBFFFF9AE7FFFF8AE2FFFF7ADBFDFF6DD1F7FF60C7
          F2FF54BCEDFF47B2E9FF3BA8E4FF2098D0FF6A818AFF00000000000000008DA5
          ADFFC0F0FFFFC0F0FFFFBCEFFFFFABEBFFFF9AE7FFFF8AE2FFFF7ADBFDFF6DD1
          F7FF60C7F2FF54BCEDFF47B2E9FF2098D0FF708890FF000000000000000090A8
          B0FFC0F0FFFFC0F0FFFFC0F0FFFFBCEFFFFFABEBFFFF9AE7FFFF8AE2FFFF7ADB
          FDFF6DD1F7FF60C7F2FF54BCEDFF2098D0FF708890FF000000000000000090A8
          B0FFC0F0FFFFC0F0FFFFC0F0FFFFC0F0FFFFBCEFFFFFABEBFFFF9AE7FFFF8AE2
          FFFF7ADBFDFF6DD1F7FF60C7F2FF54BCEDFF708890FF000000000000000090A8
          B0FF90A8B0FF90A8B0FF90A8B0FF90A8B0FF8FA7AFFF8AA2AAFF859DA5FF9932
          02FFA23E10FFA13708FF954D2DFF777877FF2831335B000000000000000090A8
          B0FFC0F0FFFFB2E8FBFF9BDCF5FF89D2F0FF859299FF1B1D1F3300000000A03B
          0CFFD47F54FF95411CC90000000000000000000000000000000000000000333C
          3F5B90A8B0FF90A8B0FF7F979FFF708890FF1B1D1F3300000000000000009D33
          03F89C421FD9A05326D0321E10430101010100000000270D0140000000000000
          0000000000000000000000000000000000000000000000000000000000007925
          00C422140A2D803514BB89471FB23B1F0E558D4A23AE7D2C05C7000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000020000042E0F024A883005CC993203E9803514BB22140A2D000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000040000
          00130000001E0000002000000020000000200000002100000021000000210000
          002200000022000000220000002300000021000000160000000500000012281E
          16CB37291EFF463A31FFBD8150FFBC7E4DFFB97949FFB67646FFB37141FFB06D
          3DFFAD6839FFAB6535FF42362EFF3D3026FF241A13CE00000015000000193B2C
          21FF685C54FF483C34FFE8C28BFFE7C088FFE6BD85FFE5BB81FFE4B87CFFE3B5
          79FFE2B276FFE2B273FF443931FF51433AFF34261DFF0000001E000000183E2F
          24FF6C6057FF4A3F37FFD9B27DFFD8B07BFFD7AE77FFD7AB74FFD6A970FFD5A6
          6DFFD4A56AFFD4A268FF473B33FF5B4F47FF37291EFF0000001D000000164031
          26FF6F645CFF4C4038FFFFFFFFFFF7F1EBFFF7F0EBFFF7F0EBFFF7EFEBFFF6EF
          EAFFF6EFEAFFF6EFE9FF463B34FF5D5249FF3A2C21FF0000001B000000144434
          29FF73675FFF4F443CFFFFFFFFFFF8F2EDFFF8F1EDFFF7F1EDFFF7F0EDFFF8F1
          EBFFF7F0EBFFF7F0ECFF4A4037FF5F534BFF3D2E23FF00000019000000124637
          2CFF776B63FF50453DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF4E433BFF61544CFF403126FF0000001700000010493A
          2FFF796E66FF50453DFF61564EFF60564EFF60554DFF5F544CFF5E544CFF5E53
          4BFF5D524AFF5C5249FF5B5149FF61554DFF433429FF000000150000000E4C3D
          32FF7C706AFF674E44FF654B42FF634A41FF61473FFF5F473EFF5C443CFF5B43
          3AFF594139FF584038FF573F37FF63574FFF46362DFF000000130000000D4E3F
          35FF80746DFF6B5248FFF4ECE6FFE9DACEFFE9D8CDFFE9D8CCFFE9D8CBFFE8D7
          CAFFF3EAE2FFF3E9E2FF5A4139FF645850FF483A2FFF000000110000000B5142
          36FF827770FF70564DFFF9F5F2FFF4EAE4FFF1E6DEFFEBDCD2FFE9D9CCFF4E41
          3DFF60534CFFF3EAE3FF5D453CFF655951FF4C3D32FF0000000F000000095344
          39FF857A73FF755A50FFFAF6F3FFF5EDE7FFF4EDE6FFF4ECE6FFEFE2DAFF493D
          38FF5A4D46FFF4EBE4FF60483FFF655A52FF4F3F34FF0000000D000000075545
          3AFF887D76FF795E54FFFAF6F4FFF5EEE9FFF5EDE7FFF4EDE7FFF4ECE6FF473A
          36FF483D36FFE9D9CDFF644C43FF675A52FF514137FF0000000B000000065748
          3DFF898079FF7C6157FFFAF7F4FFFAF6F4FFFAF6F4FFFAF6F3FFFAF6F3FFFAF5
          F2FFF5EEE9FFF4ECE6FF695046FF82776FFF534439FF00000009000000034235
          2EC058493DFF7F645AFF998178FF967F75FF937A72FF8E786DFF8B7269FF866E
          64FF82695FFF7D645BFF6E544AFF56453BFF3F332BC200000005000000000000
          0002000000030000000400000004000000040000000400000005000000050000
          0005000000050000000500000006000000060000000400000001}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000B7A293FF694731FF694731FF694731FF694731FF694731FF694731FF6947
          31FF694731FF694731FF694731FF694731FF694731FF00000000000000000000
          0000B7A293FFEEE6E1FFD4BFB2FFD4BFB2FFD4BFB2FFD4BFB2FFCFBAADFFCAB5
          A7FFC4AFA1FFBFAA9CFFBAA596FFB7A293FF694731FF00000000000000000000
          0000B7A293FFF1EAE6FFEEE6E1FFEBE2DDFFE9DED8FFE6D9D3FFE3D5CEFFE0D1
          C9FFDDCDC4FFDBC9BFFFDBC9BFFFB7A293FF694731FF00000000000000000000
          0000B7A293FFF4EEEBFFF1EAE6FFEEE6E1FFEBE2DDFFE9DED8FFE6D9D3FFE3D5
          CEFFE0D1C9FFDDCDC4FFDBC9BFFFB7A293FF694731FF00000000000000000000
          0000B7A293FFF6F2F0FFF4EEEBFFF1EAE6FFEEE6E1FFEBE2DDFFE9DED8FFE6D9
          D3FFE3D5CEFFE0D1C9FFDDCDC4FFB7A293FF694731FF00000000000000000000
          0000B7A293FFF9F6F5FFF6F2F0FFF4EEEBFFF1EAE6FFEEE6E1FFEBE2DDFFE9DE
          D8FFE6D9D3FFE3D5CEFFE0D1C9FFB7A293FF694731FF00000000000000000000
          0000B7A293FFFCFBFAFFF9F6F5FFF6F2F0FFF4EEEBFFF1EAE6FFEEE6E1FFEBE2
          DDFFE9DED8FFE6D9D3FFE3D5CEFFB7A293FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFCFBFAFFF9F6F5FFF6F2F0FFF4EEEBFFF1EAE6FFEEE6
          E1FFEBE2DDFFE9DED8FFE6D9D3FFB7A293FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFDFDFDFFFBF9F8FFF8F4F3FFF5F0EEFFF2EC
          E9FFEFE8E4FFEDE4DFFFEAE0DAFFB7A293FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFFFBF9F8FFF8F4F3FFF5F0
          EEFFF2ECE9FFEFE8E4FFEDE4DFFFB7A293FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFFFBF9F8FFF8F4
          F3FFF5F0EEFFF2ECE9FFB7A293FFB7A293FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFFFBF9
          F8FFF8F4F3FFB7A293FF694731FF694731FF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFD
          FDFFFBF9F8FFB7A293FFF3EBE6FFDBC9BFFF694731FF00000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFDFDFDFFB7A293FFDBC9BFFF694731FF100B072600000000000000000000
          0000B7A293FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFB7A293FF694731FF100B07260000000000000000000000000000
          0000B7A293FFB7A293FFB7A293FFB7A293FFB7A293FFB7A293FFB7A293FFB7A2
          93FFB7A293FFB7A293FF100B0726000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000001200000033000000330000003300000033000000330000
          0033000000330000001200000000000000000000000000000000000000000000
          0000000000121116457C2C3CC0FF2B3BBEFF2B3ABEFF2B3ABEFF2B3ABEFF2B3B
          BEFF2C3CC0FF1116457C00000012000000000000000000000000000000000000
          0012101543792F3EC3FF5F71F9FF697DFFFF697CFFFF697CFFFF697CFFFF697D
          FFFF5F71F9FF2F3EC3FF10154379000000120000000000000000000000121015
          43792F3EC2FF586BF6FF5F74FFFF5D72FEFF5E72FDFF5E73FDFF5E72FDFF5D72
          FEFF5F74FFFF586BF6FF2F3EC2FF1015437900000012000000001116457C303F
          C2FF5568F3FF586CFCFF4E64F9FF4D63F8FF5468F9FF576BF9FF5468F9FF4D63
          F8FF4E64F9FF586CFCFF5568F3FF303FC2FF1116457C000000002D3DC0FF5367
          F2FF556BFAFF4960F7FFFFFFFFFFFFFFFFFF3E56F6FF475EF6FF3E56F6FFFFFF
          FFFFFFFFFFFF4960F7FF556BFAFF5166F2FF2D3DC0FF000000002B3BBFFF6276
          FCFF4D64F6FF4259F4FFFFFFFFFFFFFFFFFFFFFFFFFF2C46F3FFFFFFFFFFFFFF
          FFFFFFFFFFFF4259F4FF4E64F6FF5F75FCFF2C3BBFFF000000002A3ABFFF7386
          FAFF495FF3FF435AF3FF6E80F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF6E80F6FF435AF3FF495FF3FF6E81FAFF2B3ABFFF000000002939BFFF8696
          FBFF425AF1FF4259F1FF354EF0FF5B70F2FFFFFFFFFFFFFFFFFFFFFFFFFF5B70
          F2FF354EF0FF4259F1FF435BF1FF7D90F9FF2A39BFFF000000002737BFFF9AA8
          FBFF3A55EFFF3953EEFF2844EDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF2844EDFF3953EEFF3B55EFFF8E9DFAFF2838BFFF000000002637BFFF9FAB
          F1FF314CEDFF2B47EBFFFFFFFFFFFFFFFFFFFFFFFFFF5369EFFFFFFFFFFFFFFF
          FFFFFFFFFFFF2C47EBFF314CEDFF9FABF1FF2737BFFF000000002838C1FF9FAB
          F1FF8091F4FF213EE8FFFFFFFFFFFFFFFFFF5D72EEFF2340E8FF5D72EEFFFFFF
          FFFFFFFFFFFF213EE8FF8091F4FF9FABF1FF2838C1FF000000001016455B2E3E
          C3FF97A5EFFF778AF2FF5B71EEFF6074EEFF2643E6FF2C48E7FF2643E6FF6074
          EEFF5B71EEFF778AF2FF97A5EFFF2E3EC3FF1016455B00000000000000000F15
          43582E3EC2FF95A2EEFF7688F0FF1E3BE4FF2340E5FF2541E5FF2340E5FF1E3B
          E4FF7688F0FF95A2EEFF2E3EC2FF0F1543580000000000000000000000000000
          00000F1543582F3DC3FF94A0EFFFADB9F8FFADB8F7FFADB9F7FFADB8F7FFADB9
          F8FF94A0EFFF2F3DC3FF0F154358000000000000000000000000000000000000
          0000000000001015455B303FC4FF4555CEFF4454CDFF4354CDFF4454CDFF4555
          CEFF303FC4FF1015455B00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00004A4F50B83939396400000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000002E2E2E534A4E
          50A5496677F348494A9B0D0D0D1200000000393939662E2E2E4F000000000000
          000000000000000000000000000000000000151515204B5256AF60849BFF4C7B
          98FF467999FF293D49FF193649E115151520565A5BAF4F50509F000000000000
          0000000000000D0D0D124C4C4C88525456B5556E7EEA3E739BFF4E6E84FF505D
          63FF5E8AA3FF242D36FF03213BFF31383D79476978DD525D64BB000000000000
          0000020202034042439F4B7E9FFF356F98FF44728CFF4D5F69FF646F74FF5971
          80FF66889FFF0E2233F13A444BD6464647A64E6572DD54636ABB000000000F0F
          0F164F5659A636678AFF346C92FF4A6374FF41484CF54F758AFF4C6570FF4472
          8BFF658192FF2D2D2D600C0C0C11444545CD577487FC606364BB000000003A3A
          3A93384651FF467EA4FF5D6970C5191919261414141D525657DB3C3E3E9F4579
          9BFF5D6970EB04040406000000003E42447C638FAAFF46464692000000005B5E
          60EE4C5155FF646E73C8373737882D2D2D5F0D0D0D121C1C1C2D526673DF5A88
          A7FF51535397000000000000000050616BE07394A8FF2C2D2D521F1F1F335359
          5CFF2E2E2EBF3D3D3D89516672FF1A3A52FF4D5154E3525659AD4E81A1FF718C
          A1FF2828284600000000383838725387A4FF657178F20909090D272727455982
          9DFF436F8AFF416F90FF2C6793FF40779BFF476979FF5A87A2FF497EA0FF6573
          7CF10E0E0E1418181824546E7FFA4D80A2FF4F5052A500000000040404064F6C
          7BEB467695FF3F5F6FFF517B95FF316C95FF66808FFF607683FF627783FF3338
          3BFA3F404094647985EF3C7298FF728995FC2424243A00000000000000004F4F
          4FBC070A0CFF020507FF48728BFF2C6692FF5084A3FF7092A4FF87ABBEFF7480
          85FF636D71FF565F63FF616E72FF515252B800000000000000001F1F1F336368
          6BFF010202FF2D3133FF316E98FF5184A3FF568BACFF6195B2FF5283A2FF355C
          79FF4D6D80FF4A5A62FF737D81FF46484A9900000000000000000C0C0C11656A
          6BEA455055FF6B8591FF4A80A4FF578EAEFF6299B8FF437B9FFF266490FF2C67
          91FF557E9AFF64859AFF6E767AD8222222370000000000000000000000002323
          233A5B6266D377A3B9FF659AB6FF578EAEFF4D83A5FF4C7EA0FF397199FF6C84
          93F33738396A1616162207070709000000000000000000000000000000000000
          00000202020337383869575C5EA8576A75FA526773FF50565AFF5B6C74F13536
          366B000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E9E9E900EBEBEB00FFFF
          FF00FFFFFF00F7F7F700D5D5D500E4E4E400FFFFFF00FFFFFF00C2C3C400BBBE
          C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D1D1D100B1B1B100F7F6
          F600FFFFFF00E2E2E2009696960090909000D1D1D100FFFFFF00C8CACC00727D
          8300DFE0E100FFFFFF00FFFFFF00FDFDFD00DADADA00C7C8C800696A6A008B8F
          9300F2F3F400FAFAFA00AAAAAA006A6A6A007E7D7D00D8D8D800FFFFFF00CDD1
          D2008A949700C8CBCC00E6E5E500AAAAAA00696C6D00828789007B8588006571
          7B009BA0A600F9F9F900EFEFEF00858585005257580083858700FFFFFF00FFFF
          FF00C8CBCD00888F92008A8F940085898C00818485003F44460067757A008B93
          960093949300CACACA00EEEEEE00D7D8D800646D710059626500FFFFFF00FFFF
          FF00E3E4E40075828900627487006E7E91007F888E0055606400546268008287
          8900ACAEB000CFCECE00D8D8D800EFEEEE00CCCECF005E696D00FFFFFF00FFFF
          FF00D7DADA0064737B005B718C004C64830050616B0051626800536166007B82
          85008E929900ECECEC00F3F3F300F9F9F900F9F9F90077828700FFFFFF00FEFE
          FE00A1AAAE0053646B00515B6500485866004D606800465C6800576C7D00B4B7
          B700DCDCDC00F8F8F900FFFFFF00FFFFFF00FFFFFF00A7AFB200FFFFFF00FFFE
          FE008A969B00475E6600545D610033444C00445960004B5F6D00586F8A006873
          790060697300D0D3D700FFFFFF00FFFFFF00FFFFFF00A9B1B400FFFFFF00FFFF
          FF00949B9F003A5059003B4D5400182E3700384C5400535D6200535F6B00727F
          85006F7A82008D949900DDDDDE00FEFEFE00EFF0F0008E9A9E00FFFFFF00FFFF
          FF00D5D5D50057666B002F48510018343F00253D460048565C00555F63007A87
          8C0087919500717B8000989D9F00F8F8F800A4ACAF00B9C0C300FFFFFF00FFFF
          FF00F2F1F0006C797E00324F5A00203F4A00233D47003C505900596B72007482
          8800818C9200818C91008B9498009EA3A6009CA5A800FBFCFC00FFFFFF00FFFF
          FF00DDDDDC005D6B7000324D58002B46510029454F00394F5800435860006071
          780075848A00768489007F888B00B3B8BA00F7F8F800FFFFFF00FFFFFF00FFFF
          FF00FBFBFB00D8DBDC00B8BFC2007C898F00364D5600344B5400395159004258
          610062717700848D9100DADBDB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00F4F4F4008D979A0043565E0028414B003145
          4E0079808300EBEBEB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDFDFC00CACECF00859297007880
          8400D3D3D300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000023000000330000003300000033000000330000
          0033000000330000002300000000000000000000000000000000000000000000
          00000000000000000000805E39BFB5844EFFB3824BFFB3814BFFB3814BFFB382
          4BFFB5844EFF805E39BF00000000000000000000000000000000000000230000
          00330000003300000033BA854BFFFFFFFCFFFFFFF5FFFFFFF4FFFFFFF4FFFFFF
          F5FFFFFFFCFFBA854BFF000000330000003300000033000000235B5B5BC08181
          81FF818182FF7F8386FFBD8546FFFFFFF7FFFFF3DAFFFFF2D9FFFFF2D9FFFFF3
          DAFFFFFFF7FFBD8546FF7F8386FF818182FF818181FF5B5B5BC0818181FFD5D2
          D1FFCBC9C9FF7D7C7CFF676768FFA8A6A8FFA4A2A4FFA3A2A3FFA3A2A3FFA4A2
          A4FFA8A6A8FF676768FF7D7C7CFFCBC9C9FFD5D2D1FF818181FF7F7F7FFFDAD7
          D6FFC2BFBEFFC8C5C4FFAFACACFFAFACABFFADAAAAFFADAAAAFFADAAAAFFADAA
          AAFFAFACABFFAFACACFFC8C5C4FFC2BFBEFFDAD7D6FF7F7F7FFF7E7E7EFFE1E0
          DFFFBDBBB9FF92908EFF7B7977FF7D7B78FF7D7B78FF7D7B78FF7D7B78FF7D7B
          78FF7D7B78FF7B7977FF92908EFFBDBBB9FFE1E0DFFF7E7E7EFF7D7D7DFFEDEB
          EBFFB8B5B3FF646261FF6B6968FF6C6A69FF6C6A69FF6C6A69FF6C6A69FF6C6A
          69FF6C6A69FF6B6968FF646261FFB8B5B3FFEDEBEBFF7D7D7DFF7C7C7DFFF9F8
          F8FFF3F4F2FF949190FF9B9897FF9C9998FF9C9998FF9C9998FF9C9998FF9C99
          98FF9C9998FF9B9897FF949190FFF3F4F2FFF9F8F8FF7C7C7DFF7C7C7DFFF4F3
          F2FFD3D1D0FF827F7EFF888685FF898686FF898685FF898685FF898685FF8986
          85FF898686FF888685FF827F7EFFD3D1D0FFF4F3F2FF7C7C7DFF7E7E7EFFFFFF
          FFFFFFFFFFFF6D6B6AFF706F6FFF6C6B6BFF6A6867FF6A6867FF6A6867FF6A68
          67FF6C6B6BFF706F6FFF6D6B6AFFFFFFFFFFFFFFFFFF7E7E7EFF5A5A5AB07F7F
          7FFF7F7F80FF808387FFBF8648FFFFFFF8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFF8FFBF8648FF808387FF7F7F80FF7F7F7FFF5A5A5AB0000000000000
          00000000000075777AFFBA8347FFFFFFF3FFFFF0DDFFFFEFDCFFFFEFDCFFFFF0
          DDFFFFFFF3FFBA8347FF75777AFF000000000000000000000000000000000000
          00000000000000000000B78349FFFFFFF4FFFFE1C0FFFFE0BFFFFFE0BFFFFFE1
          C0FFFFFFF4FFB78349FF00000000000000000000000000000000000000000000
          00000000000000000000B7854EFFFFFFFDFFFFFFF5FFFFFEF4FFFFFEF4FFFFFF
          F5FFFFFFFDFFB7854EFF00000000000000000000000000000000000000000000
          000000000000000000007F5F3BB0B5844FFFB3824BFFB3814BFFB3814BFFB382
          4BFFB5844FFF7F5F3BB000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000001E000000310000003300000033000000330000
          00310000001E0000000000000000000000000000000000000000000000000000
          00000000000E0000003367360DAAA95814F9AD5912FFAD5912FFAD5912FFA958
          14F967360DAA000000330000000E000000000000000000000000000000000000
          000E301A076BAD5A13FFCA8A48FFE0AD6EFFE6B87CFFE6B77BFFE6B87CFFE0AD
          6EFFCA8A48FFAD5A13FF301A076B0000000E000000000000000000000000301A
          076BB16019FFDAA464FFE2B173FFE0AE6FFFDEAB6AFFDDA866FFDEAB6AFFE0AE
          6FFFE2B173FFDAA464FFB16019FF301A076B00000000000000000000001EAE5B
          14FFD89F5EFFDFAC6BFFDDA968FFDCA764FFDAA25DFFFFFFFFFFDAA25DFFDCA7
          64FFDDA968FFDFAC6BFFD89F5EFFAE5B14FF0000001E0000000067370DA9C582
          3EFFDCA766FFDAA362FFD9A260FFD8A15EFFD69C56FFFFFFFFFFD69C56FFD8A1
          5EFFD9A260FFDAA362FFDCA766FFC5823EFF67370DA900000000AA5915F9D59C
          58FFD9A05CFFD79E5AFFD79E5AFFD79D58FFD59952FFD3954AFFD4984FFFD69C
          57FFD79E5AFFD79E5AFFD9A05CFFD59C58FFAA5915F900000000AF5B15FFD79F
          5AFFD49A55FFD49954FFD49954FFD49852FFD19349FFFFFFFFFFDDB07AFFD193
          4AFFD39752FFD49954FFD49A55FFD79F5AFFAF5B15FF00000000AE5B14FFDAA7
          69FFD2954DFFD2954DFFD2954DFFD1934BFFCF8F44FFEED7BDFFFFFFFFFFD9A4
          67FFD09147FFD2944CFFD2954DFFDAA769FFAE5B14FF00000000AE5A13FFDEAF
          78FFCE8E46FFCF8F47FFCD8D44FFCC8A3FFFCC893EFFCA8536FFF4E5D4FFFFFF
          FFFFCC883CFFCE8E46FFCE8E46FFDEAF78FFAE5A13FF00000000A85812F8E4BE
          96FFCC893DFFCC893EFFCA8436FFFFFFFFFFD0924DFFC88030FFD19653FFFFFF
          FFFFC88232FFCC893EFFCC893DFFE4BE96FFA85812F80000000066360C95D5A6
          7BFFD9A86FFFC88334FFC57E2CFFFFFFFFFFEDD9C1FFC1741DFFEDD8BFFFFFFF
          FFFFC57D2BFFC88334FFD9A86FFFD5A67BFF66360C950000000000000000B15E
          19FFE8CBAEFFD7A167FFC37824FFDBAF7FFFFFFFFFFFFFFFFFFFFFFFFFFFDBAF
          7FFFC37824FFD7A167FFE8CBAEFFB15E19FF000000000000000000000000301A
          0646B76C2CFFE4C3A0FFE0B98DFFCD8E48FFC0741FFFBF6E15FFC0741FFFCD8E
          48FFE0B98DFFE4C3A0FFB76C2CFF301A06460000000000000000000000000000
          0000301A0646B15E1AFFCC9360FFE2C09CFFE9CEB0FFE9CDAFFFE9CEB0FFE2C0
          9CFFCC9360FFB15E1AFF301A0646000000000000000000000000000000000000
          0000000000000000000066360C95A95610F7AD5810FFAD580FFFAD5810FFA956
          10F766360C950000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000020000
          000A0000000F0000001000000010000000100000001100000011000000110000
          001100000011000000100000000B000000030000000000000000000000094633
          2CC160453BFF644A41FFB87D4EFFB97A4AFFB47444FFB06C3DFFA76436FFA764
          36FF583D36FF5B3E37FF3B2821C20000000A00000000000000000000000D6F53
          47FF947869FF6A4F46FFD8B07BFFD7AE77FFD7AB74FFD6A970FFD5A66DFFD4A5
          6AFF5D413AFF684B41FF543931FF0000000E00000000000000000000000C7357
          4AFF987D6EFF70564BFFFFFFFFFFF6EFEAFFF6EFE9FFF6EEE9FFF5EEE9FFF6EE
          E8FF62473FFF715348FF573B33FF0000000F00000000000000000000000B785C
          4EFF9D8273FF765C50FFFFFFFFFFF7F0EBFFF7F0EBFFF7EFEBFFF6EFEAFFF6EF
          EAFF684E44FF72554BFF593E35FF0000000E00000000000000000000000A7C60
          50FFA28777FF7B6154FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF6E5349FF74574CFF5C4138FF0000000C0000000000000000000000097F63
          54FFA78E7DFF977A6AFF967969FF957967FF82675BFF695044FF6E554BFF6E55
          4BFF6E534AFF6C5248FF583F35FF000000200000001100000005000000088367
          57FFAB9382FF634A41FF614740FF5E463DFF574139FF805E52FF805D51FF7F5C
          51FF7F5C50FF7E5B4FFF7E5A4EFFA27262FFA07061FF0000001000000007866A
          59FFAF9788FF674E44FFF3EAE4FFE7D5C8FFDAC8BBFFAA7D6DFFFDFCFAFFF7F0
          E9FFF7F0E8FFF7EFE7FFF6EFE7FFF6EEE6FFA37363FF0000001200000006886D
          5CFFB39C8CFF6B5248FFF4ECE6FFE9D9CDFFDDCDC0FFAD8070FFFEFDFCFFF7F2
          EAFFF8F1E9FFF7F0E9FFF6F0E8FFF6EFE7FFA47566FF00000010000000058B70
          5EFFB7A091FF70564DFFF6EFEAFFECDDD3FFE1D1C8FFAF8273FFFEFEFDFFF8F3
          ECFFF8F2EBFFF7F1EAFFF7F1E9FFF7F0E8FFA77869FF0000000E000000048E72
          60FFBBA595FF755A50FFF7F1ECFFF6F0EBFFECE6E1FFB18576FFFFFFFEFFF9F3
          EEFFF9F3EDFFF9F2ECFFF8F2EBFFF7F1EAFFA97B6BFF0000000C000000026A56
          49BF8F7361FF795E54FF765D52FF745A50FF6F564CFFB38879FFFFFFFFFFF9F5
          EEFFF9F4EEFFF9F3EDFFF8F3ECFFF8F2EBFFAB7E6DFF0000000A000000010000
          00020000000300000003000000030000000400000009B58A7BFFFFFFFFFFFAF5
          F0FFF9F5EFFFF9F5EFFFF9F4EEFFF9F3EDFFAD8071FF00000008000000000000
          00000000000000000000000000000000000000000004B88D7EFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAF8273FF00000007000000000000
          00000000000000000000000000000000000000000002BA8F80FFB88D7FFFB78C
          7EFFB68B7CFFB68A7AFFB48979FFB38777FFB28576FF00000004}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000E4E4E300D5D5
          D300D5D5D300CBCBC900CBCBC900CBCBC900CBCBC900CBCBC900C3C3C300CBCB
          C900CBCBC900D5D5D300D5D5D300DFDFDC00F2F2F200FFFFFF00D5D5D300C3C3
          C300C3C3C300BBBBBC00BBBBBC00BBBBBC00BBBBBC00BBBBBC00BBBBBC00C3C3
          C300C3C3C300CBCBC900EBEBEB00F2F2F200FFFFFF00FFFFFF00D5D5D300C3C3
          C300C3C3C300C3C3C300C3C3C300CBCBC900CBCBC900CBCBC900D5D5D3006E6E
          A300BBBBBC00DFDFDC00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DFDFDC00C3C3
          C300C3C3C300C3C3C300CBCBC9006E6EA3006E6EA3006E6EA3006E6EA3001111
          A3000C0C95007373CD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DFDFDC00CBCB
          C900CBCBC900CBCBC900D5D5D3001111A3000C0C95000C0C95000C0C95000C0C
          95000C0C95000C0C95002D2DB000F2F2F200FFFFFF00FFFFFF00E4E4E300D5D5
          D300D5D5D300D5D5D300DFDFDC002D2DB0001111A3001111A3001111A3001111
          A3001111A3001111A3001111A3001111A300EBEBEB00FFFFFF00EBEBEB00D5D5
          D300D5D5D300D5D5D300DFDFDC002D2DB0001111A3001111A3001111A3001111
          A3001111A3001111A3002D2DB000DFDFDC00FFFFFF00FFFFFF00EBEBEB00DFDF
          DC00DFDFDC00DFDFDC00DFDFDC007373CD007373CD007373CD007373CD002D2D
          B0001111A3007373CD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EBEBEB00DFDF
          DC00DFDFDC00DFDFDC00DFDFDC00E4E4E300E4E4E300E4E4E300F2F2F2007373
          CD00ADADDF00F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00F2F2F200E4E4
          E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300EBEB
          EB00E4E4E300F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00F2F2F200E4E4
          E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4E300E4E4
          E300E4E4E300F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EBEB
          EB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEB
          EB00EBEBEB00F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EBEB
          EB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00F2F2
          F200F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EBEB
          EB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00F2F2F2006E6E
          A30065656500CBCBC900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EBEB
          EB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00EBEBEB00FFFFFF006565
          6500BBBBBC00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F2F2
          F200F2F2F200F2F2F200F2F2F200F2F2F200F2F2F200F2F2F200FFFFFF00BBBB
          BC00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = 15000803
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000003010004000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000002010002974825ABEC83
          51FEA07353A50000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000000A04020CAD52
          2BCAEB723EFFA07353A500000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000001E0E
          0726D06436F1EB7441FFA07353A5060402060000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00006B341C87E7703DFFF19E6DFE5C4E3D5C000000000000000000000000E078
          40FFC06840FFC06840FFC06840FFB05830FF512A177F0B05030E000000000000
          00001D0F0827B95E33FCED8553FFA07353A5000000000000000000000000E078
          40FFDC5F27FFE07030FFE27D4EFF512A177F0000000000000000000000000000
          00000904020EA8562FF5EA7A47FFD89B70DF000000000000000000000000E078
          40FFE07030FFF09060FFE98758FFC36D45EA1A0D072A00000000000000000000
          000005030109A6562FF3E97644FFD89B70DF000000000000000000000000E078
          40FFE88D60FFF0A070FFEC9466FFE38355FF914D2BDE05020107000000000000
          00001109041BAE5A32F9E97846FFD89B70DF000000000000000000000000E078
          40FFE68E63FEE99568FEF0A070FFEC9466FFD5794DFF8F4B2AD8190E081D0000
          0001512A177FBD6339FFE97A49FFD89B70DF000000000000000000000000E078
          40FFA07353A5A68A6BA9ECA174FEF0A070FFEC9466FFD67A4EFFA95934F89E53
          2FECB76139FDE87F4EFFEA8251FFA07353A5000000000000000000000000A073
          53A501010001060504069A80649CEFA97CFEF0A070FFEC9466FFEC9466FFE985
          56FFE98353FFE98151FFF0A978FD1A0D072A0000000000000000000000000000
          000000000000000000000201010277634D79ECB285F6EB9466FFE98A5CFFE987
          59FFEA895AFFEFA172FEA07353A5030201030000000000000000000000000000
          00000000000000000000000000000000000030281F308C765C8DB0906FB4B391
          6FB7A78768AB5C4E3D5C05040206000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00CFCFCF00ACACAC00CCCCCC00D8E9EC00D8E9EC00CCCC
          CC00ACACAC00CFCFCF00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8A57400DD761400E0AD7C00B5B5B500CECECE00D4A17000DD76
          1400E0AD7C00B8B8B800D6D6D600D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00E8B48300DD761400D2D2D200DD761400E0AC7B00C8946300DD761400D8E9
          EC00DD761400D7A37200D5D5D500D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00E8B58400D9A67500BCBCBC00D8E9EC00DD761400DD761400D8E9EC00D8E9
          EC00E0AD7C00CB986700D8D8D800D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00EAB78600DD761400D7D7D700BABABA00DEAB7A00C7936200B3B3B300D8E9
          EC00DD761400D8A57400D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00E9B68500DD761400D5D5D500DD761400DD761400C7C7C700DD76
          1400D7A47300D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00E9B68500DD761400DEAB7A00C4905F00DD761400DEAB
          7A00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC007F7F7F007F7F7F00ADADAD00CFCF
          CF00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00D8E9EC00B5B5B5007F7F7F007F7F7F00A3A3A300B8B8
          B800D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00D8E9EC007F7F7F009A9A9A00B2B2B2007F7F7F00B9B9
          B900D4D4D400D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC00B5B5B5007F7F7F00D3D3D300D8E9EC007F7F7F00A7A7
          A700BABABA00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00D8E9EC007F7F7F009B9B9B00D8E9EC00D8E9EC00BABABA007F7F
          7F00BBBBBB00D5D5D500D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC00B8B8B8007F7F7F00D6D6D600D8E9EC00D8E9EC00D8E9EC007F7F
          7F00A9A9A900BFBFBF00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC007F7F7F00A0A0A000D8E9EC00D8E9EC00D8E9EC00D8E9EC00BBBB
          BB007F7F7F00C4C4C400D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC00D8E9EC007F7F7F00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9
          EC007F7F7F00D8E9EC00D8E9EC00D8E9EC00D8E9EC00D8E9EC00}
        MaskColor = 14215660
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00E2E2E200D7D7D700D4D4D400D4D4D400D4D4
          D400D4D4D400D4D4D400D7D7D700E1E1E100EAEAEA00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00E7E7E7008E8E8E00818181007C7C7C007C7C7C007C7C
          7C007C7C7C007C7C7C008181810089898900E1E1E100FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00E77E3400E9853B00E9853C00E9853C00E9853C00E985
          3B00E7823800E7813600E77E340081818100D7D7D700FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00D9D9D900E77D3100E2E2E200E2E2E200E2E2E200E2E2E200E2E2
          E200E2E2E200DFDFDF00E77D31007C7C7C00D4D4D400FFFFFF00FFFFFF00FFFF
          FF009494940085858500E67B2E00E2E2E200EEA46700EEA46700EEA46700EEA4
          6700EEA46700E1E1E100E67B2E007C7C7C00D4D4D400FFFFFF00FFFFFF00E77E
          3400E9853B00E9853C00E6772A00E1E1E100E2E2E200E2E2E200E2E2E200E1E1
          E100DFDFDF00DEDEDE00E6772A007C7C7C00D4D4D400FFFFFF00FFFFFF00E77D
          3100E2E2E200E2E2E200E6742600E1E1E100EEA46700EEA46700EEA46700EEA4
          6700EEA46700DCDCDC00E67426007C7C7C00D4D4D400FFFFFF00FFFFFF00E67B
          2E00E2E2E200EEA46700E6772A00E6E6E600E6E6E600E6E6E600E6E6E600E4E4
          E400E2E2E200DFDFDF00E6772A007D7D7D00D6D6D600FFFFFF00FFFFFF00E677
          2A00E1E1E100E2E2E200E67C3000E7E7E700EEA46700EEA46700EEA46700E6E6
          E600E4E4E400E1E1E100E67C300084848400DEDEDE00FFFFFF00FFFFFF00E674
          2600E1E1E100EEA46700E7894100ECECEC00ECECEC00ECECEC00ECECEC00E989
          4200E9894200E7894100E7894100C5C5C500E9E9E900FFFFFF00FFFFFF00E677
          2A00E6E6E600E6E6E600E9914C00EFEFEF00EEA46700EEA46700EFEFEF00EA91
          4D00F1CCB100E9914C00CBB7A400E7E7E700FFFFFF00FFFFFF00FFFFFF00E67C
          3000E7E7E700EEA46700EC995800F6F6F600F6F6F600F6F6F600F6F6F600EC9A
          5800EC9A5800CBB7A400E7E7E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00E789
          4100ECECEC00ECECEC00EEA46700EEA46700EEA46700EEA46700EEA46700EEA4
          6700CBB7A400E7E7E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E991
          4C00EFEFEF00EEA46700EEA46700EFEFEF00EA914D00F1CCB100E9914C00CBB7
          A400E7E7E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EC99
          5800F6F6F600F6F6F600F6F6F600F6F6F600EC9A5800EC9A5800CEB8A600E7E7
          E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EEA4
          6700EEA46700EEA46700EEA46700EEA46700EEA46700E1CBB700E9E9E900FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000002F000000330000003300000033000000330000
          0033000000330000003300000033000000330000003300000030000000000000
          00000000000000000000AB7A17EFB67E0EFFB47B09FFB47A08FFB47B08FFB47B
          08FFB47B08FFB47B08FFB47B08FFB47B09FFB67E0EFFAE7B18F2000000000000
          00000000002200000033B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000000000
          00007D5912BCB88114FFB37905FFFFFFFFFFFFFFFFFFFFFFFFFFD7C0A5FFFFFF
          FFFFD8C0A6FFFFFFFFFFD7BFA5FFFFFFFFFFFFFFFFFFB47B09FF0000002F0000
          0033B88114FFFFFFFFFFB17500FFFFFFFFFFD5BA9BFFD6BC9EFFD8BFA2FFD8BF
          A2FFD9C0A3FFD8BFA2FFD8BFA1FFD6BC9DFFFFFFFFFFB47B08FFAB7A17EFB780
          12FFB57C0BFFFFFFFFFFB07300FFFFFFFFFFFFFFF5FFFFFFF9FFD9BE9DFFFFFF
          FDFFD9BE9DFFFFFFFDFFD8BD9CFFFFFFF8FFFFFFFFFFB47B08FFB67F11FFFFFF
          FFFFB27702FFFFFFFFFFB07300FFFFFFFFFFD5B691FFD7B995FFD9BC99FFD9BC
          99FFD9BD99FFD9BC99FFD9BC98FFD7B893FFFFFFFFFFB47B09FFB57D0CFFFFFF
          FFFFB17500FFFFFFFFFFB07300FFFFFFFFFFFFFAE2FFFFFDE7FFD9BA92FFFFFF
          EBFFD9BA93FFFFFFEBFFD8B991FFFFFCE5FFFFFFFFFFB47B08FFB57C0BFFFFFF
          FFFFB07400FFFFFFFFFFB07300FFFFFFFFFFDDB280FFDFB685FFDEB78AFFDEB7
          8AFFDEB88BFFDEB78AFFDDB789FFDBB383FFFFFFFFFFB57B08FFB57C0BFFFFFF
          FFFFB07400FFFFFFFFFFB17300FFFFFFFFFF44C4FFFF46C6FFFFE2B57FFF43C7
          FFFFE1B680FF43C7FFFFE1B57EFF40C4FFFFFFFFFFFFB57C09FFB57C0BFFFFFF
          FFFFB07400FFFFFFFFFFB27300FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFFB57C0BFFFFFF
          FFFFB07200FFFFFFFFFF8E8E54FFB17100FFB07100FFB07100FFAF7100FFAF71
          00FFAF7100FFB07100FFB17400FFB47903FFB67E0DFFAD7B17EEB57C0AFFFFFF
          FFFFB17200FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFB77F11FF0000000000000000B57C0AFFFFFF
          FFFF869265FFB17100FFAF7100FFAF7100FFAF7200FFAF7200FFAF7200FFAF72
          00FFB17400FFB37A06FFB67F10FF7E5A11AE0000000000000000B67E0FFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFB77F11FF00000000000000000000000000000000AD7C17EFB67E
          0FFFB57C0AFFB57C0AFFB57C0BFFB57C0BFFB57C0BFFB57C0BFFB57C0BFFB57D
          0CFFB77F11FFAD7B17EE00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000030000000C00000010000000110000
          0011000000120000001200000013000000130000001000000004000000000000
          00000000000000000000000000000000000BA97563FFA87462FFA77261FFA571
          5FFFA5705EFFA36F5DFFA36D5CFFA26D5BFFA26C5AFF0000000F000000000000
          00000000000000000000000000000000000DAB7866FFFDFBF8FFF7EFE8FFF6EF
          E6FFF6EEE6FFF5EEE5FFF5EDE4FFF5EDE4FFA36D5CFF00000013000000000000
          0000265080B7336CB1FF326BB0FF2E63A6FFAD7C6AFFFDFCFAFFF7F0E9FFF7F0
          E8FFF7EFE7FFF6EFE7FFF6EEE6FFF5EEE5FFA46F5DFF00000012000000000000
          00003976B8FF91D2F4FF66BEEEFF60B5E4FFB07F6DFFFEFDFCFFF7F2EAFFF8F1
          E9FFF7F0E9FFF6F0E8FFF6EFE7FFF6EFE6FFA67260FF00000011000000000000
          00003F7DBCFF9AD6F5FF6CC3F0FF66B8E5FFB28070FFFEFEFDFFF8F3ECFFF8F2
          EBFFF7F1EAFFF7F1E9FFF7F0E8FFF7EFE8FFA87563FF00000010000000000000
          00004384C1FFA4DBF6FF73C7F1FF6CBEE8FFB48473FFFFFFFEFFF9F3EEFFF9F3
          EDFFF9F2ECFFF8F2EBFFF7F1EAFFF7F0E9FFAB7766FF0000000F000000000000
          0000488BC5FFADE1F8FF7ACCF2FF73C3E9FFB68676FFFFFFFFFFF9F5EEFFF9F4
          EEFFF9F3EDFFF8F3ECFFF8F2EBFFF7F2EBFFAC7A6AFF0000000E000000000000
          00004C92CAFFB6E6FAFF81D2F4FF7AC9EBFFB88878FFFFFFFFFFFAF5F0FFF9F5
          EFFFF9F5EFFFF9F4EEFFF9F3EDFFF9F3ECFFAF7E6CFF0000000D000000000000
          00005098CDFFBEE9FAFF88D6F6FF81CEEEFFBB8B7BFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFCFAFFB1816FFF0000000C000000000000
          0000539DD1FFC5EDFBFF8FDBF7FF89D5F2FFBD8D7DFFBB8C7CFFBA8B7BFFB989
          79FFB98977FFB78876FFB68674FFB58373FFB38371FF00000009000000000000
          000056A1D4FFCBF0FCFF95E0F8FF82CBE9FF72B7D9FF71B7D9FF70B7DAFF70B8
          DBFF6FB7DBFF4385BBFF00000009000000090000000800000002000000000000
          000058A5D7FFCBEDF8FF73B2D0FF5792B7FF5893B7FF5995BAFF5B99BDFF62A3
          C9FF69AFD4FF4184BBFF00000000000000000000000000000000000000000000
          000059A8D9FFBCDBE7FF8E7875FF9B7061FF946A5BFF8F6456FF885D50FF7B65
          63FF97BCD3FF488EC4FF00000000000000000000000000000000000000000000
          0000437EA2BD4A90BFFFB48E7FFFF3EDE7FFDEC9B8FFDDC8B5FFDBC4B2FF9770
          60FF3B7BAEFF40799EBD00000000000000000000000000000000000000000000
          00000000000000000000876B60BDB69181FFB69080FFB58E7FFFB28C7DFF7D60
          54BD000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000001000000040000000B000000130000001A0000001E000000200000
          00200000001B0000000D00000003000000000000000000000000000000000000
          00030000000F00070A2C00374F7F005C83B70078ACDD0094D4FD0096D7FF0096
          D7FF0096D7FF00587FA90000000B000000000000000000000000000000000000
          000F005478A5059BDBFF12A8E4FF1BB2EBFF23BAF0FF2BC2F6FF2CC3F6FF2CC3
          F6FF2CC3F6FF0DA5E2FF002D405A00000000000000000000000000000000005B
          829F3CB8E9FF2CC4F7FF2EC6F8FF2EC6F7FF29BCF6FF26B6F5FF25B3F5FF25B3
          F5FF2DC3F7FF20B9F0FF006D9CBC00000000000000000000000000000000009D
          E1FF99E4FCFF81DEFBFF31BBF7FF28B7F7FF28B7F7FF28B7F7FF28B7F7FF28B7
          F7FF2BBDF8FF2DC4F6FF008CC9E700000000000000000000000000000000005E
          869724B0EBFF8FE1FBFF6FD5FBFF2ABBF8FF2ABBF8FF2ABBF8FF2ABBF8FF2ABB
          F8FF2BBDF8FF34CBFAFF009CE0FA000000000000000000000000000000000000
          0000005478863DBDF1FF9AE7FDFF3AC5FAFF2FC3FAFF39CAFBFF4FD5FBFF60D9
          FCFF66C4F3FF5CA0E5FF02A4E9FF000203030000000000000000000000000000
          00000002030302A6ECFF8BE1FCFF90E6FEFF78C6F3FF4A89DDFF224FC8FF081F
          B7FF010BB6FF010DC0FF013D9AC1000000000000000000000000000000000000
          000000000000004F70790D73DAFF052EBFFF040DB9FF0915C7FF0C1AD2FF0D1D
          DAFF0E1DDAFF0B18D1FF020792D2000000000000000000000000000000000000
          00000000000000000000020A92CD2536E2FF2332E2FF1F2DDEFF1F2DDEFF1F2D
          DEFF111BCAFF0308B5FF01034A69000000000000000000000000000000000000
          000000000000000000000202425D151BC4FF171EC6FF2E3BDAFF3B4DE8FF3443
          E6FF1C24CEFF02035A7E00000000000000000000000000000000000000000000
          00000000000000000000000000000201293902023F572A32CEFF6179F3FF4253
          E9FF3744DFFF050487BA00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000100161E1817C2FF88A3F9FF4F60
          F1FF596BF2FF0803B0F000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000070188B77B8CEBFF8095
          FCFF6A7CF7FF0C05BFFF00000406000000000000000000000000000000000000
          0000000000000000000000000000000000000000000003003B4E08018AB70B01
          C0FF0A01B5F00601668700000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000003300000000000000000000000000000000000000000000
          0000000000000000000700000033000000330000003300000007000000000000
          000000000000BB8747FF00000033000000000000000000000000000000330000
          0033000000001A130A47BB8747FFBB8747FFBB8747FF1A130A49000000330000
          003300000033B98545FFB78444FF000000330000000000000000BB8747FFBB87
          47FF000000009B703ADBBB8747FF00000000BB8747FF9C713BDDB98546FFB884
          44FFB68242FFB48041FFF1B665FFC38E4BFF0000003300000000BB8747FFBB87
          47FF00000000BB8747FFBB8747FF00000000BB8747FFBB8747FFB88445FFFFCB
          85FFFDC882FFFBC680FFF8C37EFFFCC781FFB68343FF00000000000000000000
          000000000000BB8747FFBB8747FF00000000BB8747FFBB8747FFB98546FFB884
          44FFB68242FFB37F3FFFFFD69BFFC49152FF0000000000000000000000000000
          000000000000BB8747FFBB8747FF00000005BB8747FFBB8747FF000000000000
          000000000000B78342FFC89456FF000000000000000000000000000000000000
          0000000000009C703CD6BB8747FF130E0748BB8747FF9C703CD6000000000000
          000000000000B98544FF00000000000000000000000000000000000000000000
          00000000000019120922BB8747FFBB8747FFBB8747FF19120922000000000000
          0000000000330000003300000000000000070000003300000033000000330000
          0007000000000000000700000033000000330000003300000007000000000000
          0000BB8747FFBB8746FF0000000018110946BA8646FFBB8747FFBB8747FF1A13
          0A470000000019120A46BB8747FFBB8747FFBB8747FF1A130A48000000000000
          0000BB8747FFBB8747FF000000009B703ADBBB8747FF00000000BB8747FF9B70
          3ADB000000009B703ADBBB8747FF00000000BB8747FF9C713BDD000000000000
          0000000000000000000000000000BB8747FFBB8747FF00000000BB8747FFBB87
          47FF00000000BB8747FFBB8747FF00000000BB8747FFBB8747FF000000000000
          0000000000000000000000000000BB8747FFBB8747FF00000000BB8747FFBB87
          47FF00000000BB8747FFBB8747FF00000000BB8747FFBB8747FF000000000000
          0000000000000000000000000000BB8747FFBB8747FF00000005BB8747FFBB87
          47FF00000000BB8747FFBB8747FF00000005BB8747FFBB8747FF000000000000
          00000000000000000000000000009C703CD6BB8747FF130E0748BB8747FF9A6F
          3BD3000000009A6F3BD3BB8747FF130E0748BB8747FF9C703CD6000000000000
          00000000000000000000000000001A130A24BB8747FFBB8747FFBB8747FF1A13
          0A23000000001A130A23BB8747FFBB8747FFBB8747FF1A130A24}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000020000000500000005000000020000000000000000000000030000
          000B0000000F0000001000000011000000110000000E00000004000000000000
          0001000000080728167A041F0D6F000000080000000100000000000000081315
          84D816199CFF141699FF131497FF111294FF0C0C6FD800000009000000000000
          000504160C4C1B774CFB14673AF9021007430000000500000001000000050D0E
          4B7D191CA1FF0708336B000000140000000E0000000B00000003000000030208
          052416633DEA34BD8DFF2FB885FF0F532AE50106032200000003000000010000
          0009121569A6161897F5030419390000000400000000000000000001010E0F4E
          30C437B385FF39CA98FF39C998FF2DAA79FF0B401FC20001000F000000020000
          000101010410171B87CC151788DC0101091C00000003000000000C39238F46A8
          83FF72DFBDFF58D7AEFF3FCE9EFF57D5ADFF3F9C75FF082D168E000000060000
          00000000000203030F1E1C209DE6111571B80000000A0000000123855CFF2184
          5CFF20835BFF63DBB5FF45D1A4FF1A774EFF19764DFF18754CFF000000090000
          00040000000500000008080925411F24AAF70D10528800000005000000060000
          000F23895FFF6CE0BDFF4CD6A9FF1C7B53FF000000110000000800000004242A
          A4D32932C5FF2830C1FF2931C3FF282EBDFF191F96DD00000005000000000000
          0007278F66FF75E4C3FF53DAB0FF1E8057FF0000000900000000000000020000
          000A0000000A00000005000000060000000C0000000D00000004000000000000
          00062A946CFF7FE8CAFF59DEB6FF20865DFF0000000800000000000000066D36
          28D64E261D9F000000060000000753281EAF693225D700000008000000000000
          00062C9971FF88ECD1FF60E2BCFF238A61FF0000000700000000000000054A27
          1D91763B2CE40000001102010115834334EF4522199400000007000000000000
          00052F9E76FF90EFD5FF65E6C1FF258F66FF0000000600000000000000022313
          0E46894634FF884534FF914D3AFF8B4736FF1F0F0B4900000003000000000000
          000431A279FF97F1DAFF6AE8C6FF27946BFF0000000500000000000000000201
          010A8C4D3CEE311B15613D211977814332EF0201010C00000001000000000000
          000333A57DFF9DF3DDFF6DEBC9FF28996FFF0000000400000000000000000000
          00035F3327A9562E239D68392CB75A2E23AB0000000500000000000000000000
          000235A880FFC3F8ECFFC3F8ECFF2B9E72FF0000000300000000000000000000
          0001361E175F804837DA8B4D3BEE321A14600000000200000000000000000000
          0001297F61BE36AA82FF36AA82FF287D5FBF0000000200000000000000000000
          00000B0605159B5944FC94523EFC0A0504160000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00C3DEE0008BC3C200DAF4F200FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00DCF5F50071C9C8003FB8B10068B6B400CDE2E400EDFFFF00F1FF
          FF00E1F5F90087D2C8002FAF94006CC6BA00E9F5F600FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00B0E0DE003DACA30035BBAB0042C8BD004AB5B300A0D6D500C2E8
          E60060C3B8003DBDA60044D6C60033BBA500C8EAE400FFFFFF00FFFFFF00FFFF
          FF00F9FAFC008CC8C800209B8F001A9D83003DC4AB004ED9CB0051B0AC004EA3
          970033B4A30036BEAF003FD4C20045C4B600D0EAE900FFFFFF00FFFFFF00FFFF
          FF00FDFFFF00A4D9D8002DA39700128C7B002595850029A6A70030AAAC002388
          7500258D860045C7B9004FD9CB0071C8C200DEF1F000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00E6F8F80075C0C0001F87830019877B001A9D990034C7C800349F
          9E0024A9AE0059E5D9004BBFB60069B6B300B5E0DE00F8FCFC00FFFFFF00F9FC
          FD00C4E4E400DAE9E900B6E2DE00258C8F0010868F003FB4B50046A6A5003D98
          9D0045BFC60044C6C40048CBC60042BFAC0037B199007CCBC400F0FDFD00A3D9
          D40051BBAC003FB49E0039958A001D8585002398980023857C0019675900246F
          650035959A001F99A1003BC2BE004FDACD0057E1D6003FBAA400AADEDC0051BF
          AE003CC2A70034B19400168B7C000C8A8E00239F9A001D757200156F60002174
          6A003F9DA10031AFB40043C8C00054DDD00058E0D6003FB9A40079C6C4003AB5
          A5003EB69E003BB39B001C8E8200178E880036AAA7002D838200278880002F8F
          88002EA1A50025A7B40048D2D0005EE6DE003EBBA600B6E2DE0095D2D20040B4
          A6002EA991003BBBA10028AA94001C8C82001D9597003099A30039989F00399F
          9E0032B1AA0040A6AA0051BBAC0032B09700A9E0DA00FFFFFF00DEF6F500A6DE
          DA007BC6BE005EBAAB004AB09F0055ABA40031989E00118C9300118E990017B0
          B80040C3BA0087C4C200FCFCFD00F2FDFD00F9FDFD00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00F2FCFC00E2F6F800D6E9EA0058B3AB0018938600128A82002EC8
          C2004DCFBF0085C9C000FAFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FAFFFF00F1FAFC0076CCC20027A18E002B9E8A0055D5
          C4004FD0BE00A5D4CF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FAFFFF00C8EAE9004EAEA300279F860040CF
          B30055BDAB00E0F1F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A5DAD50043AB990063BF
          B100D1EAEA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000001E0000003300000033000000330000001E00000000000000300000
          0033000000330000003300000033000000330000003300000033000000330000
          0033005330A9008D4CFF008B4AFF008C4CFF00552FAC0000001EAE7B18F2B67E
          0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A08FFB67B08FFC47D0AFF5188
          33FF00995DFF00BB86FF77E0C6FF00BB86FF00995CFF00552FACB67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0086
          43FF00C08DFF00BC83FFFFFFFFFF00BC83FF00C18DFF008C4CFFB47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFD6BDA2FFFFFFFFFFFFFFFFFFEEC6B1FF0083
          3DFF73E6CCFFFFFFFFFFFFFFFFFFFFFFFFFF77E7CEFF008B49FFB47A08FFFFFF
          FFFFFFFFFDFFFFFFFDFFFFFFFFFFD7BEA0FFFFFFFFFFFFFFFFFFEEC6AEFF0083
          3DFF00CB96FF00C88FFFFFFFFFFF00C990FF00CD99FF008C4BFFB47B08FFFFFF
          FFFFD4B999FFD5BA9AFFD6BC9EFFD8BFA1FFD7BD9EFFD9BD9FFFE6C3A8FF569E
          6DFF009C5CFF00D29BFF73EDD4FF00D39EFF00A368FF00522E94B47B08FFFFFF
          FFFFFFFDF2FFFFFEF3FFFFFFF7FFD7BB9AFFFFFFF8FFFFFFF8FFDCBD9DFFFFFF
          FFFF68BB90FF00813BFF00813BFF008441FF558631FF00000000B47B08FFFFFF
          FFFFFFFBEBFFFFFCECFFFFFFF0FFD7BA96FFFFFFF1FFFFFFF1FFD8BA97FFFFFF
          F4FFFFFFF8FFECBF9FFFFFFFFBFFFFFFFFFFC67D09FF00000000B47B08FFFFFF
          FFFFD4B38CFFD5B58FFFD7B892FFD8BA95FFD7B893FFD7B893FFD8BA95FFD7B8
          93FFD9B994FFDBBA96FFDAB892FFFFFFFFFFB77B09FF00000000B47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFBE5FFD6B78FFFFFFBE6FFFFFBE6FFD6B78FFFFFFB
          E6FFFFFBE6FFD5B78EFFFFFAE3FFFFFFFFFFB47B08FF00000000B47B08FFFFFF
          FFFFFFF5D7FFFFF6D9FFFFF9DEFFD7B58BFFFFF9DFFFFFF9DFFFD7B58BFFFFF9
          DFFFFFF9DFFFD7B58AFFFFF8DBFFFFFFFFFFB47B08FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFDFB6
          83FFDFB683FFDDB684FFDBB37FFFFFFFFFFFB57B09FF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C7
          FFFF46C7FFFFE1B47EFF40C4FFFFFFFFFFFFB57C09FF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000AD7C17EFB67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67C09FFB67E0EFFAD7C17EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
          00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF0000000000000000000000000000000000FFFFFF00000000000000
          0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
          00000000000000000000FFFFFF00FFFFFF0000000000FFFFFF00000000000000
          0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
          0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00000000000000
          0000000000000000000000000000FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
          00000000000000000000000000000000000000000000FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
          00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF000020
          4000002040000020400000204000002040000020400000204000002040000020
          4000002040000020400000204000002040000020400000204000FFFFFF000020
          40000020800040C0E00040A0E00040C0E00040E0C00040E0E00040A0E00040E0
          C00040A0E00040A0E00040E0C00040C0E00040C0E00000204000FFFFFF000020
          400040E0E00040A0E00040A0E00040E0C0000020A00040E0C00040E0E0000020
          600040E0C00040C0E00040E0C0000020800040E0C00000204000FFFFFF000020
          400040A0E0000020400040C0E00040C0E00040C0E00040C0E00040E0E00040A0
          E00040E0C00040C0E00040E0E00040A0E00040C0E00000204000FFFFFF000020
          400040A0E00040C0E00040C0E00040C0E00040C0E00040C0E00040E0E00040A0
          E0000020800040A0E00040E0E00040A0E00040C0E00000204000FFFFFF000020
          40000020600040C0E00040C0E0000020600040A0E00040C0E0000020800040C0
          E00040A0E00040E0C00040E0E0000020600040C0E00000204000FFFFFF000020
          400040C0E00040A0E00040A0E00040C0E00040A0E00040C0E00040C0E00040C0
          E00040A0E00040C0E00040C0E00040C0E00040E0E00000204000FFFFFF000020
          400040C0E00040A0E0000020400040C0E00040C0E00040C0E00040A0E00040C0
          E00040C0E0000020600040A0E00040A0E00040C0E00000204000FFFFFF000020
          400040A0E00040A0E00040E0E00040E0E0000020600040C0E00040E0E00040A0
          E00040E0E00040C0E00040C0E00040A0E00040A0E00000204000FFFFFF000020
          40000020800040A0E00040A0E00040A0E00040A0E0000020600040C0E0000020
          A00040A0E00040E0E0000020800040E0C00040A0E00000204000FFFFFF000020
          400040A0E00040C0E00040C0E0000020800040C0E00040E0E00040C0E00040E0
          E00040A0E00040E0E00040C0E00040A0E00040E0C00000204000FFFFFF000020
          400040A0E00040A0E00040C0E00040C0E00040C0E0000020A00040C0E00040A0
          E0000020400040E0C00040C0E00040C0E00040C0E00000204000FFFFFF000020
          40000020800040A0E00040C0E00040C0E00040C0E00040C0E00040C0E00040A0
          E00040E0E00040E0E00040C0E00040C0E00040C0E00000204000FFFFFF000020
          400040C0E00040A0E00040C0E0000040A00040C0E00040E0E00040E0E00040C0
          E00040E0E00040E0E00040C0E0000020800040C0E00000204000FFFFFF000020
          4000002040000020400000204000002040000020400000204000002040000020
          4000002040000020400000204000002040000020400000204000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          20000000000000040000000000000000000000000000000000000080E0000080
          E0000080E0000080E0000080E0000080E0000080E0000080E0000080E0000080
          E0000080E0000080E0000080E0000080E0000080E0000080E0000060A0000060
          A0000060A0000060A0000060A0000060A0000060A0000060A0000060A0000060
          A0000060A0000060A0000060A0000060A0000060A0000060A00040A0E00040A0
          E00040A0E00040A0E00040A0E00040A0E00040A0E00040A0E00040A0E00040A0
          E00040A0E00040A0E00040A0E00040A0E00040A0E00040A0E0000040A0000040
          A0000040A0000040A0000040A0000040A0000040A0000040A0000040A0000040
          A0000040A0000040A0000040A0000040A0000040A0000040A0004080A0004080
          A0004080A0004080A0004080A0004080A0004080A0004080A0004080A0004080
          A0004080A0004080A0004080A0004080A0004080A0004080A000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0FBFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000020A000FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000020A000FFFFFF00FFFFFF000020
          A000FFFFFF00FFFFFF00FFFFFF00FFFFFF000020A000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000204000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000040A000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000020A000FFFFFF00FFFFFF00FFFFFF00FFFFFF000040A000FFFFFF000020
          A000FFFFFF00FFFFFF000020A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF000020A000FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00F0FBFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00F0FBFF00F0FBFF00FFFFFF00FFFFFF000020A000F0FBFF00FFFF
          FF0000204000FFFFFF00F0FBFF00FFFFFF000040A000FFFFFF00FFFFFF00FFFF
          FF000020A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF000040A000FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF000020A000FFFFFF00FFFFFF00FFFFFF000020
          A000FFFFFF000040A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000020
          A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000020A000FFFFFF00}
        MaskColor = 32992
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF003E8B42001D7B2D00418D4700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF001A7823004EBB7A001A782300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF001B7B240051C47F001B7B2400FFFFFF00FFFFFF00FFFFFF00666666006666
          660066666600666666006666660066666600666666001F772A001C852F00268F
          3E00157E220052C88300137B1F00268F3E00268F3E003B90490066666600F4F4
          F400F4F4F400F4F4F400F4F4F400BABABA00F4F4F400258D3B0066D1950066D1
          950066D1950050BB830064CF930066D1950064CF9300218A380066666600F4F4
          F400F4F4F400F4F4F400F4F4F400BABABA00F4F4F400489852001E8029001B7D
          26000E7515007ADCA600117719001E8029001779220046964E00666666000F9E
          C1001BA1C10026A5C10032A9C1003A88960048B1C10053B5C1004EB3C1003F8A
          9600157E280084E3AE00157D28001AA1C10066666600FFFFFF006666660000CC
          FF0010D1FF0020D7FF0031DCFF003DADC10051E7FF0061EDFF0059EAFF0044AF
          C10016822D008CE8B50015812D000FD1FF0066666600FFFFFF006666660000CC
          FF0010D1FF0020D7FF0031DCFF003DADC10051E7FF0061EDFF0059EAFF0044AF
          C100188F4A002CB35300179956000FD1FF0066666600FFFFFF00666666000F9E
          C1001BA1C10026A5C10032A9C1003A88960048B1C10053B5C1004EB3C1003F8A
          960039ACC1002FA8C10024A5C1001AA1C10066666600FFFFFF0066666600F4F4
          F400F4F4F400F4F4F400F4F4F400BABABA00F4F4F400F4F4F400F4F4F400BABA
          BA00F4F4F400F4F4F400F4F4F400F4F4F40066666600FFFFFF0066666600F4F4
          F400F4F4F400F4F4F400F4F4F400BABABA00F4F4F400F4F4F400F4F4F400BABA
          BA00F4F4F400F4F4F400F4F4F400F4F4F40066666600FFFFFF00666666006666
          6600666666006666660066666600575757006666660066666600666666005757
          57006666660066666600666666006666660066666600FFFFFF00525252005A5A
          5A00626262006969690071717100787878008080800088888800898989008181
          8100797979007171710069696900626262005A5A5A00FFFFFF00525252005A5A
          5A00626262006969690071717100787878008080800088888800898989008181
          8100797979007171710069696900626262005A5A5A00FFFFFF00999999008383
          8300898989008F8F8F00959595009A9A9A00A0A0A000A6A6A600A7A7A700A1A1
          A1009B9B9B00959595008F8F8F00898989009A9A9A00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000009560DCA1D7B2DFF09550FC7000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000C6A15F14EBB7AFF0C6A15F1000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000D6D16F151C47FFF0D6D16F1000000000000000000000000666666FF6666
          66FF666666FF666666FF666666FF666666FF666666FF1F772AFF1C852FFF268F
          3EFF157E22FF52C883FF137B1FFF268F3EFF268F3EFF126720D6666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF258D3BFF66D195FF66D1
          95FF66D195FF50BB83FF64CF93FF66D195FF64CF93FF218A38FF666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF219455FF16802AFF147C
          26FF0E7515FF7ADCA6FF117719FF1E8029FF177922FF0B5B13C4666666FFBABA
          BAFFBABABAFFBABABAFFBABABAFF1A7E96FF2DA8C1FF4AB1C1FF46B0C1FF2D84
          96FF1C7F28FF84E3AEFF1C7F28FFBABABAFF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FF20832CFF8CE8B5FF20832CFFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FF3C9348FF2CB353FF449F54FFF4F4F4FF666666FF00000000666666FFBABA
          BAFFBABABAFFBABABAFFBABABAFF1A7E96FF2DA8C1FF4AB1C1FF46B0C1FF2D84
          96FFBABABAFFBABABAFFBABABAFFBABABAFF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FF6666
          66FF666666FF666666FF666666FF575757FF666666FF666666FF666666FF5757
          57FF666666FF666666FF666666FF666666FF666666FF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000646464CA8383
          83FF898989FF8F8F8FFF959595FF9A9A9AFFA0A0A0FFA6A6A6FFA7A7A7FFA1A1
          A1FF9B9B9BFF959595FF8F8F8FFF898989FF6A6A6ACF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000424798B46165DAFF4B49CEFF2221
          677E0000000000000000000000003C3AB5E05251D3FF6068D9F8000000000000
          00000000000000000000000000000000000000000000373F96AA5960E1FF4641
          C8FB0F0E36430000000033309BC44745D4FF5F6BE0F90C0D2125000000000000
          00000000000000000000000000000000000000000000000000004550AEC35158
          DEFF443FC2F51C1B627A4844CFFF5F6CE2FB181D505B00000000666666FF6666
          66FF666666FF666666FF666666FF666666FF666666FF666666FF666666FF5C6B
          D5FF4A4CD9FF514DCEFF5460E3FF5C63A1FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FFA9AB
          BEFF5A66E0FF3B40D8FF737DE3FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FF898B
          C2FF5359D9FF7880E7FF535AD8FFF4F4F4FF666666FF00000000666666FF0F9E
          C1FF1BA1C1FF26A5C1FF32A9C1FF3A8896FF48B1C1FF53B5C1FF4EB3C1FF4A55
          D2FF5968E3FF446ADAFF5E66DFFF2C60CCFF666666FF00000000666666FF00CC
          FFFF10D1FFFF20D7FFFF31DCFFFF3DADC1FF51E7FFFF61EDFFFF4B9AEAFF5A65
          DFFF4E94EFFF2DDBFFFF5A78E9FF4F5BD9FF666666FF00000000666666FF00CC
          FFFF10D1FFFF20D7FFFF31DCFFFF3DADC1FF51E7FFFF61EDFFFF4B68E4FF6B86
          E9FF3CE0FFFF2DDBFFFF2EAAF4FF667AE8FF4E5AB7FF00000000666666FF0F9E
          C1FF1BA1C1FF26A5C1FF32A9C1FF3A8896FF48B1C1FF5E9CD4FF819EEFFF4A7C
          BBFF39ACC1FF2FA8C1FF24A5C1FF6186E7FF7997EFFF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FF6666
          66FF666666FF666666FF666666FF575757FF666666FF666666FF666666FF5757
          57FF666666FF666666FF666666FF666666FF666666FF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000646464CA8383
          83FF898989FF8F8F8FFF959595FF9A9A9AFFA0A0A0FFA6A6A6FFA7A7A7FFA1A1
          A1FF9B9B9BFF959595FF8F8F8FFF898989FF6A6A6ACF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000424798B46165DAFF4B49CEFF2221
          677E0000000000000000000000003C3AB5E05251D3FF6068D9F8000000000000
          00000000000000000000000000000000000000000000373F96AA5960E1FF4641
          C8FB0F0E36430000000033309BC44745D4FF5F6BE0F90C0D2125000000000000
          00000000000000000000000000000000000000000000000000004550AEC35158
          DEFF443FC2F51C1B627A4844CFFF5F6CE2FB181D505B00000000666666FF6666
          66FF666666FF666666FF666666FF666666FF666666FF666666FF666666FF5C6B
          D5FF4A4CD9FF514DCEFF5460E3FF5C63A1FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2C9B
          C5FF5A66E0FF3B40D8FF737DE3FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2E7F
          C7FF5359D9FF7880E7FF535AD8FFF4F4F4FF666666FF00000000666666FFBABA
          BAFFBABABAFFBABABAFFBABABAFF1A7E96FF2DA8C1FF4AB1C1FF46B0C1FF4955
          D2FF5B69E3FF656ED7FF5E66DFFF666ACAFF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4597EAFF5A65
          DFFF8F9BEAFFF4F4F4FF697AE8FF545CD8FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4A68E4FF6986
          E9FFF4F4F4FFF4F4F4FFB7BDEDFF667AE8FF4E5AB7FF00000000666666FFBABA
          BAFFBABABAFFBABABAFFBABABAFF1A7E96FF2DA8C1FF5A9BD4FF819EEFFF4079
          BBFFBABABAFFBABABAFFBABABAFF7589E5FF7997EFFF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FF0F9EC1FF2ADAFFFF54E8FFFF4EE6FFFF2BA7
          C1FFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FF6666
          66FF666666FF666666FF666666FF575757FF666666FF666666FF666666FF5757
          57FF666666FF666666FF666666FF666666FF666666FF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000646464CA8383
          83FF898989FF8F8F8FFF959595FF9A9A9AFFA0A0A0FFA6A6A6FFA7A7A7FFA1A1
          A1FF9B9B9BFF959595FF8F8F8FFF898989FF6A6A6ACF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000001E0000003300000033000000330000001E00000000000000300000
          0033000000330000003300000033000000330000003300000033000000330000
          0033101C6BA92132AEFF2232ADFF2233ADFF151F69AC0000001EAE7B18F2B67E
          0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A08FFB67C07FFC18403FF6354
          67FF2139C7FF385FFBFF3961FEFF3960FAFF283EC1FF141F69ACB67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF071E
          B1FF3E63FEFF3D61FBFF3A5EF9FF3D61FBFF4366FDFF1E30ADFFB47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFD6BDA2FFFFFFFFFFFFFFFFFFEACFA8FF061B
          ABFFA8BAFFFFFFFFFFFFFFFFFFFFFFFFFFFFACBDFFFF1B2DACFFB47A08FFFFFF
          FFFFFFFFFDFFFFFFFDFFFFFFFFFFD7BEA0FFFFFFFFFFFFFFFFFFEACFA5FF041A
          ACFF5877FFFF5876FFFF5473FEFF5877FFFF5E7BFFFF1D2EADFFB47B08FFFFFF
          FFFFD4B999FFD5BA9AFFD6BC9EFFD8BFA1FFD7BD9EFFD8BE9EFFE4C9A2FF6968
          A6FF263DC6FF6B85FFFF728BFFFF6D87FFFF324ACCFF111C6894B47B08FFFFFF
          FFFFFFFDF2FFFFFEF3FFFFFFF7FFD7BB9AFFFFFFF8FFFFFFF8FFDBBE9BFFFFFF
          F8FF7B85CBFF0319AAFF061BA9FF071DAFFF655464FF00000000B47B08FFFFFF
          FFFFFFFBEBFFFFFCECFFFFFFF0FFD7BA96FFFFFFF1FFFFFFF1FFD8BB97FFFFFF
          F2FFFFFFF2FFE8C896FFFFFFF2FFFFFFFFFFC38501FF00000000B47B08FFFFFF
          FFFFD4B38CFFD5B58FFFD7B892FFD8BA95FFD7B893FFD7B893FFD8BA95FFD7B8
          93FFD9BA93FFDABB95FFD9B990FFFFFFFFFFB67C07FF00000000B47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFBE5FFD6B78FFFFFFBE6FFFFFBE6FFD6B78FFFFFFB
          E6FFFFFBE6FFD5B78EFFFFFAE3FFFFFFFFFFB47B08FF00000000B47B08FFFFFF
          FFFFFFF5D7FFFFF6D9FFFFF9DEFFD7B58BFFFFF9DFFFFFF9DFFFD7B58BFFFFF9
          DFFFFFF9DFFFD7B58AFFFFF8DBFFFFFFFFFFB47B08FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFDFB6
          83FFDFB683FFDDB684FFDBB37FFFFFFFFFFFB57B09FF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C7
          FFFF46C7FFFFE1B47EFF40C4FFFFFFFFFFFFB57C09FF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000AD7C17EFB67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67C09FFB67E0EFFAD7C17EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000B16849FFB16849FFB16849FFB16849FFB16849FFB16849FFB16849FFB168
          49FFB16849FFB16849FFB16849FFB16849FF0000000000000000000000000000
          0000B16849FFD8A549FFD29D45FFD7A650FFD8A853FFE6C26CFFECCF77FFEED3
          7DFFFBED99FFF8E998FFFAE98BFFB16849FF0000000000000000000000000000
          0000B16849FFC28119FFC17E1AFFCD9639FFD6A84DFFDCB562FFE1C174FFEAD1
          86FFF1DC91FFEBCF83FFEED276FFB16849FF0000000000000000000000000000
          0000B16849FFD19C38FFD09B41FFDBB059FFE2BE6BFFEED684FFFAE494FFF7E7
          9AFFEFD38AFFE7C474FFEECF72FFB16849FF0000000000000000000000000000
          0000B16849FFDCB153FFD6A853FFF4E087FFB16849FFB16849FFB16849FFB168
          49FFB16849FFB16849FFB16849FFB16849FF0000000000000000000000000000
          000000000000B16849FFEACE74FFEAD084FFFFFEA6FFB16849FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000B16849FFFAEC9CFFEFD88BFFFFF598FFB16849FF0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000B16849FFEFD37CFFDFB359FFF5E57FFFB168
          49FF000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000B16849FFF2D77DFFD59B3BFFDCA334FFB168
          49FF000000000000000000000000000000000000000000000000000000000000
          00000000000000000000B16849FFF3DB86FFD79F3EFFD79C2CFFB16849FF0000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000B16849FFF1D47BFFD69A32FFD79A27FFB16849FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000B16849FFFEF4B1FFDFB266FFD59830FFB16849FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000B16849FFEDD38EFFDEB474FFDEB56FFFB16849FFB16849FFB16849FFB168
          49FFB16849FFB16849FFB16849FFB16849FF0000000000000000000000000000
          0000B16849FFE3B96DFFD49B4FFFD59F51FFDDB160FFE2BA6CFFE4BF74FFE6C3
          76FFE8CA7AFFE8CC80FFF8ED9CFFB16849FF0000000000000000000000000000
          0000B16849FFF5E4A2FFEACE90FFECD494FFECD396FFECD79CFFEFDCA4FFF0E0
          ABFFF1E3AFFFEFE0AEFFFAF6C0FFB16849FF0000000000000000000000000000
          0000B16849FFB16849FFB16849FFB16849FFB16849FFB16849FFB16849FFB168
          49FFB16849FFB16849FFB16849FFB16849FF0000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00004089DDFF4089DDFF4089DDFF4089DDFF0000000000000000000000000000
          000009131E232E63A0B93F87DAFB2F66A4BD09121D2200000000000000000000
          0000000000004089DDFF4F9EF0FF4797ECFF4089DDFF0000000000000000060D
          16193F88DEFF4798EFFF51A5F3FF59AAEEFF3F88DEFF060D1518000000000000
          0000000000004089DDFF4496EDFF4DA6F6FF4089DDFF00000000000000002754
          889D4293EDFF4996E7FF3B86E1FF76CDF1FF6BBCECFF2753869B000000000000
          000000000000000000004089DDFF5EB3F3FF62B7F1FF4089DDFF000000003C81
          D0F04D9EF3FF3B86E1FF000000003B86E1FF6DC4F5FF3C81D1F1000000000000
          000000000000000000004089DDFF61B3EFFF79D3F6FF4089DDFF000000003C81
          D0F064B6F3FF3B86E1FF000000003B86E1FF4DADF4FF3C81D1F1000000000000
          00000000000000000000000000004089DDFF89E2F7FF8BE4F4FF4089DDFF2754
          889D73C6F0FF58A2E5FF3B86E1FF42A6EEFF4BABEDFF2753869B000000000000
          00000000000000000000000000004089DDFF7CD0F0FF9AF4F6FF4089DDFF060D
          16193F88DEFF58ABEEFF4AADF0FF49B1EEFF4089DDFF060D1518000000000000
          0000000000000000000000000000000000004089DDFF8FEAF7FF6BC1F0FF4089
          DDFF09131E232E63A0B93F87DAFB2F66A4BD09121D2200000000000000000913
          1E232E63A0B93F87DAFB2F66A4BD09121D224089DDFF5EB3EFFF59B2F5FF4089
          DDFF000000000000000000000000000000000000000000000000060D16193F88
          DEFF4695EDFF499AF0FF51A1EEFF4089DDFF060D15184089DDFF419AF2FF3F97
          EEFF4089DDFF00000000000000000000000000000000000000002754889D589C
          EDFF559DEFFF4089DDFF509BE4FF76C9EFFF2753869B4089DDFF409DEFFF3EA8
          F4FF4089DDFF00000000000000000000000000000000000000003C81D0F06CAD
          F6FF4089DDFF000000004089DDFF83CAF5FF3C81D1F1000000004089DDFF51B7
          F4FF53B4F0FF4089DDFF000000000000000000000000000000003C81D0F081C3
          F6FF4089DDFF000000004089DDFF6FB7F5FF3C81D1F1000000004089DDFF69BC
          F1FF72D1F6FF4089DDFF000000000000000000000000000000002754889D72B8
          ECFF93D9F4FF4089DDFF55A0E8FF64B7F1FF2753869B00000000000000004089
          DDFF79E2F8FF6CCBF1FF4089DDFF000000000000000000000000060D16194089
          DDFF73B9EEFF70B8F3FF68B9F0FF418ADEFF060D151800000000000000004089
          DDFF65C5EFFF79E3F6FF4089DDFF000000000000000000000000000000000913
          1E232E63A0B93F87DAFB2F66A4BD09121D220000000000000000000000000000
          00004089DDFF4089DDFF4089DDFF4089DDFF0000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF006B64
          5D004F47410047403A00463F3A00463F3A00463F3A00463F3A00463F3A002A25
          23000000000000000000000000005769890041557100836E6F00FFFFFF008D86
          7F00C4C3C300C8C8C800CFCFCF00D5D5D500DCDCDC00E3E3E300E7E7E700E4E4
          E300DAD9D900DEDEDD007C8BA30062ADCF0055AFE20026406900FFFFFF00B3B0
          AE00C6C6C600C6C6C600D1D1D100DBDBDB00E5E5E500F0F0F000F4F4F400E7E7
          E700E3E3E2007B8EAB005FA7CC0072DAFE00187FD500546E9600FFFFFF00BAB8
          B600C6C6C600C6C6C600D0D0D000DBDBDB00E5E5E500EFEFEF00F2F2F200E1E1
          E1007B95B4005EADD30073D8FE00177ED3005274A30022222200FFFFFF00BDBB
          B900C6C6C600C6C6C600CECECE00D9D9D900E3E3E300ECECEC00F3F3F300A9B5
          C8003F95CA0073D7FE001881D800557FB00075706D0000000000FFFFFF00C7C4
          C200D4CDCC00A9948D0097806F0099847100927C7200AC9C9B00D7CECD00A499
          9C003B74A600187CD2005789C200DDDCDC00837D790000000000FFFFFF00BFB3
          B300A6836200F0DD9600FEFEB100FEFEC200FEFED700DCD3BB00856C67008C6C
          69009A99A30098B7D800EBF0F600E8E8E80086807C0000000000D5CDCD00A47B
          5800FEE99500FEEC9D00FDF7AD00FDFEC300FDFDD600FEFEF200F0EDE3008368
          6500D9D0D000E3E3E300E2E2E200EBEBEB0087827E00000000009B7F7500F0C4
          7900FBD68600FBE19400FDF8AF00FDFEC100FDFDD600FDFDE800FEFEFE00CABD
          AF00C1B5B400D9D9D900E3E3E300E1E1E10087817D0000000000A5785900FED7
          8300F8D68B00FBE69B00FCF6B100FDFEC900FDFDCE00FDFDDB00FDFDE100FCFB
          DB00A6938F00DFDFDF00D9D9D900D7D7D70086807C0000000000BA845900FBD2
          8200F8DC8E00F9E39D00FBEDA700FDFBC100FDFDCC00FDFDC800FDFDCE00FEFE
          D200AC969000DADADA00D7D7D700CFCFCF0085807B0000000000B0826100FDCC
          7800FBEB9E00FDFED000FCF8D800FCEEAA00FDFBBD00FDFDB500FDFEBB00FCFB
          B800AE9E9800D9D9D900D5D5D500D1D1D10086807C0000000000B4988A00F2B5
          6900FCE39400FDFDBD00FDFED100FBE9A500FCF1A700FBEB9D00FEFBAA00E1D3
          9900CFC6C500DDDDDD00D9D9D900D5D5D500857F7B0000000000DCD3D200CB91
          6200FDC87400FBE69700FBEEA200FBE69900F6D68800FCDE8E00FBE39500BEA6
          9100E3E2E200E1E1E100DDDDDD00D7D7D700837D780000000000FFFFFF00CEC1
          BE00D1996900F2B76B00F9CC7A00F9D18100FBD07C00F1CA8200C9AD9000DAD3
          D300E3E3E200DFDFDF00DBDBDB00C2C0BF006A615900FFFFFF00FFFFFF00FFFF
          FF00E2DBDA00CAAF9F00D2A47C00D7A97C00CDAC8F00D0C0B700FFFFFF00958C
          85008B807900756A61007469600074696000FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF005C55
          4E004F47410047403A00463F3A00463F3A00463F3A00463F3A00463F3A002A25
          23000000000000000000000000005769890041557100836E6F00FFFFFF008D86
          7F00C4C3C300C8C8C800CFCFCF00D5D5D500DCDCDC00E3E3E300E7E7E700E4E4
          E300DAD9D900DEDEDD007C8BA30062ADCF0055AFE20026406900FFFFFF00B3B0
          AE00C6C6C600C6C6C600D1D1D100DBDBDB00E5E5E500F0F0F000F4F4F400E7E7
          E700E3E3E2007B8EAB005FA7CC0072DAFE00187FD500546E9600FFFFFF00BAB8
          B600C6C6C600C6C6C60018435A002B6189004C8ABE006FA8CB00F2F2F200E1E1
          E1007B95B4005EADD30073D8FE00177ED3005274A30022222200FFFFFF00BDBB
          B900C6C6C600C6C6C6002E67850094C7F90091C9F9004185C900266BAE00A9B5
          C8003F95CA0073D7FE001881D800557FB00075706D0000000000FFFFFF00C7C4
          C200D4CDCC00A9948D004389AA00E0F2FF00549AD8001A7ABE004998C500488E
          C7003B74A600187CD2005789C200DDDCDC00837D790000000000FFFFFF00BFB3
          B300A6836200F0DD9600A5C3D7007AB6D50090B7D10055C9E4005BDFF50078D0
          ED00519DDD0098B7D800EBF0F600E8E8E80086807C0000000000D5CDCD00A47B
          5800FEE99500FEEC9D00FDF7AD00B2D5E50076BAD700C2F6FD0063DFF7005DE2
          F80079D3F0004998DC00E2E2E200EBEBEB0087827E00000000009B7F7500F0C4
          7900FBD68600FBE19400FDF8AF00FDFEC100AFD4E50077CBE700C7F7FD005EDC
          F5005AE1F7007BD4F1004B9ADD00E1E1E10087817D0000000000A5785900FED7
          8300F8D68B00FBE69B00FCF6B100FDFEC900FDFDCE00BDE5F20079D3EE00C7F7
          FD005FDCF5005BE2F7007AD6F20051A2E200234A6B0000000000BA845900FBD2
          8200F8DC8E00F9E39D00FBEDA700FDFBC100FDFDCC00FDFDC800BAE3F0007DD4
          EE00C4F6FD006CDDF6006DCAED0063A3D7005C99CF004F8EC400B0826100FDCC
          7800FBEB9E00FDFED000FCF8D800FCEEAA00FDFBBD00FDFDB500FDFEBB00A8D9
          E80081D6EE00B2E3F9008BC0E700AED3F600C4E0FC00669FD300B4988A00F2B5
          6900FCE39400FDFDBD00FDFED100FBE9A500FCF1A700FBEB9D00FEFBAA00E1D3
          9900AFE4F30077BEE700B4D2F000E5F3FF00ACD2EF00488CC700DCD3D200CB91
          6200FDC87400FBE69700FBEEA200FBE69900F6D68800FCDE8E00FBE39500BEA6
          9100E3E2E200ACD5E40058A5D80085B1DB00469DD0002B95D100FFFFFF00CEC1
          BE00D1996900F2B76B00F9CC7A00F9D18100FBD07C00F1CA8200C9AD9000DAD3
          D300E3E3E200DFDFDF00DBDBDB00C2C0BF006A615900FFFFFF00FFFFFF00FFFF
          FF00E2DBDA00CAAF9F00D2A47C00D7A97C00CDAC8F00D0C0B700FFFFFF00958C
          85008B807900756A61007469600074696000FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000C0C0C0000000
          0000C0C0C000C0C0C00000000000C0C0C000C0C0C00000000000C0C0C000C0C0
          C00000000000C0C0C000C0C0C00000000000C0C0C000C0C0C000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000C0C0C0000000
          00008000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF008000000080000000FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF008000000080000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF008000000080000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF008000000080000000FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00800000008000
          000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00800000008000000080000000FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF00FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF008000000080000000FFFFFF00000000000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF00C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF008000000080000000C0C0C0000000
          0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0080000000}
        MaskColor = clSilver
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000252B4AFF141B
          2BFF232940FF283455FF090C15FF000000FF010100FF010103FF10101EFF0000
          00FF000000FF000000FF000000FF000000FF0B091BFF121975FF1A2237FF1D22
          39FF3E5787FF20263EFF000000FF000000FF000000FF000001FF11121AFF2021
          27FF06080DFF000000FF020100FF03020CFF080E1CFF141A8EFF242B45FF364E
          7CFF2E3A5CFF01040FFF000000FF0B0D19FF525871FFA7AEC1FFB6B8C7FFC8CB
          DAFFC1C5D2FF676A7CFF000000FF02070BFF0C0E38FF1421B0FF0E0C4EFF090D
          06FF060700FF000000FF505363FFB3B8C3FFBBBFCDFFA8AEBDFFCCCFD8FFC2C9
          CFFFCCCDDAFF959DA7FF4D4F62FF070851FF1922AEFF1122B2FF10139DFF0D0E
          81FF050641FF4D5468FFB6BCCCFFCDD3DEFFC2C8D1FFBAC1CDFFADB5BFFF475C
          8CFF4D6088FF858997FF575F94FF0E18A9FF1420AEFF1124ABFF0E1096FF090B
          96FF464DA2FFB9BFCBFFB7BDC8FFCBCFD7FFBEC2CBFF6F83A3FF29468CFF2F52
          90FF1E3163FF717981FF5A618FFF121BA2FF1420ADFF1427AFFF0D0F8EFF090A
          8CFF465495FF727991FF656A82FF727692FF6480A8FF82AEF0FF476EACFF304F
          90FF11255CFF1E2547FF242EA1FF151FA5FF1320A8FF1024AAFF100F93FF0D0F
          94FF0D1184FF020414FF000000FF000016FF466EA9FFA8C8FCFF86A6E7FF5E78
          B6FF3B5390FF0E1473FF101DB0FF101C9FFF1320A4FF1522A8FF0E108FFF1012
          90FF020204FF030000FF04030BFF000016FF7B9DD0FFB6C8E5FFB0C5E9FF95B4
          E4FF496295FF000017FF192077FF1723ADFF121FA3FF1623A8FF0C0F86FF1414
          81FF010100FF000000FF020301FF000019FF738DB9FFD3F0FFFF9BBADCFFAAD3
          FFFF304778FF000002FF000000FF17219DFF1622A7FF1926ACFF0F1189FF0E12
          90FF02050AFF010100FF010000FF000000FF21263BFF616A80FF5D6275FF1D23
          3EFF02000BFF020310FF141A71FF1726ACFF1420A3FF1826ACFF0D0D89FF0B0D
          84FF12128BFF0D0B3AFF030202FF050503FF000000FF000002FF00000DFF0004
          17FF03061FFF1B27A8FF1524B1FF1926A0FF1826A5FF1928AAFF1C2199FF1217
          89FF0F108EFF10119AFF111481FF010100FF000000FF030100FF050515FF0306
          15FF070A20FF1E26ABFF1C25ABFF1B27A3FF1E28A5FF1F2BA8FF1C2595FF1820
          8EFF181E82FF0F0F90FF141594FF000200FF020100FF05060DFF07041AFF0107
          15FF070B1DFF1924A3FF1825A6FF14219BFF1F29A7FF2331A5FF181C85FF1214
          7FFF1A1C8DFF0C0F91FF13149EFF02030CFF000203FF020519FF020512FF0E10
          1DFF111538FF131795FF111795FF091095FF1E28A0FF333BA2FF11128CFF1518
          8EFF151A8AFF141891FF171D9FFF1D2382FF222754FF2B3054FF323564FF383D
          7EFF4547A0FF4648A2FF3D3E9BFF3D409DFF3A439DFF3E419FFF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000F7F5F3FFDCDC
          DCFFDADADAFFD9D9D9FFDADADAFFDBDBDBFFDADADAFFDADADAFFDADADAFFDADA
          DAFFDADADAFFD9D9D9FFD9D9D9FFDADADAFFD6D6D7FFECEBEAFFFFFFFBFFEFED
          EAFFCECFCFFFDAD9D8FFD3D3D3FFD1D1D1FFD1D1D1FFD1D1D1FFD1D1D1FFD0D0
          D0FFCDCECEFFD2D2D2FFD1D1D1FFCDCECEFFDFDEDDFFFEFCF8FFFFFBF6FFFBF6
          F2FFD4D3D1FFF6F2EEFFCFCECEFFC5C5C5FFC7C7C7FFC7C7C7FFC7C7C7FFC4C4
          C4FFDCD9D8FFF6F4EFFFD2D0CFFFC1C1C2FFE9E5E2FFFFFDF8FFFFF9F2FFFEF7
          F1FFDCD8D5FFFCF6F0FFD1CFCDFFB7B8B8FFBCBCBCFFBCBCBCFFB8B8B8FFC9C8
          C6FFFFF9F3FFFFFCF6FFD1CFCDFFB7B8B8FFEEE9E4FFFFFCF5FFFFF6EEFFFFF6
          EEFFF5EEE7FFFFF9F0FFEEE7E1FFAFAEAFFFADADADFFAEAEAEFFABABACFFE7E1
          DBFFFFFAF1FFFFFBF2FFD9D5D0FFB5B4B3FFFDF5EDFFFEF5ECFFFFFCE9FFFFF5
          EAFFFFF6EBFFFFF5EAFFFFF9EEFFE0D9D2FFA3A3A3FFA0A0A0FFD8D2CBFFFFF8
          EDFFFFF5EAFFFFF9EDFFE0D9D2FFBDBBB7FFFFF3E8FFF2D4CBFFD9CFEAFFFFFD
          E3FFFFFAE4FFFFF4E5FFFFF3E5FFFFFBEDFFB6B2AEFFAAA8A5FFFFF8EAFFFFF3
          E6FFFFF2E5FFFFF3E5FFFCF0E3FFF7EEE2FFF3D5C9FFF9E3D7FF595AFDFF9F99
          EFFFE0D6E4FFFFF1DEFFFFF8DCFFFFF5E4FFD4CAC0FFCDC3BAFFFFF4E3FFFFF0
          E0FFFFF2E2FFFFF0E0FFFFF1E1FFFFECDCFFEDC6B8FFFFF1E1FF5558FFFF494B
          FFFF5758FEFF7774F6FFC0B5E6FFFDECD7FFFDEAD6FFFDE9D7FFFFEDD9FFFEEA
          D7FFE7B7A8FFF9DFCCFFFFF5E0FFEDC2B2FFF5D4C2FFFFEFDBFF585AFFFF4C4F
          FFFF474BFFFF5355FDFF9D92E8FFFCE6CDFFFFE8CDFFFFE7CFFFFFEDD4FFEDBF
          ABFFECBDA9FFEABAA6FFEDC1ADFFEDBEABFFFFEAD2FFFEE5CEFF4D51FFFF6F69
          F1FFB5A4D8FFEBD0C8FFFFE6C1FFFFE0C1FFFFE6C8FFFFE6C7FFEEBEA6FFE8B0
          99FFFFEACCFFF0C1A8FFE6AB94FFFFE2C5FFFEDFC2FFFEDEC1FFA691D6FFF8D4
          B5FFFFE3B1FFFFE4B9FFEEB799FFDF9982FFECB599FFE6A78EFFE7A98DFFFDD6
          B3FFFED9B6FFFFD9B6FFFFDBB7FFFED8B5FFFED7B4FFFED7B4FFFFD5A3FFFFD8
          A9FFFED0A7FFF4BF99FFE09779FFF9C8A0FFEBAB89FFF1B893FFFFD6ABFFFED1
          A7FFFDCFA5FFFDCFA6FFFDD0A6FFFDCFA5FFFDCFA5FFFDCFA5FFFFCE9BFFEDAB
          82FFDE8E6DFFDA8565FFF1B287FFFFCD9CFFFFCC9BFFFECA99FFFCC696FFFCC6
          96FFFCC796FFFCC796FFFCC696FFFCC696FFFCC696FFFCC796FFEEA777FFDB82
          5DFFF9BB86FFFBBF89FFFBC089FFFBBE88FFFABE88FFFBBE87FFFABE88FFFBBE
          88FFFBBE87FFFBBE87FFFBBE87FFFBBE87FFFBBE87FFFBBE87FFD6744CFFFBB8
          7BFFFCB97BFFFBB779FFFAB679FFFAB678FFFAB578FFFBB578FFFAB578FFFAB5
          78FFFAB578FFFAB578FFFAB578FFFAB579FFFBB578FFFAB578FF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          20000000000000040000000000000000000000000000000000006D6D6D00FFFF
          FF000B0B0B006D6D6D006D6D6D000C0C0C006D6D6D006D6D6D000E0E0E00FFFF
          FF000A0A0A006D6D6D006D6D6D000B0B0B006D6D6D006D6D6D000A0A0A00FFFF
          FF000B0B0B000A0A0A000A0A0A001515150075757500FFFFFF00FFFFFF00FFFF
          FF000A0A0A0018181800FFFFFF00FFFFFF00FFFFFF00FFFFFF006D6D6D00FFFF
          FF000B0B0B000A0A0A000A0A0A000A0A0A000B0B0B009C9C9C00FFFFFF00FFFF
          FF000A0A0A000A0A0A0040404000FFFFFF00FFFFFF00FFFFFF006D6D6D00FFFF
          FF000B0B0B000A0A0A000A0A0A000A0A0A000B0B0B009D9D9D00FFFFFF00FFFF
          FF000A0A0A000A0A0A000C0C0C0090909000FFFFFF00FFFFFF000A0A0A00FFFF
          FF000B0B0B000A0A0A000A0A0A000B0B0B00A6A6A600FFFFFF00FFFFFF00FFFF
          FF000A0A0A001818180018181800FFFFFF00FFFFFF00FFFFFF006D6D6D00FFFF
          FF000B0B0B000A0A0A000C0C0C0099999900FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A0040404000FFFFFF00FFFFFF006D6D6D00FFFF
          FF000C0C0C0062626200AAAAAA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000C0C0C00A3A3A300FFFFFF000B0B0B00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A0018181800FFFFFF00FFFFFF006D6D6D00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000A0A0A0040404000FFFFFF006D6D6D00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000A0A0A000B0B0B00AEAEAE000E0E0E00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000A0A0A000A0A0A00B1B1B1006D6D6D00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000A0A0A0018181800FFFFFF006D6D6D00FFFF
          FF000B0B0B00A0A0A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000A0A0A000A0A0A000A0A0A000A0A0A000C0C0C00AEAEAE00FFFFFF00FFFF
          FF000B0B0B0081818100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF000B0B0B0015151500797979009A9A9A009E9E9E00FFFFFF00FFFFFF00FFFF
          FF00404040000B0B0B0040404000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00404040000B0B0B0040404000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00404040000B0B0B0075757500FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00404040000B0B0B008B8B8B00FFFFFF00FFFFFF00}
        MaskColor = 7171437
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000008A6B51ED8A6A
          4EF4000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000695040A49B7D60FF9779
          5DFF82644ED70000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000015100D1FA27F5DFCCC9D7AFFD2A2
          7DFFA38260FF4332276900000000000000000000000000000000666666FF6666
          66FF666666FF666666FF666666FF666666FFA7866CFFCAA17EFFC99A7DFFB794
          7BFFD3A67FFFA4815FFF6F6A66FF666666FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBAA38AFFBE9770FFD8A782FFE0CBBDFFBABA
          BAFFE5BA94FFD0A97EFFB99673FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFEAE3DDFFB78E6BFFE4B689FFD1A58AFFF4F4F4FFBABA
          BAFFF3EFEBFFEDBE8FFFC49A73FFD6B8A9FF666666FF00000000666666FFBABA
          BAFFBABABAFFBABABAFFC09A77FFE2B788FFDFB38FFFC1B6ADFFBABABAFF9191
          91FFBABABAFFC7BCAFFFECBF8EFFBA916EFF736D66FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF6E0C3FFE3CAA9FFEEE0D0FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF2DABFFFE5B889FFAD8B6EFF03020106666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F3F2FFBCBAB9FFF4F4F4FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF4F4F4FFF3D1ABFFD5A97EFF69523F89666666FFBABA
          BAFFBABABAFFBABABAFFBABABAFF919191FFBABABAFFBABABAFFBABABAFF9191
          91FFBABABAFFBABABAFFBABABAFFBDBAB7FFE4BB8FFFD0A280F8666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FFF4F4
          F4FFF4F4F4FFF4F4F4FFF4F4F4FFBABABAFFF4F4F4FFF4F4F4FFF4F4F4FFBABA
          BAFFF4F4F4FFF4F4F4FFF4F4F4FFF4F4F4FF666666FF00000000666666FF6666
          66FF666666FF666666FF666666FF575757FF666666FF666666FF666666FF5757
          57FF666666FF666666FF666666FF666666FF666666FF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000525252FF5A5A
          5AFF626262FF696969FF717171FF787878FF808080FF888888FF898989FF8181
          81FF797979FF717171FF696969FF626262FF5A5A5AFF00000000646464CA8383
          83FF898989FF8F8F8FFF959595FF9A9A9AFFA0A0A0FFA6A6A6FFA7A7A7FFA1A1
          A1FF9B9B9BFF959595FF8F8F8FFF898989FF6A6A6ACF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000220000003300000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000A000000260000003300000033858484BB888A8CFF00000033000000330000
          00330000003300000033000000000000000000000000000000000000001F2322
          205C837E75C9B0AA9EFFB0AA9CFF97999BFFC8C8CBFF848D97FFBA823EFFB782
          42FFB68344FFB88445FF000000330000000000000000000000006B6760ADB4AE
          A2FFC5BEB3FFD4CBC2FFE2D8CFFFEDE3DDFF959CA5FFB77D35FFF8C073FFF2BA
          6DFFEFB665FFE5B56DFFB78344FF000000330000000000000000B1AB9FFFC8C1
          B6FFCFC7BFFFD6CCC5FFDED5CCFFE8E1DEFFB4792FFFF3C88DFFF6C078FFF2BB
          70FFEBBF80FFB17D3FFFEFB35DFFB98442FF0000000000000000B0AB9EFFC7C0
          B6FFCDC4BBFFD3CAC2FFDBD2CAFFE6E0DDFFB17730FFF8D09CFFF8C27DFFF2CB
          94FFAF7A3AFFF4B96AFFDEB272FFBC8139FF0000003300000000B0AA9EFFCAC3
          B9FFEAE5DDFFF7F3EBFFFFFCF6FFFFFFFFFFB0762EFFFFDAACFFFBD7A7FFAD78
          36FFF9C279FFE8C188FFB87D35FFC0C2CAFF898C8FFF000000336F6B64ADF9F3
          EDFFD8D1C9FFC2B8B0FFC0B7AFFFC6BFBBFFB1752BFFFFE7BEFFAD7734FFFFCB
          88FFF0CC9BFFB77C34FF61615E9A9B9EA2FFCDCBCAFF898989FF706C64B4A39A
          8FFFBAB2A7FFCAC1B8FFDED5CCFFE6DDD7FFEEE7E7FFAF742CFFFFD698FFFCDB
          B1FFB67B32FFAAA5A0FF6B6962AC000000009B9C9DFFD2D0CFFFB1AB9FFFC9C2
          B9FFCFC7BFFFD5CCC4FFDCD3CAFFE3DAD2FFEBE2DDFFE8E3E1FFB1752BFFB578
          2EFFBCBFC6FF85888CFFB7B0A3FF000000000000000000000000B0AB9EFFC7C0
          B6FFCCC4BBFFD3C9C1FFDAD0C7FFE1D7CFFFECE1DBFFE5DCD6FFDED7D2FFD9D2
          CDFF94979AFFC9C8C7FF868788FF000000000000000000000000AFAA9DFFC8C1
          B7FFE8E3DBFFF5F0E8FFFDF8F2FFFCF8F1FFFBF7F1FFFCF8F1FFFDF9F3FFF7F2
          ECFFEEE6DDFF939596FFD1CFCFFF000000000000000000000000AEA89CFFFBF5
          EFFFEEE7DEFFE0D8CEFFDDD5CCFFDDD4CBFFDDD4CBFFDDD4CBFFDDD5CCFFE0D8
          CFFFEFE8DEFFFCF8EFFFAEA89AFF000000000000000000000000AFA99DFFE1D8
          CEFFE1D7CEFFDFD6CCFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD6
          CCFFE1D7CEFFE1D8CEFFAFA99DFF0000000000000000000000006A675F99B6B0
          A4FFD6CFC4FFE6DED5FFEFE7DDFFEEE6DCFFEEE6DCFFEEE6DCFFEFE7DDFFE6DE
          D5FFD6CFC4FFB6B0A4FF6A675F99000000000000000000000000000000002322
          2033827D74BCAEA99CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA9
          9CFF827D74BC2322203300000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000330000
          0033000000000000000000000000000000000000000000000000000000300000
          0033000000330000003300000033000000330000003300000033008C4DFF0081
          3CFF000000330000003300000033000000330000003000000000AE7B18F2B67E
          0EFFB47B09FFB47A07FFB67B09FFBF7E0DFFD5800FFF00894AFF13C892FF0089
          4BFFDD8212FFD18417FFCD8518FFC98518FFBB7C19F200000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF008240FF35CD9EFF00DCA2FF00BC
          81FF00813CFF00813CFF00813CFF00813CFFB0851DFF00000033B47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF00792EFF4FD2ADFF00D49DFF00D29CFF00D5
          A1FF00D9A5FF00DAA7FF00DBA8FF00C08BFF00813CFFFFFFFFFFB47A08FFFFFF
          FFFFFFFFFDFFFFFFFDFFFFFFFFFFF4C7B0FF007F36FF7CE8D7FF00C59DFF00AF
          7CFF00813CFF00813CFF00813CFF00AF7BFF00B688FF00813CFFB47B08FFFFFF
          FFFFD4B999FFD6BA9BFFDFBFA1FFF0C6ACFFFFC9B1FF007E35FF95E9E5FF0081
          39FFF4C5ACFFF4C5ACFFF4C5ACFF3FA97AFF009E6DFF00813CFFB47B08FFFFFF
          FFFFFFFDF2FFFFFFF4FFFEFCF0FF007E35FFFFFFFFFFFFFFFFFF007F37FF0081
          3CFFFFFFFFFF00813CFF00813CFFFFFFFFFF758323FF00813CFFB47B08FFFFFF
          FFFFFFFBEBFFFFFCEDFFFFFFF8FF00813CFF00A663FF3DA46FFFF4C5ACFFFFFF
          FFFFFFFFFFFF007F39FF0AE3AEFF008240FFE97F0AFF00000000B47B08FFFFFF
          FFFFD4B38CFFD7B58FFFE6BB98FF00813CFF00BE80FF00B879FF00813CFF0081
          3CFF00813CFF00B97BFF00DA9FFF36E8BDFF008746FF00000033B47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFDE8FFBBB287FF00813CFF00BF86FF00D8A6FF00D8
          A5FF00D7A4FF00D4A0FF00D19CFF00D39FFF5EDBB8FF008C4BFFB47B08FFFFFF
          FFFFFFF5D7FFFFF6DAFFFFFADFFFE4B990FFE4E9CAFF00813CFF00833FFF0084
          40FF00843FFF00AF7DFF00C69FFF7EDCC5FF008747FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B683FFE1B887FFE9B988FFF1BB8BFFF5BD8FFFFBBE
          8EFFFFBF90FF008239FF94DFD2FF00823EFFD3800EFF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B67EFF47C7FFFF49C7FFFFE6B680FF4CC8
          FFFF55CAFFFF00813CFF007C33FFFFFFFFFFBF7F0EFF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB87F0FFF00000000AD7C17EFB67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67C08FFB77C09FFB77C0AFFB77E0FFFAD7C17EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFD8CFCCFFD3C6BEFFD2C5BDFFD2C5BDFFD2C5BDFFD2C5
          BDFFD3C5BFFFD8CFCCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCFB07BFFB17B1CFFB07714FFB27916FFB37A17FFB37A17FFB279
          16FFAA7A1AFFB17B1CFFCFB07BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFBB8827FFB47701FFB67903FFB67A08FFB77D0CFFB77C0EFFB77B
          09FFAB7C09FFB47701FFBB8827FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFC89828FFC79007FFC9910CFFCB9819FFCC991BFFCB991BFFCB98
          1AFFC8930DFFC89003FFC89828FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFC89828FFC79007FFC9910CFFCB9819FFCC991BFFCB991BFFCB98
          1AFFC8930DFFC89003FFC89828FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCDA447FFD1A333FFD2A93CFFD4AA45FFD4AA45FFD6AA45FFD4AA
          45FFD3A93FFFD0A232FFCDA447FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCBB592FFCDAF7EFFCEB381FFCDB17BFFCDB17BFFCDB17BFFCDB1
          7BFFCFB37DFFD1B481FFCBB592FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF5F0E7FFE5D2AFFFE5D2ACFFEBD8B2FFE7D7B2FFE9D8B1FFE8D8
          B3FFE5D2ACFFE5D2AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFBF9F8FFEDE2D4FFCCAD76FFBF9248FFBF9143FFD6B9
          7CFFE6D9BFFFF1EEEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFEAE9F3FFCCAD76FFBA7F01FFBA8002FFBA8002FFB881
          02FFD6B97CFFF1EEEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFE8D4B1FFBB810AFFBA7F01FFBA8002FFBA8002FFB881
          02FFB87C00FFE8D4B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFDCBB76FFC38901FFC38C03FFC38C03FFC38C03FFC38C
          01FFC38A00FFDCBB76FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFDCBB76FFC38901FFC38C03FFC38C03FFC38C03FFC38C
          01FFC38A00FFDCBB76FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFEBDDC0FFD3AE54FFD5B054FFD5B054FFD7B054FFD5B0
          54FFD4B058FFE8D4B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFE1CDA4FFD5B054FFD5B054FFD5B054FFD5B0
          54FFDFC89AFFF6F1E8FFFAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E7F3FFE0C78FFFE0C78FFFE0C78FFFE0C7
          8FFFE5E0E9FFECECFAFFEDEDFBFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000001E0000003300000033000000330000001E00000000000000000000
          000A000000260000003300000033000000330000003300000033000000330000
          0033005C36A9009E5EFF009D5DFF009E5EFF005E39AC0000001E0000001F2322
          205C837E75C9B0AA9EFFAFA99DFFAEA89CFFAEA89CFFB0A89DFFBDABA2FF4EA3
          7BFF00A567FF00BA85FF77DFC4FF00BA86FF00A66AFF005E39AC6B6760ADB4AE
          A2FFC5BEB3FFD4CAC2FFE1D7CFFFE8DED6FFEFE4DDFFEEE1DAFFF6DBD8FF0099
          53FF00BF8AFF00BB82FFFFFFFFFF00BB82FF00C08CFF009E5EFFB1AB9FFFC8C1
          B6FFCFC7BFFFD6CCC5FFDCD3CAFFE4D9D2FFEBE0D9FFEADDD6FFF3D8D5FF0096
          50FF73E4CAFFFFFFFFFFFFFFFFFFFFFFFFFF77E5CCFF009C5CFFB0AB9EFFC7C0
          B6FFCDC4BBFFD3CAC2FFDAD1C8FFE2D7CFFFECE1DAFFE7DBD3FFF0D6D2FF0095
          4EFF00CA94FF00C78FFFFFFFFFFF00C88FFF00CC98FF009D5DFFB0AA9EFFCAC3
          B9FFEAE5DDFFF7F3EBFFFFFBF4FFFDFAF3FFFDF9F2FFFFFAF3FFFFFEFAFF68C4
          9DFF00AB6AFF00D39CFF75EDD3FF00D39EFF00AE72FF005E39976F6B64ADF9F3
          EDFFD8D1C9FFC2B8B0FFBFB6AEFFC5BAB2FFC8BEB5FFC6BBB3FFC5B8B1FFD7BE
          BBFF47A278FF009B54FF009A56FF009C5BFF005E399700000000706C64B4A39A
          8FFFBAB2A7FFCAC1B8FFDED5CCFFE5DBD3FFECE1DAFFE8DED5FFE1D6CEFFD2C4
          BDFFCAB6B0FFBA9F9AFF796763AB000000000000000000000000B1AB9FFFC9C2
          B9FFCFC7BFFFD5CCC4FFDCD3CAFFE3D9D1FFEADFD8FFE5DCD3FFDED4CCFFD8CF
          C6FFD3CAC1FFCFC4BDFFBAACA2FF000000000000000000000000B0AB9EFFC7C0
          B6FFCCC4BBFFD3C9C1FFDAD0C7FFE1D7CFFFEBE1DAFFE4D9D1FFDCD1C9FFD5CC
          C2FFCEC6BDFFCAC1B9FFB2AB9FFF000000000000000000000000AFAA9DFFC8C1
          B7FFE8E3DBFFF5F0E8FFFDF8F2FFFCF8F1FFFBF7F0FFFCF7F1FFFCF8F1FFF6F0
          EAFFE9E2DBFFCAC2BAFFB0A99DFF000000000000000000000000AEA89CFFFBF5
          EFFFEEE7DEFFE0D8CEFFDDD5CCFFDDD4CBFFDDD4CBFFDDD4CBFFDDD5CCFFE0D7
          CEFFEDE6DEFFFBF6EFFFAEA89CFF000000000000000000000000AFA99DFFE1D8
          CEFFE1D7CEFFDFD6CCFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD6
          CCFFE1D7CEFFE1D8CEFFAFA99DFF0000000000000000000000006A675F99B6B0
          A4FFD6CFC4FFE6DED5FFEFE7DDFFEEE6DCFFEEE6DCFFEEE6DCFFEFE7DDFFE6DE
          D5FFD6CFC4FFB6B0A4FF6A675F99000000000000000000000000000000002322
          2033827D74BCAEA99CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA9
          9CFF827D74BC2322203300000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000001E0000003300000033000000330000001E00000000000000000000
          000A000000260000003300000033000000330000003300000033000000330000
          00331C2A79A9374DCCFF384DCBFF384DCCFF212F79AC0000001E0000001F2322
          205C837E75C9B0AA9EFFAFA99DFFAEA89CFFAEA89CFFB0AA9CFFB9B199FF6C76
          B8FF324ED9FF375CF9FF375DFAFF385DF9FF3852D7FF202E79AC6B6760ADB4AE
          A2FFC5BEB3FFD4CAC2FFE1D7CFFFE8DED6FFEFE4DDFFEDE2D8FFF0E3CEFF213C
          CEFF3E62FCFF3B60FAFF3A5DF8FF3C60FAFF4165FBFF344BCCFFB1AB9FFFC8C1
          B6FFCFC7BFFFD6CCC5FFDCD3CAFFE4D9D2FFEBE0D9FFE8DED4FFEEE0CAFF1F39
          CBFFA6B8FFFFFFFFFFFFFFFFFFFFFFFFFFFFA9BAFFFF3148CAFFB0AB9EFFC7C0
          B6FFCDC4BBFFD3CAC2FFDAD1C8FFE2D7CFFFECE1DAFFE7DBD1FFEBDDC9FF1C37
          CAFF5875FEFF5775FEFF5473FDFF5776FEFF5D79FFFF334ACBFFB0AA9EFFCAC3
          B9FFEAE5DDFFF7F3EBFFFFFBF4FFFDFAF3FFFDF9F2FFFFFAF3FFFFFFF3FF8993
          DDFF3954DEFF6C86FFFF728AFFFF6F89FFFF465EDDFF1F2D79976F6B64ADF9F3
          EDFFD8D1C9FFC2B8B0FFBFB6AEFFC5BAB2FFC8BEB5FFC6BCB3FFC4BAAFFFD1C5
          B2FF6771BAFF233ED0FF2942CEFF2F47CDFF1F2D799700000000706C64B4A39A
          8FFFBAB2A7FFCAC1B8FFDED5CCFFE5DBD3FFECE1DAFFE8DED5FFE1D7CEFFD1C6
          BBFFC6BBAAFFB4A790FF746D5AAB000000000000000000000000B1AB9FFFC9C2
          B9FFCFC7BFFFD5CCC4FFDCD3CAFFE3D9D1FFEADFD8FFE5DCD3FFDED4CCFFD8CF
          C5FFD3CBC1FFCEC6BAFFB7B09DFF000000000000000000000000B0AB9EFFC7C0
          B6FFCCC4BBFFD3C9C1FFDAD0C7FFE1D7CFFFEBE1DAFFE4D9D1FFDCD1C9FFD5CC
          C2FFCEC6BDFFCAC1B9FFB1AB9EFF000000000000000000000000AFAA9DFFC8C1
          B7FFE8E3DBFFF5F0E8FFFDF8F2FFFCF8F1FFFBF7F0FFFCF7F1FFFCF8F1FFF6F0
          EAFFE9E2DBFFCAC2BAFFAFA99DFF000000000000000000000000AEA89CFFFBF5
          EFFFEEE7DEFFE0D8CEFFDDD5CCFFDDD4CBFFDDD4CBFFDDD4CBFFDDD5CCFFE0D7
          CEFFEDE6DEFFFBF6EFFFAEA89CFF000000000000000000000000AFA99DFFE1D8
          CEFFE1D7CEFFDFD6CCFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD6
          CCFFE1D7CEFFE1D8CEFFAFA99DFF0000000000000000000000006A675F99B6B0
          A4FFD6CFC4FFE6DED5FFEFE7DDFFEEE6DCFFEEE6DCFFEEE6DCFFEFE7DDFFE6DE
          D5FFD6CFC4FFB6B0A4FF6A675F99000000000000000000000000000000002322
          2033827D74BCAEA99CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA9
          9CFF827D74BC2322203300000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000003300000033000000330000
          0000000000000000000000000000000000000000000000000000000000000000
          000A0000002600000033000000330000003350677AFF496684FF5090D9FF0000
          0033000000250000000A000000000000000000000000000000000000001F2322
          205C837E75C9B0AA9EFFB0AA9DFFB8AD9CFF54809FFF7FA6B6FF8ED5FFFF2D65
          9BFF908272C82523205C0000001F0000000000000000000000006B6760ADB4AE
          A2FFC5BEB3FFD4CAC2FFE2D8CFFFF2E1D5FF39ABF2FF89E5FFFF7FD3FFFF1099
          FFFF2D659BFFC8B6A0FF6F6960AD000000000000000000000000B1AB9FFFC8C1
          B6FFCFC7BFFFD6CCC5FFDDD3CAFFE9DBD1FFFCE6D7FF1F70C4FF3EC4FFFF2AAA
          FFFF159BFFFF2E659BFFC4B39EFF000000000000000000000000B0AB9EFFC7C0
          B6FFCDC4BBFFD3CAC2FFDAD1C8FFE3D8CFFFF3E4DAFFF9E1D0FF2372C3FF43C6
          FFFF2BABFFFF139BFFFF2A67A1FF000000330000000000000000B0AA9EFFCAC3
          B9FFEAE5DDFFF7F3EBFFFFFBF4FFFDFAF3FFFEFAF2FFFFFDF2FFFFFFF2FF2574
          C6FF41C7FFFF21ABFFFF83B0D7FF7E7871FF00000033000000006F6B64ADF9F3
          EDFFD8D1C9FFC2B8B0FFBFB6AEFFC5BAB2FFC8BEB5FFC7BCB3FFC7BAAFFFD7C2
          B1FF2176CCFFAEDBF1FF928880FFC1BFB8FF777C6EFF00000033706C64B4A39A
          8FFFBAB2A7FFCAC1B8FFDED5CCFFE5DBD3FFECE1DAFFE8DED5FFE1D7CEFFD3C5
          BAFFC7B8A9FF857F7AFFEAE8E5FF888C82FFBA7AB6FF9869CAFFB1AB9FFFC9C2
          B9FFCFC7BFFFD5CCC4FFDCD3CAFFE3D9D1FFEADFD8FFE5DCD3FFDED4CCFFD9CF
          C5FFD3CBC1FFCFC6BBFF7F817CFFE1B1E1FFCB96C6FFAE7DCEFFB0AB9EFFC7C0
          B6FFCCC4BBFFD3C9C1FFDAD0C7FFE1D7CFFFEBE1DAFFE4D9D1FFDCD1C9FFD5CC
          C2FFCFC7BDFFCAC3B8FFB0AE9AFFC187D7FFBE8AD3FF00000000AFAA9DFFC8C1
          B7FFE8E3DBFFF5F0E8FFFDF8F2FFFCF8F1FFFBF7F0FFFCF7F1FFFCF8F1FFF6F0
          EAFFE9E2DBFFC9C3B9FFAEAC99FF000000000000000000000000AEA89CFFFBF5
          EFFFEEE7DEFFE0D8CEFFDDD5CCFFDDD4CBFFDDD4CBFFDDD4CBFFDDD5CCFFE0D7
          CEFFEDE6DEFFFBF6EFFFAEAA9AFF000000000000000000000000AFA99DFFE1D8
          CEFFE1D7CEFFDFD6CCFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD5CBFFDFD6
          CCFFE1D7CEFFE1D8CEFFAFAA9DFF0000000000000000000000006A675F99B6B0
          A4FFD6CFC4FFE6DED5FFEFE7DDFFEEE6DCFFEEE6DCFFEEE6DCFFEFE7DDFFE6DE
          D5FFD6CFC4FFB6B0A4FF6A675F99000000000000000000000000000000002322
          2033827D74BCAEA99CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA89CFFAEA9
          9CFF827D74BC2322203300000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000033000000330000000E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000B5834BFFB48248FF3224146C0000001A00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000694B2A98FFFBE8FFD4B48CFF5B41239A0000001D000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000A1C140B45D2B087FFFFFFFFFFD1B085FF654826A6000000330000
          00330000003300000033000000260000000A0000000000000000000000000000
          0012241A0F5A7F5A31C1BC8A51FFFFFFEFFFFFFFF1FFCEA576FFB57E43FFB680
          46FFB68046FFB78247FF886237C9261C105D00000012000000000000000A4330
          1C7BBE8A53FFEAD0AEFFFFF5DEFFFFF7E1FFFFF6E1FFFFFAE5FFFFFDEAFFFFFE
          EBFFFFFFECFFFFF9E4FFEAD1AFFFBE8A53FF43301C7B0000000A271D1152C08C
          54FFF8E8CBFFFFF8E3FFFFF4DAFFFFF2D8FFFFF1D7FFFFF2D9FFFFF3D9FFFFF3
          D9FFFFF3DAFFFFF4DDFFFFF8E3FFF8E8CBFFC08C54FF271D11528D663CC9EBD1
          AEFFFFF7E1FFFFF0D4FFFFEED2FFFFEED2FFFFEED2FFFFEED2FFFFEED2FFFFEE
          D2FFFFEED2FFFFEED2FFFFF0D4FFFFF7E1FFEBD1AEFF8D663CC9C0884FFFFFFC
          E6FFFFEED3FFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEED3FFFFFCE6FFC0884FFFC18A4FFFFFF8
          E4FFFFEACCFFFFE8C8FFFFE8C8FFFFE8C8FFFFE8C8FFFFE8C8FFFFE8C8FFFFE8
          C8FFFFE8C8FFFFE8C8FFFFE8C8FFFFEACCFFFFF8E4FFC18A4FFFC38B50FFFFF7
          E4FFFFE8C9FFFFE5C2FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C3FFFFE5C3FFFFE5C2FFFFE8C9FFFFF7E4FFC38B50FFC68E54FFFFF9
          E8FFFFE9CAFFFFE3BCFFFFE3BEFFFFE3BEFFFFE3BEFFFFE3BEFFFFE3BEFFFFE3
          BEFFFFE3BEFFFFE3BEFFFFE3BCFFFFE9CAFFFFF9E8FFC68E54FF956B41BFEED1
          B1FFFFF4E1FFFFE1B9FFFFDFB6FFFFDFB7FFFFDFB7FFFFDFB7FFFFDFB7FFFFDF
          B7FFFFDFB7FFFFDFB6FFFFE1B9FFFFF4E1FFEED1B1FF956B41BF2A1E1334CE97
          60FFFAE6D0FFFFF4E3FFFFE6C4FFFFE2BDFFFFE2BDFFFFE2BDFFFFE2BDFFFFE2
          BDFFFFE2BDFFFFE6C4FFFFF4E3FFFAE6D0FFCE9760FF2A1E1334000000004935
          215AD09861FFF0D3B5FFFFF4E4FFFFFBEDFFFFFAEDFFFFFAEDFFFFFAEDFFFFFA
          EDFFFFFBEDFFFFF4E4FFF0D3B5FFD09861FF4935215A00000000000000000000
          00002B1F1434996F45BCCF945BFFCE945AFFCE935AFFCE935AFFCE935AFFCE93
          5AFFCE945AFFCF945BFF996F45BC2B1F14340000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000033000000330000000E000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000B5834BFFB48248FF3224146C000000190000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000694B2999FFFBE7FFD4B38BFF583F22980000
          00330000003300000033000000330000002A0000000700000000000000000000
          00000000000000000000000000052A1E1061D4B184FFFFFFFAFFD3B083FFB67F
          43FFB78145FFB78146FFB88347FF9A6F3FDB18120B4D00000007000000000000
          0033000000330000000B150F073EC18C52FFE7CEABFFFFFBE6FFFFFCE7FFFFFE
          EBFFFFFFECFFFFFFEDFFFFFFF0FFE5CAA6FFBF8D56FF19120B46000000004865
          D5FF4361D6FF0C1531609B6C33D1E8C9A2FFFFF9E3FFFFF3DAFFFFF2D9FFFFF2
          D8FFFFF2D7FFFFF2D7FFFFF3D9FFFFFAE4FFE7CAA6FF9E7242DB000000002839
          7C99DDFEFFFF7AA0F3FFC78641FFFFFDE6FFFFEFD2FFFFEDD0FFFFEDD0FFFFED
          D0FFFFECD0FFFFECCEFFFFECCEFFFFEFD1FFFFFDE8FFC18850FF000000061017
          31617EA1EAFFE4FFFFFFC48241FFFFF5DDFFFFE9C9FFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9CAFFFFE8C8FFFFE7C5FFFFE8C6FFFFF6E0FFC28A51FF0A0E1B445073
          DFFF9EC8F5FFD3FFFFFFC78241FFFFF6E4FFFFE6C3FFFFE6C2FFFFE6C3FFFFE6
          C3FFFFE6C3FFFFE6C3FFFFE5C2FFFFE5C1FFFFF9E8FFC68D54FF405EBADB98C2
          F4FFCDFFFFFFC3FCFFFFC8A275FFF0CDAAFFFFF0DAFFFFE0B7FFFFDEB4FFFFDE
          B4FFFFDEB4FFFFDEB4FFFFE0B7FFFFF1DCFFECCBAAFFA6784AD34C72E4FFD2FF
          FFFFB7F3FFFFB8F4FFFFBAE2E8FFD1955BFFEEC8A3FFFFFBEDFFFFF3DEFFFFF3
          DFFFFFF4DFFFFFF4E0FFFFFDF0FFEDCDACFFD09963FF1B130C214E76E7FFC7FA
          FFFFA9ECFFFFAEEDFFFFADF0FFFFB2DFE8FFCAA478FFD58A48FFD48B49FFD38B
          4AFFD48D4BFFD5924FFFD39456FFAA7A4CD01B140D2100000000517BE9FFD2FD
          FFFFA0E9FFFFA2E8FFFFA2E9FFFFA1EBFFFFA0EDFFFF9FEFFFFF9BEEFFFF99ED
          FFFFCBFFFFFF4079FCFF00000000000000000000000000000000476BC3D3A4CD
          FAFFC3F3FFFF8FE1FFFF8CE0FFFF8CE0FFFF8CE0FFFF8BE0FFFF8EE3FFFFC2F5
          FFFF9BC6FBFF4269C7D1000000000000000000000000000000000C111F215E8B
          F1FF9FC7F9FFDDFEFFFFC7F6FFFFC7F6FFFFC7F6FFFFC7F6FFFFDDFEFFFF9FC7
          F9FF5F8BF1FF0C111F2100000000000000000000000000000000000000000C12
          1F214A71C7D25788F3FF5787F3FF5787F3FF5787F3FF5787F3FF5788F3FF4A71
          C7D20C121F210000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000AFB1B3FFB1B8C1FFB69C6CFFBB80
          1EFFBB7C16FFC17B15FFC57B14FF442C08AF0000004600000000000000300000
          003300000033000000330000003300000033FEFEFEFFC69034FFC68516FFE2A0
          2FFFEEA231FF9BB750FF19D482FFA5902BFFAC7819F800000034AE7B18F2B67E
          0EFFB47B09FFB47A07FFB47A08FFB47B08FFDBBC88FFC68314FFEDAD42FFF4AC
          42FFFEA73CFF38D583FF00E79FFF00E69DFFAF8D26FF546323DEB67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB9760BFFB2BD5BFFFAB651FFCBBF
          61FF01E9A0FF44D583FF76C568FFB2AE47FFC29F2FFFBE7F19FFB47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFD6BDA2FFB56D00FF96DA86FFFEC979FF51E1
          94FF00EDA5FF00E59BFFFBAD45FFF8A336FFB5AB3DFFBF7E18FFB47A08FFFFFF
          FFFFFFFFFDFFFFFFFDFFFFFFFFFFD7BEA0FFB36D00FFFFD38BFFFEDCA7FF52ED
          B1FF00ECA4FF00E69CFF60CD76FFFEA738FF39C970FFC37D16FFB47B08FFFFFF
          FFFFD4B999FFD5BA9AFFD6BC9EFFD8BFA1FFB67607FFF6CE8AFFFEEDCBFF82F3
          C7FF28EFB6FF00E8A2FF8FC569FFE3AD44FF01D07FFFC57D16FFB47B08FFFFFF
          FFFFFFFDF2FFFFFEF3FFFFFFF7FFD7BB9AFFD3B37DFFCB8B1FFFFEF3DAFFA1FD
          E1FFECE1B0FF75E4A9FF48D688FF00DF93FF919634FF63410C82B47B08FFFFFF
          FFFFFFFBEBFFFFFCECFFFFFFF0FFD7BA96FFF1F5FCFFBF8525FFB98F25FF69F3
          C7FF7AFCD5FF63E7A8FF00DD8DFFA7922EFFC67D14FF00000000B47B08FFFFFF
          FFFFD4B38CFFD5B58FFFD7B892FFD8BA95FFEAEBEEFFF7FCFEFFE3BF89FFC479
          09FFC16F00FFC36F00FFC77910FFE2C08CFFB77B09FF00000000B47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFBE5FFD6B78FFFFFFBE6FFFFFBE6FFD6B78FFFFFFB
          E6FFFFFBE6FFD5B78EFFFFFAE3FFFFFFFFFFB47B08FF00000000B47B08FFFFFF
          FFFFFFF5D7FFFFF6D9FFFFF9DEFFD7B58BFFFFF9DFFFFFF9DFFFD7B58BFFFFF9
          DFFFFFF9DFFFD7B58AFFFFF8DBFFFFFFFFFFB47B08FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFDFB6
          83FFDFB683FFDDB684FFDBB37FFFFFFFFFFFB57B09FF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C7
          FFFF46C7FFFFE1B47EFF40C4FFFFFFFFFFFFB57C09FF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000AD7C17EFB67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67C09FFB67E0EFFAD7C17EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000003300000033000000330000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000024000000230000000000000000757371FF73716FFF757371FF0000
          0000000000000000002F00000023000000000000000000000000000000000000
          002352514FC1514F4FBF0000002F00000033716F6DFFEEECEBFF716F6DFF0000
          0033000000336E6C6AF151504FC0000000240000000000000000000000005352
          50BFA19F9DFF9E9C9AFF696765EF716F6DFF898785FFE1DFDEFF898785FF716F
          6DFF72706EFE9F9D9BFFA19F9DFF545251BD0000000000000000000000007170
          6EED9F9D9BFFDFDDDBFFB8B6B4FFDBD9D7FFD8D6D4FFD6D4D2FFD8D6D4FFDBD9
          D7FFB8B6B4FFDFDDDBFF9F9D9BFF545251AF0000000000000000000000000000
          0000767572FEB7B3B3FFD2D0CFFFD1CFCFFFD3D1D0FFD3D1D0FFD3D1D0FFD1CF
          CFFFD2D0CFFFB7B3B3FF6E6C6AEF000000000000000000000000000000330000
          0033787674FFD2D0CEFFCECCCAFFBEBCBAFF92908EFF8D8B89FF92908EFFBEBC
          BAFFCECCCAFFD2D0CEFF787674FF000000330000003300000000817F7DFF7C7A
          78FF9D9B99FFCCC9C8FFCCC9C8FF93918FFF4B49489C111110224B49489C9391
          8FFFCCC9C8FFCCC9C8FF9D9B99FF7C7A78FF817F7DFF00000000817F7DFFE3E1
          DFFFDCDAD8FFC6C5C2FFC8C6C4FF8F8D8BFF1111113D000000071111113D8F8D
          8BFFC8C6C4FFC6C5C2FFDCDAD8FFE3E1DFFF817F7DFF00000000848280FF807E
          7CFF949492FFD0CECCFFC3C0BFFF93918FFF4D4D4BAD1211114E4D4D4BAD9392
          90FFC3C0BFFFD0CECCFF949492FF807E7CFF848280FF00000000000000000000
          0000807E7CFFDAD9D8FFBEBBB9FFBCB9B7FF94918EFF928F8DFF94918FFFB3B2
          B0FFBEBBB9FFDBD9D8FF807E7CFF000000000000000000000000000000000000
          00237A7775EFACAAA8FFC7C5C3FFBBB8B7FFBAB7B6FFBBB8B7FFBBB8B7FFBBB8
          B7FFC7C5C3FFACAAA8FF797775EF000000230000000000000000000000005F5D
          5CBAA4A2A0FFDAD8D7FFC6C4C2FFE4E3E1FFDBD9D7FFC2BFBEFFD7D5D4FFE4E3
          E1FFC5C4C2FFDAD8D7FFA4A2A0FF5F5D5CBA0000000000000000000000006160
          5EB2B2B1AFFFAFAEACFF7B7977EB868482FF9A9897FFBCBAB7FF9A9897FF8684
          82FF848280FEAFAEACFFB2B1AFFF61605EB20000000000000000000000000000
          0000626160B2615F5EAF00000000000000008B8987FFE9E7E7FF8B8987FF0000
          00000000000082807EED61605FB0000000000000000000000000000000000000
          000000000000000000000000000000000000908E8CFF8F8D8BFF908E8CFF0000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000A89D8FFFBBB3ABFF0000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000D6C4A9FF82541AFFA57E4EFFD9CD
          C0FF000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000A68859FFC8A171FFBE9A6DFFB29D
          84FFF6F7F6FF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000AE9D84FFC3AF96FFAD997BFFC1B2
          9FFFF6F6F5FF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000A29EA1FFDFDEDDFFD6D3D2FFDCDB
          DBFFE6E5E6FF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000989494FFE0DFDFFFD6D6D8FFD3D1
          D0FFE2E2E2FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000009C9493FFDED7D2FFC7AE96FFC7C1
          C0FFE3E3E3FF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000817C7FFFE2DAD2FFCFA871FFBABA
          BFFFE1E1E1FF0000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000082828FFFE3D9D2FFD1A76BFFB5B9
          C8FFE6E7EAFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000A56800FFD8B074FFD5B473FFB079
          1CFFF1EADCFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000AF5900FFD29539FFBF8621FFBA68
          00FFF2E6CCFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000897E6EFFAAA49EFFA59B92FFB1A5
          93FFDBDBDCFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000706E78FF94939CFF9998A2FFA09F
          A8FFDEE0E3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000F7F0E0FF927845FFB69860FFA88A53FFB398
          68FFDCD4C7FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000EBC76FFFD98F00FFD68C00FFD88E00FFCF7C
          00FFC29447FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000EED89FFFDAA52CFFD8A12BFFD79B1EFFD396
          19FFD6B683FF0000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000002A0000003300000033000000330000002E000000050000
          00000000002A0000003300000033000000330000002E00000007000000300000
          003300000033514F4FDB6B6968FF757370FF696766FF2D2B2AEA050505460000
          0033302F2FDA383635FF6A6867FF62605FFF4A4847EC0C0B0B4DAF7B17F2BE82
          0CFF7D7054FFACABACFFD7D5D4FFC1C0BFFF8D8B8BFF3E3C3CFF453B2AFF614E
          2CFF555353FF817F7DFFAFADABFFAAA8A6FF92908DFF5A5857FDB87F0FFFFFFF
          FFFF68686BFFE5E4E4FF82817FFF6A6866FF535251FF838180FF787777FF7775
          76FF706E6EFF5A5858FF686664FF52504FFFAAA8A6FF716F6DFFB67D0AFFFFFF
          FFFF6D6C6CFFE9E7E8FF7C7B79FFBCAB9BFF686665FFFFFFFFFFECEAEAFFE3E2
          E1FFC3C1BFFF7A7877FFD6D6D3FF504E4DFFB1AFAEFF817F7EFFB67C09FFFFFF
          FFFF727171FFFFFFFFFF7F7D7BFF636260FF7B7978FF7D7B79FF7C7B79FF7D7B
          7AFF7D7B7AFF7C7A78FF656362FF565451FFDBD9D8FF807E7CFFB57C09FFFFFF
          FFFF918880FFB0B0AEFFFCFBFBFFE6E5E4FFE4E3E2FFAAA9A8FF7F786FFF8F88
          7EFFB0AFAFFFFFFFFFFFF1EFEEFFE7E5E5FFAFAEADFF666464D2B47B08FFFFFF
          FFFFFFFBEEFF9B9995FF757475FF717172FF6A6A6BFF8F8E8CFFDCC09EFFFFFF
          F6FFA4A19DFF757576FF767676FF79797BFF8F7F62FF00000000B47B08FFFFFF
          FFFFFFFEEDFFFFFFF2FFFFFFF6FFE0C29CFFFFFFF8FFFFFFF8FFDBBE9AFFFFFF
          F4FFFFFFF5FFDFC09BFFFFFFF6FFFFFFFFFFBD7E00FF00000000B47B08FFFFFF
          FFFFD5B48CFFD6B690FFD8B994FFDABB97FFD9BA94FFD8B994FFD9BA96FFD7B8
          93FFD8B994FFD9BB95FFD8B891FFFFFFFFFFB67C06FF00000000B47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFBE5FFD6B78FFFFFFBE6FFFFFBE6FFD6B78FFFFFFB
          E6FFFFFBE6FFD5B78EFFFFFAE3FFFFFFFFFFB47B08FF00000000B47B08FFFFFF
          FFFFFFF5D7FFFFF6D9FFFFF9DEFFD7B58BFFFFF9DFFFFFF9DFFFD7B58BFFFFF9
          DFFFFFF9DFFFD7B58AFFFFF8DBFFFFFFFFFFB47B08FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFDFB6
          83FFDFB683FFDDB684FFDBB37FFFFFFFFFFFB57B09FF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C7
          FFFF46C7FFFFE1B47EFF40C4FFFFFFFFFFFFB57C09FF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000AD7C17EFB67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67C09FFB67E0EFFAD7C17EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000003000000033000000330000003300000033000000330000
          0033000000330000003300000033000000330000003300000030000000000000
          000000000000AD7B18F1B67E0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A
          08FFB47A08FFB47B08FFB47A08FFB47B09FFB67E0EFFAE7B18F2000000000000
          000000000033B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000000000
          0000B88317FFB37904FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7BFA4FFFFFF
          FFFFFFFFFFFFD7BFA4FFFFFFFFFFFFFFFFFFFFFFFFFFB47B09FF000000330000
          0033B57E0EFFFFFFFFFFAC6D00FFDAC4ACFFD8C0A4FFD8BFA2FFD9C1A3FFD8BF
          A1FFD8BFA1FFD9C1A3FFD7BE9FFFD5BC9CFFFFFFFFFFB47B08FFB47C0BFFB37A
          09FFAF7400FFFFFFFFFFFFFFFFFFAC6D00FFFFFFFFFFFFFFFFFFD7BC9EFFFFFF
          FCFFFFFFFCFFD7BC9DFFFFFFFBFFFFFFF7FFFFFFFFFFB47B08FFFFFAE5FFFFFA
          E4FFFFF7DEFFFFFAEBFFFFFAEBFFFFFFFFFFAD6E00FFFFFFFEFFD7BC9AFFFFFF
          F4FFFFFFF4FFD7BB98FFFFFFF3FFFFFDEFFFFFFFFFFFB47B08FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFF5E0FFFFF6E0FFFFFFFFFFAD6F00FFD9BD9DFFD9BC99FFD7B9
          95FFD7B995FFD8BB97FFD6B893FFD4B58FFFFFFFFFFFB47B08FFB47A08FFB37A
          06FFAF7300FFFFF8E1FFFFFFFFFFAA6B00FFFFFFF0FFFFFEECFFD7B991FFFFFC
          E8FFFFFCE8FFD7B890FFFFFBE6FFFFF8E2FFFFFFFFFFB47B08FF000000000000
          0000B57D0DFFFFFFFFFFAC6D00FFFFFCE7FFFFF9E2FFFFF9E1FFD7B58CFFFFF9
          E1FFFFF9E1FFD7B58CFFFFF8DFFFFFF5DAFFFFFFFFFFB47B08FF000000000000
          0000B88317FFB37803FFFFFFFFFFDEB482FFE0B581FFE0B683FFDEB787FFDFB6
          84FFDFB684FFDEB787FFDFB582FFDDB27DFFFFFFFFFFB57B09FF000000000000
          000000000000B57B08FFFFFFFFFF44C4FFFF49C5FFFF47C6FFFFE3B57EFF46C7
          FFFF46C7FFFFE3B57EFF46C6FFFF44C4FFFFFFFFFFFFB57C09FF000000000000
          000000000000B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000000000
          000000000000805B11B0B67E0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67B08FFB67C09FFB67E0EFFAD7C17EF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000300000
          0033000000330000003300000033000000330000003300000033000000330000
          0033000000330000003300000030000000000000000000000000AE7B18F2B67E
          0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A08FFB47A08FFB47B08FFB47A
          08FFB47B09FFB67E0FFFAE7B18F2000000000000000000000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFB67F10FF000000000000000000000000B47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFD7BFA4FFFFFFFFFFFFFFFFFFD7BFA5FFFFFF
          FFFFFFFFFFFFD3AF69FFB47B09FF000000330000000000000000B47B08FFFFFF
          FFFFD5BB9CFFD6BC9CFFD8BEA0FFD9C1A3FFD8BFA1FFD8BFA1FFDBC3A8FFDCC6
          AFFFDDC9B6FFB07300FFFFFFFFFFB37906FF0000003300000000B47B08FFFFFF
          FFFFFFFEF7FFFFFFF7FFFFFFFBFFD7BC9DFFFFFFFCFFFFFFFDFFDAC1A7FFAF72
          00FFAF7200FFCFA85AFFFFFFFFFFFFFFFFFFB27904FF00000033B47B08FFFFFF
          FFFFFFFCEEFFFFFDEFFFFFFFF3FFD7BB98FFFFFFF4FFFFFFF5FFD8BD9CFFFFFF
          F6FFFFFFF4FFFFFCEEFFFFF8E8FFFFFAECFFFFFFFFFFB67E0EFFB47B08FFFFFF
          FFFFD4B48EFFD5B691FFD7B994FFD8BB97FFD7B995FFD7B995FFD8BB99FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFF4DDFFFFF6E1FFFFFFFFFFB67E0EFFB47B08FFFFFF
          FFFFFFF8E1FFFFF9E3FFFFFCE7FFD7B890FFFFFCE8FFFFFDE9FFD9BC96FFAD70
          00FFAE7000FFCEA34EFFFFF7DFFFFFFFFFFFB27804FF00000000B47B08FFFFFF
          FFFFFFF5D9FFFFF6DCFFFFF9E0FFD7B58CFFFFF9E1FFFFFAE1FFD9B890FFFFFF
          ECFFFFFFF1FFB07300FFFFFFFFFFB37906FF0000000000000000B57B09FFFFFF
          FFFFDDB17DFFE0B47FFFE0B683FFDEB787FFDFB684FFDFB684FFDEB887FFE0B7
          86FFE0B889FFD7B16CFFB57B08FF000000000000000000000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C6
          FFFF45C6FFFFFFFFFFFFB67D0BFF000000000000000000000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFB67E0FFF000000000000000000000000805B11B0B67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67C09FFB67E0EFF805B11B0000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000090000
          000E0000000F0000000F0000000F0000000F0000000F0000000F000000100000
          0010000000100000001000000010000000100000000F0000000A7B574BC1AC79
          68FFAC7968FFAB7968FFAB7968FFAB7968FFAA7968FFAA7969FFAA7969FFA979
          69FFA97969FFA97969FFA97A69FFA97A6AFFA87A6AFF78584CC1B27967FFF9F3
          EFFFF9F3EEFFFAF3EEFFFAF3EEFFFAF3EDFFF9F3EEFFF9F3EEFFF9F2EEFFF9F2
          EDFFF9F2EDFFF9F2EDFFF9F2EEFFF9F3EDFFF9F2EDFFB07764FFB37B69FFFAF3
          EFFF78675FFF443026FF7A6961FFA0938CFFF5EEEAFFF9F3EFFF9F928DFF5E4D
          46FFC5BCB6FF44322AFF44322AFFD3CAC4FFF9F2EEFFB17966FFB47C6AFFFAF5
          F0FF75645CFF75635CFFEDE6E1FF503C33FF817169FFFAF3EFFFF9F3F0FFFAF3
          EFFF6C5C55FF38251DFFDFD8D2FFF9F3EFFFF9F3EFFFB27A67FFB57E6CFFFAF5
          F1FFFAF5F1FFFAF4F1FFFAF5F0FF82726BFF473228FFCBC2BCFFFAF4F0FFFAF4
          F0FF877972FF47352CFFFAF4F0FFFAF4EFFFFAF4EFFFB37B69FFB7806EFFFAF6
          F2FFFAF6F2FFFAF6F1FFFAF5F1FFAC9F98FF49332AFF92837CFFFAF5F0FFFAF5
          F0FF55423CFF54433CFFE1DAD4FFFAF5F1FFFAF4F0FFB57D6AFFB88270FFFBF6
          F3FFFBF7F3FFFBF6F2FFFBF6F2FFD4CBC7FF4B362BFF68554CFFEEE8E3FF6354
          4BFF3D2A21FFAFA49EFF897B74FF63514BFFFAF5F1FFB67F6DFFB98472FFFBF7
          F3FFFCF7F3FFFBF7F4FFFBF7F3FFF5F0ECFF533E34FF4D362DFFE6DFDCFFFBF6
          F2FFFBF6F2FFFBF6F2FFFBF6F2FFFBF6F2FFFAF5F2FFB7806EFFBB8674FFFCF8
          F5FFFCF8F5FFFCF8F4FFFBF7F4FF503A30FF513930FF4F3930FF4F392FFF4F37
          2EFFFBF7F4FFFBF7F3FFFBF6F3FFFBF6F3FFFBF7F3FFB88270FFBC8976FFFCF8
          F6FFFCF9F5FFFBF8F5FFFCF8F5FFFCF8F5FFD6CEC9FF513B31FF79675EFFFBF8
          F5FFFCF7F4FFFBF7F5FFFBF8F4FFFBF7F4FFFBF7F4FFBA8473FFBE8B78FFFCF9
          F7FFFCF9F6FFFCF9F6FFFCF8F6FFFCF9F6FFFCF8F6FF91827AFF553F35FFEAE4
          E0FF827168FF827169FFFCF8F5FFFCF8F5FFFCF8F4FFBB8774FFBF8C7AFFFDFA
          F8FFFCFAF7FFFCFAF7FFFDFAF7FFFCF9F7FFFDFAF6FFFBF7F4FFAA9E97FF8271
          69FF543F34FF7F6E66FFFCF9F6FFFCF9F6FFFCF8F6FFBD8977FFC08F7DFFFDFA
          F8FFFDFAF8FFFCFBF8FFFCFAF7FFFDFAF7FFFCFAF8FFFCFAF8FFFDF9F7FFFCFA
          F8FFFDF9F7FFFCF9F7FFFCF9F6FFFCF9F6FFFCF9F7FFBE8B78FF98766AC0CD9F
          8EFFCC9F8EFFCC9F8EFFCC9F8DFFCC9E8DFFCB9E8DFFCB9D8CFFCB9D8CFFCA9C
          8BFFCA9C8BFFCA9B8AFFC99A89FFC89A88FFC89988FF947264C1000000030000
          0004000000050000000500000005000000050000000500000005000000050000
          0005000000050000000500000005000000050000000500000003}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000414141473636
          363602020202000000000000000010101010AFAFAFB3F3F4F4FFCBCBCBD20505
          050526262626DBDBDBFCCFCFCFFF8787879A2626262600000000C5C8CAFF9599
          9CDF1F1F1F1F000000000000000013131313C7C7C7C9B6B5B5FF929291F15C5B
          5B6717171717ABABABE66C6C6CFF797A7AFFC1C1C1E744444444818487BB7C86
          8CFF818586AD3C3C3C3C27272728525151799FA1A2E7989A9BFF4A4D4EFF838A
          91F45B5B5E624342424A797979E6454545FF6E6E6FFFD6D6D6E9161717177F83
          85BB939C9FFFA4A5A5DE959594D67E7F7FFF515557FF555D60FF5F6B70FF535E
          67FF97989AEE5454545C9D9D9DB96F7172FF20282BFF97989AFF000000003232
          32329B9FA1EB6F777DFF6C747DFF6F7579FF595B5DFF293236FF536269FF898E
          8EFFA3A1A1FFBEBEBEF7EBE8E9F2D6D2D5FF4F565CFF404648FF000000002525
          2525A6A8A8E24A5A69FF3D5472FF52627BFF545E62FF354246FF3C484CFF7075
          79FFA6A7AAFFE8E9E8FFC3C8C5FFC7CEC7FF949E9DFF354146FF000000002626
          262A858D8EE4435561FF3A516EFF31455DFF33444AFF304148FF4F595FFF8D91
          94FF78787BB09797969B419E76E812AE6DFF53A180FF535A65FF000000007677
          778365757CF9344248FF394248FF2F4049FF30454BFF263E53FF586879FFAAAB
          ACFF89898CAB3C35323E00713DAB00E89DFF4AB789FF6F6F79FF000000007374
          758252666EF92C3E45FF2C3539FF19282EFF304147FF36495DFF45576DFF434E
          55FF727784FF979292B81B8E5FC900DB9BFF38A377FF7F7F87FF000000001D1D
          1D2C566064E8263842FF18262EFF081920FF29383EFF3C4247FF434F55FF606D
          73FF5A616BFF7B8081FC34AD7EFD05D79EFF17865DFF97959DED000000001414
          14147E7E7EB63E4F56FF122832FF0A1E26FF192830FF323D42FF4C585CFF6976
          7BFF70767EFF535D60FF24986DFF0DD4A0FF44AE83FF4E474A5B000000001C1C
          1C1C89898AC0374B54FF0E2934FF0C222CFF192B32FF283B43FF44565CFF5B6B
          70FF6E747EFF5E6269FF2F966EFF21DBADFF218458C908080808000000001F1F
          1F1F8C8D8FC55B6B72F8344A53FF172D36FF162B34FF22353EFF2B3E46FF4B59
          61FF56676BFF306652FF1A9C6FFF1ED8B0FF007547CA00261160000000000000
          000022222225404143576D7174A5828E92FF20343CFF152831FF1A2F38FF2D3A
          44FF3B5751F5269E6BF320C9A4FF00BD9CFF29CBA6FF1A8D58E9000000000000
          000000000000000000000E0E0E0E77777887707779DD3E4F56FF0C2029FF3A45
          4BFF7B7C7DCD18422B613FB390EB4FD9C3FF3DAA88E60D291B48000000000000
          0000000000000000000000000000000000001D1D1D1D6A6D6E899EA6A8FDADB0
          B1FF625F6066000000000C3D246732A36FE6082D185100000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000001000000060000000F000000100000000500000000000000030000
          000C000000110000000C00000003000000000000000000000000000000010000
          00040000000E1E0E064B723315CAAE5827FF00000012000000000000000B8753
          32C3BA7143FF854F2FC40000000C0000000000000001000000030000000B130A
          0536653117B2AF6133FFD99E60FFAF592CFF00000016000000000000000FBF7C
          4EFFEEC892FFBC7345FF0000001100000002000000080A0503235A311A9BAD62
          38F9D5985EFFEDB975FFEEBB78FFB05D2FFF00000015000000000000000FC384
          57FFF0CC97FFBD7749FF00000017040301164B2C1980AB663CF2D39864FFEDBF
          81FFEFBF7BFFEDBB76FFEDBF7FFFB26333FF00000014000000000000000EC98B
          60FFF1D09DFFBF7A4DFF3A241770A36840E2D49B6BFFEFC790FFF3C98DFFF0C2
          83FFEFC17FFFEDBC7BFFF1C489FFB56737FF00000013000000000000000DCD94
          68FFF3D4A2FFC17F51FFCA9C77FFF2D2A6FFF8D5A2FFF5CE96FFF4CB92FFF4C9
          8CFFF2C686FFF0C081FFF1CA91FFB8693CFF00000012000000000000000CCF9A
          6EFFF6D8A9FFC38256FFD1A786FFF6DFC0FFFAE4C0FFF8DAABFFF8D39DFFF5CE
          96FFF3C990FFF2C588FFF4CF9CFFBA7041FF00000011000000000000000BD29E
          73FFF8DBAFFFC6875CFF44302070B37F58E4E1BA96FFFAE6CCFFFBE4C1FFF8D7
          A4FFF5CE96FFF4C98CFFF5D3A6FFBD7445FF000000100000000000000009D4A2
          78FFF9DDB4FFC88C5FFF0000000F05030211583E297DC0885FF1E7C4A4FFFBEA
          CDFFF8DDB3FFF5CC95FFF7DAAFFFBF774AFF0000000F0000000000000008D5A6
          7BFFFFF9EFFFCA9063FF0000000900000001000000050C08061B6D4B3396C993
          6BF8EBCCADFFF9E4C3FFF9E2BEFFC27E4EFF0000000E00000000000000059E7B
          5BC2CD9367FF976C4CC200000006000000000000000000000001000000061811
          0B2B7B5539A7D29C74FFEFD2B3FFC38254FF0000000D00000000000000010000
          0004000000060000000500000001000000000000000000000000000000000000
          000200000007261B123E906343BFC78558FF0000000900000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000200000006000000080000000200000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00040000000D0000000D00000005000000010000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000DB96F40FF773B1EC71E0F07480000000D0000000400000001000000000000
          000000000000000000030000000C000000110000000C00000003000000000000
          0010BC7546FFDFA873FFB46A3CFF67341AB0130905350000000B000000030000
          0001000000000000000B875332C3BA7143FF854F2FC40000000C000000000000
          000FC17C4CFFF3CE98FFF0C081FFD69B64FFAC6237F9582D169B090502240000
          0009000000020000000FBF7C4EFFEEC892FFBC7345FF00000011000000000000
          000EC38152FFF5D6A9FFF0C081FFEFC183FFEDC183FFD0945EFFA35D30F24725
          12820402011900000016C38457FFF0CC97FFBD7749FF00000011000000000000
          000DC58458FFF8DEB8FFF2C78AFFF2C688FFF0C283FFF0C484FFEBBD81FFCC8C
          57FF96522BE4381E0F74C98B60FFF1D09DFFBF7A4DFF00000010000000000000
          000CC98C5FFFFBE6C8FFF5CF95FFF4CB92FFF4C98CFFF2C686FFF0C082FFF0C3
          86FFEABB85FFC88756FFCD9468FFF3D4A2FFC17F51FF0000000F000000000000
          000BCC9164FFFCEDD4FFF7D49FFFF8D29CFFF5CE96FFF3CA91FFF3CA93FFF4D1
          A0FFEFCB9BFFCF9062FFCF9A6EFFF6D8A9FFC38256FF0000000E000000000000
          000ACE9569FFFDF3DFFFFAD9A8FFF8D6A5FFF8D8A5FFF8DDB4FFF6DDB8FFD9A8
          7DFFA66940E542281774D29E73FFF8DBAFFFC6875CFF0000000D000000000000
          0009CE9A6CFFFEF5E7FFFDE1B5FFFDE7C3FFFCECD0FFE4BF9DFFB97B51F15536
          2181040302140000000ED4A278FFF9DDB4FFC88C5FFF0000000B000000000000
          0008D19D70FFFFFAEFFFFFF2DFFFEDD2B8FFC99069F86C472F960C08051C0000
          00060000000100000008D5A67BFFFFF9EFFFCA9063FF00000009000000000000
          0007D3A073FFF4E4D6FFD7A780FF7B573CA518100B2900000006000000020000
          000000000000000000059E7B5BC2CD9367FF976C4CC200000006000000000000
          0005D5A276FF966E4CBD271C143A000000060000000200000000000000000000
          0000000000000000000100000004000000060000000500000001000000000000
          0001000000040000000400000002000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00040000000F0000000F00000007000000010000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000EB0683FFF834324E131190D6A000000110000000600000001000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0011B37045FFDEAF77FFB47247FF773C20D2201009500000000F000000050000
          0001000000000000000000000000000000000000000000000000000000000000
          0010B6764BFFECC38FFFE8BA7DFFD8A66FFFAD693FFF6A371CBE170C06400000
          000D000000040000000100000000000000000000000000000000000000000000
          000FBB7C51FFEFCD9CFFE9BB7FFFE8BC80FFEABE83FFD39D6CFFA7623BFD5B30
          1AA90D07032C0000000B00000003000000010000000000000000000000000000
          000EBE8257FFF1D5ACFFEBC087FFE9BF85FFE8BD81FFE9BF82FFE9C087FFCD97
          65FF9F5933F74E29169408040221000000090000000200000000000000000000
          000DC0855EFFF5DEBBFFEDC68FFFEDC58DFFEBC289FFEAC084FFE8BC80FFE9BD
          82FFE8BB87FFC78E60FF965430EE4223137E0000000900000000000000000000
          000CC59067FFF9E9CFFFF3D4A3FFF2D09FFFF0CC98FFEEC890FFEBC088FFE9BE
          83FFEAC38AFFECC693FFE3B889FFA65B33FF0000000D00000000000000000000
          000BC9956EFFFAEFDAFFF4DAAEFFF5D8AAFFF2D5A6FFF1D1A1FFF1D0A2FFF1D2
          A8FFEDCDA1FFCC956BFF9A5D39E33A2314680000000700000000000000000000
          000ACC9B73FFFCF4E3FFF8E0B7FFF6DDB4FFF6DEB4FFF7E2C0FFF6E1C1FFD9B2
          8CFFB0754EF14D301F7E04030216000000060000000100000000000000000000
          0009CDA077FFFEF7E9FFFBE7C2FFFBEBCCFFFBEFD6FFE3C5A7FFC08B65F96544
          2E960B07051E0000000600000002000000000000000000000000000000000000
          0008D0A47CFFFEFBEFFFFDF4E0FFEEDAC1FFD1A07DFF78553CA717100B2C0000
          0007000000020000000000000000000000000000000000000000000000000000
          0007D2A77FFFF5EADBFFD8B291FF916D50BE261C143C00000007000000020000
          0000000000000000000000000000000000000000000000000000000000000000
          0005D5AA83FFA98462D3372B204F000000070000000200000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0001000000040000000500000002000000010000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0002000000080000001200000012000000050000000000000000000000000000
          0000000000000000000000000000000000000000000000000002000000060000
          001332180C6E813C1CE0AC5A2DFF000000130000000000000000000000000000
          000000000000000000000000000000000001000000050000000F231209527E40
          20D4B67042FFDAA66DFFAE5E30FF000000170000000000000000000000000000
          00000000000000000001000000030000000C180E083C733E24BFB66F42FFD6A4
          6DFFE4B77BFFE4B77BFFB06034FF000000160000000000000000000000000000
          000100000002000000090F090529673E25A8B57548FDD7A674FFE7BF89FFE6BB
          80FFE5B87CFFE6B97FFFB26537FF000000150000000000000000000000010000
          00070906041C5B3B2590B4774EF7D8A87CFFECCA9AFFEAC38EFFE9C089FFE8BD
          84FFE7BA81FFE7BE86FFB4693AFF000000140000000000000000000000065139
          2978B17B54ECD7AA82FFEFD1A9FFEFCFA0FFEDC996FFECC793FFEBC490FFE9C1
          8AFFE7BE86FFE9C38FFFB56B3FFF00000013000000000000000000000009CB97
          6FFFF1DCC1FFF3DCB8FFF3D8AEFFF0D2A4FFF0CFA0FFEFD0A1FFEFCF9FFFEDCC
          9BFFEDC996FFEECDA0FFB87043FF000000120000000000000000000000044433
          2661AF815BE1DDB693FFF5E0C3FFF8E3C3FFF6DFB9FFF4DAAFFFF2D5AAFFF0D2
          A4FFEECE9DFFF1D5ABFFBA7648FF000000110000000000000000000000010000
          000405040311533D2B78BF8D67F1E3C2A2FFF8EACEFFF8E6C5FFF5DDB6FFF2D6
          ABFFF0D2A4FFF3DBB5FFBD784CFF000000100000000000000000000000000000
          000000000001000000050C09061B6B4E3894C79772F8E6C9AAFFFAEBCEFFF6E2
          BEFFF2D7ACFFF5E0BCFFBF7C52FF0000000F0000000000000000000000000000
          00000000000000000000000000010000000618120C2B7C583FA7D2A17BFFEBD2
          B4FFF8E6C8FFF8E7C9FFC18456FF0000000E0000000000000000000000000000
          0000000000000000000000000000000000000000000200000007261C133E9167
          4AC0D5A881FFEFDABDFFC3875BFF0000000E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000020000
          000936281C54A37453D5C68C63FF0000000A0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0001000000030000000800000008000000020000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000020000000A170D0738542D1894814626D193502AEA924F2AE87F45
          25D0522C17931209053000000009000000010000000000000000000000000000
          00030201011159311B97A96239FAC58957FFD6A36DFFDDAF75FFDDAF74FFD6A4
          6BFFC58956FFA46137F53C2112730000000F0000000300000000000000020201
          0110744226B9BC7C4DFFDDAE77FFDEB076FFE2B782FFE3BB87FFE3BC86FFE1B7
          82FFDEAF74FFDBAB72FFBD7E4EFF6F3E24B50000001000000002000000085C36
          2095BE8053FFE0B37CFFDFB076FFDEB177FFB78254FFAA7144FFAB7245FFBC88
          59FFDFB279FFDFB277FFDEB077FFC08253FF55321D920000000A190F0932B070
          47FADFB27DFFDFB27AFFE0B37BFFE0B57DFFA56B3FFFF5EFEAFFF8F3EEFFAB72
          45FFE2B67EFFE0B47CFFE0B47BFFDEB079FFB3734AFB130B072F613C2795CD9B
          6FFFE2B780FFE5BD89FFE7C291FFE8C393FFA56B3FFFF1E6DEFFF9F5F1FFAA71
          44FFE8C494FFE8C393FFE5BF8CFFE1B77FFFD09C6EFF5434218B935E3DD2DCB3
          83FFE3B781FFBA8659FFA97043FFAB7245FFAC7346FFF5EDE6FFFAF6F3FFAD75
          47FFB0784AFFB17A4BFFC29162FFE4B983FFDEB17EFF8E5B3BD0B0744CF2E3BF
          8FFFE4BB84FFA56B3FFFF3EBE6FFFAF6F3FFF6EFE8FFF7F0EAFFFBF7F5FFFAF7
          F4FFFAF7F3FFFAF6F2FFAB7245FFE5BD87FFE5BE8BFFAB714CEEAE764FECE9C9
          A0FFE5BE89FFA56B3FFFE0D2CAFFE1D3CCFFE3D5CFFFF2EAE4FFF8F3EFFFEADF
          D9FFE6DAD4FFE9DED9FFAA7144FFE7C08CFFEACA9DFFAE764FEE9A6A49D0E9CD
          ACFFEAC796FFB78456FFA56B3FFFA56B3FFFA56B3FFFF1EAE5FFFAF6F3FFA56B
          3FFFA56B3FFFA56B3FFFB78457FFEACA99FFEBD1ADFF996A49D46E4E3697DDBB
          9DFFEED3A9FFEECFA2FFEED2A5FFF0D6A9FFA56B3FFFF0EAE7FFFDFCFBFFA56B
          3FFFF1D6AAFFF0D5A8FFEED2A5FFEFD4A7FFE0C2A2FF6246318F1C140E2BC794
          6CFCF5E8CCFFEFD6ABFFF1D8AEFFF2DAB0FFA56B3FFFDECFC9FFDFD1CBFFA56B
          3FFFF3DCB2FFF1DBB0FFF1D8ADFFF7EACDFFC69470FA1A120D2E000000036F52
          3C92D7B08CFFF8EFD3FFF3E0B9FFF3DFB7FFB98A5FFFA56B3FFFA56B3FFFBA8A
          5FFFF4E1B9FFF4E2BDFFFAF1D5FFD9B390FF664B368C00000006000000010202
          0107906C4EB8D9B38FFFF7EDD3FFF8EED0FFF7EBC9FFF6E8C4FFF6E8C5FFF7EC
          CAFFF8EED0FFF4E8CDFFD7AF8BFF88664AB30202010B00000001000000000000
          00010202010770543F8FCFA078FCE2C4A2FFEBD7B8FFF4E9CDFFF4EACEFFECD8
          B9FFE3C5A3FFC59973F24C392A67000000060000000100000000000000000000
          000000000001000000022019122C6C543E89A47E5FCCC59770F1C19570EEA47E
          60CD6C543F8B16110D2200000003000000010000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000020000000A170D0738542D1894814626D193502AEA924F2AE87F45
          25D0522C17931209053000000009000000010000000000000000000000000000
          00030201011159311B97A96239FAC58957FFD6A36DFFDDAF75FFDDAF74FFD6A4
          6BFFC58956FFA46137F53C2112730000000F0000000300000000000000020201
          0110744226B9BC7C4DFFDDAE77FFDEB076FFDEAF75FFDEAF75FFDEB074FFDDAF
          75FFDEAF74FFDBAB72FFBD7E4EFF6F3E24B50000001000000002000000085C36
          2095BE8053FFE0B37CFFDFB076FFDEB177FFDFB279FFE0B379FFE0B27AFFE0B2
          79FFDFB279FFDFB277FFDEB077FFC08253FF55321D920000000A190F0932B070
          47FADFB27DFFDFB27AFFE0B37BFFE0B57DFFE1B67EFFE2B67FFFE2B77FFFE2B7
          7FFFE2B67EFFE0B47CFFE0B47BFFDEB079FFB3734AFB130B072F613C2795CD9B
          6FFFE2B780FFE5BD89FFE7C291FFE8C393FFE8C494FFE8C594FFE8C495FFE8C4
          95FFE8C494FFE8C393FFE5BF8CFFE1B77FFFD09C6EFF5434218B935E3DD2DCB3
          83FFE3B781FFBA8659FFA97043FFAB7245FFAC7346FFB0794AFFAB7245FFAD75
          47FFB0784AFFB17A4BFFC29162FFE4B983FFDEB17EFF8E5B3BD0B0744CF2E3BF
          8FFFE4BB84FFA56B3FFFF5EEE9FFFAF6F3FFFAF7F3FFFBF7F4FFFBF7F5FFFAF7
          F4FFFAF7F3FFFAF6F2FFAB7245FFE5BD87FFE5BE8BFFAB714CEEAE764FECE9C9
          A0FFE5BE89FFA56B3FFFE6D9D2FFE7DBD4FFE9DED7FFEAE0D9FFEAE0DAFFEBE1
          DBFFEBE0DBFFEEE5E1FFAA7144FFE7C08CFFEACA9DFFAE764FEE9A6A49D0E9CD
          ACFFEAC796FFB78456FFA56B3FFFA56B3FFFA56B3FFFA56B3FFFA56B3FFFA56B
          3FFFA56B3FFFA56B3FFFB78457FFEACA99FFEBD1ADFF996A49D46E4E3697DDBB
          9DFFEED3A9FFEECFA2FFEED2A5FFF0D6A9FFF1D7ABFFF1D8ADFFF1D8ADFFF1D8
          ADFFF1D6AAFFF0D5A8FFEED2A5FFEFD4A7FFE0C2A2FF6246318F1C140E2BC794
          6CFCF5E8CCFFEFD6ABFFF1D8AEFFF2DAB0FFF3DCB3FFF3DEB4FFF3DEB4FFF3DE
          B4FFF3DCB2FFF1DBB0FFF1D8ADFFF7EACDFFC69470FA1A120D2E000000036F52
          3C92D7B08CFFF8EFD3FFF3E0B9FFF3DFB7FFF4E1B9FFF5E3BBFFF5E2BBFFF5E2
          BBFFF4E1B9FFF4E2BDFFFAF1D5FFD9B390FF664B368C00000006000000010202
          0107906C4EB8D9B38FFFF7EDD3FFF8EED0FFF7EBC9FFF6E8C4FFF6E8C5FFF7EC
          CAFFF8EED0FFF4E8CDFFD7AF8BFF88664AB30202010B00000001000000000000
          00010202010770543F8FCFA078FCE2C4A2FFEBD7B8FFF4E9CDFFF4EACEFFECD8
          B9FFE3C5A3FFC59973F24C392A67000000060000000100000000000000000000
          000000000001000000022019122C6C543E89A47E5FCCC59770F1C19570EEA47E
          60CD6C543F8B16110D2200000003000000010000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000002000000070000000C0000001000000012000000110000
          000E000000080000000200000000000000000000000000000000000000000000
          000100000004000101120D2A1D79184E36C6216B4BFF216B4BFF216C4BFF1A53
          3AD20F2F21840001011500000005000000010000000000000000000000000000
          0005050F0A351C5B40DC24805CFF29AC7EFF2CC592FF2DC894FF2DC693FF2AAE
          80FF258560FF1A563DD405110C3D00000007000000010000000000000003040E
          0A31206548ED299D74FF2FC896FF2EC996FF56D4ACFF68DAB5FF3BCD9DFF30C9
          96FF32CA99FF2BA479FF227050F805110C3D00000005000000000000000A1A57
          3DD02EA57CFF33CA99FF2EC896FF4CD2A8FF20835CFF00673BFF45BE96FF31CB
          99FF31CB98FF34CC9CFF31AD83FF1B5C41D300010113000000020B23185E2E8A
          66FF3BCD9EFF30CA97FF4BD3A9FF349571FF87AF9DFFB1CFC1FF238A60FF45D3
          A8FF36CF9FFF33CD9BFF3ED0A3FF319470FF0F32237F00000007184D37B63DB3
          8CFF39CD9FFF4BD5A9FF43A382FF699782FFF8F1EEFFF9F3EEFF357F5DFF56C4
          A1FF43D5A8FF3ED3A4FF3CD1A4FF41BC95FF1B5C43CD0000000B1C6446DF4BCA
          A4FF44D2A8FF4FB392FF4E826AFFF0E9E6FFC0C3B5FFEFE3DDFFCEDDD4FF1B75
          4FFF60DCB8FF48D8ACFF47D6AAFF51D4ACFF247A58F80000000E217050F266D9
          B8FF46D3A8FF0B6741FFD2D2CBFF6A8F77FF116B43FF73967EFFF1E8E3FF72A2
          8BFF46A685FF5EDFBAFF4CD9AFFF6BE2C2FF278460FF020604191E684ADC78D9
          BEFF52DAB1FF3DBA92FF096941FF2F9C76FF57DEB8FF2D9973FF73967EFFF0EA
          E7FF4F886CFF5ABB9AFF5BDEB9FF7FE2C7FF27835FF80000000C19523BAB77C8
          B0FF62E0BCFF56DDB7FF59DFBAFF5CE1BDFF5EE2BEFF5FE4C1FF288C67FF698E
          76FFE6E1DCFF176B47FF5FD8B4FF83D5BDFF1E674CC60000000909201747439C
          7BFF95ECD6FF5ADFBAFF5EE2BDFF61E4BFFF64E6C1FF67E6C5FF67E8C7FF39A1
          7EFF1F6D4AFF288B64FF98EFD9FF4DAC8CFF1036286D00000004000000041C5F
          46B578C6ADFF9AEED9FF65E5C0FF64E7C3FF69E7C6FF6BE8C8FF6CE9C9FF6BEA
          C9FF5ED6B6FF97EDD7FF86D3BBFF237759D20102010C0000000100000001030A
          0718247B5BDA70C1A8FFB5F2E3FF98F0DAFF85EDD4FF75EBCEFF88EFD6FF9CF2
          DDFFBAF4E7FF78CDB3FF2A906DEA0615102E0000000200000000000000000000
          0001030A07171E694FB844AB87FF85D2BBFFA8E6D6FFC5F4EBFFABE9D8FF89D8
          C1FF4BB692FF237F60CB05130E27000000030000000000000000000000000000
          000000000001000000030A241B411B60489D258464CF2C9D77EE258867CF1F71
          56B00E3226560000000600000002000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000330000
          00330000003300000033000000330000002C0000000000000000000000000000
          00000000002F0000003300000033000000330000003300000033B47A07FFB57B
          08FFB67C09FFB87C0BFFB97F10FFA17115E10000000000000000000000000000
          0000AB7A18F0B67E0EFFB47B09FFB47A08FFB47B08FFB47A08FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFCB800FFF0000000000000000000000000000
          0000B67E0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF3E9862FF007F39FF00833FFF00894AFF0000003300000000000000000000
          0000B47B09FFFFFFFFFFFFFFFFFFFFFFFFFFD6BDA2FFFFFFFFFFFFFFFEFFFFFF
          FFFF007E36FF00DFA5FF00E0A7FF00BF84FF008A4AFF00000033000000000000
          0000B57A07FFFFFFFFFFFFFFFEFFFFFFFFFFD7BEA0FFFFFFFFFFD7BB9BFFE4C0
          A3FF419962FF007F39FF007F3AFF09BF8BFF00BC84FF008A4AFF000000330000
          0000B77B07FFFFFFFFFFD4B999FFD6BC9DFFD8BFA1FFD6BC9EFFFFFEF4FFFFFF
          F9FFE4BEA0FFFFFFFFFFFFFFFFFF00813DFF24C79CFF00B885FF008B4CFF0000
          0033BD7A06FFFFFFFFFFFFFEF3FFFFFFF6FFD7BB9AFFFFFFF7FFFFFCEDFFFFFF
          F1FFD9BA97FFFFFFF0FFFFFFFFFFD07800FF008848FF44CEACFF00B486FF0089
          4AFFCC7901FFFFFFFFFFFFFDEDFFFFFFF1FFD7BA97FFFFFFF0FFD5B590FFD7B8
          92FFD8B994FFD6B68FFFFFFFFFFFC47A04FF00000000008948FF5FD3B9FF00B0
          83FF00823DFFFFFFFFFFEDBC98FFE6BD9AFFDEBC98FFD7B893FFFFF8E2FFFFFB
          E5FFD5B78EFFFFFAE3FFFFFFFFFFBB7A06FF0000000000000000008947FF79D9
          C6FF00AA7EFF00823AFF00833CFF52B481FFE5BD97FFFFFBE6FFFFF6DAFFFFF9
          DEFFD7B58AFFFFF8DBFFFFFFFFFFB77B08FF0000000000000000000000000089
          48FF91E0D5FF00BCA7FF00BDA9FF00843DFFEBBC94FFFFFADFFFE1B47FFFE0B6
          82FFDDB684FFDBB37FFFFFFFFFFFB67B08FF0000000000000000000000000000
          0000008949FF00843CFF008337FF499958FFECBB8BFFE2B683FF4BC6FFFF47C6
          FFFFE1B47EFF40C4FFFFFFFFFFFFB67C09FF0000000000000000000000000000
          0000C67E0AFFFFFFFFFF59C9FFFF54C9FFFFE8B680FF47C7FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF0000000000000000000000000000
          0000B97F0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67B07FFB67B
          08FFB57B08FFB67C09FFB67E0EFF8F6613C50000000000000000000000000000
          00009D7015D8B67E0EFFB67C09FFB67B08FFB57B08FFB67B08FF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000E99F7FFFD882
          64FFD88264FFD68066FFD68066FFD67E64FFD67E64FFD77E63FFD58063FFD57D
          63FFD57D63FFD37F63FFD37F63FFD67D62FFE69D7AFF00000000DA836CFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD68066FF00000000DE886EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2DBDAFFE5CDCAFFDCD9D9FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD98369FF00000000DD8D75FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9282FFFF573EFFFF523AFFFF6049FFF3B3
          ABFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD9886DFF00000000E09078FFFFFF
          FFFFFFFFFFFFFFFFFFFFFEA396FFFF523AFFFF806FFFF3B3ABFFFF6753FFFF59
          42FFE4D4D1FFFFFFFFFFFFFFFFFFFFFFFFFFDD8A71FF00000000E1967DFFFFFF
          FFFFFFFFFFFFFFFFFFFFFF7360FFFF533BFFE5DBD9FFFFFFFFFFFFA093FFFF52
          3AFFFF9788FFFFFFFFFFFFFFFFFFFFFFFFFFE09176FF00000000E69A80FFFFFF
          FFFFFFFFFFFFFFFFFFFFFF5D47FFFF5F4AFFFFFFFFFFFFFFFFFFEBC3BDFFFF52
          3AFFFF8272FFFFFFFFFFFFFFFFFFFFFFFFFFE1937BFF00000000E79E85FFFFFF
          FFFFFFFFFFFFFFFFFFFFFF5740FFFF6652FFFFFFFFFFFFFFFFFFE7CEC9FFFF52
          3AFFFF7C6BFFFFFFFFFFFFFFFFFFFFFFFFFFE5997FFF00000000E99F89FFFFFF
          FFFFFFFFFFFFFFFFFFFFFF5842FFFF634EFFFFFFFFFFFFFFFFFFE7CCC7FFFF52
          3AFFFF7F6DFFFFFFFFFFFFFFFFFFFFFFFFFFE89A82FF00000000ECA28CFFFFFF
          FFFFFFFFFFFFFFFFFFFFFF634EFFFF5B43FFFFFFFFFFFFFFFFFFEEBBB4FFFF52
          3AFFFF8B7BFFFFFFFFFFFFFFFFFFFFFFFFFFE99E87FF00000000EEA48EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFF7F6CFFFF523AFFE9C5C0FFFFFFFFFFFF9383FFFF52
          3AFFF7ADA3FFFFFFFFFFFFFFFFFFFFFFFFFFECA38AFF00000000EEA792FFFFFF
          FFFFFFFFFFFFFFFFFFFFECC0BAFFFF563DFFFF634EFFFF7F6EFFFF563FFFFF6F
          5BFFDCD9D9FFFFFFFFFFFFFFFFFFFFFFFFFFECA68EFF00000000EFA893FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFF0BBB3FFFF7967FFFF6F5BFFFF8A79FFE2D7
          D6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEEA792FF00000000F1AC95FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFA893FF00000000FFC2A5FFF1AE
          97FFF1AE97FFF1AE97FFF1AE97FFF1AE97FFF1AC95FFF1AC95FFF1AC95FFF1AC
          95FFF1AC95FFF1AC95FFF1AC95FFF1AC95FFFFC2A1FF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000FAFA
          FAFFEDEDEDFFE9E9E9FFEAEAEAFFEBEBEBFFECECECFFEDEDEDFFEEEEEEFFEFEF
          EFFFF0F0F0FFF1F1F1FFF2F2F2FFF6F6F6FFFDFDFDFF0000000000000000EFEF
          EFFFAE5726FFAF582BFFB05C2EFFB26232FFB56636FFB8683BFFBA6F40FFBD73
          44FFBF7649FFC27D4DFFC38253FFC78557FFF7F7F7FF0000000000000000F0F0
          F0FF8E5D45FFD99E5FFFEEBB77FFEDBF7EFFF1C489FFF1CA91FFF4CF9CFFF5D3
          A6FFF7DAAFFFF9E2BEFFEFD2B3FFAC8971FFF9F9F9FF0000000000000000F9F9
          F9FFBCB8B5FFAF6032FFEDB974FFEDBB75FFEDBC7AFFF0C081FFF2C588FFF4C9
          8CFFF5CC95FFF9E4C3FFD29C73FFCAC7C5FFFDFDFDFF0000000000000000FEFE
          FEFFF1F1F1FF936F5CFFD5985DFFEFBF7AFFEFC17EFFF2C686FFF3C990FFF5CE
          96FFF8DDB3FFEBCCADFFA88F7DFFF8F8F8FF0000000000000000000000000000
          0000FBFBFBFFCDCBCAFFAF653CFFEDBF81FFF0C283FFF4C98CFFF5CE96FFF8D7
          A4FFFBEACDFFCA966EFFD8D6D5FFFDFDFDFF0000000000000000000000000000
          0000FEFEFEFFF4F4F4FF9A8173FFD39863FFF3C98DFFF4CB92FFF8D39DFFFBE4
          C1FFE7C4A4FFA89486FFF9F9F9FF000000000000000000000000000000000000
          000000000000FCFCFCFFDDDCDCFFAF6D45FFEFC790FFF5CE96FFF8DAABFFFAE6
          CCFFC38E67FFE5E4E4FFFEFEFEFF000000000000000000000000000000000000
          000000000000FEFEFEFFF7F7F7FFA4958BFFD49B6AFFF8D5A2FFFAE4C0FFE1BA
          96FFACA096FFFAFAFAFF00000000000000000000000000000000000000000000
          00000000000000000000FDFDFDFFE9E9E9FFAD7855FFF2D2A6FFF6DFC0FFBB8C
          69FFEEEEEEFFFEFEFEFF00000000000000000000000000000000000000000000
          0000FCFCFCFFF3F3F3FFEEEEEEFFE8E8E8FFA89E99FFCA9C76FFD1A786FFACA4
          9DFFF0F0F0FFF6F6F6FFF9F9F9FFFEFEFEFF0000000000000000000000000000
          0000F3F3F3FFA1775EFFBC7244FFBD7648FFBF794CFFC17E50FFC38255FFC687
          5BFFC88C5EFFCA9062FFB08E76FFFAFAFAFF0000000000000000000000000000
          0000EEEEEEFFBA7042FFEEC892FFF0CC97FFF1D09DFFF3D4A2FFF6D8A9FFF8DB
          AFFFF9DDB4FFFFF9EFFFCD9366FFF9F9F9FF0000000000000000000000000000
          0000F3F3F3FFA37B62FFBF7B4DFFC38456FFC98B5FFFCD9467FFCF9A6DFFD29E
          72FFD4A277FFD5A67AFFB59A81FFFBFBFBFF0000000000000000000000000000
          0000FCFCFCFFF4F4F4FFF0F0F0FFF0F0F0FFF1F1F1FFF2F2F2FFF3F3F3FFF4F4
          F4FFF6F6F6FFF7F7F7FFFAFAFAFFFEFEFEFF0000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000FEFEFEFFFAFAFAFFF7F7F7FFF6F6F6FFF4F4F4FFF3F3F3FFF2F2F2FFF1F1
          F1FFF0F0F0FFF0F0F0FFF4F4F4FFFCFCFCFF0000000000000000000000000000
          0000FBFBFBFFB59A81FFD5A67AFFD4A277FFD29E72FFCF9A6DFFCD9467FFC98B
          5FFFC38456FFBF7B4DFFA37B62FFF3F3F3FF0000000000000000000000000000
          0000F9F9F9FFCD9366FFFFF9EFFFF9DDB4FFF8DBAFFFF6D8A9FFF3D4A2FFF1D0
          9DFFF0CC97FFEEC892FFBA7042FFEEEEEEFF0000000000000000000000000000
          0000FAFAFAFFB08E76FFCA9062FFC88C5EFFC6875BFFC38255FFC17E50FFBF79
          4CFFBD7648FFBC7244FFA1775EFFF3F3F3FF0000000000000000000000000000
          0000FEFEFEFFF9F9F9FFF6F6F6FFF0F0F0FFACA49DFFD1A786FFCA9C76FFA89E
          99FFE8E8E8FFEEEEEEFFF3F3F3FFFCFCFCFF0000000000000000000000000000
          00000000000000000000FEFEFEFFEEEEEEFFBB8C69FFF6DFC0FFF2D2A6FFAD78
          55FFE9E9E9FFFDFDFDFF00000000000000000000000000000000000000000000
          00000000000000000000FAFAFAFFACA096FFE1BA96FFFAE4C0FFF8D5A2FFD49B
          6AFFA4958BFFF7F7F7FFFEFEFEFF000000000000000000000000000000000000
          000000000000FEFEFEFFE5E4E4FFC38E67FFFAE6CCFFF8DAABFFF5CE96FFEFC7
          90FFAF6D45FFDDDCDCFFFCFCFCFF000000000000000000000000000000000000
          000000000000F9F9F9FFA89486FFE7C4A4FFFBE4C1FFF8D39DFFF4CB92FFF3C9
          8DFFD39863FF9A8173FFF4F4F4FFFEFEFEFF0000000000000000000000000000
          0000FDFDFDFFD8D6D5FFCA966EFFFBEACDFFF8D7A4FFF5CE96FFF4C98CFFF0C2
          83FFEDBF81FFAF653CFFCDCBCAFFFBFBFBFF0000000000000000000000000000
          0000F8F8F8FFA88F7DFFEBCCADFFF8DDB3FFF5CE96FFF3C990FFF2C686FFEFC1
          7EFFEFBF7AFFD5985DFF936F5CFFF1F1F1FFFEFEFEFF0000000000000000FDFD
          FDFFCAC7C5FFD29C73FFF9E4C3FFF5CC95FFF4C98CFFF2C588FFF0C081FFEDBC
          7AFFEDBB75FFEDB974FFAF6032FFBCB8B5FFF9F9F9FF0000000000000000F9F9
          F9FFAC8971FFEFD2B3FFF9E2BEFFF7DAAFFFF5D3A6FFF4CF9CFFF1CA91FFF1C4
          89FFEDBF7EFFEEBB77FFD99E5FFF8E5D45FFF0F0F0FF0000000000000000F7F7
          F7FFC78557FFC38253FFC27D4DFFBF7649FFBD7344FFBA6F40FFB8683BFFB566
          36FFB26232FFB05C2EFFAF582BFFAE5726FFEFEFEFFF0000000000000000FDFD
          FDFFF6F6F6FFF2F2F2FFF1F1F1FFF0F0F0FFEFEFEFFFEEEEEEFFEDEDEDFFECEC
          ECFFEBEBEBFFEAEAEAFFE9E9E9FFEDEDEDFFFAFAFAFF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000FAFA
          FAFFECECECFFE8E8E8FFE9E9E9FFEAEAEAFFEBEBEBFFECECECFFEDEDEDFFEEEE
          EEFFEFEFEFFFF0F0F0FFF1F1F1FFF1F1F1FFF5F5F5FFFDFDFDFF00000000EDED
          EDFFAC592CFFAE5D2FFFB05F33FFB26436FFB46839FFB56A3EFFB86F42FFBA75
          47FFBD774BFFBF7B51FFC18455FFC3875AFFC68C62FFF7F7F7FF00000000EDED
          EDFF905337FFDAA66CFFE4B77AFFE6B97EFFE7BE86FFE9C38FFFEECDA0FFF1D5
          ABFFF3DBB5FFF5E0BCFFF8E7C9FFEFDABDFFB28A6FFFF7F7F7FF00000000F7F7
          F7FFA69B96FFB66F41FFE4B77AFFE5B87BFFE7BA81FFE7BE86FFEDC996FFEECE
          9DFFF0D2A4FFF2D7ACFFF8E6C8FFD5A881FFBCB8B4FFFCFCFCFF00000000FDFD
          FDFFECECECFF936045FFD6A46CFFE6BB80FFE8BD84FFE9C18AFFEDCC9BFFF0D2
          A4FFF2D6ABFFF6E2BEFFEBD2B4FFAC8C76FFF6F6F6FFFEFEFEFF000000000000
          0000F9F9F9FFB8B2AFFFB66E41FFE7BF89FFE9C089FFEBC490FFEFCF9FFFF2D5
          AAFFF5DDB6FFFAEBCEFFD2A17AFFCAC7C5FFFDFDFDFF00000000000000000000
          0000FDFDFDFFF0F0F0FF956E5AFFD7A673FFEAC38EFFECC793FFEFD0A1FFF4DA
          AFFFF8E6C5FFE6C9AAFFA89181FFF8F8F8FF0000000000000000000000000000
          000000000000FAFAFAFFC8C6C4FFB57549FFECCA9AFFEDC996FFF0CFA0FFF6DF
          B9FFF8EACEFFC89A75FFD8D7D6FFFDFDFDFF0000000000000000000000000000
          000000000000FEFEFEFFF3F3F3FF9A7F6FFFD8A87BFFEFCFA0FFF0D2A4FFF8E3
          C3FFE3C2A2FFA8988BFFF9F9F9FF000000000000000000000000000000000000
          00000000000000000000FCFCFCFFD8D7D6FFB67A53FFEFD1A9FFF3D8AEFFF5E0
          C3FFC2936EFFE5E4E4FFFEFEFEFF000000000000000000000000000000000000
          00000000000000000000FEFEFEFFF6F6F6FFA29083FFD7AA82FFF3DCB8FFDDB6
          93FFADA39BFFFAFAFAFF00000000000000000000000000000000000000000000
          0000000000000000000000000000FDFDFDFFE3E3E3FFB78460FFF1DCC1FFB890
          6DFFEEEEEEFFFEFEFEFF00000000000000000000000000000000000000000000
          0000000000000000000000000000FEFEFEFFF8F8F8FFACA19AFFCB976EFFB7B1
          ACFFFBFBFBFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000FEFEFEFFF9F9F9FFF6F6F6FFFBFB
          FBFFFEFEFEFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000FEFEFEFFFBFBFBFFF6F6F6FFF9F9
          F9FFFEFEFEFF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000FBFBFBFFB7B1ACFFCB976EFFACA1
          9AFFF8F8F8FFFEFEFEFF00000000000000000000000000000000000000000000
          0000000000000000000000000000FEFEFEFFEEEEEEFFB8906DFFF1DCC1FFB784
          60FFE3E3E3FFFDFDFDFF00000000000000000000000000000000000000000000
          0000000000000000000000000000FAFAFAFFADA39BFFDDB693FFF3DCB8FFD7AA
          82FFA29083FFF6F6F6FFFEFEFEFF000000000000000000000000000000000000
          00000000000000000000FEFEFEFFE5E4E4FFC2936EFFF5E0C3FFF3D8AEFFEFD1
          A9FFB67A53FFD8D7D6FFFCFCFCFF000000000000000000000000000000000000
          00000000000000000000F9F9F9FFA8988BFFE3C2A2FFF8E3C3FFF0D2A4FFEFCF
          A0FFD8A87BFF9A7F6FFFF3F3F3FFFEFEFEFF0000000000000000000000000000
          000000000000FDFDFDFFD8D7D6FFC89A75FFF8EACEFFF6DFB9FFF0CFA0FFEDC9
          96FFECCA9AFFB57549FFC8C6C4FFFAFAFAFF0000000000000000000000000000
          000000000000F8F8F8FFA89181FFE6C9AAFFF8E6C5FFF4DAAFFFEFD0A1FFECC7
          93FFEAC38EFFD7A673FF956E5AFFF0F0F0FFFDFDFDFF00000000000000000000
          0000FDFDFDFFCAC7C5FFD2A17AFFFAEBCEFFF5DDB6FFF2D5AAFFEFCF9FFFEBC4
          90FFE9C089FFE7BF89FFB66E41FFB8B2AFFFF9F9F9FF0000000000000000FEFE
          FEFFF6F6F6FFAC8C76FFEBD2B4FFF6E2BEFFF2D6ABFFF0D2A4FFEDCC9BFFE9C1
          8AFFE8BD84FFE6BB80FFD6A46CFF936045FFECECECFFFDFDFDFF00000000FCFC
          FCFFBCB8B4FFD5A881FFF8E6C8FFF2D7ACFFF0D2A4FFEECE9DFFEDC996FFE7BE
          86FFE7BA81FFE5B87BFFE4B77AFFB66F41FFA69B96FFF7F7F7FF00000000F7F7
          F7FFB28A6FFFEFDABDFFF8E7C9FFF5E0BCFFF3DBB5FFF1D5ABFFEECDA0FFE9C3
          8FFFE7BE86FFE6B97EFFE4B77AFFDAA66CFF905337FFEDEDEDFF00000000F7F7
          F7FFC68C62FFC3875AFFC18455FFBF7B51FFBD774BFFBA7547FFB86F42FFB56A
          3EFFB46839FFB26436FFB05F33FFAE5D2FFFAC592CFFEDEDEDFF00000000FDFD
          FDFFF5F5F5FFF1F1F1FFF1F1F1FFF0F0F0FFEFEFEFFFEEEEEEFFEDEDEDFFECEC
          ECFFEBEBEBFFEAEAEAFFE9E9E9FFE8E8E8FFECECECFFFAFAFAFF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000CF980800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000CF980800FFF3D500CF98
          0800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D8007F5B0000CF980800F6CB9700F6CB9700FFF3
          D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D8007F5B0000CF980800F6CB9700F6CB9700F6CB9700F6CB
          9700FFF3D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D8007F5B0000CF980800F6CB9700F6CB9700F6CB9700F6CB9700F6CB
          9700F6CB9700FFF3D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D8007F5B0000CF980800F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB
          9700F6CB9700F6CB9700FFF3D500CF980800D8D8D800D8D8D800D8D8D8007F5B
          0000CF980800FFF3D500FFF3D500FFF3D500FFF3D500FFF3D500FFF3D500FFF3
          D500FFF3D500FFF3D500FFF3D500FFF3D500CF980800D8D8D800D8D8D800CF98
          08007F5B00007F5B00007F5B00007F5B00007F5B00007F5B00007F5B00007F5B
          00007F5B00007F5B00007F5B00007F5B00007F5B0000D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800}
        MaskColor = 14211288
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F8F8
          F800C3C3C3009E9E9E0095959500959595009595950095959500959595009595
          950095959500959595009E9E9E00C3C3C300F8F8F800FFFFFF00FFFFFF00BFBF
          BF00AFAFAF00E7E7E700F4F4F400F4F4F400F4F4F400F4F4F400F4F4F400F4F4
          F400F4F4F400F4F4F400E7E7E700AFAFAF00BFBFBF00FFFFFF00FFFFFF008E8E
          8E00E3E3E300EFEFEF00EFEFEF00EFEFEF00EFEFEF00F8F8F800F8F8F800EFEF
          EF00EFEFEF00EFEFEF00EFEFEF00E1E1E1008E8E8E00FFFFFF00FFFFFF007979
          7900ECECEC00E9E9E900E9E9E900E9E9E900E9E9E9009999990099999900E9E9
          E900E9E9E900E9E9E900E9E9E900E9E9E90079797900FFFFFF00FFFFFF006F6F
          6F00E7E7E700E3E3E300E3E3E300E3E3E300E3E3E3006F6F6F006F6F6F00E3E3
          E300E3E3E300E3E3E300E3E3E300E3E3E3006F6F6F00FFFFFF00FFFFFF006969
          6900EBEBEB00DDDDDD00EFEFEF00EFEFEF00EFEFEF006969690069696900EFEF
          EF00EFEFEF00EFEFEF00DCDCDC00DEDEDE0069696900FFFFFF00FFFFFF006666
          6600F3F3F300E6E6E60099999900999999009999990066666600666666009999
          99009999990099999900D6D6D600D9D9D90066666600FFFFFF00FFFFFF006969
          6900F4F4F400EEEEEE0069696900696969006969690069696900696969006969
          69006969690069696900D1D1D100D6D6D60069696900FFFFFF00FFFFFF007171
          7100F6F6F600F0F0F000F0F0F000F0F0F000EBEBEB007171710071717100D1D1
          D100CECECE00CECECE00D1D1D100DDDDDD0071717100FFFFFF00FFFFFF007B7B
          7B00F9F9F900F3F3F300F3F3F300F3F3F300F3F3F3007B7B7B007B7B7B00F3F3
          F300F3F3F300F3F3F300F3F3F300F6F6F6007B7B7B00FFFFFF00FFFFFF008888
          8800FBFBFB00F7F7F700F7F7F700F7F7F700F7F7F7008888880088888800F7F7
          F700F7F7F700F7F7F700F7F7F700FAFAFA0088888800FFFFFF00FFFFFF009F9F
          9F00F0F0F000FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFB
          FB00FBFBFB00FBFBFB00FBFBFB00EFEFEF009F9F9F00FFFFFF00FFFFFF00CACA
          CA00C0C0C000F3F3F300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00F3F3F300C0C0C000CACACA00FFFFFF00FFFFFF00FAFA
          FA00CECECE00B1B1B100A9A9A900A9A9A900A9A9A900A9A9A900A9A9A900A9A9
          A900A9A9A900A9A9A900B1B1B100CECECE00FAFAFA00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDF6
          F400F3A79400EB715200E9634100E9634100E9634100E9634100E9634100E963
          4100E9634100E9634100EB715200F3A79400FDF6F400FFFFFF00FFFFFF00EDA4
          9100E98D7600F9DAD600FCECEC00FCECEC00FCECEC00FCECEC00FCECEC00FCEC
          EC00FCECEC00FCECEC00F9DAD600E98C7500EDA49100FFFFFF00FFFFFF00D665
          4600F3D7D300F7E8E800F7E8E800F7E8E800F7E8E800FCF4F400FCF4F400F7E8
          E800F7E8E800F7E8E800F7E8E800F2D5D100D6654600FFFFFF00FFFFFF00C54F
          2D00F1E7E700EFE4E400EFE4E400EFE4E400EFE4E400EE664400EE664400EFE4
          E400EFE4E400EFE4E400EFE4E400EFE4E400C54F2D00FFFFFF00FFFFFF00B849
          2700EBE4E400E7DFDF00E7DFDF00E7DFDF00E7DFDF00B8492700B8492700E7DF
          DF00E7DFDF00E7DFDF00E7DFDF00E7DFDF00B8492700FFFFFF00FFFFFF00AF45
          2300EDEAEA00E1DADA00F1EDED00F1EDED00F1EDED00AF452300AF452300F1ED
          ED00F1EDED00F1EDED00E0D9D900E1DBDB00AF452300FFFFFF00FFFFFF00AB44
          2200F3F3F300E7E5E500EE664400EE664400EE664400AB442200AB442200EE66
          4400EE664400EE664400D8D4D400DBD8D800AB442200FFFFFF00FFFFFF00AC48
          2600F4F4F400EEEEEE00AC482600AC482600AC482600AC482600AC482600AC48
          2600AC482600AC482600D2D0D000D7D6D600AC482600FFFFFF00FFFFFF00B450
          2E00F6F6F600F0F0F000F0F0F000F0F0F000EBEBEB00B4502E00B4502E00D2D1
          D100CECECE00CECECE00D2D1D100DEDDDD00B4502E00FFFFFF00FFFFFF00BE5B
          3900F9F9F900F3F3F300F3F3F300F3F3F300F3F3F300BE5B3900BE5B3900F3F3
          F300F3F3F300F3F3F300F3F3F300F6F6F600BE5B3900FFFFFF00FFFFFF00CC67
          4500FBFBFB00F7F7F700F7F7F700F7F7F700F7F7F700CC674500CC674500F7F7
          F700F7F7F700F7F7F700F7F7F700FAFAFA00CC674500FFFFFF00FFFFFF00DC81
          6200F9ECE800FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFBFB00FBFB
          FB00FBFBFB00FBFBFB00FBFBFB00F8EBE700DC816200FFFFFF00FFFFFF00F0B7
          A400EEA99200FCEFEA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FCEFEA00EEA99200F0B7A400FFFFFF00FFFFFF00FEF8
          F600F5BBA800EF927300ED876500ED876500ED876500ED876500ED876500ED87
          6500ED876500ED876500EF927300F5BBA800FEF8F600FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000D8DADBFF8EA2AEFFB9CFD5FFEAF4F6FFEEF5F6FFF1F6F7FFFDFCFBFFFFFE
          FCFF0000000000000000FFFFFEFFD4D8DEFFC7D0D5FF0000000000000000FCFB
          FBFF5B6775FF003667FF0467A2FF1992C8FF20A5D0FF28B0D5FF3EC0E2FF50C8
          E5FF68D3E6FF67CADAFF5BB3D0FF126CB6FF2B678CFF0000000000000000F8F6
          F5FF3B4A5AFF00335CFF3F7494FF80A8BEFF83AABDFF83B0C0FF76B3C3FF55A8
          BDFF2B9EBEFF0893C2FF0898D9FF005AA2FF95A9BCFF00000000000000000000
          0000B6B9BBFF686A6EFFEAE7E6FF00000000000000000000000000000000FFFE
          FDFFF1ECECFF979EA8FF0F4177FF075193FFCFDCE7FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000B1B5B7FF144174FF5E7288FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000E3E5E5FFE9EBEBFF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          001E0000003C0000003D0000003E0000003F0000003F00000040000000410000
          00420000003E0000000600000000000000000000000000000000000000000808
          0841FCFCFBFFFAFAFAFFFBFBFBFFFCFCFCFFFDFDFDFFFDFDFDFFFEFEFEFFFEFE
          FEFFD3D3D3FA4243429B00000005000000000000000000000000000000000808
          0841F8F8F8FFD4D4D4FFF7F7F7FFFAFAFAFFFBFBFBFFFCFCFCFFFDFDFDFFFFFF
          FFFFD4D4D4FFF7F7F7FF4D4F4EA9000000040000000000000000000000000808
          0842F8F8F8FFF4F4F4FFF7F7F7FFBEBEBEFFBEBEBEFFFCFCFCFF4D8797FF69AE
          C5FF87B1C6FFFEFEFEFFF5F6F7FF4C4E4EA20000000300000000000000000808
          0842F8F8F7FFD4D4D4FFF6F6F6FFF9F9F9FFFAFAFAFFFBFBFBFF8D966CFFA9AA
          78FFAFA679FFB9AF89FFA3A380FFD8D8D8FB0000003800000000000000000808
          0842F7F7F7FFF2F2F2FFF5F5F5FFBCBCBCFFBEBEBEFFFBFBFBFFFEB73FFFFEB7
          3FFFFEB73FFFFEB73FFFFEB73FFFFBFBFBFD0000003E00000000000000000808
          0842F7F7F6FFD3D3D3FFF4F4F3FFF6F6F6FFF8F8F8FFFAFAFAFFFBFBFBFFFCFC
          FCFFFCFCFCFFFDFDFDFFFDFDFDFFFAFAFAFD0000003E00000000000000000808
          0842F6F6F5FFF0F0EFFFF2F2F2FFBBBBBBFFBCBCBCFFBDBDBDFFBEBEBEFFBEBE
          BEFFBEBEBEFFBFBFBFFFBFBFBFFFFBFBFBFD0000003E00000000000000000808
          0842F5F5F5FFD2D2D2FFF0F0F0FFF2F2F2FFF5F5F4FFF6F6F6FFF8F8F8FFFAFA
          FAFFFAFAFAFFFAFAFAFFFBFBFBFFFBFBFBFE0000003E00000000000000000808
          0842F4F4F4FFECECEBFFEFEFEEFFB9B9B9FFBABABAFFBBBBBBFFBCBCBBFFBCBC
          BCFFBDBDBDFFBDBDBDFFBEBEBEFFFBFBFBFE0000003E00000000000000000808
          0842F3F3F2FFD1D1D0FFEDEDECFFEEEEEEFFF0F0F0FFF2F2F1FFF3F3F3FFF5F5
          F4FFF6F6F5FFF6F6F6FFF7F7F7FFF9F9F9FE0000003D00000000000000000808
          0842F2F1F1FFE8E7E6FFEAEAE9FFC99A6AFFCEA376FFEFEFEFFFB9B9B9FFBABA
          B9FFBABABAFFBBBBBAFFBBBBBBFFF8F8F8FE0000003D00000000000000000808
          0842F1F0F0FFCFCECEFFE7E7E6FFD1AC87FFEAE8E4FFEDEDECFFEEEEEDFFEFEF
          EFFFF0F0F0FFF1F1F0FFF1F1F1FFF7F7F7FE0000003C00000000000000000808
          0841F1F0F0FFE3E2E1FFE4E4E3FFCB9F74FFE8E7E5FFEAEAE9FFB7B7B7FFB8B8
          B7FFB8B8B8FFB8B8B8FFB8B8B8FFF6F6F6FE0000003C00000000000000000707
          0740F3F3F2FCEDECECFDEDECECFDEDEDECFDEEEEEDFDEFEEEEFDEFEFEFFDF0F0
          EFFDF0F0F0FDF1F1F0FDF1F1F1FDF5F5F4FC0000003B00000000000000000000
          001D000000380000003800000039000000390000003900000039000000390000
          0039000000390000003900000039000000380000001D00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000230000
          0033000000330000003300000033000000330000003300000033000000330000
          0033000000330000003300000033000000330000002C00000000286590C03890
          CEFF388FCEFF3990CEFF3A91CFFF3991CFFF3991D0FF388FCFFF388ED1FF3E8F
          DCFF00883BFF00C57DFF16897AFF4191DDFF347DB6E1000000003890CEFF74DE
          FFFF5ED1FAFF4CC8F4FF3CAFE5FF57B1E7FF55B0EBFF88E8FFFF88E6FFFF8EE8
          FFFF00843BFF00E3A1FF00BD76FF32AC8CFF4191DEFF00000000388FCEFF5ED1
          FAFF4AC5F2FF3BA9E0FF39BDF3FF3B8DD4FF29AB88FF008333FF008236FF0083
          39FF00813DFF00D8A0FF00D89DFF00BA77FF168A7CFF000000223990CEFF4CC9
          F4FF3BA9E0FF38BAEFFF48D6FFFF3D8ED7FF008634FF3FE7BCFF00D69DFF00D6
          9FFF00D59EFF00D09CFF00D09BFF00D39DFF00B97DFF005C2FBA3A91CFFF3BAE
          E4FF38BDF2FF47D5FFFF69E0FFFF3D8DD8FF008635FF6EE8CDFF00C899FF00C8
          99FF00C899FF00C797FF00C898FF00CA9AFF63E6CCFF008A47FF3991CFFF5AB1
          E3FF3689C9FF3688C8FF3688CAFF4EACEDFF008432FF96EEDDFF4DE7D2FF4FE7
          D2FF4DE6D1FF93E8D7FF00C397FF5FDFC4FF00B27DFF005C2EA93790CEFF59AF
          E0FF61DBFFFF62D9FFFF63D9FFFF66DBFFFF1BA483FF00802FFF008031FF0081
          34FF008036FF81E4D5FF57D9C1FF00AB74FF148B7BFF00000000358ECDFF96EB
          FFFF57D4FFFF59D3FFFF5AD3FFFF5BD4FFFF5ED6FFFF61D7FFFF62D8FFFF67DC
          FFFF008234FF76E1D1FF00A571FF33AB87FF3E90DDFF00000000338CCCFF99EA
          FFFF4FD1FFFF52D0FFFF53D1FFFF53D1FFFF54D1FFFF54D2FFFF56D3FFFF5AD6
          FFFF00802AFF00A26EFF14A081FFA2EFFFFF378ED1FF00000000338CCCFF9DEA
          FFFF47CEFFFF4ACEFFFF4BCFFFFF4BCFFFFF4BCFFFFF4BCFFFFF4BCFFFFF4DD1
          FFFF51D3FFFF51D3FFFF4CD2FFFF9FECFFFF338CCDFF00000000328CCCFFA2ED
          FFFF8CE4FFFF8FE4FFFF90E4FFFF90E4FFFF90E4FFFF90E4FFFF90E4FFFF91E4
          FFFF91E5FFFF91E4FFFF8DE4FFFFA3EDFFFF328CCCFF00000000328CCCFFA9EF
          FFFF37B5EEFF3BB6EEFF3CB7EEFF3CB7EEFF3CB7EEFF3CB7EEFF3CB7EEFF3CB7
          EEFF3CB7EEFF3BB6EEFF37B5EEFFA9EFFFFF328CCCFF00000000338CCCFFB3F3
          FFFF37CDFFFF3BCDFFFF3CCEFFFF3CCEFFFF3CCEFFFF3CCEFFFF3CCEFFFF3CCE
          FFFF3CCEFFFF3BCDFFFF37CDFFFFB3F3FFFF338CCCFF00000000368ECEFF85EA
          FFFF85E7FFFF86E6FFFF87E6FFFF87E6FFFF87E6FFFF87E6FFFF87E6FFFF87E6
          FFFF87E6FFFF86E6FFFF85E7FFFF85EAFFFF368ECEFF000000003589C2EF368E
          CEFF358DCCFF358CCCFF358CCCFF358CCCFF358CCCFF358CCCFF358CCCFF358C
          CCFF358CCCFF358CCCFF358DCCFF368ECEFF3589C2EF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000CA0000
          00A7000000A7000000A7000000A7000000A7000000B8000000B8000000B80000
          00A7000000A7000000A7000000A7000000A7000000A7000000C5000000C90000
          006F0000006F0000006F0000006F0000006F4C677FFF486584FF4E8FD9FF0000
          008B0000006F0000006F0000006F0000006F0000006F000000C4000000280000
          00880000006F0000003F000000BB000000375180A4FF7EA6B6FF8DD4FEFF2A65
          9FFF00000037000000BB0000003F0000006F0000008800000024000000000000
          00670000003F00000000000000A70000000036ABF7FF87E4FEFF7ED2FEFF0F98
          FEFF2A66A1FF000000A7000000000000003F0000006700000000000000000000
          00670000003F00000000000000A7000000000000009F1B6DC4FF3CC3FEFF28A9
          FEFF139BFFFF26629CFF000000000000003F0000006700000000000000000000
          00670000003F00000000000000A7000000000000009F0000000F2070C5FF41C5
          FEFF2BABFFFF0F98FEFF1F5E9BFF0000003F0000006700000000000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F2274
          C9FF40C7FFFF1FA9FEFF7EACD5FF6F6B69FF0000006700000000000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F0000
          009F1D75CFFFACDAF1FF90877FFFBBBAB6FF6C716FFF00000000000000000000
          00680000004B0000000F000000AA000000000000009F0000001E0000001E0000
          009F00000000807C7CFFE8E7E4FF868A81FFB676B7FF9364D1FF000000060000
          00C70000009F0000009F000000B500000080000000C20000009F0000009F0000
          00C200000080000000B5787D7CFFDEAEE0FFC792C8FFAA77D4FF0000009B0000
          00D3000000B7000000B7000000C1000000D2000000CA000000B7000000B70000
          00CA000000D2000000C1000000B7B67DD8FFB67ED9FF0000009F000000B30000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000001000000B40000006E0000
          00B5000000510000000100000000000000000000000000000000000000000000
          000000000000000000000000000200000058000000B700000067000000000000
          00090000006D000000B80000005D000000040000000000000000000000000000
          00000000000400000061000000B8000000670000000700000000000000000000
          0000000000000000000500000062000000B80000006900000007000000080000
          006A000000B80000005E00000004000000000000000000000000000000000000
          00000000000000000000000000000000000200000056000000B6000000B60000
          0055000000020000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000CA0000
          00A7000000A7000000A7000000A7000000A7000000A7000000A7000000A70000
          00B2005333E2009D5DFF009C5CFF009D5DFF005333E2000000CB000000C90000
          006F0000006F0000006F0000006F0000006F0000006F0000006F0000006F0256
          32D600A56AFF00B985FF76DEC3FF00B985FF00A569FF005735EB000000280000
          00880000006F0000003F000000BB00000037000000B40000004B0000004B009C
          5EFF00BF8BFF00BA81FFFEFEFEFF00BA81FF00BF8BFF009D5DFF000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F0095
          50FF73E4CAFFFEFEFEFFFFFFFFFFFEFEFEFF76E4CBFF009C5CFF000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F0090
          49FF00C993FF00C68DFFFFFFFFFF00C78EFF00CB97FF009D5DFF000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F64C2
          9DFF00A766FF00D098FF73ECD2FF00D29CFF00AE73FF005C3994000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000FFEF8
          FCFF61C099FF00924AFF00934DFF009654FF548F39FF00000000000000000000
          00670000003F00000000000000A7000000000000009F0000000F0000000F0000
          009F00000000000000A7000000000000003F0000006700000000000000000000
          00680000004B0000000F000000AA000000000000009F0000001E0000001E0000
          009F00000000000000AA0000000F0000004B0000006800000000000000060000
          00C70000009F0000009F000000B500000080000000C20000009F0000009F0000
          00C200000080000000B50000009F0000009F000000C7000000060000009B0000
          00D3000000B7000000B7000000C1000000D2000000CA000000B7000000B70000
          00CA000000D2000000C1000000B7000000B7000000D30000009F000000B30000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000001000000B40000006E0000
          00B5000000510000000100000000000000000000000000000000000000000000
          000000000000000000000000000200000058000000B700000067000000000000
          00090000006D000000B80000005D000000040000000000000000000000000000
          00000000000400000061000000B8000000670000000700000000000000000000
          0000000000000000000500000062000000B80000006900000007000000080000
          006A000000B80000005E00000004000000000000000000000000000000000000
          00000000000000000000000000000000000200000056000000B6000000B60000
          0055000000020000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000230000
          0033000000330000003300000033000000330000003300000033000000330000
          0033000000330000003300000033000000330000002C000000005C5C5CC08383
          83FF838383FF838383FF848484FF848484FF848484FF838383FF848484FF8D8D
          8DFF444444FF626262FF4F4F4FFF8F8F8FFF747474E100000000838383FFB9B9
          B9FFACACACFFA0A0A0FF909090FF9F9F9FFFA0A0A0FFC3C3C3FFC3C3C3FFC6C6
          C6FF424242FF717171FF5E5E5EFF6F6F6FFF8F8F8FFF00000000838383FFACAC
          ACFF9E9E9EFF8D8D8DFF969696FF878787FF6A6A6AFF414141FF414141FF4141
          41FF404040FF6C6C6CFF6C6C6CFF5D5D5DFF505050FF00000022838383FFA0A0
          A0FF8D8D8DFF939393FFA3A3A3FF8A8A8AFF434343FF939393FF6B6B6BFF6B6B
          6BFF6A6A6AFF686868FF686868FF696969FF5C5C5CFF2E2E2EBA848484FF8F8F
          8FFF959595FFA3A3A3FFB4B4B4FF8A8A8AFF434343FFABABABFF646464FF6464
          64FF646464FF636363FF646464FF656565FFA4A4A4FF454545FF848484FF9E9E
          9EFF7F7F7FFF7F7F7FFF808080FF9D9D9DFF424242FFC2C2C2FF9A9A9AFF9B9B
          9BFF999999FFBDBDBDFF616161FF9F9F9FFF595959FF2E2E2EA9828282FF9C9C
          9CFFB0B0B0FFB0B0B0FFB1B1B1FFB2B2B2FF5F5F5FFF404040FF404040FF4040
          40FF404040FFB2B2B2FF989898FF555555FF4F4F4FFF00000000818181FFCACA
          CAFFABABABFFACACACFFACACACFFADADADFFAEAEAEFFB0B0B0FFB0B0B0FFB3B3
          B3FF414141FFABABABFF525252FF6F6F6FFF8D8D8DFF000000007F7F7FFFCCCC
          CCFFA7A7A7FFA8A8A8FFA9A9A9FFA9A9A9FFA9A9A9FFA9A9A9FFAAAAAAFFACAC
          ACFF404040FF515151FF5A5A5AFFD0D0D0FF848484FF000000007F7F7FFFCECE
          CEFFA3A3A3FFA4A4A4FFA5A5A5FFA5A5A5FFA5A5A5FFA5A5A5FFA5A5A5FFA6A6
          A6FFA8A8A8FFA8A8A8FFA5A5A5FFCFCFCFFF808080FF000000007F7F7FFFD0D0
          D0FFC5C5C5FFC7C7C7FFC7C7C7FFC7C7C7FFC7C7C7FFC7C7C7FFC7C7C7FFC8C8
          C8FFC8C8C8FFC8C8C8FFC6C6C6FFD1D1D1FF7F7F7FFF000000007F7F7FFFD4D4
          D4FF929292FF949494FF959595FF959595FF959595FF959595FF959595FF9595
          95FF959595FF949494FF929292FFD4D4D4FF7F7F7FFF000000007F7F7FFFD9D9
          D9FF9B9B9BFF9D9D9DFF9D9D9DFF9D9D9DFF9D9D9DFF9D9D9DFF9D9D9DFF9D9D
          9DFF9D9D9DFF9D9D9DFF9B9B9BFFD9D9D9FF7F7F7FFF00000000828282FFC2C2
          C2FFC2C2C2FFC2C2C2FFC3C3C3FFC3C3C3FFC3C3C3FFC3C3C3FFC3C3C3FFC3C3
          C3FFC3C3C3FFC2C2C2FFC2C2C2FFC2C2C2FF828282FF000000007C7C7CEF8282
          82FF808080FF808080FF808080FF808080FF808080FF808080FF808080FF8080
          80FF808080FF808080FF808080FF828282FF7C7C7CEF00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000004000000130000002F0C09
          0074342700A7352700AE1810008D0000003D0000001800000006000000000000
          000000000000000000241C1C1C79555454B2777571D3777565E067500DEAB494
          00FFA38101FF7D5600FF795100FF613E00EA0604002B00000000000000000000
          0004171717879B9A97FAEBEAE8FFF5F5F3FFDBD8C9FF998041FF9D7700FFAE8F
          0BFFC6B02AFF8C6809FF7E5606FF714903FF613A00E500000001000000000303
          0342A5A5A3FFA8A7A3FFF0EFECFFFAFAF9FFD9D5BFFF7A5100FF825F00FFB49C
          1CFF9D7B1AFFA27F12FFA78416FF97710DFF795204FF2516015B000000000A0A
          0A44AFAEADFFA2A19EFFB5B3AFFFBAB7AAFFA79970FF7C5500FF6E4604FF8E66
          09FFB69825FFD0B94BFFD4BE54FFC2A836FFB49530FF3D26028E000000001515
          153B8A8A88FF999894FFE2E3DFFFF1F0ECFFCEC6A1FF724B00FF7A5406FFA785
          14FFD1BA4AFFE3D578FFE6DA82FFDACA69FFD5C358FF45320384000000001818
          173B9A9997FFA7A6A3FFF0EFECFFFAFAF8FFDCDAC3FF785207FF937108FFBBA0
          2AFFD1BB4BFFE2D57DFFE8DC8AFFDFCF71FFD0BC4EFF1F190538000000001515
          143BACACAAFFA09F9CFFAAAAA7FFABA9A2FFA7A189FF978350FF997600FFCFBC
          3AFFD3BF4DFFD6C255FFDFCE64FFDDCC67FF7B6825AA00000000000000001414
          143B868583FF8F8E8BFFDFDFDCFFEEEEECFFD5D2CAFFB4AF96FFA39251FFBAA4
          28FFCAB74AFFCDB74EFFC6AD35FFAEA05CFF12110B2700000000000000001817
          173B969593FFA7A6A2FFECECE9FFF8F8F9FFD7D6D3FFAFADA1FF9B9681FFC9C6
          B5FFF1EEDCFFD5CDABFFBEB8A3FF959183FF1110102A00000000000000001514
          143BABAAA9FFACABA8FFE1E0DDFFDAD9D7FFD0CFCDFFD3D2CFFFD8D7D4FFDFDD
          D9FFECEBE9FFE6E5E1FFC0BEB7FF95948EFF0D0D0D2A00000000000000001414
          143BAFAEACFFB4B3AFFFB7B4B0FFC1BEBAFFCBC9C6FFD2D0CDFFD7D6D3FFDBDA
          D7FFDCDBD8FFDFDEDBFFE0DFDEFFABABA8FF0E0E0D2A00000000000000001E1E
          1E3CA19F9BFFAAA7A3FFB2B0ACFFBBB9B7FFC6C4C0FFCECCC9FFD3D1CEFFD4D4
          D1FFD8D6D4FFDAD8D6FFDCDAD8FFDAD9D7FF1616162B00000000000000000404
          040A999793EBA5A29EFFAEACA8FFB8B4B0FFBEBEBAFFC7C5C1FFCCCAC7FFCFCD
          CAFFD0D0CDFFD4D2D0FFD7D7D3FFB1B0AFE20101010300000000000000000000
          00000B0B0A11716F6E97B2B1ADF6B5B3AFFFB8B6B2FFBCBAB7FFC1BFBBFFC6C4
          C0FFCBCAC6FFC3C2C0F36E6D6B900606060B0000000000000000000000000000
          00000000000000000000000000001A1A1A293939385047474661464645613839
          3850191919280000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000002C2C2CFF000000FF5A5A5AFF00000000B0B0B0FF0000
          00FF010101FFE7E7E7FF00000000000000000000000000000000000000000000
          000000000000E1E1E1FF000000FF000000FF101010FFFAFAFAFF666666FF0000
          00FF000000FF9E9E9EFF00000000000000000000000000000000000000000000
          000000000000989898FF000000FF0A0A0AFF030303FFBBBBBBFF1C1C1CFF0000
          00FF000000FF545454FF00000000000000000000000000000000000000000000
          0000000000004E4E4EFF000000FF4A4A4AFF3C3C3CFF3F3F3FFF000000FF0606
          06FF424242FF0F0F0FFFFAFAFAFF000000000000000000000000000000000000
          0000F8F8F8FF0C0C0CFF000000FF8C8C8CFF8C8C8CFF000000FF000000FF3D3D
          3DFF909090FF000000FFBFBFBFFF000000000000000000000000000000000000
          0000B9B9B9FF000000FF000000FFCECECEFFDCDCDCFF000000FF000000FF7F7F
          7FFFD3D3D3FF000000FF757575FF000000000000000000000000000000000000
          0000707070FF000000FF131313FFFDFDFDFFEFEFEFFF030303FF000000FFC0C0
          C0FFFEFEFEFF181818FF2B2B2BFF000000000000000000000000000000000000
          0000252525FF000000FF525252FFFFFFFFFFA6A6A6FF000000FF080808FFF8F8
          F8FFFFFFFFFF5A5A5AFF000000FFDDDDDDFF0000000000000000000000005858
          58FF000000FF000000FF252525FFADADADFF1F1F1FFF000000FF050505FF7E7E
          7EFFB5B5B5FF2A2A2AFF000000FF323232FFE1E1E1FF00000000000000004545
          45FF3C3C3CFF3C3C3CFF3C3C3CFF979797FF3C3C3CFF3C3C3CFF3C3C3CFF5D5D
          5DFFA0A0A0FF3C3C3CFF3C3C3CFF3C3C3CFFD8D8D8FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          20000000000000040000000000000000000000000000000000000000000A0000
          0010000000110000001100000011000000120000001200000012000000120000
          0012000000120000001300000013000000120000000C0000000381594CC2B47C
          69FFB37B69FFB37B68FFB37A68FFB37A68FFB27A68FFB27A68FFB37968FFB279
          68FFB27967FFB27867FFB17867FFB17866FF7F5649C30000000BB77F6EFFFBF8
          F5FFF8EEE9FFF8EEE9FFF7EFE8FFF7EEE8FFF7EEE8FFF7EEE8FFF7EDE7FFF7ED
          E6FFF6EDE6FFF6ECE6FFF6ECE6FFF6ECE5FFB47B69FF00000011B98472FFFBF8
          F6FFBF998AFFEBDAD3FFBE9788FFEBDAD3FFBD9586FFEBDAD3FFBC9484FFEBDA
          D3FF5D6DDDFFE4DDE1FF5A69DCFFF7EDE7FFB77F6EFF00000011BC8978FFFCFA
          F8FFEBDDD5FFECDCD5FFEBDDD5FFECDCD5FFEBDDD5FFECDCD5FFEBDDD5FFECDC
          D5FFE5DFE3FFE5DFE2FFE5DEE2FFF8EEE9FFB98472FF00000010C08E7DFFFCFA
          F9FFC6A294FFEDDED6FFC4A092FFEDDED6FFC29E8EFFEDDED6FFC19B8CFFEDDE
          D6FF6577E1FFE5E0E4FF6272E0FFF8F1EBFFBC8977FF00000010C39482FFFCFA
          FAFFEDDFD9FFEDDFD8FFEDDFD9FFEDDFD8FFEDDFD9FFEDDFD8FFEDDFD9FFEDDF
          D8FFE6E2E6FFE6E2E6FFE6E2E5FFF9F2EEFFC08E7CFF0000000FC79887FFFDFB
          FAFFCCAB9DFFEEE0DBFFCAA99BFFEEE0DBFFC9A799FFEEE0DBFFC8A496FFEEE0
          DBFF6D81E5FFE8E3E8FF6A7DE4FFFAF4F0FFC49381FF0000000EC99D8CFFFDFC
          FCFFEEE2DCFFEEE2DCFFEEE2DCFFEEE2DCFFEEE2DCFFEEE2DCFFEEE2DCFFEEE2
          DCFFE8E6EAFFE8E5EAFFE8E4E9FFFAF6F2FFC69886FF0000000DCDA190FFFEFC
          FCFFD0B1A3FFEFE3DFFFCFB0A2FFEFE3DFFFCFAFA0FFEFE3DFFFCDAD9FFFEFE3
          DFFF7388E8FFE9E6EBFF7186E7FFFBF7F5FFC99D8BFF0000000DCFA594FFFEFC
          FCFFFDF9F9FFFDF9F9FFFDF9F9FFFDFAF8FFFDF9F8FFFDFAF8FFFCF9F7FFFCF9
          F7FFFCF9F7FFFDF8F7FFFCF9F7FFFCF9F7FFCCA290FF0000000C4B53C3FF8D9E
          ECFF687CE3FF6678E2FF6476E1FF6172E0FF5F70DFFF5F70DFFF5D6CDEFF5B69
          DCFF5966DBFF5664DAFF5462D9FF616DDCFF3337AAFF0000000B4C55C4FF93A4
          EEFF6C80E6FF6A7EE4FF687BE4FF6678E2FF6375E1FF6375E1FF6172E0FF5E6F
          DEFF5C6CDDFF5A69DCFF5766DAFF6472DDFF3538ABFF0000000A4D56C6FF96A7
          EFFF95A6EFFF93A4EDFF90A2EDFF8F9FEDFF8B9BEBFF8B9BEBFF8898EAFF8595
          EAFF8291E7FF7F8DE7FF7D89E5FF7987E5FF3539ACFF000000093A4093C14D55
          C5FF4B53C3FF4A51C1FF484FBFFF464DBEFF444BBBFF444BBBFF4249B9FF4046
          B7FF3E44B4FF3C41B3FF3A3EB0FF393CAEFF282B80C200000006000000040000
          0006000000060000000600000007000000070000000700000007000000070000
          0007000000070000000800000008000000070000000500000001}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00008F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F79
          66FF8F7966FF8F7966FF8F7966FF8F7966FF0000000000000000000000000000
          00008E7561F18F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F79
          66FF8F7966FF8F7966FF8F7966FF786757D20000000000000000000000000000
          00000E0A0614AD764CF0E1A87BFFF0B78BFFF0B78BFFE2A87DFFAC744BF0100B
          0716000000000000000000000000000000000000000000000000000000000000
          0000000000003826194FB47B50F7ECB387FFEDB388FFB17950F43B2819530000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000001D181460936747F6C58C61FCC1885EF6946847FF4D4036FF4D40
          36FF4D4036FF4D4036FF4D4036FF000000000000000000000000000000000000
          00001B1613583F352CD218120E38A06C47DE9E6B45DC0D090612000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00003F342CD0110E0C3800000000000000000000000000000000000000000000
          0000645548B30000000000000000000000000000000000000000000000000000
          0000493C33F10403030D0000000000000000000000000000000000000000B57A
          4EFFB57A4EFFB57A4EFF00000000000000000000000000000000000000000000
          00003B3129C21814114E0000000000000000000000000000000000000000B57A
          4EFFF0B78BFFB57A4EFF00000000000000000000000000000000000000000000
          0000110E0C39453930E41B17135B2F2620944D3F36FB4D4036FF4D4036FFB57A
          4EFFF0B78BFFB57A4EFF00000000000000000000000000000000000000000000
          0000000000000F0D0B33352C25B04C4036FBCB9E78FF77644BFF77644BFFB57A
          4EFFF0B78BFFB57A4EFF00000000000000000000000000000000000000000000
          00000000000000000000000000002D251F8E4C3F36FC4D4036FF4D4036FFB57A
          4EFFF0B78BFFB57A4EFF00000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000B57A
          4EFFF0B78BFFB57A4EFF00000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000B57A
          4EFFB57A4EFFB57A4EFF00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00008F7966FF0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000B57A
          4EFFB57A4EFFB57A4EFF00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000BEC0C2FF777A80FF777B81FF7B7E81FF8285
          86FF7F8284FFCFD2D2FF00000000000000000000000000000000000000000000
          000000000000B2B4B4FF63676CFF9CA0A4FFBDBFC0FFCDD0D1FFA4A6A9FF9B9E
          A2FFA3A6AAFF63666BFF4F5359FFECEEEEFF0000000000000000000000000000
          0000A5A7A8FFBABCBDFFF0F2F2FFCBCDCEFFC3C5C5FFC1C2C3FFB8BBBDFF8589
          8DFFB6B7BBFFABACB0FF9FA2A8FF0C0F17FFD8D9DAFF0000000000000000BBBD
          BEFFD2D4D4FFFAFBFCFFDBDCDDFFE9EBEBFFF0F2F3FFB7B9BAFFBDBEBFFFD3D4
          D6FFA2A4A6FFEBEBEDFF9D9EA1FF7A7E84FF151B23FF00000000000000009496
          98FFFFFFFFFFF4F3F3FFE8E8E7FFE7E7E8FFCED1D1FFF9FBFCFFFDFEFFFFE7E6
          E8FFF0F1F2FFB6B8BBFF919398FF9B9CA1FF323842FFB7B9BCFFDCDDDFFFB4B6
          B9FFEDEFEFFFD8DADAFFF7F9F9FFE5E7E7FFE0E2E3FFE1E3E3FFE6E8E8FFDFE2
          E3FFCED0D1FFB0B3B4FFC7CCCCFFA4A7ABFF23272FFFB2B4B9FFD8D9DAFF8183
          86FFD3D5D5FFF2F4F4FFBEC0C0FFF2F4F4FFEAECEDFFCED0D1FFC6C8C9FFB2B4
          B4FFADAFB0FFDEE1E1FF919596FF72757AFF474C52FFF1F2F3FF000000006567
          6BFFD1D3D4FFC3C5C6FFD4D6D8FFEDEFEFFFE8EAEBFFD1D3D4FFDCDEDFFFC3C5
          C6FFF0F2F3FFB0B3B4FFB4B8BAFF585C62FF7D8084FF00000000000000000000
          0000888A8DFF74777CFFE0E2E4FFDFE1E1FFE7E9E9FFC1C3C4FFBDBEBEFFD8D9
          DAFFB6B7BAFFB5B7BAFF7B7F85FF666C70FF0000000000000000000000000000
          000000000000B3B5B6FFA2A4A5FFF9FBFCFFD9DBDAFFDBDDDEFFD7D9D9FFD8DA
          DCFFB4B7BAFF484C51FF707378FF000000000000000000000000000000000000
          00000000000000000000B6B8B9FFD0D2D3FFDFE1E0FFB8BABAFFCACBCDFF979A
          9EFF44474DFFABAFB4FF00000000000000000000000000000000000000000000
          00000000000000000000E2E3E6FF9D9FA2FFBBBCBEFFCCCFD3FF21252BFF7075
          79FF000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000B2B4B7FF8E9196FF7A7D81FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000070000
          000B0000000C0000000C0000000C0000000C0000000C0000000C0000000D0000
          000D0000000D0000000D0000000D0000000D0000000C0000000882594DBEB47C
          6AFFB37C69FFB37B6AFFB37B69FFB37B68FFB37B68FFB37A69FFB37A68FFB37A
          68FFB37A68FFB27968FFB37967FFB27967FFB27967FF7F574ABFB67F6DFFF9F2
          EEFFF9F2EEFFF9F2EDFFF9F1EDFFC69A8CFFF9F2ECFFF9F1EDFFF9F1ECFFF9F1
          ECFFC5998BFFF8F0EBFFF8F0EBFFF8F0EBFFF8F0EBFFB37B69FFB78170FFF9F3
          EFFFF7EEE9FFF8EEE8FFF8EEE9FFC79C8DFFF7EEE9FFF8EEE8FFF8EEE9FFF7EE
          E8FFC69A8BFFF8EEE8FFF7EDE8FFF7EEE8FFF9F1ECFFB57D6BFFBA8472FFFAF4
          F0FFF8EFEAFFF8F0EAFFF8EFE9FFC99D8FFFF8EFEAFFF8EFEAFFF7EEEAFFF8EF
          EAFFC89D8EFFF7EFE9FFF8EFE9FFF7EFE9FFF9F1EDFFB7806EFFBB8776FFCCA2
          95FFCAA193FFCBA193FFCAA193FFCAA192FFCBA192FFCAA091FFCA9F91FFCA9F
          91FFC99F91FFC99F90FFC99E90FFC99E8FFFC99F90FFB88371FFBD8A79FFFBF6
          F2FFF9F1ECFFF9F1ECFFF9F0EDFFCCA295FFF8F1ECFFF9F1EBFFF9F0ECFFF9F1
          ECFFCAA194FFF9F0ECFFF9F1EBFFF8F0EBFFF9F3F0FFBA8574FFC08E7CFFFBF6
          F3FFF9F2EEFFFAF2EEFFF9F1EDFFCEA697FFF9F1EDFFF9F1EDFFF9F2EDFFF9F2
          ECFFCDA496FFF9F1EDFFF9F1ECFFF9F1EDFFFBF5F1FFBC8977FFC29180FFFCF8
          F5FFF9F2EFFFFAF3EFFFFAF2EFFFCFA89AFFFAF3EEFFF9F2EEFFF9F2EEFFFAF3
          EEFFCEA799FFF9F2EEFFF9F2EEFFF9F2EDFFFBF5F2FFBF8C7AFFC88E5AFFD9AD
          80FFCE9964FFCD9763FFCD9660FFCD9460FFCB935EFFCA925DFFC9905BFFC88F
          5AFFC88E59FFC88D57FFC88C56FFC78B55FFD19D6CFFBB7943FFC98F5AFFF1DA
          B5FFE7C28DFFE7C18DFFE7C18CFFCD9660FFE6BF89FFE5BE89FFE5BD87FFE5BC
          87FFC98E59FFE4BA84FFE4BA83FFE4B983FFECCDA3FFBC7A44FFCA905CFFF1DB
          B8FFE8C28EFFE7C28DFFE7C18CFFCD9662FFE6BF8BFFE6BE89FFE5BD88FFE5BC
          87FFC98F5AFFE4BB86FFE4BB84FFE4BA83FFEDCEA5FFBD7B45FFCA915EFFF2DD
          B9FFF1DAB9FFF1DAB7FFF1D9B6FFD8AC7EFFF0D8B3FFF0D6B2FFF0D6B1FFEFD5
          AFFFD5A576FFEFD2ACFFEED2A9FFEDD1A9FFEDD1A8FFBE7B45FF976C47BECA91
          5DFFCA8F5BFFC88E5AFFC78C58FFC68B57FFC58955FFC48852FFC48651FFC284
          50FFC2834EFFC0814CFFC0804BFFBF7F49FFBE7D48FF8D5D34BF000000010000
          0002000000020000000200000002000000020000000200000002000000020000
          0003000000030000000300000003000000030000000300000002000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000002011F382A2240CC2A2240CC0201
          1E38000000000000000000000000000000000000000000000000000000000000
          000000000000000000000403132B261C32AB594522FF725B00FF725B00FF5945
          22FF261B30AB0503122A00000000000000000000000000000000000000000000
          000000000E130F0B3F8B231964F8423E4DFF48483CFF423F3EFD423F3FFD4945
          38FF45464DFF211A68F80D07438B00000E130000000000000000000000000C08
          2A633A2F38E4604F1FFF504029FF2D2B5BFD0476D8FD0292EDFD048BE7FD0093
          F1FD1059B1FD422F39FF5A4A27FF3B3037E40C082A6300000000000000004437
          42FF6F5D02FF675506FD6B5900FD644400FD125BADFD02AAFCFD089FECFD009E
          F7FD324160FD6F5400FD685704FD6F5D02FF443742FF0000000000000000473A
          34FF695804FD64530AFD64530AFD675406FD40303AFD0D70C4FD04ABF8FD0481
          E0FD493B2FFD6A5602FD64530AFD695804FD473A34FF00000000000000004539
          36FD695804FD64530AFD64530AFD65540AFD694A00FD1F4888FD00A8FCFD1F4C
          8BFD634704FD655408FD64530AFD695804FD453936FD00000000000000004539
          36FD695804FD64530AFD64530AFD64530AFD695602FD433A3AFD0454C3FD4B3F
          2EFD6A5700FD63520AFD64530AFD695804FD453936FD00000000000000004539
          36FD695804FD63520AFD625108FD63520AFD635208FD62500AFD4D3C25FD6250
          0AFD635208FD63520AFD63520AFD695804FD453936FD00000000000000004539
          36FD685704FD65540DFD685711FD65540DFD695914FD645308FD685502FD6756
          0EFD66550FFD63520AFD64530AFD695804FD453936FD0000000000000000473A
          34FF655300FD766729FDA0966AFD968B5BFD84763EFD8D814BFD908350FD8D81
          4BFD968B5AFD918552FD78692BFD645200FD473A34FF00000000000000004336
          42FF6A5700FF7D6E2BFDAEA580FD85773FFD8E824DFD948857FD85783FFD887B
          43FD84773FFD8F834FFD74641CFD6C5900FF433642FF00000000000000000B07
          295F372C3AE2685723FF7D6D20FF604F02FD6B5B18FD675610FD5D4C00FD604E
          04FD614F02FD675400FF615018FF392D3AE20B07295F00000000000000000000
          000000000F10130E348741322EF6685713FF695701FF625108FD64530AFD6B59
          04FF685612FF453735F6140F378700000F100000000000000000000000000000
          00000000000000000000000019271E183BA851422EFF6B5909FF6B5909FF5142
          2FFF1F183CA70000192700000000000000000000000000000000000000000000
          00000000000000000000000000000000000001001D3529213FC729213FC70100
          1D34000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000C0C0C0FF0000
          00FFC0C0C0FFC0C0C0FF000000FFC0C0C0FFC0C0C0FF000000FFA7A7A7FF328D
          62FF00C482FF008742FF999999FF000000FF999999FF999999FF000000FF0000
          00FF000000FF000000FF000000FF000000FF000000FF000000FF00592EFF00BD
          7FFF00E3A4FF008540FF000000FF000000FF000000FF000000FFC0C0C0FF0000
          00FF800000FF800000FFFFFFFFFFFFFFFFFFDDDDDDFF46A075FF00BC80FF00D8
          A0FF00D8A1FF00823FFF008540FF00853EFF00843CFF4CAB7CFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFF800000FF800000FF429F74FF00B981FF00D39FFF00D0
          9CFF00D09CFF00D59FFF00D69FFF00D69FFF3BE6BEFF008037FF000000FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFF800000FF008946FF63E6CDFF00CA9AFF00C8
          98FF00C797FF00C899FF00C899FF00C899FF6BE7CDFF007F36FFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2A5D31FF00B281FF60E0C7FF00C3
          97FF93E8D8FF4DE6D1FF4EE7D2FF4BE7D2FF90EDDFFF007F35FFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF2C592EFF00AD7FFF59DA
          C4FF81E4D5FF008038FF008239FF008037FF008036FF329262FF000000FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF5BB387FF00A9
          7CFF73E2D5FF00833AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF800000FF4195
          66FF00A579FF008135FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF8000
          00FF800000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF800000FF800000FF800000FFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FFFFFFFFFFFFFFFFFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF800000FFFFFFFFFF000000FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FFFFFFFFFFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF800000FFC0C0C0FF0000
          00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FF}
      end>
  end
  object ipwJSON1: TipwJSON
    Left = 48
    Top = 312
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 144
    Top = 352
  end
  object PopupMenuLOI: TPopupMenu
    Images = cxImageList1
    Left = 704
    Top = 112
    object LOIClear1: TMenuItem
      Caption = '&Clear'
      ImageIndex = 4
      ShortCut = 46
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 336
    Top = 120
    object ImportAllSpecimens1: TMenuItem
      Caption = 'Import All Specimens'
      OnClick = ImportAllSpecimens1Click
    end
    object InsertSingleSpecimen1: TMenuItem
      Caption = 'Insert Single Specimen'
      OnClick = InsertSingleSpecimen1Click
    end
    object AppendSingleSpecimen1: TMenuItem
      Caption = 'Append Single Specimen'
      OnClick = AppendSingleSpecimen1Click
    end
  end
  object FormControlEditLinkPretreat: TFormControlEditLink
    Tag = 0
    AutoPopupWidth = True
    WantKeyLeftRight = True
    WantKeyUpDown = True
    WantKeyHomeEnd = True
    WantKeyPriorNext = True
    WantKeyReturn = True
    WantKeyEscape = True
    Control = AdvControlDropDownPretreatment
    OnSetEditorValue = FormControlEditLinkPretreatSetEditorValue
    OnGetEditorValue = FormControlEditLinkPretreatGetEditorValue
    Left = 296
    Top = 328
  end
  object cxImageList2: TcxImageList
    Height = 9
    Width = 9
    FormatVersion = 1
    DesignInfo = 6816592
    ImageInfo = <
      item
        Image.Data = {
          7A010000424D7A01000000000000360000002800000009000000090000000100
          2000000000004401000000000000000000000000000000000000000000000908
          B7FF00000000000000000000000000000000000000000707B1FF000000001313
          BCFF0F10BBFF0C0CB9FF0000000000000000000000000707B4FF0708B3FF0707
          B2FF000000001717BFFF1414BDFF1010BBFF000000000909B7FF0808B6FF0808
          B5FF0000000000000000000000001D1DC2FF1918C0FF1515BEFF1111BCFF0E0E
          BAFF00000000000000000000000000000000000000002222C4FF1E1EC2FF1919
          C0FF00000000000000000000000000000000000000003232CBFF2D2DC9FF2928
          C7FF2424C5FF1F1FC2FF0000000000000000000000004444D1FF3F3FCFFF3939
          CDFF000000002E2EC9FF2A2AC7FF2525C5FF000000005858D7FF5151D5FF4C4C
          D3FF0000000000000000000000003535CBFF3030C9FF2B2BC7FF000000005E5E
          D9FF00000000000000000000000000000000000000003C3CCEFF00000000}
      end
      item
        Image.Data = {
          7A010000424D7A01000000000000360000002800000009000000090000000100
          2000000000004401000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000908B7FF0908B7FF0908B7FF0908B7FF0908B7FF0908B7FF0908
          B7FF0908B7FF0908B7FF1717BFFF1717BFFF1717BFFF1717BFFF1717BFFF1717
          BFFF1717BFFF1717BFFF1717BFFF2D2DC9FF2D2DC9FF2D2DC9FF2D2DC9FF2D2D
          C9FF2D2DC9FF2D2DC9FF2D2DC9FF2D2DC9FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          7A010000424D7A01000000000000360000002800000009000000090000000100
          2000000000004401000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000049031FF000000000000000000000000000000000000
          00000000000000000000069C30FF059631FF059131FF00000000000000000000
          0000000000000000000007A731FF06A230FF069D30FF059830FF059331FF0000
          0000000000000000000007AD32FF07AA31FF07A831FF00000000069F30FF059B
          31FF059530FF00000000000000000000000007AD32FF00000000000000000000
          000006A131FF059C30FF059731FF000000000000000000000000000000000000
          0000000000000000000007A231FF069E2FFF059930FF00000000000000000000
          00000000000000000000000000000000000006A430FF00000000000000000000
          000000000000000000000000000000000000000000000000000000000000}
      end>
  end
  object PopupMenuIsotope: TPopupMenu
    Left = 376
    Top = 216
    object SeriesMetadata1: TMenuItem
      Caption = 'Series Metadata'
      OnClick = SeriesMetadata1Click
    end
  end
  object cxImageList3: TcxImageList
    Height = 24
    Width = 24
    FormatVersion = 1
    DesignInfo = 8913696
    ImageInfo = <
      item
        Image.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000F9F9F9FFE9E9E9FFE6E6E6FFFBFBFBFF000000000000000000000000FDFD
          FDFFE4E4E4FFD8D8D8FFEAEAEAFF000000000000000000000000DDDDDDFFD7D6
          D7FFECECEDFF000000000000000000000000000000000000000000000000FEFE
          FEFFF0F0F0FFB1B1B1FF9C9C9CFFDEDEDEFF000000000000000000000000E2E2
          E2FF858585FF7A7A7AFF818181FFC2C2C2FFF4F4F4FF00000000AAACACFF4148
          50FFB3B7BAFF0000000000000000000000000000000000000000000000000000
          0000F0F0F0FFBABABAFF737373FF8E8E8EFFF8F7F7FF0000000000000000EEEE
          EEFF929292FF6C6C6CFF505151FF646464FFADADADFFFDFDFDFFE8E8E9FF4854
          5DFF616D73FFF5F4F3FF0000000000000000000000000000000000000000D7D8
          D8FFCACACBFFC0C0C1FF5D5D5DFF272828FF6C7177FFDDDEE1FF000000000000
          0000C7C7C7FF737373FF565757FF515252FF676767FFB6B6B6FF00000000D0D3
          D3FF5D686DFF788284FFCACCCEFFFFFEFEFF00000000D9D9D9FFA2A2A2FF4345
          45FF696E70FF888E91FF62696CFF5D6567FF3E4D5BFF6A7482FFFEFDFCFF0000
          000000000000C1C1C1FF595959FF515151FF3F4142FF525354FF000000000000
          0000E1E1E2FF6B767AFF606A6EFFA5A7A7FFB8B8B8FF8C8D8DFF636464FF4A4D
          50FF606668FF404547FF5A676DFF748084FF657078FF33393FFF9A9898FFE9E9
          E9FF00000000F9F8F8FF8F8F90FF404445FF374145FF30373AFF000000000000
          000000000000D4D5D6FF6F777AFF72787BFF6C7178FF6B7278FF6F7373FF7D81
          82FF444748FF161A1CFF45535AFF57666CFF7D8486FF7B7B7AFF838282FFAEAE
          AEFFD6D6D6FFF4F4F4FFFDFDFDFF919595FF2C373CFF3B454AFF000000000000
          000000000000E7E7E8FF747C7FFF55626CFF4A5A6CFF505F6FFF606B77FF7A7E
          81FF5C6061FF333E43FF3D4B51FF3E4C52FFA4A6A7FFCDCDCDFFC4C3C3FFC3C3
          C3FFC4C4C4FFC7C7C7FFE9E9E9FFFAFAF9FF858A8CFF424F54FF000000000000
          000000000000E6E7E6FF626B6EFF384B5AFF425874FF485D7AFF3D5476FF5965
          72FF495457FF344147FF3E4C52FF343F43FF66696CFF555D66FF77797BFFE0E0
          DFFFD8D8D8FFB6B6B6FFB0B0B0FFCCCCCBFFC3C2C2FF4D5A5EFF000000000000
          000000000000DFE0E0FF546064FF405260FF435B79FF375175FF2D4362FF3341
          49FF324349FF39474DFF39484EFF3E484BFF6D7376FF5A616AFF989B9FFFFFFF
          FEFFFBFBFBFF409E73FF008A4AFF008A4AFF42A076FF6E777AFF000000000000
          000000000000989FA1FF42555CFF414D54FF465460FF364658FF2F3E4BFF3444
          4BFF2E4047FF2F414BFF2D4354FF6C757BFFD3D2D1FFF1F1F0FF000000000000
          000000000000008949FF00E7A7FF00E7A7FF008949FFB4B8BAFF000000000000
          0000FAF9F9FF58646AFF304A55FF333F43FF383A3AFF2F3940FF2E3F4AFF384B
          53FF33474DFF293F4FFF2F486AFF5D6A76FF939797FF9A9B9DFFA4A7AAFFF6F7
          F7FF00000000008847FF08E2A6FF00E0A2FF008847FFDFE1E2FF000000000000
          0000FEFDFDFF69767BFF28424CFF394A51FF464F53FF253138FF17252CFF2538
          3FFF36484DFF344553FF334C70FF475768FF445155FF2B3540FF434E5CFFDADC
          DDFF00000000008747FF16E0ACFF00DCA2FF008847FFBABFC0FF000000000000
          000000000000646E73FF1E3742FF2C3E46FF313D41FF0E1B22FF0E1B21FF1F30
          37FF3C4A4EFF333B40FF45566AFF475664FF59676CFF5C6770FF434F5CFF8C92
          97FFEEEEEEFF008746FF23E0B2FF00D9A2FF008847FF6C797EFF000000000000
          0000000000008B8D8EFF19282FFF283B45FF213038FF0F1E25FF081A20FF1626
          2EFF374449FF3C4344FF323537FF404C51FF677479FF737C80FF5A646AFF545D
          62FF7C8183FF008846FF30DFB7FF00D5A2FF008847FF47575EFF000000000000
          000000000000E8E6E6FF696D6EFF253942FF1B2F38FF192C33FF031821FF1324
          2AFF1D2C33FF364146FF394246FF4F5D63FF616F75FF6F7A7EFF6A767BFF5965
          6AFF535C60FF008845FF3EDFBDFF00D2A1FF008847FF9BA3A6FF000000000000
          00000000000000000000696D6EFF273A42FF1C3640FF20343DFF071D27FF1124
          2CFF1C2C33FF26373FFF3B4D54FF536369FF5C6B71FF616F74FF757D81FF6874
          7AFF566268FF008845FF4BDFC1FF00CEA0FF008847FFF8F7F7FF000000000000
          000000000000E7E6E5FF92999BFF293E47FF1F3943FF1F353EFF0B212BFF1227
          31FF24353CFF263941FF2E4048FF48575DFF55656BFF57676DFF6A757AFF6672
          77FF636F76FF008744FF58E0C7FF00CAA1FF008946FF00000000000000000000
          000000000000E7E5E5FF878C8EFF5C696FFF0F2832FF142B35FF1B2F38FF1229
          33FF1E3138FF23363EFF23363FFF304249FF4B5A61FF58676EFF5D6C71FF505C
          62FF404C51FF008642FF6AE1CBFF00C9A1FF008744FF00000033000000000000
          00000000000000000000CECFCFFF8E969AFF7A858AFF5C696FFF2B3E45FF2034
          3DFF1A2F37FF20333BFF273A42FF1F343DFF2D4149FF4F5D63FF4E5E64FF0F7B
          4BFF008846FF00AE7FFF00C39EFF00C39EFF00AE80FF008946FF000000000000
          00000000000000000000000000000000000000000000F1F1F2FF838C90FF2738
          3EFF192D36FF24363EFF22353DFF1F333BFF253941FF364850FF4E585DFF008C
          4AFF82DCCAFF00C1A0FF00BE9BFF00BE9BFF00C1A0FF83DCCAFF000000000000
          0000000000000000000000000000000000000000000000000000FBFBFAFF989D
          9EFF3A474CFF192C34FF10262FFF1A2E36FF16272FFF3F484BFFA8A9A9FF0000
          0000008844FF8EDBCBFF00B99DFF00B99DFF8EDBCBFF008844FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000D9DADAFF848B8EFF3E4D55FF1A2C33FF3E464AFF8B8C8CFFDEDEDDFF0000
          000000000000008742FF9AE0D3FF9AE0D3FF008742FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000EAEAEAFFBEC2C3FFA7A9A9FFE5E5E5FF000000000000
          00000000000000000000008A47FF008A47FF0000000000000000}
      end
      item
        Image.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000F3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFEFFFFF4F7F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCF2E7FF89E0C7FF88DE
          C5FF89DFC7FF99E5CFFFF8FDFBFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3F0F7
          F3FFC8E3D3FFAED9C3FFBEDFCDFFE7EFEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF9FCFAFFD8EBE2FFEFF3F0FFFFFFFFFFA7E8D6FF36CBA1FF3ECE
          A5FF3BCCA4FF51D2ADFFF3FCF9FFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3D3E9
          DDFF9DD6B8FFA2D9BDFFA0D9BDFFB3DAC6FFF9FAF9FFFFFFFFFFFFFFFFFFF8FB
          FAFFF3F7F4FFF6FBF9FFE1F1EBFFD8E8DFFFFDFBFBFFA6E6D4FF3ECDA5FF45CF
          A8FF42CEA7FF57D4B0FFF3FCF9FFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3D8ED
          E2FFA0D7BBFFA4D9BEFFA5DBBFFFAAD9C1FFEBF0EDFFFFFFFFFFFFFFFFFFE6F4
          EDFFCDE4D8FFFFFFFFFFFAFAF7FFCEE8DBFFE9EFEBFF99E1CBFF3FCEA6FF45CF
          A8FF42CEA7FF57D4B0FFF3FCF9FFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3E0F1
          E9FFA0D7BBFFA2D9BDFFA4DABFFFA5DBC1FFB0DBC5FFE6EFE9FFFFFFFFFFF0F8
          F4FFDDECE4FFDBEDEEFF9EDCD7FFBAD8CAFFDCE2DCFF8AD6BCFF40CFA7FF45CF
          A8FF42CEA7FF57D4B0FFF3FCF9FFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3DEEE
          E5FFA8D9C1FFB1DDC7FFB4DFCAFFAADCC2FFA4DBC0FFC3E0CFFFDFEEE2FFE0E9
          E2FFA2C1B8FF3ED7ECFF49E9FBFF5AAA9FFF486648FF46B098FF45D2AAFF45CF
          A8FF42CEA7FF58D4B0FFF6FCF9FFFFFFFFFFFEFEFEFFFFFFFFFFF3F3F3F3FDFE
          FDFFF6FAF8FFFBFCFBFFFDFCFCFFBEE2CFFFA8DDC1FF99DBCBFF78C9C2FF5B81
          67FF466F55FF4ACFE3FF39E3FEFF7EC7C5FF9EBAA9FF57CFC3FF42CFA7FF45CF
          A8FF43CEA7FF52D1AEFFD3EFECFFFBFCFBFFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFDFCFCFFB8E0CCFFA9DBC3FF58DBEAFF33DFF9FF4FBF
          BFFFA2C5ACFFAADED3FF8DDCDDFFC0E7DBFFD6F0E5FF90DEC8FF3FCEA6FF45CF
          A8FF45CFA7FF42CEAEFF4CE3EFFFB3EDEDFFFFFFFEFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFF1F7F3FFC1E1D1FFA6DDC3FF9ECDB3FF40C1D1FF44E3FCFF86E5
          E1FFBBE4D1FFBDE5D3FFC4E6D5FFC5E8DAFFD1ECE1FF93DFC8FF3FCEA6FF45CF
          A8FF45CFA7FF45D1B0FF39E3F8FF75CDD5FFFCF9F6FFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFECF5F0FFD6EBDFFFBFE2CCFF67896BFF4E846DFF8FDAD3FFB3E0
          CDFFB8E3D1FFBCE5D4FFC0E7D7FFC5E9DBFFD3ECE2FF93DFC8FF3FCEA6FF45CF
          A8FF44CFA7FF4CD3B2FF6ED3DEFF42745EFFC1C6BAFFFFFFFFFFF2F2F2F3F9FB
          FAFFFFFEFEFFDBEBE2FFC4E0D1FFA6E7E6FF509992FF89B8A1FFBAE6CEFFB6E2
          CFFFBCE5D4FFBFE6D6FFC2E4D5FFC8E8DAFFD5EDE3FF94E0C9FF3FCEA6FF45CF
          A8FF42CEA7FF58D4B1FFEBF3ECFF6DB1A6FF79C2BDFFF3F6F5FFE7EBE9F3BBDE
          CCFFC5E0D2FFDAE8DCFF90D6C6FF47E5F9FF3EE6FFFF82D9E1FF90AE95FF81A0
          89FF8DAC96FFB3D5C3FFA3C2AFFFB4CBBCFFDCF2E9FF96E2CCFF3FCEA6FF45CF
          A8FF42CEA7FF5AD4B0FFD5F0F0FF4BE4FDFF45E9FFFF96E2F0FFEEEFEFF3BBDF
          CCFF9FD6BAFFDAE5DCFFB0DCCDFF3ED3E4FF53D7EEFFD1F0F7FF798975FF627B
          62FF7D9781FF9DB3A1FF9BB5A4FF617860FFA3B1A3FF86CDB5FF40CFA7FF45CF
          A8FF43CFA7FF55CFABFFCEE4E1FF5DE2F8FF3ACCE3FFAAE4EFFFF3F3F3F3EDF5
          F0FFC3E1D0FFB3D5C0FFB1DEC6FF668C73FF9BAEA0FFFFFFFFFFDEE2DDFF7787
          74FF9BB4A2FFB2C7B9FFABB9ABFF778A77FFD5D2CDFF94D4BFFF3FCFA6FF45CF
          A8FF44D0A9FF45C39EFFB3BCB2FFF5FAFDFFCED7D2FFF9F8F6FFF3F3F3F3FFFF
          FFFFFAFAFAFFAFDAC4FFAEDCC5FF7DC2BBFF5AC5D2FFCEEDF2FFFFFFFFFFCED7
          D0FF738A76FFB2C4B6FFA7C2B3FF98A897FFC9C1BCFF87C5B0FF40D0A7FF45CF
          A8FF43CFA8FF4ECCA7FFE0EAE5FFFFFFFFFFEBE7E2FFFFFFFFFFF3F3F3F3FFFF
          FFFFEDF3F0FFC5E0CFFFB1DED3FF50E9FCFF39E7FFFF90E0F0FFEBF4ECFFD3EE
          E2FFDCEBE4FFCBE6D9FFC8E8DAFFB5D9CAFFA1D2C1FF7FD7BDFF41CFA7FF45CF
          A8FF43CEA7FF51D2AEFFB7EEDFFFCAF0E6FFF4F3F1FFFFFFFFFFF3F3F3F3FFFF
          FFFFFEFFFFFFFFFEFEFFF4FAFAFF8AE2F2FF31C4D4FFC6E0E2FFCDEADAFFB6E3
          D0FFC2E7D8FFC7E9DAFFCFEBDEFFC7ECDFFF52D4AFFF40CFA7FF45CFA8FF45CF
          A8FF45CFA8FF45CFA8FF38CCA2FF97DFCAFFFEFAFBFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFEFDFF859A8AFF7E9580FFBCE3D7FFBDE4
          D1FFC1E7D7FFC7E9DBFFCEEBE0FFDCF0E7FFA8E7D4FF3FCEA6FF45CFA8FF45CF
          A8FF45CFA8FF42CFA7FF5BD0ADFFE3E9E4FFFFFEFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2EBE8FF59B9BAFF3FD8F2FF97D9
          D8FFC7E8D7FFC9E9DCFFD0ECE2FFD6EFE5FFE3F4EDFF64D7B6FF41CEA6FF45CF
          A8FF45CFA8FF3ECEA6FF85D6C9FFF6F2F2FFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6FAFAFF53EAFCFF33E2FDFF81CB
          D5FFE2EDE2FFCBE8DBFFD2E9DEFFD9F0E6FFE3F4ECFFB6E7D5FF45CFA6FF44CF
          A8FF43CEA6FF45D4B9FF92DFE5FFF6F7F6FFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFEFDFFB7E8F2FF7EE5F5FF85A8
          9DFF8CA796FF7EDFEAFF57D6EAFFC8E3DCFFD4EDE4FF7FE4E9FF41D3BBFF43CE
          A5FF44CFA7FFA6E8DCFFDFEDEDFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFF
          FFFFACE8E8FF42E8FBFF33DCF8FF75A29BFF82AC9DFF47E4F5FF45DFE6FF40CC
          A4FF79DCC0FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3F3FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFEAFAFBFF87E1F2FF74E0EFFFE2EDECFFEBF6F5FFC1EFF0FFBBE6E4FF90E0
          C9FFD3F4EBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 112
    Top = 312
  end
end
