object SelectItemForm: TSelectItemForm
  Left = 0
  Top = 0
  Caption = 'Select Item'
  ClientHeight = 321
  ClientWidth = 572
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 572
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    Caption = 'Select Item'
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    ExplicitLeft = 256
    ExplicitTop = 24
    ExplicitWidth = 185
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 41
    Width = 572
    Height = 231
    Cursor = crDefault
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    FixedCols = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ColumnHeaders.Strings = (
      'ID'
      'Item')
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
    FixedRowHeight = 18
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FloatFormat = '%.2f'
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
    Version = '3.1.2.4'
    Columns = <
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
        Header = 'ID'
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
        Width = 64
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
        Header = 'Item'
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
        Width = 503
      end>
    ExplicitHeight = 218
    ColWidths = (
      64
      503)
  end
  object Panel2: TPanel
    Left = 0
    Top = 272
    Width = 572
    Height = 49
    Align = alBottom
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 2
    ExplicitTop = 267
    object FlowPanel1: TFlowPanel
      Left = 208
      Top = 12
      Width = 150
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 75
        Height = 25
        Caption = '&Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
          FFFFFFF6FBFFDAD8FFE1E4FFECFFE3F4FFDDFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4FFF9CEDCD8A4AFB39FADA7B5CCACE7
          FFD9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          F3FFF18AA67B638A3F5B813977906ECBDDCCF0FFF1FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFE8FFE7C9E9BA679543548F0F4F861155764395
          A899D4E2DCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFF5DEFDD6
          91BE6F69A52F61A80C5C9F0E4B7926617D59ACBBB7E8F4F6FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFE5FFE8BEE4B05E9431589A15569D065A9F0F4E861B59
          823F829885C5D3CFF5FFF1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFF3C985B071
          4E871E50911669A63270AD395C991F60952E65865393A991D2E1D3FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFB1D8A1527E3B6095386FA846A8D987A2D57D69A43154
          8F1D5782316F8D5CB5C4B6F2F9FCFFFFFFFFFFFFFFFFFFFFFFFFEEFFD5C1EAAC
          9CC48AADD59EE3FFD6EBFFD7A0D17B497F1B6699315A8234819481C3CCD0EBF3
          ECFFFFFFFFFFFFFFFFFFF1FFD8F0FFDEE4FDE1E6FFEBEFFFEEEFFFE7D4FAC0A7
          D48552841E6D9B426B8561849588D3E0D0F8FFF5FFFFFFFFFFFFEEFFDBF4FFEB
          FFFFFFFFFFFFFFFFFFEDFFECE8FFE2E1FFD080A8606D97496286446E8B5A97AA
          8FD1DED0F4FFF5FFFFFFF5FFEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3FFF2F3
          FFEDD2F1C48FB476759E4D7AA05878906D9EAE9CD8E8D7F0FFEFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4FFF2F3FFF5DDF7D3A1CC7B85AF5C8AA6
          7B83978098AE91D7EECEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFF4FFF9F3FFF0D8FDBFB2DA9398B5878BA67F95B088AAC69BFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7FEE2F1FFF0EAFFE3B5D7
          A1ABCF93BCDEA8B0D09FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFF2FFFBF1FFF5F1FFDCCCF4ADC5E9ADEEFFDA}
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 75
        Top = 0
        Width = 75
        Height = 25
        Caption = '&Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000808080FF808080FF000000000000000000000000000000000000
          000000000000808080FF00000000000000000000000000000000000000000000
          FFFF000080FF000000FF808080FF808080FF0000000000000000000000000000
          FFFF000000FF808080FF808080FF000000000000000000000000000000000000
          FFFF000080FF000080FF000000FF808080FF808080FF00000000000000000000
          FFFF000080FF000000FF808080FF808080FF0000000000000000000000000000
          FFFF000080FF000080FF000080FF000000FF808080FF808080FF0000FFFF0000
          80FF000080FF000080FF000000FF808080FF808080FF00000000000000000000
          FFFF0000FFFF000080FF000080FF000080FF000000FF0000FFFF000080FF0000
          80FF000080FF000080FF000000FF000000FF0000000000000000000000000000
          00000000FFFF0000FFFF000080FF000080FF000080FF000080FF000080FF0000
          80FF000080FF000080FF000000FF000000000000000000000000000000000000
          0000000000000000FFFF0000FFFF000080FF000080FF000080FF000080FF0000
          80FF000080FF000000FF00000000000000000000000000000000000000000000
          000000000000000000000000FFFF0000FFFF000080FF000080FF000080FF0000
          80FF000000FF808080FF00000000000000000000000000000000000000000000
          00000000000000000000000000000000FFFF000080FF000080FF000080FF0000
          80FF000000FF808080FF00000000000000000000000000000000000000000000
          00000000000000000000000000000000FFFF000080FF000080FF000080FF0000
          80FF000000FF000000FF808080FF000000000000000000000000000000000000
          000000000000000000000000FFFF000080FF000080FF000080FF000080FF0000
          80FF000080FF000000FF808080FF808080FF0000000000000000000000000000
          0000000000000000FFFF0000FFFF000080FF000080FF000080FF0000FFFF0000
          FFFF000080FF000000FF000000FF808080FF808080FF00000000000000000000
          00000000FFFF0000FFFF000080FF000080FF000080FF000000FF808080FF0000
          FFFF0000FFFF000080FF000000FF000000FF808080FF808080FF000000000000
          00000000FFFF000080FF000080FF000080FF000000FF808080FF000000000000
          00000000FFFF0000FFFF000080FF000000FF000000FF808080FF000000000000
          FFFF0000FFFF0000FFFF000080FF000080FF000000FF00000000000000000000
          0000000000000000FFFF0000FFFF000080FF000080FF00000000000000000000
          0000000000000000FFFF0000FFFF0000FFFF0000000000000000000000000000
          000000000000000000000000FFFF0000FFFF0000000000000000}
        TabOrder = 1
      end
    end
  end
end
