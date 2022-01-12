object FindPubForm: TFindPubForm
  Left = 0
  Top = 0
  Caption = 'Search for Publication'
  ClientHeight = 357
  ClientWidth = 552
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 338
    Width = 552
    Height = 19
    Panels = <>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 552
    Height = 65
    Align = alTop
    BorderStyle = bsSingle
    TabOrder = 1
    object FlowPanel1: TFlowPanel
      Left = 8
      Top = 12
      Width = 542
      Height = 41
      BevelOuter = bvNone
      TabOrder = 0
      DesignSize = (
        542
        41)
      object Label1: TLabel
        Left = 0
        Top = 0
        Width = 161
        Height = 15
        AutoSize = False
        Caption = 'Search Field:'
      end
      object Label2: TLabel
        Left = 161
        Top = 0
        Width = 330
        Height = 15
        AutoSize = False
        Caption = 'Search String (use % for wildcard):'
      end
      object ComboBox1: TComboBox
        Left = 0
        Top = 15
        Width = 161
        Height = 21
        ItemIndex = 0
        TabOrder = 0
        Text = 'Author'#39's Family Name'
        Items.Strings = (
          'Author'#39's Family Name'
          'Citation'
          'PublicationID')
      end
      object Edit1: TEdit
        Left = 161
        Top = 15
        Width = 330
        Height = 21
        TabOrder = 2
        OnChange = Edit1Change
      end
      object cxButton4: TcxButton
        AlignWithMargins = True
        Left = 491
        Top = 15
        Width = 26
        Height = 21
        Margins.Left = 0
        Margins.Top = 0
        Margins.Right = 0
        Margins.Bottom = 0
        Anchors = [akTop, akRight]
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton4Click
      end
    end
    object cxMemo2: TcxMemo
      Left = 416
      Top = -3
      Properties.ReadOnly = True
      Style.BorderStyle = ebsSingle
      Style.Color = clBtnFace
      StyleFocused.BorderStyle = ebsSingle
      TabOrder = 1
      Visible = False
      Height = 27
      Width = 141
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 65
    Width = 552
    Height = 227
    Align = alClient
    BorderStyle = bsSingle
    TabOrder = 2
    object AdvColumnGrid1: TAdvColumnGrid
      Left = 1
      Top = 21
      Width = 546
      Height = 201
      Cursor = crDefault
      Align = alClient
      ColCount = 3
      Ctl3D = True
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
      ParentCtl3D = False
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 0
      OnMouseMove = AdvColumnGrid1MouseMove
      HoverRowCells = [hcNormal, hcSelected]
      OnGetEditorProp = AdvColumnGrid1GetEditorProp
      OnCheckBoxClick = AdvColumnGrid1CheckBoxClick
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ColumnHeaders.Strings = (
        ''
        'ID'
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
      ControlLook.FlatButton = True
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
      FixedColWidth = 24
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
      MouseActions.DirectEdit = True
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
          Editor = edCheckBox
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
          Width = 24
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
          Header = 'ID'
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
          EditLink = FormControlEditLink1
          Editor = edCustom
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
          Width = 458
        end>
      ExplicitTop = 27
      ExplicitWidth = 556
      ExplicitHeight = 211
      ColWidths = (
        24
        60
        458)
      object AdvControlDropDown1: TAdvControlDropDown
        Left = 392
        Top = 72
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
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 546
      Height = 20
      Align = alTop
      BevelOuter = bvNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 292
    Width = 552
    Height = 46
    Align = alBottom
    BorderStyle = bsSingle
    TabOrder = 3
    object cxButton1: TcxButton
      Left = 8
      Top = 8
      Width = 153
      Height = 25
      Caption = 'Add New Publication'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
        F6070000424DF60700000000000036000000280000001F000000100000000100
        200000000000C007000000000000000000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFF5F5F5FFDADADAFFCCCCCCFFCCCCCCFFCCCCCCFFCCCC
        CCFFDADADAFFF5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFDDDDDDFFA3C0B3FF369D6EFF008C4BFF008B4AFF008B4AFF008C4BFF369D
        6EFFA3C0B3FFE1E1E1FFFFFFFFFFFFFFFFFFA4A0A0FFC0C0C0FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FFFFFFFFFFFFFFFFFFFFFF
        FFFF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1FF44A2
        77FF009050FF01A169FF00AA76FF00AB77FF00AB77FF00AA76FF01A169FF0090
        50FF55A882FFE1E1E1FFFFFFFFFFC0C0C0FF806060FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFC0C0C0FF806060FF80A0A0FFFFFFFFFFFFFFFFFFC0C0
        C0FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFF5F5F5FF55A882FF009152FF02AC
        77FF00C38CFF00D699FF18DEA8FF18DEA8FF00D699FF00C38CFF01AB76FF0092
        53FF55A882FFF5F5F5FFFFFFFFFFC0C0C0FF8060A0FFC0C0C0FFC0C0C0FFC0C0
        C0FF806060FFA4A0A0FF806060FF8060A0FFA4A0A0FFFFFFFFFFC0C0C0FFA4A0
        A0FF404040FFA4A0A0FFFFFFFFFFAECABEFF009051FF0FB483FF02D299FF00D6
        9BFF00D193FFFFFFFFFFFFFFFFFF00D193FF00D69BFF00D198FF01AB76FF0090
        50FFAECBBEFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0A0FFA4A0A0FFA4A0
        A0FF404040FF80A0A0FFA4A0A0FFA4A0A0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
        A0FF806060FFFFFFFFFF369D6CFF16AB78FF11C997FF00D49AFF00D297FF00CD
        8EFFFFFFFFFFFFFFFFFF00CD8EFF00D297FF00D59BFF00C18CFF01A169FF369E
        6EFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FF406060FF8060A0FF806060FF8060
        60FF404060FFA4A0A0FFA4A0A0FFC0C0C0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
        60FFFFFFFFFF008A48FF38C49CFF00D198FF00CD92FF00CB8EFF00C787FFFFFF
        FFFFFFFFFFFF00C787FF00CB8EFF00CE93FF00D09AFF00AB76FF008C4BFFFFFF
        FFFFFFFFFFFFFFFFFFFF806060FF8060A0FF406060FF8060A0FF406060FF8060
        60FF806060FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8060A0FFFFFF
        FFFF008946FF51D2AFFF12D4A3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF00CF97FF00AD78FF008B4AFFFFFFFFFFFFFF
        FFFFA4A0A0FF806060FF404060FF806060FF404060FF406060FF406060FFC0C0
        C0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80C0C0FFFFFFFFFF0088
        45FF66DDBEFF10D0A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF00CD97FF00AD78FF008B4AFFFFFFFFFFFFFFFFFFA4A0
        A0FF406060FF806060FF404040FF806060FF406060FF80A0A0FF806060FF8060
        A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FFFFFFFFFF008846FF76E0
        C5FF00CA98FF00C590FF00C48EFF00C187FFFFFFFFFFFFFFFFFF00C187FF00C4
        8EFF00C793FF00CB99FF00AB76FF008C4BFFFFFFFFFFFFFFFFFFA4A0A0FF4060
        60FF404040FF404040FF404040FF806060FF404060FF8060A0FF806060FFA4A0
        A0FFC0C0C0FFFFFFFFFFC0C0C0FFA4A0A0FFFFFFFFFF41A675FF59C9A4FF49DE
        BCFF00C794FF00C794FF00C38EFFFFFFFFFFFFFFFFFF00C38EFF00C896FF00CB
        9AFF06C190FF00A168FF40A878FFFFFFFFFFFFFFFFFFFFFFFFFF806060FF4060
        60FF004040FF406060FF406060FF806060FF806060FFA4A0A0FF806060FFA4A0
        A0FFFFFFFFFFC0C0C0FFC0C0C0FFFFFFFFFFCCE8DBFF0A9458FFADF8E9FF18D0
        A7FF00C494FF00C290FFFFFFFFFFFFFFFFFF00C391FF00C799FF05C89BFF18B7
        87FF009050FFCCE8DBFFFFFFFFFFFFFFFFFFC0C0C0FF8060A0FF404040FF4040
        60FF004040FF406060FF406060FF80A0A0FF806060FFA4A0A0FF80A0A0FFA4A0
        A0FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFF55B185FF199C63FFBCFFF7FF5DE4
        C9FF00C397FF00BF90FF00C091FF00C498FF22CAA2FF31C297FF039355FF6ABC
        96FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF806060FF406060FF404060FF4060
        60FF404060FF806060FF806060FFA4A0A0FF8060A0FFA4A0A0FF80C0C0FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6ABB94FF0E9659FF74D5B6FF9FF3
        E0FF92EFDAFF79E5CAFF5DD6B5FF2EB586FF039152FF55B288FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FF80A0A0FF404040FF4060
        60FF404040FF406060FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCE8DBFF44A877FF008744FF0087
        43FF008744FF008946FF44AA7AFFCCE8DBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FF406060FF4060
        60FF404040FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0
        A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 234
      Top = 8
      Width = 65
      Height = 25
      Caption = 'Use'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      OptionsImage.ImageIndex = 1
      OptionsImage.Images = cxImageList1
      TabOrder = 1
      OnClick = cxButton2Click
    end
    object cxButton3: TcxButton
      Left = 300
      Top = 8
      Width = 65
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      OptionsImage.ImageIndex = 2
      OptionsImage.Images = cxImageList1
      TabOrder = 2
    end
  end
  object cxMemo1: TcxMemo
    Left = 175
    Top = 162
    Properties.ReadOnly = False
    Properties.ScrollBars = ssVertical
    Style.BorderColor = clSilver
    Style.BorderStyle = ebsSingle
    Style.LookAndFeel.Kind = lfUltraFlat
    StyleDisabled.LookAndFeel.Kind = lfUltraFlat
    StyleFocused.LookAndFeel.Kind = lfUltraFlat
    StyleHot.LookAndFeel.Kind = lfUltraFlat
    TabOrder = 4
    Height = 41
    Width = 106
  end
  object TcpClient1: TTcpClient
    Left = 392
    Top = 8
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
    Left = 328
    Top = 160
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 19399104
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000AB7E62FFA477
          5AFF955F3FFF8E5739FF7E4020FF7E4020FF000000000000000000000000AB7E
          62FFA4775AFF955F3FFF8E5739FF7E4020FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF6F4324FFAB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF00000000DDC5A9FFAB7E
          62FFECD8CDFFECD8CDFFCAA089FFAC7655FF7E4020FF9F6B4EFFAB7E62FFECD8
          CDFFECD8CDFFCAA089FFAC7655FF7E4020FF906060FF0000000000000000AB7E
          62FFFFFFFFFFF1E8E5FFEED2C1FFAC7655FF7E4020FFC89890FFAB7E62FFFFFF
          FFFFF1E8E5FFEED2C1FFAC7655FF906060FF0000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF7E4020FF9F6B4EFFAB7E62FF9F6B
          4EFF955F3FFF7E4020FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FFFCFAFAFFDEC3B1FFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFDEC3B1FFAC7655FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF9F6B4EFF00000000AB7E62FF9F6B
          4EFF955F3FFF7E4020FF9F6B4EFF000000000000000000000000000000000000
          000000000000AB7E62FFFCFAFAFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFF7E4020FF00000000000000000000000000000000000000000000
          000000000000AB7E62FFAB7E62FF9F6B4EFF000000000000000000000000AB7E
          62FFAB7E62FF9F6B4EFF00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000A000000250000003300000033000000330000
          0033000000250000000A00000000000000000000000000000000000000000000
          00000000000000000022001D105C006738C9008C4BFF008B4AFF008B4AFF008C
          4BFF006738C9001D105C0000001E000000000000000000000000000000000000
          00000000001E005E33BB009050FF01A169FF01AB76FF01AC79FF01AC79FF01AB
          76FF01A169FF009050FF00532DAA0000001E0000000000000000000000000000
          000A00532DAA009152FF02AC77FF00C38CFF00D79BFF00DA9CFF00DA9CFF00D7
          9CFF01C38CFF01AB76FF009253FF00532DAA0000000A0000000000000000001C
          1051009051FF0FB483FF00D298FF00D598FF00D192FF00CF90FF00D091FF00D3
          96FF00D69BFF00D198FF01AB76FF009050FF001D105100000000000000000067
          36C916AB78FF10C996FF00D397FF00CD8CFFFFFFFFFFFFFFFFFFFFFFFFFF00CC
          8CFF00D195FF00D59BFF01C18CFF01A169FF006838C90000000000000000008A
          48FF39C49DFF00D198FF00CB8CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF00CA8CFF00CF96FF00D29BFF01AB76FF008C4BFF00000000000000000089
          46FF52D2B0FF00CC92FFFFFFFFFFFFFFFFFFFFFFFFFF00C484FFFFFFFFFFFFFF
          FFFFFFFFFFFF00C88DFF00D09AFF00AD79FF008B4AFF00000000000000000088
          45FF68DDBEFF00C991FFFFFFFFFFFFFFFFFF00C68CFF00C891FF00C58BFFFFFF
          FFFFFFFFFFFFFFFFFFFF00CC96FF00AD78FF008B4AFF00000000000000000088
          46FF76E0C6FF00CB98FF00C590FF00C691FF00C895FF00C997FF00C894FF00C3
          8CFFFFFFFFFFFFFFFFFF00C792FF00AB75FF008C4BFF00000000000000000065
          34BE59C9A4FF49DEBCFF00C794FF00C897FF00C998FF00C999FF00C998FF00C7
          94FF00C38EFFFFFFFFFF00BD8AFF00A067FF006838BF0000000000000000001C
          0F330A9458FFADF8E9FF18D0A7FF00C495FF00C697FF00C698FF00C798FF00C7
          98FF00C697FF00C596FF12B585FF008F50FF001C0F3300000000000000000000
          0000005C30AA199C63FFBCFFF7FF5EE4C9FF00C59AFF00C396FF00C497FF00C5
          9AFF22CAA2FF2FC196FF029355FF00522C950000000000000000000000000000
          00000000000000512A950E9659FF74D5B6FFA0F4E1FF94EFDCFF7CE6CCFF5ED6
          B5FF2EB587FF039152FF005D33AA000000000000000000000000000000000000
          00000000000000000000001C0F33006433BB008744FF008743FF008744FF0089
          46FF006636BB001C0F3300000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
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
    Left = 472
    Top = 8
  end
end
