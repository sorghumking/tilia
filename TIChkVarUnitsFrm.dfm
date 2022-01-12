object CheckVarUnitsForm: TCheckVarUnitsForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Check Variable Units'
  ClientHeight = 353
  ClientWidth = 651
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
  DesignSize = (
    651
    353)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 651
    Height = 50
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 14
      Width = 624
      Height = 26
      Caption = 
        'The following variables have no units specified. Check the box i' +
        'n the first column if the variable is unitless. This situation i' +
        's rare (e.g. pH).'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
  end
  object cxButton1: TcxButton
    Left = 257
    Top = 321
    Width = 65
    Height = 24
    Anchors = [akTop, akRight]
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 1
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 328
    Top = 321
    Width = 65
    Height = 24
    Anchors = [akTop, akRight]
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 2
  end
  object cxButton5: TcxButton
    Left = 8
    Top = 321
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
    TabOrder = 3
    OnClick = cxButton5Click
  end
  object cxButton3: TcxButton
    Left = 32
    Top = 321
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
    TabOrder = 4
    OnClick = cxButton3Click
  end
  object cxButton4: TcxButton
    Left = 56
    Top = 321
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
    TabOrder = 5
    OnClick = cxButton4Click
  end
  object cxButton6: TcxButton
    Left = 80
    Top = 321
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
    TabOrder = 6
    OnClick = cxButton6Click
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 50
    Width = 651
    Height = 265
    Cursor = crDefault
    Align = alTop
    ColCount = 6
    DefaultRowHeight = 18
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    ScrollBars = ssBoth
    TabOrder = 7
    HoverRowCells = [hcNormal, hcSelected]
    OnButtonClick = AdvColumnGrid1ButtonClick
    OnCheckBoxClick = AdvColumnGrid1CheckBoxClick
    OnEditCellDone = AdvColumnGrid1EditCellDone
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ColumnHeaders.Strings = (
      ''
      'Row'
      'Variable Code'
      'Taxon Name'
      'Element'
      'Units')
    ColumnSize.Stretch = True
    ColumnSize.StretchColumn = 3
    ControlLook.FixedGradientHoverFrom = clGray
    ControlLook.FixedGradientHoverTo = clWhite
    ControlLook.FixedGradientDownFrom = clGray
    ControlLook.FixedGradientDownTo = clSilver
    ControlLook.CheckAlwaysActive = True
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
      'Larger than'
      'Smaller than'
      'Clear')
    FixedColWidth = 20
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
    MouseActions.CheckAllCheck = True
    MouseActions.DisjunctCellSelect = True
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
        Width = 20
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
        Header = 'Row'
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
        Header = 'Variable Code'
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
        Width = 110
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
        Width = 275
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
        Width = 106
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
        Header = 'Units'
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
        Width = 104
      end>
    ColWidths = (
      20
      32
      110
      275
      106
      104)
  end
  object TcpClient1: TTcpClient
    Left = 488
    Top = 320
  end
  object ImageList1: TImageList
    Height = 14
    Width = 15
    Left = 424
    Top = 320
    Bitmap = {
      494C01010100700098000F000E00FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      00000000000036000000280000003C0000000E0000000100200000000000200D
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000EBEB
      EB000000000000000000F7F7F700D5D5D5000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C8CACC00DFE0E1000000
      000000000000FDFDFD00DADADA00696A6A008B8F9300F2F3F400FAFAFA00AAAA
      AA007E7D7D00D8D8D80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000008A949700C8CBCC00E6E5E500AAAAAA00696C6D007B85
      880065717B009BA0A600F9F9F900EFEFEF005257580083858700000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C8CBCD00888F
      92008A8F940085898C008184850067757A008B93960093949300CACACA00EEEE
      EE00646D71005962650000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000D7DADA0064737B005B718C004C64830050616B005361
      66007B8285008E929900ECECEC00F3F3F300F9F9F90077828700000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A1AAAE005364
      6B00515B6500485866004D606800576C7D00B4B7B700DCDCDC00F8F8F9000000
      000000000000A7AFB20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000008A969B00475E6600545D610033444C0044596000586F
      8A006873790060697300D0D3D7000000000000000000A9B1B400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000949B9F003A50
      59003B4D5400182E3700384C5400535F6B00727F85006F7A82008D949900DDDD
      DE00EFF0F0008E9A9E0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F2F1F0006C797E00324F5A00203F4A00233D4700596B
      720074828800818C9200818C91008B9498009CA5A800FBFCFC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DDDDDC005D6B
      7000324D58002B46510029454F00435860006071780075848A00768489007F88
      8B00F7F8F8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FBFBFB00D8DBDC00B8BFC2007C898F00364D56003951
      59004258610062717700848D9100DADBDB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FDFDFC008592970078808400D3D3D300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
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
      280000003C0000000E0000000100010000000000700000000000000000000000
      000000000000000000000000FFFFFF00FFFE000000000000FECE000000000000
      9802000000000000C002000000000000C002000000000000C002000000000000
      C01A000000000000C01A000000000000C002000000000000C002000000000000
      C006000000000000C00E000000000000FC3E000000000000FFFE000000000000
      00000000000000000000000000000000000000000000}
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 456
    Top = 320
  end
end
