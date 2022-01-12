object NeotomaContactPubForm: TNeotomaContactPubForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'Neotoma Publications'
  ClientHeight = 235
  ClientWidth = 432
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 432
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    Caption = 'Contact Name'
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 202
    Width = 432
    Height = 33
    Align = alBottom
    BevelOuter = bvNone
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
    object cxButton1: TcxButton
      Left = 187
      Top = 4
      Width = 57
      Height = 25
      Caption = 'Close'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 11
      TabOrder = 0
    end
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 33
    Width = 432
    Height = 169
    Cursor = crDefault
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 20
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goTabs]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 2
    HoverRowCells = [hcNormal, hcSelected]
    OnGetEditorProp = AdvColumnGrid1GetEditorProp
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ColumnSize.Stretch = True
    ColumnSize.StretchColumn = 0
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
      'Larger than'
      'Smaller than'
      'Clear')
    FixedColWidth = 428
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
        EditLink = FormControlEditLink1
        Editor = edCustom
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
        Width = 428
      end>
    ExplicitTop = 39
    ColWidths = (
      428)
    object AdvControlDropDown1: TAdvControlDropDown
      Left = 151
      Top = 73
      Width = 145
      Height = 21
      EmptyTextFocused = False
      EmptyTextStyle = []
      Visible = False
      DropDownColor = 15984090
      DropDownColorTo = 15785680
      DropDownBorderColor = clNone
      DropDownHeight = 100
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
      DropDownHeader.Caption = 'Publication'
      DropDownHeader.Font.Charset = DEFAULT_CHARSET
      DropDownHeader.Font.Color = 7485192
      DropDownHeader.Font.Height = -11
      DropDownHeader.Font.Name = 'Tahoma'
      DropDownHeader.Font.Style = [fsBold]
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
          ModalResult = 1
        end>
      TabOrder = 2
      Control = cxMemo1
      SelectionColorStyle = 1
      TMSStyle = 4
    end
    object cxMemo1: TcxMemo
      Left = 151
      Top = 100
      Properties.ReadOnly = True
      Properties.ScrollBars = ssVertical
      Style.BorderColor = clSilver
      Style.BorderStyle = ebsSingle
      Style.LookAndFeel.Kind = lfUltraFlat
      StyleDisabled.LookAndFeel.Kind = lfUltraFlat
      StyleFocused.LookAndFeel.Kind = lfUltraFlat
      StyleHot.LookAndFeel.Kind = lfUltraFlat
      TabOrder = 3
      Height = 41
      Width = 106
    end
  end
  object TcpClient1: TTcpClient
    Left = 376
  end
  object FormControlEditLink1: TFormControlEditLink
    Tag = 0
    WantKeyLeftRight = False
    WantKeyUpDown = False
    WantKeyHomeEnd = False
    WantKeyPriorNext = False
    Control = AdvControlDropDown1
    OnSetEditorValue = FormControlEditLink1SetEditorValue
    OnGetEditorValue = FormControlEditLink1GetEditorValue
    Left = 32
    Top = 120
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 336
  end
end
