object IsoDatasetMetadataForm: TIsoDatasetMetadataForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Isotope Dataset Metadata'
  ClientHeight = 442
  ClientWidth = 284
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 284
    Height = 25
    Align = alTop
    BevelEdges = [beLeft, beTop, beRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'Instrumental Error'
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
  object GridPanel1: TGridPanel
    Left = 0
    Top = 25
    Width = 284
    Height = 67
    Align = alTop
    BevelKind = bkFlat
    BevelOuter = bvNone
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 150.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 134.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = cxLabel1
        Row = 0
      end
      item
        Column = 1
        Control = cxTextEdit1
        Row = 0
      end
      item
        Column = 0
        Control = cxLabel2
        Row = 1
      end
      item
        Column = 1
        Control = cxTextEdit2
        Row = 1
      end
      item
        Column = 0
        Control = cxLabel3
        Row = 2
      end
      item
        Column = 1
        Control = cxTextEdit3
        Row = 2
      end>
    ParentBackground = False
    RowCollection = <
      item
        SizeStyle = ssAuto
        Value = 50.000000000000000000
      end
      item
        SizeStyle = ssAuto
        Value = 100.000000000000000000
      end
      item
        SizeStyle = ssAuto
      end>
    ShowCaption = False
    TabOrder = 3
    OnResize = GridPanel1Resize
    object cxLabel1: TcxLabel
      Left = 45
      Top = 0
      Align = alRight
      Caption = 'Technical Error ('#8240'):'
      Style.TextColor = clWindowText
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 150
    end
    object cxTextEdit1: TcxTextEdit
      Left = 150
      Top = 0
      Align = alClient
      Properties.Alignment.Horz = taRightJustify
      Properties.ClearKey = 46
      Properties.OnValidate = cxTextEdit1PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 1
      Width = 134
    end
    object cxLabel2: TcxLabel
      Left = 42
      Top = 21
      Align = alRight
      Caption = 'SD of Material in Run:'
      Style.TextColor = clWindowText
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 150
    end
    object cxTextEdit2: TcxTextEdit
      Left = 150
      Top = 21
      Align = alClient
      Properties.Alignment.Horz = taRightJustify
      Properties.ClearKey = 46
      Properties.OnValidate = cxTextEdit2PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 2
      Width = 134
    end
    object cxLabel3: TcxLabel
      Left = 19
      Top = 42
      Align = alRight
      Caption = 'Long Term Lab Error ('#8240'):'
      Style.TextColor = clWindowText
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 150
    end
    object cxTextEdit3: TcxTextEdit
      Left = 150
      Top = 42
      Align = alClient
      Properties.Alignment.Horz = taRightJustify
      Properties.ClearKey = 46
      Properties.OnValidate = cxTextEdit3PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 3
      Width = 134
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 92
    Width = 284
    Height = 25
    Align = alTop
    BevelEdges = [beLeft, beRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'Instrumentation'
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 10
  end
  object GridPanel2: TGridPanel
    Left = 0
    Top = 117
    Width = 284
    Height = 46
    Align = alTop
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'GridPanel2'
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 150.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 134.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = cxLabel4
        Row = 0
      end
      item
        Column = 1
        Control = cxComboBox1
        Row = 0
      end
      item
        Column = 0
        Control = cxLabel5
        Row = 1
      end
      item
        Column = 1
        Control = cxComboBox2
        Row = 1
      end>
    ParentBackground = False
    RowCollection = <
      item
        SizeStyle = ssAuto
        Value = 50.000000000000000000
      end
      item
        SizeStyle = ssAuto
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 5
    OnResize = GridPanel2Resize
    object cxLabel4: TcxLabel
      Left = 89
      Top = 0
      Align = alRight
      Caption = 'Instrument:'
      Style.TextColor = clWindowText
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 150
    end
    object cxComboBox1: TcxComboBox
      Left = 150
      Top = 0
      Align = alClient
      Properties.ClearKey = 46
      Properties.DropDownListStyle = lsFixedList
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 1
      Width = 134
    end
    object cxLabel5: TcxLabel
      Left = 8
      Top = 21
      Align = alRight
      Caption = 'Sample Introduction System:'
      Style.TextColor = clWindowText
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 150
    end
    object cxComboBox2: TcxComboBox
      Left = 150
      Top = 21
      Align = alClient
      Properties.ClearKey = 46
      Properties.DropDownListStyle = lsFixedList
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 2
      Width = 134
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 401
    Width = 284
    Height = 41
    Align = alBottom
    BevelEdges = [beLeft, beRight, beBottom]
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 6
    DesignSize = (
      284
      41)
    object FlowPanel1: TFlowPanel
      Left = 72
      Top = 8
      Width = 138
      Height = 25
      Anchors = [akLeft, akTop, akRight]
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 69
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        LookAndFeel.NativeStyle = False
        LookAndFeel.SkinName = 'Blue'
        ModalResult = 1
        OptionsImage.Glyph.Data = {
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
        TabOrder = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 69
        Top = 0
        Width = 69
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        LookAndFeel.NativeStyle = False
        LookAndFeel.SkinName = 'Blue'
        ModalResult = 2
        OptionsImage.Glyph.Data = {
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
        TabOrder = 1
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object Panel7: TPanel
    Left = 0
    Top = 376
    Width = 284
    Height = 25
    Align = alBottom
    BevelKind = bkFlat
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    ShowCaption = False
    TabOrder = 4
    object cxLabel6: TcxLabel
      Left = 0
      Top = 0
      Align = alLeft
      Caption = 'Notes:  '
    end
    object cxBlobEdit3: TcxBlobEdit
      Left = 40
      Top = 0
      Align = alRight
      Properties.BlobEditKind = bekMemo
      Properties.BlobPaintStyle = bpsText
      Properties.ClearKey = 46
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 1
      Width = 240
    end
  end
  object GridPanel4: TGridPanel
    Left = 0
    Top = 299
    Width = 284
    Height = 69
    Align = alBottom
    BevelKind = bkFlat
    BevelOuter = bvNone
    ColumnCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = cxLabel7
        Row = 0
      end
      item
        Column = 0
        Control = cxLabel8
        Row = 2
      end
      item
        Column = 1
        Control = cxBlobEdit2
        Row = 2
      end
      item
        Column = 1
        Control = cxTextEdit4
        Row = 0
      end
      item
        Column = 0
        Control = cxLabel9
        Row = 1
      end
      item
        Column = 1
        Control = cxTextEdit5
        Row = 1
      end>
    RowCollection = <
      item
        SizeStyle = ssAuto
        Value = 33.333333333333340000
      end
      item
        SizeStyle = ssAuto
        Value = 33.333333333333340000
      end
      item
        SizeStyle = ssAuto
        Value = 33.333333333333340000
      end>
    ShowCaption = False
    TabOrder = 7
    ExplicitTop = 307
    object cxLabel7: TcxLabel
      Left = 79
      Top = 0
      Align = alRight
      Caption = 'Local Value:'
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 140
    end
    object cxLabel8: TcxLabel
      Left = 15
      Top = 42
      Align = alRight
      Caption = 'Local Geological Context:'
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 140
    end
    object cxBlobEdit2: TcxBlobEdit
      Left = 140
      Top = 42
      Align = alClient
      Properties.BlobEditKind = bekMemo
      Properties.BlobPaintStyle = bpsText
      Properties.ClearKey = 46
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 3
      Width = 140
    end
    object cxTextEdit4: TcxTextEdit
      Left = 140
      Top = 0
      Align = alClient
      Properties.OnValidate = cxTextEdit4PropertiesValidate
      TabOrder = 1
      Width = 140
    end
    object cxLabel9: TcxLabel
      Left = 63
      Top = 21
      Align = alRight
      Caption = 'Local Value SD:'
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 140
    end
    object cxTextEdit5: TcxTextEdit
      Left = 140
      Top = 21
      Align = alClient
      Properties.OnValidate = cxTextEdit5PropertiesValidate
      TabOrder = 2
      Width = 140
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 368
    Width = 284
    Height = 8
    Align = alBottom
    BevelEdges = [beLeft, beRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    ShowCaption = False
    TabOrder = 1
    ExplicitTop = 295
  end
  object Panel5: TPanel
    Left = 0
    Top = 274
    Width = 284
    Height = 25
    Align = alBottom
    BevelEdges = [beLeft, beRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'Strontium Metadata'
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 8
  end
  object Panel6: TPanel
    Left = 0
    Top = 163
    Width = 284
    Height = 25
    Align = alTop
    BevelEdges = [beLeft, beRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'Standards'
    Color = 15984090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 9
  end
  object AdvStandardsGrid: TAdvColumnGrid
    Left = 0
    Top = 188
    Width = 284
    Height = 86
    Cursor = crDefault
    Align = alClient
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    ColCount = 3
    DefaultRowHeight = 20
    DrawingStyle = gdsClassic
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goTabs]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 2
    HoverRowCells = [hcNormal, hcSelected]
    OnGetDisplText = AdvStandardsGridGetDisplText
    OnClipboardPasteDone = AdvStandardsGridClipboardPasteDone
    OnCellValidate = AdvStandardsGridCellValidate
    OnGetEditorProp = AdvStandardsGridGetEditorProp
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = clWindow
    ColumnHeaders.Strings = (
      ''
      'Standard'
      
        '<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">'#948'</FONT><FO' +
        'NT size=\"6\" face=\"Tahoma\"><SUP>13</SUP></FONT><FONT size=\"8' +
        '\" face=\"Tahoma\">C ('#8240')</FONT></P>')
    ColumnSize.Stretch = True
    ColumnSize.StretchColumn = 1
    ControlLook.FixedGradientHoverFrom = clGray
    ControlLook.FixedGradientHoverTo = clWhite
    ControlLook.FixedGradientDownFrom = clGray
    ControlLook.FixedGradientDownTo = clSilver
    ControlLook.ControlStyle = csWinXP
    ControlLook.DropDownAlwaysVisible = True
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
      'Larger than'
      'Smaller than'
      'Clear')
    FixedColWidth = 32
    FixedRowHeight = 20
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = []
    FloatFormat = '%.2f'
    HoverButtons.Buttons = <>
    HoverButtons.Position = hbLeftFromColumnLeft
    HTMLSettings.ImageFolder = 'images'
    HTMLSettings.ImageBaseName = 'img'
    Navigation.AdvanceOnEnter = True
    Navigation.AdvanceInsert = True
    Navigation.AllowClipboardShortCuts = True
    Navigation.AllowClipboardColGrow = False
    Navigation.AppendOnArrowDown = True
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
    ShowDesignHelper = False
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
        Editor = edGridDropDown
        FilterCaseSensitive = False
        Fixed = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Header = 'Standard'
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
        Width = 184
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
        Header = 
          '<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">'#948'</FONT><FO' +
          'NT size=\"6\" face=\"Tahoma\"><SUP>13</SUP></FONT><FONT size=\"8' +
          '\" face=\"Tahoma\">C ('#8240')</FONT></P>'
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
        Width = 64
      end>
    ExplicitHeight = 101
    ColWidths = (
      32
      184
      64)
  end
end
