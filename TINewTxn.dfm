object NewTaxonForm: TNewTaxonForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'New Taxon'
  ClientHeight = 566
  ClientWidth = 834
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
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 224
    Top = 0
    Height = 354
    ExplicitHeight = 100
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 354
    Width = 834
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    Visible = False
    ExplicitTop = 372
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 547
    Width = 834
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 224
    Height = 354
    Align = alLeft
    BorderStyle = bsSingle
    TabOrder = 0
    object Panel6: TPanel
      Left = 1
      Top = 42
      Width = 218
      Height = 63
      Align = alTop
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      TabOrder = 0
      object AdvMultiColumnDropDown1: TAdvMultiColumnDropDown
        Left = 4
        Top = 24
        Width = 205
        Height = 21
        DropDownRowHeight = 20
        LineColor = 15855083
        FixedLineColor = 13745060
        Columns = <
          item
            Width = 36
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Header = 'ID'
          end
          item
            Width = 160
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Header = 'Taxa Group'
          end>
        HeaderColor = clWhite
        HeaderColorTo = clSilver
        HeaderHeight = 25
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = 7485192
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = []
        LookupColumn = 1
        Items = <>
        ItemIndex = -1
        Ctl3D = True
        ParentCtl3D = False
        DropDownBorderColor = clNone
        DropDownHeight = 290
        EditorEnabled = False
        LabelCaption = 'Select Taxa Group'
        LabelPosition = lpTopLeft
        LabelMargin = 3
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        Version = '1.4.5.7'
        SelectionColor = 14155773
        SelectionColorTo = 5821692
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
        DropDownHeader.Font.Charset = DEFAULT_CHARSET
        DropDownHeader.Font.Color = 7485192
        DropDownHeader.Font.Height = -11
        DropDownHeader.Font.Name = 'Tahoma'
        DropDownHeader.Font.Style = []
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
        DropDownFooter.Buttons = <>
        TabOrder = 0
        OnSelect = AdvMultiColumnDropDown1Select
        SelectionColorStyle = 1
        TMSStyle = 4
      end
    end
    object Panel7: TPanel
      Left = 1
      Top = 1
      Width = 218
      Height = 41
      Align = alTop
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      TabOrder = 2
      object cxTextEdit1: TcxTextEdit
        Left = 4
        Top = 8
        ParentFont = False
        Properties.ReadOnly = True
        Style.BorderColor = clWindowFrame
        Style.BorderStyle = ebsFlat
        Style.Color = clBtnFace
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clHotLight
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.LookAndFeel.Kind = lfFlat
        Style.Shadow = True
        Style.TextColor = clBlue
        Style.TransparentBorder = True
        Style.IsFontAssigned = True
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 0
        Width = 206
      end
    end
    object Panel8: TPanel
      Left = 1
      Top = 105
      Width = 218
      Height = 106
      Align = alTop
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      TabOrder = 3
      Visible = False
      object Label2: TLabel
        Left = 4
        Top = 4
        Width = 86
        Height = 13
        Caption = 'Insert New Taxon'
      end
      object cxRadioButton1: TcxRadioButton
        Left = 4
        Top = 24
        Width = 76
        Height = 17
        Caption = 'As Child'
        TabOrder = 0
        OnClick = cxRadioButton1Click
        LookAndFeel.Kind = lfStandard
      end
      object cxRadioButton2: TcxRadioButton
        Left = 4
        Top = 47
        Width = 76
        Height = 17
        Caption = 'As Sibling'
        TabOrder = 1
        OnClick = cxRadioButton2Click
        LookAndFeel.Kind = lfStandard
      end
      object cxButton1: TcxButton
        Left = 5
        Top = 70
        Width = 68
        Height = 25
        Caption = 'Insert'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          2E020000424D2E0200000000000036000000280000000C0000000E0000000100
          180000000000F8010000C40E0000C40E00000000000000000000D8D8D8D8D8D8
          D8D8D8D8D8D8CF98087F5B00D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D87F5B00CF98087F5B00D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00F6CB97CF98087F5B00D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00F6CB97F6CB97CF98087F5B
          00D8D8D8D8D8D8D8D8D8CF98087F5B007F5B007F5B007F5B00F6CB97F6CB97F6
          CB97CF98087F5B00D8D8D8D8D8D87F5B00F6CB97F6CB97F6CB97F6CB97F6CB97
          F6CB97F6CB97F6CB97CF98087F5B00D8D8D87F5B00F6CB97F6CB97F6CB97F6CB
          97F6CB97F6CB97F6CB97F6CB97F6CB97CF98087F5B007F5B00F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF98087F5B00FFF3D5
          FFF3D5FFF3D5FFF3D5FFF3D5F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8CF98
          08CF9808CF9808CF98087F5B00FFF3D5F6CB97F6CB97FFF3D5CF9808D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5F6CB97FFF3D5CF9808D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5FFF3D5CF9808D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5CF9808D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8}
        OptionsImage.Layout = blGlyphRight
        TabOrder = 2
        OnClick = cxButton1Click
      end
    end
    object Panel9: TPanel
      Left = 1
      Top = 211
      Width = 218
      Height = 138
      Align = alClient
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      TabOrder = 1
      Visible = False
      object Label3: TLabel
        Left = 4
        Top = 4
        Width = 62
        Height = 13
        Caption = 'Insert Taxon'
      end
      object cxRadioButton3: TcxRadioButton
        Left = 4
        Top = 56
        Width = 76
        Height = 17
        Caption = 'As Child'
        Enabled = False
        TabOrder = 0
        OnClick = cxRadioButton3Click
        LookAndFeel.Kind = lfStandard
      end
      object cxRadioButton4: TcxRadioButton
        Left = 4
        Top = 79
        Width = 76
        Height = 17
        Caption = 'As Sibling'
        Enabled = False
        TabOrder = 1
        OnClick = cxRadioButton4Click
        LookAndFeel.Kind = lfStandard
      end
      object cxButton4: TcxButton
        Left = 5
        Top = 102
        Width = 68
        Height = 25
        Caption = 'Insert'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          2E020000424D2E0200000000000036000000280000000C0000000E0000000100
          180000000000F8010000C40E0000C40E00000000000000000000D8D8D8D8D8D8
          D8D8D8D8D8D8CF98087F5B00D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D87F5B00CF98087F5B00D8D8D8D8D8D8D8D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00F6CB97CF98087F5B00D8D8D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00F6CB97F6CB97CF98087F5B
          00D8D8D8D8D8D8D8D8D8CF98087F5B007F5B007F5B007F5B00F6CB97F6CB97F6
          CB97CF98087F5B00D8D8D8D8D8D87F5B00F6CB97F6CB97F6CB97F6CB97F6CB97
          F6CB97F6CB97F6CB97CF98087F5B00D8D8D87F5B00F6CB97F6CB97F6CB97F6CB
          97F6CB97F6CB97F6CB97F6CB97F6CB97CF98087F5B007F5B00F6CB97F6CB97F6
          CB97F6CB97F6CB97F6CB97F6CB97F6CB97F6CB97FFF3D5CF98087F5B00FFF3D5
          FFF3D5FFF3D5FFF3D5FFF3D5F6CB97F6CB97F6CB97FFF3D5CF9808D8D8D8CF98
          08CF9808CF9808CF98087F5B00FFF3D5F6CB97F6CB97FFF3D5CF9808D8D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5F6CB97FFF3D5CF9808D8D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5FFF3D5CF9808D8D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00FFF3D5CF9808D8
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D87F5B00CF9808
          D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8}
        OptionsImage.Layout = blGlyphRight
        TabOrder = 2
        OnClick = cxButton4Click
      end
      object cxTextEdit2: TcxTextEdit
        Left = 4
        Top = 24
        Properties.ReadOnly = False
        Properties.OnChange = cxTextEdit2PropertiesChange
        Style.BorderStyle = ebsFlat
        Style.Color = clWindow
        Style.LookAndFeel.Kind = lfFlat
        Style.TransparentBorder = True
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 3
        Width = 206
      end
    end
  end
  object Panel3: TPanel
    Left = 227
    Top = 0
    Width = 607
    Height = 354
    Align = alClient
    BorderStyle = bsSingle
    TabOrder = 1
    Visible = False
    DesignSize = (
      603
      350)
    object dxTreeView1: TdxTreeView
      Left = 1
      Top = 42
      Width = 601
      Height = 307
      ShowNodeHint = True
      OnCustomDraw = dxTreeView1CustomDraw
      DeletingConfirmationMessage = 'Do you want to delete the item "%s"'
      ReadOnly = True
      HideSelection = False
      Indent = 19
      OnChange = dxTreeView1Change
      Align = alClient
      ParentColor = False
      ParentCtl3D = False
      Ctl3D = False
      Options = [trConfirmDelete]
      SelectedIndex = -1
      SortType = stText
      TabOrder = 0
      PopupMenu = PopupMenu1
      IsConfirmationAssigned = True
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 601
      Height = 41
      Align = alTop
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      TabOrder = 1
      object FlowPanel1: TFlowPanel
        Left = 8
        Top = 8
        Width = 318
        Height = 24
        AutoSize = True
        AutoWrap = False
        BevelOuter = bvNone
        TabOrder = 0
        DesignSize = (
          318
          24)
        object Label1: TLabel
          AlignWithMargins = True
          Left = 0
          Top = 3
          Width = 37
          Height = 13
          Margins.Left = 0
          Margins.Right = 2
          Alignment = taRightJustify
          Caption = 'Search:'
        end
        object cxComboBox1: TcxComboBox
          AlignWithMargins = True
          Left = 39
          Top = 0
          Margins.Left = 0
          Margins.Top = 0
          Margins.Right = 0
          Margins.Bottom = 0
          Properties.DropDownRows = 12
          Properties.DropDownSizeable = True
          Properties.OnChange = cxComboBox1PropertiesChange
          Style.BorderStyle = ebs3D
          Style.LookAndFeel.Kind = lfStandard
          Style.LookAndFeel.NativeStyle = False
          Style.ButtonStyle = btsDefault
          StyleDisabled.LookAndFeel.Kind = lfStandard
          StyleDisabled.LookAndFeel.NativeStyle = False
          StyleFocused.LookAndFeel.Kind = lfStandard
          StyleFocused.LookAndFeel.NativeStyle = False
          StyleHot.LookAndFeel.Kind = lfStandard
          StyleHot.LookAndFeel.NativeStyle = False
          TabOrder = 0
          OnKeyPress = cxComboBox1KeyPress
          Width = 250
        end
        object cxButton2: TcxButton
          AlignWithMargins = True
          Left = 289
          Top = 0
          Width = 26
          Height = 21
          Margins.Left = 0
          Margins.Top = 0
          Anchors = [akTop, akRight]
          Enabled = False
          LookAndFeel.Kind = lfOffice11
          OptionsImage.ImageIndex = 9
          OptionsImage.Images = cxImageList1
          TabOrder = 1
          OnClick = cxButton2Click
        end
      end
    end
    object Panel10: TPanel
      Left = 216
      Top = 242
      Width = 138
      Height = 70
      Anchors = []
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 2
      Visible = False
      object cxTextEdit3: TcxTextEdit
        Left = 0
        Top = 24
        Properties.OnChange = cxTextEdit3PropertiesChange
        Style.BorderStyle = ebsFlat
        Style.LookAndFeel.Kind = lfFlat
        Style.Shadow = False
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 0
        Width = 138
      end
      object cxLabel1: TcxLabel
        Left = 0
        Top = 0
        Align = alTop
        AutoSize = False
        Caption = 'Code is Unique!'
        ParentFont = False
        Style.BorderStyle = ebsNone
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clGreen
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        Properties.Alignment.Horz = taCenter
        Visible = False
        Height = 17
        Width = 138
        AnchorX = 69
      end
      object FlowPanel3: TFlowPanel
        Left = 0
        Top = 47
        Width = 138
        Height = 23
        Align = alBottom
        AutoWrap = False
        BevelOuter = bvNone
        BorderWidth = 3
        Color = 15984090
        ParentBackground = False
        ShowCaption = False
        TabOrder = 2
        object cxButton11: TcxButton
          Left = 3
          Top = 3
          Width = 32
          Height = 17
          Caption = 'Auto'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton11Click
        end
        object cxButton12: TcxButton
          Left = 35
          Top = 3
          Width = 32
          Height = 17
          Caption = 'Test'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          Enabled = False
          LookAndFeel.Kind = lfOffice11
          TabOrder = 1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton12Click
        end
        object cxButton13: TcxButton
          Left = 67
          Top = 3
          Width = 32
          Height = 17
          Caption = 'Ok'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 2
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton13Click
        end
        object cxButton14: TcxButton
          Left = 99
          Top = 3
          Width = 36
          Height = 17
          Caption = 'Cancel'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton14Click
        end
      end
    end
    object Panel11: TPanel
      Left = 216
      Top = 104
      Width = 150
      Height = 121
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 3
      Visible = False
      DesignSize = (
        150
        121)
      object cxComboBox2: TcxComboBox
        Left = 4
        Top = 21
        Anchors = [akLeft, akTop, akRight]
        Properties.DropDownListStyle = lsFixedList
        Properties.DropDownSizeable = True
        Properties.Sorted = True
        Style.LookAndFeel.Kind = lfFlat
        Style.LookAndFeel.NativeStyle = False
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleDisabled.LookAndFeel.NativeStyle = False
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.NativeStyle = False
        StyleHot.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.NativeStyle = False
        TabOrder = 0
        OnClick = cxComboBox2Click
        Width = 142
      end
      object cxLabel2: TcxLabel
        Left = 4
        Top = 4
        Caption = 'Set:'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.IsFontAssigned = True
      end
      object cxButton7: TcxButton
        Left = 96
        Top = 2
        Width = 49
        Height = 17
        Caption = 'Show All'
        Colors.DefaultText = clNavy
        Colors.NormalText = clNavy
        Colors.HotText = clBlue
        Colors.PressedText = clOlive
        LookAndFeel.Kind = lfOffice11
        TabOrder = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = cxButton7Click
      end
      object cxButton8: TcxButton
        Left = 96
        Top = 53
        Width = 49
        Height = 17
        Caption = 'Show All'
        Colors.DefaultText = clNavy
        Colors.NormalText = clNavy
        Colors.HotText = clBlue
        Colors.PressedText = clOlive
        LookAndFeel.Kind = lfOffice11
        TabOrder = 3
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = cxButton8Click
      end
      object FlowPanel4: TFlowPanel
        Left = 0
        Top = 98
        Width = 150
        Height = 23
        Align = alBottom
        AutoWrap = False
        BevelOuter = bvNone
        BorderWidth = 3
        Color = 15984090
        ParentBackground = False
        ShowCaption = False
        TabOrder = 4
        object cxButton19: TcxButton
          Left = 3
          Top = 3
          Width = 36
          Height = 17
          Caption = 'Add'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          Colors.DisabledText = clGray
          LookAndFeel.Kind = lfOffice11
          TabOrder = 1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton19Click
        end
        object cxButton20: TcxButton
          Left = 39
          Top = 3
          Width = 36
          Height = 17
          Caption = 'Delete'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          Colors.DisabledText = clGray
          LookAndFeel.Kind = lfOffice11
          TabOrder = 2
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton20Click
        end
        object cxButton18: TcxButton
          Left = 75
          Top = 3
          Width = 36
          Height = 17
          Caption = 'Close'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton18Click
        end
      end
      object cxPopupEdit1: TcxPopupEdit
        Left = 4
        Top = 72
        Properties.PopupClientEdge = True
        Properties.PopupControl = Panel13
        Properties.OnChange = cxPopupEdit1PropertiesChange
        Style.LookAndFeel.Kind = lfFlat
        Style.PopupBorderStyle = epbsFlat
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 5
        Width = 142
      end
      object cxLabel4: TcxLabel
        Left = 4
        Top = 55
        Caption = 'Group:'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.IsFontAssigned = True
      end
    end
    object Panel13: TPanel
      Left = 372
      Top = 200
      Width = 209
      Height = 152
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 4
      Visible = False
      object AdvColumnGrid2: TAdvColumnGrid
        Left = 0
        Top = 0
        Width = 209
        Height = 131
        Cursor = crDefault
        Align = alClient
        ColCount = 2
        DefaultRowHeight = 18
        DrawingStyle = gdsClassic
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
        ScrollBars = ssBoth
        TabOrder = 0
        ActiveRowShow = True
        ActiveRowColor = 15387318
        HoverRow = True
        HoverRowCells = [hcNormal, hcSelected]
        OnClickCell = AdvColumnGrid2ClickCell
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        ActiveCellColor = 15387318
        ColumnHeaders.Strings = (
          'Code'
          'Name')
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
            HeaderFont.Color = clNavy
            HeaderFont.Height = -11
            HeaderFont.Name = 'Tahoma'
            HeaderFont.Style = []
            MinSize = 40
            MaxSize = 0
            Name = 'Code'
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
            Header = 'Name'
            HeaderAlignment = taCenter
            HeaderFont.Charset = DEFAULT_CHARSET
            HeaderFont.Color = clNavy
            HeaderFont.Height = -11
            HeaderFont.Name = 'Tahoma'
            HeaderFont.Style = []
            MinSize = 0
            MaxSize = 0
            Name = 'Name'
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
            Width = 170
          end>
        ColWidths = (
          35
          170)
      end
      object FlowPanel5: TFlowPanel
        Left = 0
        Top = 131
        Width = 209
        Height = 21
        Align = alBottom
        AutoWrap = False
        BevelOuter = bvNone
        Color = 15984090
        ParentBackground = False
        TabOrder = 1
        object cxButton15: TcxButton
          Left = 0
          Top = 0
          Width = 36
          Height = 17
          Caption = 'Cancel'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton15Click
        end
        object cxButton16: TcxButton
          Left = 36
          Top = 0
          Width = 36
          Height = 17
          Caption = 'New'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton16Click
        end
      end
    end
    object Panel5: TPanel
      Left = 8
      Top = 198
      Width = 209
      Height = 152
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 5
      Visible = False
      object AdvColumnGrid1: TAdvColumnGrid
        Left = 0
        Top = 0
        Width = 209
        Height = 131
        Cursor = crDefault
        Align = alClient
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
        OnClickCell = AdvColumnGrid1ClickCell
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
        FixedColWidth = 4
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
            Width = 4
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
            Width = 201
          end>
        ColWidths = (
          4
          201)
      end
      object FlowPanel2: TFlowPanel
        Left = 0
        Top = 131
        Width = 209
        Height = 21
        Align = alBottom
        AutoWrap = False
        BevelOuter = bvNone
        Color = 15984090
        ParentBackground = False
        TabOrder = 1
        object cxButton5: TcxButton
          Left = 0
          Top = 0
          Width = 36
          Height = 17
          Caption = 'Cancel'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          TabOrder = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton5Click
        end
        object cxButton10: TcxButton
          Left = 36
          Top = 0
          Width = 36
          Height = 17
          Hint = 'Add new Synonym Type to Neotoma'
          Caption = 'New'
          Colors.DefaultText = clNavy
          Colors.NormalText = clNavy
          Colors.HotText = clBlue
          Colors.PressedText = clOlive
          LookAndFeel.Kind = lfOffice11
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton10Click
        end
      end
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 357
    Width = 834
    Height = 190
    Align = alBottom
    BorderStyle = bsSingle
    TabOrder = 2
    Visible = False
    object cxGrid1: TcxGrid
      Left = 1
      Top = 32
      Width = 828
      Height = 153
      Align = alClient
      TabOrder = 0
      LookAndFeel.Kind = lfFlat
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'Lilian'
      OnFocusedViewChanged = cxGrid1FocusedViewChanged
      object cxGrid1TableView1: TcxGridTableView
        Navigator.Buttons.OnButtonClick = cxGrid1TableView1NavigatorButtonsButtonClick
        Navigator.Buttons.ConfirmDelete = True
        Navigator.Buttons.CustomButtons = <
          item
            Enabled = False
            Hint = 'Update taxon'
            ImageIndex = 8
          end>
        Navigator.Buttons.Images = cxImageList1
        Navigator.Buttons.First.Visible = True
        Navigator.Buttons.Prior.Visible = True
        Navigator.Buttons.Insert.Visible = False
        Navigator.Buttons.Append.Visible = False
        Navigator.Buttons.Delete.Enabled = False
        Navigator.Buttons.Delete.Visible = True
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Post.Visible = False
        Navigator.Buttons.Cancel.Visible = False
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.Visible = True
        OnEditing = cxGrid1TableView1Editing
        OnFocusedItemChanged = cxGrid1TableView1FocusedItemChanged
        OnFocusedRecordChanged = cxGrid1TableView1FocusedRecordChanged
        DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        DataController.OnDetailExpanding = cxGrid1TableView1DataControllerDetailExpanding
        OptionsBehavior.AlwaysShowEditor = True
        OptionsBehavior.CopyCaptionsToClipboard = False
        OptionsBehavior.FocusCellOnTab = True
        OptionsBehavior.FocusFirstCellOnNewRecord = True
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.NavigatorHints = True
        OptionsBehavior.FocusCellOnCycle = True
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnHiding = True
        OptionsCustomize.ColumnMoving = False
        OptionsData.Appending = True
        OptionsData.DeletingConfirmation = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsSelection.MultiSelect = True
        OptionsSelection.CellMultiSelect = True
        OptionsView.CellEndEllipsis = True
        OptionsView.ExpandButtonsForEmptyDetails = False
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.Content = cxStyle1
        Styles.Inactive = cxStyle1
        Styles.Header = cxStyle3
        Styles.Indicator = cxStyle4
        object txnID: TcxGridColumn
          Caption = 'ID'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 50
        end
        object txnCode: TcxGridColumn
          Caption = 'Code'
          PropertiesClassName = 'TcxPopupEditProperties'
          Properties.ImmediateDropDownWhenActivated = False
          Properties.PopupClientEdge = True
          Properties.PopupControl = Panel10
          Properties.PopupHeight = 100
          Properties.PopupMinHeight = 50
          Properties.PopupWidth = 140
          Properties.OnInitPopup = txnCodePropertiesInitPopup
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Styles.OnGetContentStyle = txnCodeStylesGetContentStyle
          Styles.Footer = cxStyle2
          Width = 100
        end
        object txnName: TcxGridColumn
          Caption = 'Name'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taLeftJustify
          Properties.BeepOnError = True
          Properties.UseLeftAlignmentOnEditing = False
          Properties.ValidateOnEnter = True
          Properties.OnValidate = txnNamePropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnNameStylesGetContentStyle
          Width = 160
        end
        object txnAuthor: TcxGridColumn
          Caption = 'Author'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taLeftJustify
          Properties.BeepOnError = True
          Properties.UseLeftAlignmentOnEditing = False
          Properties.ValidateOnEnter = True
          Properties.OnValidate = txnAuthorPropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnAuthorStylesGetContentStyle
          Width = 75
        end
        object txnHigherID: TcxGridColumn
          Caption = 'HigherID'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taRightJustify
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 50
        end
        object txnExtinct: TcxGridColumn
          Caption = 'Extinct'
          DataBinding.ValueType = 'Boolean'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.Alignment = taCenter
          Properties.ImmediatePost = True
          Properties.OnChange = txnExtinctPropertiesChange
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnExtinctStylesGetContentStyle
          Width = 40
        end
        object txnGroupID: TcxGridColumn
          Caption = 'GroupID'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taLeftJustify
          Properties.BeepOnError = True
          Properties.ReadOnly = True
          Properties.UseLeftAlignmentOnEditing = False
          Properties.ValidateOnEnter = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 50
        end
        object txnPubID: TcxGridColumn
          Caption = 'PubID'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Alignment.Horz = taRightJustify
          Properties.AutoSelect = False
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
              Stretchable = False
              Width = 16
            end>
          Properties.OnButtonClick = txnPubIDPropertiesButtonClick
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnPubIDStylesGetContentStyle
          Width = 40
        end
        object txnNotes: TcxGridColumn
          Caption = 'Notes'
          PropertiesClassName = 'TcxBlobEditProperties'
          Properties.BlobEditKind = bekMemo
          Properties.BlobPaintStyle = bpsText
          Properties.OnValidate = txnNotesPropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnNotesStylesGetContentStyle
          Width = 60
        end
        object txnEcolGroup: TcxGridColumn
          Caption = 'EcolGroup'
          PropertiesClassName = 'TcxPopupEditProperties'
          Properties.ImmediateDropDownWhenActivated = False
          Properties.PopupClientEdge = True
          Properties.PopupControl = Panel11
          Properties.PopupHeight = 112
          Properties.PopupWidth = 150
          Properties.OnCloseUp = txnEcolGroupPropertiesCloseUp
          Properties.OnInitPopup = txnEcolGroupPropertiesInitPopup
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = txnEcolGroupStylesGetContentStyle
          Width = 60
        end
        object txnValidator: TcxGridColumn
          Caption = 'Validator'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taRightJustify
          Properties.BeepOnError = True
          Properties.ReadOnly = True
          Properties.UseLeftAlignmentOnEditing = False
          Properties.ValidateOnEnter = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 50
        end
        object txnValidDate: TcxGridColumn
          Caption = 'ValidDate'
          DataBinding.ValueType = 'DateTime'
          PropertiesClassName = 'TcxDateEditProperties'
          Properties.DisplayFormat = 'yyyy-mm-dd'
          Properties.EditFormat = 'yyyy-mm-dd'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 60
        end
      end
      object cxGrid1TableView2: TcxGridTableView
        Navigator.Buttons.OnButtonClick = cxGrid1TableView2NavigatorButtonsButtonClick
        Navigator.Buttons.CustomButtons = <
          item
            Enabled = False
            Hint = 'Update synonym'
            ImageIndex = 8
          end>
        Navigator.Buttons.Images = cxImageList1
        Navigator.Buttons.Insert.Visible = False
        Navigator.Buttons.Append.Enabled = False
        Navigator.Buttons.Append.Visible = True
        Navigator.Buttons.Delete.Enabled = False
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Post.Visible = False
        Navigator.Buttons.Cancel.Visible = False
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.InfoPanel.Visible = True
        Navigator.Visible = True
        OnEditing = cxGrid1TableView2Editing
        OnFocusedRecordChanged = cxGrid1TableView2FocusedRecordChanged
        DataController.Options = [dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        DataController.OnAfterPost = cxGrid1TableView2DataControllerAfterPost
        OptionsBehavior.AlwaysShowEditor = True
        OptionsBehavior.CopyCaptionsToClipboard = False
        OptionsBehavior.FocusCellOnTab = True
        OptionsBehavior.FocusFirstCellOnNewRecord = True
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.NavigatorHints = True
        OptionsBehavior.FocusCellOnCycle = True
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsData.Appending = True
        OptionsData.DeletingConfirmation = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsSelection.MultiSelect = True
        OptionsSelection.CellMultiSelect = True
        OptionsView.CellEndEllipsis = True
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.Content = cxStyle1
        Styles.Header = cxStyle3
        Styles.Indicator = cxStyle3
        object syID: TcxGridColumn
          Caption = 'ID'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 50
        end
        object syCode: TcxGridColumn
          Caption = 'Code'
          PropertiesClassName = 'TcxPopupEditProperties'
          Properties.ImmediateDropDownWhenActivated = False
          Properties.PopupControl = Panel10
          Properties.OnInitPopup = syCodePropertiesInitPopup
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = syCodeStylesGetContentStyle
          Width = 100
        end
        object syName: TcxGridColumn
          Caption = 'Name'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.OnValidate = syNamePropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = syNameStylesGetContentStyle
          Width = 160
        end
        object syAuthor: TcxGridColumn
          Caption = 'Author'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.OnValidate = syAuthorPropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Styles.OnGetContentStyle = syAuthorStylesGetContentStyle
          Width = 75
        end
        object sySynTypeID: TcxGridColumn
          Caption = 'Syn Type'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxPopupEditProperties'
          Properties.ImmediateDropDownWhenActivated = False
          Properties.PopupControl = Panel5
          Properties.OnInitPopup = sySynTypeIDPropertiesInitPopup
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Styles.OnGetContentStyle = sySynTypeIDStylesGetContentStyle
          Width = 50
        end
        object syExtinct: TcxGridColumn
          Caption = 'Extinct'
          DataBinding.ValueType = 'Boolean'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ImmediatePost = True
          Properties.OnChange = syExtinctPropertiesChange
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Styles.OnGetContentStyle = syExtinctStylesGetContentStyle
          Width = 40
        end
        object syGroupID: TcxGridColumn
          Caption = 'GroupID'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Width = 50
        end
        object syPubID: TcxGridColumn
          Caption = 'PubID'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
              Stretchable = False
              Width = 16
            end>
          Properties.OnButtonClick = syPubIDPropertiesButtonClick
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Styles.OnGetContentStyle = syPubIDStylesGetContentStyle
          Width = 40
        end
        object syNotes: TcxGridColumn
          Caption = 'Notes'
          PropertiesClassName = 'TcxBlobEditProperties'
          Properties.BlobEditKind = bekMemo
          Properties.BlobPaintStyle = bpsText
          Properties.OnValidate = syNotesPropertiesValidate
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Styles.OnGetContentStyle = syNotesStylesGetContentStyle
          Width = 60
        end
        object syValidator: TcxGridColumn
          Caption = 'Validator'
          DataBinding.ValueType = 'Integer'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Width = 50
        end
        object syValidDate: TcxGridColumn
          Caption = 'ValidDate'
          DataBinding.ValueType = 'DateTime'
          PropertiesClassName = 'TcxDateEditProperties'
          Properties.DisplayFormat = 'yyyy-mm-dd'
          Properties.EditFormat = 'yyyy-mm-dd'
          Properties.ReadOnly = True
          HeaderAlignmentHorz = taCenter
          Options.Sorting = False
          Width = 60
        end
      end
      object cxGrid1Level1: TcxGridLevel
        Caption = 'Taxon'
        GridView = cxGrid1TableView1
        Options.DetailTabsPosition = dtpLeft
        Styles.Tab = cxStyle3
        Styles.TabsBackground = cxStyle3
        object cxGrid1Level2: TcxGridLevel
          Caption = 'Synonyms'
          GridView = cxGrid1TableView2
        end
      end
    end
    object FlowPanel6: TFlowPanel
      Left = 1
      Top = 1
      Width = 828
      Height = 31
      Align = alTop
      AutoSize = True
      BorderStyle = bsSingle
      TabOrder = 1
      object cxButton9: TcxButton
        Left = 1
        Top = 1
        Width = 81
        Height = 25
        Hint = 'Click to unlock editing of existing taxon'
        Caption = 'Locked'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        Visible = False
        OnClick = cxButton9Click
      end
      object cxButton6: TcxButton
        Left = 82
        Top = 1
        Width = 81
        Height = 25
        Caption = 'Undo'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 10
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton6Click
      end
      object cxButton3: TcxButton
        Left = 163
        Top = 1
        Width = 81
        Height = 25
        Caption = 'Close'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 11
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton3Click
      end
      object cxButton17: TcxButton
        Left = 244
        Top = 1
        Width = 81
        Height = 25
        Hint = 'Show unvalidated taxa'
        Caption = 'Validate'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = cxButton17Click
      end
    end
  end
  object PleaseWaitGroupBox: TcxGroupBox
    Left = 240
    Top = 134
    PanelStyle.Active = True
    ParentBackground = False
    ParentColor = False
    Style.BorderColor = clNavy
    Style.BorderStyle = ebsSingle
    Style.Color = 15984090
    Style.Edges = [bLeft, bTop, bRight, bBottom]
    Style.LookAndFeel.Kind = lfFlat
    Style.Shadow = True
    Style.TransparentBorder = True
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 4
    Visible = False
    Height = 60
    Width = 132
    object Image1: TImage
      Left = 0
      Top = 8
      Width = 48
      Height = 19
      AutoSize = True
      Picture.Data = {
        07544269746D6170E60A0000424DE60A00000000000036000000280000003000
        0000130000000100180000000000B00A00000000000000000000000000000000
        0000150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088FAFAFAFDFDFDFCFCFCFBFAF9
        F7F6F6F9F9F9150088150088150088150088150088150088FAFAFBF2F1F2F3F3
        F3F4F4F4F4F4F4F3F3F3F0F0F0EFEEEEF6F6F7F6F5F515008815008815008815
        0088150088150088150088C5C7C88287867B80809097998D9592A0A6A0A9B1A9
        A9ADA3A2A494ABADA2B6B8B0E0E2E0FBFAFBF3F3F31500881500881500881500
        88F5F5F5F1F1F1F5F4F4E1E3E3CAD1D8D3D8DBE1E0E1EDEDEEF1F1F1EBEBEBDA
        DADABFC0C2D0D2DAD5DDE2E8E7E7EAEAEAE6E6E6DADADACACBCBBEBDBD989B9A
        73787474797FE4E6E5150088150088150088150088150088150088F6F6F6FCFC
        FCFDFDFDFBFBFBFBFBFBFAF9FAF4F4F6F1F1F2E5E7E7C6CAC8ABB0A8A5A79AA4
        A9A5F2F2F2F7F7F7F1F1F1150088150088F2F2F2F5F5F5E5E6E5D3D7DCB5B5B6
        B3B6B6BFBFBFCBCBCBD6D6D6C8C8C8A9A9A7C4CBC3A8A9A9A4A2A1A09D9C9C99
        98929190807F80828180C2C6BADEE1C9808A877E857EB9BBBB15008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088F4F3F4F7F6F6FBFBFCE4E5E6A4A5A0A8AEAACACBCBFBFBFBF4F4F4F2F2
        F2F3F2F2F8F7F8888B899B9B97726F6C6C6C6A78787889898A8A8A8B79797963
        676597A9A997ABAF6C80866B828D6B838A4B595F95938AAFC5C092ADB18EA5A5
        889A966A776FB8BABB1500881500881500881500881500881500881500881500
        88150088150088150088150088150088150088150088150088150088F4F4F4FF
        FFFFB3B6B6919B96CFD2D3F8F8F8F2F2F2FFFFFFB2B3B258615DA9B2AFBCC0B6
        B0AEA384867B565550515051888781BCCACBCCE5EEB3D5E5A2C6D7B1D1DC93B3
        BFBDD9E3BFD4D4A6C3C9B6CAC976827E050405586461F6F5F715008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088FFFEFFB0B3B48E9891EFEFF1F8F7
        F79D9D984E595696ADB6CDDEE0BED5DFD0E7EEDEEFF3C8CAC05D6056C9D4D3D0
        E7F2B5D1E1B2D1E0B5D0DFBBD7E0C0DBEAB8D4E2A4C2D1B8C9C6A1B4AC77817A
        0F0F0B6B78791500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088FEFDFD9AA29DADB2B5DFE5D9E4E5E39FBAC5C7D7D9C2D4D8BFD2D8
        DAE7EDD5E7EFBCDCEDCCE1E9B1D2E4A5C5D5A6C4CBB0CDDAAFCDDDA9C9D8A0BD
        C98FADBEA1B9C2BDC9C7B3C1B99DACA56D807E8D9696FDFCFC15008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088F9F8F9BDC3BD727A74CBDB
        DCA6BCC7BBCFDCA9B9C29DB8C2BACDD3D0E1E5CEE3EFBCDBEAB8D8F0AED0E6A8
        C8D9A4BFD099B4BF97B7C796B6C28BA8B5798A8A747F83E1E4FB7179867F9494
        203030FFFFFFF3F3F31500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088F8F7F8BCBFBE5D67629FB2B5A8BDC9A0B7C687A1AFA5B9C0C5D5DA
        D2DDE4CBE0EBB9D9EFAACDE2A9CDE4AACCDE9ABDD49BB6C590ADB86F88937994
        9B68797C80847FECEBFF76828B495658AEB3B5FCFBFB15008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088150088FFFEFF9097947481
        818695998B9CA1B7C8CBBACACCC1D1D7A6C0CBB2CBD7ADC7D49ABDCF92B2C9A1
        BFD099B9CC93AFBD72868B65777D738D967A8B8E979797E3E4EC7D858A5B6463
        FFFFFFF2F2F11500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088FFFFFFA9AEAC72766AABB4AEA4B0AEB3BEBC9FB5BA
        98AEB9A1B5BCA3BAC39CB4C393AFBF819CAEA2C0D5778F9C7F92947281815A6E
        74535F5FBDBAAD9698976C7175929898FCFCFC15008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088150088150088150088FFFE
        FFC6C6C39A9C8799A198A7AEA991A1A1B5BFBC9FAAA9AAB8B7A7B2AF92A6AD6F
        8490708998677A80647171737F80606D6B909693E2E2E2646A6CB2B6AFCECFCF
        F6F6F61500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088FCFBFDCBCBC9868A7A929D9BAAB2AB
        B3BAB3A5B0ABAFB6AFAEB7AF9EA8A47D8A8E56666E59696F4E5B5C596261E2E3
        E2FFFFFFF9F8F9DDDEDDE3E4E6F8F8F815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        88150088FAFAFBE2E1E0676A64919990A9AEA4B7BAAEAEB3A9A7AEA7969C9680
        8D8E5E6B6F485253555E5CF3F3F3F8F7F7150088150088F5F4F4F4F4F3150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088F6F6F7F8F7F8949693
        82877F939A919CA49C848E87828C8A87908D707B78AEB2B1FEFDFEF5F5F51500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        88150088150088150088150088FDFCFDEFEFF1CED2D1C4C7C7C0C3C4BDC0C1C9
        CCCDF3F3F4FCFBFBF3F2F2150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088}
      Transparent = True
    end
    object cxLabel3: TcxLabel
      Left = 14
      Top = 29
      Caption = 'Please Wait'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -16
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
  end
  object TcpClient1: TTcpClient
    Left = 656
    Top = 8
  end
  object cxImageList1: TcxImageList
    BlendColor = clMenuText
    DrawingStyle = dsTransparent
    FormatVersion = 1
    DesignInfo = 525032
    ImageInfo = <
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
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000270000003300000033000000330000003300000033000000330000
          0033000000330000003300000033000000270000000000000000000000000000
          00000F5989D11170AEFF116FADFF116FADFF1370AEFF1471AFFF1471AFFF1370
          AEFF116FADFF106FADFF1170AEFF0E5989D10000000000000000000000000000
          00001375B3FF41BDF6FF45C5FFFF47C6FFFF129AD8FF149CDAFF149CDAFF129A
          D8FF47C6FFFF44C4FFFF4CC7FDFF1374B2FF0000000000000000000000000000
          00001476B6FF4CC2F5FF0B92D1FF0E94D3FF1299D7FF159DDCFF159DDCFF1299
          D7FF0E94D3FF0991D1FF5FD1FFFF1375B5FF0000000000000000000000000000
          00001579BBFF57C7F5FF42BFFBFF46C2FDFF139BDBFF00557CFF00557CFF139B
          DBFF46C2FDFF40BEFAFF6FD6FFFF1477BBFF0000000000000000000000000000
          0000167DC0FF64CDF5FF0990D0FF0E94D3FF149DDEFF00486BFF00486BFF149D
          DEFF0E94D3FF078FD0FF81DEFFFF147CBFFF0000000000000000000000000000
          00001980C4FF6FD0F5FF3EBEFAFF44C2FDFF119BDCFF003550FF003550FF119B
          DCFF44C2FDFF3CBCFAFF8FE4FFFF177EC3FF0000000000000000000000000000
          00001982C8FF84DCF7FF008DD0FF048FD1FF0794D6FF037BB5FF037BB5FF0794
          D6FF048FD1FF008BCFFFA0ECFFFF1881C8FF0000000000000000000000000000
          00001B88CEFFA8EFFFFFB0F4FFFFB1F4FFFFB3F5FFFFB4F7FFFFB4F7FFFFB3F5
          FFFFB1F4FFFFAFF4FFFFA7EEFFFF1B87CDFF0000000000000000000000000000
          00001974B1D2148AD8FF0F87D8FF1188D7FF1788D4FF1A89D3FF1989D3FF1789
          D5FF1288D7FF0F87D7FF148AD8FF15699FBD0000000000000000000000000000
          0000000000008D7B6FFFCBBDB3FF9E8A7DFF0000000000000000000000000000
          00008C7A6EFFCBBDB3FF9E8A7EFF000000000000000000000000000000000000
          0000000000008B837EFFC2BCB8FF99908BFF0000001800000000000000000000
          00188A827DFFC2BCB8FF98918CFF000000000000000000000000000000000000
          0000000000008E8B89FFC0BEBCFF9C9895FF4442409400000033000000334342
          41939C9896FFC0BEBCFF918D8BFF000000000000000000000000000000000000
          00000000000057565596BAB8B8FFD1CFCDFFA3A09FFF928F8DFF928F8DFFA3A0
          9FFFD1CFCDFFBAB8B8FF57565596000000000000000000000000000000000000
          000000000000000000008A8886E5C1BFBDFFE4E4E3FFE5E3E2FFE9E8E7FFE4E3
          E2FFC1BFBDFF8A8886E500000000000000000000000000000000000000000000
          00000000000000000000000000005F5D5C96A19E9CFFA09E9CFFA09E9CFFA19E
          9CFF5F5D5C960000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000270000003300000033000000330000003300000033000000330000
          0033000000330000003300000033000000270000000000000000000000000000
          00000F5989D11170AEFF116FADFF116FADFF1370AEFF1471AFFF1471AFFF1370
          AEFF116FADFF106FADFF1170AEFF0E5989D10000000000000000000000000000
          00001375B3FF41BDF6FF45C5FFFF47C6FFFF129AD8FF149CDAFF149CDAFF129A
          D8FF47C6FFFF44C4FFFF4CC7FDFF1374B2FF0000000000000000000000000000
          00001476B6FF4CC2F5FF0B92D1FF0E94D3FF1299D7FF159DDCFF159DDCFF1299
          D7FF0E94D3FF0991D1FF5FD1FFFF1375B5FF0000000000000000000000000000
          00001579BBFF57C7F5FF42BFFBFF46C2FDFF139BDBFF00557CFF00557CFF139B
          DBFF46C2FDFF40BEFAFF6FD6FFFF1477BBFF0000000000000000000000000000
          0000167DC0FF64CDF5FF0990D0FF0E94D3FF149DDEFF00486BFF00486BFF149D
          DEFF0E94D3FF078FD0FF81DEFFFF147CBFFF0000000000000000000000000000
          00001980C4FF6FD0F5FF3EBEFAFF44C2FDFF119BDCFF003550FF003550FF119B
          DCFF44C2FDFF3CBCFAFF8FE4FFFF177EC3FF0000000000000000000000000000
          00001982C8FF84DCF7FF008DD0FF048FD1FF0794D6FF037BB5FF037BB5FF0794
          D6FF048FD1FF008BCFFFA0ECFFFF1881C8FF0000000000000000000000000000
          00001B88CEFFA8EFFFFFB0F4FFFFB1F4FFFFB3F5FFFFB4F7FFFFB4F7FFFFB3F5
          FFFFB2F4FFFFB1F4FFFFA8EEFEFF1B87CDFF0000000000000000000000000000
          00001974B1D2148AD8FF0F87D8FF1188D7FF1788D4FF1A89D3FF1A89D2FF1A88
          D3FF1988D3FF1988D3FF1C8AD3FF1A6DA4C50000000000000000000000000000
          0000000000008D7B6FFFCBBDB3FF9E8A7DFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000008B837EFFC2BCB8FF99908BFF0000001800000000000000000000
          001A00000033000000330000001A000000000000000000000000000000000000
          0000000000008E8B89FFC0BEBCFF9C9895FF4542409400000033000000334A46
          449996918DFF948E8BFF4C484699000000000000000000000000000000000000
          00000000000057565596BAB8B8FFD1CFCDFFA3A09FFF928F8CFF928F8CFFA4A0
          9FFFD2D0CEFFBAB6B6FF898785EA000000000000000000000000000000000000
          000000000000000000008A8886E5C1BFBDFFE4E4E3FFE5E3E2FFE9E8E7FFE4E3
          E3FFC1BFBDFF9B9997FF14131320000000000000000000000000000000000000
          00000000000000000000000000005F5D5C96A19E9CFFA09E9CFFA09E9CFFA19E
          9CFF6B6967A90808080D00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFD8CFCCFFD3C6BEFFD2C5BDFFD2C5BDFFD2C5BDFFD2C5
          BDFFD3C5BFFFD8CFCCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCFB07BFFB17B1CFFB07714FFB27916FFB37A17FFB37A17FFB279
          16FFAA7A1AFFB17B1CFFCFB07BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFBB8827FFB47701FFB67903FFB67A08FFB77D0CFFB77C0EFFB77B
          09FFAB7C09FFB47701FFBB8827FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFC89828FFC79007FFC9910CFFCB9819FFCC991BFFCB991BFFCB98
          1AFFC8930DFFC89003FFC89828FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFC89828FFC79007FFC9910CFFCB9819FFCC991BFFCB991BFFCB98
          1AFFC8930DFFC89003FFC89828FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCDA447FFD1A333FFD2A93CFFD4AA45FFD4AA45FFD6AA45FFD4AA
          45FFD3A93FFFD0A232FFCDA447FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFCBB592FFCDAF7EFFCEB381FFCDB17BFFCDB17BFFCDB17BFFCDB1
          7BFFCFB37DFFD1B481FFCBB592FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF5F0E7FFE5D2AFFFE5D2ACFFEBD8B2FFE7D7B2FFE9D8B1FFE8D8
          B3FFE5D2ACFFE5D2AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFBF9F8FFEDE2D4FFCCAD76FFBF9248FFBF9143FFD6B9
          7CFFE6D9BFFFF1EEEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFEAE9F3FFCCAD76FFBA7F01FFBA8002FFBA8002FFB881
          02FFD6B97CFFF1EEEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFE8D4B1FFBB810AFFBA7F01FFBA8002FFBA8002FFB881
          02FFB87C00FFE8D4B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFDCBB76FFC38901FFC38C03FFC38C03FFC38C03FFC38C
          01FFC38A00FFDCBB76FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFDCBB76FFC38901FFC38C03FFC38C03FFC38C03FFC38C
          01FFC38A00FFDCBB76FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFEBDDC0FFD3AE54FFD5B054FFD5B054FFD7B054FFD5B0
          54FFD4B058FFE8D4B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFE1CDA4FFD5B054FFD5B054FFD5B054FFD5B0
          54FFDFC89AFFF6F1E8FFFAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E7F3FFE0C78FFFE0C78FFFE0C78FFFE0C7
          8FFFE5E0E9FFECECFAFFEDEDFBFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000020202030808080D131313202727284C25252D4E2221334F2221354F2121
          364F2221364F2222364F212031480808090E0000000000000000000000000000
          00000E0E0E152A2A2A41494949C9575757FF514F75FF3C36CDFF3E38CFFF403A
          D1FF423CD4FF443ED6FF4843CEFD3A3C41630505060900000000000000000303
          0304222222344C4C4C754C4C4CE8505050FF4A4872FF2922CAFF2B24CDFF2D27
          CFFF3029D1FF322CD4FF413CD0FF687B9FDC19191A2800000000000000000808
          080D3131314B616161B8494949FF505050FF4A4973FF2B25CDFF2D27CFFF3029
          D2FF322CD4FF352ED7FF423ED2FF5875A4DC2525253901010101000000001212
          121B35353552535353B7424242FF525252FF4D4C76FF2E27D0FF302AD2FF332C
          D4FF352FD7FF3731D9FF433FD4FF486999C70E0F101801010101000000000A0A
          0A0F161616233D3D3D933F3F3FFF585858FF514F7AFF302AD2FF332DD5FF352F
          D7FF3831DAFF3A34DCFF4541D6FF355897BB0000000000000000000000000000
          0000000000002525257F3F3F3FFF5F5F5FFF55537EFF332DD5FF362FD7FF3832
          DAFF3A34DCFF3D36DFFF4743D7FF335899BB0000000000000000000000000000
          0000000000001F1F1F7F3F3F3FFF656565FF585681FF3630D8FF3832DAFF3B34
          DDFF3D37DFFF3F39E1FF4845D9FF33599BBB0000000000000000000000000000
          0000000000001C1C1C7F3F3F3FFF686868FF595882FF3932DBFF3B35DDFF3D37
          DFFF4039E2FF423CE4FF4A46DAFF345C9CBB0000000000000000000000000000
          0000000000001C1C1C7F3F3F3FFF696969FF5A5882FF3B35DDFF3E37E0FF403A
          E2FF423CE4FF443EE6FF4B48DCFF365F9DBB0000000000000000000000000000
          0000000000001D1D1D7F3F3F3FFF6E6E6EFF616086FF514CE3FF534EE5FF5550
          E7FF5752E9FF5953EAFF5552DEFF38639DBB0000000000000000000000000000
          0000000000001F1F1F7F585858FFB3B3B3FFAFAFBDFFA7A6CEFFA7A6CEFFA8A7
          CFFFA9A8D0FFA9A8D0FF7896CCFF40699DBB0000000000000000000000000000
          0000000000002424247F656565FF797979FFB9B9B9FFB5BAC4FFB3BACBFFB4BB
          CCFFB5BCCDFFB5BCCDFFB2BBD0FF333A4B680000000000000000000000000000
          00000000000024242478B0B0B0FFB4B4B6FFB3BACBFFB4BBCCFFB4BBCCFFB5BC
          CDFFB6BDCEFF8F95A4DF1213151E050607090000000000000000000000000000
          0000000000000505050A1010111F0F0F0F191010111911111119111112191111
          1219111112190F0F0F1600000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000002020202B48157FFB07E55FFA08859FF998A5BFFA47350FFA06F
          4EFF9D6C4DFF99684BFF96654AFF4A3224800000000000000000000000000000
          00000000000007070707B78459FFFEF6F0FFCFE9C9FF7CD58BFFD2E7C7FFFEEF
          E5FFFDEDE1FFFDEDE0FFF8EFE8FFBD9F8EFF37251B6000000000B48157FFB07E
          55FFAC7A53FFAB7A57FFB98659FFF7F3EAFFBCE4BBFF71D484FF6AD17FFFA0DB
          A3FFF0EAD7FFFDECDFFFFEF8F3FFE9DFD9FF8D5F45F121161039B78459FFFEF6
          F0FFFEF4ECFFD9EACFFF82B870FF70D283FF66CF7BFF83DC94FF80DB91FF6ED3
          82FF75D285FFC1E2B8FFF4F1E4FFFEF8F4FFE0CDC2FF946449FFAF7F55F0FEF5
          EFFFB2E2B4FF66CF7AFF94E3A3FF8DE09CFF8CE09BFF92E2A1FF89DE99FF7AD8
          8CFF6CD280FF93D99AFFE4E9D0FFFDEDE0FFFDEEE3FF96664AFFBD8A5BFFBEE6
          BFFF8ADF9AFF6AD07EFF79C174FF9FDEA7FF92DA9DFF8CE09BFF7CD98EFF75D3
          86FFC6E6C1FFFEF1E7FFFEEFE4FFFEEDE1FFFDEDE0FF99684BFFA89E65FF81D6
          8FFFB2E3B5FFECF1E1FFC5925FFFFEF6F1FFD0EACCFF78D78BFF9DDDA5FFEFF1
          E4FFFEF4EDFFFEF3EAFFFEF1E7FFFEEFE4FFFEEFE4FF9C6B4CFFA4A467FFD9ED
          D4FFFEF6F0FFFEF6F0FFC89460FFFEF6F1FFDFEED8FFCEEACBFFFEF6F0FFFEF6
          F0FFFEF5EFFFFEF4EDFFFEF3EAFFFEF1E7FFFEF1E7FF9E6D4DFFBE9661FFFBF5
          EFFFFEF6F0FFFEF6F0FFCA9762FFFEF6F1FFFEF6F0FFFEF6F0FFFEF6F0FFFEF6
          F0FFFEF6F0FFFEF5EFFFFEF4EDFFFEF3EAFFFEF2E9FFA1704FFFC89460FFFEF6
          F1FFFEF6F0FFFEF6F0FFCD9963FFFEF6F1FFFEF6F0FFFEF6F0FFFEF6F0FFFEF6
          F0FFFEF6F0FFFEF6F0FFFEF5EFFFFEF4EDFFFEF4ECFFA47350FFCA9762FFFEF6
          F1FFFEF6F0FFFEF6F0FFCF9B64FFFEF6F1FFF3DEB3FFF1D7AAFFEECD9DFFEAC0
          8FFFE7B683FFE6B17CFFE6B17CFFE6B17CFFFEF5EFFFA77651FFCD9963FFFEF6
          F1FFFEF6F0FFFEF6F0FFD19D64FFFEF6F1FFF3DEB2FFF1D6A9FFEECC9BFFEABF
          8DFFE7B581FFE6B07AFFE6B07AFFE6B07AFFFEF6F0FFAA7953FFCF9B64FFFEF6
          F1FFF3DEB3FFF1D8ACFFD29E65FFFEF8F3FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7
          F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF8F3FFAD7B54FFD19D64FFFEF6
          F1FFF3DEB2FFF1D6AAFFD4A066FFD29E65FFD09C64FFCD9963FFCA9761FFC794
          60FFC3905EFFC08D5DFFBC895BFFB88659FFB48258FFB07E56FFD29E65FFFEF8
          F3FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7F2FFFEF7
          F2FFFEF8F3FFAD7B54FF00000000000000000000000000000000D4A066FFD29E
          65FFD09C64FFCD9963FFCA9761FFC79460FFC3905EFFC08D5DFFBC895BFFB886
          59FFB48258FFB07E56FF00000000000000000000000000000000}
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
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000001D25DAFF1D25
          DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25
          DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF5A60
          E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF5A60
          E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF5A60E4FF1D25DAFF1D25DAFF767B
          E8FF767BE8FF767BE8FF767BE8FF767BE8FF767BE8FF767BE8FF767BE8FF767B
          E8FF767BE8FF767BE8FF767BE8FF767BE8FF767BE8FF1D25DAFF1D25DAFF979B
          EEFF979BEEFF979BEEFF979BEEFF979BEEFF979BEEFF979BEEFF979BEEFF979B
          EEFF979BEEFF979BEEFF979BEEFF979BEEFF979BEEFF1D25DAFF1D25DAFFB8BA
          F3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BA
          F3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FFB8BAF3FF1D25DAFF1D25DAFF1D25
          DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25
          DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF1D25DAFF000000000000
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
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000028160B30000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000007946228F361F0F400000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000001B100820BD6C34DF0D07041000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000AF622FCF6B3B1D8000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000077411F8FCA6D36EF0D070310000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000005B301670DB753EFF4D271160000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000331A0C40DD783EFF8C4620AFD05F29FFD05F
          29FFD05F29FFD05F29FFD05F29FFD05F29FFD05F29FFA2481CCF000000000000
          0000000000000000000000000000401F0D50DE783EFF9A4B22BFD05F29FFDA76
          45FFD8713CFFD9713AFFDD6F36FFDC6932FFA3471CCF0C050210000000000000
          0000000000000000000000000000642F1480E47B41FFA65024CFD05F29FFD672
          40FFD36B35FFD76F39FFDF7947FFB04E21DF0C05021000000000000000000000
          0000000000000000000000000000A34B20CFE57A40FF97441EBFD05F29FFD671
          40FFD77442FFD56D38FFDD7A47FFD16534FF2510073000000000000000000000
          000000000000000000003E1C0C50D56935FFE37941FF883E1CAFD05F29FFDB82
          56FFDF8A62FFDD8053FFD56C37FFDE7B4AFFC46032EF57261070000000000000
          00000000000031160940C0592AEFE37841FFD86C38FF49200E60D05F29FFDD8D
          67FFBC552BEFD7794FFFDC7F50FFD46C36FFDE7A49FFD76E3DFFB35126DF9944
          1FBFA64B22CFD46633FFE0743EFFE0743EFFBB5326EF0C050210D05F29FFA34C
          29CF0C0502107031168FD47247FFDE8357FFD7713EFFD76F3AFFDC7440FFDE72
          3DFFDD713BFFDB703AFFDE723CFFCF602FFF3C190A5000000000A64C21CC0C05
          021000000000000000003E1A0B50B4572FDFDA7A4FFFDD7E50FFDB7645FFDA72
          3FFFDC703CFFD86735FFBC5226EF3C190B5000000000000000000F0703120000
          0000000000000000000000000000000000004B1E0C608A3C1DAF984623BF9744
          21BF95401DBF54230E700C050210000000000000000000000000}
      end>
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    OnSSLServerAuthentication = ipsHTTPS1SSLServerAuthentication
    Left = 608
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 656
    Top = 56
  end
  object PopupMenuValidator: TPopupMenu
    Images = cxImageList1
    Left = 648
    Top = 104
    object ShowValidator1: TMenuItem
      Caption = 'Show Validator'
      ImageIndex = 4
      OnClick = ShowValidator1Click
    end
  end
  object PopupMenuPubID: TPopupMenu
    Images = cxImageList1
    OnPopup = PopupMenuPubIDPopup
    Left = 736
    Top = 104
    object ShowPublication1: TMenuItem
      Caption = 'Show Publication'
      ImageIndex = 5
      OnClick = ShowPublication1Click
    end
    object PubDitto1: TMenuItem
      Caption = 'Ditto'
      ImageIndex = 6
      OnClick = PubDitto1Click
    end
    object PubDelete1: TMenuItem
      Caption = 'Delete'
      ImageIndex = 7
      OnClick = PubDelete1Click
    end
  end
  object PopupMenuAuthor: TPopupMenu
    Images = cxImageList1
    Left = 648
    Top = 144
    object AuthorDitto1: TMenuItem
      Caption = '&Ditto'
      ImageIndex = 6
      OnClick = AuthorDitto1Click
    end
  end
  object PopupMenuEcolGroup: TPopupMenu
    Images = cxImageList1
    Left = 736
    Top = 144
    object EcolGroupDitto1: TMenuItem
      Caption = '&Ditto'
      ImageIndex = 6
      OnClick = EcolGroupDitto1Click
    end
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 728
    Top = 56
    object Mark1: TMenuItem
      Caption = 'Mark'
      OnClick = Mark1Click
    end
    object Unmark1: TMenuItem
      Caption = 'Unmark'
      OnClick = Unmark1Click
    end
    object InsertChild1: TMenuItem
      Caption = 'Insert as Child'
      OnClick = InsertChild1Click
    end
    object InsertSibling1: TMenuItem
      Caption = 'Insert as Sibling'
      OnClick = InsertSibling1Click
    end
    object InsertSynonym1: TMenuItem
      Caption = 'Insert as Synonym'
      OnClick = InsertSynonym1Click
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 784
    Top = 8
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14803425
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5525059
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = 5525059
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13828095
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWindowText
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clNavy
    end
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 704
    Top = 8
  end
end
