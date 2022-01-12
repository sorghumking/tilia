object NewSynTypeForm: TNewSynTypeForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'New Synonym Type'
  ClientHeight = 277
  ClientWidth = 368
  Color = 15984090
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 0
    Width = 368
    Height = 169
    Cursor = crDefault
    Align = alTop
    ColCount = 2
    DefaultRowHeight = 18
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
    ScrollBars = ssBoth
    TabOrder = 0
    ActiveRowShow = True
    ActiveRowColor = 15387318
    HoverRow = True
    HoverRowCells = [hcNormal, hcSelected]
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = 15387318
    ColumnHeaders.Strings = (
      'ID'
      'Synonym Type')
    ColumnSize.Stretch = True
    ColumnSize.StretchColumn = 1
    ColumnSize.SynchWithGrid = True
    ControlLook.FixedGradientFrom = clWhite
    ControlLook.FixedGradientTo = clSilver
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
    ControlLook.DropDownFooter.SizeGrip = False
    ControlLook.DropDownFooter.Buttons = <>
    ControlLook.DropDownFooter.ButtonAlignment = baLeft
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
    FixedColWidth = 35
    FixedRowHeight = 18
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clNavy
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FloatFormat = '%.2f'
    HoverButtons.Buttons = <>
    HoverButtons.Position = hbLeftFromColumnLeft
    HTMLSettings.ImageFolder = 'images'
    HTMLSettings.ImageBaseName = 'img'
    Look = glTMS
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
    SortSettings.Column = 0
    SortSettings.Show = True
    SortSettings.IgnoreCase = True
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
        Header = 'ID'
        HeaderAlignment = taCenter
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = clNavy
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = []
        MinSize = 0
        MaxSize = 0
        Name = 'ID'
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
        Width = 35
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
        Header = 'Synonym Type'
        HeaderAlignment = taCenter
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = clNavy
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = []
        MinSize = 0
        MaxSize = 0
        Name = 'SynonymType'
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
        Width = 329
      end>
    ColWidths = (
      35
      329)
  end
  object cxTextEdit1: TcxTextEdit
    Left = 8
    Top = 192
    Properties.OnChange = cxTextEdit1PropertiesChange
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 1
    Width = 354
  end
  object cxLabel1: TcxLabel
    Left = 8
    Top = 174
    Caption = 'New Synonym Type:'
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clNavy
    Style.Font.Height = -11
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.IsFontAssigned = True
  end
  object FlowPanel1: TFlowPanel
    Left = 109
    Top = 224
    Width = 150
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 3
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Upload'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
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
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 75
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Close'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 11
      OptionsImage.Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000050000000B0000000B0000
        0005000000000000000000000000000000000000000000000000000000000000
        000000000000000000040000012D02021989090940C80F1059E20F1059E20909
        40C8020219890000012D00000004000000000000000000000000000000000000
        00000000000D01010E73141569EE262991FF272C97FF252997FF252997FF272B
        97FF262991FF141569EE01010E730000000D0000000000000000000000000000
        00050202106C1F2186FB4448A5FF3136A0FF181F9DFF1921A0FF1821A0FF181F
        9DFF2D339FFF474BA6FF1E2186FB0202106C0000000500000000000000000000
        02241C207FF0777ABFFFFEFEFEFFF4F5FAFF575FBEFF2532B1FF2532B1FF4D56
        BAFFEFF0F8FFFEFEFEFF8487C4FF1C207FF00000022400000000000000000B0C
        3B902930A2FFB3B6DEFFFFFFFFFFFFFFFFFFF5F6FBFF606CC8FF5864C6FFF1F2
        F9FFFFFFFFFFFFFFFFFFC1C3E4FF2930A1FF0B0C3C9000000000000000002228
        8EE72833ACFF525DC0FFF1F2FAFFFFFFFFFFFFFFFFFFF6F6FCFFF2F3FAFFFFFF
        FFFFFFFFFFFFF5F6FBFF5A65C3FF2832ABFF22278DE700000000010105192F38
        ABFF303EB7FF384AC1FF6575D2FFF3F4FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFF6F7FCFF6D7BD3FF3849C0FF2F3DB6FF2E37AAFF01010619020209253743
        B5FF4050C2FF4C60CFFF566DD6FF98A8E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFA2B0E9FF546BD5FF4B5FCEFF3F4FC1FF3742B4FF020209250101030F3F4C
        BBFE5263CDFF6076D9FF8599E4FFF5F6FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFF8F9FDFF8A9DE5FF5E74D7FF5162CCFF3E4BBAFE0101040F000000003540
        9CD06476D6FF899BE4FFF5F7FDFFFFFFFFFFFFFFFFFFFBFCFEFFF9FBFEFFFFFF
        FFFFFFFFFFFFF8F9FDFF8E9FE4FF6375D4FF34409BD000000000000000001318
        3D697082DAFFD1D8F4FFFFFFFFFFFFFFFFFFFCFDFEFFCEDFFCFFCADDFCFFFAFC
        FEFFFFFFFFFFFFFFFFFFD9DFF6FF6F80D9FF13193F6900000000000000000000
        01044958A7CAB8C4F0FFFEFEFEFFFBFCFEFFD1E2FCFFD1E2FEFFD1E1FDFFCEDF
        FCFFFAFBFEFFFEFEFEFFBDC8F1FF4857A7CA0000010400000000000000000000
        00000304091A6476BED6B5C8F4FFC0D5F8FFC9DDFBFFD4E3FDFFD3E3FDFFC8DC
        FBFFBED4F8FFB5C7F3FF6375BDD603040A1A0000000000000000000000000000
        0000000000000102040D404D7A93A6BCECF7C6DAFAFFCDDFFBFFCDDFFBFFC5D9
        FAFFA5BBECF7404D7B930202040D000000000000000000000000000000000000
        0000000000000000000000000000030406121B213355333D5679333D56791B22
        3355030406120000000000000000000000000000000000000000}
      TabOrder = 1
    end
  end
  object StatusBar1: TPanel
    Left = 0
    Top = 258
    Width = 368
    Height = 19
    Align = alBottom
    Alignment = taLeftJustify
    BevelOuter = bvLowered
    Color = 15984090
    ParentBackground = False
    TabOrder = 4
  end
  object TcpClient1: TTcpClient
    Left = 64
    Top = 224
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 288
    Top = 224
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 24
    Top = 224
  end
end
