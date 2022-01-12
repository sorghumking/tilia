object CalibForm: TCalibForm
  Left = 0
  Top = 0
  Caption = 'Calibrate'
  ClientHeight = 362
  ClientWidth = 666
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  DesignSize = (
    666
    362)
  PixelsPerInch = 96
  TextHeight = 13
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 8
    Top = 35
    Width = 649
    Height = 264
    Cursor = crDefault
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 10
    Ctl3D = True
    DefaultRowHeight = 20
    DrawingStyle = gdsClassic
    RowCount = 100
    FixedRows = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goTabs]
    ParentCtl3D = False
    ScrollBars = ssBoth
    TabOrder = 1
    OnKeyUp = AdvColumnGrid1KeyUp
    HoverRowCells = [hcNormal, hcSelected]
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = 15387318
    ColumnHeaders.Strings = (
      ''
      'Lab Number'
      'yr BP'
      'SD'
      'Median'
      'Older'
      'Younger'
      'Older'
      'Younger'
      '% Prob')
    ControlLook.FixedGradientFrom = clWhite
    ControlLook.FixedGradientTo = clBtnFace
    ControlLook.FixedGradientHoverFrom = 13619409
    ControlLook.FixedGradientHoverTo = 12502728
    ControlLook.FixedGradientHoverMirrorFrom = 12502728
    ControlLook.FixedGradientHoverMirrorTo = 11254975
    ControlLook.FixedGradientDownFrom = 8816520
    ControlLook.FixedGradientDownTo = 7568510
    ControlLook.FixedGradientDownMirrorFrom = 7568510
    ControlLook.FixedGradientDownMirrorTo = 6452086
    ControlLook.FixedGradientDownBorder = 14007466
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
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clNavy
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = []
    FloatFormat = '%.2f'
    HoverButtons.Buttons = <>
    HoverButtons.Position = hbLeftFromColumnLeft
    HTMLSettings.ImageFolder = 'images'
    HTMLSettings.ImageBaseName = 'img'
    MouseActions.AllSelect = True
    MouseActions.RangeSelectAndEdit = True
    MouseActions.RowSelect = True
    Navigation.AdvanceOnEnter = True
    Navigation.AllowClipboardShortCuts = True
    Navigation.AllowCtrlEnter = False
    Navigation.AllowSmartClipboard = True
    Navigation.AllowClipboardAlways = True
    Navigation.AdvanceAuto = True
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
    SortSettings.HeaderColorTo = 16579058
    SortSettings.HeaderMirrorColor = 16380385
    SortSettings.HeaderMirrorColorTo = 16182488
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
        Editor = edNormal
        FilterCaseSensitive = False
        Fixed = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Header = 'Lab Number'
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
        Width = 80
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
        Header = 'yr BP'
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
        Header = 'SD'
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
        Header = 'Median'
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
        Header = 'Older'
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
        Header = 'Younger'
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
        Header = 'Older'
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
        Header = 'Younger'
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
        Header = '% Prob'
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
        Width = 64
      end>
    ColWidths = (
      36
      80
      64
      64
      64
      64
      64
      64
      64
      64)
  end
  object cxLabel3: TcxLabel
    Left = 8
    Top = 8
    Caption = 'Calibration Curve: '
    Properties.Alignment.Horz = taRightJustify
    AnchorX = 102
  end
  object cxComboBox1: TcxComboBox
    Left = 100
    Top = 8
    Properties.Items.Strings = (
      'IntCal20.14c'
      'IntCal13.14c'
      'IntCal09.14c'
      'IntCal04.14c'
      'IntCal98.14c'
      'ShCal20.14c'
      'ShCal13.14c'
      'ShCal04.14c'
      'Marine20.14c'
      'Marine13.14c'
      'Marine09.14c'
      'Marine09.14c'
      'Marine98.14c')
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 3
    Text = 'IntCal20.14c'
    Width = 97
  end
  object FlowPanel1: TFlowPanel
    Left = 183
    Top = 320
    Width = 300
    Height = 25
    Anchors = [akBottom]
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 2
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Calibrate'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 0
      OptionsImage.Images = cxImageList1
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 75
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Browser'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 1
      OptionsImage.Images = cxImageList1
      TabOrder = 1
      OnClick = cxButton2Click
    end
    object cxButton3: TcxButton
      Left = 150
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Copy'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 2
      OptionsImage.Images = cxImageList1
      TabOrder = 2
      OnClick = cxButton3Click
    end
    object cxButton4: TcxButton
      Left = 225
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Close'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 11
      OptionsImage.ImageIndex = 3
      OptionsImage.Images = cxImageList1
      TabOrder = 3
    end
  end
  object cxLabel1: TcxLabel
    Left = 223
    Top = 8
    Caption = 'Program Version: '
    Properties.Alignment.Horz = taRightJustify
    Visible = False
    AnchorX = 312
  end
  object cxTextEdit1: TcxTextEdit
    Left = 310
    Top = 8
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 5
    Visible = False
    Width = 266
  end
  object ipwHTTP1: TipwHTTP
    TransferredDataLimit = 65536
    Left = 536
    Top = 312
  end
  object TcpClient1: TTcpClient
    Left = 568
    Top = 312
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 20447256
    ImageInfo = <
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
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000030000000D0000001E0000003100000040070605550907065A0302
          0249000000370000002600000013000000060000000000000000000000000000
          0009000000250000004D0D09077C5D463FC5BB9D93F4E3D0CBFFE1CCC6FFD1B4
          ACFD927970E02C1E19A20100005B000000340000001100000002000000050000
          00270000005B2D1910ADA97561FBCAA599FFCBA79BFFD3B4AAFFD2B2A8FFCAA6
          9AFFC9A598FFBB8D7BFF734632E1080301780000003B0000000E0000000A0000
          0039271106A5A16347FEAF7862FFD3B0A6FFCCA99CFFC59C8EFFCAA598FFBF93
          83FFBA8B79FFB98A77FFB3806AFF7A442BE80301005800000018000000050603
          0145914C2CFA995332FF9A5434FFDCBEB7FFFCFBFAFFCBA699FFBB8C7AFFAE77
          61FFAA7057FFA4664BFF924722FFAA7156FF3F1C0BAF0000000E000000004920
          0C9D995433FF8E3F18FF985230FFDBBDB5FFEFE1DEFFBD917EFFAE7760FFB078
          62FFB17964FFA36449FFC18F7FFFA56448FF9A5838FC0D06032001000001843C
          18EC924723FF934924FF9C5736FFD1ADA1FFE8D5D0FFD0AFA2FFB88974FFBB89
          78FFB57D69FFB67D6AFFD5AFA7FFC7998CFFB0735DFF3D1C0C6D0D0602188F41
          1BFF8E3F18FF9E5B3AFFB27961FFE2C7C2FFEBD9D6FFEDDEDBFFD8BEB2FFD8BB
          B1FFAB6D56FFB17761FFD9B7B0FFD6B1A8FF924622FF55260E981108031F8E3F
          18FF995331FF934824FFC29584FFE8D5D0FFE2CCC6FFAE7760FFB4816CFFBF93
          82FFB98975FFCEA99CFFE1C7C1FFD5AFA7FFAC6D55FF58270F9E0502010A8B3D
          17FC9D5938FFB5836EFFCFACA0FFD1B2A6FFB3826DFFB17E69FFB98B78FFCAA8
          99FFF3EAE8FFEDDEDAFFE9D5D1FFDAB8B1FFB9816FFF4E251287000000007032
          13C9C29383FFD2B2A7FFCDAB9FFFC7A293FFC39C8CFFC09786FFC6A293FFCFB0
          A3FFF9F4F3FFF5ECEBFFEAD7D3FFE1C8C2FFC28E80FF2B160C4900000000391C
          0F62D2ABA1FFE9D6D2FFE6D3CDFFD0B2A6FFD0B3A7FFCEAFA2FFDBC5BCFFD2B7
          ABFFEBDDD9FFEDE0DCFFE0CAC3FFE5CFCAFF955F4BDD02010103000000000201
          0103865743C6EEE0DCFFF0E4E1FFECDEDAFFE8DAD4FFE5D5CEFFE7D9D3FFDEC8
          C0FFEADCD7FFF1E6E3FFF0E3E0FFDCC2B9FE301D144B00000000000000000000
          00000F090618A07B6AD6F3EAE8FFF5EDECFFF2E9E6FFECE0DBFFECE0DCFFEADE
          D9FFF2E9E7FFF2E9E6FFEBDED9FE513B30710000000000000000000000000000
          0000000000000A07050F7154469CDCC8BEFCF8F4F3FFFAF6F5FFF9F5F3FFF8F4
          F3FFF4EDEAFFB9A196DD382C264B000000000000000000000000000000000000
          0000000000000000000000000000140E0A1E4A33276D715649987961559E644B
          408733241C490202010300000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000003000000033000000330000
          0033000000330000003300000033000000330000003300000030000000000000
          000000000000000000000000000000000000AE7E2AF2B68124FFB57F20FFB57F
          1FFFB57F1FFFB57F1FFFB57F1FFFB57F20FFB68124FFAE7E2AF2000000000000
          000000000000000000000000000000000000B68225FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB68124FF000000300000
          003300000033000000330000003300000033B58022FFFFFFFFFFEADDBAFFEADC
          B8FFE8D9B3FFE7D7B1FFE6D6AFFFE6D6AEFFFFFFFFFFB57F1FFFAE7E2AF2B681
          24FFB57F20FFB57F1FFFB57F1FFFB47E1EFFB37B1AFFB07712FFB07612FFBB8A
          32FFEADCB8FFE7D7B1FFE6D6AFFFE5D5ACFFFFFFFFFFB47E1EFFB68124FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB076
          10FFFCFBF4FFF9F4E9FFF8F2E6FFF8F2E5FFFFFFFFFFB47E1EFFB57F1FFFFFFF
          FFFFE6D6AEFFE6D6AFFFE6D7B0FFE6D7B0FFE6D6AFFFE6D6AEFFFFFFFFFFAE74
          0EFFF8F5E7FFF4EEDCFFF3ECD9FFF3ECD8FFFFFFFFFFB47E1EFFB47E1EFFFFFF
          FFFFE5D5ACFFE6D6AFFFE6D6AFFFE6D6AFFFE6D6AFFFE5D5ACFFFFFFFFFFAE74
          0EFFF6F0DEFFF1E8D1FFF0E6CDFFF0E7CDFFFFFFFFFFB47E1EFFB47E1EFFFFFF
          FFFFF8F2E5FFF8F2E6FFF8F3E7FFF8F3E7FFF8F2E6FFF8F2E5FFFFFFFFFFAE74
          0EFFF1EAD3FFF7F1E4FFFFFFFFFFFFFFFFFFFFFFFFFFB47F1EFFB47E1EFFFFFF
          FFFFF3ECD9FFF3ECD9FFF3ECDAFFF3ECD9FFF3ECD9FFF3ECD8FFFFFFFFFFAE74
          0EFFEFE4C7FFFFFFFFFFCFAB6DFFAC7005FFFFFFFFFFB58022FFB47E1EFFFFFF
          FFFFF1E8CFFFF1E8D0FFF1E8D0FFF0E7CFFFF0E6CDFFF0E7CDFFFFFFFFFFAE74
          0EFFEBDEBCFFFFFFFFFFAC7005FFFFFFFFFFECDCC4FF7B581AACB47E1EFFFFFF
          FFFFEDE3C7FFEDE3C8FFEDE3C7FFF6F0E1FFFFFFFFFFFFFFFFFFFFFFFFFFB076
          11FFFFFFFFFFFFFFFFFFFFFFFFFFECDCC4FF775416A700000000B47E1EFFFFFF
          FFFFEBDDBCFFEBDDBDFFEBDCBBFFFFFFFFFFCFAB6DFFAC7005FFFFFFFFFFB37D
          1CFFB58021FFB57F20FFB58022FF7B581AAC0000000000000000B57F1FFFFFFF
          FFFFE7D8B1FFE7D8B1FFE7D7B0FFFFFFFFFFAC7005FFFFFFFFFFECDCC3FF7554
          18A4000000000000000000000000000000000000000000000000B68124FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECDCC4FF775416A70000
          0000000000000000000000000000000000000000000000000000AD7F2AEFB681
          24FFB57F1FFFB47E1EFFB47E1EFFB47F1FFFB58022FF996D21D5000000000000
          0000000000000000000000000000000000000000000000000000}
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
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 616
    Top = 312
  end
end
