object UpdateNeotomaSiteForm: TUpdateNeotomaSiteForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Update Site Metadata'
  ClientHeight = 468
  ClientWidth = 554
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 554
    Height = 44
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object cxLabel1: TcxLabel
      Left = 8
      Top = 8
      AutoSize = False
      Caption = 
        'Differences in site metadata between Tilia and Neootoma are show' +
        'n in orange. You may update a Tilia field by clicking the green ' +
        'arrow button. To update Neotoma, click the Update Neotoma button' +
        '.'
      Style.TextColor = clNavy
      Properties.WordWrap = True
      Height = 32
      Width = 516
    end
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 44
    Width = 554
    Height = 365
    Cursor = crDefault
    Align = alClient
    ColCount = 4
    DefaultRowHeight = 20
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 14
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
    HoverRow = True
    HoverRowCells = [hcNormal, hcSelected]
    OnCellValidate = AdvColumnGrid1CellValidate
    OnGetEditorType = AdvColumnGrid1GetEditorType
    OnButtonClick = AdvColumnGrid1ButtonClick
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = 15387318
    ColumnHeaders.Strings = (
      'Field'
      'Tilia'
      ''
      'Neotoma')
    ColumnSize.Stretch = True
    ColumnSize.StretchColumn = 0
    ControlLook.FixedGradientFrom = clWhite
    ControlLook.FixedGradientTo = clSilver
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
    FixedColWidth = 162
    FixedRowHeight = 20
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
    RowHeaders.Strings = (
      'Rebne'
      'Vicky')
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
        Editor = edNormal
        FilterCaseSensitive = False
        Fixed = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Header = 'Field'
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
        Width = 162
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
        Header = 'Tilia'
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
        Width = 180
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
        Width = 26
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
        Header = 'Neotoma'
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
    ExplicitWidth = 532
    ExplicitHeight = 381
    ColWidths = (
      162
      180
      26
      182)
  end
  object Panel2: TPanel
    Left = 0
    Top = 409
    Width = 554
    Height = 40
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object FlowPanel1: TFlowPanel
      Left = 170
      Top = 8
      Width = 195
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 120
        Height = 25
        Caption = 'Update Neotoma'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList2
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 120
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Close'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 11
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList2
        TabOrder = 1
        OnClick = cxButton2Click
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 449
    Width = 554
    Height = 19
    Panels = <>
  end
  object TcpClient1: TTcpClient
    Left = 408
    Top = 88
  end
  object cxImageList1: TcxImageList
    Height = 9
    FormatVersion = 1
    DesignInfo = 5767480
    ImageInfo = <
      item
        Image.Data = {
          76020000424D7602000000000000360000002800000010000000090000000100
          2000000000004002000000000000000000000000000000000000000000000000
          0000000000000000003300000027000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000033008C4BFF006D3BD1000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0033008746FF54DAB0FF008847FF000000330000003300000033000000330000
          0033000000330000003300000033000000330000003300000023000000330087
          44FF65D7B3FF00D8A0FF00B97FFF008644FF008846FF008947FF008947FF0089
          47FF008947FF008947FF008947FF008947FF008A49FF006135C0008A48FF74DA
          BDFF00CD9CFF00CB9AFF00CD9CFF00CF9FFF00D0A0FF00D0A0FF00D0A0FF00D0
          A0FF00D0A0FF00D0A0FF00D0A0FF00D1A1FF00D5A7FF008A49FF008A48FF86DE
          C8FF00C59CFF00C49AFF64DFC7FF61E0C8FF61E1CAFF61E1CAFF61E1CAFF61E1
          CAFF61E1CAFF61E1CAFF61E1CAFF61E2CBFF65E6D1FF008A48FF000000000087
          43FF9BE0D0FF00C09EFF00AB7DFF008641FF008744FF008844FF008844FF0088
          44FF008844FF008844FF008844FF008845FF008A47FF006134B0000000000000
          0000008743FFA4E4D9FF008945FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000008C49FF007941DA000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end>
  end
  object cxImageList2: TcxImageList
    FormatVersion = 1
    DesignInfo = 5767432
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000CC0000
          00840202008714140EF500001BFF000063FF000086FF00006CFF00006AFF0000
          7AFF000066FF00001EFF090903DC191915B000000084000000CB171717BA4040
          3E4D1E1E2B76060664F8000090FF00007FFF06052CFF50595FFF626870FF2A31
          37FF000053FF00008EFF0A0A68F63A3A42B040403E50161616B8050503921515
          105B040421F2000045E900005FE9000446FF005445FF2C9E9AFF67B1ADFF0380
          78FF002329FF000069FA000048E4040422EE1212124D07070793121215CB0707
          22DA3B3B339F5A5A48A11A1A23BB010641FF4D968DFF62A4A4FF7FAAAAFF58A9
          A6FF285264FF000030F43D3D299B585855A71818169F000000D107072FFF0404
          42EE2020122F414140BF080863F800054CFF107A70FF2D9292FF5D9F9FFF138E
          8BFF06414CFF000067FF202049E34141346009090977000015FF000044FF0000
          66F200000E8A00005AF7000091FF0B0B49FF4B9187FF61A3A3FF7FABABFF55A4
          A1FF2E5258FF02006CFF000087FF000022B300002BAF000041FF00007BFF0000
          84FF000080FF00008BFF000051FF497275FF289391FF278D8DFF5D9F9FFF1482
          82FF569A95FF112D50FF000076FF000086FF000080FF00007DFF000082FF0000
          86FF020060FF0B1245FF4E7175FF86B8B3FF5D9FA0FF5C9F9FFF7FABABFF4E95
          95FF82B0B0FF6BA59CFF2C3853FF06025EFF000088FF000081FF000085FF0003
          5BFF135E5AFF49978BFF108482FF5EA0A0FF288D8DFF268D8DFF5D9F9FFF127F
          7FFF5D9F9FFF2A9192FF1A9086FF48706BFF00025AFF000085FF00008EFF060B
          41FF60A493FF88B5B6FF4F9595FF82ADADFF5EA9A6FF5EAAA7FF86B8B4FF4EA0
          9DFF7FADADFF5D9E9EFF61A6A7FF81AF9FFF060940FF000089FF000063FF0204
          64FF316762FF5DA69CFF168D8DFF5D9C96FF325459FF254C55FF39535CFF1D49
          4EFF699F9AFF2B9798FF2E958CFF5B7671FF02045EFF000083FF000017FF0000
          8EFF00005EFF082B49FF2B7764FF08294FFF00006AFF000070FF00006EFF0000
          67FF2E365DFF529582FF052C49FF03015FFF00008CFF000023FF000000C40000
          4EDD000094FF000077FF100549FF000079FF000083FF000072FF000071FF0000
          83FF000078FF160C50FF020078FF000093FF000050DE000000C4181818B23737
          36A603035DFF00008BFF00008BFF00007DFF1C1C41F23C3C44EC3F3F46F11B1B
          41F100007CFF000089FF00008BFF000059F6373736A7181818B10707079D0404
          04040404063B08085EF3000089FF00007EFF0A0A0687111111114D4D435A0A0A
          017D00007DFF000089FF090962F022222077040404040808089B000000D00000
          008E0606038F14140DF500001BFF000064FF000061ED040404A2141414C10000
          5EE9000065FF00001DFF090902DD1B1B18B80000008E000000CF}
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
          2000000000000004000000000000000000000000000000000000D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800CF9808007F5B0000D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000CF9808007F5B0000D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000F6CB9700CF9808007F5B
          0000D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000F6CB9700F6CB9700CF98
          08007F5B0000D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800CF9808007F5B00007F5B00007F5B00007F5B0000F6CB9700F6CB9700F6CB
          9700CF9808007F5B0000D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D8007F5B0000F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB
          9700F6CB9700CF9808007F5B0000D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D8007F5B0000F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB
          9700F6CB9700F6CB9700CF9808007F5B0000D8D8D800D8D8D800D8D8D800D8D8
          D8007F5B0000F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB9700F6CB
          9700F6CB9700F6CB9700FFF3D500CF980800D8D8D800D8D8D800D8D8D800D8D8
          D8007F5B0000FFF3D500FFF3D500FFF3D500FFF3D500FFF3D500F6CB9700F6CB
          9700F6CB9700FFF3D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800CF980800CF980800CF980800CF9808007F5B0000FFF3D500F6CB9700F6CB
          9700FFF3D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000FFF3D500F6CB9700FFF3
          D500CF980800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000FFF3D500FFF3D500CF98
          0800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000FFF3D500CF980800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D8007F5B0000CF980800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8
          D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800D8D8D800}
        MaskColor = 14211288
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 360
    Top = 88
  end
end
