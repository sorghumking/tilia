object CheckListVarForm: TCheckListVarForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Check Variables'
  ClientHeight = 343
  ClientWidth = 514
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 514
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object Memo1: TMemo
      Left = 8
      Top = 8
      Width = 455
      Height = 28
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Lines.Strings = (
        
          'Duplicate variables found. Click '#171'Combine Duplicates'#187' to sum the' +
          'm together.'
        'Note: Some categorical variables cannot be summed.')
      ParentCtl3D = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 41
    Width = 514
    Height = 260
    Cursor = crDefault
    Align = alTop
    ColCount = 4
    DefaultRowHeight = 18
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    ScrollBars = ssVertical
    TabOrder = 0
    HoverRowCells = [hcNormal, hcSelected]
    OnCheckBoxClick = AdvColumnGrid1CheckBoxClick
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ColumnHeaders.Strings = (
      'Combine'
      'Variable'
      'Duplicate'
      'Permitted')
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
    MouseActions.DirectDateClose = True
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
    SortSettings.DefaultFormat = ssAutomatic
    Version = '3.1.4.2'
    WordWrap = False
    Columns = <
      item
        AutoMinSize = 0
        AutoMaxSize = 0
        Alignment = taCenter
        Borders = []
        BorderPen.Color = clSilver
        CheckFalse = 'N'
        CheckTrue = 'Y'
        Color = clWindow
        ColumnPopupType = cpFixedCellsRClick
        DropDownCount = 8
        EditLength = 0
        Editor = edNumeric
        FilterCaseSensitive = False
        Fixed = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Header = 'Combine'
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
        Width = 60
      end
      item
        AutoMinSize = 0
        AutoMaxSize = 0
        Alignment = taLeftJustify
        Borders = []
        BorderPen.Color = clSilver
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
        Header = 'Variable'
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
        ReadOnly = True
        ShowBands = False
        SortStyle = ssAutomatic
        SpinMax = 0
        SpinMin = 0
        SpinStep = 1
        Tag = 0
        Width = 226
      end
      item
        AutoMinSize = 0
        AutoMaxSize = 0
        Alignment = taLeftJustify
        Borders = []
        BorderPen.Color = clSilver
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
        Header = 'Duplicate'
        HeaderAlignment = taCenter
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = [fsBold]
        MinSize = 64
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
        Width = 156
      end
      item
        AutoMinSize = 0
        AutoMaxSize = 0
        Alignment = taCenter
        Borders = []
        BorderPen.Color = clSilver
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
        Header = 'Permitted'
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
        Width = 68
      end>
    ExplicitTop = 42
    ColWidths = (
      60
      226
      156
      68)
  end
  object Panel2: TPanel
    Left = 0
    Top = 301
    Width = 514
    Height = 42
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object FlowPanel1: TFlowPanel
      Left = 120
      Top = 8
      Width = 297
      Height = 24
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton7: TcxButton
        Left = 0
        Top = 0
        Width = 129
        Height = 24
        Caption = 'Combine Duplicates'
        LookAndFeel.Kind = lfOffice11
        TabOrder = 0
        OnClick = cxButton7Click
      end
      object cxButton1: TcxButton
        Left = 129
        Top = 0
        Width = 56
        Height = 24
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        TabOrder = 1
        OnClick = cxButton1Click
      end
      object cxButton8: TcxButton
        Left = 185
        Top = 0
        Width = 56
        Height = 24
        Caption = 'Ignore'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 5
        TabOrder = 2
        OnClick = cxButton8Click
      end
      object cxButton2: TcxButton
        Left = 241
        Top = 0
        Width = 56
        Height = 24
        Caption = 'Abort'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 3
        TabOrder = 3
      end
    end
    object FlowPanel2: TFlowPanel
      Left = 8
      Top = 8
      Width = 100
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 1
      object cxButton5: TcxButton
        Left = 0
        Top = 0
        Width = 25
        Height = 25
        Hint = 'Scroll spreadsheet page down'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF
          9808FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6
          CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF98
          08D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D87F5B00
          CF9808FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3
          D5FFF3D5CF9808D8D8D8D8D8D8CF98087F5B007F5B007F5B007F5B007F5B007F
          5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B00D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF
          9808FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6
          CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF98
          08D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D87F5B00
          CF9808FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3
          D5FFF3D5CF9808D8D8D8D8D8D8CF98087F5B007F5B007F5B007F5B007F5B007F
          5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B00D8D8D8}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = cxButton5Click
      end
      object cxButton3: TcxButton
        Left = 25
        Top = 0
        Width = 25
        Height = 25
        Hint = 'Scroll spreadsheet row down'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF
          9808FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6
          CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF98
          08D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D87F5B00
          CF9808FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3
          D5FFF3D5CF9808D8D8D8D8D8D8CF98087F5B007F5B007F5B007F5B007F5B007F
          5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B00D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = cxButton3Click
      end
      object cxButton4: TcxButton
        Left = 50
        Top = 0
        Width = 25
        Height = 25
        Hint = 'Scroll spreadsheet row up'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8CF9808
          7F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B
          007F5B007F5B00D8D8D8D8D8D87F5B00CF9808FFF3D5FFF3D5FFF3D5FFF3D5FF
          F3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5CF9808D8D8D8D8D8D8D8D8D8
          7F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3
          D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6
          CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808FFF3D5CF9808D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F
          5B00CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = cxButton4Click
      end
      object cxButton6: TcxButton
        Left = 75
        Top = 0
        Width = 25
        Height = 25
        Hint = 'Scroll spreadsheet page up'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000D8D8D8CF9808
          7F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B
          007F5B007F5B00D8D8D8D8D8D87F5B00CF9808FFF3D5FFF3D5FFF3D5FFF3D5FF
          F3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5CF9808D8D8D8D8D8D8D8D8D8
          7F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3
          D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6
          CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808FFF3D5CF9808D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F
          5B00CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8CF9808
          7F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B007F5B
          007F5B007F5B00D8D8D8D8D8D87F5B00CF9808FFF3D5FFF3D5FFF3D5FFF3D5FF
          F3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5FFF3D5CF9808D8D8D8D8D8D8D8D8D8
          7F5B00CF9808F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3
          D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D87F5B00CF9808F6CB97F6CB97F6CB97F6CB97FFF3D5CF9808D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808F6
          CB97F6CB97FFF3D5CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808FFF3D5CF9808D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F
          5B00CF9808D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = cxButton6Click
      end
    end
  end
end
