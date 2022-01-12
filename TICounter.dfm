object CounterForm: TCounterForm
  Left = 0
  Top = 0
  Caption = 'Tilia Counter'
  ClientHeight = 491
  ClientWidth = 812
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Icon.Data = {
    0000010001001010000001002000680400001600000028000000100000002000
    0000010020000000000000040000000000000000000000000000000000000000
    0000000000008F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F79
    66FF8F7966FF8F7966FF8F7966FF8F7966FF8F7966FF00000000000000000000
    000000000000967C67F18F7966FF8F7966FF8F7966FF8F7966FF8F7966FF8F79
    66FF8F7966FF8F7966FF8F7966FF8F7966FF927D6AD200000000000000000000
    000000000000B3804D14B87D51F0E1A87BFFF0B78BFFF0B78BFFE2A87DFFB77B
    50F0B98051160000000000000000000000000000000000000000000000000000
    00000000000000000000B57B514FBA7F53F7ECB387FFEDB388FFB97E54F4B57B
    4D53000000000000000000000000000000000000000000000000000000000000
    000000000000000000004D403560986B4AF6C78E62FCC88D61F6946847FF4D40
    36FF4D4036FF4D4036FF4D4036FF4D4036FF0000000000000000000000000000
    0000000000004E4037584D4035D26D524038B87C52DEB77C50DCB88055120000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000004D4036D04D403738000000000000000000000000000000000000
    0000000000008E7967B300000000000000000000000000000000000000000000
    0000000000004D3F36F14E3B3B0D000000000000000000000000000000000000
    0000B57A4EFFB57A4EFFB57A4EFF000000000000000000000000000000000000
    0000000000004E4036C24E41384E000000000000000000000000000000000000
    0000B57A4EFFF0B78BFFB57A4EFF000000000000000000000000000000000000
    0000000000004C3F36394D4036E44C40355B514137944E4037FB4D4036FF4D40
    36FFB57A4EFFF0B78BFFB57A4EFF000000000000000000000000000000000000
    000000000000000000004B4137334D4036B04D4137FBCB9E78FF77644BFF7764
    4BFFB57A4EFFF0B78BFFB57A4EFF000000000000000000000000000000000000
    0000000000000000000000000000000000005142388E4D4037FC4D4036FF4D40
    36FFB57A4EFFF0B78BFFB57A4EFF000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000B57A4EFFF0B78BFFB57A4EFF000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000B57A4EFFB57A4EFFB57A4EFF000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000008F7966FF00000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000B57A4EFFB57A4EFFB57A4EFF00000000000000000000000000000000C003
    0000C0030000C03F0000E07F0000E0070000C0FF0000CFDF0000CF8F0000CF8F
    0000C00F0000E00F0000F80F0000FF8F0000FF8F0000FFDF0000FF8F0000}
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSplitter2: TAdvSplitter
    Left = 200
    Top = 0
    Height = 491
    Appearance.BorderColor = clNone
    Appearance.BorderColorHot = clNone
    Appearance.Color = clWhite
    Appearance.ColorTo = clSilver
    Appearance.ColorHot = clWhite
    Appearance.ColorHotTo = clGray
    Appearance.Direction = gdVertical
    GripStyle = sgDots
    ExplicitLeft = 224
    ExplicitTop = 192
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 200
    Height = 491
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
    object AdvSplitter3: TAdvSplitter
      Left = 0
      Top = 196
      Width = 200
      Height = 3
      Cursor = crVSplit
      Align = alTop
      OnCanResize = AdvSplitter1CanResize
      Appearance.BorderColor = clNone
      Appearance.BorderColorHot = clNone
      Appearance.Color = clWhite
      Appearance.ColorTo = clSilver
      Appearance.ColorHot = clWhite
      Appearance.ColorHotTo = clGray
      GripStyle = sgDots
      OnDblClick = AdvSplitter1DblClick
    end
    object Panel4: TPanel
      Left = 0
      Top = 199
      Width = 200
      Height = 292
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      Visible = False
      object AdvColumnGrid1: TAdvColumnGrid
        Left = 0
        Top = 0
        Width = 200
        Height = 262
        Cursor = crDefault
        Align = alClient
        ColCount = 5
        DefaultRowHeight = 20
        DrawingStyle = gdsClassic
        FixedCols = 0
        RowCount = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goTabs, goRowSelect]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        Visible = False
        HoverRowCells = [hcNormal, hcSelected]
        OnCellChanging = AdvColumnGrid1CellChanging
        OnCanClickCell = AdvColumnGrid1CanClickCell
        OnButtonClick = AdvColumnGrid1ButtonClick
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        ColumnHeaders.Strings = (
          'Code'
          'Taxon Name'
          'Element'
          'Group'
          '')
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
        ControlLook.FlatButton = True
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
        FixedColWidth = 32
        FixedRowHeight = 20
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
        Navigation.AlwaysEdit = True
        Navigation.AdvanceOnEnter = True
        Navigation.AdvanceAuto = True
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
        SortSettings.Column = 1
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
            Header = 'Code'
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
            Width = 32
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
            Header = 'Taxon Name'
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
            Width = 55
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
            Header = 'Element'
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
            SortStyle = ssAlphaNoCase
            SpinMax = 0
            SpinMin = 0
            SpinStep = 1
            Tag = 0
            Width = 36
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
            Header = 'Group'
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
            SortStyle = ssAlphaNoCase
            SpinMax = 0
            SpinMin = 0
            SpinStep = 1
            Tag = 0
            Width = 36
          end
          item
            AutoMinSize = 0
            AutoMaxSize = 0
            Alignment = taCenter
            Borders = []
            BorderPen.Color = clSilver
            ButtonWidth = 16
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
            Width = 20
          end>
        ExplicitTop = -3
        ColWidths = (
          32
          55
          36
          36
          20)
      end
      object AdvDockPanel4: TAdvDockPanel
        Left = 0
        Top = 262
        Width = 200
        Height = 30
        Align = daBottom
        MinimumSize = 3
        LockHeight = False
        Persistence.Location = plRegistry
        Persistence.Enabled = False
        ToolBarStyler = AdvToolBarOfficeStyler1
        UseRunTimeHeight = True
        Version = '6.5.2.7'
        object AdvToolBar4: TAdvToolBar
          Left = 3
          Top = 1
          Width = 194
          Height = 28
          AllowFloating = False
          CaptionFont.Charset = DEFAULT_CHARSET
          CaptionFont.Color = clWindowText
          CaptionFont.Height = -11
          CaptionFont.Name = 'Tahoma'
          CaptionFont.Style = []
          CompactImageIndex = -1
          FullSize = True
          TextAutoOptionMenu = 'Add or Remove Buttons'
          TextOptionMenu = 'Options'
          ToolBarStyler = AdvToolBarOfficeStyler1
          Images = cxImageList1
          ParentOptionPicture = True
          ToolBarIndex = -1
          object AdvToolBarButton12: TAdvToolBarButton
            Left = 9
            Top = 2
            Width = 24
            Height = 24
            Hint = 'Save taxa'
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 2
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
          end
          object AdvToolBarButton13: TAdvToolBarButton
            Left = 33
            Top = 2
            Width = 24
            Height = 24
            Hint = 'Edit taxa'
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 7
            ParentFont = False
            Position = daBottom
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton13Click
          end
          object AdvToolBarButton14: TAdvToolBarButton
            Left = 81
            Top = 2
            Width = 24
            Height = 24
            Hint = 'Delete taxon'
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 9
            ParentFont = False
            Position = daBottom
            Version = '6.5.2.7'
          end
          object AdvToolBarButton15: TAdvToolBarButton
            Left = 105
            Top = 2
            Width = 24
            Height = 24
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 8
            ParentFont = False
            Position = daBottom
            Version = '6.5.2.7'
          end
          object AdvToolBarButton16: TAdvToolBarButton
            Left = 57
            Top = 2
            Width = 24
            Height = 24
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 10
            ParentFont = False
            Position = daBottom
            Version = '6.5.2.7'
          end
        end
      end
    end
    object AdvDockPanel2: TAdvDockPanel
      Left = 0
      Top = 0
      Width = 200
      Height = 30
      MinimumSize = 3
      LockHeight = False
      Persistence.Location = plRegistry
      Persistence.Enabled = False
      ToolBarStyler = AdvToolBarOfficeStyler1
      UseRunTimeHeight = True
      Version = '6.5.2.7'
      object AdvToolBar2: TAdvToolBar
        Left = 3
        Top = 1
        Width = 194
        Height = 28
        AllowFloating = False
        CaptionFont.Charset = DEFAULT_CHARSET
        CaptionFont.Color = clWindowText
        CaptionFont.Height = -11
        CaptionFont.Name = 'Tahoma'
        CaptionFont.Style = []
        CompactImageIndex = -1
        FullSize = True
        TextAutoOptionMenu = 'Add or Remove Buttons'
        TextOptionMenu = 'Options'
        ToolBarStyler = AdvToolBarOfficeStyler1
        Images = cxImageList1
        ParentOptionPicture = True
        ToolBarIndex = -1
        object AdvToolBarButton3: TAdvToolBarButton
          Left = 9
          Top = 2
          Width = 114
          Height = 24
          Appearance.CaptionFont.Charset = DEFAULT_CHARSET
          Appearance.CaptionFont.Color = clWindowText
          Appearance.CaptionFont.Height = -12
          Appearance.CaptionFont.Name = 'Segoe UI'
          Appearance.CaptionFont.Style = []
          Caption = 'Open Dictionary'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImageIndex = 0
          ParentFont = False
          Position = daTop
          ShowCaption = True
          Version = '6.5.2.7'
          OnClick = AdvToolBarButton3Click
        end
        object AdvToolBarButton9: TAdvToolBarButton
          Left = 123
          Top = 2
          Width = 24
          Height = 24
          Hint = 'Groups in sum'
          Appearance.CaptionFont.Charset = DEFAULT_CHARSET
          Appearance.CaptionFont.Color = clWindowText
          Appearance.CaptionFont.Height = -12
          Appearance.CaptionFont.Name = 'Segoe UI'
          Appearance.CaptionFont.Style = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImageIndex = 3
          ParentFont = False
          Position = daTop
          Version = '6.5.2.7'
          Visible = False
          OnClick = AdvToolBarButton9Click
        end
        object AdvToolBarButton11: TAdvToolBarButton
          Left = 147
          Top = 2
          Width = 24
          Height = 24
          Appearance.CaptionFont.Charset = DEFAULT_CHARSET
          Appearance.CaptionFont.Color = clWindowText
          Appearance.CaptionFont.Height = -12
          Appearance.CaptionFont.Name = 'Segoe UI'
          Appearance.CaptionFont.Style = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImageIndex = 6
          ParentFont = False
          Position = daTop
          Version = '6.5.2.7'
          Visible = False
          OnClick = AdvToolBarButton11Click
        end
      end
    end
    object AdvColumnGrid2: TAdvColumnGrid
      Left = 0
      Top = 113
      Width = 200
      Height = 83
      Cursor = crDefault
      Align = alTop
      ColCount = 2
      DefaultRowHeight = 20
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 3
      Visible = False
      OnExit = AdvColumnGrid2Exit
      HoverRowCells = [hcNormal, hcSelected]
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ColumnHeaders.Strings = (
        'Include'
        'Group')
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
      HoverButtons.Buttons = <>
      HoverButtons.Position = hbLeftFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      Navigation.AdvanceOnEnter = True
      Navigation.AdvanceAuto = True
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
      SortSettings.Column = 1
      Version = '3.1.6.0'
      WordWrap = False
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
          Header = 'Group'
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
          SortStyle = ssAlphaNoCase
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 131
        end>
      ExplicitTop = 110
      ColWidths = (
        48
        131)
    end
    object AdvColumnGrid4: TAdvColumnGrid
      Left = 0
      Top = 30
      Width = 200
      Height = 83
      Cursor = crDefault
      Align = alTop
      ColCount = 3
      DefaultRowHeight = 20
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 2
      Visible = False
      OnExit = AdvColumnGrid2Exit
      HoverRowCells = [hcNormal, hcSelected]
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ColumnHeaders.Strings = (
        'Code'
        'Element')
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
      ControlLook.FlatButton = True
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
      FixedColWidth = 32
      FixedRowHeight = 20
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
      Navigation.AdvanceOnEnter = True
      Navigation.AdvanceAuto = True
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
      SortSettings.Column = 1
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
          Header = 'Code'
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
          Width = 32
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
          Header = 'Element'
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
          SortStyle = ssAlphaNoCase
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 127
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
          Width = 20
        end>
      ExplicitTop = 40
      ExplicitWidth = 179
      ColWidths = (
        32
        127
        20)
    end
  end
  object Panel2: TPanel
    Left = 203
    Top = 0
    Width = 609
    Height = 491
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object AdvSplitter1: TAdvSplitter
      Left = 0
      Top = 244
      Width = 609
      Height = 3
      Cursor = crVSplit
      Align = alTop
      OnCanResize = AdvSplitter1CanResize
      Appearance.BorderColor = clNone
      Appearance.BorderColorHot = clNone
      Appearance.Color = clWhite
      Appearance.ColorTo = clSilver
      Appearance.ColorHot = clWhite
      Appearance.ColorHotTo = clGray
      GripStyle = sgDots
      OnDblClick = AdvSplitter1DblClick
      ExplicitTop = 263
      ExplicitWidth = 228
    end
    object Panel3: TPanel
      Left = 0
      Top = 30
      Width = 609
      Height = 214
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      Visible = False
      OnResize = Panel3Resize
      object Bevel1: TBevel
        Left = 0
        Top = 165
        Width = 609
        Height = 3
        Align = alBottom
        ExplicitTop = 172
        ExplicitWidth = 604
      end
      object AdvComboBox4: TAdvComboBox
        Left = 430
        Top = 108
        Width = 170
        Height = 21
        Hint = 'Person from Contacts metadata form'
        Color = clWindow
        Version = '1.9.0.0'
        Visible = True
        EmptyTextStyle = []
        DropWidth = 0
        Enabled = False
        ItemIndex = -1
        LabelCaption = 'Sample Analyst:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        ParentShowHint = False
        ReturnIsTab = True
        ShowHint = True
        Sorted = True
        TabOrder = 17
        OnChange = AdvComboBox4Change
      end
      object AdvEdit1: TAdvEdit
        Left = 112
        Top = 8
        Width = 200
        Height = 21
        DefaultHandling = True
        EmptyTextStyle = []
        ReturnIsTab = True
        LabelCaption = 'Site:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 0
        Visible = True
        OnExit = AdvEdit1Exit
        Version = '3.4.5.5'
      end
      object AdvEdit2: TAdvEdit
        Left = 112
        Top = 28
        Width = 200
        Height = 21
        DefaultHandling = True
        EmptyTextStyle = []
        ReturnIsTab = True
        LabelCaption = 'Collection Unit:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 1
        Visible = True
        OnExit = AdvEdit2Exit
        Version = '3.4.5.5'
      end
      object AdvEdit3: TAdvEdit
        Left = 112
        Top = 48
        Width = 200
        Height = 21
        OnValueValidate = AdvEditValueValidate
        AllowNumericNullValue = True
        DefaultHandling = True
        EmptyTextStyle = []
        ShowError = True
        ReturnIsTab = True
        LabelCaption = 'Depth:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 2
        Visible = True
        OnExit = AdvEdit3Exit
        Version = '3.4.5.5'
      end
      object AdvComboBox1: TAdvComboBox
        Left = 430
        Top = 28
        Width = 86
        Height = 21
        Color = clWindow
        Version = '1.9.0.0'
        Visible = True
        EmptyTextStyle = []
        DropWidth = 0
        Enabled = True
        ItemIndex = -1
        Items.Strings = (
          'Eucalyptus'
          'Lycopodium'
          'Microsphere')
        LabelCaption = 'Spike:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        ReturnIsTab = True
        TabOrder = 9
        OnChange = AdvComboBox1Change
        OnEnter = AdvComboBox1Enter
      end
      object AdvEdit5: TAdvEdit
        Left = 430
        Top = 8
        Width = 86
        Height = 21
        OnValueValidate = AdvEditValueValidate
        DefaultHandling = True
        EmptyTextStyle = []
        ShowError = True
        ReturnIsTab = True
        LabelCaption = 'Sample Quantity:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 7
        Visible = True
        OnExit = AdvEdit5Exit
        Version = '3.4.5.5'
      end
      object AdvComboBox2: TAdvComboBox
        Left = 515
        Top = 8
        Width = 85
        Height = 21
        Color = clWindow
        Version = '1.9.0.0'
        Visible = True
        EmptyTextStyle = []
        DropWidth = 0
        Enabled = True
        ItemIndex = -1
        Items.Strings = (
          'g'
          'ml')
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        ReturnIsTab = True
        TabOrder = 8
        OnChange = AdvComboBox2Change
      end
      object AdvEdit6: TAdvEdit
        Left = 430
        Top = 48
        Width = 86
        Height = 21
        Hint = 'e.g. number of tablets, ml of suspension'
        OnValueValidate = AdvEditValueValidate
        AllowNumericNullValue = True
        DefaultHandling = True
        EmptyTextStyle = []
        ExcelStyleDecimalSeparator = True
        ShowError = True
        ReturnIsTab = True
        LabelCaption = 'Spike Quantity:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        ParentShowHint = False
        ShowHint = True
        TabOrder = 11
        Visible = True
        OnExit = AdvEdit6Exit
        Version = '3.4.5.5'
      end
      object AdvEdit4: TAdvEdit
        Left = 112
        Top = 88
        Width = 200
        Height = 21
        DefaultHandling = True
        EmptyTextStyle = []
        ReturnIsTab = True
        LabelCaption = 'Analysis Unit Name:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 4
        Visible = True
        OnExit = AdvEdit4Exit
        Version = '3.4.5.5'
      end
      object AdvEdit7: TAdvEdit
        Left = 430
        Top = 68
        Width = 170
        Height = 21
        Hint = 'e.g. spores/tablet, microspheres/ml'
        OnValueValidate = AdvEditValueValidate
        AllowNumericNullValue = True
        DefaultHandling = True
        EmptyTextStyle = []
        ExcelStyleDecimalSeparator = True
        FocusColor = clBtnFace
        ShowError = True
        ReturnIsTab = True
        LabelCaption = 'Spike Concentration:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        ParentShowHint = False
        ShowHint = True
        TabOrder = 12
        Visible = True
        OnExit = AdvEdit7Exit
        Version = '3.4.5.5'
      end
      object AdvEdit8: TAdvEdit
        Left = 112
        Top = 108
        Width = 200
        Height = 21
        DefaultHandling = True
        EmptyTextStyle = []
        ReturnIsTab = True
        LabelCaption = 'Sample Name:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 5
        Visible = True
        OnExit = AdvEdit8Exit
        Version = '3.4.5.5'
      end
      object AdvEdit9: TAdvEdit
        Left = 112
        Top = 68
        Width = 200
        Height = 21
        OnValueValidate = AdvEditValueValidate
        AllowNumericNullValue = True
        DefaultHandling = True
        EmptyTextStyle = []
        ShowError = True
        ReturnIsTab = True
        LabelCaption = 'Thickness:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 3
        Visible = True
        OnExit = AdvEdit9Exit
        Version = '3.4.5.5'
      end
      object AdvEdit10: TAdvEdit
        Left = 112
        Top = 128
        Width = 200
        Height = 21
        DefaultHandling = True
        EmptyTextStyle = []
        ReturnIsTab = True
        LabelCaption = 'Sample Notes:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        TabOrder = 6
        Visible = True
        OnExit = AdvEdit10Exit
        Version = '3.4.5.5'
      end
      object cxLabel1: TcxLabel
        Left = 338
        Top = 135
        Caption = 'Preparation Date:'
        Properties.Alignment.Horz = taRightJustify
        AnchorX = 428
      end
      object AdvDockPanel1: TAdvDockPanel
        Left = 0
        Top = 168
        Width = 609
        Height = 46
        Align = daBottom
        MinimumSize = 3
        LockHeight = False
        Persistence.Location = plRegistry
        Persistence.Enabled = False
        ToolBarStyler = AdvToolBarOfficeStyler1
        UseRunTimeHeight = True
        Version = '6.5.2.7'
        object AdvToolBar1: TAdvToolBar
          Left = 3
          Top = 1
          Width = 273
          Height = 44
          AllowFloating = False
          CaptionFont.Charset = DEFAULT_CHARSET
          CaptionFont.Color = clWindowText
          CaptionFont.Height = -11
          CaptionFont.Name = 'Tahoma'
          CaptionFont.Style = []
          CompactImageIndex = -1
          FullSize = True
          TextAutoOptionMenu = 'Add or Remove Buttons'
          TextOptionMenu = 'Options'
          ToolBarStyler = AdvToolBarOfficeStyler1
          Images = cxImageList3
          ParentOptionPicture = True
          ToolBarIndex = -1
          object AdvToolBarButton2: TAdvToolBarButton
            Left = 179
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 1
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton2Click
          end
          object AdvToolBarButton1: TAdvToolBarButton
            Left = 139
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 0
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton1Click
          end
          object AdvToolBarButton6: TAdvToolBarButton
            Left = 9
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 2
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton6Click
          end
          object AdvToolBarButton7: TAdvToolBarButton
            Left = 49
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 3
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton7Click
          end
          object AdvToolBarButton8: TAdvToolBarButton
            Left = 89
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 4
            ParentFont = False
            Position = daBottom
            ShowCaption = True
            Version = '6.5.2.7'
          end
          object AdvToolBarSeparator1: TAdvToolBarSeparator
            Left = 129
            Top = 2
            Width = 10
            Height = 40
            LineColor = clBtnShadow
          end
          object AdvToolBarButton10: TAdvToolBarButton
            Left = 219
            Top = 2
            Width = 40
            Height = 40
            Appearance.CaptionFont.Charset = DEFAULT_CHARSET
            Appearance.CaptionFont.Color = clWindowText
            Appearance.CaptionFont.Height = -12
            Appearance.CaptionFont.Name = 'Segoe UI'
            Appearance.CaptionFont.Style = []
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImageIndex = 5
            ParentFont = False
            Position = daBottom
            Version = '6.5.2.7'
            OnClick = AdvToolBarButton10Click
          end
        end
      end
      object AdvEdit13: TAdvEdit
        Left = 576
        Top = 88
        Width = 24
        Height = 21
        AllowNumericNullValue = True
        DefaultHandling = True
        EditType = etAlphaNumeric
        EmptyTextStyle = []
        ExcelStyleDecimalSeparator = True
        FocusColor = clBtnFace
        ReturnIsTab = True
        LabelCaption = 'Spike Character:'
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Lookup.Font.Charset = DEFAULT_CHARSET
        Lookup.Font.Color = clWindowText
        Lookup.Font.Height = -11
        Lookup.Font.Name = 'Arial'
        Lookup.Font.Style = []
        Lookup.Separator = ';'
        Color = clWindow
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 2
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 13
        Text = '.'
        Visible = True
        Version = '3.4.5.5'
      end
      object AdvComboBox3: TAdvComboBox
        Left = 515
        Top = 28
        Width = 85
        Height = 21
        Color = clWindow
        Version = '1.9.0.0'
        Visible = True
        EmptyTextStyle = []
        DropWidth = 0
        Enabled = True
        ItemIndex = -1
        Items.Strings = (
          'suspension'
          'tablets')
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        ReturnIsTab = True
        TabOrder = 10
        OnChange = AdvComboBox3Change
        OnEnter = AdvComboBox3Enter
      end
      object AdvComboBox5: TAdvComboBox
        Left = 515
        Top = 48
        Width = 85
        Height = 21
        Color = clWindow
        Version = '1.9.0.0'
        Visible = True
        EmptyTextStyle = []
        DropWidth = 0
        Enabled = True
        ItemIndex = -1
        Items.Strings = (
          'g'
          'ml'
          'number')
        LabelPosition = lpLeftCenter
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        ReturnIsTab = True
        TabOrder = 18
      end
      object cxDateEdit1: TcxDateEdit
        Left = 430
        Top = 128
        Properties.OnChange = cxDateEdit1PropertiesChange
        TabOrder = 14
        Width = 170
      end
    end
    object AdvDockPanel3: TAdvDockPanel
      Left = 0
      Top = 0
      Width = 609
      Height = 30
      MinimumSize = 3
      LockHeight = False
      Persistence.Location = plRegistry
      Persistence.Enabled = False
      ToolBarStyler = AdvToolBarOfficeStyler1
      UseRunTimeHeight = True
      Version = '6.5.2.7'
      object AdvToolBar3: TAdvToolBar
        Left = 3
        Top = 1
        Width = 603
        Height = 28
        AllowFloating = False
        CaptionFont.Charset = DEFAULT_CHARSET
        CaptionFont.Color = clWindowText
        CaptionFont.Height = -11
        CaptionFont.Name = 'Tahoma'
        CaptionFont.Style = []
        CompactImageIndex = -1
        FullSize = True
        TextAutoOptionMenu = 'Add or Remove Buttons'
        TextOptionMenu = 'Options'
        ToolBarStyler = AdvToolBarOfficeStyler1
        Images = cxImageList1
        ParentOptionPicture = True
        ToolBarIndex = -1
        object AdvToolBarButton4: TAdvToolBarButton
          Left = 102
          Top = 2
          Width = 88
          Height = 24
          Hint = 'New count file'
          Appearance.CaptionFont.Charset = DEFAULT_CHARSET
          Appearance.CaptionFont.Color = clWindowText
          Appearance.CaptionFont.Height = -12
          Appearance.CaptionFont.Name = 'Segoe UI'
          Appearance.CaptionFont.Style = []
          Caption = 'New Count'
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImageIndex = 1
          ParentFont = False
          Position = daTop
          ShowCaption = True
          Version = '6.5.2.7'
          OnClick = AdvToolBarButton4Click
        end
        object AdvToolBarButton5: TAdvToolBarButton
          Left = 9
          Top = 2
          Width = 93
          Height = 24
          Appearance.CaptionFont.Charset = DEFAULT_CHARSET
          Appearance.CaptionFont.Color = clWindowText
          Appearance.CaptionFont.Height = -12
          Appearance.CaptionFont.Name = 'Segoe UI'
          Appearance.CaptionFont.Style = []
          Caption = 'Open Count'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImageIndex = 0
          ParentFont = False
          Position = daTop
          ShowCaption = True
          Version = '6.5.2.7'
          OnClick = AdvToolBarButton5Click
        end
      end
    end
    object Panel5: TPanel
      Left = 0
      Top = 247
      Width = 609
      Height = 244
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 2
      object AdvMemo1: TAdvMemo
        Left = 0
        Top = 127
        Width = 609
        Height = 117
        Cursor = crIBeam
        PopupMenu = AdvPopupMenu1
        ActiveLineSettings.ShowActiveLine = True
        ActiveLineSettings.ShowActiveLineIndicator = False
        Align = alClient
        AutoCompletion.Font.Charset = DEFAULT_CHARSET
        AutoCompletion.Font.Color = clWindowText
        AutoCompletion.Font.Height = -11
        AutoCompletion.Font.Name = 'Tahoma'
        AutoCompletion.Font.Style = []
        AutoCompletion.StartToken = '(.'
        AutoCorrect.Active = True
        AutoHintParameterPosition = hpBelowCode
        BookmarkGlyph.Data = {
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
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFD25252525
          2525252525252525FDFDFD2E25FFFFFFFFFFFFFFFFFFFF25FDFDFD2525252525
          2525252525252525FDFD9A9AB7B7B7B7B7B7B7B7B7B72525FDFDFD25B7B7B7B7
          B7B7B7B7B7B72525FDFD9A9AB7B7B7B7B7B7B7B7B7B72525FDFDFD25BFB7BFBF
          B7B7B7B7B7B72525FDFD9A9ABFBFBFB7BFBFB7B7B7B72525FDFDFD25BFBFBFBF
          BFB7BFBFB7B72525FDFD9A9ABFBFBFB7BFBFBFB7BFB72525FDFDFD25BFBFBFBF
          BFBFBFBFBFB72525FDFD9A9ABFBFBFBFBFB7BFBFB7B72525FDFDFD25BFBFBFBF
          BFBFBFBFBFB72525FDFD9A9ABFBFBFBFBFBFBFBFBFB725FDFDFDFD2525252525
          25252525252525FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD}
        BorderStyle = bsSingle
        ClipboardFormats = [cfText]
        CodeFolding.Enabled = False
        CodeFolding.LineColor = clGray
        Ctl3D = False
        DelErase = True
        EnhancedHomeKey = False
        Gutter.Font.Charset = DEFAULT_CHARSET
        Gutter.Font.Color = clWindowText
        Gutter.Font.Height = -13
        Gutter.Font.Name = 'Courier New'
        Gutter.Font.Style = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'COURIER NEW'
        Font.Style = []
        HiddenCaret = False
        Lines.Strings = (
          '')
        MarkerList.UseDefaultMarkerImageIndex = False
        MarkerList.DefaultMarkerImageIndex = -1
        MarkerList.ImageTransparentColor = 33554432
        OleDropTarget = []
        PrintOptions.MarginLeft = 0
        PrintOptions.MarginRight = 0
        PrintOptions.MarginTop = 0
        PrintOptions.MarginBottom = 0
        PrintOptions.PageNr = False
        PrintOptions.PrintLineNumbers = False
        ReadOnly = True
        RightMarginColor = 14869218
        ScrollHint = False
        SelColor = clWhite
        SelBkColor = clNavy
        ShowRightMargin = True
        SmartTabs = False
        StylerManager = AdvMemoStylerManager1
        SyntaxStyles = AdvXMLMemoStyler1
        TabOrder = 1
        TabStop = True
        TrimTrailingSpaces = False
        UILanguage.ScrollHint = 'Row'
        UILanguage.Undo = 'Undo'
        UILanguage.Redo = 'Redo'
        UILanguage.Copy = 'Copy'
        UILanguage.Cut = 'Cut'
        UILanguage.Paste = 'Paste'
        UILanguage.Delete = 'Delete'
        UILanguage.SelectAll = 'Select All'
        UrlStyle.TextColor = clBlue
        UrlStyle.BkColor = clWhite
        UrlStyle.Style = [fsUnderline]
        UseStyler = True
        Version = '3.6.2.10'
        Visible = False
        WordWrap = wwNone
        OnGutterRightClick = AdvMemo1GutterRightClick
      end
      object AdvPanel1: TAdvPanel
        Left = 0
        Top = 0
        Width = 609
        Height = 46
        Align = alTop
        BevelOuter = bvNone
        Color = 16440004
        TabOrder = 0
        UseDockManager = True
        Visible = False
        Version = '2.5.7.4'
        Caption.Color = clHighlight
        Caption.ColorTo = clNone
        Caption.Font.Charset = DEFAULT_CHARSET
        Caption.Font.Color = clWindowText
        Caption.Font.Height = -11
        Caption.Font.Name = 'Tahoma'
        Caption.Font.Style = []
        Caption.Indent = 0
        ColorTo = 16440004
        ColorMirror = 16440004
        ColorMirrorTo = 16440004
        DoubleBuffered = True
        StatusBar.Font.Charset = DEFAULT_CHARSET
        StatusBar.Font.Color = clWindowText
        StatusBar.Font.Height = -11
        StatusBar.Font.Name = 'Tahoma'
        StatusBar.Font.Style = []
        FullHeight = 46
        object AdvPicture1: TAdvPicture
          Left = 176
          Top = 8
          Width = 32
          Height = 32
          Animate = False
          AutoSize = True
          ImageTypes = []
          Picture.Stretch = False
          Picture.Frame = 0
          Picture.Data = {
            4749463839612000200077000021F90401000000002C000000002000200087FF
            00FF3F7CB4427EB5437FB64480B74781B34882B84A83B54D86BB4E87C04F88C1
            4F89C25088BC508BC35286B6528CC55388B8548CC15588B95689B9578EBD5A94
            CF5B8EBF5B94D05F95CD6299D16397C76698C4699BCF6A9DD06B9DD16D9ED26E
            9EC87496B57698B77798B779A7CD7C9AB47C9DBC7CABD37D9EBE7DA9D080A1C1
            84B0DC85B2DE86B0D188B2D388B2D68BB4D48DB7E192B1CB93B3D493BBD993BB
            DE94BCE395A8BB97B6D899A8B69AC0E69CBCDE9CBDDE9DBDDEADB2B6AFDBFFB1
            D0E6B2DDFFB3DDFFB4DEFFB5DEFFB6DFFFB8BABDB8E0FFB9E0FFBAE1FFBBBBBB
            BBE2FFBCBCBCBCE2FFBDBDBDBDE2FFBFE4FFC0E4FFC2E5FFC3C3C3C3E5FFC6C6
            C6C6E7FFC7C7C7C7E7FFC8D3DDC8E7FFC9E9FFCAE9FFCBCED0CBE8FFCCEBFFCD
            EBFFCEE5F9CEECFFCFECFFD0EBFFD1D1D1D1E8F9D1EDFFD2D2D2D2ECFFD3D3D3
            D3E8FAD4EFFFD5ECF6D5EEFFD5F0FFD7EDF8D8D8D8D8F1FFDADADADAF2FFDBF3
            FFDCF4FFDFF5FFE0F6FFE2F4FFE2F7FFE3E3E3E3F4FFE3F5FFE3F8FFE4E4E4E5
            F4FFE5F9FFE6E6E6E6FAFFE7F9FFE7FAFFE7FBFFE8E8E8E8FAFFE9E9E9E9FAFF
            E9FBFFE9FCFFEAF9FFEAFAFFEAFBFFEAFCFFEBFBFFEBFCFFECEEF0ECFDFFECFE
            FFEDEDEDEDFEFFEDFFFFEEEEEEEEFFFFEFEFEFEFFBFFEFFEFFEFFFFFF0FFFFF1
            F1F1F2F2F2F3F3F3F3FFFFF4F6F9F4FFFFF5F5F5F5FFFFF6F6F6F7FFFFF8FFFF
            F9F9F9F9FFFFFAFAFAFAFFFFFBFBFBFCFCFCFDFDFDFEFEFEFF00FFFFFFFF0000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000008
            FE0001081C48B0A0C18308132A5C5890D48E0F172A489C48F1C2871DA418C2EA
            9141C71A4E20438A04B94647061EB012B6F2C002101F2F4F7EC89C49F389173E
            8058746875B01587188DC81009226488D1A34885042142A6510C0E3C09C2C2B1
            A2919622479068DDCA95EB91225A1AADC09172E0240C79D22459D2A4ADDBB770
            9B2C4992260F8649035FCDB0D1070A942880030B1E1CD86F1F1B335E0914A521
            8C1B2954224B9E4C99B214376134881268E981A33156B0881E4DBA74692B631C
            3DB0243051034463B670994DBBB66DDB5BC6206A90A8F5024562BE80194EBCB8
            71E35FC4285AD01B40220591DE9C994EBDBAF5EB67DE4452D03C51024C74D8FE
            881F4FBEBC7936743025E86EC10C1E39F0E3CB9F4F5F0E1E33169A5B52518391
            9D3A000628E08003DAC1480D2AB00680285D44A0082178DC21E184145638211E
            84281241179B01F0CA1F269C304A217EE861E28928A6A8871F858C72020A7B28
            265028654CF0C229951812C88E3CF6C8E320865472CA0B1294118A54895C0141
            0A9D7C2289228A2C02892454562909259A8CE2490A105C91485903B522C81523
            200084278B3CA24929A9A8E2E69BACC0410303225C21485405B59248194A8050
            8A249EB461800003146A28010E8460441989E069102CA2CC11402A9F5CB2810F
            4C64AA29134E4C51C61EA18099502214B8C20A0937CC714822ACB69A882540A2
            C8B8902C59B8404B0B21C4610A430CAD224321309450C626B1F0BA5028071490
            831A96886AEC41A0A051C51CA038FBAC41AB6462092AB25CEBEDB7E03E1B1000
            3B}
          PicturePosition = bpTopLeft
          Visible = False
          Version = '1.5.0.0'
        end
        object AdvEdit12: TAdvEdit
          Left = 12
          Top = 6
          Width = 150
          Height = 33
          BorderColor = clNavy
          DefaultHandling = True
          EditType = etUppercase
          EmptyTextStyle = []
          FocusColor = clWindow
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          Lookup.Font.Charset = DEFAULT_CHARSET
          Lookup.Font.Color = clWindowText
          Lookup.Font.Height = -11
          Lookup.Font.Name = 'Arial'
          Lookup.Font.Style = []
          Lookup.Separator = ';'
          BevelInner = bvNone
          AutoSelect = False
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Visible = True
          OnKeyPress = AdvEdit12KeyPress
          Version = '3.4.5.5'
        end
        object AdvColumnGrid3: TAdvColumnGrid
          Left = 220
          Top = 0
          Width = 389
          Height = 46
          Cursor = crDefault
          Align = alRight
          ColCount = 7
          DefaultColWidth = 55
          DrawingStyle = gdsClassic
          FixedCols = 0
          RowCount = 2
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 1
          HoverRowCells = [hcNormal, hcSelected]
          ActiveCellFont.Charset = DEFAULT_CHARSET
          ActiveCellFont.Color = clWindowText
          ActiveCellFont.Height = -11
          ActiveCellFont.Name = 'Tahoma'
          ActiveCellFont.Style = [fsBold]
          ColumnHeaders.Strings = (
            'Slides'
            'Trans'
            ''
            'Total'
            ''
            'Conc')
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
          FixedColWidth = 55
          FixedRowHeight = 22
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -11
          FixedFont.Name = 'Tahoma'
          FixedFont.Style = [fsBold]
          FloatFormat = '%.0f'
          GridImages = cxImageList1
          HoverButtons.Buttons = <>
          HoverButtons.Position = hbLeftFromColumnLeft
          HTMLSettings.ImageFolder = 'images'
          HTMLSettings.ImageBaseName = 'img'
          Navigation.AdvanceOnEnter = True
          Navigation.AdvanceAuto = True
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
          SelectionColor = clWindow
          SortSettings.DefaultFormat = ssAutomatic
          SortSettings.Column = 1
          VAlignment = vtaCenter
          Version = '3.1.6.0'
          WordWrap = False
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
              Header = 'Slides'
              HeaderAlignment = taCenter
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = clWindowText
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
              Width = 55
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
              Header = 'Trans'
              HeaderAlignment = taCenter
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = clWindowText
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
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
              HeaderAlignment = taCenter
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = clWindowText
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
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
              Header = 'Total'
              HeaderAlignment = taCenter
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = clWindowText
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
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
              Header = 'Conc'
              HeaderAlignment = taCenter
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = clWindowText
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
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
              SortStyle = ssAlphaNoCase
              SpinMax = 0
              SpinMin = 0
              SpinStep = 1
              Tag = 0
              Width = 55
            end>
          ColWidths = (
            55
            55
            55
            55
            55
            55
            55)
        end
      end
      object AdvStringGrid1: TAdvStringGrid
        Left = 0
        Top = 46
        Width = 609
        Height = 81
        Cursor = crDefault
        Align = alTop
        Anchors = [akLeft, akTop, akRight, akBottom]
        ColCount = 255
        DefaultColWidth = 55
        DefaultRowHeight = 20
        DrawingStyle = gdsClassic
        FixedCols = 0
        RowCount = 3
        ScrollBars = ssHorizontal
        TabOrder = 2
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
        DefaultAlignment = taRightJustify
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
          'Larger than'
          'Smaller than'
          'Clear')
        FixedColWidth = 55
        FixedRowHeight = 20
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
        ScrollBarAlways = saHorz
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
        SelectionColor = clWindow
        SizeWithForm = True
        SortSettings.DefaultFormat = ssAutomatic
        Version = '8.3.5.4'
        WordWrap = False
      end
    end
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 656
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
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00030000000C0000001300000014000000140000001500000015000000150000
          001600000016000000150000000E000000030000000000000000000000000000
          000B19437DC32058ABFF1F56ABFF1F56ABFF1E55AAFF1C54ABFF1D54A9FF1C52
          A9FF1B52A8FF1B51A8FF133A78C60000000D0000000000000000000000000000
          000F2763B2FF74CAF6FF60C0F4FF74CAF6FF7CCCF6FF77CAF6FF72C7F5FF6FC5
          F4FF69C3F4FF65C0F3FF1D53A9FF000000120000000000000000000000000000
          000E2A69B3FB7FCBF2FF52A3DBFF306CB2FF2F6BB1FF2E6AB1FF2D69B1FF2D68
          B0FF2C67B0FF2A65B0FF1F4A82C90000000C0000000000000000000000000000
          00081738629A67A6D9FF89D6F9FF4C94CFFF0B2459BA0002052A000000140000
          001100000011000000110000000B000000030000000000000000000000000000
          00010000000B1A3C689F6CACDCFF8DD8F9FF58A8E0FF102E68C5010205180000
          0002000000000000000000000000000000000000000000000000000000000000
          0000000000020000000D1B3F68A167ABDCFF78D1F8FF59A9DFFF0D2556A80000
          0007000000000000000000000000000000000000000000000000000000000000
          0000000000010000000B091B4B9F4D8DC5FF7BD4F9FF6EB4E1FF1E4673AA0000
          0007000000000000000000000000000000000000000000000000000000000000
          0001000000090A1F4D9B5694CAFF84DBFAFF7ABEE6FF2B5A8CC2020407160000
          0002000000000000000000000000000000000000000000000000000000000000
          00050C224D94649BCBFF8FE2FCFF81C3E8FF27547FB30204071E0000000D0000
          000B0000000C0000000B00000007000000020000000000000000000000000000
          00074186C5FBA1E3F9FF67B9E4FF3777BCFF3372B7FF316EB5FF2E6AB2FF2C67
          B0FF2A63ADFF2961ACFF1B4278BF000000070000000000000000000000000000
          0007458FCBFFC7F4FEFFC4F2FEFFC3F2FEFFBFF0FEFFBCF0FEFFB9EEFDFFB5ED
          FDFFB2ECFCFFAEEBFCFF3677BBFF000000090000000000000000000000000000
          000431729AC14299D0FF4298D0FF4398CFFF4397CFFF4396CFFF4395CEFF4294
          CEFF4292CDFF4190CCFF2C6090C3000000060000000000000000000000000000
          0001000000030000000600000006000000060000000600000007000000070000
          0007000000080000000700000005000000010000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
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
          0000000000000000000000000000000000000000001E00000033000000330000
          00330000001E0000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000001E3B3B3BAC636363FF626263FF6363
          63FF3B3B3BAC0000001E00000000000000000000000000000000000000000000
          00000000000000000000000000003B3B3BAC6F6E6EFF95918FFF989492FF9591
          8FFF6F6E6EFF3B3B3BAC00000000000000000000000000000000000000000000
          0000000000000000000000000000636464FF858381FF878481FF868381FF8784
          81FF858381FF636464FF00000000000000000000000000000000000000000000
          0000000000000000000000000000626363FF8E8C8BFF767371FF767371FF7673
          71FF8E8C8BFF626363FF00000000000000000000000000000000000000000000
          0000000000000000000000000000626363FFA7A5A5FF7D7B7AFF787675FF7D7B
          7AFFA7A5A5FF626363FF00000000000000000000000000000000000000000000
          00000000000000000000000000003B3B3B976F6E6EFFA6A5A4FFA9A8A9FFA6A5
          A4FF6D6E6EFF3B3B3B9700000000000000000000000000000000000000000000
          0000000000000000000000000000000000003B3B3B97626262FF616161FF6262
          62FF3B3B3B970000000000000000000000000000000000000000000000000000
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
          00000000000000000001000000050000000A0000000D0000000E0000000D0000
          000A000000050000000100000000000000000000000000000000000000000000
          0000000000030000000A0B0C3065191A67BF1F2285EE222492FF1F2085EE1719
          66BF0B0B30650000000B00000003000000010000000000000000000000000000
          000403040D241A1C67B83439A5FF515CC7FF606DD6FF6574DEFF5E6CD6FF4E5A
          C6FF3034A2FF181A65BA03030C25000000040000000100000000000000030606
          1632292B8FEA525BC1FF6574DBFF535DCBFF484FC0FF444CBEFF4750C1FF535E
          CBFF6371DAFF4851BDFF23278BEB04040E2700000003000000000101020D2629
          84D5636ECBFF6472D7FF464DBEFF999CD9FFDBDCF1FFFEFDFDFFDBDBF1FF999C
          DAFF484EC0FF626ED7FF515CC4FF1C1E69B80000000A0000000112143D694A52
          B8FF7887E0FF4A50BEFFD2D3EBFFFCFBFAFFFDFBF9FFFCFBFAFF73584EFFE2E1
          E0FFD5D5ECFF4B52C0FF6B7ADDFF3E46AFFF0F10366500000004262A79BB7681
          D5FF5964CBFFA1A2D8FFFBF8F5FFFCF8F6FFFBF8F6FFFBF8F6FF755950FFE1DF
          DDFFFBF8F6FFA2A3D9FF5761CBFF606CCEFF222574BD00000008363AA2EC92A0
          E7FF454CBCFFE1DEEAFFFAF5F2FFF9F5F2FFFAF5F2FFFAF5F2FF775C51FFE0DC
          D9FFFAF5F2FFE2DFEAFF464DBEFF7485DFFF2E3398EA000000093E45B4FFA1AF
          EEFF3F43B7FFF4EEEDFFF8F2EDFFE0DCD8FFE3E2E1FFE5E5E5FF785D53FFE0DC
          D8FFF7F2EDFFF4EEECFF4146B8FF8193E7FF363BA9FA000000093B42AAECA1AE
          EBFF454BBAFFDED8E2FF4945B2FF433CACFF3B33A5FF352B9EFF5B4770FFF8F7
          F6FFF6EFE9FFDED9E2FF464BBCFF8595E5FF343BA2EA00000008313685B9919C
          E1FF6770CCFF9492CBFFF5ECE6FFFEFDFCFFFFFFFFFFFFFFFFFFFFFFFFFFFEFD
          FCFFF4ECE5FF9593CDFF5D68CCFF7D8ADCFF2C3280BA000000061A1C44607982
          D6FFA5B3EBFF4246B7FFC5C0D7FFF5EEE7FFFBF8F5FFFEFDFCFFFBF8F6FFF5EE
          E7FFC6C0D7FF4247B7FF8E9FE7FF6B73CFFF17193F6000000003010102085A61
          AACF9FAAE8FF96A1E3FF4044B5FF8C89C6FFCDC6D7FFF0E6DFFFCDC6D7FF8C8A
          C7FF3F44B6FF8593DFFF949EE3FF464A8CB40000000600000001000000011112
          1E296F75C4E99AA5E6FFADBAEDFF6A74CCFF444AB8FF383CB0FF454AB8FF636C
          CBFFA1B0EBFF959EE3FF6269BDE90A0B141F0000000100000000000000000000
          00010A0B121A535894B18690DEFFACB7EDFFBDC9F5FFC5D2F8FFBDC8F5FFAAB6
          ECFF828BDCFF4E5491B2090A111B000000020000000000000000000000000000
          000000000001000000032527404F494D7F9A6168ABCC7780D4F96066ABCC474C
          7F9B23263F500000000400000001000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000F8FAF8FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000395D2EFF488A4FFF49AE72FF4B9C67FF000000004A9B
          66FF4C9B61FF3E6936FF00000000000000000000000000000000000000000000
          000000000000467946FF47CC8EFF4CCC8BFF3ACE99FF3CD09FFF5DBE72FF38CC
          91FF3DC882FF45CE89FF52944BFF00000000000000000000000000000000F2F4
          F1FF447540FF43C97CFF69E7D2FF95FBF8FF54D6AAFF41C482FF5BA85AFF43C0
          74FF4DD19FFF7EECD9FF51D8A1FF4AAB6AFF000000000000000000000000395F
          2FFF45C988FF58D9ADFF9CFFFFFF96FDFBFF4ED4A0FF4DA353FF375B2DFF479A
          50FF4DD8A6FF9CFFFFFF90FAF4FF4ED398FF4A8543FFF2F4F1FF000000003D78
          46FF40CF92FF86F5EDFF9FFFFFFF6DE4C3FF53B557FF395D2AFF00000000365A
          2BFF4EB05CFF67E2BFFF9DFFFFFF76E8CEFF44CA87FF3A6131FF00000000439C
          61FF4ED19AFF9AFFFFFF85F5EDFF46CD8CFF456B24FF00000000000000000000
          000042601AFF4CC26DFF81F4E9FF92FCF9FF43D092FF468750FF000000003DAA
          70FF4FDCB8FF9EFFFFFF69DDB6FF51B853FF385D2BFF00000000000000000000
          0000385C25FF48BF67FF6CE5CBFF9BFFFFFF4AD2A0FF439E61FF0000000043A1
          64FF50D29EFF9EFFFFFF64E4C8FF4CBD62FF395D2BFF00000000000000000000
          00003E6528FF4AC16AFF7CECD7FF9AFFFEFF46D8ADFF429C65FF000000004084
          4EFF40D5A1FF91FBF8FF85F6EDFF4EC472FF497027FFF8FAF8FF000000000000
          0000539A3DFF51DBB1FF97FEFDFF8FF9F3FF49C982FF427C48FF00000000395F
          2FFF4DC273FF71E3C4FFA0FFFFFF71EEDAFF4BC276FF3B612FFF00000000467B
          3AFF4EC77BFF88F4E7FFA0FFFFFF6BE8D2FF3FCF91FF3C6332FF000000000000
          000042713BFF44D399FF7EF2E7FF9BFFFFFF4AD19AFF4FB364FF496834FF4ABC
          69FF5FDDB6FFA0FFFFFF8CF6EFFF47CB87FF4FA465FF00000000000000000000
          00000000000045874EFF50CD81FF5BDCB7FF40C98EFF3FC178FF66C574FF39C8
          93FF50D5ABFF78EAD5FF4ADBB0FF4DB26AFF395F2FFF00000000000000000000
          000000000000000000003F6533FF48BC78FF44CB7FFF42CB8FFF5DA96BFF3FD3
          9EFF40CF91FF4BBE6FFF499C60FF385D2EFF0000000000000000000000000000
          000000000000000000000000000000000000375935FF3C6435FF000000003058
          36FF36653EFF3A6131FF00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000003300000033000000330000
          0000000000000000000000000000000000000000000000000000000000300000
          0033000000330000003300000033000000334F6B87FF496686FF4F91DBFF0000
          0033000000330000003300000033000000330000003000000000AE7B18F2B67E
          0EFFB47B09FFB47A07FFB67B06FFBF7D00FF5382A8FF7FA7B7FF8ED5FFFF2C68
          A5FFCD8500FFBD7F08FFB67C09FFB67E0EFFAE7B18F200000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF37A9F3FF88E4FFFF7FD3FFFF109A
          FFFF2964A0FFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000B47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFDBBFA3FFFFFFFFFF1C6EC3FF3DC4FFFF2AAA
          FFFF1399FFFF255D93FFFFFFFFFFFFFFFFFFB57C09FF00000000B47A08FFFFFF
          FFFFFFFFFDFFFFFFFDFFFFFFFFFFD9BFA1FFFFFFFFFFFFFFFFFF2373C6FF43C7
          FFFF2AAAFFFF0F97FFFF1E5C96FFFFFFFFFFB97F0AFF00000000B47B08FFFFFF
          FFFFD4B999FFD5BA9AFFD6BC9EFFD8BFA1FFD8BE9EFFDEC09DFFEEC79DFF2373
          C6FF3FC5FFFF20A9FFFF7EACD5FF747173FFC08406FF00000000B47B08FFFFFF
          FFFFFFFDF2FFFFFEF3FFFFFFF7FFD7BB9AFFFFFFF8FFFFFFF8FFDEBE99FFFFFF
          F5FF1B70C7FFACD9F0FF918780FFBEBEBBFF737B76FF00000033B47B08FFFFFF
          FFFFFFFBEBFFFFFCECFFFFFFF0FFD7BA96FFFFFFF1FFFFFFF1FFD8BB96FFFFFF
          F1FFFFFFF2FF807C79FFE9E7E4FF888B83FFB979B7FF9769CCFFB47B08FFFFFF
          FFFFD4B38CFFD5B58FFFD7B892FFD8BA95FFD7B893FFD7B893FFD8BA95FFD8B9
          93FFDBBA94FFE1C097FF7A7E7BFFDFAFE0FFCA95C8FFAE7CD0FFB47B08FFFFFF
          FFFFFFF7DFFFFFF8E1FFFFFBE5FFD6B78FFFFFFBE6FFFFFBE6FFD6B78FFFFFFB
          E6FFFFFCE6FFD9BA90FFFFFFE5FFB87ED7FFBB86DFFF00000000B47B08FFFFFF
          FFFFFFF5D7FFFFF6D9FFFFF9DEFFD7B58BFFFFF9DFFFFFF9DFFFD7B58BFFFFF9
          DFFFFFF9DFFFD8B68AFFFFFBDCFFFFFFFFFFB67E00FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFDFB6
          83FFDFB683FFDDB684FFDBB380FFFFFFFFFFB57C07FF00000000B57C09FFFFFF
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
          00000000000000000000000000000000000000000000000000000000002C0000
          0033000000330000003300000033000000330000003300000033000000330000
          00330000003300000033000000330000003300000030000000009E7115E1B67E
          0EFFB47B09FFB47A07FFB47A08FFB47B08FFB47A08FFB47A08FFB47B08FFB47B
          08FFB57B08FFB67C08FFB67D09FFB77F0EFFAE7B18F200000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB87F0EFF00000000B47B09FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFD8BFA2FFFFFFFFFFFFFFFFFFD8BFA2FFFFFF
          FFFFFFFFFFFF5D5FB3FF091EBFFFFFFFFFFFBD8208FF00000000B57B08FFFFFF
          FFFFFFFFFCFFFFFFFBFFFFFFFEFFE9CC9DFFFFFFFFFFFFFFFFFFE7CA9EFFFFFF
          FFFFFFFFFFFF1225BDFF818EF5FF1329C9FFCC8C00FF00000000B67C08FFFFFF
          FFFF5E5FAFFF1124BBFF1628BCFF172ABDFF1729BCFF1628BCFF1327BFFF6364
          B2FFF4D39BFF182BBEFF546AFFFF8D9BF5FF1C32CBFF00000033B77D08FFFFFF
          FFFF1124BEFF7386FFFF5066FCFF5167FCFF5167FCFF5066FCFF7487FFFF1428
          BFFFFFFFF5FF1B2DBEFF4961F9FF465FF8FF98A3F4FF2839C4FFB77D08FFFFFF
          FFFF1024BFFF94A4FAFF7C8FF5FF7D90F5FF7D8FF5FF7C8FF5FF95A4FBFF1428
          C0FFFFFFEEFF1B2DBEFF3C56F3FF3853F1FFA1AEF5FF2839C4FFB67C08FFFFFF
          FFFF5E5DABFF1024BEFF1427BFFF1528C0FF1528BFFF1427BFFF1126C2FF6362
          AFFFF4CE8EFF192CC1FF2A48F0FFA9B5F8FF1B30CBFF00000000B57B08FFFFFF
          FFFFFFFFDDFFFFFFDEFFFFFFE1FFE7C48BFFFFFFE2FFFFFFE2FFE5C38CFFFFFF
          E3FFFFFFE2FF1226C2FFA7B3F7FF1228C9FFCB8C00FF00000000B47B08FFFFFF
          FFFFFFF6D7FFFFF8D9FFFFFBDDFFDAB88AFFFFFCDEFFFFFCDEFFD9B78AFFFFFC
          DEFFFFFFDCFF5F5FAEFF0B21C4FFFFFFFFFFBD8208FF00000000B57B09FFFFFF
          FFFFDDB17CFFE0B47EFFE0B682FFDEB786FFDFB683FFDFB683FFDEB786FFE0B6
          83FFE3B982FFE8BE83FFE8BD7FFFFFFFFFFFB67D09FF00000000B57C09FFFFFF
          FFFF44C3FFFF49C5FFFF47C6FFFFE3B57EFF46C7FFFF46C7FFFFE3B57EFF46C7
          FFFF47C7FFFFE3B67EFF42C6FFFFFFFFFFFFB67C09FF00000000B67E0EFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000008F6613C5B67E
          0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B08FFB67B
          08FFB67B08FFB57B08FFB67C09FFB67E0EFF9E7115DA00000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          002F000000330000003300000033000000330000003300000033000000330000
          003300000033000000330000003300000033000000330000003000000000AB7A
          18F0B87F0FFFB87C0BFFB77C0AFFB57B09FFB47B08FFB47A08FFB47A08FFB47B
          08FFB47A08FFB47A08FFB47B08FFB47B09FFB67E0EFFAE7B18F200000000B87F
          0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF00000000C07F
          0EFFFFFFFFFF007D34FF10975DFFFFFFFFFFDABEA5FFFFFFFFFFFFFFFFFFD9BD
          A4FFFFFFFFFFFFFFFFFFD9BDA3FFFFFFFFFFFFFFFFFFB47B09FF00000000C082
          14FF008341FF45D6A9FF007F37FFFFFFFFFFE8C3A8FFFFFFFFFFFFFFFFFFEFC3
          AAFFFFFFFFFFFFFFFFFFECC2A8FFFFFFFFFFFFFFFFFFB57B08FF000000330088
          49FF5CD7B5FF00DAA2FF00813BFFFDC7AFFF449A64FF007E36FF007E37FF007F
          38FF007E37FF007E37FF007E36FF3E965FFFFFFFFFFFB67C09FF008B4CFF6DDA
          BFFF00CE9DFF00CFA0FF00813BFFFFFFFFFF008039FF26E2B5FF00D59EFF00D5
          9EFF00D59EFF00D59EFF26E2B5FF007E36FFFFFFFFFFB87C0AFF008A4BFF80DE
          CAFF00C69EFF00C8A0FF00813BFFFFFFFFFF008039FF78E3D8FF5BD9C9FF5DD9
          C9FF5DD9C9FF5BD9C9FF78E3D8FF007E36FFFFFFFFFFB87C0AFF000000000087
          47FF93E0D2FF00C1A1FF00823CFFFCC2A2FF439860FF007F37FF007F37FF0080
          39FF007F37FF007F37FF007F38FF3D945AFFFFFFFFFFB67C09FF00000000BF82
          12FF00833FFF95E0D4FF00813AFFFFFFF2FFE6BC96FFFFFFEDFFFFFFEDFFECBC
          96FFFFFFEDFFFFFFEDFFE9BB95FFFFFDE8FFFFFFFFFFB57B09FF00000000BF7E
          0DFFFFFFFFFF007F37FF11985AFFFFFFE7FFDCB78DFFFFFAE0FFFFFAE0FFDBB6
          8CFFFFFAE0FFFFFAE0FFDAB68BFFFFF8DCFFFFFFFFFFB47B09FF00000000B77C
          0AFFFFFFFFFFDDB480FFDEB681FFE7B886FFDFB786FFDFB683FFDFB683FFDEB7
          86FFDFB683FFDFB683FFDDB684FFDBB37FFFFFFFFFFFB57B09FF00000000B67C
          09FFFFFFFFFF48C4FFFF4CC6FFFF48C7FFFFE3B57EFF46C7FFFF46C7FFFFE3B5
          7EFF46C7FFFF46C7FFFFE1B47EFF40C4FFFFFFFFFFFFB57C09FF00000000B67E
          0EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB67E0EFF000000009D70
          15D8B67E0EFFB67C09FFB67B07FFB67B08FFB57B08FFB67B08FFB67B08FFB57B
          08FFB67B08FFB67B08FFB57B08FFB67C09FFB67E0EFF9E7115DA}
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
      end>
  end
  object AdvToolBarOfficeStyler1: TAdvToolBarOfficeStyler
    AppColor.AppButtonColor = 13005312
    AppColor.AppButtonHoverColor = 16755772
    AppColor.TextColor = clWhite
    AppColor.HoverColor = 16246477
    AppColor.HoverTextColor = clBlack
    AppColor.HoverBorderColor = 15187578
    AppColor.SelectedColor = 15187578
    AppColor.SelectedTextColor = clBlack
    AppColor.SelectedBorderColor = 15187578
    Style = bsCustom
    BorderColor = 14731181
    BorderColorHot = 14731181
    ButtonAppearance.Color = 16640730
    ButtonAppearance.ColorTo = 14986888
    ButtonAppearance.ColorChecked = 9229823
    ButtonAppearance.ColorCheckedTo = 5812223
    ButtonAppearance.ColorDown = 5149182
    ButtonAppearance.ColorDownTo = 9556991
    ButtonAppearance.ColorHot = 13432063
    ButtonAppearance.ColorHotTo = 9556223
    ButtonAppearance.BorderDownColor = clNavy
    ButtonAppearance.BorderHotColor = clNavy
    ButtonAppearance.BorderCheckedColor = clNavy
    ButtonAppearance.CaptionFont.Charset = DEFAULT_CHARSET
    ButtonAppearance.CaptionFont.Color = clWindowText
    ButtonAppearance.CaptionFont.Height = -12
    ButtonAppearance.CaptionFont.Name = 'Segoe UI'
    ButtonAppearance.CaptionFont.Style = []
    CaptionAppearance.CaptionColor = clHighlight
    CaptionAppearance.CaptionColorTo = clHighlight
    CaptionAppearance.CaptionBorderColor = clHighlight
    CaptionAppearance.CaptionColorHot = 13432063
    CaptionAppearance.CaptionColorHotTo = 9556223
    CaptionAppearance.CaptionTextColorHot = clBlack
    CaptionFont.Charset = DEFAULT_CHARSET
    CaptionFont.Color = clWindowText
    CaptionFont.Height = -11
    CaptionFont.Name = 'Segoe UI'
    CaptionFont.Style = []
    ContainerAppearance.LineColor = clBtnShadow
    ContainerAppearance.Line3D = True
    Color.Color = 16640730
    Color.ColorTo = 14986888
    Color.Direction = gdVertical
    Color.Mirror.Color = 16440004
    Color.Mirror.ColorTo = 16440004
    Color.Mirror.ColorMirror = 16372409
    Color.Mirror.ColorMirrorTo = 16572878
    ColorHot.Color = 16773606
    ColorHot.ColorTo = 16444126
    ColorHot.Direction = gdVertical
    ColorHot.Mirror.Color = 16507602
    ColorHot.Mirror.ColorTo = 16507602
    ColorHot.Mirror.ColorMirror = 16506056
    ColorHot.Mirror.ColorMirrorTo = 16639959
    CompactGlowButtonAppearance.BorderColor = 14727579
    CompactGlowButtonAppearance.BorderColorHot = 10079963
    CompactGlowButtonAppearance.BorderColorDown = 4548219
    CompactGlowButtonAppearance.BorderColorChecked = clBlack
    CompactGlowButtonAppearance.Color = 15653832
    CompactGlowButtonAppearance.ColorTo = 16178633
    CompactGlowButtonAppearance.ColorChecked = 11918331
    CompactGlowButtonAppearance.ColorCheckedTo = 7915518
    CompactGlowButtonAppearance.ColorDisabled = 15921906
    CompactGlowButtonAppearance.ColorDisabledTo = 15921906
    CompactGlowButtonAppearance.ColorDown = 7778289
    CompactGlowButtonAppearance.ColorDownTo = 4296947
    CompactGlowButtonAppearance.ColorHot = 15465983
    CompactGlowButtonAppearance.ColorHotTo = 11332863
    CompactGlowButtonAppearance.ColorMirror = 15586496
    CompactGlowButtonAppearance.ColorMirrorTo = 16245200
    CompactGlowButtonAppearance.ColorMirrorHot = 5888767
    CompactGlowButtonAppearance.ColorMirrorHotTo = 10807807
    CompactGlowButtonAppearance.ColorMirrorDown = 946929
    CompactGlowButtonAppearance.ColorMirrorDownTo = 5021693
    CompactGlowButtonAppearance.ColorMirrorChecked = 10480637
    CompactGlowButtonAppearance.ColorMirrorCheckedTo = 5682430
    CompactGlowButtonAppearance.ColorMirrorDisabled = 11974326
    CompactGlowButtonAppearance.ColorMirrorDisabledTo = 15921906
    CompactGlowButtonAppearance.GradientHot = ggVertical
    CompactGlowButtonAppearance.GradientMirrorHot = ggVertical
    CompactGlowButtonAppearance.GradientDown = ggVertical
    CompactGlowButtonAppearance.GradientMirrorDown = ggVertical
    CompactGlowButtonAppearance.GradientChecked = ggVertical
    DockColor.Color = 16105376
    DockColor.ColorTo = 16440004
    DockColor.Direction = gdHorizontal
    DockColor.Steps = 128
    FloatingWindowBorderColor = 9516288
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    GlowButtonAppearance.BorderColor = 14727579
    GlowButtonAppearance.BorderColorHot = 10079963
    GlowButtonAppearance.BorderColorDown = 4548219
    GlowButtonAppearance.BorderColorChecked = clBlack
    GlowButtonAppearance.Color = 15653832
    GlowButtonAppearance.ColorTo = 16178633
    GlowButtonAppearance.ColorChecked = 11918331
    GlowButtonAppearance.ColorCheckedTo = 7915518
    GlowButtonAppearance.ColorDisabled = 15921906
    GlowButtonAppearance.ColorDisabledTo = 15921906
    GlowButtonAppearance.ColorDown = 7778289
    GlowButtonAppearance.ColorDownTo = 4296947
    GlowButtonAppearance.ColorHot = 15465983
    GlowButtonAppearance.ColorHotTo = 11332863
    GlowButtonAppearance.ColorMirror = 15586496
    GlowButtonAppearance.ColorMirrorTo = 16245200
    GlowButtonAppearance.ColorMirrorHot = 5888767
    GlowButtonAppearance.ColorMirrorHotTo = 10807807
    GlowButtonAppearance.ColorMirrorDown = 946929
    GlowButtonAppearance.ColorMirrorDownTo = 5021693
    GlowButtonAppearance.ColorMirrorChecked = 10480637
    GlowButtonAppearance.ColorMirrorCheckedTo = 5682430
    GlowButtonAppearance.ColorMirrorDisabled = 11974326
    GlowButtonAppearance.ColorMirrorDisabledTo = 15921906
    GlowButtonAppearance.GradientHot = ggVertical
    GlowButtonAppearance.GradientMirrorHot = ggVertical
    GlowButtonAppearance.GradientDown = ggVertical
    GlowButtonAppearance.GradientMirrorDown = ggVertical
    GlowButtonAppearance.GradientChecked = ggVertical
    GroupAppearance.Background = clInfoBk
    GroupAppearance.BorderColor = 12763842
    GroupAppearance.Color = 16640730
    GroupAppearance.ColorTo = 15851212
    GroupAppearance.ColorMirror = 15851212
    GroupAppearance.ColorMirrorTo = 16640730
    GroupAppearance.Font.Charset = DEFAULT_CHARSET
    GroupAppearance.Font.Color = clWindowText
    GroupAppearance.Font.Height = -12
    GroupAppearance.Font.Name = 'Segoe UI'
    GroupAppearance.Font.Style = []
    GroupAppearance.Gradient = ggVertical
    GroupAppearance.GradientMirror = ggVertical
    GroupAppearance.TextColor = clBlack
    GroupAppearance.CaptionAppearance.CaptionColor = 15915714
    GroupAppearance.CaptionAppearance.CaptionColorTo = 15784385
    GroupAppearance.CaptionAppearance.CaptionTextColor = clBlack
    GroupAppearance.CaptionAppearance.CaptionColorHot = 16769224
    GroupAppearance.CaptionAppearance.CaptionColorHotTo = 16772566
    GroupAppearance.CaptionAppearance.CaptionTextColorHot = clBlack
    GroupAppearance.PageAppearance.BorderColor = 12763842
    GroupAppearance.PageAppearance.Color = 14086910
    GroupAppearance.PageAppearance.ColorTo = 16382457
    GroupAppearance.PageAppearance.ColorMirror = 16382457
    GroupAppearance.PageAppearance.ColorMirrorTo = 16382457
    GroupAppearance.PageAppearance.Gradient = ggVertical
    GroupAppearance.PageAppearance.GradientMirror = ggVertical
    GroupAppearance.PageAppearance.ShadowColor = 12888726
    GroupAppearance.PageAppearance.HighLightColor = 16644558
    GroupAppearance.TabAppearance.BorderColor = clHighlight
    GroupAppearance.TabAppearance.BorderColorHot = clHighlight
    GroupAppearance.TabAppearance.BorderColorSelected = 10534860
    GroupAppearance.TabAppearance.BorderColorSelectedHot = 10534860
    GroupAppearance.TabAppearance.BorderColorDisabled = clNone
    GroupAppearance.TabAppearance.BorderColorDown = clNone
    GroupAppearance.TabAppearance.Color = clBtnFace
    GroupAppearance.TabAppearance.ColorTo = clWhite
    GroupAppearance.TabAppearance.ColorSelected = 10412027
    GroupAppearance.TabAppearance.ColorSelectedTo = 12249340
    GroupAppearance.TabAppearance.ColorDisabled = clNone
    GroupAppearance.TabAppearance.ColorDisabledTo = clNone
    GroupAppearance.TabAppearance.ColorHot = 13432063
    GroupAppearance.TabAppearance.ColorHotTo = 13432063
    GroupAppearance.TabAppearance.ColorMirror = clWhite
    GroupAppearance.TabAppearance.ColorMirrorTo = clWhite
    GroupAppearance.TabAppearance.ColorMirrorHot = 13432063
    GroupAppearance.TabAppearance.ColorMirrorHotTo = 9556223
    GroupAppearance.TabAppearance.ColorMirrorSelected = 12249340
    GroupAppearance.TabAppearance.ColorMirrorSelectedTo = 13955581
    GroupAppearance.TabAppearance.ColorMirrorDisabled = clNone
    GroupAppearance.TabAppearance.ColorMirrorDisabledTo = clNone
    GroupAppearance.TabAppearance.Font.Charset = DEFAULT_CHARSET
    GroupAppearance.TabAppearance.Font.Color = clWindowText
    GroupAppearance.TabAppearance.Font.Height = -11
    GroupAppearance.TabAppearance.Font.Name = 'Segoe UI'
    GroupAppearance.TabAppearance.Font.Style = []
    GroupAppearance.TabAppearance.Gradient = ggVertical
    GroupAppearance.TabAppearance.GradientMirror = ggVertical
    GroupAppearance.TabAppearance.GradientHot = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorHot = ggVertical
    GroupAppearance.TabAppearance.GradientSelected = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorSelected = ggVertical
    GroupAppearance.TabAppearance.GradientDisabled = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorDisabled = ggVertical
    GroupAppearance.TabAppearance.TextColor = clBlack
    GroupAppearance.TabAppearance.TextColorHot = clBlack
    GroupAppearance.TabAppearance.TextColorSelected = clBlack
    GroupAppearance.TabAppearance.TextColorDisabled = clWhite
    GroupAppearance.TabAppearance.ShadowColor = 10796223
    GroupAppearance.TabAppearance.HighLightColor = 16775871
    GroupAppearance.TabAppearance.HighLightColorHot = 16643309
    GroupAppearance.TabAppearance.HighLightColorSelected = 6540536
    GroupAppearance.TabAppearance.HighLightColorSelectedHot = 12451839
    GroupAppearance.TabAppearance.HighLightColorDown = 16776144
    GroupAppearance.ToolBarAppearance.BorderColor = 13423059
    GroupAppearance.ToolBarAppearance.BorderColorHot = 13092807
    GroupAppearance.ToolBarAppearance.Color.Color = 15530237
    GroupAppearance.ToolBarAppearance.Color.ColorTo = 16382457
    GroupAppearance.ToolBarAppearance.Color.Direction = gdHorizontal
    GroupAppearance.ToolBarAppearance.ColorHot.Color = 15660277
    GroupAppearance.ToolBarAppearance.ColorHot.ColorTo = 16645114
    GroupAppearance.ToolBarAppearance.ColorHot.Direction = gdHorizontal
    PageAppearance.BorderColor = 14922381
    PageAppearance.Color = 16440004
    PageAppearance.ColorTo = 16440004
    PageAppearance.ColorMirror = 16372409
    PageAppearance.ColorMirrorTo = 16640215
    PageAppearance.Gradient = ggVertical
    PageAppearance.GradientMirror = ggVertical
    PageAppearance.ShadowColor = 13475194
    PageAppearance.HighLightColor = 16644558
    PagerCaption.BorderColor = 15780526
    PagerCaption.Color = 14986888
    PagerCaption.ColorTo = 14986888
    PagerCaption.ColorMirror = 14986888
    PagerCaption.ColorMirrorTo = 14986888
    PagerCaption.Gradient = ggVertical
    PagerCaption.GradientMirror = ggVertical
    PagerCaption.TextColor = clGray
    PagerCaption.TextColorExtended = clBlue
    PagerCaption.Font.Charset = DEFAULT_CHARSET
    PagerCaption.Font.Color = clWindowText
    PagerCaption.Font.Height = -13
    PagerCaption.Font.Name = 'Segoe UI'
    PagerCaption.Font.Style = []
    QATAppearance.BorderColor = 9516288
    QATAppearance.Color = 16640730
    QATAppearance.ColorTo = 14986888
    QATAppearance.FullSizeBorderColor = 14986888
    QATAppearance.FullSizeColor = 14986888
    QATAppearance.FullSizeColorTo = 14986888
    RightHandleColor = 15836789
    RightHandleColorTo = 9516288
    RightHandleColorHot = 13891839
    RightHandleColorHotTo = 7782911
    RightHandleColorDown = 557032
    RightHandleColorDownTo = 8182519
    TabAppearance.BorderColor = clNone
    TabAppearance.BorderColorHot = clHighlight
    TabAppearance.BorderColorSelected = clBlack
    TabAppearance.BorderColorSelectedHot = 6343929
    TabAppearance.BorderColorDisabled = clNone
    TabAppearance.BorderColorDown = clNone
    TabAppearance.Color = clBtnFace
    TabAppearance.ColorTo = clWhite
    TabAppearance.ColorSelected = 16571588
    TabAppearance.ColorSelectedTo = 16445929
    TabAppearance.ColorDisabled = clWhite
    TabAppearance.ColorDisabledTo = clSilver
    TabAppearance.ColorHot = 13432063
    TabAppearance.ColorHotTo = 13432063
    TabAppearance.ColorMirror = clWhite
    TabAppearance.ColorMirrorTo = clWhite
    TabAppearance.ColorMirrorHot = 13432063
    TabAppearance.ColorMirrorHotTo = 9556223
    TabAppearance.ColorMirrorSelected = 16445929
    TabAppearance.ColorMirrorSelectedTo = 16181984
    TabAppearance.ColorMirrorDisabled = clWhite
    TabAppearance.ColorMirrorDisabledTo = clSilver
    TabAppearance.Font.Charset = DEFAULT_CHARSET
    TabAppearance.Font.Color = clWindowText
    TabAppearance.Font.Height = -11
    TabAppearance.Font.Name = 'Segoe UI'
    TabAppearance.Font.Style = []
    TabAppearance.Gradient = ggVertical
    TabAppearance.GradientMirror = ggVertical
    TabAppearance.GradientHot = ggVertical
    TabAppearance.GradientMirrorHot = ggVertical
    TabAppearance.GradientSelected = ggVertical
    TabAppearance.GradientMirrorSelected = ggVertical
    TabAppearance.GradientDisabled = ggVertical
    TabAppearance.GradientMirrorDisabled = ggVertical
    TabAppearance.TextColor = clBlack
    TabAppearance.TextColorHot = clBlack
    TabAppearance.TextColorSelected = clBlack
    TabAppearance.TextColorDisabled = clGray
    TabAppearance.ShadowColor = 10708799
    TabAppearance.HighLightColor = 16775871
    TabAppearance.HighLightColorHot = 16643309
    TabAppearance.HighLightColorSelected = 6540536
    TabAppearance.HighLightColorSelectedHot = 12451839
    TabAppearance.HighLightColorDown = 16776144
    TabAppearance.BackGround.Color = 14986888
    TabAppearance.BackGround.ColorTo = 16440004
    TabAppearance.BackGround.Direction = gdHorizontal
    Left = 624
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'xml'
    Filter = 'XML Dictionary Files (*.xml)|*.xml'
    Left = 72
    Top = 136
  end
  object ipwXMLp1: TipwXMLp
    Left = 728
  end
  object cxImageList2: TcxImageList
    Height = 14
    Width = 14
    FormatVersion = 1
    DesignInfo = 688
    ImageInfo = <
      item
        Image.Data = {
          46030000424D460300000000000036000000280000000E0000000E0000000100
          2000000000001003000000000000000000000000000000000000000000000000
          0000000000000000000000000000CF9808FF7F5B00FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000007F5B00FFCF9808FF7F5B00FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000007F5B
          00FFF6CB97FFCF9808FF7F5B00FF000000000000000000000000000000000000
          000000000000000000000000000000000000000000007F5B00FFF6CB97FFF6CB
          97FFCF9808FF7F5B00FF0000000000000000000000000000000000000000CF98
          08FF7F5B00FF7F5B00FF7F5B00FF7F5B00FFF6CB97FFF6CB97FFF6CB97FFCF98
          08FF7F5B00FF000000000000000000000000000000007F5B00FFF6CB97FFF6CB
          97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFCF9808FF7F5B
          00FF0000000000000000000000007F5B00FFF6CB97FFF6CB97FFF6CB97FFF6CB
          97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFCF9808FF7F5B00FF0000
          0000000000007F5B00FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFF6CB97FFF6CB
          97FFF6CB97FFF6CB97FFF6CB97FFFFF3D5FFCF9808FF00000000000000007F5B
          00FFFFF3D5FFFFF3D5FFFFF3D5FFFFF3D5FFFFF3D5FFF6CB97FFF6CB97FFF6CB
          97FFFFF3D5FFCF9808FF000000000000000000000000CF9808FFCF9808FFCF98
          08FFCF9808FF7F5B00FFFFF3D5FFF6CB97FFF6CB97FFFFF3D5FFCF9808FF0000
          0000000000000000000000000000000000000000000000000000000000007F5B
          00FFFFF3D5FFF6CB97FFFFF3D5FFCF9808FF0000000000000000000000000000
          000000000000000000000000000000000000000000007F5B00FFFFF3D5FFFFF3
          D5FFCF9808FF0000000000000000000000000000000000000000000000000000
          00000000000000000000000000007F5B00FFFFF3D5FFCF9808FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000007F5B00FFCF9808FF000000000000000000000000000000000000
          00000000000000000000}
      end>
  end
  object AdvMemoStylerManager1: TAdvMemoStylerManager
    Items = <>
    Left = 448
    Top = 88
  end
  object AdvXMLMemoStyler1: TAdvXMLMemoStyler
    LineComment = '//'
    MultiCommentLeft = '<!--'
    MultiCommentRight = '-->'
    CommentStyle.TextColor = clNavy
    CommentStyle.BkColor = clWhite
    CommentStyle.Style = [fsItalic]
    NumberStyle.TextColor = clFuchsia
    NumberStyle.BkColor = clWhite
    NumberStyle.Style = [fsBold]
    AllStyles = <
      item
        KeyWords.Strings = (
          'val'
          'encoding'
          'xml version'
          ']]'
          '![cdata['
          '![ignore['
          '![include['
          '!element'
          '!doctype'
          'pcdata'
          'required'
          'implied'
          'fixed'
          'entity'
          'nmtoken'
          'nmtokens'
          'notation'
          'id'
          'idref'
          'idrefs'
          'xml:space'
          'xml:lang')
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        BGColor = clWhite
        StyleType = stKeyword
        BracketStart = #0
        BracketEnd = #0
        Info = 'XML Default'
      end
      item
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        BGColor = clWhite
        StyleType = stBracket
        BracketStart = #39
        BracketEnd = #39
        Info = 'Single quote'
      end
      item
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        BGColor = clWhite
        StyleType = stBracket
        BracketStart = '"'
        BracketEnd = '"'
        Info = 'Double Quote'
      end
      item
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clTeal
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        BGColor = clWhite
        StyleType = stSymbol
        BracketStart = #0
        BracketEnd = #0
        Symbols = ' =<?/>#'#13#10
        Info = 'XML delimiters'
      end>
    Description = 'XML Files (XML)'
    Filter = 'XML Files (*.xml)|*.xml'
    DefaultExtension = '.xml'
    StylerName = 'XML Files'
    Extensions = 'xml'
    Left = 448
    Top = 136
  end
  object cxImageList3: TcxImageList
    Height = 32
    Width = 32
    FormatVersion = 1
    DesignInfo = 584
    ImageInfo = <
      item
        Image.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00090000001C0C08043500000028000000280000002800000028000000280000
          0028000000280000002800000028000000280000002800000028000000280000
          0028000000280000002800000028000000280000002800000028000000280000
          002800000028000000280C080433000000150000000700000000000000000000
          00158D6134D2B2793FFDB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB378
          3DFFB2783DFFB2783DFFB2783EFE7A542DBE0000001400000000000000000000
          0016B2783DFFFFF6E4FFFDEBD4FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEA
          D2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEA
          D2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEA
          D2FFFCEAD2FFFDEBD4FFFFF6E4FFB3783DFF0000001600000000000000000000
          0016B1783CFFFFF1DEFFFFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0
          C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0
          C4FFF6E0C4FFF7E1C5FFFFF1DEFFB1783CFF0000001600000000000000000000
          0016B1783CFFFFF2DFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DC
          BDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DC
          BDFFF4DCBDFFF4DCBEFFFFF2DFFFB1783CFF0000001600000000000000000000
          0016B1783CFFFFF2DFFFFFFFFFFFFEFCFAFFFFFFFFFFFFFFFFFFFEFCFAFFFFFF
          FFFFFFFFFFFFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7
          B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7
          B6FFF1D7B6FFF1D7B6FFFFF2DFFFB1783CFF0000001600000000000000000000
          0016B1783DFFFFF3E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3
          AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3
          AFFFEFD3AEFFEFD3AEFFFFF3E0FFB1783DFF0000001600000000000000000000
          0016B1783DFFFFF3E1FFFEFDFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCF
          A7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCF
          A7FFECCFA6FFECCEA5FFFFF3E1FFB1783DFF0000001600000000000000000000
          0016B1783DFFFFF3E2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACB
          A1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACB
          A1FFEACBA0FFE9CA9EFFFFF3E2FFB1783DFF0000001600000000000000000000
          0016B2783DFFFFF4E3FFFFFEFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C6
          9AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C6
          9AFFE7C699FFE6C497FFFFF4E3FFB2783DFF0000001600000000000000000000
          0016B2783DFFFFF4E4FFFEFCF9FFFEFDFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFEFFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C2
          93FFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C2
          93FFE5C192FFE4C08FFFFFF4E4FFB2783DFF0000001600000000000000000000
          0016B27840FFFBF0DEFFDFB781FFE1BB87FFE3BE8AFFE3BE8AFFE3BE8AFFE3BE
          8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE
          8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE
          8AFFE2BD89FFE1BB85FFF9ECD9FFB27842FF0000001600000000000000000000
          000EB38659FEB67E45FFB2783DFFB47A40FFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB3783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB57C40FFB5895CFF0000000E00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
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
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00090000001C0C08043500000028000000280000002800000028000000280000
          0028000000280000002800000028000000280000002800000028000000280000
          0028000000280000002800000028000000280000002800000028000000280000
          002800000028000000280C080433000000150000000700000000000000000000
          00158D6134D2B2793FFDB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB2783DFFB378
          3DFFB2783DFFB2783DFFB2783EFE7A542DBE0000001400000000000000000000
          0016B2783DFFFFF6E4FFFDEBD4FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEA
          D2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFECDBD5FF7E75E9FFDCCD
          D8FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEAD2FFFCEA
          D2FFFCEAD2FFFDEBD4FFFFF6E4FFB3783DFF0000001600000000000000000000
          0016B1783CFFFFF1DEFFFFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FF8277E0FF0000FFFF3E38
          F0FFD7C4CBFFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0C4FFF6E0
          C4FFF6E0C4FFF7E1C5FFFFF1DEFFB1783CFF0000001600000000000000000000
          0016B1783CFFFFF2DFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFF9082D8FF0000FFFF0000
          FFFF3D37EEFFD5C0C5FFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DCBDFFF4DC
          BDFFF4DCBDFFF4DCBEFFFFF2DFFFB1783CFF0000001600000000000000000000
          0016B1783CFFFFF2DFFFFFFFFFFFFEFCFAFFFFFFFFFFFFFFFFFFFEFCFAFFFFFF
          FFFFFFFFFFFFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FF7165DDFF0000
          FFFF0000FFFF786BDBFFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7B6FFF1D7
          B6FFF1D7B6FFF1D7B6FFFFF2DFFFB1783CFF0000001600000000000000000000
          0016B1783DFFFFF3E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFF5A4F
          E1FF0000FFFF3C35EBFFD1B9B9FFEFD3AFFFEFD3AFFFEFD3AFFFEFD3AFFFEFD3
          AFFFEFD3AEFFEFD3AEFFFFF3E0FFB1783DFF0000001600000000000000000000
          0016B1783DFFFFF3E1FFFEFDFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCFA7FF8C7B
          CBFF0000FFFF0000FFFF7667D3FFECCFA7FFECCFA7FFECCFA7FFECCFA7FFECCF
          A7FFECCFA6FFECCEA5FFFFF3E1FFB1783DFF0000001600000000000000000000
          0016B1783DFFFFF3E2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACBA1FFEACB
          A1FF584CDCFF0000FFFF3B33E7FFCDB2ADFFEACBA1FFEACBA1FFEACBA1FFEACB
          A1FFEACBA0FFE9CA9EFFFFF3E2FFB1783DFF0000001600000000000000000000
          0016B2783DFFFFF4E3FFFFFEFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C69AFFE7C6
          9AFF8975C3FF0000FFFF0000FFFF3A32E6FFCAADA7FFE7C69AFFE7C69AFFE7C6
          9AFFE7C699FFE6C497FFFFF4E3FFB2783DFF0000001600000000000000000000
          0016B2783DFFFFF4E4FFFEFCF9FFFEFDFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFEFFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C293FFE5C2
          93FFE5C293FF6C5BCCFF0000FFFF0000FFFF7261C9FFE5C293FFE5C293FFE5C2
          93FFE5C192FFE4C08FFFFFF4E4FFB2783DFF0000001600000000000000000000
          0016B27840FFFBF0DEFFDFB781FFE1BB87FFE3BE8AFFE3BE8AFFE3BE8AFFE3BE
          8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE8AFFE3BE
          8AFFE3BE8AFFE3BE8AFF6B59C8FF0000FFFF7865C1FFE3BE8AFFE3BE8AFFE3BE
          8AFFE2BD89FFE1BB85FFF9ECD9FFB27842FF0000001600000000000000000000
          000EB38659FEB67E45FFB2783DFFB47A40FFB2783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFFB2783DFFB3783DFFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB2783DFF855A6EFFAC7443FFB2783DFFB2783DFFB278
          3DFFB2783DFFB2783DFFB57C40FFB5895CFF0000000E00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
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
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000030000000900000011000000150000001600000016000000160000
          0016000000150000001100000009000000030000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001000000060000
          00100000001B0000002900000038000000410000004300000043000000430000
          00430000004100000038000000290000001B0000001000000006000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000030000000D000000200000
          00350806034C4F371B99936630DEB57D39FFB47C37FFB47C37FFB47C37FFB47C
          37FFB57D39FF936731DE4F381B990806034C00000035000000200000000D0000
          0003000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000005000000160000002E1610085A9568
          31DFBF8D4EFFD8B687FFF2E0C1FFFFF8E3FFFFFFEFFFFFFFEEFFFFFFEEFFFFFF
          EFFFFFF8E4FFEDD7B5FFD3AD7DFFB98442FF956832DF1610085A0000002E0000
          0016000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000500000019000000386B4B24B4BE8B4EFFE7CF
          A9FFFFFFEEFFFFFCE7FFFFF8E2FFFFF6DFFFFFF5DEFFFFF5DDFFFFF5DDFFFFF5
          DEFFFFF6DFFFFFF8E4FFFFFDE8FFFFF8E4FFDDBF94FFB98543FF6B4B25B40000
          0038000000190000000500000000000000000000000000000000000000000000
          00000000000000000005000000190000003AA27034EDD2AC7BFFFFF7E1FFFFF8
          E4FFFFF5DEFFFFF3DBFFFEF3DAFFFEF2D9FFFEF2D9FFFEF2D9FFFEF2D9FFFEF2
          D9FFFEF2D9FFFEF3DAFFFFF4DBFFFFF5DFFFFFFAE6FFFCF0D8FFC89C65FFA371
          37ED0000003A0000001900000005000000000000000000000000000000000000
          0000000000030000001600000038A06F33EBE6CEA9FFFFFCE9FFFFF5DEFFFEF1
          D7FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0
          D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFEF1D8FFFFF6DFFFFFFEEBFFD3B0
          7FFFA17035EB0000003800000016000000030000000000000000000000000000
          00010000000D0000002EA27134ECE7CDA9FFFFFAE6FFFFF3D9FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDF0D4FFFFF3DBFFFFFC
          E9FFD5B080FFA37237EC0000002E0000000D0000000100000000000000000000
          00060000001F6A4B24B0D2AB79FFFFFBE8FFFEF2D8FFFCEED2FFFCEED2FFFCEE
          D2FFFCEED2FFFCEED2FFFCEED2FFFCEFD3FFFDF0D4FFFCEFD3FFFCEED2FFFCEE
          D2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEFD2FFFEF2
          DAFFFFFDEBFFC4965CFF6A4B25B00000001F0000000600000000000000000000
          0010150F074CBE8C4EFFFFF4DFFFFFF2DAFFFCECD0FFFCECD0FFFCECD0FFFCEC
          D0FFFCECD0FFFCECD0FFFDEED3FFFFF2D8FFFBEBCDFFFEEFD5FFFCEDD1FFFCEC
          D0FFFCECD0FFFCECD0FFFCECD0FFFCECD0FFFCECD0FFFCECD0FFFCECD0FFFCEC
          D0FFFFF3DBFFFDEFD8FFB67F3CFF150F074C0000001000000000000000030000
          001B946831DDE6CBA7FFFFF6E2FFFDECCEFFFCEBCEFFFCEBCEFFFCEBCEFFFCEB
          CEFFFCEBCEFFFDECD0FFFFF1D6FFCDA36FFFAD722CFFFFF6DDFFFFEFD3FFFDEC
          CFFFFCEBCEFFFCEBCEFFFCEBCEFFFCEBCEFFFCEBCEFFFCEBCEFFFCEBCEFFFCEB
          CEFFFDECCFFFFFF7E4FFD7B488FF956932DD0000001B00000003000000090806
          0332BE8C4CFFFFFBEAFFFCEFD3FFFBEACBFFFBEACBFFFBEACBFFFBEACBFFFBEA
          CBFFFBEACBFFFCECCDFFFFF3D6FFAF7631FFF8C77DFFAD732FFFFFF5DAFFFDEE
          D0FFFBEBCCFFFBEACBFFFBEACBFFFBEACBFFFBEACBFFFBEACBFFFBEACBFFFBEA
          CBFFFBEACBFFFDEFD5FFFCF1DDFFB67F3CFF0806033200000009000000114F37
          1B8DD6B386FFFFF6E4FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8
          C9FFFBE8C9FFFCEACBFFFFF1D6FFB07734FFF2C582FFF1C480FFAD732FFFFFF2
          D7FFFEEBCEFFFCE9CAFFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8
          C9FFFBE8C9FFFCE9C9FFFFF7E6FFC99E6AFF4F381C8D00000011000000159367
          31DAF0DABCFFFEF1D8FFFAE7C6FFFAE7C7FFFAE7C7FFFAE7C7FFFAE7C7FFFAE7
          C7FFFAE7C7FFFBE9C9FFFFF0D4FFB07734FFEEC385FFE7B469FFEDC382FFAD74
          30FFFFF1D5FFFCEBCCFFFAE8C8FFFAE7C7FFFAE7C7FFFAE7C7FFFAE7C7FFFAE7
          C7FFFAE7C7FFFAE7C7FFFFF2DBFFE2C49FFF946732DA0000001500000016B57D
          39FFFFF3E1FFFDECD0FFFAE5C4FFFAE5C5FFFAE5C5FFFAE5C5FFFAE5C5FFFAE5
          C5FFFAE5C5FFFBE7C7FFFFEED1FFB07734FFEAC489FFE1AE62FFE2AF63FFEDC7
          8DFFAD742FFFFFEED2FFFDE8CAFFFBE6C6FFFAE5C5FFFAE5C5FFFAE5C5FFFAE5
          C5FFFAE5C5FFFAE5C4FFFEEDD2FFF5E6CEFFB67E3BFF0000001600000016B47C
          38FFFFFAECFFFBE7C9FFF9E4C2FFF9E4C3FFF9E4C3FFF9E4C3FFF9E4C3FFF9E4
          C3FFF9E4C3FFFAE6C5FFFFEDCFFFB07834FFE8C48CFFDCA95CFFDCA95DFFDCA9
          5CFFECCB9AFFAE742FFFFFEDD0FFFBE7C7FFF9E4C3FFF9E4C3FFF9E4C3FFF9E4
          C3FFF9E4C3FFF9E4C2FFFCE8CAFFF9ECD9FFB57D39FF0000001600000016B47C
          38FFFFFAEDFFFAE6C5FFF9E3C0FFF9E3C1FFF9E3C1FFF9E3C1FFF9E3C1FFF9E3
          C1FFF9E3C1FFFAE5C3FFFFECCDFFB07834FFE6C592FFD7A255FFD7A357FFD7A2
          56FFDAAA62FFECCEA1FFAE742EFFFDE9C9FFFAE4C3FFF9E3C1FFF9E3C1FFF9E3
          C1FFF9E3C1FFF9E3C0FFFBE6C9FFFFFBEEFFB57D38FF0000001600000016B47C
          38FFFFFBEDFFFAE6C6FFF8E0BDFFF8E1BEFFF8E1BEFFF8E1BEFFF8E1BEFFF8E1
          BEFFF8E1BEFFF9E3C0FFFEE9C9FFB17834FFE6C797FFD19D4EFFD29E51FFD19D
          4FFFD5A55DFFEBCFA5FFAE742EFFFCE7C6FFF9E2BFFFF8E1BEFFF8E1BEFFF8E1
          BEFFF8E1BEFFF8E0BDFFFAE7C6FFFFFCEEFFB57D38FF0000001600000015B47D
          38FFFFFCEFFFFAE5C5FFF8DFBBFFF8E0BCFFF8E0BCFFF8E0BCFFF8E0BCFFF8E0
          BCFFF8E0BCFFF9E2BEFFFEE8C7FFB17834FFE5CA9FFFCB9748FFCC984AFFCB95
          46FFEAD3AEFFAE742FFFFEE9C8FFFAE3C0FFF8E0BCFFF8E0BCFFF8E0BCFFF8E0
          BCFFF8E0BCFFF8E0BBFFFBE6C6FFFBF0E1FFB57D39FF0000001500000011B57E
          39FFFEF5E6FFFBE7CAFFF7DEB8FFF7DFBAFFF7DFBAFFF7DFBAFFF7DFBAFFF7DF
          BAFFF7DFBAFFF8E1BCFFFDE7C5FFB17834FFE5CBA4FFC58E3DFFC58E3EFFE7CF
          AAFFAF7531FFFDE8C6FFF9E2BFFFF7E0BBFFF7DFBAFFF7DFBAFFF7DFBAFFF7DF
          BAFFF7DFBAFFF7DFB8FFFBE8CBFFF6EAD8FFB67E3AFF00000011000000099366
          31D6EAD4B7FFFDEED8FFF7DCB6FFF7DDB8FFF7DDB8FFF7DDB8FFF7DDB8FFF7DD
          B8FFF7DDB8FFF8DFBAFFFDE5C3FFB17833FFE5CEABFFBF8530FFE5CFADFFAF76
          31FFFDE6C4FFFAE0BDFFF8DEB9FFF7DDB8FFF7DDB8FFF7DDB8FFF7DDB8FFF7DD
          B8FFF7DDB8FFF7DCB6FFFDEFD9FFE4CBABFF936732D600000009000000034F37
          1B7CD4B285FFFFF8EBFFF6DBB3FFF6DBB5FFF6DCB6FFF6DCB6FFF6DCB6FFF6DC
          B6FFF6DCB6FFF7DEB8FFFCE4C0FFB17832FFE6D1B2FFE6D1B2FFAF7530FFFCE5
          C2FFF8DFBBFFF6DDB7FFF6DCB6FFF6DCB6FFF6DCB6FFF6DCB6FFF6DCB6FFF6DC
          B6FFF6DBB5FFF6DBB3FFFFF9ECFFCFAA7AFF4F371B7C00000003000000000806
          031AB98543FFFFFBF2FFFAE5C6FFF6DAB2FFF6DBB4FFF6DBB4FFF6DBB4FFF6DB
          B4FFF6DBB4FFF7DDB6FFFBE2BDFFB07732FFE7D7BBFFAF752FFFFCE3BFFFF8DE
          B8FFF6DCB5FFF6DBB4FFF6DBB4FFF6DBB4FFF6DBB4FFF6DBB4FFF6DBB4FFF6DB
          B4FFF6DAB2FFFAE5C7FFFEF6EBFFB78140FF0806031A00000000000000000000
          0006956831D6E3C8A9FFFFF6EAFFF6DAB1FFF6D8AFFFF6D9B1FFF6D9B1FFF6D9
          B1FFF6D9B1FFF7DAB2FFF9DEB7FFCC9E65FFAE742FFFFCE1BBFFF9DCB5FFF7DA
          B2FFF6D9B1FFF6D9B1FFF6D9B1FFF6D9B1FFF6D9B1FFF6D9B1FFF6D9B1FFF6D8
          AFFFF6DAB1FFFFF7EAFFDEC29FFF956832D60000000600000000000000000000
          0001150F0829B98543FFFDF5EAFFFCEDD7FFF5D6ABFFF5D7AEFFF5D8AFFFF5D8
          AFFFF5D8AFFFF5D8AFFFF6DAB1FFF8DDB5FFF9DDB5FFF7DBB2FFF5D9B0FFF5D8
          AFFFF5D8AFFFF5D8AFFFF5D8AFFFF5D8AFFFF5D8AFFFF5D8AFFFF5D7AEFFF5D6
          ABFFFCEDD8FFFAF1E5FFB88240FF150F08290000000100000000000000000000
          0000000000036A4A239CCBA270FFFFFFF9FFF9E3C4FFF5D5A9FFF5D7ABFFF5D7
          ADFFF5D7ADFFF5D7ADFFF5D7ADFFF6D8AEFFF6D8AEFFF5D7ADFFF5D7ADFFF5D7
          ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ABFFF5D5A9FFF9E3
          C4FFFFFEF7FFC99F6BFF6A4B249C000000030000000000000000000000000000
          00000000000000000005A37235E7DEC2A0FFFFFFFAFFF9E2C4FFF4D3A6FFF4D4
          A9FFF4D5AAFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5
          ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5AAFFF4D4A9FFF4D3A6FFF9E2C4FFFFFE
          F8FFD9BC99FFA37235E700000005000000000000000000000000000000000000
          0000000000000000000000000005A17032E5DEC3A1FFFFFFFEFFFCEDD9FFF4D4
          A8FFF4D2A5FFF4D3A7FFF4D4A8FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4
          A9FFF4D4A9FFF4D4A8FFF4D3A7FFF4D2A5FFF4D4A8FFFCEDD9FFFFFFFDFFDABF
          9BFFA27033E50000000500000000000000000000000000000000000000000000
          000000000000000000000000000000000005A37234E6CBA271FFFEFAF4FFFFFA
          F3FFF7E2C3FFF3D0A1FFF3D1A2FFF3D1A3FFF3D1A4FFF3D1A4FFF3D1A4FFF3D1
          A4FFF3D1A3FFF3D1A2FFF3D0A1FFF8E2C3FFFFFBF3FFFDF8F1FFCAA16FFFA372
          35E6000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000036B4B2499B88341FFE3CE
          B1FFFFFFFFFFFFFFFCFFFCEEDCFFF9E1C2FFF7DBB5FFF7DBB5FFF7DBB5FFF7DB
          B5FFF9E1C2FFFCEEDCFFFFFFFCFFFFFFFFFFE3CCB0FFB88341FF6B4B24990000
          0003000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001161008239467
          31D3B98342FFD5B68EFFEAD8C2FFFEFCF9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFEFCF9FFEAD8C2FFD5B58DFFB98342FF946731D316100823000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000806030E4F371B72936630D1B57D38FFB57C37FFB47C36FFB47C36FFB57C
          37FFB57D38FF936630D14F371B720806030E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000030000000900000011000000150000001600000016000000160000
          0016000000150000001100000009000000030000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001000000060000
          00100000001B0000002900000038000000410000004300000043000000430000
          00430000004100000038000000290000001B0000001000000006000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000030000000D000000200000
          00350806034C4F371B99936630DEB57D39FFB47C37FFB47C37FFB47C37FFB47C
          37FFB57D39FF936731DE4F381B990806034C00000035000000200000000D0000
          0003000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000005000000160000002E1610085A9568
          31DFBF8D4EFFD8B687FFF2E0C1FFFFF8E3FFFFFFEFFFFFFFEEFFFFFFEEFFFFFF
          EFFFFFF8E4FFEDD7B5FFD3AD7DFFB98442FF956832DF1610085A0000002E0000
          0016000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000500000019000000386B4B24B4BE8B4EFFE7CF
          A9FFFFFFEEFFFFFCE7FFFFF8E2FFFFF6DFFFFFF5DEFFFFF5DDFFFFF5DDFFFFF5
          DEFFFFF6DFFFFFF8E4FFFFFDE8FFFFF8E4FFDDBF94FFB98543FF6B4B25B40000
          0038000000190000000500000000000000000000000000000000000000000000
          00000000000000000005000000190000003AA27034EDD2AC7BFFFFF7E1FFFFF8
          E4FFFFF5DEFFFFF3DBFFFEF3DAFFFEF2D9FFFEF2D9FFFEF2D9FFFEF2D9FFFEF2
          D9FFFEF2D9FFFEF3DAFFFFF4DBFFFFF5DFFFFFFAE6FFFCF0D8FFC89C65FFA371
          37ED0000003A0000001900000005000000000000000000000000000000000000
          0000000000030000001600000038A06F33EBE6CEA9FFFFFCE9FFFFF5DEFFFEF1
          D7FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0
          D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFEF1D8FFFFF6DFFFFFFEEBFFD3B0
          7FFFA17035EB0000003800000016000000030000000000000000000000000000
          00010000000D0000002EA27134ECE7CDA9FFFFFAE6FFFFF3D9FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDF0D4FFFFF3DBFFFFFC
          E9FFD5B080FFA37237EC0000002E0000000D0000000100000000000000000000
          00060000001F6A4B24B0D2AB79FFFFFBE8FFFEF2D8FFFCEED2FFFCEED2FFFCEE
          D2FFFCEFD3FFFDF0D4FFFDF0D4FFFDF0D4FFFCEFD3FFFCEED2FFFCEED2FFFCEF
          D3FFFDF0D4FFFDF0D4FFFDF0D4FFFCEFD3FFFCEED2FFFCEED2FFFCEFD2FFFEF2
          DAFFFFFDEBFFC4965CFF6A4B25B00000001F0000000600000000000000000000
          0010150F074CBE8C4EFFFFF4DFFFFFF2DAFFFCECD0FFFCECD0FFFCECD0FFFDEE
          D3FFFFF2D8FFFFF4DCFFFFF5DDFFFFF4DCFFFFF2D8FFFEEED3FFFEEED3FFFFF2
          D8FFFFF4DCFFFFF5DDFFFFF4DCFFFFF2D8FFFDEED3FFFCECD0FFFCECD0FFFCEC
          D0FFFFF3DBFFFDEFD8FFB67F3CFF150F074C0000001000000000000000030000
          001B946831DDE6CBA7FFFFF6E2FFFDECCEFFFCEBCEFFFCEBCEFFFDECD0FFFFF1
          D6FFCDA36FFFAE7531FFAF7633FFAE7631FFCDA36FFFFFF2D7FFFFF2D7FFCDA3
          6FFFAE7531FFAF7633FFAE7631FFCDA36FFFFFF1D6FFFDECD0FFFCEBCEFFFCEB
          CEFFFDECCFFFFFF7E4FFD7B488FF956932DD0000001B00000003000000090806
          0332BE8C4CFFFFFBEAFFFCEFD3FFFBEACBFFFBEACBFFFBEACBFFFCECCDFFFFF3
          D6FFAE7631FFF7C880FFF6C47BFFF8C57BFFAF7632FFFFF4D8FFFFF4D8FFAE76
          31FFF7C880FFF6C47BFFF8C57BFFAF7632FFFFF3D7FFFCECCDFFFBEACBFFFBEA
          CBFFFBEACBFFFDEFD5FFFCF1DDFFB67F3CFF0806033200000009000000114F37
          1B8DD6B386FFFFF6E4FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFCEACBFFFFF1
          D6FFAF7734FFF2C583FFEEBD73FFF1C075FFAF7735FFFFF3D8FFFFF3D8FFAF77
          34FFF2C583FFEEBD73FFF1C075FFAF7735FFFFF1D6FFFCEACBFFFBE8C9FFFBE8
          C9FFFBE8C9FFFCE9C9FFFFF7E6FFC99E6AFF4F381C8D00000011000000159367
          31DAF0DABCFFFEF1D8FFFAE7C6FFFAE7C7FFFAE7C7FFFAE7C7FFFBE9C9FFFFF0
          D4FFAF7734FFEFC487FFE9B76DFFECB96FFFB07836FFFFF2D6FFFFF2D6FFAF77
          34FFEFC487FFE9B76DFFECB96FFFB07836FFFFF0D4FFFBE9C9FFFAE7C7FFFAE7
          C7FFFAE7C7FFFAE7C7FFFFF2DBFFE2C49FFF946732DA0000001500000016B57D
          39FFFFF3E1FFFDECD0FFFAE5C4FFFAE5C5FFFAE5C5FFFAE5C5FFFBE7C7FFFFEE
          D1FFB07734FFECC68BFFE4B166FFE6B469FFB07936FFFFF0D4FFFFEFD3FFB077
          34FFECC68BFFE4B166FFE6B469FFB07936FFFFEED2FFFBE7C7FFFAE5C5FFFAE5
          C5FFFAE5C5FFFAE5C4FFFEEDD2FFF5E6CEFFB67E3BFF0000001600000016B47C
          38FFFFFAECFFFBE7C9FFF9E4C2FFF9E4C3FFF9E4C3FFF9E4C3FFFAE6C5FFFFED
          CFFFB07734FFEAC68FFFDFAD61FFE2AF63FFB17937FFFFEFD2FFFFEED1FFB077
          34FFEAC68FFFDFAD61FFE2AF63FFB17937FFFFEDD0FFFAE6C5FFF9E4C3FFF9E4
          C3FFF9E4C3FFF9E4C2FFFCE8CAFFF9ECD9FFB57D39FF0000001600000016B47C
          38FFFFFAEDFFFAE6C5FFF9E3C0FFF9E3C1FFF9E3C1FFF9E3C1FFFAE5C3FFFFEC
          CDFFB07834FFEAC795FFDBA75AFFDDAA5DFFB17A38FFFFEECFFFFFEDCFFFB078
          34FFEAC795FFDBA75AFFDDAA5DFFB17A38FFFFECCEFFFAE5C3FFF9E3C1FFF9E3
          C1FFF9E3C1FFF9E3C0FFFBE6C9FFFFFBEEFFB57D38FF0000001600000016B47C
          38FFFFFBEDFFFAE6C6FFF8E0BDFFF8E1BEFFF8E1BEFFF8E1BEFFF9E3C0FFFEE9
          C9FFB07834FFE9CA9CFFD7A153FFD9A457FFB27A39FFFFEBCCFFFFEBCBFFB078
          34FFE9CA9CFFD7A153FFD9A457FFB27A39FFFEEACAFFF9E3C0FFF8E1BEFFF8E1
          BEFFF8E1BEFFF8E0BDFFFAE7C6FFFFFCEEFFB57D38FF0000001600000015B47D
          38FFFFFCEFFFFAE5C5FFF8DFBBFFF8E0BCFFF8E0BCFFF8E0BCFFF9E2BEFFFEE8
          C7FFB07834FFE9CCA2FFD29D4EFFD4A051FFB27B39FFFFEACAFFFFEAC9FFB078
          34FFE9CCA2FFD29D4EFFD4A051FFB27B39FFFEE9C8FFF9E2BEFFF8E0BCFFF8E0
          BCFFF8E0BCFFF8E0BBFFFBE6C6FFFBF0E1FFB57D39FF0000001500000011B57E
          39FFFEF5E6FFFBE7CAFFF7DEB8FFF7DFBAFFF7DFBAFFF7DFBAFFF8E1BCFFFDE7
          C5FFB17833FFE8CEA9FFCE9748FFD09A4CFFB37C3AFFFEE9C8FFFDE9C7FFB178
          33FFE8CEA9FFCE9748FFD09A4CFFB37C3AFFFDE8C6FFF8E1BCFFF7DFBAFFF7DF
          BAFFF7DFBAFFF7DFB8FFFBE8CBFFF6EAD8FFB67E3AFF00000011000000099366
          31D6EAD4B7FFFDEED8FFF7DCB6FFF7DDB8FFF7DDB8FFF7DDB8FFF8DFBAFFFDE5
          C2FFB17833FFEAD2B1FFC89040FFCA9345FFB37C3AFFFEE7C6FFFDE6C4FFB178
          33FFEAD2B1FFC89040FFCA9345FFB37C3AFFFDE6C4FFF8DFBAFFF7DDB8FFF7DD
          B8FFF7DDB8FFF7DCB6FFFDEFD9FFE4CBABFF936732D600000009000000034F37
          1B7CD4B285FFFFF8EBFFF6DBB3FFF6DBB5FFF6DCB6FFF6DCB6FFF7DEB8FFFCE4
          C0FFB17732FFEAD6B9FFC28834FFC38C39FFB37B39FFFDE6C3FFFCE5C2FFB177
          32FFEAD6B9FFC28834FFC38C39FFB37B39FFFCE4C1FFF7DEB8FFF6DCB6FFF6DC
          B6FFF6DBB5FFF6DBB3FFFFF9ECFFCFAA7AFF4F371B7C00000003000000000806
          031AB98543FFFFFBF2FFFAE5C6FFF6DAB2FFF6DBB4FFF6DBB4FFF7DDB6FFFBE2
          BDFFB07732FFECDBC1FFEDDBC2FFEEDDC5FFB17834FFFCE4BFFFFCE3BFFFB077
          32FFECDBC1FFEDDBC2FFEEDDC5FFB17834FFFBE2BDFFF7DDB6FFF6DBB4FFF6DB
          B4FFF6DAB2FFFAE5C7FFFEF6EBFFB78140FF0806031A00000000000000000000
          0006956831D6E3C8A9FFFFF6EAFFF6DAB1FFF6D8AFFFF6D9B1FFF7DAB2FFF9DE
          B7FFCC9E65FFB07732FFB17833FFB07732FFCC9F66FFFADFB8FFFADEB8FFCC9E
          65FFB07732FFB17833FFB07732FFCC9F66FFF9DEB7FFF7DAB2FFF6D9B1FFF6D8
          AFFFF6DAB1FFFFF7EAFFDEC29FFF956832D60000000600000000000000000000
          0001150F0829B98543FFFDF5EAFFFCEDD7FFF5D6ABFFF5D7AEFFF5D8AFFFF6DA
          B1FFF8DDB5FFFADFB8FFFADFB8FFFADFB8FFF8DDB5FFF7DAB2FFF7DAB2FFF8DD
          B5FFFADFB8FFFADFB8FFFADFB8FFF8DDB5FFF6DAB1FFF5D8AFFFF5D7AEFFF5D6
          ABFFFCEDD8FFFAF1E5FFB88240FF150F08290000000100000000000000000000
          0000000000036A4A239CCBA270FFFFFFF9FFF9E3C4FFF5D5A9FFF5D7ABFFF5D7
          ADFFF6D8AEFFF6D8AFFFF6D9AFFFF6D8AFFFF6D8AEFFF5D7ADFFF5D7ADFFF6D8
          AEFFF6D8AFFFF6D9AFFFF6D8AFFFF6D8AEFFF5D7ADFFF5D7ABFFF5D5A9FFF9E3
          C4FFFFFEF7FFC99F6BFF6A4B249C000000030000000000000000000000000000
          00000000000000000005A37235E7DEC2A0FFFFFFFAFFF9E2C4FFF4D3A6FFF4D4
          A9FFF4D5AAFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5
          ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5AAFFF4D4A9FFF4D3A6FFF9E2C4FFFFFE
          F8FFD9BC99FFA37235E700000005000000000000000000000000000000000000
          0000000000000000000000000005A17032E5DEC3A1FFFFFFFEFFFCEDD9FFF4D4
          A8FFF4D2A5FFF4D3A7FFF4D4A8FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4
          A9FFF4D4A9FFF4D4A8FFF4D3A7FFF4D2A5FFF4D4A8FFFCEDD9FFFFFFFDFFDABF
          9BFFA27033E50000000500000000000000000000000000000000000000000000
          000000000000000000000000000000000005A37234E6CBA271FFFEFAF4FFFFFA
          F3FFF7E2C3FFF3D0A1FFF3D1A2FFF3D1A3FFF3D1A4FFF3D1A4FFF3D1A4FFF3D1
          A4FFF3D1A3FFF3D1A2FFF3D0A1FFF8E2C3FFFFFBF3FFFDF8F1FFCAA16FFFA372
          35E6000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000036B4B2499B88341FFE3CE
          B1FFFFFFFFFFFFFFFCFFFCEEDCFFF9E1C2FFF7DBB5FFF7DBB5FFF7DBB5FFF7DB
          B5FFF9E1C2FFFCEEDCFFFFFFFCFFFFFFFFFFE3CCB0FFB88341FF6B4B24990000
          0003000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001161008239467
          31D3B98342FFD5B68EFFEAD8C2FFFEFCF9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFEFCF9FFEAD8C2FFD5B58DFFB98342FF946731D316100823000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000806030E4F371B72936630D1B57D38FFB57C37FFB47C36FFB47C36FFB57C
          37FFB57D38FF936630D14F371B720806030E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000030000000900000011000000150000001600000016000000160000
          0016000000150000001100000009000000030000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001000000060000
          00100000001B0000002900000038000000410000004300000043000000430000
          00430000004100000038000000290000001B0000001000000006000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000030000000D000000200000
          00350806034C4F371B99936630DEB57D39FFB47C37FFB47C37FFB47C37FFB47C
          37FFB57D39FF936731DE4F381B990806034C00000035000000200000000D0000
          0003000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000005000000160000002E1610085A9568
          31DFBF8D4EFFD8B687FFF2E0C1FFFFF8E3FFFFFFEFFFFFFFEEFFFFFFEEFFFFFF
          EFFFFFF8E4FFEDD7B5FFD3AD7DFFB98442FF956832DF1610085A0000002E0000
          0016000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000500000019000000386B4B24B4BE8B4EFFE7CF
          A9FFFFFFEEFFFFFCE7FFFFF8E2FFFFF6DFFFFFF5DEFFFFF5DDFFFFF5DDFFFFF5
          DEFFFFF6DFFFFFF8E4FFFFFDE8FFFFF8E4FFDDBF94FFB98543FF6B4B25B40000
          0038000000190000000500000000000000000000000000000000000000000000
          00000000000000000005000000190000003AA27034EDD2AC7BFFFFF7E1FFFFF8
          E4FFFFF5DEFFFFF3DBFFFEF3DAFFFEF2D9FFFEF2D9FFFEF2D9FFFEF2D9FFFEF2
          D9FFFEF2D9FFFEF3DAFFFFF4DBFFFFF5DFFFFFFAE6FFFCF0D8FFC89C65FFA371
          37ED0000003A0000001900000005000000000000000000000000000000000000
          0000000000030000001600000038A06F33EBE6CEA9FFFFFCE9FFFFF5DEFFFEF1
          D7FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0
          D6FFFDF0D6FFFDF0D6FFFDF0D6FFFDF0D6FFFEF1D8FFFFF6DFFFFFFEEBFFD3B0
          7FFFA17035EB0000003800000016000000030000000000000000000000000000
          00010000000D0000002EA27134ECE7CDA9FFFFFAE6FFFFF3D9FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEF
          D4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDEFD4FFFDF0D4FFFFF3DBFFFFFC
          E9FFD5B080FFA37237EC0000002E0000000D0000000100000000000000000000
          00060000001F6A4B24B0D2AB79FFFFFBE8FFFEF2D8FFFCEED2FFFCEED2FFFCEE
          D2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEE
          D2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEED2FFFCEFD2FFFEF2
          DAFFFFFDEBFFC4965CFF6A4B25B00000001F0000000600000000000000000000
          0010150F074CBE8C4EFFFFF4DFFFFFF2DAFFFCECD0FFFCECD0FFFCECD0FFFCEC
          D0FFFDEDD1FFFDEDD2FFFDEED2FFFDEED2FFFDEED2FFFDEED2FFFDEED2FFFDEE
          D2FFFDEED2FFFDEED2FFFDEDD2FFFDEDD1FFFCECD0FFFCECD0FFFCECD0FFFCEC
          D0FFFFF3DBFFFDEFD8FFB67F3CFF150F074C0000001000000000000000030000
          001B946831DDE6CBA7FFFFF6E2FFFDECCEFFFCEBCEFFFCEBCEFFFCEBCEFFFEED
          D1FFFFF1D6FFFFF3DAFFFFF4DBFFFFF4DBFFFFF4DBFFFFF4DBFFFFF4DBFFFFF4
          DBFFFFF4DBFFFFF4DBFFFFF3DAFFFFF1D6FFFEEDD1FFFCEBCEFFFCEBCEFFFCEB
          CEFFFDECCFFFFFF7E4FFD7B488FF956932DD0000001B00000003000000090806
          0332BE8C4CFFFFFBEAFFFCEFD3FFFBEACBFFFBEACBFFFBEACBFFFBEBCCFFFEF0
          D3FFCDA46EFFAE7631FFAF7734FFAF7734FFAF7734FFAF7734FFAF7734FFAF77
          34FFAF7734FFAF7734FFAE7631FFCDA46EFFFEF0D3FFFBEBCCFFFBEACBFFFBEA
          CBFFFBEACBFFFDEFD5FFFCF1DDFFB67F3CFF0806033200000009000000114F37
          1B8DD6B386FFFFF6E4FFFBE8C9FFFBE8C9FFFBE8C9FFFBE8C9FFFCE9CBFFFFF0
          D4FFAF7632FFF8C881FFF4C479FFF4C479FFF4C479FFF4C479FFF4C479FFF4C4
          79FFF4C479FFF4C479FFF8C881FFAF7632FFFFF0D4FFFCE9CBFFFBE8C9FFFBE8
          C9FFFBE8C9FFFCE9C9FFFFF7E6FFC99E6AFF4F381C8D00000011000000159367
          31DAF0DABCFFFEF1D8FFFAE7C6FFFAE7C7FFFAE7C7FFFAE7C7FFFBE9C9FFFFF0
          D4FFAF7734FFF1C685FFECBA70FFEBBA71FFEBBA71FFEBBA71FFEBBA71FFEBBA
          71FFEBBA71FFECBA70FFF1C685FFAF7734FFFFF0D4FFFBE9C9FFFAE7C7FFFAE7
          C7FFFAE7C7FFFAE7C7FFFFF2DBFFE2C49FFF946732DA0000001500000016B57D
          39FFFFF3E1FFFDECD0FFFAE5C4FFFAE5C5FFFAE5C5FFFAE5C5FFFBE7C7FFFFEE
          D1FFB07734FFEFC688FFE5B468FFE5B46AFFE5B46AFFE5B46AFFE5B46AFFE5B4
          6AFFE5B46AFFE5B468FFEFC688FFB07734FFFFEED1FFFBE7C7FFFAE5C5FFFAE5
          C5FFFAE5C5FFFAE5C4FFFEEDD2FFF5E6CEFFB67E3BFF0000001600000016B47C
          38FFFFFAECFFFBE7C9FFF9E4C2FFF9E4C3FFF9E4C3FFF9E4C3FFFAE6C5FFFFED
          CFFFB07734FFEBC68FFFE0AD61FFE0AE63FFE0AE64FFE0AE64FFE0AE64FFE0AE
          64FFE0AE63FFE0AD61FFEBC68FFFB07734FFFFEDCFFFFAE6C5FFF9E4C3FFF9E4
          C3FFF9E4C3FFF9E4C2FFFCE8CAFFF9ECD9FFB57D39FF0000001600000016B47C
          38FFFFFAEDFFFAE6C5FFF9E3C0FFF9E3C1FFF9E3C1FFF9E3C1FFFAE5C3FFFFEC
          CDFFB07734FFEAC895FFDBA65AFFDBA85DFFDBA85EFFDBA85EFFDBA85EFFDBA8
          5EFFDBA85DFFDBA65AFFEAC895FFB07734FFFFECCDFFFAE5C3FFF9E3C1FFF9E3
          C1FFF9E3C1FFF9E3C0FFFBE6C9FFFFFBEEFFB57D38FF0000001600000016B47C
          38FFFFFBEDFFFAE6C6FFF8E0BDFFF8E1BEFFF8E1BEFFF8E1BEFFF9E3C0FFFEE9
          C9FFB07834FFE9CB9EFFD5A153FFD6A357FFD6A358FFD6A358FFD6A358FFD6A3
          58FFD6A357FFD5A153FFE9CB9EFFB07834FFFEE9C9FFF9E3C0FFF8E1BEFFF8E1
          BEFFF8E1BEFFF8E0BDFFFAE7C6FFFFFCEEFFB57D38FF0000001600000015B47D
          38FFFFFCEFFFFAE5C5FFF8DFBBFFF8E0BCFFF8E0BCFFF8E0BCFFF9E2BEFFFEE8
          C7FFB17833FFE9CEA6FFCF9A4CFFD19C51FFD19D52FFD19D52FFD19D52FFD19D
          52FFD19C51FFCF9A4CFFE9CEA6FFB17833FFFEE8C7FFF9E2BEFFF8E0BCFFF8E0
          BCFFF8E0BCFFF8E0BBFFFBE6C6FFFBF0E1FFB57D39FF0000001500000011B57E
          39FFFEF5E6FFFBE7CAFFF7DEB8FFF7DFBAFFF7DFBAFFF7DFBAFFF8E1BCFFFDE7
          C5FFB17833FFEAD2AFFFCA9343FFCB9649FFCB974AFFCB974AFFCB974AFFCB97
          4AFFCB9649FFCA9343FFEAD2AFFFB17833FFFDE7C5FFF8E1BCFFF7DFBAFFF7DF
          BAFFF7DFBAFFF7DFB8FFFBE8CBFFF6EAD8FFB67E3AFF00000011000000099366
          31D6EAD4B7FFFDEED8FFF7DCB6FFF7DDB8FFF7DDB8FFF7DDB8FFF8DFBAFFFDE5
          C2FFB17732FFEBD7B9FFC28936FFC48C3BFFC48C3CFFC48C3CFFC48C3CFFC48C
          3CFFC48C3BFFC28936FFEBD7B9FFB17732FFFDE5C2FFF8DFBAFFF7DDB8FFF7DD
          B8FFF7DDB8FFF7DCB6FFFDEFD9FFE4CBABFF936732D600000009000000034F37
          1B7CD4B285FFFFF8EBFFF6DBB3FFF6DBB5FFF6DCB6FFF6DCB6FFF7DDB8FFFBE3
          BFFFB07731FFECDBC1FFECDBC1FFECDCC3FFEDDCC3FFEDDCC3FFEDDCC3FFEDDC
          C3FFECDCC3FFECDBC1FFECDBC1FFB07731FFFBE3BFFFF7DDB8FFF6DCB6FFF6DC
          B6FFF6DBB5FFF6DBB3FFFFF9ECFFCFAA7AFF4F371B7C00000003000000000806
          031AB98543FFFFFBF2FFFAE5C6FFF6DAB2FFF6DBB4FFF6DBB4FFF7DCB5FFF9E0
          BAFFCC9E66FFB07732FFB17832FFB17832FFB17832FFB17832FFB17832FFB178
          32FFB17832FFB17832FFB07732FFCC9E66FFF9E0BAFFF7DCB5FFF6DBB4FFF6DB
          B4FFF6DAB2FFFAE5C7FFFEF6EBFFB78140FF0806031A00000000000000000000
          0006956831D6E3C8A9FFFFF6EAFFF6DAB1FFF6D8AFFFF6D9B1FFF6D9B1FFF7DB
          B3FFF9DEB7FFFBE0BAFFFCE1BAFFFCE1BBFFFCE1BBFFFCE1BBFFFCE1BBFFFCE1
          BBFFFCE1BBFFFCE1BAFFFBE0BAFFF9DEB7FFF7DBB3FFF6D9B1FFF6D9B1FFF6D8
          AFFFF6DAB1FFFFF7EAFFDEC29FFF956832D60000000600000000000000000000
          0001150F0829B98543FFFDF5EAFFFCEDD7FFF5D6ABFFF5D7AEFFF5D8AFFFF5D8
          AFFFF5D9B0FFF6D9B1FFF6DAB1FFF6DAB1FFF6DAB1FFF6DAB1FFF6DAB1FFF6DA
          B1FFF6DAB1FFF6DAB1FFF6D9B1FFF5D9B0FFF5D8AFFFF5D8AFFFF5D7AEFFF5D6
          ABFFFCEDD8FFFAF1E5FFB88240FF150F08290000000100000000000000000000
          0000000000036A4A239CCBA270FFFFFFF9FFF9E3C4FFF5D5A9FFF5D7ABFFF5D7
          ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7
          ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ADFFF5D7ABFFF5D5A9FFF9E3
          C4FFFFFEF7FFC99F6BFF6A4B249C000000030000000000000000000000000000
          00000000000000000005A37235E7DEC2A0FFFFFFFAFFF9E2C4FFF4D3A6FFF4D4
          A9FFF4D5AAFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5
          ABFFF4D5ABFFF4D5ABFFF4D5ABFFF4D5AAFFF4D4A9FFF4D3A6FFF9E2C4FFFFFE
          F8FFD9BC99FFA37235E700000005000000000000000000000000000000000000
          0000000000000000000000000005A17032E5DEC3A1FFFFFFFEFFFCEDD9FFF4D4
          A8FFF4D2A5FFF4D3A7FFF4D4A8FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4A9FFF4D4
          A9FFF4D4A9FFF4D4A8FFF4D3A7FFF4D2A5FFF4D4A8FFFCEDD9FFFFFFFDFFDABF
          9BFFA27033E50000000500000000000000000000000000000000000000000000
          000000000000000000000000000000000005A37234E6CBA271FFFEFAF4FFFFFA
          F3FFF7E2C3FFF3D0A1FFF3D1A2FFF3D1A3FFF3D1A4FFF3D1A4FFF3D1A4FFF3D1
          A4FFF3D1A3FFF3D1A2FFF3D0A1FFF8E2C3FFFFFBF3FFFDF8F1FFCAA16FFFA372
          35E6000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000036B4B2499B88341FFE3CE
          B1FFFFFFFFFFFFFFFCFFFCEEDCFFF9E1C2FFF7DBB5FFF7DBB5FFF7DBB5FFF7DB
          B5FFF9E1C2FFFCEEDCFFFFFFFCFFFFFFFFFFE3CCB0FFB88341FF6B4B24990000
          0003000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001161008239467
          31D3B98342FFD5B68EFFEAD8C2FFFEFCF9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFEFCF9FFEAD8C2FFD5B58DFFB98342FF946731D316100823000000010000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000806030E4F371B72936630D1B57D38FFB57C37FFB47C36FFB47C36FFB57C
          37FFB57D38FF936630D14F371B720806030E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000001000000060000000F0000001500000016000000160000
          00150000000F0000000600000001000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000030000000E00000020000000340000004000000043000000430000
          004000000034000000200000000E000000030000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0003000000120000002D001C0F69006637D1008A49FF008949FF008949FF008A
          49FF006637D1001C0F690000002D000000120000000300000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000010000
          000E0000002D00522CB4009152FF00B679FF00CD90FF00D194FF00D194FF00CD
          90FF00B679FF009152FF00522CB40000002D0000000E00000001000000000000
          0000000000000000000000000000000000060000001100000012000000090000
          0001000000000000000000000000000000000000000000000000000000060000
          002000522CB1009656FF00CB8FFF00CD8FFF00C98AFF00C685FF00C685FF00C9
          8AFF00CD8FFF00CB8FFF009656FF00522CB10000002000000006000000000000
          00000000000000000000000000000000000E0000002D00000039000000250000
          000E0000000300000000000000000000000000000000000000000000000F001C
          0F5D009251FF00C98DFF00CA8CFF00C788FF00C380FFFFFFFFFFFFFFFFFF00C3
          80FF00C788FF00CA8CFF00C98DFF009251FF001C0F5D0000000F000000000000
          00000000000000000000000000000000000DB5834AFFB38147FF3224147A0000
          002C000000120000000300000000000000000000000000000000000000150067
          37CD00B374FF00C88AFF00C586FF00C383FF00BE79FFFFFFFFFFFFFFFFFF00BE
          79FF00C383FF00C586FF00C88AFF00B374FF006737CD00000015000000000000
          000000000000000000000000000000000006715737A4FFFAE7FFD4B48BFF5B41
          23A50000002E000000100000000200000000000000000000000000000016008A
          4AFF00C587FF00C383FF00BE7CFF00BC77FF00B86FFFFFFFFFFFFFFFFFFF00B8
          6FFF00BC77FF00BE7CFF00C383FF00C587FF008A4AFF00000016000000000000
          00000000000000000000000000000000000123190E45D3B288FFFFFFFFFFD1B0
          86FF694A28B3000000270000000A000000000000000000000000000000160089
          49FF1BCD96FF00BD7AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF00BD7AFF1BCD96FF008949FF00000016000000000000
          00000000000000000000000000000000000000000016BD8E57FFFFFFFAFFFFFF
          F9FFCDA779FF3F2D198300000025000000170000001600000016000000270089
          47FF38D3A2FF00BB77FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF00BB77FF39D3A2FF008948FF00000015000000000000
          00000000000000000000000000030000000C00000025B47C3FFFFFFFF7FFFFFF
          F0FFFFFEEDFFC49866FF0F0B0658000000430000004300000043000000480088
          45FF6ADBB8FF00BB78FF00B974FF00B771FF00B268FFFFFFFFFFFFFFFFFF00B2
          68FF00B771FF00B974FF00BB78FF6EDCB9FF008947FF0000000F000000000000
          00000000000000000005000000160000002E00000044C89E6EFFFFFFF4FFFFFC
          EBFFFFFFEFFFF6ECD5FFB88248FFB57E42FFB67F43FFB97F43FFC57F44FF2882
          3FFF58C49CFF28C894FF00BA78FF00B978FF00B46EFFFFFFFFFFFFFFFFFF00B4
          6EFF00B978FF00BA78FF2AC895FF63C7A0FF006636C400000006000000000000
          00000000000500000019000000386C4E2CB4BB864DFFE6D0B1FFFFFFEFFFFFFB
          E9FFFFFBEAFFFFFFEEFFFFFFF4FFFFFFF7FFFFFFF8FFFFFFF8FFFFFFFAFFCBE7
          CDFF008B49FF87E0C2FF1CC38AFF00B774FF00B36DFFFFFFFFFFFFFFFFFF00B3
          6DFF00B774FF1DC48BFF8DE2C6FF0C9457FF001C0F3E00000001000000000000
          00030000001600000038A67642EDD0A97DFFFFFEEFFFFFFFF0FFFFFCEBFFFFFA
          E9FFFFFAE9FFFFFBE9FFFFFCEAFFFFFCEBFFFFFCEBFFFFFCEBFFFFFDEDFFFFFF
          F4FF4FAF7DFF009152FF91E1C5FF5BD4AAFF0ABC7EFF00B068FF00B068FF0BBC
          7FFF5CD4ACFF96E4C9FF149A5EFF00512B9C0000000300000000000000000000
          000D0000002EA77644ECD6B288FFFFFFF5FFFFFEECFFFFFBE7FFFFF9E5FFFFF9
          E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E6FFFFFC
          E9FFFFFFF2FF64B787FF008947FF52BF94FF8EDFC3FF9AE5CCFF9AE5CCFF8FE0
          C4FF56C299FF009355FF004F2A9C000000030000000000000000000000040000
          001B6E4F2EB0D3AB7CFFFFFFF3FFFFFAE7FFFFF8E3FFFFF7E2FFFFF7E2FFFFF7
          E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF8
          E3FFFFFAE6FFFFFEECFFC7E0C1FF3CA56EFF007C34FF007D36FF007D36FF007E
          36FF339356FF585B33C20000001C0000000300000000000000000000000C0806
          0437C18C54FFFFFAE9FFFFF9E7FFFFF6E0FFFFF5DFFFFFF5DFFFFFF5DFFFFFF5
          DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5
          DFFFFFF5E0FFFFF7E1FFFFF9E5FFFFFCE9FFFFFEECFFFFFFEDFFFFFFEDFFFFFF
          F1FFFFFDEDFFCF8C55FF070403340000000C0000000000000000000000127151
          30AEDEBB93FFFFFCE9FFFFF4DCFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3
          DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3
          DBFFFFF3DBFFFFF3DBFFFFF3DCFFFFF4DDFFFFF5DDFFFFF5DDFFFFF5DDFFFFF6
          DEFFFFFCEAFFE0BB93FF725130AE00000012000000000000000000000016A979
          45E9F9E8D1FFFFF6E0FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF6E0FFF9E8D1FFA97945E900000016000000000000000000000016C087
          4EFFFFFFEDFFFFF2DAFFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFF2DAFFFFFFEDFFC0874EFF00000016000000000000000000000016C188
          4FFFFFFBEBFFFFF0D5FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFF0D5FFFFFBEBFFC1884FFF00000016000000000000000000000016C289
          4FFFFFFAE9FFFFECCEFFFFEBCCFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CCFFFFECCEFFFFFAE9FFC2894FFF00000016000000000000000000000016C38B
          50FFFFFAE8FFFFECCFFFFFE9C9FFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          C9FFFFECCFFFFFFAE8FFC38B50FF00000016000000000000000000000012C58C
          52FFFFFAEAFFFFECCFFFFFE7C6FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C6FFFFECCFFFFFFAEAFFC58C52FF0000001200000000000000000000000CAE7E
          4BE6F9E5CEFFFFEED5FFFFE5C2FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C2FFFFEED5FFF9E5CEFFAE7E4BE60000000C0000000000000000000000047555
          34A0E3BC94FFFFF5E3FFFFE4BFFFFFE4BFFFFFE4C0FFFFE4C0FFFFE4C0FFFFE4
          C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4
          C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4BFFFFFE4
          BFFFFFF5E3FFE3BC94FF755534A1000000040000000000000000000000000906
          0417CD955FFFFFF4E2FFFFECD2FFFFE1BAFFFFE2BBFFFFE2BCFFFFE2BCFFFFE2
          BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2
          BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BBFFFFE1BAFFFFEC
          D2FFFFF4E2FFCD955FFF09060417000000000000000000000000000000000000
          00037655369DDCB084FFFFF9EAFFFFE7C8FFFFDFB6FFFFE0B8FFFFE0B9FFFFE0
          B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0
          B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B8FFFFDFB6FFFFE7C8FFFFF9
          EAFFDCB084FF7856369E00000003000000000000000000000000000000000000
          000000000005B88352E7E1B78DFFFFF9EAFFFFEBD0FFFFDEB5FFFFDDB2FFFFDD
          B3FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDE
          B4FFFFDEB4FFFFDEB4FFFFDDB3FFFFDDB2FFFFDEB5FFFFEBD0FFFFF9EAFFE1B7
          8DFFB98452E80000000500000000000000000000000000000000000000000000
          00000000000000000005B88552E6DEB285FFFFF4E5FFFFF4E3FFFFE8CBFFFFE2
          BDFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDB
          AFFFFFDBAFFFFFDBAFFFFFE2BDFFFFE8CBFFFFF4E3FFFFF4E5FFDEB285FFB985
          52E7000000050000000000000000000000000000000000000000000000000000
          000000000000000000000000000379583799D19962FFE6C09AFFFAE8D3FFFFFB
          EFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFB
          EFFFFFFBEFFFFFFBEFFFFFFBEFFFFAE8D3FFE6C09AFFD19962FF7958389A0000
          0003000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000907040F7A58389AB68351E3D094
          5BFFCF945AFFCF945AFFCF945AFFCF945AFFCF945AFFCF945AFFCF945AFFCF94
          5AFFCF945AFFCF945AFFD0945BFFB68351E37A58389A0907040F000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          2000000000000010000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000600000011000000120000
          0009000000010000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000E0000002D000000390000
          00250000000E0000000300000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000DB5834AFFB38147FF3224
          147A0000002C0000001200000003000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000006715737A4FFFAE7FFD4B4
          8BFF5B4123A50000002E00000010000000020000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000123190E45D3B288FFFFFF
          FFFFD1B086FF694A28B3000000270000000A0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000016BD8E57FFFFFF
          FAFFFFFFF9FFCDA779FF3F2D1983000000250000001700000016000000160000
          001600000016000000160000001600000016000000120000000C000000040000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000030000000C00000025B47C3FFFFFFF
          F7FFFFFFF0FFFFFEEDFFC49866FF0F0B06580000004300000043000000430000
          0043000000430000004300000043000000420000003C0000002E0000001C0000
          000D000000030000000000000000000000000000000000000000000000000000
          0000000000000000000000000005000000160000002E00000044C89E6EFFFFFF
          F4FFFFFCEBFFFFFFEFFFF6ECD5FFB88248FFB57E42FFB67F43FFB67F43FFB67F
          43FFB67F43FFB67F43FFB67F43FFB78044FFA2723FEB6C4E2CB60806034A0000
          002E000000160000000500000000000000000000000000000000000000000000
          0000000000000000000500000019000000386C4E2CB4BB864DFFE6D0B1FFFFFF
          EFFFFFFBE9FFFFFBEAFFFFFFEEFFFFFFF4FFFFFFF7FFFFFFF8FFFFFFF8FFFFFF
          F8FFFFFFF8FFFFFFF8FFFFFFF8FFFFFFF9FFF8EDD7FFD9BB93FFBC8850FF6D4E
          2DB5000000380000001900000005000000000000000000000000000000000000
          0000000000030000001600000038A67642EDD0A97DFFFFFEEFFFFFFFF0FFFFFC
          EBFFFFFAE9FFFFFAE9FFFFFBE9FFFFFCEAFFFFFCEBFFFFFCEBFFFFFCEBFFFFFC
          EBFFFFFCEBFFFFFCEBFFFFFCEBFFFFFDECFFFFFFEEFFFFFFF3FFFFFFEFFFD0A9
          7DFFA67642ED0000003800000016000000030000000000000000000000000000
          00000000000D0000002EA77644ECD6B288FFFFFFF5FFFFFEECFFFFFBE7FFFFF9
          E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9
          E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFF9E5FFFFFAE6FFFFFBE7FFFFFEECFFFFFF
          F5FFD6B288FFA77744ED0000002E0000000D0000000000000000000000000000
          00040000001B6E4F2EB0D3AB7CFFFFFFF3FFFFFAE7FFFFF8E3FFFFF7E2FFFFF7
          E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7
          E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF7E2FFFFF8E3FFFFFA
          E7FFFFFFF3FFD3AB7CFF6F4F2EB00000001C0000000400000000000000000000
          000C08060437C18C54FFFFFAE9FFFFF9E7FFFFF6E0FFFFF5DFFFFFF5DFFFFFF5
          DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5
          DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF5DFFFFFF6
          E0FFFFF9E7FFFFFAE9FFC18C54FF080604370000000C00000000000000000000
          0012715130AEDEBB93FFFFFCE9FFFFF4DCFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3
          DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3
          DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3DBFFFFF3
          DBFFFFF4DCFFFFFCE9FFDEBB93FF715130AE0000001200000000000000000000
          0016A97945E9F9E8D1FFFFF6E0FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1D8FFFFF1
          D8FFFFF1D8FFFFF6E0FFF9E8D1FFA97945E90000001600000000000000000000
          0016C0874EFFFFFFEDFFFFF2DAFFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEFD4FFFFEF
          D4FFFFEFD4FFFFF2DAFFFFFFEDFFC0874EFF0000001600000000000000000000
          0016C1884FFFFFFBEBFFFFF0D5FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFEDD1FFFFED
          D1FFFFEDD1FFFFF0D5FFFFFBEBFFC1884FFF0000001600000000000000000000
          0016C2894FFFFFFAE9FFFFECCEFFFFEBCCFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEBCDFFFFEB
          CDFFFFEBCCFFFFECCEFFFFFAE9FFC2894FFF0000001600000000000000000000
          0016C38B50FFFFFAE8FFFFECCFFFFFE9C9FFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9CAFFFFE9
          CAFFFFE9C9FFFFECCFFFFFFAE8FFC38B50FF0000001600000000000000000000
          0012C58C52FFFFFAEAFFFFECCFFFFFE7C6FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7C7FFFFE7
          C7FFFFE7C6FFFFECCFFFFFFAEAFFC58C52FF0000001200000000000000000000
          000CAE7E4BE6F9E5CEFFFFEED5FFFFE5C2FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5C3FFFFE5
          C3FFFFE5C2FFFFEED5FFF9E5CEFFAE7E4BE60000000C00000000000000000000
          0004755534A0E3BC94FFFFF5E3FFFFE4BFFFFFE4BFFFFFE4C0FFFFE4C0FFFFE4
          C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4
          C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4C0FFFFE4
          BFFFFFE4BFFFFFF5E3FFE3BC94FF755534A00000000400000000000000000000
          000009060417CD955FFFFFF4E2FFFFECD2FFFFE1BAFFFFE2BBFFFFE2BCFFFFE2
          BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2
          BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BCFFFFE2BBFFFFE1
          BAFFFFECD2FFFFF4E2FFCD955FFF090604170000000000000000000000000000
          0000000000037655369DDCB084FFFFF9EAFFFFE7C8FFFFDFB6FFFFE0B8FFFFE0
          B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0
          B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B9FFFFE0B8FFFFDFB6FFFFE7
          C8FFFFF9EAFFDCB084FF7655369D000000030000000000000000000000000000
          00000000000000000005B88352E7E1B78DFFFFF9EAFFFFEBD0FFFFDEB5FFFFDD
          B2FFFFDDB3FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDE
          B4FFFFDEB4FFFFDEB4FFFFDEB4FFFFDDB3FFFFDDB2FFFFDEB5FFFFEBD0FFFFF9
          EAFFE1B78DFFB88352E700000005000000000000000000000000000000000000
          0000000000000000000000000005B88552E6DEB285FFFFF4E5FFFFF4E3FFFFE8
          CBFFFFE2BDFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDBAFFFFFDB
          AFFFFFDBAFFFFFDBAFFFFFDBAFFFFFE2BDFFFFE8CBFFFFF4E3FFFFF4E5FFDEB2
          85FFB98552E70000000500000000000000000000000000000000000000000000
          00000000000000000000000000000000000379583799D19962FFE6C09AFFFAE8
          D3FFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFB
          EFFFFFFBEFFFFFFBEFFFFFFBEFFFFFFBEFFFFAE8D3FFE6C09AFFD19962FF7958
          389A000000030000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000907040F7A58389AB683
          51E3D0945BFFCF945AFFCF945AFFCF945AFFCF945AFFCF945AFFCF945AFFCF94
          5AFFCF945AFFCF945AFFCF945AFFD0945BFFB68351E37A58389A0907040F0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end>
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 544
  end
  object AdvPopupMenu1: TAdvPopupMenu
    AutoPopup = False
    MenuStyler = AdvMenuStyler1
    Version = '2.6.5.6'
    Left = 280
    Top = 400
    object Edit1: TMenuItem
      Caption = 'Edit'
      OnClick = Edit1Click
    end
    object Delete1: TMenuItem
      Caption = 'Delete'
      OnClick = Delete1Click
    end
  end
  object AdvMenuStyler1: TAdvMenuStyler
    AntiAlias = aaNone
    Background.Position = bpCenter
    SelectedItem.Font.Charset = DEFAULT_CHARSET
    SelectedItem.Font.Color = clWindowText
    SelectedItem.Font.Height = -12
    SelectedItem.Font.Name = 'Segoe UI'
    SelectedItem.Font.Style = []
    SelectedItem.NotesFont.Charset = DEFAULT_CHARSET
    SelectedItem.NotesFont.Color = clWindowText
    SelectedItem.NotesFont.Height = -9
    SelectedItem.NotesFont.Name = 'Segoe UI'
    SelectedItem.NotesFont.Style = []
    RootItem.Font.Charset = DEFAULT_CHARSET
    RootItem.Font.Color = clMenuText
    RootItem.Font.Height = -12
    RootItem.Font.Name = 'Segoe UI'
    RootItem.Font.Style = []
    Glyphs.SubMenu.Data = {
      5A000000424D5A000000000000003E0000002800000004000000070000000100
      0100000000001C0000000000000000000000020000000200000000000000FFFF
      FF0070000000300000001000000000000000100000003000000070000000}
    Glyphs.Check.Data = {
      7E000000424D7E000000000000003E0000002800000010000000100000000100
      010000000000400000000000000000000000020000000200000000000000FFFF
      FF00FFFF0000FFFF0000FFFF0000FFFF0000FDFF0000F8FF0000F07F0000F23F
      0000F71F0000FF8F0000FFCF0000FFEF0000FFFF0000FFFF0000FFFF0000FFFF
      0000}
    Glyphs.Radio.Data = {
      7E000000424D7E000000000000003E0000002800000010000000100000000100
      010000000000400000000000000000000000020000000200000000000000FFFF
      FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FC3F0000F81F0000F81F
      0000F81F0000F81F0000FC3F0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
      0000}
    SideBar.Font.Charset = DEFAULT_CHARSET
    SideBar.Font.Color = clWhite
    SideBar.Font.Height = -19
    SideBar.Font.Name = 'Tahoma'
    SideBar.Font.Style = [fsBold, fsItalic]
    SideBar.Image.Position = bpCenter
    SideBar.Background.Position = bpCenter
    SideBar.SplitterColorTo = clBlack
    Separator.GradientType = gtBoth
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMenuText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    NotesFont.Charset = DEFAULT_CHARSET
    NotesFont.Color = clGray
    NotesFont.Height = -9
    NotesFont.Name = 'Segoe UI'
    NotesFont.Style = []
    ButtonAppearance.CaptionFont.Charset = DEFAULT_CHARSET
    ButtonAppearance.CaptionFont.Color = clWindowText
    ButtonAppearance.CaptionFont.Height = -11
    ButtonAppearance.CaptionFont.Name = 'Segoe UI'
    ButtonAppearance.CaptionFont.Style = []
    Left = 336
    Top = 400
  end
end
