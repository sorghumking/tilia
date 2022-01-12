object WhitmoreForm: TWhitmoreForm
  Left = 0
  Top = 0
  Caption = 'Whitmore Data'
  ClientHeight = 349
  ClientWidth = 636
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 636
    Height = 80
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      636
      80)
    object FlowPanel1: TFlowPanel
      Left = 8
      Top = 49
      Width = 365
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 1
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 145
        Height = 25
        Caption = 'Get Whitmore Citations'
        OptionsImage.Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000333333FF333333FF0000
          0000000000000000000000000000000000000000000000000000000000003333
          33FF333333FF333333FF333333FF333333FF333333FF0F0F0F4D0F0F0F4D3333
          33FF333333FF333333FF333333FF333333FF333333FF00000000000000003333
          33FF000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000333333FF00000000000000003333
          33FF00000000242424B3242424B3242424B3242424B300000000000000002424
          24B3242424B3242424B3242424B300000000333333FF00000000000000003333
          33FF000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000333333FF00000000000000003333
          33FF00000000242424B3242424B3242424B3242424B300000000000000002424
          24B3242424B3242424B3242424B300000000333333FF00000000000000003333
          33FF000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000333333FF00000000000000003333
          33FF00000000242424B3242424B3242424B3242424B300000000000000002424
          24B3242424B3242424B3242424B300000000333333FF00000000000000003333
          33FF000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000333333FF00000000000000003333
          33FF00000000242424B3242424B3242424B3242424B300000000000000002424
          24B3242424B3242424B3242424B300000000333333FF00000000000000003333
          33FF0000000000000000000000000000000000000000333333FF333333FF0000
          000000000000000000000000000000000000333333FF00000000000000003333
          33FF333333FF333333FF333333FF333333FF333333FF0F0F0F4D0F0F0F4D3333
          33FF333333FF333333FF333333FF333333FF333333FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 145
        Top = 0
        Width = 137
        Height = 25
        Caption = 'Download Data'
        Enabled = False
        OptionsImage.Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000300000006000000080007
          0346012A159300331BA300190D75000000140000000000000000000000000000
          000000000000000000241C1C1C79555454B2717572D3627167DF0E5E37E80093
          4CFF00904EFF059453FF069554FF038446F50009044400000000000000000000
          0004171717879B9A97FAEBEAE8FFF2F5F3FFC9D7CEFF409268FF00873FFF0488
          46FF067F42FF03662BFF0E9B5EFF0D985AFF08894DF700010117000000000303
          0342A5A5A3FFA8A7A3FFEFEFECFFF9FAF9FFBDD0C5FF00813CFF028743FF0883
          49FF02662CFF047738FF077E42FF15A96EFF0D9E5FFF03251680000000000A0A
          0A44AFAEADFFA1A19EFFB2B3B0FFAAB6AFFF71A187FF008841FF0E965EFF1989
          57FF1EA163FF23AD70FF2AAA71FF209B66FF19AE74FF06462AB0000000001515
          153B8A8A88FF989894FFE2E3DEFFECF0EDFFA5C6B5FF00A366FF2CC295FF69DD
          BCFF49CA9BFF42D0A4FF7FE4C9FF6BDBB8FF2CBD89FF0A4931A6000000001818
          173B9A9997FFA7A6A3FFEFEFECFFF8FAF8FFC0D3C6FF0CB587FF37CEA7FF7FE0
          C7FF51D4ABFF4FD8B3FF8EE7D0FF82E0C4FF38C896FF071C155B000000001515
          143BACACAAFFA09F9CFFA9AAA7FFA3AAA5FF87A190FF4F9E81FF1DD4AEFF7CE2
          C9FF6DDCBEFF6FE0C2FF93E8D0FF74DFBFFF287F64CB00000000000000001414
          143B868583FF8F8E8BFFDFDFDCFFEDEEEDFFCAD2CCFF94AE9CFF51A287FF53D5
          B9FF81E5CFFF94E9D6FF7FE2C8FF5EB296FF090D0B2C00000000000000001817
          173B969593FFA7A6A2FFECECE9FFF9F8F9FFD5D6D3FFA3ADA5FF829587FFB0C1
          B4FFD8EAE4FFB5D7CBFF9FB5A7FF859086FF1011102A00000000000000001514
          143BABAAA9FFACABA8FFE1E0DDFFDAD9D7FFD0CFCDFFD2D2CFFFD6D7D5FFDBDD
          DBFFEAEBEAFFE2E5E1FFB9BEB9FF91948FFF0D0D0D2A00000000000000001414
          143BAFAEACFFB4B3AFFFB7B4B0FFC1BEBAFFCBC9C6FFD2D0CDFFD7D6D3FFDBDA
          D7FFDCDBD9FFDEDEDCFFE1DFDFFFABABA8FF0E0E0D2A00000000000000001E1E
          1E3CA19F9BFFAAA7A3FFB2B0ACFFBBB9B7FFC6C4C0FFCECCC9FFD3D1CEFFD4D4
          D1FFD8D6D4FFDAD8D6FFDCDAD8FFDAD9D7FF1616162B00000000000000000404
          040A999793EBA5A29EFFAEACA8FFB8B4B0FFBEBEBAFFC7C5C1FFCCCAC7FFCFCD
          CAFFD0D0CDFFD4D2D0FFD7D7D3FFB1B0AFE20101010300000000000000000000
          00000B0B0A11716F6E97B2B1ADF6B5B3AFFFB8B6B2FFBCBAB7FFC1BFBBFFC6C4
          C0FFCBCAC6FFC3C2C0F36E6D6B900606060B0000000000000000000000000000
          00000000000000000000000000001A1A1A293939385047474661464645613839
          3850191919280000000000000000000000000000000000000000}
        TabOrder = 2
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 282
        Top = 0
        Width = 83
        Height = 25
        Caption = 'Cancel'
        ModalResult = 2
        OptionsImage.Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000020000000C05031A46110852AB190C76E31D0E89FF1C0E89FF190C
          76E4120852AD06031B4D0000000E000000030000000000000000000000000000
          000301010519130A55A9211593FF2225AEFF2430C2FF2535CBFF2535CCFF2430
          C3FF2225AFFF211594FF140B58B20101051E0000000400000000000000020101
          03151C1270CD2522A6FF2D3DCCFF394BD3FF3445D1FF2939CDFF2839CDFF3344
          D0FF394AD4FF2D3CCDFF2523A8FF1C1270D20101051D00000003000000091912
          5BA72A27AAFF2F41D0FF3541C7FF2726ABFF3137BCFF384AD3FF384BD3FF3137
          BCFF2726ABFF3540C7FF2E40D0FF2927ACFF1A115EB10000000D08061C3D3129
          A2FD2C3CCCFF3842C6FF5F5DBDFFEDEDF8FF8B89CEFF3337B9FF3437B9FF8B89
          CEFFEDEDF8FF5F5DBDFF3741C6FF2B3ACDFF3028A4FF0907204A1E185F9F373B
          BCFF3042D0FF2621A5FFECE7ECFFF5EBE4FFF8F2EEFF9491D1FF9491D1FFF8F1
          EDFFF3E9E2FFECE6EBFF2621A5FF2E3FCFFF343ABEFF201A66B0312A92E03542
          CBFF3446D1FF2C2FB5FF8070ADFFEBDBD3FFF4EAE4FFF7F2EDFFF8F1EDFFF4E9
          E2FFEADAD1FF7F6FACFF2B2EB5FF3144D0FF3040CBFF312A95E53E37AEFA3648
          D0FF374AD3FF3A4ED5FF3234B4FF8A7FB9FFF6ECE7FFF5ECE6FFF4EBE5FFF6EB
          E5FF897DB8FF3233B4FF384BD3FF3547D2FF3446D1FF3E37AEFA453FB4FA4557
          D7FF3B50D5FF4C5FDAFF4343B7FF9189C7FFF7EFE9FFF6EEE9FFF6EFE8FFF7ED
          E8FF9087C5FF4242B7FF495DD8FF394CD4FF3F52D4FF443FB3FA403DA1DC5967
          DAFF5B6EDDFF4F4DBAFF8F89CAFFFBF6F4FFF7F1ECFFEDE1D9FFEDE0D9FFF7F0
          EAFFFAF5F2FF8F89CAFF4E4DB9FF576ADCFF5765D9FF403EA4E12E2D70987C85
          DDFF8798E8FF291D9BFFE5DADEFFF6EEEBFFEDDFDAFF816EA9FF816EA9FFEDDF
          D8FFF4ECE7FFE5D9DCFF291D9BFF8494E7FF7A81DDFF33317BAC111125356768
          D0FC9EACEDFF686FCEFF5646A1FFCCB6BCFF7A68A8FF4C4AB6FF4D4BB7FF7A68
          A8FFCBB5BCFF5646A1FF666DCCFF9BAAEEFF696CD0FD1212273F000000043B3B
          79977D84DFFFA5B6F1FF6D74D0FF2D219BFF5151B9FF8EA2ECFF8EA1ECFF5252
          BBFF2D219BFF6B72D0FFA2B3F0FF8086E0FF404183A700000008000000010303
          050C4E509DBC8087E2FFAEBDF3FFA3B6F1FF9DAFF0FF95A9EEFF95A8EEFF9BAD
          EFFFA2B3F0FFACBCF3FF838AE3FF4F52A0C10303051100000002000000000000
          000100000005323464797378D9F8929CEAFFA1AEEFFFB0BFF3FFB0BFF4FFA2AE
          EFFF939DE9FF7479DAF83234647D000000080000000200000000000000000000
          000000000000000000031213232D40437D935D61B5D07378DFFC7378DFFC5D61
          B5D040437D951212223000000004000000010000000000000000}
        TabOrder = 1
      end
    end
    object AdvFileNameEdit1: TAdvFileNameEdit
      Left = 8
      Top = 22
      Width = 620
      Height = 21
      OnValueValidate = AdvFileNameEdit1ValueValidate
      DefaultHandling = True
      EmptyTextStyle = []
      LabelCaption = 'Location of Whitmore Access file:'
      LabelPosition = lpTopLeft
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
      Anchors = [akLeft, akTop, akRight]
      Color = clWindow
      TabOrder = 0
      Visible = True
      Version = '1.5.0.2'
      ButtonStyle = bsButton
      ButtonWidth = 18
      Flat = False
      Etched = False
      Glyph.Data = {
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
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFDFDFDFDFD
        FDFDFDFDFDFDFDFDFDFDB7B76F67676767676767676767B7FDFD6FFDBFBFBFBF
        BFBFBFBFBFB7FD6FFDFD6FFDBFBFBFBFBF7F7F7F7777FD6FFDFD6FFDBFBFBFBF
        BFBFBFBF7F7FFD6FFDFD6FFDFDFDBFBFBFBFBFBFBF7FFD6FFDFD6FFDFDFDFD08
        070707B6B6B6096FE3EC6FFDB76F6FAFFDFDFDFDFDFDFD6FFDE36FFDBFBFBFED
        B76F6F6F6F6F6F6FFDE377FDBFBFBF09FD09FD09FDFDFDFDFDE377FDFDFDFD09
        FD09090909090909FDE377B7B7B7B709FD09FD09FDFDFDFDFDE3FDFDFDFDFD09
        FD09090909090909FDEBFDFDFDFDFD09FDFDFDFDFDFDFDFDFDEBFDFDFDFDFD09
        FDBDBDB5B4B4B4B4FDEBFDFDFDFDFDFD0909090909ECECECEC09}
      ReadOnly = False
      Filter = 'Access files (*.mdb)|*.mdb'
      FilterIndex = 0
      DialogOptions = []
      DialogKind = fdOpen
    end
    object CheckBox1: TCheckBox
      Left = 432
      Top = 53
      Width = 121
      Height = 17
      Caption = 'Show Removed Sites'
      TabOrder = 2
    end
    object CheckBox2: TCheckBox
      Left = 564
      Top = 53
      Width = 97
      Height = 17
      Caption = 'ENA Only'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
  end
  object AdvColumnGrid1: TAdvColumnGrid
    Left = 0
    Top = 80
    Width = 636
    Height = 269
    Cursor = crDefault
    Align = alClient
    ColCount = 3
    DrawingStyle = gdsClassic
    FixedCols = 0
    ScrollBars = ssBoth
    TabOrder = 1
    HoverRowCells = [hcNormal, hcSelected]
    OnClickSort = AdvColumnGrid1ClickSort
    OnCheckBoxClick = AdvColumnGrid1CheckBoxClick
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ColumnHeaders.Strings = (
      'Get'
      'Author'
      'Citation')
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
      'Larger than'
      'Smaller than'
      'Clear')
    FixedColWidth = 36
    FixedRowHeight = 22
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
    SortSettings.Show = True
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
        Header = 'Get'
        HeaderAlignment = taCenter
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = clNavy
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = []
        MinSize = 36
        MaxSize = 36
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
        Header = 'Author'
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
        Color = clWindow
        ColumnPopupType = cpFixedCellsRClick
        DropDownCount = 8
        EditLength = 0
        Editor = edMemoDropDown
        FilterCaseSensitive = False
        Fixed = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Header = 'Citation'
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
        Width = 416
      end>
    ExplicitLeft = 224
    ExplicitTop = 88
    ExplicitWidth = 400
    ExplicitHeight = 250
    ColWidths = (
      36
      180
      416)
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 536
    Top = 72
  end
  object ADODataSet1: TADODataSet
    Connection = ADOConnection1
    Parameters = <>
    Prepared = True
    Left = 576
    Top = 72
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'SampleID'
        DataType = ftInteger
        Size = -1
        Value = Null
      end
      item
        Name = 'ID1'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE Whitmore SET Whitmore.NeotomaSampleID = :SampleID '
      'WHERE (((Whitmore.ID1)=:ID1));')
    Left = 576
    Top = 128
  end
end
